# Bruce — the `0x600921b8`–`0x600c9cc4` block: Broadcom BTA/BTE Bluetooth stack (sessions 7–8)

Target: the single largest unmapped contiguous range in the image (`analysis/bruce-decompile-status.md` §3b run #1) — 1,076 functions, 204,449 code bytes, 89.6% density, 2/1,076 decompiled at session-7 start.

**Session 8 update (same day):** executed session 7's continuation plan in full. Swept the remaining ~388 BTA/BTE trace-string table entries through `FindRef.java` (317 identifier-shaped strings checked in bulk, plus a targeted L2CAP/`btu_task` batch) and got **261 new function identifications** with effectively zero false positives, then batch-decompiled all of them plus a few hand-resolved "gap" functions Ghidra's auto-analysis hadn't boundary-detected (same phenomenon as `btu_task` below). **Net result: 327 of 1,076 functions now decompiled (up from 69), ~93,400 of 204,449 code bytes (~45.7%, up from ~11%).** All three of session 7's flagged open threads made concrete progress this session:
- **`btu_task` confirmed as the real BTU-layer main dispatch loop** (thread 3) — see prose below.
- **L2CAP fully surfaced**: the block session 7 called "GATT-client attribute-cache" (`0x600b5xxx`–`0x600bcxxx`) is actually the **L2CAP channel-state-machine + FCR** implementation (`l2c_csm_*`/`l2c_fcr_*`/`l2c_rcv_acl_data`, all string-confirmed) — a direct correction to session 7's module-map guess, not just new territory (thread 4, previously "not yet touched").
- **`smp_data_ind` traced down into the confirmed P-256 scalar-multiplication code**, closing the "what calls the EC crypto stack" question (thread 5) with a complete, non-speculative call chain — see prose below.

Five of session 7's own guessed identifications turned out to be wrong and are corrected in the table below (all in the `0x600c3xxx`–`0x600c4xxx` band session 7 guessed was "SMP/pairing state helpers" — it's actually **BTA DM** search/SDP-result/ACL-change handling, not SMP).

## Identification: confidence VERY HIGH

**This range is the statically-linked Broadcom BTA/BTE Bluetooth protocol stack** — the same "Google-forked Broadcom BTA (GATT/L2CAP/RFCOMM/SPP/HFP/SDP)" that `firmware-map.md` already documented existed *somewhere* in the image from leaked module names, but whose address range no prior session had located. Concretely, this block holds (at minimum): the HCI transport + command-send layer, the top-level HCI event dispatcher, BTM (device/link manager: ACL, inquiry, advertising/EIR), BTA DM (multi-profile device manager, power management), GATT client and server, SDP (service discovery), SMP (Security Manager Protocol / LE pairing), and curve-specific EC field arithmetic (NIST P-256, feeding SMP's LE Secure Connections ECDH).

This supersedes/extends the prior session's guarded "TLV parser, maybe HCI/GATT/SDP framing" + "maybe P-256" hedges (`bruce-misc-functions.md`) — both of those functions (`FUN_600ba1c4`, `FUN_600c8fd8`) turn out to sit inside exactly this one real module, not two unrelated coincidences.

### Evidence

**1. A ~400-entry BTA/BTE function-name string table, individually cross-referenced from code inside this exact range.**

The flash image embeds a large table of literal function-name strings at `0x60103xxx`–`0x60122xxx` (outside this block, in decompile-status run #2's span) — `bta_dm_pm_btm_cback`, `BTA_GATTC_Open`, `l2c_csm_closed`, `smp_build_pairing_cmd`, `btu_hcif_command_complete_evt`, `btsnd_hcic_disconnect`, etc. (`grep -inE "l2cap|rfcomm|smp|gatt|sdp|hci|bta_|btm_|btu_" analysis/ghidra/bruce_strings.txt` → 411 hits). These read like a Broadcom BTE debug/trace symbol table (each function logs its own name, a common BTE idiom). A stratified sample of 23 of the 411 was checked with `FindRef.java`; **19 of 23 had their sole code cross-reference land inside `0x600921b8`–`0x600c9cc4`**, and the referencing-function addresses track the string-table addresses monotonically (e.g. strings at `0x60116a58…0x601177dc` map in order to functions at `0x600ae4e0…0x600b4798`) — consistent with the linker placing the trace-string constant next to the object code that logs it, in source-file order. The 4 misses were either no-refs-found (probably consumed via a data table Ghidra didn't type as pointers, a known limitation — see `bruce-crypto.md`'s EVP registry writeup for the same phenomenon) or one hit from outside the range entirely (`0x60105ab0`, an unanalyzed address in run #2).

*Caveat on generalizing the 19/23 rate:* of the 18 functions this session actually tags "named (via string xref)" in the table below, 8 (44%) are the `btsnd_hcic_*` family — which also happens to be the one category with independent, opcode-level spec confirmation (Evidence §2), not just string-adjacency. That's not a coincidence to worry about (the opcode match and the string match are two genuinely independent checks that happened to agree), but it does mean the sample is weighted toward the easiest-to-verify, self-confirming category, and the 19/23 hit-rate shouldn't be read as equally strong evidence for harder-to-check categories (SDP/SMP/GATT-cache internals, which have no spec-level byte pattern to cross-check against). Treat the ~400-string extrapolation as a well-motivated hypothesis for *where to look next*, not as ~400 individually-confirmed identifications — the doc's own "what's left" section below already frames it this way, which is the right call.

**2. HCI command opcodes match the Bluetooth spec exactly, byte-for-byte.**

Eight `btsnd_hcic_*`-named functions are present in the decompiled set; all eight have the identical shape (allocate a GKI-style buffer via `FUN_6006dbac`, write a 2-byte little-endian HCI opcode + 1-byte param-length header, copy the command parameters, send via `FUN_600a9234`). Audited independently against the Bluetooth Core Spec HCI opcode table (OGF/OCF): all eight opcodes match exactly, not just the 4 originally tabulated here:
| Function | String name | Opcode bytes written | Spec opcode |
|---|---|---|---|
| `FUN_600b218c` | `btsnd_hcic_disconnect` | `0x06,0x04` | `0x0406` (OGF 1/OCF 0x06, Disconnect) ✓ |
| `FUN_600b1090` | `btsnd_hcic_ble_remove_from_white_list` | `0x12,0x20` | `0x2012` (OGF 8/OCF 0x12, LE Remove Device From White List) ✓ |
| `FUN_600b19c0` | `btsnd_hcic_ble_add_device_resolving_list` | `0x27,0x20` | `0x2027` (OGF 8/OCF 0x27, LE Add Device To Resolving List) ✓ |
| `FUN_600b29b8` | `btsnd_hcic_rmt_ext_features` | `0x1c,0x04` | `0x041c` (OGF 1/OCF 0x1c, Read Remote Extended Features) ✓ |
| `FUN_600b3240` | `btsnd_hcic_set_event_filter` | `0x05,0x0c` | `0x0c05` (OGF 3/OCF 0x05, Set Event Filter) ✓ |
| `FUN_600b3b2c` | `btsnd_hcic_write_cur_iac_lap` | `0x3a,0x0c` | `0x0c3a` (OGF 3/OCF 0x3a, Write Current IAC LAP) ✓ |
| `FUN_600b4798` | `btsnd_hcic_write_inq_tx_power` | `0x59,0x0c` | `0x0c59` (OGF 3/OCF 0x59, Write Inquiry Transmit Power Level) ✓ |
| `FUN_600b4dcc` | `btsnd_hcic_write_secure_conns_support` | `0x7a,0x0c` | `0x0c7a` (OGF 3/OCF 0x7a, Write Secure Connections Host Support) ✓ |

Param-length fields also check out against spec (e.g. Disconnect's 3-byte params = handle+reason; LE Remove Device From White List's 7-byte params = addr-type+BD_ADDR; LE Add Device To Resolving List's 39-byte params = addr-type+BD_ADDR+peer IRK+local IRK). This is independent, spec-level confirmation beyond string co-location — every `btsnd_hcic_*` function checked, not a cherry-picked subset.

**3. The top-level HCI event dispatcher's switch matches the HCI event-code table 1:1, including the nested LE-Meta-Event sub-dispatch.**

`FUN_600a89f0` (1,044B, no static callers — almost certainly invoked via a registered function pointer, matching BTE's `btu_hcif_process_event`) switches on a raw event-code byte into ~50 handler calls. Independently checked against the Core Spec event-code table: the outer switch's case values (`0x01`–`0x23`, `0x2c`–`0x3e`, `0x4e`, `0x57`) all land on real assigned HCI event codes (e.g. `0x2c`/`0x2d` Synchronous Connection Complete/Changed, `0x30`–`0x36` the Simple Pairing event cluster, `0x4e` Triggered Clock Capture, `0x57` Authenticated Payload Timeout Expired) — consistent with a real BTE dispatcher rather than an arbitrary/invented set of codes. Case `'>'` (`0x3e`, the real **HCI LE Meta Event** code) itself contains a **nested switch** on a second byte into 8 more cases (`1..7, 0xa`) — exactly the real **LE Meta Event sub-event codes** (LE Connection Complete=1, LE Advertising Report=2, LE Connection Update Complete=3, LE Read Remote Features Complete=4, LE LTK Request=5, LE Remote Conn Param Request=6, LE Data Length Change=7, LE Enhanced Connection Complete=0xa). Notably absent: sub-event codes `0x08`/`0x09` (LE Read Local P-256 Public Key Complete / LE Generate DHKey Complete) — the two events a controller emits when it performs LE Secure Connections ECDH *on the controller*. Their absence is consistent with this stack instead computing ECDH in the *host*, which lines up with the P-256 field-arithmetic functions independently found at `0x600c8fd8`/`0x600c8b24` (Evidence §5) — a small piece of corroboration connecting the two otherwise-separate findings. Separately, case `0xef` (not a spec-assigned event code — the real spec Vendor-Specific event is `0xff`, handled here by its own `case -1` calling `FUN_600a1490`) calls a registered vendor-callback pointer at `DAT_600a9230+0xd4`; this is inferred from the `BTM_VendorSpecificCommand` string-table slot rather than from a spec match, and `0xef`'s exact meaning (a Broadcom-internal/reserved code, not an official BT SIG assignment) is unconfirmed.

**4. Recognizable protocol framing shapes for SDP and GAP advertising data.**

- `FUN_600beb20`/`FUN_600be150`/`FUN_600be558` build a buffer with header bytes `0x35`/`0x36` (SDP Data-Element-Sequence type/size-index bytes) and a PDU opcode field set to `7` (`SDP_ServiceSearchAttributeResponse`) — an SDP server response builder.
- `FUN_6009cf8c` (2,464B) assembles a length-prefixed AD-structure stream whose type bytes match the real **GAP Advertising Data type codes** exactly: Flags=`0x01`, Appearance=`0x19`, Shortened/Complete Local Name=`0x08`/`0x09`, Incomplete/Complete 16-bit UUID list=`0x02`/`0x03`, 32-bit=`0x04`/`0x05`, 128-bit=`0x06`/`0x07`, TX Power Level=`0x0a`, Slave Connection Interval Range=`0x12`, Service Data (16-bit UUID)=`0x16` — a BTM/GAP advertising/EIR-data builder.

**5. NIST P-256 field reduction (confirmed prior session) sits alongside a second, smaller bignum-reduction sibling using the identical compare/subtract helper pair.**

`FUN_600c8fd8` (2,764B, prior session) is Solinas-style reduction for the 256-bit NIST P-256 prime. Newly decompiled `FUN_600c8b24` (1,198B, immediately upstream in the call graph — called from `FUN_601005ac`) does the same "weighted partial-sum add, then compare/conditional-subtract" pattern but only over **6 words (192 bits)** of output from a 12-word (384-bit) input, using the *same* two helpers (`FUN_601002bc` compare, `FUN_601004b2` subtract) as the P-256 function. Shape strongly suggests a second curve-specific reduction — most plausibly **NIST P-192** (the curve classic BT Secure Simple Pairing originally specified before the industry-wide move to P-256), consistent with BoringSSL linking in whatever curves its generic `EC_GROUP` layer references (the string table also has literal `"NIST P-256"`, `"brainpoolP256r1"`, `"brainpoolP256t1"`). Not spec-verified byte-for-byte (would need the actual modulus constant, which sits in a literal pool Ghidra hasn't resolved — same caveat as before). `FUN_600c8798` (574B) is a further neighbor in this cluster calling more `0x60100xxx`-suffixed bignum helpers — plausibly a point-arithmetic step (add/double), not decompiled deeply this session.

**6. Call-graph coherence.** Everything above cross-links internally: `FUN_600b5e00` (the connection-event dispatcher session 7 flagged) feeds the same neighborhood the previously-flagged `FUN_600ba1c4` TLV/PDU parser sits in — i.e. `FUN_600ba1c4` (session 6's "connection-protocol TLV parser... feeds `state_machine.cc`") is inside that same cluster. **Session 8 update: this whole cluster is now string-confirmed as L2CAP** (`l2c_csm_*`/`l2c_fcr_*`/`l2c_rcv_acl_data`, see address-range map below), not GATT-client attribute-cache as session 7 guessed — so `FUN_600ba1c4` is more likely an L2CAP-internal PDU dispatcher/reassembler (it's called directly from `l2c_rcv_acl_data`) than an ATT/GATT parser per se. Still not a bespoke Google session protocol either way — that reading holds.

## Address-range map (approximate module clusters, by evidence + neighborhood)

| Range | Module (evidence) |
|---|---|
| `0x600921b8`–~`0x60092440` | CRC-32 utility (classic slicing-by-8 table-driven CRC, `~crc` init/final XOR) — generic, not BT-specific; sits at the very head of this object-file group |
| ~`0x60093xxx`–`0x600944xx` | BTA DM power management (`bta_dm_pm_btm_cback` confirmed @ `0x6009430c`) |
| ~`0x60096xxx`–`0x60098xxx` | HCI H4 UART transport (`hcisu_h4_send_msg_now` @ `0x60096e38`) + BTM link-policy/sniff-mode helpers |
| ~`0x60099xxx`–`0x6009cxxx` | Mixed BTM cluster: ACL/security link-record updater (`0x6009ad00`) and an LE connection-complete-style event parser (`0x6009b368`) occupy most of this span; only the tail end is confirmed **BTM advertising/EIR data assembly** (`FUN_6009cf8c`, spec-verified AD-type bytes) — the "advertising/EIR" label doesn't cover the whole range |
| ~`0x600a0xxx`–`0x600a9xxx` | BTM ACL/inquiry/connection event-handler cluster + the top-level **HCI event dispatcher** (`FUN_600a89f0`) and HCI-EVT trace/forward (`btu_hci_forward_all_event` @ `0x600a86d0`) |
| ~`0x600aaxxx`–`0x600b02xx` | **GATT client/server core**, confirmed by session-8 string sweep from end to end: `GATTC_Read` (`0x600ab620`), `gatts_process_primary_service_req` (`0x600ae4e0`), `GATTS_CreateService`/`GATTS_DeleteService`/`GATTS_StartService`/`GATTC_Write` (`0x600ab110`–`0x600ab778`), the `gatt_*`/`gatts_*` internal-helper family (signing, enc-complete, pending-indication queues, read/read-multi/read-by-type request handlers, `gatt_end_operation`/`gatt_cleanup_upon_disc`) filling `0x600ac014`–`0x600b02e0` essentially without gaps |
| ~`0x600b07xx`–`0x600b4e40` | **HCI command-send layer, `btsnd_hcic_*`** — session 8 confirmed essentially the *entire* Bluetooth Core Spec HCI command set is implemented here (~123 functions total between sessions 7–8: 34 LE commands `0x600b0824`–`0x600b1e00`, ~89 classic commands `0x600b1e58`–`0x600b4e40`), all identical shape, opcode-verified where checked (Evidence §2) |
| ~`0x600b5xxx`–`0x600b9fxx` | **L2CAP** — session 7 mis-identified this as "GATT-client attribute-cache"; session 8's string sweep corrected it: `l2c_csm_*` (channel state machine: closed/orig_w4_sec_comp/term_w4_sec_comp/w4_l2cap(a)_connect_rsp/config/w4_l2cap(a)_disconnect_rsp, `0x600b5ec8`–`0x600b70f4`), `l2c_fcr_*` (flow-control/retransmission: clone_buf/send_S_frame/proc_pdu, `0x600b742c`–`0x600b7800`), `l2c_link_hci_disc_comp`/`l2c_link_segments_xmitted` (`0x600b8ba4`, `0x600b9d94`), and `l2c_rcv_acl_data` (`0x600b9e28`, the ACL-data entry point that calls `FUN_600ba1c4`) — see prose below. `FUN_600b5e00` itself (the dispatcher feeding all the `l2c_csm_*` state handlers) is very likely `l2c_csm_execute`, not yet string-confirmed. `FUN_600b9408` (16 callers, GATT-cache-shaped in session 7's read) is now more plausibly an L2CAP-internal sub-routine given its neighbors, not re-examined this session. |
| ~`0x600ba1c4` | `FUN_600ba1c4` (3,898B, session 6) — an ATT/GATT-shaped TLV/PDU parser called *from* `l2c_rcv_acl_data`; given it now sits inside the confirmed L2CAP layer rather than a GATT-client cluster, it's more likely L2CAP's own basic-mode PDU dispatch/reassembly (e.g. `l2c_process_held_packets`-shaped) than an ATT parser per se — re-open as a naming question, not re-examined this session |
| ~`0x600bda54`–`0x600bfeec` | **SDP** (service discovery) — `SDP_AddUuidSequence`/`SDP_AddProtocolList`/`SDP_AddServiceClassIdList` (public API, `0x600bda54`–`0x600bdb7c`), `sdp_data_ind` (`0x600be100`, PDU receive entry point, sibling of `smp_data_ind`/`l2c_rcv_acl_data`), `sdpu_release_ccb`/`sdpu_build_n_send_error`/`sdpu_build_partial_attrib_entry` (`0x600bf374`–`0x600bfeec`) plus the session-7 `ServiceSearchAttributeResponse` PDU builders |
| ~`0x600c0ac4`–`0x600c239c` | **SMP** — Security Manager Protocol proper: `smp_encrypt_data` (`0x600c0ac4`), the local P-256/P-192 ECDH keypair-generation cluster (`FUN_600c0f34`→`FUN_600c1030`→`FUN_600c8798`, see prose), `smp_data_ind` (`0x600c1864`), the central FSM dispatcher `smp_sm_event`-shaped (`FUN_600c1a34`, 54 callers), and the full `smp_build_*` PDU-builder family (pairing/confirm/rand/encrypt-info/master-id/identity-info/id-addr/signing-info/pairing-fail/security-request/pair-public-key/pair-commitm/pair-dhkey-check/keypr-notif/reject-unexp, `0x600c1c30`–`0x600c239c`) |
| ~`0x600c2604`–`0x600c51d0` | **BTA DM** search/discovery/SDP-result/ACL-change flow — session 7 guessed "SMP/pairing state helpers" for part of this range; session 8's string sweep corrects that: `bta_dm_enable`/`bta_dm_search_start`/`bta_dm_search_cancel`/`bta_dm_discover`/`bta_dm_di_disc*`/`bta_dm_inq_cmpl*`/`bta_dm_sdp_result`/`bta_dm_disc_result`/`bta_dm_free_sdp_db`/`bta_dm_queue_*`/`bta_dm_find_services`/`bta_dm_discover_*`/`bta_dm_remname_cback`/`bta_dm_acl_change`/`bta_dm_disable_conn_down_timer_cback`, `0x600c2604`–`0x600c51d0` — no SMP functions actually live in this band |
| ~`0x600c5db0`–`0x600c6ad0` | BTA DM/GATTC/GATTS tail: `bta_dm_gatt_disc_complete`, `bta_gattc_disc_cmpl`/`conn_cback`/`process_api_refresh`/`cmpl_cback`/`register` (`bta_gattc_register` session-7-named @ `0x600c611c`), `bta_gatts_register` |
| ~`0x600c74xx`–`0x600c9cxx` | Mixed: the leading ~1,800 bytes (`FUN_600c74a0`, `FUN_600c80fc`) are **not conclusively identified** — large-buffer parser/formatter shape, no bignum-helper callees seen — despite sitting inside this range; from `FUN_600c8798` onward is confirmed **BoringSSL EC field arithmetic**: NIST P-256 Solinas reduction + a second (P-192-shaped) sibling, sharing bignum compare/subtract primitives with helpers just outside this block (`0x60100xxx`, in decompile-status run #2 — a good next-session lead, see below). `FUN_600c8798` is now further confirmed as **EC scalar multiplication** (windowed double-and-add, curve-parameterized), directly called from SMP's keypair-gen wrapper — see prose below. |

Two clusters outside the main `0x60092xxx`–`0x600c9xxx` span are also now confirmed part of this same object-file group (found via string xref, not yet folded into the byte/function counts above since they sit past `0x600c9cc4`): `bte_hcisu_*` (`send`/`lp_allow_bt_device_sleep`/`task`/`start_quick_timer`, `0x6006b98c`–`0x6006bb68`) and `bta_gattc_ci_cache_*`/`bta_sys_hw_ci_*` (`0x6006d8f0`–`0x6006d9f0`, plus two at `0x600d91xx`) — evidently the HCI-transport and cache/persistence glue link into earlier/later object files rather than staying inside the single contiguous block. Also, `FUN_600c1a34` (`smp_sm_event`)'s 54 callers include many addresses in `0x600faxxx`–`0x600fcxxx`, which is **decompile-status run #2** (`0x600ecb72`–`0x6013d4e4`) — strong evidence that run #2 contains the bulk of the actual SMP per-state handler functions (the ones that call into the FSM dispatcher), making it a much higher-value next target than its 28.8% density alone would suggest.

## Functions decompiled session 7 (67 new + 2 pre-existing = 69 of 1,076 at session-7 end)

Sorted by address. "Named" = identified via the BTA string-table cross-reference (§ Evidence 1) or spec-opcode match; everything else is inferred from call-graph position, callee shape, and neighborhood. Five rows below are corrected from session 7's original guesses (see session-8 addendum note at top of doc and the table below).

| Address | Bytes | Name / description |
|---|---:|---|
| `0x600921b8` | 650 | CRC-32 (table-driven, slice-style, `~crc` init/final) — generic utility, not BT-specific |
| `0x60093a30` | 734 | BTA DM power-management helper (link-policy mode select); calls `0x60093d20` |
| `0x60093d20` | 1164 | BTA DM power-management state handler (park/sniff mode negotiation) |
| `0x6009430c` | 98 | **`bta_dm_pm_btm_cback`** (named) — allocates+queues a small event record from a BTM PM callback |
| `0x60096e38` | 606 | **`hcisu_h4_send_msg_now`** (named) — H4 UART HCI transport send |
| `0x60097b20` | 668 | BTM link-policy/mode-change helper (operates on global `DAT_60098190`-rooted link record) |
| `0x60097f5c` | 564 | BTM link-policy/mode-change helper, sibling of above |
| `0x6009ad00` | 604 | ACL/security link-record field updater (writes link-key/mode flags by selector byte) |
| `0x6009b368` | 582 | LE connection-complete-style event parser — called from the LE-Meta sub-dispatch (`0x600f2f9a`/`0x600f2fba`) inside the HCI event dispatcher |
| `0x6009cf8c` | 2464 | BTM/GAP **advertising & EIR data assembler** — AD-type bytes match spec (Flags, Appearance, Local Name, UUID16/32/128 lists, TX Power, Conn-Interval-Range, Service Data) |
| `0x600a08c4` | 758 | BTM link-mode config helper (bitfield ORed into a global at `+0xaf0`) |
| `0x600a1900` | 602 | BTM/inquiry helper; calls `btsnd_hcic_write_cur_iac_lap` (`0x600b3b2c`) |
| `0x600a2ab0` | 944 | Inquiry/EIR-result parser, called from HCI-event sub-handlers `0x600f2120`/`0x600f213c` |
| `0x600a44bc` | 850 | ACL/connection-complete handler, called from HCI-event sub-handlers `0x600f1ad4`/`0x600f1b34` |
| `0x600a4c5c` | 1346 | BTM connection-state helper; caller/callee of the `0x600a5xxx`/`0x600a7xxx` cluster |
| `0x600a51a8` | 908 | BTM connection setup/auth helper (takes a `code*` callback param) |
| `0x600a59d0` | 1236 | BTM connection-state helper (sibling of `0x600a4c5c`) |
| `0x600a5ec8` | 682 | ACL-event handler, called from LE-Meta sub-dispatch `0x600f2dfa` |
| `0x600a62cc` | 680 | ACL-event handler, called from LE-Meta sub-dispatch (`0x600f2e2e/0x600f2e4a/0x600f2e66`) |
| `0x600a67ec` | 686 | ACL/encryption-change-style handler, called from HCI event sub-handler `0x600f21ba` |
| `0x600a6d70` | 1246 | BTM ACL/connection helper, calls `0x6009a72c` (BD_ADDR-shaped compare) |
| `0x600a7870` | 714 | ACL state-flag helper gated on a global connection-record byte at `+0x118c` |
| `0x600a86d0` | 150 | **`btu_hci_forward_all_event`** (named) — logs `"HCI EVT %s\n"` and forwards the raw HCI event buffer |
| `0x600a8778` | 608 | HCI event pre-processing/trace helper, called only from the dispatcher below (large 514B stack buffer — event-to-string formatting for BT_TRACE-style debug logging) |
| `0x600a89f0` | 1044 | **Top-level HCI event dispatcher** (`btu_hcif_process_event`-shaped) — ~50-way switch on HCI event code, nested switch on LE-Meta sub-event code; both code sets match the Bluetooth spec exactly (see Evidence §3) |
| `0x600a96d8` | 730 | ACL/connection dispatch helper aggregating many of the `0x600axxx` handlers above |
| `0x600ab620` | 316 | **`GATTC_Read`**-shaped (named via string xref) — GATT client read-by-handle API, validates handle/type, allocates a client-op record, `switch` on op-type (1,2,3,4,5) |
| `0x600ac734` | 614 | GATT client op-completion/callback helper |
| `0x600ac9a4` | 1076 | **`gatt_process_read_by_type_rsp`** (named, session 8 — corrects session 7's "GATT client op builder" guess) |
| `0x600ad228` | 590 | GATT registration-list walker (linked-list traversal keyed by a handle field) |
| `0x600ae4e0` | 396 | **`gatts_process_primary_service_req`**-shaped (named via string xref) — GATT server primary-service-discovery request handler |
| `0x600b0730` | 56 | **`gatt_add_pending_enc_channel_clcb`**-shaped (named) — tiny linked-list node allocator/pusher |
| `0x600b1090` | 142 | **`btsnd_hcic_ble_remove_from_white_list`** (named + opcode-verified `0x2012`) |
| `0x600b19c0` | 198 | **`btsnd_hcic_ble_add_device_resolving_list`** (named + opcode-verified `0x2027`) |
| `0x600b218c` | 148 | **`btsnd_hcic_disconnect`** (named + opcode-verified `0x0406`) |
| `0x600b29b8` | 144 | **`btsnd_hcic_rmt_ext_features`** (named + opcode-verified `0x041c`) |
| `0x600b3240` | 352 | **`btsnd_hcic_set_event_filter`**-shaped (named via string xref) |
| `0x600b3b2c` | 206 | **`btsnd_hcic_write_cur_iac_lap`**-shaped (named via string xref) |
| `0x600b400c` | 584 | **`btsnd_hcic_set_mws_signaling`** (named, session 8 — confirms session 7's opcode-shape guess; opcode bytes `0x70,0x0c` = `0x0c70`) |
| `0x600b4798` | 110 | **`btsnd_hcic_write_inq_tx_power`**-shaped (named via string xref) |
| `0x600b4dcc` | 110 | **`btsnd_hcic_write_secure_conns_support`**-shaped (named via string xref) |
| `0x600b5ec8` | 620 | Connection-event handler, called from `FUN_600b5e00` (the dispatcher `FUN_600ba1c4` feeds events into) |
| `0x600b6900` | 940 | Connection-event handler (sibling of above, also called from `FUN_600b5e00`); calls into GATT-cache functions `0x600bc1f8`/`0x600bc2a0` |
| `0x600b7800` | 830 | GATT-cache record builder |
| `0x600b7db8` | 725 | GATT-cache record builder (called from `0x600b7800`) |
| `0x600b81ec` | 568 | GATT-cache handle-range validator (masks param on `0xc000`) |
| `0x600b85e4` | 666 | GATT-cache list helper |
| `0x600b90d8` | 590 | Small fixed-size record parser (three 4-entry `ushort`/`short` stack arrays) |
| `0x600b9408` | 804 | GATT-cache dispatch helper (16 callers — a common sub-routine across the GATT-cache handlers) |
| `0x600b9e28` | 902 | GATT-client PDU ingress helper — calls **`FUN_600ba1c4`** (the TLV/PDU parser) and **`FUN_600bcc30`** (connection-by-handle accessor, per `bruce-misc-functions.md`) directly |
| `0x600ba1c4` | 3898 | (pre-existing, session 6) TLV/PDU parser feeding `FUN_600b5e00`'s connection-event dispatch — now situated inside the GATT-client cluster, strengthening the "ATT/GATT PDU parser" reading over a bespoke protocol |
| `0x600bbd3c` | 716 | GATT-cache record accessor, called from `FUN_600ba1c4` itself |
| `0x600bd150` | 810 | SDP-adjacent buffer builder (calls `0x600bdb7c`/`0x600bd848`/`0x600bd730`/`0x600bd65c`) |
| `0x600be150` | 1026 | SDP response builder (same shape as `0x600beb20` below, smaller) |
| `0x600be558` | 1472 | SDP response builder (sibling of `0x600beb20`) |
| `0x600beb20` | 1966 | **SDP `ServiceSearchAttributeResponse` PDU builder** — DES headers `0x35`/`0x36`, PDU opcode `7` written at `+0x15` |
| `0x600bf8ec` | 576 | SDP attribute-list byte-stream reader, called from both SDP builders above |
| `0x600c1864` | 284 | **`smp_data_ind`**-shaped (named via string xref) — SMP PDU receive/dispatch entry point |
| `0x600c223c` | 90 | **`smp_build_pair_keypr_notif_cmd`**-shaped (named via string xref) — tiny SMP command builder (keypress notification) |
| `0x600c3558` | 932 | **`bta_dm_sdp_result`** (named, session 8 — corrects session 7's "SMP/pairing state helper" guess; this is BTA DM, not SMP) |
| `0x600c3b18` | 52 | **`bta_dm_search_clear_queue`**-shaped (named via string xref) — one-line queue-free-and-clear |
| `0x600c3c00` | 618 | **`bta_dm_find_services`** (named, session 8 — corrects session 7's "SMP/pairing state helper, sibling" guess) |
| `0x600c4da8` | 1030 | **`bta_dm_acl_change`** (named, session 8 — corrects session 7's "SMP/BTA-DM pairing-flow helper" guess; purely BTA DM, no SMP involvement) |
| `0x600c611c` | 498 | **`bta_gattc_register`**-shaped (named via string xref) — GATT client app registration |
| `0x600c74a0` | 980 | Large-buffer (2×800B stack array) parser/formatter — not conclusively identified |
| `0x600c80fc` | 830 | Small fixed-field parser (no sub-calls except a memcpy-shaped thunk) — not conclusively identified |
| `0x600c8798` | 574 | EC bignum-cluster neighbor, calls `0x601004b2`/`0x601005ac`/`0x601005f6` (same helper family as the P-256/P-192 reductions) — plausibly a point-add/double step, not decompiled deeply |
| `0x600c8b24` | 1198 | 384-bit→192-bit weighted-sum bignum reduction sharing `FUN_601002bc`/`FUN_601004b2` with the P-256 function below — plausible **NIST P-192** field reduction (shape-only, constant not confirmed) |
| `0x600c8fd8` | 2764 | (pre-existing, session 6) **NIST P-256 Solinas-style modular reduction**, confirmed |

## Functions identified/decompiled session 8 (261 identified, 258 newly decompiled in-range)

Session 8 executed session 7's continuation plan: swept the remaining BTA/BTE trace-string table (317 identifier-shaped strings via bulk `FindRef.java`, plus a targeted L2CAP/`btu_task`/`smp_data_ind`-trace batch), then batch-decompiled everything found plus a handful of functions Ghidra's auto-analysis hadn't boundary-detected (the same "gap" phenomenon `btu_task` exhibits — see prose below). Zero false positives found in this pass (all string→function landings were coherent with their name, unlike the caveat noted for session 7's smaller sample). Sorted by address; `btsnd_hcic_*` HCI-command-builder functions (all identical shape, all in the already-described `FUN_6006dbac`-buffer/opcode-write pattern) are consolidated into range-summary rows with a full address:name appendix below rather than 105 near-identical individual rows.

| Address | Bytes | Name / description |
|---|---:|---|
| `0x60092920` | 74 | **BTA_DmBleScatternetEnable** (named) — BTA DM public API entry point |
| `0x60092990` | 96 | **bta_lower_level_prm_cback** (named) |
| `0x60092e5c` | 46 | **BTA_DisableBluetooth** (named) |
| `0x60092e90` | 72 | **BTA_DmSetDeviceName** (named) — BTA DM public API entry point |
| `0x60092edc` | 120 | **BTA_DmSetVisibility** (named) — BTA DM public API entry point |
| `0x60092f68` | 72 | **BTA_DmConfirm** (named) — BTA DM public API entry point |
| `0x60092fb4` | 204 | **BTA_DmAddDevice** (named) — BTA DM public API entry point |
| `0x60093084` | 82 | **BTA_DmAuthorizeReply** (named) — BTA DM public API entry point |
| `0x60093138` | 100 | **BTA_DmAddBleKey** (named) — BTA DM public API entry point |
| `0x600931a0` | 92 | **BTA_DmAddBleDevice** (named) — BTA DM public API entry point |
| `0x60093200` | 82 | **BTA_DmBleSecurityGrant** (named) — BTA DM public API entry point |
| `0x60093258` | 96 | **BTA_DmBleSetAdvConfig** (named) — BTA DM public API entry point |
| `0x600932bc` | 78 | **BTA_DmBleSetScanRspConfig** (named) — BTA DM public API entry point |
| `0x60093310` | 68 | **BTA_DmBleConfigLocalPrivacy** (named) — BTA DM public API entry point |
| `0x60093358` | 104 | **BTA_DmSetEncryption** (named) — BTA DM public API entry point |
| `0x60094590` | 98 | **BTA_GATTC_Open** (named) — BTA GATTC public API entry point |
| `0x600945f8` | 84 | **BTA_GATTC_CancelOpen** (named) — BTA GATTC public API entry point |
| `0x60094650` | 58 | **BTA_GATTC_Close** (named) — BTA GATTC public API entry point |
| `0x60094690` | 118 | **BTA_GATTC_ServiceSearchRequest** (named) — BTA GATTC public API entry point |
| `0x6009470c` | 66 | **BTA_GATTC_Refresh** (named) — BTA GATTC public API entry point |
| `0x60094754` | 104 | **bta_gattc_alloc_cache_buf** (named) — BTA GATTC internal helper |
| `0x600947c0` | 168 | **bta_gattc_init_cache** (named) — BTA GATTC internal helper |
| `0x6009496c` | 194 | **bta_gattc_sdp_service_disc** (named) — BTA GATTC internal helper |
| `0x60094c5c` | 196 | **bta_gattc_rebuild_cache** (named) — BTA GATTC internal helper |
| `0x60095234` | 192 | **bta_gattc_srcb_alloc** (named) — BTA GATTC internal helper |
| `0x60095650` | 58 | **BTA_GATTS_AppDeregister** (named) — BTA GATTS public API entry point |
| `0x60095690` | 108 | **BTA_GATTS_CreateService** (named) — BTA GATTS public API entry point |
| `0x60095700` | 114 | **BTA_GATTS_AddCharacteristic** (named) — BTA GATTS public API entry point |
| `0x60095778` | 110 | **BTA_GATTS_AddCharDescriptor** (named) — BTA GATTS public API entry point |
| `0x600957ec` | 60 | **BTA_GATTS_DeleteService** (named) — BTA GATTS public API entry point |
| `0x6009582c` | 72 | **BTA_GATTS_StartService** (named) — BTA GATTS public API entry point |
| `0x60095878` | 136 | **BTA_GATTS_HandleValueIndication** (named) — BTA GATTS public API entry point |
| `0x60095904` | 132 | **BTA_GATTS_SendRsp** (named) — BTA GATTS public API entry point |
| `0x6009598c` | 60 | **BTA_GATTS_Close** (named) — BTA GATTS public API entry point |
| `0x60095f38` | 94 | **bta_sys_hw_btm_cback** (named) — BTA SYS (task/event-bus) helper |
| `0x600961e0` | 84 | **bta_sys_event** (named) — BTA SYS (task/event-bus) helper |
| `0x600962dc` | 42 | **bta_sys_sendmsg** (named) — BTA SYS (task/event-bus) helper |
| `0x60096a50` | 124 | **hcisu_h4_receive_msg** (named) — HCI transport (H4) helper |
| `0x6009a7c0` | 54 | **btm_acl_reset_paging** (named) — BTM (device/link manager) internal function |
| `0x6009b77c` | 306 | **BTM_BleDataSignature** (named) — BTM (device/link manager) internal function |
| `0x6009c7c8` | 44 | **btm_ble_enqueue_direct_conn_req** (named) — BTM (device/link manager) internal function |
| `0x6009c7fc` | 64 | **btm_send_pending_direct_conn** (named) — BTM (device/link manager) internal function |
| `0x6009fa34` | 160 | **btm_ble_resolving_list_init** (named) — BTM (device/link manager) internal function |
| `0x600a1394` | 86 | **BTM_VendorSpecificCommand** (named) — BTM (device/link manager) internal function |
| `0x600a25f8` | 64 | **btm_clr_inq_result_flt** (named) — BTM (device/link manager) internal function |
| `0x600a29a0` | 258 | **btm_initiate_inquiry** (named) — BTM (device/link manager) internal function |
| `0x600a2e68` | 194 | **btm_sort_inq_result** (named) — BTM (device/link manager) internal function |
| `0x600a5760` | 210 | **btm_sec_check_pending_reqs** (named) — BTM (device/link manager) internal function |
| `0x600a81ac` | 116 | **btm_sec_queue_mx_request** (named) — BTM (device/link manager) internal function |
| `0x600a8228` | 110 | **btm_sec_queue_encrypt_request** (named) — BTM (device/link manager) internal function |
| `0x600a85b8` | 270 | **btu_hcif_store_cmd** (named) — BTU (upper HCI/task) internal function |
| `0x600a943c` | 312 | **btu_hcif_command_complete_evt_1** (named) — BTU (upper HCI/task) internal function |
| `0x600a957c` | 338 | **btu_hcif_command_complete_evt** (named) — BTU (upper HCI/task) internal function |
| `0x600a99cc` | 302 | **btu_hcif_command_status_evt_1** (named) — BTU (upper HCI/task) internal function |
| `0x600a9b04` | 318 | **btu_hcif_command_status_evt** (named) — BTU (upper HCI/task) internal function |
| `0x600a9e14` | 78 | **btu_hcif_flush_cmd_queue** (named) — BTU (upper HCI/task) internal function |
| `0x600a9fce` | 674 | **btu_task** (named) — **central BTU RTOS task loop** — GKI-mailbox message pump; dispatches HCI events into FUN_600a89f0, ACL data into l2c_rcv_acl_data, segment-tx into l2c_link_segments_xmitted, HCI cmd-send via FUN_600a9234, plus two registered-callback dispatch tables (see prose) |
| `0x600aa340` | 128 | **btu_start_timer** (named) — BTU (upper HCI/task) internal function |
| `0x600aa3cc` | 96 | **btu_stop_timer** (named) — BTU (upper HCI/task) internal function |
| `0x600aa438` | 126 | **btu_start_quick_timer** (named) — BTU (upper HCI/task) internal function |
| `0x600aa4f4` | 44 | **btu_process_quick_timer_evt** (named) — BTU quick-timer expiry handler, called from btu_task bit 0x40 |
| `0x600ab110` | 502 | **GATTS_CreateService** (named) — GATT public API entry point |
| `0x600ab318` | 252 | **GATTS_DeleteService** (named) — GATT public API entry point |
| `0x600ab424` | 304 | **GATTS_StartService** (named) — GATT public API entry point |
| `0x600ab778` | 272 | **GATTC_Write** (named) — GATT public API entry point |
| `0x600ac014` | 270 | **gatt_sign_data** (named) — GATT client/server core helper |
| `0x600ac128` | 256 | **gatt_enc_cmpl_cback** (named) — GATT client/server core helper |
| `0x600ac22c` | 114 | **gatt_notify_enc_cmpl** (named) — GATT client/server core helper |
| `0x600ac9a4` | 1076 | **gatt_process_read_by_type_rsp** (corrected from session-7 guess) — GATT client/server core helper |
| `0x600acddc` | 368 | **gatt_process_read_rsp** (named) — GATT client/server core helper |
| `0x600ad710` | 224 | **gatt_congest_handler** (named) — GATT client/server core helper |
| `0x600ad7fc` | 102 | **gatt_channel_congestion** (named) — GATT client/server core helper |
| `0x600ad868` | 68 | **gatt_le_data_ind** (named) — GATT client/server core helper |
| `0x600ad9d8` | 142 | **gatt_data_process** (named) — GATT client/server core helper |
| `0x600adc88` | 84 | **gatt_dequeue_sr_cmd** (named) — GATT client/server core helper |
| `0x600adeb4` | 542 | **gatt_process_read_multi_req** (named) — GATT client/server core helper |
| `0x600ae670` | 378 | **gatts_process_find_info** (named) — GATT server internal helper |
| `0x600ae90c` | 506 | **gatts_process_read_by_type_req** (named) — GATT server internal helper |
| `0x600aed40` | 326 | **gatts_process_read_req** (named) — GATT server internal helper |
| `0x600af020` | 80 | **gatts_chk_pending_ind** (named) — GATT server internal helper |
| `0x600af170` | 48 | **gatt_free_pending_ind** (named) — GATT client/server core helper |
| `0x600af1a4` | 46 | **gatt_free_pending_enc_queue** (named) — GATT client/server core helper |
| `0x600af2d0` | 64 | **gatt_add_pending_ind** (named) — GATT client/server core helper |
| `0x600af314` | 50 | **gatt_add_pending_new_srv_start** (named) — GATT client/server core helper |
| `0x600af350` | 56 | **gatt_add_srv_chg_clt** (named) — GATT client/server core helper |
| `0x600af4d4` | 66 | **gatt_free_hdl_buffer** (named) — GATT client/server core helper |
| `0x600af51c` | 116 | **gatt_free_srvc_db_buffer_app_id** (named) — GATT client/server core helper |
| `0x600b00b4` | 550 | **gatt_end_operation** (named) — GATT client/server core helper |
| `0x600b02e0` | 346 | **gatt_cleanup_upon_disc** (named) — GATT client/server core helper |
| `0x600b5ec8` | 620 | **l2c_csm_closed** (named) — L2CAP channel-state-machine: CLOSED state handler |
| `0x600b61c4` | 288 | **l2c_csm_orig_w4_sec_comp** (named) — L2CAP CSM: originator waiting-for-security-complete state |
| `0x600b6378` | 260 | **l2c_csm_term_w4_sec_comp** (named) — L2CAP CSM: terminator waiting-for-security-complete state |
| `0x600b6550` | 384 | **l2c_csm_w4_l2cap_connect_rsp** (named) — L2CAP CSM: waiting-for-L2CAP-connect-response state |
| `0x600b674c` | 310 | **l2c_csm_w4_l2ca_connect_rsp** (named) — L2CAP CSM: waiting-for-L2CA(upper)-connect-response state |
| `0x600b6900` | 940 | **l2c_csm_config** (named) — L2CAP CSM: CONFIG state (channel config negotiation) |
| `0x600b6fcc` | 172 | **l2c_csm_w4_l2cap_disconnect_rsp** (named) — L2CAP CSM: waiting-for-L2CAP-disconnect-response state |
| `0x600b70f4` | 154 | **l2c_csm_w4_l2ca_disconnect_rsp** (named) — L2CAP CSM: waiting-for-L2CA(upper)-disconnect-response state |
| `0x600b742c` | 166 | **l2c_fcr_clone_buf** (named) — L2CAP FCR (flow-control/retransmission mode): clone a GKI buffer |
| `0x600b7674` | 390 | **l2c_fcr_send_S_frame** (named) — L2CAP FCR: build+send a Supervisory frame |
| `0x600b7800` | 830 | **l2c_fcr_proc_pdu** (named) — L2CAP FCR: process an incoming I/S-frame PDU |
| `0x600b8ba4` | 460 | **l2c_link_hci_disc_comp** (named) — L2CAP link layer: HCI disconnect-complete handler |
| `0x600b9d94` | 144 | **l2c_link_segments_xmitted** (named) — L2CAP link layer: segment-transmitted event handler |
| `0x600b9e28` | 902 | **l2c_rcv_acl_data** (named) — L2CAP: **top-level ACL-data receive entry point** — dispatches into l2c_fcr_proc_pdu / FUN_600ba1c4 (basic-mode PDU parser) |
| `0x600bda54` | 86 | **SDP_AddUuidSequence** (named) — SDP (service discovery) function |
| `0x600bdaaa` | 100 | **SDP_AddUuidSequence** (named) — SDP (service discovery) function |
| `0x600bdb14` | 98 | **SDP_AddProtocolList** (named) — SDP (service discovery) function |
| `0x600bdb7c` | 162 | **SDP_AddServiceClassIdList** (named) — SDP (service discovery) function |
| `0x600be100` | 76 | **sdp_data_ind** (named) — SDP (service discovery) function |
| `0x600bf374` | 60 | **sdpu_release_ccb** (named) — SDP (service discovery) function |
| `0x600bf5a4` | 246 | **sdpu_build_n_send_error** (named) — SDP (service discovery) function |
| `0x600bfeec` | 148 | **sdpu_build_partial_attrib_entry** (named) — SDP (service discovery) function |
| `0x600c0ac4` | 442 | **smp_encrypt_data** (named) — SMP (Security Manager Protocol) function |
| `0x600c1c30` | 160 | **smp_build_pairing_cmd** (named) — SMP command-PDU builder |
| `0x600c1cd4` | 102 | **smp_build_confirm_cmd** (named) — SMP command-PDU builder |
| `0x600c1d40` | 102 | **smp_build_rand_cmd** (named) — SMP command-PDU builder |
| `0x600c1dac` | 102 | **smp_build_encrypt_info_cmd** (named) — SMP command-PDU builder |
| `0x600c1e18` | 138 | **smp_build_master_id_cmd** (named) — SMP command-PDU builder |
| `0x600c1ea8` | 114 | **smp_build_identity_info_cmd** (named) — SMP command-PDU builder |
| `0x600c1f20` | 128 | **smp_build_id_addr_cmd** (named) — SMP command-PDU builder |
| `0x600c1fa4` | 102 | **smp_build_signing_info_cmd** (named) — SMP command-PDU builder |
| `0x600c2010` | 90 | **smp_build_pairing_fail** (named) — SMP command-PDU builder |
| `0x600c2070` | 90 | **smp_build_security_request** (named) — SMP command-PDU builder |
| `0x600c20d0` | 144 | **smp_build_pair_public_key_cmd** (named) — SMP command-PDU builder |
| `0x600c2164` | 102 | **smp_build_pair_commitm_cmd** (named) — SMP command-PDU builder |
| `0x600c21d0` | 102 | **smp_build_pair_dhkey_check_cmd** (named) — SMP command-PDU builder |
| `0x600c239c` | 84 | **smp_reject_unexp_pair_cmd** (named) — SMP (Security Manager Protocol) function |
| `0x600c2604` | 138 | **bta_dm_enable** (named) — BTA DM internal helper |
| `0x600c2f68` | 280 | **bta_dm_search_start** (named) — BTA DM internal helper |
| `0x600c309c` | 168 | **bta_dm_search_cancel** (named) — BTA DM internal helper |
| `0x600c3150` | 242 | **bta_dm_discover** (named) — BTA DM internal helper |
| `0x600c32c4` | 68 | **bta_dm_di_disc_callback** (named) — BTA DM internal helper |
| `0x600c3368` | 116 | **bta_dm_di_disc** (named) — BTA DM internal helper |
| `0x600c3450` | 198 | **bta_dm_inq_cmpl** (named) — BTA DM internal helper |
| `0x600c3558` | 932 | **bta_dm_sdp_result** (corrected from session-7 guess) — BTA DM internal helper |
| `0x600c3960` | 86 | **bta_dm_disc_result** (named) — BTA DM internal helper |
| `0x600c3a50` | 46 | **bta_dm_free_sdp_db** (named) — BTA DM internal helper |
| `0x600c3a88` | 62 | **bta_dm_queue_search** (named) — BTA DM internal helper |
| `0x600c3ad0` | 62 | **bta_dm_queue_disc** (named) — BTA DM internal helper |
| `0x600c3b88` | 52 | **bta_dm_search_cancel_transac_cmpl** (named) — BTA DM internal helper |
| `0x600c3c00` | 618 | **bta_dm_find_services** (corrected from session-7 guess) — BTA DM internal helper |
| `0x600c3e84` | 118 | **bta_dm_discover_next_device** (named) — BTA DM internal helper |
| `0x600c3f04` | 346 | **bta_dm_discover_device** (named) — BTA DM internal helper |
| `0x600c41c0` | 130 | **bta_dm_inq_cmpl_cb** (named) — BTA DM internal helper |
| `0x600c4320` | 142 | **bta_dm_remname_cback** (named) — BTA DM internal helper |
| `0x600c4da8` | 1030 | **bta_dm_acl_change** (corrected from session-7 guess) — BTA DM internal helper |
| `0x600c51d0` | 74 | **bta_dm_disable_conn_down_timer_cback** (named) — BTA DM internal helper |
| `0x600c5db0` | 232 | **bta_dm_gatt_disc_complete** (named) — BTA DM internal helper |
| `0x600c63e0` | 228 | **bta_gattc_disc_cmpl** (named) — BTA GATTC internal helper |
| `0x600c6654` | 142 | **bta_gattc_conn_cback** (named) — BTA GATTC internal helper |
| `0x600c66e8` | 186 | **bta_gattc_process_api_refresh** (named) — BTA GATTC internal helper |
| `0x600c68fc` | 218 | **bta_gattc_cmpl_cback** (named) — BTA GATTC internal helper |
| `0x600c6ad0` | 472 | **bta_gatts_register** (named) — BTA GATTS internal helper |

TOTAL non-hcic rows: 152
TOTAL hcic entries (consolidated separately): 105
| `0x600929f0`-`0x60092de8` | ~1016 | **bta_prm_hdl_event**-adjacent (partial) — a ~1KB unrecognized-by-autoanalysis function region (like `btu_task`'s gap); `FUN_60092ada` (40B) carved out of it confirms the `bta_prm_hdl_event` string xref; also holds the 2 `BTA_PatchRam` xrefs (`0x60092d68`, `0x60092db4`) — full function boundary not yet resolved, treat as a lead not a closed ID |
| `0x600a9f10` | 190 | `btu_task`'s immediate predecessor — near-identical body (same event-group-wait/GKI-mailbox-pump shape as `btu_task` below) with extra one-time setup calls (`FUN_6006be9c`, `FUN_600d9380(10)`, thunks `0x600f31c6`/`0x600d908e`/`0x60095df4`, `FUN_6006e6a8(5,1)`) — plausibly the real task-entry trampoline that does init then pumps once before falling through to steady-state `btu_task`, or a second near-duplicate GKI task; not string-confirmed itself but structurally inseparable from `btu_task` |
| `0x600a9fce` | 674 | **btu_task** (named — 3 self-referencing xrefs to the `"btu_task"` string @ `0x601167fc`) — see prose below |
| `0x6009436e` | 2 (Ghidra size, real body larger) | **bta_dm_pm_timer_cback** (named) — walks a 3-entry PM-mode table, on match decrements a use-count and marks a "pending" byte; sends a GKI event (id `0x112`) via `bta_sys_sendmsg`-shaped `FUN_600962dc` when the table entry is freed |
| `0x60094942` | 32 | **bta_gattc_sdp_callback** (named) — small SDP-completion callback stub, zeroes two client-record fields |
| `0x600c405e` | 2 (Ghidra size, real body larger) | **bta_dm_sdp_callback** (named) — allocates a GKI event buffer (id `0x205`), sets a 2-field header, sends via `bta_sys_sendmsg`-shaped `FUN_600962dc` |
| `0x600c4c6a` | 110 | **bta_dm_acl_change_cback** (named) — allocates a 0x18-byte ACL-change event record, populates address/type fields, sends via `bta_sys_sendmsg`-shaped `FUN_600962dc` with event id `0x109` |
| `0x600c556e` | 2 (Ghidra size, real body larger) | **bta_dm_set_encryption** (named) — scans a device-record table for a matching entry, maps an encryption-algorithm param to a status code (0/3/4/5), invokes the record's callback function pointer with `(2, param_2, status)` |
| `0x600c0f34` | 230 | SMP local-keypair-entropy state machine — cases 9/10/11/12 each copy 8 bytes of `btsnd_hcic_ble_rand` output into a 32-byte private-key buffer at `param_1+0x6d..0x85`; on the 4th chunk (case 0xc) calls `FUN_600c1030` to generate the P-256 keypair. Called only from `FUN_600c15a8` (mutual recursion / re-entry per random-command completion) |
| `0x600c1030` | 112 | SMP local P-256/P-192 keypair generator — copies the 32-byte accumulated private key, calls `FUN_600c8798` (EC scalar multiplication) with base point `DAT_600c10a0` (curve generator G) and the private key as scalar, writes the resulting 32+32-byte public-key X/Y coordinates into the SMP control block, then re-enters the state machine via `FUN_600c1a34` (event `0x1c`) |
| `0x600c1a34` | 220 | **smp_sm_event**-shaped — SMP's central finite-state-machine dispatcher: 2D `[state][event]`→action-index lookup table (`DAT_600c1b10`), then walks a second table of function pointers (`DAT_600c1b1c`) executing up to 2 actions per event; 54 static callers across the whole SMP module (every `smp_build_*`/`smp_data_ind`/keypair-gen function reaches it) — textbook BTE `smp_sm_event` shape |
| `0x600b0824`–`0x600b1e00` | (34 funcs) | **`btsnd_hcic_ble_*`** — the full LE HCI command-send sub-family (named, session 8). Full list in appendix below. |
| `0x600b1e58`–`0x600b4e40` | (71 funcs) | **`btsnd_hcic_*`** (classic/BR-EDR) — the remaining classic HCI command-send functions beyond session 7's original 8 (named, session 8). Full list in appendix below. |

### Appendix: full `btsnd_hcic_*` list (105 functions, session 8)

`0x600b0824` btsnd_hcic_ble_set_evt_mask &nbsp;&nbsp; `0x600b08ac` btsnd_hcic_ble_read_buffer_size &nbsp;&nbsp; `0x600b0910` btsnd_hcic_ble_read_local_spt_feat  
`0x600b0974` btsnd_hcic_ble_set_random_addr &nbsp;&nbsp; `0x600b09f8` btsnd_hcic_ble_write_adv_params &nbsp;&nbsp; `0x600b0b00` btsnd_hcic_ble_set_adv_data  
`0x600b0bb0` btsnd_hcic_ble_set_scan_rsp_data &nbsp;&nbsp; `0x600b0c60` btsnd_hcic_ble_set_adv_enable &nbsp;&nbsp; `0x600b0cd4` btsnd_hcic_ble_set_scan_params  
`0x600b0da8` btsnd_hcic_ble_set_scan_enable &nbsp;&nbsp; `0x600b0e2c` btsnd_hcic_ble_create_ll_conn &nbsp;&nbsp; `0x600b0fc8` btsnd_hcic_ble_create_conn_cancel  
`0x600b102c` btsnd_hcic_ble_read_white_list_size &nbsp;&nbsp; `0x600b1124` btsnd_hcic_ble_upd_ll_conn_params &nbsp;&nbsp; `0x600b1264` btsnd_hcic_ble_set_host_chnl_class  
`0x600b12e4` btsnd_hcic_ble_read_remote_feat &nbsp;&nbsp; `0x600b1368` btsnd_hcic_ble_rand &nbsp;&nbsp; `0x600b13dc` btsnd_hcic_ble_start_enc  
`0x600b14b8` btsnd_hcic_ble_ltk_req_reply &nbsp;&nbsp; `0x600b1558` btsnd_hcic_ble_ltk_req_neg_reply &nbsp;&nbsp; `0x600b15dc` btsnd_hcic_ble_read_supported_states  
`0x600b1640` btsnd_hcic_ble_write_host_supported &nbsp;&nbsp; `0x600b16c4` btsnd_hcic_ble_rc_param_req_reply &nbsp;&nbsp; `0x600b1804` btsnd_hcic_ble_rc_param_req_neg_reply  
`0x600b1898` btsnd_hcic_ble_set_data_length &nbsp;&nbsp; `0x600b195c` btsnd_hcic_ble_read_dflt_data_length &nbsp;&nbsp; `0x600b1a8c` btsnd_hcic_ble_rm_device_resolving_list  
`0x600b1b20` btsnd_hcic_ble_clear_resolving_list &nbsp;&nbsp; `0x600b1b84` btsnd_hcic_ble_read_resolving_list_size &nbsp;&nbsp; `0x600b1be8` btsnd_hcic_ble_read_resolvable_addr_peer  
`0x600b1c7c` btsnd_hcic_ble_set_addr_resolution_enable &nbsp;&nbsp; `0x600b1cf0` btsnd_hcic_ble_set_rand_priv_addr_timeout &nbsp;&nbsp; `0x600b1d74` btsnd_hcic_ble_set_default_phy  
`0x600b1e00` btsnd_hcic_any &nbsp;&nbsp; `0x600b1e58` btsnd_hcic_inquiry &nbsp;&nbsp; `0x600b1ef8` btsnd_hcic_inq_cancel  
`0x600b1f5c` btsnd_hcic_per_inq_mode &nbsp;&nbsp; `0x600b203c` btsnd_hcic_exit_per_inq &nbsp;&nbsp; `0x600b20a0` btsnd_hcic_create_conn  
`0x600b2224` btsnd_hcic_create_conn_cancel &nbsp;&nbsp; `0x600b22a8` btsnd_hcic_accept_conn &nbsp;&nbsp; `0x600b233c` btsnd_hcic_reject_conn  
`0x600b23d0` btsnd_hcic_link_key_req_reply &nbsp;&nbsp; `0x600b2474` btsnd_hcic_link_key_neg_reply &nbsp;&nbsp; `0x600b24f8` btsnd_hcic_pin_code_req_reply  
`0x600b25c8` btsnd_hcic_pin_code_neg_reply &nbsp;&nbsp; `0x600b264c` btsnd_hcic_auth_request &nbsp;&nbsp; `0x600b26d0` btsnd_hcic_set_conn_encrypt  
`0x600b2764` btsnd_hcic_change_link_key &nbsp;&nbsp; `0x600b27e8` btsnd_hcic_rmt_name_req &nbsp;&nbsp; `0x600b28b0` btsnd_hcic_rmt_name_req_cancel  
`0x600b2934` btsnd_hcic_rmt_features_req &nbsp;&nbsp; `0x600b2a4c` btsnd_hcic_rmt_ver_req &nbsp;&nbsp; `0x600b2ad0` btsnd_hcic_read_rmt_clk_offset  
`0x600b2b54` btsnd_hcic_hold_mode &nbsp;&nbsp; `0x600b2c18` btsnd_hcic_sniff_mode &nbsp;&nbsp; `0x600b2d20` btsnd_hcic_exit_sniff_mode  
`0x600b2da4` btsnd_hcic_park_mode &nbsp;&nbsp; `0x600b2e68` btsnd_hcic_exit_park_mode &nbsp;&nbsp; `0x600b2eec` btsnd_hcic_switch_role  
`0x600b2f80` btsnd_hcic_write_policy_set &nbsp;&nbsp; `0x600b3028` btsnd_hcic_write_def_policy_set &nbsp;&nbsp; `0x600b30ac` btsnd_hcic_set_event_mask  
`0x600b3138` btsnd_hcic_set_event_mask_page_2 &nbsp;&nbsp; `0x600b31c4` btsnd_hcic_reset &nbsp;&nbsp; `0x600b33a4` btsnd_hcic_write_pin_type  
`0x600b3418` btsnd_hcic_delete_stored_key &nbsp;&nbsp; `0x600b34ac` btsnd_hcic_change_name &nbsp;&nbsp; `0x600b3548` btsnd_hcic_write_page_tout  
`0x600b35cc` btsnd_hcic_write_scan_enable &nbsp;&nbsp; `0x600b3640` btsnd_hcic_write_pagescan_cfg &nbsp;&nbsp; `0x600b36e8` btsnd_hcic_write_inqscan_cfg  
`0x600b3790` btsnd_hcic_write_auth_enable &nbsp;&nbsp; `0x600b3804` btsnd_hcic_write_encr_mode &nbsp;&nbsp; `0x600b3878` btsnd_hcic_write_dev_class  
`0x600b38fc` btsnd_hcic_write_auto_flush_tout &nbsp;&nbsp; `0x600b39a4` btsnd_hcic_set_host_buf_size &nbsp;&nbsp; `0x600b3a80` btsnd_hcic_write_link_super_tout  
`0x600b3c00` btsnd_hcic_write_simple_pairing_mode &nbsp;&nbsp; `0x600b3c74` btsnd_hcic_io_cap_req_reply &nbsp;&nbsp; `0x600b3d28` btsnd_hcic_io_cap_req_neg_reply  
`0x600b3dbc` btsnd_hcic_set_mws_chann_param &nbsp;&nbsp; `0x600b3ec0` btsnd_hcic_set_ext_frame_config &nbsp;&nbsp; `0x600b400c` btsnd_hcic_set_mws_signaling  
`0x600b4258` btsnd_hcic_set_mws_trans_layer &nbsp;&nbsp; `0x600b434c` btsnd_hcic_set_mws_scan_freq_table &nbsp;&nbsp; `0x600b4450` btsnd_hcic_set_mws_pattern_config  
`0x600b4548` btsnd_hcic_get_mws_trans_layer_config &nbsp;&nbsp; `0x600b45b4` btsnd_hcic_user_conf_reply &nbsp;&nbsp; `0x600b4658` btsnd_hcic_user_passkey_reply  
`0x600b4714` btsnd_hcic_user_passkey_neg_reply &nbsp;&nbsp; `0x600b480c` btsnd_hcic_read_local_ver &nbsp;&nbsp; `0x600b4878` btsnd_hcic_read_local_supported_cmds  
`0x600b48e4` btsnd_hcic_read_local_features &nbsp;&nbsp; `0x600b4948` btsnd_hcic_read_local_ext_features &nbsp;&nbsp; `0x600b49bc` btsnd_hcic_read_buffer_size  
`0x600b4a20` btsnd_hcic_read_bd_addr &nbsp;&nbsp; `0x600b4a84` btsnd_hcic_get_link_quality &nbsp;&nbsp; `0x600b4b08` btsnd_hcic_read_rssi  
`0x600b4b8c` btsnd_hcic_enable_test_mode &nbsp;&nbsp; `0x600b4bf0` btsnd_hcic_set_afh_host_channel_class &nbsp;&nbsp; `0x600b4c70` btsnd_hcic_write_inqscan_type  
`0x600b4ce4` btsnd_hcic_write_inquiry_mode &nbsp;&nbsp; `0x600b4d58` btsnd_hcic_write_pagescan_type &nbsp;&nbsp; `0x600b4e40` btsnd_hcic_read_authenticated_payload_tout  


## What's decompiled vs. what's left, and how to continue

- **327 of 1,076 functions decompiled** (up from 69 at session-7 end, 2 at session-6 end) — **~93,400 of 204,449 code bytes (~45.7%)**, up from ~11%. **749 functions / ~111,000 bytes remain.**
- Session 8 fully executed session 7's plan item 1 (the ~388-remaining-string sweep): 317 identifier-shaped strings checked in bulk via `FindRef.java`, yielding 245 in-range hits (zero false positives on manual spot-check) plus 44 "no-func" hits (string referenced from code, but landing in a gap Ghidra's auto-analysis hadn't recognized as a function — see `bta_prm_hdl_event` below) and 15 with no resolvable xref at all (consumed via an unresolved data table, matching the known limitation). A further 44 non-identifier-shaped strings (mostly `BTA_GATT_*` status-code names) turned out to be a pure error-code→string lookup table at `0x60108ab8`–`0x60108d00`, referenced from *data*, not from any self-naming function — a dead end for identification purposes, noted so it isn't re-attempted.
- **The `bta_prm_hdl_event`/`BTA_PatchRam` gap** (`0x600929f0`–`0x60092de8`, ~1KB) and 5 similar small gaps (`bta_dm_pm_timer_cback`, `bta_gattc_sdp_callback`, `bta_dm_sdp_callback`, `bta_dm_acl_change_cback`, `bta_dm_set_encryption`) are all cases where a function is reached only via a registered callback pointer and Ghidra's auto-analysis never created a function there — the same phenomenon that hid `btu_task` (see prose below). All 6 were manually resolved this session via `disassemble()`+`createFunction()` at the exact xref site. **This pattern (string xref lands with "no func") is worth treating as a signal, not just a dead end** — it may catch more hidden callback-only functions in the remaining ~749.
- Both layers session 7 flagged as "not yet touched" are now substantially covered: **L2CAP** (found to be the actual identity of the `0x600b5xxx`–`0x600b9fxx` range, previously mis-labeled GATT-client — see address-range map and prose below) and **BTA_GATTS_*** (full server-side API surface named: `CreateService`/`DeleteService`/`AddCharacteristic`/`AddCharDescriptor`/`StartService`/`HandleValueIndication`/`SendRsp`/`Close`/`AppDeregister`). **RFCOMM/SPP/HFP still not found** — the `[RFCOMM]` tag string exists (`0x60121a14`) but no `rfc_*`/`port_*` function-name strings turned up in this session's identifier sweep; still an open question whether it's linked in under a different naming convention or not present at all.
- **New lead for a future session**: `smp_sm_event`'s (`0x600c1a34`) 54 callers are scattered across `0x600faxxx`–`0x600fcxxx`, which is **decompile-status run #2** (`0x600ecb72`–`0x6013d4e4`, 330KB span, only 1/1,006 decompiled) — strong circumstantial evidence that run #2 holds the actual SMP per-state handler functions (`smp_br_state`, `smp_state`, the individual pairing-flow steps), not just miscellaneous tail code as its low 28.8% density might suggest. Worth a dedicated string-xref sweep of run #2 using the same method as this session, rather than treating it as lower-priority just because of density.
- The P-256/P-192-shaped bignum helpers (`FUN_601002bc` compare, `FUN_601004b2` subtract, `FUN_60100424` add, `FUN_601005ac`, `FUN_601005f6`, `FUN_60100166`, `FUN_6010027c`) live just outside this block (~`0x60100xxx`, inside decompile-status run #2) and are still a good, tightly-scoped next target — they'd both nail down the P-192 guess and likely connect to `bruce-crypto.md`'s already-documented EVP/ASN.1 registry (same address neighborhood as the `0x6010b9xx` `EVP_PKEY_ASN1_METHOD` table).
- `FUN_600c74a0`/`FUN_600c80fc` (the ~1,800-byte "not conclusively identified" pair right before the EC crypto cluster) remain unidentified — not investigated this session.
- **Tooling note confirmed this session**: the `$ADDRS`-variable-mangling bug from session 7 is specifically about *quoting* — `"$ADDRS"` (quoted) collapses to one string argument and breaks; `$(cat file)` **unquoted** word-splits correctly and was used successfully throughout this session for batches up to 28 addresses per `Decompile.java`/`FindRef.java` invocation. Root-caused, not just avoided.
- All work this session was `-process -noanalysis` only; no `-import`/`-overwrite`, no commits, per constraints.

## Relevance to other open threads (CLAUDE.md)

- **Main event/dispatch loop (thread 3) — substantially closed for the BT stack.** `FUN_600a9fce` self-references the string `"btu_task"` (`0x601167fc`) three times — it **is** `btu_task`, the central BTU-layer RTOS task. It was invisible to auto-analysis (a ~1KB region between two recognized functions, only found by resolving the string-xref address directly, same trick as the small callback gaps above). Its body: `FUN_6006e5bc(0xffff,0)` (an event-group-wait-shaped call, blocking on up to 16 bits), then bit-tested dispatch — bit `0x10` drains a GKI-mailbox event queue with a ~20-case switch on event-record type (delegating to e.g. `FUN_600a0344`, `FUN_600bb2ac`, `FUN_600c1c04`, plus a registered-callback-table fallback), bit `4` drains a second mailbox via `FUN_600961e0`, bit `0x20`/`0x40` call periodic helpers (`FUN_6009623c`, `btu_process_quick_timer_evt`). A second loop (`LAB_600aa0d0`) drains a third mailbox (`FUN_6006df58(0)`) of raw HCI/L2CAP messages, switching on a 16-bit type-code field: `0x1000`/`0x1200`→**`FUN_600a89f0`** (the confirmed HCI event dispatcher), `0x1100`→**`l2c_rcv_acl_data`**, `0x1900`→**`l2c_link_segments_xmitted`**, `0x1600`→`FUN_600a9234` (HCI command send), plus a second registered-callback-table fallback for everything else. This is an exact structural match for BTE's real `btu_task()` — the single RTOS task that owns HCI-event dispatch, L2CAP ACL-data ingress, and HCI command transmission, all serialized through GKI mailboxes. **It is very likely the closest thing to "the" main Bluetooth dispatch loop that exists in this firmware** (as opposed to a single whole-system `main()` — bruce almost certainly runs several FreeRTOS tasks side by side; this is BT's). Not yet found: who calls `xTaskCreate`-equivalent to spawn it (not traced this session). Its immediate 190-byte predecessor `FUN_600a9f10` has near-identical body plus one-time setup calls — plausibly the task-entry trampoline, not conclusively distinguished from `btu_task` itself this session.
- **Report-packing / button-ADC threads (1, 2)**: nothing in this block touches HID reports, buttons, or ADC — it's purely the BT/BLE protocol stack. No new lead on those threads from this session.
- **Ed25519/EVP crypto callers (thread 5) — closed for the P-256 half.** Traced a complete, non-speculative call chain from PDU-receive down to modular arithmetic: **`smp_data_ind`** (`0x600c1864`, reads the SMP opcode byte from an incoming PDU) → **`FUN_600c1a34`** (`smp_sm_event`-shaped: 2D `[state][event]` lookup table dispatching through a function-pointer table, 54 static callers — the SMP FSM's central event dispatcher). Working the other direction from the confirmed P-256 code: **`FUN_600c8798`** (EC scalar multiplication — windowed double-and-add over a NAF-style digit table, curve-parameterized by a word-count argument that selects between two constant sets, i.e. handles both P-256 and the P-192-shaped sibling) is called by **`FUN_600c1030`**, which copies a 32-byte accumulated value as a scalar, multiplies it by base point `DAT_600c10a0` (almost certainly the curve generator **G**), writes the 32+32-byte result as an EC-point public key into the SMP control block, and re-enters the FSM dispatcher (`FUN_600c1a34`) with event `0x1c`. `FUN_600c1030` in turn is called only from **`FUN_600c0f34`**, a 4-state state machine that accumulates 4×8=32 bytes of `btsnd_hcic_ble_rand` (**`0x600b1368`**, the real HCI LE-Rand command) output as private-key entropy across repeated HCI command completions, calling `FUN_600c1030` once the 32nd byte arrives. So: **incoming SMP pairing traffic drives the FSM; the FSM (elsewhere, via its function-pointer table — not statically provable which entry, but structurally consistent) drives local ECDH keypair generation using controller-sourced randomness; keypair generation calls the confirmed P-256/P-192 EC scalar-multiplication code; that code calls the same modular-reduction helpers (`FUN_601005ac`/`FUN_601005f6`) as the previously-confirmed standalone P-256 Solinas reduction.** This is SMP's LE Secure Connections local-keypair-generation step, and it is the P-256 stack's real runtime consumer — the Ed25519/X25519 stack in `bruce-crypto.md` remains uncalled from anywhere traced so far and is now the *less* likely "live" curve of the two.
- **L2CAP (part of thread 4, "layers not yet touched")**: no longer untouched — see address-range map and the dedicated cluster in the session-8 table above (`l2c_csm_*`/`l2c_fcr_*`/`l2c_rcv_acl_data`/`l2c_link_*`, 14 functions). This also corrects session 7's read of `FUN_600ba1c4` (the TLV/PDU parser) from "ATT/GATT PDU parser" to more likely an L2CAP-internal PDU dispatcher, since it's called directly from `l2c_rcv_acl_data` rather than from anything GATT-named.

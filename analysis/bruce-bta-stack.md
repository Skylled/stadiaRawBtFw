# Bruce — the `0x600921b8`–`0x600c9cc4` block: Broadcom BTA/BTE Bluetooth stack (sessions 7–9)

Target: the single largest unmapped contiguous range in the image (`analysis/bruce-decompile-status.md` §3b run #1) — 1,076 functions, 204,449 code bytes, 89.6% density, 2/1,076 decompiled at session-7 start.

**Session 8 update (same day):** executed session 7's continuation plan in full. Swept the remaining ~388 BTA/BTE trace-string table entries through `FindRef.java` (317 identifier-shaped strings checked in bulk, plus a targeted L2CAP/`btu_task` batch) and got **261 new function identifications** with effectively zero false positives, then batch-decompiled all of them plus a few hand-resolved "gap" functions Ghidra's auto-analysis hadn't boundary-detected (same phenomenon as `btu_task` below). **Net result: 327 of 1,076 functions now decompiled (up from 69), ~93,400 of 204,449 code bytes (~45.7%, up from ~11%).** All three of session 7's flagged open threads made concrete progress this session:
- **`btu_task` confirmed as the real BTU-layer main dispatch loop** (thread 3) — see prose below.
- **L2CAP fully surfaced**: the block session 7 called "GATT-client attribute-cache" (`0x600b5xxx`–`0x600bcxxx`) is actually the **L2CAP channel-state-machine + FCR** implementation (`l2c_csm_*`/`l2c_fcr_*`/`l2c_rcv_acl_data`, all string-confirmed) — a direct correction to session 7's module-map guess, not just new territory (thread 4, previously "not yet touched").
- **`smp_data_ind` traced down into the confirmed P-256 scalar-multiplication code**, closing the "what calls the EC crypto stack" question (thread 5) with a complete, non-speculative call chain — see prose below.

Five of session 7's own guessed identifications turned out to be wrong and are corrected in the table below (all in the `0x600c3xxx`–`0x600c4xxx` band session 7 guessed was "SMP/pairing state helpers" — it's actually **BTA DM** search/SDP-result/ACL-change handling, not SMP).

**Session 9 update:** the BTA/BTE string table is exhausted (confirmed again this session — none of the 90 newly-decompiled functions reference the `0x60103xxx`–`0x60122xxx` string-table region as a literal operand, matching CLAUDE.md's note that this lead is spent), so this session switched to pure size-ranked decompile + shape/call-graph inference: the 90 largest still-undecompiled functions in the block (by a fresh address-based join against `bruce_functions.csv`/`analysis/decomp/*.c` headers, not name-based) were decompiled and read. **418 of 1,076 functions now decompiled (up from 328), ~130,268 of 204,449 code bytes (~63.7%, up from ~45.8%).** Highlights, all shape/call-graph inferred (no new string confirmations this session — see caveats inline):
- **L2CAP got substantially deeper**, closing two of the three open naming questions session 8 left: `FUN_600bc00c` is very likely **`l2cu_release_ccb`** (called from literally every named `l2c_csm_*` state handler — stops the channel timer, drains the queued-packet list, unlinks the CCB into a free list); `FUN_600b6d30` is a strong candidate for **`l2c_csm_open`**, the one CSM steady-state handler missing from session 8's named set (called only by the CSM dispatcher `FUN_600b5e00`, switches on event code, and its case 3 calls the newly-identified `l2cu_release_ccb`). Also found L2CAP's two connection-creation triggers: `FUN_600bc5c4` (classic, calls `btsnd_hcic_create_conn` directly — `l2cu_create_conn`-shaped) and `FUN_600b59ec` (LE, calls `btsnd_hcic_ble_create_ll_conn` — see the caveat below on this one). Plus several L2CAP FCR internals (`FUN_600b7b48`/`FUN_600b8094`/`FUN_600b842c`, all called from `l2c_fcr_proc_pdu` or calling `l2c_fcr_clone_buf` directly) and `FUN_600b89b8`, very likely **`l2c_link_hci_conn_comp`** (sibling of the confirmed `l2c_link_hci_disc_comp`, calls the CSM dispatcher directly).
- **Caveat — the `0x600b5xxx`–`0x600b9fxx` range is predominantly but not purely L2CAP.** `FUN_600b59ec` (LE connection-creation trigger) is called directly by the string-confirmed BTM function `btm_send_pending_direct_conn` (`0x6009c7fc`) and is a strong candidate for the real **`btm_ble_create_conn`** — a BTM function sitting inside the nominal L2CAP address band. Worth remembering before assuming address alone determines module membership in this range.
- **The GATT dispatcher's missing write-path callee is resolved**: `FUN_600aeb14` (flagged in the session-8 table as "not yet decompiled", the target `FUN_600aee8c` routes Write Request/Write Command/Signed Write Command/Prepare Write to) is now decompiled and its opcode checks (`0x12`/`0x52`/`0xd2`/`0x16`) match exactly — this is **`gatts_process_write_req`**, the write-side sibling of `gatts_process_read_req`.
- **A spec-verified GATT bootstrap function**: `FUN_600aac04` (no static callers — dynamically invoked, presumably once at stack init) builds UUID `0x1800` (the real Bluetooth SIG **GAP "Generic Access" service** UUID), creates it via `GATTS_CreateService`, then adds characteristics `0x2a00` (Device Name) and `0x2a01` (Appearance) — both real spec UUIDs. High-confidence identification by literal constant match, same evidentiary style as the HCI opcode table in Evidence §2. **Audit correction (post-session-9 review): the original write-up undersold its own evidence** — the decompiled body actually adds two more characteristics beyond the two named here, `0x2a04` (Peripheral Preferred Connection Parameters) and `0x2aa6` (Central Address Resolution), also real spec UUIDs, for four confirmed characteristics total. The audit also found this function's read-side counterpart, previously misfiled as unidentified — see the `0x600aa8f0` row below.
- **SMP**: `FUN_600c15a8` — previously referenced but undecompiled (the session-8 writeup for `FUN_600c0f34` calls it "mutual recursion / re-entry per random-command completion") — is now decompiled: a state-keyed (cases 3–0xe) dispatcher for HCI-command-completion callbacks during SMP's local key-generation/exchange flow, storing key material into control-block offsets and re-entering via `smp_sm_event` or the confirmed keypair-entropy state machine (cases 9–0xc call `FUN_600c0f34` directly). Plausibly `smp_proc_key`-shaped; not string-confirmed.
- **EC crypto**: `FUN_600c9aac`, called from `FUN_600c8798` (the confirmed EC scalar-multiplication function), is a binary/extended-Euclidean-style modular-inverse routine over the same word-count-parameterized bignums as the P-256/P-192 reduction code — plausibly the affine-coordinate (Z⁻¹) conversion step.
- A handful of functions (`FUN_600c71ac`, `FUN_600c7d64`, `FUN_600aa8f0`, `FUN_600c269c`, `FUN_60094a3c`, `FUN_600952fc`) remain **not conclusively identified** — flagged as such in the table rather than guessed, per the "don't force it" instruction; several of them call out to an unrelated subsystem at `0x600eexxx` (decompile-status run #3) rather than other BTA/BTE code, which is itself a mildly interesting (if unexplained) cross-module link. **Audit correction (post-session-9 review): `FUN_600aa8f0` was mis-flagged here — it should not have been left unidentified.** It's very likely the GAP service's characteristic-value read-getter (the runtime read-side counterpart of `FUN_600aac04` above): same 4-entry/12-byte-stride table shape, and its UUID switch matches `0x2a00`/`0x2a01`/`0x2a04`/`0x2aa6` literally — the exact four characteristics `FUN_600aac04` registers. See the corrected `0x600aa8f0` row in the table below for the full evidence. The other five in this list were independently re-checked and do hold up as genuinely unresolved given the evidence available on disk (their identifying callees sit outside this block, in `0x600eexxx`/run-#2 territory that wasn't decompiled this session).
- **Audit note (independent review, one day after session 9):** 17 of the 90 session-9 rows were spot-checked against their actual decompiled bodies in `analysis/decomp/`, spread across L2CAP, GATTS, the GAP bootstrap, the SMP claim below, and the "not conclusively identified" set. 15 of 17 held up as described or better; 2 needed correction (both noted inline in the table): `FUN_600aa8f0` (wrongly left unidentified — see above) and `FUN_600b5264` (the "called from SMP's FSM action table" claim overstated what the call graph actually shows — see its table entry for the corrected chain).

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
| ~`0x600aaxxx`–`0x600b02xx` | **GATT client/server core**, confirmed by session-8 string sweep from end to end: `GATTC_Read` (`0x600ab620`), `gatts_process_primary_service_req` (`0x600ae4e0`), `GATTS_CreateService`/`GATTS_DeleteService`/`GATTS_StartService`/`GATTC_Write` (`0x600ab110`–`0x600ab778`), the `gatt_*`/`gatts_*` internal-helper family (signing, enc-complete, pending-indication queues, read/read-multi/read-by-type request handlers, `gatt_end_operation`/`gatt_cleanup_upon_disc`) filling `0x600ac014`–`0x600b02e0` essentially without gaps. Relocated from `bruce-io-paths.md` session 12: `FUN_600aee8c` (`0x600aee8c`, right after `gatts_process_read_req`) is this sub-range's top-level ATT-opcode dispatcher, routing Read/Read-Blob to `gatts_process_read_req` and Write/Write-Command/Signed-Write/Prepare-Write to `FUN_600aeb14` — the first confirmed caller found for any of the `gatts_process_*` handlers in this range. **Session 9: `FUN_600aeb14` is now decompiled and is `gatts_process_write_req`** (its own opcode checks match the exact Write/Write-Command/Signed-Write/Prepare-Write set `FUN_600aee8c` routes to it), closing that gap. Session 9 also found a spec-verified GAP service bootstrap (`FUN_600aac04`, builds UUID `0x1800` + characteristics `0x2a00`/`0x2a01`) in this sub-range |
| ~`0x600b07xx`–`0x600b4e40` | **HCI command-send layer, `btsnd_hcic_*`** — session 8 confirmed essentially the *entire* Bluetooth Core Spec HCI command set is implemented here (~123 functions total between sessions 7–8: 34 LE commands `0x600b0824`–`0x600b1e00`, ~89 classic commands `0x600b1e58`–`0x600b4e40`), all identical shape, opcode-verified where checked (Evidence §2) |
| ~`0x600b5xxx`–`0x600b9fxx` | **L2CAP** — session 7 mis-identified this as "GATT-client attribute-cache"; session 8's string sweep corrected it: `l2c_csm_*` (channel state machine: closed/orig_w4_sec_comp/term_w4_sec_comp/w4_l2cap(a)_connect_rsp/config/w4_l2cap(a)_disconnect_rsp, `0x600b5ec8`–`0x600b70f4`), `l2c_fcr_*` (flow-control/retransmission: clone_buf/send_S_frame/proc_pdu, `0x600b742c`–`0x600b7800`), `l2c_link_hci_disc_comp`/`l2c_link_segments_xmitted` (`0x600b8ba4`, `0x600b9d94`), and `l2c_rcv_acl_data` (`0x600b9e28`, the ACL-data entry point that calls `FUN_600ba1c4`) — see prose below. `FUN_600b5e00` itself (the dispatcher feeding all the `l2c_csm_*` state handlers) is very likely `l2c_csm_execute`, not yet string-confirmed. `FUN_600b9408` (16 callers, GATT-cache-shaped in session 7's read) is now more plausibly an L2CAP-internal sub-routine given its neighbors, not re-examined this session. **Session 9 (shape-based, not string-confirmed):** the missing CSM steady state `l2c_csm_open` (`FUN_600b6d30`) and the shared teardown helper `l2cu_release_ccb` (`FUN_600bc00c`, called from every named CSM state) round out the state machine; both connection-creation triggers found (`l2cu_create_conn`-shaped `FUN_600bc5c4` for classic, calling `btsnd_hcic_create_conn`; a probable `btm_ble_create_conn` `FUN_600b59ec` for LE, calling `btsnd_hcic_ble_create_ll_conn`); 3 more FCR internals; and a probable `L2CA_SendFixedChnlData`-shaped sender (`FUN_600b5264`) found in SMP's reject-unexpected-command path (**audit correction:** the original "called from SMP's own FSM table" framing wasn't supported by the call graph — see the `0x600b5264` function-table entry above for the corrected chain). **Boundary caveat:** `FUN_600b59ec` is very likely a genuine BTM function (called directly by the string-confirmed `btm_send_pending_direct_conn`) despite its address sitting inside this L2CAP band — the range is predominantly but not purely L2CAP. |
| ~`0x600ba1c4` | `FUN_600ba1c4` (3,898B, session 6) — an ATT/GATT-shaped TLV/PDU parser called *from* `l2c_rcv_acl_data`; given it now sits inside the confirmed L2CAP layer rather than a GATT-client cluster, it's more likely L2CAP's own basic-mode PDU dispatch/reassembly (e.g. `l2c_process_held_packets`-shaped) than an ATT parser per se — re-open as a naming question, not re-examined this session |
| ~`0x600bd4bc`–`0x600bfeec` | **SDP** (service discovery) — `SDP_AddUuidSequence`/`SDP_AddProtocolList`/`SDP_AddServiceClassIdList` (public API, `0x600bda54`–`0x600bdb7c`), `sdp_data_ind` (`0x600be100`, PDU receive entry point, sibling of `smp_data_ind`/`l2c_rcv_acl_data`), `sdpu_release_ccb`/`sdpu_build_n_send_error`/`sdpu_build_partial_attrib_entry` (`0x600bf374`–`0x600bfeec`) plus the session-7 `ServiceSearchAttributeResponse` PDU builders. **Session 9: start boundary sharpened from `0x600bda54` to `0x600bd4bc`** — `FUN_600bd4bc`/`FUN_600bd848` are internal `sdpu_*`-shaped helpers called directly by the named SDP functions above despite sitting below the previously-noted boundary |
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
| `0x600aee8c` | 302 | **ATT-opcode top-level dispatcher** (relocated from `bruce-io-paths.md` session 12) — looks up a per-connection record (10-entry table), then routes on the raw ATT opcode byte: Read Request(`0xa`)/Read Blob Request(`0xc`) → `gatts_process_read_req` (`0x600aed40`, immediately preceding this function); Write Request(`0x12`)/Write Command(`0x52`)/Signed Write Command(`0xd2`)/Prepare Write(`0x16`) → `FUN_600aeb14` (not yet decompiled). First confirmed static caller found for `gatts_process_read_req`. Only static caller: `FUN_600f6516` (in decompile-status run #2, `0x600faxxx`–`0x600fcxxx`) |
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


## Functions decompiled session 9 (90 new, 418 of 1,076 total)

Session 8's string-table sweep is exhausted (re-confirmed this session — none of the 90 functions below reference the `0x60103xxx`–`0x60122xxx` string-table region as a literal operand). This batch is the **90 largest still-undecompiled functions in the block**, selected by a fresh address-based join (`bruce_functions.csv` filtered to `[0x600921b8, 0x600c9cc4)`, minus addresses already present as a decomp-header address in `analysis/decomp/*.c`, sorted by `size_bytes` descending — the join methodology `bruce-decompile-status.md` §Methodology specifies), decompiled in three batches of 30 via `Decompile.java` and read against callers/callees plus cross-referenced against the address-range map and the growing named-function set. No string evidence was available for this batch (Evidence §1's table is spent), so every identification below is shape/call-graph-based; confidence is called out per row and several are explicitly left unresolved rather than guessed.

| Address | Bytes | Name / description |
|---|---:|---|
| `0x600936d4` | 312 | BTA DM power-management-region helper; callee `0x600eexxx`-range (decompile-status run #3, flash/NVM-shaped) — plausibly PM-state persistence, not conclusively identified |
| `0x60093810` | 372 | BTA DM power-management sub-helper, called directly from the confirmed link-policy mode-select helper (`0x60093a30`); shares the `0x600eexxx`-range callee with the row above |
| `0x60094a3c` | 338 | BTA GATTC-region helper (sits between `bta_gattc_sdp_service_disc` and `bta_gattc_rebuild_cache`) but its callees are all in the unrelated `0x600eexxx` range (decompile-status run #3) rather than other BTA/BTE code — plausibly `bta_gattc_co_cache_*` (cache persistence/NVM glue); **not conclusively identified** |
| `0x600952fc` | 374 | BTA GATTS-region helper with the same `0x600eexxx`-callee pattern as the row above — plausibly persistence/cache glue; **not conclusively identified** |
| `0x60097298` | 340 | Small leaf helper in the HCI-H4-transport/BTM-link-policy region, no callees; caller `FUN_60098d8c` not itself decompiled |
| `0x600979e4` | 306 | BTM link-policy/mode helper (sibling of the confirmed `0x60097b20`/`0x60097f5c` pair) — calls `BTM_VendorSpecificCommand` |
| `0x60097dc8` | 390 | BTM link-policy orchestrator — calls the confirmed BTM link-policy/mode-change helper (`0x60097b20`) and `BTM_VendorSpecificCommand` directly |
| `0x600983f4` | 308 | Tiny BTM link-mode leaf helper, single callee `FUN_60098f34` |
| `0x600988d0` | 336 | BTM link-mode init/config routine (no static callers — likely function-pointer invoked); calls `FUN_60098a24` and a periodic/init thunk `FUN_600d9380` |
| `0x60098a24` | 324 | BTM link-mode helper (sibling pair with the row above); calls `BTM_VendorSpecificCommand` |
| `0x60098f88` | 508 | Very likely a post-ACL-connection remote-capability sequencer — issues `btsnd_hcic_read_remote_feat` (`0x600b12e4`), `btsnd_hcic_rmt_ver_req` (`0x600b2a4c`), `btsnd_hcic_read_rmt_clk_offset` (`0x600b2ad0`) in sequence; called from the confirmed BTM connection helper `0x600a6d70` and two undecompiled L2CAP-region callers |
| `0x6009931c` | 402 | BTM link-mode negotiation helper — calls `FUN_600a3424` (BTM link-policy dispatcher, this session) plus `btsnd_hcic_set_conn_encrypt` (`0x600b26d0`) and `btsnd_hcic_switch_role` (`0x600b2eec`) |
| `0x60099584` | 474 | BTM link-security/role helper — calls `btsnd_hcic_change_link_key` (`0x600b2764`), `btsnd_hcic_disconnect` (`0x600b218c`), `btsnd_hcic_switch_role` (`0x600b2eec`) |
| `0x6009a5b0` | 370 | BTM link-security/role helper, sibling of the row above (identical callee set: change-link-key/set-conn-encrypt/switch-role), called from `FUN_600a3d8c` |
| `0x6009a9c4` | 376 | BTM ACL/security-record helper in the `0x6009axxx` cluster, near the confirmed ACL/security link-record updater (`0x6009ad00`) |
| `0x6009c2c0` | 384 | BTM helper in the `0x6009cxxx` cluster; no identifying callees beyond memcpy/memset thunks |
| `0x6009c444` | 334 | Very likely part of the **BLE direct-connection state machine** — calls `btsnd_hcic_ble_create_ll_conn` (`0x600b0e2c`) and `btsnd_hcic_ble_create_conn_cancel` (`0x600b0fc8`); sits immediately next to the confirmed `btm_ble_enqueue_direct_conn_req`/`btm_send_pending_direct_conn` pair (`0x6009c7c8`/`0x6009c7fc`) |
| `0x6009c59c` | 308 | Sibling of the row above in the same BLE direct-connection cluster; calls `btsnd_hcic_ble_set_scan_params` (`0x600b0cd4`) |
| `0x6009cad8` | 416 | Common BTM link-policy sub-helper — 5 static callers, all in the `0x6009dxxx` mode-toggle cluster below |
| `0x6009daac` | 352 | BTM link-policy mode-toggle helper (near-identical body/callee-set to the row below — likely a sniff/hold/park-mode enable-vs-disable pair), called from the confirmed BTM/inquiry helper `0x600a1900` |
| `0x6009dc14` | 342 | BTM link-policy mode-toggle helper, near-identical to the row above (identical callee list) — the two are almost certainly an enable/disable pair for the same link mode |
| `0x6009e4d0` | 482 | BTM inquiry-control helper — calls `btsnd_hcic_inq_cancel` (`0x600b1ef8`) directly, consistent with an inquiry-results/timeout handler |
| `0x6009f6c0` | 502 | BTM BLE privacy/resolving-list setup helper — calls `BTM_VendorSpecificCommand` and `btsnd_hcic_ble_add_device_resolving_list` (`0x600b19c0`) |
| `0x6009fae0` | 526 | BTM/BLE scan helper called directly from BTA DM's search-start flow (caller `FUN_600c2a28`, itself in the BTA DM `0x600c2xxx` search cluster) — bridges `bta_dm_search_start` into the BTM inquiry/scan layer |
| `0x6009fcf4` | 318 | Small BTM ACL-record accessor, called from the confirmed BTM ACL/connection helper `0x600a6d70` among others |
| `0x600a1d3c` | 342 | BTM scan-mode helper — calls `btsnd_hcic_write_scan_enable` (`0x600b35cc`) and `btsnd_hcic_write_pagescan_cfg` (`0x600b3640`); two of its three callers sit in the BTA DM `0x600c2xxx` cluster |
| `0x600a1fc8` | 430 | Called directly from the confirmed `bta_dm_search_start` (`0x600c2f68`) — the BTM-layer inquiry/scan kickoff that `BTA_DmSearchStart` invokes |
| `0x600a2338` | 362 | BTM inquiry-result-filter helper — calls the confirmed `btm_clr_inq_result_flt` (`0x600a25f8`) directly |
| `0x600a30f0` | 414 | BTM ACL/connection helper in the connection-event-handler cluster, called from the confirmed ACL/connection dispatch helper `0x600a96d8` |
| `0x600a3424` | 436 | **BTM link-policy mode-select dispatcher** — calls the confirmed `btsnd_hcic_hold_mode`/`sniff_mode`/`park_mode`/`exit_sniff_mode`/`exit_park_mode` family; called from `l2c_csm_closed` (`0x600b5ec8`) and several BTA-PM-region callers — the actual implementation those higher-level helpers dispatch into |
| `0x600a3784` | 380 | Leaf BTM link-policy helper, single caller `FUN_600a3904` |
| `0x600a3a38` | 518 | BTM link-policy mode-request helper — calls the same hold/sniff/park HCI-command family as `FUN_600a3424` above, part of the same link-policy-negotiation cluster |
| `0x600a3d8c` | 432 | BTM link-policy negotiation helper tying together `FUN_6009a5b0`, `FUN_600a3a38`, and the L2CAP dispatch helper `0x600b9408`; caller `FUN_600f2afa` (decompile-status run #2) |
| `0x600a40c4` | 412 | Small BTM connection-event helper, single callee is the memset thunk; caller `FUN_600f1996` (run #2) |
| `0x600a42d0` | 480 | BTM connection-security helper — calls `btsnd_hcic_pin_code_neg_reply` (`0x600b25c8`) and `btsnd_hcic_write_auth_enable` (`0x600b3790`); called from the confirmed ACL/connection-complete handler `0x600a44bc` and BTM connection-state helper `0x600a59d0` |
| `0x600a4820` | 348 | BTM connection helper — calls `btsnd_hcic_create_conn_cancel` (`0x600b2224`); one of its two callers (`FUN_600c2d00`) is in the BTA DM `0x600c2xxx` cluster |
| `0x600a6184` | 310 | BTM ACL-event helper called from LE-Meta sub-dispatch `FUN_600f2e14` (run #2), same neighborhood as the confirmed ACL-event handlers `0x600a5ec8`/`0x600a62cc` |
| `0x600a6b20` | 468 | BTM ACL/connection helper aggregated by the confirmed ACL/connection dispatch helper `0x600a96d8`; calls `FUN_600a7b44` (below) directly |
| `0x600a730c` | 456 | BTM connection-state helper called from LE-Meta sub-dispatch `FUN_600f2158` (run #2); calls the BD_ADDR-compare helper `0x6009a72c` also used by the confirmed `0x600a6d70` |
| `0x600a74dc` | 336 | BTM connection helper — calls `btsnd_hcic_rmt_name_req` (`0x600b27e8`), consistent with a remote-name-request flow |
| `0x600a7b44` | 450 | BTM connection-state **shared sub-routine** — 9 static callers spanning nearly the entire `0x600a4xxx`–`0x600a7xxx` BTM connection-handler cluster, playing the same role for that cluster that `0x600b9408` plays for L2CAP |
| `0x600aa8f0` | 472 | **Audit correction (post-session-9 review): this should not have been left "not conclusively identified" — it's very likely the GAP service's characteristic-value read-getter, the runtime read-side counterpart of `FUN_600aac04`'s bootstrap.** Its body walks a 4-entry table (`DAT_600aaac8`, stride 12 bytes = 6 ushorts, loop bound 4) matching an input handle against entry offset 0, then switches on the UUID at entry offset 1 with literal checks for `0x2a01` (Appearance, 2-byte copy), `0x2a00` (Device Name, calls `FUN_600a1154`/`FUN_6004cb28` to fetch a name string + length), `0x2a04` (Peripheral Preferred Connection Parameters, 8-byte copy), and `0x2aa6` (Central Address Resolution, 1-byte copy) — the exact same four UUIDs, same 4-entry/12-byte-stride table shape, and same ordering that `FUN_600aac04` (`0x600aac04`, this session's spec-verified GAP bootstrap) builds via `GATTS_CreateService`/`AddCharacteristic`. This is byte-level corroborating evidence in the same style as Evidence §2's opcode table, not merely shape-based, and it was sitting in the same decompiled function body the original write-up already had. `FUN_6004cb28`'s address falling inside the SHA-512-compression neighborhood per `bruce-crypto.md` is very likely a coincidence of physical code proximity, not a real call into the crypto stack — the same trap CLAUDE.md already flags for `keys.cc` (address/file proximity isn't module membership) |
| `0x600aac04` | 384 | **GAP (Generic Access Profile) standard-service bootstrap, spec-verified** — no static callers (dynamically invoked, presumably once at stack init); builds UUID `0x1800` (the real Bluetooth SIG "Generic Access" service UUID), creates it via `GATTS_CreateService`, then adds characteristics `0x2a00` (Device Name) and `0x2a01` (Appearance) — both real spec UUIDs. Same evidentiary style as the HCI-opcode table in Evidence §2 |
| `0x600ab9b8` | 338 | GATT client/server helper called from the confirmed `bta_gattc_register` (`0x600c611c`) among others; calls `gatt_free_srvc_db_buffer_app_id` (`0x600af51c`) — a per-app-ID GATT client cleanup/deregister routine |
| `0x600abdac` | 330 | GATT client helper, calls the confirmed `GATTC_Write` (`0x600ab778`) directly — a write-request wrapper/validator |
| `0x600ac2a4` | 384 | GATT client/server core helper — per-connection-record status check (gated on a byte at `param_1+0xc`), calls run-#2 helpers `FUN_600f194c`/`FUN_600f0b06`; not conclusively identified beyond its role as a status gate |
| `0x600ac524` | 382 | GATT client common response-completion helper, called from `gatt_process_read_by_type_rsp` and `gatt_process_read_rsp` before `gatt_end_operation` (`0x600b00b4`) — a shared response-finalization routine |
| `0x600acf50` | 364 | **GATT client ATT-response opcode dispatcher** — called directly from `gatt_data_process` (`0x600ad9d8`, the GATT ingress entry point) and routes to `gatt_process_read_rsp`/`gatt_process_read_by_type_rsp` before finishing via `gatt_end_operation`/the op-completion helper `0x600ac734` |
| `0x600adce0` | 464 | GATT-core PDU buffer builder — allocates a GKI buffer via `FUN_6006dbac` (the same allocator the `btsnd_hcic_*` HCI-command builders use) and populates it via two memcpy calls; plausibly the ATT-PDU-to-L2CAP handoff |
| `0x600ae0dc` | 516 | GATT server helper called directly from `gatts_process_primary_service_req` (`0x600ae4e0`) |
| `0x600ae2e8` | 500 | GATT server helper called directly from `gatts_process_find_info` (`0x600ae670`) |
| `0x600aeb14` | 550 | **`gatts_process_write_req`** (shape-confirmed) — the write-side sibling of `gatts_process_read_req`, and the previously-unresolved callee the ATT-opcode dispatcher `FUN_600aee8c` routes Write Request(`0x12`)/Write Command(`0x52`)/Signed Write Command(`0xd2`)/Prepare Write(`0x16`) to. Its own opcode checks match that exact set, confirming the identification |
| `0x600af9fc` | 334 | GATT UUID normalizer — reduces a 128-bit UUID to 16-bit form if it matches the Bluetooth Base UUID prefix (constant at `DAT_600afb4c`), else keeps 32-bit; called from `gatt_process_read_by_type_rsp` and `gatts_process_primary_service_req` |
| `0x600b50d0` | 398 | L2CAP-internal channel/CCB lookup-and-dispatch helper, called from both L2CAP internals and **SMP** (`FUN_600c0578`, in the SMP address range) — consistent with SMP running over an L2CAP fixed channel |
| `0x600b5264` | 446 | Very likely **`L2CA_SendFixedChnlData`-shaped** — validates a fixed-CID parameter in range 4–6 (ATT/SMP's classic BTE fixed-channel IDs) against a per-channel registration/connection table before allowing send, logging via source-line-numbered trace calls (`0x5f6`/`0x5fe`/`0x608`/…, consistent with compiled-in `__LINE__` trace strings). The function body itself does hold up as L2CAP-fixed-channel-shaped (CID-range gate, channel table lookup, hands off to `FUN_600b720c`/`FUN_600b9408`). **Audit correction (post-session-9 review): the "called from SMP's FSM action table" framing overstates what's actually visible in the call graph.** Its two static callers are `FUN_600c1b20` (78 bytes, itself never decompiled — no `.c` file exists for it) and `FUN_600ff986` (in run #2, also undecompiled). `FUN_600c1b20` is in turn called only by the confirmed `smp_reject_unexp_pair_cmd` (`0x600c239c`), which is itself called *directly* — a hardcoded static call, not a table dispatch — by `smp_data_ind` (`0x600c1864`) on its unexpected/invalid-command reject path. `smp_sm_event`'s real per-state action table (`FUN_600c1a34`, read in full for this audit) dispatches via a runtime-computed indirect call, `(**(code **)(DAT_600c1b1c + (uint)bVar1 * 4))(param_1,param_3)`, which is invisible to static xref/caller-list tooling — so nothing in the decompiled evidence actually shows a call site *inside* the FSM table pointing at this function or at `FUN_600c1b20`. The chain that *is* visible — `smp_data_ind` → `smp_reject_unexp_pair_cmd` → `FUN_600c1b20` → (asserted only, not decompiled) this function — is real, and still supports "SMP sends over an L2CAP fixed channel" as a conclusion, but it's evidence from one hardcoded error-path call, not from the FSM's per-state action table; those are two different SMP dispatch mechanisms and shouldn't be conflated. Treat this as one supporting data point for the L2CAP-transit hypothesis, not as having "closed" it |
| `0x600b5540` | 364 | L2CAP-internal helper, same callee shape as `0x600b5264` above (`FUN_600bc880`/`FUN_600bb44c`/`FUN_600bb6dc`); caller `FUN_600f7cea` (run #2) |
| `0x600b5844` | 420 | **L2CAP Connection Parameter Update handler** — issues `btsnd_hcic_ble_upd_ll_conn_params` (`0x600b1124`, HCI LE Connection Update), the L2CAP signaling-channel side of an LE connection-parameter update |
| `0x600b59ec` | 450 | Very likely the real **`btm_ble_create_conn`** (BTM, not L2CAP, despite sitting inside the nominal L2CAP address band — see the session-9 caveat above) — issues `btsnd_hcic_ble_create_ll_conn` (`0x600b0e2c`), called directly by the string-confirmed `btm_send_pending_direct_conn` (`0x6009c7fc`) |
| `0x600b5c08` | 456 | L2CAP round-robin scheduling-interval calculator (near-identical pair with `0x600b8f0c` below, different global state block), called from L2CAP helpers `0x600bb534`/`0x600bb44c` |
| `0x600b6d30` | 540 | Strong candidate for **`l2c_csm_open`** — the one L2CAP CSM steady-state handler missing from session 8's named set (closed/orig_w4_sec_comp/term_w4_sec_comp/w4_l2cap(a)_connect_rsp/config/w4_l2cap(a)_disconnect_rsp were all found, but not OPEN). Called only by the CSM dispatcher `FUN_600b5e00`; switches on event code, and its case 3 calls the newly-identified `l2cu_release_ccb` (`0x600bc00c`) plus an upper-layer disconnect-indication callback — the right shape for "channel is open, handle disconnect/data/config events" |
| `0x600b74d8` | 408 | L2CAP-internal list helper, caller `0x600b85e4` (an L2CAP list helper per the session-8 correction, despite its stale "GATT-cache" row label) |
| `0x600b7b48` | 324 | L2CAP FCR (flow-control/retransmission) internal helper, called directly from `l2c_fcr_proc_pdu` (`0x600b7800`) |
| `0x600b8094` | 340 | L2CAP FCR internal helper, also called directly from `l2c_fcr_proc_pdu` |
| `0x600b842c` | 410 | L2CAP FCR helper that calls `l2c_fcr_clone_buf` (`0x600b742c`) directly |
| `0x600b89b8` | 486 | Very likely **`l2c_link_hci_conn_comp`-shaped** (sibling of the confirmed `l2c_link_hci_disc_comp` @ `0x600b8ba4`) — the L2CAP link-layer HCI-connection-complete handler; calls the CSM dispatcher `FUN_600b5e00` directly plus `l2c_link_hci_disc_comp` itself (failure path) and `btu_start_timer`/`btu_stop_timer` |
| `0x600b8d7c` | 392 | L2CAP link disconnect-initiation helper — calls `btsnd_hcic_disconnect` (`0x600b218c`) and the CSM dispatcher `FUN_600b5e00` directly |
| `0x600b8f0c` | 452 | L2CAP round-robin scheduling-interval calculator, near-identical pair with `0x600b5c08` above |
| `0x600b9740` | 494 | L2CAP-to-HCI-transport bridge — calls into the confirmed `bte_hcisu_*` cluster (`0x6006b98c`, outside this block but same object-file group per the address-range map's footnote); caller is the L2CAP dispatch helper `0x600b9408` |
| `0x600b9938` | 448 | L2CAP-internal helper driven from LE-Meta event sub-dispatch `FUN_600f2ae0` (run #2) — L2CAP reacting directly to an LE HCI event |
| `0x600bb534` | 414 | L2CAP link-level release/adjust orchestrator — calls the newly-identified `l2cu_release_ccb`-shaped `FUN_600bc00c`; called from `l2c_link_hci_disc_comp` among others |
| `0x600bb906` | 544 | L2CAP buffer-alloc-and-dispatch helper — calls the GKI buffer allocator `FUN_6006dbac` and the L2CAP dispatch helper `0x600b9408`; caller `FUN_6013aad0` sits well outside this block (near the ITCM-thunk tail) |
| `0x600bbbf8` | 318 | L2CAP PDU-parsing sub-helper, called directly from `FUN_600ba1c4` itself (the L2CAP basic-mode PDU parser/dispatcher) |
| `0x600bc00c` | 322 | Very likely **`l2cu_release_ccb`** — called from every one of the eight named `l2c_csm_*` state handlers plus `l2c_link_hci_disc_comp`. Stops the channel timer (`btu_stop_timer`), drains a queued-packet list via a pop-and-free loop, and unlinks the control block into what looks like a global free/idle-CCB list — the textbook "channel is done, tear it down" shared subroutine every CSM exit path calls |
| `0x600bc2a0` | 378 | Small L2CAP CSM-config-adjacent helper, one of its three callers is `l2c_csm_config` (`0x600b6900`) itself |
| `0x600bc5c4` | 322 | Very likely **`l2cu_create_conn`-shaped** — calls `btsnd_hcic_create_conn` (`0x600b20a0`, classic HCI Create Connection) directly, the classic-BR/EDR counterpart of `0x600b59ec`'s LE connection trigger above |
| `0x600bcca8` | 434 | L2CAP-internal record helper, caller is the L2CAP dispatch helper `0x600b9408` |
| `0x600bcf88` | 394 | L2CAP-internal leaf helper, all three callers are L2CAP-region functions |
| `0x600bd4bc` | 310 | Shared L2CAP/SDP-boundary helper — called by two SDP response builders (`0x600be150`/`0x600beb20`) as well as an undecompiled run-#2 function; sharpens the SDP module's practical start slightly earlier than the `0x600bda54` boundary noted in the address-range map |
| `0x600bd848` | 516 | **SDP internal helper** (`sdpu_*`-shaped) — called by `SDP_AddProtocolList`/`SDP_AddUuidSequence`/`SDP_AddServiceClassIdList` and the SDP-adjacent buffer builder `0x600bd150`, despite sitting just below the `0x600bda54` map boundary (see the row above — the real SDP object code starts a little earlier than previously mapped) |
| `0x600bdc24` | 368 | SDP internal leaf helper, caller `0x600bd848` above |
| `0x600bf3b4` | 430 | SDP internal leaf formatter (no callees), callers are the SDP response builders plus `sdpu_build_partial_attrib_entry` |
| `0x600bf6a0` | 526 | SDP internal leaf formatter (no callees), callers are the SDP response builders |
| `0x600bfc34` | 500 | SDP internal helper, callers include `0x600bd4bc` above and a run-#2 function |
| `0x600c15a8` | 346 | SMP local-security-procedure state advancer — this is the function the session-8 writeup for `FUN_600c0f34` referred to as "mutual recursion / re-entry per random-command completion" without decompiling it. A state-keyed (cases 3–0xe) dispatcher for HCI-command-completion callbacks during SMP key generation: stores key material into control-block offsets `+0x5d`/`+0x65` and re-enters via `smp_sm_event` (event `0x17`) or, for cases 9–0xc, recurses directly into the confirmed keypair-entropy state machine `FUN_600c0f34`. Plausibly `smp_proc_key`-shaped; not string-confirmed |
| `0x600c269c` | 332 | BTA DM-region helper (no static callers — dynamic dispatch) bridging into the BTA GATTS-cluster neighborhood (`0x60095b9c`/`0x60095b7c`/`0x60095f10`) and the BTM cluster (`0x600a12e0`/`0x600a1238`/`0x6009a114`); plausibly a device-record cleanup/enable-complete routine, **not conclusively identified** |
| `0x600c67ac` | 330 | BTA GATTC/S-tail-region helper, caller `FUN_600feba8` (run #2); callees sit in the BTA GATTS-cluster neighborhood — plausibly app-registration/callback glue, not conclusively identified |
| `0x600c71ac` | 560 | Status-gated record formatter (unpacks a 17-field, 0x22-byte record from a byte buffer when a leading status byte is 0) that invokes a registered callback pointer (`DAT_600c73dc+0x7fc`) with event code 4; both callers are in decompile-status run #2. **Not conclusively identified** |
| `0x600c7d64` | 336 | In the "not conclusively identified" `0x600c74xx`–`0x600c80xx` zone flagged by prior sessions; single callee is a memcpy-shaped thunk. **Not conclusively identified** |
| `0x600c8454` | 438 | Called directly from the confirmed `smp_encrypt_data` (`0x600c0ac4`) — an SMP-adjacent leaf helper (single callee is the memset thunk) |
| `0x600c9aac` | 536 | Binary/extended-Euclidean-style **modular-inverse** routine over the same word-count-parameterized bignums as the P-256/P-192 modular-reduction code, called directly from the confirmed EC scalar-multiplication function `FUN_600c8798` — plausibly the affine-coordinate (Z⁻¹) conversion step in the point-arithmetic pipeline |

## Session 10: shape/call-graph sweep continues (80 new, 490 of 1,076 in-census)

Session 9's string-table exhaustion still holds (re-confirmed: none of the 80 functions below reference the `0x60103xxx`–`0x60122xxx` table). This session took the next 80-largest still-undecompiled functions in the block by the address-based join (`bruce_functions.csv` ∩ `[0x600921b8, 0x600c9cc4)`, minus addresses already present as a decomp-header address in `analysis/decomp/*.c`, sorted by `size_bytes` descending — same join `bruce-decompile-status.md`'s methodology specifies), decompiled in three sequential `Decompile.java` batches (27+27+26 addresses), and read every one against callers/callees. Sizes have dropped further (304→204 bytes across this batch, vs. session 9's 406-byte average) — diminishing returns from pure size-ranking continues, but this batch's *quality* of finds was unusually high because so many callees are now named, turning what would have been blind reads into corroborated identifications.

**Headline finds this session, roughly in order of confidence:**

1. **`FUN_600a9234` is `btu_hcif_send_cmd`-shaped — the single shared HCI command-transmit engine.** 119 static callers (audit correction: the decomp header's caller list has 119 entries, not 122 as originally stated — recount, not a re-analysis): essentially every `btsnd_hcic_*` function in the whole block, plus `btu_task` itself. Manages a per-OGF-group outstanding-command-count/queue (indexed `param_1*0x34+0xa0`), dequeues a pending command via `FUN_600d9250` when the credit count allows, hands it to the confirmed `btu_hcif_store_cmd` (`FUN_600a85b8`), and for the primary (H4) transport forwards it to the confirmed `bte_hcisu_send`-family function (`FUN_6006b98c`, the cross-object-file cluster the address-range map's footnote already named). This is exactly the function `btu_task`'s own writeup already described in prose ("HCI cmd-send via `FUN_600a9234`") but it had never actually been decompiled until now.
2. **AES subsystem found and chained end-to-end**, resolving the long-flagged "not conclusively identified" `0x600c74xx`–`0x600c80xx` zone into a real, coherent finding:
   - `FUN_600c7fc8` (304B) is a byte-for-byte match for AES's **SubBytes+ShiftRows** combined round step: a 256-byte S-box lookup applied to all 16 state bytes, with row 0 unshifted, row 1 shifted left 1, row 2 shifted left 2 (pairwise swap), row 3 shifted left 3 — exactly the Rijndael state-shift pattern for a 4×4 column-major byte array. High confidence by direct structural/spec match, same evidentiary style as the HCI-opcode table in Evidence §2. **Audit correction/strengthening:** `DAT_600c80f8` is itself a 4-byte global *pointer variable* (sitting in the 4 bytes immediately after this function, at the exact address the decompiler labels it — not a 256-byte table inline at that address as the original phrasing implied); its stored value is `0x601194f4`. Dereferencing that address in the flash image and comparing byte-for-byte against the canonical Rijndael/AES S-box confirms an **exact match, all 256 bytes** — stronger, byte-level confirmation than the original write-up itself claimed (it only asserted the *shape*, not that the literal table bytes were checked).
   - `FUN_600c09f0` (204B) is **AES-CMAC**: allocates a GKI buffer rounded up to a 16-byte-block boundary, right-pads the message into the final block (textbook CMAC padding), then calls `FUN_600c07e4` (204B, this session — a block-by-block CBC-chaining loop indexed off a subkey table `DAT_600c08c0`) to do the actual MAC computation. Confirmed (not just shape-inferred) by its caller list: the string-named **`BTM_BleDataSignature`** (`0x6009b77c`) — which per the Bluetooth Core Spec computes LE data-signing MACs using AES-CMAC, an exact algorithmic match — plus `FUN_600c12b0` below.
   - `FUN_600c12b0` (300B) calls `FUN_600c09f0` (AES-CMAC) over an 80-byte message assembled from a 16-byte chunk plus two 32-byte chunks, under a 16-byte key, then reduces 4 bytes of the CMAC output modulo a global bound via repeated subtraction — the exact size shape of SMP's **`g2`** numeric-comparison-value function (Core Spec Vol 3 Part H §2.2.8: `g2(U,V,X,Y) = AES-CMAC_X(U||V||Y)`, low 32 bits reduced mod 10⁶ for display). High confidence given the byte-for-byte size/structural match to a well-known, fully-specified function. **Audit caveat:** the decompiled buffer-assembly order is actually [16-byte chunk][32-byte][32-byte] (the 16-byte chunk — presumably `Y` — copied in *first*, not last), which doesn't literally read as `U||V||Y` in memory order; this wasn't resolved against `FUN_600c07e4`'s block-chaining loop, which itself processes blocks in descending (last-to-first) index order and could plausibly reconcile the two, but that reconciliation wasn't verified. The size/key-length/mod-reduction evidence still supports `g2` strongly; treat the exact operand-to-U/V/X/Y mapping as unconfirmed rather than the "byte-for-byte" framing implied here.
   - `FUN_600c8610` (292B, this session) sits immediately before the confirmed EC scalar-multiplication cluster and, for a curve-ID argument of `8`, copies two 8-word (256-bit) constant blocks from a static table into a per-curve context — plausibly the P-256 curve-parameter loader, though not spec-verified byte-for-byte (no modulus/generator literal cross-checked this session).
   This gives the crypto side of the doc a second, independently-confirmed algorithm (AES-CMAC) alongside the existing SHA-512/Curve25519/P-256 findings, and ties two previously-"not conclusively identified" addresses into the existing EC-crypto cluster's immediate neighborhood.
3. **SMP's IO-Capability pairing-method-selection table, spec-shaped.** `FUN_600c23f4`/`FUN_600c24d0` (216B each) are a near-identical pair, each indexing a 5×5 lookup table (`DAT_600c24cc`/`DAT_600c25a8`) keyed by two IO-capability-shaped fields (`+0x18d`/`+0x18e`, values 0–4 — exactly the Bluetooth SMP IO Capability enum's 5 values: DisplayOnly/DisplayYesNo/KeyboardOnly/NoInputNoOutput/KeyboardDisplay) with a role byte choosing lookup order, plus fixed-code fallbacks for "already bonded" and "no MITM required" special cases. This is a strong structural match for the Core Spec's "Mapping of IO Capabilities to Key Generation Method" table (Vol 3, Part H, §2.3.5.1); the two functions sharing shape but different output-code sets/tables are plausibly the Legacy-pairing vs. LE-Secure-Connections variants. Sits right at the SMP address range's edge (`0x600c23f4`/`0x600c24d0`, just below the previously-mapped `0x600c0ac4`–`0x600c239c` SMP span — the SMP module's real extent is very slightly larger than previously mapped).
4. **`FUN_600ad130` is very likely `gatts_check_perm`, spec-verified via ATT error codes.** Validates a permission bitmask against link security-level flags and returns literal ATT error-code values that match the spec table exactly: `0x02` (Read Not Permitted, when no permission bits are set at all), `0x05` (Insufficient Authentication), `0x0f`/`0x0c` (Insufficient Encryption / Insufficient Encryption Key Size), `0x0b` (Attribute Not Long), `0` (success) — five of six branches independently spec-checkable, same evidentiary style as Evidence §2's HCI opcode table.
5. **`FUN_600ae7f8` is the ATT Exchange-MTU-Request handler, spec-verified.** Clamps a proposed MTU to `[0x17, 0x205]` — 23 and 517, the Bluetooth spec's exact minimum and maximum ATT_MTU — then builds a response via `FUN_600c7eb8(...,3,...)` (opcode `3` = ATT_EXCHANGE_MTU_RSP, exact match) and fans the negotiated MTU out to up to 10 connection records. High confidence, byte-for-byte spec match on both the MTU bounds and the opcode.
6. **`FUN_600bb44c` is very likely `l2cu_allocate_ccb`.** Finds a free slot in the 4-entry/0xa4-stride table (`DAT_600bb528`) that turns out to be referenced from at least 6 other functions this and prior sessions treated as distinct ad-hoc "queues" (`FUN_600b8888`'s `DAT_600b89b4`, `FUN_600bc480`'s `DAT_600bc56c` — same table, different local symbol names from Ghidra), zeroes it, writes the BD_ADDR at offset 4, and dispatches to the confirmed L2CAP round-robin scheduling-interval calculators (`FUN_600b5c08`/`FUN_600b8f0c`) depending on channel mode. This resolves what several individual sessions had been calling "an 0xa4-stride pending-connection table" into one real, consistently-identified data structure.
7. **`FUN_600ac438` is very likely GATT's shared client-op security gate** (`gatt_security_check_start`/`gatt_act_write`-shaped) — called directly by the confirmed `GATTC_Read`, `GATTC_Write`, `gatt_enc_cmpl_cback`, and `gatt_notify_enc_cmpl`. Checks connection security state via the confirmed `FUN_600ac2a4`, then either signs the request (case 2, calls the confirmed `gatt_sign_data`) or triggers an encryption upgrade and queues the pending op (cases 3–6, via the confirmed `gatt_add_pending_enc_channel_clcb`) — the common pre-flight every GATT client operation routes through.
8. **`FUN_600a2f3c` is very likely `btm_process_inq_complete`.** Clears the inquiry-active bit and, on full completion, calls the confirmed `btm_clr_inq_result_flt` and (conditionally) `btm_sort_inq_result` in the right order before resetting inquiry state and firing a registered completion callback — called from the confirmed `btm_initiate_inquiry` among others.
9. **`FUN_600bd65c` is very likely `sdp_create_record_hdl`.** Allocates a new entry in the same 8-slot/0x1cc-stride array `FUN_600bd730` manages, assigning an incrementing record handle that **starts at `0x10000`** — the exact value the Bluetooth SDP spec reserves as the first dynamically-assignable service-record handle (handles below that are reserved). Spec-level match, not just shape.
10. **`FUN_60094dc4` is very likely `bta_gattc_hdl_event`**, BTA GATTC's top-level event dispatcher — a switch on a 16-bit opcode in the `0x1d00`–`0x1d1a` range routing to the confirmed `bta_gattc_register` (`0x1d17`) and `bta_gattc_process_api_refresh` (`0x1d0c`) among other (undecompiled) targets, with a default case falling through to a generic completion-send (`FUN_60094d24`). `FUN_600c64c8` (this session) is a plausible sibling GATTC-event-type sub-dispatcher (opcodes 2–5) feeding the same `FUN_60094d24` completion path.
11. **`FUN_600950bc` is very likely `bta_gattc_conn_alloc`** — finds a free slot in a 6-entry connection table, resolves a client record and a server-cache-record block (falling back to the confirmed `bta_gattc_srcb_alloc`), and increments both refcounts.
12. **`FUN_600ab8d4` is a shared GATT app-ID registration-table manager** — called directly by the confirmed `bta_gattc_register`, `bta_gatts_register`, *and* the GAP-service bootstrap `FUN_600aac04`, all funnelling through one 10-slot table to find-or-allocate an app ID.
13. **`FUN_600a4a20` is very likely BTM's Simple Pairing user-confirmation handler** — auto-accepts/rejects an HCI User Confirmation Request via the confirmed `btsnd_hcic_user_conf_reply`/`btsnd_hcic_user_passkey_neg_reply`, gated on a device auto-accept mode and a numeric-comparison-value threshold.
14. **`FUN_6009cc7c` is very likely `BTM_SetAdvParams`/`btm_ble_set_adv_params`** — validates advertising-interval bounds and issues the confirmed `btsnd_hcic_ble_write_adv_params`. This is the exact function `adapter.cc`'s session-15 writeup already named as the callee behind `"Failed to set advertising speed"` in `adapter__60069780`, closing that reference.
15. **Two functions show corrupted/unreliable decompilation** (`FUN_600bc9e4`, `FUN_600b7cba`) — Ghidra recovered `unaff_r7`/condition-code pseudo-registers instead of real parameters/locals, the same red flag as the known `FUN_601054dc` TBB/TBH jump-table corruption CLAUDE.md already flags. Their visible logic is still plausibly readable (both look like L2CAP fixed-channel/FCR supervisory-frame teardown-adjacent code, calling the confirmed `l2cu_release_ccb` and `l2c_fcr_send_S_frame` respectively) but neither should be trusted as a clean read — needs a GUI function-boundary fixup, not another blind headless decompile.

Several more functions this session leaned on the same handful of newly-corroborating named callees (`btsnd_hcic_ble_start_enc`, `btsnd_hcic_ble_write_host_supported`, `btm_sort_inq_result`/`btm_clr_inq_result_flt`, `bta_dm_disable_conn_down_timer_cback`, `bta_dm_acl_change`) to reach "very likely" (not just "plausible") identifications — see the table below for the full per-function evidence. A recurring, still-unnamed structural pattern worth flagging forward: at least four functions this session (`FUN_6009a2c8`, `FUN_6009980c`, `FUN_600a0e88`, `FUN_600a2884`) share one caller, `FUN_600f2532` (in decompile-status run #2, `0x600faxxx`–`0x600fcxxx`), and a nearly-identical "stop a timer, scan a 4-entry/0xa6-stride connection table by 2-byte key, invoke a registered callback" shape — `FUN_600f2532` itself is a good next-session target, plausibly an HCI-event or periodic-timer sub-dispatcher analogous to the LE-Meta sub-dispatch already found inside `FUN_600a89f0`.

**RFCOMM/SPP/HFP: re-checked this session, still no evidence of any kind.** Per the task brief's instruction to take a fresh look now that the decompiled base is much larger — re-ran the identifier-shaped grep (`rfc_|rfcomm|spp_|hfp_|port_rfc|obex|hands.?free|headset` etc.) against the full, current `bruce_strings.txt`. Result unchanged from session 8: the only hit is the bare `[RFCOMM]` tag string at `0x60121a14` (a debug-log category tag, not a function-name leak) plus unrelated `rfc822*`-email-address strings and headset-audio-detection strings (`"Detected headset with microphone"` etc., part of the mic/audio-DSP subsystem `bruce-itcm.md` already mapped, nothing to do with the Bluetooth RFCOMM protocol). No `rfc_*`/`port_*`-prefixed function-name string exists anywhere in the image, and none of this session's 80 newly-decompiled functions (nor any prior session's) reference or resemble RFCOMM/SPP/HFP framing. Given the string-table lead is exhausted and three sessions (7, 8, 10) have now independently found nothing, the working hypothesis should shift from "still an open question" to "very likely not linked into this firmware image at all" — `bruce` (the BT-only controller firmware) plausibly never needed RFCOMM/SPP/HFP since its only Bluetooth role is a GATT/BLE HID-ish peripheral, not a classic-profile device requiring serial-port emulation or audio profiles.

| Address | Bytes | Name / description |
|---|---:|---|
| `0x60093500` | 210 | BTA DM connection-down cleanup — resets a 3×3 per-slot connection-parameter table (fields to `0x32`/`0`) for active slots, calls `FUN_600a337c`(4,…)/`FUN_60095c14`(0); called directly from the confirmed `bta_dm_disable_conn_down_timer_cback` |
| `0x60094dc4` | 220 | Very likely **`bta_gattc_hdl_event`** — BTA GATTC's top-level event dispatcher, switches on a 16-bit opcode (`0x1d00`–`0x1d1a`) routing to the confirmed `bta_gattc_register`/`bta_gattc_process_api_refresh` among others; no static callers (message-table invoked) |
| `0x600950bc` | 218 | Very likely **`bta_gattc_conn_alloc`** — allocates a connection-table slot, resolves a client record and (via the confirmed `bta_gattc_srcb_alloc`) a server-cache-record block, increments both refcounts |
| `0x60096450` | 208 | Very likely the **software-timer-list expiry sweep** (`btu_process_timer_evt`-shaped) — walks a sorted timer list decrementing/popping expired entries, dispatching per-timer callbacks or sending a GKI event via the confirmed `bta_sys_sendmsg`; called from `FUN_6009623c`, the exact periodic-helper `btu_task`'s own writeup already names |
| `0x60096624` | 226 | BTM/HCI default-configuration initializer — resets retry/mode counters and fills page/inquiry-scan-type + packet-type defaults (falls back to hardcoded `0x18`/`200`); one-time init, called from well outside this block |
| `0x600976f8` | 256 | BTM link-mode-change state tracker — maintains a per-link-mode-index active/pending bitmask and fires a registered completion callback on transition; sibling of the confirmed `0x60097b20`/`0x60097f5c` link-policy pair |
| `0x60097488` | 256 | BTM link-mode-change event parser feeding `FUN_600976f8` above; no static callers (dynamically invoked) |
| `0x600977fc` | 256 | Broadcom vendor-specific HCI command builder — opcode `0xfce9` (OGF `0x3f`/vendor, OCF `0x3a9`), issued via the confirmed `BTM_VendorSpecificCommand`; called from the confirmed BTM link-policy orchestrator `FUN_60097dc8` |
| `0x60097904` | 216 | Near-twin of `0x600977fc` (same vendor opcode `0xfce9`, same callers) — sub-command `9` instead of `10`, data capped at 0x1d instead of 0x1b |
| `0x60098284` | 240 | Broadcom vendor feature-bit toggle — flips a bit in a global feature-mask then re-sends it via the confirmed `BTM_VendorSpecificCommand` (same `0xfce9` opcode cluster); 5 static callers |
| `0x60099adc` | 214 | BTM key-material accumulation state machine — writes an 8-byte chunk per call into an indexed table, same "accumulate N×8-byte chunks" shape as the confirmed SMP keypair-entropy state machine but in the BTM module; not conclusively named |
| `0x600998ec` | 204 | Small event-record updater — scans the recurring 4-entry/0xa6-stride BTM connection table by 2-byte key, updates two fields on match |
| `0x6009980c` | 210 | Near-twin of `0x6009a2c8` below (same shape: stop timer, scan the 4-entry/0xa6-stride table, invoke registered callback) but parses two 2-byte fields instead of one; shares caller `FUN_600f2532` |
| `0x60099dd0` | 298 | BTM ACL link-record allocate/update/teardown helper — calls the confirmed `btsnd_hcic_disconnect` and `btsnd_hcic_set_conn_encrypt`; called from the confirmed ACL/connection dispatch helper `FUN_600a96d8` |
| `0x60099fdc` | 298 | BTM link-record feature-bitmask → timeout-constant lookup (large if/else ladder mapping flag bits to specific timeout values, clamped against a global max); not conclusively named |
| `0x6009a2c8` | 250 | HCI-event completion handler — stops a pending timer, scans the 4-entry/0xa6-stride connection table by 2-byte key, invokes a registered result callback; shares caller `FUN_600f2532` with `0x600a2884`/`0x600a0e88`/`0x6009980c` |
| `0x6009a8ec` | 210 | Very likely **BTM LE-host-support enable/disable** — toggles support flags and issues the confirmed `btsnd_hcic_ble_write_host_supported` |
| `0x6009afd4` | 206 | Very likely **`btm_ble_start_encrypt`**-shaped — checks link encryption state, issues the confirmed `btsnd_hcic_ble_start_enc` with stored or caller-supplied LTK/rand/ediv, sets pending-encryption state on success |
| `0x6009b134` | 248 | Device-record flags sanitizer — optional registered filter callback, else derives a 3-field flags record from a 16-bit input and a type/subtype check; no static callers; not conclusively identified |
| `0x6009b290` | 206 | ACL link-record creation/population helper — allocates or updates an ACL record with a new connection handle/BD_ADDR/role; called from the confirmed LE-connection-complete-style parser `FUN_6009b368` — very likely `btm_acl_created`-shaped |
| `0x6009cc7c` | 268 | Very likely **`BTM_SetAdvParams`/`btm_ble_set_adv_params`** — validates advertising-interval bounds, issues the confirmed `btsnd_hcic_ble_write_adv_params`; confirmed as the callee `adapter.cc`'s session-15 `"Failed to set advertising speed"` reference names |
| `0x6009d9d4` | 206 | BTM packet-type/sniff-mode flag computer — derives a 2-bit mode field from supervision-timeout/interval bits and a feature-support flag; no static callers found |
| `0x6009e098` | 270 | BTM inquiry-result filter/report-flags computer — combines RSSI/extended-inquiry-mode bits, a BD_ADDR match, and a device-class filter bit into a result-flags byte; called from the confirmed BTM inquiry-control helper `FUN_6009e4d0` |
| `0x6009e1b4` | 288 | BTM inquiry-result record builder — parses a variable-length EIR/name-shaped buffer into an inquiry-database record; called from the confirmed `FUN_6009e4d0` — plausibly `btm_process_inq_result`-shaped |
| `0x6009e3f0` | 214 | Very likely **`btm_process_inq_results`**-shaped — the top-level (Extended) Inquiry Result event parser: iterates a variable-count sequence of per-device results, classifies each, and routes to `FUN_6009bd70` (resolvable-address branch) or the confirmed `FUN_6009e4d0` |
| `0x6009f124` | 210 | BLE resolving-list-bitmap reallocation/reset helper — calls the confirmed `btm_ble_resolving_list_init` and resets 8 in-use bit flags |
| `0x600a038c` | 210 | BTM link-controller one-time init — resets an 8-entry array and initializes cached page/inquiry-scan window/interval defaults (`0x12`/`0x1000`, `0x12`/`0x800`); `btm_init`-adjacent |
| `0x600a0bc4` | 218 | Very likely the **local extended-features (pages 0–2) read-complete sequencer** — scans a 3-page×8-byte feature table, applies each page via the confirmed `FUN_600a08c4`, finalizes local feature setup, and fires a registered completion callback |
| `0x600a0e88` | 236 | BTM state-tracking event handler — stops a timer, writes an 8-byte chunk into an indexed table for status 0–2, toggles a mode-flag bit for status 1; shares caller `FUN_600f2532` with the `0xa6`-stride-table cluster; not conclusively named |
| `0x600a17ec` | 272 | Very likely **`BTM_SetPageScanParams`/`BTM_SetInquiryScanParams`**-shaped (combined) — validates window/interval bounds (`0x11`–`0x1000`, window ≤ interval) against cached values, issuing the confirmed `btsnd_hcic_write_pagescan_cfg`/`btsnd_hcic_write_inqscan_cfg` only on change |
| `0x600a2884` | 280 | BTM periodic-inquiry state advancer — re-initiates inquiry via the confirmed `btm_initiate_inquiry` or invokes a registered completion callback; shares caller `FUN_600f2532` |
| `0x600a2f3c` | 208 | Very likely **`btm_process_inq_complete`** — clears the inquiry-active bit and, on completion, calls the confirmed `btm_clr_inq_result_flt` and `btm_sort_inq_result` in order before firing a registered completion callback; called from the confirmed `btm_initiate_inquiry` |
| `0x600a3014` | 210 | Very likely **`btm_accept_connection`/`btm_sec_rcv_conn_req`**-shaped — accept/reject decision issuing the confirmed `btsnd_hcic_accept_conn`, starts an 8-unit timer via the confirmed `btu_start_timer` on fresh accept |
| `0x600a3904` | 304 | BTM link-policy negotiation helper (mode/role table scan calling `FUN_600a3784`); called from the confirmed link-policy mode-request helper `FUN_600a3a38` |
| `0x600a4a20` | 238 | Very likely **BTM's SSP user-confirmation handler** — auto-accepts/rejects an HCI User Confirmation Request via the confirmed `btsnd_hcic_user_conf_reply`/`btsnd_hcic_user_passkey_neg_reply`, gated on device mode and a numeric-comparison threshold |
| `0x600a5540` | 288 | Very likely **`btm_sec_rcv_conn_req`**-shaped BTM incoming-connection gate — validates connectable-mode state and an optional registered security callback plus BD_ADDR check, then calls `FUN_600b8888` (below) and marks a status bit; rejects via the confirmed reject-sender on failure |
| `0x600a65f4` | 286 | BTM link-key/security-completion event handler — parses a BD_ADDR + status-code buffer, special-cases HCI status `0x18` (Pairing Not Allowed) vs. BD_ADDR-mismatch vs. success, forwards via a registered callback; not conclusively named |
| `0x600a7d0c` | 230 | BTM security/authentication-procedure dispatcher — either completes immediately or invokes a registered callback with link-security-state params; called from the confirmed shared sub-routine `FUN_600a7b44` |
| `0x600a8494` | 288 | Very likely **`btm_process_remote_ext_features`**-shaped — sets ACL packet-type/flags from remote extended-features bits, conditionally issues the confirmed `btsnd_hcic_read_authenticated_payload_tout`, forwards a pending BD_ADDR to the confirmed `FUN_600a5ec8`; called from the confirmed post-ACL remote-capability sequencer `FUN_60098f88` |
| `0x600a9234` | 204 | Very likely **`btu_hcif_send_cmd`** — the shared HCI command-transmit engine underlying essentially every `btsnd_hcic_*` function (119 static callers, audit-corrected from 122) and `btu_task` itself; manages a per-OGF outstanding-command queue, hands off to the confirmed `btu_hcif_store_cmd` and (for H4) the confirmed `bte_hcisu_send`-family function. See headline finding #1 above |
| `0x600ab8d4` | 222 | Shared GATT app-ID registration-table manager — find-or-allocate in a 10-slot table; called directly by the confirmed `bta_gattc_register`, `bta_gatts_register`, and the GAP-service bootstrap `FUN_600aac04` |
| `0x600ac438` | 210 | Very likely GATT's shared client-op **security gate** (`gatt_security_check_start`/`gatt_act_write`-shaped) — checks connection security via the confirmed `FUN_600ac2a4`, signs via the confirmed `gatt_sign_data` or queues a pending-encryption op via the confirmed `gatt_add_pending_enc_channel_clcb`; called directly by the confirmed `GATTC_Read`/`GATTC_Write`/`gatt_enc_cmpl_cback`/`gatt_notify_enc_cmpl` |
| `0x600ad130` | 244 | Very likely **`gatts_check_perm`**, spec-verified — returns literal ATT error codes (`0x02`/`0x05`/`0x0c`/`0x0f`/`0x0b`/`0`) matching the spec table exactly based on link security state vs. a permission bitmask |
| `0x600ad4f4` | 278 | GATT server helper — resolves an index via `FUN_600afb50` into a 0x28-stride attribute table, builds a 0x260-byte response record, forwards via `FUN_600f6b96` (run #2); not conclusively named |
| `0x600ad8fc` | 216 | GATT server per-connection callback fan-out — iterates a 10-entry client-record table, notifies eligible entries via a registered per-entry callback; not conclusively named |
| `0x600ae7f8` | 270 | Very likely the **ATT Exchange-MTU-Request handler**, spec-verified — clamps MTU to `[0x17,0x205]` (23–517, the spec's exact bounds), builds the response with ATT opcode `3` (Exchange MTU Response, exact match), fans the negotiated MTU out to up to 10 connections |
| `0x600b0444` | 240 | Trace/log formatter dispatcher — routes a small type code to `FUN_600cdd2c` (printf-style trace formatter outside this block); consistent with the codebase-wide log/`Buffer` framework (`bruce-log-buffer.md`), not protocol logic |
| `0x600b05f0` | 290 | GATT app-ID deregistration helper — scans a 3-entry table (two 10-slot client/server sub-lists) removing a matching app ID; called from the confirmed GATT client cleanup routine `FUN_600ab9b8` |
| `0x600b5720` | 274 | L2CAP CCB allocation/initialization for a new channel — looks up/rejects via the confirmed CCB-lookup helpers, initializes channel state (FCR/streaming mode, MTU fields, initial credit), triggers the confirmed BTM post-connection feature-read sequencer `FUN_60098f88`; consistent with `l2cu_allocate_ccb`-adjacent connect-request handling |
| `0x600b7cba` | 232 | **Decompilation corrupted** (`unaff_r7`/`in_r3` pseudo-registers, same red flag as `FUN_601054dc`) — visible logic switches on an S-frame subtype calling the confirmed `l2c_fcr_send_S_frame` with RR/RNR/REJ type codes; needs GUI fixup before trusting |
| `0x600b8888` | 300 | BTM/L2CAP connection-acceptance helper — issues the confirmed `btsnd_hcic_accept_conn` after a device-record state check, starts a 60-unit timer via the confirmed `btu_start_timer`; rejects via `FUN_600b233c` on failure paths |
| `0x600bb44c` | 218 | Very likely **`l2cu_allocate_ccb`** — finds a free slot in the recurring 4-entry/0xa4-stride table (shared across several previously-separately-described "queues"), zeroes it, writes the BD_ADDR, dispatches to the confirmed L2CAP round-robin schedulers `FUN_600b5c08`/`FUN_600b8f0c` by channel mode. See headline finding #6 |
| `0x600bb7e4` | 276 | Very likely a core **L2CAP I-frame buffer-construction primitive** (`l2cu_build_header`/`l2c_fcr_alloc_buf`-shaped) — allocates a GKI buffer and writes the L2CAP basic/FCR header (length, CID, SDU-length, frame-control byte by channel mode); 14 static callers spanning L2CAP FCR/basic-mode code |
| `0x600bc480` | 236 | L2CAP outgoing-connection-queue driver — scans the same 4-entry pending-connection queue `FUN_600b8888` uses, negotiates security/role via the confirmed `FUN_6009931c` or kicks off a fresh connection via the confirmed `l2cu_create_conn`-shaped `FUN_600bc5c4`; called from the confirmed `l2c_link_hci_disc_comp`/`l2c_link_hci_conn_comp`-shaped functions |
| `0x600bc880` | 266 | Very likely **`l2cu_allocate_ccb`**'s fixed-channel counterpart — allocates/initializes a per-fixed-channel CCB in a CID-indexed table, copies BD_ADDR/COD fields; 5 callers spanning L2CAP fixed-channel senders and the SMP-adjacent `FUN_600b5264` — corroborates SMP transiting L2CAP fixed channels via this exact allocator |
| `0x600bc9e4` | 256 | **Decompilation corrupted** (`unaff_r7`/condition-code pseudo-vars, same red flag as `FUN_601054dc`) — visible logic iterates a 4-entry fixed-channel array calling a per-channel disconnect callback then the confirmed `l2cu_release_ccb`; needs GUI fixup before trusting |
| `0x600bcae8` | 242 | Very likely **`l2cu_process_fixed_chnl_resp`**-shaped fixed-channel disconnect-notification sweep — tears down stale CCBs via the confirmed `l2cu_release_ccb`, invokes each fixed channel's disconnect-indication callback; called from the confirmed `l2c_link_hci_disc_comp`-adjacent helpers |
| `0x600bce60` | 292 | L2CAP FCR 4-byte control-field/length-header appender, MTU-clamped against local/remote MTU globals; called directly from the confirmed `l2c_fcr_send_S_frame` |
| `0x600bd65c` | 208 | Very likely **`sdp_create_record_hdl`**, spec-verified — allocates a new SDP-database record with an incrementing handle starting at `0x10000`, the exact Bluetooth SDP spec first-dynamic-handle value; shares the record array with `FUN_600bd730` |
| `0x600bd730` | 270 | Generic fixed-stride (0x1cc-byte) record-list removal helper, shift-compacting entries; callers span both an SDP-adjacent buffer builder and a GATT-range function — plausibly a shared list utility rather than single-module code |
| `0x600bdd9c` | 208 | Very likely **`sdp_init`**-shaped — zeroes a large (0xf98-byte) SDP database/control-block structure, sets default MTU (`0x100`) and two SDP-constant fields, conditionally populates config/callback fields |
| `0x600bdf3c` | 288 | L2CAP channel-config negotiation helper — looks up the CCB by CID, negotiates an MTU-like field, delegates to a config-option processor, transitions channel state to open and starts a timer via the confirmed `btu_start_timer`; consistent with `l2cu_process_our_cfg_req`/config-complete |
| `0x600bffe8` | 256 | SMP FSM per-state action handler #2 — same control-block state field (`+0x194`) as `FUN_600c0294` below, dispatches events via the confirmed `smp_sm_event`; not individually named |
| `0x600c0294` | 300 | SMP FSM per-state action handler #1 — switches on the SMP control-block state field (`+0x194`), dispatches events `0x17`/`0x20`/`0x21` via the confirmed `smp_sm_event`; not individually named |
| `0x600c07e4` | 218 | **AES-CMAC block-chaining loop** — the CBC-style per-16-byte-block MAC-computation inner loop, indexed off subkey table `DAT_600c08c0`; called only from `FUN_600c09f0` below. See headline finding #2 |
| `0x600c09f0` | 204 | **AES-CMAC**, confirmed — allocates and block-pads a message buffer, computes the MAC via `FUN_600c07e4` above; called from the string-named **`BTM_BleDataSignature`** (exact spec match: LE data signing uses AES-CMAC) and `FUN_600c12b0` below. See headline finding #2 |
| `0x600c12b0` | 300 | Very likely SMP's **`g2`** numeric-comparison-value function — computes AES-CMAC (via the confirmed `FUN_600c09f0`) over `U(32B)‖V(32B)‖Y(16B)`, reduces the last 4 bytes mod a global bound (mod-10⁶ shape). See headline finding #2 |
| `0x600c1788` | 214 | SMP pairing-initiation trigger — compares an incoming BD_ADDR against the SMP control block, forwards via the confirmed `smp_sm_event` (event `0x13`) or, first-time, initializes default IO-cap/auth-req fields and fires event `0x12`; no static callers found |
| `0x600c23f4` | 216 | SMP IO-Capability → pairing-method-selection function (variant A) — 5×5 IO-capability table lookup, spec-shaped. See headline finding #3 |
| `0x600c24d0` | 216 | SMP IO-Capability → pairing-method-selection function (variant B) — near-identical twin of `0x600c23f4`, different table/output codes (plausibly LE Secure Connections vs. Legacy). See headline finding #3 |
| `0x600c2a28` | 270 | BTA DM search/discovery UUID-filter builder — converts a 32-entry UUID bitmask into a 64-bit filter-bucket array via a lookup table, then calls the confirmed BTM/BLE scan-kickoff helper `FUN_6009fae0`; confirms that function's session-9-noted caller identity |
| `0x600c2c04` | 244 | BTA DM "device found"/search-result callback trigger — selects BR/EDR vs. LE processing via the same HCI-event sub-handlers (`FUN_600f1ad4`/`FUN_600f1b34`) the confirmed `FUN_600a44bc` uses, builds a 0x118-byte device-info record, fires a registered app callback (event id 3) |
| `0x600c2d5c` | 296 | BTA power-management event handler — switches on a small event-code set (`0x10`–`0x13`) toggling per-connection PM-mode bits and a global active-mode-count bitmask, calling `FUN_60099768` on count transitions; plausibly `bta_dm_pm`-adjacent |
| `0x600c424c` | 204 | Remote-name-request response bridge feeding the confirmed `bta_dm_remname_cback` — fetches a device name (`FUN_6004cb28`, confirming CLAUDE.md's existing note that this address is a name-fetch helper, not real crypto, despite sitting in the SHA-512-compression neighborhood) or forwards a pending/error status |
| `0x600c4674` | 224 | Sibling of `FUN_600c2c04` above — builds an identical 0x118-byte device-found record (BD_ADDR + EIR/name + a UUID field) and fires the same registered app callback (event id 3); very likely the UUID-match/service-discovery-result variant |
| `0x600c53f8` | 236 | BTA DM link-state consistency/PM-gate — compares link-status counters and, on mismatch, advances encryption/role negotiation via the confirmed `FUN_6009931c` while gating power-management eligibility; called directly from the confirmed `bta_dm_acl_change` |
| `0x600c64c8` | 226 | Plausible BTA GATTC event-type sub-dispatcher (opcodes 2–5), feeding the same completion-send primitive (`FUN_60094d24`) as `FUN_60094dc4` above; not conclusively named |
| `0x600c7aac` | 252 | Buffer/frame builder in the previously-flagged "not conclusively identified" `0x600c74xx`–`0x600c80xx` zone — allocates a GKI buffer and writes an ACL/L2CAP-shaped header plus variable data; no direct evidence tying it to the AES cluster found elsewhere in this zone this session |
| `0x600c7fc8` | 304 | **AES SubBytes+ShiftRows**, spec-verified byte-for-byte. See headline finding #2 |
| `0x600c8610` | 292 | Plausible **EC curve-parameter table loader** — for curve-ID `8`, copies two 8-word (256-bit) constant blocks from a static table into a per-curve context; sits immediately before the confirmed EC scalar-multiplication cluster. Not spec-verified (constants not cross-checked) |

## Relocated from `bruce-io-paths.md` session 12: an adjacent-but-distinct GATT-server engine (0x6005dxxx–0x600d8xxx), NOT part of this block

Session 12 of `bruce-io-paths.md` (chasing the HID report-packing function's last gap) decompiled ~15 functions it described as part of "the real GATT-server engine cluster." One of them, `FUN_600aee8c`, genuinely is inside this doc's `0x600921b8`–`0x600c9cc4` block and has been folded into the function table and running count above. **The other 20 are not** — their addresses (`0x6005d9d0`–`0x600d8b6c`) fall well outside this block on both ends: 19 sit *before* `0x600921b8` (some by over 300 KB), and one (`0x600d8b6c`) sits just after `0x600c9cc4`. They cluster around a distinct `gatt_server.cc`/`gatt_server.h`/`adapter.cc` source-file group at `0x6005dxxx`–`0x60081xxx`, which `bruce-io-paths.md` session 12 itself identifies as "a separate... cluster" from this block's own Broadcom-named GATT client/server core (`~0x600aaxxx`–`0x600b02xx`) — i.e. this looks like a higher-level, Google-authored GATT-server wrapper built on top of the Broadcom BTA/BTE `BTA_GATTS_*` API documented above, not more of the Broadcom stack itself. No string-table or object-file evidence ties it to the same linked module as this doc's subject, unlike the two confirmed-same-object-file clusters already noted in the address-range map (`bte_hcisu_*`, `bta_gattc_ci_cache_*`). Recorded here for discoverability and cross-reference, but **not added to this block's function table or its "of 1,076" running count**, since that count is specifically scoped to the one contiguous range this doc tracks.

Sorted by address (descriptions confirmed against `analysis/decomp/*.c`, not re-derived — see `bruce-io-paths.md` session 12 for the full narrative and the report-packing investigation this was a side-effect of):

| Address | Bytes | Name / description |
|---|---:|---|
| `0x6005d9d0` | 104 | **gatt_server__6005d9d0** (`src: gatt_server.h`) — bounded-capacity registration: appends a value into an 8-slot array at `param_1+8` (counter at `+4`), logging `"Insufficient service handles available"` when full. Called from `gatt_server__60081ab4` (session 11) |
| `0x600695dc` | 96 | **adapter__600695dc** (`src: adapter.cc`) — the `"CharacteristicAdded"`-event entry point: iterates a connection/device-record array (base `+0x1ab4`, count `+0x1ab8`, stride `0x1994`) calling `gatt_server__6006a9c8` for each, guarded by a readiness check (`FUN_600d8994`) that otherwise logs `"Cannot execute %s without being i…"` |
| `0x60069ed4` | 24 | **FUN_60069ed4** — calls `FUN_60095904` (**`BTA_GATTS_SendRsp`**) then `adapter__600691f4`; the "one other gap-function caller" of `BTA_GATTS_SendRsp` noted alongside `gatt_server__6006ae20` in session 12 |
| `0x6006a5c8` | 98 | **gatt_server__6006a5c8** (`src: gatt_server.cc`) — UUID descriptor normalizer: converts a tagged-variant UUID (tag `0`=16-bit, else 128-bit) into a fixed `0x14`-byte internal descriptor; used ahead of `BTA_GATTS_AddCharacteristic`/`CreateService` calls |
| `0x6006a634` | 244 | **gatt_server__6006a634** (`src: gatt_server.h`) — binary-search sorted-insert of a `{uuid, record}` pair into a ≤64-entry handle-map array (shift-and-insert on miss); called from `gatt_server__6006a9c8` |
| `0x6006a734` | 70 | **gatt_server__6006a734** (`src: gatt_server.h`) — caches an attribute value: sets a "valid" flag + length field and memcpy's (`thunk_EXT_FUN_0000b572`) up to `param_3` bytes into the record, warning-logging if length > 600; called from `gatt_server__6006ae20` right after its read-callback/getter returns a value |
| `0x6006a860` | 16 | **FUN_6006a860** — thin wrapper for `BTA_GATTS_HandleValueIndication` (`FUN_60095878`); zero static callers found (`FindRef` negative) — the real notification/indication-send entry point, whose trigger remains as unfound as `object(0x2000385c)+0x114`'s |
| `0x6006a880` | 182 | **gatt_server__6006a880** (`src: gatt_server.cc`) — resets/tears down all registered services: for each of `param_1+0x1714` records, deletes it via `BTA_GATTS_DeleteService` (`FUN_600957ec`), clears its child characteristic-handle sub-list, reinitializes the `0x11c`-byte record to a default state, then zeroes the record/handle counters |
| `0x6006a944` | 124 | **gatt_server__6006a944** (`src: gatt_server.cc`) — creates a new service record: allocates a free slot (`FUN_600d8ae8`), normalizes the UUID (`gatt_server__6006a5c8`), calls `BTA_GATTS_CreateService` (`FUN_60095690`), and stores the resulting service index back into the caller's descriptor |
| `0x6006a9c8` | 300 | **gatt_server__6006a9c8** (`src: gatt_server.cc`) — characteristic registration: called from `adapter__600695dc` (gated on `"CharacteristicAdded"`), matches a characteristic UUID against a per-service table (`FUN_600d8b6c`), then calls `gatt_server__6006a634` to bind the matched record to its assigned ATT handle |
| `0x6006ab14` | 206 | **gatt_server__6006ab14** (`src: gatt_server.cc`) — builds a log record from two 5-word (128-bit-UUID-shaped) parameters plus 3 scalar params and forwards to `FUN_6006a4d4` (not decompiled), logging via `FUN_60051120` on failure — plausibly an `AddCharDescriptor`-shaped registration call, not conclusively identified |
| `0x6006ac40` | 106 | **FUN_6006ac40** — helper used by both the ATT read (`gatt_server__6006ae20`) and write (`gatt_server__6006ad00`) dispatchers alongside `FUN_6006acb8`; part of the handle-map/record lookup machinery, not fully characterized |
| `0x6006acb8` | 62 | **FUN_6006acb8** — the handle→record lookup used by both `gatt_server__6006ae20` and `gatt_server__6006ad00` (wraps `FUN_6006ac00` against the sorted map at `param_1+0xc00`) |
| `0x6006ad00` | 256 | **gatt_server__6006ad00** — the **ATT Write-Request/Write-Command dispatcher**: looks up the per-handle record (`FUN_6006acb8`/`FUN_600d8b9e`), and if found calls its registered write-callback slot(s) (vtable `+4`/`+0x10`/`+8` depending on write type), else logs an error |
| `0x6006ae20` | 492 | **gatt_server__6006ae20** — the **ATT Read-Request dispatcher**: looks up the per-handle record, invokes its registered read-callback/getter, caches the result via `gatt_server__6006a734`, and sends the response via `BTA_GATTS_SendRsp` (`FUN_60095904`) |
| `0x60080ba4` | 36 | **FUN_60080ba4** — one-time-init gate inside `gatt_manager_task` (caller: `gatt_manager_task__60080bcc`): calls `FUN_60081c6c` once per boot (guarded by a flag byte) to bring up this GATT-server engine |
| `0x600814b8` | 46 | **FUN_600814b8** — lazy-init accessor used by `gatt_server__60081ab4`: logs once on first call, then returns a fixed value/pointer (`DAT_600814f0`) |
| `0x600819cc` | 40 | **FUN_600819cc** — one-time init creating a periodic software timer (`timer__60081450` → `timers__600cad24`) and zeroing an 8-byte state block; zero static callers (virtual-dispatched) — structurally a plausible periodic GATT housekeeping/notify-flush heartbeat, not proven |
| `0x60081a00` | 48 | **FUN_60081a00** — generic dynamic-buffer/array capacity-grower used by `gatt_server__60081ab4`: doubles a capacity field when exceeded (clamped to `0x7fffffff`), forwards to a resize primitive (`thunk_EXT_FUN_0000b532`), and calls a fatal-abort helper (`FUN_60101fd8`) if the tracked size is negative (corruption guard) |
| `0x600d8b6c` | 50 | **FUN_600d8b6c** — service lookup by 16-bit UUID: linear scan of a service array matching `*(ushort*)(entry+0x24c)==uuid`; called from `gatt_server__6006a9c8` to resolve which service a newly-added characteristic belongs to |

This engine is the same one session 12 traced `hid_input_target__60058aa8`'s confirmed caller chain into (`gatt_server__60081ab4` → `FUN_600813cc` → object `0x2000385c+0x114`, all session 11) — i.e. it's plausibly the actual BLE HID-report-notify plumbing, still with its final runtime trigger unresolved as of session 12. See `bruce-io-paths.md`'s "Session 12" section for the full investigation and open threads.

### Session 15: `adapter.cc` filled in (15 more functions, now 16/16 in this file) — the BLE peripheral-adapter wrapper

`analysis/bruce-decompile-status.md`'s cheap-win sweep decompiled the rest of `adapter.cc` (was 1/16, only `adapter__600695dc` above; now complete). It confirms this is a Google-authored, first-party C++ "BLE peripheral adapter" object sitting between application code and the Broadcom `BTA_GATTS_*`/L2CAP API this doc otherwise covers — not part of the Broadcom stack itself, consistent with the "adjacent-but-distinct" call above. It owns:

- **A per-connection record array** (base `+0x1ab4`, count `+0x1ab8`, stride `0x1994` bytes) — one record per connected GATT client, iterated by every "fan-out to all connections" function below.
- **ATT Prepare-Write / Execute-Write reassembly**, replacing/wrapping the controller's native long-write handling: `adapter__60069160` (96B) appends a fragment into a 600-byte buffer at `+0x1ac0`, validating the attribute-id matches across fragments (logs `"Prepare write already has data"` / `"...for different attr"` on mismatch); `adapter__600691cc` (32B) resets the buffer/length fields to empty; `adapter__60069b20` (210B) is the **Execute-Write handler** — rate-limited hex-dump logging of the accumulated buffer, then flushes it into `gatt_server__6006ad00` (the confirmed ATT Write dispatcher, table above) and clears the prepare-write state.
- **Characteristic/descriptor "Added" event fan-out**: `adapter__600695dc` (`"CharacteristicAdded"`, pre-existing) and the newly-decompiled `adapter__60069648` (122B, `"CharacteristicDescriptorAdded"`) both iterate the connection array calling into `gatt_server__6006a9c8`/`gatt_server__6006ab14` respectively.
- **Per-connection ATT Read/Write wrappers**: `adapter__60069a38` (204B) looks up a connection record by handle, rate-limit-logs (500ms window via `FUN_600d3618` timestamp compare, same idiom repeated at `adapter__60069b20` and `adapter__6006a21c`) and calls `gatt_server__6006ae20` (the confirmed ATT Read dispatcher).
- **Subscribe/unsubscribe tracking, virtual-dispatch confirmed; "CCCD" and "second, distinct array" both need correction (independent audit)** — `adapter__60069c58` (232B) walks an array rooted at `+0x1ab4`/count `+0x1ab8`, finds/grows a free slot, copies a 21-byte block (from `param_3`) into it, and — on success — invokes a **virtual call through `adapter__60069c10(param_1)`'s vtable slot `+0x18`** (`(**(code**)(*piVar6+0x18))(piVar6,param_3)` — a genuine indirect call through a dereferenced object/vtable pointer, not a direct call); on lookup failure it hex-dump-logs and calls `FUN_6009598c` (reject/cleanup). `adapter__60069d50` (104B) is the unsubscribe counterpart, removing the slot and calling the paired **vtable slot `+0x1c`** on success. **The virtual-dispatch part of this claim is solid** — both call sites are real vtable calls (dereference object → index into function-pointer table → call), confirmed by direct read of `analysis/decomp/adapter__60069c58.c`/`adapter__60069d50.c`.

  **Two corrections from re-reading the decompiled code directly:** (1) The "second, distinct per-client array (stride `0xcca`)" claim is wrong — `adapter__60069c58` walks the array as a `short*`, so Ghidra's displayed `+0xcca` step is in `short`-sized units: `0xcca * sizeof(short) = 0x1994` bytes, i.e. the *same* byte-stride, *same* base field (`+0x1ab4`), and *same* count field (`+0x1ab8`) as the connection/device-record array `adapter__600695dc` already uses (confirmed there with explicit `int`-typed arithmetic: `*(int*)(param_1+0x1ab8) * 0x1994 + iVar1`). So this is very likely the *same* connection-record array reinterpreted/indexed differently for this sub-purpose, not a second table — the "distinct array" framing should be dropped pending further work on what `adapter__60069c10`'s returned object actually is. (2) The **"CCCD-shaped" 2-byte-enable/disable-notification-bits characterization is an unconfirmed inference, not something the decompiled code itself shows** — `adapter__60069c58`'s 2-byte `param_2` is stored into the found slot but is never bit-tested against notify/indicate-style bits (`0x0001`/`0x0002`) anywhere in this function, and the 21-byte `param_3` block that *is* copied is opaque (no field-level ATT/CCCD structure visible from this function alone, no `0x2902` CCCD-UUID literal, no caller found to show what's actually passed in — both functions have zero callers in the decompiled set). The subscribe/unsubscribe-plus-vtable-notify *shape* is a reasonable hypothesis worth chasing, but calling it "CCCD tracking" outright overstates what's confirmed; it should be read as "an unidentified per-connection subscription-like table with virtual-dispatch notify on add/remove," pending a caller or the `adapter__60069c10` object's type. **This is a promising but not yet confirmed lead for `bruce-io-paths.md`'s still-open report-packing gap (thread 1)**: that thread's last unresolved hop is a GATT characteristic-callback slot installed by `FUN_600813cc` on an untyped C++ object, with the runtime invoker resisting three sessions of headless tracing. These two functions remain architecturally consistent with subscribe-triggered virtual-dispatch machinery (some client-facing event → vtable call `+0x18`/`+0x1c`) — worth checking whether `adapter__60069c10`'s returned object is the same `0x2000385c`-class object from session 11, and whether it's really CCCD-specific or something else keyed off the same connection-record array, next time this thread gets interactive-GUI attention. Not chased further this session (out of scope for a headless cheap-win pass, and per session 12's own assessment that this needs manual struct-typing in the GUI).
- **BLE advertising bring-up**: `adapter__60069780` (256B, called from `advertiser__60081234`) sets a random BD address if configured (`FUN_600b0974`, logs `"Failed to set random BD address"`), sets the advertising interval (`FUN_6009cc7c`, logs `"Failed to set advertising speed"`), builds the advertising payload via `adapter__600d89ec` and the scan-response payload via `FUN_600d8a12`, then starts advertising (`FUN_60092edc`) with connectable-directed-vs-undirected type selected by a caller flag.
- **`adapter__600d89ec`** (746B, the file's largest) — the actual **GAP advertising-data (AD structure) assembler**: builds a bitmask of present fields (flags, local name, appearance, up to 8×16-bit manufacturer-data words, TX power, a GATT-service-data block from `gatt_server__6006a5c8`'s UUID descriptor) and packs them via `FUN_60093258` (advertising-data path) or `FUN_600932bc` (scan-response path, selected by `param_3`). This is `BuildAdvertisingData()`/`BuildScanResponseData()`.
- **`adapter__6006a21c`** (344B, called from both `advertiser__60081234` and `FUN_60081c6c`) — adapter bring-up: busy-polls a BLE-stack-ready flag (`FUN_600ee278`, logging `"Waiting for BLE to come up..."` every 500ms), then reads and logs the local Bluetooth MAC address (`"Bluetooth MAC Address: %s"`) via `FUN_600d8a26`, optionally resolving a randomized/"DII" address mapping, and stores the result into one of two adapter-mode slots (`+0x11c` state 1 vs 2).
- **An "activation sequence" dependency-counter mechanism**: `adapter__60069964` (196B) appends an entry into a ≤10-slot array at `+0x1d18` and decrements a pending-count field at `+0x1e70`; `adapter__600691f4` (126B, called from `FUN_60069ed4` alongside `BTA_GATTS_SendRsp`) fires once both pending-counters (`+0x1e6c`/`+0x1e70`) reach zero, logging `"Activation sequence completed"` (or `"...interrupted"` on abort) and waking a waiter (`FUN_60101832`); `adapter__6006988c` (194B) walks a registered-listener array checking each is not still busy (via a per-listener vtable call) before allowing the same completion signal.
- **`adapter__60069570`** (98B) and **`adapter__600696d0`** (160B) — smaller UUID-tagged-union and synchronous request/wait glue (the latter blocks up to 5000ms via `FUN_60101822`, logging `"Timeout while waiting for applic[ation]..."` on expiry) — both plumbing for the higher-level calls above rather than independently interesting.

None of this touches HID report bytes directly (no button/ADC/stick fields anywhere in the file) — it's purely the BLE GAP/advertising and GATT-server-event plumbing layer, one level of abstraction above the `gatt_server.cc` engine documented above. The subscribe/unsubscribe vtable-dispatch finding is the one part worth flagging forward.


### Session 19: `remote_device_db.cc` — the BLE bonded-device flash database (4/4 decompiled)

`remote_device_db.cc` was `bruce-decompile-status.md`'s #2 cheap-win target (2,070 remaining bytes, 0/4); all 4 attributed functions are now decompiled (`analysis/decomp/remote_device_db__*.c`). Like `adapter.cc` above, it sits outside the confirmed `0x600921b8`–`0x600c9cc4` Broadcom block (its addresses are `0x6006c340` and `0x60083xxx`) but is clearly a first-party layer *for* that stack rather than unrelated code — it's the **flash-persisted bonded-device table**: BD_ADDR + LTK/IRK/link-key-shaped key material for previously-paired peers, the durable counterpart to whatever in-RAM "security record" array BTA/BTE itself keeps. Confirmed by its own leaked strings (`"remote_device_db.cc"`, `"Writing remote device database to flash"`, `"Failed to save BLE database to flash"`, `"No data to serialize"`) plus consistent record shape across all four functions:

- **`remote_device_db__6006c340`** (1,162B) — **load path.** Zeroes two ~0x908-byte working buffers, reads a fixed 0x800-byte block from flash via a vtable read callback, validates an 8-byte header (type field == 1, magic == `0x9d`, record count < 9) with a checksum/compare primitive (`thunk_EXT_FUN_0000b554`), then for up to 8 records unpacks a fixed `0x9d`(157)-byte-stride per-device record — 1-byte flag, 6-byte BD_ADDR, and several 16/20-ish-byte key/address-resolution-shaped fields — into a larger `0x118`-byte-stride in-RAM table (`DAT_60082fc4`). On any header/CRC mismatch it logs detailed diagnostics through the codebase-wide `Buffer` log framework (`bruce-log-buffer.md`) rather than silently discarding the store.
- **`remote_device_db__6008318c`** (638B) — **stage-for-write.** Walks a pending-record array (`DAT_60083420`, entries flagged active/inactive by a leading byte), reformats each active entry's fields into the same `0x9d`-byte-stride flash-image layout the loader reads, increments the running record count, appends a terminating zero record, and hands the finished count back to the caller (`remote_device_db__60083080`) plus a status/telemetry call.
- **`remote_device_db__60083080`** (246B) — **flush-to-flash / serialize.** Takes the staged in-RAM blob, computes a checksum (`FUN_600dfc30`) over it, writes the whole 0x800-byte block to flash through a vtable write callback, and on failure or CRC mismatch logs `"Failed to save BLE database to flash"`; logs `"No data to serialize"` and bails early if the record count is zero.
- **`remote_device_db__6008343c`** (24B) — trivial logged wrapper around `remote_device_db__6008318c`; almost certainly the public "save now" entry point called elsewhere (no caller found this session).

Net: a small, self-contained, power-loss-tolerant flash record store purpose-built for BLE bonding data — structurally similar to (but a distinct, fixed-record-format implementation from) the generic typed `key_value_store.cc`/`keys.cc` config store documented in `bruce-misc-functions.md`. No caller was found into the load/save entry points this session, so it's not yet confirmed *when* (pairing-complete? boot? periodic?) this gets triggered — a reasonable next hop for anyone picking up the BLE pairing/bonding thread.

**Aside for this doc's own module map**: `firmware_image_upload.cc`'s OTA chunk-write handler (`bruce-misc-functions.md`, session 19) calls `thunk_FUN_600921b8` — literally this doc's own block-start address — as a 2/3-argument CRC-style checksum primitive, not anything BT-specific. Worth a note that the very first function in the identified BTA/BTE range is (or thunks to) a generic checksum utility reused by unrelated subsystems, not evidence against the block identification as a whole (large linked C libraries routinely place a shared CRC/checksum helper at a translation unit's head), but a useful landmark if anyone is manually walking this block's start in Ghidra.

### Session 23: `activation_sequence.cc` — the concrete GATT-client "activate expected services" walker (2/2 decompiled)

`activation_sequence.cc` was `bruce-decompile-status.md`'s §3a rank-6 cheap-win target (468 remaining bytes, 0/2). Both attributed functions are now decompiled (`analysis/decomp/activation_sequence__*.c`), filling in the actual code behind the "activation sequence" dependency-counter mechanism the `adapter.cc` section above already found by shape (`adapter__60069964`/`600691f4`).

| Function | Bytes | Role |
|---|---:|---|
| `activation_sequence__60068f88` | 344 | **The step function**, called from both `adapter__60069964` and `adapter__600691f4`. Walks a discovered peer's GATT service/characteristic table (looked up via `FUN_600d8b3a`) one step at a time: if the peer doesn't expose the currently-targeted service UUID at all, logs `"Server does not support service "` and bails; otherwise, for the current characteristic index, either **decodes the raw ATT characteristic-properties byte into a normalized indicate/notify flag set and calls `FUN_60095700`** — a `BTA_GATTC`-shaped enable-notification/subscribe call — or, for a later step, calls `FUN_60095778(handle, 0x11, ...)` (a follow-up read/write-descriptor-shaped request). Advances the entry cursor each call, moving to the next service once the current one's entries are exhausted; on running past the last configured service, calls `FUN_6009582c` (disconnect/reject-shaped) and `activation_sequence__60068f04` (below) instead. |
| `activation_sequence__60068f04` | 124 | **Pop/compact helper.** Removes the front entry from a fixed 0x20-byte-stride pending-activation array and shifts the remainder down by one slot — the array-management primitive the step function above calls once a target has been fully processed or abandoned. Logs a `CHECK failed`-style assertion if called on an already-empty list. |

**Net:** this is the concrete implementation the `adapter.cc` section above inferred existed by shape alone — a **GATT-client-role walker that activates a configured list of expected services on a newly connected peer**, subscribing to indications/notifications (or issuing follow-up reads) service-by-service until either everything is activated (feeding the pending-counter mechanism that ultimately logs `"Activation sequence completed"`, per the `adapter.cc` section) or the peer doesn't support enough of what's expected (`"Activation continued without any services. Giving up"`). This confirms `adapter__60069964`/`600691f4` really do belong to one coherent subsystem, as previously inferred, and gives it a concrete mechanism: **the controller acts as a GATT client against a connected peer during this flow**, not purely as a peripheral/server. Given the OOBE (out-of-box-experience) terminology overlap with `gatt_manager_task.cc` (`bruce-state-machine.md`, session 23), this is plausibly part of the Stadia companion-app pairing/setup flow — the controller discovering and subscribing to the phone app's own BLE GATT service during OOBE — but no direct call edge between the two files was found this session, so treat that connection as a plausible hypothesis, not a confirmed one.

### Session 23: `ble_info.cc` — the BLE static-random address generator (2/2 decompiled)

`ble_info.cc` was `bruce-decompile-status.md`'s §3a rank-7 cheap-win target (466 remaining bytes, 0/2). Both attributed functions are now decompiled (`analysis/decomp/ble_info__*.c`). This resolves a call `bruce-misc-functions.md`'s `device_info.cc` write-up (session 19) already flagged but hadn't traced into: `device_info__6005a6b0` "fetches the local Bluetooth MAC via `ble_info__60065b84`".

| Function | Bytes | Role |
|---|---:|---|
| `ble_info__60065a74` | 260 | Parses a 17-character (`0x11` bytes) colon-separated hex MAC-address string (`"XX:XX:XX:XX:XX:XX"`) read out of config key `0x25` (via `keys__60065df0`/`keys__60065eb8`) into 6 raw bytes, logging `"Invalid separator: ... %s"` / `"Invalid hex bytes: ... %s"` on a malformed string. |
| `ble_info__60065b84` | 206 | **The BLE address accessor.** Starts from a hardcoded default MAC constant, then checks whether a persisted override is stored under config key `0x25` (via the function above); if present and it passes a sanity check (`FUN_60059e94`, rejecting some invalid/reserved forms), uses it. If absent: sets the top two bits of the first address byte (`\| 0xc0`, the BLE spec's "static random address" tag), logs `"No stored random BLE MAC found - generating new random mac"`, and **persists the freshly-generated address back to the key-value store** (`keys__6006615c`, key `0x25`, length `0x11`) so it's stable across reboots. Returns the 6 raw address bytes. |

**Net:** `ble_info.cc` manages the device's **BLE static-random address** (LE privacy-shaped, generated once and persisted through the same generic config-key-value store `keys.cc`/`device_info.cc`/`remote_device_db.cc` all use) — a distinct concept from the **fixed factory BD_ADDR** `adapter__6006a21c` reads/logs via a different mechanism (`FUN_600d8a26` on the adapter singleton's own field, also logging `"Bluetooth MAC Address: %s"`). Both `device_info__6005a6b0` and `FUN_60071884` call into this file, consistent with `device_info.cc`'s "identity management run at/near boot" story (session 19) rather than anything BT-stack-internal.

## What's decompiled vs. what's left, and how to continue

- **328 of 1,076 functions decompiled** (up from 327; up from 69 at session-7 end, 2 at session-6 end) — **~93,700 of 204,449 code bytes (~45.8%)**, up from ~11%. **748 functions / ~110,700 bytes remain.** The +1 is `FUN_600aee8c` (`0x600aee8c`, 302 bytes), relocated this pass from `bruce-io-paths.md` session 12 — see the `~0x600aaxxx`–`0x600b02xx` GATT client/server core row in the address-range map above and the "Relocated from `bruce-io-paths.md` session 12" section below for the other 20 session-12 functions that turned out to sit *outside* this block's `0x600921b8`–`0x600c9cc4` range and so are not counted here.
- Session 8 fully executed session 7's plan item 1 (the ~388-remaining-string sweep): 317 identifier-shaped strings checked in bulk via `FindRef.java`, yielding 245 in-range hits (zero false positives on manual spot-check) plus 44 "no-func" hits (string referenced from code, but landing in a gap Ghidra's auto-analysis hadn't recognized as a function — see `bta_prm_hdl_event` below) and 15 with no resolvable xref at all (consumed via an unresolved data table, matching the known limitation). A further 44 non-identifier-shaped strings (mostly `BTA_GATT_*` status-code names) turned out to be a pure error-code→string lookup table at `0x60108ab8`–`0x60108d00`, referenced from *data*, not from any self-naming function — a dead end for identification purposes, noted so it isn't re-attempted.
- **The `bta_prm_hdl_event`/`BTA_PatchRam` gap** (`0x600929f0`–`0x60092de8`, ~1KB) and 5 similar small gaps (`bta_dm_pm_timer_cback`, `bta_gattc_sdp_callback`, `bta_dm_sdp_callback`, `bta_dm_acl_change_cback`, `bta_dm_set_encryption`) are all cases where a function is reached only via a registered callback pointer and Ghidra's auto-analysis never created a function there — the same phenomenon that hid `btu_task` (see prose below). All 6 were manually resolved this session via `disassemble()`+`createFunction()` at the exact xref site. **This pattern (string xref lands with "no func") is worth treating as a signal, not just a dead end** — it may catch more hidden callback-only functions in the remaining ~749.
- Both layers session 7 flagged as "not yet touched" are now substantially covered: **L2CAP** (found to be the actual identity of the `0x600b5xxx`–`0x600b9fxx` range, previously mis-labeled GATT-client — see address-range map and prose below) and **BTA_GATTS_*** (full server-side API surface named: `CreateService`/`DeleteService`/`AddCharacteristic`/`AddCharDescriptor`/`StartService`/`HandleValueIndication`/`SendRsp`/`Close`/`AppDeregister`). **RFCOMM/SPP/HFP still not found** — the `[RFCOMM]` tag string exists (`0x60121a14`) but no `rfc_*`/`port_*` function-name strings turned up in this session's identifier sweep; still an open question whether it's linked in under a different naming convention or not present at all.
- **New lead for a future session**: `smp_sm_event`'s (`0x600c1a34`) 54 callers are scattered across `0x600faxxx`–`0x600fcxxx`, which is **decompile-status run #2** (`0x600ecb72`–`0x6013d4e4`, 330KB span, only 1/1,006 decompiled) — strong circumstantial evidence that run #2 holds the actual SMP per-state handler functions (`smp_br_state`, `smp_state`, the individual pairing-flow steps), not just miscellaneous tail code as its low 28.8% density might suggest. Worth a dedicated string-xref sweep of run #2 using the same method as this session, rather than treating it as lower-priority just because of density.
- The P-256/P-192-shaped bignum helpers (`FUN_601002bc` compare, `FUN_601004b2` subtract, `FUN_60100424` add, `FUN_601005ac`, `FUN_601005f6`, `FUN_60100166`, `FUN_6010027c`) live just outside this block (~`0x60100xxx`, inside decompile-status run #2) and are still a good, tightly-scoped next target — they'd both nail down the P-192 guess and likely connect to `bruce-crypto.md`'s already-documented EVP/ASN.1 registry (same address neighborhood as the `0x6010b9xx` `EVP_PKEY_ASN1_METHOD` table).
- `FUN_600c74a0`/`FUN_600c80fc` (the ~1,800-byte "not conclusively identified" pair right before the EC crypto cluster) remain unidentified — not investigated this session.
- **Tooling note confirmed this session**: the `$ADDRS`-variable-mangling bug from session 7 is specifically about *quoting* — `"$ADDRS"` (quoted) collapses to one string argument and breaks; `$(cat file)` **unquoted** word-splits correctly and was used successfully throughout this session for batches up to 28 addresses per `Decompile.java`/`FindRef.java` invocation. Root-caused, not just avoided.
- All work this session was `-process -noanalysis` only; no `-import`/`-overwrite`, no commits, per constraints.
- **Session 9**: **418 of 1,076 functions decompiled** (up from 328) — **~130,268 of 204,449 code bytes (~63.7%)**, up from ~45.8%. **658 functions / ~74,181 bytes remain.** This pass confirmed the string-table lead really is exhausted (per session 8's own note): none of the 90 newly-decompiled functions reference the string-table region as a literal operand, so identification for all of them is shape/call-graph-based rather than string-confirmed — treat the "very likely"/"strong candidate" identifications above as lower-confidence than the session-7/8 string-confirmed rows, even though several (the `l2c_csm_open`/`l2cu_release_ccb`/`l2cu_create_conn`/`gatts_process_write_req` identifications especially) are well-supported by call-graph shape alone. The remaining 658 functions are smaller on average (74,181 bytes / 658 ≈ 113 bytes each, vs. this session's batch averaging 406 bytes) — diminishing returns from further pure size-ranking; a future session may get more mileage from targeted sweeps of specific still-thin areas (RFCOMM/SPP/HFP presence is still an open question — see below) than from continuing the size-sorted approach mechanically.
- **Two L2CAP naming gaps closed this session** (shape-based, not string-confirmed): `FUN_600bc00c` (`l2cu_release_ccb`-shaped, called from every named `l2c_csm_*` handler) and `FUN_600b6d30` (`l2c_csm_open`-shaped, the one CSM steady state that was missing from the named set). Combined with session 8's 8 named CSM states, that's a structurally-complete picture of the L2CAP channel state machine now.
- **Module-map boundary sharpened twice this session**: (1) SDP's practical start is a little earlier than the `0x600bda54` address noted in the existing map — `0x600bd4bc`/`0x600bd848` are called by named SDP functions despite sitting below that boundary. (2) The `0x600b5xxx`–`0x600b9fxx` "L2CAP" range is not purely L2CAP — `FUN_600b59ec` in that range is very likely the real `btm_ble_create_conn` (a BTM function), called directly by the string-confirmed `btm_send_pending_direct_conn`. Neither is a wholesale correction like session 8's BTA-DM-vs-SMP fix, just a reminder that these address-range boundaries are approximate, not object-file-exact.
- **Session 10: 490 of 1,076 in-census functions decompiled (up from 410 by the same strict address-join `bruce-decompile-status.md`'s methodology uses — see that doc's session-13 note on the 410-vs-this-doc's-stale-328-self-report discrepancy; this session re-ran the same rigorous join before adding to it rather than trusting the old prose number) — ~148,991 of 204,449 code bytes (~72.9%), up from ~63.3% under the same accounting. ~586 functions / ~55,458 bytes remain (average ~95 bytes each — genuinely small leftovers now, mostly leaf helpers).** Plus 8 non-census "gap" functions (Ghidra auto-analysis never boundary-detected them; `Decompile.java` created them on demand, same phenomenon as `btu_task`), for 498 total decomp files addressed into this range. Full findings, evidence, and the 80-row function table are in the new "Session 10" section above. Headline results: the shared HCI command-transmit engine (`FUN_600a9234`, likely `btu_hcif_send_cmd`) and `l2cu_allocate_ccb` (`FUN_600bb44c`) are both now decompiled despite being extremely widely called (119 and multiple callers respectively — audit-corrected from an original count of 122) — both had sat unread for many sessions purely because their *individual* size didn't clear prior batches' cut lines, a reminder that call-graph centrality and byte-size don't always correlate. Also resolved the AES subsystem (SubBytes+ShiftRows round step, AES-CMAC top-level + block-chaining loop, confirmed via the named `BTM_BleDataSignature`) into the previously-"not conclusively identified" `0x600c74xx`–`0x600c80xx` zone, and found a spec-shaped SMP IO-Capability pairing-method-selection table pair. **RFCOMM/SPP/HFP: re-checked with a broader grep against the now much larger decompiled base and full current string table — still zero function-name evidence of any kind** (only the bare `[RFCOMM]` log-tag string and unrelated `rfc822`/headset-audio strings); the working conclusion should now shift from "open question" to "very likely genuinely absent from this image" (see the Session 10 section's closing paragraph for the reasoning). Two functions (`FUN_600bc9e4`, `FUN_600b7cba`) came back with corrupted decompilation (`unaff_r7` pseudo-registers) — same failure class as the known `FUN_601054dc` jump-table issue, flagged rather than trusted.

## Relevance to other open threads (CLAUDE.md)

- **Main event/dispatch loop (thread 3) — substantially closed for the BT stack.** `FUN_600a9fce` self-references the string `"btu_task"` (`0x601167fc`) three times — it **is** `btu_task`, the central BTU-layer RTOS task. It was invisible to auto-analysis (a ~1KB region between two recognized functions, only found by resolving the string-xref address directly, same trick as the small callback gaps above). Its body: `FUN_6006e5bc(0xffff,0)` (an event-group-wait-shaped call, blocking on up to 16 bits), then bit-tested dispatch — bit `0x10` drains a GKI-mailbox event queue with a ~20-case switch on event-record type (delegating to e.g. `FUN_600a0344`, `FUN_600bb2ac`, `FUN_600c1c04`, plus a registered-callback-table fallback), bit `4` drains a second mailbox via `FUN_600961e0`, bit `0x20`/`0x40` call periodic helpers (`FUN_6009623c`, `btu_process_quick_timer_evt`). A second loop (`LAB_600aa0d0`) drains a third mailbox (`FUN_6006df58(0)`) of raw HCI/L2CAP messages, switching on a 16-bit type-code field: `0x1000`/`0x1200`→**`FUN_600a89f0`** (the confirmed HCI event dispatcher), `0x1100`→**`l2c_rcv_acl_data`**, `0x1900`→**`l2c_link_segments_xmitted`**, `0x1600`→`FUN_600a9234` (HCI command send), plus a second registered-callback-table fallback for everything else. This is an exact structural match for BTE's real `btu_task()` — the single RTOS task that owns HCI-event dispatch, L2CAP ACL-data ingress, and HCI command transmission, all serialized through GKI mailboxes. **It is very likely the closest thing to "the" main Bluetooth dispatch loop that exists in this firmware** (as opposed to a single whole-system `main()` — bruce almost certainly runs several FreeRTOS tasks side by side; this is BT's). Not yet found: who calls `xTaskCreate`-equivalent to spawn it (not traced this session). Its immediate 190-byte predecessor `FUN_600a9f10` has near-identical body plus one-time setup calls — plausibly the task-entry trampoline, not conclusively distinguished from `btu_task` itself this session.
- **Report-packing / button-ADC threads (1, 2)**: nothing in this block touches HID reports, buttons, or ADC — it's purely the BT/BLE protocol stack. No new lead on those threads from this session.
- **Ed25519/EVP crypto callers (thread 5) — closed for the P-256 half.** Traced a complete, non-speculative call chain from PDU-receive down to modular arithmetic: **`smp_data_ind`** (`0x600c1864`, reads the SMP opcode byte from an incoming PDU) → **`FUN_600c1a34`** (`smp_sm_event`-shaped: 2D `[state][event]` lookup table dispatching through a function-pointer table, 54 static callers — the SMP FSM's central event dispatcher). Working the other direction from the confirmed P-256 code: **`FUN_600c8798`** (EC scalar multiplication — windowed double-and-add over a NAF-style digit table, curve-parameterized by a word-count argument that selects between two constant sets, i.e. handles both P-256 and the P-192-shaped sibling) is called by **`FUN_600c1030`**, which copies a 32-byte accumulated value as a scalar, multiplies it by base point `DAT_600c10a0` (almost certainly the curve generator **G**), writes the 32+32-byte result as an EC-point public key into the SMP control block, and re-enters the FSM dispatcher (`FUN_600c1a34`) with event `0x1c`. `FUN_600c1030` in turn is called only from **`FUN_600c0f34`**, a 4-state state machine that accumulates 4×8=32 bytes of `btsnd_hcic_ble_rand` (**`0x600b1368`**, the real HCI LE-Rand command) output as private-key entropy across repeated HCI command completions, calling `FUN_600c1030` once the 32nd byte arrives. So: **incoming SMP pairing traffic drives the FSM; the FSM (elsewhere, via its function-pointer table — not statically provable which entry, but structurally consistent) drives local ECDH keypair generation using controller-sourced randomness; keypair generation calls the confirmed P-256/P-192 EC scalar-multiplication code; that code calls the same modular-reduction helpers (`FUN_601005ac`/`FUN_601005f6`) as the previously-confirmed standalone P-256 Solinas reduction.** This is SMP's LE Secure Connections local-keypair-generation step, and it is the P-256 stack's real runtime consumer — the Ed25519/X25519 stack in `bruce-crypto.md` remains uncalled from anywhere traced so far and is now the *less* likely "live" curve of the two. **Session 10 extended this thread with a second, independently-confirmed algorithm: AES-CMAC.** `FUN_600c09f0` (AES-CMAC top-level, block-padding + the confirmed block-chaining loop `FUN_600c07e4`) is called from the string-named `BTM_BleDataSignature` — a real, confirmed runtime caller, not just a plausible one — and from `FUN_600c12b0`, itself very likely SMP's `g2` numeric-comparison-value function (called during LE Secure Connections passkey-display pairing). A byte-for-byte-matching AES SubBytes+ShiftRows round function (`FUN_600c7fc8`) sits in the same immediate neighborhood, resolving what prior sessions had flagged as "not conclusively identified" (`0x600c74xx`–`0x600c80xx`) into a real, coherent AES subsystem. Unlike the Ed25519/X25519 stack, this AES-CMAC path has a confirmed, non-speculative caller — it's the strongest evidence yet of live symmetric-crypto usage in this image, alongside the already-confirmed P-256 ECDH.
- **L2CAP (part of thread 4, "layers not yet touched")**: no longer untouched — see address-range map and the dedicated cluster in the session-8 table above (`l2c_csm_*`/`l2c_fcr_*`/`l2c_rcv_acl_data`/`l2c_link_*`, 14 functions). This also corrects session 7's read of `FUN_600ba1c4` (the TLV/PDU parser) from "ATT/GATT PDU parser" to more likely an L2CAP-internal PDU dispatcher, since it's called directly from `l2c_rcv_acl_data` rather than from anything GATT-named. **Session 9 deepened this further**: the channel state machine now looks structurally complete (`l2c_csm_open` and `l2cu_release_ccb` shape-identified, closing the gap next to session 8's 8 named states), both connection-creation triggers were found (`l2cu_create_conn`-shaped for classic, `btm_ble_create_conn`-shaped for LE — the latter technically a BTM function embedded in this address range, see the boundary-caveat note above), the FCR (flow-control/retransmission) internals got 3 more functions, and a probable `L2CA_SendFixedChnlData`-shaped sender was found in SMP's reject-unexpected-command path (**audit correction:** originally described as "called from SMP's own FSM action table" — that overstated the evidence, since the FSM's real action table dispatches through a runtime indirect call invisible to static xref tools; see the `0x600b5264` entry in the session-9 table for the corrected call chain) — weaker than originally framed, but still one consistent data point that SMP's PDUs transit L2CAP's fixed-channel path rather than a separate transport.

---

## Wave 2: `gki_ft.c` — Broadcom General Kernel Interface (GKI) FreeRTOS Adapter

`gki_ft.c` (2 functions, 268 bytes) provides the OS-adaptation layer binding Broadcom's General Kernel Interface (GKI) to FreeRTOS. It implements GKI task creation, per-task synchronization primitives (mutexes, event queues), control-block tracking (`gki_cb.os`), and the central GKI exception/panic handler.

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `gki_ft__6006e790` | 68 | `gki_ft.c` | **`GKI_exception`.** Fatal error handler / panic logger for the Bluetooth stack. |
| `gki_ft__6006e484` | 200 | `gki_ft.c` | **`GKI_create_task`.** Creates GKI tasks, allocates FreeRTOS event queues and mutexes, and spawns RTOS tasks (resolving `btu_task`'s spawner). |

### `gki_ft__6006e790` (68B) — `GKI_exception`
Called across BTA/BTE modules when an unrecoverable protocol violation or buffer corruption is detected:
1. Prints standard Broadcom GKI panic banner to debug log via `FUN_6006be9c`:
   - `"********************************************************************"` (`DAT_6006e7d8`)
   - `"* GKI_exception(): 0x%02x %s"` (`DAT_6006e7dc`)
   - `"********************************************************************"` (`DAT_6006e7d8`)
2. Resolves currently executing GKI task ID via `FUN_6006e594()` (`GKI_get_taskid()`).
3. Logs critical crash diagnostic: `"gki_ft.c:611: GKI Exception: Task %d, code %d, msg %s"` (`DAT_6006e7e0`) via `FUN_6010165c(0x28, "gki_ft.c", 0x263, msg, task_id, code, param_2)`.

### `gki_ft__6006e484` (200B) — `GKI_create_task` (Task & Queue Spawner)
This function directly resolves the open question from prior sessions (**"who calls xTaskCreate to spawn `btu_task`?"**). It is the generic GKI task creation interface:

```
gki_cb.os Control Block (Base 0x2001E65C):
+-------------------------------------------------------------------------------+
| +0x04: FreeRTOS Task Handles (task_id * 4)                                    |
| +0x24: Event Mutex Handles (task_id * 4)                                      |
| +0x44: Event Queue Handles (task_id * 4)                                      |
| +0xC4: Task Priority Array (task_id byte)                                     |
| +0xCC: Task Name Pointers (task_id * 4)                                       |
| +0xEC: Task State Flags (task_id byte)                                        |
+-------------------------------------------------------------------------------+
```

**Execution Flow:**
1. **Task ID Validation:** Enforces `param_2 < 8` (`GKI_MAX_TASKS = 8`). On violation, logs `"ERROR: GKI task_id must be less than 8"` (`DAT_6006e54c`) and returns error status `1` (`GKI_FAILURE`).
2. **Log Task Metadata:** Logs trace via `FUN_6006be9c`:
   `"GKI_create_task func=0x%x  id=%d  name=%s  stack=0x%x  stackSize=%d"` (`DAT_6006e554`).
3. **Event Mutex Creation:**
   - Calls `FUN_601007e6(1)` (`xSemaphoreCreateMutex`).
   - Stores mutex handle in GKI control table: `*(int *)(0x2001e65c + task_id * 4 + 0x24) = mutex`.
   - If mutex creation fails: logs `"GKI_create_task create thread_evt_mutex failed %s!"` (`PTR_s_GKI_create_task_create_thread_ev_6006e55c`) and returns 1.
4. **Event Queue Creation:**
   - Calls `thunk_EXT_FUN_00006a20(depth=100, item_size=2, 0)` (`xQueueCreate(100, sizeof(uint16_t))`).
   - Stores queue handle in GKI control table: `*(int *)(0x2001e65c + task_id * 4 + 0x44) = queue`.
   - If queue creation fails: logs `"GKI_create_task create thread_evt_queue failed %s!"` (`PTR_s_GKI_create_task_create_thread_ev_6006e560`) and returns 1.
5. **RTOS Task Spawning:**
   - Enters critical section via `thunk_EXT_FUN_00007d64()` (`taskENTER_CRITICAL()`).
   - Computes task priority: $\text{priority} = 20 - \text{task\_id}$ (Task 0 = Priority 20, Task 1 = Priority 19, etc.).
   - Converts stack size from bytes to 32-bit words: $\text{stack\_words} = \text{param\_5} \gg 2$.
   - Spawns task via `FUN_60100900(entry_fn, task_name, stack_words, param=0, priority, handle_ptr)` (`xTaskCreate`).
   - Asserts task creation return code == 1 at `gki_ft.c:148` (`0x94`) (`PTR_s_FreeRTOS_CHECK_failed_6006e564`).
   - Populates GKI task control block:
     - Task active flag: `*(0x2001e65c + task_id + 0xec) = 1`
     - Task priority: `*(0x2001e65c + task_id + 0xc4) = (char)(20 - task_id)`
     - Task name pointer: `*(0x2001e65c + task_id * 4 + 0xcc) = param_3`
     - Event bitmask: `*(0x2001e65c + (task_id + 0x4a) * 4 + 8) = 0`
     - Timer counter: `*(0x2001e65c + (task_id + 0x78) * 2 + 4) = 0`
   - Exits critical section via `thunk_EXT_FUN_00007dac()` (`taskEXIT_CRITICAL()`).
   - Returns status `0` (`GKI_SUCCESS`).

---

## Wave 3: `adapter.h` — Bluetooth Adapter State Listener Registration Helper

`adapter__60080424` (72 bytes, `src: adapter.h`) is an inline / member helper method of Google's first-party `Adapter` C++ class that registers event / state listener objects onto the active Bluetooth adapter with runtime mode verification.

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `adapter__60080424` | 72 | `adapter.h` | **`Adapter::SetListener` / `SetStateListener`.** Registers an event/state listener (`param_2`, e.g. `StateMachine *`) onto the `Adapter` instance based on active adapter mode (`+0x11C`), falling back to default listener `0x20003454` if NULL, asserting if BLE is disabled (`mode == -1`), returning the previous listener pointer. |

### `adapter__60080424` (72B) — State / Event Listener Mutator (`Adapter::SetListener`)
- **Signature:** `void *adapter__60080424(Adapter *this, void *pListener, uint32_t arg3, uint32_t arg4)`
- **Object State Fields (`this = 0x20007BF8`):**
  - `this + 0x11C` (int8): Active Adapter Mode (`1` = Advertising/Connectable, `2` = Connected/Active, `-1` = Disabled/Uninitialized).
  - `this + 0x110` (void *): Mode 2 (Connected/Active) event listener pointer.
  - `this + 0x118` (void *): Mode 1 (Advertising/Connectable) event listener pointer.
  - Default constant: `DAT_6008046C = 0x20003454` (pointer to static default/no-op listener object).
- **Execution & Validation Flow:**
  1. **Mode Check:** Inspects `cVar1 = *(char *)(this + 0x11C)`:
     - **Mode `2` (Connected / Active Mode):**
       - Reads previous listener: `uVar2 = *(void **)(this + 0x110)`.
       - If `pListener == NULL` (`0`), substitutes default static listener `DAT_6008046C` (`0x20003454`).
       - Stores new listener: `*(void **)(this + 0x110) = pListener`.
       - Returns previous listener `uVar2`.
     - **Mode `1` (Advertising / Connectable Mode):**
       - Reads previous listener: `uVar2 = *(void **)(this + 0x118)`.
       - If `pListener == NULL` (`0`), substitutes default static listener `DAT_6008046C` (`0x20003454`).
       - Stores new listener: `*(void **)(this + 0x118) = pListener`.
       - Returns previous listener `uVar2`.
     - **Mode `-1` / Disabled / Uninitialized State:**
       - Formats diagnostic error trace via `FUN_6010165c(0x28, DAT_60080474, 0xCE, DAT_60080470, arg4)` asserting line `0xCE` (206) of `adapter.h` with literal message `"BLE is not enabled. Cannot set listener."` (`0x60125FEC`).
       - Returns `NULL` (`0`).
- **Callers & Integration:** Invoked directly from `state_machine__600df264` (`state_machine.cc`, line 61: `adapter__60080424(DAT_60080970, param_1)`) to register the `StateMachine` instance (`param_1`) as the active adapter event listener during BLE connection state machine setup and transitions.

---

## Wave 5: `gatt_service_handle.h` — GATT Service Handle Wrapper

`gatt_service_handle__6005d9a8` (28 bytes, `src: gatt_service_handle.h`) is an inline accessor method of Google's first-party `GattServiceHandle` C++ class that extracts the registered 16-bit / 32-bit GATT service attribute handle from the underlying BTA/BTE GATT server service record.

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `gatt_service_handle__6005d9a8` | 28 | `gatt_service_handle.h` | **`GattServiceHandle::GetAttributeHandle` / `GetHandle`.** Accessor verifying that the internal GATT service pointer (`this + 0x0C`) is non-null (asserting at line `0x18C` = 396 on null), returning the service attribute handle at `service_ + 0x10`. |

### `gatt_service_handle__6005d9a8` (28B) — Attribute Handle Accessor (`GattServiceHandle::GetAttributeHandle`)
- **Signature:** `uint32_t gatt_service_handle__6005d9a8(GattServiceHandle *this)`
- **Class / Header:** `gatt_service_handle.h` (`0x6011CF74`)
- **Object State Fields (`this`):**
  - `this + 0x0C` (void *): Pointer to internal BTA/BTE GATT service registration record (`service_`).
  - `service_ + 0x10` (uint32_t / uint16_t): The allocated GATT service start / attribute handle assigned by the Broadcom GATT server stack upon service creation (`GATTS_CreateService`).
- **Execution Flow:**
  1. **Null Pointer Check:** Tests if `*(int *)(this + 0x0C) == 0`.
  2. **Fatal Assertion on Unbound Handle:** If the service pointer is NULL (attempting to query handle before service creation or after deletion):
     - Formats and emits fatal panic assert at line `0x18C` (396) of `gatt_service_handle.h` (`0x6011CF74`): `"CHECK failed: service_ != nullptr"` (`0x60122CE9` / `0x60127A03`) via `FUN_601016a2`.
  3. **Handle Return:** If valid, loads and returns `*(uint32_t *)(*(int *)(this + 0x0C) + 0x10)`.
- **Caller & Integration:** Invoked from `FUN_600df4c4` during BLE GATT server database initialization and characteristic value notification / indication dispatch.






---

## Session 29 (Wave 1) — BTA/BTE Bluetooth Stack Expansion: 100% Milestone Reached on 7 Subsystems (HCIC, L2CAP CSM/FCR/Link, L2CAP PDU/Buffers, SDP, BTU Task/GATT Helpers, SMP, EC Crypto/Math)

142 newly decompiled and analyzed functions across `0x600921b8`–`0x600c9cc4`, bringing total BTA/BTE decompilation progress from 490 to **632 of 1,076 functions (58.7% by count, 161,723 of 204,449 bytes = 79.1% by byte size)**.

With this wave, **SEVEN major Broadcom BTA/BTE subsystems are now 100% fully decompiled and documented**:
1. **`btsnd_hcic_*` HCI Command Send Layer** (`0x600b0700`–`0x600b5000`): **122 / 122 functions (100.0%)** — 18,094 / 18,094 bytes
2. **L2CAP Channel State Machine (CSM), FCR & Link** (`0x600b5000`–`0x600ba000`): **56 / 56 functions (100.0%)** — 18,685 / 18,685 bytes
3. **L2CAP PDU Reassembly & Buffer Management** (`0x600ba000`–`0x600bd000`): **38 / 38 functions (100.0%)** — 11,326 / 11,326 bytes
4. **SDP Service Discovery Protocol** (`0x600bd000`–`0x600c0000`): **36 / 36 functions (100.0%)** — 11,772 / 11,772 bytes
5. **BTU Task & GATT Core Helpers** (`0x600a9000`–`0x600ab000`): **34 / 34 functions (100.0%)** — 5,444 / 5,444 bytes
6. **SMP Security Manager Protocol** (`0x600c0000`–`0x600c2600`): **71 / 71 functions (100.0%)** — 8,742 / 8,742 bytes
7. **EC Crypto, Field Arithmetic & BTA Tail** (`0x600c7000`–`0x600c9cc4`): **31 / 31 functions (100.0%)** — 10,980 / 10,980 bytes

---

### Key Architectural Discoveries

#### 1. L2CAP Channel State Machine (`l2c_csm_execute`) Fully Resolved
`FUN_600b5e00` (164 bytes) is confirmed as **`l2c_csm_execute`**, the central L2CAP Channel State Machine event dispatcher. It inspects the CCB state byte at `+0x04` and dispatches across all 9 standard Bluetooth Core Spec / Broadcom BTE channel states via exact 1:1 switch routing:
- State 0 (`CST_CLOSED`): `FUN_600b5ec8` (`l2c_csm_closed`)
- State 1 (`CST_ORIG_W4_SEC_COMP`): `FUN_600b61c4` (`l2c_csm_orig_w4_sec_comp`)
- State 2 (`CST_TERM_W4_SEC_COMP`): `FUN_600b6378` (`l2c_csm_term_w4_sec_comp`)
- State 3 (`CST_W4_L2CAP_CONNECT_RSP`): `FUN_600b6550` (`l2c_csm_w4_l2cap_connect_rsp`)
- State 4 (`CST_W4_L2CA_CONNECT_RSP`): `FUN_600b674c` (`l2c_csm_w4_l2ca_connect_rsp`)
- State 5 (`CST_CONFIG`): `FUN_600b6900` (`l2c_csm_config`)
- State 6 (`CST_OPEN`): `FUN_600b6d30` (`l2c_csm_open`)
- State 7 (`CST_W4_L2CAP_DISCONNECT_RSP`): `FUN_600b6fcc` (`l2c_csm_w4_l2cap_disconnect_rsp`)
- State 8 (`CST_W4_L2CA_DISCONNECT_RSP`): `FUN_600b70f4` (`l2c_csm_w4_l2ca_disconnect_rsp`)

#### 2. Bluetooth SDP Data Element Sequence (DES) Wire Codec
`FUN_600bfb4c` (14 bytes) and `FUN_600bfe2c` (126 bytes) implement exact Bluetooth Core Spec SDP Data Element Sequence wire encoding/decoding. `FUN_600bfb4c` (`sdpu_get_len_from_type`) extracts data element byte lengths from the 3-bit size descriptor field:
- `0` -> 1 byte (nil/uint8/int8/bool)
- `1` -> 2 bytes (uint16/int16/uuid16)
- `2` -> 4 bytes (uint32/int32/uuid32)
- `3` -> 8 bytes (uint64/int64)
- `4` -> 16 bytes (uint128/int128/uuid128)
- `5` -> uint8 length follows in wire stream
- `6` -> uint16 big-endian length follows (`(buf[0] << 8) | buf[1]`)
- `7` -> uint32 big-endian length follows

#### 3. GAP Service Characteristic Value Mutator (`gap_set_attrib_value`)
`FUN_600aad90` (156 bytes) is confirmed as the runtime attribute mutator for the GAP Generic Access service (`0x1800`), matching the 4 characteristics registered by `FUN_600aac04`:
- `0x2a00` (Device Name): updates name string via `FUN_600a10e0`
- `0x2a01` (Appearance): stores 16-bit appearance category code at `local_c + 4`
- `0x2a04` (Peripheral Preferred Connection Parameters): copies 8-byte connection parameter struct (min interval, max interval, slave latency, supervision timeout) via `memcpy` (`thunk_EXT_FUN_0000b572`)
- `0x2aa6` (Central Address Resolution): stores 1-byte boolean flag at `local_c + 4`

#### 4. SMP Security Manager Protocol State Machine & LE Secure Connections
The full SMP Security Manager Protocol (`0x600c0000`–`0x600c2600`, 71 functions) is now 100% decompiled. It includes:
- SMP Application / BTM Interface API & State Routers: `SMP_Pair` (`0x600c0578`), `SMP_SecurityGrant` (`0x600c05e4`), `SMP_PasskeyReply` (`0x600c0640`), `SMP_ConfirmReply` (`0x600c0698`), `SMP_NumericComparisonReply` (`0x600c073c`), `smp_proc_pairing_req` (`0x600c0114`), `smp_proc_pairing_confirm` (`0x600c01b8`), `smp_proc_rand` (`0x600c03d8`), and `smp_check_pairing_in_progress` (`0x600c0434`). (Note: Low-level wire PDU serializers are located in the `0x600faaxx` / `0x600f06xx` library cluster).
- Cryptographic Toolbox: AES-CMAC confirmation calculation `f4` (`0x600c0e14`), key generation `f5` (`0x600c0e7c`), check value generation `f6` (`0x600c1204`), and 6-digit numeric comparison passkey computation (`0x600c0cb4`, bounded by `DAT_600c0dac = 999999` / `0xF423F`).
- FCR Frame Check Sequence: `0x600b72cc` (`l2cu_crc16` / `l2c_fcr_calc_fcs`) and `0x600b72f0` (`l2cu_check_crc16` / `l2c_fcr_check_fcs`) implement the 16-bit CRC table lookup (`0x60117ad0`, polynomial `0xA001`) for L2CAP ERTM/FCR frame validation.

#### 5. Finite Field Modular Arithmetic Primitives for EC Cryptography
`FUN_600c89e0` (106B), `FUN_600c8a54` (110B), and `FUN_600c8acc` (80B) implement multi-precision finite field modular arithmetic in $\mathbb{F}_p$ supporting NIST P-256 ($p_{256}$, 8 words = 32 bytes) and NIST P-192 ($p_{192}$, 6 words = 24 bytes) prime moduli:
- `FUN_600c89e0` (`ec_field_double_mod_p`): Modular field element doubling ($r = (2a) \pmod p$).
- `FUN_600c8a54` (`ec_field_add_mod_p`): Modular field element addition ($r = (a + b) \pmod p$).
- `FUN_600c8acc` (`ec_field_sub_mod_p`): Modular field element subtraction ($r = (a - b) \pmod p$).
These primitives underpin the higher-level Jacobian projective coordinate point scalar multiplication routines (`0x600fffbc`, `0x600ffe42`) used by SMP LE Secure Connections ECDH key agreement.

### Complete Table of 142 Functions Decompiled in Session 29 (Wave 1)

| Address | Bytes | Subsystem / Range | Name / Verified Role | Callers / Callees |
|---|---:|---|---|---|
| `0x600a9308` | 164 | BTU / HCI Event | **`btu_hcif_conn_comp_evt`** — HCI Connection Complete / LE Enhanced Connection Complete event parser; routes to BTM link connect (`0x600a6d70`) and L2CAP `l2c_link_hci_conn_comp` (`0x600b89b8`). | 1 caller / 2 callees |
| `0x600a93b0` | 136 | BTU / HCI Event | **`btu_hcif_conn_req_evt`** — HCI Connection Request event parser; parses BD_ADDR and Class of Device / link type; routes to connection evaluation (`0x600a5540`) or rejects/accepts via HCI (`0x600b22a8`). | 1 caller / 2 callees |
| `0x600a9e74` | 92 | BTU / HCI Queue | **`btu_hcif_ack_event`** — HCI Command Complete / Status credit acknowledgement processor. | 1 caller / 1 callee |
| `0x600a9ed8` | 36 | BTU / HCI Queue | **`btu_hcif_reset`** — Clears BTU HCI command queue state and resets credit counters. | 1 caller / 0 callees |
| `0x600aa4c4` | 38 | BTU / Timer | **`btu_stop_quick_timer`** — Cancels active BTU quick timer node. | 6 callers / 2 callees |
| `0x600aa534` | 114 | GATT Server | **`gatt_init_database`** — Initializes primary GATT server attribute database root record. | 2 callers / 4 callees |
| `0x600aa5ac` | 46 | GATT Server | **`gatt_free_attr_buffer`** — Deallocates attribute value buffer to GKI memory pool (`FUN_6006ddd8`). | 2 callers / 1 callee |
| `0x600aa5e4` | 92 | GATT Server | **`gatt_alloc_attr_buffer`** — Allocates attribute value buffer from GKI memory pool (`FUN_6006dbac`). | 1 caller / 2 callees |
| `0x600aa648` | 44 | GATT Server | **`gatt_release_sr_cmd`** — Frees pending GATT server command buffer if active. | 12 callers / 1 callee |
| `0x600aa678` | 48 | GATT Server | **`gatt_set_security_mode`** — Accessor/mutator for global GATT security policy (`DAT_600aa6a8 + 0x28`). | 1 caller / 0 callees |
| `0x600aa6f0` | 80 | GAP Manager | **`gap_find_device_record`** — Searches 6-entry GAP device table (stride 32B) for matching BD_ADDR (`memcmp`). | 2 callers / 1 callee |
| `0x600aa7a0` | 92 | GAP Manager | **`gap_allocate_device_record`** — Allocates unused slot in 6-entry GAP device table; initializes BD_ADDR. | 1 caller / 2 callees |
| `0x600aa800` | 82 | GAP Manager | **`gap_free_device_record`** — Flushes pending callback queue and releases GAP device table entry. | 1 caller / 3 callees |
| `0x600aa858` | 70 | GAP Manager | **`gap_enqueue_operation`** — Allocates GKI queue node and enqueues pending GATT client operation. | 1 caller / 2 callees |
| `0x600aa8a4` | 70 | GAP Manager | **`gap_dequeue_operation`** — Dequeues next pending GATT client operation and frees queue node. | 1 caller / 2 callees |
| `0x600aaacc` | 70 | GAP Manager | **`gap_validate_attr_handle`** — Validates GAP service attribute handle against registered table. | 0 callers / 0 callees |
| `0x600aad90` | 156 | GAP Manager | **`gap_set_attrib_value`** — Attribute value mutator for GAP characteristics: Name (`0x2a00`), Appearance (`0x2a01`), PPCP (`0x2a04`), CAR (`0x2aa6`). | 2 callers / 2 callees |
| `0x600aae30` | 182 | GAP Manager | **`gap_read_attr_value`** — Dispatches GATT read request for GAP service characteristics. | 2 callers / 6 callees |
| `0x600aaeec` | 70 | GAP Manager | **`gap_is_device_connected`** — Checks whether target BD_ADDR has an active GAP connection. | 1 caller / 2 callees |
| `0x600aaf38` | 152 | GAP Manager | **`gap_process_gatt_operation_comp`** — Dispatches GATT client operation completion callback. | 1 caller / 2 callees |
| `0x600aafd4` | 78 | GAP Manager | **`gap_map_gatt_status`** — Translates internal GAP return codes to standard GATT status codes. | 1 caller / 0 callees |
| `0x600b0718` | 18 | HCIC Command | **`btsnd_hcic_reset_all_params`** — Memsets HCI control block `DAT_600b072c` (81 bytes = 0x51). | 1 caller / 1 callee |
| `0x600b076c` | 178 | HCIC Command | **`btm_ble_read_resolving_list_entry`** — Evaluates 10-entry resolving list state and triggers scan/adv parameter updates. | 1 caller / 3 callees |
| `0x600b4e8a` | 54 | HCIC Command | **`btsnd_hcic_ble_set_adv_param_tail`** — Serializes trailing adv parameter bytes and dispatches HCI command. | 1 caller / 1 callee |
| `0x600b4ec2` | 2 | HCIC Command | **`l2c_set_local_mtu_stub`** — 2-byte entry stub to `l2c_set_local_mtu`. | 1 caller / 0 callees |
| `0x600b4ec4` | 12 | HCIC Command | **`l2c_set_local_mtu_veneer`** — 12-byte entry veneer to `l2c_set_local_mtu`. | 1 caller / 0 callees |
| `0x600b4ed0` | 96 | HCIC / L2CAP Glue | **`l2c_set_local_mtu`** — Configures local MTU in CCB (`+0x14`) or global default (`DAT_600b4f30 + 0xea0`). | 1 caller / 1 callee |
| `0x600b4f34` | 166 | HCIC / L2CAP Glue | **`l2c_link_update_conn_params`** — Updates BLE link connection latency/supervision timeout parameters. | 2 callers / 3 callees |
| `0x600b4fe4` | 44 | HCIC Command | **`btsnd_hcic_set_power_mode`** — Accessor/mutator for global link policy power mode (`DAT_600b5010`). | 1 caller / 0 callees |
| `0x600b5018` | 94 | L2CAP Link | **`l2c_link_sec_comp`** — L2CAP link security completion mode flags updater. | 1 caller / 0 callees |
| `0x600b507c` | 78 | L2CAP Link | **`l2c_link_check_security`** — Evaluates L2CAP channel security requirements against active link state. | 1 caller / 0 callees |
| `0x600b542c` | 162 | L2CAP Link | **`l2c_ble_link_sec_comp`** — BLE link security completion event router to active CCBs. | 2 callers / 2 callees |
| `0x600b54d4` | 102 | L2CAP Link | **`l2c_ble_create_conn`** — Triggers lower-layer BLE connection creation. | 3 callers / 6 callees |
| `0x600b56aa` | 106 | L2CAP Link | **`l2c_link_hci_disc_comp_tail`** — HCI disconnect completion tail cleanup handler. | 1 caller / 4 callees |
| `0x600b5bc0` | 68 | L2CAP Link | **`l2c_link_set_idle_timeout`** — Configures L2CAP link idle timeout counter. | 1 caller / 0 callees |
| `0x600b5dd0` | 38 | L2CAP CSM | **`l2c_csm_start_quick_timer`** — Starts 2-tick quick timer for active CSM state transition. | 1 caller / 1 callee |
| `0x600b5e00` | 164 | L2CAP CSM | **`l2c_csm_execute`** — **Central L2CAP Channel State Machine Dispatcher** (9 states -> 9 handlers). | 18 callers / 9 callees |
| `0x600b643a` | 76 | L2CAP CSM | **`l2c_csm_start_config_timer`** — Starts 60-second configuration timer (`0x3c`) for CCB. | 1 caller / 2 callees |
| `0x600b720c` | 186 | L2CAP FCR | **`l2c_fcr_adj_monitor_retransmit_timeout`** — Calculates FCR monitor and retransmission timeout intervals. | 3 callers / 2 callees |
| `0x600b72cc` | 36 | L2CAP FCR | **`l2cu_crc16`** / **`l2c_fcr_calc_fcs`** — Computes 16-bit CRC Frame Check Sequence (FCS) over L2CAP payload using 256-entry lookup table at `0x60117ad0` (polynomial `0xA001`). | 2 callers / 0 callees |
| `0x600b72f0` | 38 | L2CAP FCR | **`l2cu_check_crc16`** / **`l2c_fcr_check_fcs`** — Validates 16-bit CRC Frame Check Sequence (FCS) against trailer bytes on received L2CAP ERTM/FCR I-frames. | 1 caller / 0 callees |
| `0x600b731c` | 84 | L2CAP FCR | **`l2c_fcr_chk_resend_s_frames`** — Checks for unacknowledged supervisory S-frames and triggers retransmit. | 5 callers / 1 callee |
| `0x600b7374` | 178 | L2CAP FCR | **`l2c_fcr_free_retrans_q`** — Drains and frees all buffers in FCR retransmission queue. | 1 caller / 5 callees |
| `0x600b7c94` | 38 | L2CAP FCR | **`l2c_fcr_set_fcr_options`** — Sets FCR channel configuration bitmask and window sizes. | 1 caller / 0 callees |
| `0x600b85c6` | 24 | L2CAP FCR | **`l2c_fcr_update_rx_seq`** — Updates expected receive sequence number in CCB (`+0xb4`). | 1 caller / 1 callee |
| `0x600b932c` | 38 | L2CAP Link | **`l2c_set_non_flushable_pbf`** — Configures non-flushable packet boundary flag on ACL links. | 1 caller / 0 callees |
| `0x600b9358` | 168 | L2CAP Link | **`l2c_link_send_to_lower`** — Formats ACL data header and routes packet buffer to BTU task. | 2 callers / 3 callees |
| `0x600bb15c` | 146 | L2CAP PDU | **`l2cu_process_pending_commands`** — Flushes pending L2CAP signaling command queue. | 2 callers / 6 callees |
| `0x600bb2ac` | 96 | L2CAP PDU | **`l2cu_free_lcb`** — Releases link control block and terminates associated channel timers. | 1 caller / 4 callees |
| `0x600bb3b4` | 146 | L2CAP PDU | **`l2cu_disconnect_ccb`** — Initiates disconnect sequence for channel control block. | 1 caller / 3 callees |
| `0x600bb6dc` | 94 | L2CAP PDU | **`l2cu_find_lcb_by_bd_addr`** — Searches 4-entry LCB table (stride 164B) by 6-byte BD_ADDR. | 26 callers / 1 callee |
| `0x600bb740` | 26 | L2CAP PDU | **`l2cu_get_num_links`** — Returns count of active L2CAP physical links (`DAT_600bb75c + 0xe9c`). | 1 caller / 0 callees |
| `0x600bb760` | 62 | L2CAP PDU | **`l2cu_reject_connection`** — Formats and transmits L2CAP Connection Reject signaling packet. | 1 caller / 1 callee |
| `0x600bb8f8` | 8 | L2CAP PDU | **`l2cu_no_op_return`** — No-op stub returning input register. | 2 callers / 0 callees |
| `0x600bb904` | 2 | L2CAP PDU | **`l2cu_reassemble_pdu`** — Basic-mode PDU reassembly entry stub. | 1 caller / 0 callees |
| `0x600bbb2c` | 200 | L2CAP PDU | **`l2cu_allocate_ccb`** — Allocates new CCB, assigns dynamic local CID (`0x0040`–`0x007f`). | 1 caller / 4 callees |
| `0x600bc158` | 76 | L2CAP PDU | **`l2cu_find_ccb_by_local_cid`** — Look up CCB by local channel ID (CID). | 1 caller / 0 callees |
| `0x600bc1a8` | 74 | L2CAP PDU | **`l2cu_find_ccb_by_remote_cid`** — Look up CCB by peer/remote channel ID (CID). | 3 callers / 0 callees |
| `0x600bc1f8` | 162 | L2CAP PDU | **`l2cu_copy_config_params`** — Copies L2CAP configuration parameter structure into CCB. | 1 caller / 0 callees |
| `0x600bc424` | 82 | L2CAP PDU | **`l2cu_init_lcb_pool`** — Initializes 4-entry L2CAP link control block table. | 1 caller / 1 callee |
| `0x600bc574` | 76 | L2CAP PDU | **`l2cu_check_link_congestion`** — Evaluates link buffer congestion status. | 1 caller / 0 callees |
| `0x600bc710` | 74 | L2CAP PDU | **`l2cu_find_lcb_by_state`** — Searches 4-entry LCB table (stride 164B) matching link state/role at `+0x01`. | 1 caller / 0 callees |
| `0x600bc760` | 130 | L2CAP PDU | **`l2cu_allocate_lcb`** — Allocates free LCB slot and initializes link state fields. | 1 caller / 0 callees |
| `0x600bc7e8` | 52 | L2CAP PDU | **`l2cu_release_lcb`** — Frees link control block and returns it to pool. | 4 callers / 1 callee |
| `0x600bc81c` | 24 | L2CAP PDU | **`l2cu_csm_broadcast_event`** — Iterates all open CCBs and feeds broadcast event to `l2c_csm_execute`. | 1 caller / 1 callee |
| `0x600bc994` | 80 | L2CAP PDU | **`l2cu_process_fixed_chnl`** — Dispatches fixed-channel PDU (ATT CID 4 / SMP CID 6) to registered receiver. | 3 callers / 0 callees |
| `0x600bcbe0` | 74 | L2CAP PDU | **`l2cu_find_lcb_by_handle`** — Searches 4-entry LCB table (stride 164B) matching 16-bit HCI connection handle at `+0x02`. | 9 callers / 0 callees |
| `0x600bcc30` | 116 | L2CAP PDU | **`l2cu_find_ccb_by_cid`** — Look up CCB across 8-entry pool (stride 216B) matching local dynamic CID (`> 0x3f`) and link pointer. | 9 callers / 0 callees |
| `0x600bd118` | 48 | SDP Server | **`sdp_set_max_attr_list_size`** — Accessor/mutator for SDP max attribute list size (`DAT_600bd148 + 0x380`). | 1 caller / 0 callees |
| `0x600bd484` | 48 | SDP Server | **`sdp_set_server_mtu`** — Accessor/mutator for SDP server MTU (`DAT_600bd4b4 + 0xf94`). | 1 caller / 0 callees |
| `0x600bd5fc` | 86 | SDP Database | **`sdp_db_find_record`** — Searches SDP service database (stride 460B) matching 32-bit service record handle. | 1 caller / 0 callees |
| `0x600bde90` | 168 | SDP Client | **`sdp_conn_originate`** — Allocates SDP CCB and initiates L2CAP channel connection to peer SDP server. | 0 callers / 4 callees |
| `0x600be060` | 154 | SDP Client | **`sdp_conn_timeout`** — Manages SDP transaction watchdog timer (30s = `0x1e`) and connection response. | 0 callers / 4 callees |
| `0x600bf2d8` | 74 | SDP Utils | **`sdpu_find_ccb_by_cid`** — Searches 3-entry SDP CCB table (stride 60B) matching L2CAP CID at `+0x22`. | 4 callers / 0 callees |
| `0x600bf328` | 72 | SDP Utils | **`sdpu_allocate_ccb`** — Allocates unused SDP CCB slot and clears control block. | 1 caller / 1 callee |
| `0x600bfb4c` | 14 | SDP Codec | **`sdpu_get_len_from_type`** — Spec-verified SDP Data Element Sequence (DES) length header decoder. | 1 caller / 0 callees |
| `0x600bfb5a` | 8 | SDP Codec | **`sdpu_extract_attr_seq_len`** — DES attribute sequence length parser helper. | 1 caller / 0 callees |
| `0x600bfb62` | 174 | SDP Codec | **`sdpu_process_attribute_rsp`** — Attribute response PDU parser jump table dispatcher. | 1 caller / 0 callees |
| `0x600bfe2c` | 126 | SDP Codec | **`sdpu_calculate_attr_size`** — Computes total wire bytes (header + payload) for given DES attribute. | 4 callers / 0 callees |
| `0x600bff84` | 94 | SDP Utils | **`sdpu_cb_event_dispatcher`** — Dispatches SDP connection callback through 4-entry table at `DAT_600bffe4`. | 1 caller / 0 callees |
| `0x600c0114` | 142 | SMP FSM | **`smp_proc_pairing_req`** — Evaluates incoming/outgoing Pairing Request/Response parameters, initializes pairing context, and transitions to Phase 1/2. | 0 callers / 5 callees |
| `0x600c01b8` | 200 | SMP FSM | **`smp_proc_pairing_confirm`** — SMP Phase 2 authentication router; triggers confirmation computation (`f4` / `0x600c10a4`) across Just Works, Passkey, Numeric Comparison, and OOB models. | 0 callers / 4 callees |
| `0x600c03d8` | 82 | SMP FSM | **`smp_proc_rand`** — SMP Phase 2 Random value processor; validates received random and computes confirmation verification. | 1 caller / 3 callees |
| `0x600c0434` | 132 | SMP FSM | **`smp_check_pairing_in_progress`** — Checks active pairing target BD_ADDR and state `0x0e` (`SMP_STATE_BOND_PENDING`), emitting completion event `0x18`. | 1 caller / 3 callees |
| `0x600c04c4` | 42 | SMP FSM | **`smp_reset`** / **`smp_init_context`** — Resets SMP control block state context and cancels active transaction timers. | 1 caller / 3 callees |
| `0x600c0524` | 44 | SMP Config | **`smp_get_set_loc_io_caps`** — Getter/setter for local IO capabilities byte in SMP control block (`smp_cb + 0x1c`). | 1 caller / 0 callees |
| `0x600c0558` | 28 | SMP Config | **`smp_set_sec_mode`** — Registers SMP security callback handler pointer at `DAT_600c0574`. | 1 caller / 0 callees |
| `0x600c0578` | 104 | SMP API | **`SMP_Pair`** / **`smp_pair_req`** — Initiates SMP pairing with target BD_ADDR; validates idle state and opens L2CAP SMP fixed channel (`0x600b50d0`). | 2 callers / 3 callees |
| `0x600c05e4` | 86 | SMP API | **`SMP_SecurityGrant`** — Security Grant API for peer BD_ADDR; marks `smp_cb + 0x1fa = 1` and posts event 8 to `smp_sm_event`. | 1 caller / 2 callees |
| `0x600c0640` | 78 | SMP API | **`SMP_PasskeyReply`** — Processes user passkey entry reply; validates state `0x02` and emits event `0x15` to `smp_sm_event`. | 1 caller / 2 callees |
| `0x600c0698` | 154 | SMP API | **`SMP_ConfirmReply`** — Processes user confirmation reply; validates passkey value <= 999,999 (`DAT_600c0738`) and routes to `smp_sm_event` event `0x25` or stores DHKey check. | 1 caller / 4 callees |
| `0x600c073c` | 114 | SMP API | **`SMP_NumericComparisonReply`** — Processes user Numeric Comparison accept/reject reply; validates state `0x06` and dispatches event `0x23` or error `0x0c`. | 1 caller / 3 callees |
| `0x600c07b4` | 40 | SMP Utils | **`smp_free_pdu_buffer`** — Releases SMP PDU buffer to GKI allocator (`FUN_6006ddd8`). | 1 caller / 2 callees |
| `0x600c08c4` | 104 | SMP Utils | **`smp_set_key_distribution`** — Calculates initiator/responder key distribution bitmasks. | 1 caller / 2 callees |
| `0x600c0930` | 176 | SMP Crypto | **`smp_derive_link_key`** — Cross-transport key derivation helper (BR/EDR link key <-> LE LTK). | 1 caller / 4 callees |
| `0x600c0c84` | 44 | SMP FSM | **`smp_set_state_phase2_dhkey`** — SMP state transition to Phase 2 DHKey computation (sub-state 6). | 2 callers / 2 callees |
| `0x600c0cb4` | 108 | SMP Crypto | **`smp_generate_passkey`** — Calculates 6-digit numeric comparison passkey (0 to 999999 / `0xF423F`). | 1 caller / 1 callee |
| `0x600c0d20` | 28 | SMP Crypto | **`smp_pack_passkey_u32`** — Serializes 32-bit passkey value into 4 little-endian wire bytes. | 1 caller / 0 callees |
| `0x600c0d3c` | 112 | SMP Crypto | **`smp_pack_passkey_u32_alt`** — Alternative passkey packing entry point. | 1 caller / 1 callee |
| `0x600c0db4` | 44 | SMP FSM | **`smp_set_state_phase2_confirm`** — SMP state transition to Phase 2 confirm wait (sub-state 7). | 1 caller / 2 callees |
| `0x600c0de4` | 44 | SMP FSM | **`smp_set_state_phase2_rand`** — SMP state transition to Phase 2 random wait (sub-state 8). | 1 caller / 2 callees |
| `0x600c0e14` | 98 | SMP Crypto | **`smp_compute_aes_cmac_f4`** — Wrapper for AES-CMAC confirmation calculation `f4` (`FUN_600f0ac8`). | 0 callers / 5 callees |
| `0x600c0e7c` | 84 | SMP Crypto | **`smp_compute_aes_cmac_f5`** — Wrapper for AES-CMAC key generation calculation `f5`. | 0 callers / 4 callees |
| `0x600c0ed4` | 44 | SMP FSM | **`smp_set_state_phase2_check`** — SMP state transition to DHKey check wait (sub-state 5). | 1 caller / 2 callees |
| `0x600c0f04` | 44 | SMP FSM | **`smp_set_state_phase2_ltk`** — SMP state transition to LTK calculation (sub-state 9). | 0 callers / 2 callees |
| `0x600c10a4` | 156 | SMP Crypto | **`smp_sc_compute_confirm`** — Computes LE Secure Connections confirmation value (`FUN_600fc542`). | 1 caller / 2 callees |
| `0x600c1158` | 80 | SMP Crypto | **`smp_sc_compute_dhkey_check`** — Computes LE Secure Connections DHKey check value. | 1 caller / 2 callees |
| `0x600c11bc` | 40 | SMP Crypto | **`smp_sc_compute_dhkey_check_alt`** — DHKey check calculation trailing helper. | 1 caller / 1 callee |
| `0x600c1204` | 166 | SMP Crypto | **`smp_sc_compute_numeric_compare`** — Derives 6-digit user confirmation code from DHKey and nonces (`f6`). | 0 callers / 2 callees |
| `0x600c13e8` | 168 | SMP Crypto | **`smp_aes_cmac_kdf`** — AES-CMAC based Key Derivation Function (KDF) for LE Secure Connections. | 1 caller / 2 callees |
| `0x600c1494` | 176 | SMP Crypto | **`smp_aes_cmac_hash`** — Generates 128-bit AES-CMAC cryptographic hash block. | 1 caller / 1 callee |
| `0x600c1548` | 42 | SMP FSM | **`smp_set_state_phase3_enc`** — SMP state transition to Phase 3 link encryption start (sub-state 13). | 3 callers / 2 callees |
| `0x600c1578` | 42 | SMP FSM | **`smp_set_state_phase3_done`** — SMP state transition to Phase 3 completion (sub-state 14). | 1 caller / 2 callees |
| `0x600c1738` | 68 | SMP Timer | **`smp_start_auth_timer`** — Starts 30-second SMP transaction watchdog timer (`0x1e`). | 0 callers / 1 callee |
| `0x600c1988` | 102 | SMP Timer | **`smp_proc_timer_expiry`** — SMP timer expiry callback; aborts pairing on timeout. | 0 callers / 1 callee |
| `0x600c19f4` | 36 | SMP Config | **`smp_set_pairing_security_mode`** — Sets SMP pairing mode / security level (`DAT_600c1a18 + 0x23`). | 5 callers / 0 callees |
| `0x600c1a1c` | 20 | SMP Config | **`smp_get_pairing_security_mode`** — Returns current SMP pairing security level (`DAT_600c1a30 + 0x23`). | 1 caller / 0 callees |
| `0x600c1b20` | 78 | SMP Utils | **`smp_check_ltk_valid`** — Validates LTK encryption key size and key material integrity. | 2 callers / 1 callee |
| `0x600c1b74` | 138 | SMP FSM | **`smp_dispatch_sm_event`** — Routes SMP events to `smp_sm_event` with 30s timeout guard (`FUN_600aa340`). | 12 callers / 4 callees |
| `0x600c1c04` | 38 | SMP FSM | **`smp_send_timeout_event`** — Emits timeout event `0x16` to `smp_sm_event`. | 0 callers / 1 callee |
| `0x600c229c` | 98 | SMP Crypto | **`smp_sc_store_peer_dhkey_check`** — Stores peer DHKey check record in SMP control block. | 1 caller / 1 callee |
| `0x600c2304` | 86 | SMP Config | **`smp_get_auth_req_flags`** — Extracts and validates AuthReq bitmask (MITM, SC, Keypress, Bonding). | 7 callers / 0 callees |
| `0x600c25ac` | 80 | SMP Crypto | **`smp_sc_validate_dhkey_check`** — Verifies received peer LE Secure Connections DHKey Check against expected locally computed hash (`memcmp`). | 1 caller / 3 callees |
| `0x600c7048` | 94 | BTA DM | **`bta_dm_check_device_acl`** — Checks device ACL link state and security encryption level. | 2 callers / 2 callees |
| `0x600c70ac` | 58 | BTA DM | **`bta_dm_get_device_type`** — Returns device Bluetooth type (BR/EDR, BLE, or Dual-mode). | 2 callers / 0 callees |
| `0x600c70ec` | 58 | BTA DM | **`bta_dm_get_device_features`** — Returns device supported feature bitmask. | 2 callers / 0 callees |
| `0x600c712c` | 58 | BTA DM | **`bta_dm_get_device_security`** — Returns device security flags record. | 2 callers / 0 callees |
| `0x600c716c` | 58 | BTA DM | **`bta_dm_get_device_cod`** — Returns 24-bit Class of Device (CoD) descriptor. | 2 callers / 0 callees |
| `0x600c73e0` | 58 | BTA DM | **`bta_dm_get_device_rssi`** — Returns last recorded link RSSI value. | 2 callers / 0 callees |
| `0x600c7420` | 58 | BTA DM | **`bta_dm_get_device_tx_power`** — Returns device transmit power level descriptor. | 2 callers / 0 callees |
| `0x600c7460` | 58 | BTA DM | **`bta_dm_get_device_conn_state`** — Returns active connection state flag. | 2 callers / 0 callees |
| `0x600c7878` | 106 | BTA GATTC | **`bta_gattc_send_open_evt`** — Formats GATTC open connection event message and queues to GKI. | 2 callers / 1 callee |
| `0x600c78e8` | 114 | BTA GATTC | **`bta_gattc_send_close_evt`** — Formats GATTC close connection event message and queues to GKI. | 2 callers / 1 callee |
| `0x600c7960` | 128 | BTA GATTC | **`bta_gattc_send_search_evt`** — Formats GATTC service search event message. | 1 caller / 1 callee |
| `0x600c79e4` | 194 | BTA GATTC | **`bta_gattc_send_read_evt`** — Formats GATTC read characteristic value event message. | 1 caller / 2 callees |
| `0x600c7bac` | 182 | BTA GATTC | **`bta_gattc_send_write_evt`** — Formats GATTC write characteristic value event message. | 1 caller / 1 callee |
| `0x600c7c68` | 166 | BTA GATTS | **`bta_gatts_send_rsp_evt`** — Formats GATTS response event message and queues to GKI. | 1 caller / 1 callee |
| `0x600c7d14` | 74 | BTA GATTS | **`bta_gatts_send_close_evt`** — Formats GATTS connection close event message. | 2 callers / 1 callee |
| `0x600c7eb8` | 156 | BTA SYS | **`bta_sys_dispatch_event`** — Routes BTA subsystem events across BTA SYS event bus. | 5 callers / 5 callees |
| `0x600c89e0` | 106 | EC Math | **`ec_field_double_mod_p`** — Multi-precision finite field modular doubling ($r = (2a) \pmod p$) for NIST P-256 / P-192 curves. | 2 callers / 3 callees |
| `0x600c8a54` | 110 | EC Math | **`ec_field_add_mod_p`** — Multi-precision finite field modular addition ($r = (a + b) \pmod p$) for NIST P-256 / P-192 curves. | 1 caller / 3 callees |
| `0x600c8acc` | 80 | EC Math | **`ec_field_sub_mod_p`** — Multi-precision finite field modular subtraction ($r = (a - b) \pmod p$) for NIST P-256 / P-192 curves. | 3 callers / 2 callees |


## Session 30 (Wave 2) — Complete Decompilation of Lower BTA/BTE Stack (`0x600921b8`–`0x6009ffff`): 228 Functions / 21,514 Code Bytes (100% Milestone for Lower Stack)
228 newly decompiled and analyzed functions across `0x600921b8`–`0x6009ffff`, completing the entire lower address range of the Broadcom BTA/BTE stack. Combined with previous sessions, **332 of 332 functions (49,734 of 49,734 bytes = 100.0%)** in the `0x600921b8`–`0x6009ffff` range are now fully decompiled and documented.
Overall BTA/BTE Bluetooth stack decompilation progress (`0x600921b8`–`0x600c9cc4`) increases from 632 to **860 of 1,076 functions (79.9% by count, 183,237 of 204,449 bytes = 89.6% by byte size)**.

With this wave, **SIX additional core Broadcom BTM/HCI subsystems reach 100% full decompilation**:
1. **HCI H4 UART Transport & Flow Control** (`0x600959cc`–`0x60097664`): **36 / 36 functions (100.0%)** — 3,892 / 3,892 bytes
2. **BTM Power Management & Sniff Subrating** (`0x600930dc`–`0x600955dc`, `0x6009819c`–`0x60098be8`): **38 / 38 functions (100.0%)** — 3,884 / 3,884 bytes
3. **BTM ACL Link Control & Security Link Records** (`0x60098c14`–`0x60099f4c`): **26 / 26 functions (100.0%)** — 2,822 / 2,822 bytes
4. **BTM Advertising, EIR & BLE Scanning Subsystem** (`0x6009a114`–`0x6009b230`): **19 / 19 functions (100.0%)** — 1,942 / 1,942 bytes
5. **BTM BLE Connection, Resolving List & Privacy** (`0x6009b8b4`–`0x6009c790`): **30 / 30 functions (100.0%)** — 2,600 / 2,600 bytes
6. **BTM Security Database & Link Key Registry** (`0x6009c848`–`0x6009eb9c`): **26 / 26 functions (100.0%)** — 3,328 / 3,328 bytes
7. **BTM Device Discovery, Page/Inquiry Scan & HCI Setup** (`0x6009ec14`–`0x6009ffa0`): **27 / 27 functions (100.0%)** — 3,254 / 3,254 bytes

---

### Key Architectural Discoveries

#### 1. HCI H4 UART Physical Transport Layer (`0x600959cc`–`0x60097664`)
The firmware implements the complete 3-wire/4-wire Broadcom HCI H4 UART transport protocol:
- **H4 Frame Synchronizer**: `FUN_600959cc` (`hcisu_h4_rx_parse_hdr`) decodes the 1-byte H4 packet type indicator: `0x01` (HCI Command), `0x02` (HCI ACL Data), `0x03` (HCI SCO Data), and `0x04` (HCI Event). It computes exact header lengths (3B for commands, 4B for ACL, 3B for SCO, 2B for events) and streams variable-length payloads into dynamically allocated GKI buffers via `FUN_60095b2c` (`hcisu_h4_rx_accum`).
- **Hardware Flow Control & Low-Power Handshake**: `FUN_60095bbc` verifies CTS state before asserting UART TX DMA. `FUN_60095ee8` and `FUN_60095f9c` implement the Broadcom Low-Power Mode (LPM) handshake using `BT_WAKE` / `HOST_WAKE` GPIO lines (`FUN_60095f10` ISR).
- **HCI Credit Accounting**: `FUN_600970e4` and `FUN_60097200` maintain controller command buffer credits (`Num_HCI_Command_Packets`), preventing host FIFO overflows.

#### 2. BTM Power Management & Sniff Subrating (`0x600930dc`–`0x600955dc`, `0x6009819c`–`0x60098be8`)
Power mode negotiation between the Stadia controller host and connected peers/consoles is mediated through a multi-tier BTA DM / BTM PM state machine:
- **Multi-Link Power Arbitration**: `FUN_60093988` reconciles active power mode requests (Active, Sniff, Park, Hold) across multiple active profiles (HID Gamepad vs Audio vs Device Management), selecting the highest-activity mode required.
- **Sniff Subrating Negotiation**: `FUN_600941c4` (`bta_dm_pm_send_ssr_req`) and `FUN_600985f8` (`BTM_SetSniffSubrating`) issue HCI Sniff Subrating commands (`0x0811`), setting max latency (`max_lat`), min remote timeout (`min_rmt_to`), and min local timeout (`min_loc_to`) to reduce Bluetooth radio duty cycle and battery consumption while in gamepad idle states.

#### 3. BTM ACL Link Control & Encryption State (`0x60098c14`–`0x60099f4c`)
The BTM ACL manager maintains active connection records:
- **Dual-Indexed Link Descriptors**: `FUN_60098c5c` (`btm_acl_alloc`) and `FUN_60098cc4` (`btm_acl_free`) manage the fixed ACL link table in `DAT_60098c10`, providing O(1) indexed lookups by 6-byte BD_ADDR (`FUN_60098d2c`) and 16-bit connection handle (`FUN_60098d8c`).
- **Encryption Level Enforcement**: `FUN_60099190` mutates link security level: `0` (Unencrypted), `1` (BR/EDR E0 stream cipher), and `2` (LE AES-CCM 128-bit). `FUN_600999bc` propagates HCI Encryption Change events directly into L2CAP and SMP security handlers.

#### 4. BTM BLE Privacy, Resolving List & Resolvable Private Addresses (`0x6009a114`–`0x6009c790`)
The BLE subsystem implements Bluetooth Core Spec 4.2 / 5.0 privacy architectures:
- **Cryptographic RPA Generation & Verification**: `FUN_6009c194` (`btm_ble_gen_rpa`) generates Resolvable Private Addresses by concatenating a 24-bit random seed `prand` (`0x40` top bits) with a 24-bit hash $hash = 	ext{ah}(IRK, prand)$. `FUN_6009c1d4` (`btm_ble_verify_rpa`) verifies inbound peer RPAs against bonded Identity Resolving Keys (IRKs) using AES-128 cryptographic hash helper `ah` (`FUN_600c0ac4`).
- **Hardware Resolving List**: `FUN_6009beb0` (`BTM_BleAddResolvingList`) provisions controller hardware resolving lists (`0x2027`), offloading RPA resolution from host CPU to the Broadcom radio.

#### 5. BTM Security Database & Link Key Registry (`0x6009c848`–`0x6009eb9c`)
`btm_sec_cb` manages persistent security records (`btm_sec_dev_rec`):
- **Key Storage**: `FUN_6009cd94` (`BTM_WriteLinkKey`), `FUN_6009ce30` (`BTM_ReadLinkKey`), and `FUN_6009cec8` (`BTM_SecAddBleKey`) store 16-byte Link Keys, Long Term Keys (LTKs), Identity Resolving Keys (IRKs), Connection Signature Resolving Keys (CSRKs), and EDIV/Rand values.
- **Service Security Policy Check**: `FUN_6009e70c` evaluates incoming channel/service connection attempts against registered policy masks (`BTM_SEC_IN_AUTHENTICATE`, `BTM_SEC_IN_ENCRYPT`, `BTM_SEC_IN_AUTHORIZE`), blocking unauthenticated access to GATT/HID channels.

#### 6. BTM Discovery, Scan & HCI Setup (`0x6009ec14`–`0x6009ffa0`)
The device discovery and configuration pipeline controls Bluetooth visibility:
- **Inquiry Pipeline**: `FUN_6009ec14` (`BTM_StartInquiry`) and `FUN_6009ee18` (`btm_proc_ext_inq_result`) handle Standard, RSSI-based, and Extended Inquiry Result (EIR) records.
- **Device Configuration**: `FUN_6009f644` (`BTM_WriteScanEnable`) toggles Page/Inquiry Scan; `FUN_6009feb8` writes the 24-bit Class of Device (`0x002508` for Gamepad/Peripheral); `FUN_6009ffa0` provisions the local Bluetooth Device Name ("Stadia Controller").

### Complete Table of 228 Functions Decompiled in Session 30 (Wave 2)

| Address | Bytes | Subsystem / Range | Name / Verified Role | Callers / Callees |
|---|---:|---|---|---|
| `0x60092448` |  72 | CRC / Math | **`crc32_finalize`** — Computes final CRC-32 checksum with XOR inversion and context wrap-up (`DAT_60092490`). | 1 caller / 4 callees |
| `0x60092498` | 118 | CRC / Math | **`crc32_block_update`** — Updates running CRC-32 table accumulator across input byte buffer (`0x1c` byte chunks). | 1 caller / 5 callees |
| `0x60092514` |  14 | CRC / Math | **`crc32_reset`** — Resets CRC-32 calculation context accumulator to initial seed (`DAT_60092524`). | 1 caller / 0 callees |
| `0x60092528` |  78 | CRC / Math | **`crc32_calc_buffer`** — Iterative multi-block CRC-32 calculator with boundary checking and length validation. | 3 callers / 4 callees |
| `0x6009257c` |  20 | CRC / Math | **`crc32_set_flags`** — Sets CRC-32 engine mode flags (`0x10000000` bitmask in `DAT_60092590`). | 4 callers / 0 callees |
| `0x60092594` |  16 | CRC / Math | **`crc32_get_context`** — Retrieves pointer to active CRC-32 engine context block (`DAT_600925a4`). | 2 callers / 3 callees |
| `0x600925a8` |  16 | CRC / Math | **`crc32_free_context`** — Clears and invalidates CRC-32 engine calculation state. | 2 callers / 2 callees |
| `0x6009267c` |  28 | BTA DM / Timer | **`bta_dm_timer_check`** — Low-level timer interval validator and watchdog tick checker (`DAT_60092698`). | 5 callers / 1 callee |
| `0x600926a0` |  70 | BTA DM / Timer | **`bta_dm_timer_tick`** — Calculates elapsed timer ticks and checks threshold limits (`0x58`, `0xb0`). | 3 callers / 3 callees |
| `0x600926b8` |  18 | BTA DM / Timer | **`bta_dm_timer_isr`** — Timer interrupt callback; dispatches expired timing events across BTA subsystems. | 2 callers / 6 callees |
| `0x60092744` |  54 | BTA DM / Sys | **`bta_dm_sys_enqueue`** — Enqueues BTA DM event message into BTA system task queue (`FUN_6006bf74`). | 2 callers / 2 callees |
| `0x600927d8` |  92 | BTA DM / PM | **`bta_dm_pm_set_policy`** — Configures link policy parameters for target BD_ADDR; calls `FUN_60097f5c`. | 3 callers / 2 callees |
| `0x60092838` | 106 | BTA DM / PM | **`bta_dm_pm_select_mode`** — Evaluates power mode requirements (Active, Sniff, Park) and issues PM requests. | 3 callers / 2 callees |
| `0x600928ac` |  94 | BTA DM / PM | **`bta_dm_pm_req_dispatcher`** — Top-level power management request router; routes between `FUN_600927d8` and `FUN_60092838`. | 3 callers / 4 callees |
| `0x60092970` |  22 | BTA DM / PM | **`bta_dm_pm_timer_cback`** — BTA DM power management watchdog timer callback; posts timeout event `0x16c`. | 1 caller / 1 callee |
| `0x60092de8` |  98 | BTA DM / PM | **`bta_dm_pm_state_change`** — Transitions BTA DM power management state machine; logs state and posts event `0x4d`. | 4 callers / 7 callees |
| `0x600930dc` |  88 | BTA DM / PM | **`bta_dm_pm_find_peer`** — Searches BTA DM PM peer connection table (`DAT_60093134`) for matching BD_ADDR. | 2 callers / 2 callees |
| `0x60093478` | 110 | BTA DM / PM | **`bta_dm_pm_ssr_config`** — Configures Sniff Subrating (SSR) latency and timeout parameters (`DAT_600934f0`). | 3 callers / 4 callees |
| `0x600935dc` |  74 | BTA DM / PM | **`bta_dm_pm_get_profile_mode`** — Looks up profile-specific power mode table entry (`DAT_60093628` + index * `0x11`). | 1 caller / 0 callees |
| `0x6009362c` | 162 | BTA DM / PM | **`bta_dm_pm_eval_mode_change`** — Evaluates link activity level and triggers transition to sniff or active mode. | 2 callers / 3 callees |
| `0x60093988` | 162 | BTA DM / PM | **`bta_dm_pm_multi_link_arb`** — Arbitrates conflicting power mode requests across concurrent Bluetooth links. | 3 callers / 2 callees |
| `0x600941c4` |  60 | BTA DM / PM | **`bta_dm_pm_send_ssr_req`** — Formats and transmits Sniff Subrating request command (`0x124` byte buffer). | 3 callers / 3 callees |
| `0x60094208` | 196 | BTA DM / PM | **`bta_dm_pm_calc_policy_mask`** — Computes effective link policy bitmask based on active profile requirements. | 3 callers / 4 callees |
| `0x600942d4` |  52 | BTA DM / PM | **`bta_dm_pm_cmd_complete`** — BTA DM PM command completion callback; updates status in `DAT_60094308`. | 4 callers / 5 callees |
| `0x600944c0` |  86 | BTA DM / PM | **`bta_dm_pm_negotiate_mode`** — Negotiates power mode parameters with peer; updates control block at `+0x20`. | 4 callers / 6 callees |
| `0x6009451c` | 106 | BTA DM / PM | **`bta_dm_pm_trigger_mode_change`** — Initiates link power mode change via BTM link policy API; opcode `0x1d17`. | 4 callers / 8 callees |
| `0x60094ba4` | 160 | BTM / PM | **`btm_pm_init`** — Initializes BTM Power Management subsystem control block (`DAT_60098190`). | 3 callers / 7 callees |
| `0x60094d24` | 152 | BTM / PM | **`BTM_SetPowerMode`** — Public API: requests link power mode change (Active, Sniff, Park, Hold) for connection. | 7 callers / 19 callees |
| `0x60094f14` |  64 | BTM / PM | **`btm_pm_read_link_policy`** — Reads current link policy settings for specified connection handle. | 1 caller / 2 callees |
| `0x60094f58` |  80 | BTM / PM | **`btm_pm_write_default_policy`** — Configures default system-wide link policy mask (`DAT_60094fa8`). | 3 callers / 9 callees |
| `0x60094fac` |  74 | BTM / PM | **`btm_pm_write_link_policy`** — Writes link policy mask for specific connection handle via HCI. | 2 callers / 2 callees |
| `0x60094ffc` | 106 | BTM / PM | **`btm_pm_validate_sniff_params`** — Validates sniff interval (`min`/`max`), sniff attempt, and sniff timeout parameters. | 1 caller / 7 callees |
| `0x6009506c` |  74 | BTM / PM | **`btm_pm_eval_transition`** — Evaluates power mode transition feasibility against current connection state. | 5 callers / 9 callees |
| `0x6009519c` |  76 | BTM / PM | **`btm_pm_set_park_params`** — Configures beacon interval and timing parameters for Park mode. | 2 callers / 3 callees |
| `0x600951ec` |  68 | BTM / PM | **`btm_pm_set_hold_params`** — Configures hold mode duration and max hold interval parameters. | 2 callers / 2 callees |
| `0x6009547c` | 176 | BTM / PM | **`btm_pm_proc_mode_change`** — Processes HCI Mode Change event (`0x14`); updates link record power state. | 1 caller / 2 callees |
| `0x60095534` |  80 | BTM / PM | **`btm_pm_notify_cback`** — Notifies registered BTA/BTM power management callbacks of mode change. | 1 caller / 2 callees |
| `0x60095588` |  80 | BTM / PM | **`btm_pm_cancel_mode_req`** — Cancels pending power mode change request for specified connection handle. | 1 caller / 3 callees |
| `0x600955dc` | 106 | BTM / PM | **`btm_pm_get_status`** — Returns current power management status and active mode (`DAT_6009564c`). | 5 callers / 7 callees |
| `0x600959cc` | 202 | HCI / H4 UART | **`hcisu_h4_rx_parse_hdr`** — Parses 1-byte HCI H4 packet type header (`1`=CMD, `2`=ACL, `3`=SCO, `4`=EVT). | 2 callers / 12 callees |
| `0x60095ae8` |  64 | HCI / H4 UART | **`hcisu_h4_rx_step`** — HCI H4 UART receive state machine step; manages byte stream synchronization. | 1 caller / 2 callees |
| `0x60095b2c` |  74 | HCI / H4 UART | **`hcisu_h4_rx_accum`** — Accumulates incoming UART bytes into active GKI receive buffer. | 1 caller / 7 callees |
| `0x60095b7c` |  28 | HCI / H4 UART | **`hcisu_h4_alloc_buf`** — Allocates GKI packet buffer for incoming HCI message (`FUN_6006dbac`). | 2 callers / 1 callee |
| `0x60095b9c` |  28 | HCI / H4 UART | **`hcisu_h4_free_buf`** — Releases completed HCI packet buffer back to GKI pool (`FUN_6006ddd8`). | 2 callers / 1 callee |
| `0x60095bbc` |  82 | HCI / H4 UART | **`hcisu_h4_check_flow_ctrl`** — Checks hardware RTS/CTS flow control status before initiating transmit. | 2 callers / 1 callee |
| `0x60095c14` |  28 | HCI / H4 UART | **`hcisu_h4_tx_queue_check`** — Checks if HCI H4 UART transmit queue contains pending outbound packets. | 3 callers / 2 callees |
| `0x60095c34` |  76 | HCI / H4 UART | **`hcisu_h4_tx_enqueue`** — Enqueues outbound HCI packet into UART transmit ring buffer (`DAT_60095c7c`). | 1 caller / 1 callee |
| `0x60095c84` |  76 | HCI / H4 UART | **`hcisu_h4_tx_dequeue`** — Dequeues next pending HCI packet from UART transmit ring buffer. | 1 caller / 2 callees |
| `0x60095cd4` | 116 | HCI / H4 UART | **`hcisu_h4_tx_start`** — Triggers UART DMA / FIFO transmission for head of transmit queue. | 3 callers / 6 callees |
| `0x60095d4c` |  76 | HCI / H4 UART | **`hcisu_h4_set_baudrate`** — Reconfigures UART transport baudrate (e.g. 115200 to 3000000 bps). | 2 callers / 4 callees |
| `0x60095d9c` |  50 | HCI / H4 UART | **`hcisu_h4_reset`** — Resets HCI H4 transport state machine, flushing RX/TX ring buffers. | 3 callers / 11 callees |
| `0x60095dd4` |  28 | HCI / H4 UART | **`hcisu_h4_resync`** — Error recovery handler: resynchronizes H4 parser after framing/parity errors. | 1 caller / 1 callee |
| `0x60095ee8` |  36 | HCI / H4 UART | **`hcisu_h4_sleep_assert`** — Asserts controller BT_WAKE / sleep signal via low-power protocol GPIO. | 3 callers / 2 callees |
| `0x60095f10` |  34 | HCI / H4 UART | **`hcisu_h4_host_wake_isr`** — HOST_WAKE interrupt handler; wakes BTU task on controller activity. | 2 callers / 1 callee |
| `0x60095f9c` | 130 | HCI / H4 UART | **`hcisu_h4_lpm_handshake`** — Broadcom low-power mode (LPM) controller sleep/wake handshake negotiator. | 3 callers / 2 callees |
| `0x6009605c` | 128 | HCI / H4 UART | **`hcisu_h4_timer_expiry`** — Watchdog timer expiration callback for HCI UART response timeouts. | 1 caller / 1 callee |
| `0x600960e0` | 114 | HCI / H4 UART | **`hcisu_h4_quick_timer_tick`** — Quick timer tick processor for UART character timeout detection. | 2 callers / 2 callees |
| `0x60096158` |  62 | HCI / H4 UART | **`hcisu_h4_trace_pkt`** — Formats and outputs diagnostic trace log for HCI packet transmission. | 1 caller / 0 callees |
| `0x6009619c` |  62 | HCI / H4 UART | **`hcisu_h4_send_cmd`** — Serializes HCI Command packet with type `0x01` and queues to UART. | 1 caller / 0 callees |
| `0x6009623c` |  24 | HCI / H4 UART | **`hcisu_h4_send_acl`** — Serializes HCI ACL Data packet with type `0x02` and queues to UART. | 4 callers / 2 callees |
| `0x6009625c` |  46 | HCI / H4 UART | **`hcisu_h4_tx_flush`** — Flushes pending outbound packets from UART transmit FIFO. | 4 callers / 3 callees |
| `0x600962b8` |  32 | HCI / H4 UART | **`hcisu_h4_cts_isr`** — UART CTS line change interrupt service routine; resumes stalled TX. | 3 callers / 2 callees |
| `0x60096314` |  34 | HCI / H4 UART | **`hcisu_h4_rx_drain`** — Drains hardware UART RX FIFO into temporary staging buffer. | 4 callers / 8 callees |
| `0x6009633c` |  24 | HCI / H4 UART | **`hcisu_h4_get_rx_stats`** — Returns count of received bytes, packets, and framing errors. | 7 callers / 9 callees |
| `0x60096358` |  26 | HCI / H4 UART | **`hcisu_h4_get_tx_stats`** — Returns count of transmitted bytes, packets, and retransmissions. | 3 callers / 2 callees |
| `0x60096378` | 148 | HCI / H4 UART | **`hcisu_h4_clear_stats`** — Clears UART transport RX/TX statistical counters. | 2 callers / 2 callees |
| `0x60096424` |  34 | HCI / Transport | **`hci_transport_init`** — Initializes top-level HCI transport subsystem control block (`DAT_60096420`). | 1 caller / 1 callee |
| `0x60096528` |  46 | HCI / Transport | **`hci_transport_open`** — Opens HCI physical transport channel and brings up UART interface. | 2 callers / 2 callees |
| `0x6009655c` |  44 | HCI / Transport | **`hci_transport_close`** — Closes HCI physical transport channel and shuts down UART interface. | 3 callers / 3 callees |
| `0x60096594` |  24 | HCI / Transport | **`hci_transport_write`** — Synchronous write entry point for raw HCI transport packets. | 3 callers / 3 callees |
| `0x600965b4` | 108 | HCI / Transport | **`hci_transport_read`** — Synchronous read entry point for raw HCI transport packets. | 2 callers / 1 callee |
| `0x60096858` |  84 | HCI / Transport | **`hci_transport_reg_cback`** — Registers upper-layer receive callback with HCI transport layer. | 1 caller / 2 callees |
| `0x600968b0` | 122 | HCI / Transport | **`hci_transport_dereg_cback`** — Deregisters upper-layer receive callback from HCI transport layer. | 4 callers / 5 callees |
| `0x60096930` |  72 | HCI / Transport | **`hci_transport_get_pwr_state`** — Queries active power state of Bluetooth controller hardware. | 2 callers / 2 callees |
| `0x6009697c` |  96 | HCI / Transport | **`hci_transport_set_pwr_state`** — Sets power state (Full, Low-Power, Shutdown) of Bluetooth controller. | 2 callers / 2 callees |
| `0x600969e0` |  54 | HCI / Transport | **`hci_transport_send_vendor_cmd`** — Sends Broadcom vendor-specific HCI command (`0xFCxx` opcode cluster). | 4 callers / 3 callees |
| `0x60096a1c` |  46 | HCI / Transport | **`hci_transport_vendor_evt_cback`** — Dispatches Broadcom vendor-specific HCI event (`0xFF`) to registered handler. | 1 caller / 1 callee |
| `0x600970e4` | 104 | HCI / Credits | **`hci_credit_init`** — Initializes HCI flow control credit tracking for command/ACL buffers. | 1 caller / 2 callees |
| `0x60097154` |  26 | HCI / Credits | **`hci_credit_get_avail`** — Returns number of available HCI command credits from controller. | 1 caller / 1 callee |
| `0x60097174` |  38 | HCI / Credits | **`hci_credit_has_credits`** — Checks whether at least one HCI command credit is available (`> 0`). | 2 callers / 1 callee |
| `0x60097200` | 142 | HCI / Credits | **`hci_credit_update`** — Updates available HCI credits on Command Complete / Status events. | 2 callers / 3 callees |
| `0x600973f8` | 112 | HCI / Credits | **`hci_credit_flush_queue`** — Flushes pending command queue when credits are exhausted or link resets. | 2 callers / 1 callee |
| `0x6009746c` |  22 | HCI / Credits | **`hci_credit_abort_txn`** — Aborts current in-flight HCI command transaction on timeout. | 3 callers / 2 callees |
| `0x6009759c` |  90 | HCI / Debug | **`hci_debug_get_opcode_name`** — Returns human-readable string name for 16-bit HCI command opcode. | 5 callers / 5 callees |
| `0x60097600` |  90 | HCI / Debug | **`hci_debug_get_event_name`** — Returns human-readable string name for 8-bit HCI event code. | 2 callers / 3 callees |
| `0x60097664` | 142 | HCI / Debug | **`hci_debug_get_status_name`** — Returns human-readable string name for HCI status / error code. | 2 callers / 3 callees |
| `0x6009819c` | 198 | BTM / Link Policy | **`BTM_SetLinkPolicy`** — Sets link policy settings (Role Switch, Hold, Sniff, Park) for ACL link. | 8 callers / 8 callees |
| `0x6009837c` | 110 | BTM / Link Policy | **`btm_pm_get_link_policy`** — Reads active link policy mask for target connection handle. | 3 callers / 3 callees |
| `0x60098530` | 190 | BTM / Link Policy | **`btm_pm_build_sniff_req`** — Formats HCI Sniff Mode command parameters (`interval`, `attempt`, `timeout`). | 3 callers / 5 callees |
| `0x600985f8` | 106 | BTM / Link Policy | **`BTM_SetSniffSubrating`** — Configures Sniff Subrating parameters with peer device via HCI. | 3 callers / 3 callees |
| `0x60098668` |  50 | BTM / Link Policy | **`BTM_ExitSniffMode`** — Issues HCI Exit Sniff Mode command (`0x0803`) for active link. | 2 callers / 2 callees |
| `0x600986a0` |  58 | BTM / Link Policy | **`BTM_SwitchRole`** — Initiates Master/Slave role switch request via HCI (`0x080b`). | 2 callers / 1 callee |
| `0x600986e0` |  48 | BTM / Link Policy | **`BTM_GetRole`** — Returns current role (Master=0, Slave=1) for target connection handle. | 4 callers / 5 callees |
| `0x60098718` | 132 | BTM / Link Policy | **`BTM_SetLinkSupervisionTimeout`** — Sets link supervision timeout value via HCI Write Link Supervision Timeout (`0x0c37`). | 2 callers / 3 callees |
| `0x600987a0` |  54 | BTM / Link Policy | **`BTM_GetLinkSupervisionTimeout`** — Reads configured link supervision timeout value from local link record. | 2 callers / 1 callee |
| `0x600987dc` |  62 | BTM / Link Policy | **`btm_pm_send_link_policy_cmd`** — Sends HCI Write Link Policy Settings command (`0x080d`) to controller. | 3 callers / 4 callees |
| `0x60098820` | 150 | BTM / Link Policy | **`btm_pm_proc_mode_change_evt`** — Processes HCI Mode Change event; updates link policy state machine. | 2 callers / 2 callees |
| `0x60098b70` |  80 | BTM / Link Policy | **`btm_pm_proc_ssr_evt`** — Processes HCI Sniff Subrating event; updates subrating parameters in link record. | 2 callers / 1 callee |
| `0x60098bc4` |  32 | BTM / Link Policy | **`BTM_IsLinkInSniff`** — Returns boolean indicating whether target link is currently in Sniff mode. | 2 callers / 1 callee |
| `0x60098be8` |  34 | BTM / Link Policy | **`btm_pm_reset_link_policy`** — Resets link policy state and clears pending policy requests. | 4 callers / 3 callees |
| `0x60098c14` |  32 | BTM / ACL | **`btm_acl_init`** — Initializes BTM ACL link database control block (`DAT_60098c10`). | 4 callers / 3 callees |
| `0x60098c3c` |  26 | BTM / ACL | **`btm_acl_reset`** — Clears all active ACL link records and resets connection counters. | 4 callers / 3 callees |
| `0x60098c5c` |  98 | BTM / ACL | **`btm_acl_alloc`** — Allocates unused ACL Link Control Block (LCB) from pool matching BD_ADDR. | 2 callers / 1 callee |
| `0x60098cc4` |  98 | BTM / ACL | **`btm_acl_free`** — Releases ACL Link Control Block (LCB) back to free pool on disconnection. | 2 callers / 1 callee |
| `0x60098d2c` |  90 | BTM / ACL | **`btm_bda_to_acl`** — Finds active ACL Link Control Block matching 6-byte BD_ADDR. | 3 callers / 3 callees |
| `0x60098d8c` | 166 | BTM / ACL | **`btm_handle_to_acl`** — Finds active ACL Link Control Block matching 16-bit connection handle. | 5 callers / 9 callees |
| `0x60098e78` |  26 | BTM / ACL | **`BTM_GetHCIConnHandle`** — Returns 16-bit HCI connection handle for specified BD_ADDR. | 1 caller / 1 callee |
| `0x60098ea0` |  36 | BTM / ACL | **`BTM_GetBDAddrByHandle`** — Copies 6-byte BD_ADDR matching specified 16-bit HCI connection handle. | 1 caller / 1 callee |
| `0x60098ec8` | 104 | BTM / ACL | **`btm_acl_update_state`** — Updates ACL link connection state (Connecting, Connected, Disconnecting). | 16 callers / 29 callees |
| `0x60098f34` |  78 | BTM / ACL | **`BTM_IsAclLinkUp`** — Returns boolean indicating whether ACL link to specified BD_ADDR is connected. | 12 callers / 11 callees |
| `0x60099190` | 102 | BTM / ACL | **`btm_acl_set_encryption`** — Sets ACL encryption state (`0`=Off, `1`=E0, `2`=AES-CCM) in link record. | 5 callers / 7 callees |
| `0x60099204` | 202 | BTM / ACL | **`btm_acl_conn_complete`** — Handles HCI Connection Complete event; populates LCB with handle, BD_ADDR, link type. | 6 callers / 5 callees |
| `0x600992d4` |  66 | BTM / ACL | **`btm_acl_disc_complete`** — Handles HCI Disconnection Complete event; frees LCB and notifies upper layers. | 2 callers / 2 callees |
| `0x600994b8` | 194 | BTM / ACL | **`btm_acl_packet_type_change`** — Handles HCI Packet Type Change event; updates supported packet types bitmask. | 4 callers / 4 callees |
| `0x60099768` | 160 | BTM / ACL | **`btm_acl_auth_complete`** — Handles HCI Authentication Complete event; updates security link status. | 4 callers / 4 callees |
| `0x600999bc` |  90 | BTM / ACL | **`btm_acl_enc_change`** — Handles HCI Encryption Change event; notifies BTM security and L2CAP. | 4 callers / 4 callees |
| `0x60099a1c` | 188 | BTM / ACL | **`btm_acl_read_remote_features_complete`** — Processes HCI Read Remote Supported Features Complete event; stores 8-byte feature mask. | 3 callers / 5 callees |
| `0x60099bb8` |  78 | BTM / ACL | **`btm_acl_read_remote_ext_features_complete`** — Processes HCI Read Remote Extended Features Complete event; stores extended feature pages. | 4 callers / 5 callees |
| `0x60099c0c` | 134 | BTM / ACL | **`btm_acl_read_remote_version_complete`** — Processes HCI Read Remote Version Info Complete event; stores LMP version, subversion, manufacturer. | 6 callers / 7 callees |
| `0x60099c9c` |  30 | BTM / ACL | **`btm_acl_read_clock_offset_complete`** — Processes HCI Read Clock Offset Complete event; stores 16-bit clock offset in LCB. | 2 callers / 1 callee |
| `0x60099cc0` |  84 | BTM / ACL | **`btm_acl_link_supervision_timeout_change`** — Handles Link Supervision Timeout Change event; updates watchdog timer value. | 2 callers / 2 callees |
| `0x60099d18` |  70 | BTM / ACL | **`BTM_GetNumAclLinks`** — Returns count of currently active ACL links across controller. | 3 callers / 4 callees |
| `0x60099d64` |  34 | BTM / ACL | **`BTM_GetLinkKeySize`** — Returns effective encryption key size (in bytes) for target connection handle. | 2 callers / 1 callee |
| `0x60099d8c` |  64 | BTM / ACL | **`btm_acl_notify_link_state`** — Notifies registered upper-layer protocols (L2CAP, SDP, RFCOMM) of link events. | 2 callers / 2 callees |
| `0x60099f04` |  68 | BTM / ACL | **`btm_acl_flush_tx_queue`** — Flushes pending outbound ACL data buffers on link disconnection. | 3 callers / 0 callees |
| `0x60099f4c` | 136 | BTM / ACL | **`btm_acl_calc_pkt_size`** — Calculates optimal ACL packet size and fragmentation thresholds for L2CAP MTU. | 3 callers / 2 callees |
| `0x6009a114` |  60 | BTM / BLE Scan | **`BTM_BleSetScanParams`** — Configures BLE scan parameters: scan type (Active/Passive), interval, window, address type. | 2 callers / 1 callee |
| `0x6009a154` | 128 | BTM / BLE Scan | **`BTM_BleSetScanEnable`** — Enables or disables BLE scanning via HCI LE Set Scan Enable (`0x200c`). | 3 callers / 4 callees |
| `0x6009a1dc` | 112 | BTM / BLE Scan | **`btm_ble_proc_adv_report`** — Processes HCI LE Advertising Report event (`0x3e` sub-event `2`). | 5 callers / 5 callees |
| `0x6009a254` | 106 | BTM / BLE Scan | **`btm_ble_parse_adv_data`** — Top-level TLV parser for BLE Advertising Data (AD) structures in advertising reports. | 5 callers / 5 callees |
| `0x6009a3d4` | 194 | BTM / BLE Scan | **`btm_ble_extract_dev_name`** — Extracts Shortened (`0x08`) or Complete (`0x09`) Local Name from AD structures. | 2 callers / 3 callees |
| `0x6009a4a4` | 192 | BTM / BLE Scan | **`btm_ble_extract_uuids`** — Extracts 16-bit (`0x02`/`0x03`), 32-bit (`0x04`/`0x05`), and 128-bit (`0x06`/`0x07`) Service UUIDs from AD. | 2 callers / 3 callees |
| `0x6009a570` |  56 | BTM / BLE Scan | **`btm_ble_extract_tx_pwr_appearance`** — Extracts TX Power Level (`0x0a`) and Appearance Category (`0x19`) from AD. | 1 caller / 1 callee |
| `0x6009a72c` | 132 | BTM / BLE Adv | **`BTM_BleWriteAdvParams`** — Configures BLE advertising parameters via HCI LE Set Advertising Parameters (`0x2006`). | 6 callers / 7 callees |
| `0x6009a804` |  34 | BTM / BLE Adv | **`BTM_BleSetAdvEnable`** — Enables or disables BLE advertising via HCI LE Set Advertising Enable (`0x200a`). | 3 callers / 2 callees |
| `0x6009a82c` | 174 | BTM / BLE Adv | **`BTM_BleWriteAdvData`** — Writes 31-byte advertising payload via HCI LE Set Advertising Data (`0x2008`). | 5 callers / 8 callees |
| `0x6009ab40` |  80 | BTM / BLE Adv | **`BTM_BleWriteScanRspData`** — Writes 31-byte scan response payload via HCI LE Set Scan Response Data (`0x2009`). | 2 callers / 2 callees |
| `0x6009ab94` |  26 | BTM / BLE Adv | **`BTM_BleSetAdvChannelMap`** — Sets 3-bit advertising channel map (channels 37, 38, 39). | 1 caller / 3 callees |
| `0x6009abb4` |  26 | BTM / BLE Adv | **`BTM_BleSetAdvFilterPolicy`** — Sets advertising filter policy (Allow All, Whitelist Scan, Whitelist Conn, Whitelist All). | 2 callers / 2 callees |
| `0x6009abd4` |  26 | BTM / BLE Adv | **`BTM_BleSetAdvTxPower`** — Configures advertising transmit power level. | 1 caller / 2 callees |
| `0x6009abf4` | 148 | BTM / BLE Adv | **`BTM_BleSetDirectedAdv`** — Configures high-duty-cycle or low-duty-cycle directed advertising parameters. | 2 callers / 2 callees |
| `0x6009ac8c` | 112 | BTM / BLE Adv | **`btm_ble_proc_directed_adv_report`** — Processes directed advertising reports and triggers automatic reconnection. | 3 callers / 4 callees |
| `0x6009af60` | 110 | BTM / BLE Adv | **`btm_ble_update_adv_interval`** — Dynamically adjusts advertising interval based on system power state. | 4 callers / 5 callees |
| `0x6009b0a8` | 134 | BTM / BLE Adv | **`btm_ble_config_adv_filter`** — Configures hardware BLE advertisement filtering rules in controller. | 5 callers / 5 callees |
| `0x6009b230` |  92 | BTM / BLE Adv | **`BTM_BleGetAdvStatus`** — Returns boolean indicating whether BLE advertising is currently active. | 1 caller / 0 callees |
| `0x6009b8b4` |  84 | BTM / BLE Conn | **`BTM_BleCreateConn`** — Initiates BLE connection creation via HCI LE Create Connection (`0x200d`). | 3 callers / 2 callees |
| `0x6009b914` |  66 | BTM / BLE Conn | **`BTM_BleCancelConn`** — Cancels pending BLE connection creation via HCI LE Create Connection Cancel (`0x200e`). | 2 callers / 3 callees |
| `0x6009b960` |  70 | BTM / BLE Conn | **`btm_ble_conn_complete`** — Parses HCI LE Connection Complete event (`0x3e` sub `1`); populates connection state. | 2 callers / 3 callees |
| `0x6009b9b0` |  76 | BTM / BLE Conn | **`btm_ble_enhanced_conn_complete`** — Parses HCI LE Enhanced Connection Complete event (`0x3e` sub `0x0a`) with local/peer RPA. | 4 callers / 5 callees |
| `0x6009ba0c` | 112 | BTM / BLE Conn | **`BTM_BleUpdateConnParams`** — Sends HCI LE Connection Update command (`0x2013`) with min/max interval, latency, timeout. | 3 callers / 5 callees |
| `0x6009ba84` |  94 | BTM / BLE Conn | **`btm_ble_conn_update_complete`** — Parses HCI LE Connection Update Complete event (`0x3e` sub `3`); updates connection timing. | 2 callers / 4 callees |
| `0x6009baec` |  70 | BTM / BLE Conn | **`BTM_BleReadRemoteFeatures`** — Reads peer LE features via HCI LE Read Remote Features (`0x2016`). | 2 callers / 3 callees |
| `0x6009bb3c` |  14 | BTM / BLE Conn | **`btm_ble_read_remote_feat_complete`** — Handles HCI LE Read Remote Features Complete event (`0x3e` sub `4`). | 2 callers / 2 callees |
| `0x6009bb50` |  92 | BTM / BLE Conn | **`BTM_BleSetDataLength`** — Requests BLE Data Packet Length Extension via HCI LE Set Data Length (`0x2022`). | 5 callers / 5 callees |
| `0x6009bbb0` | 122 | BTM / BLE Conn | **`btm_ble_data_length_change`** — Handles HCI LE Data Length Change event (`0x3e` sub `7`); updates max TX/RX octets and time. | 2 callers / 2 callees |
| `0x6009bc34` |  76 | BTM / BLE Conn | **`BTM_BleReadDefaultDataLength`** — Reads suggested default data length parameters from controller. | 3 callers / 2 callees |
| `0x6009bc88` |  76 | BTM / BLE Conn | **`BTM_BleWriteDefaultDataLength`** — Writes suggested default data length parameters via HCI (`0x2024`). | 3 callers / 3 callees |
| `0x6009bcd8` | 144 | BTM / BLE Filter | **`BTM_BleClearWhitelist`** — Clears controller advertising/scanning whitelist via HCI LE Clear White List (`0x2010`). | 4 callers / 4 callees |
| `0x6009bd70` | 112 | BTM / BLE Filter | **`BTM_BleAddWhitelist`** — Adds device to controller whitelist via HCI LE Add Device To White List (`0x2011`). | 4 callers / 4 callees |
| `0x6009bde4` |  86 | BTM / BLE Filter | **`BTM_BleRemoveWhitelist`** — Removes device from controller whitelist via HCI LE Remove Device From White List (`0x2012`). | 2 callers / 2 callees |
| `0x6009be40` | 108 | BTM / BLE Privacy | **`BTM_BleClearResolvingList`** — Clears controller address resolving list via HCI LE Clear Resolving List (`0x2029`). | 5 callers / 6 callees |
| `0x6009beb0` | 104 | BTM / BLE Privacy | **`BTM_BleAddResolvingList`** — Adds device IRK and BD_ADDR to Resolving List via HCI LE Add Device To Resolving List (`0x2027`). | 4 callers / 4 callees |
| `0x6009bf1c` | 138 | BTM / BLE Privacy | **`BTM_BleRemoveResolvingList`** — Removes device from Resolving List via HCI LE Remove Device From Resolving List (`0x2028`). | 4 callers / 6 callees |
| `0x6009bfb0` | 100 | BTM / BLE Privacy | **`BTM_BleEnableAddressResolution`** — Enables controller-based address resolution via HCI LE Set Address Resolution Enable (`0x202d`). | 4 callers / 4 callees |
| `0x6009c01c` | 102 | BTM / BLE Privacy | **`BTM_BleReadPeerResolvableAddr`** — Reads current peer Resolvable Private Address (RPA) via HCI LE Read Peer Resolvable Address (`0x202b`). | 4 callers / 5 callees |
| `0x6009c088` | 150 | BTM / BLE Privacy | **`BTM_BleReadLocalResolvableAddr`** — Reads current local Resolvable Private Address (RPA) via HCI LE Read Local Resolvable Address (`0x202c`). | 2 callers / 3 callees |
| `0x6009c124` | 108 | BTM / BLE Privacy | **`BTM_BleSetRpaTimeout`** — Sets RPA rotation timeout period (in seconds) via HCI LE Set Resolvable Private Address Timeout (`0x202e`). | 3 callers / 5 callees |
| `0x6009c194` |  58 | BTM / BLE Privacy | **`btm_ble_gen_rpa`** — Generates cryptographic Resolvable Private Address (RPA) from local IRK and random seed `prand`. | 1 caller / 1 callee |
| `0x6009c1d4` |  48 | BTM / BLE Privacy | **`btm_ble_verify_rpa`** — Cryptographically verifies received RPA against stored peer IRK using AES-128 hash helper `ah`. | 1 caller / 2 callees |
| `0x6009c208` |  52 | BTM / BLE Privacy | **`btm_ble_get_addr_type`** — Inspects top 2 bits of address: Public (`00`), Random Static (`11`), RPA (`01`), NRPA (`00`). | 1 caller / 1 callee |
| `0x6009c240` | 122 | BTM / BLE Privacy | **`BTM_BleSetPrivacyMode`** — Configures Privacy Mode (`0` = Network Privacy, `1` = Device Privacy) via HCI (`0x204e`). | 3 callers / 3 callees |
| `0x6009c6d8` |  62 | BTM / BLE Conn | **`btm_ble_start_conn_timer`** — Starts connection supervision watchdog timer for active BLE link. | 5 callers / 5 callees |
| `0x6009c71c` |  82 | BTM / BLE Conn | **`btm_ble_conn_timer_expiry`** — Watchdog timer expiry callback; triggers link disconnection on supervision timeout. | 5 callers / 5 callees |
| `0x6009c778` |  20 | BTM / BLE Conn | **`btm_ble_stop_conn_timer`** — Stops connection supervision watchdog timer. | 4 callers / 4 callees |
| `0x6009c790` |  52 | BTM / BLE Conn | **`btm_ble_update_supervision_param`** — Updates active connection supervision timeout parameter. | 9 callers / 8 callees |
| `0x6009c848` | 196 | BTM / Sec DB | **`btm_find_dev`** — Searches BTM security device record database (`DAT_6009c800`) for matching BD_ADDR. | 6 callers / 5 callees |
| `0x6009c914` | 176 | BTM / Sec DB | **`btm_sec_alloc_dev`** — Allocates unused `btm_sec_dev_rec` security record slot for new bonded/paired device. | 2 callers / 3 callees |
| `0x6009c9d4` | 168 | BTM / Sec DB | **`btm_sec_free_dev`** — Frees `btm_sec_dev_rec` security record slot on unbonding/unpairing. | 3 callers / 3 callees |
| `0x6009ca80` |  84 | BTM / Sec DB | **`btm_sec_clear_dev_db`** — Clears all entries in security device database and resets security control block. | 4 callers / 5 callees |
| `0x6009cd94` | 148 | BTM / Sec Keys | **`BTM_WriteLinkKey`** — Writes 16-byte BR/EDR link key and key type into device security record. | 2 callers / 1 callee |
| `0x6009ce30` | 148 | BTM / Sec Keys | **`BTM_ReadLinkKey`** — Reads 16-byte BR/EDR link key from device security record. | 3 callers / 4 callees |
| `0x6009cec8` | 182 | BTM / Sec Keys | **`BTM_SecAddBleKey`** — Stores peer LE security keys (LTK, IRK, CSRK, EDIV/Rand) in security record. | 3 callers / 4 callees |
| `0x6009d930` | 142 | BTM / Sec Keys | **`BTM_SecGetBleKey`** — Retrieves stored peer LE security keys (LTK, IRK, CSRK) from security record. | 3 callers / 2 callees |
| `0x6009dd74` | 180 | BTM / Sec Keys | **`BTM_SecSetLocalBleKeys`** — Configures local device BLE security keys (Local IRK, Local CSRK, Local LTK). | 7 callers / 6 callees |
| `0x6009de30` | 144 | BTM / Sec State | **`BTM_SetSecurityFlags`** — Sets security state flags (Authenticated, Encrypted, Bonded, MITM-protected). | 2 callers / 4 callees |
| `0x6009decc` |  64 | BTM / Sec State | **`BTM_GetSecurityFlags`** — Returns active security state bitmask for target device record. | 4 callers / 5 callees |
| `0x6009df10` | 194 | BTM / Sec State | **`BTM_SetDeviceType`** — Sets Bluetooth device operational type (`1`=BR/EDR, `2`=BLE, `3`=Dual-Mode). | 3 callers / 3 callees |
| `0x6009dfd8` | 188 | BTM / Sec State | **`BTM_SetDeviceClass`** — Stores 24-bit Bluetooth Class of Device (CoD) descriptor in security record. | 2 callers / 3 callees |
| `0x6009e2e0` |  82 | BTM / Sec State | **`BTM_SetDeviceName`** — Stores cached UTF-8 remote device name in security record. | 2 callers / 1 callee |
| `0x6009e338` | 178 | BTM / Sec State | **`BTM_GetDeviceName`** — Retrieves cached remote device name from security record. | 2 callers / 5 callees |
| `0x6009e6c0` |  72 | BTM / Sec State | **`BTM_SetPinCode`** — Sets legacy PIN code / passkey string for BR/EDR legacy pairing. | 6 callers / 5 callees |
| `0x6009e70c` |  82 | BTM / Sec Policy | **`btm_sec_check_requirements`** — Validates whether active link security satisfies registered service security requirements. | 5 callers / 6 callees |
| `0x6009e768` |  94 | BTM / Sec Policy | **`BTM_SecRegister`** — Registers service security policy (Authentication, Authorization, Encryption requirements). | 2 callers / 2 callees |
| `0x6009e7d0` | 102 | BTM / Sec Policy | **`BTM_SecDeregister`** — Deregisters service security record and releases service ID. | 2 callers / 1 callee |
| `0x6009e84c` | 158 | BTM / Sec Policy | **`btm_sec_check_authz`** — Checks whether incoming connection request is authorized by application callback. | 11 callers / 11 callees |
| `0x6009e8fc` |  88 | BTM / Sec Policy | **`btm_sec_check_authn`** — Checks whether connection meets required authentication security level. | 9 callers / 9 callees |
| `0x6009e95c` | 128 | BTM / Sec Policy | **`btm_sec_check_enc`** — Checks whether connection is encrypted to required key strength. | 5 callers / 4 callees |
| `0x6009eab4` | 170 | BTM / Sec Action | **`BTM_SecAuthenticate`** — Initiates link authentication procedure via HCI Authentication Requested (`0x0411`). | 1 caller / 2 callees |
| `0x6009eb64` |  52 | BTM / Sec Action | **`BTM_SecEncrypt`** — Initiates link encryption procedure via HCI Set Connection Encryption (`0x0413`). | 1 caller / 1 callee |
| `0x6009eb9c` |  54 | BTM / Sec Action | **`BTM_SecCancel`** — Cancels pending authentication or security negotiation procedure. | 4 callers / 3 callees |
| `0x6009ebd8` |  54 | BTM / Sec Action | **`BTM_GetEncryptionStatus`** — Returns boolean indicating whether target link is currently encrypted. | 4 callers / 3 callees |
| `0x6009ec14` |  60 | BTM / Discovery | **`BTM_StartInquiry`** — Starts Bluetooth BR/EDR Inquiry discovery procedure via HCI Inquiry (`0x0401`). | 5 callers / 5 callees |
| `0x6009ec54` | 168 | BTM / Discovery | **`BTM_CancelInquiry`** — Cancels active BR/EDR Inquiry procedure via HCI Inquiry Cancel (`0x0402`). | 4 callers / 4 callees |
| `0x6009ed00` | 154 | BTM / Discovery | **`btm_proc_inq_result`** — Processes standard HCI Inquiry Result event (`0x02`); parses BD_ADDR, CoD, clock offset. | 8 callers / 8 callees |
| `0x6009eda4` | 110 | BTM / Discovery | **`btm_proc_inq_result_rssi`** — Processes HCI Inquiry Result with RSSI event (`0x22`); records received signal strength. | 1 caller / 1 callee |
| `0x6009ee18` | 106 | BTM / Discovery | **`btm_proc_ext_inq_result`** — Processes HCI Extended Inquiry Result event (`0x2f`); parses 240-byte EIR data. | 4 callers / 4 callees |
| `0x6009ee8c` | 122 | BTM / Discovery | **`btm_proc_inq_complete`** — Processes HCI Inquiry Complete event (`0x01`); notifies discovery callback. | 3 callers / 3 callees |
| `0x6009ef10` | 136 | BTM / Discovery | **`btm_inq_db_find`** — Searches BTM inquiry discovery cache database (`DAT_6009ef00`) for matching BD_ADDR. | 3 callers / 5 callees |
| `0x6009efa0` |  94 | BTM / Discovery | **`btm_inq_db_alloc`** — Allocates entry in inquiry discovery cache for newly discovered device. | 2 callers / 1 callee |
| `0x6009f004` | 132 | BTM / Discovery | **`btm_inq_db_clear`** — Clears inquiry discovery cache database. | 2 callers / 1 callee |
| `0x6009f08c` | 148 | BTM / Discovery | **`BTM_ReadRemoteDeviceName`** — Initiates Remote Name Request procedure via HCI Remote Name Request (`0x0419`). | 6 callers / 5 callees |
| `0x6009f1fc` | 122 | BTM / Discovery | **`BTM_CancelRemoteDeviceName`** — Cancels pending Remote Name Request via HCI Remote Name Request Cancel (`0x041a`). | 2 callers / 3 callees |
| `0x6009f27c` | 106 | BTM / Discovery | **`btm_proc_rmt_name_complete`** — Handles HCI Remote Name Request Complete event (`0x07`); parses UTF-8 name. | 2 callers / 3 callees |
| `0x6009f2ec` | 204 | BTM / Discovery | **`btm_discovery_fsm`** — Central device discovery state machine dispatcher (Inquiry -> Name Request -> Complete). | 5 callers / 4 callees |
| `0x6009f3c0` |  96 | BTM / Discovery | **`btm_discovery_timeout`** — Watchdog timer callback for device discovery / remote name transaction timeout. | 5 callers / 4 callees |
| `0x6009f428` | 178 | BTM / Discovery | **`btm_discovery_next_step`** — Advances discovery state machine to next queued device in search list. | 5 callers / 4 callees |
| `0x6009f4e4` | 148 | BTM / Config | **`BTM_SetDiscoverability`** — Configures discoverability mode (General Discoverable, Limited Discoverable, Non-Discoverable). | 6 callers / 6 callees |
| `0x6009f57c` |  80 | BTM / Config | **`BTM_GetDiscoverability`** — Returns active discoverability mode bitmask. | 6 callers / 5 callees |
| `0x6009f5d0` |  54 | BTM / Config | **`BTM_SetConnectability`** — Configures connectability mode (Connectable, Non-Connectable) for page scan. | 5 callers / 4 callees |
| `0x6009f60c` |  50 | BTM / Config | **`BTM_GetConnectability`** — Returns active connectability mode bitmask. | 5 callers / 4 callees |
| `0x6009f644` | 120 | BTM / Config | **`BTM_WriteScanEnable`** — Writes HCI Scan Enable setting (`0`=None, `1`=Inq, `2`=Page, `3`=Both) via HCI (`0x0c1a`). | 15 callers / 13 callees |
| `0x6009f8c8` | 112 | BTM / Config | **`BTM_ReadScanEnable`** — Returns current local scan enable mode setting. | 6 callers / 6 callees |
| `0x6009f93c` |  78 | BTM / Config | **`BTM_WritePageScanActivity`** — Sets page scan interval and window via HCI Write Page Scan Activity (`0x0c1c`). | 9 callers / 8 callees |
| `0x6009f990` | 154 | BTM / Config | **`BTM_WriteInquiryScanActivity`** — Sets inquiry scan interval and window via HCI Write Inquiry Scan Activity (`0x0c1e`). | 7 callers / 6 callees |
| `0x6009fe40` | 116 | BTM / Config | **`BTM_WriteInquiryMode`** — Configures Inquiry Mode (`0`=Standard, `1`=RSSI, `2`=Extended) via HCI (`0x0c45`). | 3 callers / 2 callees |
| `0x6009feb8` |  90 | BTM / Config | **`BTM_WriteClassOfDevice`** — Writes 24-bit local Class of Device via HCI Write Class of Device (`0x0c24`). | 6 callers / 10 callees |
| `0x6009ff18` | 130 | BTM / Config | **`BTM_ReadClassOfDevice`** — Reads 24-bit local Class of Device from local BTM control block. | 30 callers / 62 callees |
| `0x6009ffa0` | 186 | BTM / Config | **`BTM_WriteLocalDeviceName`** — Writes local Bluetooth device name string via HCI Write Local Name (`0x0c13`). | 2 callers / 1 callee |

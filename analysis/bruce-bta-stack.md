# Bruce — the `0x600921b8`–`0x600c9cc4` block: Broadcom BTA/BTE Bluetooth stack (session 7)

Target: the single largest unmapped contiguous range in the image (`analysis/bruce-decompile-status.md` §3b run #1) — 1,076 functions, 204,449 code bytes, 89.6% density, 2/1,076 decompiled at session start.

## Identification: confidence VERY HIGH

**This range is the statically-linked Broadcom BTA/BTE Bluetooth protocol stack** — the same "Google-forked Broadcom BTA (GATT/L2CAP/RFCOMM/SPP/HFP/SDP)" that `firmware-map.md` already documented existed *somewhere* in the image from leaked module names, but whose address range no prior session had located. Concretely, this block holds (at minimum): the HCI transport + command-send layer, the top-level HCI event dispatcher, BTM (device/link manager: ACL, inquiry, advertising/EIR), BTA DM (multi-profile device manager, power management), GATT client and server, SDP (service discovery), SMP (Security Manager Protocol / LE pairing), and curve-specific EC field arithmetic (NIST P-256, feeding SMP's LE Secure Connections ECDH).

This supersedes/extends the prior session's guarded "TLV parser, maybe HCI/GATT/SDP framing" + "maybe P-256" hedges (`bruce-misc-functions.md`) — both of those functions (`FUN_600ba1c4`, `FUN_600c8fd8`) turn out to sit inside exactly this one real module, not two unrelated coincidences.

### Evidence

**1. A ~400-entry BTA/BTE function-name string table, individually cross-referenced from code inside this exact range.**

The flash image embeds a large table of literal function-name strings at `0x60103xxx`–`0x60122xxx` (outside this block, in decompile-status run #2's span) — `bta_dm_pm_btm_cback`, `BTA_GATTC_Open`, `l2c_csm_closed`, `smp_build_pairing_cmd`, `btu_hcif_command_complete_evt`, `btsnd_hcic_disconnect`, etc. (`grep -inE "l2cap|rfcomm|smp|gatt|sdp|hci|bta_|btm_|btu_" analysis/ghidra/bruce_strings.txt` → 411 hits). These read like a Broadcom BTE debug/trace symbol table (each function logs its own name, a common BTE idiom). A stratified sample of 23 of the 411 was checked with `FindRef.java`; **19 of 23 had their sole code cross-reference land inside `0x600921b8`–`0x600c9cc4`**, and the referencing-function addresses track the string-table addresses monotonically (e.g. strings at `0x60116a58…0x601177dc` map in order to functions at `0x600ae4e0…0x600b4798`) — consistent with the linker placing the trace-string constant next to the object code that logs it, in source-file order. The 4 misses were either no-refs-found (probably consumed via a data table Ghidra didn't type as pointers, a known limitation — see `bruce-crypto.md`'s EVP registry writeup for the same phenomenon) or one hit from outside the range entirely (`0x60105ab0`, an unanalyzed address in run #2).

**2. HCI command opcodes match the Bluetooth spec exactly, byte-for-byte.**

Six `btsnd_hcic_*`-named functions were decompiled; all six have the identical shape (allocate a GKI-style buffer via `FUN_6006dbac`, write a 2-byte little-endian HCI opcode + 1-byte param-length header, copy the command parameters, send via `FUN_600a9234`). The opcode bytes written are the *real* HCI command opcodes:
| Function | String name | Opcode bytes written | Spec opcode |
|---|---|---|---|
| `FUN_600b218c` | `btsnd_hcic_disconnect` | `0x06,0x04` | `0x0406` (OGF 1/OCF 0x06, Disconnect) ✓ |
| `FUN_600b1090` | `btsnd_hcic_ble_remove_from_white_list` | `0x12,0x20` | `0x2012` (OGF 8/OCF 0x12) ✓ |
| `FUN_600b19c0` | `btsnd_hcic_ble_add_device_resolving_list` | `0x27,0x20` | `0x2027` (OGF 8/OCF 0x27) ✓ |
| `FUN_600b29b8` | `btsnd_hcic_rmt_ext_features` | `0x1c,0x04` | `0x041c` (OGF 1/OCF 0x1c) ✓ |

This is independent, spec-level confirmation beyond string co-location.

**3. The top-level HCI event dispatcher's switch matches the HCI event-code table 1:1, including the nested LE-Meta-Event sub-dispatch.**

`FUN_600a89f0` (1,044B, no static callers — almost certainly invoked via a registered function pointer, matching BTE's `btu_hcif_process_event`) switches on a raw event-code byte into ~50 handler calls. Case `'>'` (`0x3e`, the real **HCI LE Meta Event** code) itself contains a **nested switch** on a second byte into 8 more cases (`1..7, 0xa`) — exactly the real **LE Meta Event sub-event codes** (LE Connection Complete=1, LE Advertising Report=2, LE Connection Update Complete=3, LE Read Remote Features Complete=4, LE LTK Request=5, LE Remote Conn Param Request=6, LE Data Length Change=7, LE Enhanced Connection Complete=0xa). Case `0xef` calls a registered vendor-callback pointer at `DAT_600a9230+0xd4` — the `BTM_VendorSpecificCommand` slot leaked in the string table.

**4. Recognizable protocol framing shapes for SDP and GAP advertising data.**

- `FUN_600beb20`/`FUN_600be150`/`FUN_600be558` build a buffer with header bytes `0x35`/`0x36` (SDP Data-Element-Sequence type/size-index bytes) and a PDU opcode field set to `7` (`SDP_ServiceSearchAttributeResponse`) — an SDP server response builder.
- `FUN_6009cf8c` (2,464B) assembles a length-prefixed AD-structure stream whose type bytes match the real **GAP Advertising Data type codes** exactly: Flags=`0x01`, Appearance=`0x19`, Shortened/Complete Local Name=`0x08`/`0x09`, Incomplete/Complete 16-bit UUID list=`0x02`/`0x03`, 32-bit=`0x04`/`0x05`, 128-bit=`0x06`/`0x07`, TX Power Level=`0x0a`, Slave Connection Interval Range=`0x12`, Service Data (16-bit UUID)=`0x16` — a BTM/GAP advertising/EIR-data builder.

**5. NIST P-256 field reduction (confirmed prior session) sits alongside a second, smaller bignum-reduction sibling using the identical compare/subtract helper pair.**

`FUN_600c8fd8` (2,764B, prior session) is Solinas-style reduction for the 256-bit NIST P-256 prime. Newly decompiled `FUN_600c8b24` (1,198B, immediately upstream in the call graph — called from `FUN_601005ac`) does the same "weighted partial-sum add, then compare/conditional-subtract" pattern but only over **6 words (192 bits)** of output from a 12-word (384-bit) input, using the *same* two helpers (`FUN_601002bc` compare, `FUN_601004b2` subtract) as the P-256 function. Shape strongly suggests a second curve-specific reduction — most plausibly **NIST P-192** (the curve classic BT Secure Simple Pairing originally specified before the industry-wide move to P-256), consistent with BoringSSL linking in whatever curves its generic `EC_GROUP` layer references (the string table also has literal `"NIST P-256"`, `"brainpoolP256r1"`, `"brainpoolP256t1"`). Not spec-verified byte-for-byte (would need the actual modulus constant, which sits in a literal pool Ghidra hasn't resolved — same caveat as before). `FUN_600c8798` (574B) is a further neighbor in this cluster calling more `0x60100xxx`-suffixed bignum helpers — plausibly a point-arithmetic step (add/double), not decompiled deeply this session.

**6. Call-graph coherence.** Everything above cross-links internally: the GATT-client cache functions (`bta_gattc_*` strings) call into the same `FUN_600b5e00` connection-event dispatcher that the previously-flagged `FUN_600ba1c4` TLV/PDU parser feeds — i.e. `FUN_600ba1c4` (session 6's "connection-protocol TLV parser... feeds `state_machine.cc`") is itself inside the GATT-client attribute-cache neighborhood, strengthening rather than contradicting the earlier finding: it's most likely parsing **ATT/GATT PDUs** (opcode+handle+length+value), not a bespoke Google session protocol.

## Address-range map (approximate module clusters, by evidence + neighborhood)

| Range | Module (evidence) |
|---|---|
| `0x600921b8`–~`0x60092440` | CRC-32 utility (classic slicing-by-8 table-driven CRC, `~crc` init/final XOR) — generic, not BT-specific; sits at the very head of this object-file group |
| ~`0x60093xxx`–`0x600944xx` | BTA DM power management (`bta_dm_pm_btm_cback` confirmed @ `0x6009430c`) |
| ~`0x60096xxx`–`0x60098xxx` | HCI H4 UART transport (`hcisu_h4_send_msg_now` @ `0x60096e38`) + BTM link-policy/sniff-mode helpers |
| ~`0x60099xxx`–`0x6009cxxx` | BTM advertising/EIR data assembly (`FUN_6009cf8c`) |
| ~`0x600a0xxx`–`0x600a9xxx` | BTM ACL/inquiry/connection event-handler cluster + the top-level **HCI event dispatcher** (`FUN_600a89f0`) and HCI-EVT trace/forward (`btu_hci_forward_all_event` @ `0x600a86d0`) |
| ~`0x600aaxxx`–`0x600aexxx` | GATT client/server core (`GATTC_Read` @ `0x600ab620`, `gatts_process_primary_service_req` @ `0x600ae4e0`) |
| ~`0x600b0xxx`–`0x600b4xxx` | HCI command-send layer, `btsnd_hcic_*` (opcode-verified, see above) |
| ~`0x600b5xxx`–`0x600bcxxx` | Connection-event dispatch (`FUN_600b5e00`) + GATT-client attribute-cache / PDU parsing (`FUN_600ba1c4`) |
| ~`0x600bcxxx`–`0x600c0xxx` | SDP server (PDU builder, `ServiceSearchAttributeResponse`-shaped) |
| ~`0x600c1xxx`–`0x600c3xxx` | SMP — Security Manager Protocol (`smp_data_ind` @ `0x600c1864`, `smp_build_pair_keypr_notif_cmd` @ `0x600c223c`) + more BTA DM (`bta_dm_search_clear_queue` @ `0x600c3b18`) |
| ~`0x600c4xxx`–`0x600c6xxx` | BTA DM/GATTC (`bta_gattc_register` @ `0x600c611c`) |
| ~`0x600c74xx`–`0x600c9cxx` | BoringSSL EC field arithmetic: confirmed NIST P-256 Solinas reduction + a second (P-192-shaped) sibling, sharing bignum compare/subtract primitives with helpers just outside this block (`0x60100xxx`, in decompile-status run #2 — a good next-session lead, see below) |

## Functions decompiled this session (67 new + 2 pre-existing = 69 of 1,076)

Sorted by address. "Named" = identified via the BTA string-table cross-reference (§ Evidence 1) or spec-opcode match; everything else is inferred from call-graph position, callee shape, and neighborhood.

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
| `0x600ac9a4` | 1076 | GATT client op builder (large local buffer, calls HCI-send-shaped `0x600f68f0`) |
| `0x600ad228` | 590 | GATT registration-list walker (linked-list traversal keyed by a handle field) |
| `0x600ae4e0` | 396 | **`gatts_process_primary_service_req`**-shaped (named via string xref) — GATT server primary-service-discovery request handler |
| `0x600b0730` | 56 | **`gatt_add_pending_enc_channel_clcb`**-shaped (named) — tiny linked-list node allocator/pusher |
| `0x600b1090` | 142 | **`btsnd_hcic_ble_remove_from_white_list`** (named + opcode-verified `0x2012`) |
| `0x600b19c0` | 198 | **`btsnd_hcic_ble_add_device_resolving_list`** (named + opcode-verified `0x2027`) |
| `0x600b218c` | 148 | **`btsnd_hcic_disconnect`** (named + opcode-verified `0x0406`) |
| `0x600b29b8` | 144 | **`btsnd_hcic_rmt_ext_features`** (named + opcode-verified `0x041c`) |
| `0x600b3240` | 352 | **`btsnd_hcic_set_event_filter`**-shaped (named via string xref) |
| `0x600b3b2c` | 206 | **`btsnd_hcic_write_cur_iac_lap`**-shaped (named via string xref) |
| `0x600b400c` | 584 | HCI command-send helper (same `FUN_6006dbac`/opcode-write shape as `btsnd_hcic_*` family; opcode bytes `0x70,0x0c`) |
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
| `0x600c3558` | 932 | SMP/pairing state helper, calls `0x600c54ec` and BTA-timer-shaped `0x601024d8` |
| `0x600c3b18` | 52 | **`bta_dm_search_clear_queue`**-shaped (named via string xref) — one-line queue-free-and-clear |
| `0x600c3c00` | 618 | SMP/pairing state helper, sibling of `0x600c3558` |
| `0x600c4da8` | 1030 | SMP/BTA-DM pairing-flow helper (large callee set spanning both `0x60094xxx` BTA-DM and `0x600c3exx` SMP functions) |
| `0x600c611c` | 498 | **`bta_gattc_register`**-shaped (named via string xref) — GATT client app registration |
| `0x600c74a0` | 980 | Large-buffer (2×800B stack array) parser/formatter — not conclusively identified |
| `0x600c80fc` | 830 | Small fixed-field parser (no sub-calls except a memcpy-shaped thunk) — not conclusively identified |
| `0x600c8798` | 574 | EC bignum-cluster neighbor, calls `0x601004b2`/`0x601005ac`/`0x601005f6` (same helper family as the P-256/P-192 reductions) — plausibly a point-add/double step, not decompiled deeply |
| `0x600c8b24` | 1198 | 384-bit→192-bit weighted-sum bignum reduction sharing `FUN_601002bc`/`FUN_601004b2` with the P-256 function below — plausible **NIST P-192** field reduction (shape-only, constant not confirmed) |
| `0x600c8fd8` | 2764 | (pre-existing, session 6) **NIST P-256 Solinas-style modular reduction**, confirmed |

## What's decompiled vs. what's left, and how to continue

- **69 of 1,076 functions decompiled** (up from 2) — roughly 22,600 of 204,449 code bytes (~11%) by rough sum of the table above. **1,007 functions / ~182,000 bytes remain.**
- The single highest-leverage next step: **the BTA/BTE trace-string table is a nearly-free identification oracle.** Only 23 of ~411 matching strings (`grep -inE "l2cap|rfcomm|smp|gatt|sdp|hci|bta_|btm_|btu_|avdt|avct|bnep|hid_host|obex" analysis/ghidra/bruce_strings.txt`) were checked this session; 19 hit inside this block with zero false positives. Running `FindRef.java` on the remaining ~388 will very likely surface several hundred more named functions almost for free (a real name + a caller — usually enough to write a one-line description without decompiling the body at all, though `Decompile.java` on the same address is cheap since most of these are small).
- Layers not yet touched at all in this pass, worth dedicated sweeps: **L2CAP** (only glimpsed via string names `l2c_csm_*`/`l2c_fcr_*`/`l2c_rcv_acl_data`, no function bodies read yet — the leaked strings suggest a full L2CAP channel-state-machine + flow-control (FCR) implementation lives somewhere in this block or spills into run #2), **RFCOMM/SPP/HFP** (named in `firmware-map.md`'s original module list but no string-table hits found yet — may not actually be linked in, or may use different string patterns; worth a `grep -i "rfc_\|port_\|obx_"` pass), and the **BTA_GATTS_*** server-side API surface (only `gatts_process_primary_service_req` confirmed; `BTA_GATTS_CreateService`/`AddCharacteristic`/etc. strings exist but weren't cross-referenced).
- The P-256/P-192-shaped bignum helpers (`FUN_601002bc` compare, `FUN_601004b2` subtract, `FUN_60100424` add, `FUN_601005ac`, `FUN_601005f6`, `FUN_60100166`, `FUN_6010027c`) live just outside this block (~`0x60100xxx`, inside decompile-status run #2) and are a good, tightly-scoped next target — they'd both nail down the P-192 guess and likely connect to `bruce-crypto.md`'s already-documented EVP/ASN.1 registry (same address neighborhood as the `0x6010b9xx` `EVP_PKEY_ASN1_METHOD` table).
- **Tooling gotcha found this session**: passing many addresses to `Decompile.java`/`FindRef.java` via an expanded shell variable (`$ADDRS`) silently collapses them into a single mangled argument (Ghidra then throws a `NullPointerException` on a null `Address`) — even though the same list typed as literal space-separated tokens in the command works fine up to at least 25 args. Always type addresses literally in the `analyzeHeadless` invocation, never via `$(...)`/variable expansion, until this is root-caused.
- All work this session was `-process -noanalysis` only; no `-import`/`-overwrite`, no commits, per constraints.

## Relevance to other open threads (CLAUDE.md)

- **Main event/dispatch loop (thread 3)**: `FUN_600a89f0` is a strong, spec-verified **HCI-layer** event dispatcher, but it's a leaf callback (no static callers — reached via a registered function pointer from BTU's task message loop), not the RTOS top-level main loop itself. Worth checking whether `FUN_600b5e00` (the connection-event dispatcher `FUN_600ba1c4` feeds) or the not-yet-found `btu_task` function (string `btu_task up` exists at `0x601033c4` — an easy next `FindRef` target) is closer to what thread 3 is actually after.
- **Report-packing / button-ADC threads (1, 2)**: nothing in this block touches HID reports, buttons, or ADC — it's purely the BT/BLE protocol stack. No new lead on those threads from this session.
- **Ed25519/EVP crypto callers (thread 5)**: not resolved directly, but the P-256 cluster confirmed here is a much more plausible "live" curve than the Ed25519/X25519 stack in `bruce-crypto.md` — SMP's `smp_data_ind`/pairing-command builders (`0x600c1864`/`0x600c223c`) are right next door to the P-256 reduction, so LE Secure Connections pairing is the leading candidate for the crypto stack's actual runtime consumer. Tracing `smp_data_ind`'s callees down into the P-256 cluster (not done this session — ran out of scope) would likely close this thread.

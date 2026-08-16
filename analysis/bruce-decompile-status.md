# Bruce — full-decompile tracking status

Data-driven status doc for the "decompile all of `bruce` to source-reconstruction quality" effort. Regenerate the numbers here whenever `bruce_functions.csv`, `bruce_srcmap.csv`, or `analysis/decomp/` change materially — don't hand-edit stale tables into new prose, just re-run the join described in [Methodology](#methodology) below.

**Snapshot: 2026-08-16 01:21 EDT (session ~13 regeneration).** Full refresh of every table in the doc, built on top of sessions 9–13's work since the session-8 baseline: all 52 `bcm.c` functions (BoringSSL BIGNUM/EC, not a Broadcom BT driver — see CLAUDE.md's known-traps note), the button/ADC/report-packing investigation (sessions 8–12, `bruce-io-paths.md`), and continued BTA/BTE stack decompilation. `analysis/decomp/` **was growing live while this snapshot was taken** — a first pass mid-session read 677 files, a later pass 90 seconds later read 767 — consistent with a concurrent session actively decompiling, per this task's own heads-up. All tables below are built from **one single consistent read** taken at 767 files (`analysis/decomp/`), joined against the unchanged `bruce_functions.csv` (4,995 rows) and `bruce_srcmap.csv` (448 rows, 139 src files — no re-import happened, same as every prior snapshot). As always: treat every count below as a lower bound as of the snapshot instant, not a hard current total — re-run before trusting exact numbers for planning.

**Session 15 patch (2026-08-16, on top of this snapshot):** hand-applied §2/§3a updates only, for `tasn_dec.c`/`adapter.cc`/`keys.cc` going to fully-decompiled (see the inline patch notes in §2 and §3a) — not a full re-join, so §1/§1a/§3b/§4's top-line numbers below still reflect the session-13 snapshot and are correspondingly stale on top of it (they don't yet reflect these 3 files, sessions 14's work, or any other concurrent session's progress). Re-run the full methodology before trusting exact top-line percentages.

Unlike the session-8→9 patch (a hand-adjustment of a few numbers), this is a full mechanical re-join from scratch, so there's no separate "patch" section this time — every number below, including the BTA/BTE block figures in §1a, comes from the same strict address-join against the current `analysis/decomp/` state described in [Methodology](#methodology). Note this means the BTA/BTE-block decompiled count here (**410 of 1,076**) is computed the same way as last time's self-consistent 319, not compared against `bruce-bta-stack.md`'s own self-reported running count (328, last updated at that doc's session 8 — stale relative to this snapshot, since sessions 9–13's concurrent BTA work hadn't been written back into that doc's prose as of this pass). See the §1a footnote for that discrepancy.

## 1. Top-line stats

| Metric | Functions | % of 4,995 | Bytes | % of 660,570 |
|---|---:|---:|---:|---:|
| **Total functions (census)** | 4,995 | 100% | 660,570 | 100% |
| **Attributed** (leaked `__FILE__` → 139 src files) | 448 | 8.97% | 97,450 | 14.75% |
| **Decompiled** (`analysis/decomp/*.c`, matched to a census address) | 634 | 12.69% | 201,935 | 30.57% |
| **Attributed ∪ Decompiled** (understood in *some* way) | 976 | 19.54% | 273,139 | **41.35%** |
| **Totally unknown** (no attribution, no decompile) | 4,019 | 80.46% | 387,431 | **58.65%** |

Size-weighted (bytes) is still the more honest progress metric than function-count, for the same reason as before (a handful of huge functions dominate the byte total disproportionately to their count). **Bottom line: ~41% of the binary's code by size is now understood in some way, up from ~35% at the session-8 snapshot (~22% at session 6) — real, continued progress, but 59% (387 KB across 4,019 functions) is still completely unmapped.**

Notes on the numbers:
- **CLAUDE.md / project memory says "5,137 functions"** — `bruce_functions.csv` still has only 4,995 data rows, unchanged since session 6 (no re-import happened this round either). Same ~142-function discrepancy as before; still not chased further here.
- **`bruce_functions.csv`'s `name` column is still stale for all 448 attributed addresses** — same gotcha as every prior session, unchanged. Always join on `address`.
- Of the 767 files currently in `analysis/decomp/` (up from 546 at the session-8 snapshot, +221), **634 map onto an address in the 4,995-function census; 133 do not** (up from 439/107 respectively) — the non-census ones are the tiny (mostly ≤364-byte) `Decompile.java`-carved-out ITCM-thunk/veneer-style functions described in `bruce-itcm.md`, plus a scattering of other sub-boundary carve-outs. They total 13,400 bytes of real decompiled code that stays outside the 4,995/660,570 baseline for the same consistency reason as before. Re-spot-checked this session: **0 size mismatches** between census `size_bytes` and the decomp-header `size=` field across all 634 in-census decompiled functions, and 0 unparseable decomp-file headers across all 767 — the header format (`// <addr>  <name>  size=<N> bytes`) has held steady.
- Of the 634 in-census decompiled functions, **106 are also formally attributed** to a source file (up from 88 at the session-8/9 snapshot). The other **528 are decompiled-but-unattributed** — of those, **410 are inside the identified BTA/BTE Bluetooth-stack block** (§1a below, up from 319), and the remaining **118** are scattered elsewhere (crypto-stack/I/O-path decompiles from earlier sessions, plus non-BTA gains this round — see the per-file table in §2, e.g. `tasks.c`, `state_machine.cc`, `timer.h`, `adapter.cc`, `main.cc`/`gatt_server.cc`/`advertiser.cc`/`platform.h` all newly complete or improved).
- **Growth attribution since session 8**: decompiled-in-census bytes grew from 145,891 to 201,935, **+56,044 bytes**. Of that, **+36,870 bytes (65.8%) is inside the BTA/BTE block** (§1a's own strict-join figure: 92,535 → 129,405 — use this doc's own numbers for the before/after, not `bruce-bta-stack.md`'s stale self-reported prose figure, for an apples-to-apples delta). The remaining **+19,174 bytes (34.2%)** landed in newly-completed or newly-touched attributed files (`bcm.c`'s 52 functions were already folded in by the session-8 snapshot; genuinely new this round includes `gatt_server.cc` (0→8/8), `main.cc` (1→2/2), `advertiser.cc` (0→1/1), `platform.h` (0→1/1), `tasks.c` (3→4/19), `queue.c` (unchanged at 6/12), `state_machine.cc` (0→1/11), `adapter.cc` (0→1/16), `timer.h` (2→3/9)) plus scattered unattributed non-BTA gains (§3b run deltas below).

### 1a. Module-identified-but-not-formally-attributed (informational — not folded into "Attributed" above)

`analysis/bruce-bta-stack.md` identifies the entire `0x600921b8`–`0x600c9cc4` range as the Broadcom BTA/BTE stack via a ~400-entry leaked function-name string table cross-referenced with `FindRef.java`, plus independent spec-level confirmation (HCI opcodes, HCI/LE-Meta event codes, SDP/GAP framing bytes — see that doc for full evidence). This is a **different provenance than `bruce_srcmap.csv`'s `__FILE__`-leak attribution** (no `.cc`/`.c` source filename is recovered, just a Broadcom-internal function name and module identity), so it is deliberately **not** merged into the "Attributed" row above — that row's definition stays a clean join against `bruce_srcmap.csv` per the methodology. Instead, it's broken out here as its own status tier, because lumping its still-undecompiled functions into "Totally unknown" would misrepresent them — their *identity* is known, just not their *decompiled content*.

| | Functions | Bytes | % of block |
|---|---:|---:|---:|
| BTA/BTE block total | 1,076 | 204,449 | 100% |
| — decompiled (also counted in §1's "Decompiled" row) | 410 | 129,405 | 63.3% |
| — **identified but not yet decompiled** | 666 | 75,044 | 36.7% |

That 666/75,044 is a subset of §1's "Totally unknown" row. Netting it out gives a more honest "no idea at all" figure:

| | Functions | % of 4,995 | Bytes | % of 660,570 |
|---|---:|---:|---:|---:|
| Totally unknown (§1, includes BTA-identified-but-undecompiled) | 4,019 | 80.46% | 387,431 | 58.65% |
| — of which: BTA-identified, module known, just not decompiled | 666 | 13.33% | 75,044 | 11.36% |
| **— truly unidentified (no attribution, no decompile, no module ID)** | **3,353** | **67.13%** | **312,387** | **47.29%** |

(`bruce-bta-stack.md`'s own prose still self-reports "328 of 1,076... ~93,700 bytes (~45.8%)" — that text was last hand-updated at its own session 8 and hasn't been rewritten to reflect the concurrent decompile work that landed in `analysis/decomp/` since (this session's read found 410/1,076 by strict address-join, not 328). This is expected drift, not an error: that doc's prose is a narrative snapshot from whenever it was last edited, while this doc's numbers come from a fresh join against the live `analysis/decomp/` directory at read time. If you're picking up BTA/BTE work next, trust `bruce-bta-stack.md`'s *identification* evidence and address-range map, but trust *this* doc's function-count/byte figures — and re-run the join yourself if either file has moved since.)

## 2. Per-source-file table (all 139 attributed files, sorted by total byte size descending)

"Decompiled funcs/bytes" = how many of that file's *attributed* functions have a matching file in `analysis/decomp/` (cross-referenced by address).

| Src file | Attributed funcs | Decompiled funcs | Total bytes | Decompiled bytes | Remaining bytes |
|---|---:|---:|---:|---:|---:|
| `bcm.c` | 52 | 52 | 11548 | 11548 | 0 |
| `timer.h` | 9 | 3 | 4016 | 2684 | 1332 |
| `tasn_dec.c` | 7 | 7 | 3856 | 3856 | 0 |
| `state_machine.cc` | 11 | 1 | 3332 | 604 | 2728 |
| `keys.cc` | 19 | 19 | 3296 | 3296 | 0 |
| `adapter.cc` | 16 | 16 | 3216 | 3216 | 0 |
| `usb_host_audio_topology.cc` | 8 | 0 | 2876 | 0 | 2876 |
| `audio_states.cc` | 6 | 0 | 2392 | 0 | 2392 |
| `usb_host_audio.cc` | 9 | 0 | 2346 | 0 | 2346 |
| `device_info.cc` | 7 | 0 | 2300 | 0 | 2300 |
| `tasks.c` | 19 | 4 | 2220 | 484 | 1736 |
| `remote_device_db.cc` | 4 | 0 | 2070 | 0 | 2070 |
| `gatt_server.cc` | 8 | 8 | 2028 | 2028 | 0 |
| `usb_audio_receive.cc` | 8 | 0 | 1994 | 0 | 1994 |
| `key_value_store.cc` | 6 | 0 | 1968 | 0 | 1968 |
| `application_state.cc` | 6 | 0 | 1956 | 0 | 1956 |
| `firmware_image_upload.cc` | 1 | 0 | 1714 | 0 | 1714 |
| `ec_asn1.c` | 5 | 0 | 1630 | 0 | 1630 |
| `queue.c` | 12 | 6 | 1540 | 1090 | 450 |
| `usb_host_hid.cc` | 3 | 0 | 1468 | 0 | 1468 |
| `pem_lib.c` | 3 | 0 | 1458 | 0 | 1458 |
| `xbara.h` | 2 | 1 | 1246 | 1172 | 74 |
| `main.cc` | 2 | 2 | 1128 | 1128 | 0 |
| `http_flash_writer.cc` | 4 | 0 | 1116 | 0 | 1116 |
| `synapse_audio_processor.cc` | 2 | 0 | 1060 | 0 | 1060 |
| `thermal.cc` | 4 | 0 | 912 | 0 | 912 |
| `gotham.cc` | 5 | 0 | 882 | 0 | 882 |
| `stats.cc` | 1 | 0 | 816 | 0 | 816 |
| `receiver.cc` | 4 | 0 | 812 | 0 | 812 |
| `battery_gauge_bq2742X.cc` | 3 | 0 | 808 | 0 | 808 |
| `usb_device_cdc_acm.c` | 3 | 0 | 750 | 0 | 750 |
| `sleep_driver.cc` | 1 | 1 | 744 | 744 | 0 |
| `flash_lut.cc` | 3 | 0 | 706 | 0 | 706 |
| `headphone_state_machine.cc` | 5 | 0 | 672 | 0 | 672 |
| `bug_report.cc` | 4 | 0 | 660 | 0 | 660 |
| `heap_5_improved.c` | 4 | 2 | 650 | 346 | 304 |
| `usb_device.cc` | 5 | 0 | 578 | 0 | 578 |
| `led_driver_lp5562.cc` | 3 | 0 | 548 | 0 | 548 |
| `usb_device_audio.cc` | 3 | 0 | 540 | 0 | 540 |
| `usb_host.cc` | 3 | 0 | 526 | 0 | 526 |
| `haptics.cc` | 3 | 3 | 526 | 526 | 0 |
| `gatt_manager_task.cc` | 4 | 0 | 518 | 0 | 518 |
| `mimxrt10xx_flash_memory.cc` | 2 | 2 | 512 | 512 | 0 |
| `usb_port_controller_tusb320.cc` | 4 | 0 | 508 | 0 | 508 |
| `battery_service.cc` | 3 | 0 | 506 | 0 | 506 |
| `recording_pipeline.cc` | 3 | 0 | 500 | 0 | 500 |
| `p_x25519_asn1.c` | 4 | 0 | 492 | 0 | 492 |
| `p_ed25519_asn1.c` | 4 | 2 | 474 | 170 | 304 |
| `activation_sequence.cc` | 2 | 0 | 468 | 0 | 468 |
| `ble_info.cc` | 2 | 0 | 466 | 0 | 466 |
| `tasn_new.c` | 2 | 0 | 464 | 0 | 464 |
| `sai.cc` | 5 | 0 | 450 | 0 | 450 |
| `mpu.cc` | 1 | 0 | 440 | 0 | 440 |
| `trigger_bug_report.cc` | 2 | 0 | 438 | 0 | 438 |
| `bee.cc` | 2 | 0 | 436 | 0 | 436 |
| `battery_charger_bq25601.h` | 4 | 0 | 432 | 0 | 432 |
| `types.h` | 3 | 0 | 424 | 0 | 424 |
| `asn1_lib.c` | 3 | 0 | 422 | 0 | 422 |
| `gatt_server.h` | 3 | 3 | 418 | 418 | 0 |
| `frames.h` | 2 | 0 | 402 | 0 | 402 |
| `timers.c` | 5 | 0 | 360 | 0 | 360 |
| `haptics_cluster.cc` | 2 | 2 | 332 | 332 | 0 |
| `p_dsa_asn1.c` | 2 | 0 | 332 | 0 | 332 |
| `input_task.cc` | 2 | 2 | 330 | 330 | 0 |
| `partition_table.h` | 2 | 0 | 324 | 0 | 324 |
| `audio_player.cc` | 2 | 0 | 322 | 0 | 322 |
| `io_pin.cc` | 1 | 1 | 318 | 318 | 0 |
| `advertiser.cc` | 1 | 1 | 316 | 316 | 0 |
| `pattern_player.cc` | 1 | 0 | 308 | 0 | 308 |
| `p_rsa_asn1.c` | 2 | 0 | 298 | 0 | 298 |
| `private_heap.cc` | 3 | 0 | 292 | 0 | 292 |
| `battery_gauge_bq2742X.h` | 1 | 0 | 290 | 0 | 290 |
| `a_int.c` | 1 | 0 | 286 | 0 | 286 |
| `a_object.c` | 2 | 0 | 274 | 0 | 274 |
| `bn_asn1.c` | 2 | 0 | 272 | 0 | 272 |
| `usb_host_worker.cc` | 3 | 0 | 268 | 0 | 268 |
| `gki_ft.c` | 2 | 0 | 268 | 0 | 268 |
| `dcp_encryption_engine.cc` | 2 | 0 | 266 | 0 | 266 |
| `adc.h` | 1 | 1 | 248 | 248 | 0 |
| `sleep_lock.cc` | 1 | 0 | 238 | 0 | 238 |
| `switch_pro_controller.cc` | 1 | 1 | 236 | 236 | 0 |
| `board.cc` | 2 | 2 | 230 | 230 | 0 |
| `usb_audio_send.cc` | 1 | 0 | 230 | 0 | 230 |
| `power_rpcs.cc` | 1 | 0 | 228 | 0 | 228 |
| `dynamic_buffer.h` | 2 | 0 | 226 | 0 | 226 |
| `a_bitstr.c` | 1 | 0 | 218 | 0 | 218 |
| `logger.cc` | 1 | 0 | 216 | 0 | 216 |
| `bio.c` | 3 | 0 | 200 | 0 | 200 |
| `binary_build_metadata.cc` | 1 | 0 | 194 | 0 | 194 |
| `pattern_player.h` | 1 | 0 | 190 | 0 | 190 |
| `gotham_patterns.cc` | 1 | 0 | 190 | 0 | 190 |
| `hardware_timer.cc` | 1 | 0 | 188 | 0 | 188 |
| `append_buffer.h` | 2 | 0 | 186 | 0 | 186 |
| `sound_codec_wm8904.cc` | 2 | 0 | 184 | 0 | 184 |
| `external_controller.cc` | 1 | 0 | 180 | 0 | 180 |
| `led_calibration.cc` | 1 | 0 | 178 | 0 | 178 |
| `hid_input_target.cc` | 1 | 1 | 172 | 172 | 0 |
| `linear_interpolation_source.h` | 1 | 0 | 170 | 0 | 170 |
| `platform.h` | 1 | 1 | 164 | 164 | 0 |
| `ex_data.c` | 1 | 0 | 160 | 0 | 160 |
| `audio_tasks.cc` | 1 | 0 | 158 | 0 | 158 |
| `reset.cc` | 2 | 0 | 148 | 0 | 148 |
| `accessory_detect_ts3a227e.cc` | 1 | 0 | 140 | 0 | 140 |
| `snvs.h` | 1 | 0 | 138 | 0 | 138 |
| `parser.cc` | 1 | 0 | 136 | 0 | 136 |
| `get_device_data.cc` | 1 | 0 | 134 | 0 | 134 |
| `adapter.h` | 2 | 0 | 132 | 0 | 132 |
| `gotham_16mb_mimxrt10xx_mpu.cc` | 1 | 0 | 132 | 0 | 132 |
| `wakelock.cc` | 1 | 0 | 132 | 0 | 132 |
| `util.cc` | 1 | 0 | 132 | 0 | 132 |
| `flash_memory.h` | 1 | 0 | 130 | 0 | 130 |
| `buffer.h` | 1 | 0 | 128 | 0 | 128 |
| `event_groups.c` | 2 | 0 | 128 | 0 | 128 |
| `buf.c` | 2 | 0 | 122 | 0 | 122 |
| `pwm.h` | 3 | 0 | 116 | 0 | 116 |
| `uart.cc` | 1 | 0 | 114 | 0 | 114 |
| `battery_charger_bq25601.cc` | 2 | 0 | 114 | 0 | 114 |
| `usb_configuration_handler.cc` | 1 | 0 | 112 | 0 | 112 |
| `reboot_reason.cc` | 1 | 0 | 108 | 0 | 108 |
| `obj.c` | 1 | 0 | 102 | 0 | 102 |
| `system_tasks.cc` | 1 | 0 | 100 | 0 | 100 |
| `persistent_crash_register.cc` | 1 | 0 | 100 | 0 | 100 |
| `i2c_device.h` | 1 | 0 | 100 | 0 | 100 |
| `tasn_utl.c` | 1 | 0 | 100 | 0 | 100 |
| `logging.cc` | 1 | 0 | 98 | 0 | 98 |
| `buffer.cc` | 1 | 0 | 94 | 0 | 94 |
| `ecdsa_asn1.c` | 1 | 0 | 92 | 0 | 92 |
| `pem_oth.c` | 1 | 0 | 88 | 0 | 88 |
| `key_value_store.h` | 1 | 0 | 88 | 0 | 88 |
| `srtc.cc` | 1 | 0 | 80 | 0 | 80 |
| `evp.c` | 1 | 1 | 70 | 70 | 0 |
| `dsa.c` | 1 | 0 | 64 | 0 | 64 |
| `info.cc` | 1 | 0 | 62 | 0 | 62 |
| `transfer_bug_report.cc` | 1 | 0 | 48 | 0 | 48 |
| `heap_support.c` | 1 | 0 | 44 | 0 | 44 |
| `gotham_task.cc` | 1 | 0 | 44 | 0 | 44 |
| `gatt_service_handle.h` | 1 | 0 | 28 | 0 | 28 |
| `init.cc` | 1 | 0 | 22 | 0 | 22 |
| `exit.c` | 1 | 0 | 16 | 0 | 16 |

Files fully decompiled already (0 remaining bytes), 17 of 139 (up from 12): `bcm.c`, `gatt_server.cc`, `main.cc`, `sleep_driver.cc`, `haptics.cc`, `mimxrt10xx_flash_memory.cc`, `gatt_server.h`, `haptics_cluster.cc`, `input_task.cc`, `io_pin.cc`, `advertiser.cc`, `adc.h`, `switch_pro_controller.cc`, `board.cc`, `hid_input_target.cc`, `platform.h`, `evp.c`. New completions this round vs. session 8: `gatt_server.cc` (0/8 → 8/8), `gatt_server.h` (0/3 → 3/3), `main.cc` (1/2 → 2/2), `advertiser.cc` (0/1 → 1/1), `platform.h` (0/1 → 1/1). Partial-progress files worth noting: `tasks.c` (3/19 → 4/19), `queue.c` unchanged at 6/12, `timer.h` (2/9 → 3/9), `state_machine.cc` (0/11 → 1/11).

**Session 15 targeted patch (hand-applied, not a full mechanical re-join — see note below):** `tasn_dec.c` (0/7 → **7/7, file complete**, extends `bruce-crypto.md`'s ASN.1/BoringSSL narrative — it's `crypto/asn1/tasn_dec.c`, the DER decode engine), `adapter.cc` (1/16 → **16/16, file complete**, documented in `bruce-bta-stack.md`'s new "Session 15" subsection — a first-party BLE peripheral-adapter wrapper over the `gatt_server.cc`/BTA_GATTS engine, with a promising unexplored subscribe/unsubscribe vtable-dispatch lead for `bruce-io-paths.md`'s report-packing thread), `keys.cc` (2/19 → **19/19, file complete**, documented in `bruce-misc-functions.md`'s new "Session 15" subsection — confirms it's a generic typed config/property KV store, reinforcing CLAUDE.md's known trap). **Files fully decompiled count is now 20 of 139** (17 above + these 3). All three files' new byte totals were cross-checked by summing individual decompiled-function sizes against the pre-existing "Total bytes" column and matched exactly (tasn_dec.c 3856, adapter.cc 3216, keys.cc 3296 — see `analysis/decomp/tasn_dec__*.c` / `adapter__*.c` / `keys__*.c`), so these three rows are trustworthy even though the rest of the doc (§1, §1a, §3b, §4 top-line stats) was **not** re-joined this pass and is now mildly stale on top of session 13's own staleness re: sessions 14+ concurrent BTA/BTE work — a full regeneration per [Methodology](#methodology) is still owed whenever convenient.

## 3. Prioritized gap list

### 3a. Attributed-but-not-yet-decompiled — cheapest wins (top 10 files by remaining bytes)

**Session 15 update: the former #1–#3 (`tasn_dec.c`, `adapter.cc`, `keys.cc`) are now all fully decompiled** (see the patch note in §2 above) — dropped from this table. `usb_host_audio_topology.cc` is now the top cheap-win target.

| Rank | Src file | Remaining funcs | Remaining bytes | Already decompiled |
|---:|---|---:|---:|---:|
| 1 | `usb_host_audio_topology.cc` | 8 | 2876 | 0/8 |
| 2 | `state_machine.cc` | 10 | 2728 | 1/11 |
| 3 | `audio_states.cc` | 6 | 2392 | 0/6 |
| 4 | `usb_host_audio.cc` | 9 | 2346 | 0/9 |
| 5 | `device_info.cc` | 7 | 2300 | 0/7 |
| 6 | `remote_device_db.cc` | 4 | 2070 | 0/4 |
| 7 | `usb_audio_receive.cc` | 8 | 1994 | 0/8 |
| 8 | `key_value_store.cc` | 6 | 1968 | 0/6 |
| 9 | `application_state.cc` | 6 | 1956 | 0/6 |
| 10 | `firmware_image_upload.cc` | 1 | 1714 | 0/1 |

Ranks 8-10 are carried forward from §2's full per-file table (not independently re-verified against `analysis/decomp/` this session beyond the three rows patched above) — worth a quick re-check before starting on them in case a concurrent session has already touched them.

`state_machine.cc` remains the only file in this top-10 with any progress (1/11) — a natural next cheap-win pick since it's already partway there. Note three of the four USB-audio-shaped files here (`usb_host_audio_topology.cc`, `usb_host_audio.cc`, `usb_audio_receive.cc`) plus `audio_states.cc` look like they could be one coherent "USB audio subsystem" sweep worth doing together rather than file-by-file, given the accessory/headphone-jack audio hardware (`sound_codec_wm8904.cc`, `headphone_state_machine.cc`, `accessory_detect_ts3a227e.cc`) already visible elsewhere in §2's table.

Regenerate the full per-file remaining-function list anytime with:
```python
# addresses in bruce_srcmap.csv for src_file == X, minus addresses with a header-matching file in analysis/decomp/
```
(join key is the 8-hex-digit address suffix on the decomp filename / the first line's address, *not* the filename string — see methodology note on stale names below.)

### 3b. Unattributed contiguous address ranges — candidate whole modules

Same 168 runs as every prior snapshot (the attributed set hasn't changed, so run boundaries are identical) — only the "already decompiled" counts moved. Run #1 continues to be an *identified* module (§1a), not an unknown blob — kept in this table for continuity (it's still the biggest single lever by size) but should be read as "still has 36.7% left to decompile," not "still unidentified."

| # | Start | End | Span (B) | Code bytes | Funcs | Already decompiled | Density | Largest function in range |
|---:|---|---|---:|---:|---:|---:|---:|---|
| 1★ | `0x600921b8` | `0x600c9cc4` | 228108 | 204449 | 1076 | 410 | 89.6% | `FUN_600ba1c4` (3898B @ `600ba1c4`) |
| 2 | `0x600ecb72` | `0x6013d4e4` | 330098 | 95117 | 1006 | 5 | 28.8% | `FUN_601054dc` (2546B @ `601054dc`) |
| 3 | `0x600df286` | `0x600ea868` | 46562 | 44326 | 316 | 9 | 95.2% | `FUN_600e398a` (6270B @ `600e398a`) |
| 4 | `0x600cc6e4` | `0x600d4560` | 32380 | 24998 | 304 | 4 | 77.2% | `FUN_600ccfb4` (1568B @ `600ccfb4`) |
| 5 | `0x600d8a12` | `0x600df24c` | 26682 | 23204 | 399 | 7 | 87.0% | `FUN_600dcf8c` (984B @ `600dcf8c`) |
| 6 | `0x6004cd58` | `0x60051164` | 17420 | 17174 | 10 | 1 | 98.6% | `FUN_6004cdb8` (15662B @ `6004cdb8`) |
| 7 | `0x60086720` | `0x6008ac36` | 17686 | 14608 | 19 | 0 | 82.6% | `FUN_60087970` (4036B @ `60087970`) |
| 8 | `0x60040500` | `0x60047038` | 27448 | 12698 | 92 | 10 | 46.3% | `FUN_60043ecc` (1364B @ `60043ecc`) |
| 9 | `0x60054f30` | `0x60058570` | 13888 | 10908 | 66 | 0 | 78.5% | `FUN_60056fa4` (1694B @ `60056fa4`) |
| 10 | `0x6004898c` | `0x6004cb5c` | 16848 | 10520 | 171 | 25 | 62.4% | `FUN_6004a4e6` (840B @ `6004a4e6`) |
| 11 | `0x600d56b8` | `0x600d89ec` | 13108 | 10254 | 177 | 3 | 78.2% | `FUN_600d80f4` (260B @ `600d80f4`) |
| 12 | `0x6007b96c` | `0x6007e69c` | 11568 | 9552 | 53 | 0 | 82.6% | `FUN_6007d144` (980B @ `6007d144`) |
| 13 | `0x60052294` | `0x60054a46` | 10162 | 8254 | 99 | 3 | 81.2% | `FUN_600526a0` (472B @ `600526a0`) |
| 14 | `0x60072260` | `0x60073b7c` | 6428 | 6400 | 3 | 2 | 99.6% | `FUN_600723b4` (6088B @ `600723b4`) |
| 15 | `0x6006c35c` | `0x6006e480` | 8484 | 5784 | 53 | 0 | 68.2% | `FUN_6006d998` (712B @ `6006d998`) |

★ = identified module (§1a), not an unknown blob — kept in this "unattributed" table only because it fails the strict `bruce_srcmap.csv` join, not because it's a mystery.

168 unattributed runs total (unchanged); span across all of them sums to 899,666 bytes, code bytes sum to 563,120 (both unchanged from every prior snapshot — run boundaries and their contents outside `analysis/decomp/` are a function of the attributed set only, which hasn't changed; 563,120 = 660,570 − 97,450 exactly, a good consistency check on this pass).

Per-range deltas vs. the session-8 snapshot (using that doc's own strict-join numbers, not `bruce-bta-stack.md`'s self-reported prose figure), for the top 15: run #1 **319→410** (the single biggest mover this round — 91 more BTA/BTE functions decompiled), #2 **2→5**, #3 7→9, #4 2→4, #5 4→7, #6 1→1 (no change), #7 0→0 (no change), #8 9→10, #9 0→0 (no change), #10 25→25 (no change — no further work landed in this range since the earlier 3→25 jump), #11 2→3, #12 0→0 (no change), #13 3→3 (no change), #14 2→2 (no change), #15 0→0 (no change).

**#1 remains the headline finding by size, and its status keeps improving: `0x600921b8`–`0x600c9cc4`, 204,449 bytes of dense (89.6%) code across 1,076 functions, is the confirmed Broadcom BTA/BTE Bluetooth stack (`analysis/bruce-bta-stack.md`), now 63.3% decompiled by size** (up from 45.3% at the session-8 snapshot). Full evidence for the identification (a ~400-entry leaked BTA function-name string table, HCI command opcodes verified byte-for-byte against the spec, and the top-level HCI event dispatcher's switch matching the real HCI/LE-Meta event-code tables) is in that doc, along with a module-by-module address-range map (HCI transport, BTM, BTA DM, GATT client+server, L2CAP, SDP, SMP, and NIST P-256/P-192 EC field arithmetic for LE Secure Connections). **666 functions / 75,044 bytes remain in this block.**

Runner-up #2 (`0x600ecb72`–`0x6013d4e4`, 330 KB span but only 28.8% density) picked up 3 more decompiled functions this round (2→5) but is still overwhelmingly untouched. `bruce-bta-stack.md` separately notes that many of `smp_sm_event`'s 54 callers live in `0x600faxxx`–`0x600fcxxx`, inside this run — meaning run #2 likely contains a substantial chunk of real SMP per-state-handler code, not just miscellaneous ITCM-thunk mechanical tail code. Still worth a dedicated string-xref sweep before the next full-doc regeneration, per that doc's own "New lead for a future session" note.

## 4. The honest bottom line

Of **4,995 total functions** (the current census — see the 5,137-vs-4,995 discrepancy note in §1):

| | Functions | Bytes |
|---|---:|---:|
| Attributed to a source file | 448 | 97,450 |
| Decompiled (in census) | 634 | 201,935 |
| — of which both attributed AND decompiled | 106 | 26,246 |
| — of which in the identified-but-not-formally-attributed BTA/BTE stack (§1a) | 410 | 129,405 |
| **Understood in some way (union)** | **976 (19.5%)** | **273,139 (41.4%)** |
| **Completely unknown — no attribution, no decompile, no module ID** | 4,019 (80.5%), or **3,353 (67.1%) excluding BTA-identified** | 387,431 (58.7%), or **312,387 (47.3%) excluding BTA-identified** |

**Compared to the session-8 snapshot: union coverage grew by function count (17.0% → 19.5%) and by byte-weight (35.4% → 41.4%).** The "truly unidentified, no module guess at all" byte figure improved only slightly (47.7% → 47.3%) — most of this round's gains landed inside the already-*identified* BTA/BTE block (moving functions from "identified but undecompiled" to "decompiled," a real quality upgrade that doesn't move the "truly unidentified" needle) rather than opening new unidentified territory. That's expected and still valuable progress: the single biggest coherent subsystem in the image (the BTA/BTE Bluetooth stack) is now nearly two-thirds decompiled by size, up from under half.

**3,353 functions and ~312 KB of code — still just under half the binary by size — remain truly unidentified with no attribution, no decompile, and no module ID of any kind.** That's the real remaining scope of the "full decompile to source-reconstruction quality" goal. The single best next lever by size is still finishing §1a/§3b-run-#1 (666 functions / 75,044 bytes still to decompile, but already identified — cheap in the sense that no more detective work is needed, just `Decompile.java` + read, same as §3a); the next cheapest *fresh-territory* win is `tasn_dec.c` (§3a, still fully untouched); and run #2 (330 KB, mixed ITCM-thunk mechanical work plus a real pocket of SMP state-handler code per `bruce-bta-stack.md`) remains the best candidate for genuinely new-territory progress at scale, now that most of the "cheap, already-identified" BTA work is roughly two-thirds done.

## Methodology (for regenerating this doc)

Inputs: `analysis/ghidra/bruce_functions.csv` (address, name, size_bytes — full census), `analysis/ghidra/bruce_srcmap.csv` (address, name, src_file — 448-row attribution), `analysis/decomp/*.c` (one file per decompiled function; first line is a `// <addr>  <name>  size=<N> bytes` header written by `Decompile.java` — parse *that*, not the filename, for address/size ground truth).

Join key is always the **8-hex-digit address**, lowercase, zero-padded — not the name string. Same gotchas as every prior session, still true:
1. `bruce_functions.csv`'s `name` column is stale (pre-attribution `FUN_xxxxxxxx` defaults) for every one of the 448 attributed addresses; only `bruce_srcmap.csv` has the current name. Sizes/addresses in `bruce_functions.csv` are fine (re-spot-checked this session: 0 mismatches between census size and decomp-header size across all 634 in-census decompiled functions).
2. Not every file in `analysis/decomp/` corresponds to a census address — `Decompile.java` will create a function (and thus a decomp file) at an address Ghidra's auto-analysis didn't already recognize as a function boundary. 133 of 767 current decomp files are like this (all ≤364 bytes, same pattern as prior sessions) — exclude them from census-relative stats or the percentages won't reconcile against `bruce_functions.csv`'s totals.
3. For any block identified by means *other* than `bruce_srcmap.csv` (i.e. string-table cross-reference, as in `bruce-bta-stack.md`, rather than a leaked `__FILE__` path): **do not fold it into the "Attributed" join.** Keep it as a separate reported tier (this doc's §1a) so the core `bruce_srcmap.csv`-based join stays a clean, mechanically-reproducible number, while still surfacing the fact that "unattributed" isn't the same thing as "unidentified" for that range. When computing §1a's own decompiled-count, use a fresh strict address-join against the current `analysis/decomp/` state — **don't** just copy `bruce-bta-stack.md`'s self-reported running-count prose, which is only updated when that doc itself is hand-edited and can lag well behind the actual directory contents (this session found 410/1,076 by join vs. that doc's stale self-reported 328).

Unattributed contiguous ranges (§3b) = walk `bruce_functions.csv` in address order, group maximal runs where no function's address is in the attributed set, compute span (last function's end − first function's start) and code_bytes (sum of `size_bytes` in the run) separately since span includes non-function bytes.

**A note on snapshot consistency**, learned again this session: if `analysis/decomp/` is being actively written to by a concurrent session, take **one single directory listing + parse pass** and derive every table in the doc from that same in-memory snapshot (e.g. dump to a pickle/dict and reuse it), rather than re-listing the directory for each table. A first exploratory pass this session read 677 decomp files; a later pass 90 seconds later read 767 — using a stale count for one table and a fresher one for another would have produced internally-inconsistent numbers (e.g. a per-file table that doesn't sum to the top-line total). This doc's final numbers are all from the 767-file read.

See also: `bruce-ghidra.md` (workspace/tooling, original module-mass table), `bruce-io-paths.md` / `bruce-crypto.md` / `bruce-itcm.md` (subsystem-level narrative findings for functions already decompiled), `bruce-bta-stack.md` (the BTA/BTE stack identification and address-range map — its prose is stale relative to this doc's function-count/byte figures as of this snapshot, see §1a), `firmware-map.md` (bruce vs gotham top-level structure).

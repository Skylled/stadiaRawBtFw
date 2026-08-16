# Bruce — full-decompile tracking status

Data-driven status doc for the "decompile all of `bruce` to source-reconstruction quality" effort. Regenerate the numbers here whenever `bruce_functions.csv`, `bruce_srcmap.csv`, or `analysis/decomp/` change materially — don't hand-edit stale tables into new prose, just re-run the join described in [Methodology](#methodology) below.

**Snapshot: 2026-08-16 02:27 EDT (full regeneration after sessions 14–16).** Prior full regeneration was session ~13 (41.4% union / 47.3% truly-unidentified, by bytes), hand-patched once afterward (session 15: `tasn_dec.c`/`adapter.cc`/`keys.cc` → complete, not re-joined). Since then: session 14 found and decompiled the codebase-wide diagnostic **log/message-buffer framework** (`analysis/bruce-log-buffer.md` — a small class + emit engine referenced from 64 of 139 attributed source files), session 15 resolved its RPC transport (`StreamLogBuffer` handler + a 16-entry debug-command dispatch table) and finished `tasn_dec.c`/`adapter.cc`/`keys.cc`, and this session's own snapshot-taking caught a **concurrent Ghidra session actively sweeping the BTA/BTE block in real time**: `analysis/decomp/` was read once at 896 files (already reflecting all of the above), then found to have grown to 976 files 90 seconds later on a routine re-check. Per this doc's own methodology note (learned session 13, re-confirmed this session), a **fresh single directory listing + parse pass was taken at the final 976-file count** and every table below is derived from that one in-memory snapshot — no table mixes counts from the 896-file read and the 976-file read. The concurrent session's gains landed entirely inside the already-identified BTA/BTE block (§1a: 410→490 of 1,076 decompiled between the two reads); nothing outside that block changed in the 90 seconds between reads. As always: treat every count below as a lower bound as of the snapshot instant — re-run before trusting exact numbers for planning, especially if Ghidra is still running.

`bruce_functions.csv` (4,995 rows, 660,570 bytes) and `bruce_srcmap.csv` (448 rows, 139 src files) are both **byte-for-byte unchanged** from every prior snapshot back to session 6 — reloaded fresh this session and reconfirmed identical (no re-import happened). All growth this round is exclusively in `analysis/decomp/`.

## 1. Top-line stats

| Metric | Functions | % of 4,995 | Bytes | % of 660,570 |
|---|---:|---:|---:|---:|
| **Total functions (census)** | 4,995 | 100% | 660,570 | 100% |
| **Attributed** (leaked `__FILE__` → 139 src files) | 448 | 8.97% | 97,450 | 14.75% |
| **Decompiled** (`analysis/decomp/*.c`, matched to a census address) | 836 | 16.74% | 246,879 | 37.37% |
| **Attributed ∪ Decompiled** (understood in *some* way) | 1,124 | 22.50% | 305,815 | **46.30%** |
| **Totally unknown** (no attribution, no decompile) | 3,871 | 77.50% | 354,755 | **53.70%** |

Size-weighted (bytes) is still the more honest progress metric than function-count, for the same reason as every prior snapshot (a handful of huge functions dominate the byte total disproportionately to their count). **Bottom line: ~46% of the binary's code by size is now understood in some way, up from ~41% at the session-13 snapshot (~35% at session 8, ~22% at session 6).**

Notes on the numbers:
- **CLAUDE.md / project memory says "5,137 functions"** — `bruce_functions.csv` still has only 4,995 data rows, unchanged since session 6. Same ~142-function discrepancy as before; still not chased further here.
- **`bruce_functions.csv`'s `name` column is still stale for all 448 attributed addresses** — same gotcha as every prior session, unchanged. Always join on `address`.
- Of the 976 files currently in `analysis/decomp/` (up from 767 at session 13, +209), **836 map onto an address in the 4,995-function census; 140 do not** (up from 634/133 respectively) — the non-census ones are the tiny (mostly ≤364-byte) `Decompile.java`-carved-out ITCM-thunk/veneer-style functions described in `bruce-itcm.md`, plus a scattering of other sub-boundary carve-outs. They total 14,676 bytes of real decompiled code that stays outside the 4,995/660,570 baseline for consistency. Re-spot-checked this session: **0 size mismatches** between census `size_bytes` and the decomp-header `size=` field across all 836 in-census decompiled functions, and 0 unparseable decomp-file headers, 0 duplicate addresses across all 976 files — the header format has held steady.
- Of the 836 in-census decompiled functions, **160 are also formally attributed** to a source file (up from 106 at session 13). The other **676 are decompiled-but-unattributed** — of those, **490 are inside the identified BTA/BTE Bluetooth-stack block** (§1a below, up from 410 — entirely from the concurrent session caught mid-run, see the Snapshot note above), and the remaining **186 are scattered elsewhere** (unchanged from the 896-file read, i.e. no concurrent-session activity touched non-BTA territory in the 90-second gap) — crypto-stack/I/O-path decompiles from earlier sessions, plus the session-14/15 log-buffer framework's core (unattributed) functions, a BoringSSL runtime-support extension, and a GKI buffer-pool extension. See §2/§3b for the per-file/per-range detail.
- **Growth attribution since session 13**: decompiled-in-census bytes grew from 201,935 to 246,879, **+44,944 bytes**, cleanly splitting three ways: **+19,586 bytes (43.6%) inside the BTA/BTE block** (410→490 functions, entirely the concurrent session caught by this snapshot — see §1a); **+12,268 bytes (27.3%) in files that are both attributed and now decompiled** (106→160 functions — the session-15 `tasn_dec.c`/`adapter.cc`/`keys.cc` completions, 39 functions, plus 9 newly-complete log-buffer-framework attributed files — `usb_device_cdc_acm.c`, `frames.h`, `dynamic_buffer.h`, `append_buffer.h`, `logger.cc`, `buffer.h`, `buffer.cc`, `system_tasks.cc`, `uart.cc`, 14 functions — plus `adapter.h` partial, +1); and **+13,090 bytes (29.1%) scattered outside both** (118→186 unattributed non-BTA functions — the log-buffer framework's core unattributed cluster plus its RPC-transport/dispatch-table functions, a BoringSSL runtime-support extension, and a GKI buffer-pool extension — see §3b's per-run deltas and `bruce-log-buffer.md`). This last bucket is the only one of the three that opens genuinely new (not-previously-identified) territory — see §4 for why.

### 1a. Module-identified-but-not-formally-attributed (informational — not folded into "Attributed" above)

`analysis/bruce-bta-stack.md` identifies the entire `0x600921b8`–`0x600c9cc4` range as the Broadcom BTA/BTE stack via a ~400-entry leaked function-name string table cross-referenced with `FindRef.java`, plus independent spec-level confirmation (HCI opcodes, HCI/LE-Meta event codes, SDP/GAP framing bytes — see that doc for full evidence). Same different-provenance reasoning as every prior snapshot: **not** merged into "Attributed" above, kept as its own tier.

| | Functions | Bytes | % of block |
|---|---:|---:|---:|
| BTA/BTE block total | 1,076 | 204,449 | 100% |
| — decompiled (also counted in §1's "Decompiled" row) | 490 | 148,991 | 72.9% |
| — **identified but not yet decompiled** | 586 | 55,458 | 27.1% |

That 586/55,458 is a subset of §1's "Totally unknown" row. Netting it out gives a more honest "no idea at all" figure:

| | Functions | % of 4,995 | Bytes | % of 660,570 |
|---|---:|---:|---:|---:|
| Totally unknown (§1, includes BTA-identified-but-undecompiled) | 3,871 | 77.50% | 354,755 | 53.70% |
| — of which: BTA-identified, module known, just not decompiled | 586 | 11.73% | 55,458 | 8.40% |
| **— truly unidentified (no attribution, no decompile, no module ID)** | **3,285** | **65.77%** | **299,297** | **45.31%** |

**A near-live capture of concurrent work:** this snapshot's BTA/BTE decompiled count (490/1,076, 72.9%) is up sharply from session 13's 410/1,076 (63.3%) — an 80-function jump that, per the Snapshot note above, happened *during this regeneration's own directory reads* (896-file read still showed 410; the final 976-file read showed 490). `bruce-bta-stack.md`'s own self-reported prose (last hand-updated with a "Session 9: 418 of 1,076" figure, itself already stale relative to session 13's 410-by-fresh-join) is now stale by an even larger margin — expected, not an error, per the same reasoning as every prior snapshot: trust *this* doc's address-join for counts, trust `bruce-bta-stack.md` for the identification evidence and module map, and re-run the join yourself if either file has moved since.

**Worth flagging for whoever picks up BTA/BTE work next**: since a concurrent session is (or very recently was) actively working this exact block, check `analysis/decomp/`'s current file count before starting — it may already be past 976.

## 2. Per-source-file table (all 139 attributed files, sorted by total byte size descending)

"Decompiled funcs/bytes" = how many of that file's *attributed* functions have a matching file in `analysis/decomp/` (cross-referenced by address).

| Src file | Attributed funcs | Decompiled funcs | Total bytes | Decompiled bytes | Remaining bytes |
|---|---:|---:|---:|---:|---:|
| `bcm.c` | 52 | 52 | 11548 | 11548 | 0 |
| `timer.h` | 9 | 3 | 4016 | 2684 | 1332 |
| `tasn_dec.c` | 7 | 7 | 3856 | 3856 | 0 |
| `state_machine.cc` | 11 | 11 | 3332 | 3332 | 0 |
| `keys.cc` | 19 | 19 | 3296 | 3296 | 0 |
| `adapter.cc` | 16 | 16 | 3216 | 3216 | 0 |
| `usb_host_audio_topology.cc` | 8 | 0 | 2876 | 0 | 2876 |
| `audio_states.cc` | 6 | 0 | 2392 | 0 | 2392 |
| `usb_host_audio.cc` | 9 | 0 | 2346 | 0 | 2346 |
| `device_info.cc` | 7 | 0 | 2300 | 0 | 2300 |
| `tasks.c` | 19 | 19 | 2220 | 2220 | 0 |
| `remote_device_db.cc` | 4 | 0 | 2070 | 0 | 2070 |
| `gatt_server.cc` | 8 | 8 | 2028 | 2028 | 0 |
| `usb_audio_receive.cc` | 8 | 0 | 1994 | 0 | 1994 |
| `key_value_store.cc` | 6 | 6 | 1968 | 1968 | 0 |
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
| `usb_device_cdc_acm.c` | 3 | 3 | 750 | 750 | 0 |
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
| `frames.h` | 2 | 2 | 402 | 402 | 0 |
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
| `dynamic_buffer.h` | 2 | 2 | 226 | 226 | 0 |
| `a_bitstr.c` | 1 | 0 | 218 | 0 | 218 |
| `logger.cc` | 1 | 1 | 216 | 216 | 0 |
| `bio.c` | 3 | 0 | 200 | 0 | 200 |
| `binary_build_metadata.cc` | 1 | 0 | 194 | 0 | 194 |
| `pattern_player.h` | 1 | 0 | 190 | 0 | 190 |
| `gotham_patterns.cc` | 1 | 0 | 190 | 0 | 190 |
| `hardware_timer.cc` | 1 | 0 | 188 | 0 | 188 |
| `append_buffer.h` | 2 | 2 | 186 | 186 | 0 |
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
| `adapter.h` | 2 | 1 | 132 | 60 | 72 |
| `gotham_16mb_mimxrt10xx_mpu.cc` | 1 | 0 | 132 | 0 | 132 |
| `wakelock.cc` | 1 | 0 | 132 | 0 | 132 |
| `util.cc` | 1 | 0 | 132 | 0 | 132 |
| `flash_memory.h` | 1 | 0 | 130 | 0 | 130 |
| `buffer.h` | 1 | 1 | 128 | 128 | 0 |
| `event_groups.c` | 2 | 0 | 128 | 0 | 128 |
| `buf.c` | 2 | 0 | 122 | 0 | 122 |
| `pwm.h` | 3 | 0 | 116 | 0 | 116 |
| `uart.cc` | 1 | 1 | 114 | 114 | 0 |
| `battery_charger_bq25601.cc` | 2 | 0 | 114 | 0 | 114 |
| `usb_configuration_handler.cc` | 1 | 0 | 112 | 0 | 112 |
| `reboot_reason.cc` | 1 | 0 | 108 | 0 | 108 |
| `obj.c` | 1 | 0 | 102 | 0 | 102 |
| `system_tasks.cc` | 1 | 1 | 100 | 100 | 0 |
| `persistent_crash_register.cc` | 1 | 0 | 100 | 0 | 100 |
| `i2c_device.h` | 1 | 0 | 100 | 0 | 100 |
| `tasn_utl.c` | 1 | 0 | 100 | 0 | 100 |
| `logging.cc` | 1 | 0 | 98 | 0 | 98 |
| `buffer.cc` | 1 | 1 | 94 | 94 | 0 |
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

Files fully decompiled already (0 remaining bytes), **32 of 139** (up from 20 recorded after session 15's patch): `bcm.c`, `tasn_dec.c`, `keys.cc`, `adapter.cc`, `gatt_server.cc`, `main.cc`, `sleep_driver.cc`, `haptics.cc`, `mimxrt10xx_flash_memory.cc`, `gatt_server.h`, `haptics_cluster.cc`, `input_task.cc`, `io_pin.cc`, `advertiser.cc`, `adc.h`, `switch_pro_controller.cc`, `board.cc`, `hid_input_target.cc`, `platform.h`, `evp.c`, plus **9 newly complete session 14/15's log-buffer-framework round**: `usb_device_cdc_acm.c`, `frames.h`, `dynamic_buffer.h`, `append_buffer.h`, `logger.cc`, `buffer.h`, `buffer.cc`, `system_tasks.cc`, `uart.cc` (see prior paragraph), plus **3 newly complete session 17**: `tasks.c` (4/19 → 19/19 — full FreeRTOS task-lifecycle/notification API, `analysis/bruce-itcm.md`'s new §"Session 17" section), `state_machine.cc` (1/11 → 11/11 — the generic hierarchical-state-machine framework plus its BLE-pairing/advertising-mode instantiation, new doc `analysis/bruce-state-machine.md`), `key_value_store.cc` (0/6 → 6/6 — the wear-leveled flash record store underneath `keys.cc`, extends `analysis/bruce-misc-functions.md`'s `keys.cc` section).

Partial-progress files (5, down from 8 — `tasks.c`/`state_machine.cc`/`key_value_store.cc` moved to fully-complete above): `timer.h` (3/9), `queue.c` (6/12), `xbara.h` (1/2), `heap_5_improved.c` (2/4), `p_ed25519_asn1.c` (2/4), `adapter.h` (1/2).

**Session 17 note on §1/§1a/§4 top-line stats below**: not re-joined/regenerated this session (same hand-patch-only convention as session 15, flagged there too) — this round's 31 newly-decompiled functions (15 `tasks.c` + 10 `state_machine.cc` + 6 `key_value_store.cc`, 6,432 bytes closed) are **not yet reflected** in §1's headline percentages, §1a's BTA/BTE tier (unaffected — none of these three files are in that block), or §4's bottom line. All three are formally-attributed files, so this round's gain lands entirely in the "attributed AND decompiled" bucket (160 → 191 functions by hand count), nudging the overall union-coverage percentage up slightly from the 46.3% recorded below — re-run the full join (§ Methodology) before trusting an exact updated figure.

## 3. Prioritized gap list

### 3a. Attributed-but-not-yet-decompiled — cheapest wins (top 10 files by remaining bytes)

**Session 17 update**: `tasks.c` (#10), `state_machine.cc` (#2), and `key_value_store.cc` (#8) — three of the prior top-10 — were fully decompiled this session (see §2 and the "Files fully decompiled" list above) and drop out of this table entirely. The table below is refreshed by pulling the next-largest `Remaining bytes` files from §2's full per-file listing (not a fresh regen of the whole doc — same hand-patch convention as session 15).

| Rank | Src file | Remaining funcs | Remaining bytes | Already decompiled |
|---:|---|---:|---:|---:|
| 1 | `usb_host_audio_topology.cc` | 8 | 2876 | 0/8 |
| 2 | `audio_states.cc` | 6 | 2392 | 0/6 |
| 3 | `usb_host_audio.cc` | 9 | 2346 | 0/9 |
| 4 | `device_info.cc` | 7 | 2300 | 0/7 |
| 5 | `remote_device_db.cc` | 4 | 2070 | 0/4 |
| 6 | `usb_audio_receive.cc` | 8 | 1994 | 0/8 |
| 7 | `application_state.cc` | 6 | 1956 | 0/6 |
| 8 | `firmware_image_upload.cc` | 1 | 1714 | 0/1 |
| 9 | `ec_asn1.c` | 5 | 1630 | 0/5 |
| 10 | `usb_host_hid.cc` | 3 | 1468 | 0/3 |

(#11, just outside the table: `pem_lib.c`, 3 funcs / 1458 bytes, 0/3 decompiled.)

The USB-audio cluster (`usb_host_audio_topology.cc`, `usb_host_audio.cc`, `usb_audio_receive.cc`, `audio_states.cc` — ranks 1/2/3/6, 9,608 bytes / 31 functions combined) is now even more clearly the single best next lever in this table — still worth doing as one coherent sweep rather than file-by-file, per session 13's original note, untouched since. `application_state.cc` (rank 7) is also a natural pairing with this session's `state_machine.cc` work — `application_state__6005b8dc`/`application_state__6005b1c0` are both direct callers of `state_machine__600849a4` (`bruce-state-machine.md`), so decompiling it would likely resolve that doc's open thread about the OOBE state/event names.

Regenerate the full per-file remaining-function list anytime with:
```python
# addresses in bruce_srcmap.csv for src_file == X, minus addresses with a header-matching file in analysis/decomp/
```
(join key is the 8-hex-digit address suffix on the decomp filename / the first line's address, *not* the filename string.)

### 3b. Unattributed contiguous address ranges — candidate whole modules

Same 168 runs as every prior snapshot (the attributed set hasn't changed, so run boundaries are identical, re-verified this session: span sum 899,666 / code-bytes sum 563,120 = 660,570 − 97,450 exactly) — only the "already decompiled" counts moved.

| # | Start | End | Span (B) | Code bytes | Funcs | Already decompiled | Density | Largest function in range |
|---:|---|---|---:|---:|---:|---:|---:|---|
| 1★ | `0x600921b8` | `0x600c9cc4` | 228108 | 204449 | 1076 | 490 | 89.6% | `FUN_600ba1c4` (3898B @ `600ba1c4`) |
| 2† | `0x600ecb72` | `0x6013d4e4` | 330098 | 95117 | 1006 | 14 | 28.8% | `FUN_601054dc` (2546B @ `601054dc`) |
| 3† | `0x600df286` | `0x600ea868` | 46562 | 44326 | 316 | 15 | 95.2% | `FUN_600e398a` (6270B @ `600e398a`) |
| 4† | `0x600cc6e4` | `0x600d4560` | 32380 | 24998 | 304 | 35 | 77.2% | `FUN_600ccfb4` (1568B @ `600ccfb4`) |
| 5† | `0x600d8a12` | `0x600df24c` | 26682 | 23204 | 399 | 16 | 87.0% | `FUN_600dcf8c` (984B @ `600dcf8c`) |
| 6 | `0x6004cd58` | `0x60051164` | 17420 | 17174 | 10 | 1 | 98.6% | `FUN_6004cdb8` (15662B @ `6004cdb8`) |
| 7 | `0x60086720` | `0x6008ac36` | 17686 | 14608 | 19 | 0 | 82.6% | `FUN_60087970` (4036B @ `60087970`) |
| 8 | `0x60040500` | `0x60047038` | 27448 | 12698 | 92 | 10 | 46.3% | `FUN_60043ecc` (1364B @ `60043ecc`) |
| 9 | `0x60054f30` | `0x60058570` | 13888 | 10908 | 66 | 1 | 78.5% | `FUN_60056fa4` (1694B @ `60056fa4`) |
| 10 | `0x6004898c` | `0x6004cb5c` | 16848 | 10520 | 171 | 25 | 62.4% | `FUN_6004a4e6` (840B @ `6004a4e6`) |
| 11 | `0x600d56b8` | `0x600d89ec` | 13108 | 10254 | 177 | 3 | 78.2% | `FUN_600d80f4` (260B @ `600d80f4`) |
| 12 | `0x6007b96c` | `0x6007e69c` | 11568 | 9552 | 53 | 0 | 82.6% | `FUN_6007d144` (980B @ `6007d144`) |
| 13 | `0x60052294` | `0x60054a46` | 10162 | 8254 | 99 | 3 | 81.2% | `FUN_600526a0` (472B @ `600526a0`) |
| 14 | `0x60072260` | `0x60073b7c` | 6428 | 6400 | 3 | 2 | 99.6% | `FUN_600723b4` (6088B @ `600723b4`) |
| 15 | `0x6006c35c` | `0x6006e480` | 8484 | 5784 | 53 | 0 | 68.2% | `FUN_6006d998` (712B @ `6006d998`) |

★ = fully identified module (§1a) — the confirmed BTA/BTE stack.
† = **partially identified this round** — `analysis/bruce-log-buffer.md` (sessions 14–15) traced real, named clusters inside these four runs (same representational pattern as the ★ marker, one tier down in confidence/completeness — see below). Not a whole-range identification like BTA/BTE; each of these runs is still mostly either genuinely unidentified or generic C-library code, with the log-buffer-framework functions accounting for only a modest slice of each run's *decompiled* count, not its total.

Per-range deltas vs. the session-13 snapshot, for the top 15: run #1 (BTA) **410→490** (+80, the concurrent session caught mid-run by this snapshot — see §1a), run #2 **5→14** (+9, `bruce-log-buffer.md`'s emit/append/sink engine + the `StreamLogBuffer` RPC handler + the 16-entry debug-command dispatch table, all sitting in this run's `0x60100exx`–`0x60103xxx` sub-span), run #3 **9→15** (+6, a BoringSSL/OpenSSL runtime-support extension — `ERR_put_error`-shaped ring buffer, `OPENSSL_malloc`-shaped allocator, bignum helpers — called from `bcm.c`/`evp.c`/`tasn_dec.c`, not part of the log-buffer framework itself but found via the same session's sweep), run #4 **4→35** (+31, the single biggest scattered mover — the log-buffer framework's core buffer ctor/dtor/emit cluster, plus incidentally-identified fdlibm-shaped float math and a newlib `vfprintf`-shaped formatter core, all coexisting in this one range), run #5 **7→16** (+9, a GKI buffer-pool free-list allocator pair plus BTA/BTE-control-block-shaped zero-init code — extends `bruce-bta-stack.md`'s territory beyond its formal block boundary — plus one stray radix-4 FFT butterfly), run #6–8/10–15 **unchanged** except run #9 **0→1** (+1, untraced this session, likely incidental). Full per-run detail and evidence for all of these is in `bruce-log-buffer.md`, not reproduced here.

**#1 remains the headline finding by size**: `0x600921b8`–`0x600c9cc4`, 204,449 bytes of dense (89.6%) code across 1,076 functions, the confirmed Broadcom BTA/BTE Bluetooth stack (`analysis/bruce-bta-stack.md`), now **72.9% decompiled by size** (up from 63.3% at session 13, and that jump happened *during this session's own snapshot-taking* — see §1a). **586 functions / 55,458 bytes remain in this block.**

Run #2 (`0x600ecb72`–`0x6013d4e4`, 330 KB span, still only 28.8% density) remains the largest still-mostly-unmapped range. `bruce-bta-stack.md` separately notes `smp_sm_event`'s 54 callers live in `0x600faxxx`–`0x600fcxxx`, inside this run — still strong circumstantial evidence for a real pocket of SMP per-state-handler code here, not yet swept. `bruce-log-buffer.md` additionally confirms this run's `0x60102xxx`–`0x60103xxx` sub-span is a dense mixed debug/diagnostic string-table region (RPC command names, Synaptics audio-debug strings, the BTA build-banner string all sit within a few hundred bytes of each other) — useful color for anyone navigating this run next, but not itself a large decompile win. Still the best candidate for genuinely new-territory progress at scale.

## 4. The honest bottom line

Of **4,995 total functions** (the current census — see the 5,137-vs-4,995 discrepancy note in §1):

| | Functions | Bytes |
|---|---:|---:|
| Attributed to a source file | 448 | 97,450 |
| Decompiled (in census) | 836 | 246,879 |
| — of which both attributed AND decompiled | 160 | 38,514 |
| — of which in the identified-but-not-formally-attributed BTA/BTE stack (§1a) | 490 | 148,991 |
| **Understood in some way (union)** | **1,124 (22.5%)** | **305,815 (46.3%)** |
| **Completely unknown — no attribution, no decompile, no module ID** | 3,871 (77.5%), or **3,285 (65.8%) excluding BTA-identified** | 354,755 (53.7%), or **299,297 (45.3%) excluding BTA-identified** |

**Compared to the session-13 snapshot: union coverage grew by function count (19.5% → 22.5%) and by byte-weight (41.4% → 46.3%).** The "truly unidentified, no module guess at all" byte figure improved from 47.3% to **45.3%**, a real ~2-point gain — and unlike the session-8→13 comparison (where most gains sat inside the already-identified BTA block and didn't move this number at all), **this round's improvement is entirely attributable to genuinely new territory** opened by the log-buffer-framework work (sessions 14–15) and its incidental BoringSSL/GKI extensions. This is provable directly from the numbers: the "truly unidentified" byte figure is mathematically *exactly* `358,671 − (scattered non-BTA-non-attributed decompiled bytes)` — a fixed constant (`total_bytes − attributed_bytes − BTA_block_bytes`) minus whatever's been decompiled outside both the attributed set and the BTA block. BTA/BTE progress (even this session's own concurrent +80-function jump) provably cannot move this number by construction; only work in the "scattered" bucket can, and this round scattered grew by 13,090 bytes (118→186 functions) — the log-buffer framework's genuine contribution. Worth internalizing this distinction going forward: **BTA/BTE progress is valuable (it's finishing an already-mapped subsystem) but it will never shrink the "truly unidentified" figure — only work that identifies genuinely new clusters (like session 14's log-buffer find) does that.**

**3,285 functions and ~299 KB of code — just under half the binary by size — remain truly unidentified with no attribution, no decompile, and no module ID of any kind.** That's the real remaining scope of the "full decompile to source-reconstruction quality" goal. The single best next lever by size is still finishing §1a/§3b-run-#1 (586 functions / 55,458 bytes still to decompile, but already identified, cheap in the "no more detective work needed" sense — and apparently already being worked concurrently as of this snapshot); the best candidate for *new* territory at scale remains run #2 (330 KB, mixed ITCM-thunk mechanical work, a real pocket of SMP state-handler code, and a debug-string-table region, per `bruce-bta-stack.md` and `bruce-log-buffer.md`); and the top-10 cheap-win attributed files in §3a (`usb_host_audio_topology.cc` and the rest of the USB-audio cluster, `state_machine.cc`, `device_info.cc`, `remote_device_db.cc`, `key_value_store.cc`, `application_state.cc`, `tasks.c`) remain completely untouched since session 13.

## Methodology (for regenerating this doc)

Inputs: `analysis/ghidra/bruce_functions.csv` (address, name, size_bytes — full census), `analysis/ghidra/bruce_srcmap.csv` (address, name, src_file — 448-row attribution), `analysis/decomp/*.c` (one file per decompiled function; first line is a `// <addr>  <name>  size=<N> bytes` header written by `Decompile.java` — parse *that*, not the filename, for address/size ground truth).

Join key is always the **8-hex-digit address**, lowercase, zero-padded — not the name string. Same gotchas as every prior session, still true:
1. `bruce_functions.csv`'s `name` column is stale (pre-attribution `FUN_xxxxxxxx` defaults) for every one of the 448 attributed addresses; only `bruce_srcmap.csv` has the current name. Sizes/addresses in `bruce_functions.csv` are fine (re-spot-checked this session: 0 mismatches between census size and decomp-header size across all 836 in-census decompiled functions).
2. Not every file in `analysis/decomp/` corresponds to a census address — `Decompile.java` will create a function (and thus a decomp file) at an address Ghidra's auto-analysis didn't already recognize as a function boundary. 140 of 976 current decomp files are like this (all ≤364 bytes, same pattern as prior sessions) — exclude them from census-relative stats or the percentages won't reconcile against `bruce_functions.csv`'s totals.
3. For any block identified by means *other* than `bruce_srcmap.csv` (i.e. string-table cross-reference, as in `bruce-bta-stack.md`, or call-graph/shape identification, as in `bruce-log-buffer.md`, rather than a leaked `__FILE__` path): **do not fold it into the "Attributed" join.** Keep it as a separate reported tier or annotation (§1a's numeric tier for the large, cleanly-bounded BTA/BTE block; §3b's lighter-weight `†` annotation for the log-buffer framework's more scattered, partial-range identifications) so the core `bruce_srcmap.csv`-based join stays a clean, mechanically-reproducible number, while still surfacing that "unattributed" isn't the same thing as "unidentified." When computing §1a's own decompiled-count, use a fresh strict address-join against the current `analysis/decomp/` state — **don't** just copy `bruce-bta-stack.md`'s self-reported running-count prose, which lags well behind the actual directory contents (this session found 490/1,076 by join vs. that doc's stale self-reported figures from session 9).

Unattributed contiguous ranges (§3b) = walk `bruce_functions.csv` in address order, group maximal runs where no function's address is in the attributed set, compute span (last function's end − first function's start) and code_bytes (sum of `size_bytes` in the run) separately since span includes non-function bytes.

**A note on snapshot consistency**, reconfirmed again this session (first learned session 13): if `analysis/decomp/` is being actively written to by a concurrent session, take **one single directory listing + parse pass** and derive every table in the doc from that same in-memory snapshot, rather than re-listing the directory for each table. This session's first exploratory pass read 896 decomp files; a routine re-check 90 seconds later found 976 — the gap was entirely inside the BTA/BTE block (410→490 decompiled), consistent with a concurrent session actively sweeping that exact block. All of this doc's final numbers are from a single, final 976-file read (parsed once, cached, and reused for every table above) — using a stale count for one table and a fresher one for another would have produced internally-inconsistent numbers (e.g. a per-file table that doesn't sum to the top-line total, or a §1a figure that doesn't match §4's).

See also: `bruce-ghidra.md` (workspace/tooling, original module-mass table), `bruce-io-paths.md` / `bruce-crypto.md` / `bruce-itcm.md` (subsystem-level narrative findings for functions already decompiled), `bruce-bta-stack.md` (the BTA/BTE stack identification and address-range map — its prose is stale relative to this doc's function-count/byte figures as of this snapshot, see §1a), `bruce-log-buffer.md` (the codebase-wide log/message-buffer framework — sessions 14–15, see §2/§3b), `firmware-map.md` (bruce vs gotham top-level structure).

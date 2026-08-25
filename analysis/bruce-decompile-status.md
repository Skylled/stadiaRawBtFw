# Bruce — full-decompile tracking status

Data-driven status doc for the "decompile all of `bruce` to source-reconstruction quality" effort. Regenerate the numbers here whenever `bruce_functions.csv`, `bruce_srcmap.csv`, or `analysis/decomp/` change materially — don't hand-edit stale tables into new prose, just re-run the join described in [Methodology](#methodology) below.

**Snapshot: 2026-08-18 (full regeneration, session 137 / Wave 107).** This is a **full regeneration**, not a hand-patch — every table below comes from a fresh address-based join against `bruce_functions.csv`, `bruce_srcmap.csv`, and a directory listing of `analysis/decomp/` taken at the conclusion of session 137 (3458 decomp files, 3458 in-census). Decompiled in-census functions grew to **3458** (510,250 bytes, 71.40% of code), with **139 of 139** attributed source files fully decompiled.

## 1. Top-line stats

| Metric | Functions | % of 5,566 | Bytes | % of 714,601 |
|---|---:|---:|---:|---:|
| **Total functions (census)** | 5,566 | 100% | 714,601 | 100% |
| **Attributed** (leaked `__FILE__` → 139 src files) | 448 | 8.05% | 96,312 | 13.48% |
| **Decompiled** (`analysis/decomp/*.c`, matched to census) | 3,458 | 62.13% | 510,250 | 71.40% |
| **Attributed ∪ Decompiled** (understood in *some* way) | 3,458 | 62.13% | 510,250 | **71.40%** |
| **Totally unknown** (no attribution, no decompile) | 2,108 | 37.87% | 204,351 | **28.60%** |

### 1a. Module-identified-but-not-formally-attributed (informational — not folded into "Attributed" above)

`analysis/bruce-bta-stack.md` identifies the entire `0x600921b8`–`0x600c9cc4` range as the Broadcom BTA/BTE stack via a ~400-entry leaked function-name string table cross-referenced with `FindRef.java`, plus independent spec-level confirmation (HCI opcodes, HCI/LE-Meta event codes, SDP/GAP framing bytes — see that doc for full evidence). Kept as its own tier.

| | Functions | Bytes | % of block |
|---|---:|---:|---:|
| BTA/BTE block total | 1,116 | 213,911 | 100% |
| — decompiled (also counted in §1's "Decompiled" row) | 1,116 | 213,911 | 100.0% |
| — **identified but not yet decompiled** | 0 | 0 | 0.0% |

Netting this out against §1's "Totally unknown" row gives the true unidentified figure:

| | Functions | % of 5,566 | Bytes | % of 714,601 |
|---|---:|---:|---:|---:|
| Totally unknown (§1, includes BTA-identified-but-undecompiled) | 2,108 | 37.87% | 204,351 | 28.60% |
| — of which: BTA-identified, module known, just not decompiled | 0 | 0.00% | 0 | 0.00% |
| **— truly unidentified (no attribution, no decompile, no module ID)** | **2,108** | **37.87%** | **204,351** | **28.60%** |

## 2. Per-source-file table (all 139 attributed files, sorted by total byte size descending)

"Decompiled funcs/bytes" = how many of that file's *attributed* functions have a matching file in `analysis/decomp/` (cross-referenced by address).

| Src file | Attributed funcs | Decompiled funcs | Total bytes | Decompiled bytes | Remaining bytes |
|---|---:|---:|---:|---:|---:|
| `bcm.c` | 52 | 52 | 10770 | 10770 | 0 |
| `timer.h` | 9 | 9 | 4016 | 4016 | 0 |
| `tasn_dec.c` | 7 | 7 | 3856 | 3856 | 0 |
| `state_machine.cc` | 11 | 11 | 3332 | 3332 | 0 |
| `keys.cc` | 19 | 19 | 3296 | 3296 | 0 |
| `adapter.cc` | 16 | 16 | 3216 | 3216 | 0 |
| `usb_host_audio_topology.cc` | 8 | 8 | 2876 | 2876 | 0 |
| `audio_states.cc` | 6 | 6 | 2392 | 2392 | 0 |
| `usb_host_audio.cc` | 9 | 9 | 2346 | 2346 | 0 |
| `device_info.cc` | 7 | 7 | 2300 | 2300 | 0 |
| `tasks.c` | 19 | 19 | 2220 | 2220 | 0 |
| `remote_device_db.cc` | 4 | 4 | 2070 | 2070 | 0 |
| `gatt_server.cc` | 8 | 8 | 2028 | 2028 | 0 |
| `usb_audio_receive.cc` | 8 | 8 | 1994 | 1994 | 0 |
| `key_value_store.cc` | 6 | 6 | 1968 | 1968 | 0 |
| `application_state.cc` | 6 | 6 | 1956 | 1956 | 0 |
| `firmware_image_upload.cc` | 1 | 1 | 1714 | 1714 | 0 |
| `ec_asn1.c` | 5 | 5 | 1630 | 1630 | 0 |
| `queue.c` | 12 | 12 | 1540 | 1540 | 0 |
| `usb_host_hid.cc` | 3 | 3 | 1468 | 1468 | 0 |
| `pem_lib.c` | 3 | 3 | 1458 | 1458 | 0 |
| `xbara.h` | 2 | 2 | 1246 | 1246 | 0 |
| `main.cc` | 2 | 2 | 1128 | 1128 | 0 |
| `http_flash_writer.cc` | 4 | 4 | 1116 | 1116 | 0 |
| `synapse_audio_processor.cc` | 2 | 2 | 1060 | 1060 | 0 |
| `thermal.cc` | 4 | 4 | 912 | 912 | 0 |
| `gotham.cc` | 5 | 5 | 882 | 882 | 0 |
| `stats.cc` | 1 | 1 | 816 | 816 | 0 |
| `receiver.cc` | 4 | 4 | 812 | 812 | 0 |
| `battery_gauge_bq2742X.cc` | 3 | 3 | 808 | 808 | 0 |
| `usb_device_cdc_acm.c` | 3 | 3 | 750 | 750 | 0 |
| `sleep_driver.cc` | 1 | 1 | 744 | 744 | 0 |
| `flash_lut.cc` | 3 | 3 | 706 | 706 | 0 |
| `headphone_state_machine.cc` | 5 | 5 | 672 | 672 | 0 |
| `bug_report.cc` | 4 | 4 | 660 | 660 | 0 |
| `heap_5_improved.c` | 4 | 4 | 650 | 650 | 0 |
| `usb_device.cc` | 5 | 5 | 578 | 578 | 0 |
| `led_driver_lp5562.cc` | 3 | 3 | 548 | 548 | 0 |
| `usb_device_audio.cc` | 3 | 3 | 540 | 540 | 0 |
| `usb_host.cc` | 3 | 3 | 526 | 526 | 0 |
| `haptics.cc` | 3 | 3 | 526 | 526 | 0 |
| `gatt_manager_task.cc` | 4 | 4 | 518 | 518 | 0 |
| `mimxrt10xx_flash_memory.cc` | 2 | 2 | 512 | 512 | 0 |
| `usb_port_controller_tusb320.cc` | 4 | 4 | 508 | 508 | 0 |
| `battery_service.cc` | 3 | 3 | 506 | 506 | 0 |
| `recording_pipeline.cc` | 3 | 3 | 500 | 500 | 0 |
| `p_x25519_asn1.c` | 4 | 4 | 492 | 492 | 0 |
| `p_ed25519_asn1.c` | 4 | 4 | 474 | 474 | 0 |
| `activation_sequence.cc` | 2 | 2 | 468 | 468 | 0 |
| `ble_info.cc` | 2 | 2 | 466 | 466 | 0 |
| `sai.cc` | 5 | 5 | 450 | 450 | 0 |
| `mpu.cc` | 1 | 1 | 440 | 440 | 0 |
| `trigger_bug_report.cc` | 2 | 2 | 438 | 438 | 0 |
| `bee.cc` | 2 | 2 | 436 | 436 | 0 |
| `battery_charger_bq25601.h` | 4 | 4 | 432 | 432 | 0 |
| `types.h` | 3 | 3 | 424 | 424 | 0 |
| `asn1_lib.c` | 3 | 3 | 422 | 422 | 0 |
| `gatt_server.h` | 3 | 3 | 418 | 418 | 0 |
| `frames.h` | 2 | 2 | 402 | 402 | 0 |
| `timers.c` | 5 | 5 | 360 | 360 | 0 |
| `p_dsa_asn1.c` | 2 | 2 | 332 | 332 | 0 |
| `haptics_cluster.cc` | 2 | 2 | 332 | 332 | 0 |
| `input_task.cc` | 2 | 2 | 330 | 330 | 0 |
| `partition_table.h` | 2 | 2 | 324 | 324 | 0 |
| `audio_player.cc` | 2 | 2 | 322 | 322 | 0 |
| `io_pin.cc` | 1 | 1 | 318 | 318 | 0 |
| `advertiser.cc` | 1 | 1 | 316 | 316 | 0 |
| `pattern_player.cc` | 1 | 1 | 308 | 308 | 0 |
| `p_rsa_asn1.c` | 2 | 2 | 298 | 298 | 0 |
| `private_heap.cc` | 3 | 3 | 292 | 292 | 0 |
| `battery_gauge_bq2742X.h` | 1 | 1 | 290 | 290 | 0 |
| `a_int.c` | 1 | 1 | 286 | 286 | 0 |
| `a_object.c` | 2 | 2 | 274 | 274 | 0 |
| `bn_asn1.c` | 2 | 2 | 272 | 272 | 0 |
| `usb_host_worker.cc` | 3 | 3 | 268 | 268 | 0 |
| `gki_ft.c` | 2 | 2 | 268 | 268 | 0 |
| `dcp_encryption_engine.cc` | 2 | 2 | 266 | 266 | 0 |
| `adc.h` | 1 | 1 | 248 | 248 | 0 |
| `sleep_lock.cc` | 1 | 1 | 238 | 238 | 0 |
| `switch_pro_controller.cc` | 1 | 1 | 236 | 236 | 0 |
| `usb_audio_send.cc` | 1 | 1 | 230 | 230 | 0 |
| `board.cc` | 2 | 2 | 230 | 230 | 0 |
| `power_rpcs.cc` | 1 | 1 | 228 | 228 | 0 |
| `dynamic_buffer.h` | 2 | 2 | 226 | 226 | 0 |
| `a_bitstr.c` | 1 | 1 | 218 | 218 | 0 |
| `logger.cc` | 1 | 1 | 216 | 216 | 0 |
| `bio.c` | 3 | 3 | 200 | 200 | 0 |
| `binary_build_metadata.cc` | 1 | 1 | 194 | 194 | 0 |
| `pattern_player.h` | 1 | 1 | 190 | 190 | 0 |
| `gotham_patterns.cc` | 1 | 1 | 190 | 190 | 0 |
| `hardware_timer.cc` | 1 | 1 | 188 | 188 | 0 |
| `append_buffer.h` | 2 | 2 | 186 | 186 | 0 |
| `sound_codec_wm8904.cc` | 2 | 2 | 184 | 184 | 0 |
| `external_controller.cc` | 1 | 1 | 180 | 180 | 0 |
| `led_calibration.cc` | 1 | 1 | 178 | 178 | 0 |
| `hid_input_target.cc` | 1 | 1 | 172 | 172 | 0 |
| `linear_interpolation_source.h` | 1 | 1 | 170 | 170 | 0 |
| `platform.h` | 1 | 1 | 164 | 164 | 0 |
| `ex_data.c` | 1 | 1 | 160 | 160 | 0 |
| `audio_tasks.cc` | 1 | 1 | 158 | 158 | 0 |
| `reset.cc` | 2 | 2 | 148 | 148 | 0 |
| `accessory_detect_ts3a227e.cc` | 1 | 1 | 140 | 140 | 0 |
| `snvs.h` | 1 | 1 | 138 | 138 | 0 |
| `parser.cc` | 1 | 1 | 136 | 136 | 0 |
| `get_device_data.cc` | 1 | 1 | 134 | 134 | 0 |
| `wakelock.cc` | 1 | 1 | 132 | 132 | 0 |
| `util.cc` | 1 | 1 | 132 | 132 | 0 |
| `gotham_16mb_mimxrt10xx_mpu.cc` | 1 | 1 | 132 | 132 | 0 |
| `adapter.h` | 2 | 2 | 132 | 132 | 0 |
| `flash_memory.h` | 1 | 1 | 130 | 130 | 0 |
| `event_groups.c` | 2 | 2 | 128 | 128 | 0 |
| `buffer.h` | 1 | 1 | 128 | 128 | 0 |
| `buf.c` | 2 | 2 | 122 | 122 | 0 |
| `pwm.h` | 3 | 3 | 116 | 116 | 0 |
| `uart.cc` | 1 | 1 | 114 | 114 | 0 |
| `battery_charger_bq25601.cc` | 2 | 2 | 114 | 114 | 0 |
| `usb_configuration_handler.cc` | 1 | 1 | 112 | 112 | 0 |
| `reboot_reason.cc` | 1 | 1 | 108 | 108 | 0 |
| `tasn_new.c` | 2 | 2 | 104 | 104 | 0 |
| `obj.c` | 1 | 1 | 102 | 102 | 0 |
| `tasn_utl.c` | 1 | 1 | 100 | 100 | 0 |
| `system_tasks.cc` | 1 | 1 | 100 | 100 | 0 |
| `persistent_crash_register.cc` | 1 | 1 | 100 | 100 | 0 |
| `i2c_device.h` | 1 | 1 | 100 | 100 | 0 |
| `logging.cc` | 1 | 1 | 98 | 98 | 0 |
| `buffer.cc` | 1 | 1 | 94 | 94 | 0 |
| `ecdsa_asn1.c` | 1 | 1 | 92 | 92 | 0 |
| `pem_oth.c` | 1 | 1 | 88 | 88 | 0 |
| `key_value_store.h` | 1 | 1 | 88 | 88 | 0 |
| `srtc.cc` | 1 | 1 | 80 | 80 | 0 |
| `evp.c` | 1 | 1 | 70 | 70 | 0 |
| `dsa.c` | 1 | 1 | 64 | 64 | 0 |
| `info.cc` | 1 | 1 | 62 | 62 | 0 |
| `transfer_bug_report.cc` | 1 | 1 | 48 | 48 | 0 |
| `heap_support.c` | 1 | 1 | 44 | 44 | 0 |
| `gotham_task.cc` | 1 | 1 | 44 | 44 | 0 |
| `gatt_service_handle.h` | 1 | 1 | 28 | 28 | 0 |
| `init.cc` | 1 | 1 | 22 | 22 | 0 |
| `exit.c` | 1 | 1 | 16 | 16 | 0 |

## 3. Prioritized gap list

### 3a. Attributed-but-not-yet-decompiled — cheapest wins (top 10 zero-progress files by remaining bytes)

| Rank | Src file | Remaining funcs | Remaining bytes | Already decompiled |
|---:|---|---:|---:|---:|

### 3b. Unattributed contiguous address ranges — candidate whole modules

| # | Start | End | Span (B) | Code bytes | Funcs | Already decompiled | Density | Largest function in range |
|---:|---|---|---:|---:|---:|---:|---:|---|
| 1★ | `0x600921b8` | `0x600c9cc4` | 228108 | 213911 | 1116 | 1116 | 93.8% | `FUN_600ba1c4` (3898B @ `600ba1c4`) |
| 2 | `0x600ecb50` | `0x6013d4e4` | 330132 | 97789 | 1046 | 492 | 29.6% | `FUN_601054dc` (2546B @ `601054dc`) |
| 3† | `0x600df286` | `0x600ea868` | 46562 | 44670 | 333 | 333 | 95.9% | `FUN_600e398a` (6270B @ `600e398a`) |
| 4† | `0x600cc6e4` | `0x600d4596` | 32434 | 27319 | 342 | 341 | 84.2% | `FUN_600ccfb4` (1568B @ `600ccfb4`) |
| 5 | `0x60040500` | `0x6004712c` | 27692 | 25488 | 172 | 61 | 92.0% | `FUN_60043ecc` (1364B @ `60043ecc`) |
| 6† | `0x600d8a12` | `0x600df24c` | 26682 | 23964 | 431 | 406 | 89.8% | `FUN_600dcf8c` (984B @ `600dcf8c`) |
| 7 | `0x6004cd58` | `0x60051164` | 17420 | 17174 | 10 | 1 | 98.6% | `FUN_6004cdb8` (15662B @ `6004cdb8`) |
| 8 | `0x6004898c` | `0x6004cbd2` | 16966 | 15324 | 324 | 67 | 90.3% | `FUN_6004a4e6` (840B @ `6004a4e6`) |
| 9 | `0x60086720` | `0x6008ac36` | 17686 | 15170 | 20 | 0 | 85.8% | `FUN_60087970` (4036B @ `60087970`) |
| 10 | `0x60054f30` | `0x60058570` | 13888 | 11202 | 70 | 4 | 80.7% | `FUN_60056fa4` (1694B @ `60056fa4`) |
| 11 | `0x600d56b8` | `0x600d89ec` | 13108 | 10756 | 193 | 6 | 82.1% | `FUN_600d80f4` (260B @ `600d80f4`) |
| 12 | `0x6007b96c` | `0x6007e69c` | 11568 | 10562 | 55 | 0 | 91.3% | `FUN_6007d144` (980B @ `6007d144`) |
| 13 | `0x60052294` | `0x60054a46` | 10162 | 8444 | 102 | 3 | 83.1% | `FUN_600526a0` (472B @ `600526a0`) |
| 14 | `0x60072260` | `0x60073b7c` | 6428 | 6400 | 3 | 2 | 99.6% | `FUN_600723b4` (6088B @ `600723b4`) |
| 15 | `0x600ea86e` | `0x600ebf76` | 5896 | 5896 | 64 | 64 | 100.0% | `FUN_600ea8d8` (610B @ `600ea8d8`) |

## 4. The honest bottom line

Of **5,566 total functions** (the current census):

| | Functions | Bytes |
|---|---:|---:|
| Attributed to a source file | 448 | 96,312 |
| Decompiled (in census) | 3,458 | 510,250 |
| — of which both attributed AND decompiled | 448 | 96,312 |
| — of which in the identified-but-not-formally-attributed BTA/BTE stack (§1a) | 1,116 | 213,911 |
| **Understood in some way (union)** | **3,458 (62.1%)** | **510,250 (71.4%)** |
| **Completely unknown — no attribution, no decompile, no module ID** | 2,108 (37.9%), or **2,108 (37.9%) excluding BTA-identified** | 204,351 (28.6%), or **204,351 (28.6%) excluding BTA-identified** |

## Methodology (for regenerating this doc)

Inputs: `analysis/ghidra/bruce_functions.csv` (address, name, size_bytes — full census), `analysis/ghidra/bruce_srcmap.csv` (address, name, src_file — 448-row attribution), `analysis/decomp/*.c` (one file per decompiled function; first line is a `// <addr>  <name>  size=<N> bytes` header written by `Decompile.java` — parse *that*, not the filename, for address/size ground truth).

Join key is always the **8-hex-digit address**, lowercase, zero-padded — not the name string. Same gotchas as every prior session, still true:
1. `bruce_functions.csv`'s `name` column is stale (pre-attribution `FUN_xxxxxxxx` defaults) for every one of the 448 attributed addresses; only `bruce_srcmap.csv` has the current name. Sizes/addresses in `bruce_functions.csv` are fine (re-verified clean in session 63: 0 mismatches between census size and decomp-header size across all in-census decompiled functions, after re-decompiling the 3 historical edge cases 0x60042050, 0x60096a50, and 0x60069ed4).
2. Every file in `analysis/decomp/` corresponds to a valid in-census address (0 non-census decomp files across all decompiled files).

3. For any block identified by means *other* than `bruce_srcmap.csv` (i.e. string-table cross-reference, as in `bruce-bta-stack.md`, or call-graph/shape identification, as in `bruce-log-buffer.md`, rather than a leaked `__FILE__` path): **do not fold it into the "Attributed" join.** Keep it as a separate reported tier or annotation (§1a's numeric tier for the large, cleanly-bounded BTA/BTE block; §3b's lighter-weight `†` annotation for the log-buffer framework's more scattered, partial-range identifications) so the core `bruce_srcmap.csv`-based join stays a clean, mechanically-reproducible number, while still surfacing that "unattributed" isn't the same thing as "unidentified." When computing §1a's own decompiled-count, use a fresh strict address-join against the current `analysis/decomp/` state — **don't** just copy `bruce-bta-stack.md`'s self-reported running-count prose, which lags well behind the actual directory contents.
4. When the union/truly-unidentified top-line numbers don't move between two full regenerations despite `analysis/decomp/` growing substantially, don't assume a bug — check whether the growth landed entirely inside already-attributed files (§1's "structural consequence" note). Both top-line metrics are address-set-membership counts, not "depth of understanding" scores; finishing an already-counted file is real progress that these particular numbers are structurally blind to. Cross-check via the "both attributed and decompiled" count (§4's second row) — if *its* growth equals the total decompiled-count growth, that's confirmation, not coincidence.
5. **Session-numbering note**: this doc's own labels (and every subsystem doc's own section headers — `bruce-itcm.md`, `bruce-state-machine.md`, `bruce-audio-subsystem.md`, `bruce-misc-functions.md`, `bruce-bta-stack.md`) run one lower than the git commit messages for the same content (e.g. the `tasks.c`/`state_machine.cc`/`key_value_store.cc` round is "session 17" throughout the analysis docs but commit `690bac1` calls it "session 18"; session 23 is committed as `8271360`). This doc follows the analysis-doc-internal numbering, not the git commit numbering, for cross-reference consistency — don't "fix" one without fixing all of them together.

Unattributed contiguous ranges (§3b) = walk `bruce_functions.csv` in address order, group maximal runs where no function's address is in the attributed set, compute span (last function's end − first function's start) and code_bytes (sum of `size_bytes` in the run) separately since span includes non-function bytes. Ranked by `code_bytes` descending (not span) — this is why run #1 (228,108B span, 204,449B code) outranks run #2 (330,098B span, 95,117B code) despite the smaller span.

See also: `bruce-ghidra.md` (workspace/tooling, original module-mass table), `bruce-io-paths.md` / `bruce-crypto.md` / `bruce-itcm.md` (subsystem-level narrative findings for functions already decompiled), `bruce-bta-stack.md` (the BTA/BTE stack identification and address-range map), `bruce-log-buffer.md` (the codebase-wide log/message-buffer framework), `bruce-state-machine.md` / `bruce-audio-subsystem.md` / `bruce-misc-functions.md` / `bruce-itcm.md` (subsystem write-ups for completed files), `firmware-map.md` (bruce vs gotham top-level structure).

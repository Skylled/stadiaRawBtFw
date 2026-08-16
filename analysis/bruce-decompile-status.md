# Bruce — full-decompile tracking status

Data-driven status doc for the "decompile all of `bruce` to source-reconstruction quality" effort. Regenerate the numbers here whenever `bruce_functions.csv`, `bruce_srcmap.csv`, or `analysis/decomp/` change materially — don't hand-edit stale tables into new prose, just re-run the join described in [Methodology](#methodology) below.

**Snapshot: 2026-08-15 22:43 EDT.** `analysis/decomp/` is under active, ongoing expansion by a concurrent Ghidra session (grew 82 → 146 `.c` files during the ~20 minutes this doc was being built) — treat every count below as a lower bound as of the snapshot time, not a hard current total. Re-run before trusting exact numbers for planning.

## 1. Top-line stats

| Metric | Functions | % of 4,995 | Bytes | % of 660,570 |
|---|---:|---:|---:|---:|
| **Total functions (census)** | 4,995 | 100% | 660,570 | 100% |
| **Attributed** (leaked `__FILE__` → 139 src files) | 448 | 8.97% | 97,450 | 14.75% |
| **Decompiled** (`analysis/decomp/*.c`, matched to a census address) | 80 | 1.60% | 57,558 | 8.71% |
| **Attributed ∪ Decompiled** (understood in *some* way) | 494 | 9.89% | 145,522 | **22.03%** |
| **Totally unknown** (no attribution, no decompile) | 4,501 | 90.11% | 515,048 | **77.97%** |

Size-weighted (bytes) is the more honest progress metric than function-count, since a handful of huge functions (the 15,662-byte SHA-512 compressor, several 2–6 KB Curve25519 field-arithmetic functions) dominate the byte total disproportionately to their count. **Bottom line: ~22% of the binary's code by size is understood in some way; ~78% (515 KB across 4,501 functions) is completely unmapped.**

Notes on the numbers:
- **CLAUDE.md / project memory says "5,137 functions"** — the current `bruce_functions.csv` has only 4,995 data rows (no dupes, no parse issues). This is a ~142-function discrepancy against the documented figure, most likely from a project re-import/re-analysis pass between sessions that landed a slightly different auto-analysis function count. Worth a one-line note/correction in `bruce-ghidra.md` next time someone's in there, but not chased further here.
- **`bruce_functions.csv`'s `name` column is stale for all 448 attributed addresses** — every one of them still shows a default `FUN_xxxxxxxx` name in `bruce_functions.csv`, while `bruce_srcmap.csv` has the real attributed name (`<stem>__<addr>`) for the same address. This means `DumpMap.java` was run *before* `AnnotateFromFilenames.java` last renamed things, and never re-run after. **Always join on `address`, never trust `bruce_functions.csv`'s `name` for an attributed function** — use `bruce_srcmap.csv`'s `name` instead. Sizes and addresses in `bruce_functions.csv` are otherwise reliable (spot-checked against every decomp file's header comment: 0 mismatches).
- Of the 146 files currently in `analysis/decomp/`, only 80 map onto an address in the 4,995-function census. The other **66 are tiny (2–364 byte, mostly ≤32 byte) functions that Decompile.java carved out on demand** at addresses the main auto-analysis pass didn't recognize as standalone functions — consistent with the ITCM-thunk/veneer work described in `bruce-itcm.md`. They're real decompiled code (7,196 bytes worth) but sit outside the 4,995/660,570 baseline, so they're tracked separately rather than folded into the top-line % (folding them in would make the denominator inconsistent with the rest of this doc).
- Of the 80 in-census decompiled functions, only **34 are also attributed** to a source file — the other 46 are decompiled-but-unattributed (mostly the crypto stack in `bruce-crypto.md` and I/O-path functions in `bruce-io-paths.md` that were decompiled by address before/without file attribution).

## 2. Per-source-file table (all 139 attributed files, sorted by total byte size descending)

"Decompiled funcs/bytes" = how many of that file's *attributed* functions have a matching file in `analysis/decomp/` (cross-referenced by address, not name — see note above). Full module-subsystem descriptions are in `bruce-ghidra.md`'s "Module mass" table; this table supersedes it for exact counts (that table lists top ~20 by function count only, this one is byte-sorted and complete).

| Src file | Attributed funcs | Decompiled funcs | Total bytes | Decompiled bytes | Remaining bytes |
|---|---:|---:|---:|---:|---:|
| `bcm.c` | 52 | 0 | 11548 | 0 | 11548 |
| `timer.h` | 9 | 2 | 4016 | 2600 | 1416 |
| `tasn_dec.c` | 7 | 0 | 3856 | 0 | 3856 |
| `state_machine.cc` | 11 | 0 | 3332 | 0 | 3332 |
| `keys.cc` | 19 | 2 | 3296 | 280 | 3016 |
| `adapter.cc` | 16 | 0 | 3216 | 0 | 3216 |
| `usb_host_audio_topology.cc` | 8 | 0 | 2876 | 0 | 2876 |
| `audio_states.cc` | 6 | 0 | 2392 | 0 | 2392 |
| `usb_host_audio.cc` | 9 | 0 | 2346 | 0 | 2346 |
| `device_info.cc` | 7 | 0 | 2300 | 0 | 2300 |
| `tasks.c` | 19 | 3 | 2220 | 360 | 1860 |
| `remote_device_db.cc` | 4 | 0 | 2070 | 0 | 2070 |
| `gatt_server.cc` | 8 | 0 | 2028 | 0 | 2028 |
| `usb_audio_receive.cc` | 8 | 0 | 1994 | 0 | 1994 |
| `key_value_store.cc` | 6 | 0 | 1968 | 0 | 1968 |
| `application_state.cc` | 6 | 0 | 1956 | 0 | 1956 |
| `firmware_image_upload.cc` | 1 | 0 | 1714 | 0 | 1714 |
| `ec_asn1.c` | 5 | 0 | 1630 | 0 | 1630 |
| `queue.c` | 12 | 6 | 1540 | 1090 | 450 |
| `usb_host_hid.cc` | 3 | 0 | 1468 | 0 | 1468 |
| `pem_lib.c` | 3 | 0 | 1458 | 0 | 1458 |
| `xbara.h` | 2 | 1 | 1246 | 1172 | 74 |
| `main.cc` | 2 | 1 | 1128 | 96 | 1032 |
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
| `heap_5_improved.c` | 4 | 0 | 650 | 0 | 650 |
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
| `gatt_server.h` | 3 | 0 | 418 | 0 | 418 |
| `frames.h` | 2 | 0 | 402 | 0 | 402 |
| `timers.c` | 5 | 0 | 360 | 0 | 360 |
| `haptics_cluster.cc` | 2 | 2 | 332 | 332 | 0 |
| `p_dsa_asn1.c` | 2 | 0 | 332 | 0 | 332 |
| `input_task.cc` | 2 | 2 | 330 | 330 | 0 |
| `partition_table.h` | 2 | 0 | 324 | 0 | 324 |
| `audio_player.cc` | 2 | 0 | 322 | 0 | 322 |
| `io_pin.cc` | 1 | 1 | 318 | 318 | 0 |
| `advertiser.cc` | 1 | 0 | 316 | 0 | 316 |
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
| `platform.h` | 1 | 0 | 164 | 0 | 164 |
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

Files fully decompiled already (0 remaining bytes): `sleep_driver.cc`, `haptics.cc`, `mimxrt10xx_flash_memory.cc`, `haptics_cluster.cc`, `input_task.cc`, `io_pin.cc`, `adc.h`, `switch_pro_controller.cc`, `board.cc`, `hid_input_target.cc`, `evp.c` — 11 of 139. All are small (≤744 bytes total).

## 3. Prioritized gap list

### 3a. Attributed-but-not-yet-decompiled — cheapest wins (top 10 files by remaining bytes)

Already know the file, already know the function boundaries — just needs `Decompile.java` + a read. Full remaining-function lists (address + size) for these top 10 are one `bruce_srcmap.csv` filter away; the two biggest are dumped in full below since they're worth queuing directly.

| Rank | Src file | Remaining funcs | Remaining bytes | Already decompiled |
|---:|---|---:|---:|---:|
| 1 | `bcm.c` | 52 | 11548 | 0/52 |
| 2 | `tasn_dec.c` | 7 | 3856 | 0/7 |
| 3 | `state_machine.cc` | 11 | 3332 | 0/11 |
| 4 | `adapter.cc` | 16 | 3216 | 0/16 |
| 5 | `keys.cc` | 17 | 3016 | 2/19 |
| 6 | `usb_host_audio_topology.cc` | 8 | 2876 | 0/8 |
| 7 | `audio_states.cc` | 6 | 2392 | 0/6 |
| 8 | `usb_host_audio.cc` | 9 | 2346 | 0/9 |
| 9 | `device_info.cc` | 7 | 2300 | 0/7 |
| 10 | `remote_device_db.cc` | 4 | 2070 | 0/4 |

`bcm.c` (Broadcom BT chip HCI/patchram driver, the single biggest module in the whole attributed set at 52 functions / 11,548 bytes, **0 decompiled**) is the single highest-value target in the entire attributed set — bigger than the next two combined. Biggest remaining functions there: `bcm__6008e264` (1160B), `bcm__6008bbdc` (800B), `bcm__6008c334` (706B), `bcm__6008d7ac` (642B), `bcm__6008c0d8` (628B).

Runner-up `tasn_dec.c` (ASN.1 DER decode, BoringSSL) top functions: `tasn_dec__6008fa18` (1410B), `tasn_dec__6008f794` (640B), `tasn_dec__6008ffc0` (514B).

Regenerate the full per-file remaining-function list anytime with:
```python
# addresses in bruce_srcmap.csv for src_file == X, minus addresses with a header-matching file in analysis/decomp/
```
(join key is the 8-hex-digit address suffix on the decomp filename / the first line's address, *not* the filename string — see methodology note on stale names below.)

### 3b. Unattributed contiguous address ranges — candidate whole modules

Comparing the full address-sorted function list in `bruce_functions.csv` against the 448 attributed addresses in `bruce_srcmap.csv` and grouping consecutive unattributed functions into runs. "Density" = actual function code bytes / total address span (low density usually means interleaved data/strings/padding or many tiny thunks rather than one dense module).

| # | Start | End | Span (B) | Code bytes | Funcs | Already decompiled | Density | Largest function in range |
|---:|---|---|---:|---:|---:|---:|---:|---|
| 1 | `0x600921b8` | `0x600c9cc4` | 228108 | 204449 | 1076 | 327 | 89.6% | `FUN_600ba1c4` (3898B @ `600ba1c4`) |
| 2 | `0x600ecb72` | `0x6013d4e4` | 330098 | 95117 | 1006 | 1 | 28.8% | `FUN_601054dc` (2546B @ `601054dc`) |
| 3 | `0x600df286` | `0x600ea868` | 46562 | 44326 | 316 | 7 | 95.2% | `FUN_600e398a` (6270B @ `600e398a`) |
| 4 | `0x600cc6e4` | `0x600d4560` | 32380 | 24998 | 304 | 1 | 77.2% | `FUN_600ccfb4` (1568B @ `600ccfb4`) |
| 5 | `0x600d8a12` | `0x600df24c` | 26682 | 23204 | 399 | 3 | 87.0% | `FUN_600dcf8c` (984B @ `600dcf8c`) |
| 6 | `0x6004cd58` | `0x60051164` | 17420 | 17174 | 10 | 1 | 98.6% | `FUN_6004cdb8` (15662B @ `6004cdb8`) |
| 7 | `0x60086720` | `0x6008ac36` | 17686 | 14608 | 19 | 0 | 82.6% | `FUN_60087970` (4036B @ `60087970`) |
| 8 | `0x60040500` | `0x60047038` | 27448 | 12698 | 92 | 8 | 46.3% | `FUN_60043ecc` (1364B @ `60043ecc`) |
| 9 | `0x60054f30` | `0x60058570` | 13888 | 10908 | 66 | 0 | 78.5% | `FUN_60056fa4` (1694B @ `60056fa4`) |
| 10 | `0x6004898c` | `0x6004cb5c` | 16848 | 10520 | 171 | 3 | 62.4% | `FUN_6004a4e6` (840B @ `6004a4e6`) |
| 11 | `0x600d56b8` | `0x600d89ec` | 13108 | 10254 | 177 | 2 | 78.2% | `FUN_600d80f4` (260B @ `600d80f4`) |
| 12 | `0x6007b96c` | `0x6007e69c` | 11568 | 9552 | 53 | 0 | 82.6% | `FUN_6007d144` (980B @ `6007d144`) |
| 13 | `0x60052294` | `0x60054a46` | 10162 | 8254 | 99 | 2 | 81.2% | `FUN_600526a0` (472B @ `600526a0`) |
| 14 | `0x60072260` | `0x60073b7c` | 6428 | 6400 | 3 | 2 | 99.6% | `FUN_600723b4` (6088B @ `600723b4`) |
| 15 | `0x6006c35c` | `0x6006e480` | 8484 | 5784 | 53 | 0 | 68.2% | `FUN_6006d998` (712B @ `6006d998`) |

168 unattributed runs total; span across all of them sums to 899,666 bytes (there's overlap-free but non-adjacent gap space between runs occupied by attributed functions and non-function data).

**#1 is the headline finding: `0x600921b8`–`0x600c9cc4`, 204,449 bytes of dense (89.6%) code across 1,076 functions.** This is by a wide margin the single largest block of totally-unmapped, clearly-real code in the image — bigger by actual code bytes than every other run combined except #2. **Session 7 identified this block with very high confidence as the statically-linked Broadcom BTA/BTE Bluetooth stack** (HCI transport/command-send/event-dispatch, BTM, BTA DM, GATT client+server, SDP, SMP, plus NIST P-256/P-192 EC field arithmetic feeding SMP's LE Secure Connections ECDH) — see `analysis/bruce-bta-stack.md` for full evidence (a ~400-entry leaked BTA function-name string table individually cross-referenced into this range, HCI command opcodes verified byte-for-byte against the spec, and the top-level HCI event dispatcher's switch matching the real HCI/LE-Meta event-code tables). 69 of 1,076 functions are now decompiled (up from the 2 that seeded the identification: `FUN_600ba1c4`, a GATT/ATT PDU parser, and `FUN_600c8fd8`, confirmed NIST P-256 modular reduction). 1,007 functions remain — `bruce-bta-stack.md`'s "how to continue" section has the fastest path (batch `FindRef.java` over the ~388 not-yet-checked BTA string-table entries, each a near-free function ID).

Runner-up #2 (`0x600ecb72`–`0x6013d4e4`, 330 KB span but only 28.8% density) is the tail of the image and includes the still-mostly-unresolved `thunk_EXT_FUN_0000xxxx` ITCM-veneer cluster (`0x6013cxxx`–`0x6013dxxx` per `bruce-itcm.md`; 145 of 155 veneers still unmapped there) plus other low-density scattered code — lower priority as a block since it's mostly a match for already-known-shape ITCM thunks (mechanical, not a mystery module) rather than one coherent unknown subsystem like #1.

## 4. The honest bottom line

Of **4,995 total functions** (the current census — see the 5,137-vs-4,995 discrepancy note in §1):

| | Functions | Bytes |
|---|---:|---:|
| Attributed to a source file | 448 | 97,450 |
| Decompiled (in census) | 80 | 57,558 |
| — of which both attributed AND decompiled | 34 | — |
| **Understood in some way (union)** | **494 (9.9%)** | **145,522 (22.0%)** |
| **Completely unknown — no attribution, no decompile** | **4,501 (90.1%)** | **515,048 (78.0%)** |

**4,501 functions and ~515 KB of code — nearly four-fifths of the binary by size — remain completely unmapped.** That's the real remaining scope of the "full decompile to source-reconstruction quality" goal. The single best next lever by size is §3b run #1 (204 KB / 1,076 functions, one contiguous unattributed block); the cheapest immediate wins are §3a's top 10 files (already-attributed, just need `Decompile.java` runs — largest is `bcm.c` at 11.5 KB / 52 functions).

## Methodology (for regenerating this doc)

Inputs: `analysis/ghidra/bruce_functions.csv` (address, name, size_bytes — full census), `analysis/ghidra/bruce_srcmap.csv` (address, name, src_file — 448-row attribution), `analysis/decomp/*.c` (one file per decompiled function; first line is a `// <addr>  <name>  size=<N> bytes` header written by `Decompile.java` — parse *that*, not the filename, for address/size ground truth).

Join key is always the **8-hex-digit address**, lowercase, zero-padded — not the name string. Two gotchas found this session, both worth remembering for next time:
1. `bruce_functions.csv`'s `name` column is stale (pre-attribution `FUN_xxxxxxxx` defaults) for every one of the 448 attributed addresses; only `bruce_srcmap.csv` has the current name. Sizes/addresses in `bruce_functions.csv` are fine.
2. Not every file in `analysis/decomp/` corresponds to a census address — `Decompile.java` will create a function (and thus a decomp file) at an address Ghidra's auto-analysis didn't already recognize as a function boundary. 66 of 146 current decomp files are like this (all tiny, ≤364 bytes) — exclude them from census-relative stats or the percentages won't reconcile against `bruce_functions.csv`'s totals.

Unattributed contiguous ranges (§3b) = walk `bruce_functions.csv` in address order, group maximal runs where no function's address is in the attributed set, compute span (last function's end − first function's start) and code_bytes (sum of `size_bytes` in the run) separately since span includes non-function bytes.

See also: `bruce-ghidra.md` (workspace/tooling, original module-mass table, next-session leads this doc's §3b run #1 corroborates), `bruce-io-paths.md` / `bruce-crypto.md` / `bruce-itcm.md` (subsystem-level narrative findings for functions already decompiled), `firmware-map.md` (bruce vs gotham top-level structure).

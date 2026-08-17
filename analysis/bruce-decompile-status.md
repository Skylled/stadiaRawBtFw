# Bruce — full-decompile tracking status

Data-driven status doc for the "decompile all of `bruce` to source-reconstruction quality" effort. Regenerate the numbers here whenever `bruce_functions.csv`, `bruce_srcmap.csv`, or `analysis/decomp/` change materially — don't hand-edit stale tables into new prose, just re-run the join described in [Methodology](#methodology) below.

**Snapshot: 2026-08-17 (hand-patch after session 21).** Prior full regeneration covered sessions 14–16 (46.30% union / 45.31% truly-unidentified, by bytes); a subsequent full regeneration after sessions 17–20 confirmed the union figure was still unchanged (same structural reason — see the note below) and committed that snapshot's numbers (`223c163`, session 20's work is now committed). This is a **hand-patch, not a full regeneration**: session 21 closed out the entire prior §3a top-10 (`stats.cc`, `receiver.cc`, `battery_gauge_bq2742X.cc`, `flash_lut.cc`, `headphone_state_machine.cc`, `bug_report.cc`, `usb_device.cc`, `led_driver_lp5562.cc`, `usb_device_audio.cc`, `usb_host.cc` — 34 functions, 6,666 bytes, all in already-attributed files) without touching the BTA/BTE block or any unattributed territory, so every number below is a direct, mechanical `+34 functions / +6,666 bytes` delta onto the prior committed snapshot rather than a fresh rejoin. **Someone should still run a full regeneration per the Methodology section next time `analysis/decomp/` is touched by an untracked/concurrent process**, per the doc's own session-13 consistency discipline — this hand-patch trusts the prior regen's base numbers rather than re-deriving them from scratch.

`bruce_functions.csv` (4,995 rows, 660,570 bytes) and `bruce_srcmap.csv` (448 rows, 139 src files) remain **byte-for-byte unchanged** — session 21 only added new files under `analysis/decomp/`, all 34 addresses independently verified present in both `bruce_srcmap.csv` (as the expected attributed rows) and `bruce_functions.csv` (as census entries, confirming none are the "created a function Ghidra hadn't already recognized" out-of-census case). `analysis/decomp/` now holds **1,116 files** (1,082 + 34), all 34 new ones in-census, so the in-census/out-of-census split stays 976/140 (the out-of-census 140 are untouched, same as every round since session 17).

## 1. Top-line stats

| Metric | Functions | % of 4,995 | Bytes | % of 660,570 |
|---|---:|---:|---:|---:|
| **Total functions (census)** | 4,995 | 100% | 660,570 | 100% |
| **Attributed** (leaked `__FILE__` → 139 src files) | 448 | 8.97% | 97,450 | 14.75% |
| **Decompiled** (`analysis/decomp/*.c`, matched to a census address) | 976 | 19.54% | 286,151 | 43.32% |
| **Attributed ∪ Decompiled** (understood in *some* way) | 1,124 | 22.50% | 305,815 | **46.30%** |
| **Totally unknown** (no attribution, no decompile) | 3,871 | 77.50% | 354,755 | **53.70%** |

Size-weighted (bytes) is still the more honest progress metric than function-count, for the same reason as every prior snapshot. **Bottom line up front: the union figure is unchanged yet again — still ~46.3% of the binary understood in some way — even though session 21 fully decompiled 10 more source files. Same structural reason as every round since session 17: see the note below.**

Notes on the numbers:
- **CLAUDE.md / project memory says "5,137 functions"** — `bruce_functions.csv` still has only 4,995 data rows, unchanged since session 6. Same ~142-function discrepancy as before; still not chased further here.
- **`bruce_functions.csv`'s `name` column is still stale for all 448 attributed addresses** — same gotcha as every prior session, unchanged. Always join on `address`.
- Of the 1,116 files now in `analysis/decomp/` (up from 1,082, +34, all session 21), **976 map onto an address in the 4,995-function census; 140 do not** (unchanged count/addresses — session 21 targeted only well-formed, already-recognized attributed-file functions, no new ITCM-thunk/sub-boundary carve-outs). Those 140 total 14,676 bytes of real decompiled code (max 960 bytes, mostly ≤364) that stays outside the 4,995/660,570 baseline for consistency, unchanged.
- Of the 976 in-census decompiled functions, **300 are also formally attributed** to a source file (up from 266). The other **676 are decompiled-but-unattributed — unchanged since the last regen**: of those, **490 are inside the identified BTA/BTE Bluetooth-stack block** (§1a, frozen) and **186 are scattered elsewhere** (also frozen). See §2/§3b for detail.
- **Growth attribution this round**: decompiled-in-census bytes grew from 279,485 to 286,151, **+6,666 bytes**, and — same pattern as sessions 17–20 — **100% of it landed in the "attributed AND decompiled" bucket** (266→300 functions, +34; 71,120→77,786 bytes, +6,666). Session 21 closed the entire prior §3a top-10 in one round: `stats.cc`, `receiver.cc`, `battery_gauge_bq2742X.cc`, `flash_lut.cc`, `bug_report.cc`, `led_driver_lp5562.cc` (`bruce-misc-functions.md`, 5 new sections), `headphone_state_machine.cc`, `usb_device_audio.cc` (`bruce-audio-subsystem.md`, 2 new sections), `usb_device.cc`, `usb_host.cc` (`bruce-io-paths.md`, 1 new section), plus `receiver.cc` doubling as a `bruce-itcm.md` extension (closing that doc's "which peripheral feeds the mic-DSP pipeline" open thread — it's SPI, via a dedicated `"SpiReceiverTask"`). **Zero bytes landed in the BTA/BTE block** (frozen at 490/1,076 — see §1a) **and zero in the scattered-unattributed bucket** (frozen at 186 functions/59,374 bytes — see §3b).
- **The same structural consequence flagged every round since session 17 applies again**: all 34 of this round's newly-decompiled functions live in files that were *already* formally attributed, so they add **zero new addresses** to the attributed ∪ decompiled union set. §1's union row and §4's bottom line are therefore **byte-for-byte identical to every snapshot back to session 14** (1,124 functions / 305,815 bytes / 46.30%), despite 10 more source files reaching full source-reconstruction-quality decompilation this round (57 of 139 now fully done, up from 47 — see §2). Finishing an already-*attributed* file can't grow the *union* number, by the same set-theoretic construction that means finishing the BTA/BTE block can't shrink "truly unidentified" (§4). The work is real and valuable — it's just invisible to a metric built around address-set membership rather than depth of understanding.

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

**This entire tier is frozen at exactly the last regen's numbers** — 490/1,076 decompiled, 72.9%, unchanged function-for-function and byte-for-byte across all five rounds since (sessions 17–21). Every round of work since the last full regen (per the growth-attribution note in §1) landed inside already-attributed files, not the BTA/BTE block. **Not independently re-verified against a fresh join this round** (this snapshot is a hand-patch, not a full regeneration — see the header note); trust this doc's numbers provisionally and re-run the join yourself if in doubt.

**Worth flagging for whoever picks up BTA/BTE work next**: check `analysis/decomp/`'s current file count before starting — it was 1,116 (976 in-census) as of this snapshot (session 21), and this doc has seen concurrent hand-patching before, so more may have landed since.

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
| `queue.c` | 12 | 6 | 1540 | 1090 | 450 |
| `usb_host_hid.cc` | 3 | 3 | 1468 | 1468 | 0 |
| `pem_lib.c` | 3 | 3 | 1458 | 1458 | 0 |
| `xbara.h` | 2 | 1 | 1246 | 1172 | 74 |
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
| `heap_5_improved.c` | 4 | 2 | 650 | 346 | 304 |
| `usb_device.cc` | 5 | 5 | 578 | 578 | 0 |
| `led_driver_lp5562.cc` | 3 | 3 | 548 | 548 | 0 |
| `usb_device_audio.cc` | 3 | 3 | 540 | 540 | 0 |
| `usb_host.cc` | 3 | 3 | 526 | 526 | 0 |
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

Files fully decompiled already (0 remaining bytes), **57 of 139** (up from 47 at the last snapshot): `bcm.c`, `tasn_dec.c`, `keys.cc`, `adapter.cc`, `gatt_server.cc`, `main.cc`, `sleep_driver.cc`, `haptics.cc`, `mimxrt10xx_flash_memory.cc`, `gatt_server.h`, `haptics_cluster.cc`, `input_task.cc`, `io_pin.cc`, `advertiser.cc`, `adc.h`, `switch_pro_controller.cc`, `board.cc`, `hid_input_target.cc`, `platform.h`, `evp.c`, the log-buffer-framework round (`usb_device_cdc_acm.c`, `frames.h`, `dynamic_buffer.h`, `append_buffer.h`, `logger.cc`, `buffer.h`, `buffer.cc`, `system_tasks.cc`, `uart.cc`), session 17's `tasks.c`/`state_machine.cc`/`key_value_store.cc`, session 18's `usb_host_audio_topology.cc`/`usb_host_audio.cc`/`usb_audio_receive.cc`/`audio_states.cc`, session 19's `device_info.cc`/`remote_device_db.cc`/`application_state.cc`/`firmware_image_upload.cc`/`ec_asn1.c`, session 20's `usb_host_hid.cc`/`pem_lib.c`/`http_flash_writer.cc`/`synapse_audio_processor.cc`/`thermal.cc`/`gotham.cc` (now committed, `223c163`) — see `bruce-itcm.md`, `bruce-state-machine.md`, `bruce-misc-functions.md`, `bruce-bta-stack.md`, `bruce-audio-subsystem.md`, `bruce-crypto.md`, `bruce-io-paths.md` for each round's write-up — **plus 10 newly complete this snapshot (session 21, uncommitted)**, the entire prior §3a top-10: `stats.cc` (0/1 → 1/1 — a per-task CPU/stack/heap diagnostic-report generator streamed to a caller-supplied sink, new section in `bruce-misc-functions.md`), `receiver.cc` (0/4 → 4/4 — the construct/run/receive-commit/join lifecycle of the `"SpiReceiverTask"` FreeRTOS task feeding `bruce-itcm.md`'s already-identified mic-DSP entry point `FUN_60046ccc`, closing that doc's "which peripheral feeds the pipeline" open thread — extends `bruce-itcm.md`), `battery_gauge_bq2742X.cc` (0/3 → 3/3 — the TI BQ2742x fuel-gauge I2C unseal/config-verify driver, confirmed a separate I2C peripheral from `thermal.cc`'s BQ25601 charger chip, new section in `bruce-misc-functions.md`), `flash_lut.cc` (0/3 → 3/3 — a verified-write/retry/rate-limited-erase flash lookup-table store, plausibly (not confirmed) related to CLAUDE.md's still-open calibration-blob question, new section in `bruce-misc-functions.md`), `headphone_state_machine.cc` (0/5 → 5/5 — the `HeadphoneStateMachine` HSM object unifying volume control across the onboard WM8904 codec and an attached USB audio accessory, new section in `bruce-audio-subsystem.md`), `bug_report.cc` (0/4 → 4/4 — the sector-aligned, magic-tagged (`0xbad5`), CRC-16-checksummed flash ring-buffer engine underneath `trigger_bug_report.cc`/`transfer_bug_report.cc`, new section in `bruce-misc-functions.md`), `usb_device.cc` (0/5 → 5/5) + `usb_host.cc` (0/3 → 3/3 — together the USB dual-role (device+host) state machine and composite class-driver dispatcher sitting above `usb_host_hid.cc`/`usb_host_audio.cc`, confirming real USB-C role-switching via `usb_port_controller_tusb320.cc`, extends `bruce-io-paths.md`), `led_driver_lp5562.cc` (0/3 → 3/3 — the TI LP5562 RGB status-LED I2C driver, init + two near-identical set-color entry points for normal playback vs. calibration, new section in `bruce-misc-functions.md`), `usb_device_audio.cc` (0/3 → 3/3 — the USB Audio Class 1.0 feedback-endpoint transport `usb_audio_receive.cc` (session 18) calls into, closing that session's open thread, extends `bruce-audio-subsystem.md`).

Partial-progress files (6, unchanged since the last regen): `timer.h` (3/9), `queue.c` (6/12), `xbara.h` (1/2), `heap_5_improved.c` (2/4), `p_ed25519_asn1.c` (2/4), `adapter.h` (1/2).

## 3. Prioritized gap list

### 3a. Attributed-but-not-yet-decompiled — cheapest wins (top 10 zero-progress files by remaining bytes)

The prior top-10 (`stats.cc`, `receiver.cc`, `battery_gauge_bq2742X.cc`, `flash_lut.cc`, `headphone_state_machine.cc`, `bug_report.cc`, `usb_device.cc`, `led_driver_lp5562.cc`, `usb_device_audio.cc`, `usb_host.cc`) was closed out in full this round (session 21, §2) — all 34 functions across all 10 files now decompiled. `receiver.cc` connected `bruce-itcm.md`'s mic-DSP pipeline to a concrete SPI-receive task (see that doc's new "Session 21" section); `usb_device_audio.cc` closed the `usb_audio_receive.cc` feedback-endpoint open thread from session 18; `usb_device.cc`/`usb_host.cc` confirmed real USB-C dual-role switching via `usb_port_controller_tusb320.cc`. Freshly refreshed list — same convention as always (zero-progress files only; files already partway there are tracked separately in §2's "Partial-progress files" line, not folded into this ranking), re-derived by re-sorting §2's current remaining-bytes column and filtering to `Decompiled funcs == 0`:

| Rank | Src file | Remaining funcs | Remaining bytes | Already decompiled |
|---:|---|---:|---:|---:|
| 1 | `gatt_manager_task.cc` | 4 | 518 | 0/4 |
| 2 | `usb_port_controller_tusb320.cc` | 4 | 508 | 0/4 |
| 3 | `battery_service.cc` | 3 | 506 | 0/3 |
| 4 | `recording_pipeline.cc` | 3 | 500 | 0/3 |
| 5 | `p_x25519_asn1.c` | 4 | 492 | 0/4 |
| 6 | `activation_sequence.cc` | 2 | 468 | 0/2 |
| 7 | `ble_info.cc` | 2 | 466 | 0/2 |
| 8 | `tasn_new.c` | 2 | 464 | 0/2 |
| 9 | `sai.cc` | 5 | 450 | 0/5 |
| 10 | `mpu.cc` | 1 | 440 | 0/1 |

Quick context for whoever picks these up: `gatt_manager_task.cc` (rank 1) is the GATT-manager task `state_machine__600df264` (`bruce-state-machine.md`) already calls by name (`gatt_manager_task__60080cdc`) to spin up BLE services — decompiling it would close that doc's remaining loose end. `usb_port_controller_tusb320.cc` (rank 2) is the real TI TUSB320 USB-C CC-logic chip driver this session's `usb_device.cc` write-up (`bruce-io-paths.md`) inferred must exist behind `usb_device__60060fe8`'s role-switch callback (`FUN_60064924`) — decompiling it would confirm that inference directly. `recording_pipeline.cc` (rank 4) is the capture-pipeline entry point `audio_states__60075088` (`bruce-audio-subsystem.md`) calls at the end of its setup sequence. `battery_service.cc` (rank 3) is a plausible BLE GATT-side counterpart to `battery_gauge_bq2742X.cc`'s I2C fuel-gauge driver (unconfirmed). `sound_codec_wm8904.cc` (184B, 0/2 — not quite top-10) is the natural next hop to fully resolve `headphone_state_machine.cc`'s onboard-codec half.

Also worth noting: `timer.h`'s remaining 1,332 bytes (partial-progress, 3/9 already done, see §2) is bigger than every entry in this zero-progress top-10 — it just isn't ranked here because §3a has always been scoped to *zero*-progress files by this doc's own convention. If the goal is fewest-functions-to-finish-a-file rather than biggest-remaining-byte-chunk, `timer.h` and `queue.c` (both 6 functions left) are arguably better next targets than several of the above.

Regenerate the full per-file remaining-function list anytime with:
```python
# addresses in bruce_srcmap.csv for src_file == X, minus addresses with a header-matching file in analysis/decomp/
```
(join key is the 8-hex-digit address suffix on the decomp filename / the first line's address, *not* the filename string.)

### 3b. Unattributed contiguous address ranges — candidate whole modules

Same 168 runs as every prior snapshot (the attributed set hasn't changed, so run boundaries are identical) — and this round, **every single "already decompiled" count is expected to be unchanged** from the last regen, since session 21's work (§1) landed entirely in already-attributed files, not unattributed territory. **Not independently re-verified by a fresh join this round** (hand-patch, not a full regeneration — see header note); the inference follows directly from session 21's file list rather than a re-run of the range-walk.

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
† = partially identified — `analysis/bruce-log-buffer.md` traced real, named clusters inside these four runs (sessions 14–15, unchanged since). Not a whole-range identification like BTA/BTE.

**No per-range deltas expected this round** — every one of the 15 largest runs (and, by extension, all 168) should have an identical "already decompiled" count to the last regen, as a direct consequence of this round's work being scoped entirely to already-attributed files (§1's growth-attribution note) rather than any unattributed-territory sweep — not independently re-verified by a fresh join this round (see header note).

**#1 remains the headline finding by size**: `0x600921b8`–`0x600c9cc4`, 204,449 bytes of dense (89.6%) code across 1,076 functions, the confirmed Broadcom BTA/BTE Bluetooth stack (`analysis/bruce-bta-stack.md`), still **72.9% decompiled by size**, unchanged across sessions 17–21. **586 functions / 55,458 bytes remain in this block** — still the single biggest "no more detective work needed, just mechanical decompile" lever in the whole doc.

Run #2 (`0x600ecb72`–`0x6013d4e4`, 330 KB span, still only 28.8% density) remains the largest still-mostly-unmapped range, unchanged this round. `bruce-bta-stack.md` separately notes `smp_sm_event`'s 54 callers live in `0x600faxxx`–`0x600fcxxx`, inside this run — still strong circumstantial evidence for a real pocket of SMP per-state-handler code here, not yet swept. Still the best candidate for genuinely new-territory progress at scale.

## 4. The honest bottom line

Of **4,995 total functions** (the current census — see the 5,137-vs-4,995 discrepancy note in §1):

| | Functions | Bytes |
|---|---:|---:|
| Attributed to a source file | 448 | 97,450 |
| Decompiled (in census) | 976 | 286,151 |
| — of which both attributed AND decompiled | 300 | 77,786 |
| — of which in the identified-but-not-formally-attributed BTA/BTE stack (§1a) | 490 | 148,991 |
| **Understood in some way (union)** | **1,124 (22.5%)** | **305,815 (46.3%)** |
| **Completely unknown — no attribution, no decompile, no module ID** | 3,871 (77.5%), or **3,285 (65.8%) excluding BTA-identified** | 354,755 (53.7%), or **299,297 (45.3%) excluding BTA-identified** |

**Compared to the last regen: both headline percentages are unchanged, for the fifth round running** — union coverage still 22.5% by count / 46.3% by bytes, truly-unidentified still 65.8% / 45.3%. This is not stagnation: 140 more functions across 10 more source files were fully decompiled to source-reconstruction quality across sessions 17–21 (§1, §2). It's the mechanical consequence explained in §1's "structural consequence" note — every one of those functions lived in an already-attributed file, so they were already counted in the union set via attribution alone; decompiling them deepened the *quality* of understanding without growing the *breadth*. The same asymmetry that's true for BTA/BTE progress (can't shrink "truly unidentified," because that block is already module-identified) is true in mirror image for attributed-file progress (can't grow "understood in some way," because attribution already granted membership). **Only work that identifies or decompiles genuinely new, previously-unattributed/unidentified territory moves either top-line number** — the session-14 log-buffer-framework find is still the most recent example of that happening.

**3,285 functions and ~299 KB of code — just under half the binary by size — remain truly unidentified with no attribution, no decompile, and no module ID of any kind.** That's the real remaining scope of the "full decompile to source-reconstruction quality" goal, and it hasn't moved in five-plus sessions of otherwise-productive work. The single best next lever by size is still finishing §1a/§3b-run-#1 (586 functions / 55,458 bytes still to decompile in the already-identified BTA/BTE block — cheap in the "no more detective work needed" sense, and the only lever big enough to make a real dent); the best candidate for *new* territory at scale remains run #2 (330 KB, mixed ITCM-thunk mechanical work, a real pocket of SMP state-handler code, and a debug-string-table region, per `bruce-bta-stack.md` and `bruce-log-buffer.md`); and §3a's refreshed top-10 (`gatt_manager_task.cc` through `mpu.cc`) are the cheapest attributed-file wins left, though — per the note above — they'll keep the union percentage flat too, for exactly the same structural reason sessions 17–21's work did.

## Methodology (for regenerating this doc)

Inputs: `analysis/ghidra/bruce_functions.csv` (address, name, size_bytes — full census), `analysis/ghidra/bruce_srcmap.csv` (address, name, src_file — 448-row attribution), `analysis/decomp/*.c` (one file per decompiled function; first line is a `// <addr>  <name>  size=<N> bytes` header written by `Decompile.java` — parse *that*, not the filename, for address/size ground truth).

Join key is always the **8-hex-digit address**, lowercase, zero-padded — not the name string. Same gotchas as every prior session, still true:
1. `bruce_functions.csv`'s `name` column is stale (pre-attribution `FUN_xxxxxxxx` defaults) for every one of the 448 attributed addresses; only `bruce_srcmap.csv` has the current name. Sizes/addresses in `bruce_functions.csv` are fine (re-spot-checked this session: 0 mismatches between census size and decomp-header size across all 942 in-census decompiled functions).
2. Not every file in `analysis/decomp/` corresponds to a census address — `Decompile.java` will create a function (and thus a decomp file) at an address Ghidra's auto-analysis didn't already recognize as a function boundary. 140 of 1,082 current decomp files are like this (max 960 bytes, mostly ≤364, same pattern as prior sessions) — exclude them from census-relative stats or the percentages won't reconcile against `bruce_functions.csv`'s totals.
3. For any block identified by means *other* than `bruce_srcmap.csv` (i.e. string-table cross-reference, as in `bruce-bta-stack.md`, or call-graph/shape identification, as in `bruce-log-buffer.md`, rather than a leaked `__FILE__` path): **do not fold it into the "Attributed" join.** Keep it as a separate reported tier or annotation (§1a's numeric tier for the large, cleanly-bounded BTA/BTE block; §3b's lighter-weight `†` annotation for the log-buffer framework's more scattered, partial-range identifications) so the core `bruce_srcmap.csv`-based join stays a clean, mechanically-reproducible number, while still surfacing that "unattributed" isn't the same thing as "unidentified." When computing §1a's own decompiled-count, use a fresh strict address-join against the current `analysis/decomp/` state — **don't** just copy `bruce-bta-stack.md`'s self-reported running-count prose, which lags well behind the actual directory contents.
4. **New this session**: when the union/truly-unidentified top-line numbers don't move between two full regenerations despite `analysis/decomp/` growing substantially, don't assume a bug — check whether the growth landed entirely inside already-attributed files (§1's "structural consequence" note). Both top-line metrics are address-set-membership counts, not "depth of understanding" scores; finishing an already-counted file is real progress that these particular numbers are structurally blind to. Cross-check via the "both attributed and decompiled" count (§4's second row) — if *its* growth equals the total decompiled-count growth, that's confirmation, not coincidence (this session: +106 in both places, exactly).
5. **Session-numbering note**: this doc's own hand-patch labels (and every subsystem doc's own section headers — `bruce-itcm.md`, `bruce-state-machine.md`, `bruce-audio-subsystem.md`, `bruce-misc-functions.md`, `bruce-bta-stack.md`) run one lower than the git commit messages for the same content (e.g. the `tasks.c`/`state_machine.cc`/`key_value_store.cc` round is "session 17" throughout the analysis docs but commit `690bac1` calls it "session 18"). This doc follows the analysis-doc-internal numbering, not the git commit numbering, for cross-reference consistency — don't "fix" one without fixing all of them together.

Unattributed contiguous ranges (§3b) = walk `bruce_functions.csv` in address order, group maximal runs where no function's address is in the attributed set, compute span (last function's end − first function's start) and code_bytes (sum of `size_bytes` in the run) separately since span includes non-function bytes.

**A note on snapshot consistency**, reconfirmed again this session (first learned session 13): if `analysis/decomp/` — or this very doc — is being actively written to by a concurrent session, take **one single directory listing + parse pass** and derive every table in the doc from that same in-memory snapshot, rather than re-listing the directory for each table. This session found `analysis/bruce-decompile-status.md` itself mid-edit in the working tree twice (git status showed it modified both times this was checked, with a hand-patch covering §2's table, the "fully decompiled" list, and §3a's commentary for the 6 newest files, self-labeled "session 20") — this full regeneration's independent fresh join reached identical numbers for those 6 files, a good agreement check — and supersedes the partial hand-patch with a complete, freshly-joined, internally-consistent regeneration exactly as every prior full regen has done to its predecessor's hand-patches. `analysis/decomp/`'s own file count (1,082) was stable across both checks, so no mid-regeneration growth to worry about this time — only the doc text itself was still being hand-patched when this run started.

See also: `bruce-ghidra.md` (workspace/tooling, original module-mass table), `bruce-io-paths.md` / `bruce-crypto.md` / `bruce-itcm.md` (subsystem-level narrative findings for functions already decompiled), `bruce-bta-stack.md` (the BTA/BTE stack identification and address-range map — its prose is stale relative to this doc's function-count/byte figures as of this snapshot, see §1a), `bruce-log-buffer.md` (the codebase-wide log/message-buffer framework — sessions 14–15, see §2/§3b), `bruce-state-machine.md` / `bruce-audio-subsystem.md` / `bruce-misc-functions.md` / `bruce-itcm.md` (subsystem write-ups for sessions 17–21's newly-closed files), `firmware-map.md` (bruce vs gotham top-level structure).

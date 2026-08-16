# Bruce — full-decompile tracking status

Data-driven status doc for the "decompile all of `bruce` to source-reconstruction quality" effort. Regenerate the numbers here whenever `bruce_functions.csv`, `bruce_srcmap.csv`, or `analysis/decomp/` change materially — don't hand-edit stale tables into new prose, just re-run the join described in [Methodology](#methodology) below.

**Snapshot: 2026-08-15 23:46 EDT (session 8 regeneration).** This is a full refresh of every table in the doc, built on top of two sessions of work (session 6 continued, session 7 twice) that ran between this doc's original session-6 build and now: `analysis/decomp/` grew from 146 files (session 6 baseline) to **546** at the moment this snapshot was taken — more than 3.7x. Only one row of the previous version (§3b run #1) had been kept manually up to date in the interim; every other number below was stale until this pass. `analysis/decomp/` was under active, ongoing expansion by a concurrent session while this doc was being rebuilt (confirmed growing from 534 → 546 files mid-session) — as with the original session-6 snapshot, treat every count below as a lower bound as of the snapshot time, not a hard current total. Re-run before trusting exact numbers for planning. The census (`bruce_functions.csv`, 4,995 rows) and attribution table (`bruce_srcmap.csv`, 448 rows) are unchanged from session 6 — all growth this round is in `analysis/decomp/`.

**Session 9 patch (targeted, not a full regeneration):** all 52 `bcm.c` functions are now decompiled (`analysis/decomp/bcm__*.c`, 11,548 bytes) — the numbers below have been hand-corrected wherever they mention `bcm.c` specifically (§1 top-line Decompiled/overlap counts, §2's `bcm.c` row, §3a). **`bcm.c` also turned out to be misidentified** — it was called "the Broadcom BT chip HCI/patchram driver" purely from the filename; actually reading the code shows it's BoringSSL's `crypto/fipsmodule/bcm.c` ("BoringCrypto Module") aggregate file — BIGNUM + generic EC_GROUP/EC_POINT/EC_KEY code, with a small EVP block-cipher-padding cluster. Full evidence, corrected description, and a per-function map are in `bruce-crypto.md`'s new session-9 section; this doc's job is just the byte/function accounting. No other number in this doc has been re-verified this session — everything not about `bcm.c` should still be treated as a session-8-snapshot lower bound per the paragraph above, likely stale given how much concurrent decompile work the session-8 note already flagged as in-flight.

The other major input new this session: `analysis/bruce-bta-stack.md`, which identifies §3b's run #1 (the 204 KB block at `0x600921b8`–`0x600c9cc4`) as the statically-linked Broadcom BTA/BTE Bluetooth stack, with 319 of its 1,076 functions now decompiled via a string-table cross-reference method (not the `__FILE__`-leak method the rest of this doc's "Attributed" numbers rest on). That block is no longer *unidentified* — see the new §1a and the rewritten §3b run #1 for how this doc represents that distinction without polluting the formal "Attributed" join.

## 1. Top-line stats

| Metric | Functions | % of 4,995 | Bytes | % of 660,570 |
|---|---:|---:|---:|---:|
| **Total functions (census)** | 4,995 | 100% | 660,570 | 100% |
| **Attributed** (leaked `__FILE__` → 139 src files) | 448 | 8.97% | 97,450 | 14.75% |
| **Decompiled** (`analysis/decomp/*.c`, matched to a census address) | 491 | 9.83% | 157,439 | 23.83% |
| **Attributed ∪ Decompiled** (understood in *some* way) | 851 | 17.04% | 233,509 | **35.35%** |
| **Totally unknown** (no attribution, no decompile) | 4,144 | 82.96% | 427,061 | **64.65%** |

Size-weighted (bytes) is still the more honest progress metric than function-count, for the same reason as before (a handful of huge functions dominate the byte total disproportionately to their count). **Bottom line: ~35% of the binary's code by size is now understood in some way, up from ~22% at the session-6 snapshot — real progress, but 65% (427 KB across 4,144 functions) is still completely unmapped.**

(Session 9 note: "Decompiled" rows above are hand-bumped by exactly `bcm.c`'s 52 functions/11,548 bytes over the session-8 snapshot — `439→491` funcs, `145,891→157,439` bytes. The "Attributed ∪ Decompiled" union is **unchanged** by this, and that's expected, not an error: `bcm.c`'s 52 functions were already inside "Attributed" before this session, so decompiling them moves them from the attributed-only bucket into the attributed-and-decompiled overlap bucket without growing the union. It's a real quality upgrade — "we know the filename" to "we've read the code and know what it does" — just not one that shows up in the top-line coverage percentage.)

Notes on the numbers:
- **CLAUDE.md / project memory says "5,137 functions"** — `bruce_functions.csv` still has only 4,995 data rows, unchanged from session 6 (no re-import happened this round). Same ~142-function discrepancy as before; still not chased further here.
- **`bruce_functions.csv`'s `name` column is still stale for all 448 attributed addresses** — same gotcha as session 6, unchanged. Always join on `address`.
- Of the 546 files currently in `analysis/decomp/`, **439 map onto an address in the 4,995-function census; 107 do not** (up from 66 at the session-6 snapshot, proportionally about the same ~20% share) — these are the tiny (2–364 byte) `Decompile.java`-carved-out ITCM-thunk/veneer-style functions described in `bruce-itcm.md`. They total 10,848 bytes of real decompiled code that stays outside the 4,995/660,570 baseline for the same consistency reason as before.
- Of the 491 in-census decompiled functions (session-9-updated count), **88 are also formally attributed** to a source file — session-8 snapshot had 36; session 9 added exactly `bcm.c`'s 52 (all of which were already attributed) on top, all in one file. The other **403 are decompiled-but-unattributed** (unchanged from session 8 — the session-9 work was entirely inside the already-attributed `bcm.c`, so it doesn't move this figure). The overwhelming majority of that 403 — **319 of them** — are inside the newly-identified BTA/BTE Bluetooth-stack block (§1a below); the remaining 84 are the pre-existing crypto-stack/I/O-path decompiles from session 6 plus scattered small wins elsewhere (see §3b's per-range deltas).
- **Growth attribution**: decompiled-in-census bytes grew from 57,558 (session 6) to 145,891 at the session-8 snapshot, +88,333 bytes. **97.2% of that growth (+85,873 bytes) came from the BTA/BTE stack block alone** — i.e. essentially all of two sessions' worth of decompile work went into one module. Outside that block, growth was real but modest and scattered (see the per-range deltas in §3b, e.g. run #10 going from 3→25 decompiled functions). Session 9 added a further +11,548 bytes, all from `bcm.c` (see the session-9 patch note at the top of this doc) — not reflected in the 97.2%/session-8 figures above, which are left as their original snapshot.

### 1a. Module-identified-but-not-formally-attributed (informational — not folded into "Attributed" above)

`analysis/bruce-bta-stack.md` identifies the entire `0x600921b8`–`0x600c9cc4` range as the Broadcom BTA/BTE stack via a ~400-entry leaked function-name string table cross-referenced with `FindRef.java`, plus independent spec-level confirmation (HCI opcodes, HCI/LE-Meta event codes, SDP/GAP framing bytes — see that doc for full evidence). This is a **different provenance than `bruce_srcmap.csv`'s `__FILE__`-leak attribution** (no `.cc`/`.c` source filename is recovered, just a Broadcom-internal function name and module identity), so it is deliberately **not** merged into the "Attributed" row above — that row's definition stays a clean join against `bruce_srcmap.csv` per the methodology. Instead, it's broken out here as its own status tier, because lumping its 757 still-undecompiled functions into "Totally unknown" would misrepresent them — their *identity* is known, just not their *decompiled content*.

| | Functions | Bytes | % of block |
|---|---:|---:|---:|
| BTA/BTE block total | 1,076 | 204,449 | 100% |
| — decompiled (also counted in §1's "Decompiled" row) | 319 | 92,535 | 45.3% |
| — **identified but not yet decompiled** | 757 | 111,914 | 54.7% |

That 757/111,914 is a subset of §1's "Totally unknown" row. Netting it out gives a more honest "no idea at all" figure:

| | Functions | % of 4,995 | Bytes | % of 660,570 |
|---|---:|---:|---:|---:|
| Totally unknown (§1, includes BTA-identified-but-undecompiled) | 4,144 | 82.96% | 427,061 | 64.65% |
| — of which: BTA-identified, module known, just not decompiled | 757 | 15.16% | 111,914 | 16.94% |
| **— truly unidentified (no attribution, no decompile, no module ID)** | **3,387** | **67.81%** | **315,147** | **47.71%** |

(`bruce-bta-stack.md` self-reports "327 of 1,076... ~93,400 bytes (~45.7%)" for this block — its own session-time snapshot. The 319/92,535/45.3% figures here come from a strict address-join against the current `bruce_functions.csv`/`analysis/decomp/` state at this doc's snapshot time and are the ones this doc's other tables are built from; the two are consistent to within normal snapshot-drift and both tell the same story.)

## 2. Per-source-file table (all 139 attributed files, sorted by total byte size descending)

"Decompiled funcs/bytes" = how many of that file's *attributed* functions have a matching file in `analysis/decomp/` (cross-referenced by address). This table is **essentially unchanged from the session-6 snapshot** — the two sessions of work in between went almost entirely into the unattributed BTA/BTE block (§1a, §3b) and scattered small unattributed ranges, not into resolving more of the already-attributed files. The one exception: `heap_5_improved.c` gained 2 decompiled functions (346 of its 650 bytes, up from 0).

| Src file | Attributed funcs | Decompiled funcs | Total bytes | Decompiled bytes | Remaining bytes |
|---|---:|---:|---:|---:|---:|
| `bcm.c` | 52 | 52 | 11548 | 11548 | 0 |
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

Files fully decompiled already (0 remaining bytes): `sleep_driver.cc`, `haptics.cc`, `mimxrt10xx_flash_memory.cc`, `haptics_cluster.cc`, `input_task.cc`, `io_pin.cc`, `adc.h`, `switch_pro_controller.cc`, `board.cc`, `hid_input_target.cc`, `evp.c` — 11 of 139 as of the session-6/8 snapshot; **session 9 adds `bcm.c` as a 12th** (all 52 functions decompiled, see the session-9 patch note at the top of this doc — and note `bcm.c` is BoringSSL BIGNUM/EC code, not the Broadcom BT driver the name suggests, per `bruce-crypto.md`). `heap_5_improved.c` moved from 0/4 to 2/4 at the session-8 snapshot but isn't fully done.

## 3. Prioritized gap list

### 3a. Attributed-but-not-yet-decompiled — cheapest wins (top 10 files by remaining bytes)

Unchanged from the session-6 list — no session-7/8 work touched these files (all of it went into §1a's BTA/BTE block and scattered unattributed ranges instead). Still the cheapest, most legible wins: file and function boundaries are already known, this is purely `Decompile.java` + a read.

| Rank | Src file | Remaining funcs | Remaining bytes | Already decompiled |
|---:|---|---:|---:|---:|
| 1 | `tasn_dec.c` | 7 | 3856 | 0/7 |
| 2 | `state_machine.cc` | 11 | 3332 | 0/11 |
| 3 | `adapter.cc` | 16 | 3216 | 0/16 |
| 4 | `keys.cc` | 17 | 3016 | 2/19 |
| 5 | `usb_host_audio_topology.cc` | 8 | 2876 | 0/8 |
| 6 | `audio_states.cc` | 6 | 2392 | 0/6 |
| 7 | `usb_host_audio.cc` | 9 | 2346 | 0/9 |
| 8 | `device_info.cc` | 7 | 2300 | 0/7 |
| 9 | `remote_device_db.cc` | 4 | 2070 | 0/4 |

`bcm.c` **is now fully decompiled (52/52 functions, session 9)** and drops off this "remaining" ranking entirely — it's no longer a cheap-win target, it's done. It also turned out **not** to be a Broadcom BT chip HCI/patchram driver as previously assumed from the filename: it's BoringSSL's `crypto/fipsmodule/bcm.c` ("BoringCrypto Module") aggregate file — BIGNUM + generic EC_GROUP/EC_POINT/EC_KEY code plus a small EVP cipher-padding cluster. Full per-function map and evidence in `bruce-crypto.md`'s new session-9 section. (The real Broadcom BT chip/HCI transport layer is unrelated to this block — it's the material in `bruce-bta-stack.md`, e.g. `hcisu_h4_send_msg_now`.) `tasn_dec.c` is now the top remaining cheap-win target.

Runner-up `tasn_dec.c` (ASN.1 DER decode, BoringSSL) top functions: `tasn_dec__6008fa18` (1410B), `tasn_dec__6008f794` (640B), `tasn_dec__6008ffc0` (514B).

Regenerate the full per-file remaining-function list anytime with:
```python
# addresses in bruce_srcmap.csv for src_file == X, minus addresses with a header-matching file in analysis/decomp/
```
(join key is the 8-hex-digit address suffix on the decomp filename / the first line's address, *not* the filename string — see methodology note on stale names below.)

### 3b. Unattributed contiguous address ranges — candidate whole modules

Same 168 runs as the session-6 snapshot (the attributed set hasn't changed, so run boundaries are identical) — only the "already decompiled" counts moved. **Run #1 is qualitatively different from the other 167 now**: it's an *identified* module (§1a) that's 45% decompiled by size, not an unknown blob. It's kept in this table for continuity (it's still the biggest single lever by size) but should be read as "still has 55% left to decompile," not "still unidentified."

| # | Start | End | Span (B) | Code bytes | Funcs | Already decompiled | Density | Largest function in range |
|---:|---|---|---:|---:|---:|---:|---:|---|
| 1★ | `0x600921b8` | `0x600c9cc4` | 228108 | 204449 | 1076 | 319 | 89.6% | `FUN_600ba1c4` (3898B @ `600ba1c4`) |
| 2 | `0x600ecb72` | `0x6013d4e4` | 330098 | 95117 | 1006 | 2 | 28.8% | `FUN_601054dc` (2546B @ `601054dc`) |
| 3 | `0x600df286` | `0x600ea868` | 46562 | 44326 | 316 | 7 | 95.2% | `FUN_600e398a` (6270B @ `600e398a`) |
| 4 | `0x600cc6e4` | `0x600d4560` | 32380 | 24998 | 304 | 2 | 77.2% | `FUN_600ccfb4` (1568B @ `600ccfb4`) |
| 5 | `0x600d8a12` | `0x600df24c` | 26682 | 23204 | 399 | 4 | 87.0% | `FUN_600dcf8c` (984B @ `600dcf8c`) |
| 6 | `0x6004cd58` | `0x60051164` | 17420 | 17174 | 10 | 1 | 98.6% | `FUN_6004cdb8` (15662B @ `6004cdb8`) |
| 7 | `0x60086720` | `0x6008ac36` | 17686 | 14608 | 19 | 0 | 82.6% | `FUN_60087970` (4036B @ `60087970`) |
| 8 | `0x60040500` | `0x60047038` | 27448 | 12698 | 92 | 9 | 46.3% | `FUN_60043ecc` (1364B @ `60043ecc`) |
| 9 | `0x60054f30` | `0x60058570` | 13888 | 10908 | 66 | 0 | 78.5% | `FUN_60056fa4` (1694B @ `60056fa4`) |
| 10 | `0x6004898c` | `0x6004cb5c` | 16848 | 10520 | 171 | 25 | 62.4% | `FUN_6004a4e6` (840B @ `6004a4e6`) |
| 11 | `0x600d56b8` | `0x600d89ec` | 13108 | 10254 | 177 | 2 | 78.2% | `FUN_600d80f4` (260B @ `600d80f4`) |
| 12 | `0x6007b96c` | `0x6007e69c` | 11568 | 9552 | 53 | 0 | 82.6% | `FUN_6007d144` (980B @ `6007d144`) |
| 13 | `0x60052294` | `0x60054a46` | 10162 | 8254 | 99 | 3 | 81.2% | `FUN_600526a0` (472B @ `600526a0`) |
| 14 | `0x60072260` | `0x60073b7c` | 6428 | 6400 | 3 | 2 | 99.6% | `FUN_600723b4` (6088B @ `600723b4`) |
| 15 | `0x6006c35c` | `0x6006e480` | 8484 | 5784 | 53 | 0 | 68.2% | `FUN_6006d998` (712B @ `6006d998`) |

★ = identified module (§1a), not an unknown blob — kept in this "unattributed" table only because it fails the strict `bruce_srcmap.csv` join, not because it's a mystery.

168 unattributed runs total (unchanged); span across all of them sums to 899,666 bytes (same as session 6 — run boundaries are a function of the attributed set only, which hasn't changed).

Per-range deltas vs. the session-6 snapshot, for the top 15: run #1 327→319*, #2 1→2, #3 7→7 (no change), #4 1→2, #5 3→4, #6 1→1 (no change), #7 0→0 (no change), #8 8→9, #9 0→0 (no change), **#10 3→25** (an 8x jump — some concentrated work landed in this 16,848-byte range, worth a look next session for what specifically got decompiled there), #11 2→2 (no change), #12 0→0 (no change), #13 2→3, #14 2→2 (no change), #15 0→0 (no change). (*Run #1's count is a fresh address-join recount, not literally a decrease from a prior 327 — see the §1a footnote on the small discrepancy with `bruce-bta-stack.md`'s self-reported figure.)

**#1 remains the headline finding by size, but its status has changed fundamentally: `0x600921b8`–`0x600c9cc4`, 204,449 bytes of dense (89.6%) code across 1,076 functions, is no longer unmapped — it's the confirmed Broadcom BTA/BTE Bluetooth stack (`analysis/bruce-bta-stack.md`), and 319 of its functions (45.3% by size) are now decompiled.** Full evidence for the identification (a ~400-entry leaked BTA function-name string table, HCI command opcodes verified byte-for-byte against the spec, and the top-level HCI event dispatcher's switch matching the real HCI/LE-Meta event-code tables) is in that doc, along with a module-by-module address-range map (HCI transport, BTM, BTA DM, GATT client+server, L2CAP, SDP, SMP, and NIST P-256/P-192 EC field arithmetic for LE Secure Connections). **757 functions / 111,914 bytes remain in this block** — `bruce-bta-stack.md`'s "how to continue" section has the fastest path (the string-table sweep is largely exhausted per that doc, so the remaining work is mostly direct decompile + read of already-identified-but-not-yet-decompiled functions, plus resolving the handful of "not conclusively identified" gaps it flags).

Runner-up #2 (`0x600ecb72`–`0x6013d4e4`, 330 KB span but only 28.8% density) is still the tail of the image and still includes the mostly-unresolved `thunk_EXT_FUN_0000xxxx` ITCM-veneer cluster — unchanged assessment from session 6, still lower priority as a block for the same reason (mechanical veneer resolution, not one coherent unknown subsystem). `bruce-bta-stack.md` separately notes that many of `smp_sm_event`'s 54 callers live in `0x600faxxx`–`0x600fcxxx`, inside this run — meaning run #2 likely contains a substantial chunk of real SMP per-state-handler code, making it a higher-value target than its density alone suggests. Worth a closer look before writing it off as pure ITCM-thunk mechanical work.

## 4. The honest bottom line

Of **4,995 total functions** (the current census — see the 5,137-vs-4,995 discrepancy note in §1):

| | Functions | Bytes |
|---|---:|---:|
| Attributed to a source file | 448 | 97,450 |
| Decompiled (in census) | 491 | 157,439 |
| — of which both attributed AND decompiled | 88 | — |
| — of which in the identified-but-not-formally-attributed BTA/BTE stack (§1a) | 319 | 92,535 |
| **Understood in some way (union)** | **851 (17.0%)** | **233,509 (35.4%)** |
| **Completely unknown — no attribution, no decompile, no module ID** | 4,144 (83.0%), or **3,387 (67.8%) excluding BTA-identified** | 427,061 (64.7%), or **315,147 (47.7%) excluding BTA-identified** |

(Session 9 hand-patch: the "Decompiled"/"both attributed AND decompiled" rows above are bumped by `bcm.c`'s 52 functions/11,548 bytes, all now decompiled — see the session-9 patch note at the top of this doc. The union/unknown rows are unchanged, as expected, since `bcm.c` was already inside "Attributed" — see the §1 note for why that's not a bug.)

**Compared to the session-6 snapshot: union coverage nearly doubled by function count (9.9% → 17.0%) and grew by more than half again by byte-weight (22.0% → 35.4%).** Almost all of that gain — 97.2% of the raw byte growth — came from one place: two sessions of concentrated work decompiling the newly-identified BTA/BTE Bluetooth stack (§1a). That's a real, meaningful move in the project's actual goal, not a bookkeeping artifact — the BTA/BTE stack is genuinely one of the largest coherent subsystems in the image, on par with or larger than the crypto stack (`bruce-crypto.md`) that dominated the session-4/5 numbers.

**3,387 functions and ~315 KB of code — still nearly half the binary by size — remain truly unidentified with no attribution, no decompile, and no module ID of any kind.** That's the real remaining scope of the "full decompile to source-reconstruction quality" goal, now that the low-hanging "is this even a known module" question has been answered for the single biggest block. The single best next lever by size is finishing §1a/§3b-run-#1 (757 functions / 111,914 bytes still to decompile, but already identified — cheap in the sense that no more detective work is needed, just `Decompile.java` + read, same as §3a); `bcm.c` (formerly the top §3a entry) is now **fully decompiled** (session 9) and turned out to be BoringSSL BIGNUM/EC code, not a Broadcom BT driver — see `bruce-crypto.md`; the next cheapest *fresh-territory* win is `tasn_dec.c` (§3a); and run #2 (330 KB, mixed ITCM-thunk mechanical work plus a real pocket of SMP state-handler code per `bruce-bta-stack.md`) is worth a closer look before the next full-doc regeneration.

## Methodology (for regenerating this doc)

Inputs: `analysis/ghidra/bruce_functions.csv` (address, name, size_bytes — full census), `analysis/ghidra/bruce_srcmap.csv` (address, name, src_file — 448-row attribution), `analysis/decomp/*.c` (one file per decompiled function; first line is a `// <addr>  <name>  size=<N> bytes` header written by `Decompile.java` — parse *that*, not the filename, for address/size ground truth).

Join key is always the **8-hex-digit address**, lowercase, zero-padded — not the name string. Same two gotchas as session 6, still true:
1. `bruce_functions.csv`'s `name` column is stale (pre-attribution `FUN_xxxxxxxx` defaults) for every one of the 448 attributed addresses; only `bruce_srcmap.csv` has the current name. Sizes/addresses in `bruce_functions.csv` are fine (re-spot-checked this session: 0 mismatches between census size and decomp-header size across all 439 in-census decompiled functions).
2. Not every file in `analysis/decomp/` corresponds to a census address — `Decompile.java` will create a function (and thus a decomp file) at an address Ghidra's auto-analysis didn't already recognize as a function boundary. 107 of 546 current decomp files are like this (all tiny, ≤364 bytes) — exclude them from census-relative stats or the percentages won't reconcile against `bruce_functions.csv`'s totals.

New this session — a third consideration for any block identified by means *other* than `bruce_srcmap.csv` (i.e. string-table cross-reference, as in `bruce-bta-stack.md`, rather than a leaked `__FILE__` path): **do not fold it into the "Attributed" join.** Keep it as a separate reported tier (this doc's §1a) so the core `bruce_srcmap.csv`-based join stays a clean, mechanically-reproducible number, while still surfacing the fact that "unattributed" isn't the same thing as "unidentified" for that range.

Unattributed contiguous ranges (§3b) = walk `bruce_functions.csv` in address order, group maximal runs where no function's address is in the attributed set, compute span (last function's end − first function's start) and code_bytes (sum of `size_bytes` in the run) separately since span includes non-function bytes.

See also: `bruce-ghidra.md` (workspace/tooling, original module-mass table), `bruce-io-paths.md` / `bruce-crypto.md` / `bruce-itcm.md` (subsystem-level narrative findings for functions already decompiled), `bruce-bta-stack.md` (the BTA/BTE stack identification and address-range map — the main new input this session), `firmware-map.md` (bruce vs gotham top-level structure).

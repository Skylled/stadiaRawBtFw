# Bruce — the codebase-wide diagnostic log/message-`Buffer` framework (session 14)

Target: chasing decompile-status §3b's next-biggest genuinely-unidentified ranges (run #4, `0x600cc6e4`–`0x600d4560`; run #2's `0x60100xxx`–`0x60103xxx` sub-span; run #3, `0x600df286`–`0x600ea868`; run #5, `0x600d8a12`–`0x600df24c`) looking for a BTA/BTE-scale breakthrough. Runs #3 and #5 turned out to be **extensions of already-identified subsystems** (noted briefly at the end of this doc, with pointers to where the detail lives). Run #4 turned out to be a grab-bag of several unrelated small clusters — but one of them, once pulled on, turned into this doc: a small, pervasively-used **message-buffer class + logging/telemetry emission engine** referenced directly from **64 of the repo's 139 attributed source files** (46%), the widest call-graph reach of any single cluster found in this project so far, including the BTA/BTE stack itself.

## Identification: confidence HIGH (core mechanism); MEDIUM (naming/exact semantics)

**High confidence:** a small fixed/growable string-buffer class (several inline-capacity variants) is constructed on the stack at call sites scattered across virtually every subsystem in the firmware, populated with a `__FILE__`-shaped string constant + a line number + a formatted message, and passed into a shared emit/flush engine that packages it into a rate-limited, ISR-aware ring-buffer record and wakes a consumer task. This **is very likely the mechanism that generates the `__FILE__` string leaks** this entire RE project's function-attribution technique (`AnnotateFromFilenames`, per CLAUDE.md) depends on — i.e. this session accidentally found the source of its own primary tool.

**Medium confidence:** the exact class name, the precise severity semantics (plain `LOG()` vs. `CHECK()`/assert-with-abort — both idioms are visible at different call sites), and the final sink/transport (UART? a GATT characteristic? persisted to flash?) are not confirmed — see Open questions.

### Evidence

**1. Universal call-graph reach.** The five core functions (`FUN_600d37ac`, `FUN_600d37b8`, `FUN_60101b76`, `FUN_60101740`, `FUN_601016f0`) are called directly from **64 distinct attributed source files**, extracted mechanically from each function's caller list in `analysis/decomp/`:

```
accessory_detect_ts3a227e, activation_sequence, adapter, adc, append_buffer, application_state,
audio_player, audio_states, battery_service, board, buffer, bug_report, dcp_encryption_engine,
device_info, dynamic_buffer, firmware_image_upload, flash_lut, flash_memory, frames,
gatt_manager_task, gatt_server, get_device_data, gotham, gotham_16mb_mimxrt10xx_mpu, haptics,
haptics_cluster, headphone_state_machine, hid_input_target, http_flash_writer, i2c_device,
input_task, io_pin, key_value_store, keys, led_driver_lp5562, linear_interpolation_source,
logger, logging, main, mimxrt10xx_flash_memory, parser, partition_table, pattern_player,
platform, receiver, recording_pipeline, remote_device_db, reset, sleep_driver, sleep_lock,
snvs, sound_codec_wm8904, state_machine, stats, synapse_audio_processor, system_tasks, thermal,
timer, trigger_bug_report, types, usb_audio_receive, usb_device, usb_device_audio, usb_host,
usb_port_controller_tusb320
```

That spans BT GATT server code, the config-key store, the application state machine, ADC/timers, LED/haptics drivers, USB host+device audio, battery gauging, headphone-jack detection, the OTA/HTTP flash-writer, the input task, i2c, the Gotham/Wi-Fi glue, and more — i.e. essentially the whole non-BTA/BTE application layer. No other single cluster found in this project touches this much of the codebase.

**2. The already-attributed but tiny, never-explained source files turn out to be members of this exact class.** `buffer.h`, `buffer.cc`, `dynamic_buffer.h`, `append_buffer.h`, and `frames.h` were attributed (by leaked `__FILE__` string) back in early sessions but never decompiled (0 of 1–2 functions each, per `bruce-decompile-status.md`). Decompiling their one-or-two functions this session shows they **construct, bounds-check, and pass around the exact same buffer objects** as the unattributed cluster:

- `buffer__60058754` (`buffer.h`, `0x60058754`) builds a local buffer object whose first two constructed fields are literally the string `"buffer.h"` and the constant `0x7b` (123) — a `__FILE__`/`__LINE__` pair — then emits `"Dumping log entries..."`, calls `FUN_6010162e` (see #5 below), and emits `"Log dump completed..."`. **This is almost certainly the implementation behind the `StreamLogBuffer` RPC/debug command** (see #3).
- `buffer__600cbdf4` (`buffer.cc`, `0x600cbdf4`) bounds-checks an index against `[*param_1, *param_1+param_1[1])` and — if out of range — builds a buffer object with a `__FILE__`/`__LINE__` pair and calls the same assert-report path (`FUN_60101740`), otherwise computes a wrapped offset via `FUN_60101536`. Shape of a **circular-buffer logical-index accessor with bounds assertion** — i.e. the read-side accessor for the log ring buffer itself.
- `dynamic_buffer__6005a464`/`dynamic_buffer__600662e0` (`dynamic_buffer.h`) and `append_buffer__6007b59c`/`append_buffer__6007b6c0` (`append_buffer.h`) and `frames__6007b694`/`frames__7a2c0` (`frames.h`) all follow the identical idiom: do the real work, and on a failure/bounds condition, construct one of these buffer objects (via `FUN_600d3b3a` / `FUN_600ce2a0`, the constructors found in the unattributed cluster), fill in `__FILE__`+`__LINE__`+message, and hand it to `FUN_60101740`.

This directly proves the unattributed `0x600d37ac`–`0x600d4550` cluster and these five small attributed files are **one subsystem**, not five unrelated coincidences.

**3. A small adjacent debug/RPC command-name table matches the `buffer.h` function's own behavior.** `analysis/ghidra/bruce_strings.txt` has, at `0x6010277c`–`0x601027ec` (inside decompile-status run #2, right next to the emit-engine functions in #5 below):

```
6010277c  StreamLogBuffer
6010278c  dumpable
601027b4  DumpDeviceInformation
601027cc  ResetDeviceIds
601027ec  GetCurrentTime
```

No direct code cross-reference resolved for these (same "unresolved literal-pointer table" limitation `bruce-bta-stack.md`'s Evidence §1 already documented for the BTA trace-string table — consistent, not a new problem). But `buffer__60058754`'s shape (walk a registered-sink list, bracketed by "Dumping log entries..."/"Log dump completed..." log lines) is exactly what a `StreamLogBuffer` RPC handler would look like, and the immediate adjacency in the image is the same linker-placement pattern (`.rodata` string next to the object code that uses it) that confirmed the BTA string table.

**4. A ring-buffer / rate-limited / ISR-aware record allocator feeding into `tasks.c`.** The emit path bottoms out at `FUN_600cc124` (`0x600cc124`):

```c
undefined4 * FUN_600cc124(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  iVar1 = thunk_EXT_FUN_00007734();                 // get current state/mode flag
  if (((iVar1 == 2) && (iVar1 = FUN_6005856c(), *(char *)(iVar1 + 0xfd) != '\0')) &&
     ((_DAT_e000ed04 & 0x1ff) == 0)) {               // ICSR.VECTACTIVE == 0, i.e. NOT in an ISR
    thunk_EXT_FUN_0000737c(10000);                   // rate-limit/backoff delay
  }
  puVar2 = (undefined4 *)FUN_6005f8c0(param_1,param_2,param_3);  // allocate a record slot
  *puVar2 = DAT_600cc174;                            // tag with a magic/version constant
  if (puVar2[0x16] != 0) {
    tasks__600ca27c();                                // wake the consumer task
  }
  return puVar2;
}
```

`_DAT_e000ed04` is the Cortex-M **ICSR** (Interrupt Control and State Register) — checking `VECTACTIVE == 0` is a textbook "am I currently executing inside an interrupt handler" test, gating a rate-limit backoff so logging from thread context doesn't starve. The record is tagged with a magic constant and, conditionally, wakes an already-attributed `tasks.c` function. This is a coherent shape for **a background log-flush/streaming task fed by a lock-free-ish ring buffer that ISR and thread contexts can both write into** — not a naive synchronous `printf`-to-UART.

**5. A registered-callback sink-fanout function.** `FUN_6010162e` (called only from `buffer__60058754` and `logger__600cbebc`, both attributed):

```c
void FUN_6010162e(int param_1,undefined4 param_2)
{
  puVar2 = (undefined4 *)(param_1 + 0x174);
  for (puVar1 = (undefined4 *)(param_1 + 0x15c); puVar2 != puVar1; puVar1 = puVar1 + 2) {
    (*(code *)*puVar1)(puVar1[1],param_2);            // call each registered (fn, ctx) pair
  }
}
```

Walks a fixed-size array of `(function pointer, context)` pairs and invokes each — a **registered-sink fan-out**, exactly what a "stream this log buffer to N registered listeners" implementation needs, and exactly what `buffer.h`'s own function (`StreamLogBuffer` candidate) calls in the middle of its two bracketing log lines.

## What this explains

- The origin of the `__FILE__` string leaks this whole project's attribution methodology (`bruce_srcmap.csv`, `AnnotateFromFilenames`) is built on: every one of the tiny attributed files this session decompiled embeds its own filename + a line number directly into one of these buffer objects at the point of construction — that's almost certainly a `LOG(...)`/`CHECK(...)`-style macro expanding to `__FILE__, __LINE__`, not something manually written per call site.
- Why so many otherwise-unrelated small functions across 64 files call into a common tiny cluster: they're not calling a shared *subsystem* in the BTA/BTE sense, they're expanding a shared **logging/assertion macro**.
- A plausible reading for the `StreamLogBuffer`/`DumpDeviceInformation`/`ResetDeviceIds`/`GetCurrentTime` RPC name cluster: an engineering/diagnostic command surface (likely reachable over BT, given its neighbors are BTA-adjacent — unconfirmed) for pulling this log ring buffer and device info off the controller.

## What this does *not* explain (don't over-read run #4)

Decompile-status run #4 (`0x600cc6e4`–`0x600d4560`, 304 functions) is **not** wholly this subsystem. Sampling across the range this session found at least two other, unrelated clusters sitting in the same run:
- `~0x600ccc10`–`0x600cd9ac`: software float math (`FUN_600ccfb4`, `FUN_600ccc10`, `FUN_600cd73c` — fdlibm/newlib-shaped trig-argument-reduction and `logf`-shaped polynomial evaluation, complete with split-precision constants and `coprocessor_function2` FPSCR-exception-flag calls). Plain C library code, not app-specific.
- `~0x600cd9ac`–`0x600ce1f8`: a `printf`-family formatter core (`FUN_600cdfb4` switches on format-spec bytes `%d/%i/%u/%o/%x/%X/%c/%s/%n/%p` with a digit-lookup table at `DAT_600ce1d0`) — newlib's internal `vfprintf`/`_svfprintf_r`-shaped engine, again general C library, not the log-buffer subsystem itself (though plausibly what the log-buffer's message-formatting call sites use upstream of it — not traced this session).
- `~0x600d0332`: an unidentified state/tag dispatcher (`FUN_600d0332`, 1244B) switching on byte values that look like ASN.1/BER context tags (`0x21/0x22/0xa1/0xa2`) with an indirect (vtable-style) callback dispatch Ghidra couldn't resolve ("Could not recover jumptable... Too many branches"). Not conclusively identified — flagged, not guessed.

So run #4 is now **partially** explained (three separate identified clusters: libm, printf, log-buffer) plus one genuinely open question (`FUN_600d0332`'s cluster), not a single coherent subsystem end to end.

## Function table (this session)

| Address | Bytes | Role |
|---|---:|---|
| `0x600d3b3a` | 22 | Buffer ctor, 14-byte-header variant (inline capacity 0x80) |
| `0x600ce2a0` | 38 | Buffer ctor, extended variant (2 extra header fields — owner/type?) |
| `0x600d3b24` | 22 | Buffer release, 20-byte-header variant → `FUN_601016f0(0x14,...)` |
| `0x600d37b8` | 22 | Buffer release, 40-byte-header variant → `FUN_601016f0(0x28,...)` |
| `0x600d4550` | 16 | Buffer release, simplest form (direct inline-pointer-vs-heap check) |
| `0x600d37ac` | 12 | Trivial forwarder into `FUN_60101b76` — 76+ call sites |
| `0x600d4330` | 56 | Buffer → typed-value marshal helper |
| `0x600d382e` / `0x600d39ba` | 90 / 90 | `keys.cc`-adjacent typed get/set glue sharing the same error-report idiom (type tag 4=int32, 1=bool) |
| `0x600d3618` | 32 | Millisecond-rounding timestamp helper, used widely as a log-entry time source |
| `0x601010c8` | 100 | Typed-value validate/lookup helper shared by `keys.cc` and `dynamic_buffer.h` |
| `0x60101b76` | 30 | Append a C string into the buffer up to remaining capacity — 70+ call sites |
| `0x60101740` | 32 | Flush/emit entry point → `FUN_601016f0` then `FUN_600cc124` — 60+ call sites |
| `0x6010162e` | 46 | Registered-sink fan-out (walks `(fn,ctx)` pairs at struct offset `0x15c`–`0x174`) |
| `0x601016f0` | 80 | Shared buffer-release path (alloc-record lookup + free + bookkeeping) |
| `0x60101b4c` | 14 | Buffer clear/reset |
| `0x600cc124` | 60 | Ring-buffer record allocator: ISR-aware rate limit, magic-tag, wakes `tasks__600ca27c` |
| `buffer__60058754` | 128 | **`buffer.h`** — likely `StreamLogBuffer` implementation itself (see Evidence §2) |
| `buffer__600cbdf4` | 94 | **`buffer.cc`** — circular-buffer bounds-checked logical-index accessor |
| `dynamic_buffer__6005a464` / `__600662e0` | 90 / 136 | **`dynamic_buffer.h`** — heap-backed growable buffer alloc, asserts via this framework on OOM |
| `append_buffer__6007b59c` / `__6007b6c0` | 90 / 96 | **`append_buffer.h`** — append/consume with capacity assertion |
| `frames__6007b694` / `__7a2c0` | 36 / — | **`frames.h`** — frame-window space helper with capacity assertion |

Callees not decompiled this session but load-bearing to the chain (named, not yet read): `FUN_6005f8c0` (record-slot allocator, 140B), `FUN_60100e78` (50B), `FUN_60101b94` (14B), `FUN_600cbfa0` (88B), `FUN_600cc090` (142B), `FUN_6005856c` (4B — likely a task/state-pointer accessor thunk), `FUN_60101536` (38B — ring-buffer modulo-wrap).

## Address-range notes

Not a single contiguous block — two clusters plus a supporting string table, in different decompile-status runs:
- Buffer ctor/dtor family: `~0x600ce2a0`–`0x600d4550`, inside run #4 (`0x600cc6e4`–`0x600d4560`).
- Emit/append/sink engine: `~0x600cc124` (just below run #4's start) and `~0x60100e78`–`0x60102000ish`, inside run #2 (`0x600ecb72`–`0x6013d4e4`).
- RPC/debug command-name strings: `0x6010277c`–`0x601027ec`, also inside run #2, immediately adjacent to the Synaptics audio-debug command strings (`SynCaptureBypass*`/`SynLoopbackMix*`/`SynAgc*`/`SynNs*`/`SynAec*`, `0x6010310b`–`0x60103221`) and the BTA build-banner string (`"BTA 4 Google V0.0.2 ARMGCC Newlib "`, `0x60103238`) — confirms run #2's `0x60102xxx`–`0x60103xxx` sub-span is a dense, mixed debug/diagnostic string-table region, not itself BTA/BTE code (matching `bruce-bta-stack.md`'s own note that run #2 also holds the BTA trace-string table starting a little further along at `0x60103xxx`).

## Open questions / not chased further this session

- Exact class name and full method set (only ~10 of what's probably a larger method family were read).
- Whether `LOG`-style (informational, called unconditionally in normal control flow, e.g. `main.cc`/`timer.h`/`adc.h` call sites) and `CHECK`-style (only on an error/bounds branch, e.g. `dynamic_buffer.h`/`append_buffer.h`/`frames.h`) share one macro with a severity parameter or are two related-but-distinct macros — both idioms are visible but not disambiguated.
- The actual sink transport: does `StreamLogBuffer` push over a BT GATT characteristic (there is BT-adjacent context nearby), USB, or something else? Would need to trace the registered-sink array's contents (the `(fn, ctx)` pairs `FUN_6010162e` walks) — not attempted this session, flagged as the natural next step for whoever picks this up.
- `FUN_600d0332`'s cluster (§ What this does not explain) — a real, separate open question inside run #4, not part of this subsystem.

## Also investigated this session (extensions of already-identified subsystems, not new)

- **Decompile-status run #3** (`0x600df286`–`0x600ea868`, 95.2% dense, 0 leaked strings) is BoringSSL/OpenSSL runtime-support code, called overwhelmingly from the already-fully-decompiled `bcm.c` plus `evp.c`/`p_ed25519_asn1.c`/`tasn_dec.c`/etc.: `FUN_600e0552` (a 16-slot ring-buffer error-record writer matching BoringSSL's `ERR_put_error`/`ERR_STATE` shape almost exactly — `ERR_NUM_ERRORS` is classically 16), `FUN_600e092c` (malloc-with-header, `OPENSSL_malloc`-shaped), `FUN_600e6a6c` (allocator size-class bucketing), `FUN_600e7706`/`FUN_600e72fc` (`BN_is_odd`/bignum-growth-copy-shaped, calling `bcm.c` functions directly), `FUN_600e6a52` (byte-swap helper). This extends `bruce-crypto.md`, not a new subsystem — flagged here for whoever continues that doc, not written up separately.
- **Decompile-status run #5** (`0x600d8a12`–`0x600df24c`, 87% dense) is called overwhelmingly from already-*named* BTA/BTE functions (`bta_gattc_init_cache`, `bta_dm_acl_change`, `gatt_enc_cmpl_cback`, `l2cu_release_ccb`, `btu_hcif_command_status_evt`, and more): `FUN_600d9250`/`FUN_600d9290` are a buffer-pool free-list pop/remove pair with a `-0x38`-byte header offset — the classic **GKI (Generic Key Interface) buffer-pool allocator** BTE code is built on — and `FUN_600d9c0a` zero-initializes a ~2.8 KB control block (multiple `memset`s of sizes `0x50`/`0xa0`/`0x960`/`0x10`/`0x40`), BTA/BTE-control-block-shaped. This confirms `bruce-bta-stack.md`'s existing speculation that BTA/BTE-adjacent territory extends beyond the formally-identified `0x600921b8`–`0x600c9cc4` block — extends that doc, not written up separately. One outlier: `FUN_600dcf8c` (984B, the range's largest function) is a **radix-4 FFT butterfly** (float, classic decimation-in-time/frequency combine pattern) sitting inside this otherwise-GKI range — a stray sighting of the audio-DSP subsystem `bruce-itcm.md` already found in ITCM, now also seen in main flash. Not chased further.

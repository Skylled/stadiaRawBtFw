# Bruce — miscellaneous decompiled functions (session 6 sweep)

Cross-check pass over `analysis/decomp/*.c`: every file was grepped against the other four
analysis docs (`bruce-io-paths.md`, `bruce-crypto.md`, `bruce-itcm.md`, `bruce-ghidra.md`,
`firmware-map.md`) by function name/address to find decompiled-but-never-written-up functions.
~21 were undocumented; write-ups below, grouped by what they turned out to touch. Confidence is
stated per entry — several of these are small glue functions where the surrounding call graph is
the main evidence.

**Bottom line up front:** none of these is the missing report-packing function or the main
event/dispatch loop. The one lead worth following up is `FUN_60071624` (late-stage board bring-up,
possible GPIO-IRQ/NVIC registration pass) — it's boot-time registration, not the ISR itself, but it
sits exactly where you'd expect the button-IRQ wiring to happen, reinforcing the existing
"buttons are edge-interrupt-driven" hypothesis from `bruce-io-paths.md`. `FUN_600ba1c4` is a solid
new subsystem find (a connection/session protocol parser feeding `state_machine.cc`), but its
fields are connection handles and event opcodes, not button/stick data, so it's unrelated to HID
reporting.

## Rumble / haptics — the missing per-tick drive step

`bruce-io-paths.md` already documents `haptics_cluster.cc @ 0x6006581c` (cluster init/enable) and
`haptics.cc @ 0x600656a0`/`0x600655dc` (enable/disable, battery-compensated strength scaling). Two
functions found in this sweep fill in the actual **periodic update** step between those:

### `haptics_cluster__600658b4` (haptics_cluster.cc) — confidence: high
The per-tick cluster update, called from `FUN_600d6d2a`. Updates the L/R target-magnitude fields
(offsets `+8`/`+0x10`) if new values were supplied, then does a **bus/queue transaction** (cmd 3,
via `thunk_EXT_FUN_00007a2c` — the same "bus/queue transaction" HAL primitive resolved in
`bruce-itcm.md`) against the object's driver handle at `+0xd4`, gated by `timers__600cae38`
(FreeRTOS timer-is-active check). On success it stops any channel whose new magnitude is zero
(`FUN_600d6cca`), otherwise drives it (`FUN_600d6cf8` → `haptics__6006573c`, next entry), then —
after two `DataMemoryBarrier` calls — writes the final L/R magnitudes out via
**`external_controller__6007053c(left, right)`**. `external_controller.cc` is a real attributed
source file (confirmed in `bruce_srcmap.csv`) not previously mentioned in any analysis doc — likely
the motor-driver-IC (or PWM peripheral) write. On failure it logs `"..."` via
`FUN_60051120`/`FUN_600d37ac` (same structured-log-record builder seen elsewhere).

### `haptics__6006573c` (haptics.cc) — confidence: high
Called from `FUN_600d6cf8`. If `param_2` (a duration/magnitude) is 0, just calls
`haptics__600656a0()` (documented stop path). Otherwise: reads a tick value
(`thunk_EXT_FUN_0000714c`, the trivial "return global tick/state word" ITCM thunk from
`bruce-itcm.md`) and does a bus/queue transaction (cmd 1) to check whether the pulse is still
running; if so it just logs status. If not, it converts the signed input to float
(`VectorSignedToFloat`), scales it (`* DAT_60065810 / DAT_60065814`), and calls
**`haptics__600655dc`** — the already-documented battery-compensated strength scaler — closing the
loop from "cluster wants this much rumble" to "scaled, battery-corrected motor drive." Two
guard-logged failure paths (`FUN_600601a4`, `FUN_60060284`) precede a final
`FUN_600cedd8(obj+0x20, obj+0x18, 0)` call — the `(obj+0x20, obj+0x18)` argument pair is the same
shape used for GPIO DR-register-pointer + bit-index elsewhere in the io-pin code
(`bruce-io-paths.md`'s `FUN_600ce24c`), so this is plausibly a GPIO line toggle (motor enable pin)
around the actual pulse.

### `FUN_60072260` — confidence: high (for what it constructs), low (for the exact watchdog logic)
Called from `timer__60073bf0` (the input/HID task constructor already documented in
`bruce-io-paths.md`). Initializes a haptics-watchdog sub-object and arms a **`"Haptic watchdog"`
timer, period 5000 (ms), one-shot, callback `PTR_LAB_600d99cc`** via `timer__600721e8` (a sibling
of the generic timer-constructor helper documented below). This is a new, previously-unlisted
detail on top of the "Haptic pulse" timer (1000 units) `bruce-io-paths.md` already calls out from
the same constructor — the input task apparently arms *two* haptics-related timers: a periodic
pulse timer and a 5-second watchdog (presumably to force-stop rumble if a stop/ack message is
never received).

### `FUN_600d99d2` — confidence: low-medium
6-byte function: `(*fn)(arg)` — an indirect call through a function pointer passed in a register.
Ghidra couldn't recover a jump table at `0x600d99d6` ("Too many branches") and mis-labeled the
first parameter `UNRECOVERED_JUMPTABLE`; in reality this is almost certainly just a generic
one-argument callback trampoline, not a real switch/jump table. Its address (`0x600d99d2`) sits
right next to `PTR_LAB_600d99cc`, the callback pointer `FUN_60072260` hands to the haptic-watchdog
timer — plausible (not confirmed) that this trampoline *is* that watchdog-expiry callback.

## Power management

### `sleep_driver__6005990c` (sleep_driver.cc, 744 bytes) — confidence: high
Not previously documented as its own entry (only used in `bruce-io-paths.md` as a boundary marker
for the `input_calibration.cc` address range). This is the controller's **low-power sleep
implementation**, called from `sleep_lock__60059d54`:
- Rejects sleep requests shorter than 10 (ms/ticks) or when the driver object isn't initialized.
- Checks for a usable wakeup source; if the SRTC (secure RTC) alarm isn't enabled and no other
  wakeup source exists, logs `"Skipping sleep as no wakeup source"` and bails (`"SRTC isn't
  enabled, so the sleep..."` is the softer variant that still proceeds).
- Reads the current SRTC time (`FUN_600d4dc2`), computes a wake deadline (current + requested
  duration, with proper 32-bit carry propagation into a compare against `DAT_60059bf8` — this is a
  real timestamp/tick-rate arithmetic block, not crypto, despite superficially similar add/carry
  shape), and arms the SRTC alarm (`FUN_6006089c`, `FUN_60060910`).
- Spin-waits via **`thunk_EXT_FUN_0000737c`** — the PendSV/context-yield ITCM primitive identified
  in `bruce-itcm.md` — checking a status bit each iteration, capped at 0x32 (50) ticks per yield,
  until the deadline passes or a wakeup-ready condition is observed.
- Calls **`FUN_60070080`** to actually enter the low-power mode (its failure path logs
  `"SwitchToLowPowerMode failed"`, which is presumably that function's real name); on wake,
  re-reads SRTC time to report actual elapsed sleep duration to the caller, and disarms the SRTC
  alarm (`FUN_60060940`, "Unable to stop SRTC alarm" on failure).

This is a legitimate, previously-unmapped subsystem (device power management / sleep-mode entry) —
worth a mention in `firmware-map.md`'s module list if that doc gets revisited, though per this
task's constraints that edit isn't made here.

## Board bring-up / GPIO — extending the ADC and IRQ story

### `FUN_60071624` — confidence: medium, flagged as a button-IRQ lead
Called **16 times** in a row from the tail of `xbara__600cbdc8` (the board bring-up function
documented in `bruce-io-paths.md`), immediately after a long run of `io_pin__6005fe04` calls
(which, per that doc, configure GPIO direction/mux and — when a flag is set — register a GPIO
interrupt via `FUN_600532f0`). Each call: `FUN_60071624(pin_object, shared_context)`. The function
itself unpacks 7 fields out of the pin object and forwards them, plus a shared name pointer
(`DAT_6007165c`) and the shared context, into `FUN_60060040`, then finalizes with `FUN_600d9b7c`.
The same ~16 offsets this is called with are also passed to `FUN_600d9b7c` **earlier** in
`xbara__600cbdc8` (before MPU/TRNG init even runs) — i.e. there's an early "clear" pass and a late
"register" pass over the same set of pin/subsystem objects. This two-phase clear-then-register
shape, sitting directly after the pin-IRQ-configuration calls and right before SRTC/hardware-timer
init, is a strong candidate for **NVIC/interrupt-vector registration** — i.e., this may be where
button GPIO interrupts actually get hooked to their handlers. Not confirmed (would need
`FUN_60060040` and `FUN_600d9b7c` decompiled, and `DAT_6007165c` resolved), but directly relevant
to `bruce-io-paths.md`'s open "button read path" thread and worth prioritizing next.

### `FUN_60052294` — confidence: high
`*(u32*)(DAT_600522b4 + (x>>8)*4) = (that word & ~(3<<(x&0x1f))) | (val<<(x&0x1f))` — a generic
2-bit-field register-write helper (bitfield index encoded as `byte_offset<<8 | bit_offset`). Sole
caller is `FUN_600522b8`, which `bruce-io-paths.md` already identifies as the ADC1/ADC2 one-shot
configuration-register writer (base+0x44/+0x48). This is that writer's low-level "set a 2-bit
field" primitive — confirms the ADC config path is built from generic bitfield-register helpers
rather than fixed masks, no new subsystem but fills in a supporting detail.

### `FUN_600d9a5e` — confidence: high
This **is** the ADC channel-table binary search that `bruce-io-paths.md` already describes
narratively under `adc__60071f74` ("does a binary search of a channel table at `DAT_6007206c`") —
it just hadn't been individually written up. Confirmed shape: binary search over up to 16 entries
of an 8-byte-stride table, keyed by a byte at each entry's offset 0 (the channel number), called as
`FUN_600d9a5e(table_base, channel_num)`. Returns a pointer to the matching entry, or to a fixed
"default/not-found" slot at `table_base+0x80` (i.e. exactly past the 16th 8-byte entry) if no exact
match. Direct caller: `adc__60071f74`.

## Input-task constructor internals (`timer__60073bf0`)

Four small helpers called directly from the already-documented input/HID task constructor
(`bruce-io-paths.md`'s "Input subsystem construction" section). None of these touch button or
stick/ADC *values* — they're all setting up sub-objects/config templates, consistent with that
doc's session-5 conclusion that this constructor is boot-time wiring, not the runtime sampler.

### `FUN_60065454` — confidence: low-medium
Clones a static 0x68-byte template (`DAT_600654c0`, copied via the resolved `memcpy` ITCM thunk)
into the new object, copies 4 more template words into fields `0x1b`-`0x1e`, then sets a batch of
scalar defaults: two `0xffffffff` sentinels (fields `0x1f`/`0x21`, each followed by a paired zero
field — looks like `{max, count}` or `{invalid-handle, refcount}` pairs), `100`/`10` (fields
`0x25`/`0x26` — a plausible percent/threshold pair), and `0x1000` (field `0x2d` — plausibly a
buffer size, 4096). Shape is consistent with initializing another descriptor/state object in the
input task (calibration-adjacent or report-adjacent), but without the template's actual bytes
decoded, purpose is a guess.

### `FUN_600715fc` — confidence: low
Trivial: sets one pointer field to a static value, zeroes a couple of scalar fields, calls
`FUN_601017fc()` (no visible arguments — likely a mutex/list-node initializer operating on an
implicit `this` in a register), zeroes one more byte. Generic sub-object constructor; no strong
signal on which sub-object.

### `FUN_60071814` — confidence: low
Pure 20-word (0x50-byte) struct copy from a static table `DAT_6007186c` into the new object — no
computation at all. Likely duplicating one of the static descriptor/range tables referenced
elsewhere in the input-ctor's calibration-schema section (`bruce-io-paths.md`'s `FUN_600717a0`
10-word records — 20 words could be two such records back-to-back). Not enough here to say more.

### `FUN_600748ec` — confidence: medium
`timer__60073bf0(DAT_60074904); FUN_60101c48(DAT_60074904, DAT_6007490c, DAT_60074908);` — directly
invokes the input/HID task constructor with a fixed global argument, then registers the result
(name/type/pointer triple, going by the 3-argument shape) with what's presumably a generic
object/task registry. No callers found in the decompiled set (consistent with this being reached
only via a static constructor-pointer table, e.g. a C++ static-init array), which also matches why
it wasn't picked up by earlier call-graph tracing from `main`. This is likely **the actual call site
that instantiates the input subsystem singleton at boot** — useful if anyone later wants to find
where in the boot sequence the input task object actually gets created (vs. just its constructor
body).

## `keys.cc` — typed config store, filling in a helper

### `keys__60065d1c` — confidence: high
Companion to `keys__60066070` (`bruce-io-paths.md`'s already-documented `Get(key_id, out, size)`).
This is the **size-of(type)** lookup: given a key's type tag (switch on a byte field), returns its
byte width via an out-param — 1 byte (types 1/7/0xb), 2 bytes (6/0xa), 4 bytes (2/3/5/9), 8 bytes
(4/8). Type 0 is the variable-length/string case: if the key has a value, its length comes from
`FUN_6004cb28`; if not yet initialized, it tail-calls a noreturn error handler (`FUN_6010209a`,
Ghidra-flagged "does not return" — presumably an assert/abort). Any other type value logs an error
(`FUN_6010165c`) and returns error code `0xd`. Reinforces `bruce-io-paths.md`'s correction that
`keys.cc` is a generic typed KV store, not gamepad button state.

### Session 15: the rest of `keys.cc` (17 more functions, now 19/19 — file complete)

`bruce-decompile-status.md`'s cheap-win sweep decompiled every remaining function in `keys.cc`. Together with the two functions above, the full picture is now a complete, generically-typed config/property key-value store API — `keys__60066070`'s already-documented `Get(key_id, out, size)` and `keys__60065d1c`'s size-of(type) helper turn out to be just two entry points into a much larger surface. Each key record carries a **type tag** (byte field, same 0–0xb enumeration as `keys__60065d1c`'s size switch: 0=string, 1/7/0xb=1-byte, 6/0xa=2-byte, 2/3/5/9=4-byte, 4/8=8-byte), a **read-only flag**, and a **"factory property" flag** gating erasure — every function below checks these before acting and returns a small integer status code (`0`=OK, `3`=type mismatch, `5`=uninitialized, `7`=read-only/protected, `0xd`=bad type, `0xf`=buffer too small) via the same structured-log-record idiom (`FUN_60051120`/`FUN_600d37ac`/`FUN_600d37b8`/`FUN_600ce2a0`) used throughout the codebase's `Buffer` logging framework (`bruce-log-buffer.md`).

- **`keys__60065df0`** (106B) / **`keys__60065e68`** (66B) — typed-size accessors: read a key's declared size (delegating to `FUN_601010c8`, an ASN.1/protobuf-shaped typed-value decode helper) or its stored length, erroring `"..."` on an invalid key.
- **`keys__60065eb8`** (400B) — the **string Get**: copies up to `param_3` bytes of a string-typed key's value into the caller's buffer, logging detailed diagnostics (`"...is <n> bytes, buffer is <m>"`-shaped) on truncation/type-mismatch, and handling both the "resident" (already materialized) and "must decode from typed-store" cases via `key_value_store__600cb598` / `FUN_601010c8`.
- **`keys__600666f0`** (604B, largest in the file) — **GetAsString**: converts *any* typed key's value to its ASCII string representation. Switches on the type tag (cases 1–0xb) and calls one of eleven per-type formatters (`FUN_600d732e`/`FUN_600d7032`/`FUN_600d72b8`/`FUN_600d70e6`/`FUN_600d382e`/`FUN_600d708c`/`FUN_600d39ba`/`FUN_600d6fd8`/`FUN_600d6f7e`/`FUN_600d6f24`/`FUN_600d6eca` — bool/int8/int16/int32/int64-shaped formatters based on their call sites elsewhere; audit correction: an earlier draft of this row listed nine of the eleven, omitting the case-1 and case-8 handlers `FUN_600d732e`/`FUN_600d6fd8`), plus a separate type-0 (string) path that allocates a scratch buffer and delegates to `keys__60065eb8`/`keys__60065df0` before freeing it via `thunk_EXT_FUN_00008832`/`0000b52a` — the "raw byte-buffer copy for the untyped/generic case" in the original wording. This is the counterpart the CLI/diagnostic-dump code (`bug_report.cc`, `logging.cc`) almost certainly calls to print arbitrary config keys.
- **`keys__600668dc`** (90B, string Set) / **`keys__60066944`** (88B, bool Set) / **`keys__600669a8`** (182B, int Get, types 3/8/9/0xa/0xb) / **`keys__60066a74`** (186B, int Get, types 2/4/5/6/7) — typed Set/Get pairs, each gated by the read-only/factory flags (returning `7` if protected) before delegating to a per-type parse helper (`FUN_600d72ec`/`FUN_600d6fd8`/`FUN_600d6f7e`/etc., the inverse of `keys__600666f0`'s formatters).
- **`keys__60066b40`** (92B) / **`keys__60066ba8`** (114B) — thin wrappers forwarding to `keys__6006615c` (already-attributed helper) and a fixed-size (4-byte) typed Set via `FUN_60101198`, respectively — both used from a common caller (`FUN_60078e00`) alongside the array-indexed Get/Set pair below.
- **`keys__60066c28`** (162B) / **`keys__60066ce0`** (162B) — **array/indexed element Set and Get**: same type-tag switch as the scalar accessors, but operating on one element of an array-typed key (types 3/8/9/0xa/0xb for Set, 2/4/5/6/7 for Get) — the array-typed sibling of `keys__600669a8`/`keys__60066a74` above.
- **`keys__60066d94`** (172B) → **`keys__600661fc`** (116B) — **Erase(key)**: checks the "factory property" flag (logs `"Unable to erase factory properti..."` / `"Property %s cannot be erased from the comman[d line]..."` and refuses if set or absent), otherwise delegates to `FUN_6010112c` to remove the entry.
- **`keys__60066284`** (74B) — a small struct-out accessor: packs `{value_ptr, type_size_via_lookup_table, is_bool_flag}` into a 3-word caller struct — likely feeding a generic "describe this key" / introspection call (e.g. for the CLI `keys list`-style command the "Property %s cannot be erased" wording implies exists).

Net: `keys.cc` is now fully decompiled (19/19) and its purpose is unambiguous — a generic, typed, read-only/factory-protected configuration and calibration property store with Get/Set/GetAsString/Erase and both scalar and array-element accessors, used throughout the firmware (joystick calibration keys, `HidPollMs`, BLE device name, and others already cross-referenced in `bruce-io-paths.md`). Definitively **not** a gamepad-button table, reconfirming CLAUDE.md's known trap.

## `key_value_store.cc` — the flash-backed persistence engine underneath `keys.cc` (session 17)

Picked as a top-10 `bruce-decompile-status.md` §3a cheap win (1,968 remaining bytes, 0/6 done); all 6 decompiled this session, file now 6/6 complete. `keys.cc`'s row above already called two of these out by name (`key_value_store__600cb598` as the typed-store decode/fetch path behind `keys__60065eb8`'s string Get) — this section is the low-level flash storage engine those calls bottom out in.

Where `keys.cc` is the typed, named-property-facing API (`Get`/`Set`/`GetAsString`/`Erase` by key id), `key_value_store.cc` is the **wear-leveled flash record store** underneath it — reads and writes fixed-format records to/from raw QSPI flash, using a `0x55aa` magic value to mark valid records and a monotonic generation/write counter per record to pick the freshest of several redundant copies (classic embedded NVS/wear-leveling design, not unlike NXP's own `flash_nvm`/`nvm` libraries or Zephyr's `NVS`):

- **`key_value_store__600cb6fc`** (1,006B, largest in the file) — **the store's lazy-init/rebuild scan.** On first use (guarded by a per-object init flag), zero-fills a working index table, then walks flash sector-by-sector: for each candidate slot, reads a small header via the object's own vtable read callback (`vtable+0xc`) plus a raw flash read (`FUN_601018de`), checks for the `0x55aa` magic, and — if found — compares the record's generation/sequence pair against the currently-tracked maximum (`param_1[0x18]`/`param_1[0x19]`, a 64-bit-shaped counter) to decide whether this copy is the "live" one; ties and out-of-range/corrupt records get logged via the `Buffer` framework (`FUN_600d37ac`/`FUN_600d37b8`) rather than crashing. Finishes by calling `key_value_store__600cb39c` (below) to reconcile/erase stale copies and marking the store initialized. Shape is unmistakably a **power-loss-safe flash journal scan-and-recover routine** run once at boot.
- **`key_value_store__600cb39c`** (126B) — small **compaction/reclaim helper**: if a "needs compaction" check (`FUN_60100b38`) fails and the flash region isn't already erased (`FUN_60100bb0`), logs progress twice (`"..."`/`0x173`, `0x179`) while erasing (`FUN_60100f90`) and re-verifying — a straightforward "erase this sector if it's due for reclaim" step, called both from the boot-time scan above and standalone.
- **`key_value_store__600cb2fc`** (148B) — **append a new record slot to the in-memory index** (capped at 100 live entries — matches `keys.cc`'s error code `0xd`/"bad type" ceiling seen elsewhere as a suspiciously round limit): if under the cap, clears a small local descriptor, probes it via the same vtable read callback, and on success stores the new record's `{offset, size, flags}` triple into the index array and bumps the count; on failure or at the 100-entry ceiling, logs an error and returns status `0xd`.
- **`key_value_store__600cb428`** (46B) — trivial two-step erase wrapper: logs, then calls `FUN_60100f90(...,1)` (erase) and on failure retries with `FUN_60100f90(...,0)` (a "try aggressive, fall back to gentle" erase-mode pattern).
- **`key_value_store__600cb460`** (304B) — **read a stored value out of a slot**, with a size/generation match check up front (returns `0` immediately on any mismatch — a defensive read-integrity guard) and then a chunked copy loop (`FUN_601018de` flash-read → `thunk_EXT_FUN_0000b554`/`memcmp`, resolved in `bruce-itcm.md`, verifying each chunk) with an early-out and `Buffer`-framework error log if a chunk fails to verify — i.e. **read-with-verify**, not a raw unchecked copy.
- **`key_value_store__600cb598`** (338B, the one `keys.cc` already called by name) — **the typed-store Get entry point** proper: validates the destination buffer and requested size against the record's declared width, looks up the record's slot (`FUN_60100e78`), checks a per-record "erased/tombstoned" byte, reads the record header and confirms the `0x55aa` magic, then calls `key_value_store__600cb460` (above) to do the actual verified read — 16 distinct callers across `keys.cc`'s per-type formatters (`FUN_600d70xx`/`FUN_600d6fxx`/`FUN_600d39ba`/`FUN_600d382e` — the same eleven-formatter family `keys__600666f0` dispatches through) plus `dynamic_buffer.h`/`append_buffer.h` (`bruce-log-buffer.md`) and `input_task__600764fc` (below) — far and away this file's most heavily-used entry point.

**Net:** `key_value_store.cc` closes out the picture `keys.cc` started — together they're a complete two-layer persistent-config subsystem: a typed, named-property-facing API on top of a wear-leveled, magic-tagged, generation-counted flash record store with a boot-time scan/recovery pass and a bounded (100-slot) in-memory index. Confirms and extends the existing "not gamepad buttons" trap note: this is calibration constants, `HidPollMs`, BLE device name, and similar small persistent settings, stored the way you'd expect an embedded NVS to work.

## `input_task.cc` — a config/telemetry helper, not the report packer

Despite the promising name, neither function here touches button state, stick/ADC values, or an
HID report buffer — they're a config-value loader with structured-logging side effects.

### `input_task__600764fc` — confidence: medium
Tries a fast path first (`FUN_600d6e14` check → `keys__60066070` typed-store `Get`, type 4/32-bit).
If that's not available, falls back to decoding a value via `FUN_60065db0`/`FUN_60065dd8` (get two
sub-fields) → `FUN_601010c8` (signature `(a, b, &out_struct)` — plausible ASN.1/protobuf-style
decode, and `tasn_dec.c` is a real 7-function attributed module per `bruce-ghidra.md`'s module-mass
table) and, on success, caches it back into the KV store (`key_value_store__600cb598`). Either way
it logs the outcome (same structured binary log-record builder as elsewhere:
`FUN_600d3b3a`/`FUN_600d37ac`/`FUN_600d736c`/`FUN_60101ba2`) and falls back to a default value of
`0x10` on total failure, then calls `input_task__60076438` with whatever value was resolved.

### `input_task__60076438` — confidence: medium
Given that resolved value (`param_2`): if zero, returns error 3. Otherwise does a bus/queue
transaction (cmd 4) against a handle at `obj+0x3a4`; on success, converts the value into a
**12-bit fixed-point percentage** (`value << 0xc / 100`, stored at `obj+0x68`) and an odd count
(`value*2 - 1`, at `obj+0x6c`; the earlier branch on `param_2 < 5` picks between two other
constants, 10 vs 0, stored at `obj+0x64`). It then emits a structured telemetry record with four
key/value pairs (the raw value, the fixed-point percentage, the branch constant, and the odd count)
via the same binary log-record builder. The `<<0xc / 100` fixed-point-percentage shape is
consistent with configuring a haptic-pulse duty cycle or intensity ramp (ties back to the "Haptic
pulse" timer noted in the `timer__60073bf0` write-up in `bruce-io-paths.md`), but this is inference
from shape, not a confirmed link — flagged as medium confidence only.

## Generic glue / dispatch primitives

### `FUN_600d9ab2` — confidence: low-medium
`obj = thunk_EXT_FUN_00007c58(); (*(code**)(obj+8))(*(u32*)(obj+0xc), obj);` — acquires a
lock-guarded object pointer (via the mutex-protected-field-read ITCM thunk resolved in
`bruce-itcm.md`) and calls through its vtable at offset 8 with `(obj+0xc value, obj)`. Generic
"dispatch through a locked object's vtable" trampoline — the same C++-object-with-vtable pattern
seen throughout this firmware, but with no source-file attribution nearby, can't say which
subsystem owns it.

### `FUN_600d9a56` — confidence: low
Two-instruction wrapper: `FUN_600926a0(*param_1 + 0x68)`. Not enough context (callee
undecompiled, no callers found) to say more than "thin forwarding wrapper into a `+0x68` field."

## Generic infrastructure

### `timer__58e0c` / `timer__60058e0c` (timer.h) — confidence: high
A generic **"create a FreeRTOS software timer, assert on failure"** wrapper: stores the
callback/args into the new timer object, and if a name pointer wasn't supplied
(`param_3 == 0`) or the underlying `timers__600cad24` create call fails, it builds and raises a
`CHECK failed` diagnostic (`FUN_600ce2a0` + `FUN_60101740`, referencing literal `timer.h` and a
"CHECK failed" string) rather than returning an error code — i.e. these are non-recoverable
asserts. This explains where the `"CHECK failed"`-style aborts seen from several timer-creation
call sites (haptic pulse timer, haptic watchdog timer via the sibling `timer__600721e8`) actually
come from. Pure infrastructure, not tied to one subsystem.

---

## The three flagged leads from `bruce-ghidra.md`

### `FUN_600ba1c4` (3,898 bytes) — connection/session protocol packet parser — confidence: high
`bruce-ghidra.md` flagged this as a possible "protocol packet parser/serializer." Confirmed: it's a
length-prefixed TLV packet dispatcher, `FUN_600ba1c4(session_obj, byte *buf, u16 len)`. Walks
`buf` in a loop, reading a 4-byte sub-message header (`type` byte, `id` byte, little-endian 16-bit
`length`), and switches on `type` (0x1–0xb) into ~11 distinct sub-message handlers. The overwhelming
majority of those handlers:
- extract a 16-bit **connection/session handle** (`local_1a`/`local_1a`-equivalent) and look it up
  via **`FUN_600bcc30(session_obj, handle)`** — a connection-object-by-handle accessor,
- validate a per-connection field against the handler's own `id` byte,
- and, on success, dispatch a numbered **event** into the connection object via
  **`FUN_600b5e00(conn_obj, event_code, optional_data)`** — event codes 0xb–0x13 for the various
  message types.

That `(conn_obj, event_code, data)` calling shape matches `state_machine.cc`, a real 11-function
attributed module (`bruce-ghidra.md`'s module-mass table, "app state machine") that has no other
entry point documented yet. So this function is best described as **the ingress packet
parser/demultiplexer for a connection-oriented control protocol (very likely the BT
adapter/connection-management layer — `adapter.cc` is a 16-function attributed module in the same
address neighborhood), which decodes framed TLV messages and feeds decoded events into a
per-connection state machine.** Type 8 does something distinct (`FUN_600bbb2c(session_obj, id, 0,
0)` with no handle lookup — maybe a keepalive/ping), and type 9 fires a one-shot completion
callback stored at `obj+0x10` (classic "connect complete" callback-and-clear pattern). A length
guard (`param_3 > 0x2a0` → 672 bytes) switches to a fallback per-byte scan (`FUN_600bb760`) for
oversized inputs, suggesting this normal path expects small control messages and treats anything
larger as a different (possibly bulk-data) framing.

Not related to HID reporting or the main loop — its fields are session/connection handles and
protocol opcodes, not button/ADC/report data.

### `FUN_600c8fd8` (2,764 bytes) — NIST P-256 modular reduction — confidence: medium-high
`bruce-ghidra.md` flagged this as a possible P-256 field-arithmetic candidate. The decompiled body
supports that reading strongly: `FUN_600c8fd8(u32 *out[8], u32 *in[16])` takes a 16-word
(512-bit) input — the shape of a double-width product — and produces an 8-word (256-bit) output,
via a long chain of weighted partial sums built from `in[8]`..`in[15]` (the product's high half)
added into the low half with full carry propagation (`CARRY4`-style `bVarN` carry bits threaded
through ~8 stages). This is exactly the shape of the classic **Solinas-style fast reduction for the
NIST P-256 prime** (`p = 2^256 - 2^224 + 2^192 + 2^96 - 1`), where the reduction of a 512-bit
product is expressed as ~9 shifted-and-signed partial sums of 32-bit input words rather than a
generic long division — a very recognizable, curve-specific pattern distinct from the Curve25519
`fe_mul`/`fe_sq` already traced in `bruce-crypto.md` (which use a different, radix-2^25.5 limb
scheme). After the partial-sum stage, it conditionally adds or subtracts a fixed 8-word constant
(`DAT_600c9238`, passed to bignum helpers `FUN_60100424`/add, `FUN_601004b2`/subtract,
`FUN_601002bc`/compare — all sized to operate on 8 words, matching a 256-bit modulus) a
carry-count number of times, then does one final comparison-gated subtract — the textbook
"reduce, then at most a couple of conditional final subtracts" tail of a Solinas reduction.
Supporting (not conclusive) evidence: the firmware's string table contains a literal **`"NIST
P-256"`** string (`0x6012865d`), alongside `brainpoolP256r1`/`brainpoolP256t1`, confirming the
BoringSSL build embeds P-256 (and other) curve support — consistent with `bruce-crypto.md`'s
already-documented "generic `EVP_PKEY_ASN1_METHOD` registry." This function sits in an unattributed
address range (`0x600c8fd8`, no `__FILE__` leak nearby) distinct from the attributed
`p_x25519/ed25519_asn1.c` region `bruce-crypto.md` covers, consistent with it being a separate,
lower-level curve implementation (BoringSSL's `ecp_nistp256.c`-equivalent) rather than part of the
already-traced Ed25519 code. I attempted to confirm `DAT_600c9238`'s actual byte contents against
the known P-256 prime and got a RAM address (`0x20027330`) instead of the expected constant — this
is most likely a literal-pool placement artifact in a large (2.7 KB) function rather than a
disproof (a similar large-function disassembly hazard is confirmed for `FUN_601054dc` below); it
means the exact constant's identity isn't nailed down without further Ghidra work, which is out of
scope for this pass. Overall: strong shape-based evidence for P-256 field reduction, one loose end
on the constant. If confirmed, this closes the "does bruce implement BT LE Secure Connections'
actual ECDH curve" question `bruce-ghidra.md` raised — a more relevant find than the already-mapped
Ed25519/X25519 stack for anything BLE-pairing-related.

### `FUN_601054dc` (2,546 bytes) — real disassembly/boundary problem, not a real function body — confidence: low (explicitly, per the task's instruction not to force an interpretation)
`bruce-ghidra.md` flagged this as decompiled-with-warnings and asked whether it's a genuine
boundary issue or actually fine. Having read the full decompilation: **it's a genuine, severe
boundary/disassembly problem, not usable as-is.** Evidence:
- An explicit "Instruction at (ram,0x6010598a) overlaps instruction at (ram,0x60105988)" warning —
  two decoded instructions physically overlap in the byte stream, which is only possible if Ghidra
  picked a wrong instruction-start offset somewhere upstream and desynced from the real Thumb
  instruction stream.
- ~100 "Removing unreachable block" warnings and two "Bad instruction - Truncating control flow
  here" / `halt_baddata()` calls.
- The decompiled body is unreadable as C: it's dominated by `unaff_r5`/`unaff_r7`/`unaff_r8`/
  `unaff_r10`/`unaff_r11`/`in_CY`/`in_OV` (Ghidra's markers for "this register's value is used but
  no defining write was found in this function") and dozens of self-assignments like
  `*(code **)param_1 = pcVar1;` that don't correspond to any sensible operation.
This overall signature (desynced disassembly + mass "unreachable block" removal + heavy
`unaff_*`/flag-register use) is the classic symptom of Ghidra walking into an **unrecognized Thumb-2
table-branch (`TBB`/`TBH`) jump table** — i.e., a real `switch` statement's jump table got
disassembled as if it were code, corrupting instruction boundaries downstream until the linear
sweep re-syncs by luck. Its only caller, `FUN_60134420`, sits right in the ITCM-thunk-veneer
cluster (`0x6013cxxx`–`0x6013dxxx`) per `bruce-ghidra.md`, so this could plausibly be a real,
non-trivial dispatcher (matching the switch-jump-table theory) rather than noise — but nothing
reliable can be said about *what* it does until the function boundary/jump table is fixed in
Ghidra (define the table at the `TBB`/`TBH` instruction, or manually correct the CFG) — out of
scope here per the no-`analyzeHeadless` constraint. Flagging as unresolved for a future session
rather than guessing at behavior from the corrupted decompilation.

## Session 19: `device_info.cc` — device identity / certificate provisioning (7/7 decompiled)

`device_info.cc` was `bruce-decompile-status.md`'s #1 cheap-win target (2,300 remaining bytes, 0/7); all 7 attributed functions are now decompiled (`analysis/decomp/device_info__*.c`). This is genuinely new territory — a self-contained **device-identity / certificate provisioning subsystem**, run once at boot (`device_info__6005a6b0` is called directly from `main__60051240`), that ties together the config key-value store (`keys.cc`), the Bluetooth MAC address, and an internal RPC-style call into `gotham.cc` to fetch/renew a signed per-unit device certificate.

| Function | Bytes | Role |
|---|---:|---|
| `device_info__6005a6b0` | 596 | **The entry point**, called once from `main`. Skips everything if already initialized (a cached flag byte). Checks stack headroom, loads a config key via `device_info__6005a05c`, loads two more identity-shaped config keys (ids `0x38`/`0x37`), fetches the local Bluetooth MAC via `ble_info__60065b84` and logs `"Bluetooth MAC Address: %s"` (the **same log line** `adapter__6006a21c` — `bruce-bta-stack.md` — independently logs from the BT-stack side), then calls `device_info__6005a1b0` to decode a hex-encoded BD_ADDR string. Reads config key `3` (37 bytes): if its value is `5` (a "needs cert" sentinel), runs the `gotham`-RPC certificate-derivation flow (`device_info__6005a4cc`, below) and persists the result back into key `3`; otherwise reads key `4` (up to 128 bytes, the cached certificate blob) and unpacks two 64-bit fields out of it into the object (offsets `+0x98`/`+0x9c` and `+0xa0`/`+0xa4` — an issued/expiry timestamp pair), falling back to `device_info__6004cbf0` (cert refresh, below) if the cached blob is missing or malformed. |
| `device_info__6005a4cc` | 444 | **Certificate derivation via `gotham.cc`.** Builds three small request objects (fixed opcode/size constants) and passes each through `gotham__60067d14` (`gotham.cc`, still undecompiled) — despite the name, this is **not** confirmed to be the Wi-Fi/cloud-streaming firmware; `gotham.cc` is one of the 168 source files `firmware-map.md` already notes bruce shares with the `gotham` build, so this may be a generic internal RPC/message-builder rather than anything network-specific. Combines the three results (`FUN_600e0298` ×2) into a blob, validates it field-by-field (4× `device_info__6005a0ac`, 1× `device_info__6005a13c`), and — if a status field reads `1` and the payload is exactly 32 bytes — formats it as a **dashed, UUID-shaped hex string** (8-4-4-4-12-style dash placement) into the object's device-ID field. |
| `device_info__6005a1b0` | 642 | **Hex-string → binary BD_ADDR decoder.** Fetches a factory-provisioned string via an "env var"-shaped accessor (`FUN_600dfbac`/`FUN_60086720`/`FUN_600e0d54` — a distinct lookup mechanism from `keys.cc`, not chased further here), validates it's exactly 12 hex digits, decodes each byte pair, and writes the resulting 6-byte MAC into the device_info object. |
| `device_info__6004cbf0` | 320 | **Certificate refresh/renewal.** Compares the cached expiry (the `+0xa0`/`+0xa4` 64-bit field `6005a6b0` populates) against a fixed cutoff constant; if expired/expiring, builds a request via the codebase-wide `Buffer` framework (`bruce-log-buffer.md` — reused here as a generic byte-builder, not for logging), fetches the current time, and calls `FUN_600df878` (an RPC/transport call, not chased) to obtain a fresh signed blob (≤128 bytes), which it then persists into config key `4` via `keys__6006615c` and uses to update the cached timestamp pair. |
| `device_info__6005a13c` | 106 | Reads one 8-byte field via `FUN_60059e94` — the same encrypted-flash-blob-store accessor CLAUDE.md's io-paths false-lead note already identifies (`obj+0x36e4`/`obj+0x3684`) — and validates it via `device_info__6005a0ac`. A single-field helper feeding the cert-derivation flow above. |
| `device_info__6005a0ac` | 126 | Generic **read-length validator**: compares an expected vs. actual byte count from a raw store-read primitive (`thunk_EXT_FUN_00006668`) and logs a mismatch; a shared helper called by three of the other functions in this file, not device-identity-specific itself. |
| `device_info__6005a05c` | 66 | Trivial cached-key loader: returns immediately if already loaded (object flag byte), else fetches config key `0x3a` (17 bytes) via `keys__60065eb8`, logging on failure. |

**Reading of the whole file**: each Stadia controller unit appears to carry a persisted, expiring, signed identity blob (config key `4`) alongside its Bluetooth MAC (decoded from a separate factory-provisioned hex string) and a UUID-shaped device ID derived from it — consistent with a **client-side device-attestation/registration flow**, plausibly feeding the original Stadia service's device-pairing/entitlement checks. **Not confirmed** whether `gotham__60067d14`'s RPC actually reaches any live transport on the BT-only `bruce` build, or whether this is linked-but-dormant code inherited wholesale from the shared `gotham` (Wi-Fi/cloud-streaming) codebase — same "present in the link, no confirmed live caller chain traced yet" caveat `bruce-crypto.md` already flags for the BoringSSL EVP/ASN.1 registry. `gotham.cc`/`gotham_task.cc`/`info.cc` (all still undecompiled, all cross-referenced from this file) would be the natural next hop to resolve the question either way.

## Session 19: `firmware_image_upload.cc` — the in-band OTA firmware-update RPC handler (1/1 decompiled)

`firmware_image_upload.cc` was `bruce-decompile-status.md`'s #4 cheap-win target (1,714 bytes, its one attributed function). Now decompiled (`analysis/decomp/firmware_image_upload__60078340.c`): a single, large, state-based **RPC command handler that streams a new firmware image into flash and triggers a reset into it** — the field/runtime OTA-update path, distinct from the factory NXP-SDP USB reflashing procedure documented in project memory.

`firmware_image_upload__60078340(request, session)` filters on a command-family byte (`*(request+8) == 6`) and then switches on a sub-opcode at `request+0x11`:

1. **Begin upload** — reads the active/inactive boot-slot indicator (`FUN_60061794`), resolves the *inactive* partition as the write target (`partition_table__6007818c`, confirming the A/B-slot scheme other docs had only inferred), allocates a 576-byte upload-session object, sanity-checks flash alignment and available space against the incoming image size, and starts the write session via `http_flash_writer__60079778` (`http_flash_writer.h`/`.cc`, still undecompiled — despite the name, nothing networking-specific is visible at this call site; more likely a generically-named chunked-write helper shared with the `gotham` HTTP-OTA code). Logs `"Failed to start firmware upload"` on any failure.
2. **Write chunk** — requires data + offset + a CRC field on the request, computes a checksum over the incoming chunk via `thunk_FUN_600921b8` (**the same address `bruce-bta-stack.md` names as the start of the confirmed BTA/BTE block** — here invoked as a plain 2/3-argument checksum primitive, a landmark noted in that doc rather than a contradiction of the block identification), rejects on mismatch (`"Invalid data crc..."`/`"Bad CRC"`), then verifies the write offset matches the session's running byte count before writing to flash (`FUN_600db730`), rate-limit-logging progress (`"WRITING <n> bytes, <total> bytes written so far"`) roughly once per second.
3. **Abort** — `FUN_60078218`.
4. **Stage/finalize** — builds a length-prefixed view of the accumulated buffer for the response.
5. **Commit** — fetches the newly-written image's footer via `binary_build_metadata.cc` (attributed, still undecompiled), checks two magic/struct-id matches, resolves the target partition's reset/vector-table address (`partition_table__60061684`), and — if that resolves — **updates the persisted boot-slot selection, fires the same lifecycle event-tag call `application_state.cc`'s reboot-reason path uses (`thunk_FUN_60059eb8(1, 0, ts)`, see `bruce-state-machine.md`), triggers a haptic pattern (`FUN_6005f120`), and spins in an infinite empty loop** — i.e. this is the actual trigger for a warm reset into the freshly-flashed image, relying on an external watchdog/reset line rather than calling a reset vector directly (consistent with the boot-time code in `bruce-itcm.md`). On a metadata/magic mismatch it logs `"Invalid image flashed"` and discards the session instead.

**Net**: confirms and connects four previously-isolated attributed-but-undecompiled files (`partition_table.h`, `http_flash_writer.h`/`.cc`, `binary_build_metadata.cc`) into one coherent runtime OTA-update subsystem, and gives independent, textual confirmation of the A/B flash-partition boot scheme other analysis (project memory's flashing-protocol notes) had inferred from the *factory* tooling side only. **Not yet identified**: what transport carries these request/session objects into this handler (BLE, UART, or USB CDC-ACM — the same open question `bruce-log-buffer.md` already has for the `StreamLogBuffer` RPC command; this handler's request-struct shape, byte-offset-addressed fields, and single-byte sub-opcode are consistent with the same "cwy"-framework RPC dispatch pattern that doc documents, though not proven to be the identical dispatch table).

## Session 20: `http_flash_writer.cc` — the low-level flash erase/write/verify engine underneath OTA (4/4 decompiled)

`http_flash_writer.cc` was `bruce-decompile-status.md`'s #1 cheap-win target this round (1,116 remaining bytes, 0/4). All 4 attributed functions are now decompiled (`analysis/decomp/http_flash_writer__*.c`), and — despite the name — confirm the session-19 guess above: **nothing networking-specific is visible anywhere in this file.** It's a generic sector-erase/page-write/hash-verify state object that `firmware_image_upload__60078340` (above) drives directly; "http" is very likely a vestigial name inherited from the shared `gotham` codebase's OTA path (where firmware images plausibly *do* arrive over HTTP) rather than anything this BT-only file itself does.

| Function | Bytes | Role |
|---|---:|---|
| `http_flash_writer__60079778` | 394 | **Erase.** Loops sector-by-sector over the target region (calling an erase vtable/function-pointer pair at `+0`/`+0xc` off the writer's backing flash-device object), rate-limit-logs progress every 100 sectors, checks a cancel flag each iteration (`"Erase cancelled at index %lu"`), and on completion invokes a caller-supplied completion callback (`param_1[0x43](param_1[0x44])`). |
| `http_flash_writer__6007952c` | 218 | **Page write.** A thin wrapper around the backing device's write vtable call (`(*piVar1->vtable[2])(...)`), logging `"Error while writing to flash"` / `"Not enough space, writing N bytes to address M"` on failure — the primitive `http_flash_writer__6007991c` and `firmware_image_upload.cc`'s "write chunk" step call per chunk. |
| `http_flash_writer__60079668` | 242 | **Streamed SHA-256 verify.** Re-reads the just-written region back from flash in 1024-byte chunks (through the same backing-device vtable, offset `+4` = read) and folds each chunk through a running SHA-256 (`FUN_600ec016`/`FUN_600ce31c`, the same BoringSSL SHA-256 primitives `thermal.cc`/elsewhere don't touch but `bruce-crypto.md`'s hash cluster documents) — the "compute a hash of what's actually on disk" half of the write-then-verify pattern. |
| `http_flash_writer__6007991c` | 262 | **Top-level "write and verify" orchestrator.** Calls `6007952c` to write (if a length is pending), hashes the on-disk result via `60079668`, and compares it against the expected hash passed in by the caller. On mismatch: logs `"On-disk hash %s different from %s"`, calls **`trigger_bug_report.cc`**'s entry point with the literal tag `"ON_DISK_OTA_HASH_MISMATCH"`, then re-writes the correct bytes from RAM as a self-heal. On match, logs `"Verified on-disk data"` and returns cleanly. |

**Net**: this is the concrete "erase → write → read-back → SHA-256 compare → self-heal-on-mismatch" engine that makes `firmware_image_upload.cc`'s OTA-commit step trustworthy against flash write glitches — a defense-in-depth detail worth noting for anyone reasoning about OTA reliability, and it closes out `bruce-decompile-status.md`'s "next natural pairing with this session's work" prediction from session 19. No caller outside `firmware_image_upload.cc` was found, and no networking/HTTP-shaped code appears anywhere in the file despite its name.

## Session 20: `gotham.cc` — the internal RPC/transport client underneath the `device_info.cc` certificate flow (5/5 decompiled)

`gotham.cc` was `bruce-decompile-status.md`'s #6 cheap-win target (882 remaining bytes, 0/5) and the exact open thread session 19's `device_info.cc` write-up (above) flagged as "the natural next hop to resolve the question either way." All 5 attributed functions are now decompiled (`analysis/decomp/gotham__*.c`). **Verdict: this is a real BIO-based (BoringSSL `bio.c`) network/transport client wrapper, not a no-op or dead stub.**

**Correction (independent verification pass, session 22): the "no confirmed caller" claim below was wrong, and contradicted this doc's own session-19 `device_info.cc` write-up.** `device_info__6005a4cc`'s decompiled header lists exactly one caller: `device_info__6005a6b0` — which the session-19 write-up above already documents as called unconditionally from `main__60051240` at boot, with `device_info__6005a6b0` calling `device_info__6005a4cc` whenever config key `3` reads back the "needs cert" sentinel `5`. That alone gives `device_info__6005a4cc` (and therefore `gotham__60067d14`) a confirmed static path from `main`, conditional only on a config-store value, not on any unresolved caller. Separately, `gotham__60067d14`'s own decompiled header lists **two more direct callers** the previous pass missed: `FUN_600781d4` and `FUN_600dfbac`. Disassembling `FUN_600dfbac` (Capstone, Thumb-2, no Ghidra needed) shows it unconditionally falls through to `bl gotham__60067d14` regardless of whether an internal config-entry search loop finds a match (both the "found" and "not-found" paths converge on the same call). `FUN_600dfbac` is itself called as the *first instruction* of `device_info__6005a1b0`, which `device_info__6005a6b0` calls unconditionally (unconditionally as in: every boot, not gated on the cert-sentinel check). So the real call graph is **`main__60051240` → `device_info__6005a6b0` → `device_info__6005a1b0` → `FUN_600dfbac` → `gotham__60067d14`, unconditional on every boot** — a second, independent, and *unconditional* static path into `gotham.cc`, on top of the conditional `device_info__6005a4cc` one. Whether `gotham__60067d14` actually does anything at that call (vs. hitting its own `*DAT_60067db0 == 0` early-out and logging error `0xae`) depends on whether `gotham__600679d4`'s lazy client-object constructor — called from the periodic `timer__60074658` — has already populated the global client handle by that point, which is unresolved. But "no caller was found" is simply incorrect; there are three confirmed static callers, one of them unconditional at boot.

| Function | Bytes | Role |
|---|---:|---|
| `gotham__600679d4` | 104 | **Lazy client-object constructor**, called from `timer__60074658` (a periodic-timer callback — not a one-shot init). If the module-global client handle is unset, creates a `BIO`-chain object (`FUN_60084cf0`, `bio.c`) and runs it through **7 chained setter calls** (`FUN_600e02XX`, offsets suggesting a builder/config-object pattern: host, port, timeout, TLS-verify mode, etc.) using fixed module-global constants as arguments — i.e. builds one persistent, statically-configured client object and caches it, re-entrant-safe (returns "already initialized" `9` if called again). |
| `gotham__60067a68` | 216 | **Method dispatcher.** Given an opcode (`param_2`: `0xb` or `1` are special-cased, matching vtable calls at offsets `0x14`/`0x18` on the client object — plausibly "connect"/"is-connected"-shaped checks — anything else falls straight through), resolves the underlying transport handle (`FUN_600e02a8`) and calls **`bio__60084c90`** (a generic BIO read/write/ctrl primitive, `bio.c`) with the caller's method/arg/arg2 — i.e. this is the generic "do a BIO operation, with two opcodes special-cased for connection-state checks" entry point. |
| `gotham__60067b50` | 210 | **Rate-limited write-with-retry-suppression wrapper.** Calls the client's vtable write op (offset `0xc`), and on failure, **logs at most once per 5 seconds** (`thunk_EXT_FUN_0000714c` = uptime-ms read, compared against a cached last-log timestamp — the exact same idiom `bruce-log-buffer.md` documents for its rate-limited diagnostic sinks) rather than every call. |
| `gotham__60067c3c` | 196 | **Rate-limited read-with-retry-suppression wrapper.** Same shape as `60067b50` but for the read op (offset `0x10`), returning the read result on success or a fixed error sentinel with the same 5-second-throttled log line on failure. |
| `gotham__60067d14` | 156 | **Connect/perform-request entry point** — called from `device_info__6005a4cc`, `FUN_600dfbac`, and `FUN_600781d4` (3 confirmed static callers, corrected from the earlier "the one caller" claim — see below). Opens a fresh `BIO` (`bio__60084bec`), stores it into the caller's session object, calls the client's "do-connect"-shaped vtable op (offset `8`), and on failure logs and tears the `BIO` back down (`FUN_600e0242`); on success marks the session ready (`FUN_600e02fc(handle, 1)`) and returns. |

**Reading of the whole file**: `gotham.cc` is a small, generic, **BIO-based network client wrapper** — lazy singleton construction, connect, rate-limited read/write — structurally identical to any embedded HTTPS/TLS RPC client built on BoringSSL's `BIO` abstraction (matching `firmware-map.md`'s description of `gotham`, the Wi-Fi cloud-streaming firmware, as the natural owner of this shape of code). It is **not** itself HTTP-specific or Stadia-specific in any way visible from this file alone — no URL/hostname strings, no HTTP verb literals were found in any of the 5 decompiled functions (the actual endpoint config lives in the module-global constants passed to `600679d4`'s 7 setter calls, not decompiled/resolved here). **Corrected (session 22): unlike the previous "present-in-the-link but not confirmed reachable" verdict, `gotham.cc` *is* confirmed statically reachable from `main` — unconditionally, via `main__60051240` → `device_info__6005a6b0` → `device_info__6005a1b0` → `FUN_600dfbac` → `gotham__60067d14`** (see the correction note above the function table). The device-attestation/certificate-renewal path proper (`device_info__6005a4cc`) is also reachable, conditionally on a config-store sentinel. What's still genuinely unresolved is only the *downstream* question: whether `gotham__600679d4`'s lazy client-object constructor (armed by periodic `timer__60074658`) has actually populated the global BIO client handle by the time any of these callers run — if not, `gotham__60067d14` early-outs on `*DAT_60067db0 == 0` without touching the network. So "does bruce actually open a TLS connection at runtime" is still open, but "is the code path reachable/called" is now answered yes, correcting the prior no.

## Session 20: `thermal.cc` — battery/charger thermal-safety monitor (4/4 decompiled)

`thermal.cc` was `bruce-decompile-status.md`'s #5 cheap-win target (912 remaining bytes, 0/4). All 4 attributed functions are now decompiled (`analysis/decomp/thermal__*.c`). This is a small, self-contained **battery/charger temperature-safety subsystem** — not part of the OTA/crypto/RPC clusters above, but genuinely new territory tying together `battery_charger_bq25601.h`, `keys.cc`, `timers.c`, and `application_state.cc` (the top-level Application lifecycle state machine documented in `bruce-state-machine.md`, session 19).

| Function | Bytes | Role |
|---|---:|---|
| `thermal__6005d1e4` | 190 | **Event-subscribe entry point**, called once from `application_state__6005b8dc` (the Application state machine's `0xc` "thermal" event case, per `bruce-state-machine.md`'s session-19 write-up). Under a spinlock-shaped exclusive-access guard, appends a `(callback, context)` pair into a fixed 10-slot listener array on the thermal object (rejecting with error `8` once full) — a lightweight pub/sub registration, not a poll. Also lazily arms a periodic 10-second timer (`thunk_EXT_FUN_00007a2c`) the very first time a listener registers. |
| `thermal__6005d634` | 74 | **Periodic timer tick**, called from `main__60051240` at boot to kick off the cycle (re-arms itself via the timer primitive on each call, `10-second`/`15-second` intervals depending on path). Delegates the actual temperature check to `thermal__6005d3b4`. |
| `thermal__6005d3b4` | 534 | **The core temperature-check routine.** Reads the fuel-gauge/thermal-sensor's current temperature via `battery_charger_bq25601__600683f4`-adjacent calls (`FUN_60068604`/`FUN_60068470`/`FUN_60068674`, all in the still-undecompiled `battery_charger_bq25601.cc`), compares against high/low threshold pairs loaded from the config key-value store (`keys__60066070`, confirming this file — like `application_state.cc` — reads calibration/threshold data out of `keys.cc`), and on an out-of-range reading: **disables the charger** (`battery_charger_bq25601__600683f4`, passing a fault code), logs a descriptive warning, and — after 3 consecutive failed retries — calls `trigger_bug_report.cc`'s entry point to flag the condition for diagnostics. Also separately checks free-heap headroom (`FUN_600cc6f0() < 0x5000`) and fires its own one-shot bug-report on low memory, unrelated to temperature itself but living in the same tick function. |
| `thermal__6005d160` | 114 | **Generic "fire once, then re-arm a 60-second cooldown" helper**, called twice per tick from `6005d3b4` (once for the ambient/board sensor, once for the battery sensor) to avoid re-logging/re-alerting on every single 10-second tick while a fault condition persists — the same rate-limiting idiom `gotham.cc` (above) and `bruce-log-buffer.md` use elsewhere in this codebase, implemented independently here rather than through the shared `Buffer` framework. |

**Net**: a straightforward, well-contained safety monitor — poll temperature every ~10s, compare to config-driven thresholds, cut charging and raise a bug report on sustained faults — wired into the Application-level state machine as event `0xc` (thermal) rather than being polled from `main` directly. Confirms `application_state.cc`'s session-19 guess that event `0xc` was thermal-shaped. No new open threads of note; the remaining undecompiled sibling `battery_charger_bq25601.cc`/`.h` (808 + 432 bytes) would fill in the actual I2C-level sensor-read/charger-disable primitives this file calls into but doesn't itself implement.

## Session 21: `battery_gauge_bq2742X.cc` — the TI BQ2742x fuel-gauge I2C driver (3/3 decompiled)

`battery_gauge_bq2742X.cc` was `bruce-decompile-status.md`'s §3a rank-3 cheap-win target (808 remaining bytes, 0/3). All 3 attributed functions are now decompiled (`analysis/decomp/battery_gauge_bq2742X__*.c`). Confirms the filename literally: this is a driver for Texas Instruments' **BQ2742x family fuel-gauge/protector ICs**, a sibling of `thermal.cc`'s charger-safety subsystem but a separate I2C peripheral (the fuel gauge, not the BQ25601 charger chip).

| Function | Bytes | Role |
|---|---:|---|
| `battery_gauge_bq2742X__60068cb4` | 444 | **The periodic poll/init routine**, called from `timer__60074658` (the same periodic-timer callback that drives `gotham__600679d4` and `usb_device__60060f28`). On first call (a one-shot init-latch byte), does a **"seal" handshake dance**: sends a security-mode probe, and depending on the chip's response (`0x421` vs `0x426`, distinguishing two different lock-state codes), calls `battery_gauge_bq2742X__60068a00` (below) to send the matching unseal key sequence, then re-verifies a firmware/config-version register (offset `+0x18`) against an expected value, re-running a config-update sub-flow (`FUN_600d87f4`/`FUN_600d87c0`) if it's stale. Logs progress at each step (`"..."`-shaped rate-15/20 log severities matching the codebase's structured-log framework). |
| `battery_gauge_bq2742X__60068a00` | 212 | **The unseal/key-write sequence.** Copies a 7-word key-table entry (indexed `0`–`4` off a lock-level field) into a local struct, then writes it to the chip via two `I2C write` calls (`FUN_600cedd8`, register `local_24`) 10ms apart (`thunk_EXT_FUN_0000737c(1)`, a 1-tick delay) — the standard **BQ2742x two-step 0x????-key unseal-register write** sequence documented in TI's datasheets for exiting SEALED/FULL-ACCESS-SEALED mode. Calls `FUN_60068970` (still undecompiled) afterward, presumably a post-unseal settle/verify step. |
| `battery_gauge_bq2742X__60068ae0` | 152 | **Generic 3-register I2C write-then-verify helper**: writes three sequential register values (`0x60`/`0x3e`/`0x3f` — matching BQ2742x's `MACWrite`/data-block-command protocol: command register + two data-block bytes) via `FUN_600d83bc` (I2C write wrapper, 200ms timeout each, 5ms spacing), then reads back the first register and compares against the value just written, logging a mismatch (`"..."`) if the readback doesn't match — a defensive write-verify pattern for chip register access, called both from this file's own init flow and from two other still-undecompiled callers (`FUN_600d87f4`/`FUN_600d855e`). |

**Net:** a self-contained I2C driver implementing the BQ2742x fuel-gauge's security-unlock and configuration-verification sequence, polled periodically alongside several other unrelated periodic tasks off the same shared timer (`timer__60074658`) that also drives `gotham.cc` and `usb_device.cc`'s state polls. Sibling to (but distinct from) `thermal.cc`'s charger-safety monitor — `thermal__6005d3b4` calls into `battery_charger_bq25601.cc` (the charger chip, still undecompiled), not this file, so the two battery-adjacent I2C subsystems remain confirmed-separate. The three still-undecompiled callees this file references but doesn't implement (`FUN_60068970`, `FUN_600d87f4`, `FUN_600d855e`, `FUN_600d87c0`, `FUN_600d8636`, `FUN_600d4330`) would be the natural next hop to reach the actual state-of-charge/voltage-reading registers this driver almost certainly also exposes elsewhere in the same object.

## Session 21: `flash_lut.cc` — a verified-write flash lookup-table store (3/3 decompiled)

`flash_lut.cc` was `bruce-decompile-status.md`'s §3a rank-4 cheap-win target (706 remaining bytes, 0/3). All 3 attributed functions are now decompiled (`analysis/decomp/flash_lut__*.c`). This is a small, generic **flash-backed lookup-table write/verify/retry engine** — structurally similar in spirit to `key_value_store.cc`'s wear-leveling flash record store (session 17), but simpler (no magic/generation-counter header scheme visible) and object-oriented (dispatches through vtable calls at offsets `+0x20`/`+0x24` on a backing flash-device object rather than calling a fixed low-level driver directly).

| Function | Bytes | Role |
|---|---:|---|
| `flash_lut__6005fa0c` | 102 | **Single-entry verified write.** Given a byte offset, computes the target LUT slot (`offset / stride`), bounds-checks it against the table's configured entry count, locks a per-object guard (`thunk_EXT_FUN_0000b4c2`/`00007d10`), and — if the object is initialized — writes via `thunk_EXT_FUN_00000b1c(offset, stride)` then commits/flushes via `thunk_EXT_FUN_00008996`. Logs and returns error `3` on a misaligned offset or out-of-range slot. |
| `flash_lut__6005fa80` | 130 | **Range write primitive**, the lower-level op `flash_lut__600d4902` (below) actually calls per differing byte. Validates both the start and end offsets are stride-aligned, locks the same per-object guard, and — via the object's vtable (offset `+0x24`, a "get target address" call) — dispatches the real write through `thunk_EXT_FUN_00000c7c(start, len, end, targetAddr, entryStride, ...)`, committing via the same `thunk_EXT_FUN_00008996` flush primitive. |
| `flash_lut__600d4902` | 474 | **The top-level "sync new data into flash, only touching changed bytes" driver.** Only runs for a specific object variant (`param_1[3]==1 && param_1[6]==-1`) and length range (`0x6000`–`0x39fff`). Walks byte-by-byte comparing the caller's new data against the current flash contents (accessed via a vtable getter, `(**(*param_1+0x20))()`); wherever a byte differs, checks (and lazily triggers) an erase-if-due background reclaim (`FUN_600cc8f8`/`FUN_600cc984`, rate-limited to once per 60 real-time seconds per region via `thunk_EXT_FUN_0000714c`, an uptime-ms read), then writes just that byte range via `flash_lut__6005fa80` above — retrying with a **`"Flash write failed, retrying"`** log if the write doesn't stick, and re-verifying after the retry, logging **`"Flash rewrite failed"`** (and bumping a persistent failure counter at `param_1[0x20]`) if it still doesn't match. |

**Net:** `flash_lut.cc` is a defensive, retry-and-rate-limited-erase flash write engine for a stride-indexed lookup table — plausibly the calibration or per-channel constant store CLAUDE.md's open-thread notes allude to (the ADC/stick-calibration data path), though **no direct evidence ties this specific file to that data** — the caller (`FUN_600d48d8`, still undecompiled) and the object's actual field-level semantics (what a "LUT entry" represents) weren't resolved this session. Worth flagging as a stronger candidate for CLAUDE.md's still-open "calibration-blob store" question than the `obj+0x36e4`/`obj+0x3684` false lead that doc already closed, given the "verified write, retry-on-failure, rate-limited erase" shape matches what a calibration-table writer would need — but this is a plausibility note, not a confirmed identification.

## Session 21: `bug_report.cc` — the flash-backed bug-report ring-buffer engine (4/4 decompiled)

`bug_report.cc` was `bruce-decompile-status.md`'s §3a rank-6 cheap-win target (660 remaining bytes, 0/4). All 4 attributed functions are now decompiled (`analysis/decomp/bug_report__*.c`). This is the low-level **read/write engine for a persistent, magic-tagged, checksummed circular log of diagnostic bug-report records** — a natural sibling to `key_value_store.cc`'s flash record store (session 17) and `http_flash_writer.cc`'s OTA write-verify engine (session 20), but purpose-built for diagnostics rather than config or firmware images.

| Function | Bytes | Role |
|---|---:|---|
| `bug_report__6005e200` | 82 | **Sector-alignment round-up helper.** Given a size and the object's configured sector-size field (dereferenced from `param_1`, logging an assert if it reads `0`), rounds the size up to the next multiple — used throughout the other three functions here to keep record boundaries sector-aligned, the same defensive pattern `flash_lut.cc`/`http_flash_writer.cc` apply at the erase-block level. |
| `bug_report__6005e3d0` | 194 | **Ring-buffer scan/seek.** Walks forward through stored records via a backing-store vtable read call (offset `+0xc`), reading each record's length prefix, until either it finds free/unwritten space (marks a "done" flag and returns) or the accumulated offset exceeds the store's total capacity (`FUN_600d4652`, logs and marks done as a corruption/overflow guard) — i.e. this is "find where to append the next record," walking the log linearly rather than tracking a cached write cursor. |
| `bug_report__6005e58c` | 214 | **Read the Nth stored record.** Seeks to a target record index using the same length-prefix-walking primitive as above (`bug_report__6005e200`-aligned reads via the same vtable), validates the record's declared length is within a sane bound (`0x200`/512 bytes) before copying it into the caller's buffer — the read-side counterpart to the append path below. |
| `bug_report__6005e7e0` | 170 | **Append a new record.** Computes the current write position (`FUN_6005e1c0`), checks (and logs, `"..."`) if the store is nearing full (`> 0x27f7`/10,231 bytes used), writes a **magic-tagged header** — bytes `0xd5`/`0xba` (i.e. magic value `0xbad5`, little-endian) followed by a fixed type tag `2` and the payload length — computes a checksum over the record via `FUN_600cc29c` (a CRC-style routine seeded with `0xffff`, the classic CRC-16/CCITT initial value), and writes the trailing checksum word. |

**Net:** a self-contained, sector-aligned, magic-tagged (`0xbad5`), CRC-16-checksummed circular log store for diagnostic bug reports — read (`6005e58c`) and append (`6005e7e0`) both built on the same linear scan/seek primitive (`6005e3d0`) and sector-rounding helper (`6005e200`). This is almost certainly the storage engine underneath the still-undecompiled `trigger_bug_report.cc` (438 bytes, 2 functions — presumably calls `bug_report__6005e7e0` to append a new report, and is itself the entry point `thermal.cc`/`http_flash_writer.cc` (sessions 20–21) both call on fault conditions) and `transfer_bug_report.cc` (48 bytes, 1 function — presumably reads records back out via `bug_report__6005e58c` for upload/retrieval over some transport). Neither sibling file was decompiled this session; they'd be small, fast follow-ons that would close out the whole bug-report subsystem.

## Session 21: `led_driver_lp5562.cc` — the TI LP5562 RGB LED driver (3/3 decompiled)

`led_driver_lp5562.cc` was `bruce-decompile-status.md`'s §3a rank-8 cheap-win target (548 remaining bytes, 0/3). All 3 attributed functions are now decompiled (`analysis/decomp/led_driver_lp5562__*.c`). Confirms the filename: a driver for TI's **LP5562, a 4-channel programmable-engine I2C LED driver** — almost certainly the physical controller's RGB status/logo light, given the register layout below (three independent PWM-current channels plus a fourth "W"/white channel).

| Function | Bytes | Role |
|---|---:|---|
| `led_driver_lp5562__6006b02c` | 202 | **Chip init**, called once from `main__60051240`. Optionally restores a cached brightness/current value first (`FUN_600cedd8`), then writes the LP5562's **`RESET`/enable register sequence**: register `0xd` (all-channel PWM reset) to `0xff`, register `0`(`ENABLE`) to `0x40` or `0xc0` depending on a config flag (matches the real LP5562's `CHIP_EN`/log-dimming-mode bits), register `8` (`CONFIG`, internal-clock/power-save mode) to `1`, and register `0x70` (`LED_MAP`, engine-vs-direct-PWM-control select) to `0` — i.e. puts all channels under direct I2C PWM control rather than the chip's internal animation-engine mode. Logs a distinct error string at each of the four steps on I2C failure. |
| `led_driver_lp5562__6006b10c` | 176 | **Set RGB via registers 4/3/2** (LP5562's `B_PWM`/`G_PWM`/`R_PWM` direct-control registers, in that call order) **plus a 4th value into register `0xe`** (`LED_CURRENT`, more likely a shared max-current/brightness scaler than a true 4th color channel on this 3-LED-channel-mapped part). Called from two still-undecompiled siblings (`FUN_600d8db2`/`FUN_600d8d5a`) — presumably the LED-pattern/animation player (`pattern_player.cc`, `gotham_patterns.cc`) driving this at runtime. |
| `led_driver_lp5562__6006b1d0` | 170 | **A second RGB-set variant, registers 7/6/5** (`OUT3`/`ILED2`/`ILED1`-shaped — the LP5562's second bank of current-control registers) **plus register `0xf`**, byte-identical in shape to `6006b10c` above but targeting the alternate register bank. Called from `led_calibration__600d4596` (`led_calibration.cc`, still undecompiled) — i.e. this is the variant used specifically during **factory/runtime LED calibration**, as opposed to the general-purpose set-color call above. |

**Net:** a straightforward TI LP5562 I2C driver — init once at boot, then two near-identical "set RGB + current/brightness" entry points, one for normal pattern playback and one specifically wired to the calibration flow. All three functions share the same defensive "log a distinct string per failing I2C step" pattern seen throughout this codebase's hardware drivers (`battery_gauge_bq2742X.cc`, above). `pattern_player.cc`/`pattern_player.h`/`gotham_patterns.cc`/`led_calibration.cc` (all still undecompiled, all cross-referenced from this file) are the natural next hop to see what actually drives the LED patterns (connect/pair/error/charging states, presumably) into these two register-write entry points.

## Session 21: `stats.cc` — a per-task CPU/stack/heap diagnostic report generator (1/1 decompiled)

`stats.cc` was `bruce-decompile-status.md`'s §3a rank-1 cheap-win target (816 bytes, its one attributed function). Now decompiled (`analysis/decomp/stats__60051b50.c`). Confidence on this one is **medium** — the function's overall shape (streamed field-by-field structured-record output) is clear, but its single caller (`FUN_600ce5cc`) and several of its callees (the `FUN_600ce4xx`/`FUN_600ce5xx` field-append family, `FUN_6010138c`'s per-record flush/send) are all in still-undecompiled territory, so the exact consumer of this report isn't confirmed.

`stats__60051b50(sink)` iterates the live FreeRTOS task list (`FUN_600ca570`/`FUN_600ca72c`, capped at 31 tasks — beyond that it instead emits a short "too many tasks" error record and returns `9`) and, for each task, streams out a structured record: task priority/state byte (mapped through a small lookup table for state names), stack high-water mark (as a byte count, `<<2`-scaled), total run-time, and — when the task's peak stack usage differs from its allocated size — a computed **stack-headroom** delta accumulated into running totals. After the per-task loop, it appends heap-usage fields (`FUN_60052200`, `heap_5_improved__600cc6a0` — free-heap byte count, the same allocator `bruce-itcm.md` documents) and a computed heap-fragmentation-shaped delta, then does a final pass copying `{stack_used, priority}` pairs into a fixed output table and zeroing a secondary scratch region. Every field group is written through `FUN_6010138c(sink, &buffer)` and only proceeds to the next group if that call reports success (`& 0xff == 0`) — i.e. this streams the report out incrementally to a caller-supplied sink rather than building the whole thing in memory first, bailing out early if the sink stops accepting data.

A `local_56a = 0x7d7b` field initialization near the top (little-endian bytes `0x7b`/`0x7d` = ASCII `{`/`}`) is suggestive of a JSON-object-shaped output framing, though this wasn't confirmed against the still-undecompiled `FUN_600ce4xx` field-append family's actual output format.

**Net:** a per-task CPU-state/stack-headroom/heap-usage diagnostic snapshot generator, streamed to a caller-supplied sink — plausibly feeding either the `bug_report.cc` subsystem (above) as an attached diagnostics blob, or a separate telemetry/logging channel; the exact consumer is not confirmed this session since its only caller (`FUN_600ce5cc`) sits in still-undecompiled territory. A natural, very cheap follow-on for whoever wants to close this thread: decompile `FUN_600ce5cc` and 2-3 of the `FUN_600ce4xx`/`FUN_600ce5xx` field-append helpers to confirm both the caller and the output framing.

## Session 23: `battery_service.cc` — the BLE GATT-side battery/charging-status characteristic (3/3 decompiled)

`battery_service.cc` was `bruce-decompile-status.md`'s §3a rank-3 cheap-win target (506 remaining bytes, 0/3). All 3 attributed functions are now decompiled (`analysis/decomp/battery_service__*.c`), confirming the plausibility note that doc's own commentary raised: this really is "a plausible BLE GATT-side counterpart to `battery_gauge_bq2742X.cc`'s I2C fuel-gauge driver" — except it turns out to drive the **BQ25601 charger chip** (the same one `thermal.cc`, session 20, already documents disabling on a thermal fault), not the BQ2742x fuel gauge.

| Function | Bytes | Role |
|---|---:|---|
| `battery_service__6007ffd0` | 226 | **The periodic tick / GATT-notify driver**, called from `FUN_6005acf4` — the same function `application_state.cc`'s session-19 write-up already flags as a "charger/battery-shaped query" feeding Application-state event `0xb`. Calls the poll function below, reads a charge-percentage-shaped field (`FUN_600deecc`) and a "significant change" flag (`FUN_600def50`), and on an actual VBUS-presence transition logs `"State(USB_CHARGING) changed from <bool> to <bool>"` before calling `FUN_6007ff34(param_1, &value)` — a GATT-characteristic-notify-shaped call (single-byte payload) pushing the new charging state out to connected clients. Calls the same notify function again with a distinct fixed code on the separate "significant change" flag. |
| `battery_service__6007fcec` | 180 | **VBUS/charger-presence poll**, rate-limited to once per 5 real-time seconds. Calls `FUN_600684bc` (still undecompiled, presumably a `battery_charger_bq25601.cc` status-read) to get a presence boolean; when a separate cached flag byte's low bit differs and a debounce check (`FUN_600cc8f8`) passes, updates the cached copy (`FUN_600cc984`) and logs the transition with the numeric status code. |
| `battery_service__6007fdb0` | 100 | **"Long charge mode" toggle.** On an actual state change, logs `"Entering"`/`"Exiting"` `"... long charge mode"` and writes the corresponding command (`0x1004`/`0x10fe`) directly to the charger chip via **`battery_charger_bq25601__600683f4`** — confirming `battery_service.cc` and `thermal.cc` share the same underlying charger driver/chip, not two independent charging paths. |

**Net:** `battery_service.cc` is the **BLE GATT-side battery/charging-status characteristic** — periodically polls VBUS presence off the BQ25601 charger chip and, on a state change, notifies connected GATT clients of the new charging state, plus exposes a "long charge mode" (presumably a battery-longevity/reduced-current mode) toggle that writes directly to the charger chip. Confirms and closes the "plausible BLE GATT-side counterpart" open note `bruce-decompile-status.md`'s §3a table previously flagged for this file — and clarifies it's the charger chip (`battery_charger_bq25601.cc`, still undecompiled), not the fuel gauge (`battery_gauge_bq2742X.cc`, session 21), that it actually drives.

## Session 23: `mpu.cc` — the Cortex-M7 MPU + I/D-cache bring-up routine (1/1 decompiled)

`mpu.cc` was `bruce-decompile-status.md`'s §3a rank-10 cheap-win target (440 remaining bytes, its one attributed function). Now decompiled (`analysis/decomp/mpu__600cb030.c`). Genuinely new territory — the first piece of low-level ARM cache/MPU-management code mapped in this project, distinct from `bruce-itcm.md`'s ITCM-copy boot sequence (which runs even earlier and doesn't touch the MPU/cache at all).

`mpu__600cb030` (440B) — the **Cortex-M7 MPU (Memory Protection Unit) + I/D-cache reconfiguration routine**, called from `xbara__600cbdc8` (the same function `bruce-io-paths.md` documents as the button/pin-registration bring-up routine — i.e. this runs once during early board bring-up, alongside GPIO/XBAR setup). Confirmed by its own log strings, `"Failed to disable MPU region %d!"` / `"Failed to enable default MPU region %d!"`. Saves/restores interrupt-enable state around the whole sequence, then: disables the I-cache and D-cache (clearing enable bits on two SCB-shaped registers), performs a full **invalidate-by-set/way loop** over the cache (the classic Cortex-M7 nested set/way-invalidate idiom, writing to a cache-maintenance register), disables any previously-configured MPU regions one at a time (`FUN_600cafcc`, logging per-region failures), fetches a **board-specific MPU region table** from `gotham_16mb_mimxrt10xx_mpu__6006f660` (an attributed sibling file) and programs each entry (`FUN_600cafec`, RBAR/RASR-shaped region-base/attribute register writes, logging per-region failures), re-enables the MPU, re-invalidates and re-enables both caches, and finally restores the saved interrupt-enable state.

**Independent PMSAv7 MPU Region Table Verification:**
Disassembly of `gotham_16mb_mimxrt10xx_mpu__6006f660` confirms it loads the region table embedded at flash `0x6010288c` and programs **7 concrete MPU regions** via `FUN_600cafec`:

| Region | Base Address | Size | Access / Exec (XN) | Cacheability / Memory Type | Memory Map Role |
|---|---|---|---|---|---|
| **0** | `0x60000000` | 16 MB | RO, Executable | Outer/Inner WB Write-Allocate (TEX=1, C=1, B=1) | QSPI Flash (Firmware image & RO data) |
| **1** | `0x00000000` | 128 KB | RO, Executable | Normal Non-cacheable (TEX=1, C=0, B=0) | Boot ROM / ITCM vector table alias |
| **2** | `0x20000000` | 512 KB | Full Access (RW), XN | Normal Non-cacheable (TEX=1, C=0, B=0) | DTCM / OCRAM Non-cacheable (DMA/buffers) |
| **3** | `0x20200000` | 512 KB | Full Access (RW), XN | Outer/Inner WB Write-Allocate (TEX=1, C=1, B=1) | OCRAM Cacheable (RAM, BSS, Heap) |
| **4** | `0xE0000000` | 1 MB | Full Access (RW), XN | Strongly-Ordered Shareable (TEX=0, C=0, B=0) | System Control Space / PPB (SCB, MPU, NVIC) |
| **5** | `0x40000000` | 32 MB | Full Access (RW), XN | Shared Device (TEX=0, C=0, B=1) | AIPS Peripherals / Hardware Registers |
| **6** | `0x00200000` | 128 KB | RO, Executable | Outer/Inner WB Write-Allocate (TEX=1, C=1, B=1) | FlexRAM / Flash remap alias |

**Net:** the firmware's one-time MPU + cache bring-up — disable caches, tear down any stale MPU config, invalidate cache, load and program the board's real 7-region MPU table (protecting and configuring 16 MB QSPI flash, 512 KB non-cacheable DMA RAM, 512 KB WB-cached RAM, peripherals, and PPB space), then re-enable everything.

## Wave 1: `trigger_bug_report.cc` & `transfer_bug_report.cc` — Diagnostic Bug Report Subsystem

`trigger_bug_report.cc` (2 functions, 438 bytes) and associated timer routines form the front door for device-level fault reporting and telemetry snapshots. They serialize structured diagnostics metadata into the circular flash store (`bug_report.cc`, Session 21) and queue the report for background transfer (`transfer_bug_report.cc`).

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `trigger_bug_report__6005d714` | 152 | `trigger_bug_report.cc` | **Bug report trigger entry point.** Throttled / rate-limited dispatch routine called across the system on faults. |
| `trigger_bug_report__6005d844` | 286 | `trigger_bug_report.cc` | **Diagnostic metadata serializer.** Appends build info, hardware revision, timestamps, and active flash partition name. |
| `FUN_6005d694` (`0x6005d6e4`) | 92 | `thermal.cc` / `trigger_bug_report.cc` | **Bug report timer / supervision init.** Registers `"charge_complete_timer"` (5s one-shot) and `"thermal_shutoff_timer"` (10s periodic) supervision timers. |

### `trigger_bug_report__6005d714` (152B) — Fault Trigger & Rate-Limiter
Called directly from multiple subsystem fault handlers:
- `thermal__6005d160` / `thermal__6005d3b4` (thermal shutoff and JEITA battery profile mismatches)
- `http_flash_writer__6007991c` (OTA flash verification and write failures)
- `timer__60074658`, `FUN_60071884`

**Execution Flow:**
1. Computes string length of `reason` (`param_1`), clamping to a maximum of 100 bytes (`uVar8 <= 100`).
2. Checks RTOS state via `thunk_EXT_FUN_00007734()` (scheduler active check, state == 2) and system state bitmask `*(uint *)(DAT_6005d7ac + 4) & 0x1ff == 0`. If abnormal, logs `"Can't generate a bug report here!"` (`FUN_601016a2(DAT_6005d7b4, 0x25, DAT_6005d7b0)`).
3. **60-Second Cooldown Throttling:** Reads current uptime in ms via `FUN_600d3618()`. Compares against next permitted timestamp at `*DAT_6005d7b8`. If `now < next_allowed`, logs `"Throttling this request for bug report: %s"` (`FUN_6010165c(0x28, DAT_6005d7b4, 0x2a, DAT_6005d7bc, reason)`) and rejects the request.
4. **Dispatch:** If cooldown expired:
   - Updates `*DAT_6005d7b8 = now + 60000` (60,000 ms = 60s cooldown).
   - Logs `"Bug report triggered: %s"` (`FUN_6010165c(0x14, DAT_6005d7b4, 0x30, DAT_6005d7c0, reason)`).
   - Formats log record via `FUN_600653f8()` and copies reason string via `FUN_60101198`.
   - Dispatches background generation task via `thunk_EXT_FUN_00001834(FUN_6005bdac(), 5, param_2, 1, 0)`.

### `trigger_bug_report__6005d844` (286B) — System Metadata Serializer
Serializes 8 system diagnostic key-value pairs into the bug report buffer using `FUN_600cc450(buffer, key, value)`:
- Key `"version"` (`DAT_6005d970`) — firmware image version string (`"337784"`, `DAT_6005d96c`).
- Key `"app"` (`DAT_6005d974`) — application build profile string (`"user"`, `DAT_6005d980`).
- Key `"build"` (`DAT_6005d984`) — build type string (`"user"`, `DAT_6005d980`).
- Key `"dev_hw"` (`DAT_6005d988`) — development hardware boolean flag (`"true"` / `"false"`) evaluated from `FUN_600d7cc4()`.
- Key `"internal"` (`DAT_6005d990`) — internal Google build boolean flag (`"true"` / `"false"`) evaluated from `FUN_600d7cdc()`.
- Key `"partition"` (`DAT_6005d994`) — **Active Flash Partition Name**: reads active partition ID from `FUN_60061794()` and performs binary search over the 21-entry Partition Table (`0x60105188`, 8-byte entries `{byte id, ..., const char *name}`: `"Invalid"`, `"AppA"`, `"AppB"`, `"Bootloader"`, `"BootloaderMetaData"`, `"PersistentData"`, `"Recovery"`, `"Test"`, `"Tombstone"`, `"UserData"`, `"Reserved0..3"`, `"AppAMailbox"`, `"AppBMailbox"`, `"RecoveryMailbox"`, `"Analytics"`, `"ImageVectorTable"`, `"BootloaderB"`, `"MainExecutable"`), appending the resolved partition name.
- Key `"power_on_ts_sec_epoch"` (`DAT_6005d9a0`) — boot epoch timestamp read via `FUN_6004cd58()`, formatted into 16-byte hex buffer `local_c8` via `FUN_6005d7c8`.
- Key `"time_ms"` (`DAT_6005d9a4`) — current uptime ms read via `FUN_600d3618()`, formatted into 16-byte hex buffer `local_b0`.
- Frees temporary stack buffers via `thunk_EXT_FUN_0000b52a` before returning.

### `FUN_6005d694` (`0x6005d6e4`, 92B) — Thermal & Charging Supervision Timers
Initializes FreeRTOS software timers for thermal monitoring and charge completion supervision:
- Timer 1: 5000 ms (5s) one-shot `"charge_complete_timer"` (`timer__600511c8(..., name="charge_complete_timer", period=5000, callback=thermal__6005d0bd, reload=0)`), registered via `FUN_60101c48`.
- Timer 2: 10000 ms (10s) periodic `"thermal_shutoff_timer"` (`timer__600511c8(..., name="thermal_shutoff_timer", period=10000, callback=thermal__6005d3b4, reload=1)`), registered via `FUN_60101c48`.

---

## Wave 1: `battery_charger_bq25601.h` & `battery_charger_bq25601.cc` — TI BQ25601 I2C Battery Charger Driver

All 6 attributed driver functions for Texas Instruments BQ25601 (I2C switchmode single-cell charger with Power Path) are now decompiled and analyzed.

| Function | Bytes | Source File | Register / Role |
|---|---:|---|---|
| `battery_charger_bq25601__60068278` | 106 | `battery_charger_bq25601.h` | **REG03 / Precharge Current Limit (IPRECHG).** Sets bits 7:4 (60mA steps, 60 to 780mA), preserves bits 3:0. Logs `"Battery charger %s set to %u, target %u (0x%02X)"` with string `"precharge"`. |
| `battery_charger_bq25601__600682f4` | 110 | `battery_charger_bq25601.h` | **REG02 / Fast Charge Current (ICHG).** Sets bits 5:0 (60mA steps, 0 to 3000mA), preserves bits 7:6. Logs with string `"fastcharge"`. |
| `battery_charger_bq25601__60068374` | 110 | `battery_charger_bq25601.h` | **REG03 / Termination Current (ITERM).** Sets bits 3:0 (60mA steps, 60 to 780mA), preserves bits 7:4. Logs with string `"terminal charge"`. |
| `battery_charger_bq25601__600683f4` | 106 | `battery_charger_bq25601.h` | **REG04 / Charge Voltage Limit (VREG / cutoff voltage).** Sets bits 7:3 (32mV steps, 3856mV to 4624mV), preserves bits 2:0. Logs with string `"cutoff voltage"`. |
| `battery_charger_bq25601__600684e0` | 58 | `battery_charger_bq25601.cc` | **REG0B / Device ID & Part Number Verification.** Verifies `PN[3:0] == (REG0B & 0x7F) >> 3 == 0x02` (BQ25601 signature). |
| `battery_charger_bq25601__6006855c` | 56 | `battery_charger_bq25601.cc` | **REG08 / Power Good (PG) & Bus Status Check.** Queries VBUS presence and status. |

### Register-Level Implementation Details:
1. **Mathematical Parameter Scaling:**
   All four `.h` inline configuration routines share a common template:
   $$\text{RegVal} = \frac{\text{target\_val} - \text{min\_val}}{\text{step\_val}}$$
   - `60068278` (REG03 IPRECHG): Bits 7:4 $\rightarrow$ `reg = (reg & 0x0F) | (val << 4)` (60mA step, 60mA offset)
   - `600682f4` (REG02 ICHG): Bits 5:0 $\rightarrow$ `reg = (reg & 0xC0) | (val & 0x3F)` (60mA step, 0mA offset, up to 3000mA)
   - `60068374` (REG03 ITERM): Bits 3:0 $\rightarrow$ `reg = (reg & 0xF0) | (val & 0x0F)` (60mA step, 60mA offset, up to 780mA)
   - `600683f4` (REG04 VREG): Bits 7:3 $\rightarrow$ `reg = (reg & 0x07) | (val << 3)` (32mV step, 3856mV offset, up to 4624mV)
   Read via `FUN_600d8322(dev, reg_addr)` $\rightarrow$ bitfield combine $\rightarrow$ formatted logging $\rightarrow$ writeback via `FUN_600d835e(dev, reg_addr)`.
2. **Device ID Check (`600684e0`):**
   Reads Part Information register `REG0B` (`+0x0B`). Extracts Part Number bits: `PN = (REG0B & 0x7F) >> 3`. Checks `PN == 2` (TI BQ25601 part identifier). If mismatch, logs `"Invalid product Number 0x%04X != 0x%04X"` and returns error 5.
3. **Power Good / Bus Status (`6006855c`):**
   Calls `FUN_6006849c` to read `REG08` (`VBUS_STAT` bits 7:6 and `PG_STAT` bit 2). On I2C communication error, formats error via `FUN_600cbb14` and logs `"Error getting bus status: %s"`. Returns `true` if bus power is present and good (`cVar2 == 0 && PG != 0`).

---

## Wave 1: `battery_gauge_bq2742X.h` (`0x60068b80`) — TI BQ27421/BQ27425/BQ27426 Fuel Gauge Configuration

`battery_gauge_bq2742X__60068b80` (290B) implements Data Flash Block **0x52** configuration (State of Charge subclass) for the TI BQ2742x family of Impedance Track fuel gauges.

### Subclass 0x52 Configuration & Dual-Variant Flash Offsets:
The function inspects the hardware gauge variant stored at `*(char *)(param_1 + 0x1b)`:
- **Variant 1 (TI BQ27421):**
  - Offset `10` (`0x0A`): **Design Capacity** (mAh) $\leftarrow$ `*(ushort *)(cfg + 4)`
  - Offset `12` (`0x0C`): **Design Energy** (mWh) $\leftarrow$ $\text{Design Capacity} \times 3.8\text{V}$ (`DAT_60068cac` = `3.8f`)
  - Offset `16` (`0x10`): **Terminate Voltage** (mV) $\leftarrow$ `*(short *)(cfg + 6)`
  - Offset `27` (`0x1B`): **Taper Rate** $\leftarrow$ $\frac{\text{Design Capacity}}{\text{Taper Current} \times 0.1}$ (`*(ushort *)(cfg + 8)` = Taper Current, `DAT_60068cb0` = `0.1f`)
- **Variant 2 (TI BQ27425 / BQ27426):**
  - Offset `6` (`0x06`): **Design Capacity** (mAh)
  - Offset `8` (`0x08`): **Design Energy** (mWh)
  - Offset `10` (`0x0A`): **Terminate Voltage** (mV)
  - Offset `21` (`0x15`): **Taper Rate** (0.1 hr units)
- **Unknown Variant:** Triggers assertion failure `"NOTREACHED"` via `FUN_601016a2(DAT_60068ca8, line, DAT_60068ca4)` and traps into an infinite loop.

### Flash Transaction & Checksum Commit:
1. Opens Data Flash Subclass 0x52 block via `FUN_600d83e0(param_1, 0x52, 0, &checksum)`.
2. Writes updated 16-bit big-endian words into the 32-byte block RAM mirror using `FUN_600d8518(dev, offset, value, &checksum)`.
3. Commits the updated parameters and writes the recomputed block checksum to flash register `0x60` via `battery_gauge_bq2742X__60088ae0(dev, checksum, 0x52)`.

---

## Wave 2: `bee.cc` — NXP i.MX RT Bus Encryption Engine (BEE) Controller

The NXP i.MX RT1061 incorporates an on-the-fly hardware Bus Encryption Engine (BEE) that decrypts/encrypts QSPI flash memory traffic on AHB bus transactions with zero latency overhead. `bee.cc` (2 functions, 436 bytes) manages BEE region bounds checking, memory alignment, hardware fuse verification, and key slot programming.

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `bee__6005ee88` | 92 | `bee.cc` | **BEE region bounds & enablement validator.** Checks address ranges against hardware bounds registers. |
| `bee__6005ef04` | 344 | `bee.cc` | **BEE region configuration & key programmer.** Verifies 16-byte alignment, checks OCOTP fused keys, configures BEE hardware control and key registers. |

### `bee__6005ee88` (92B) — Region Range Validator
- Queries lower and upper address bounds via ITCM thunk `thunk_EXT_FUN_000007b8`:
  - Region 0 (`param_3 == 0`): queries `DAT_6005eee4 = 0x01120020` (bottom) and `DAT_6005eee8 = 0x01130020` (top). Tag string `"0"` (`DAT_6005eeec`).
  - Region 1 (`param_3 == 1`): queries `DAT_6005eef0 = 0x01140020` (bottom) and `DAT_6005eef4 = 0x01150020` (top). Tag string `"1"` (`DAT_6005eef8`).
- Validates if target range `[param_1, param_2]` falls completely within region bounds:
  $$\text{param\_1} \ge \text{bottom} \quad \text{and} \quad \text{param\_2} < \text{top}$$
- If out of bounds, formats error at `bee.cc:184` (`0xb8`): `"Region%s is not enabled for address range 0x%08x to 0x%08x"` (`DAT_6005eefc`) and returns error status `9` (`kOutOfRange` / `kInvalidArgument`). On success, returns `0` (`kOk`).

### `bee__6005ef04` (344B) — Region Configuration & Fuse Validation
Configures on-the-fly encryption/decryption for a specified BEE memory region:
1. **16-Byte AES Block Alignment:** Computes `start = param_1[0]` and `end = start + param_1[1]`. Enforces 16-byte alignment:
   $$(\text{start} \mid \text{end}) \ \& \ 0\text{x}0\text{F} == 0$$
   On violation, logs `"bee.cc:101: Problem with region alignment, bottom=0x%08x, top=0x%08x"` (`DAT_6005f05c`) and returns error status `3`.
2. **Region ID & Hardware Fuse Check:**
   - Reads OCOTP fuse register at `0x401f4000 + 0x460` (`OCOTP->BEE_KEY_SEL` / `OCOTP->CFG4`).
   - For Region 0 (`param_2 == 0`): extracts bits [13:12] via `(val << 18) >> 30`.
   - For Region 1 (`param_2 == 1`): extracts bits [15:14] via `(val << 16) >> 30`.
   - If region > 1: logs `"bee.cc:49: Invalid region provided"` (`DAT_6005f064`).
   - If encryption enabled (`param_1[4] != 0`), cross-checks key descriptor (`param_1[2]`):
     - Key type `0` (user/software key): requires fuse selector == 0.
     - Key type `1` (fused hardware key): checks against boot mode key setting `FUN_600d4772()`. If fuse selector != 1/2/3, logs `"bee.cc:83: Region(%lu) key provided doesn't match BEE's fused key value(%lu)"` (`DAT_6005f074`) and `"bee.cc:107: BEE key doesn't match fused value"` (`DAT_6005f068`).
     - Key type > 1: logs `"bee.cc:78: Key is unexpected type:%lu"` (`DAT_6005f070`).
3. **Hardware Programming:**
   - Prepares region structure via `FUN_600ce95c`.
   - Programs BEE peripheral registers at base `0x403ec000` via `FUN_60052378(0x403ec000, param_2, region_cfg)`.
   - Synchronizes BEE status via `thunk_EXT_FUN_00008996()`.
   - Asserts control bits `*BEE_CTRL |= 0x11` (BEE key access / enable), programs key/lock configuration via `FUN_600ce96e`, re-synchronizes hardware state, and clears access bits via `*BEE_CTRL &= ~0x11` (`0xffffffee`).

---

## Wave 2: `types.h` — Bluetooth Low Energy (BLE) Advertising Data Structures

`types.h` (3 functions, 424 bytes) implements Bluetooth Low Energy GAP advertising packet construction, UUID list encoding, and payload size validation according to the Bluetooth Core Specification (31-byte advertising payload limit).

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `types__6005da44` | 108 | `types.h` | **Advertising payload length validator.** Enforces strict $\le 31$ byte BLE advertising data limit. |
| `types__60080e60` | 126 | `types.h` | **16-bit Service UUID list encoder.** Formats 16-bit UUIDs into GAP AD Type `0x02` (Incomplete) or `0x03` (Complete). |
| `types__600810bc` | 190 | `types.h` | **Advertising packet assembler.** Constructs full BLE advertising descriptor for `advertiser__60081234`. |

### `types__6005da44` (108B) — BLE Advertising Size Validator
Calculates the aggregate length of all populated AD structures in the advertising buffer `param_1`:
$$\text{TotalBytes} = \text{FlagsLen} + (\text{NameLen} + 1) + (\text{Num16BitUUIDs} \times 2 + 1) + (\text{MfgDataLen} + 2) + \text{ExtraDataLen}$$
- Checks offsets: `+0x04` (local name length), `+0x28` (UUID count), `+0x4b` (manufacturer data length), `+0x6b` (extra data).
- If $\text{TotalBytes} > 31$ (`0x1F`): triggers a critical assertion failure at `types.h:448` (`0x1c0`):
  `"Advertising data must be <= 31 bytes. Data provided was <N> bytes"` (`PTR_s_Advertising_data_must_be_<__31_b_6005dab4` / `PTR_s_bytes_6005dab8`) via `FUN_60101740`.

### `types__60080e60` (126B) — 16-Bit Service UUID Encoder
- Validates that encoded UUIDs fit within AD structure capacity: `param_3 * 2 + 1 <= 31`. If exceeded, asserts at `types.h:455` (`0x1c7`).
- Sets AD Type identifier at `param_1 + 0x2c`:
  - `0x02` (Incomplete List of 16-bit Service Class UUIDs) if `param_4 == 0`.
  - `0x03` (Complete List of 16-bit Service Class UUIDs) if `param_4 != 0`.
- Serializes 16-bit little-endian UUID values into payload buffer `param_1 + 0x2c + offset`.
- Stores UUID count at `*(int *)(param_1 + 0x28) = param_3` and calls `types__6005da44(param_1)` to verify total packet size.

### `types__600810bc` (190B) — Advertising Packet Assembler
Called directly from `advertiser__60081234` during BLE pairing and discovery advertisement setup:
1. Clears stack advertising descriptor (`0x8c` bytes) via `thunk_EXT_FUN_0000b5ba` (memset 0).
2. Adds Stadia service UUID (`0x6010b134`) via `types__60080e60(buffer, &kStadiaServiceUuid, 1, 0)`.
3. Reads local device name string via `FUN_60080fb8(&local_name)`. Asserts `name_len + 1 <= 31` at `types.h:326` (`0x146`).
4. Appends name bytes at offset `+9`, sets name length at `+4`, and validates size via `types__6005da44`.
5. Copies packet to destination `param_2` (`0x8c` bytes) via `thunk_EXT_FUN_0000b572` (memcpy).
6. Configures BLE advertising parameters:
   - `param_2[0x8b] = 1` (advertising enabled)
   - `param_2[0] = 1` (advertising type)
   - `param_2[1] = 6` (General Discoverable / Connectable Undirected) if in pairing mode (`*(param_1 + 0x58) == 1`), else `5` (Limited Discoverable).

---

## Wave 2: `timers.c` — FreeRTOS Software Timer Daemon Task & Timer Core

`timers.c` (5 functions, 360 bytes) contains the core FreeRTOS software timer subsystem implementation, including daemon task creation, timer control block (TCB) initialization, timer list expiry processing, period querying, and active-state queries.

| Function | Bytes | Source File | FreeRTOS API / Role |
|---|---:|---|---|
| `timers__600cacb8` | 82 | `timers.c` | **`xTimerCreateTimerTask` / daemon bring-up.** Spawns `"Tmr Svc"` daemon task at priority 31 (`0x1F`). |
| `timers__600cad24` | 104 | `timers.c` | **`xTimerCreateStatic` / `prvInitialiseNewTimer`.** Initializes `Timer_t` descriptor structure. |
| `timers__600cae18` | 22 | `timers.c` | **`xTimerGetPeriod`.** Returns timer period in ticks from `Timer_t->xTimerPeriodInTicks` (`+0x18`). |
| `timers__600cad94` | 114 | `timers.c` | **`prvSwitchTimerLists` / tick-overflow list sweep.** Drains the current timer list (dispatch callback, auto-reload or post overflow command), then swaps `pxCurrentTimerList`/`pxOverflowTimerList`. *(Corrected from `prvProcessExpiredTimer`, which handles a single timer with no loop/swap.)* |
| `timers__600cae38` | 38 | `timers.c` | **`xTimerIsTimerActive`.** Thread-safe critical section query checking if timer is in an active list (`+0x14`). |

### `timers__600cacb8` (82B) — `xTimerCreateTimerTask`
- Initializes active and overflow timer list structures via `FUN_600cac50()`.
- Verifies timer message queue (`*DAT_600cad0c != 0`).
- Retrieves daemon parameters via `FUN_600583d8`: stack depth, priority `0x1F` (31 - highest RTOS priority), name `"Tmr Svc"`.
- Spawns daemon task via `tasks__600ca1f8` (`xTaskCreateStatic`). Stores task handle at `*DAT_600cad18` (`xTimerTaskHandle`).
- If task creation fails, triggers `"timers.c:271: FreeRTOS CHECK failed"` (`DAT_600cad20` / `0x10f`).

### `timers__600cad24` (104B) — `xTimerCreateStatic`
Initializes static `Timer_t` control block (`param_6`):
- `+0x00`: `pcTimerName` (`param_1`)
- `+0x04`: `xTimerListItem` (`ListItem_t`, initialized via `FUN_601007b6`)
- `+0x18`: `xTimerPeriodInTicks` (`param_2` / `param_6[6]`)
- `+0x1c`: `uxAutoReload` (`param_3` / `param_6[7]`)
- `+0x20`: `pvTimerID` (`param_4` / `param_6[8]`)
- `+0x24`: `pxCallbackFunction` (`param_5` / `param_6[9]`)
- `+0x2c` (byte): `ucStatus = 1` (static allocation flag)
- Asserts `param_6 != NULL` (at `timers.c:330`, `0x14a`) and `period > 0` (at `timers.c:360`, `0x168`).

### `timers__600cad94` (114B) — `prvSwitchTimerLists`
Processes timer list head entries until list is exhausted (this is the tick-counter-overflow handler `prvSwitchTimerLists`, not the single-timer `prvProcessExpiredTimer`):
1. Reads head item from active timer list `*pxCurrentTimerList` (`DAT_600cae08 = 0x20027734`).
2. Extracts timer object `uVar7` (`Timer_t`) and scheduled expiry tick `uVar8`.
3. Unlinks item from active list via `thunk_EXT_FUN_0000b344(uVar7 + 4)` (`uxListRemove`).
4. Executes registered timer callback: `(**(code **)(uVar7 + 0x24))(uVar7)`.
5. If auto-reload enabled (`*(int *)(uVar7 + 0x1c) == 1`):
   - Computes next expiry `next_tick = uVar8 + period`.
   - If no tick overflow (`uVar8 < next_tick`): inserts back into active list via `thunk_EXT_FUN_0000b316(pxCurrentTimerList, uVar7 + 4)`.
   - On tick overflow: posts timer command to queue via `thunk_EXT_FUN_00007a2c(uVar7, 0, uVar8, ...)` and asserts queue status at `timers.c:878` (`0x36e`).
6. Swaps `pxCurrentTimerList` (`0x20027734`) and `pxOverflowTimerList` (`DAT_600cae10 = 0x20027738`).

### `timers__600cae38` (38B) — `xTimerIsTimerActive`
- Enters FreeRTOS critical section via `thunk_EXT_FUN_00007d64()` (`taskENTER_CRITICAL()`).
- Reads list container pointer `*(int *)(param_1 + 0x14)` (`xTimerListItem.pvContainer`).
- Exits critical section via `thunk_EXT_FUN_00007dac()` (`taskEXIT_CRITICAL()`).
- Returns `true` if `pvContainer != NULL`, `false` if unlinked.

---

## Wave 2: `partition_table.h` — Flash Partition Geometry & Descriptor Mapping

`partition_table.h` (2 functions, 324 bytes) manages the controller's A/B flash layout, partition descriptor lookups by partition ID, and physical address boundary validation.

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `partition_table__6007818c` | 64 | `partition_table.h` | **`GetPartitionById`.** Looks up partition descriptor object by 8-bit partition ID. |
| `partition_table__60061684` | 260 | `partition_table.h` | **`ValidatePartitionBounds`.** Resolves partition block geometry and validates physical flash address range. |

### `partition_table__6007818c` (64B) — Partition Descriptor Lookup
- Asserts `param_2 != 0` (`partition_id != 0`) at `partition_table.h:86` (`0x56`).
- Iterates across partition table array `param_1[0]` (length `param_1[1]`):
  - Reads entry `piVar1 = entries[i]`.
  - Compares partition ID byte: `*(byte *)(*piVar1 + 8) == param_2`.
  - On match, returns partition descriptor object pointer `piVar1[1]`.
- Returns `NULL` (`0`) if not found.

### `partition_table__60061684` (260B) — Physical Flash Boundary Validator
1. Searches partition table for descriptor matching target ID `*param_3`. On failure, logs `"partition_table.h:130: No partition matching partition id:%u"` (`DAT_60061790`) and returns 0.
2. Queries block count via virtual method `(*piVar3->vtable->GetBlockCount)(piVar3)` (`+0x14`) $\rightarrow \text{block\_count}$.
3. Reads block size from partition geometry: $\text{block\_size} = \text{piVar3->geometry->block\_size}$ (`*(int *)(piVar3[1] + 4)`).
4. Resolves start address: `start_addr = FUN_600d4752(piVar3, 0)`. Asserts `start_addr != 0` at line `0x8c`.
5. Resolves end address: `end_addr = FUN_600d4752(piVar3, block_count * block_size - 1)`. Asserts `end_addr != 0` at line `0x90`.
6. Checks if target physical address `*param_2` satisfies:
   $$\text{start\_addr} \le *\text{param\_2} \le \text{end\_addr}$$
   Returns 1 if within range, 0 otherwise.

---

## Wave 2: `private_heap.cc` — Isolated Memory Heap Pool with Block Checksums

`private_heap.cc` (3 functions, 292 bytes) implements an isolated memory heap allocator featuring 16-byte (`0x10`) block headers with cryptographic/integrity checksumming on every chunk header, preventing heap corruption and buffer overflow tampering.

```
+-------------------+-------------------+-------------------+-------------------+
| prev_size (int32) | curr_size (int32) |   state (int32)   |  checksum (uint32)|
|      +0x00        |       +0x04       |       +0x08       |       +0x0C       |
+-------------------+-------------------+-------------------+-------------------+
|                             User Payload Data ...                             |
+-------------------------------------------------------------------------------+
```

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `private_heap__60083534` | 42 | `private_heap.cc` | **`GetNextBlock`.** Advances to next block header and validates header checksum. |
| `private_heap__60083568` | 56 | `private_heap.cc` | **`ValidateBlockHeader`.** Validates chunk state (`0x10` free, `0x01` in-use) and checksum. |
| `private_heap__600835ac` | 194 | `private_heap.cc` | **`private_heap_free`.** Frees memory block, coalesces adjacent free chunks, and updates checksums. |

### Block Header Fields & Constants:
- `prev_size` (`+0x00`): size of preceding chunk (-1 if first chunk).
- `curr_size` (`+0x04`): size of user payload (-1 if sentinel end block).
- `state` (`+0x08`): `0x10` = `FREE_BLOCK`, `0x01` = `IN_USE_BLOCK`, `0xFF` = `TRANSFERRED_BLOCK`.
- `checksum` (`+0x0C`): CRC/checksum computed over the first 12 bytes via `FUN_600dfd6a()`.

### `private_heap__60083534` (42B) — `GetNextBlock`
- If `curr_size == -1`: returns `NULL` (sentinel end of heap).
- Computes expected checksum via `FUN_600dfd6a(param_1)`. If `param_1->checksum != expected`, triggers `"private_heap.cc:35: Corrupted heap: checksum is invalid"` (`DAT_60083560`).
- Returns pointer to next block header: `param_1 + 0x10 + param_1->curr_size`.

### `private_heap__60083568` (56B) — `ValidateBlockHeader`
- Checks `header->state == 0x10` or `header->state == 0x01`. If invalid, asserts `"private_heap.cc:60: Invalid header state (neither free nor in use) at %p"` (`DAT_600835a0`).
- Checks `header->checksum == FUN_600dfd6a(param_1)`. If mismatch, asserts `"private_heap.cc:63: Corrupted heap: checksum is invalid at %p"` (`DAT_600835a8`).

### `private_heap__600835ac` (194B) — `private_heap_free` & Coalescing
1. Computes header address: `header = param_1 - 0x10`. Validates via `private_heap__60083568(header)`.
2. Sets state to free: `header->state = 0x10`. Updates `header->checksum = FUN_600dfd6a(header)`.
3. **Coalesce with Previous Block:**
   If `header->prev_size != -1`:
   - Checks previous block `prev = header - header->prev_size - 0x10`.
   - If `prev->state == 0x10` and `prev->curr_size != -1`:
     - Merges current block: `prev->curr_size += 0x10 + header->curr_size`.
     - Recomputes `prev->checksum`.
     - Sets current header state to `0xFF`.
     - Updates subsequent block's `prev_size`.
4. **Coalesce with Next Block:**
   - Obtains `next = private_heap__60083534(header)`.
   - If `next != NULL`, `next->state == 0x10`, and `next->curr_size != -1`:
     - Sets `next->state = 0xFF`.
     - Merges next block: `header->curr_size += 0x10 + next->curr_size`.
     - Recomputes `header->checksum`.
     - Updates following block's `prev_size`.

---

## Wave 2: `usb_host_worker.cc` — USB Host Worker Thread & Queue Pump

`usb_host_worker.cc` (3 functions, 268 bytes) coordinates the asynchronous USB Host event pipeline, background worker task lifecycle, and ISR-to-task event posting with Cortex-M PendSV interrupt synchronization.

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `usb_host_worker__6006525c` | 36 | `usb_host_worker.cc` | **`StartUsbHostTask`.** Spawns the `"USB host task"` FreeRTOS worker thread at priority 27 (`0x1B`). |
| `usb_host_worker__600d56ae` | 64 | `usb_host_worker.cc` | **`QueueHostEvent`.** Posts event message to host worker queue from thread context. |
| `usb_host_worker__600610d0` | 168 | `usb_host_worker.cc` | **`UsbHostWorker_ISR_Dispatch`.** ISR/Thread dual-mode event poster with Cortex-M PendSV trigger (`0xE000ED04`). |

### `usb_host_worker__6006525c` (36B) — Task Bring-Up
- Checks `*(int *)(DAT_60065280 + 0x58) == 0` (`0x2001bdd0` context).
- If task not active: logs `"usb_host_worker.cc:89: starting host task"` (`DAT_60065288`).
- Spawns task via `FUN_6010177a(0x2001bdd0, "USB host task", 0x1B)` (`xTaskCreate` priority 27).

### `usb_host_worker__600d56ae` (64B) — Thread-Mode Event Queueing
- Reads event fields from `param_1 + 0xe4` and `param_1 + 0xe8`.
- Posts event to worker queue handle `*(0x2001bdd0 + 0xb0)` via `thunk_EXT_FUN_00006a74` (`xQueueSend`, timeout=0).
- If queue full / send fails: logs `"usb_host_worker.cc:26: Unable to queue host event"` (`DAT_600652cc`).

### `usb_host_worker__600610d0` (168B) — Dual-Mode ISR/Thread Event Dispatcher
- Inspects USB state at `*(int *)(0x200064c0 + 0x3e78)`:
  - If state == 2: invokes indirect callback trampoline `(*DAT_6013d1fc)(*(0x200064c0 + 16000))`.
  - If state == 3:
    - Cleans endpoint state via `FUN_60057e88(*(0x2000a2a8 + 0x9c))`.
    - Formats event message (ID 9, handler `0x600d6c13`, `DAT_60065340`).
    - **ISR vs Thread Mode Detection:** reads Cortex-M `ICSR` / CPUID at `0xE000ED00` (`DAT_60065348`).
      - If `(IPSR & 0x1FF) == 0` (Thread Mode): sends via `thunk_EXT_FUN_00006a74` (`xQueueSend`).
      - If `(IPSR & 0x1FF) != 0` (Interrupt / Handler Mode): sends via `thunk_EXT_FUN_00006bc8` (`xQueueSendFromISR`).
        - If `higherPriorityTaskWoken` (`local_18 != 0`): writes `0x10000000` (`PENDSVSET`) to `ICSR` (`0xE000ED04`, `DAT_6006534c`) followed by `DataSynchronizationBarrier` and `InstructionSynchronizationBarrier` to trigger an immediate FreeRTOS context switch upon ISR exit.
    - If send fails: logs `"usb_host_worker.cc:40: Unable to queue host event"` (`DAT_60065350`).

---

## Wave 2: `dcp_encryption_engine.cc` — NXP i.MX RT Data Co-Processor (DCP) Hardware Crypto

`dcp_encryption_engine.cc` (2 functions, 266 bytes) implements hardware-accelerated AES-128 cryptographic operations (ECB, CBC, and CTR modes) utilizing the i.MX RT on-chip Data Co-Processor (DCP) peripheral engine.

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `dcp_encryption_engine__6005f418` | 48 | `dcp_encryption_engine.cc` | **Incompatible cipher error logger.** Logs diagnostic record for unsupported crypto modes. |
| `dcp_encryption_engine__6005f450` | 218 | `dcp_encryption_engine.cc` | **`ExecuteDcpCrypto`.** Validates AES-128 key, locks engine mutex, configures channel, and executes hardware ECB/CBC/CTR. |

### `dcp_encryption_engine__6005f450` (218B) — Hardware AES Execution
Parameters:
- `param_1`: DCP engine object pointer (`+0x04` = mutex, `+0x58` = init flag, `+0x5c` = channel config)
- `param_2`: input buffer pointer
- `param_3`: output buffer pointer
- `param_4`: byte length
- `param_5`: initialization vector (IV) pointer
- `param_6`: key descriptor (`param_6 + 8` = key length, must equal 16 bytes `0x10`)
- `param_7`: cipher mode (`0` = AES-ECB, `1` = AES-CBC, `2` = AES-CTR)

**Control & Execution Flow:**
1. **Key Length & Mode Validation:** Checks `param_7 <= 2` and `*(int *)(param_6 + 8) == 0x10`. On mismatch, calls `dcp_encryption_engine__6005f418()` (logs `"dcp_encryption_engine.cc:48: Incompatible cypher type"`) and logs `"dcp_encryption_engine.cc:298: Key Validation Failed"` (`DAT_6005f530`).
2. **Mutex Acquisition:** Locks DCP hardware mutex via `thunk_EXT_FUN_0000b4c2(param_1 + 4)` (`xSemaphoreTake`).
3. **Engine Ready Check:** Checks `*(char *)(param_1 + 0x58) != 0`.
4. **Key Slot Programming:** Configures hardware key registers via `thunk_EXT_FUN_00001c30(param_6, &dcp_handle, param_1 + 0x5c)`.
5. **DCP Channel 1 Dispatch:** Sets channel `local_c8 = 1`:
   - Mode `1` (AES-CBC): executes `FUN_6005f310(&channel, &dcp_handle, in, out, len, iv)`.
   - Mode `2` (AES-CTR): executes `thunk_EXT_FUN_00001e10(&dcp_handle, in, out, len, iv)`.
   - Mode `0` (AES-ECB): executes `thunk_EXT_FUN_00001d6c(&channel, &dcp_handle, in, out, len)`.
   - Releases channel via `thunk_EXT_FUN_00001d44(&channel)`.
6. **Mutex Release:** Unlocks mutex via `thunk_EXT_FUN_00007d10(param_1 + 4)` (`xSemaphoreGive`).

---

## Wave 2: `sleep_lock.cc` — Low-Power Sleep Lock / Inhibitor

`sleep_lock__60059d54` (238 bytes) implements the sleep coordination and deadline evaluation routine that mediates between system wakelock holders and the low-level `sleep_driver__6005990c` power management driver.

### `sleep_lock__60059d54` (238B) — Sleep Coordinator
- Checks sleep requested flag at `*DAT_60059e44` (`0x2001a470`). If 0, returns immediately.
- Reads current uptime ticks via `thunk_EXT_FUN_0000714c()`. Rounds tick value to milliseconds:
  $$\text{now\_ms} = \frac{(\text{ticks} \pmod{1000}) \times 1000 + 500}{1000} + \lfloor \frac{\text{ticks}}{1000} \rfloor \times 1000$$
- **Deadline Expiry Guard:** Compares against target sleep end time `*(uint *)(0x2001a470 + 4)`. If $\text{end\_time} \le \text{now\_ms}$:
  - Logs `"sleep_lock.cc:63: Did not attempt to sleep until after the sleep end time."` (`PTR_s_Did_not_attempt_to_sleep_until_a_60059e64`) and bails.
- **Sleep Driver Invocation:** If driver pointer `*DAT_60059e48` (`0x2001a478`) is non-null:
  - Calls `sleep_driver__6005990c(*driver, duration = end_time - now_ms, &actual_slept_ms)`.
  - If return is `0x09` (`kDisabled`): logs `"sleep_lock.cc:53: Sleep disabled; skipping sleep attempt."` (`DAT_60059e50`).
  - If return is `0x00` (`kOk`): logs `"sleep_lock.cc:59: Slept for %lu ms"` (`PTR_s_Slept_for__lu_ms_60059e60`) and subtracts slept time from remaining budget.
  - On error: formats error name via `FUN_600cbb14` and logs `"sleep_lock.cc:57: Unable to sleep: <err>"` (`PTR_s_Unable_to_sleep__60059e5c`).
- Clears sleep flag `*0x2001a470 = 0` and releases sleep lock mutex `0x2001a47c` via `FUN_60059cd8(mutex, &tag=0xb)`.

---

## Wave 2: `power_rpcs.cc` — Power Management & Wakelock RPC Query Handlers

`power_rpcs__6005e020` (228 bytes) implements the protobuf RPC query handler for inspecting system wakelock status, power state, and component lock holders over the control interface.

### `power_rpcs__6005e020` (228B) — `GetWakelockStatus` RPC Handler
- Reads wakelock manager state from singleton `DAT_6005e104 = 0x2001fa38`:
  - `+0x158` (char): wakelock enabled flag (`1` = `"enabled"`, `0` = `"disabled"`).
  - `+0x150` (uint32): wakelock expiry timeout in milliseconds.
- Logs debug trace: `"power_rpcs.cc:28: Wakelock %s. Timeout is %lu ms."` (`DAT_6005e114`).
- Queries active wakelock holders: `FUN_600df072(0x2001fa38, &holders_list)`.
- Populates response protobuf object via `FUN_60101a80(*(param_1 + 0x14))`:
  - Field `"IsEnabled()"` (`DAT_6005e118`): writes `"true"` (`DAT_6005e11c`) or `"false"` (`DAT_6005e120`) via `FUN_600cdcc4` and `FUN_601019da`.
  - Field `"Component holds"` (`DAT_6005e124`): serializes list of component names currently holding active wakelocks via `FUN_60101aa4`.
  - Field `"ExpiryMillis()"` (`DAT_6005e128`): serializes timeout ms value via `FUN_60050c18` and `FUN_601019da`.
- Returns RPC execution status code (`0` = success).

---

## Wave 2: `binary_build_metadata.cc` — Firmware Build Metadata Header Parser

`binary_build_metadata__600678ec` (194 bytes) parses and validates the structured `BinBuildMetadata` firmware image header embedded in flash partitions.

### `binary_build_metadata__600678ec` (194B) — `GetBinBuildMetadata`
Parameters:
- `param_1`: partition table manager object
- `param_2`: partition ID (must be `0x13` = slot metadata, or `1..3` = Bootloader / App A / App B)

**Validation & Parsing Flow:**
1. **Partition ID Check:** Validates `param_2 == 0x13` or `1 <= param_2 <= 3`. On failure: logs `"binary_build_metadata.cc:38: Getting BinBuildMetadata failed, partition id not valid"` (`DAT_600679b0`).
2. **Partition Lookup:** Scans partition table for matching partition descriptor. If not found: logs `"binary_build_metadata.cc:43: Getting BinBuildMetadata failed, couldn't find partition"` (`DAT_600679b8`).
3. **IVT / Vector Table Header Detection:** Reads first 4 bytes of partition via virtual method `(*partition->Read)(partition, &first_word, 0, 4)`:
   - If read fails: logs `"binary_build_metadata.cc:55: Getting BinBuildMetadata failed, reading first word failed"` (`DAT_600679bc`).
   - If `first_word == 0x412000D1` (`DAT_600679c0`, Cortex-M Initial SP / IVT vector marker): sets metadata offset to `0x1400` (XIP signed application image offset).
   - Else: sets metadata offset to `0x400` (standard partition offset).
4. **Resolve MCU Physical Address:** Computes MCU memory mapped address via `(*partition->GetMcuAddress)(partition, offset)`. On failure: logs `"binary_build_metadata.cc:65: Getting BinBuildMetadata failed, couldn't get meta mcu addr"` (`DAT_600679c4`).
5. **Magic Header & Size Validation:** Validates `BinBuildMetadata` struct (`0x100` = 256 bytes):
   - Header magic: `header[0] == 0x747315A2` (`DAT_600679c8`, `'st\x15\xa2'`)
   - Trailer magic: `header[0x3F] == 0x4786CD88` (`DAT_600679cc`, word 63 / byte offset `0xFC`)
   - Header size: `header[2] == 0x100` (256 bytes)
   - On match: returns pointer to `BinBuildMetadata` struct.
   - On mismatch: logs `"binary_build_metadata.cc:71: Seems like no metadata exists, likely legacy binary"` (`DAT_600679d0`) and returns `NULL`.

---

## Wave 2: `hardware_timer.cc` — NXP i.MX RT General Purpose Timer (GPT1 / GPT2) Driver

`hardware_timer__60061a98` (188 bytes) configures and brings up the i.MX RT General Purpose Timer (GPT1 at `0x401EC000` or GPT2 at `0x401F0000`) hardware peripherals, managing CCM clock gating, prescaler calculation, interrupt configuration, and singleton registration.

### `hardware_timer__60061a98` (188B) — GPT Initialization Driver
Parameters (`param_1` = `HardwareTimer` descriptor struct):
- `param_1[0]`: GPT peripheral base address (`0x401EC000` = GPT1, `0x401F0000` = GPT2)
- `param_1[1]`: timer callback / state sub-object
- `param_1[5]`: clock source index
- `param_1[6]`: clock gate enable bit
- `param_1[7]`: prescaler divider value (0..63)
- `param_1[8]` (byte): initialized flag
- `param_1[10]`: output tick frequency in Hz

**Hardware Register Configuration:**
1. **Clock Controller Module (CCM):** Programs `CCM_CSCMR1` (Clock Source Multiplexer Register 1 at `0x400FC01C`, `DAT_60061b54`):
   - Sets `PERCLK_CLK_SEL` (bit 6): `*CCM_CSCMR1 = (*CCM_CSCMR1 & ~0x40) | ((param_1[6] & 1) << 6)` (0 = IPG clock, 1 = OSC clock).
   - Sets `PERCLK_PODF` prescaler divider (bits 5:0): `*CCM_CSCMR1 = (*CCM_CSCMR1 & ~0x3F) | (param_1[7] & 0x3F)`.
2. **Singleton Registration & Multi-Init Guards:**
   - For GPT1 (`0x401EC000`): checks `*DAT_60061b5c` (`0x2001bdac`). If already set and != `param_1`, logs `"hardware_timer.cc:41: Multiple initializations of GPT1"` (`DAT_60061b60`).
   - For GPT2 (`0x401F0000`): checks `*DAT_60061b6c` (`0x2001bdb0`). If duplicate, logs `"hardware_timer.cc:45: Multiple initializations of GPT2"` (`DAT_60061b70`).
   - If invalid base: logs `"hardware_timer.cc:48: Invalid timer"` (`DAT_60061b74`).
   - Stores singleton pointer: `*instance_ptr = param_1`.
3. **Peripheral Control & Interrupt Setup:**
   - Resets configuration structure via `FUN_600cedc2(&cfg)`.
   - Configures GPT registers via `FUN_60053220(GPT_base, &cfg)`.
   - Enables Output Compare 1 Interrupt in `GPT_IR`: `*(GPT_base + 0x0C) |= 0x20` (OF1IE bit).
   - Registers ISR vector via `FUN_6005f534(param_1 + 1)`.
   - Enables timer in `GPT_CR`: `*GPT_base |= 1` (EN bit).
   - Resolves source clock frequency via `FUN_60052aa8((char)param_1[5])` $\rightarrow f_{\text{src}}$.
   - Computes effective timer frequency:
     $$f_{\text{timer}} = \frac{f_{\text{src}}}{\text{param\_1}[7] + 1}$$
   - Stores frequency at `param_1[10]` and marks `param_1[8] = 1`.

---

## Wave 3: `timer.h` & `board.cc` — FreeRTOS Software Timer Infrastructure & Board Diagnostic Supervision

`timer.h` (6 functions, 1,228 bytes across `timer.h` and `board.cc`) provides C++ RAII / helper wrappers for FreeRTOS software timer creation, initialization assertion checks (`timer.h:76`, `timer.h:79`), timeout handling, and board-level periodic health monitoring.

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `timer__600511c8` | 108 | `timer.h` | **Generic Timer Constructor & Assertion Wrapper.** Initializes timer fields, asserts non-zero period and successful handle creation, invokes post-init callback. |
| `timer__60074658` | 538 | `timer.h`, `board.cc` | **Board Diagnostic Health Supervisor Callback.** Probes accessory detector (TS3A227E), audio codec (WM8904), battery gauge (BQ2742X), USB-C controller (TUSB320), USB device, and haptics. Spawns 1000ms periodic supervision timer and triggers bug report on fault. |
| `timer__6007fb34` | 164 | `timer.h` | **`Timer` Constructor with Structured CHECK Assertion.** Validates non-zero period and non-null timer handle with structured assertion formatting (`0x4C`, `0x4F`). |
| `timer__6005afd8` | 298 | `timer.h` | **Application State Supervisor Construction (Dual Timers).** Allocates and arms a periodic supervision timer and a 30,000 ms (30 s) **`"BLE Connect timeout"`** connection-establishment timeout (see detail below — this is a BLE connect timeout, *not* an inactivity/shutdown watchdog). |
| `timer__60082ff4` | 116 | `timer.h` | **`"BleDbWriteTmr"` 2000ms Flash Writeback Debounce Timer.** Cancels pending writes and arms 2-second debounce timer before serializing bonded BLE device database to flash. |
| `timer__600721e8` | 108 | `timer.h` | **Haptic Watchdog Timer Constructor Helper.** Initializes `Timer` object for haptic pulse watchdog (`5000ms` one-shot) with `timer.h` line 76/79 assertions. |

### `timer__600511c8` (108B) — Generic Timer Constructor & Assertion Wrapper
- **Signature:** `void timer__600511c8(Timer *this, const char *pcTimerName, TickType_t xTimerPeriodInTicks, uint32_t arg1, uint32_t arg2, UBaseType_t uxAutoReload, void *pContext)`
- **Object Layout:**
  - `this[0]` (`+0x00`): Context / user callback pointer (`param_7`)
  - `this[1]` (`+0x04`): `TimerHandle_t` (returned from `timers__600cad24`)
  - `this[2]` (`+0x08`): User parameter 1 (`param_4`)
  - `this[3]` (`+0x0C`): User parameter 2 (`param_5`)
  - `this[4..]` (`+0x10`): `StaticTimer_t` storage buffer passed to `xTimerCreateStatic`
- **Assertion & Creation Logic:**
  1. If `xTimerPeriodInTicks == 0`: builds structured assertion via `FUN_600ce2a0(stack_buf, "CHECK_failed", "timer.h", 0x4C)` (line 76) and panics via `FUN_60101740`.
  2. Calls `timers__600cad24(pcTimerName, xTimerPeriodInTicks, uxAutoReload, this, timer_callback_thunk, &this[4])` (`xTimerCreateStatic`).
  3. If returned handle is `NULL` (`0`): builds structured assertion at line `0x4F` (line 79) and panics.
  4. Dispatches post-init indirect call `(*UNRECOVERED_JUMPTABLE)(this)`.
- **Callers:** `FUN_600761d4`, `FUN_60080a78`, `FUN_6005d694`, `FUN_60080278`, `FUN_6005cd20`, `FUN_600765a4`.

### `timer__60074658` (538B) — Board Diagnostic Health Supervisor
- **Context:** Executed from board management thread / periodic timer callback (`FUN_600cbd68`).
- **Execution Flow & Component Diagnostic Sweep:**
  1. **Uptime Stamp & State Sync:** Reads high-resolution timestamp `FUN_600d7d1c()`, issues `DataMemoryBarrier`, and stores to `*(param_1 + 0xE38)`. Queries component state via `FUN_600d6e14(0x14)` and `FUN_600d72ec(0x14, &local_b1)`.
  2. **Accessory Detection:** Checks TI TS3A227E headset detector at `param_1 + 0x433C` via `accessory_detect_ts3a227e__6006816c`. Asserts status via `board__60071580(status, DAT_60074878)` with string `"Accessory detect"` (`0x60123330`).
  3. **I2C Bus Health:** Probes I2C bus 3 at `param_1 + 0x433C` via `i2c_device__6006820c(..., 3)` with status verified by `board__60071580(status, DAT_6007487C)` (`"Accessory detect micbias voltage"`, `0x60123341`).
  4. **Audio Codec Health:** Queries Wolfson/Cirrus WM8904 audio codec at `param_1 + 0x432C` via `sound_codec_wm8904__6006b630`, verified with string `"Sound codec"` (`0x60123362`).
  5. **Audio Pipeline & Subsystems:** Probes I2S audio volume at `param_1 + 0x3A68` (`FUN_60061e98`, string `"Usb audio volume"`, `0x6012336E`), exit-shipping-mode detector at `param_1 + 0x431C` (`FUN_600d9414`, string `"Exit shipping mode detector"`, `0x6012337F`), and BQ25601 battery charger at `param_1 + 0x4364` (`FUN_600686e4`, string `"Charger"`, `0x6012339B`).
  6. **Battery Gauge (BQ2742X):** Queries battery gauge status via `battery_gauge_bq2742X__60068cb4(param_1 + 0x4348, 1)`. On failure, logs diagnostic record `FUN_6010165c(0x28, DAT_60074894, 0x14B, DAT_60074890)` with `"Gauge Init failed"` (`0x601233A3`) at `board.cc:331` (`0x14B`) and handles battery mutex.
  7. **Haptics Cluster:** Probes haptic actuator drivers at `param_1 + 0x6B10` via `haptics_cluster__6006581c`, verified with string `"Haptics cluster"` (`0x601233B5`).
  8. **USB & Type-C Subsystem:** Initializes USB device core at `param_1 + 0x3DE8` (`usb_device__60060f28`), USB OTG PHY at `param_1 + 0x39C0` (`FUN_600d4ec8`), and TI TUSB320 Type-C Port Controller at `param_1 + 0x3F04` (`usb_port_controller_tusb320__6006b2e8`, `6006b3e8`).
  9. **Supervision Periodic Timer:** If timer not yet initialized (`*DAT_600748BC & 1 == 0`), allocates 1000ms periodic timer with name `"Heap trace"` (`0x601233C5`) via `timers__600cad24("Heap trace", 1000, 1, ...)` and registers handle in subsystem registry (`FUN_60101c48`).
  10. **Gotham Framework & Fault Trigger:** Queries `gotham__600679d4()`, verified against `"Gotham Bio init failed"` (`0x601233D0`). If any composite error flag is non-zero (`uVar13 != 0 || cVar5 != 0 || iVar6 != 0`), immediately captures system dump via `trigger_bug_report__6005d714(DAT_600748E8, 0)` with error reason `"INIT_ERROR"` (`0x60123325`).

### `timer__6007fb34` (164B) — `Timer` Constructor with Structured CHECK Assertion
- Initializer for standard `Timer` instance with comprehensive diagnostic message formatting.
- Populates `this[0] = context`, `this[2] = period_arg`, `this[3] = timer_id`.
- Validates period non-zero: formats `"CHECK failed"` at `timer.h:76` (`0x4C`) via `FUN_600d37ac` and panics via `FUN_60101740`.
- Creates static timer via `timers__600cad24(pcName, period, autoReload, this, PTR_LAB_600dedee_1_6007fbe0, &this[4])`.
- Validates handle: formats `"CHECK failed"` at `timer.h:79` (`0x4F`) on `NULL` handle.
- Returns `this` pointer. Called by `FUN_6007fbe4`.

### `timer__6005afd8` (298B) — Application State Supervisor Construction (Dual Timers)
- Instantiates state-machine supervision object (`param_1`) under `"GothamApp"` context (`0x6011C24E`) with two embedded FreeRTOS software timers:
  - **Timer 1 (Supervision Periodic Timer — `"Gamepad check"`):**
    - Embedded at offset `param_1 + 0x22` (control block at `+0x22`, handle at `+0x23`, callback context at `+0x24`, static buffer at `+0x26`).
    - Name: `"Gamepad check"` (`0x6011C258`), Period: `DAT_6005b134` (`0x0F731400` ticks = 259,200,000 ms / 72 hours), one-shot mode (`autoReload = 0`).
    - Creates timer via `timers__600cad24("Gamepad check", DAT_6005b134, 0, param_1 + 0x22, DAT_6005b14C, param_1 + 0x26)`.
    - Asserts at `timer.h:79` on failure.
  - **Timer 2 (Connection Watchdog Timer — `"BLE Connect timeout"`):**
    - Embedded at offset `param_1 + 0x32` (control block at `+0x32`, handle at `+0x33`, static buffer at `+0x36`).
    - Name: `"BLE Connect timeout"` (`0x6011C266`), Period: **`30,000` ms (30 seconds)**.
    - Callback: `PTR_LAB_6005ab5c_1_6005b144`.
    - Creates timer via `timers__600cad24("BLE Connect timeout", 30000, 0, param_1 + 0x32, DAT_6005b14C, param_1 + 0x36)`.
    - Asserts at `timer.h:79` on failure.
- Initializes object metadata: flags at `param_1 + 0x47 = 1`, `param_1 + 0x62 = 1`, context pointer `param_1[0x46] = param_2`.
- Direct caller: `FUN_6005bc74`.

### `timer__60082ff4` (116B) — `"BleDbWriteTmr"` 2000ms Debounce Timer
- Implements the delayed flash commit timer for bonded Bluetooth peer security records in `remote_device_db.cc`.
- Cancels any existing pending writeback timer via `FUN_60074ec8()`.
- Programs FreeRTOS one-shot timer:
  - Name: `"BleDbWriteTmr"` (`PTR_s_BleDbWriteTmr_60083074`, `0x60127506`)
  - Period: **`2000` ms (2.0 seconds)**
  - Auto-Reload: `0` (one-shot)
  - Callback: `PTR_LAB_600dfc56_1_60083070` (serializes bonded device records to flash)
  - Creates timer via `timers__600cad24("BleDbWriteTmr", 2000, 0, storage, callback, buffer)`.
- Validates handle: asserts at `timer.h:79` (`0x4F`) via `FUN_600d37ac` / `FUN_60101740` on failure.
- Prevents excessive flash wear during rapid BLE connection parameter or key exchange updates by deferring write until 2 seconds of inactivity.

### `timer__600721e8` (108B) — Haptic Watchdog Timer Constructor Helper
- Companion helper called from `FUN_60072260` to configure the 5-second haptic safety watchdog timer.
- Populates `this[0] = context`, `this[2] = period`, `this[3] = id`.
- Checks `period != 0` (asserts `timer.h:76`).
- Creates static timer with callback `PTR_LAB_600d9aa0_1_6007225c` via `timers__600cad24`.
- Validates handle non-null (asserts `timer.h:79`).

---

## Wave 3: `queue.c` — FreeRTOS Queue, Recursive Mutex & ISR Synchronisation Primitives

`queue.c` (6 functions, 450 bytes) constitutes the core FreeRTOS Queue and Mutex management implementation in the firmware, handling static queue creation, recursive mutex acquisition/release, thread-to-ISR and ISR-to-thread message passing with Cortex-M priority masking (`BASEPRI`).

| Function | Bytes | FreeRTOS API Equivalent | Role |
|---|---:|---|---|
| `queue__600c9de4` | 128 | `xQueueGenericCreateStatic` | **Static Queue Initializer.** Validates capacity, item size, and static buffer pointers; sets up `QueueDefinition` header and calls `xQueueReset`. |
| `queue__600c9e6c` | 54 | `xQueueGiveMutexRecursive` | **Recursive Mutex Release.** Verifies current task is mutex holder, decrements recursive count, and releases queue when count reaches zero. |
| `queue__600c9eac` | 60 | `xQueueTakeMutexRecursive` | **Recursive Mutex Acquisition.** Increments call count if already held by current task; otherwise calls `xQueueGenericReceive` to block-wait. |
| `queue__600c9ef0` | 154 | `xQueueReceiveFromISR` | **ISR Queue Receive with Priority Masking.** Sets Cortex-M `BASEPRI` to `0x50`, extracts queue item, unblocks pending sender tasks (`xTasksWaitingToSend`), and evaluates `pxHigherPriorityTaskWoken`. |
| `queue__600c9f94` | 22 | `uxQueueMessagesWaitingFromISR` | **Lockless ISR Message Count Query.** Atomic 32-bit read of `pxQueue->uxMessagesWaiting` for interrupt handlers. |
| `queue__600477e4` | 32 | `uxQueueMessagesWaiting` | **Thread-Safe Message Count Query.** Reads `pxQueue->uxMessagesWaiting` enclosed in `taskENTER_CRITICAL()` / `taskEXIT_CRITICAL()`. |

### `queue__600c9de4` (128B) — `xQueueGenericCreateStatic`
- **Parameters:** `(uxQueueLength, uxItemSize, pucQueueStorage, pxStaticQueue, ucQueueType)`
- **Assertions (`configASSERT` via `FUN_601016a2`):**
  - Line `0x132` (306): `configASSERT(uxQueueLength > 0)`
  - Line `0x136` (310): `configASSERT(pxStaticQueue != NULL)`
  - Lines `0x13A`/`0x13B` (314/315): `configASSERT((pucQueueStorage != NULL && uxItemSize != 0) || (pucQueueStorage == NULL && uxItemSize == 0))`
- **Structure Initialization (`QueueDefinition` / `StaticQueue_t`):**
  - If `uxItemSize == 0`: sets `pucQueueStorage = (int8_t *)pxStaticQueue` (dummy pointer for semaphores/mutexes).
  - `pxStaticQueue->pcHead = pucQueueStorage` (`*param_4 = param_3`)
  - `pxStaticQueue->uxLength = uxQueueLength` (`param_4[0xF] = param_1`)
  - `pxStaticQueue->uxItemSize = uxItemSize` (`param_4[0x10] = param_2`)
  - `pxStaticQueue->ucStaticallyAllocated = 1` (`*(param_4 + 0x46) = 1`)
  - `pxStaticQueue->ucQueueType = ucQueueType` (`*(param_4 + 0x13) = param_5`)
  - Resets queue state via `thunk_EXT_FUN_000069a0(pxStaticQueue)` (`prvInitialiseNewQueue` / `xQueueReset`).
- **Callers:** `FUN_600587fc`, `FUN_6005bc74`, `gatt_manager_task__60080b24`, `FUN_601007bc`, `receiver__6007f540`, `FUN_600cac50`, `FUN_60062e28`, `FUN_601017fc`, `FUN_600650dc`, `FUN_600765a4`.

### `queue__600c9e6c` (54B) — `xQueueGiveMutexRecursive`
- **Validation:** `configASSERT(pxMutex != NULL)` at line `0x243` (579).
- **Execution:**
  1. Reads mutex holder handle from `*(int *)(param_1 + 4)` (`pxMutex->pxMutexHolder`).
  2. Queries current task handle via `FUN_600ca9dc()` (`xTaskGetCurrentTaskHandle()`).
  3. If current task holds the mutex:
     - Decrements recursive depth: `pxMutex->u.uxRecursiveCallCount--` (`*(int *)(param_1 + 0xC) -= 1`).
     - If count reaches 0: calls `thunk_EXT_FUN_00006a74(param_1, 0, 0)` (`xQueueGenericSend(pxMutex, NULL, 0, queueSEND_TO_BACK)`).
     - Returns `pdPASS` (`1`).
  4. Else returns `pdFAIL` (`0`).
- **Caller:** `FUN_600d16ae`.

### `queue__600c9eac` (60B) — `xQueueTakeMutexRecursive`
- **Validation:** `configASSERT(pxMutex != NULL)` at line `0x27A` (634).
- **Execution:**
  1. Compares `pxMutex->pxMutexHolder` against `xTaskGetCurrentTaskHandle()`.
  2. If already held by calling task: increments `pxMutex->u.uxRecursiveCallCount++` and returns `pdPASS` (`1`).
  3. If not held: calls `thunk_EXT_FUN_00006e5c(param_1, xTicksToWait)` (`xQueueGenericReceive`).
     - If acquired (`iVar1 != 0`): sets `pxMutex->u.uxRecursiveCallCount = 1` and returns `pdPASS`.
     - Else returns `pdFAIL` (`0`).
- **Caller:** `FUN_600d1692`.

### `queue__600c9ef0` (154B) — `xQueueReceiveFromISR`
- **Validation:**
  - Line `0x6DC` (1756): `configASSERT(pxQueue != NULL)`
  - Line `0x6DD` (1757): `configASSERT(!(pvBuffer == NULL && pxQueue->uxItemSize != 0))`
- **Interrupt Masking & Critical Section:**
  1. Reads current privilege mode; saves active `BASEPRI` priority level.
  2. Masks interrupts up to max syscall priority by setting `BASEPRI = 0x50` (`configMAX_SYSCALL_INTERRUPT_PRIORITY` = priority level 5).
  3. Executes memory/instruction barriers: `ISB(0xF)`, `DSB(0xF)`.
- **Queue Reception & Event Unblocking:**
  1. Checks `uxMessagesWaiting = pxQueue->uxMessagesWaiting` (`*(int *)(param_1 + 0x38)`).
  2. If empty (`0`): restores `BASEPRI` and returns `pdFALSE` (`0`).
  3. If message present:
     - Copies payload out via `thunk_EXT_FUN_0000b3e2(pxQueue, pvBuffer)` (`prvCopyDataFromQueue`).
     - Decrements message count: `pxQueue->uxMessagesWaiting--`.
     - Checks receive lock `cRxLock` (`*(char *)(param_1 + 0x44)`):
       - If `cRxLock == queueUNLOCKED` (`-1`):
         - Checks if tasks are waiting on space (`pxQueue->xTasksWaitingToSend.uxNumberOfItems != 0` at `param_1 + 0x10`).
         - If non-empty, unblocks highest-priority waiting task via `thunk_EXT_FUN_00007564(param_1 + 0x10)` (`xTaskRemoveFromEventList`).
         - If unblocked task priority > current task: sets `*pxHigherPriorityTaskWoken = pdTRUE` (`1`).
       - If queue locked (`cRxLock != -1`): increments lock counter `pxQueue->cRxLock++`.
     - Restores original `BASEPRI` priority and returns `pdTRUE` (`1`).
- **Caller:** `FUN_600cc000`.

### `queue__600c9f94` (22B) & `queue__600477e4` (32B) — `uxQueueMessagesWaiting` Variants
- **`queue__600c9f94` (ISR context):** Asserts `pxQueue != NULL` at line `0x78D` (1933). Returns `pxQueue->uxMessagesWaiting` (`*(param_1 + 0x38)`) directly without locking, safe under Cortex-M single-word atomic load.
- **`queue__600477e4` (Task context):** Asserts `pxQueue != NULL` at line `0x76B` (1899). Wraps the read in `taskENTER_CRITICAL()` (`FUN_60048580`) and `taskEXIT_CRITICAL()` (`FUN_600485c8`).

---

## Wave 3: `heap_5_improved.c` — FreeRTOS Multi-Region Heap Allocator (`Heap_5`)

`heap_5_improved.c` (2 functions, 304 bytes) implements the multi-region dynamic memory allocator (`Heap_5`) customized with heap bounds validation, memory fragmentation telemetry, and hardware memory configuration detection.

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `heap_5_improved__600cc6a0` | 50 | `heap_5_improved.c` | **`xPortGetLargestFreeBlockSize` / Heap Stats Inspector.** Suspends scheduler, traverses free block list to compute largest contiguous free block, resumes scheduler. |
| `heap_5_improved__600521b8` | ~52 (+ tail-branch body) | `heap_5_improved.c` | **`vPortDefineHeapRegions` — hardware-profile HeapRegion selector.** Reads an SoC config register to pick a `HeapRegion_t` table, then `b.w 0x600cc71c` tail-branches to the multi-region init (validates ascending layout, initializes 8-byte-aligned free blocks + end sentinels). *(Ghidra's 254B size for this addr is a boundary artifact — see detail note.)* |

### `heap_5_improved__600cc6a0` (50B) — `xPortGetLargestFreeBlockSize`
- **Validation:** Asserts `pxEnd != NULL` (heap initialized) at line `0xDD` (221) of `heap_5_improved.c` (`DAT_600cc6dc`).
- **Execution Flow:**
  1. Suspends FreeRTOS task scheduler via `thunk_EXT_FUN_0000713c` (`vTaskSuspendAll()`).
  2. Obtains head of free block list `xStart` (`DAT_600cc6e0`).
  3. Iterates linked list of `BlockLink_t` nodes:
     ```c
     while (pxBlock = pxBlock->pxNextFreeBlock, pxBlock != NULL) {
         if (max_size < pxBlock->xBlockSize) {
             max_size = pxBlock->xBlockSize;
         }
     }
     ```
  4. Resumes scheduler via `thunk_EXT_FUN_0000728c` (`xTaskResumeAll()`).
  5. Returns `max_size` (size in bytes of largest contiguous allocatable block).
- **Caller:** `stats__60051b50` (`stats.cc`) — used in diagnostic memory statistics dumps to evaluate heap fragmentation headroom.

### `heap_5_improved__600521b8` — `vPortDefineHeapRegions` (profile selector, ~52B + tail-branch)
> **Size/framing corrected (sessions 24–28 adversarial audit).** Ghidra reports this function as 254 bytes, but that extent is a boundary artifact: it *overlaps four other census functions* (`0x60052200`, `0x60052230`, `0x60052254` = `heap_support.c`, `0x60052294`). The real function at `0x600521b8` is only ~52 bytes — it performs the hardware-profile read below, then ends in a `b.w 0x600cc71c` tail-branch. The multi-region init body described afterward physically lives at that branch target (`0x600cc71c`), which Ghidra inlined into this decompilation; the `configASSERT`s and the `*DAT_600cc804 = 0x80000000` xBlockAllocatedBit store are at `0x600cc71c`–`0x600cc770`, **not** within `[0x600521b8, +0x100)`. (Same failure class as the known `FUN_601054dc` boundary corruption.)
- **Hardware Profile Detection:**
  - Reads an SoC configuration register at `*(int *)(DAT_600521ec + 0x260)` (`DAT_600521ec = 0x400D8000` = the i.MX RT106x **CCM_ANALOG / ANATOP** analog-clock/PMU block base — **not** OCOTP; the real OCOTP base is `0x401F4000`, as used correctly in the `bee.cc` section above and confirmed by on-device probing in `device-probe-log.md`. `+0x260` reads `0x400D8260` within the ANATOP block):
    - If flash/RAM configuration matches `0x6C0000` (7MB partition boundary) or `DAT_600521f0` (`0x006C0001`), and `FUN_600d4698() == 0`: selects alternate `HeapRegion_t` region table `DAT_600521F8` (`0x20003024`) / `DAT_600521F4` (`0x2000303C`).
    - Otherwise selects standard multi-region table `DAT_600521FC` (`0x20003054`).
- **Validation & Region Initialization (`configASSERT` via `FUN_601016a2`):**
  - Line `0x2AA` (682): `configASSERT(pxEnd == NULL)` (verifies heap regions are defined only once at boot).
  - Loops over `HeapRegion_t pxHeapRegions[]` until `xSizeInBytes == 0`:
    1. **8-Byte Alignment:** Aligns `pucStartAddress` upward: `pucStartAddress = (pucStartAddress + 7) & ~7`.
    2. Adjusts region size for alignment loss.
    3. Line `0x2CB` (715) & `0x2CE` (718): Asserts regions are sorted in strictly ascending physical memory order (`pucStartAddress > pxPreviousEndAddress`).
    4. **Block Setup:**
       - Installs sentinel node at region end: `pxEnd = (pucStartAddress + xSizeInBytes - 8) & ~7`.
       - Links previous region's sentinel to current region's start block.
       - Initializes free block header with size and marks next pointer.
       - Accumulates total free heap capacity: `xTotalHeapSize += xBlockSize`.
- **Global Heap Metrics Initialization:**
  - `*DAT_600cc7f4 = xTotalHeapSize` (`xFreeBytesRemaining`)
  - `*DAT_600cc7f8 = xTotalHeapSize` (`xMinimumEverFreeBytesRemaining`)
  - `*DAT_600cc7fc = xTotalHeapSize` (`xLargestFreeBlockAllocatedEver`)
  - `*DAT_600cc800 = pxHeapRegions` (stores active regions descriptor pointer)
  - `*DAT_600cc804 = 0x80000000` (`xBlockAllocatedBit`, MSB flag used to mark allocated blocks)
  - Line `0x2F9` (761): Asserts `xTotalHeapSize > 0`.
- **Caller:** `FUN_600cdb74` (early system initialization / FreeRTOS kernel startup).

---

## Wave 3: `xbara.h` — NXP i.MX RT Crossbar Switch (XBARA1) Signal Routing Driver

`xbara__60060170` (74 bytes) provides the low-level signal routing primitive for the on-chip Crossbar Switch (XBARA1 at `0x403BC000`) peripheral on the NXP i.MX RT1050/1060 MCU.

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `xbara__60060170` | 74 | `xbara.h` | **`XBARA_SetSignalsConnection`.** Connects internal hardware trigger sources (GPT timers, PWMs, GPIOs) to destination peripherals (ADC ETC, DMA, DAC). |
### `xbara__60060170` (74B) — `XBARA_SetSignalsConnection`
- **Signature:** `void xbara__60060170(XBARA_Type *base, uint8_t input_signal, uint16_t output_index, uint32_t arg4)`
- **Peripheral Base:** `DAT_600601a0 = 0x403BC000` (XBARA1 Peripheral Base Address on i.MX RT1060).
- **Register Architecture:**
  - The i.MX RT XBARA peripheral features 30 16-bit Signal Select registers (`XBARA_SEL0` through `XBARA_SEL29`, memory offsets `0x00` through `0x3A`):
    - Each 16-bit register configures **two** output channels:
      - Low byte (bits 7:0): `SEL(2*n)` selects input signal for Output `2*n`.
      - High byte (bits 15:8): `SEL(2*n + 1)` selects input signal for Output `2*n + 1`.
- **Register Programming Logic:**
  1. Validates base pointer: if `*param_1 != 0`, calls `FUN_601016a2` with `"Invalid XBAR base: %d"` (`0x6011DC82`) asserting line `0x17` (23) of `xbara.h`.
  2. Computes register byte offset: `reg_offset = output_index & 0xFE`.
  3. Computes bit shift within 16-bit register: `bit_shift = (output_index & 1) << 3` (0 for even output index, 8 for odd output index).
  4. Performs read-modify-write on target `XBARA_SELx` register:
     ```c
     uint16_t *p_sel = (uint16_t *)(0x403BC000 + (output_index & 0xFE));
     *p_sel = (*p_sel & ~(0xFF << bit_shift)) | ((uint16_t)input_signal << bit_shift);
     ```
- **System Role:** Called by `FUN_600d49fc` during boot-time hardware interconnect configuration to wire timer compare output pulses (e.g. GPT1 / PIT) to ADC External Trigger Control (ADC_ETC) inputs for synchronized analog stick sampling without CPU intervention.

---

## Wave 4: System Infrastructure, Hardware Drivers & FreeRTOS Primitives

14 additional system infrastructure, hardware driver, power management, and synchronization functions across 12 source files are now decompiled and mapped.

| Function | Bytes | Source File | Role |
|---|---:|---|---|
| `snvs__60059f00` | 138 | `snvs.h` | **NXP i.MX RT SNVS Low-Power General Purpose Registers (`SNVS_LPGPR`).** Accesses persistent hardware scratchpad registers across system resets. |
| `reset__6006044c` | 126 | `reset.cc` | **System Reset / Reboot Trigger.** Flushes peripherals, logs reset reason, arms watchdog or triggers Cortex-M `NVIC_SystemReset()`. |
| `reset__600604dc` | 22 | `reset.cc` | **Fatal Error Panic Reset Wrapper.** Immediate forced reboot trigger on unrecoverable system bring-up faults. |
| `accessory_detect_ts3a227e__6006816c` | 140 | `accessory_detect_ts3a227e.cc` | **TI TS3A227E Autonomous Audio Jack Detector Driver.** I2C device probe (Device ID `0x11`), configuration, and autonomous accessory detection. |
| `gotham_16mb_mimxrt10xx_mpu__6006f660` | 132 | `gotham_16mb_mimxrt10xx_mpu.cc` | **Gotham 16MB Flash MPU Region Configuration Provider.** Populates 8 MPU memory protection regions (RBAR/RASR pairs) for i.MX RT10xx. |
| `wakelock__60080180` | 132 | `wakelock.cc` | **System Wakelock Acquire Coordinator.** Atomic refcounting (`LDREX`/`STREX`) with hardware power manager sleep-inhibit dispatch. |
| `event_groups__600c9d44` | 60 | `event_groups.c` | **`xEventGroupCreateStatic`.** FreeRTOS static event group initializer (`uxEventBits = 0`, `vListInitialise`, `ucStaticallyAllocated = pdTRUE`). |
| `event_groups__600c9d88` | 68 | `event_groups.c` | **`vEventGroupDelete`.** FreeRTOS event group deletion, unblocking pending tasks (`0x02000000`), and dynamic memory reclamation. |
| `flash_memory__60067e8c` | 130 | `flash_memory.h` | **Flash Address & Capacity Range Validator.** Queries sector geometry and validates operational bounds before erase/write. |
| `parser__600834a4` | 136 | `parser.cc` | **JSON Document / String Parser.** Decodes structured JSON configuration payloads, formats numeric error telemetry, and translates return codes. |
| `get_device_data__60078b4c` | 134 | `get_device_data.cc` | **Device Data / Key Store Telemetry Extractor.** Probes device state and verifies parameter existence in typed config storage. |
| `util__60092128` | 132 | `util.cc` | **Key-Value Dictionary / Argument Sequence Walker.** Matches key identifiers against lookup tables, formats diagnostic traces, and extracts item indices. |
| `external_controller__6007053c` | 180 | `external_controller.cc` | **External Haptic / Motor Controller Driver.** Packs 16-bit L/R rumble magnitudes into 32-bit packets, manages retries, and invokes recovery. |
| `led_calibration__600d4596` | 178 | `led_calibration.cc` | **TI LP5562 RAW (Red/Amber/White) LED Calibration & Color Trim Loader.** Reads Red, Amber, and White trim constants, applies float gain scaling, and programs LED driver currents. |

### `snvs__60059f00` (138B) — `snvs.h`: NXP i.MX RT SNVS LPGPR Register Access
- **Peripheral Architecture:**
  - Base Address: `0x400D4000` (`SNVS` Peripheral Base on NXP i.MX RT1050/1060).
  - Register Target: `SNVS_LPGPR[0..3]` (SNVS Low Power General Purpose Registers 0 through 3).
  - Hardware Offset: `0x400D4000 + (reg_index + 0x40) * 4` $\rightarrow$ `0x400D4100` (`SNVS_LPGPR0`), `0x400D4104` (`SNVS_LPGPR1`), `0x400D4108` (`SNVS_LPGPR2`), `0x400D410C` (`SNVS_LPGPR3`).
  - Characteristics: Powered by SNVS coin-cell / battery domain, retains 32-bit scratchpad values across software resets, warm boots, and core power-gating.
- **Validation & Flow:**
  1. Asserts `param_3 != NULL` (`out_val`) at line `0x2B` (43) of `snvs.h` (`DAT_60059f8c` points to `"snvs.h"`, `DAT_60059f90` points to `"CHECK failed"`).
  2. Asserts `reg_index <= 3` at line `0x2C` (44) of `snvs.h`.
  3. Checks handle initialized: `if (*param_1 == '\0') return 9;` (error `kNotReady` / `kUninitialized`).
  4. Reads 32-bit register value into caller buffer: `*param_3 = *(uint32_t *)(0x400D4000 + (reg_index + 0x40) * 4);`.
  5. Returns `0` (`kOk`).
- **Callers:** `reboot_reason__60059f98` (reads persistent boot flags and watchdog reset reasons across reboots), `FUN_600d512e`.

### `reset__6006044c` (126B) & `reset__600604dc` (22B) — `reset.cc`: System Reboot & Panic Handlers
- **`reset__6006044c` (Main Reset Trigger):**
  - **Parameters:** `(undefined4 target, int mode)`.
  - **Reason Persistence:** If `mode == 1`, writes reset reason `4` (`kSoftwareReset`) to retention state `*(int *)(0x400F8000 + 0x30) = 4` (`SRC_GPR5` at `0x400F8030` in NXP System Reset Controller `SRC`).
  - **Peripheral Teardown:** If `mode == 0` or `mode == 1`, calls `FUN_60060368()` to flush hardware queues and quiesce active DMA channels. If `mode == 2`, teardown is bypassed for emergency reboot.
  - **Logging:** Logs reset notice `"Going down for soft reset to NXPs BootROM"` (`0x6011dca1`) at line `0x45` (69) of `reset.cc` (`DAT_600604d0`).
  - **Hardware Reset Dispatch:**
    - Evaluates watchdog controller state via `FUN_600d4772()`.
    - If watchdog active: calls `FUN_6005f18c(0, 1, 0)` (forces watchdog timeout / external reset pulse), logs failure at line `0x49` (73) (`"NOTREACHED"` via `DAT_600604d8`), and enters infinite spinloop `while(true)`.
    - If direct core reset: calls `FUN_6005f164()` (`NVIC_SystemReset()` $\rightarrow$ writes `0x05FA0004` to Cortex-M `AIRCR` register at `0xE000ED0C`), logs failure at line `0x4C` (76) (`"NOTREACHED"`), and enters infinite spinloop `while(true)`.
- **`reset__600604dc` (Fatal Panic Reset Wrapper):**
  - Invokes `reset__6006044c(DAT_600604f4, mode=2)` (immediate forced reset bypass).
  - Logs panic trace at line `0x71` (113) of `reset.cc` (`DAT_600604fc` = `"NOTREACHED"`) and enters infinite spinloop.
  - **Caller:** `xbara__600cbdc8` (invoked when hardware crossbar / clock tree initialization fails fatally during early boot).

### `accessory_detect_ts3a227e__6006816c` (140B) — `accessory_detect_ts3a227e.cc`: TI TS3A227E Audio Switch Driver
- **Hardware Profile:** Texas Instruments TS3A227E Autonomous Audio Accessory Detection and Configuration Switch (manages 3.5mm headset ground/mic pin auto-routing, OMTP vs. CTIA standard detection, and hook/send key presses).
- **Execution Flow:**
  1. Checks initialized byte at `*(char *)(param_1 + 10)`. If already configured, returns `0` (`kOk`).
  2. Probes TS3A227E over I2C: reads 8-bit Device ID register `0x00` via `FUN_600d81f8(param_1, reg=0, &dev_id, timeout=200ms)`.
  3. **Device ID Validation:**
     - Validates `dev_id == 0x11` (fixed TS3A227E Silicon ID).
     - If mismatch (`dev_id != 0x11`): logs warning at line `0x3E` (62) of `accessory_detect_ts3a227e.cc` (`DAT_600681f8`) and returns error status `5` (`kDeviceMismatch`).
  4. **Accessory Configuration:**
     - Marks initialized: `*(char *)(param_1 + 10) = 1`.
     - Invokes configuration routine `FUN_600d8226(param_1)` (enables auto-detection, interrupt mask, and mic bias switching).
     - On configuration success: logs status line `0x46` (70) (`"TS3A227E available"`) and returns `0`.
     - On I2C error: logs line `0x3A` (58) or `0x43` (67) with error code.
- **Caller:** `timer__60074658` (audio accessory periodic detection supervisor).

### `gotham_16mb_mimxrt10xx_mpu__6006f660` (132B) — `gotham_16mb_mimxrt10xx_mpu.cc`: Gotham 16MB MPU Config Provider
- **Role:** Supplies the ARM Cortex-M7 Memory Protection Unit (MPU) table definitions tailored for the Gotham 16MB Flash memory architecture on NXP i.MX RT10xx.
- **Execution Flow:**
  1. Copies 8 MPU region definitions (each 8 bytes: RBAR base address + RASR attribute/size word) from static table `DAT_6006f6e4` (`0x6010288c`, 16 32-bit words) into caller-supplied region array `param_2`:
     - Region 0: `RBAR=0x60000000, RASR=0x060B002E` (QSPI NOR Flash)
     - Region 1: `RBAR=0x00000000, RASR=0x06080020` (ITCM Fast RAM)
     - Region 2: `RBAR=0x20000000, RASR=0x130C0024` (DTCM Data RAM)
     - Region 3: `RBAR=0x20200000, RASR=0x130B0024` (OCRAM On-Chip RAM)
     - Region 4: `RBAR=0xE0000000, RASR=0x13000026` (PPB Private Peripheral Bus)
     - Region 5: `RBAR=0x40000000, RASR=0x13050030` (AIPS Peripheral MMIO Space)
     - Region 6: `RBAR=0x00200000, RASR=0x060B0020` (BootROM / FlexRAM aliases)
     - Region 7: `RBAR=0x00000000, RASR=0x10080008` (Null Trap Background Region)
  2. Populates region tracking metadata: `*param_1 = 8` (active regions count), `param_1[1] = 9` (default MPU type identifier).
  3. Validates region limits: if region index $> 15$, triggers assertion at line `0xBB` (187) of `gotham_16mb_mimxrt10xx_mpu.cc` (`DAT_6006f6ec`).
  4. Returns region count `8`.
- **Caller:** `mpu__600cb030` (`mpu.cc` — system boot MPU initialization pass).

### `wakelock__60080180` (132B) — `wakelock.cc`: System Wakelock Acquisition Coordinator
- **Role:** Coordinates power management wakelocks that inhibit deep sleep and low-power CPU states during active gameplay, haptics, and audio streaming.
- **Concurrency & Reference Counting:**
  1. Issues data memory barrier `DataMemoryBarrier(0x1B)`.
  2. Pointer `piVar5 = param_1 + 2` points to 32-bit reference counter `wakelock->ref_count`.
  3. Checks valid state: if `param_1[2] == -1` (refcount overflow), logs error at line `0x13` (19) of `wakelock.cc` (`DAT_600801d4` = `"Too many objects preventing shutdown!"`) and returns error `8` (`kInvalidState`).
  4. Atomic Increment: Uses Cortex-M `LDREX` (`ExclusiveAccess`) and `STREX` (`hasExclusiveAccess`) loop to increment `ref_count`:
     ```c
     do {
         ExclusiveAccess(piVar5);
         prev_count = *piVar5;
     } while (!hasExclusiveAccess(piVar5));
     *piVar5 = prev_count + 1;
     ```
  5. **First Acquisition Dispatch (`prev_count == 0`):**
     - Obtains power manager lock `thunk_EXT_FUN_0000b4c2(pwr_mgr + 0xBC)`.
     - Reads wakelock bit index: `lock_id = *(uint8_t *)(param_1 + 1)`.
     - Updates active wakelocks bitmask: `*(uint32_t *)(pwr_mgr + 0x14C) |= (1 << lock_id)`.
     - Invokes hardware low-power inhibitor: `FUN_600df014(pwr_mgr)` (adjusts clock gating and low-power sleep modes).
     - Releases power manager lock `thunk_EXT_FUN_00007d10(pwr_mgr + 0xBC)`.
  6. Returns `0` (`kOk`).
- **Caller:** `application_state__6005b8dc`.

### `event_groups__600c9d44` (60B) & `event_groups__600c9d88` (68B) — `event_groups.c`: FreeRTOS Event Groups
- **`event_groups__600c9d44` (`xEventGroupCreateStatic`):**
  - Takes `StaticEventGroup_t *pxEventGroupBuffer` (`param_1`).
  - Enforces `configASSERT(pxEventGroupBuffer != NULL)` at line `0x62` (98) of `event_groups.c` (`DAT_600c9d84`).
  - Initializes event bits: `pxEventGroup->uxEventBits = 0` (`*param_1 = 0`).
  - Initializes waiting task list: `thunk_EXT_FUN_0000b2e8(param_1 + 1)` (`vListInitialise(&pxEventGroup->xTasksWaitingForBits)`).
  - Marks static allocation flag: `((uint8_t *)param_1)[0x1C] = 1` (`ucStaticallyAllocated = pdTRUE`, represented as `*(param_1 + 7) = 1` in 32-bit word indexing).
  - Returns `EventGroupHandle_t` pointer.
  - **Callers:** `FUN_6006e854`, `FUN_600765a4`, `FUN_60055730`, `FUN_6005cd20`.
- **`event_groups__600c9d88` (`vEventGroupDelete`):**
  - Suspends scheduler: `thunk_EXT_FUN_0000713c()` (`vTaskSuspendAll()`).
  - Unblocks pending waiting tasks: while list count `*(int *)(param_1 + 4) != 0`:
    - Asserts list item integrity at line `0x263` (611) of `event_groups.c`.
    - Unblocks task: `thunk_EXT_FUN_000075ec(item, 0x02000000)` (`xTaskRemoveFromEventList` with `eventUNBLOCKED_DUE_TO_BIT_SET = 0x02000000`).
  - Dynamic Memory Reclamation: if `ucStaticallyAllocated == pdFALSE` (`*(char *)(param_1 + 0x1C) == 0`), frees buffer via `thunk_EXT_FUN_000080d8(param_1)` (`vPortFree`).
  - Resumes scheduler: `thunk_EXT_FUN_0000728c()` (`xTaskResumeAll()`).
  - **Callers:** `FUN_6006e854`, `FUN_6006e9b0`, `FUN_600d15f8`.

### `flash_memory__60067e8c` (130B) — `flash_memory.h`: Flash Bounds & Capacity Verification
- **Role:** Protects NOR flash physical memory by enforcing strict boundary and capacity checks before read, write, or erase operations.
- **Execution Flow:**
  1. Queries flash driver sector/block size via vtable call `(**(code **)(*param_1 + 0x14))()`.
  2. Computes total flash storage capacity: `total_capacity = block_size * *(int *)(param_1[1] + 4)`.
  3. **Boundary Verification:**
     - Checks `if (total_capacity < offset + length)`:
       - Formats error message with `offset` (`param_2`), `length` (`param_3`), and `total_capacity`.
       - Logs out-of-bounds error at line `0x132` (306) of `flash_memory.h` (`DAT_60067f10` = `"flash_memory.h"`, `DAT_60067f14` = `"Attempted out-of-bound flash memory access (address: "`, `DAT_60067f18` = `" length: "`) at log level `0x28`.
       - Returns error code `3` (`kOutOfRange` / `kInvalidArgument`).
     - Otherwise returns `0` (`kOk`).
- **Callers:** `mimxrt10xx_flash_memory__60068024`, `FUN_600d8052`, `FUN_600d808e`, `FUN_600d9b8e`, `FUN_600d9bc6`.

### `parser__600834a4` (136B) — `parser.cc`: JSON Payload Parser
- **Role:** Parses and decodes incoming structured JSON command payloads received over communication endpoints.
- **Execution Flow:**
  1. Initializes JSON parser stack context: `FUN_600edfcc(auStack_b4)`.
  2. Invokes JSON token decoder: `iVar1 = FUN_600edcd6(auStack_b4, param_1[0], param_1[1], param_1[2], param_1[3])`.
  3. Records parser return code: `param_1[4] = iVar1`.
  4. **Error Handling:**
     - If `iVar1 < 0`:
       - Formats error string containing numeric parse error code: `"JSON parsing error: <err>"` via `FUN_60101b0c` (`DAT_60083530` = `"JSON parsing error: "`).
       - Logs parsing failure at line `0x1F` (31) of `parser.cc` (`DAT_6008352c` = `"parser.cc"`).
       - Resets status word: `param_1[4] = 0`.
       - Returns error status `8` if `iVar1 == -1` (`kBufferUnderflow`), else `0x0F` (`kMalformedPacket`).
     - If `iVar1 >= 0`: returns `0` (`kOk`).
- **Caller:** `FUN_600d4664`.

### `get_device_data__60078b4c` (134B) — `get_device_data.cc`: Device Config & Telemetry Query
- **Role:** Extracts system serial numbers, hardware revision codes, and factory calibration blocks from the persistent key-value configuration store.
- **Execution Flow:**
  1. Probes telemetry store availability via `FUN_600d6e14()`. If uninitialized (`0`), sets `*param_3 = 0` (absent).
  2. Queries config key: calls `keys__60065eb8(param_1, param_2, type=0x20)`.
  3. If key exists (returns `\0`): sets `*param_3 = 1` (present/valid).
  4. If key lookup fails:
     - Formats key name via `FUN_600d736c(param_1, ...)`.
     - Logs missing key trace `"Failed to read <key> from KVS"` (`DAT_60078bd8`, `DAT_60078bdc`) at line `0x14` (20) of `get_device_data.cc` (`DAT_60078bd4`).
     - Sets `*param_3 = 0`.
- **Caller:** `FUN_60078be0`.

### `util__60092128` (132B) — `util.cc`: Key-Value Dictionary / Argument Sequence Walker
- **Role:** Searches structured key-value descriptor arrays and configuration tables for key identifiers, logging diagnostics on missing or duplicate values.
- **Execution Flow:**
  1. Validates stream header magic: `if (*param_1 != '\x01') return 3;`.
  2. Iterates over `param_2` descriptor entries (index `iVar2 = 1 .. param_2`):
     - Extracts descriptor fields and invokes descriptor validator/comparator: `FUN_600edc9c(*(param_1 + 0x10), *(param_1 + 0x14), *(param_1 + 0x18), *(param_1 + 0x1c), param_3, param_4)`.
     - If validator returns non-zero (key match found):
       - If descriptor value slot is `0`: logs info at line `0x97` (151) of `util.cc` (`DAT_600921ac` = `"Key '%s' found with no matching value. Using the key's index.\n"`).
       - If descriptor value slot $> 1$: logs warning at line `0x9F` (159) of `util.cc` (`DAT_600921b4` = `"Multiple matching values for key '%s'. Using the first value.\n"`).
       - If `param_5 != NULL`: sets `*param_5 = iVar2` (matched descriptor sequence index) and returns `0`.
     - Advances descriptor pointer by 16 bytes: `param_1 += 0x10`.
  3. Returns error code `5` (`kNotFound`) if no matching descriptor is found.
- **Caller:** `FUN_600dfcf2`.

### `external_controller__6007053c` (180B) — `external_controller.cc`: External Haptic / Motor Controller Driver
- **Role:** Transmits dual-motor rumble magnitudes (Left/Right) to the dedicated external haptics controller IC.
- **Execution Flow:**
  1. Issues double memory barrier `DataMemoryBarrier(0x1B)`.
  2. Checks enabled status: if `*DAT_600705f0 == '\0'`, returns immediately.
  3. Packs Left and Right 16-bit rumble magnitudes into a single 32-bit word: `local_14 = CONCAT22((short)param_2, (short)param_1);`.
  4. Acquires controller mutex `thunk_EXT_FUN_0000b4c2(DAT_600705f4)`.
  5. Obtains controller handle `iVar2 = FUN_6007014c(0)`.
  6. Transmits rumble command packet via `FUN_6006543c(*(iVar2 + 4), DAT_600705f8, &local_14, ...)`.
  7. **Error Tracking & Recovery:**
     - If transfer returns `0x0E` (`kUnavailable`): increments consecutive error count `*(int *)(iVar2 + 8)++`.
     - If transfer succeeds: resets error count `*(int *)(iVar2 + 8) = 0`.
     - If consecutive errors persist and recovery check `FUN_600d7cdc()` passes:
       - Logs error trace at line `0xCA` (202) of `external_controller.cc` (`DAT_600705fc` = `"external_controller.cc"`, `DAT_60070600` = `"%lu consecutive haptics HID packets dropped due to UNAVAILABLE"`).
       - Triggers hardware recovery callback `(*DAT_60070604)(DAT_60070604[1], DAT_60070608)` (metric `"HAPTICS_HID_PKTS_DROPPED"`).
  8. Releases controller mutex `thunk_EXT_FUN_00007d10(DAT_600705f4)`.
- **Caller:** `haptics_cluster__600658b4` (`haptics_cluster.cc` — the per-tick haptic drive loop).

### `led_calibration__600d4596` (178B) — `led_calibration.cc`: TI LP5562 RAW (Red/Amber/White) LED Calibration & Color Trim
- **Role:** Computes and applies factory color-balance calibration trims to the TI LP5562 4-channel LED driver controlling the front indicator LEDs (Red, Amber, and White channels).
- **Execution Flow:**
  1. Checks if calibration was already applied (`*DAT_6005e008`).
  2. If first execution:
     - Probes calibration validity: `FUN_6005ded8()`. If valid, marks `*DAT_6005e008 = 1`.
     - Logs calibration constants at line `0x35` (53) of `led_calibration.cc` (`DAT_6005e00c` = `"led_calibration.cc"`, `DAT_6005e01c` = `"LED calibration: R=0x%02X A=0x%02X W=0x%02X"`) with raw Red (`*DAT_6005e018`), Amber (`*DAT_6005e014`), and White (`*DAT_6005e010`) trim bytes.
  3. **Floating Point Gain Calculation:**
     - Red: converts `*DAT_6005e018` to float, multiplies by scale factor `1.0f`, converts to unsigned integer `uVar5`.
     - Amber: converts `*DAT_6005e014` to float, multiplies by `1.0f`, converts to unsigned integer `uVar6`.
     - White: converts `*DAT_6005e010` to float, multiplies by `1.0f`, converts to unsigned integer `uVar7`.
  4. Obtains LP5562 driver instance `uVar3 = FUN_600653e0()`.
  5. Programs LED driver current registers: `led_driver_lp5562__6006b1d0(uVar3, r=uVar5 & 0xFF, a=uVar6 & 0xFF, 0, w=uVar7 & 0xFF);`.
- **Caller:** `main__60051240` (system startup sequence).

## Wave 5 Decompilation (Final 100% Attributed File Completion Sweep)

### `pwm__600600c4` (38B), `pwm__600600f8` (38B), `pwm__6006012c` (40B) — `pwm.h`: NXP PWM Peripheral Channel & Submodule Helpers
- **Role:** Inline helper routines for NXP i.MX RT10xx eFlexPWM (Pulse Width Modulation) submodule index translation, submodule mask generation, and MMIO base address resolution.
- **Functions:**
  - **`pwm__600600c4` (`PwmSubmoduleIndex`):**
    - Switches on submodule enum `param_1` (0..3) returning submodule indices `0`, `1`, `2`, `3` (`kPWM_Module_0` through `kPWM_Module_3`).
    - Enforces strict enum bounds: default case triggers fatal assertion `FUN_601016a2("pwm.h", line 0x74 = 116, "NOTREACHED")` and halts in an infinite spin loop `b 0x600600e4`.
    - **Callers:** `FUN_600d4c3a`, `FUN_600d4b78`, `FUN_600d4cae`, `FUN_600601a4`, `FUN_600d4a7e`, `FUN_60060284` (haptics and LED PWM configuration).
  - **`pwm__600600f8` (`PwmSubmoduleMask`):**
    - Switches on submodule enum `param_1` (0..3) returning bitmask `1 << param_1`: `0 -> 0x01` (`kPWM_Submodule_0_Mask`), `1 -> 0x02` (`kPWM_Submodule_1_Mask`), `2 -> 0x04` (`kPWM_Submodule_2_Mask`), `3 -> 0x08` (`kPWM_Submodule_3_Mask`).
    - Default case triggers fatal assertion `FUN_601016a2("pwm.h", line 0x82 = 130, "NOTREACHED")` and halts.
    - **Callers:** `FUN_600d4c3a`, `FUN_600d4b78`, `FUN_600d4cae`, `FUN_600601a4`, `FUN_600d4ada`, `FUN_600d4b28`, `FUN_60060284`.
  - **`pwm__6006012c` (`PwmBaseAddress`):**
    - Switches on module index `*param_1` (0..3) to return the MMIO base address of the selected eFlexPWM block:
      - `0 -> 0x403DC000` (NXP `PWM1` peripheral base).
      - `1 -> 0x403E0000` (NXP `PWM2` peripheral base).
      - `2 -> 0x403E4000` (NXP `PWM3` peripheral base).
      - `3 -> 0x403E8000` (NXP `PWM4` peripheral base).
    - Default case triggers fatal assertion `FUN_601016a2("pwm.h", line 0x41 = 65, "NOTREACHED")` and halts.
    - **Callers:** `FUN_600d4c3a`, `FUN_600d4b78`, `FUN_600d4cae`, `FUN_600601a4`, `FUN_600d4a7e`, `FUN_600d4ada`, `FUN_600d4b28`, `FUN_60060284`.

### `usb_configuration_handler__600619bc` (112B) — `usb_configuration_handler.cc`: Dynamic USB Configuration & Headset Audio Descriptor Selector
- **Role:** Selects the appropriate USB configuration descriptor and length depending on active BLE connection status and analog 3.5mm headset/microphone accessory detection.
- **Execution Flow:**
  1. Obtains Gotham main context via `iVar1 = FUN_6005bdac()`.
  2. Queries active BLE link state via `FUN_600dffe8(iVar1 + 0x448, 7)`.
  3. **BLE Connected Mode:**
     - If BLE link is active (`iVar1 != 0`), USB audio/gamepad endpoints are withheld so the host does not double-enumerate inputs:
     - Logs at level `0x14` (`kInfo`), line `0x28` (40) of `usb_configuration_handler.cc` (`0x6011E43D`): `"Plugged in while ble is connected (BLE_HID)"` (`0x6011E6BD`).
     - Sets descriptor pointer `*param_2 = 0x6011E4AA` and length `param_2[1] = 0x28` (40 bytes — minimal USB charging / BLE_HID mode).
  4. **USB Active / Wired Mode:**
     - Checks analog audio accessory detection state in global peripheral context `0x200064C0` at offsets `0x4344` (headset present) and `0x4345` (microphone present):
     - **No Headset:** (`*(char *)(0x200064C0 + 0x4344) == 0`):
       - Selects standard USB Gamepad HID descriptor: `*param_2 = 0x6011E45A`, length `0x50` (80 bytes).
     - **Headset Without Mic:** (`*(char *)(0x200064C0 + 0x4345) == 0`):
       - Logs at line `0x36` (54): `"Detected headset without microphone."` (`0x6011E70B`).
       - Selects Gamepad HID + USB Audio Output (headphone speaker) descriptor: `*param_2 = 0x6011E4D2`, length `0xCC` (204 bytes).
     - **Headset With Mic:** (`*(char *)(0x200064C0 + 0x4345) != 0`):
       - Logs at line `0x30` (48): `"Detected headset with microphone."` (`0x6011E6E9`).
       - Selects Gamepad HID + USB Audio Duplex (speaker + microphone) descriptor: `*param_2 = 0x6011E59E`, length `0x11F` (287 bytes).
  5. Returns status `0` (`kOk`).

### `reboot_reason__60059f98` (108B) — `reboot_reason.cc`: NXP SNVS Reboot Reason & Reset Status Decoder
- **Role:** Reads persistent reset reason and crash flags from NXP SNVS Non-Volatile General-Purpose Registers (GPR0..GPR3) across reboots.
- **Execution Flow:**
  1. Initializes output buffer `*param_1 = 0; param_1[1] = 0;`.
  2. Iterates `i = 0..3` calling `snvs__60059f00(0x20009D74, i, &local_28[i])` to read 4 words from the SNVS GPR register block. Returns immediately if any register read fails.
  3. **Reboot Reason Decoding:**
     - Checks if GPR0 (`local_28[0]`) has high bit 31 set (`local_28[0] < 0`, indicating a valid reboot code is stored).
     - Extracts base reboot code: `*param_1 = local_28[0] - 0x80000000` (masks off valid bit `0x80000000`).
     - Extracts reset status bitflags from GPR1 (`local_28[1]`):
       - Byte 0 (offset `+4`): `local_28[1] & 1` (flag 0: clean software reset).
       - Byte 1 (offset `+5`): `(local_28[1] >> 1) & 1` via `ubfx` (flag 1: hardware watchdog reset).
       - Byte 2 (offset `+6`): `(local_28[1] >> 2) & 1` via `ubfx` (flag 2: brownout / low battery reset).
     - If `param_2 == 0` (clear requested on read), attempts to clear persistent flag via `FUN_60059eb8(0, 0, 0)`. If clear fails:
       - Logs warning at level `0x28` (`kWarn`), line `0x36` (54) of `reboot_reason.cc` (`0x6011BB1C`): `"Unable to erase the reboot reason flag."` (`0x6011BB34`).
  4. Returns decoded result pointer `param_1`.
- **Callers:** `main__60051240` (system startup), `application_state__6005b1c0`.

### `persistent_crash_register__60061cc8` (100B) — `persistent_crash_register.cc`: Persistent Crash Signature Storage (`CwyCrashSign`)
- **Role:** Encodes CPU crash dumps, register state, and fault signatures into the non-volatile persistent storage key `"CwyCrashSign"`.
- **Execution Flow:**
  1. Initializes stack crash register frame `FUN_600d5122(stack_84)`.
  2. Probes hardware fault status via `FUN_600d512e(*param_1, stack_84)`. If no fault recorded (`status != 0`), exits.
  3. Formats formatted crash signature string via `FUN_60061c48(stack_84, stack_74, max_len=100)`.
  4. If formatted string length $\ge 100$:
     - Logs warning at level `0x1E` (`kWarn`), line `0x6A` (106) of `persistent_crash_register.cc` (`0x6011E792`): `"Signature clipped to store in buffer"` (`0x6011E7AF`).
  5. If crash string is empty (`uVar1 == 0`):
     - Erases persistent key `"CwyCrashSign"` (`0x6011C88D`) via `FUN_6010112c(param_2, "CwyCrashSign")`. Returns `0` if successful or not found (`code 5`).
  6. If crash string is present:
     - Commits crash signature to non-volatile memory via `FUN_60101198(param_2, "CwyCrashSign", stack_74, (uVar1 + 1) & 0xFFFF)`.
- **Caller:** `FUN_6005f8c0` (system panic & crash dump generator).

### `i2c_device__6006820c` (100B) — `i2c_device.h`: I2C Bus Speed & Parameter Configuration Helper
- **Role:** Configures I2C bus baud rate / clock speed parameters for connected peripheral ICs (e.g. TI LP5562 RGB LED driver, audio codec).
- **Execution Flow:**
  1. Loads 6-byte I2C device transaction descriptor into stack buffer via `FUN_600d82d8(auStack_a8, param_1, 6)`.
  2. Range validation: tests if `(param_2 & ~0x07) != 0` (speed enum index $> 7$):
     - Logs diagnostic assertion at line `0x52` (82) of `i2c_device.h` (`0x601203D1`) via `FUN_600d37ac` and sink `FUN_60101740`.
  3. Updates I2C speed field: shifts `param_2 << 3` into descriptor bitfield `[5:3]` (`auStack_a8[5] = (param_2 << 3) & 0x38 | (auStack_a8[5] & ~0x38)`).
  4. Commits updated I2C configuration descriptor to driver context via `FUN_600d82c0(auStack_a8)`.
- **Caller:** `timer__60074658`.

### `logging__60067ddc` (98B) — `logging.cc`: Diagnostic Log Record Flush & Telemetry Sink
- **Role:** Flushes pending buffered log records to the telemetry stream and resets log pending state.
- **Execution Flow:**
  1. Checks pending log count at `*(int *)(param_1 + 0x6C)`. If 0, returns immediately with 0 (`kOk`).
  2. Prepares 128-byte stack log buffer: formats prefix tag header via `FUN_60101b76(&local_a0, *(param_1 + 8))` (source subsystem and timestamp).
  3. Extracts pending log message body via `uVar2 = FUN_600d7fec(param_1, buffer_ptr, remaining_space)`.
  4. Appends payload to formatted record via `FUN_60101ba2(&local_a0, uVar2)`.
  5. Dispatches log record to system logger at level `0x14` (`kInfo`), line `0x28` (40) of `logging.cc` (`0x6012035E`) via `FUN_601016f0`.
  6. Clears pending counter: `*(int *)(param_1 + 0x6C) = 0`.
  7. Returns 0 (`kOk`).

### `key_value_store__600cb210` (88B) — `key_value_store.h`: KeyValueStore Block-Aligned Sector Capacity Calculator
- **Role:** Calculates the maximum block-aligned sector storage capacity (up to 64 bytes) for a key-value store partition.
- **Execution Flow:**
  1. Invokes partition vtable method at `+0x10` (`(**(code **)(*(int *)*param_1 + 0x10))()`) to query partition sector / block size `uVar1`.
  2. Bounds check: if sector size $> 0x40$ (64 bytes):
     - Formats error message and logs warning at line `0x118` (280) of `key_value_store.h` (`0x6013C7DE`) via `FUN_600d37ac` / `FUN_60101740`.
  3. Re-queries sector size `uVar1`.
  4. Computes aligned block multiple: `return (0x40 / uVar1) * uVar1` (using unsigned division `udiv r3, r3, r0` followed by multiplication `muls r0, r3`).
- **Callers:** `key_value_store__600cb460`, `FUN_60100d30`.

### `srtc__60060804` (80B) — `srtc.cc`: Secure RTC (SNVS SRTC) Hardware Initialization & Crystal Lock Verification
- **Role:** Initializes NXP SNVS High-Power / Low-Power Secure Real-Time Clock (SRTC) module and verifies external 32.768 kHz crystal oscillator lock status.
- **Execution Flow:**
  1. Acquires SNVS hardware mutex via `thunk_EXT_FUN_0000b4c2()`.
  2. Checks initialized flag at `*(char *)(param_1 + 100)` (`+0x64`). If already initialized, unlocks mutex via `thunk_EXT_FUN_0000887a()` and returns 0.
  3. **First-Time Initialization:**
     - Prepares stack SRTC configuration context `FUN_600cfb2c(&uStack_10)`.
     - Initializes SNVS base register `0x400D4000` (NXP `SNVS` MMIO peripheral) via `FUN_60054330(0x400D4000, &uStack_10)`.
     - Programs 32.768 kHz LP oscillator clock divider count 4 via `FUN_600cfb42(0x400D4000, 4)`.
     - Probes external crystal oscillator lock status via `iVar1 = FUN_600607a8()`.
     - If external crystal fails to lock (`iVar1 == 0`):
       - Logs warning at level `0x1E` (`kWarn`), line `0x30` (48) of `srtc.cc` (`0x6011DDA7`): `"Internal oscillator in use; SRTC will be imprecise."` (`0x6011DDAF`).
     - Marks initialized: `*(char *)(param_1 + 100) = 1`.
  4. Unlocks mutex via `thunk_EXT_FUN_0000887a()` and returns 0.
- **Caller:** `xbara__600cbdc8` (board bring-up / hardware initialization).

### `info__6006180c` (62B) — `info.cc`: Bootloader & Firmware Build Version Metadata Resolver
- **Role:** Resolves bootloader partition build metadata (build version string, git commit hash) from the binary build metadata header.
- **Execution Flow:**
  1. Queries build info manager instance `uVar1 = FUN_600653f0()`.
  2. Queries bootloader partition descriptor `iVar2 = FUN_60083f98()`.
  3. If bootloader partition descriptor is missing (`iVar2 == 0`):
     - Logs error at level `0x14` (`kInfo`), line `0x38` (56) of `info.cc` (`0x6011E2BC`): `"Couldn't identify which bootloader."` (`0x6011E2D7`).
     - Logs fallback trace at line `0x73` (115): `"No bootloader metadata found, using default build version."` (`0x6011E323`).
     - Returns NULL (`0`).
  4. If bootloader partition present:
     - Locates binary metadata header via `binary_build_metadata__600678ec(uVar1, iVar2)`.
     - If metadata found (`iVar2 != 0`): returns build version string pointer at `*(undefined4 *)(iVar2 + 0x14)`.
     - If metadata missing: logs error at line `0x3E` (62) `"Bootloader doesn't have metabuild info."` (`0x6011E2FB`), logs fallback at line `0x73` (115), and returns NULL (`0`).
- **Callers:** `FUN_6006185c`, `FUN_60077140`, `application_state__6005b150`.

### `transfer_bug_report__6007946c` (48B) — `transfer_bug_report.cc`: Diagnostic Bug Report RPC Dispatcher
- **Role:** Handles diagnostic bug report / crash log transfer RPC requests received over Bluetooth LE / USB diagnostic channels.
- **Execution Flow:**
  1. Validates incoming RPC packet: checks `*(int *)(param_1 + 8) == 3` (Diagnostic Service RPC) and sub-command opcode `*(char *)(param_1 + 0x10) == 0x09` (`kTransferBugReportCommand`).
  2. If matched:
     - Logs transfer start at level `0x14` (`kInfo`), line `99` of `transfer_bug_report.cc` (`0x60124F96`): `"Transfering Bug report"` (`0x6012500C`).
     - Sets up asynchronous stream transfer context `param_2`:
       - Transfer channel / session code: `*(int *)(param_2 + 8) = 0x0E` (14 = `kBugReportTransferSession`).
       - Transfer stream chunk callback: `*(void **)(param_2 + 0x10) = 0x60079399` (`FUN_60079398_1` — bug report chunk pump function).
       - Transfer offset: `*(int *)(param_2 + 0x14) = 0`.
     - Returns `2` (`kHandledWithAsyncStream`).
  3. If command not matched: returns `0` (`kUnhandled`).

### `heap_support__60052254` (44B) — `heap_support.c`: FreeRTOS Heap Allocation Failure Hook (`vApplicationMallocFailedHook`)
- **Role:** FreeRTOS heap exhaustion handler capturing and logging memory telemetry on allocation failure.
- **Execution Flow:**
  1. Reads three global heap telemetry registers:
     - `*0x20011BA8` (`DAT_60052288`): requested allocation size in bytes.
     - `*0x20011BA4` (`DAT_60052284`): largest contiguous free block size in bytes.
     - `*0x20011BA0` (`DAT_60052280`): total free heap remaining in bytes.
  2. Logs fatal out-of-memory error at level `0x1E` (`kWarn`/`kError`), line `0x9F` (159) of `heap_support.c` (`0x6011B319`): `"Malloc failed. Requested size: %lu, Largest free block: %lu, Total free heap: %lu"` (`0x6011B2C7`).
  3. Resets telemetry registers to 0: `*0x20011BA8 = 0; *0x20011BA0 = 0; *0x20011BA4 = 0;`.
  4. Returns to caller (where system assert / panic triggers core dump and reboot).

### `gotham_task__6005bdb4` (44B) — `gotham_task.cc`: Gotham Task Low-Battery Emergency Shutdown Handler
- **Role:** Disables peripheral timers and triggers the emergency low-battery power-down sequence in the Gotham task supervisor.
- **Execution Flow:**
  1. Logs power-down message at level `0x1E` (`kWarn`), line `0x350` (848) of `gotham_task.cc` (`0x6011C355`): `"Low battery: powering down."` (`0x6011C719`).
  2. Stops active peripheral timers and event queues via `FUN_600d40cc(param_1 + 0x440, 0)`.
  3. Dispatches shutdown event to top-level Gotham state machine: calls `state_machine__600849a4(param_1 + 0x448, event_id=0x0D, param_3=0)` (`0x0D` = `kEventLowBatteryShutdown`).

### `init__600cbdd4` (22B) — `init.cc`: FreeRTOS Task Kernel Launcher & Post-Scheduler Trap
- **Role:** Spawns system kernel supervisor tasks and starts the FreeRTOS multitasking scheduler.
- **Execution Flow:**
  1. Spawns system supervisor tasks via `system_tasks__60058574()`.
  2. Launches FreeRTOS scheduler via `tasks__600ca4ac()` (`vTaskStartScheduler()`).
  3. The scheduler call is non-returning in normal operation. If the scheduler returns (due to fatal memory exhaustion):
     - Triggers fatal assertion `FUN_601016a2("init.cc", line 0x38 = 56, "NOTREACHED")` (`0x6013CB38` / `0x6011C653`).
     - Halts in an infinite spin loop `b 0x600cbde8`.
- **Caller:** `main__60051168` (C runtime entry).

### `exit__60051824` (16B) — `exit.c`: Low-Level Bare-Metal CRT `_exit(status)` Abort Handler
- **Role:** Low-level standard C library `_exit(int status)` / `abort()` implementation for ARM Cortex-M7 bare-metal target.
- **Execution Flow:**
  1. Receives process exit `status` in register `r0`.
  2. Triggers fatal assertion at line `5` of `exit.c` (`0x6011B19C`): `"Ended up in _exit() with status %d"` (`0x6011B179`) with the status code formatted into the message via `FUN_601016a2`.
  3. Enters an infinite branch trap `b 0x60051832` (halting CPU).
- **Callers:** `FUN_6010209a`, `FUN_600cdb4c` (newlib/libc abort paths).

---

## Session 48 (Wave 18) — FreeRTOS Heap Metrics, C++ Threading / Synchronization & IEEE 754 Math (15 functions, 1,062 bytes)

Following 100% completion of the Broadcom BTA/BTE Bluetooth stack in Session 47, Wave 18 targets the next major unattributed contiguous block (§3b Run #4: `0x600cc6e4`–`0x600d4560`, 24,998 bytes / 304 functions), decompiling and documenting 15 core functions across FreeRTOS heap inspection, C++ runtime `std::call_once` synchronization / mutex primitives, and single-precision IEEE 754 math routines:

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600cc6e4` |   6 | FreeRTOS / Heap | **`xPortGetFreeHeapSize`** — FreeRTOS heap capacity inspector: reads current free heap bytes (`*DAT_600cc6ec` = `xFreeBytesRemaining`). | 5 callers / 0 callees |
| `0x600cc6f0` |   6 | FreeRTOS / Heap | **`xPortGetMinimumEverFreeHeapSize`** — FreeRTOS heap high-water metric: reads all-time minimum free heap bytes (`*DAT_600cc6f8` = `xMinimumEverFreeBytesRemaining`). | 3 callers / 0 callees |
| `0x600cc6fc` |  24 | FreeRTOS / Heap | **`xPortResetLargestFreeBlockAllocated`** — FreeRTOS heap metric snapshot & reset: enters scheduler critical section via `thunk_EXT_FUN_0000713c()`, snapshots `*DAT_600cc714`, resets with `*DAT_600cc718`, exits critical section via `thunk_EXT_FUN_0000728c()`. | 1 caller / 2 callees |
| `0x600cc824` |  22 | C++ Runtime / Sync | **`cxx_mutex_unlock`** — C++ mutex unlock wrapper: unlocks mutex handle `*DAT_600cc840` via `thunk_EXT_FUN_0000b294` and triggers fatal abort via `FUN_6010209a()` on failure. | 2 callers / 2 callees |
| `0x600cc884` |  20 | C++ Runtime / Thread | **`cxx_thread_self`** — C++ thread-ID resolver: retrieves active thread handle `*DAT_600cc8a4` via `thunk_EXT_FUN_0000b18c`. | 2 callers / 1 callee |
| `0x600cc8a8` |  38 | C++ Runtime / Sync | **`cxx_mutex_lock`** — C++ mutex lock wrapper: sets flag `*param_1 = 1`, locks mutex `*DAT_600cc8dc` via `thunk_EXT_FUN_0000b28c`, and aborts via `FUN_6010209a()` on failure. | 2 callers / 3 callees |
| `0x600cc8e0` |  18 | C++ Runtime / Sync | **`cxx_condvar_broadcast`** — C++ condition variable wake / broadcast: wakes pending threads via `thunk_EXT_FUN_0000b15c()` and aborts on error. | 1 caller / 2 callees |
| `0x600cc8f8` | 122 | C++ Runtime / Sync | **`cxx_call_once_acquire`** — C++ `std::call_once` initialization acquisition primitive: issues DMB (`0x1b`), verifies state bit 31, acquires mutex via `FUN_600cc8a8`, tests in-progress flag `param_1[1]`, loops on thread completion via `FUN_600edffe`, and sets `param_1[1] = 1`. | 32 callers / 6 callees |
| `0x600cc984` |  60 | C++ Runtime / Sync | **`cxx_call_once_release`** — C++ `std::call_once` initialization completion release: clears in-progress flag `param_1[1] = 0`, issues DMB barrier, marks initialized `*param_1 = 1`, broadcasts condition variable via `FUN_600cc8e0()`, and unlocks mutex via `FUN_600cc824()`. | 32 callers / 4 callees |
| `0x600cc9e4` |  72 | C Runtime / Diagnostics | ~~**`cxx_pure_virtual_abort`** — C++ ABI `__cxa_pure_virtual` / diagnostic abort handler~~ ⚠️ **refuted, real identity unconfirmed** *(corrected, QA session 48)* — the format string this function copies (`DAT_600cca2c`, verified byte-for-byte against the raw flash image at its resolved pointer target `0x6013cbea`) reads `"not enough space for format expansion (Please submit full bug report at https://gcc.gnu.org/bugs/):\n    "` — a GCC/libstdc++-internal format-buffer-overflow diagnostic, with nothing about pure-virtual-call dispatch. Behaviorally it copies that 0x68-byte template into a stack buffer, appends a caller-supplied text range (`param_1`..`param_2`) after it, null-terminates, and halts via `FUN_60101fd2` (does-not-return) — consistent with an internal "format-expansion buffer too small" abort helper, not `__cxa_pure_virtual`. Exact standard-library name not yet established. | 1 caller / 2 callees |
| `0x600cca30` |  74 | C Runtime / Format | **`int_to_dec_string`** — Integer to decimal ASCII string formatter: repeatedly computes `param_3 % 10` and `param_3 / 10`, maps digits via `DAT_600cca7c`, and copies to output buffer via `thunk_EXT_FUN_0000b572`. | 1 caller / 1 callee |
| `0x600cca80` | 134 | Libm / Math | **`sinf`** — Single-precision IEEE 754 sine function: compares against threshold `DAT_600ccb08` (`pi/4`), performs argument reduction via `FUN_600ccc10`, and evaluates cosine polynomial `FUN_600cceb0` or sine polynomial `FUN_600cd604`. | 2 callers / 3 callees |
| `0x600ccb10` | 102 | Libm / Math | **`modff`** — Single-precision IEEE 754 `modff`: extracts exponent `(ABS(x) >> 23) - 127`, separates integer and fractional parts via bitmask `DAT_600ccb78 >> exp`. | 1 caller / 0 callees |
| `0x600ccb7c` | 138 | Libm / Math | **`cosf`** — Single-precision IEEE 754 cosine function: compares against threshold `DAT_600ccc08` (`pi/4`), performs argument reduction via `FUN_600ccc10`, and evaluates sine/cosine polynomial kernels. | 2 callers / 3 callees |
| `0x600cceb0` | 226 | Libm / Math | **`__kernel_cosf`** — Single-precision polynomial cosine kernel: evaluates 6th-order Taylor polynomial with split-precision constants `DAT_600ccf94`..`DAT_600ccfa8` (`fdlibm`/`newlib` implementation). | 2 callers / 0 callees |

## Session 49 (Wave 19) — IEEE 754 Math Kernels, CRT Static Init/Exit & Stdio vsnprintf Core (14 functions, 924 bytes)

Resolved stdio / string formatting cluster boundaries in Ghidra DB via `FixSpuriousSplits.java`, plus decompiled and documented 14 functions (924 bytes across `0x600ccea8`–`0x600cdcc4`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ccea8` |   6 | Libm / Math | **`sqrtf`** — Single-precision square root: executes Cortex-M hardware `vsqrt.f32` instruction. | 1 caller / 0 callees |
| `0x600cd604` | 114 | Libm / Math | **`__kernel_sinf`** — Single-precision polynomial sine kernel: evaluates 6th-order polynomial with coefficients `DAT_600cd678`..`DAT_600cd690` (`fdlibm`/`newlib` implementation). | 2 callers / 0 callees |
| `0x600cd738` |   4 | Libm / Math | **`__fp_dummy_zero`** — Floating-point stub helper returning 0. | 1 caller / 0 callees |
| `0x600cd9ac` |  14 | Libm / Math | **`fabsf`** — Single-precision absolute value: clears IEEE 754 sign bit via `param_1 & 0x7fffffff`. | 1 caller / 0 callees |
| `0x600cd9bc` | 126 | Libm / Math | **`floorf`** / **`truncf`** — Single-precision floating-point rounding/truncation: extracts exponent, masks fractional bits, manages FPSCR exception flags. | 1 caller / 0 callees |
| `0x600cda48` | 186 | Libm / Math | **`scalbnf`** — Single-precision scale floating-point by power of 2 ($x \cdot 2^n$): handles normal, subnormal, overflow, and underflow exponent adjustments. | 1 caller / 1 callee |
| `0x600cdb18` |  24 | Libm / Math | **`copysignf`** — Single-precision IEEE 754 `copysignf`: copies sign bit of `param_2` to magnitude of `param_1` via `(param_1 & 0x7fffffff) | (param_2 & 0x80000000)`. | 1 caller / 0 callees |
| `0x600cdb4c` |  40 | CRT / Lifecycle | **`__call_exitprocs`** — Standard C library exit processor: calls registered cleanup hooks and invokes `exit__60051824`. | 1 caller / 1 callee |
| `0x600cdb74` |  56 | CRT / Lifecycle | **`__libc_init_array`** — Standard C/C++ static constructor array iterator: iterates function pointers in `.init_array` (`DAT_600cdbac`..`DAT_600cdbb0`) and executes global constructors. | 1 caller / 2 callees |
| `0x600cdbbc` |  20 | CRT / Reent | **`__getreent`** — Retrieves per-thread reentrancy structure errno pointer `*(reent + 0xec)`. | 3 callers / 0 callees |
| `0x600cdbd8` | 178 | CRT / Reent | **`_reent_cleanup`** — Reentrancy structure resource teardown: walks open stdio FILE streams and flush/close structures (`FUN_600d359a`). | 1 caller / 2 callees |
| `0x600cdc90` |  16 | C Runtime / Signals | **`raise`** — Standard C library `raise(sig)`: sets `r1 = sig`, `r0 = _impure_ptr`, and delegates to `_raise_r` (`0x601023fa`). ⚠️ *(QA session 49)* this table row's own claim is disassembly-grounded and correct (`ldr r3,[pc,#8]; mov r1,r0; ldr r0,[r3]; b.w 0x601023fa` — a genuine, complete 16-byte tail-call trampoline, matching `raise(sig) → _raise_r(_impure_ptr, sig)`), but the **committed `analysis/decomp/FUN_600cdc90.c` is a decompiler artifact**: `0x601023fa` (the tail-call target) has no registered function boundary of its own — it falls in a currently-undefined census gap between `0x601023e0`'s end (`0x601023fa` exactly) and `0x6010244a` — so Ghidra's decompiler bled straight through the tail branch and rendered the *target's* body (a `param_1 < 0x20` bounds check, function-pointer dispatch table lookup, and syscall-trap fallback via `FUN_600ce1e8` — shaped more like a fd/syscall dispatcher than `_raise_r` itself) as if it were part of the 16-byte function, complete with `unaff_r4`/`unaff_r5`/`unaff_lr` uninitialized-register reads (the documented HANDOFF Rule 8 tell) and a callee list in the visible C body that contradicts the file's own header (`0 callees` in the header, matching the true 16-byte boundary, vs. 2 calls visible in the rendered body). Do not cite `FUN_600cdc90.c`'s body content for anything beyond the trampoline shape already described in this row. ~~**GHIDRA-TODO: define a function boundary at `0x601023fa`**~~ ⚠️ **partially resolved, QA session 50**: Session 50 did define the `0x601023fa` boundary (now `_raise_r`, see below) and it decompiled/attributed on its own as intended — but `analysis/decomp/FUN_600cdc90.c` itself was never re-run through Decompile.java and, confirmed byte-identical to before, **still contains the exact same stale artifact content**. Defining a downstream boundary does not retroactively refresh an already-committed decomp file. ~~**GHIDRA-TODO (reopened): re-run Decompile.java on `0x600cdc90`**~~ ⚠️ **STILL NOT FIXED, QA session 52**: Session 52's `FixSignatures.java` pass did re-decompile this file (confirmed by its presence in that commit's diff) and successfully removed the `unaff_r4`/`unaff_r5`/`unaff_lr` tokens — but the underlying artifact is unchanged: the file's body is *still* the bounds-check/dispatch-table logic that belongs to `0x601023fa`, not this function's own real 16-byte trampoline (re-confirmed via direct disassembly this session — the raw bytes at `0x600cdc90` are byte-identical to session 49's reading: `ldr r3,[pc,#8]; mov r1,r0; ldr r0,[r3]; b.w 0x601023fa; nop`, unchanged, still just 4 real instructions). Locking the calling convention suppressed the *symptom* (register-tracking noise) without fixing the *cause* (the decompiler still bleeding through the tail-call boundary). **GHIDRA-TODO (reopened again): this needs a different technique than signature-locking — likely marking the `b.w 0x601023fa` instruction as an explicit non-returning tail-call edge in Ghidra so the decompiler stops rendering the target's body as this function's own.** | 1 caller / 0 callees |
| `0x600cdca0` |  36 | C Runtime / Signals | **`_kill_r`** — Reentrant process signal/kill handler: delegates to `FUN_600ce1e8`. | 0 callers / 1 callee |
| `0x600cdcc4` | 104 | Stdio / Format | **`vsnprintf`** — Standard C library `vsnprintf(buf, size, fmt, ap)`: sets up string output stream (`local_74 = 0x208`, `local_72 = 0xffff`), formats string via `_vfprintf_r` (`FUN_600cddc8`), and null-terminates output buffer. | 28 callers / 1 callee |

## Session 50 (Wave 20) — Reentrant Signals, Stdio Formatting Suite & Low-Level POSIX System Call Stubs (17 functions, 943 bytes)

Resolved Session 49 `GHIDRA-TODO` item (`_raise_r` function boundary defined at `0x601023fa`), plus decompiled and documented 17 functions (943 bytes across `0x600cdd2c`–`0x6010244a`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x601023fa` |  80 | C Runtime / Signals | **`_raise_r`** — Reentrant signal raiser: checks `sig < 0x20`, looks up signal table at `param_1 + 0x44`, dispatches registered handler `handler(sig)`, or default handles via `_kill_r(_getpid_r(param_1), sig)` (`FUN_600cdca0`). This row's *prose* is disassembly-confirmed accurate (verified independently, QA session 50 — the real final branch is a tail-call `b.w 0x600cdca0`, matching exactly). ⚠️ *(QA session 50)* ~~but **the committed `analysis/decomp/FUN_601023fa.c` is not fixed**~~ — **GHIDRA-TODO: re-run Decompile.java on `0x601023fa`... after locking `FUN_600ce1e8`'s signature to zero parameters** ⚠️ **attempted but did not fix the underlying issue, QA session 52**: Session 52's `FixSignatures.java` did re-decompile this file and the `unaff_r4`/`unaff_r5`/`unaff_lr` tokens are gone — but the call to `FUN_600ce1e8` is *still present*, now rendered as `FUN_600ce1e8()` with zero (correct-looking) arguments. This is **still fabricated**: re-confirmed via a fresh full disassembly of all 80 real bytes at `0x601023fa` this session — there is no `bl`/`b`/`blx` to `0x600ce1e8` anywhere in the function; the only two control-flow-leaving instructions are `bl 0x6010244a` (`thunk_FUN_600ce1d8`, correctly shown) and the tail-call `b.w 0x600cdca0` (`_kill_r`), which the decompiled body still omits entirely. Locking `FUN_600ce1e8`'s signature fixed the register-argument noise but not the wrong-callee substitution — the two are separate bugs that happened to look related. **GHIDRA-TODO (reopened, revised): the fix needs to make the decompiler recognize `b.w 0x600cdca0` as this function's real exit path (an explicit tail-call edge), not attempt to resolve whatever confused it into rendering `FUN_600ce1e8` instead — signature-locking on `FUN_600ce1e8` is not the right lever.** | 0 callers / 1 callee |
| `0x6010244a` |   4 | C Runtime / Signals | ~~**`_getpid_r`** — Reentrant getpid helper: sets errno 0x58 on error or returns PID 1~~ ⚠️ **corrected, QA session 50** — this is a plain 4-byte tail-call thunk (`b.w 0x600ce1d8`, disassembly-confirmed) into `FUN_600ce1d8` below, so it unconditionally inherits that function's real behavior: **always** sets the errno-shaped global to `0x58` and **always** returns `-1` (`0xffffffff`). There is no code path that returns PID 1 — the original claim's "or returns PID 1" branch does not exist. | 1 caller / 0 callees |
| `0x600cdd2c` |  64 | Stdio / Format | **`sprintf`** — Standard C library `sprintf(str, fmt, ...)`: formats into string buffer without length bounds via `_vfprintf_r`. | 7 callers / 1 callee |
| `0x600cdd6c` |  28 | Stdio / Format | **`printf`** — Standard C library `printf(fmt, ...)`: outputs formatted text to stdout FILE stream (`*DAT_600cdd84`). | 3 callers / 1 callee |
| `0x600cdd88` |  44 | Stdio / Format | **`vsprintf`** — Standard C library `vsprintf(str, fmt, ap)`: sets up unbounded string output stream and invokes `_vfprintf_r`. | 0 callers / 1 callee |
| `0x600cddb4` |  20 | Stdio / Format | **`fprintf`** — Standard C library `fprintf(fp, fmt, ...)`: format output wrapper delegating to `vsprintf`/`_vfprintf_r`. | 1 caller / 0 callees |
| `0x600cddc8` | 473 | Stdio / Format | **`_vfprintf_r`** — Standard C library reentrant formatted I/O core parsing engine (`vfprintf` conversion parser). | 4 callers / 4 callees |
| `0x600ce1d8` |  12 | POSIX / Process | ~~**`getpid`** — Low-level `getpid()` stub: returns constant process identifier 1 (`0x1`)~~ ⚠️ **corrected, QA session 50** — disassembly-confirmed (`ldr r3,[pc,#8]; movs r2,#0x58; str r2,[r3]; mov.w r0,#-1; bx lr`): this unconditionally sets the errno-shaped global to `0x58` and returns `-1` (`0xffffffff`), **never** `1`. Identical shape to `kill` (`0x600ce1e8`) below — likely a generic "not implemented" stub rather than a real PID accessor; real identity as "getpid" is now unconfirmed. | 0 callers / 0 callees |
| `0x600ce1e8` |  12 | POSIX / Process | **`kill`** — Low-level `kill(pid, sig)` stub: sets errno to ~~`0x16` (`EINVAL`)~~ ⚠️ **`0x58` (likely `ENOSYS`=88 in standard newlib/Linux numbering, not `EINVAL`=22=`0x16`), corrected, QA session 50** — disassembly-confirmed literal (`movs r2,#0x58; str r2,[r3]`) — and returns -1. | 1 caller / 0 callees |
| `0x600ce1f8` |  40 | CRT / Memory | ~~**`_sbrk_r`** — Low-level heap memory expansion hook: manages heap top pointer `*DAT_600ce21c`, checks bounds against heap limit `DAT_600ce218`, sets `ENOMEM` (12) on overflow~~ ⚠️ **identity doubtful, flagged QA session 50** — disassembly shows a genuine backward-branching **loop** (`b #0x600ce1fc`) that walks a list 4 bytes at a time (`param_1[1] += 4` per iteration) with a predicate call (`bl 0x601014d4`) gating each step, not the straight-line "bump a break pointer, bounds-check once" shape a real `_sbrk_r` has. Structurally looks more like a list/queue search or drain loop. Real identity unconfirmed — needs a fresh look rather than the assumed sbrk shape. | 2 callers / 1 callee |
| `0x600ce220` |  18 | POSIX / File I/O | **`_write_r`** — Low-level file descriptor write stub: returns error / non-implemented code. | 1 caller / 1 callee |
| `0x600ce232` |   2 | POSIX / File I/O | **`_close_r`** — Low-level file descriptor close stub: returns 0 (`kOk`). | 0 callers / 0 callees |
| `0x600ce234` |  24 | POSIX / File I/O | **`_fstat_r`** — Low-level file status query: populates `st_mode = 0x2000` (`S_IFCHR` character device) and returns 0. ⚠️ *(QA session 50, weaker finding)* this function's own top-level body (`thunk_EXT_FUN_00007a2c(*(reent+4),5,0,0,0,param_2); return param_1;`) returns `param_1` (the reent pointer), not literally `0`, and doesn't itself show the claimed `st_mode` write — that would have to happen inside the callee thunk, unverified this session. | 3 callers / 1 callee |
| `0x600ce24c` |  16 | POSIX / File I/O | ~~**`_isatty_r`** — Low-level TTY query: returns 1 (terminal character device)~~ ⚠️ **corrected, QA session 50** — disassembly-confirmed (`ldr r3,[r0,#0x20]; ldr r0,[r0,#0x18]; ldr r3,[r3]; lsr.w r0,r3,r0; and r0,r0,#1; bx lr`) computed bit-test: dereferences a pointer at `+0x20`, shifts by a variable amount from `+0x18`, masks with `1` — a genuine runtime-dependent 0/1 result, not a hardcoded constant `1`. | 4 callers / 0 callees |
| `0x600ce25c` |  14 | POSIX / File I/O | ~~**`_lseek_r`** — Low-level seek stub: returns 0~~ ⚠️ **corrected, QA session 50** — actual body is `return FUN_600ce24c() ^ 1;` (the bit-test above, inverted), not a hardcoded `0`. Plausibly gates "is this fd seekable" on the inverse of the `_isatty_r`-shaped check (ttys are typically non-seekable), but that's a hypothesis, not confirmed. | 1 caller / 1 callee |
| `0x600ce26a` |  54 | POSIX / File I/O | ~~**`_read_r`** — Low-level file descriptor read stub: reads bytes from input queue or returns EOF~~ ⚠️ **misidentified, corrected QA session 50** — disassembly shows this function's sole meaningful action is `bl 0x6007f8e4`, a direct call to the already-established `pattern_player__6007f8e4` (`pattern_player.cc`, the audio/haptic pattern-sequencer subsystem — that function's own header already lists this exact address, `0x600ce26a`, as one of its 5 callers), passing a 6-argument bundle built from this function's own parameters plus two words loaded from a caller-supplied structure. This has no plausible connection to POSIX `read()`. Likely misidentified by address-range pattern-matching (sitting between other genuine syscall stubs) rather than content verification. Real identity unconfirmed, but definitively not `_read_r`. | 3 callers / 3 callees |
| `0x600ce2a0` |  38 | POSIX / File I/O | **`_open_r`** — Low-level file open stub: returns file descriptor or `ENOSYS`. | 25 callers / 1 callee |

## Session 51 (Wave 21) — Record Sorting/Formatting Utilities, BLE GATT RPC Wrappers & Hardware BEE Crypto Primitives (16 functions, 1,246 bytes)

Resolved boundary overlap at `0x600cea74` (trimmed from 136B to 132B in `FixSpuriousSplits.java`), plus decompiled and documented 16 functions (1,246 bytes across `0x600ce31c`–`0x600ce9f0`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ce31c` |  56 | Utility / Formatting | **`hex_encode_bytes`** — Hexadecimal string encoder: converts `param_2` binary bytes from `param_1` into uppercase ASCII hex characters in `param_3` and null-terminates. | 3 callers / 0 callees |
| `0x600ce354` | 236 | Algorithms / Heap | **`stats_heap_sift_down_36b`** — Min-heap sift-down algorithm over 36-byte (9-word) records, ordering elements by key field at offset `+8` (`param_6`). Called from `FUN_6005183c` and `FUN_60051a50`. | 2 callers / 0 callees |
| `0x600ce440` |  72 | Algorithms / Sort | **`insertion_sort_shift_36b`** — Insertion sort shift routine: shifts preceding 36-byte records rightward while their key at `+8` exceeds `uVar10`. | 2 callers / 0 callees |
| `0x600ce488` | 116 | Algorithms / Sort | **`insertion_sort_36b`** — Insertion sort over 36-byte records: sorts record range from `param_1` to `param_2` using `memmove` (`thunk_EXT_FUN_0000b588`) and `FUN_600ce440`. Called from `stats__60051b50`. | 1 caller / 2 callees |
| `0x600ce4fc` |  48 | Serialization / Metrics | **`json_format_metric_u32`** — Metric serialization helper: verifies active stream buffer via `FUN_600cc3cc()`, formats integer metric value via `FUN_60050c18`, and appends closing delimiter `}` via `FUN_601019da`. | 6 callers / 3 callees |
| `0x600ce52c` |  48 | Serialization / Metrics | **`json_format_metric_u32_alt`** — Alternate entry point for integer metric serialization into text stream. Called from `stats__60051b50`. | 1 caller / 3 callees |
| `0x600ce55c` |  58 | Serialization / Metrics | **`json_format_metric_str`** — String metric serialization helper: verifies active stream, formats string token via `FUN_600cc4a8`, and appends delimiter via `FUN_601019da`. | 2 callers / 3 callees |
| `0x600ce596` |  54 | Algorithms / Utility | **`swap_records_36b`** — In-place record swap: exchanges contents of two 36-byte (9-word) structs `param_1` and `param_2`. Called from `FUN_60051a50`. | 1 caller / 0 callees |
| `0x600ce708` |  60 | BLE / GATT RPC | **`gatt_client_read_req`** — BLE GATT client read wrapper: executes `FUN_600cf2be(*(param_3[0]), param_3[1], &local_10, 0)` and maps status codes (`4 -> -5`, `0x514 -> -2`, `0 -> 0`, else `-1`). | 0 callers / 1 callee |
| `0x600ce744` |  60 | BLE / GATT RPC | **`gatt_client_write_req`** — BLE GATT client write wrapper: executes `FUN_600cf266(*(param_3[0]), param_3[1], &local_10)` and maps status codes (`4 -> -5`, `0x515 -> -2`, `0 -> 0`, else `-1`). | 0 callers / 1 callee |
| `0x600ce8be` |  32 | BLE / Advertising | **`ble_adv_params_reset`** — Advertising parameter initializer: sets default configuration fields (`param_1[5]=1`, `param_1[8]=3`, `param_1[10]=2`). Called from `FUN_600d4724`. | 1 caller / 0 callees |
| `0x600ce8de` |  84 | BLE / Advertising | **`ble_adv_status_check`** — Advertising status poll: checks and toggles flag bits at `param_1 + 0x44` (bit `0x2000`), sets `param_1 + 0x4c = 2`, polls bit `0x80`, returns 64-bit pair. | 1 caller / 0 callees |
| `0x600ce932` |  42 | Crypto / Utility | **`byte_reverse_copy_16b`** — 16-byte buffer reverse copier: reverses 16 bytes from `param_2` (`r1`) ~~in place~~ ⚠️ **and writes the result into `*param_1` (`r0`) — a separate destination, not in-place, corrected QA session 51** — disassembly-confirmed (`ldrb r4,[r3,#-0x1]!` walking backward from `r1+0x10`, `strb r4,[r2,#1]!` into a stack scratch buffer, then 4× `ldr r3,[sp,#N]; str r3,[r0,#N]` copying that reversed buffer out to `r0`, never touching `r1` again). The function's own name (`_copy_`) already correctly implied this; only the prose's "in place" was wrong. Called from `FUN_600ce96e`. | 1 caller / 0 callees |
| `0x600ce95c` |  18 | Crypto / BEE | **`bee_context_init`** — Bluetooth Encryption Engine (BEE) context initializer: zeroes structure and initializes config word `*(param_1 + 0xc) = 0xf0000000`. Called from `bee__6005ef04`. | 1 caller / 0 callees |
| `0x600ce96e` | 130 | Crypto / BEE | **`bee_key_config`** — BEE encryption key loader: validates 16-byte key length (`param_4 == 0x10`), sets mode bits `*param_1 |= 0x20`, copies reversed key via `FUN_600ce932`. Called from `bee__6005ef04`. | 1 caller / 1 callee |
| `0x600ce9f0` | 132 | Crypto / BEE | **`bee_aes_ccm_encrypt_start`** — BEE AES-CCM hardware crypto launcher: validates block alignment (`param_6 >= 0x10 && (param_6 & 0xf) == 0`), sets opcodes `0x322`/`0x722`, and invokes hardware trigger via indirect call `(*DAT_6013d0fc)()`. Called from `FUN_60052c78`. | 1 caller / 0 callees |

## Session 52 (Wave 22) — BEE Hardware Decryption, DMA Channel Engine & Hardware Timer Stubs (14 functions, 928 bytes)

Resolved Session 50 `GHIDRA-TODO` items via `FixSignatures.java` (re-decompiling `0x600cdc90` and `0x601023fa` with typed signatures), plus decompiled and documented 14 functions (928 bytes across `0x600cea74`–`0x600cee6e`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600cea74` | 132 | Crypto / BEE | **`bee_aes_ccm_decrypt_start`** — BEE AES-CCM hardware decryption launcher: validates 16-byte block alignment (`param_6 >= 0x10 && (param_6 & 0xf) == 0`), encodes direction flags `0x222`/`0x622`, and triggers hardware via indirect call `(*DAT_6013d0fc)()`. Called from `FUN_60052ccc`. | 1 caller / 0 callees |
| `0x600ceaf8` |  18 | Crypto / BEE | **`bee_hw_config_init`** — BEE hardware configuration state initializer: initializes 5-byte struct (`param_1[0]=1`, `param_1[2]=1`, `param_1[3]=0xf`, `param_1[4]=0`). Called from `FUN_6005f3e0`. | 1 caller / 0 callees |
| `0x600ceb0a` | 112 | Hardware / DMA | **`dma_channel_config_copy`** — DMA channel descriptor loader: copies 32-byte (8-word) channel descriptor from `param_3` into array offset `param_1 + param_2 * 0x20 + 0x1000`. | 0 callers / 0 callees |
| `0x600ceb7a` |  14 | Crypto / BEE | **`bee_channel_state_reset`** — BEE channel state struct reset: clears 4-byte struct fields (`param_1[0]=0`, `param_1[1]=1`, `param_1[2]=0`, `param_1[3]=0`). Called from `FUN_6005f5d4`. | 1 caller / 0 callees |
| `0x600ceb88` |  28 | Hardware / DMA | **`dma_channel_desc_init`** — DMA channel descriptor initializer: zeroes 32-byte channel descriptor and sets default control flag `*(param_1 + 7) = 8`. | 0 callers / 0 callees |
| `0x600ceba4` |  66 | Hardware / DMA | **`dma_channel_desc_pack`** — Packs DMA channel parameters from `param_2` into 32-byte channel descriptor `param_1`, setting base address and flag bits (`0x10` if `param_3 != 0`). | 0 callers / 0 callees |
| `0x600cebe6` |  40 | Hardware / DMA | **`dma_channel_status_get`** — Retrieves DMA channel status flags: extracts bit `param_2` from `param_1 + 0x24` (shifted by 2), bit from `param_1 + 0x2c` (shifted by 1), and channel status word from `param_1 + param_2 * 0x20 + 0x101c` (bit 7). | 16 callers / 0 callees |
| `0x600cec0e` |  18 | Hardware / DMA | **`dma_channel_transfer_init`** — Initializes DMA transfer state: sets transfer length/handle at `param_1 + 0xc`, zeroes status bytes `0x11, 0x12, 0x13, 0x15`, and sets mode byte `param_1 + 0x14 = param_3`. Called from `FUN_6005427c` and `FUN_600542d4`. | 2 callers / 0 callees |
| `0x600cec26` | 144 | Hardware / DMA | **`dma_channel_transfer_config`** — Configures DMA channel transfer descriptor: maps transfer widths (`1 -> 0, 2 -> 1, 4 -> 2, 0x10 -> 4, 0x20 -> 5`), computes block step `param_7 / param_6`, configures source/destination stride. Called from `FUN_600cf8de`. | 1 caller / 0 callees |
| `0x600cecb6` |  82 | Hardware / DMA | **`dma_channel_irq_enable`** — DMA channel interrupt control: sets channel active flags `*(param_1 + 8 + 0x1b) = param_1[0x10] & 0x1f`, executes privileged `disableIRQinterrupts()` / `enableIRQinterrupts()` around channel register updates. Called from `FUN_600cf8de`. | 1 caller / 0 callees |
| `0x600ced08` |  40 | Hardware / DMA | **`dma_channel_stop`** — Stops DMA channel: clears channel control registers at `*(param_1 + 8) + param_1[0x10] * 0x20 + 0x1018`, resets state bytes `0x11, 0x12, 0x13`. | 4 callers / 0 callees |
| `0x600ced30` | 146 | Hardware / DMA | **`dma_channel_transfer_cback`** — DMA transfer completion callback dispatcher: calculates transferred bytes from ring offset `*(iVar4 + 0x1018)`, updates transfer counter `param_1 + 0x13`, and invokes completion callback `(*param_1)(param_1, param_1[1], uVar5)`. | 16 callers / 0 callees |
| `0x600cedc2` |  22 | Hardware / Timer | **`hardware_timer_state_init`** — Hardware timer channel state initializer: sets timer enable bytes (`*param_1 = 1, *(param_1+4) = 1, param_1[9]=1, param_1[10]=1, param_1[13]=1`). Called from `hardware_timer__60061a98`. | 1 caller / 0 callees |
| `0x600cee6e` |  66 | Hardware / Timer | **`hardware_timer_clock_config`** — Hardware timer clock source and prescaler configurator: parses clock selection bits (`param_2 & 0x3c00`), maps clock divisor codes (`0x386`, `0x387`, `0x389`, `0x38a`), configures control register `*(param_1 + 0x10) |= 0x300`. Called from `FUN_600ceeb0`. | 1 caller / 0 callees |

## Session 53 (Wave 23) — I2C Master Engine, BLE GATT Stream Transport, Audio Curve & DMA Ring Primitives (20 functions, 1,298 bytes)

Resolved Session 50/52 `GHIDRA-TODO` item via `FixTailCalls.java` (`setFlowOverride(FlowOverride.CALL_RETURN)` on tail branches `0x600cdc96`, `0x60102428`, `0x6010244a`, `0x600cddbe`), cleanly decoupling `raise` (`0x600cdc90`) and `_raise_r` (`0x601023fa`), resolved boundary overlap at `0x600cf63e` (trimmed from 86B to 32B in `FixSpuriousSplits.java`), plus decompiled and documented 20 functions (1,298 bytes across `0x600cefde`–`0x600cf63e`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600cefde` |  20 | Hardware / I2C | **`i2c_bus_busy_check`** — I2C bus busy probe: checks state bits `*(param_1 + 0x14) & 0x3000000 == 0x2000000`, returning error `900` if busy, else `0`. Called from `FUN_600cf0ca`. | 1 caller / 0 callees |
| `0x600ceff2` | 216 | Hardware / I2C | **`i2c_clock_divisor_calc`** — I2C baud rate & clock prescaler calculator: iterates clock prescaler (1..32) and power-of-2 divisors (up to 128) to compute optimal clock divider for target baud rate `param_3`. | 1 caller / 0 callees |
| `0x600cf0ca` | 232 | Hardware / I2C | **`i2c_transfer_submit`** — I2C master transaction submitter: verifies bus state via `FUN_600cefde`, formats 16-bit packet control words (`*(param_2 + 8) = ... | 0x400`), configures mode flags, and arms peripheral registers. ⚠️ *(QA session 53/54)* ~~the decomp body carries an `extraout_r2` artifact... call-site parameter/return-width mismatch~~ **root cause now identified, QA session 54**: Session 54's `FixSignatures.java` change (typing `0x600cefde`) did not fix this — it only changed the artifact's shape from a fabricated 64-bit split return to `extraout_r1`/`extraout_r2`, still wrong. A full disassembly of this function's real 232 bytes this session shows the actual cause: **this function genuinely takes a 3rd parameter** (entry-time `r2`, a source struct pointer) that isn't declared in the current 2-parameter signature. Confirmed via three independent facts: (1) `FUN_600cefde`'s own real body (verified via disassembly) touches only `r0`/`r3`, so `r1`/`r2` survive the `bl` call to it unchanged; (2) the raw instructions right after the call are a genuine 24-byte struct copy (`ldm r5!,{r0,r1,r2,r3}` then `ldm.w r5,{r0,r1}`, `stm.w ip!`) reading from r5 (seeded from `mov r5, r2` — the undeclared 3rd parameter) and writing into `param_2+0x18`; (3) `extraout_r1` in the current decomp is really just `param_2` (r1) read a second time, still numerically live because `FUN_600cefde` never touched it — not genuine "extra output" from the callee. ~~**GHIDRA-TODO: add the missing 3rd parameter to `FUN_600cf0ca`'s own signature**~~ ⚠️ **applied but insufficient, QA session 55, downgrading to accepted limitation**: Session 55 did add the 3rd parameter (now typed `src_struct`) exactly as recommended — but it's declared and then **never referenced anywhere in the function body**; the `extraout_r1`/`extraout_r2` tokens are still there, unchanged. Root cause: this isn't a signature problem at all, it's Ghidra's decompiler conservatively treating `r1`/`r2` as clobbered-by-default across the `bl FUN_600cefde` call site (correct per AAPCS in general — r0-r3 are caller-saved — even though *this specific* callee happens not to touch them, which Ghidra's decompiler has no general way to know without deeper interprocedural analysis). Signature-typing the caller can't fix a per-call-site liveness assumption. Three sessions (53-55) have now been spent on this one function; recommend treating it as a documented, understood limitation rather than filing further `GHIDRA-TODO`s — the informal mapping (`extraout_r1` = `param_2`, `extraout_r2` = `src_struct`) is now written down here for anyone reading the raw decomp file. The row's general identity/shape claim still stands; only the specific `extraout_`-derived field accesses are unreliable. | 0 callers / 1 callee |
| `0x600cf1b2` |  52 | Hardware / I2C | **`i2c_rx_buffer_fill`** — I2C receive FIFO drain: copies `param_3` bytes into buffer `param_2` from FIFO register `param_1 + 0x1c`, applying 7-bit mask `& 0x7f` if parity/framing flag set. | 0 callers / 0 callees |
| `0x600cf1e6` |  26 | Utility / Buffer | **`ring_buffer_avail_bytes`** — Ring buffer available byte query: calculates byte capacity `uVar2 - uVar1` between read index `param_2 + 0x20` and write index `param_2 + 0x22`. Called from `FUN_600cf2be`. | 1 caller / 0 callees |
| `0x600cf200` |  36 | BLE / GATT Stream | **`gatt_channel_ctx_init`** — GATT stream channel context initializer: sets default baud/timeout constant `0x1c200` and zeroes 18-byte context structure. Called from `FUN_6006e854` and `FUN_600ce780`. | 2 callers / 0 callees |
| `0x600cf224` |  16 | Hardware / Serial | **`uart_status_flags_get`** — Serial peripheral status query: combines status word `*(param_1 + 0x28) >> 16 & 0xc3` with control word `*(param_1 + 0x14)`. Called from `FUN_60053b50`. | 1 caller / 0 callees |
| `0x600cf234` |  18 | BLE / GATT Stream | **`gatt_rx_stream_start`** — GATT stream receive starter: sets buffer pointer `param_3`, length `param_4`, clears indices, and signals event `0x8200000` via `FUN_60053864`. Called from `FUN_6006e854`. | 1 caller / 1 callee |
| `0x600cf246` |  32 | BLE / GATT Stream | **`gatt_rx_stream_stop`** — GATT stream receive terminator: clears stream pointers/indices and clears event `0x8200000` via `FUN_600538b4`. Called from `FUN_6006e9b0` and `FUN_6006eb00`. | 2 callers / 1 callee |
| `0x600cf266` |  44 | BLE / GATT Stream | **`gatt_tx_req_dispatch`** — GATT transmit request dispatcher: checks active tx state (`param_2[0xb] == 1`), copies buffer descriptors, sets active state `1`, and signals event `0x800000` via `FUN_60053864`. Called from `FUN_6006ea44` and `FUN_600ce744`. | 2 callers / 1 callee |
| `0x600cf292` |  22 | BLE / GATT Stream | **`gatt_tx_abort`** — GATT transmit abort handler: clears event `0xc00000` via `FUN_600538b4`, zeroes length and state flag `param_2 + 0x2c`. Called from `FUN_6006ea44` and `FUN_600ce780`. | 2 callers / 1 callee |
| `0x600cf2a8` |  22 | BLE / GATT Stream | **`gatt_tx_remaining_get`** — GATT transmit remaining bytes query: returns `param_2[8] - param_2[4]` if active, else returns error `6`. | 0 callers / 0 callees |
| `0x600cf2be` | 208 | BLE / GATT Stream | **`gatt_rx_data_read`** — GATT receive buffer drain & callback processor: reads incoming bytes from ring buffer `param_2 + 0x18`, copies into target buffer `*param_3`, advances ring index `param_2 + 0x22`, and invokes completion callback `*(param_2 + 0x24)`. Called from `FUN_6006eb00` and `FUN_600ce708`. | 2 callers / 3 callees |
| `0x600cf38e` |  28 | BLE / GATT Stream | **`gatt_rx_abort`** — GATT receive abort handler: clears event `0x8300000` via `FUN_600538b4`, zeroes remaining length and sets state byte `param_2 + 0x2d = 2`. Called from `FUN_6006eb00` and `FUN_600ce780`. | 2 callers / 1 callee |
| `0x600cf3aa` |  24 | BLE / GATT Stream | **`gatt_rx_remaining_get`** — GATT receive remaining bytes query: returns `param_2[0x14] - param_2[0x10]` if active, else returns error `6`. | 0 callers / 0 callees |
| `0x600cf3c2` |  28 | BLE / Link Layer | **`ble_channel_map_clear`** — BLE channel map initializer: zeroes 12-byte channel configuration structure. Called from `FUN_600d4a7e`. | 1 caller / 0 callees |
| `0x600cf548` | 210 | Audio / Haptic | **`audio_gain_curve_calc`** — Audio / haptic gain envelope calculator: computes 16-bit gain curve envelopes and duty cycles scaled by percentage `param_5` (`0..100%`) across 4 shaping modes (`0..3`), writing results into `param_1 + param_2 * 0x60 + 0x12..0x1e`. Called from `FUN_600d4c3a` and `FUN_600d4cae`. | 2 callers / 0 callees |
| `0x600cf61e` |  16 | Hardware / DMA | **`dma_ring_buffer_init_mode0`** — DMA ring buffer mode 0 descriptor initializer: sets mode byte `param_1[3]=1`, zeroes fields `0,1,2,4`. Called from `FUN_60060594`. | 1 caller / 0 callees |
| `0x600cf62e` |  16 | Hardware / DMA | **`dma_ring_buffer_init_mode1`** — DMA ring buffer mode 1 descriptor initializer: sets mode bytes `param_1[1]=1, param_1[3]=1`, zeroes fields `0,2,4`. Called from `FUN_60060668`. | 1 caller / 0 callees |
| `0x600cf63e` |  32 | Hardware / DMA | **`dma_channel_priority_config`** — DMA channel priority & control register configurator: sets bit 31 (`0x80000000`) and channel priority mask `0x40000` in control registers `*(param_1 + 8)` and `*(param_1 + 0x88)`. Called from `FUN_600cf8de` and `FUN_600cfa22`. | 2 callers / 0 callees |

## Session 54 (Wave 24) — SAI Audio Interface, SRTC Driver & Bluetooth Packet Dispatcher (20 functions, 1,526 bytes)

Added `0x600cefde` signature typing in `FixSignatures.java`, plus decompiled and documented 20 functions (1,526 bytes across `0x600cf65e`–`0x600cfc8e`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600cf65e` | 158 | Audio / SAI | **`sai_rx_config`** — Synchronous Audio Interface (SAI) receiver hardware channel configurator: computes frame synchronization divider `(param_4 / uVar5 >> 1) - 1`, word length, and slot masks for SAI RX registers `param_1 + 0x10, 0x14, 0x18, 0x1c, 0x60`. Called from `FUN_600cf876`. | 1 caller / 0 callees |
| `0x600cf6fc` | 186 | Audio / SAI | **`sai_tx_config`** — SAI transmitter hardware channel configurator: computes frame sync divider, slot mask, and data format for SAI TX registers `param_1 + 0x8c, 0x90, 0x94, 0x98, 0x9c, 0xe0`. Called from `FUN_600cf8aa`. | 1 caller / 0 callees |
| `0x600cf7b6` |  94 | Audio / SAI | **`sai_rx_dma_cback`** — SAI receiver DMA completion callback: advances RX queue index `param_2[1] + 0xe5`, invokes stream callback `*(iVar3 + 0xc)(..., 0x771)`, and disables DMA channel via `FUN_600ced08`. | 0 callers / 1 callee |
| `0x600cf814` |  98 | Audio / SAI | **`sai_tx_dma_cback`** — SAI transmitter DMA completion callback: advances TX queue index `param_2[1] + 0xe5`, invokes stream callback `*(iVar3 + 0xc)(..., 0x772)`, and disables DMA channel via `FUN_600ced08`. | 0 callers / 1 callee |
| `0x600cf876` |  52 | Audio / SAI | **`sai_rx_init`** — SAI receiver initialization wrapper: delegates to `FUN_600cf65e`, configures word length `*(param_2 + 5) = uVar1`, and clears FIFO bits in control register `*(param_1 + 0x14)`. Called from `sai__600605dc`. | 1 caller / 1 callee |
| `0x600cf8aa` |  52 | Audio / SAI | **`sai_tx_init`** — SAI transmitter initialization wrapper: delegates to `FUN_600cf6fc`, configures word length `*(param_2 + 5) = uVar1`, and clears FIFO bits in control register `*(param_1 + 0x94)`. Called from `sai__600606b0`. | 1 caller / 1 callee |
| `0x600cf8de` | 232 | Audio / SAI | **`sai_tx_dma_transfer_start`** — SAI TX DMA transfer initiator: sets up 24-byte DMA descriptor on stack, configures channel descriptor via `FUN_600cec26`, loads DMA hardware via `thunk_EXT_FUN_000083ec`, enables IRQ via `FUN_600cecb6`, and sets channel priority via `FUN_600cf63e(param_1, 1)`. | 0 callers / 5 callees |
| `0x600cf9c6` |  92 | Audio / SAI | **`sai_rx_stop`** — SAI receiver stop handler: halts DMA channel via `FUN_600ced08(*param_2)`, clears control register flags `*(param_1 + 0x14)`, and disables peripheral via `thunk_EXT_FUN_0000851a`. Called from `sai__60060634`. | 1 caller / 2 callees |
| `0x600cfa22` | 108 | Audio / SAI | **`sai_tx_stop`** — SAI transmitter stop handler: halts DMA channel via `FUN_600ced08(*param_2)`, resets priority via `FUN_600cf63e(param_1, 0)`, and disables TX control registers. Called from `sai__60060708`. | 1 caller / 2 callees |
| `0x600cfafe` |  20 | Hardware / SRTC | **`srtc_alarm_status_get`** — Secure Real-Time Clock (SRTC) alarm status query: parses alarm flags from control word `*(param_1 + 0x14)`. Called from `FUN_600607b8`. | 1 caller / 0 callees |
| `0x600cfb2c` |   8 | Hardware / SRTC | **`srtc_time_zero`** — SRTC timestamp zeroer: clears 8-byte time structure (`*param_1 = 0, *(param_1 + 4) = 0`). Called from `srtc__60060804`. | 1 caller / 0 callees |
| `0x600cfb34` |  14 | Hardware / SRTC | **`srtc_tamper_flag_get`** — SRTC tamper detection flag query: checks tamper latch bit `*(param_1 + 0x4c) & 1` (returns `4` if set, else `0`). Called from `FUN_600607b8`. | 1 caller / 0 callees |
| `0x600cfb42` |  14 | Hardware / SRTC | **`srtc_tamper_flag_set`** — SRTC tamper status setter: sets bit 0 in control register `*(param_1 + 0x4c) |= 1`. Called from `srtc__60060804`. | 2 callers / 0 callees |
| `0x600cfb50` |  14 | Hardware / SRTC | **`srtc_interrupt_enable`** — SRTC interrupt enable: sets bit 1 in control register `*(param_1 + 0x38) |= 2`. Called from `FUN_60060910`. | 1 caller / 0 callees |
| `0x600cfb5e` |  14 | Hardware / SRTC | **`srtc_interrupt_disable`** — SRTC interrupt disable: clears bit 1 in control register `*(param_1 + 0x38) &= ~2`. Called from `FUN_60060940`. | 1 caller / 0 callees |
| `0x600cfb82` | 116 | Hardware / XBARA | **`xbara_fifo_read_bytes`** — Crossbar Switch (XBARA) / hardware FIFO read utility: polls FIFO status bit `0x15`, reads up to `param_3` bytes in 4-byte chunks from data register array `param_1[uVar3 + 0x10]`. Called from `xbara__600cbdc8` and `FUN_60091d50`. | 3 callers / 0 callees |
| `0x600cfc34` |  30 | Bluetooth / Events | **`bt_event_cback_notify_1`** — Bluetooth event notification helper 1: clears flag `param_3 + 0x1b`, invokes callback `(*callback)(param_3, 1, param_2)`. Called from `FUN_600cfc8e`. | 1 caller / 0 callees |
| `0x600cfc52` |  30 | Bluetooth / Events | **`bt_event_cback_notify_2`** — Bluetooth event notification helper 2: clears flag `param_3 + 0x1d`, invokes callback `(*callback)(param_3, 2, param_2)`. Called from `FUN_600cfc8e`. | 1 caller / 0 callees |
| `0x600cfc70` |  30 | Bluetooth / Events | **`bt_event_cback_notify_3`** — Bluetooth event notification helper 3: clears flag `param_3 + 0x1c`, invokes callback `(*callback)(param_3, 3, param_2)`. Called from `FUN_600cfc8e`. | 1 caller / 0 callees |
| `0x600cfc8e` | 164 | Bluetooth / Events | **`bt_packet_dispatcher`** — Bluetooth packet event dispatcher: walks packet header array `*param_2`, parses packet type descriptors via `FUN_600d10f6`, and dispatches corresponding notification handlers `FUN_600cfc34`, `FUN_600cfc52`, `FUN_600cfc70`. Called from `FUN_600d0332` and `FUN_600d0590`. | 2 callers / 4 callees |

## Session 55 (Wave 25) — USB Audio, USB CDC-ACM, USB HID Class & Endpoint State Engines (20 functions, 1,370 bytes)

Resolved Session 54 QA finding by adding 3-parameter signature typing to `0x600cf0ca` in `FixSignatures.java`, plus decompiled and documented 20 functions (1,370 bytes across `0x600cfe6a`–`0x600d0e38`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600cfe6a` |  46 | USB / Core | **`usb_ep_queue_cancel_single`** — USB endpoint queue cancel helper: walks queue `param_1[2]` and aborts all pending descriptors via `FUN_600d10f6`. Called from `FUN_600d0332` and `FUN_600d0590`. | 2 callers / 1 callee |
| `0x600d0590` |  80 | USB / Audio | **`usb_audio_endpoints_reset`** — USB Audio Class endpoints reset: cancels transfer queues on endpoint descriptors `param_1[3]` and `param_1[4]`, flushes buffers via `FUN_600cfe6a`, and enters critical section `thunk_EXT_FUN_00008802` to clear state bytes. Note *(QA session 55)*: this row's own header lists 4 callees, but the prose only names 2 (`FUN_600cfe6a`, `thunk_EXT_FUN_00008802`) — the other two are `FUN_600d15e8` and, notably, `FUN_600cfc8e` (session 54's `bt_packet_dispatcher`). This function **is** the `FUN_600d0590` that session 54's own doc row already listed as one of `bt_packet_dispatcher`'s 2 callers — i.e. a USB Audio function is a confirmed real caller of the "BT" dispatcher. Not a correction (nothing here is factually wrong), but a scope flag: `bt_packet_dispatcher`'s `bt_` prefix may overstate how Bluetooth-specific that function actually is — it looks more like a generic class-driver event/notification dispatcher shared across BT and USB Audio, worth reconsidering if it comes up again. | 0 callers / 4 callees |
| `0x600d05e0` |  34 | USB / Audio | **`usb_audio_stream_ep_recv_enable`** — USB Audio stream endpoint receive enable: sets active flag `param_1 + 0x1b = 1` and arms endpoint via `FUN_600d1090`. Called from `usb_device_audio__60061ed4`. | 1 caller / 1 callee |
| `0x600d0602` |  34 | USB / Audio | **`usb_audio_stream_ep_send_enable`** — USB Audio stream endpoint transmit enable: sets active flag `param_1 + 0x1d = 1` and arms endpoint via `FUN_600d1090`. Called from `usb_device_audio__60061fc0`. | 1 caller / 1 callee |
| `0x600d0624` |  52 | USB / Audio | **`usb_audio_stream_ep_disable`** — USB Audio stream endpoint disable: enters critical section `thunk_EXT_FUN_00008802`, disables endpoint via `FUN_600d10a4`, and clears active flag `param_1 + 7`. Called from `usb_device_audio__600620b4`. | 1 caller / 3 callees |
| `0x600d0658` |  34 | USB / Audio | **`usb_audio_stream_ep_cancel`** — USB Audio stream endpoint cancel: sets cancel flag `param_1 + 7 = 1` and cancels endpoint via `FUN_600d109c`. Called from `FUN_600d52f0`. | 1 caller / 1 callee |
| `0x600d06d6` |  78 | USB / CDC-ACM | **`usb_cdc_ep_queues_cancel`** — USB CDC-ACM dual endpoint queue cancel: walks and cancels pending transfer descriptor queues on endpoints `param_1[2]` and `param_1[3]` via `FUN_600d10f6`. Called from `usb_device_cdc_acm__60054a54` and `usb_device_cdc_acm__60054d08`. | 2 callers / 1 callee |
| `0x600d0724` | 108 | USB / CDC-ACM | **`usb_cdc_ep_recv_start`** — USB CDC-ACM endpoint receive start: verifies endpoint index matching `param_1 + 5` or `param_1 + 9`, enters critical section, arms endpoint via `FUN_600d1090`, and sets active flag. | 0 callers / 3 callees |
| `0x600d0790` |  68 | USB / CDC-ACM | **`usb_cdc_ep_send_start`** — USB CDC-ACM endpoint transmit start: enters critical section, arms endpoint transmit via `FUN_600d109c`, and sets active flag `param_1 + 0x1d = 1`. | 0 callers / 3 callees |
| `0x600d07d4` | 192 | USB / Class | **`usb_class_req_parse_dispatch`** — USB Audio / Class request parser & dispatcher: parses setup packet request types (`GET_CUR`, `SET_CUR`, `GET_MIN`, `GET_MAX`, etc.), maps request opcodes (`0x11`, `0x21`), and delegates to `FUN_600d0bc8`. | 0 callers / 2 callees |
| `0x600d0894` |  84 | USB / Class | **`usb_class_control_transfer_cback`** — USB class control endpoint transfer callback: handles setup packet stage transitions via `FUN_600d1178` and `FUN_600d11ba`. | 0 callers / 2 callees |
| `0x600d09c4` | 138 | USB / Class | **`usb_class_req_handler_get`** — USB class request entity handler query: looks up control request entity ID `*param_2 & 0x1f` via `FUN_600d1178`. | 0 callers / 1 callee |
| `0x600d0a4e` |  66 | USB / Class | **`usb_class_req_unit_config`** — USB class request unit configuration handler: queries status via `FUN_600d1178`, configures audio unit descriptor via `FUN_6005505c`, and notifies class driver via `FUN_600d0bc8`. | 0 callers / 3 callees |
| `0x600d0a90` |  58 | USB / Class | **`usb_class_req_notify`** — USB class request entity notification: queries setup request via `FUN_600d1178` and dispatches notification `0x16` via `FUN_600d0bc8`. | 0 callers / 2 callees |
| `0x600d0b60` | 104 | USB / CDC-ACM | **`usb_cdc_acm_line_state_cback`** — USB CDC-ACM line state callback: decodes line coding request (`param_3 == 5`), updates baud rate / framing flags via `FUN_600d1134`, or receives line status data via `FUN_600d1090`. | 0 callers / 3 callees |
| `0x600d0bc8` |  56 | USB / Class | **`usb_class_entity_cback_dispatch`** — USB class entity callback dispatcher: looks up class handler descriptor via `FUN_60054f7c`, executes state transition callbacks (`FUN_60054f30`, `FUN_6005505c`), and invokes class handler function pointer `*(handler + 4)`. | 3 callers / 3 callees |
| `0x600d0c3c` |  46 | USB / Core | **`usb_ep_queue_cancel_all`** — USB endpoint transfer queue abort helper: walks queue `param_1[2]` and aborts all pending descriptors via `FUN_600d10f6`. Called from `FUN_600d0dfc` and `FUN_600d0c6a`. | 2 callers / 1 callee |
| `0x600d0dfc` |  26 | USB / HID | **`usb_hid_endpoints_reset`** — USB HID class endpoint reset: flushes pending transfer queues via `FUN_600d0c3c` and zeroes 16-byte state structure. Called from `FUN_600551b8`. | 1 caller / 1 callee |
| `0x600d0e16` |  34 | USB / HID | **`usb_hid_ep_recv_start`** — USB HID endpoint receive start: sets active flag `param_1 + 0x11 = 1` and arms receive endpoint via `FUN_600d1090`. | 0 callers / 1 callee |
| `0x600d0e38` |  32 | USB / HID | **`usb_hid_ep_send_start`** — USB HID endpoint transmit start: arms transmit endpoint via `FUN_600d109c` and sets active flag `param_1 + 0x12 = 1`. | 0 callers / 1 callee |

## Session 56 (Wave 26) — USB Low-Level Controller IOCTL Engine, Heap Memory Drivers & Event Thunks (20 functions, 950 bytes)

Decompiled and documented 20 functions (950 bytes across `0x600d0e58`–`0x600d15e4`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d0e58` | 110 | USB / HID | **`usb_hid_report_desc_parse`** — USB HID report descriptor parser: validates report descriptor length, initializes input/output report lengths, and configures report structure `param_1 + 3..param_1 + 6`. | 1 caller / 0 callees |
| `0x600d0ede` |  20 | USB / Controller | **`usb_driver_ioctl_dispatch`** — USB low-level controller IOCTL dispatcher: validates controller context `param_1` and invokes driver IOCTL function pointer `*(param_1 + 8)`. | 9 callers / 0 callees |
| `0x600d0ef2` |  34 | USB / Controller | **`usb_driver_init`** — USB low-level controller driver initializer: sets initialized flag `param_1 + 0x10 = 1` and dispatches IOCTL opcode 0 via `FUN_600d0ede`. | 2 callers / 2 callees |
| `0x600d0f14` | 162 | USB / Controller | **`usb_driver_endpoint_open`** — USB controller endpoint open handler: calculates endpoint index `((param_2 >> 7) | (param_2 & 0xf) << 1) * 0xc`, configures packet size / transfer type, and invokes IOCTL opcode 1. | 2 callers / 4 callees |
| `0x600d0fb6` | 168 | USB / Controller | **`usb_driver_transfer_submit`** — USB controller transfer submit: arms endpoint transfer slot `param_1 + index * 0xc` with buffer descriptor and length `param_3[1]`, then triggers IOCTL opcode 2. | 2 callers / 1 callee |
| `0x600d105e` |   8 | USB / Controller | **`usb_driver_device_handle_get`** — USB controller device handle getter: returns `*(param_1 + 4)`. | 2 callers / 1 callee |
| `0x600d1066` |   8 | USB / Controller | **`usb_driver_device_handle_set`** — USB controller device handle setter: stores `*(param_1 + 4) = param_2`. | 2 callers / 1 callee |
| `0x600d106e` |  34 | USB / Controller | **`usb_driver_deinit`** — USB controller driver deinitializer: invokes IOCTL opcode 0x13 and clears initialization state `param_1 + 0x10 = 0`. | 3 callers / 1 callee |
| `0x600d1090` |  12 | USB / Controller | **`usb_driver_ep_recv_enable`** — USB controller endpoint receive enable: dispatches IOCTL opcode 0x14 via `FUN_600d0ede`. | 6 callers / 1 callee |
| `0x600d109c` |   8 | USB / Controller | **`usb_driver_ep_send_enable`** — USB controller endpoint transmit enable: dispatches IOCTL opcode 0x15 via `FUN_600d0ede`. | 5 callers / 1 callee |
| `0x600d10a4` |  20 | USB / Controller | **`usb_driver_ep_disable`** — USB controller endpoint disable: dispatches IOCTL opcode 0x16 via `FUN_600d0ede`. | 2 callers / 0 callees |
| `0x600d10b8` |  62 | USB / Controller | **`usb_driver_endpoint_close`** — USB controller endpoint close: zeroes endpoint slot descriptor and dispatches IOCTL opcode 3 via `FUN_600d0ede`. | 5 callers / 1 callee |
| `0x600d10f6` |  62 | USB / Controller | **`usb_driver_transfer_cancel`** — USB controller transfer cancel: dispatches IOCTL opcode 3 and resets endpoint buffer descriptors. | 5 callers / 1 callee |
| `0x600d1134` |  34 | USB / Controller | **`usb_driver_ep_stall_set`** — USB controller endpoint STALL setter: dispatches IOCTL opcode 4 via `FUN_600d0ede`. | 4 callers / 1 callee |
| `0x600d1156` |  34 | USB / Controller | **`usb_driver_ep_stall_clear`** — USB controller endpoint STALL clearer: dispatches IOCTL opcode 5 via `FUN_600d0ede`. | 3 callers / 1 callee |
| `0x600d1178` |  58 | USB / Controller | **`usb_driver_param_get`** — USB controller parameter query: maps query selector (2..8) to controller property query opcode or reads state byte `*(param_1 + 0xcc/0xce)`. | 5 callers / 1 callee |
| `0x600d11ba` |  80 | USB / Controller | **`usb_driver_param_set`** — USB controller parameter setter: maps configuration selector (1..14) to controller configuration opcode or writes state byte. | 1 caller / 1 callee |
| `0x600d15c4` |   4 | Memory / Heap | **`private_heap_free`** (`private_heap__600835ac`) — Private heap memory block free thunk: deallocates dynamic memory block and coalesces adjacent heap chunks. This row's identity claim is correct and disassembly-confirmed (`b.w 0x600835ac`, a genuine 4-byte tail-call trampoline into the established `private_heap.cc` coalescing logic). ⚠️ **file-integrity bug, found and fixed QA session 56**: writing this function's decompile **overwrote and corrupted the pre-existing, already-attributed `analysis/decomp/private_heap__600835ac.c`** — the classic thunk-pseudocode-bleed artifact (Ghidra rendered the tail-call target `0x600835ac`'s full 194-byte body when decompiling this 4-byte thunk) collided by name with the real, established `private_heap__600835ac.c` file and clobbered its header (wrong address `0x600d15c4`, wrong size `4`, lost `src: private_heap.cc` attribution, lost its real 4-callee list) while leaving the body — which is genuinely `0x600835ac`'s content — unchanged. This caused `bruce-decompile-status.md`'s regeneration to regress `private_heap.cc` from 3/3 (complete since session 25/26) to 2/3. **Restored `private_heap__600835ac.c`'s header directly** (byte-identical to its pre-session-56 state, verified via `git diff`) since the body was already correct and this didn't require Ghidra. **GHIDRA-TODO: decompile the *actual* 4-byte thunk at `0x600d15c4` into its own file under a name that can't collide with `private_heap__600835ac`** (e.g. `thunk_private_heap_free__600d15c4.c`) — this row's 6-caller list is real and belongs to that thunk, not to `0x600835ac`. | 6 callers / 0 callees |
| `0x600d15c8` |  28 | Memory / Heap | **`private_heap_calloc`** — Private heap zeroed allocation helper: allocates memory via `thunk_EXT_FUN_00007f58` and zeroes `param_1` bytes. | 6 callers / 1 callee |
| `0x600d15e4` |   4 | USB / Host | **`usb_host_event_notify_thunk`** (`thunk_EXT_FUN_000080d8`) — USB host/peripheral event notification thunk: indirect jump via function pointer `DAT_6013d184`. | 11 callers / 0 callees |

## Session 57 (Wave 27) — USB Synchronization, Hardware Registers & USB Host Audio Pipeline (20 functions, 976 bytes)

Resolved Session 56 GHIDRA-TODO by updating `Decompile.java` to format thunk filenames as `thunk_<name>__<addr>.c` (preventing collisions with attributed target source files), plus decompiled and documented 20 functions (976 bytes across `0x600d15c4`–`0x600d1ba0`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d15c4` |   4 | Memory / Heap | **`private_heap_free`** (`thunk_private_heap__600835ac__600d15c4`) — Private heap free tail-call thunk: branches to `private_heap__600835ac` (`b.w 0x600835ac`). | 6 callers / 0 callees |
| `0x600d15e8` |  16 | Kernel / Critical | **`critical_section_exit`** — Interrupt & critical section restore helper: restores interrupt base priority `setBasePriority(param_1)` if in ISR, else exits critical section via `thunk_EXT_FUN_00007dac`. | 19 callers / 1 callee |
| `0x600d15f8` |  46 | USB / Events | **`usb_event_group_clear`** — USB event group reset: signals event group via `event_groups__600c9d88`, enters critical section `thunk_EXT_FUN_00008802`, and clears state byte `param_1[10] = 0`. Called from `FUN_600d2d94`. | 1 caller / 3 callees |
| `0x600d1626` |  60 | USB / Events | **`usb_event_wait_timeout`** — USB event wait with millisecond timeout: calls OS event wait `thunk_EXT_FUN_00006820(*param_1, param_2, ..., timeout_ms)`. | 0 callers / 1 callee |
| `0x600d1662` |  44 | USB / Mutex | **`usb_mutex_release`** — USB mutex release & state clear: unlocks mutex `thunk_EXT_FUN_00007018(*param_1)`, enters critical section, and clears active flag `param_1 + 0x15 = 0`. | 0 callers / 3 callees |
| `0x600d168e` |   4 | USB / Mutex | **`usb_mutex_release_thunk`** (`thunk_FUN_600d1662`) — USB mutex release thunk: tail-call to `FUN_600d1662`. Called from `usb_device_cdc_acm__60054d08` and others. | 6 callers / 0 callees |
| `0x600d1692` |  28 | USB / Queue | **`usb_msg_queue_post`** — USB message queue post: posts message pointer `param_3` to queue `queue__600c9eac(*param_1, 0xffffffff, ...)`. | 19 callers / 1 callee |
| `0x600d16ae` |  22 | USB / Queue | **`usb_msg_queue_fetch`** — USB message queue fetch: receives message from queue `queue__600c9e6c(*param_1)`. | 19 callers / 1 callee |
| `0x600d16c4` | 102 | USB / Hardware | **`usb_hardware_endpoint_config`** — USB hardware endpoint register configurator: sets MMIO register `*(0x400d81b4 + (param_1 - 2) * 0x60) = 0x180000`, sets control flags `0x4000 | 0x8000`, and packs endpoint address and direction. Called from `usb_device__60060ccc`. | 1 caller / 1 callee |
| `0x600d172a` |  28 | USB / Hardware | **`usb_hardware_remote_wakeup_set`** — USB hardware remote wakeup enable/disable: updates control register bit 1 `*(iVar1 + 0x30)`. | 0 callers / 1 callee |
| `0x600d1746` |  40 | USB / Host Audio | **`usb_host_audio_control_cback`** — USB Host Audio control transfer completion callback: clears state `param_1[0x17] = 0`, invokes client callback `*(param_1[0x15])(...)`, and frees buffer via `FUN_600d3386`. | 0 callers / 1 callee |
| `0x600d176e` |  32 | USB / Host Audio | **`usb_host_audio_stream_in_cback`** — USB Host Audio stream IN transfer callback: invokes callback `*(param_1[0xc])(...)` and frees buffer via `FUN_600d3386`. | 0 callers / 1 callee |
| `0x600d178e` |  32 | USB / Host Audio | **`usb_host_audio_stream_out_cback`** — USB Host Audio stream OUT transfer callback: invokes callback `*(param_1[0xe])(...)` and frees buffer via `FUN_600d3386`. | 0 callers / 1 callee |
| `0x600d18d2` |  56 | USB / Host Audio | **`usb_audio_desc_search_interface`** — USB Audio descriptor interface iterator: parses standard descriptor chain `*param_1` looking for interface descriptor type `4` and matching interface number `*param_3`. Called from `FUN_600d19ea` and `FUN_600d1a62`. | 2 callers / 0 callees |
| `0x600d190a` |  64 | USB / Host Audio | **`usb_host_audio_instance_alloc`** — USB Host Audio instance allocator: allocates 104-byte structure `FUN_600d15c8(0x68)` and registers pipe handlers via `FUN_600d33b2`. | 0 callers / 2 callees |
| `0x600d194a` | 132 | USB / Host Audio | **`usb_host_audio_device_close`** — USB Host Audio device close: aborts pending audio streams via `FUN_600d332a` / `FUN_600d3256`, unbinds interfaces via `FUN_600d26ea`, and notifies host stack via `thunk_EXT_FUN_000080d8`. Called from `usb_host_audio__6006318c`. | 1 caller / 5 callees |
| `0x600d19ce` |  28 | USB / Host Audio | **`usb_host_audio_sample_rate_get`** — USB Host Audio sample rate query: returns 16-bit sample rate `param_1 + 0x60` (channel 1) or `param_1 + 0x62` (channel 2). Called from `usb_host_audio__6006318c`. | 1 caller / 0 callees |
| `0x600d19ea` | 120 | USB / Host Audio | **`usb_host_audio_unit_find`** — USB Host Audio unit finder: searches audio topology descriptors `param_1 + 0x34` for matching unit ID `param_2` via `FUN_600d18d2`. Called from `usb_host_audio_topology__60063e24`. | 3 callers / 1 callee |
| `0x600d1a62` |  58 | USB / Host Audio | **`usb_host_audio_num_channels_get`** — USB Host Audio channel count query: iterates audio topology descriptor chain up to 10 iterations to count active channels. Called from `usb_host_audio_topology__600644dc`. | 1 caller / 1 callee |
| `0x600d1ba0` |  60 | USB / Host Audio | **`usb_host_audio_feature_unit_req`** — USB Host Audio Feature Unit request submitter: formats class-specific control request `0xa1` (GET_CUR/SET_CUR) with entity ID and dispatches via `FUN_600558b8`. Called from `usb_host_audio__6006318c`. | 1 caller / 1 callee |

## Session 58 (Wave 28) — USB Host Audio Control, CDC-ACM Pipes & HID Host Pipeline (20 functions, 1,412 bytes)

Decompiled and documented 20 functions (1,412 bytes across `0x600d1bdc`–`0x600d2140`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d1bdc` |  60 | USB / Host Audio | **`usb_host_audio_sampling_freq_req`** — USB Host Audio sampling frequency control request: formats control request `0x22` (GET_CUR/SET_CUR for endpoint) with frequency value and dispatches via `FUN_600558b8`. Called from `usb_host_audio__6006318c`. | 2 callers / 1 callee |
| `0x600d1c18` |  58 | USB / Host Audio | **`usb_host_audio_control_req_submit`** — USB Host Audio control request submitter: formats setup packet with request type `0x21` and dispatches via `FUN_600558b8`. Called from `usb_host_audio__6006318c`. | 1 caller / 1 callee |
| `0x600d1c52` |  58 | USB / Host Audio | **`usb_host_audio_stream_req_submit`** — USB Host Audio stream endpoint request submitter: formats setup packet with request type `0x22` and dispatches via `FUN_600558b8`. Called from `usb_host_audio__6006318c`. | 1 caller / 1 callee |
| `0x600d1c8c` | 154 | USB / Host Audio | **`usb_host_audio_topology_resolve`** — USB Host Audio topology descriptor parser: searches input terminal, feature unit, and output terminal descriptors via `FUN_600d19ea`, checks channel configuration, and resolves terminal audio properties. | 1 caller / 1 callee |
| `0x600d1d26` |  32 | USB / Host CDC | **`usb_host_cdc_serial_state_cback`** — USB Host CDC-ACM serial state notification callback: invokes registered callback `*(param_1 + 0x14)(..., param_3)` and frees buffer via `FUN_600d3386`. | 0 callers / 1 callee |
| `0x600d1d46` |  32 | USB / Host CDC | **`usb_host_cdc_data_in_cback`** — USB Host CDC-ACM data IN callback: invokes client callback `*(param_1 + 0x18)(..., param_3)` and frees buffer via `FUN_600d3386`. | 0 callers / 1 callee |
| `0x600d1d66` |  36 | USB / Host CDC | **`usb_host_cdc_data_out_cback`** — USB Host CDC-ACM data OUT callback: clears state `param_1 + 0x1c = 0`, invokes client callback `*(param_1 + 0x20)(..., param_3)`, and frees buffer via `FUN_600d3386`. | 0 callers / 1 callee |
| `0x600d1d8a` | 236 | USB / Host CDC | **`usb_host_cdc_stream_open`** — USB Host CDC-ACM stream open & pipe configurator: allocates ~~bulk IN and bulk OUT~~ ⚠️ **transfer-type claim wrong, corrected QA session 58** transfer pipes via `FUN_600d3244` with 3000ms timeout, stores handle in `param_1 + 0x10`/`+0x14`, and notifies client. Disassembly-confirmed (`and r1,r1,#3; cmp r1,#3`, both branches) the endpoint-selection check is `bmAttributes & 3 == 3` — per USB 2.0 Table 9-13, transfer-type value `3` is **Interrupt**, not Bulk (`2`). This is directly contradicted by the *same wave's own* `usb_host_hid_interrupt_pipe_open` (`0x600d206c` below), which uses the byte-for-byte identical check and is correctly labeled "interrupt endpoint (`type 3`)". Real endpoint type is Interrupt; the specific CDC sub-role (why an ACM stream-open function would select interrupt-type endpoints, and what the two pipe slots `+0x10`/`+0x14` represent) is unconfirmed — flagged rather than guessed. | 1 caller / 2 callees |
| `0x600d1ea2` |  62 | USB / Host CDC | **`usb_host_cdc_instance_alloc`** — USB Host CDC-ACM instance allocator: allocates 76-byte context structure `FUN_600d15c8(0x4c)` and registers pipe handles via `FUN_600d33b2`. ⚠️ *(QA session 58, moderate-confidence flag)* this function's sole caller, per its own decomp header, is `usb_host_hid__600648b0` — an **HID**-attributed function, not CDC. Note also this row's own body actually allocates `0x38` (56) bytes, not `0x4c` (76) as stated — the byte-count claim appears to have been copied from `0x600d201e` (`usb_host_hid_instance_alloc`) below, a different, correctly-76-byte allocator. The other 3 HID-labeled functions in this wave (`0x600d201e`, `0x600d206c`, `0x600d2140`) share a common caller, `FUN_600563b8`, distinct from this one — suggesting this function may itself belong to the HID subsystem (a second, smaller HID sub-context) rather than CDC-ACM. Not corrected in place since the true identity isn't confirmed either way — flagged for the next wave to investigate rather than guessed. | 1 caller / 2 callees |
| `0x600d1ee0` | 100 | USB / Host CDC | **`usb_host_cdc_device_close`** — USB Host CDC-ACM device close: aborts pending bulk pipes via `FUN_600d332a` / `FUN_600d3256`, unbinds interfaces via `FUN_600569e4`, and notifies host stack via `thunk_EXT_FUN_000080d8`. | 1 caller / 4 callees |
| `0x600d1f44` |  20 | USB / Host HID | **`usb_host_hid_report_length_get`** — USB Host HID report length query: returns 16-bit report length `param_1 + 0x34` or `param_1 + 0x36` for HID interface. Called from `usb_host_hid__600649d4`. | 1 caller / 0 callees |
| `0x600d1f58` |  32 | USB / Host HID | **`usb_host_hid_get_report_desc_req`** — USB Host HID get report descriptor request: sends standard `GET_DESCRIPTOR` request (`0x81`, opcode 6, descriptor type `0x22`) via `FUN_60055cfc`. Called from `usb_host_hid__600649d4`. | 1 caller / 1 callee |
| `0x600d1f78` |  32 | USB / Host HID | **`usb_host_hid_set_idle_req`** — USB Host HID set idle request: sends class-specific `SET_IDLE` request (`0x21`, opcode 10) via `FUN_60055cfc`. Called from `usb_host_hid__600649d4`. | 1 caller / 1 callee |
| `0x600d1f98` |  30 | USB / Host HID | **`usb_host_hid_set_protocol_req`** — USB Host HID set protocol request: sends class-specific `SET_PROTOCOL` request (`0x21`, opcode 11) via `FUN_60055cfc`. Called from `usb_host_hid__600649d4`. | 1 caller / 1 callee |
| `0x600d1fb6` |  36 | USB / Host HID | **`usb_host_hid_set_report_req`** — USB Host HID set report request: sends class-specific `SET_REPORT` request (`0x21`, opcode 9) via `FUN_60055cfc`. Called from `usb_host_hid__600649d4`. | 1 caller / 1 callee |
| `0x600d1fda` |  32 | USB / Host HID | **`usb_host_hid_interrupt_in_cback`** — USB Host HID interrupt IN transfer callback: invokes client callback `*(param_1 + 0x20)(...)` and frees buffer via `FUN_600d3386`. | 0 callers / 1 callee |
| `0x600d1ffa` |  36 | USB / Host HID | **`usb_host_hid_interrupt_out_cback`** — USB Host HID interrupt OUT transfer callback: clears state `param_1 + 0x1c = 0`, invokes client callback `*(param_1 + 0x28)(...)`, and frees buffer via `FUN_600d3386`. | 0 callers / 1 callee |
| `0x600d201e` |  78 | USB / Host HID | **`usb_host_hid_instance_alloc`** — USB Host HID instance allocator: allocates 76-byte context structure `FUN_600d15c8(0x4c)` and registers pipe handles via `FUN_600d33b2`. Called from `FUN_600563b8`. | 1 caller / 2 callees |
| `0x600d206c` | 212 | USB / Host HID | **`usb_host_hid_interrupt_pipe_open`** — USB Host HID interrupt transfer pipe open: searches endpoint descriptors for interrupt endpoint (`type 3`), allocates pipe via `FUN_600d3244` with 3000ms timeout, stores handle in `param_1 + 0x14`, and notifies client. Called from `FUN_600563b8`. | 1 caller / 4 callees |
| `0x600d2140` |  76 | USB / Host HID | **`usb_host_hid_device_close`** — USB Host HID device close: aborts pending interrupt pipes via `FUN_600d332a` / `FUN_600d3256`, unbinds interfaces via `FUN_600569e4`, and notifies host stack via `thunk_EXT_FUN_000080d8`. Called from `FUN_600563b8`. | 1 caller / 4 callees |

## Session 59 (Wave 29) — USB Host Hub Class Pipeline, Device Lifecycle & Controller Pipe Engine (21 functions, 1,596 bytes)

Decompiled and documented 21 functions (1,596 bytes across `0x600d218c`–`0x600d2a3c`, including 20 newly decompiled functions):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d218c` |  30 | USB / Host Hub | **`usb_host_hub_get_hub_desc_req`** — USB Host Hub Class GET_HUB_DESCRIPTOR request: sends standard hub class request `0xa0` with opcode 6 via `FUN_60055ed0`. | 0 callers / 1 callee |
| `0x600d21aa` |  30 | USB / Host Hub | **`usb_host_hub_clear_hub_feature_req`** — USB Host Hub Class CLEAR_HUB_FEATURE request: sends hub feature clear request `0x20` with opcode 1 via `FUN_60055ed0`. | 0 callers / 1 callee |
| `0x600d21c8` |  30 | USB / Host Hub | **`usb_host_hub_get_hub_status_req`** — USB Host Hub Class GET_HUB_STATUS request: sends hub status query request `0xa0` with opcode 0 via `FUN_60055ed0`. | 0 callers / 1 callee |
| `0x600d21e6` |  32 | USB / Host Hub | **`usb_host_hub_set_port_feature_req`** — USB Host Hub Class SET_PORT_FEATURE request: sends port feature set request `0x23` with opcode 3 via `FUN_60055ed0`. Called from `FUN_60055fbc`. | 1 caller / 1 callee |
| `0x600d2206` |  32 | USB / Host Hub | **`usb_host_hub_clear_port_feature_req`** — USB Host Hub Class CLEAR_PORT_FEATURE request: sends port feature clear request `0x23` with opcode 1 via `FUN_60055ed0`. Called from `FUN_60055fbc`. | 1 caller / 1 callee |
| `0x600d2226` |  32 | USB / Host Hub | **`usb_host_hub_get_port_status_req`** — USB Host Hub Class GET_PORT_STATUS request: sends port status query request `0xa3` with opcode 0 via `FUN_60055ed0`. Called from `FUN_60055fbc`. | 1 caller / 1 callee |
| `0x600d2246` |  48 | USB / Host Device | **`usb_host_device_list_remove`** — USB Host device list remover: unlinks device context `param_2` from host device linked list `*(param_1 + 0x2d4)`. Called from `FUN_600569e4` and `FUN_600d265a`. | 2 callers / 0 callees |
| `0x600d2298` |  48 | USB / Host Device | **`usb_host_device_bitmask_clear`** — USB Host device bitmask clearer: clears bit `param_2 - 1` in device active bitfield `*(param_1 + 0x2d8)` within critical section. Called from `FUN_600d25f4`. | 1 caller / 2 callees |
| `0x600d22c8` | 134 | USB / Host Device | **`usb_host_device_init_dispatch`** — USB Host device initialization dispatcher: iterates device interface descriptors looking for class handlers (e.g. Hub class `9`), invokes interface initialization callbacks `*(iVar7 + 4)` / `FUN_600563b8`. | 3 callers / 1 callee |
| `0x600d25f4` | 136 | USB / Host Device | **`usb_host_device_cleanup`** — USB Host device cleanup & teardown: cancels endpoint pipes via `FUN_600d332a` / `FUN_600d3256`, frees descriptor buffers `private_heap__600835ac`, and notifies host stack via `thunk_EXT_FUN_000080d8`. | 2 callers / 5 callees |
| `0x600d265a` |  74 | USB / Host Device | **`usb_host_device_detach`** — USB Host device detach handler: resets state byte `param_2 + 0x43e = 0`, cancels pending transfers, unlinks from device list via `FUN_600d2246`, and invokes `FUN_600d25f4`. | 4 callers / 4 callees |
| `0x600d26a4` |  70 | USB / Host Device | **`usb_host_device_detach_by_id`** — USB Host device detach by address/port ID: searches host device list `*(param_1 + 0x2d4)` for device matching ID `param_2`/`param_3` and invokes `FUN_600d265a`. | 0 callers / 3 callees |
| `0x600d26ea` |  28 | USB / Host Device | **`usb_host_device_list_find`** — USB Host device finder: searches host device list `*(param_1 + 0x2d4)` to verify if device pointer `param_2` is valid and active. | 3 callers / 0 callees |
| `0x600d2706` |  26 | USB / Host Controller | **`usb_host_controller_tx_wait`** — USB Host controller FIFO transfer wait: polls hardware transmit FIFO index until required byte count `param_2 << 3` is satisfied. Called from `FUN_60057c78`. | 1 caller / 0 callees |
| `0x600d2720` |  66 | USB / Host Controller | **`usb_host_controller_async_advance`** — USB Host controller asynchronous schedule advance: waits for schedule handshake bits `0x8000` / `0x20` in register `*(iVar2 + 0x144)`, updates head pointer `*(iVar2 + 0x158) = *(param_1 + 0x2c)`, and asserts `0x20`. | 3 callers / 0 callees |
| `0x600d2762` |  82 | USB / Host Controller | **`usb_host_pipe_transfer_enqueue`** — USB Host pipe transfer enqueue: sums transfer buffer lengths in descriptor chain `param_2`..`param_3`, enqueues descriptor to pipe queue `*(param_1 + 0x10)` / `*(param_1 + 0x14)`, and increments pending transfer count `param_1 + 0x49`. | 3 callers / 2 callees |
| `0x600d27b4` | 260 | USB / Host Controller | **`usb_host_pipe_config_hw`** — USB Host pipe hardware descriptor configurator: initializes 16-dword (64-byte) hardware pipe descriptor `puVar5`, queries endpoint parameters via `FUN_600d33b2`, and packs endpoint address, speed, max packet size, and bandwidth allocation fields. Called from `FUN_60056fa4`. | 1 caller / 3 callees |
| `0x600d28b8` | 206 | USB / Host Controller | **`usb_host_pipe_bandwidth_allocate`** — USB Host periodic pipe bandwidth allocator: calculates frame transaction duration via `FUN_60056a9c`, searches periodic schedule frame list `*(param_1 + 0x38)` to find available microframe slot with <900us total allocated bandwidth. Called from `FUN_60056fa4`. | 1 caller / 2 callees |
| `0x600d2986` |  50 | USB / Host Controller | **`usb_host_controller_async_stop`** — USB Host controller asynchronous schedule stop: synchronizes handshake bits and clears schedule enable bit `0x20` in register `*(param_1 + 0x140)`. | 3 callers / 0 callees |
| `0x600d29b8` | 132 | USB / Host Controller | **`usb_host_pipe_transfer_abort`** — USB Host pipe transfer abort & completion callback: pauses asynchronous schedule if active, unlinks queued transfer descriptors `puVar4`, and invokes transfer completion callback `*(puVar4[4])(puVar4[5], puVar4, 0xe)`. | 2 callers / 5 callees |
| `0x600d2a3c` |  50 | USB / Host Controller | **`usb_host_controller_periodic_stop`** — USB Host controller periodic schedule stop: synchronizes handshake bits `0x4000` / `0x10` and clears periodic schedule enable bit `0x10` in register `*(param_1 + 0x140)`. | 0 callers / 0 callees |

## Session 60 (Wave 30) — EHCI Schedule Management, Host Controller Teardown & Transfer Abort Engine (20 functions, 1,182 bytes)

Decompiled and documented 20 functions (1,182 bytes across `0x600d2a6e`–`0x600d3386`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d2a6e` |  32 | USB / Host EHCI | **`usb_host_ehci_periodic_frame_unlink`** — EHCI periodic schedule frame list unlinker: unlinks element `param_2` from frame list index `param_3` in 1024-entry frame list `*(param_1 + param_3 * 4)`. | 3 callers / 0 callees |
| `0x600d2a8e` |  64 | USB / Host EHCI | **`usb_host_ehci_itd_chain_unlink`** — EHCI isochronous transfer descriptor (iTD) chain unlinker: iterates iTD chain `param_2`..`param_3`, unlinks from frame list via `FUN_600d2a6e`, and links into free list `*(param_1 + 0x20)`. | 2 callers / 1 callee |
| `0x600d2ace` |  64 | USB / Host EHCI | **`usb_host_ehci_itd_pipe_abort`** — EHCI isochronous pipe abort: unlinks queued iTD requests, calls `FUN_600d2a8e` to release iTD frames, and invokes completion callbacks. | 2 callers / 3 callees |
| `0x600d2b0e` |  94 | USB / Host EHCI | **`usb_host_ehci_sitd_chain_unlink`** — EHCI split isochronous transfer descriptor (siTD) chain unlinker: iterates siTD chain `param_2`..`param_3`, unlinks from frame list via `FUN_600d2a6e`, zeroes descriptor fields, and returns byte sum. | 2 callers / 1 callee |
| `0x600d2b6c` |  68 | USB / Host EHCI | **`usb_host_ehci_sitd_pipe_abort`** — EHCI split isochronous pipe abort: unlinks queued siTD transfers from pipe `param_2`, calls `FUN_600d2b0e` to release siTD frames, and invokes completion callbacks. | 2 callers / 3 callees |
| `0x600d2d94` |  38 | USB / Host EHCI | **`usb_host_ehci_controller_stop`** — EHCI controller stop & shutdown: zeroes schedule registers `0x140`/`0x148`, releases host mutex `thunk_FUN_600d1662`, resets event group via `FUN_600d15f8`, and notifies host stack via `thunk_EXT_FUN_000080d8`. | 0 callers / 3 callees |
| `0x600d2dba` | 282 | USB / Host EHCI | **`usb_host_ehci_pipe_close`** — EHCI pipe close and schedule unlinker: unlinks pipe from asynchronous schedule (cases 0/2: bulk/control), split isochronous schedule (case 1: siTD/iTD), or periodic interrupt schedule (case 3: periodic frame list), cleans up descriptors, and returns to free queue. | 0 callers / 9 callees |
| `0x600d3196` |  40 | USB / Host Control | **`usb_host_control_transfer_submit`** — USB Host standard control transfer submitter: sets request length `param_2 + 4 = param_3`, buffer length `param_2 + 8 = param_4`, and dispatches via `FUN_600d32a2`. | 3 callers / 2 callees |
| `0x600d31be` |  14 | USB / Host Control | **`usb_host_control_get_status_req`** — USB Host control GET_STATUS request helper: formats standard request packet and invokes `FUN_600d3196`. | 1 caller / 1 callee |
| `0x600d31cc` |  26 | USB / Host Control | **`usb_host_control_feature_req`** — USB Host control SET/CLEAR_FEATURE request helper: formats standard request packet with feature selector and invokes `FUN_600d3196`. | 1 caller / 1 callee |
| `0x600d31e6` |  28 | USB / Host Controller | **`usb_host_controller_state_clear`** — USB Host controller state clear: enters critical section `thunk_EXT_FUN_00008802`, clears state byte `*param_1 = 0`, and exits critical section `FUN_600d15e8`. | 2 callers / 2 callees |
| `0x600d3202` |  66 | USB / Host Controller | **`usb_host_controller_deinit`** — USB Host controller deinitializer: detaches all active devices `param_1[0xb5]` via `FUN_600d265a`, calls hardware controller deinit callback `*(param_1[0xb4] + 4)`, releases controller mutex, and clears host state. | 1 caller / 3 callees |
| `0x600d3244` |  18 | USB / Host Driver | **`usb_host_pipe_open`** — USB Host pipe open dispatcher: dispatches to controller hardware pipe open function pointer `*(param_1[0xb4] + 8)`. | 4 callers / 0 callees |
| `0x600d3256` |  18 | USB / Host Driver | **`usb_host_pipe_close`** — USB Host pipe close dispatcher: dispatches to controller hardware pipe close function pointer `*(param_1[0xb4] + 0xc)`. | 7 callers / 0 callees |
| `0x600d3268` |  58 | USB / Host Driver | **`usb_host_transfer_submit_async`** — USB Host asynchronous transfer submit dispatcher: clears status flags, locks mutex `param_1[2]`, and invokes hardware transfer submit callback `*(param_1[0xb4] + 0x10)`. | 2 callers / 2 callees |
| `0x600d32a2` |  76 | USB / Host Driver | **`usb_host_transfer_submit_sync`** — USB Host synchronous/control transfer submit dispatcher: clears status flags, configures direction bit, locks mutex `param_1[2]`, and invokes hardware transfer submit callback `*(param_1[0xb4] + 0x10)`. | 7 callers / 2 callees |
| `0x600d32ee` |  60 | USB / Host Driver | **`usb_host_transfer_submit_iso`** — USB Host isochronous transfer submit dispatcher: sets isochronous flag `*(param_3 + 0x20) = 1`, locks mutex `param_1[2]`, and invokes hardware transfer submit callback `*(param_1[0xb4] + 0x14)`. | 3 callers / 2 callees |
| `0x600d332a` |  34 | USB / Host Driver | **`usb_host_pipe_abort`** — USB Host pipe abort dispatcher: dispatches to controller hardware pipe abort function pointer `*(param_1[0xb4] + 0x18)`. | 8 callers / 0 callees |
| `0x600d334c` |  58 | USB / Host Driver | **`usb_host_transfer_context_alloc`** — USB Host transfer context allocator: pops a free transfer context structure from linked list `*(param_1 + 0x2cc)` within mutex protection. | 12 callers / 2 callees |
| `0x600d3386` |  44 | USB / Host Driver | **`usb_host_transfer_context_free`** — USB Host transfer context deallocator: pushes transfer context structure `param_2` onto free linked list `*(param_1 + 0x2cc)` within mutex protection. | 21 callers / 2 callees |

## Session 61 (Wave 31) — USB Host Param Dispatcher, Clock Gating, Logging Buffers & Interpolation LUTs (20 functions, 850 bytes)

Decompiled and documented 20 functions (850 bytes across `0x600d33b2`–`0x600d379e`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d33b2` | 126 | USB / Host Param | **`usb_host_param_query`** — USB Host instance parameter query dispatcher: maps query selectors (1..15) to instance structure fields (`param_1 + 0x43d`, `+0x43f`, `+0x418`, `+0x41c`, frame speed query via `FUN_60056610`). | 19 callers / 1 callee |
| `0x600d344a` | 112 | Power / Clock | **`clock_gate_acquire`** — Peripheral clock / power domain acquire helper: disables IRQ interrupts, walks clock dependency tree `*(param_2 + 4)`, increments clock refcount `*(param_2 + uVar6 * 2)`, invokes clock enable callback `*(param_2 + 8)` on 0->1 transition, and restores IRQ state. | 0 callers / 0 callees |
| `0x600d34ba` |  60 | Power / Clock | **`clock_gate_release`** — Peripheral clock / power domain release helper: disables IRQ interrupts, decrements clock refcount, invokes clock disable callback `*(iVar5 + 0xc)` on 1->0 transition, and restores IRQ state. | 0 callers / 0 callees |
| `0x600d34f6` |   4 | Diagnostics / Log | **`log_buffer_write_thunk`** (`thunk_FUN_60057ff0`) — Logging diagnostic buffer write thunk: tail-call to `FUN_60057ff0`. | 2 callers / 0 callees |
| `0x600d34fa` |  58 | Diagnostics / Log | **`log_buffer_fill_char`** — Diagnostic log string padding helper: appends `param_4` bytes of character `param_3` to buffer, flushing via `thunk_FUN_60057ff0` when reaching 128 bytes. | 0 callers / 1 callee |
| `0x600d3534` |  48 | Diagnostics / Log | **`log_msg_format_hexdump`** — Diagnostic log message payload formatter: formats buffer memory chunk via `FUN_60050c18` and emits formatted record via `FUN_601019da`. Called from `FUN_6005dcc0`. | 1 caller / 3 callees |
| `0x600d3594` |   6 | Memory / Heap | **`heap_alloc_thunk`** — Dynamic memory allocator wrapper: calls `thunk_EXT_FUN_00007f58(param_2)`. | 2 callers / 1 callee |
| `0x600d359a` |   6 | Memory / Heap | **`heap_free_thunk`** — Dynamic memory deallocator wrapper: calls `thunk_EXT_FUN_000080d8(param_2)`. | 3 callers / 1 callee |
| `0x600d35a0` |  54 | Memory / Heap | ~~**`heap_realloc`** — Dynamic memory reallocation helper: allocates new buffer `thunk_EXT_FUN_00007f58(param_3)`, copies data `thunk_EXT_FUN_0000b572`, and frees old buffer `thunk_EXT_FUN_000080d8(param_2)`.~~ ⚠️ **misidentified, corrected QA session 61** — disassembly of the real 8 bytes at `0x600d35a0` (`mov r0,r1; mov r1,r2; b.w 0x600d3566`) shows this is a 2-argument-shift trampoline that drops `param_1` and tail-calls `0x600d3566` with `(old param_2, old param_3)` — it performs none of the alloc/copy/free logic itself. That logic is real, but lives at `0x600d3566` (no census Function boundary of its own — undefined/unattributed), which the decompiler bled into `0x600d35a0`'s rendered body because Ghidra had no boundary there — the same recurring tail-call-bleed artifact class as the `raise`/`_raise_r` saga (sessions 49–65) and session 56's `private_heap_free`. The claimed callees (`thunk_EXT_FUN_00007f58`/`0x6013d128` alloc, `thunk_EXT_FUN_0000b572`/`0x6013d3a0` copy, `thunk_EXT_FUN_000080d8`/`0x6013d180` free) are real and do form a coherent realloc — just at `0x600d3566`, not `0x600d35a0`. The claimed 54-byte size for `0x600d35a0` is the census's un-split extent covering both the real 8-byte trampoline and the bled-through target; the distinct, genuinely 6-byte `0x600d35aa` immediately following (a real register-indirect trampoline, independently documented since session 14 in `bruce-log-buffer.md`) confirms this address range packs several small stubs together, not one 54-byte function. **GHIDRA-TODO: define a function boundary at `0x600d3566`** (real body runs to at least `0x600d3593` — `bl 0x6013d128` alloc behind null/cbz guards, `bl 0x6013d3a0` copy, `bl 0x6013d180` free, `pop {r4,r5,r6,pc}` at `0x600d358a` with a secondary tail path to `0x600d3593`) **and mark the `b.w 0x600d3566` edge at `0x600d35a4` as an explicit tail-call** (`FlowOverride.CALL_RETURN`, the proven `FixTailCalls.java` technique from session 53) so both re-decompile cleanly. | 1 caller / 3 callees |
| `0x600d35b4` |  22 | System / Init | **`system_table_init_1d0`** — System constant configuration table initializer: initializes 464-byte (`0x1d0`) table via `thunk_EXT_FUN_0000b52e`. | 0 callers / 2 callees |
| `0x600d35ca` |  22 | System / Init | **`system_table_init_2ad8`** — System constant configuration table initializer: initializes 10,968-byte (`0x2ad8`) table via `thunk_EXT_FUN_0000b52e`. | 0 callers / 2 callees |
| `0x600d35e0` |  22 | System / Init | **`system_table_init_43ac`** — System constant configuration table initializer: initializes 17,324-byte (`0x43ac`) table via `thunk_EXT_FUN_0000b52e`. | 0 callers / 2 callees |
| `0x600d3602` |  22 | System / Init | **`system_table_init_1358`** — System constant configuration table initializer: initializes 4,952-byte (`0x1358`) table via `thunk_EXT_FUN_0000b52e`. | 0 callers / 2 callees |
| `0x600d3638` |  32 | Utils / String | **`string_null_terminated_check`** — String buffer null-termination validator: verifies string buffer length <= 128 and checks null terminators at offset 15 and offset 15 + length. Called from `FUN_60058600`. | 1 caller / 0 callees |
| `0x600d3664` |  14 | Math / LUT | **`lookup_key_comparator_32`** — 32-bit key comparison predicate: returns `*param_1 < *param_2`. Called by `FUN_600d36d6`. | 1 caller / 0 callees |
| `0x600d3672` |  14 | Math / LUT | **`lookup_key_comparator_32_alt`** — 32-bit key comparison predicate: returns `*param_1 < *param_2`. Called by `FUN_600d373a`. | 1 caller / 0 callees |
| `0x600d36a8` |  14 | System / Init | **`system_table_init_12`** — System table zeroer: zeroes 12-byte table via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 1 callee |
| `0x600d36d6` | 100 | Math / LUT | **`lut_piecewise_linear_interp_4point`** — 4-point piecewise linear interpolation table lookup: binary searches breakpoints using `FUN_600d3664` and computes interpolated value `y0 + (y1 - y0) * (x - x0) / (x1 - x0)`. | 0 callers / 1 callee |
| `0x600d373a` | 100 | Math / LUT | **`lut_piecewise_linear_interp_3point`** — 3-point piecewise linear interpolation table lookup: binary searches breakpoints using `FUN_600d3672` and computes interpolated value `y0 + (y1 - y0) * (x - x0) / (x1 - x0)`. | 0 callers / 1 callee |
| `0x600d379e` |  14 | Math / Predicate | **`comparator_uint32_less`** — 32-bit unsigned less-than comparison predicate: returns `*param_1 < *param_2`. Called from `FUN_600593f4` and `FUN_600db43e`. | 2 callers / 0 callees |

## Session 62 (Wave 32) — JSON Serializer, Firmware Image Upload Thunk & Device Info Utilities (20 functions, 684 bytes)

Decompiled and documented 20 functions (684 bytes across `0x600d37ce`–`0x600d3b62`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d37ce` |  48 | Diagnostics / JSON | **`json_format_key_int_curly`** — JSON key-value integer formatter: formats integer value into JSON `{key: int}` structure via `FUN_60101b0c` and `FUN_601019da` with closing `}` (`0x7d`). Called from `FUN_600593f4` and `FUN_600cbbc0`. | 5 callers / 3 callees |
| `0x600d37fe` |  48 | Diagnostics / JSON | **`json_format_int_bracket`** — JSON array integer formatter: formats integer into JSON `[int]` array via `FUN_60101b0c` and `FUN_601019da` with closing `]` (`0x5d`). Called from `FUN_600593f4`. | 1 caller / 3 callees |
| `0x600d3888` |  32 | Diagnostics / JSON | **`json_builder_init_object_256`** — JSON object builder initializer: initializes 256-byte buffer `auStack` with `{` (`0x7b`) and `}` (`0x7d`) delimiters. Called from `FUN_60059280` and `FUN_600d38c8`. | 2 callers / 0 callees |
| `0x600d38a8` |  32 | Diagnostics / JSON | **`json_builder_init_array_256`** — JSON array builder initializer: initializes 256-byte buffer with `[` (`0x5b`) and `]` (`0x5d`) delimiters. Called from `FUN_600593f4` and `FUN_600d38c8`. | 2 callers / 0 callees |
| `0x600d38c8` | 112 | Diagnostics / JSON | **`json_format_uint32_array`** — JSON uint32 array serializer: iterates array `param_2`, formats elements into JSON array `[e0, e1, ...]`, and emits formatted JSON string via `FUN_6010138c`. Called from `FUN_60059560`. | 1 caller / 7 callees |
| `0x600d3938` |  48 | Diagnostics / JSON | **`json_format_key_int_curly_alt`** — JSON key-value integer formatter: formats integer value into JSON `{key: int}` structure. Called from `FUN_60059280`. | 1 caller / 3 callees |
| `0x600d3968` |  34 | Diagnostics / JSON | **`json_builder_init_object_512`** — JSON object builder initializer: initializes 512-byte (`0x1ff`) buffer with `{` and `}` delimiters. Called from `FUN_600593f4` and `FUN_60059360`. | 2 callers / 0 callees |
| `0x600d398a` |  48 | Diagnostics / JSON | **`json_format_hex_bracket`** — JSON array hex/buffer formatter: formats buffer chunk via `FUN_60050c18` into JSON array `[...]`. Called from `FUN_600593f4`. | 1 caller / 3 callees |
| `0x600d3a14` |   2 | System / Stub | **`nop_stub`** — No-operation stub: returns immediately (`bx lr`). Called from `FUN_60059cd8`. | 1 caller / 0 callees |
| `0x600d3a16` |   4 | Firmware / Upload | **`firmware_upload_cmd_thunk`** (`thunk_FUN_60059eb8`) — Firmware image upload command submission thunk: tail-call to `FUN_60059eb8`. Called from `firmware_image_upload.cc` and `application_state.cc`. | 5 callers / 0 callees |
| `0x600d3a38` |  22 | Crypto / Keys | **`key_deref_or_copy`** — Key store value getter/dereferencer: copies pointer if `param_3 == 1` or dereferences value if `param_3 == 2`. Called by `keys.cc` (`0x60066370`). | 1 caller / 0 callees |
| `0x600d3a56` |  14 | System / Init | **`system_table_init_18`** — System table zeroer: zeroes 24-byte (`0x18`) table via `thunk_EXT_FUN_0000b52e`. | 0 callers / 1 callee |
| `0x600d3a64` |  20 | System / Init | **`system_table_init_20`** — System table initializer: calls `FUN_6005a01c` and zeroes 32-byte (`0x20`) table. | 0 callers / 2 callees |
| `0x600d3a78` |  76 | Utils / RingBuffer | **`ring_buffer_write_bounded`** — Bounded circular / stream buffer writer: appends `param_3` bytes to buffer `param_1 + 0xc`, clamping to capacity `*(param_1 + 8)` and updating write index `*(param_1 + 0x14)`. | 0 callers / 1 callee |
| `0x600d3ac4` |  34 | Diagnostics / JSON | **`json_format_int_append`** — JSON integer appending helper: formats integer into string buffer and calls `FUN_60101ba2`. Called by `device_info.cc` (`0x6005a0ac`). | 1 caller / 2 callees |
| `0x600d3ae6` |  28 | Diagnostics / JSON | ~~**`json_format_string_append`** — JSON string escaping and appending helper: escapes string `param_2` via `FUN_600cbb14` and appends via `FUN_60101b76`.~~ ⚠️ **misidentified, corrected QA session 62** — `FUN_600cbb14` is not a string escaper; disassembled directly this session (`ldrb r3,[r0]; cmp r3,#0x10; itte ls; ldrls r2,[pc,#8]; ldrls.w r0,[r2,r3,lsl#2]; ldrhi r0,[pc,#4]`): it reads a **byte code** from `*param_1`, bounds-checks it against 16, and returns a **pointer from a 17-entry lookup table** indexed by that code (or a fixed default if out of range) — a small-integer-code-to-name-string lookup, matching its independently-established role everywhere else it's cited in this repo (`sleep_lock.cc`'s "formats error via `FUN_600cbb14`", the TS3A227E driver's bus-status error path, and `bruce-bta-stack.md`'s `0x600925bc` trace dispatcher — all "error/status code → name string", never "escape an arbitrary string"). So `FUN_600d3ae6`'s real behavior is: treat `param_2` as a small numeric **code**, look up its display-name string via `FUN_600cbb14`, then append that resolved name into buffer `param_1` via `FUN_60101b76` (independently confirmed generic "append a C string up to remaining capacity", `bruce-log-buffer.md`) — not "escape a string." Whether the *overall* function still belongs in a "JSON" cluster is plausible (e.g. serializing `{"status":"<name>"}`) but unconfirmed; the specific "escapes string" claim is refuted. Softer, non-blocking note: the call to `FUN_60101b76` carries `extraout_r2`/`extraout_r3` tokens (decompiler register-clobber artifact, same accepted-limitation class as sessions 53-55's `i2c_transfer_submit` — doesn't change the identity finding above). Called by `device_info.cc` and `gotham.cc`. | 5 callers / 2 callees |
| `0x600d3b02` |  16 | Device / Info | **`device_info_resource_release`** — Device info resource cleanup helper: invokes release helper `FUN_600e0242` if handle `*param_1 != 0`. Called by `device_info.cc`. | 2 callers / 1 callee |
| `0x600d3b12` |  18 | Device / Info | **`device_info_buffer_clear_20`** — Device info 32-byte buffer clear helper: clears 32-byte (`0x20`) buffer via `thunk_EXT_FUN_0000b52e`. Called by `device_info.cc`. | 2 callers / 1 callee |
| `0x600d3b50` |  18 | Device / Info | **`device_info_vtable_release`** — Device info virtual destructor / release dispatch: invokes vtable destructor `**(code **)(*(int *)*param_1 + 4)()`. Called by `device_info.cc`. | 1 caller / 0 callees |
| `0x600d3b62` |  30 | Utils / String | **`string_to_lower`** — ASCII string to lowercase converter: iterates string buffer, replacing uppercase ASCII characters `0x41`..`0x5A` ('A'..'Z') with lowercase `+ 0x20` ('a'..'z'). Called by `device_info.cc` (`0x6005a4cc`). | 1 caller / 0 callees |

## Session 63 (Wave 33) — Application State Machine Actions, Memory Barriers, Event Post & Binary Search Tables (20 functions, 1,012 bytes)

Decompiled and documented 20 functions (1,012 bytes across `0x600d3b80`–`0x600d4084`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d3b80` |  24 | Utils / Memory | **`memcpy_1_or_n`** — Memory copy helper: single byte direct copy if `param_3 == 1` or `memcpy` via `thunk_EXT_FUN_0000b572` if `param_3 > 1`. 7 callers across flash writer, keys, and network stack. | 7 callers / 1 callee |
| `0x600d3b98` |  24 | Utils / Memory | **`memmove_1_or_n`** — Overlapping memory copy helper: single byte direct copy if `param_3 == 1` or `memmove` via `thunk_EXT_FUN_0000b588` if `param_3 > 1`. Called by `FUN_6005a9fc`. | 1 caller / 1 callee |
| `0x600d3c7c` |  64 | State / Flags | **`state_flag_eval`** — State flag / property evaluator: queries object interface property via `**(param_2 + 0x5c) + 0x1c` and packs boolean status flags. | 0 callers / 0 callees |
| `0x600d3ccc` |  68 | Math / LUT | **`key_binary_search_14`** — 14-entry sorted binary search lookup table: searches key `param_2` in 8-byte entry table `*(param_1 + 0x70)` and returns associated value `piVar4[1]`. | 0 callers / 0 callees |
| `0x600d3d10` |  68 | Math / LUT | **`key_binary_search_20`** — 20-entry sorted binary search lookup table: searches key `param_2` in 8-byte entry table `*(param_1 + 0x74)` and returns associated value `piVar4[1]`. | 0 callers / 0 callees |
| `0x600d3d54` |  40 | System / Events | **`event_notify_async`** — Asynchronous event notification sender: queries event source via `thunk_EXT_FUN_0000714c` and posts event via `thunk_EXT_FUN_00007a2c`. Called from `application_state.cc` (`0x6005b8dc`). | 1 caller / 2 callees |
| `0x600d3d7c` |  30 | Audio / Haptics | **`pattern_player_event_post`** — Pattern player event poster: posts event to queue via `thunk_EXT_FUN_00007a2c(param_1, 3, 0, 0, 10, param_2, param_3)`. Called from `pattern_player.cc` (`0x6005af04`). | 1 caller / 1 callee |
| `0x600d3d9a` |  62 | Power / State | **`device_power_state_validate`** — Device power/connection state validator: checks 5 power/connectivity state flags (types 2, 8, 10, 9, 1) via `FUN_600dffe8`. Called from `application_state.cc`. | 1 caller / 1 callee |
| `0x600d3dd8` |  28 | State / Timer | **`app_state_timer_dispatch`** — Application state timer / event dispatcher: gets timer context via `FUN_6005bdac` and dispatches via `thunk_EXT_FUN_00001834`. 10 callers across application state machine and Gotham interface. | 10 callers / 2 callees |
| `0x600d3e22` |  40 | State / Atomic | **`app_state_memory_barrier_write`** — Atomic application state writer: executes ARM `DMB` barriers around state byte write `*(param_1 + 4) = param_2` and notifies state listener `FUN_6005ae68`. Called from `application_state.cc` (`0x6005b1c0`). | 1 caller / 1 callee |
| `0x600d3e4a` |  22 | State / Flags | **`app_state_flag_getter`** — Application state flag getter: checks flag byte `*(param_2 + 0x28)` and retrieves value `*(param_2 + 0x24)`. Called by `FUN_600d3e60`. | 1 caller / 0 callees |
| `0x600d3e60` |  52 | State / Transition | **`app_state_transition_execute`** — Application state transition executor: queries transition status via `FUN_600d3e4a`, dispatches to virtual handler `*param_1 + 0x10`, or triggers error halt `FUN_6010209a`. Called from `application_state.cc`. | 2 callers / 2 callees |
| `0x600d3e94` |  32 | Diagnostics / JSON | **`json_builder_init_object_200`** — JSON object builder initializer: initializes 200-byte (`199`) buffer with `{` and `}` delimiters. Called from `FUN_6005b4f4`. | 1 caller / 0 callees |
| `0x600d3eb4` |  26 | State / Struct | **`app_state_record_copy`** — Application state record structure copier: copies structure fields and validity flags. Called by `FUN_600d3ece`. | 1 caller / 0 callees |
| `0x600d3ece` | 280 | State / Dispatch | **`app_state_action_dispatch`** — Application state hierarchical action dispatcher: binary searches state table `param_2[0x1a]`, matches action ID `param_4`, copies parameters via `FUN_600d3eb4`, and dispatches action handler `**(param_2 + 0x28)`. | 0 callers / 1 callee |
| `0x600d3fe6` |  38 | Memory / Cleanup | **`descriptor_array_free`** — Descriptor pointer array deallocator: iterates pointer array `param_1[5]`..`param_1[9]` freeing each descriptor via `thunk_EXT_FUN_0000b52a`, and frees array root `*param_1`. 6 callers! | 6 callers / 1 callee |
| `0x600d400c` |  20 | System / Init | **`system_table_init_60`** — System table initializer: calls `FUN_6005b740` and zeroes 96-byte (`0x60`) table. | 0 callers / 2 callees |
| `0x600d4020` |  22 | System / Init | **`system_table_init_120`** — System table initializer: calls `FUN_6005b764` and zeroes 288-byte (`0x120`) table. | 0 callers / 2 callees |
| `0x600d4036` |  32 | State / String | **`app_state_string_format`** — Application state string formatter: formats state description via `FUN_60079adc` and appends via `FUN_60101ba2`. Called from `application_state.cc`. | 2 callers / 2 callees |
| `0x600d4084` |  40 | System / Events | **`app_state_event_notify`** — Application state event notifier: queries event source via `thunk_EXT_FUN_0000714c` and posts event via `thunk_EXT_FUN_00007a2c`. Called from `FUN_6005c8a0`. | 1 caller / 2 callees |

## Session 64 (Wave 34) — Gotham State Setters, GATT Characteristic Handlers, Audio Receiver & BT Adapter State (20 functions, 632 bytes)

Decompiled and documented 20 functions (632 bytes across `0x600d40ac`–`0x600d8a6e`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d40ac` |  22 | System / Init | **`system_table_init_da0`** — System table initializer: calls `FUN_6005bc58` and zeroes 3,488-byte (`0xda0`) table via `thunk_EXT_FUN_0000b52e`. | 0 callers / 2 callees |
| `0x600d40c2` |  10 | Gotham / Interface | **`gotham_tx_forward_thunk`** — Gotham TX forwarding helper: forwards payload buffer `*(param_1 + 0x20)` and length `*(param_1 + 0x18)` to `FUN_600cedd8`. Called from `FUN_6005be94`. | 1 caller / 1 callee |
| `0x600d40cc` |  20 | Gotham / Task | **`gotham_task_state_set`** — Gotham task state context setter: sets context pointer `*(param_1 + 0x110) = param_2` and asserts state active flag `*(param_1 + 0x114) = 1`. Called by `gotham_task__6005bdb4`. | 2 callers / 0 callees |
| `0x600d410c` |  16 | Memory / Cleanup | **`heap_free_if_nonnull`** — Null-guarded pointer free helper: calls `thunk_EXT_FUN_0000b52a(*param_1)` if `*param_1 != 0`. Called by `FUN_6005ccd8` and `FUN_600d62f8`. | 2 callers / 1 callee |
| `0x600d411c` |  60 | Audio / Radio | **`audio_receiver_mode_select`** — Audio/radio receiver mode dispatcher: evaluates mode `param_2` (0..3), configuring receiver channels via `FUN_60074ba8(0xb/10)`, `FUN_6007ec20`/`FUN_6007ec28`, or `receiver__6007ec48`. | 0 callers / 6 callees |
| `0x600d415c` |  32 | State / String | **`app_state_string_format_alt`** — Alternate application state string formatter: formats state string via `FUN_60079bd4` and appends via `FUN_60101ba2`. | 0 callers / 2 callees |
| `0x600d41ec` |  26 | State / Timer | **`app_state_timer_dispatch_type9`** — State timer type 9 event forwarder: forwards timer event to `app_state_timer_dispatch(9, *param_2)`. | 0 callers / 1 callee |
| `0x600d4224` |  26 | State / Timer | **`app_state_timer_dispatch_type1`** — State timer type 1 event forwarder: forwards timer event to `app_state_timer_dispatch(1, *param_2)`. | 0 callers / 1 callee |
| `0x600d424c` |  22 | System / Init | **`system_table_init_588`** — System table initializer: calls `FUN_6005ccd8` and zeroes 1,416-byte (`0x588`) table. | 0 callers / 2 callees |
| `0x600d4262` |  22 | System / Init | **`system_table_init_2658`** — System table initializer: calls `FUN_6005cd08` and zeroes 9,816-byte (`0x2658`) table. | 0 callers / 2 callees |
| `0x600d4308` |  40 | Thermal / Events | **`thermal_event_notify`** — Thermal subsystem asynchronous event poster: queries event source via `thunk_EXT_FUN_0000714c` and posts event via `thunk_EXT_FUN_00007a2c`. Called from `thermal.cc` (`0x6005d634`, `0x6005d1e4`). | 2 callers / 2 callees |
| `0x600d43c6` |  70 | Bluetooth / GATT | **`gatt_char_write_buffer_copy`** — GATT characteristic write buffer copier: checks length against limit `*(ushort *)(uVar2 + 0x1c)`, copies up to 20 bytes (`0x14`) to stack buffer `auStack_28`, null-terminates, and dispatches write handler `**(param_1 + 0x34)`. | 0 callers / 1 callee |
| `0x600d44b0` |  66 | Bluetooth / GATT | **`gatt_service_notification_send`** — GATT service notification sender: gets service handle via `gatt_service_handle__6005d9a8`, formats 20-byte payload, computes checksum/length via `FUN_6004cb28`, and dispatches notification callback `*puVar1`. | 0 callers / 3 callees |
| `0x600d44f2` |  94 | Bluetooth / GATT | **`gatt_service_record_init`** — GATT service record structure initializer: zeroes struct fields, sets identifier tags 9 and 2, and zeroes 4 31-byte (`0x1f`) sub-buffers via `thunk_EXT_FUN_0000b5ba`. Called from `types.cc` (`0x600810bc`). | 2 callers / 1 callee |
| `0x600d4566` |  48 | Diagnostics / JSON | **`json_format_object_close`** — JSON object serializer and closer: formats object via `FUN_60050c18` and closes JSON object with `}` (`0x7d`) delimiter via `FUN_601019da`. Called from `FUN_6005dcc0` and `FUN_6005dbec`. | 2 callers / 3 callees |
| `0x600d8a12` |   6 | Bluetooth / Adapter | **`bt_adapter_enable_thunk`** — Bluetooth adapter enable helper: forwards call to `adapter__600d89ec(param_1, param_2, 1)`. Called from `adapter.cc` (`0x60069780`). | 1 caller / 1 callee |
| `0x600d8a18` |  14 | Bluetooth / Adapter | **`bt_adapter_assert_state2`** — Bluetooth adapter state assertion: asserts `*(param_1 + 0xc) == 2`, triggering kernel halt `FUN_6010209a` on mismatch. Called from `adapter.cc`. | 2 callers / 1 callee |
| `0x600d8a26` |  14 | Bluetooth / Adapter | **`bt_adapter_assert_state1`** — Bluetooth adapter state assertion: asserts `*(param_1 + 0xc) == 1`, triggering kernel halt `FUN_6010209a` on mismatch. Called from `adapter.cc`. | 3 callers / 1 callee |
| `0x600d8a62` |  12 | Bluetooth / GATT | **`comparator_ushort_less`** — Unsigned 16-bit less-than comparator predicate: returns `*param_1 < param_2`. Called by `gatt_server.cc` (`0x6006a634`). | 2 callers / 0 callees |
| `0x600d8a6e` |  12 | Bluetooth / GATT | **`comparator_ushort_less_alt`** — Alternate unsigned 16-bit less-than comparator predicate: returns `*param_1 < param_2`. Called by `0x6006a4d4`. | 1 caller / 0 callees |

## Session 65 (Wave 35) — GATT Server, LP5562 RGB LED Driver, TUSB320 USB Port Controller & WM8904 Codec (20 functions, 1,310 bytes)

Decompiled and documented 20 functions (1,310 bytes across `0x600d8a7a`–`0x600d8fa6`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d8a7a` |  76 | Bluetooth / GATT | **`gatt_server_client_record_alloc`** — GATT server client record allocator: allocates/zeroes a 284-byte (`0x11c`) client record in array `param_1 + 0x230`, copies descriptor info, and increments client count `*(param_1 + 0x1714)`. | 1 caller / 2 callees |
| `0x600d8ac6` |  34 | Bluetooth / GATT | **`gatt_server_format_uint16`** — GATT server uint16 formatter: formats 16-bit value via `FUN_60050c18` and appends to buffer via `FUN_60101ba2`. 4 callers in `gatt_server.cc`. | 4 callers / 2 callees |
| `0x600d8ae8` |  82 | Bluetooth / GATT | **`gatt_server_client_find_or_alloc`** — GATT server client lookup/allocator: searches client records in `param_1 + 0x230` via `FUN_6006a448`, returning index `param_3` if found or allocating via `FUN_600d8a7a` (capped at 8 clients max). Called from `gatt_server.cc` (`0x6006a944`). | 1 caller / 2 callees |
| `0x600d8b3a` |  50 | Bluetooth / GATT | **`gatt_server_client_find`** — GATT server client record lookup: searches client records in `param_1 + 0x230` via `FUN_6006a448` and returns pointer to client record struct. Called by `activation_sequence.cc` (`0x60068f88`). | 1 caller / 1 callee |
| `0x600d8b9e` |  76 | Bluetooth / GATT | **`gatt_server_handle_binary_search`** — GATT server attribute handle binary search: binary searches 8-byte sorted entry table `param_1` for attribute handle `param_2` via comparator `FUN_600d8a62`, returning attribute context pointer `*(puVar4 + 2)`. 3 callers in `gatt_server.cc`. | 3 callers / 1 callee |
| `0x600d8bea` |  32 | Bluetooth / GATT | **`gatt_server_format_uuid_or_string`** — GATT server UUID/string formatter: formats string via `FUN_60068e98` and appends via `FUN_60101ba2`. 6 callers in `gatt_server.cc`. | 6 callers / 2 callees |
| `0x600d8c0a` |  16 | Gotham / Interface | **`gotham_tx_disable_thunk`** — Gotham TX disable thunk: disables interface via `FUN_600cedd8(*(iVar1 + 0x20), *(iVar1 + 0x18), 0)`. Called by `0x600718b8`. | 1 caller / 1 callee |
| `0x600d8c1a` |  36 | Drivers / LP5562 | **`lp5562_i2c_write_reg`** — TI LP5562 RGB LED driver I2C 2-byte register write: writes 2-byte register/value pair to I2C slave via `thunk_EXT_FUN_00001ea4`. 5 callers in `led_driver_lp5562.cc`. | 5 callers / 1 callee |
| `0x600d8c3e` |  60 | Drivers / LP5562 | **`lp5562_led_driver_init`** — TI LP5562 RGB LED driver initialization: resets chip via reg `0x01` (0x00), configures clock/power via reg `0x00` (`0x40`/`0xc0`), and configures engine mode via reg `0x70`. Called by `led_driver_lp5562.cc`. | 2 callers / 1 callee |
| `0x600d8c7a` | 224 | Drivers / LP5562 | **`lp5562_program_load`** — TI LP5562 micro-engine SRAM program loader: loads LED pattern microcode sequences (16 words per engine) across program memory banks `0x10`, `0x30`, `0x50` into LP5562 SRAM via I2C bursts. Called from `FUN_600d7ad6`. | 1 caller / 3 callees |
| `0x600d8d5a` |  88 | Drivers / LP5562 | **`lp5562_set_rgb_current_atomic`** — TI LP5562 RGB channel current setter: checks busy state via `led_driver_lp5562__6006b10c`, stores R/G/B/W current settings `param_2`..`param_5` into `param_1 + 0x10`..`0x13` guarded by ARM `DMB` barriers. | 0 callers / 1 callee |
| `0x600d8db2` |  30 | Drivers / LP5562 | **`lp5562_clear_rgb_current`** — TI LP5562 RGB channel current clear / disable: clears pending flag `*(param_1 + 0x14) = 0` with ARM `DMB` and zeroes current via `led_driver_lp5562__6006b10c`. Called by `FUN_600d7ad6`. | 1 caller / 1 callee |
| `0x600d8dd0` |  34 | Drivers / TUSB320 | **`tusb320_format_port_status`** — TI TUSB320 USB Type-C CC port status string formatter: formats status via `FUN_60050c18` and appends via `FUN_60101ba2`. Called by `usb_port_controller_tusb320.cc` (`0x6006b350`). | 1 caller / 2 callees |
| `0x600d8df2` |  58 | System / State | **`usb_port_state_flag_set`** — USB port controller state flag setter: updates state byte `*(param_1 + 0x181)` with ARM `DMB` barriers and triggers notification via `FUN_600926a0`. Called from `application_state.cc`. | 1 caller / 1 callee |
| `0x600d8e2c` |  64 | Drivers / TUSB320 | **`tusb320_state_change_notify`** — TI TUSB320 Type-C attach/detach state listener notifier: mutex-locks `param_1 + 0x74`, iterates listener callback list `*(param_1 + 0x20)` notifying each listener of state change `param_2`, and unlocks mutex. Called by `usb_port_controller_tusb320.cc`. | 2 callers / 2 callees |
| `0x600d8e6c` | 104 | Drivers / TUSB320 | **`tusb320_i2c_read_reg`** — TI TUSB320 I2C register read helper: acquires mutex at `param_1 + 200`, writes register address `param_2` and reads register value `*param_3` via `thunk_EXT_FUN_00001ea4` with retries. 4 callers in `usb_port_controller_tusb320.cc`. | 4 callers / 3 callees |
| `0x600d8ed4` |  80 | Drivers / TUSB320 | **`tusb320_poll_interrupt_status`** — TI TUSB320 Type-C interrupt status poller: reads interrupt/status register 9 via `FUN_600d8e6c`, parses CC attached mode (DFP/UFP/DRP), and dispatches state update `FUN_600d8e2c`. Called from `usb_port_controller_tusb320.cc` (`0x6006b290`). | 1 caller / 2 callees |
| `0x600d8f24` |  64 | Drivers / TUSB320 | **`tusb320_i2c_write_reg`** — TI TUSB320 I2C 2-byte register write helper: acquires mutex at `param_1 + 200`, writes register address `param_2` and byte `param_3` via `thunk_EXT_FUN_00001ea4`. Called by `usb_port_controller_tusb320.cc`. | 2 callers / 3 callees |
| `0x600d8f64` |  58 | Drivers / TUSB320 | **`tusb320_clear_interrupt`** — TI TUSB320 Type-C interrupt clear: reads interrupt register 9 via `FUN_600d8e6c` and writes back clear bit via `FUN_600d8f24`. Called from `usb_port_controller_tusb320.cc` (`0x6006b290`). | 1 caller / 2 callees |
| `0x600d8fa6` |  44 | Drivers / WM8904 | **`wm8904_i2c_write_reg_16`** — Wolfson WM8904 Audio Codec I2C 16-bit register write: writes 3-byte packet (register address + 16-bit big-endian value) to WM8904 via `thunk_EXT_FUN_00001ea4`. 6 callers in `sound_codec_wm8904.cc`. | 6 callers / 1 callee |

## Session 66 (Wave 36) — WM8904 Codec Control, Radio Power Clocks, Flash Streaming & Sensor Calibration (20 functions, 626 bytes)

Decompiled and documented 20 functions (626 bytes across `0x600d8fd2`–`0x600d94c0`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d8fd2` | 108 | Drivers / WM8904 | ~~**`wm8904_soft_reset_and_init`** — Wolfson WM8904 audio codec soft reset & initialization: performs soft reset via reg `0x00` (`0x0000`) and applies bias/clocking configuration across 8 core registers (`0x16`, `0x14`, `0x04`, `0x05`, `0x18`, `0x1a`, `0x44`, `0x45`).~~ ⚠️ **misidentified, corrected QA session 66** — the decompiled body never touches registers `0x00`/`0x16`/`0x14`/`0x04`/`0x05`/`0x18`/`0x1a`/`0x44`/`0x45`; it only ever calls `FUN_600d8fa6` (`wm8904_i2c_write_reg_16`) on registers `0x39` and `0x3a`, single-stepping a level byte (`*(param_1+0xf)`) by ±1 toward a target (`param_2`, clamped ≤`0x32`) each call, gated by a channel-active flag at `+0xc` — a **gradual level/volume ramp helper**, not a reset-and-init sequence. Called by `sound_codec_wm8904.cc`. | 1 caller / 1 callee |
| `0x600d903e` |  56 | Drivers / WM8904 | ~~**`wm8904_set_volume_atomic`** — Wolfson WM8904 volume setter: stores left/right volume and mute status into struct `param_1 + 0xc` guarded by ARM `DMB` memory barriers.~~ ⚠️ **misidentified, corrected QA session 66** — the decompiled body has zero `DataMemoryBarrier` calls and never writes `param_1+0xc`; it's a **register READ helper**: writes register address `param_2` via the I2C thunk, reads back 2 bytes, and on success stores the assembled 16-bit value into `*param_3` — the read-side counterpart to `wm8904_i2c_write_reg_16`, not a volume setter. 4 callers in `sound_codec_wm8904.cc`. | 4 callers / 1 callee |
| `0x600d9076` |  24 | Drivers / WM8904 | ~~**`wm8904_i2c_write_reg_thunk`** — Wolfson WM8904 16-bit register write thunk: forwards reg `param_2` and val `param_3` to `wm8904_i2c_write_reg_16`.~~ ⚠️ **corrected QA session 66** — the call to `FUN_600d8fa6` (`wm8904_i2c_write_reg_16`) uses fields read from the `param_1` struct (`*param_1`, `*(param_1+1)`, `*(short*)(param_1+6)`) as handle/reg/value, not the function's own `param_2`/`param_3` (which go unused in the call) — gated by a flag byte at `param_1+2`. Called by `sound_codec_wm8904.cc` (`0x6006b804`). | 1 caller / 1 callee |
| `0x600d92fc` |  10 | System / State | ~~**`system_flag_equal_1`** — State predicate: checks `*(char *)(param_1 + 4) == 1`.~~ ⚠️ **misidentified, corrected QA session 66** — not a predicate at all: reads a pointer-sized value at **`param_1 - 0x38`** and, if non-null, adds `0x38` back to it before returning — a "recover the containing struct from an embedded prev-link field, or null" accessor. No comparison to `1`, no `+4` access, no boolean return anywhere in the body. 11 callers across system modules. | 11 callers / 0 callees |
| `0x600d9306` |  10 | System / State | ~~**`system_flag_equal_0`** — State predicate: checks `*(char *)(param_1 + 4) == 0`.~~ ⚠️ **corrected QA session 66** — real check is `*(short *)(param_1 + 8) == 0` (offset `+8`, 16-bit, not `+4`/8-bit) — a genuine equals-zero predicate, just at the wrong offset/width. 6 callers across system modules. | 6 callers / 0 callees |
| `0x600d9310` |  10 | System / State | ~~**`system_flag_equal_2`** — State predicate: checks `*(char *)(param_1 + 4) == 2`.~~ ⚠️ **misidentified, corrected QA session 66** — a `void` function with no return value that zeroes three consecutive fields (`*param_1`, `param_1[1]`, `param_1[2]`) — a struct-clear/reset helper, not a predicate; no comparison to `2` anywhere in the body. | 1 caller / 0 callees |
| `0x600d931a` |  16 | System / State | ~~**`system_state_byte_getter`** — State byte getter: returns `*(char *)(param_1 + 4)`.~~ ⚠️ **misidentified, corrected QA session 66** — a `void` function (no return value) that zeroes two fields, sets a third to the sentinel `0x80000000`, and zeroes a byte at `+0x16` — an initializer/reset helper matching the same shape as `0x600d9310` above, not a getter. Both `system_flag_equal_2` and this row are very likely the same kind of struct-reset helper as each other, misidentified by the same "sibling functions must all be simple predicates/getters" assumption. | 1 caller / 0 callees |
| `0x600d932a` |  74 | Unclear | ~~**`hardware_radio_power_config`** — Hardware radio clock/crystal configuration: gates RF clocks via `thunk_EXT_FUN_00007d64` / `thunk_EXT_FUN_00007dac` and signals power manager via `thunk_EXT_FUN_0000714c`.~~ ⚠️ **misidentified, corrected QA session 66** — the function's own header shows **0 callees**, confirmed by the body: it makes no external calls at all. Real shape is a self-contained linked-list walk decrementing a per-node countdown field (`piVar2[3]`) by a caller-supplied budget (`param_2`) until the budget is exhausted, counting how many nodes hit zero (returned) and zeroing their field — the classic shape of a **software timer-list tick/expiry processor**, not radio/clock/crystal configuration. Real subsystem unconfirmed; "gates RF clocks" and all three thunk-call claims are fabricated. 3 callers. | 3 callers / 0 callees |
| `0x600d9374` |   4 | C Runtime / RTOS | ~~**`thunk_EXT_FUN_0000714c`** — External power manager event dispatch thunk.~~ ⚠️ **misidentified, corrected QA session 66** — this target is already independently resolved in `bruce-itcm.md` (session 5/6, flash `0x60047968`): a trivial 6-byte getter, `return *DAT_60047970` (a single global word, likely a tick-count/state accessor) — not a "power manager event dispatch" thunk. | 1 caller / 0 callees |
| `0x600d9378` |   4 | C Runtime / RTOS | ~~**`thunk_EXT_FUN_00007d64`** — External peripheral clock enable thunk (11 callers).~~ ⚠️ **misidentified, corrected QA session 66** — this target is already independently resolved in `bruce-itcm.md` (session 5/6, flash `0x60048580`): **`portENTER_CRITICAL()` / `vTaskEnterCritical`** (FreeRTOS critical-section enter — raises `BASEPRI`, increments a nesting counter, asserts the scheduler is running on the first nesting level) — not a clock-enable thunk. **No dedicated `.c` file exists for this address** — see the file-collision note below. | 11 callers / 0 callees |
| `0x600d937c` |   4 | C Runtime / RTOS | ~~**`thunk_EXT_FUN_00007dac`** — External peripheral clock disable thunk (11 callers).~~ ⚠️ **misidentified, corrected QA session 66** — this target is already independently resolved in `bruce-itcm.md` (session 5/6, flash `0x600485c8`): **`portEXIT_CRITICAL()`** (the paired FreeRTOS critical-section exit — decrements the nesting counter, drops `BASEPRI` to 0 once it reaches zero, asserts on unbalanced enter/exit) — not a clock-disable thunk. **No dedicated `.c` file exists for this address** — see the file-collision note below. | 11 callers / 0 callees |
| `0x600d9380` |  10 | C Runtime / RTOS | ~~**`clock_gate_disable_thunk`** — Peripheral clock gating disable helper: calls `thunk_EXT_FUN_00007dac`.~~ ⚠️ **misidentified, corrected QA session 66** — the decompiled body calls `thunk_EXT_FUN_0000737c`, not `thunk_EXT_FUN_00007dac` — `0000737c` is already independently established (`bruce-io-paths.md`) as the FreeRTOS **PendSV-trigger** (context-switch request), not a clock helper. Real shape: normalizes a zero argument to `1` then triggers a PendSV yield — consistent with a delay/yield helper (its own caller `flash_page_verify_chunk`, this session, calls it in a 100-iteration busy-wait poll loop, exactly the shape of a "yield while waiting" pattern). 7 callers. | 7 callers / 1 callee |
| `0x600d938a` |   4 | C Runtime / RTOS | ~~**`thunk_EXT_FUN_00007dac_alt`** — External peripheral clock disable thunk duplicate.~~ ⚠️ **misidentified, corrected QA session 66** — same real identity as `0x600d937c` above (`portEXIT_CRITICAL()`, a second call site into the same FreeRTOS primitive), not a clock thunk. This is the address whose decompile the committed `thunk_EXT_FUN_00007dac.c` file actually reflects — see the file-collision note below. | 11 callers / 0 callees |
| `0x600d938e` |   4 | C Runtime / RTOS | ~~**`thunk_EXT_FUN_00007d64_alt`** — External peripheral clock enable thunk duplicate.~~ ⚠️ **misidentified, corrected QA session 66** — same real identity as `0x600d9378` above (`portENTER_CRITICAL()`, a second call site into the same FreeRTOS primitive), not a clock thunk. This is the address whose decompile the committed `thunk_EXT_FUN_00007d64.c` file actually reflects — see the file-collision note below. | 11 callers / 0 callees |
| `0x600d9392` |   4 | Memory / Heap | ~~**`thunk_EXT_FUN_00007f58`** — External crystal oscillator enable thunk.~~ ⚠️ **misidentified, corrected QA session 66** — this target is already independently resolved in `bruce-itcm.md` (session 5/6, flash `0x60048774`) as `heap_5_improved__60048774`, the core `pvPortMalloc` free-list search — part of the already-attributed `heap_5_improved.c` — not a crystal-oscillator thunk. The exact same target address is also `heap_alloc_thunk`'s callee from session 61 (`0x600d3594`), independently confirmed there as a heap allocator, doubly contradicting "crystal oscillator." | 2 callers / 0 callees |
| `0x600d93a8` |  58 | Flash / Poll | **`flash_page_verify_chunk`** — ⚠️ *(identity softened, QA session 66)*: the decompiled body shows a 100-iteration poll loop waiting for `FUN_6006ea38()==1` (yielding via the now-corrected `FUN_600d9380` each iteration) before calling `FUN_6006ea44(param_2, param_3)` and returning its result — a **wait-for-ready-then-fetch poller**, not an obviously buffer-comparison verifier; no byte-for-byte comparison against "expected data" is visible in this function's own body. Real role plausible but unconfirmed as flash-specific verification; flagged rather than corrected since no clear alternative identity is evidenced either. | 1 caller / 3 callees |
| `0x600d93e2` |  10 | Flash / Stream | **`flash_status_callback_dispatch`** — Flash operation callback dispatcher: invokes status handler `FUN_6006e854(param_2)` upon completion. ⚠️ **callee count corrected, QA session 66**: the body also unconditionally calls `FUN_6006e9b0()` (no args) immediately before `FUN_6006e854(param_2)` — 2 real callees, not 0. | 1 caller / 2 callees |
| `0x600d93ec` |  40 | Flash / Stream | **`flash_stream_write_loop`** — Flash stream write block loop: iteratively writes memory chunks of size `param_2` via `FUN_6006eb00`. | 1 caller / 1 callee |
| `0x600d9414` | 172 | Sensors / I2C | **`sensor_i2c_read_and_calibrate`** — I2C sensor status register poller & calibration: polls sensor registers 5 and 7 via `thunk_EXT_FUN_00001ea4`, checks calibration ready bit, and computes calibration offset via `FUN_6006f018`. Called from `timer.cc` (`0x60074658`). | 1 caller / 2 callees |
| `0x600d94c0` |   4 | Audio / DSP | **`thunk_FUN_6006f088`** — Audio SoC DSP/codec hardware initialization routine thunk: full system audio hardware initialization sequencing 30+ register configuration writes. | 1 caller / 0 callees |

⚠️ **File-collision data gap, flagged QA session 66 — GHIDRA-TODO (RESOLVED session 67).** Fixed `Decompile.java` to enforce `thunk_<name>__<ownaddr>.c` disambiguation across all thunk decompilations, re-decompiled `0x600d9378` and `0x600d937c` into dedicated files (`thunk_EXT_FUN_00007d64__600d9378.c`, `thunk_EXT_FUN_00007dac__600d937c.c`), and cleaned up colliding legacy files. 20 of 20 distinct `.c` files committed.

## Session 67 (Wave 37) — Sleep Wakeup Masks, MPU Thunk, Table Zeroers & Calibration Interpolators (20 functions, 692 bytes)

Decompiled and documented 20 functions (692 bytes across `0x600d94c4`–`0x600d9700`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d94c4` |  36 | Power / Sleep | **`sleep_wakeup_mask_set`** — Sleep wakeup GPIO/interrupt bitmask setter: sets or clears bit `(1 << (param_1 & 0x1f))` at MMIO register `0x400f4008 + (param_1 >> 5)*4`. Called by `sleep_driver.cc` (`0x6005990c`). | 1 caller / 0 callees |
| `0x600d94e8` |   4 | System / MPU | **`thunk_mpu__600cb030__600d94e8`** — Flash veneer thunk to `mpu__600cb030` (`0x600cb030`, MPU region and cache configuration). Called by `0x6006ff00`. | 1 caller / 0 callees |
| `0x600d94ee` |  14 | System / Init | **`struct_clear_12b_1`** — 12-byte structure zeroer: clears 12 bytes via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 1 callee |
| `0x600d94fc` |  30 | System / Object | **`vtable_method_dispatch_c`** — Virtual method dispatch wrapper: retrieves object reference via `FUN_6007014c(0)` and invokes vtable method at offset `+0xc` (`*(piVar1 + 0xc)(piVar1, param_2, *param_1, param_1[1])`). | 0 callers / 1 callee |
| `0x600d951c` |  40 | Controller / Calib | **`calib_descriptor_init_type2`** — Calibration descriptor initializer (type 2): zeroes 46-byte payload at `param_2 + 2` via `thunk_EXT_FUN_0000b5ba` (memset), sets type code 2 (`*param_2 = 2`), length code 3 (`param_2[1] = 3`). ⚠️ *(corrected, QA session 67)*: the two scale fields are **not** 16-bit big-endian encodes — each is a single output byte (`param_2[4]`/`param_2[3]`) holding only the *upper* byte of its 16-bit input (`(char)(param_3 >> 8)` / `(char)(param_4 >> 8)`); the low byte is discarded, not stored anywhere. | 0 callers / 1 callee |
| `0x600d9544` |  14 | System / Init | **`struct_clear_12b_2`** — 12-byte structure zeroer: clears 12 bytes via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 1 callee |
| `0x600d955a` |  14 | System / Init | **`struct_clear_12b_3`** — 12-byte structure zeroer: clears 12 bytes via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 1 callee |
| `0x600d956a` |  40 | Controller / Calib | **`calib_descriptor_init_type5`** — Calibration descriptor initializer (type 5): zeroes 30-byte payload at `param_2 + 2` via `thunk_EXT_FUN_0000b5ba`, sets type code 5 (`*param_2 = 5`), length code 1 (`param_2[1] = 1`). ⚠️ *(corrected, QA session 67)*: same pattern as `calib_descriptor_init_type2` above — the two scale fields (`param_2[5]`/`param_2[4]`) each store only the upper byte of a 16-bit input (`>> 8`, truncated), not a full 16-bit encode. | 0 callers / 1 callee |
| `0x600d9592` |  14 | System / Init | **`struct_clear_12b_4`** — 12-byte structure zeroer: clears 12 bytes via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 1 callee |
| `0x600d95b2` |  14 | Utilities / Compare | **`comparator_byte_less`** — Byte less-than comparator predicate: returns `*param_1 < *param_2`. Called by `FUN_600d95de` and `0x60070a6c`. | 2 callers / 0 callees |
| `0x600d95c0` |  14 | Utilities / Compare | **`comparator_byte_less_alt`** — Alternate byte less-than comparator predicate: returns `*param_1 < *param_2`. Called by `switch_pro_controller__60070ad0` and `FUN_600d9644`. | 2 callers / 0 callees |
| `0x600d95d0` |  14 | System / Init | **`struct_clear_12b_5`** — 12-byte structure zeroer: clears 12 bytes via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 1 callee |
| `0x600d95de` | 102 | Controller / Calib | **`interpolate_piecewise_linear_8b`** — 8-byte entry piecewise-linear calibration interpolator: performs binary search on 8-byte stride table using `comparator_byte_less` and computes linear interpolation `y = y0 + (y1 - y0) * (x - x0) / (x1 - x0)`. | 0 callers / 1 callee |
| `0x600d9644` | 112 | Controller / Calib | **`interpolate_piecewise_linear_2b`** — 2-byte entry piecewise-linear calibration interpolator: performs binary search on 2-byte stride table using `comparator_byte_less_alt` and computes interpolated byte output. | 0 callers / 1 callee |
| `0x600d96b4` |  24 | Utilities / Compare | **`comparator_float_less`** — Float less-than comparator predicate: returns boolean float pointer `(float *)(*param_1 < *param_2)`. Called by `interpolate_float_curve` (`0x600d9700`). | 1 caller / 0 callees |
| `0x600d96cc` |  16 | System / Validate | **`mode_is_valid_0_1_7`** — Mode / state validation predicate: returns true if `param_1 <= 1 || param_1 == 7`. | 0 callers / 0 callees |
| `0x600d96dc` |  12 | System / Validate | **`range_is_valid_3_to_5`** — Range validation predicate: returns true if `param_1 - 3U < 3` (values 3, 4, 5). | 0 callers / 0 callees |
| `0x600d96e8` |  12 | System / Validate | **`range_is_valid_5_to_7`** — Range validation predicate: returns true if `param_1 - 5U < 3` (values 5, 6, 7). | 0 callers / 0 callees |
| `0x600d96f4` |  12 | System / Validate | **`range_is_valid_1_to_3`** — Range validation predicate: returns true if `param_1 - 1U < 3` (values 1, 2, 3). | 0 callers / 0 callees |
| `0x600d9700` | 154 | Controller / Calib | **`interpolate_float_curve`** — Floating-point piecewise-linear calibration curve interpolator: checks NaN / bounds, binary searches 8-byte entry float table `param_2` via `comparator_float_less`, converts fixed-point vector scale, and calculates linear interpolation. Called by `switch_pro_controller.cc` (`0x60070ad0`, `0x60070dcc`) and `0x600712c8`. | 3 callers / 1 callee |

## Session 68 (Wave 38) — Piecewise Interpolators, Property Queries, Vtable Dispatch & Event Post (20 functions, 712 bytes)

Decompiled and documented 20 functions (712 bytes across `0x600d97a6`–`0x600d9c7a`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d97a6` |  14 | Utilities / Compare | **`comparator_ushort_less`** — Unsigned 16-bit less-than comparator predicate: returns `*param_1 < *param_2`. Called by `FUN_600d97c4`. | 1 caller / 0 callees |
| `0x600d97b6` |  14 | System / Init | **`struct_clear_12b_6`** — 12-byte structure zeroer: clears 12 bytes via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 1 callee |
| `0x600d97c4` | 102 | Controller / Calib | **`interpolate_piecewise_linear_4b`** — 4-byte entry piecewise-linear calibration interpolator: binary searches 4-entry ushort table `param_1` using `comparator_ushort_less` and computes linear interpolation. Called by `0x60070bf4`. | 1 caller / 1 callee |
| `0x600d9832` |  14 | System / Init | **`struct_clear_12b_7`** — 12-byte structure zeroer: clears 12 bytes via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 1 callee |
| `0x600d9840` |  14 | Utilities / Compare | **`comparator_ushort_less_alt`** — Alternate unsigned 16-bit less-than comparator predicate: returns `*param_1 < *param_2`. Called by `FUN_600d988c`. | 1 caller / 0 callees |
| `0x600d9850` |  46 | Controller / Calib | **`calib_descriptor_init_type9`** — Type-9 calibration descriptor initializer: zeroes 13 bytes via `thunk_EXT_FUN_0000b5ba`, sets `*param_2 = 9`, `param_2[3] = 9`, `param_2[5] = 3`, `param_2[10] = 0xff`, and stores upper bytes of `param_3` at `param_2[8]` and `param_4` at `param_2[9]`. | 0 callers / 1 callee |
| `0x600d987e` |  14 | System / Init | **`struct_clear_12b_8`** — 12-byte structure zeroer: clears 12 bytes via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 1 callee |
| `0x600d988c` | 102 | Controller / Calib | **`interpolate_piecewise_linear_4b_alt`** — Alternate 4-byte entry piecewise-linear calibration interpolator: binary searches 3-entry ushort table `param_1` using `comparator_ushort_less_alt` and computes linear interpolation. | 0 callers / 1 callee |
| `0x600d9910` |  14 | System / Init | **`struct_clear_12b_9`** — 12-byte structure zeroer: clears 12 bytes via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 1 callee |
| `0x600d9926` |  14 | System / Init | **`struct_clear_12b_10`** — 12-byte structure zeroer: clears 12 bytes via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 1 callee |
| `0x600d9934` |  40 | System / Property | **`device_property_query_bit8`** — Device property query helper: queries property `0x26` via `FUN_60071348`, extracts bit 8 (`((local_c >> 8) ^ 1) & 1`), stores result at `*param_1`. Called by `0x600d7cdc` and `0x60077140`. | 2 callers / 1 callee |
| `0x600d995c` |  44 | System / Property | **`device_property_query_mask_c00000`** — Device property query helper: queries property `6` via `FUN_60071348`, checks mask `(local_c & 0xc00000) != 0xc00000`, stores boolean at `*param_1`. Called by `0x600d7cc4` and `0x60077140`. | 2 callers / 1 callee |
| `0x600d9988` |  36 | System / Property | **`device_property_query_val3`** — Device property query helper: queries property `0x2f` via `FUN_60071348`, checks `(local_c & 7) == 3`, stores boolean at `*param_1`. Called by `0x60077140`. | 1 caller / 1 callee |
| `0x600d99ac` |   4 | System / Constants | **`constant_3_getter`** — Trivial constant getter: returns 3. Called by `0x60059100`. | 1 caller / 0 callees |
| `0x600d99f2` |  14 | System / Init | **`struct_clear_216b`** — 216-byte structure zeroer: clears 216 bytes (`0xd8`) via `thunk_EXT_FUN_0000b52e(param_1, 0xd8)`. | 0 callers / 1 callee |
| `0x600d9a00` |  38 | Gotham / RX | **`gotham_rx_event_dispatch_if_active`** — Gotham RX event forwarder: checks byte flag at `*(param_1 + 200)` with ARM `DMB` barriers, calling `FUN_600d4df0()` if non-zero. | 0 callers / 1 callee |
| `0x600d9a26` |  48 | System / Vtable | **`vtable_chain_dispatch_4`** — 4-element vtable method chain dispatcher: iterates 4 pointers `param_1 + 4`..`param_1 + 0x14`, invoking method `*(vtable + 4)` on each until non-zero error or all 4 succeed. | 0 callers / 0 callees |
| `0x600d9ae2` | 100 | Controller / Mode | **`controller_mode_code_map`** — Controller mode code lookup: switches on mode parameter `param_1` (cases 2/3 -> 1, 4 -> 3, 5 -> 4, 6 -> 5, default -> 0). Called by `0x60071478`. | 1 caller / 0 callees |
| `0x600d9b4c` |  16 | System / Init | **`struct_clear_84b`** — 84-byte structure zeroer: zeroes 80 bytes (`0x50`) via `thunk_EXT_FUN_0000b5ba` and zeroes trailing word `*(iVar1 + 0x50) = 0`. Called by `0x600723b4`, `0x600722b0`, `0x60071660`. | 3 callers / 1 callee |
| `0x600d9c7a` |  24 | Events / Async | **`async_event_post_type5`** — Asynchronous event poster: posts event type 5 with context `*(param_1 + 4)` via `thunk_EXT_FUN_00007a2c`. Called by `FUN_600d9c92`. | 1 caller / 1 callee |

## Session 69 (Wave 39) — Event Cascades, State Machine Engines, Table Zeroers & Object Cleanup (20 functions, 1,238 bytes)

Decompiled and documented 20 functions (1,238 bytes across `0x600d9c92`–`0x600da40c`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600d9c92` |  50 | Events / Async | **`async_event_post_type5_chain`** — Asynchronous event cascade poster: posts event type 5 with context `*(param_1 + 0x6be4)` via `thunk_EXT_FUN_00007a2c`, then invokes `async_event_post_type5` (`0x600d9c7a`) on sub-structures `param_1 + 0x6ad0` and `param_1 + 0x6a2c`. | 0 callers / 2 callees |
| `0x600d9cc4` | 152 | Controller / Descr | **`controller_descriptor_init_with_mode`** — Controller descriptor structure builder: delegates to `FUN_60071478` with ~~14~~ **13 (corrected, QA session 69)** arguments (`param_1`..`param_9` plus the 4 dereferenced pointers `*param_11`..`*param_14`; `param_10` is not passed), maps mode code `param_7` (1..5) and length `param_8` (< 16 vs >= 16) to 16-bit status code `0x50`..`0x59` (or `0xff80` default) at `param_1 + 0x2c`, setting `*(param_1 + 0x38) = param_8`, `*(param_1 + 0x30) = 5`, `*(param_1 + 0x34) = param_7`. Called from `0x600723b4`. | 1 caller / 1 callee |
| `0x600d9e28` |  64 | App / State | **`app_state_query_handler`** — Application state query helper: invokes indirect method `*(vtable + 0x1c)` from `**(param_2 + 0x5c)`, unpacks status flags `local_14`/`local_13`/`local_12`, and sets output struct fields `*param_1 = local_1c[0]`, `*(param_1 + 1) = 1`, `*(param_1 + 2) = 1`, `*(param_1 + 9) = local_13`, `*(param_1 + 10) = 1` (zeroes fields on false). | 0 callers / 0 callees |
| `0x600d9eee` |  64 | App / State | **`app_state_query_handler_alt`** — Alternate application state query helper: duplicate structure of `0x600d9e28`, invoking `*(vtable + 0x1c)` from `**(param_2 + 0x5c)` and populating output state struct `param_1`. | 0 callers / 0 callees |
| `0x600d9f4e` |  14 | System / Init | **`struct_clear_4b`** — 4-byte structure zeroer: clears 4 bytes via `thunk_EXT_FUN_0000b52e(param_1, 4)`. | 0 callers / 1 callee |
| `0x600d9f5c` |  14 | System / Init | **`struct_clear_20b_1`** — 20-byte structure zeroer: clears 20 bytes (`0x14`) via `thunk_EXT_FUN_0000b52e(param_1, 0x14)`. | 0 callers / 1 callee |
| `0x600d9f6a` |  14 | System / Init | **`struct_clear_20b_2`** — 20-byte structure zeroer: clears 20 bytes (`0x14`) via `thunk_EXT_FUN_0000b52e(param_1, 0x14)`. | 0 callers / 1 callee |
| `0x600d9fbe` |  68 | App / State | **`state_transition_table_binary_search_8b`** — 8-byte entry transition table binary search: binary searches 4-entry / 8-byte stride table `*(param_1 + 0x70)` for key `param_2`, returns value `piVar4[1]` (or fallback entry `+0x20`). | 0 callers / 0 callees |
| `0x600da0d8` |  26 | App / State | **`state_record_copy_5b`** — 5-byte state record copier: conditionally copies 4-byte payload `*param_2` to `*param_1` when `*(param_2 + 1) != 0`, setting `*(param_1 + 1)`, `*(param_1 + 2)`, `*(param_1 + 9)`, and `*(param_1 + 10)`. Called by `app_state_machine_transition_engine_4` (`0x600da0f2`). | 1 caller / 0 callees |
| `0x600da0f2` | 280 | App / State | **`app_state_machine_transition_engine_4`** — Application state machine transition engine (4-entry table): binary searches 4-entry / 12-byte stride table `param_2[0x1a]` for state `param_3`, checks event `param_4` in transition list `piVar4[1]` (or fallback array `param_2[0x1b]`), executes action handler `*(param_2 + 0x28)`, copies state record via `state_record_copy_5b`, and sets transition status `*(param_1 + 10)`. | 0 callers / 1 callee |
| `0x600da230` |  26 | App / State | **`state_record_copy_5b_alt`** — Alternate 5-byte state record copier: conditionally copies 4-byte payload `*param_2` to `*param_1` when `*(param_2 + 1) != 0`, setting `*(param_1 + 1)`, `*(param_1 + 2)`, `*(param_1 + 9)`, and `*(param_1 + 10)`. Called by `app_state_machine_transition_engine_3` (`0x600da24a`). | 1 caller / 0 callees |
| `0x600da24a` | 270 | App / State | **`app_state_machine_transition_engine_3`** — Application state machine transition engine (3-entry table): binary searches 3-entry / 12-byte stride table `param_2[0x1a]` for state `param_3`, checks event `param_4` in transition list `piVar4[1]` (or fallback array `param_2[0x1b]`), executes action handler `*(param_2 + 0x28)`, copies state record via `state_record_copy_5b_alt`, and sets transition status `*(param_1 + 10)`. Called by `app_state_event_dispatch_flag_set` (`0x600da358`). | 1 caller / 1 callee |
| `0x600da358` |  52 | App / State | **`app_state_event_dispatch_flag_set`** — Application state event pre-filter & dispatcher: updates flag bytes `*(param_2 + 0x78)` (cases 8/9 -> 1/0) or `*(param_2 + 0x79)` (cases 2/3 -> 1/0) and forwards to `app_state_machine_transition_engine_3` (`0x600da24a`). | 0 callers / 1 callee |
| `0x600da394` |  20 | System / Init | **`system_object_init_96b_1`** — 96-byte object initializer: calls `FUN_60074cc8` and clears 96 bytes (`0x60`) via `thunk_EXT_FUN_0000b52e(param_1, 0x60)`. | 0 callers / 2 callees |
| `0x600da3a8` |  20 | System / Init | **`system_object_init_96b_2`** — 96-byte object initializer: calls `FUN_60074ce4` and clears 96 bytes (`0x60`) via `thunk_EXT_FUN_0000b52e(param_1, 0x60)`. | 0 callers / 2 callees |
| `0x600da3bc` |  20 | System / Init | **`system_object_init_128b_1`** — 128-byte object initializer: calls `FUN_60074cf8` and clears 128 bytes (`0x80`) via `thunk_EXT_FUN_0000b52e(param_1, 0x80)`. | 0 callers / 2 callees |
| `0x600da3d0` |  20 | System / Init | **`system_object_init_96b_3`** — 96-byte object initializer: calls `FUN_60074d10` and clears 96 bytes (`0x60`) via `thunk_EXT_FUN_0000b52e(param_1, 0x60)`. | 0 callers / 2 callees |
| `0x600da3e4` |  20 | System / Init | **`system_object_init_128b_2`** — 128-byte object initializer: calls `FUN_60074d24` and clears 128 bytes (`0x80`) via `thunk_EXT_FUN_0000b52e(param_1, 0x80)`. | 0 callers / 2 callees |
| `0x600da3f8` |  20 | System / Init | **`system_object_init_12b`** — 12-byte object initializer: calls `FUN_60074d3c` and clears 12 bytes (`0xc`) via `thunk_EXT_FUN_0000b52e(param_1, 0xc)`. | 0 callers / 2 callees |
| `0x600da40c` |  24 | System / Cleanup | **`system_object_destructor_free`** — System object destructor and deallocator: calls destructor `FUN_60074d3c(*(param_1 + 0x10))` and deallocates memory via `thunk_EXT_FUN_0000b52a` (`vPortFree`). | 0 callers / 2 callees |

## Session 70 (Wave 40) — Audio State Moves, Ref-Counted Pointers, Headphone State & Mutex Dispatch (20 functions, 626 bytes)

Decompiled and documented 20 functions (626 bytes across `0x600da424`–`0x600da810`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600da424` |  40 | Audio / State | **`audio_state_move_assignment`** — Audio state 8-byte move assignment: moves `(param_2[0], param_2[1])` to `(param_1[0], param_1[1])`, zeroes source `param_2`, and destroys old destination pointer via `thunk_EXT_FUN_00001680(&local_c)`. Called by `audio_states__60075088`. | 1 caller / 1 callee |
| `0x600da44c` |  20 | Audio / State | **`audio_state_init_100b`** — 100-byte audio state initializer: calls `audio_states__60074e6c()` and zeroes 100 bytes via `thunk_EXT_FUN_0000b52e(param_1, 100)`. | 0 callers / 2 callees |
| `0x600da460` |  24 | Audio / State | **`audio_state_destructor_free`** — Audio state destructor & deallocator: calls destructor `audio_states__60074e6c` on `*(param_1 + 0x10)` and frees memory via `thunk_EXT_FUN_0000b52a` (`vPortFree`). | 0 callers / 2 callees |
| `0x600da478` |  18 | Audio / RefCount | **`ref_counted_ptr_copy`** — Reference-counted pointer copy constructor / assignment helper: copies `*param_2` to `*param_1` and calls add-ref `FUN_60074ec8()` if non-null. 9 callers across `audio_states.cc`, `recording_pipeline.cc`, `receiver.cc`, `audio_tasks.cc`! | 9 callers / 1 callee |
| `0x600da48a` |  34 | Audio / RefCount | **`ref_counted_ptr_assign`** — Reference-counted pointer copy assignment operator: compares `*param_1` and `*param_2`, calls add-ref `FUN_60074ec8(*param_2)` on new pointer, release `FUN_6005c44c()` on old pointer, and stores `*param_1 = *param_2`. 5 callers! | 5 callers / 2 callees |
| `0x600da4ac` |  54 | Audio / Config | **`audio_config_table_binary_search_13`** — 13-entry binary search: binary searches 13-entry / 8-byte stride table `param_1` for key `param_2`, returning matched/lower bound entry pointer. Called by `0x600da4e2` and `0x600da4fc`. | 2 callers / 0 callees |
| `0x600da4e2` |  26 | Audio / Config | **`audio_config_lookup_param_74`** — Audio configuration property lookup: searches 13-entry table `*(param_1 + 0x74)` via `audio_config_table_binary_search_13`, returning value `piVar1[1]` (or default entry at `+0x68`). | 0 callers / 1 callee |
| `0x600da4fc` |  26 | Audio / Config | **`audio_config_lookup_param_74_alt`** — Alternate audio configuration property lookup: duplicate of `0x600da4e2`, searching 13-entry table `*(param_1 + 0x74)` and returning `piVar1[1]`. | 0 callers / 1 callee |
| `0x600da58a` |   6 | Audio / Dispatch | **`audio_event_dispatch_tail_7b0`** — Audio event dispatch thunk: offsets context `param_1 + 8` and tail-calls `FUN_600da7b0`. | 0 callers / 1 callee |
| `0x600da590` |   6 | Audio / Dispatch | **`audio_event_dispatch_tail_71e`** — Audio event dispatch thunk: offsets context `param_1 + 8` and tail-calls `0x600da71e`. Called by `audio_states__60074d54`. | 1 caller / 0 callees |
| `0x600da596` |  20 | Headphone / Init | **`headphone_state_init_224b`** — 224-byte headphone state initializer: calls `FUN_60075b00()` and clears 224 bytes (`0xe0`) via `thunk_EXT_FUN_0000b52e(param_1, 0xe0)`. | 0 callers / 2 callees |
| `0x600da62e` |  64 | Audio / State | **`audio_channel_state_query`** — Audio channel state query helper: invokes indirect method `*(vtable + 0x1c)` from `**(param_2 + 0x5c)`, unpacks status flags, and sets output struct `param_1`. | 0 callers / 0 callees |
| `0x600da67e` |  30 | Headphone / State | **`headphone_buffer_slice_update`** — Headphone buffer slice updater: computes slice offset `*param_1 + param_1[2]` and length `param_1[1] - param_1[2]`, calls `FUN_600cc4a8`, and stores result via `FUN_60101ba2(param_1, uVar1)`. Called by `headphone_state_machine__60075c50`. | 1 caller / 2 callees |
| `0x600da6da` |  68 | Audio / State | **`audio_state_transition_search_8b`** — 4-entry audio state transition table binary search: binary searches 4-entry / 8-byte stride table `*(param_1 + 0x74)` for key `param_2`, returns `piVar4[1]` (or fallback at `+0x20`). | 0 callers / 0 callees |
| `0x600da766` |  22 | Audio / Tasks | **`audio_task_handle_copy`** — Audio task handle copy helper: checks flag `*(param_2 + 0x28)`, copies 4-byte handle `*(param_2 + 0x24)` to `*param_1` and sets boolean flag `*(param_1 + 1)`. Called by `audio_task_status_poll` (`0x600da77c`). | 1 caller / 0 callees |
| `0x600da77c` |  52 | Audio / Tasks | **`audio_task_status_poll`** — Audio task status poller & exception check: queries task handle via `audio_task_handle_copy`, invokes vtable method `*(vtable + 0x10)` on `param_1` if flag is 0, or raises panic exception via `FUN_6010209a()` on fatal condition. Called by `audio_task_is_active_predicate` (`0x600da7b0`). | 1 caller / 2 callees |
| `0x600da7b0` |  14 | Audio / Tasks | **`audio_task_is_active_predicate`** — Audio task active status predicate: calls `audio_task_status_poll()` and returns boolean `iVar1 != 0`. Called by `audio_event_dispatch_tail_7b0` (`0x600da58a`). | 1 caller / 1 callee |
| `0x600da7be` |  62 | Headphone / State | **`headphone_state_event_dispatch_mutex`** — Mutex-guarded headphone state event dispatcher: acquires mutex at `param_1 + 0x80` via `thunk_EXT_FUN_0000b4c2`, dispatches event code `param_2` (case 1 -> `headphone_state_machine__60075c50`, case 2 -> `headphone_state_machine__60075d78`), and releases mutex via `thunk_EXT_FUN_00007d10`. | 0 callers / 4 callees |
| `0x600da7fc` |  20 | Headphone / Init | **`headphone_object_init_96b`** — 96-byte headphone object initializer: calls `FUN_60075ee0()` and clears 96 bytes (`0x60`) via `thunk_EXT_FUN_0000b52e(param_1, 0x60)`. | 0 callers / 2 callees |
| `0x600da810` |  20 | Headphone / Init | **`headphone_object_init_216b`** — 216-byte headphone object initializer: calls `FUN_60075f04()` and clears 216 bytes (`0xd8`) via `thunk_EXT_FUN_0000b52e(param_1, 0xd8)`. | 0 callers / 2 callees |

## Session 71 (Wave 41) — State Machine Engines, Async Events, Headphone Inits & Neutral Joystick Predicates (20 functions, 1,092 bytes)

Decompiled and documented 20 functions (1,092 bytes across `0x600da824`–`0x600dad0e`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600da824` |  26 | App / State | **`state_record_copy_5b_twin`** — 5-byte state record copier: conditionally copies 4-byte payload `*param_2` to `*param_1` when `*(param_2 + 1) != 0`, setting `*(param_1 + 1)`, `*(param_1 + 2)`, `*(param_1 + 9)`, and `*(param_1 + 10)`. Called by `app_state_machine_transition_engine_3_twin` (`0x600da83e`). | 1 caller / 0 callees |
| `0x600da83e` | 270 | App / State | **`app_state_machine_transition_engine_3_twin`** — Application state machine transition engine (3-entry table): binary searches 3-entry / 12-byte stride table `param_2[0x1a]` for state `param_3`, checks event `param_4` in transition list `piVar4[1]` (or fallback array `param_2[0x1b]`), executes action handler `*(param_2 + 0x28)`, copies state record via `state_record_copy_5b_twin`, and sets transition status `*(param_1 + 10)`. | 0 callers / 1 callee |
| `0x600da952` |   2 | System / Stubs | **`noop_stub_600da952`** — Trivial empty return stub (`bx lr`). Called by `FUN_60076040`. | 1 caller / 0 callees |
| `0x600da9ba` |  68 | App / State | **`state_transition_search_8entry_8b`** — 8-entry state transition table binary search: binary searches 8-entry / 8-byte stride table `*(param_1 + 0x70)` for key `param_2`, returns value `piVar4[1]` (or fallback entry at `+0x40`). | 0 callers / 0 callees |
| `0x600da9fe` |  68 | App / State | **`state_transition_search_10entry_8b`** — 10-entry state transition table binary search: binary searches 10-entry / 8-byte stride table `*(param_1 + 0x74)` for key `param_2`, returns value `piVar4[1]` (or fallback entry at `+0x50`). | 0 callers / 0 callees |
| `0x600daa60` |  40 | Events / Async | **`async_event_post_type1_with_timestamp`** — Timed event poster (event type 1): fetches system tick count via `thunk_EXT_FUN_0000714c()`, posts type 1 event via `thunk_EXT_FUN_00007a2c(param_1, 1, timestamp, 0, 10, param_2)`, returns status 0 on success / 4 on failure. | 0 callers / 2 callees |
| `0x600daa88` |  30 | Events / Async | **`async_event_post_type3`** — Asynchronous event poster (event type 3): posts event type 3 via `thunk_EXT_FUN_00007a2c(param_1, 3, 0, 0, 10, param_2, param_3)`, returns status 0 (if 1) / 4. Called by `async_event_post_type3_triple` (`0x600daaa6`). | 1 caller / 1 callee |
| `0x600daaa6` |  32 | Events / Async | **`async_event_post_type3_triple`** — Triple event poster: invokes `async_event_post_type3` on descriptors at offsets `*(param_1 + 0x110)`, `*(param_1 + 0x150)`, and `*(param_1 + 0x190)`. | 0 callers / 1 callee |
| `0x600daac6` |  26 | App / State | **`state_record_copy_5b_quad`** — 5-byte state record copier: conditionally copies 4-byte payload `*param_2` to `*param_1` when `*(param_2 + 1) != 0`. Called by `app_state_machine_transition_engine_8` (`0x600daae0`). | 1 caller / 0 callees |
| `0x600daae0` | 226 | App / State | **`app_state_machine_transition_engine_8`** — Application state machine transition engine (8-entry table): binary searches 8-entry / 12-byte stride table `*(param_2 + 0x68)` for state `param_3`, checks event `param_4` in transition list `piVar1[1]` (or fallback array `*(param_2 + 0x6c)`), copies state record via `state_record_copy_5b_quad`, and sets transition status `*(param_1 + 10)`. Called by `app_state_lookup_and_format` (`0x600dabc2`). | 1 caller / 1 callee |
| `0x600dabc2` |  62 | App / State | **`app_state_lookup_and_format`** — Application state query and transition wrapper: invokes `app_state_machine_transition_engine_8` on `*(param_2 + 0x5c)`, formats return struct flags in `param_1`. | 0 callers / 1 callee |
| `0x600dac00` |  22 | Headphone / Init | **`headphone_object_init_464b`** — 464-byte headphone object initializer: calls `FUN_60075fd0()` and clears 464 bytes (`0x1d0`) via `thunk_EXT_FUN_0000b52e(param_1, 0x1d0)`. | 0 callers / 2 callees |
| `0x600dac16` |  20 | Headphone / Init | **`headphone_object_init_96b_alt`** — 96-byte headphone object initializer: calls `FUN_60075fac()` and clears 96 bytes (`0x60`) via `thunk_EXT_FUN_0000b52e(param_1, 0x60)`. | 0 callers / 2 callees |
| `0x600dac3c` |  22 | Headphone / Init | **`headphone_object_init_1056b`** — 1056-byte headphone object initializer: calls `FUN_600763b0()` and clears 1056 bytes (`0x420`) via `thunk_EXT_FUN_0000b52e(param_1, 0x420)`. | 0 callers / 2 callees |
| `0x600dac52` |  22 | Headphone / Init | **`headphone_object_init_4344b`** — 4344-byte headphone object initializer: calls `FUN_600763e8()` and clears 4344 bytes (`0x10f8`) via `thunk_EXT_FUN_0000b52e(param_1, 0x10f8)`. | 0 callers / 2 callees |
| `0x600dac8a` |  10 | System / Events | **`system_reset_or_event_trigger_type2`** — System event trigger wrapper: invokes `thunk_EXT_FUN_00002480(2)`. | 0 callers / 1 callee |
| `0x600dac94` |  48 | Controller / Sticks | **`joystick_neutral_pos_predicate_5arg`** — 5-argument joystick neutral position validator: checks if stick axes `*param_3 == 0x800` (2048, center), `param_3[1] == 0x800`, `*param_2 == 0x800`, `param_2[1] == 0x800`, and triggers `param_4 == 0`, `param_5 == 0`. Returns true if all at center / rest. | 0 callers / 0 callees |
| `0x600dacc4` |  50 | Controller / Sticks | **`joystick_neutral_pos_predicate_struct`** — Struct-based joystick neutral position validator: checks if fields `param_2 + 0x1c`, `+0x20`, `+0x24`, `+0x28` are all `0x800` (2048, center), and `+0x2c`, `+0x30` are 0. Returns true if all at rest. | 0 callers / 0 callees |
| `0x600dacf6` |  24 | System / Locks | **`mutex_locked_action_invoke_1`** — Mutex-locked action invoker: acquires mutex via `thunk_EXT_FUN_0000b4c2()`, invokes action handler with context `&local_c` (`param_1 + 8`) via `thunk_EXT_FUN_0000887a(&local_c)`. | 0 callers / 2 callees |
| `0x600dad0e` |  24 | System / Locks | **`mutex_locked_action_invoke_2`** — Mutex-locked action invoker: identical pattern to `0x600dacf6`, acquiring mutex and invoking action handler via `thunk_EXT_FUN_0000887a(&local_c)`. | 0 callers / 2 callees |

## Session 72 (Wave 42) — Red-Black Tree Maps, Ring Buffers, Audio Pipes & Transport State (20 functions, 1,100 bytes)

Decompiled and documented 20 functions (1,100 bytes across `0x600dadaa`–`0x600db2be`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600dadaa` |  50 | Audio / Buffer | **`buffer_slice_append_stream`** — Stream buffer slice appender: checks buffer capacity via `FUN_600cc3cc()`, appends data via `FUN_60050c18`, updates slice length with tag `0x7d` via `FUN_601019da`. Called by `0x6007694c`. | 1 caller / 3 callees |
| `0x600daddc` |  34 | Audio / Buffer | **`buffer_slice_advance_int`** — Buffer slice advance helper: converts signed integer `param_2` via `FUN_60101b0c` into buffer slice and updates slice offset via `FUN_60101ba2`. Called by `0x60076ba0`. | 1 caller / 2 callees |
| `0x600dadfe` |  30 | Data / Tree | **`rb_tree_destroy_nodes`** — Red-black tree recursive node destruction helper: traverses left/right children (`+0xc`, `+8`), frees tree node memory via `thunk_EXT_FUN_0000b52a` (`vPortFree`). | 3 callers / 2 callees |
| `0x600dae1c` | 164 | Data / Tree | **`rb_tree_erase_range`** — Red-black tree key range eraser (`std::map::erase`): finds key bounds, deletes subtree nodes via `rb_tree_destroy_nodes` if root matches or unlinks node-by-node via `FUN_60101d22`/`FUN_60101e12` and `vPortFree`, decrementing tree size `*(param_1 + 0x14)`. Called by `0x60076ba0`. | 1 caller / 4 callees |
| `0x600daec0` |  42 | Data / Tree | **`rb_tree_find_key`** — Red-black tree key lookup (`std::map::find`): traverses binary search tree root `*(param_1 + 8)` comparing key `*param_2` against node key `*(node + 0x10)`, returning node pointer or end sentinel `param_1 + 4`. Called by `0x60076e1c`. | 1 caller / 0 callees |
| `0x600daeea` |  80 | Data / Tree | **`rb_tree_insert_lookup`** — Red-black tree insertion location finder: traverses BST to find parent insertion spot for key `*param_3`, returning `(node, 0)` if key exists or `(0, parent)` for new node insertion. | 2 callers / 1 callee |
| `0x600daf3a` | 100 | Data / Tree | **`rb_tree_insert_node_1`** — Red-black tree node allocator & inserter: calls `rb_tree_insert_lookup`, allocates 20-byte node via `thunk_EXT_FUN_0000b532` (`pvPortMalloc`), sets node key `*(node + 0x10) = *param_3`, rebalances tree via `FUN_60101d4e`, and increments size `*(param_2 + 0x14)`. | 1 caller / 3 callees |
| `0x600daf9e` | 100 | Data / Tree | **`rb_tree_insert_node_2`** — Red-black tree node allocator & inserter: duplicate instantiation of `0x600daf3a`. Called by `0x60076ba0`. | 1 caller / 3 callees |
| `0x600db002` |  18 | Utilities / String | **`strnlen_custom`** — Bounded string length scanner (`strnlen`): scans string `param_1` up to maximum length `param_2` until null terminator, returning byte count. 8 callers across `key_value_store.cc` and utilities! | 8 callers / 0 callees |
| `0x600db056` |  76 | Audio / Stream | **`dual_buffer_stream_copy`** — Dual-buffer streaming copy helper: computes available bytes from primary buffer `(param_1 + 8, +0xc)` or secondary buffer `(param_1 + 0x10, +0x14)`, copies data via `thunk_EXT_FUN_0000b572` (`memcpy`), advances read offsets `+0x18` / `+0x1c`, and writes copied length to `*param_4`. | 0 callers / 1 callee |
| `0x600db0a2` |  14 | System / Init | **`struct_clear_32b`** — 32-byte structure zeroer: clears 32 bytes (`0x20`) via `thunk_EXT_FUN_0000b52e(param_1, 0x20)`. | 0 callers / 1 callee |
| `0x600db0b0` |  14 | System / Init | **`struct_clear_20b_3`** — 20-byte structure zeroer: clears 20 bytes (`0x14`) via `thunk_EXT_FUN_0000b52e(param_1, 0x14)`. | 0 callers / 1 callee |
| `0x600db0be` |  24 | Audio / Buffer | **`audio_buffer_pool_init_6080b`** — Audio buffer pool initializer: calls `FUN_6007758c()` and initializes 6080-byte buffer pool (`0x17c0`) with 32-byte element stride (`0x20`) via `FUN_60101c60`. | 0 callers / 2 callees |
| `0x600db11a` |  34 | Audio / Stream | **`audio_stream_buffer_fetch`** — Audio stream buffer fetch helper: calls `FUN_60050c18` on buffer slice and updates offset via `FUN_60101ba2`. Called by `0x60077948` and `0x60077a48`. | 2 callers / 2 callees |
| `0x600db14c` |  60 | Audio / RingBuf | **`ring_buffer_pop_front_256b`** — 256-byte ring buffer pop helper: pops up to `param_3` bytes from buffer `param_1`, copies to destination `param_2` via `memcpy`, shifts remaining bytes down via `memmove` (`thunk_EXT_FUN_0000b588`), and decrements size `*(param_1 + 0x100)`. Called by `0x60077750`. | 1 caller / 2 callees |
| `0x600db188` |  40 | Audio / RingBuf | **`ring_buffer_push_back_256b`** — 256-byte ring buffer push helper: appends up to `param_3` bytes into buffer `param_1` at offset `*(param_1 + 0x100)` via `memcpy`, and increments size `*(param_1 + 0x100)`. | 0 callers / 1 callee |
| `0x600db1b0` |  62 | Audio / Pipe | **`audio_pipe_receive_packet_256b`** — Audio pipe packet receiver: receives 256-byte packet via `FUN_600d4f98`, resets lock/state at `param_1 + 0x108` via `FUN_60101818`, updates overflow flag at `+0x104`, and triggers event via `thunk_EXT_FUN_00000f80(param_1, 0x100)`. Called by `0x60077750`. | 1 caller / 3 callees |
| `0x600db1ee` |  88 | Audio / Pipe | **`audio_pipe_send_packet_256b`** — Audio pipe packet transmitter: formats packet via `thunk_EXT_FUN_00000fac`, transmits via `FUN_600d4f6c`, handles timeout/completion at `param_1 + 0x108` via `FUN_60101818`/`FUN_60101822`, and clears buffer count `*(param_1 + 0x100) = 0`. | 0 callers / 5 callees |
| `0x600db28e` |  18 | Audio / Cleanup | **`struct_cleanup_32b_if_nonnull`** — Null-guarded 32-byte structure cleanup: frees 32-byte payload at `*(param_1 + 4)` via `thunk_EXT_FUN_00008844(*(param_1 + 4), 0x20)` if non-null. | 0 callers / 1 callee |
| `0x600db2be` |  52 | Audio / Transport | **`audio_transport_state_action_dispatch`** — Audio transport state action dispatcher: checks state `*(param_1 + 8) == 3` and mode `*(param_1 + 0x10) == 3`, calls `FUN_6005bdac()`, triggers transport event `(1, 7, 1, 0)` via `thunk_EXT_FUN_00001834`, and returns status 2. | 0 callers / 2 callees |

## Session 73 (Wave 43) — Firmware Upload Contexts, Flash Stream Writers, Calibration Engines & Crypto Dispatch (20 functions, 1,188 bytes)

Decompiled and documented 20 functions (1,188 bytes across `0x600db2fc`–`0x600db800`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600db2fc` |  14 | System / Init | **`struct_clear_20b_4`** — 20-byte structure zeroer: clears 20 bytes (`0x14`) via `thunk_EXT_FUN_0000b52e(param_1, 0x14)`. | 0 callers / 1 callee |
| `0x600db30a` |  34 | Firmware / Upload | **`firmware_upload_stream_fetch_1`** — Firmware upload stream buffer fetch helper: calls `FUN_60050c18` on buffer slice and updates slice offset via `FUN_60101ba2`. Called by `firmware_image_upload__60078340`. | 1 caller / 2 callees |
| `0x600db32c` |  34 | Firmware / Upload | **`firmware_upload_stream_fetch_2`** — Firmware upload stream buffer fetch helper: duplicate instantiation of `0x600db30a`. Called by `firmware_image_upload__60078340`. | 1 caller / 2 callees |
| `0x600db34e` |  30 | HTTP / Request | **`http_request_state_destructor_free`** — HTTP request state destructor: checks dynamic buffer at `*(iVar1 + 0xa8) != iVar1 + 0xb0`, frees via `vPortFree` (`thunk_EXT_FUN_0000b52a`), then frees object `iVar1`. | 0 callers / 1 callee |
| `0x600db36c` |  40 | Firmware / Upload | **`firmware_upload_context_init`** — Firmware upload context initializer: initializes 256-byte upload buffer context (`*param_1 = param_2`, `param_1[1] = param_2 + 0x19`, `param_1[2] = 0x100`, `param_2[8] = 2`, `param_2[0x10] = 1`, `param_2[0x14] = param_3`). Called by `firmware_image_upload__60078340`, `0x60078da8`, and `0x60078e00`. | 3 callers / 0 callees |
| `0x600db394` |  14 | Firmware / Upload | **`firmware_upload_status_update`** — Firmware upload status updater: sets boolean flag `*(bool *)(*param_1 + 0x18) = param_1[3] != 0`. Called by upload routines. | 3 callers / 0 callees |
| `0x600db3a2` |  20 | Firmware / Upload | **`firmware_upload_buffer_reset`** — Firmware upload buffer reset helper: sets `*(undefined1 *)(*param_1 + 0x18) = 1` and resets slice via `FUN_600d37ac(param_1 + 1)`. | 3 callers / 1 callee |
| `0x600db3b6` |  38 | Flash / Partition | **`partition_write_abort_or_finalize`** — Flash partition table write finalize/abort dispatcher: sets flags at `+0x114` and `+1`, retrieves partition table descriptor via `partition_table__6007818c`, dispatches vtable destructor/abort via `(**(code **)*puVar2)(puVar2, 0, 1)`. Called by `firmware_image_upload__60078340` and `0x60078218`. | 2 callers / 2 callees |
| `0x600db3dc` |  14 | System / Cleanup | **`struct_field_cleanup_1680`** — Structure field destructor: cleans field at `param_1 + 4` via `thunk_EXT_FUN_00001680`. | 0 callers / 1 callee |
| `0x600db3ea` |  30 | System / Memory | **`byte_buffer_copy_or_assign`** — Single byte vs block buffer copy: if length is 1, stores single byte `*param_1 = *param_2`; otherwise copies block via `memcpy` (`thunk_EXT_FUN_0000b572`). Called by `firmware_image_upload__60078340`. | 1 caller / 1 callee |
| `0x600db408` |  54 | Audio / Transport | **`transport_action_state_reset`** — Transport action state reset handler: checks state `*(param_1 + 8) == 3` and mode `*(param_1 + 0x10) == 6`, resets endpoints via `FUN_600d3dd8(0, 0xc)` and `FUN_600d3dd8(0, 0)`, returns status 2. | 0 callers / 1 callee |
| `0x600db43e` | 300 | Audio / Calibration | **`headphone_audio_calibration_compute`** — Headphone audio piecewise calibration computing engine: evaluates calibration thresholds, binary searches ~~13-point~~ **14-point (corrected, QA session 73 — initial `hi` bound `0xd`=13, and this doc's own established convention from `key_binary_search_14`/`lut_piecewise_linear_interp_4point`/`_3point` is `N = hi + 1`, not `hi` itself)** piecewise calibration table via `FUN_600d379e`, interpolates scaled gain values `((piVar9[1] - piVar9[-1]) * (puVar7 - piVar9[-2])) / (*piVar9 - piVar9[-2]) + piVar9[-1]`, binary searches secondary ~~2-point~~ **3-point (corrected, QA session 73 — same off-by-one, initial `hi` bound `2`)** curve via `FUN_600d6c68`, and writes calibrated profile parameters to `param_2 + 0x24`..`+0x50`. Called by `0x600db56a`. | 1 caller / 3 callees |
| `0x600db56a` |  62 | Audio / Calibration | **`headphone_calibration_state_dispatch`** — Headphone calibration state event dispatcher: checks state `*(param_1 + 8) == 3` and event `*(param_1 + 0x10) == 7`, sets mode 13 (`0xd`), evaluates left/right audio calibrations via `FUN_600db43e(FUN_60084b64(), param_2 + 0x24)` and `FUN_600db43e(thunk_EXT_FUN_000065c4(), param_2 + 0x7c)`, returns status 2. | 0 callers / 3 callees |
| `0x600db5a8` | 108 | Config / Keys | ~~**`crypto_key_dispatch_by_type`** — Crypto key generation / dispatch helper: ... executes matching crypto key handler (`keys__600668dc`... `keys__60066944`... `keys__600669a8`... `keys__60066a74`...)~~ ⚠️ **misidentified — the exact `keys.cc` "not crypto" naming trap CLAUDE.md already warns about, corrected QA session 73**: `keys__600668dc`/`keys__60066944`/`keys__600669a8`/`keys__60066a74` are already independently documented elsewhere in *this same file* (the `keys.cc` section above) as the generic typed config/property store's **string Set**, **bool Set**, **int Get (types 3/8/9/0xa/0xb)**, and **int Get (types 2/4/5/6/7)** accessors respectively — gated by read-only/factory-property flags, part of a thoroughly-documented settings database with no cryptographic content. Real behavior: **`property_typed_accessor_dispatch_by_type`** — queries a type selector via `FUN_600d74ce()` and dispatches to the matching typed Set/Get accessor on the generic key-value store (type 1: string-Set with a 0x80-byte buffer; type 2: bool-Set; types 3/4: int-Get variants), writes the resulting status to `*param_2`, returns success (`cVar1==0 || cVar1==5`). The dispatch mechanics, argument values, and return-code logic are all confirmed correct — only the "crypto key generation" subsystem/behavioral framing is wrong. Called by `0x60078da8`. | 1 caller / 5 callees |
| `0x600db61c` |  38 | Diagnostics / Format | ~~**`crypto_stream_context_push`** — Crypto stream context push helper: sets flag `*(param_1[0] + 0x18) = 1`, computes stream hash via `FUN_600cbb14(&local_14)`, and pushes into buffer via `FUN_60101b76(param_1 + 1, uVar1)`.~~ ⚠️ **misidentified, corrected QA session 73** — `FUN_600cbb14` is not a hash function; it's the same small-integer-code-to-name-string lookup table independently disassembly-confirmed in session 66 (`ldrb r3,[r0]; cmp r3,#0x10; ldrls.w r0,[r2,r3,lsl#2]`) and reused across `sleep_lock.cc`, the TS3A227E driver, `bruce-bta-stack.md`'s `0x600925bc` trace dispatcher, and session 62's `json_format_string_append` (the same misidentification pattern, corrected there too). Real behavior: sets a flag byte, looks up a type/error code's display-name string via `FUN_600cbb14`, and appends that name into a buffer via the independently-established generic string-appender `FUN_60101b76` (`bruce-log-buffer.md`) — a formatting/logging helper, not a cryptographic stream context push. Called by `0x60078e00`. | 1 caller / 2 callees |
| `0x600db642` |  58 | Audio / Transport | **`audio_transport_disconnect_action`** — Audio transport disconnect action dispatcher: checks state `*(param_1 + 8) == 3` and mode `*(param_1 + 0x10) == 8`, clears transport active flag `*(iVar1 + 0x55c) = 0`, posts disconnect event `(0, 8, 0, 0)` via `thunk_EXT_FUN_00001834`, returns status 1. | 0 callers / 2 callees |
| `0x600db6f2` |  34 | Flash / Writer | **`http_flash_writer_stream_fetch`** — HTTP flash writer stream buffer fetch helper: calls `FUN_60050c18` on buffer slice and updates slice offset via `FUN_60101ba2`. Called by 3 callers in `http_flash_writer.cc` (`0x60079668`, `0x60079778`, `0x6007952c`). | 3 callers / 2 callees |
| `0x600db714` |  28 | Flash / Writer | **`http_flash_writer_offset_update_mutex`** — Mutex-protected flash writer offset updater: acquires mutex at `param_1 + 0xb4` (`thunk_EXT_FUN_0000b4c2`), updates offset `*(param_1 + 0x24) = param_2`, releases mutex (`thunk_EXT_FUN_00007d10`). Called by `http_flash_writer__6007991c` and `FUN_600db730`. | 2 callers / 2 callees |
| `0x600db730` | 208 | Flash / Writer | **`http_flash_chunk_buffered_writer`** — HTTP flash chunk buffered writer: manages sector-aligned chunk writes to flash via `http_flash_writer__6007952c`, staging partial chunk remnants in internal buffer `param_1 + 5` and updating mutex-guarded write offsets via `FUN_600db714`. Called by `firmware_image_upload__60078340`. | 1 caller / 3 callees |
| `0x600db800` |  30 | Flash / Writer | **`http_flash_writer_event_callback`** — HTTP flash writer event callback wrapper: computes event payload length via `FUN_6004cb28(param_2)` and invokes event dispatcher `FUN_6005a9fc`. Called by `http_flash_writer__60079778` and `http_flash_writer__6007991c`. | 2 callers / 2 callees |

## Session 74 (Wave 44) — USB Audio Receiver, Linear Interpolation Ring Buffers & Mutex Event Enqueue (20 functions, 1,126 bytes)

Decompiled and documented 20 functions (1,126 bytes across `0x600db830`–`0x600dbcec`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600db830` |  14 | System / Init | **`struct_clear_16b_1`** — 16-byte structure zeroer: clears 16 bytes (`0x10`) via `thunk_EXT_FUN_0000b52e(param_1, 0x10)`. | 0 callers / 1 callee |
| `0x600db846` |  14 | System / Cleanup | **`struct_field_cleanup_1680_alt`** — Structure field destructor: cleans field at `param_1 + 4` via `thunk_EXT_FUN_00001680`. | 0 callers / 1 callee |
| `0x600db870` |  16 | System / Memory | **`dmb_state_flag_clear_60`** — Memory-barriered flag reset: executes `dmb ish`, clears byte at `param_1 + 0x60 = 0`, executes `dmb ish`. Called by `0x600db8d8`. | 1 caller / 0 callees |
| `0x600db880` |  14 | System / Init | **`struct_clear_16b_2`** — 16-byte structure zeroer: clears 16 bytes (`0x10`) via `thunk_EXT_FUN_0000b52e(param_1, 0x10)`. | 0 callers / 1 callee |
| `0x600db896` |  34 | Audio / USB | **`usb_audio_buffer_slice_fetch`** — USB audio receive buffer slice fetch helper: calls `FUN_60050c18` on buffer slice and updates slice offset via `FUN_60101ba2`. Called by `usb_audio_receive.cc` (`0x6007a118`, `0x6007a2c0`). | 2 callers / 2 callees |
| `0x600db8b8` |  32 | System / Time | **`millisecond_timestamp_round_1000`** — Millisecond timestamp rounding helper: gets microsecond/tick counter via `FUN_600ca560()`, rounds to nearest millisecond `((u % 1000) * 1000 + 500) / 1000 + (u / 1000) * 1000`. Called by `0x600db902` and `0x600db97e`. | 2 callers / 1 callee |
| `0x600db8d8` |  16 | Audio / USB | **`usb_audio_receive_state_reset`** — USB audio receiver state reset: calls `dmb_state_flag_clear_60` and resets endpoint via `thunk_EXT_FUN_00008ef2(param_1)`. Called by `usb_audio_receive__6007a254`. | 1 caller / 2 callees |
| `0x600db8e8` |   8 | Audio / USB | **`usb_audio_notify_tail_7d30`** — USB audio event notifier tail call: sets `r1=0, r2=2` and tail-calls `func_0x6013d030(param_1, 0, 2)`. Fixed tail-call boundary in `FixTailCalls.java`/`FixSpuriousSplits.java`. | 3 callers / 0 callees |
| `0x600db8f0` |  18 | Audio / USB | **`usb_audio_buffer_available_predicate`** — USB audio available buffer size calculator: calculates `*(param_1 + 0x9c8) - *(param_1 + 0x9c0)`, returns 0 if below threshold 192 (`0xc0`), else returns available byte count. Called by `usb_audio_receive__6007a62c`. | 1 caller / 0 callees |
| `0x600db902` | 124 | Audio / USB | **`usb_audio_receive_packet_enqueue`** — USB audio receive packet enqueue handler: fetches rounded millisecond timestamp, updates timestamp fields `+0x964` and `+0x958`, stores buffer pointers `*(param_1 + 0x94c) = param_2`, `*(param_1 + 0x950) = param_3`, atomically sets exclusive flag byte `+0x949` with `ldrex`/`strex`, updates buffer index `+0x19d8`, and notifies endpoint via `usb_audio_notify_tail_7d30(param_1 + 4)`. | 0 callers / 2 callees |
| `0x600db97e` |  62 | Audio / USB | **`usb_audio_receive_packet_cancel`** — USB audio receive packet cancel handler: fetches rounded millisecond timestamp, atomically clears flag byte `+0x94b` via `ldrex`/`strex`, and notifies endpoint via `usb_audio_notify_tail_7d30(param_1 + 4)` if flag was non-zero. | 0 callers / 2 callees |
| `0x600db9bc` |  24 | Audio / USB | **`usb_audio_receive_flag_set_94a`** — USB audio receive flag setter: memory-barriered store of `*(param_1 + 0x94a) = 1`, notifies endpoint via `usb_audio_notify_tail_7d30`. | 0 callers / 1 callee |
| `0x600db9dc` |  22 | Audio / USB | **`usb_audio_receive_object_init_6668b`** — 6668-byte USB audio receiver object initializer: calls `usb_audio_receive__6007a254()` and clears 6668 bytes (`0x1a0c`) via `thunk_EXT_FUN_0000b52e(param_1, 0x1a0c)`. | 0 callers / 2 callees |
| `0x600db9fa` |  42 | Audio / Buffer | **`linear_interpolation_buffer_drain`** — Linear interpolation buffer drain helper: drains up to `param_3` bytes from buffer `*param_1` to `param_2` via `memmove` (`thunk_EXT_FUN_0000b588`), advances buffer pointer `*param_1`, and decrements available length `param_1[1]`. Called by `0x600dba24` and `frames__6007a2c0`. | 2 callers / 1 callee |
| `0x600dba24` |  70 | Audio / RingBuf | **`usb_audio_ring_buffer_read`** — USB audio ring buffer read helper: iteratively drains bytes from circular buffer `param_1` using `linear_interpolation_buffer_drain`, handling wrap-around modulo buffer capacity `param_1[3]`, returning total drained bytes. Called by `usb_audio_receive.cc` (`0x6007a504`, `0x6007a62c`). | 2 callers / 1 callee |
| `0x600dba6a` | 250 | Audio / Stream | **`usb_audio_linear_interpolation_feed`** — USB audio linear interpolation streaming feeder: feeds input frames into linear interpolation engine `linear_interpolation_source__6007a450`, managing primary circular buffer span `param_1[1]` + `*param_1` and secondary wrapped span across circular buffer capacity `param_1[3]`. Called by `FUN_600dbb64`. | 1 caller / 1 callee |
| `0x600dbb64` |  50 | Audio / USB | **`usb_audio_receive_stream_interpolate`** — USB audio receive stream interpolator entry: checks frame count threshold `*(param_1 + 0x950) >= 4` (returns error 9 if below), prepares interpolation frame buffers, and invokes `usb_audio_linear_interpolation_feed`. Called by `usb_audio_receive__6007a504`. | 1 caller / 1 callee |
| `0x600dbb96` |  58 | Audio / Buffer | **`buffer_copy_slice_drain`** — Buffer copy and slice drain helper: drains up to `param_3` bytes from buffer `*param_1` to `param_2` via `memmove`, advances `*param_1`, decrements `param_1[1]`, and returns transferred length in `*param_4`. Called by `FUN_600dbbd0`. | 1 caller / 1 callee |
| `0x600dbbd0` | 244 | Audio / RingBuf | **`usb_audio_ring_buffer_write`** — USB audio ring buffer circular write manager: writes input data into circular ring buffer `param_1`, managing linear segment up to capacity `param_1[3]` and wrapped remainder, updating write offset `*param_1` and buffer level `param_1[1]`. Called by `usb_audio_receive__6007a62c`. | 1 caller / 1 callee |
| `0x600dbcec` |  14 | System / Init | **`struct_clear_20b_5`** — 20-byte structure zeroer: clears 20 bytes (`0x14`) via `thunk_EXT_FUN_0000b52e(param_1, 0x14)`. | 0 callers / 1 callee |

## Session 75 (Wave 45) — Synapse Audio Processing, Vector Containers & Channel Dispatch (20 functions, 1,110 bytes)

Decompiled and documented 20 functions (1,110 bytes across `0x600dbd22`–`0x600dc216`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600dbd22` |  22 | Synapse / Init | **`synapse_audio_object_init_4392b_1`** — 4392-byte Synapse audio object initializer: calls `FUN_6007ac50()` and clears 4392 bytes (`0x1128`) via `thunk_EXT_FUN_0000b52e(param_1, 0x1128)`. | 0 callers / 2 callees |
| `0x600dbd46` |  22 | Synapse / Init | **`synapse_audio_object_init_4392b_2`** — 4392-byte Synapse audio object initializer: calls `FUN_6007ac70()` and clears 4392 bytes (`0x1128`) via `thunk_EXT_FUN_0000b52e(param_1, 0x1128)`. | 0 callers / 2 callees |
| `0x600dbd64` |  66 | Synapse / Audio | **`synapse_audio_buffer_drain_16bit`** — 16-bit audio sample buffer drain helper: drains up to `param_3` 16-bit samples (`param_3 * 2` bytes) from buffer `*param_1` to `param_2` via `memmove` (`thunk_EXT_FUN_0000b588`), advances buffer pointer `*param_1`, and decrements available sample count `param_1[1]`. Called by `0x600dbda6`. | 1 caller / 1 callee |
| `0x600dbda6` | 250 | Synapse / Audio | **`synapse_audio_ring_buffer_write_16bit`** — 16-bit audio ring buffer circular write manager: writes 16-bit sample data into circular ring buffer `param_1` (with stride 2), managing linear segment up to capacity `param_1[3]` and wrapped remainder, updating write offset `*param_1` and sample level `param_1[1]`. Called by `0x600dbea0`. | 1 caller / 1 callee |
| `0x600dbea0` |  66 | Synapse / Audio | **`synapse_audio_receive_enqueue_mutex`** — Mutex-guarded Synapse audio receive queue manager: acquires mutex at `param_1 + 0x68`, writes samples to ring buffer at `param_1 + 0xbc` via `synapse_audio_ring_buffer_write_16bit`, triggers notification at `param_1 + 4` via `thunk_EXT_FUN_00008ef2` if flag `+0x850` is non-zero, releases mutex. | 0 callers / 4 callees |
| `0x600dbf0a` |  14 | System / Init | **`struct_clear_16b_3`** — 16-byte structure zeroer: clears 16 bytes (`0x10`) via `thunk_EXT_FUN_0000b52e(param_1, 0x10)`. | 0 callers / 1 callee |
| `0x600dbf20` |  28 | Synapse / Cleanup | **`synapse_audio_processor_destructor_free`** — 1140-byte Synapse audio processor destructor: cleans processor sub-structures via `FUN_600dc30e` and ~~frees~~ **zeroes (corrected, QA session 75)** the 1140-byte object (`0x474`) via `thunk_EXT_FUN_0000b52e(iVar1, 0x474)` — `thunk_EXT_FUN_0000b52e` is the independently, repeatedly established memset/zero helper used throughout this codebase (every `struct_clear_*`/`system_table_init_*`/`*_object_init_*` row this session), not a deallocator; the real free thunk is `thunk_EXT_FUN_0000b52a` (correctly used elsewhere in this same wave, e.g. `free_if_nonnull`). No actual heap deallocation happens in this function — it wipes the object's memory in place without returning it to the allocator. Called by `0x6007b164` and `synapse_audio_processor__6007b1b8`. | 2 callers / 2 callees |
| `0x600dbf72` |  72 | Synapse / Audio | **`synapse_audio_dual_buffer_append_mutex`** — Mutex-guarded dual buffer appender: acquires primary mutex `+0x4fb8`, appends to buffer `+0x500c` via `append_buffer__6007b59c`, releases mutex; acquires secondary mutex `+0x3160`, appends to buffer `+0x31b4` via `append_buffer__6007b6c0`, releases mutex. | 0 callers / 4 callees |
| `0x600dbfba` |  50 | Synapse / Audio | **`synapse_audio_state_clear_516b`** — 516-byte Synapse audio state cleanup: cleans sub-objects at `+0x1d8`, `+0x1b4`, `+0x190` (400), `+0x3c`, and clears 516 bytes (`0x204`) via `thunk_EXT_FUN_0000b52e(param_1, 0x204)`. Called by `0x600dc292` and `0x6007bb4c`. | 2 callers / 5 callees |
| `0x600dbfec` |   8 | Memory / Free | **`free_if_nonnull`** — Null-guarded memory deallocator: calls `vPortFree` (`thunk_EXT_FUN_0000b52a`) if `param_1 != 0`. Called by 4 callers in audio processor / vector cleanup (`0x6007b9d4`, `0x6007ba54`, `0x600dc248`, `0x600dc292`). | 4 callers / 1 callee |
| `0x600dbff4` |  28 | Synapse / Audio | **`synapse_audio_state_cleanup_23068b`** — 23068-byte Synapse audio state cleanup: frees buffer at `+0x484` if non-null, clears 23068 bytes (`0x5a1c`) via `thunk_EXT_FUN_0000b52e(param_1, 0x5a1c)`. Called by `0x600dc292` and `0x6007bb4c`. | 2 callers / 2 callees |
| `0x600dc010` |  16 | System / Init | **`array_zero_32b`** — 32-byte (8-word) array zeroer: loops 8 words clearing `*puVar1 = 0`. Called by `0x600dc020` and `0x6007bb4c`. | 2 callers / 0 callees |
| `0x600dc020` |  34 | System / Init | **`array_zero_composite`** — Composite array zeroer: zeroes 16 words (`0x40` bytes) in loop, zeroes subsequent 8 words twice via `FUN_600dc010`. Called by `0x6007bb4c`. | 1 caller / 1 callee |
| `0x600dc042` | 142 | Synapse / Config | **`synapse_audio_property_scan_flags`** — Synapse audio property scan & boolean flag updater: loops up to 10 entries fetching property tuples via `thunk_EXT_FUN_0000912c`, decodes property index 0..5, and updates boolean flags `param_1 + 0x1b4`..`+0x1b9` based on value `== 1`. | 0 callers / 1 callee |
| `0x600dc124` |  28 | Synapse / Audio | **`synapse_audio_channel_dispatch_tail`** — Synapse audio channel dispatcher tail call: if `*param_1 == 1`, tail-calls `0x600dc0d6`; else tail-calls `0x6007c5b0(param_1[0xa0])`. Fixed tail-call boundary in `FixTailCalls.java`/`FixSpuriousSplits.java`. | 0 callers / 0 callees |
| `0x600dc140` |  94 | Synapse / Audio | **`synapse_audio_channel_stream_dispatch`** — Synapse audio channel streaming dispatcher: if `*param_1 == 1`, calls `thunk_EXT_FUN_00008f98`; else fetches stream context `param_1 + 0x9d`, executes channel processor `FUN_6007c698`, and if flag `+0x1b9 == 0`, dispatches stream block via `thunk_EXT_FUN_00002fac`. | 0 callers / 4 callees |
| `0x600dc19e` |  34 | Container / Vector | **`vector_ushort_allocate`** — `std::vector<uint16_t>` memory allocator: checks for non-negative size (throws/aborts via `FUN_60101fcc` if negative), allocates `param_2 * 2` bytes via `pvPortMalloc` (`thunk_EXT_FUN_0000b532`), sets begin (`*param_1`), current (`param_1[1]`), end (`param_1[2]`). Called by `0x600dc38e` and `0x600dc1c0`. | 2 callers / 2 callees |
| `0x600dc1c0` |  50 | Container / Vector | **`vector_ushort_init_fill`** — `std::vector<uint16_t>` fill constructor: calls `vector_ushort_allocate` for `param_2` elements, fills allocated array with value `*param_3`, sets `param_1[1] = begin + param_2`. Called by `0x600dc38e`, `0x600dc1f2`, `0x6007bb4c`. | 3 callers / 1 callee |
| `0x600dc1f2` |  36 | Container / Vector | **`vector_ushort_init_480_entries`** — `std::vector<uint16_t>` specialized initializer: initializes struct header with `param_2`, `param_3`, and constructs 480-element (`0x1e0`) vector filled with `param_2 & 0xffff` via `vector_ushort_init_fill`. Called by `0x600dc38e`. | 1 caller / 1 callee |
| `0x600dc216` |  50 | Container / Vector | **`vector_geometric_growth_capacity`** — `std::vector` geometric capacity calculator: calculates current vector size `uVar2 = (end - begin) >> 2`, checks maximum capacity `0x3fffffff`, computes new geometric growth capacity `max(size, requested_add)`, handles overflow (calls `FUN_60101fd8`), returns new capacity. ⚠️ *(note, QA session 75)*: the `>> 2` shift divides the byte-span by **4**, i.e. this specific instance assumes **4-byte elements** — inconsistent with the `uint16_t` (2-byte, confirmed via `vector_ushort_allocate`'s own `param_2 * 2` allocation literal) framing implied by its grouping alongside the `vector_ushort_*` rows above. More likely a generic/shared geometric-growth helper reused across differently-typed vectors (parameterized by whichever caller's element size), or specific to a 4-byte-element vector in its actual call sites here — not confirmed `uint16_t`-specific despite the row's placement. Called by 4 callers across audio buffer vector resizing (`0x6007b9d4`, `0x6007ba54`, `0x6007c3e0`, `0x6007c4c8`). | 4 callers / 1 callee |

## Session 76 (Wave 46) — Synapse DSP Audio Processor, Nested Vector Destruction & Atomic FIFO (20 functions, 1,286 bytes)

Decompiled and documented 20 functions (1,286 bytes across `0x600dc248`–`0x600dc73c`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600dc248` |  22 | Container / Vector | **`vector_ptr_elements_free`** — Vector pointer element deallocator: walks array of 12-byte tuples (`param_1` to `param_2`, stride 3 words) calling `free_if_nonnull(*param_1)`. Called by `0x600dc25e`, `0x600dc292`, `0x6007bb4c`. | 3 callers / 1 callee |
| `0x600dc25e` |  52 | Container / Vector | **`vector_nested_ptr_destructor_zero`** — Nested pointer vector destructor: iterates outer vector `piVar1` calling `vector_ptr_elements_free(*piVar1, piVar1[1])`, frees `*piVar1`, frees outer array `*param_1`, and zeroes 16-byte header via tail-call `thunk_EXT_FUN_0000b52e(param_1, 0x10)`. Called by `0x600dc292` and `0x6007bb4c`. | 2 callers / 3 callees |
| `0x600dc292` | 124 | Synapse / Audio | **`synapse_audio_context_destructor`** — Synapse audio context destructor: cleans sub-objects at `+0x280` (zeroes 1200 bytes `0x4b0`), frees vector at `+0x274`, frees nested vector at `+0x268`, cleans nested vector at `+0x264`, frees buffer at `+600`, zeroes 96 bytes (`0x60`) at `+0x254` and 128 bytes (`0x80`) at `+0x250`, cleans state at `+0x1cc` and `+0x1c8`. Called by `0x600dc30e`. | 1 caller / 8 callees |
| `0x600dc30e` | 100 | Synapse / Audio | **`synapse_audio_processor_substruct_cleanup`** — Synapse audio processor sub-structure cleanup: frees buffer at `+0x464`, cleans context at `+0x1d8` via `synapse_audio_context_destructor`, walks and frees vector array at `+0x1d4` (zeroing 24 bytes `0x18`), frees buffer at `+0x1c8`, and cleans 5076-byte engine at `+0x1b8` via `FUN_600dc5ee` (zeroing 5076 bytes `0x13d4`). Called by `synapse_audio_processor_destructor_free` (`0x600dbf20`) and `synapse_audio_processor__6007b1b8`. | 2 callers / 4 callees |
| `0x600dc372` |  28 | Audio / Buffer | **`buffer_copy_append_range`** — Bounded byte buffer copy/append: copies `param_2 - param_1` bytes from `param_1` into `param_3` via `memmove` (`thunk_EXT_FUN_0000b588`) if pointers differ, returns pointer past copied destination. Called by `0x6007b9d4` and `0x6007ba54`. | 2 callers / 1 callee |
| `0x600dc38e` | 248 | Synapse / Audio | **`synapse_audio_processor_constructor_init`** — Synapse audio processor constructor: initializes base struct (440B `0x1b8`), allocates 5076-byte (`0x13d4`) DSP engine at `+0x1b8` via `FUN_6007c1d4`, initializes 40-byte 0xFFFF mapping table at `+0x1bc` via `FUN_600dc4d6`, builds 3-channel 480-sample vector table at `+0x1d4` via `vector_ushort_allocate`, initializes audio channel state at `+0x1d8` via `FUN_6007bb4c`, and initializes vector context at `+0x45c` via `vector_ushort_init_480_entries`. Called by `synapse_audio_processor__6007b1b8`. | 1 caller / 10 callees |
| `0x600dc486` |  80 | Container / Vector | **`vector_ptr_copy_construct`** — 4-byte element `std::vector` copy constructor: computes element count `(param_2[1] - *param_2) >> 2`, checks size limit `0x3fffffff` (aborts via `FUN_60101fcc` on overflow), allocates destination buffer via `pvPortMalloc` (`thunk_EXT_FUN_0000b532`), copies elements via `memmove`, and sets begin/current/end pointers. Called by `0x6007bf68`. | 1 caller / 3 callees |
| `0x600dc4d6` |  60 | Synapse / Audio | **`synapse_audio_mapping_table_init_40b`** — 40-byte audio mapping table initializer: zeroes 6-word struct header, allocates 40 bytes (`0x28`) via `pvPortMalloc`, fills array with 20 16-bit `0xffff` sentinel values, and sets vector pointers. Called by `synapse_audio_processor_constructor_init` (`0x600dc38e`). | 1 caller / 1 callee |
| `0x600dc512` |  92 | Synapse / FIFO | **`synapse_audio_fifo_pop_exclusive`** — Synapse audio atomic FIFO pop: checks count `*(param_1 + 8)`, fetches 4-byte entry from circular buffer at `*(param_1 + 0xc) + read_idx * 4`, swaps halfwords into `*param_2`, atomically decrements count `*piVar5` with `ldrex`/`strex`, advances read index `*(param_1 + 4)` modulo buffer capacity, returns 1 on success (0 on empty). | 0 callers / 0 callees |
| `0x600dc56e` |  54 | Synapse / Audio | **`synapse_audio_channel_frame_stride_offset`** — Channel frame stride offset calculator: iterates channel entries in `param_3`, computes buffer pointer `*(param_1) + i * 12 + param_2 * 320 (0x140)`, and stores 8-byte tuple `(ptr, 0x50)` (80-sample frame size). | 0 callers / 0 callees |
| `0x600dc5a4` |  22 | Synapse / Cleanup | **`synapse_audio_substruct_cleanup_1c`** — Sub-structure cleanup: frees buffer `+0xc` if non-null, cleans state via `FUN_600dd812`. Called by `FUN_600dc5ee`. | 1 caller / 2 callees |
| `0x600dc5ba` |  36 | Container / Vector | **`vector_ptr_array_free_all`** — Vector pointer array deallocator: iterates 12-byte tuples (`*param_1` to `param_1[1]`, stride 3 words) freeing each element `*piVar1` if non-null, then frees base array `*param_1`. Called by `FUN_600dc5ee`. | 1 caller / 1 callee |
| `0x600dc5de` |  16 | Container / Vector | **`vector_single_buf_free`** — Single buffer vector deallocator: frees `*param_1` if non-null via `vPortFree`. Called by `FUN_600dc5ee` and `0x6007c1d4`. | 2 callers / 1 callee |
| `0x600dc5ee` | 110 | Synapse / Audio | **`synapse_audio_engine_destructor_5076b`** — 5076-byte Synapse audio engine destructor: cleans 28-byte object at `+0x13d0` (zeroing `0x1c`), cleans pointer vector at `+0x13c4`, frees buffer at `+0x13b8`, cleans state at `+0x13a8` and `+0x139c`, cleans components at `+0x4c`, `+0x40`, `+0x24`, and vector arrays at `+0x14` and `+4`. Called by `synapse_audio_processor_substruct_cleanup` (`0x600dc30e`). | 1 caller / 9 callees |
| `0x600dc65c` |  38 | Container / Vector | **`vector_ptr_allocate_4byte_elements`** — 4-byte element `std::vector` allocator: checks capacity `param_2 <= 0x3fffffff` (aborts via `FUN_60101fcc` on overflow), allocates `param_2 * 4` bytes via `pvPortMalloc` (`thunk_EXT_FUN_0000b532`), sets begin, current, end pointers. Called by `0x600dc682`, `0x600dc6e2`, `0x6007dc50`, `0x6007e5c8`. | 4 callers / 2 callees |
| `0x600dc682` |  96 | Container / Vector | **`vector_vector_ptr_copy_construct`** — Vector-of-vectors copy constructor: iterates `param_2` vectors in array `*param_1`, allocates and copies each source vector `param_3` using `vector_ptr_allocate_4byte_elements` and `memmove`, advances array pointers. Called by `0x6007c1d4`. | 1 caller / 2 callees |
| `0x600dc6e2` |  48 | Container / Vector | **`vector_ptr_init_fill_4byte`** — 4-byte element `std::vector` fill constructor: allocates `param_2` 4-byte words via `vector_ptr_allocate_4byte_elements`, fills array with `*param_3`, sets `param_1[1] = begin + param_2`. Called by `0x6007c1a8` and `0x6007c1d4`. | 2 callers / 1 callee |
| `0x600dc712` |   8 | Memory / Free | **`vector_element_free_if_nonnull`** — Null-guarded element deallocator: calls `vPortFree` (`thunk_EXT_FUN_0000b52a`) if `param_1 != 0`. Called by `0x600dc71a`, `0x6007c330`, `0x6007c3e0`, `0x6007c4c8`. | 4 callers / 1 callee |
| `0x600dc71a` |  34 | Container / Vector | **`vector_of_vectors_free_elements`** — Vector-of-vectors element deallocator: iterates 12-byte vector descriptors from `param_1 + 4` to `param_1 + 8`, frees each sub-vector's buffer via `vector_element_free_if_nonnull`, then frees outer array `*(param_1 + 4)`. Called by `synapse_audio_engine_destructor_5076b` (`0x600dc5ee`). | 1 caller / 2 callees |
| `0x600dc73c` |  18 | Synapse / Buffer | **`synapse_audio_buffer_space_predicate_256b`** — Audio buffer remaining space predicate: checks if buffer capacity minus length `*(int **)(param_1 + 4))[1] - **(int **)(param_1 + 4)` exceeds 255 (`0xff`). | 0 callers / 0 callees |

## Session 77 (Wave 47) — Synapse Audio DSP Pipeline, Polyphase FIR Filters, AGC & Limiter Dynamics (20 functions, 1,288 bytes)

Decompiled and documented 20 functions (1,288 bytes across `0x600dc74e`–`0x600dcc10`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600dc74e` |  30 | Audio / Buffer | **`buffer_copy_prepend_range`** — Bounded byte buffer copy/prepend: copies `param_2 - param_1` bytes from `param_1` into `param_3 - (param_2 - param_1)` via `memmove` (`thunk_EXT_FUN_0000b588`) if pointers differ, returns updated pointer. Called by `0x6007c3e0` and `0x6007c4c8`. | 2 callers / 1 callee |
| `0x600dc76c` |  74 | Synapse / Audio | **`synapse_audio_channel_resample_process`** — Channel resample processor: iterates `*param_1` channels, processes 12-byte channel descriptors at `*param_2 + i * 12` via `FUN_6007c4c8`, and copies history samples. | 0 callers / 1 callee |
| `0x600dc7b6` | 270 | Synapse / DSP | **`synapse_audio_polyphase_filter_convolve`** — Polyphase FIR filter convolution engine: clears 160-float (`0xa0`) accumulator buffer `param_4`, computes 4-tap polyphase dot products across sub-bands with coefficients `param_1` and delay lines `param_2`/`param_5`, and stages trailing 60 bytes (`0x3c`) via tail-call `memmove` (`thunk_EXT_FUN_0000b588`). Called by `FUN_6007c698`. | 1 caller / 1 callee |
| `0x600dc8c4` |  48 | Synapse / Audio | **`synapse_audio_state_zero_1200b`** — 1200-byte state zeroer: zeroes sub-arrays in two structured loops across 1200 bytes (`0x4b0`). Called by `0x6007bb4c`. | 1 caller / 0 callees |
| `0x600dc8f4` |   2 | Synapse / Cleanup | **`synapse_audio_context_noop_destructor`** — No-op destructor stub (`bx lr`). Called by `0x600dc292` and `0x6007bb4c`. | 2 callers / 0 callees |
| `0x600dc8f6` | 162 | Synapse / DSP | **`synapse_audio_dsp_pipeline_init`** — 16kHz audio DSP pipeline initializer: sets config word, initializes sub-modules (equalizer `FUN_600de184`, high-pass `FUN_600de164`, filter bank `FUN_600dcc56`, AGC compressor `FUN_600dc998`, limiter `FUN_600dca7a`, noise gate `FUN_600dcb2e`), configures 16000Hz sampling rate, sets unit gain `1.0f` (`0x3f800000`). Called by `0x6007bb4c`. | 1 caller / 11 callees |
| `0x600dc998` |  38 | Synapse / AGC | **`synapse_audio_agc_config_init`** — Audio AGC compressor config initializer: copies 6 words from `param_2`, initializes enable flag (`*(param_1 + 6) = 1`), gain `1.0f` (`0x3f800000`), and hold counter 0. Called by `synapse_audio_dsp_pipeline_init` (`0x600dc8f6`). | 1 caller / 0 callees |
| `0x600dc9be` |   2 | Synapse / AGC | **`synapse_audio_agc_noop_destructor`** — No-op destructor stub (`bx lr`). Called by `synapse_audio_state_clear_516b` (`0x600dbfba`). | 1 caller / 0 callees |
| `0x600dc9c0` | 184 | Synapse / AGC | **`synapse_audio_agc_envelope_compute`** — Audio AGC dynamic envelope compute: performs float32 envelope detection and attack/decay gain smoothing, handling peak tracking, release timing, and coprocessor VFP floating-point operations. Merged spurious split `0x600dca10` (46B) in `FixSpuriousSplits.java`. | 0 callers / 0 callees |
| `0x600dca78` |   2 | Synapse / Limiter | **`synapse_audio_limiter_noop_destructor`** — No-op destructor stub (`bx lr`). Called by `synapse_audio_state_clear_516b` (`0x600dbfba`). | 1 caller / 0 callees |
| `0x600dca7a` |  30 | Synapse / Limiter | **`synapse_audio_limiter_config_init`** — Audio limiter config initializer: copies 6 parameter words from `param_2`, initializes limiter state via `FUN_6007c7ac`. Called by `synapse_audio_dsp_pipeline_init` (`0x600dc8f6`). | 1 caller / 1 callee |
| `0x600dca98` | 150 | Synapse / Limiter | **`synapse_audio_limiter_envelope_step`** — Audio limiter envelope step: calculates attack/decay threshold dynamics, applying attack multiplier `*(param_2 + 8)` or decay multiplier `*(param_2 + 0x10)`, updating peak hold `*(param_2 + 0x18)`. | 0 callers / 0 callees |
| `0x600dcb2e` |  26 | Synapse / Gate | **`synapse_audio_noisegate_config_init`** — Audio noise gate config initializer: copies 4 parameter words from `param_3`, stores threshold `param_1` in `param_2[4]` and `param_2[5]`, sets counter `param_2[6] = 0`. Called by `synapse_audio_dsp_pipeline_init` (`0x600dc8f6`). | 1 caller / 0 callees |
| `0x600dcb48` |   2 | Synapse / Gate | **`synapse_audio_noisegate_noop_destructor`** — No-op destructor stub (`bx lr`). Called by `synapse_audio_state_clear_516b` (`0x600dbfba`). | 1 caller / 0 callees |
| `0x600dcb4a` |  10 | Synapse / Gate | **`synapse_audio_noisegate_reset`** — Noise gate state reset: resets threshold counter `*(param_1 + 0x14) = *(param_1 + 0x10)` and hold timer `*(param_1 + 0x18) = 0`. Called by `synapse_audio_dsp_pipeline_init` (`0x600dc8f6`). | 1 caller / 0 callees |
| `0x600dcb54` |  74 | Synapse / Gate | **`synapse_audio_noisegate_envelope_step`** — Audio noise gate envelope step: checks input level against threshold `param_3`, updates gate envelope attenuation `param_2[5]` and hold timer `param_2[6]`. | 0 callers / 0 callees |
| `0x600dcb9e` |  24 | Container / Vector | **`vector_ptr_free_and_zero_12b`** — 12-byte vector struct free and zero: frees buffer `*param_1` if non-null via `vPortFree`, zeroes 12-byte header (`0xc`) via tail-call `thunk_EXT_FUN_0000b52e`. Called by `0x600dcbf8` and `0x600dcc10`. | 2 callers / 2 callees |
| `0x600dcbb6` |  66 | Container / Vector | **`vector_ptr_init_fill_zero_words`** — Vector zeroed words initializer: allocates `(param_3 - param_2) * 4` bytes via `pvPortMalloc` (`thunk_EXT_FUN_0000b532`), zeroes allocated memory in loop, sets begin/current/end pointers. Called by `0x600dcc10`. | 1 caller / 2 callees |
| `0x600dcbf8` |  24 | Synapse / Filter | **`synapse_audio_filter_bank_destructor`** — Filter bank sub-component destructor: cleans sub-module `+0x150` via `FUN_600dd65e`, frees and zeroes vector `+0x48` via `vector_ptr_free_and_zero_12b`. Called by `synapse_audio_state_clear_516b` (`0x600dbfba`). | 1 caller / 2 callees |
| `0x600dcc10` |  70 | Synapse / Filter | **`synapse_audio_filter_bank_init`** — Filter bank initializer: initializes filter sub-modules `+0x1c` via `FUN_6007dd28` and `+0x4c` via `FUN_600de276`, allocates 12-byte vector at `+0x48`, fills 48 zero words (`0x80 - 0x50 = 48`) via `vector_ptr_init_fill_zero_words`, stores sampling rate `param_2` at `+0x140`, and sets configuration parameters. Called by `0x600dc8f6` and `0x600dcc56`. | 2 callers / 5 callees |

## Session 78 (Wave 48) — Synapse Radix-4/2 FFT Engine, Subband Filter Banks & AEC Adaptive Filtering (20 functions, 1,960 bytes)

Decompiled and documented 20 functions (1,960 bytes across `0x600dcc56`–`0x600dd8f2`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600dcc56` |  68 | Synapse / Filter | **`synapse_audio_filter_bank_config_48k`** — 48kHz audio filter bank configuration initializer: copies 7 configuration words from `param_2`, initializes filter state at `+7` via `FUN_600de0c4`, filter parameters at `+0x13` via `FUN_600de288`, no-op module at `+0x54`, and initializes 48000Hz sampling rate via `FUN_600dcc10`. Called by `synapse_audio_dsp_pipeline_init` (`0x600dc8f6`). | 1 caller / 4 callees |
| `0x600dcc9a` | 130 | Synapse / Spectral | **`synapse_audio_spectral_correlation_classify`** — Spectral magnitude correlation classifier: compares frequency bin vectors `param_2` and `param_4` between indices `param_1[0]` and `param_1[1]`, tracking symmetric coherence count `uVar6` (against threshold `param_1[2]`) and asymmetric power difference count `uVar3` (against threshold `param_1[3]`), returning classification code (2 for high coherence, 0 for high variance, 1 for neutral). Called by `0x6007c7f4`. | 1 caller / 0 callees |
| `0x600dcd1c` |  28 | Audio / Buffer | **`buffer_copy_append_range_2`** — Bounded byte buffer copy/append: copies `param_2 - param_1` bytes from `param_1` to `param_3` via `memmove` (`thunk_EXT_FUN_0000b588`) if pointers differ, returns pointer past copied destination. Called by `0x6007c7f4`. | 1 caller / 1 callee |
| `0x600dcd38` |  14 | Audio / Buffer | **`array_fill_129_words`** — 129-word (`0x81` elements, 516B) array filler: loops filling 129 consecutive words with `param_1`. Called by `0x6007cf14`. | 1 caller / 0 callees |
| `0x600dcd46` | 582 | Synapse / FFT | **`synapse_audio_fft_bit_reversal_permutation`** — Radix-4/Radix-2 FFT bit-reversal shuffle engine: computes permutation index bit-reversal lookup table in `param_2` for transform size `param_1`, and executes 2-point complex in-place butterfly index permutations across complex float buffer `param_3`. | 1 caller / 0 callees |
| `0x600dd364` | 282 | Synapse / FFT | **`synapse_audio_fft_radix4_butterfly_stage`** — Radix-4/Radix-2 FFT decimation-in-frequency butterfly stage: iterates through transform stages via `FUN_600dcf8c` and `thunk_EXT_FUN_0000954a`, executing 4-point complex butterfly arithmetic (`(x0+x2)+(x1+x3)`, `(x0-x2)+j(x1-x3)`) across complex float buffer `param_2`. | 0 callers / 2 callees |
| `0x600dd5a0` | 188 | Synapse / FFT | **`synapse_audio_rfft_twiddle_postprocess`** — Real-to-complex FFT symmetry folding and twiddle recombination: applies trigonometric twiddle factor multipliers from table `param_4` with stride `(param_3 << 1) / (param_1 >> 1)` to fold symmetric half-spectrum into full complex frequency spectrum. | 0 callers / 0 callees |
| `0x600dd65c` |   2 | Synapse / Cleanup | **`synapse_audio_filter_noop_destructor_1`** — No-op destructor stub (`bx lr`). Called by `0x600dcc56` and `0x600de44e`. | 2 callers / 0 callees |
| `0x600dd65e` |   2 | Synapse / Cleanup | **`synapse_audio_filter_noop_destructor_2`** — No-op destructor stub (`bx lr`). Called by 6 callers in audio processor/filter cleanup (`0x600dcbf8`, `0x600dd8f2`, `0x600dd98e`, `0x600ddca0`, `0x600dde3e`, `0x600de376`). | 6 callers / 0 callees |
| `0x600dd6a0` |  50 | Synapse / Filter | **`synapse_audio_biquad_cascade_process`** — Biquad cascade processing loop: iterates `param_2` biquad filter stages applying `thunk_EXT_FUN_00004cd0` on sample buffers. | 0 callers / 1 callee |
| `0x600dd6d2` |  36 | Container / Vector | **`vector_ptr_tuples_free`** — 12-byte vector pointer tuple array deallocator: walks array of 12-byte tuples (`param_1 + 4` to `param_1 + 8`, stride 3 words) freeing each element `*piVar1` if non-null via `vPortFree` (`thunk_EXT_FUN_0000b52a`), then frees outer array `*(param_1 + 4)`. Called by `synapse_audio_engine_destructor_5076b` (`0x600dc5ee`). | 1 caller / 1 callee |
| `0x600dd6f6` | 152 | Synapse / Subband | **`synapse_audio_subband_stream_demux`** — Subband audio stream demultiplexer and history manager: iterates `*param_1` subbands, calls `thunk_EXT_FUN_00009304` to demux 80-sample (`0x50`) frames from `param_3` into delay lines `param_1[1]`, copies trailing history, and processes subband filter via `FUN_6007d78c`. | 0 callers / 2 callees |
| `0x600dd78e` |  60 | Synapse / Subband | **`synapse_audio_subband_channel_filter_step`** — Subband channel filter step: loops `*param_1` channels calling subband filter step `FUN_6007d78c` on channel contexts `param_1[1] + i * 12` and buffers `*param_2 + i * 12`. | 0 callers / 1 callee |
| `0x600dd7ca` |  50 | Synapse / AEC | **`synapse_audio_acoustic_echo_canceller_init`** — Acoustic Echo Cancellation (AEC) context initializer: sets sampling parameters `param_2` and `param_3`, initializes delay line via `FUN_6007d9e8`, initializes 4940-byte adaptive filter engine at `+0x22` via `FUN_600dd83c`, and zeroes trailing status `param_1[0x4d3] = 0`. Called by `0x6007c1d4`. | 1 caller / 2 callees |
| `0x600dd7fc` |  22 | Synapse / AEC | **`synapse_audio_aec_substruct_cleanup`** — AEC sub-structure cleanup: cleans adaptive filter state at `+0x88` via `FUN_600dd8f2` and sub-module at `+0xc` via `FUN_600dd98e`. Called by `synapse_audio_engine_destructor_5076b` (`0x600dc5ee`). | 1 caller / 2 callees |
| `0x600dd812` |  16 | Memory / Free | **`vport_free_ptr_if_nonnull`** — Null-guarded buffer deallocator: frees `*param_1` via `vPortFree` (`thunk_EXT_FUN_0000b52a`) if non-null. Called by `0x600dc5a4` and `0x600dc5ee`. | 2 callers / 1 callee |
| `0x600dd822` |  10 | Synapse / Event | **`synapse_audio_event_tuple_store`** — Event descriptor tuple store: stores byte `param_2` at `*param_1`, word `param_3` at `param_1 + 4`, byte `param_4` at `param_1 + 8`. | 0 callers / 0 callees |
| `0x600dd82c` |  16 | Synapse / State | **`synapse_audio_state_flag_lookup`** — State flag lookup predicate: checks active flag `param_1[0x16] != 0`, returns configuration byte `*(param_1[0] + 0x6a)`. | 0 callers / 0 callees |
| `0x600dd83c` | 182 | Synapse / AEC | **`synapse_audio_aec_adaptive_filter_init`** — 4940-byte AEC adaptive filter engine initializer: initializes sub-modules across structure (spectral estimator `FUN_600de44e`, partition tables `FUN_600ddc48`, cross-correlation engine `FUN_600ddfde`, double-talk detector `FUN_6007e204`, echo suppressor `FUN_600ddeba`, gain computer `FUN_600ddb2a`, residual estimator `FUN_600ddb8e`, post-filter `FUN_600de4e0`), zeroes coefficient vectors (64-word blocks from `+0x3ee`, `+0x42e`, `+0x46e`), and sets active flags. Called by `synapse_audio_acoustic_echo_canceller_init` (`0x600dd7ca`). | 1 caller / 8 callees |
| `0x600dd8f2` |  70 | Synapse / AEC | **`synapse_audio_aec_adaptive_filter_destructor`** — AEC adaptive filter engine destructor: cleans sub-modules at `+0xee8` (`FUN_600de46e`), `+0xedc` (`FUN_600ddba2`), `+0xddc` (`FUN_600ddb42`), `+0xdc8` (`FUN_600dde3e`), `+0xbb4` (`FUN_600de676`), `+0x22c` (`FUN_600ddee8`), `+0x10` (`FUN_600ddca0`), and `+4` (`FUN_600dd65e`). Called by `synapse_audio_aec_substruct_cleanup` (`0x600dd7fc`). | 1 caller / 8 callees |

## Session 79 (Wave 49) — Synapse Acoustic Echo Cancellation (AEC) Partition Delay Lines & Suppressors (20 functions, 1,456 bytes)

Decompiled and documented 20 functions (1,456 bytes across `0x600dd938`–`0x600ddeba`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600dd938` |  86 | Synapse / Subband | **`synapse_audio_subband_history_shift`** — Subband history buffer shift helper: copies trailing history and calls `thunk_EXT_FUN_00009304` to shift subband buffers. | 0 callers / 2 callees |
| `0x600dd98e` |  44 | Synapse / AEC | **`synapse_audio_aec_spectral_substruct_cleanup`** — AEC spectral sub-structure cleanup: cleans sub-objects at `+0x5c`, `+0x4c`, `+0x34`, `+0x1c`, and `+4` via respective destructors (`FUN_600dd65e`, `FUN_600de8d6`, `FUN_600de68a`, `FUN_600de0a0`, `FUN_600de836`). Called by `synapse_audio_aec_substruct_cleanup` (`0x600dd7fc`). | 1 caller / 5 callees |
| `0x600dd9ba` | 320 | Synapse / AEC | **`synapse_audio_aec_delay_line_filter_step`** — AEC partition delay line filter step: advances circular ring indices, computes input energy `FUN_6007da70`, shifts history via `memmove` (`thunk_EXT_FUN_0000b588`), executes complex frequency-domain cross-correlation `thunk_EXT_FUN_00005ab4`, accumulates 65-bin (`0x41`) power spectrum, and triggers filter update `FUN_6007d978` on frame completion. | 0 callers / 4 callees |
| `0x600ddafa` |  48 | Synapse / AEC | **`synapse_audio_aec_delay_line_advance`** — AEC partition delay line index advance: steps circular partition buffer write and delay pointers modulo partition bounds. | 0 callers / 0 callees |
| `0x600ddb2a` |  24 | Synapse / AEC | **`synapse_audio_aec_gain_vector_init`** — AEC gain vector initializer: copies initial value `*(param_2 + 0x18)` to `*param_1` and zeroes remaining 63 float entries (`param_1 + 1` to `param_1 + 0x40`). Called by `synapse_audio_aec_adaptive_filter_init` (`0x600dd83c`). | 1 caller / 0 callees |
| `0x600ddb42` |   2 | Synapse / AEC | **`synapse_audio_aec_noop_destructor_1`** — No-op destructor stub (`bx lr`). Called by `synapse_audio_aec_adaptive_filter_destructor` (`0x600dd8f2`). | 1 caller / 0 callees |
| `0x600ddb44` |  74 | Synapse / AEC | **`synapse_audio_aec_coherence_mask_zero`** — AEC coherence mask zeroer: tests activity counters across 61 subbands (`0x3d`), zeroing multi-tap filter weights if counter exceeds threshold 5. | 0 callers / 0 callees |
| `0x600ddb8e` |  20 | Synapse / AEC | **`synapse_audio_aec_inv_param_init`** — AEC inverse parameter initializer: computes inverse float `1.0 / *(param_2 + 0x6c)` and stores it at `param_1[1]`. Called by `synapse_audio_aec_adaptive_filter_init` (`0x600dd83c`). | 1 caller / 0 callees |
| `0x600ddba2` |   2 | Synapse / AEC | **`synapse_audio_aec_noop_destructor_2`** — No-op destructor stub (`bx lr`). Called by `synapse_audio_aec_adaptive_filter_destructor` (`0x600dd8f2`). | 1 caller / 0 callees |
| `0x600ddba4` |  32 | Synapse / AEC | **`synapse_audio_aec_spectral_power_scale`** — AEC 65-bin spectral power scaler: scales 65 float bins (`0x41`) in `param_3` by `param_1 * param_1` into `param_4`. Called by `0x6007dac0`. | 1 caller / 0 callees |
| `0x600ddbc4` | 132 | Synapse / AEC | **`synapse_audio_aec_spectral_peak_envelope`** — AEC 65-bin spectral peak envelope tracker: traverses circular buffer partitions finding maximum bin power across 65 frequency bins (`0x41`), updating envelope `param_4`. Called by `0x6007dac0`. | 1 caller / 0 callees |
| `0x600ddc48` |  88 | Synapse / AEC | **`synapse_audio_aec_partition_tables_init`** — AEC partition tables initializer: initializes forward and backward partition filter states (`FUN_6007dfcc`), shadow filter (`FUN_6007e514`), and error estimator (`FUN_600de98e`). Called by `synapse_audio_aec_adaptive_filter_init` (`0x600dd83c`). | 1 caller / 4 callees |
| `0x600ddca0` |  36 | Synapse / AEC | **`synapse_audio_aec_partition_tables_destructor`** — AEC partition tables destructor: cleans sub-objects at `+0x80` (`FUN_600de77a`), `+0x44` (`FUN_600de376`), `+8` (`FUN_600de376`), and `+0` (`FUN_600dd65e`). Called by `synapse_audio_aec_adaptive_filter_destructor` (`0x600dd8f2`). | 1 caller / 3 callees |
| `0x600ddcc4` | 206 | Synapse / AEC | **`synapse_audio_aec_mode_switch_reconfig`** — AEC operation mode switch and reconfiguration: reconfigures partition states, updates step sizes and leakage bounds across AEC filter pipeline, re-initializing spectral controllers. | 0 callers / 4 callees |
| `0x600ddd92` | 120 | Synapse / AEC | **`synapse_audio_aec_mode_reset_parameters`** — AEC mode reset parameters: copies baseline partition parameters and updates filter step sizes via tail-call `FUN_600de3de`. | 0 callers / 1 callee |
| `0x600dde0a` |   2 | Synapse / AEC | **`synapse_audio_aec_noop_destructor_3`** — No-op destructor stub (`bx lr`). | 0 callers / 0 callees |
| `0x600dde0c` |  50 | Synapse / AEC | **`synapse_audio_aec_buffer_copy_260b`** — 260-byte (`0x104`) AEC state buffer copier: copies 260-byte primary buffer and optional secondary buffer via `memmove` (`thunk_EXT_FUN_0000b588`), zeroes flags at `+0x104` and `+0x204`. | 0 callers / 1 callee |
| `0x600dde3e` |  22 | Synapse / AEC | **`synapse_audio_aec_submodule_destructor`** — AEC sub-module destructor: frees buffer at `+8` if non-null via `vPortFree` (`thunk_EXT_FUN_0000b52a`), calls `FUN_600dd65e` on `+4`. Called by `synapse_audio_aec_adaptive_filter_destructor` (`0x600dd8f2`). | 1 caller / 2 callees |
| `0x600dde54` | 102 | Container / Vector | **`synapse_audio_aec_filter_vector_alloc_256b`** — AEC 256-byte element vector allocator: allocates `param_2 * 256` bytes via `pvPortMalloc` (`thunk_EXT_FUN_0000b532`), initializes 256-byte template array, and copies template into each vector element via `thunk_EXT_FUN_0000b572`. Called by `synapse_audio_aec_suppressor_init` (`0x600ddeba`). | 1 caller / 4 callees |
| `0x600ddeba` |  46 | Synapse / AEC | **`synapse_audio_aec_suppressor_init`** — AEC echo suppressor initializer: calculates partition count `param_2 / 16000` (or 1 for 8kHz), initializes vector of 256-byte suppressor partition filters via `synapse_audio_aec_filter_vector_alloc_256b`. Called by `synapse_audio_aec_adaptive_filter_init` (`0x600dd83c`). | 1 caller / 2 callees |

## Session 80 (Wave 50) — Synapse AEC Double-Talk Detection, Equalizer Dynamic Gain & Partition Filters (20 functions, 1,304 bytes)

Decompiled and documented 20 functions (1,304 bytes across `0x600ddee8`–`0x600de3de`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ddee8` |  16 | Synapse / AEC | **`synapse_audio_aec_delay_destructor`** — AEC delay buffer destructor: calls `FUN_600de8b8` on sub-object at `+0x324`. Called by `synapse_audio_aec_adaptive_filter_destructor` (`0x600dd8f2`). | 1 caller / 1 callee |
| `0x600ddef8` |  20 | Synapse / AEC | **`synapse_audio_aec_enable_flag_set`** — AEC enable flag setter: sets flag at `+0x31c`, and if enabled sets `*(param_1 + 800) = *(param_1 + 4)`, else zeroes it. | 0 callers / 0 callees |
| `0x600ddf0c` | 210 | Synapse / AEC | **`synapse_audio_aec_double_talk_detect_step`** — AEC double-talk detector step: evaluates near-end and far-end energies via `thunk_EXT_FUN_00005614`, tests energy ratios against thresholds `param_1[0..2]`, updates double-talk hold counters `param_1[6]` and `param_1[7]`, and sets double-talk detection boolean at `+0x15`. | 0 callers / 1 callee |
| `0x600ddfde` | 194 | Synapse / AEC | **`synapse_audio_aec_cross_correlation_init`** — 2440-byte AEC cross-correlation & coherence engine initializer: initializes spectral cross-correlation engines (`FUN_600de85a`, `FUN_6007dbbc`), computes inverse frame scale `1.0 / N`, initializes 65-bin unit weights (`1.0f` at `+3`..`+0x44`), and zeroes 65-bin cross-power and error buffers. Called by `synapse_audio_aec_adaptive_filter_init` (`0x600dd83c`). | 1 caller / 2 callees |
| `0x600de0a0` |  36 | Container / Vector | **`vector_ptr_tuple_free_2`** — 12-byte vector pointer tuple array deallocator: walks array of 12-byte tuples (`param_1 + 4` to `param_1 + 8`, stride 3 words) freeing each element if non-null via `vPortFree` (`thunk_EXT_FUN_0000b52a`), then frees outer array `*(param_1 + 4)`. Called by `synapse_audio_aec_spectral_substruct_cleanup` (`0x600dd98e`). | 1 caller / 1 callee |
| `0x600de0c4` |  26 | Synapse / Filter | **`synapse_audio_filter_state_init_48k`** — 48kHz filter state initializer: zeroes 4 filter words and initializes filter context via `FUN_6007dd28` at 48000Hz. Called by `synapse_audio_filter_bank_config_48k` (`0x600dcc56`). | 1 caller / 1 callee |
| `0x600de0de` | 134 | Synapse / Resample | **`synapse_audio_resampler_downsample_frame`** — Audio frame resampler and downsampler: if 8000Hz direct copy via `memmove`, otherwise executes sinc/polyphase downsampling via `thunk_EXT_FUN_0000a94e` into stack buffer `local_798` and decimates with stride `param_1[1]`. Called by `0x6007c7f4`. | 1 caller / 2 callees |
| `0x600de164` |  20 | Synapse / Highpass | **`synapse_audio_highpass_config_init`** — High-pass filter config initializer: copies 3 words from `param_2`, initializes gain `1.0f` (`0x3f800000`) at `param_1[3]`. Called by `synapse_audio_dsp_pipeline_init` (`0x600dc8f6`). | 1 caller / 0 callees |
| `0x600de178` |  12 | Synapse / Highpass | **`synapse_audio_highpass_state_reset`** — High-pass filter state reset: zeroes byte at `+0x10`, sets gain `1.0f` at `+0xc`. Called by `synapse_audio_dsp_pipeline_init` (`0x600dc8f6`). | 1 caller / 0 callees |
| `0x600de184` |  38 | Synapse / Equalizer | **`synapse_audio_equalizer_config_init`** — Equalizer config initializer: copies 6 words from `param_2`, initializes gain `1.0f` at `param_1[6]`, frame size 160 (`0xa0`) at `param_1[7]`, and flags 0 at `param_1[8]`. Called by `synapse_audio_dsp_pipeline_init` (`0x600dc8f6`). | 1 caller / 0 callees |
| `0x600de1aa` |  20 | Synapse / Equalizer | **`synapse_audio_equalizer_state_init`** — Equalizer state initializer: sets gain `1.0f` at `+0x18`, decimation step `param_2 / 100` at `+0x1c`, and zeroes status at `+0x20`. Called by `synapse_audio_dsp_pipeline_init` (`0x600dc8f6`). | 1 caller / 0 callees |
| `0x600de1be` | 184 | Synapse / Equalizer | **`synapse_audio_equalizer_gain_adapt`** — Equalizer dynamic gain adaptation step: computes power ratio, scales by step constant `*(param_3 + 8)`, adjusts filter coefficients via `thunk_EXT_FUN_00009b30`, clamps minimum gain to `1.0f`, and updates output gain at `*(param_3 + 0x18)`. | 0 callers / 1 callee |
| `0x600de276` |  18 | Synapse / Filter | **`synapse_audio_filter_coefficients_fill_56words`** — Filter coefficients filler: fills 56 words (`param_1 + 0x14` to `param_1 + 0xf4`, 224B) with initial value `*(param_1 + 0x10)`. Called by `synapse_audio_filter_bank_init` (`0x600dcc10`) and `0x600de288`. | 2 callers / 0 callees |
| `0x600de288` |  26 | Synapse / Filter | **`synapse_audio_filter_coefficients_init`** — Filter coefficients configuration initializer: copies 5 words from `param_2` and fills array via `synapse_audio_filter_coefficients_fill_56words`. Called by `synapse_audio_filter_bank_config_48k` (`0x600dcc56`). | 1 caller / 1 callee |
| `0x600de2a2` | 178 | Synapse / Filter | **`synapse_audio_filter_coefficients_smooth_step`** — Filter coefficients asymmetric smoothing step: updates 56 filter coefficients with attack constant `*(param_1 + 4)` or decay constant `*(param_1 + 0xc)` / `*(param_1 + 8)`, clamping to minimum floor `*(param_1 + 0x10)`. Called by `0x6007c7f4`. | 1 caller / 1 callee |
| `0x600de354` |  34 | Synapse / AEC | **`synapse_audio_aec_complex_weights_zero_130words`** — AEC complex weights zeroer: zeroes two 65-word arrays (`0x41` words real + `0x41` words imag, total 130 words = 520B) at `param_1`. Called by `FUN_6007dfcc`, `FUN_6007df4c`, and `FUN_6007ded0`. | 3 callers / 0 callees |
| `0x600de376` |  30 | Synapse / AEC | **`synapse_audio_aec_weights_vector_free`** — AEC weights vector deallocator: frees buffer at `+0x2c` if non-null via `vPortFree` (`thunk_EXT_FUN_0000b52a`), frees buffer at `+0x20` if non-null via `vPortFree`, calls `FUN_600dd65e` on `param_1`. Called by `synapse_audio_aec_partition_tables_destructor` (`0x600ddca0`). | 1 caller / 2 callees |
| `0x600de394` |  32 | Container / Vector | **`vector_reserve_grow_capacity`** — Vector capacity grow/shrink helper: computes current element count `(param_1[1] - *param_1) >> 2`, calls reallocation helper `FUN_6007b9d4` if capacity needed exceeds current size, else truncates current end pointer `param_1[1]`. Called by `FUN_6007df4c` and `FUN_6007ded0`. | 2 callers / 1 callee |
| `0x600de3b4` |  42 | Synapse / AEC | **`synapse_audio_aec_partitions_zero_520b`** — AEC partitions zeroer: zeroes `param_2` partition blocks of 520 bytes (`0x208` bytes = 130 float words) each via `thunk_EXT_FUN_0000b5ba`. Called by `FUN_6007dfcc` and `FUN_6007dddc`. | 2 callers / 1 callee |
| `0x600de3de` |  34 | Synapse / AEC | **`synapse_audio_aec_partition_count_set`** — AEC partition count setter: clamps partition count `param_2` against max capacity `*(param_1 + 4)`, stores partition length at `+0x14`, and if flag set updates partition vectors via `FUN_6007df4c`. Called by `FUN_6007dfcc`, `synapse_audio_aec_mode_reset_parameters` (`0x600ddd92`), and `synapse_audio_aec_mode_switch_reconfig` (`0x600ddcc4`). | 3 callers / 1 callee |

## Session 81 (Wave 51) — Synapse AEC Post-Filter Suppressor, Convergence State Machine & Matrix Allocator (20 functions, 868 bytes)

Decompiled and documented 20 functions (868 bytes across `0x600de400`–`0x600de77a`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600de400` |  78 | Synapse / AEC | **`synapse_audio_aec_partition_interpolation_step`** — AEC partition interpolation step: performs linear interpolation of partition length between initial and target lengths with decay weight `*(param_1 + 0xc)`, updating partition vectors via `FUN_6007df4c`. | 0 callers / 1 callee |
| `0x600de44e` |  12 | Synapse / AEC | **`synapse_audio_aec_helper_noop_thunk`** — AEC helper no-op stub: forwards call to `FUN_600dd65c` (`bx lr`), returns `param_1`. Called by 5 AEC inits (`0x600dd83c`, `0x600ddc48`, `0x600ddeba`, `0x6007dfcc`, `0x6007d9e8`). | 5 callers / 1 callee |
| `0x600de45a` |  20 | Synapse / VFP | **`synapse_audio_vfp_coprocessor_unit_gain`** — VFP coprocessor unit gain initializer: issues VFP coprocessor instruction and returns `1.0f` (`0x3f800000`). Called by `0x6007dac0`. | 1 caller / 0 callees |
| `0x600de46e` |  14 | Synapse / AEC | **`synapse_audio_aec_destructor_subobject_78`** — AEC sub-object destructor: calls `FUN_600de69a` on `param_1 + 0x78`. Called by `synapse_audio_aec_adaptive_filter_destructor` (`0x600dd8f2`). | 1 caller / 1 callee |
| `0x600de47c` |  22 | Synapse / AEC | **`synapse_audio_aec_spectral_config_init`** — AEC spectral config initializer: copies parameter byte at `+0x68` and word at `+100`, sets initial status flags. Called by `synapse_audio_aec_post_filter_init` (`0x600de4e0`). | 1 caller / 0 callees |
| `0x600de492` |  18 | Synapse / AEC | **`synapse_audio_aec_spectral_state_zero_24b`** — AEC spectral state zeroer: stores `*(param_2 + 0x14)` at `*param_1` and zeroes remaining 5 words (`param_1 + 1` to `param_1 + 5`, 24B total). Called by `synapse_audio_aec_post_filter_init` (`0x600de4e0`). | 1 caller / 0 callees |
| `0x600de4a4` |  16 | Synapse / AEC | **`synapse_audio_aec_spectral_bin_threshold_select`** — AEC spectral bin threshold selector: if frame counter `param_3 < 500` scales threshold `*param_1 >> 6`, else uses `*(param_2 + 0x14)`, storing result in `param_1[1]`. | 0 callers / 0 callees |
| `0x600de4b4` |  44 | Synapse / AEC | **`synapse_audio_aec_suppressor_threshold_init`** — AEC suppressor threshold parameters initializer: copies config flags, initializes default thresholds (10000 at `+0xc` and `+0x14`), and zeroes 9 tracking fields. Called by `synapse_audio_aec_post_filter_init` (`0x600de4e0`). | 1 caller / 0 callees |
| `0x600de4e0` |  84 | Synapse / AEC | **`synapse_audio_aec_post_filter_init`** — AEC post-filter and suppressor engine initializer: initializes spectral configuration (`FUN_600de47c`), state buffer (`FUN_600de492`), threshold controller (`FUN_600de4b4`), vector memory buffer (`FUN_600de6fe`), and tracking state (`FUN_600dea3a`). Called by `synapse_audio_aec_adaptive_filter_init` (`0x600dd83c`). | 1 caller / 5 callees |
| `0x600de534` |  22 | Synapse / AEC | **`synapse_audio_aec_post_filter_threshold_reset`** — AEC post-filter threshold reset: resets threshold to 10000 at `+0x14`, zeroes `+0x18`, `+0x28`, and conditional flag `+0x24`. Called by `0x600de54a`. | 1 caller / 0 callees |
| `0x600de54a` |  56 | Synapse / AEC | **`synapse_audio_aec_post_filter_reconfig`** — AEC post-filter runtime reconfigurator: re-initializes tracking controllers at `+0x78` via `FUN_600de6e8`, resets thresholds at `+0x2c` via `synapse_audio_aec_post_filter_threshold_reset`, and tail-calls `func_0x600dea44` at `+0xcc`. | 0 callers / 2 callees |
| `0x600de582` | 244 | Synapse / AEC | **`synapse_audio_aec_convergence_state_machine`** — AEC convergence state machine: tracks adaptation frame counters `+4`, speech activity counters `+0x28` and `+0xc`, near-end voice hold timers `+0x14` and `+0x1c`, sets hangover and convergence flags at `+8`, `+0x10`, `+0x11`, `+0x24`. | 0 callers / 0 callees |
| `0x600de676` |  20 | Synapse / AEC | **`synapse_audio_aec_state_zero_260b`** — 260-byte (`0x104`) AEC state buffer zeroer: zeroes 260-byte buffer at `*(param_1 + 4)` via `thunk_EXT_FUN_0000b52e`. Called by `synapse_audio_aec_adaptive_filter_destructor` (`0x600dd8f2`). | 1 caller / 1 callee |
| `0x600de68a` |  16 | Memory / Free | **`synapse_audio_aec_free_subobject_4`** — Null-guarded deallocator: frees buffer at `param_1 + 4` via `vPortFree` (`thunk_EXT_FUN_0000b52a`). Called by `synapse_audio_aec_spectral_substruct_cleanup` (`0x600dd98e`). | 1 caller / 1 callee |
| `0x600de69a` |  16 | Memory / Free | **`synapse_audio_aec_free_subobject_8`** — Null-guarded deallocator: frees buffer at `param_1 + 8` via `vPortFree` (`thunk_EXT_FUN_0000b52a`). Called by `synapse_audio_aec_destructor_subobject_78` (`0x600de46e`). | 1 caller / 1 callee |
| `0x600de6aa` |  38 | Synapse / AEC | **`synapse_audio_aec_spectral_band_window_step`** — AEC spectral band window stepper: advances circular sliding band window `+0x2c` by 64 bins (`0x3f`) modulo spectral bounds `param_3 - 1`. | 0 callers / 0 callees |
| `0x600de6e8` |  22 | Synapse / AEC | **`synapse_audio_aec_tracking_state_zero`** — AEC tracking state zeroer: zeroes tracking fields at `+0x14`, `+0x18`, `+0x24`, `+0x2c`, `+0x30`, copies initial pointer ~~`param_1[1] = param_1[4]`~~ **`*(param_1+0x20) = *(param_1+4)` (corrected, QA session 81 — the bracket-index notation had both operands off: the real assignment is byte offset `+0x20` ← `+4`, not word-indices `[1]`←`[4]`)**, tail-calls `func_0x600de6d0`. Called by `0x600de54a` and `0x600de6fe`. | 2 callers / 0 callees |
| `0x600de6fe` | 104 | Container / Vector | **`synapse_audio_aec_vector_matrix_alloc`** — AEC 64-word column matrix allocator: allocates `param_2 * 256` bytes (`iVar1 * 0x40 * 4`) via `pvPortMalloc` (`thunk_EXT_FUN_0000b532`), zeroes matrix memory, initializes sub-engine at `+0x34` via `FUN_6007e368`, and resets tracking via `synapse_audio_aec_tracking_state_zero`. Called by `synapse_audio_aec_post_filter_init` (`0x600de4e0`). | 1 caller / 4 callees |
| `0x600de766` |  20 | Audio / Buffer | **`buffer_descriptor_range_tuple_store`** — Buffer descriptor range tuple store: computes element count `(param_2[1] - *param_2) >> 2`, stores pointer and count into `param_1[0]` and `param_1[1]`. | 0 callers / 0 callees |
| `0x600de77a` |   2 | Synapse / Cleanup | **`synapse_audio_aec_noop_destructor_4`** — No-op destructor stub (`bx lr`). Called by `synapse_audio_aec_partition_tables_destructor` (`0x600ddca0`). | 1 caller / 0 callees |

## Session 82 (Wave 52) — Synapse AEC Delay Line Accumulation, Cross-Correlation Matrix & DSP Stats (20 functions, 1,004 bytes)

Decompiled and documented 20 functions (1,004 bytes across `0x600de77c`–`0x600deb98`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600de77c` | 186 | Synapse / AEC | **`synapse_audio_aec_spectral_parameters_interpolate`** — AEC spectral parameters interpolator: linearly interpolates 5 parameter channels (`+0xc`..`+0x1c`) between initial values `+0x24`..`+0x34` and target values `+0x3c`..`+0x4c` over transition interval `*(param_1 + 0x15c)` with step decay `*(param_1 + 4)`. | 0 callers / 0 callees |
| `0x600de836` |  36 | Container / Vector | **`vector_ptr_tuple_free_3`** — 12-byte vector pointer tuple array deallocator: walks array of 12-byte tuples (`param_1 + 4` to `param_1 + 8`, stride 3 words) freeing each element if non-null via `vPortFree` (`thunk_EXT_FUN_0000b52a`), then frees outer array `*(param_1 + 4)`. Called by `synapse_audio_aec_spectral_substruct_cleanup` (`0x600dd98e`). | 1 caller / 1 callee |
| `0x600de85a` |  94 | Synapse / AEC | **`synapse_audio_aec_cross_correlation_matrix_alloc`** — AEC cross-correlation matrix allocator: allocates `param_2 * (param_3 - 1) * 4` bytes via `pvPortMalloc` (`thunk_EXT_FUN_0000b532`), zeroes matrix buffer, computes inverse scale ~~`1.0 / (param_3 - 1)`~~ **`1.0 / param_3`, unmodified (corrected, QA session 82 — disassembly-confirmed: `vmov s15,r2` [param_3] and `vcvt.f32.u32`/`vdiv.f32` all execute *before* `subs r5,r2,#1` computes `param_3-1`; the VFP division genuinely divides by the original `param_3`, not the decremented value used elsewhere in the same function for the allocation size and `param_1[1]`)**. Called by `synapse_audio_aec_cross_correlation_init` (`0x600ddfde`). | 1 caller / 2 callees |
| `0x600de8b8` |  16 | Memory / Free | **`synapse_audio_aec_delay_buffer_free`** — Null-guarded delay buffer deallocator: frees buffer at `param_1 + 0xc` via `vPortFree` (`thunk_EXT_FUN_0000b52a`). Called by `synapse_audio_aec_delay_destructor` (`0x600ddee8`). | 1 caller / 1 callee |
| `0x600de8c8` |  14 | Synapse / Filter | **`synapse_audio_filter_descriptor_init`** — Filter descriptor initializer: stores parameters into `param_1[0..2]` and zeroes status byte `param_1[3]`. Called by `0x6007d9e8`. | 1 caller / 0 callees |
| `0x600de8d6` |   2 | Synapse / Cleanup | **`synapse_audio_aec_noop_destructor_5`** — No-op destructor stub (`bx lr`). Called by `synapse_audio_aec_spectral_substruct_cleanup` (`0x600dd98e`). | 1 caller / 0 callees |
| `0x600de8d8` | 182 | Synapse / AEC | **`synapse_audio_aec_partition_delay_line_accumulate_65bins`** — 65-bin partition delay line accumulator: zeroes 65-float accumulator `param_4`, iterates through circular ring partition frames accumulating 65-bin spectral energy, copies intermediate sum to `param_5` via `memmove` (`thunk_EXT_FUN_0000b588`), and continues accumulation for remaining partitions. | 0 callers / 1 callee |
| `0x600de98e` |  62 | Synapse / AEC | **`synapse_audio_aec_transition_interpolator_init`** — 3-channel transition interpolator initializer: copies 3-word tuple from `param_2` into current, initial, and target slots (`param_1[0..8]`), sets transition duration `param_3` and inverse step `1.0 / N`. Called by `synapse_audio_aec_partition_tables_init` (`0x600ddc48`). | 1 caller / 0 callees |
| `0x600de9cc` |   8 | Synapse / AEC | **`synapse_audio_aec_leakage_state_zero`** — Zeroes leakage state words at `+0x2c` and `+0x30`. Called by `synapse_audio_aec_mode_switch_reconfig` (`0x600ddcc4`). | 1 caller / 0 callees |
| `0x600de9d4` | 102 | Synapse / AEC | **`synapse_audio_aec_transition_interpolator_step`** — 3-channel transition interpolator step: interpolates channels `param_1[1]` and `param_1[2]` towards targets `param_1[4]`/`param_1[5]` using step factor `param_1[10]` over remaining countdown `param_1[0xd]`. | 0 callers / 0 callees |
| `0x600dea3a` |  10 | Synapse / AEC | **`synapse_audio_aec_tracking_flags_zero_3b`** — Zeroes 3 tracking status bytes at `*param_1`, `param_1[1]`, `param_1[2]`. Called by `synapse_audio_aec_post_filter_init` (`0x600de4e0`). | 1 caller / 0 callees |
| `0x600dea4e` |  50 | Synapse / Atomic | **`synapse_audio_exclusive_atomic_event_set`** — Exclusive atomic event bitmask setter: tests flag at `+0x6c`, issues `dmb`, uses exclusive `ldrex`/`strex` loop on `param_1 + 0x70` to atomically OR bit 2 (`| 4`), then notifies event dispatcher via `thunk_EXT_FUN_0000645c`. | 0 callers / 1 callee |
| `0x600deaae` |  14 | Memory / Zero | **`synapse_audio_state_zero_20b_1`** — 20-byte (`0x14`) state buffer zeroer: zeroes 20 bytes at `param_1` via `memset_zero` (`thunk_EXT_FUN_0000b52e`). | 0 callers / 1 callee |
| `0x600deac0` |  22 | Memory / Virtual | **`synapse_audio_virtual_destructor_free_1`** — Virtual destructor & heap free wrapper: calls virtual destructor `(**puVar1)(puVar1)` on object pointer `*(param_1 + 0x10)`, then frees object via `vPortFree` (`thunk_EXT_FUN_0000b52a`). | 0 callers / 1 callee |
| `0x600dead6` |  20 | Memory / Zero | **`synapse_audio_state_cleanup_and_zero_16b`** — Sub-object cleanup & 16-byte zeroer: calls `FUN_6007ec60`, zeroes 16 bytes (`0x10`) at `param_1` via `memset_zero` (`thunk_EXT_FUN_0000b52e`). | 0 callers / 2 callees |
| `0x600deaea` |  80 | Synapse / Stats | **`synapse_audio_stats_collector_periodic_poll`** — Synapse audio stats collector: fetches audio context via `FUN_6007f510`, samples performance metrics from `+0x9a4` and `+0x9ac` via `FUN_600da48a`, releases reference wrappers via `thunk_EXT_FUN_00001680`, invokes receiver `receiver__6007f454`. | 0 callers / 4 callees |
| `0x600deb3a` |  16 | Synapse / DSP | **`synapse_audio_dsp_handle_cleanup`** — DSP handle cleanup: calls `FUN_6005e12c` if handle `*(param_1 + 0xc) != 0`. | 0 callers / 1 callee |
| `0x600deb50` |  14 | Memory / Zero | **`synapse_audio_state_zero_20b_2`** — 20-byte (`0x14`) state buffer zeroer: zeroes 20 bytes at `param_1` via `memset_zero` (`thunk_EXT_FUN_0000b52e`). | 0 callers / 1 callee |
| `0x600deb62` |  54 | Audio / Buffer | **`synapse_audio_circular_buffer_drain_frames`** — Audio circular buffer frame drainer: drains up to `param_2` frames from circular queue (`param_1[1]` elements available, `param_1[3]` capacity, read pointer `*param_1`), updates circular read pointer modulo capacity. | 0 callers / 0 callees |
| `0x600deb98` |  22 | Memory / Virtual | **`synapse_audio_virtual_destructor_free_2`** — Virtual destructor & heap free wrapper: calls virtual destructor `(**puVar1)(puVar1)` on object pointer `*(param_1 + 0x10)`, then frees object via `vPortFree` (`thunk_EXT_FUN_0000b52a`). | 0 callers / 1 callee |

## Session 83 (Wave 53) — Audio Ring Buffer, Haptic Rumble & Battery/Power Services (20 functions, 1,350 bytes)

Decompiled and documented 20 functions (1,350 bytes across `0x600debb4`–`0x600df224`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600debb4` |  20 | Haptics / Rumble | **`haptic_rumble_motor_command_send`** — Haptic motor command sender: invokes `thunk_EXT_FUN_00006a74` on motor descriptor `*(param_1 + 0xb0)` with parameters `param_2`, flags `0xffffffff`. Called by `receiver__6007ec48` and `0x600ded7e`. | 2 callers / 1 callee |
| `0x600debc8` | 268 | Audio / RingBuffer | **`audio_stream_ring_buffer_write_frames`** — Audio stream circular ring buffer writer: writes audio sample frames to buffer `param_1[2]` with circular wrap-around modulo `param_1[3]`, tracking write index `*param_1` and frame count `param_1[1]`, writing chunks via `thunk_EXT_FUN_000064b0`. Called by `receiver__6007f1a4`. | 1 caller / 1 callee |
| `0x600decd4` |  14 | Audio / Stream | **`audio_stream_wrapper_release`** — Releases reference wrapper at `param_1 + 4` via `thunk_EXT_FUN_00001680`. | 0 callers / 1 callee |
| `0x600dece2` |  22 | Audio / Stream | **`audio_stream_context_cleanup_2524b`** — Audio stream context cleanup: calls `FUN_6007f41c`, zeroes 2,524 bytes (`0x9dc`) at `param_1` via `memset_zero` (`thunk_EXT_FUN_0000b52e`). | 0 callers / 2 callees |
| `0x600decf8` |  30 | Audio / Stream | **`audio_stream_descriptor_reset`** — Audio stream descriptor reset: zeroes `param_1[0..1]`, releases wrapper via `thunk_EXT_FUN_00001680`. Called by `receiver__6007f540` and `receiver__6007f454`. | 2 callers / 1 callee |
| `0x600ded7e` |  46 | Haptics / Rumble | **`haptic_rumble_pulse_trigger`** — Haptic rumble pulse trigger: retrieves context via `FUN_6007f510`, packs rumble payload `uStack_14` with mode flag `param_1`, and calls `haptic_rumble_motor_command_send` (`0x600debb4`). Called by `0x6007ec28`. | 1 caller / 3 callees |
| `0x600dee00` |  40 | Haptics / Pattern | **`pattern_player_event_notify_1`** — Pattern player event notification: gets event timestamp via `thunk_EXT_FUN_0000714c`, dispatches event code 1 via `thunk_EXT_FUN_00007a2c`. Called by `pattern_player__6007f8e4`. | 1 caller / 2 callees |
| `0x600dee28` | 152 | Haptics / Pattern | **`pattern_player_channel_select_and_dispatch`** — Pattern player channel selector and dispatcher: iterates over 8 pattern channels (`param_1 + 0x9c + i * 0x10`), activates selected channel virtual methods (`+0xc` and `+4`), and dispatches to handler `func_0x6007f758`. Resized from 216B to 152B. Called by `pattern_player__6007f8e4` and `0x6007f878`. | 2 callers / 0 callees |
| `0x600deecc` |  72 | Battery / FuelGauge | **`battery_service_fuel_gauge_i2c_read`** — Battery service fuel gauge I2C register read: verifies I2C enable flag `+0x1a`, reads 2-byte word from I2C bus device `*puVar2` register 200 (`0xc8`) via `thunk_EXT_FUN_00001ea4`. Called by `battery_service__6007ffd0`. | 1 caller / 1 callee |
| `0x600def14` |  60 | Battery / State | **`battery_service_charge_state_classify`** — Battery charge state classifier: reads voltage/capacity word `+0x18e` and `+0x180`, inspects charging mode `+0x184`, returns battery status enum (0: unknown/unpowered, 1: normal, 2: low, 3: critical, 4: charging, 5: full). | 1 caller / 0 callees |
| `0x600def50` |  48 | Battery / State | **`battery_service_state_update_notify`** — Battery service state updater: classifies current state via `battery_service_charge_state_classify`, updates stored state `+0x188`, triggers notification callback `FUN_6007ff34` on change. Called by `battery_service__6007ffd0`. | 1 caller / 2 callees |
| `0x600def9c` |  68 | Power / Timer | **`power_service_timer_schedule`** — Power service timer scheduler: checks active flag `+0x158` and sleep inhibitor `+0x14c`, computes timestamp via `FUN_600d3618`, schedules timer event code 4 with delay `+0x150` via `thunk_EXT_FUN_00007a2c`. Called by `0x6005c8a0` and `0x600defe0`. | 2 callers / 2 callees |
| `0x600defe0` |  52 | Power / Wakelock | **`power_service_wakelock_clear_bit`** — Power service wakelock bit clear: takes lock `+0xbc` (`thunk_EXT_FUN_0000b4c2`), clears wakelock bit `param_2` in mask `+0x14c`, reschedules timer via `power_service_timer_schedule`, releases lock (`thunk_EXT_FUN_00007d10`). Called by `0x600800c0`. | 1 caller / 3 callees |
| `0x600df014` |  44 | Power / Wakelock | **`power_service_wakelock_cancel_timer`** — Power service timer cancellation: checks timer state via `timers__600cae38`, dispatches cancel event code 3 via `thunk_EXT_FUN_00007a2c`. Called by `wakelock__60080180`. | 1 caller / 2 callees |
| `0x600df072` |  78 | Power / RPC | ~~**`power_rpcs_buffer_crc_verify`** — Power RPC buffer descriptor CRC verification: iterates over 5 descriptors starting at `param_1 + 0x118` (stride 3 words), computes CRC/checksum via `FUN_60050c18`, verifies against expected header via `FUN_601019da`.~~ ⚠️ **misidentified, corrected QA session 83** — no CRC or checksum computation exists anywhere in this function; it's the same generic diagnostic-buffer text-formatting loop established repeatedly this session (sessions 61–62's `json_format_*` family): `FUN_60101ac8` is the established "is the diagnostic stream active" gate (same callee `json_format_int_bracket`/`0x600d37fe` used), `FUN_60050c18` is the established "format a raw value into the growable text buffer" helper (used identically in `log_msg_format_hexdump`/`gatt_char_write_buffer_copy`/etc.), and `FUN_601019da(...,0x5d)` closes each entry with the literal `]` (ASCII `0x5d`) — the exact same closing-delimiter pattern `json_format_int_bracket` uses for JSON array entries. Real behavior: **`power_rpcs_buffer_descriptor_dump`** — iterates 5 descriptors at `param_1+0x118` (stride 3 words), text-formats each one into a diagnostic/log buffer (bracket-closed per entry), returning a status byte from the buffer object — not a CRC/checksum verifier. Called by `power_rpcs__6005e020`. | 1 caller / 3 callees |
| `0x600df0c0` |  48 | Power / Timeout | **`power_service_idle_timeout_callback`** — Power service idle timeout callback: takes lock `+0xbc`, checks if wakelock mask `+0x14c == 0`, invokes idle handler `FUN_600801dc`, releases lock. Called by `0x600df0f0`. | 1 caller / 3 callees |
| `0x600df0f0` | 196 | Power / Timeout | **`power_service_timeout_interval_set`** — Power service timeout interval setter: takes lock `+0xbc`, updates timeout interval `param_1 + 0x150`, cancels existing timer if active, computes elapsed delta against current time, arms new timer via `thunk_EXT_FUN_00007a2c`, or triggers immediate idle callback via `power_service_idle_timeout_callback`. Called by `application_state__6005b8dc`. | 1 caller / 5 callees |
| `0x600df1f0` |  40 | Power / State | **`power_state_machine_event_dispatch`** — Power state machine event dispatcher: gets timestamp via `thunk_EXT_FUN_0000714c`, dispatches event code 1 via `thunk_EXT_FUN_00007a2c`. Called by `state_machine__600df264`. | 1 caller / 2 callees |
| `0x600df218` |  12 | Power / State | **`power_state_machine_status_word_read`** — Power state machine status word reader: issues `dmb`, returns status word `*(param_1 + 4)`. Called by `state_machine__6008099c`, `state_machine__600805e4`, `state_machine__600df264`. | 3 callers / 0 callees |
| `0x600df224` |  40 | Synapse / Priority | **`synapse_audio_stream_priority_configure`** — Synapse audio stream priority configuration: configures stream priorities via `FUN_600d3dd8(6, 2)` and `FUN_600d3dd8(0, 5)`. | 0 callers / 1 callee |

## Session 84 (Wave 54) — Power Services, RPC Handlers & Protobuf Serializer / Varint Encoder (20 functions, 936 bytes)

Decompiled and documented 20 functions (936 bytes across `0x600df286`–`0x600df878`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600df286` |  32 | Power / State | **`power_state_format_entry_1`** — Formats power state entry into string/stream via `FUN_60079bb4` and `FUN_60101ba2`. Called by `state_machine__6008099c`. | 1 caller / 2 callees |
| `0x600df2a6` |  32 | Power / State | **`power_state_format_entry_2`** — Formats power state entry into string/stream via `FUN_6008067c` and `FUN_60101ba2`. Called by `state_machine__6008099c`. | 1 caller / 2 callees |
| `0x600df2c6` |   2 | Power / Service | **`power_service_noop_stub`** — No-op stub function (`bx lr`). | 0 callers / 0 callees |
| `0x600df2ce` |  22 | Bluetooth / GATT | **`gatt_manager_context_cleanup_8748b`** — GATT manager context cleanup: calls `gatt_manager_task__60080af8`, zeroes 8,748 bytes (`0x222c`) at `param_1` via `memset_zero` (`thunk_EXT_FUN_0000b52e`). | 0 callers / 2 callees |
| `0x600df2e4` |  14 | Bluetooth / GATT | **`gatt_manager_state_zero_20b`** — Zeroes 20 bytes (`0x14`) at `param_1` via `memset_zero` (`thunk_EXT_FUN_0000b52e`). | 0 callers / 1 callee |
| `0x600df2f6` |  22 | Bluetooth / GATT | **`gatt_manager_virtual_destructor_free`** — Virtual destructor & heap free wrapper: calls virtual destructor on `*(param_1 + 0x10)`, then frees via `vPortFree` (`thunk_EXT_FUN_0000b52a`). | 0 callers / 1 callee |
| `0x600df30c` |  90 | Power / State | **`power_state_machine_send_command_13`** — Power state machine command dispatcher: builds command packet (opcode `0xd`), dispatches via `thunk_EXT_FUN_00006a74` to target `*(param_1 + 0x2188)`. Called by `state_machine__600df264`. | 1 caller / 3 callees |
| `0x600df366` |  14 | Power / State | **`power_state_wrapper_release`** — Releases reference wrapper at `param_1 + 4` via `thunk_EXT_FUN_00001680`. | 0 callers / 1 callee |
| `0x600df38e` |  26 | RPC / Service | **`rpc_channel_callback_invoke`** — RPC channel callback invoker: invokes callback `*(code **)(param_1 + 0x3c)` on context `*(param_1 + 0x40)` with payload `&local_10`. | 0 callers / 0 callees |
| `0x600df3a8` |  48 | RPC / Service | **`rpc_channel_packet_validate_and_forward`** — RPC packet validator: checks packet length `param_3` against minimum threshold `*(ushort *)(param_1[1] + 0x1c)`, forwards to handler callback `*(param_1 + 0x34)`. | 0 callers / 0 callees |
| `0x600df3d8` | 136 | RPC / Service | **`rpc_service_handler_table_register`** — RPC service handler table registration: registers service methods across 7 slot offsets (`+0x168`, `+0x124`, `+0xe0`, `+0x9c`, `+0x58`, `+0x14`), stores handler pointer at `param_1 + 0x10`. | 0 callers / 0 callees |
| `0x600df610` |  28 | Protobuf / Stream | **`protobuf_stream_writer_init`** — Protobuf stream writer struct initializer: initializes internal buffer pointers `+4` and `+0x1c` pointing to embedded buffers `+0xc` and `+0x24`. | 0 callers / 0 callees |
| `0x600df62c` |  20 | Protobuf / Stream | **`protobuf_stream_writer_cleanup`** — Protobuf stream writer cleanup: cleans up stream buffers at `+0x1c` and `+4` via `FUN_600d4550`. | 0 callers / 1 callee |
| `0x600df64c` |  14 | Protobuf / Memory | **`protobuf_context_zero_132b`** — Zeroes 132 bytes (`0x84`) at `param_1` via `memset_zero` (`thunk_EXT_FUN_0000b52e`). | 0 callers / 1 callee |
| `0x600df65a` |  26 | Protobuf / Buffer | **`protobuf_buffer_append_bytes`** — Protobuf buffer byte appender: appends `param_3` bytes from `param_2` into output buffer `*(param_1 + 4)`. | 0 callers / 0 callees |
| `0x600df674` | 152 | Protobuf / Presence | **`protobuf_field_presence_eval`** — Protobuf field presence and default-value evaluator: checks wire type flags `*(param_1 + 4) & 0x30`, field offset `+9`, evaluates string/sub-message emptiness. | 2 callers / 3 callees |
| `0x600df70c` |  82 | Protobuf / Varint | **`protobuf_encode_varint64`** — Protobuf 64-bit varint encoder: writes 7-bit chunks with MSB continuation bit (`| 0x80`) until value is exhausted, flushes to stream via `FUN_60081d50`. | 4 callers / 1 callee |
| `0x600df7f0` |  32 | Protobuf / Varint | **`protobuf_encode_tag`** — Protobuf field tag encoder: packs field number and wire type `(field_number << 3) | wire_type`, writes via `protobuf_encode_varint64`. | 2 callers / 1 callee |
| `0x600df810` | 104 | Protobuf / Serialize | **`protobuf_serialize_message_fields`** — Protobuf message serializer: iterates through field descriptor table (`FUN_600dfadc`/`FUN_600dfb00`), evaluates field presence, encodes primitive fields via `FUN_60081ea4` or invokes custom serializer callback. | 4 callers / 3 callees |
| `0x600df878` |  40 | Protobuf / Serialize | **`protobuf_message_compute_size`** — Protobuf message size computer: initializes 20-byte stack context `auStack_24`, executes field serializer `FUN_600df810`, returns total serialized byte size in `*param_1`. | 1 caller / 2 callees |

## Session 85 (Wave 55) — Protobuf Deserializer, Gotham Channel Registration & Remote Device DB (20 functions, 1,030 bytes)

Decompiled and documented 20 functions (1,030 bytes across `0x600df8a0`–`0x600dfd24`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600df8a0` |  32 | Protobuf / Varint | **`protobuf_encode_varint32_and_flush`** — Protobuf varint32 encoder & stream writer: encodes integer as varint via `protobuf_encode_varint64` (`FUN_600df70c`), flushes buffer via `FUN_60081d50`. | 0 callers / 2 callees |
| `0x600df8fa` |  30 | Protobuf / Buffer | **`protobuf_buffer_copy_bytes`** — Protobuf buffer byte copier: advances destination pointer `*(param_1 + 4)` by `param_3`, copies `param_3` bytes from source buffer. | 0 callers / 0 callees |
| `0x600df918` | 170 | Protobuf / Init | **`protobuf_field_clear_default`** — Protobuf field default initializer: resets field to default based on type descriptor flags (`*(param_1 + 4)`), clearing sub-messages via `protobuf_message_init_defaults` (`FUN_600df9c2`) or zeroing buffers via `memset_zero`. | 2 callers / 5 callees |
| `0x600df9c2` |  34 | Protobuf / Init | **`protobuf_message_init_defaults`** — Protobuf message initializer: walks message field descriptor table (`FUN_600dfadc`/`FUN_600dfb00`), resetting each field to default values via `protobuf_field_clear_default` (`FUN_600df918`). | 3 callers / 3 callees |
| `0x600df9e4` |   6 | Protobuf / Decode | **`protobuf_decode_varint32_wrapper`** — Protobuf varint32 decode wrapper: invokes `FUN_600821d8` with flag 0. | 2 callers / 1 callee |
| `0x600df9ea` |  52 | Protobuf / Tag | **`protobuf_decode_tag_and_wire_type`** — Protobuf tag and wire type decoder: reads varint tag via `FUN_600821d8`, decomposes into field number `*param_3 = tag >> 3` and wire type `*param_2 = tag & 7`. | 1 caller / 1 callee |
| `0x600dfa1e` |  36 | Protobuf / Stream | **`protobuf_stream_seek_and_sync`** — Protobuf stream seek & sync: seeks stream via `FUN_60082270`, updates stream offsets `param_1 + 4` and `param_1 + 0xc`. | 2 callers / 1 callee |
| `0x600dfa42` |  30 | Protobuf / Parse | **`protobuf_message_parse_from_stream`** — Protobuf message stream parser: resets message fields (`protobuf_message_init_defaults`), parses protobuf wire stream via `FUN_60082814`. | 3 callers / 2 callees |
| `0x600dfa60` |  62 | Protobuf / ZigZag | **`protobuf_decode_sint64_zigzag`** — Protobuf 64-bit zigzag decoder: reads 64-bit varint via `FUN_60082410`, decodes zigzag encoding `(n >> 1) ^ -(n & 1)` to signed 64-bit integer into `*param_2`. | 0 callers / 1 callee |
| `0x600dfadc` |  36 | Protobuf / Iterator | **`protobuf_field_iterator_init`** — Protobuf field descriptor iterator initializer: initializes iterator struct `param_1[0..5]` with descriptor table `param_2` and base struct `param_3`. | 6 callers / 0 callees |
| `0x600dfb00` | 126 | Protobuf / Iterator | **`protobuf_field_iterator_next`** — Protobuf field descriptor iterator step: advances iterator `param_1[1]` to next field in descriptor table, computes field offsets `param_1[4..5]`. | 5 callers / 1 callee |
| `0x600dfb7e` |  46 | Protobuf / Lookup | **`protobuf_field_descriptor_lookup_by_tag`** — Protobuf field descriptor lookup by tag: iterates through descriptor table (`protobuf_field_iterator_next`) until finding field matching tag `param_2`. | 1 caller / 1 callee |
| `0x600dfbac` | 102 | Gotham / Channel | **`device_info_channel_alloc_and_register`** — Gotham channel descriptor allocator & registrar: allocates 28-byte channel descriptor (`0x1c`) via `pvPortMalloc` (`thunk_EXT_FUN_0000b532`), configures descriptor via `FUN_60061964`, registers to Gotham dispatcher via `gotham__60067d14`. Called by `device_info__6005a1b0`. | 1 caller / 5 callees |
| `0x600dfc22` |  14 | Memory / Zero | **`device_info_state_zero_16b`** — 16-byte state buffer zeroer: zeroes 16 bytes (`0x10`) at `param_1` via `memset_zero` (`thunk_EXT_FUN_0000b52e`). | 0 callers / 1 callee |
| `0x600dfc30` |  38 | RemoteDB / Sync | **`remote_device_db_sync_record`** — Remote device DB record synchronizer: computes scaled offset `param_1[4] * 0x9d`, invokes DB record sync `FUN_600cc29c`. Called by `remote_device_db__60083080` and `remote_device_db__6006c340`. | 2 callers / 1 callee |
| `0x600dfc68` |  22 | RemoteDB / Sector | **`remote_device_db_flush_sector`** — Remote device DB sector flusher: calls `FUN_60101c60(*param_1, 0x810, 0x10)`. Called by `remote_device_db__6008318c` and `remote_device_db__6006c340`. | 2 callers / 1 callee |
| `0x600dfc7e` |  34 | RemoteDB / Dump | **`remote_device_db_format_dump_entry`** — Remote device DB entry formatter: formats entry text via `FUN_60050c18` and appends to output buffer via `FUN_60101ba2`. Called by `remote_device_db__6006c340`. | 1 caller / 2 callees |
| `0x600dfca0` |  40 | RemoteDB / Channel | **`remote_device_db_lookup_channel_11`** — Remote device DB channel lookup: searches channel list from `FUN_600653f0` for channel type 11 (`0xb`), returns channel index `piVar2[1]`. Called by `remote_device_db__60083080` and `remote_device_db__6006c340`. | 2 callers / 1 callee |
| `0x600dfcf2` |  50 | Util / Search | **`util_record_binary_search`** — Binary searches sorted record table `param_1[2]` with count `param_1[4]` using comparator `util__60092128`. Called by `0x600dfd24`. | 1 caller / 1 callee |
| `0x600dfd24` |  70 | Util / Lookup | **`util_record_lookup_by_key`** — Record lookup by key: searches sorted 16-byte record table (`0x10` stride) via `util_record_binary_search` (`FUN_600dfcf2`), extracts payload pointer and length. Called by `0x600d4664`. | 1 caller / 1 callee |

## Session 86 (Wave 56) — Private Heap, State Machine Queue & Audio DSP Biquad Filters (20 functions, 1,198 bytes)

Decompiled and documented 20 functions (1,198 bytes across `0x600dfd6a`–`0x600e0298`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600dfd6a` |  20 | Memory / Heap | **`private_heap_hash_tuple_calc`** — Private heap hash calculator: computes hash value `param_1[2] + (*param_1 * 31 + param_1[1]) * 31` (canonical polynomial hash with multiplier 31 / `0x1f`). Called by `private_heap__60083534`, `private_heap__600835ac`, `private_heap__60083568`, and `0x600dfd7e`. | 5 callers / 0 callees |
| `0x600dfd7e` |  48 | Memory / Heap | **`private_heap_node_init_and_insert`** — Private heap node initializer: initializes key tuple `[-1, param_2 - 0x20, 16]`, calculates hash via `private_heap_hash_tuple_calc`, inserts into heap hash table `private_heap__60083534`, and populates reverse lookup entry. Called by `FUN_60055704`. | 1 caller / 2 callees |
| `0x600dfe3e` |  48 | RemoteDevice / Message | **`remote_device_msg_format_and_send_1`** — Remote device message formatter & sender: acquires formatting buffer at `param_1 + 0x14` via `FUN_60101a80`, serializes message via `FUN_600cc450`, transmits via `FUN_6010138c`, and releases buffer via `FUN_60101a54`. Called by `FUN_60083900`. | 1 caller / 4 callees |
| `0x600dfe6e` |  48 | RemoteDevice / Message | **`remote_device_msg_format_and_send_2`** — Remote device message formatter & sender: acquires formatting buffer at `param_1 + 0x14` via `FUN_60101a80`, serializes message via `FUN_600cc450`, transmits via `FUN_6010138c`, and releases buffer via `FUN_60101a54`. Called by `FUN_60083678` and `FUN_600836a0`. | 2 callers / 4 callees |
| `0x600dfe9e` | 134 | Routing / Path | **`routing_path_cost_eval_and_select`** — Routing path cost evaluator: evaluates dual-channel path costs between `param_1` and `param_2` via `FUN_60083c78`, selects optimal route and records hop sequence in route buffer `param_5`. Called by `FUN_60083730` and `FUN_60051890`. | 2 callers / 2 callees |
| `0x600dff24` |  24 | Device / Profile | **`device_profile_offset_calc`** — Device profile offset calculator: computes base offset `0x68` (or `0x20` if flag `& 0x10` set), plus 4 if extended flag set in `*(param_1 + 0x5c)`. Called by `0x600dff3c` and `FUN_60083e30`. | 2 callers / 0 callees |
| `0x600dff3c` |  24 | Device / Profile | **`device_profile_query_offset`** — Device profile query offset: checks profile type mask `*param_1 & 0x1010 == 0`, invokes `device_profile_offset_calc` (`0x600dff24`). Called by `FUN_60083e30`. | 1 caller / 1 callee |
| `0x600dff54` |  34 | StateMachine / Format | **`state_machine_format_field_1`** — State machine diagnostic formatter: formats diagnostic text via `FUN_60050c18` and appends to output buffer `param_1` via `FUN_60101ba2`. | 7 callers / 2 callees |
| `0x600dff76` |  34 | StateMachine / Format | **`state_machine_format_field_2`** — State machine diagnostic formatter: formats 64-bit/multi-word diagnostic field via `FUN_60050c18` and appends to output buffer `param_1` via `FUN_60101ba2`. | 7 callers / 2 callees |
| `0x600dff98` |  40 | StateMachine / Iterator | **`state_machine_entry_fetch_8`** — State machine entry fetcher: checks validity byte `*(param_3 + 4)`, retrieves iterator node via `thunk_EXT_FUN_0000ab36`, invokes handler callback `*(param_2 + 8)`. | 5 callers / 1 callee |
| `0x600dffc0` |  40 | StateMachine / Iterator | **`state_machine_entry_fetch_c`** — State machine entry fetcher: checks validity byte `*(param_3 + 4)`, retrieves iterator node via `thunk_EXT_FUN_0000ab36`, invokes handler callback `*(param_2 + 0xc)`. | 1 caller / 1 callee |
| `0x600dffe8` |  70 | StateMachine / Search | **`state_machine_find_matching_entry`** — State machine iterator search: iterates linked nodes (`thunk_EXT_FUN_0000ab28`/`thunk_EXT_FUN_0000ab42`), fetches entries via `FUN_600dff98`, searches for matching key `param_2`. | 9 callers / 4 callees |
| `0x600e002e` |  92 | StateMachine / Queue | **`state_machine_drain_pending_events`** — State machine event queue drainer: sets active flag `param_1[0x16] = 1`, drains event queue nodes via virtual method `+0x10` or iterator `FUN_600dffc0`, dispatches each event to handler `state_machine__60084104`. Called by `state_machine__600843c8` and `state_machine__600848bc`. | 2 callers / 4 callees |
| `0x600e008a` |  64 | StateMachine / Queue | **`state_machine_queue_cleanup_and_free`** — State machine queue cleanup: iterates active queue elements between `param_1 + 0x38` and `param_1 + 0x48`, processes state via `state_machine__60084644`, frees allocated 512-byte blocks (`0x200`) via `vPortFree` (`thunk_EXT_FUN_0000b52a`). Called by `state_machine__600849a4` and `state_machine__600848bc`. | 2 callers / 2 callees |
| `0x600e00ca` | 234 | StateMachine / Queue | **`state_machine_queue_push_element`** — State machine ring buffer/queue push element: manages array of 512-byte capacity chunk buffers (`0x200` bytes each), reallocates and moves chunk pointers with `memmove` (`thunk_EXT_FUN_0000b588`) and `pvPortMalloc` (`thunk_EXT_FUN_0000b532`), appends element `param_2`. Called by `state_machine__600849a4`. | 1 caller / 4 callees |
| `0x600e01b4` | 142 | Audio / DSP | **`audio_dsp_biquad_coefficients_calc`** — Audio DSP biquad filter coefficient calculator: converts integer filter parameters to float using VFP instructions (`vcvt.f32.u32`), scales by 0.5, calculates dual biquad stage coefficients via `FUN_60084b90`. Called by `FUN_600591b4`. | 1 caller / 1 callee |
| `0x600e0242` |  50 | Gotham / Queue | **`gotham_channel_drain_pending_queue`** — Gotham channel queue drainer: checks queue status via `FUN_600867c8`, invokes packet completion callback `*(param_1 + 0x20)`, frees packet buffer via `thunk_EXT_FUN_0000ac5e`. Called by `firmware_image_upload__60078340`, `gotham__60067d14`, `FUN_600d3b02`. | 3 callers / 2 callees |
| `0x600e0274` |  26 | Gotham / Event | **`gotham_channel_post_event_with_length`** — Gotham channel event dispatcher: calculates payload length via `FUN_6004cb28`, dispatches event packet via `thunk_EXT_FUN_00006668`. Called by `FUN_60084cc4`. | 1 caller / 2 callees |
| `0x600e028e` |  10 | BIO / Event | **`bio_channel_11_event_trigger`** — Triggers BIO event on channel 11 (`0xb`) via `bio__60084c90`. Called by `device_info__6005a4cc` and `firmware_image_upload__60078340`. | 2 callers / 1 callee |
| `0x600e0298` |  16 | Gotham / Packet | **`gotham_packet_list_append`** — Gotham packet singly-linked list appender: traverses `+0x20` pointer chain to end of list, appends new packet `param_2`. Called by `device_info__6005a4cc`. | 1 caller / 0 callees |

## Session 87 (Wave 57) — Gotham Channel Node Allocators, Hexdump Formatter & Log Packet Queue (20 functions, 812 bytes)

Decompiled and documented 20 functions (812 bytes across `0x600e02a8`–`0x600e064c`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e02a8` |   6 | Gotham / Packet | **`gotham_packet_next_ptr_read`** — Gotham packet next pointer reader: returns `*(param_1 + 0x20)`. Called by `gotham__60067a68`, `FUN_600d7ebc`, `FUN_600d7e56`. | 3 callers / 0 callees |
| `0x600e02ae` |  34 | Gotham / Channel | **`gotham_channel_node_alloc_init`** — Gotham channel node allocator: allocates 40-byte node (`0x28`) via `FUN_600e092c`, zeroes 32-byte payload via `memset_zero`, initializes header fields `param_1` and `param_2`. Called by `gotham__600679d4`. | 1 caller / 2 callees |
| `0x600e02d0` |   6 | Gotham / Channel | **`gotham_channel_field_1c_set`** — Stores `param_2` at `*(param_1 + 0x1c)`. Called by `gotham__600679d4`. | 1 caller / 0 callees |
| `0x600e02d6` |   6 | Gotham / Channel | **`gotham_channel_field_20_set`** — Stores `param_2` at `*(param_1 + 0x20)`. Called by `gotham__600679d4`. | 1 caller / 0 callees |
| `0x600e02dc` |   6 | Gotham / Channel | **`gotham_channel_field_08_set`** — Stores `param_2` at `*(param_1 + 0x08)`. Called by `gotham__600679d4`. | 1 caller / 0 callees |
| `0x600e02e2` |   6 | Gotham / Channel | **`gotham_channel_field_0c_set`** — Stores `param_2` at `*(param_1 + 0x0c)`. Called by `gotham__600679d4`. | 1 caller / 0 callees |
| `0x600e02e8` |   6 | Gotham / Channel | **`gotham_channel_field_14_set`** — Stores `param_2` at `*(param_1 + 0x14)`. Called by `gotham__600679d4`. | 1 caller / 0 callees |
| `0x600e02ee` |   6 | Gotham / Channel | **`gotham_channel_field_18_set`** — Stores `param_2` at `*(param_1 + 0x18)`. Called by `gotham__600679d4`. | 1 caller / 0 callees |
| `0x600e02f4` |   4 | Gotham / Packet | **`gotham_packet_field_1c_set`** — Stores `param_2` at `*(param_1 + 0x1c)`. Called by `gotham__60067d14`, `FUN_600d7d6c`, `FUN_600d7d50`. | 3 callers / 0 callees |
| `0x600e02f8` |   4 | Gotham / Packet | **`gotham_packet_field_1c_get`** — Returns `*(param_1 + 0x1c)`. Called by `gotham__60067b50`, `gotham__60067d14`, `gotham__60067c3c`, `gotham__60067a68`. | 5 callers / 0 callees |
| `0x600e02fc` |   4 | Gotham / Packet | **`gotham_packet_field_04_set`** — Stores `param_2` at `*(param_1 + 4)`. Called by `gotham__60067d14`, `FUN_600d7d6c`. | 2 callers / 0 callees |
| `0x600e0300` |   4 | Gotham / Channel | **`gotham_channel_status_check`** — Returns 1. Called by `gotham__600679d4`. | 1 caller / 0 callees |
| `0x600e0304` | 340 | Firmware / Hexdump | **`firmware_hexdump_formatter`** — Canonical standard 16-byte hex dump formatter with ASCII sidebar: formats 16 bytes per line with 8-byte column spacing (`uVar3 = 4` at column 7, `uVar3 = 5` with `\|` delimiter at column 15), printable character sanitization (`.` for unprintable characters `< 0x20` or `> 0x7e`), and line-ending delimiter `\|\n` (`0xa7c`), writing chunks via `thunk_EXT_FUN_00006668`. Called by `firmware_image_upload__60078340`. | 1 caller / 4 callees |
| `0x600e049a` |  46 | Gotham / Connection | **`gotham_connection_close_and_notify`** — Gotham connection close & notify: invokes custom connection close callback `*(param_1 + 0x1c) + 0x14` or cleanup cascade `FUN_600ea886`/`FUN_600ea7fa`/`FUN_600e7474`, tail-calls `func_0x600e0458`. Resized from 112B to 46B. | 0 callers / 3 callees |
| `0x600e04c8` |  44 | Gotham / Channel | **`gotham_channel_array_cleanup`** — Cleans up 16 16-byte channel descriptors (`0x100` bytes) via `thunk_EXT_FUN_0000ac06`, frees `*(param_1 + 0x108)` and `param_1` via `thunk_EXT_FUN_0000ac5e`. | 0 callers / 2 callees |
| `0x600e04f4` |  46 | Gotham / Log | **`gotham_log_packet_enqueue_or_free`** — Gotham log packet queue inserter: retrieves log context via `thunk_EXT_FUN_000066b8`, inserts packet `param_1` into queue slot if not full, or frees packet via `thunk_EXT_FUN_0000ac5e`. Called by `FUN_600e064c` and `FUN_600e05bc`. | 2 callers / 2 callees |
| `0x600e0522` |  24 | Gotham / Channel | **`gotham_channel_config_zero`** — Invokes `FUN_60084f04(0, 0, 0, 0, 0, 0, param_3)`. Called by `FUN_60086508`. | 1 caller / 1 callee |
| `0x600e053a` |  24 | Gotham / Channel | **`gotham_channel_config_init_mode_1`** — Invokes `FUN_60084f04(0, 1, 0, 0, 0, 0, param_3)`. Called by `bcm__6008e700`. | 1 caller / 1 callee |
| `0x600e05bc` | 144 | Gotham / Log | **`gotham_log_msg_concat_and_enqueue`** — Concatenates `param_1` string arguments into dynamically grown buffer, null-terminates, enqueues via `gotham_log_packet_enqueue_or_free` (`0x600e04f4`). Called by `FUN_60086508`, `FUN_60091ddc`, `tasn_dec__6008fa18`. | 3 callers / 6 callees |
| `0x600e064c` |  52 | Gotham / Log | **`gotham_log_msg_format_and_enqueue`** — Allocates 257-byte log buffer (`0x101`), formats log string via `thunk_FUN_600cdd6c`, null-terminates, enqueues via `gotham_log_packet_enqueue_or_free` (`0x600e04f4`). Called by `evp__6008506c`. | 1 caller / 3 callees |

## Session 88 (Wave 58) — Crypto EVP/ASN.1, Ed25519/X25519 Key Management & Safe String Helpers (20 functions, 510 bytes)

Decompiled and documented 20 functions (510 bytes across `0x600e0680`–`0x600e0a14`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e0680` |  22 | Crypto / EVP | **`crypto_evp_cipher_ctx_cleanup`** — EVP cipher context cleanup: invokes cipher-specific cleanup callback `*(ctx + 0xc) + 0x4c`, zeroes state fields `param_1 + 4` and `param_1 + 8`. Called by `evp__6008506c` and `0x600e0696`. | 2 callers / 0 callees |
| `0x600e0696` |  30 | Crypto / EVP | **`crypto_evp_cipher_ctx_free`** — EVP cipher context destructor: verifies reference count via `FUN_600867c8`, cleans up context via `crypto_evp_cipher_ctx_cleanup` (`0x600e0680`), and frees memory via `thunk_EXT_FUN_0000ac5e`. | 0 callers / 3 callees |
| `0x600e06b4` |  10 | Crypto / EVP | **`crypto_evp_cipher_init_stub`** — Initializes EVP cipher subsystem via `FUN_600867a4`, returns 1. | 0 callers / 1 callee |
| `0x600e06be` |  18 | Crypto / EVP | **`crypto_evp_pkey_ctx_init`** — EVP pkey context initializer: invokes `FUN_60085040`, if successful triggers ASN.1 key handler `FUN_600ea86e`. | 0 callers / 2 callees |
| `0x600e06e6` |   8 | Crypto / ASN1 | **`crypto_asn1_error_dispatch_6`** — ASN.1 error reporting wrapper: calls `func_0x600e06d0(param_1, 6, param_2)`. | 0 callers / 0 callees |
| `0x600e06f6` |  10 | Crypto / ASN1 | **`crypto_asn1_error_dispatch_198`** — ASN.1 error reporting wrapper: calls `func_0x600e06d0(param_1, 0x198, param_2)`. Called by `FUN_60085528`. | 1 caller / 0 callees |
| `0x600e080c` |  22 | Crypto / Ed25519 | **`crypto_ed25519_pubkey_import`** — Ed25519 public key importer: extracts key data from ASN.1 structure `*(param_2 + 8)` via `FUN_600ea886`, imports key into BCM crypto context `*(param_1 + 8)` via `bcm__6008d6b8`. | 0 callers / 2 callees |
| `0x600e0822` |  32 | Crypto / Ed25519 | **`crypto_ed25519_key_decode`** — Ed25519 key decoder: parses ASN.1 key structure via `FUN_600ea886`/`FUN_600ea7fa`, extracts key via `FUN_600e7450`, or records error via `thunk_EXT_FUN_0000ac1e`. | 0 callers / 4 callees |
| `0x600e084e` |  58 | Crypto / Ed25519 | **`crypto_ed25519_key_compare`** — Ed25519 key comparator: extracts key material lengths and pointers from both parameters via `FUN_600ea886`/`FUN_600ea88e`, compares keys via constant-time comparison helper `bcm__6008db08`, maps 0 to 1 (equal), 1 to 0 (unequal), other to -2. | 0 callers / 3 callees |
| `0x600e0890` |  16 | Crypto / Ed25519 | **`crypto_ed25519_key_free`** — Ed25519 key destructor: frees key buffer `*(param_1 + 8)` via `thunk_EXT_FUN_0000ac5e`, clears pointer. Called by `p_ed25519_asn1__60085728`. | 1 caller / 1 callee |
| `0x600e0904` |  16 | Crypto / X25519 | **`crypto_x25519_key_free`** — X25519 key destructor: frees key buffer `*(param_1 + 8)` via `thunk_EXT_FUN_0000ac5e`, clears pointer. Called by `p_x25519_asn1__60085c98`. | 1 caller / 1 callee |
| `0x600e0914` |  20 | Crypto / X25519 | ~~**`crypto_x25519_key_memcmp_32b`** — X25519 constant-time 32-byte key comparison: compares 32-byte (`0x20`) buffers `*(param_1 + 8)` and `*(param_2 + 8)` via `thunk_EXT_FUN_0000b554`, returns true if identical.~~ ⚠️ **"constant-time" misidentified, corrected QA session 88** — `thunk_EXT_FUN_0000b554` is already independently established since session 5 (`bruce-itcm.md`) and re-confirmed at 5+ other call sites across `bruce-bta-stack.md`/`bruce-misc-functions.md` as plain **`memcmp`** ("byte-by-byte compare... else the signed difference of the first mismatching byte pair" — a defining early-exit-on-mismatch shape), not a constant-time comparator. This is the exact opposite property from this wave's own correctly-identified `crypto_constant_time_memcmp_diff` (`0x600e0976`, verified this session: an XOR-accumulate loop with **no early exit**, the real defining shape of constant-time comparison). The 32-byte buffer compare and true-if-identical behavior are otherwise accurate; only the "constant-time" claim is wrong — real behavior is a regular (potentially timing-variable) 32-byte memcmp. | 0 callers / 1 callee |
| `0x600e0928` |   4 | Crypto / Heap | **`crypto_heap_thunk_8844`** — Heap allocator trampoline thunk forwarding to `thunk_EXT_FUN_00008844`. | 0 callers / 1 callee |
| `0x600e093e` |  56 | Crypto / Memory | **`crypto_realloc`** — Crypto memory reallocator: if `ptr == NULL` delegates to `malloc(param_2)` (`0x600e092c`); otherwise retrieves old size `*(ptr - 8)`, allocates new buffer, copies `min(old_size, new_size)` bytes via `memcpy` (`thunk_EXT_FUN_0000b572`), frees old buffer via `free` (`thunk_EXT_FUN_0000ac5e`), and returns new pointer. Called across ASN.1 / PEM / crypto subsystems. | 7 callers / 3 callees |
| `0x600e0976` |  26 | Crypto / Util | **`crypto_constant_time_memcmp_diff`** — Constant-time memory difference accumulator: computes bitwise difference `bVar1 = bVar1 \| (*(param_1 + i) ^ *(param_2 + i))` over `param_3` bytes, preventing timing side-channel attacks. Called by `FUN_600ed3a0`. | 1 caller / 0 callees |
| `0x600e0990` |  38 | Crypto / String | **`crypto_strdup`** — String duplicator: calculates length via `strlen` (`FUN_6004cb28`), allocates `len + 1` bytes via `malloc` (`0x600e092c`), copies string plus null terminator via `memcpy`. | 0 callers / 3 callees |
| `0x600e09c2` |  26 | Crypto / Log | **`crypto_log_vprintf_wrapper`** — Formatted log printer wrapper: passes arguments to `FUN_600cdd6c`. Called by `FUN_60091ddc`. | 1 caller / 1 callee |
| `0x600e09dc` |   4 | Crypto / Log | **`crypto_log_printf_thunk`** — Formatted print trampoline thunk forwarding to `FUN_600cdd6c`. Called by `0x600e064c`. | 1 caller / 1 callee |
| `0x600e09e0` |  48 | Crypto / String | **`crypto_strlcpy`** — Standard `strlcpy` string copy helper: bounded copy of `param_2` to `param_1` with size limit `param_3`, guarantees null termination, returns bytes copied plus source length. Called by `0x600e0a14`, `FUN_60086b98`, `FUN_60091ab4`. | 3 callers / 1 callee |
| `0x600e0a14` |  46 | Crypto / PEM | **`crypto_pem_string_copy_safe`** — Safe PEM string copy helper: checks null pointers, verifies length `strlen(param_4) < param_2`, and copies string via `crypto_strlcpy` (`0x600e09e0`). Called by `pem_lib__60085f2c`. | 1 caller / 2 callees |

## Session 89 (Wave 59) — BoringSSL `OPENSSL_sk` Stack Engine & Crypto Mutex Synchronization (20 functions, 398 bytes)

Decompiled and documented 20 functions (398 bytes across `0x600e0a54`–`0x600e0c94`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e0a54` |  28 | Crypto / Bignum | **`crypto_bn_asn1_alloc_and_decode`** — Bignum ASN.1 allocator & decoder: allocates BIGNUM context via `bcm__6008b384`, stores in `*param_2`, decodes ASN.1 structure via `bn_asn1__60090dd8`. Called by `FUN_60086824`, `FUN_600868fc`. | 2 callers / 2 callees |
| `0x600e0a70` |  60 | Crypto / Stack | **`crypto_stack_alloc_with_capacity_4`** — OpenSSL/BoringSSL `OPENSSL_sk_new` stack structure allocator: allocates 20-byte stack header (`0x14`), zeroes it, allocates 16-byte initial element array (`0x10` bytes = 4 pointers), sets capacity `*(iVar1 + 0xc) = 4` and element comparator `*(iVar1 + 0x10) = param_1`. | 2 callers / 3 callees |
| `0x600e0aac` |   6 | Crypto / Stack | **`crypto_stack_alloc_null_comparator`** — OpenSSL/BoringSSL `OPENSSL_sk_new_null`: calls `crypto_stack_alloc_with_capacity_4(0)`. Called by `tasn_new__60090c3c`, `tasn_dec__6008ffc0`, `bcm__6008b570`. | 3 callers / 1 callee |
| `0x600e0ab2` |   6 | Crypto / Stack | **`crypto_stack_num_elements`** — OpenSSL/BoringSSL `OPENSSL_sk_num`: returns `*stack` (element count) or 0 if NULL. | 9 callers / 0 callees |
| `0x600e0ab8` |  20 | Crypto / Stack | **`crypto_stack_value_at_index`** — OpenSSL/BoringSSL `OPENSSL_sk_value`: returns `stack->data[index]` if `index < stack->num`, else NULL. Called by 8 callers across `ex_data.c`, `tasn_dec.c`, `bcm.c`. | 8 callers / 0 callees |
| `0x600e0acc` |  22 | Crypto / Stack | **`crypto_stack_set_value_at_index`** — OpenSSL/BoringSSL `OPENSSL_sk_set`: sets `stack->data[index] = value` if `index < stack->num`, returns value or NULL. Called by `FUN_60090568`. | 1 caller / 0 callees |
| `0x600e0ae2` |  24 | Crypto / Stack | **`crypto_stack_free_shallow`** — OpenSSL/BoringSSL `OPENSSL_sk_free`: frees `stack->data` and `stack` header via `free` (`thunk_EXT_FUN_0000ac5e`). | 4 callers / 1 callee |
| `0x600e0afa` |  46 | Crypto / Stack | **`crypto_stack_pop_free_with_callback`** — OpenSSL/BoringSSL `OPENSSL_sk_pop_free`: iterates elements in stack, invokes free callback `param_2(element)`, then frees stack via `crypto_stack_free_shallow` (`0x600e0ae2`). Called by `FUN_6008b544`. | 1 caller / 1 callee |
| `0x600e0be8` |   6 | Crypto / Stack | **`crypto_stack_push_element`** — OpenSSL/BoringSSL `OPENSSL_sk_push`: inserts `param_2` at end of stack via `func_0x600e0b28(stack, elem, stack->num)`. Resized from 134B to 6B. | 2 callers / 0 callees |
| `0x600e0bee` |  16 | Crypto / Stack | **`crypto_stack_pop_element`** — OpenSSL/BoringSSL `OPENSSL_sk_pop`: pops last element `stack->num - 1` via `func_0x600e0ba8`. Resized from 80B to 16B. | 1 caller / 0 callees |
| `0x600e0bfe` |  76 | Crypto / Stack | **`crypto_stack_dup_deep`** — OpenSSL/BoringSSL `OPENSSL_sk_dup`: clones stack structure, reallocates element buffer via `crypto_realloc` (`0x600e093e`), copies pointer array via `memcpy`. Called by `ex_data__600919d4`. | 1 caller / 4 callees |
| `0x600e0c4a` |  16 | Crypto / Mutex | **`crypto_mutex_lock_and_panic_check`** — Locks crypto mutex via `FUN_600ee100`, panics via `FUN_6010209a` on deadlock/error. Called by `dsa__60091098`, `bcm__600ebf76`. | 2 callers / 2 callees |
| `0x600e0c5a` |  14 | Crypto / Mutex | **`crypto_mutex_lock_1`** — Locks crypto mutex via `thunk_EXT_FUN_0000b28c`, panics on failure. | 1 caller / 2 callees |
| `0x600e0c68` |   4 | Crypto / Mutex | **`crypto_mutex_lock_1_thunk`** — Trampoline thunk to `crypto_mutex_lock_1` (`0x600e0c5a`). Called by `FUN_60086740`. | 1 caller / 1 callee |
| `0x600e0c6c` |  14 | Crypto / Mutex | **`crypto_mutex_unlock_1`** — Unlocks crypto mutex via `thunk_EXT_FUN_0000b294`, panics on failure. | 1 caller / 2 callees |
| `0x600e0c7a` |   4 | Crypto / Mutex | **`crypto_mutex_unlock_1_thunk`** — Trampoline thunk to `crypto_mutex_unlock_1` (`0x600e0c6c`). Called by `FUN_60086740`. | 1 caller / 1 callee |
| `0x600e0c7e` |   4 | Crypto / Mutex | **`crypto_mutex_lock_2_thunk`** — Trampoline thunk to `FUN_600ee0c8`. Called by `FUN_600910dc`, `FUN_6008ea5c`, `bcm__600ebf76`. | 3 callers / 1 callee |
| `0x600e0c82` |  14 | Crypto / Mutex | **`crypto_mutex_lock_global`** — Locks global crypto mutex via `thunk_EXT_FUN_0000b28c`, panics on failure. Called by 6 crypto subsystems (`obj.c`, `ex_data.c`, etc.). | 6 callers / 2 callees |
| `0x600e0c90` |   4 | Crypto / Mutex | **`crypto_mutex_lock_global_thunk`** — Trampoline thunk to `crypto_mutex_lock_global` (`0x600e0c82`). Called by 5 subsystems. | 5 callers / 1 callee |
| `0x600e0c94` |  14 | Crypto / Mutex | **`crypto_mutex_unlock_global`** — Unlocks global crypto mutex via `thunk_EXT_FUN_0000b294`, panics on failure. Called by 5 subsystems. | 5 callers / 2 callees |

## Session 90 (Wave 60) — Curve25519 / Ed25519 / X25519 Field Arithmetic & Point Operations (20 functions, 3,936 bytes)

Decompiled and documented 20 functions (3,936 bytes across `0x600e0ca2`–`0x600e1c92`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e0ca2` |    4 | Crypto / Mutex | **`crypto_mutex_unlock_global_thunk`** — Trampoline thunk to `crypto_mutex_unlock_global` (`0x600e0c94`). | 5 callers / 1 callee |
| `0x600e0ca6` |    6 | Crypto / Stack | ~~**`crypto_stack_is_sorted`** — Returns `*(stack + 8)` (sorted boolean flag).~~ ⚠️ **wrong offset, corrected QA session 90** — raw disassembly (`ldr r3,[r0]; ldr r0,[r3,#0x14]; bx lr`) confirms the real body is `*(*param_1 + 0x14)`: an extra pointer indirection (dereference `param_1` first) at offset **`0x14`** (20), not a single dereference at offset 8. Since the established `OPENSSL_sk` stack header is only 0x14 bytes total (`crypto_stack_alloc_with_capacity_4`, session 89), offset `0x14` from a *dereferenced* pointer falls just past the end of an embedded stack struct, not inside it — the sole caller (`device_info__6005a1b0`) suggests this may be a `device_info.cc`-specific field getter that only superficially resembles a generic stack accessor, not confirmed to be `OPENSSL_sk_is_sorted` at all. Real identity left unconfirmed rather than guessed. | 1 caller / 0 callees |
| `0x600e0cac` |   56 | Crypto / Stack | **`crypto_stack_find_element`** — `OPENSSL_sk_find`: linear search through stack elements for matching item via comparator `FUN_600edc52`, returns index or -1. | 0 callers / 3 callees |
| `0x600e0ce4` |   38 | Crypto / Stack | ~~**`crypto_stack_sort_and_find`** — Sorts stack if unsorted and binary searches for matching element via `crypto_stack_value_at_index` (`0x600e0ab8`).~~ ⚠️ **misidentified, corrected QA session 90** — the decompiled body has no sort call and no binary-search loop at all: it bounds-checks a caller-supplied index (rejects negative indices and indices `≥ crypto_stack_num_elements`, `0x600e0ab2`) and then does a single direct indexed lookup via `crypto_stack_value_at_index` (`0x600e0ab8`) — a bounds-checked direct getter, structurally a stricter sibling of `OPENSSL_sk_value` itself, not `OPENSSL_sk_find`. Renamed in spirit to "bounds-checked indexed getter"; no sort or search of any kind occurs. | 0 callers / 2 callees |
| `0x600e0d54` |   38 | Crypto / ExData | **`crypto_ex_data_get_typed_item`** — Retrieves application-specific extra data (`ex_data`) item for given object type (`obj__60091c10`) and index. Resized from 112B to 38B. | 1 caller / 1 callee |
| `0x600e0e02` | 1190 | Crypto / Curve25519 | **`fe25519_mul`** — 10-limb Curve25519 field multiplication ($2^{25.5}$ radix representation, limbs 0..9 with alternating 26-bit/25-bit representation). Multiplies 10 limbs by 10 limbs, performing polynomial multiplication and modular reduction modulo $2^{255} - 19$ with $19 \times \text{high}$ fold-back. | 8 callers / 0 callees |
| `0x600e12a8` | 1160 | Crypto / Curve25519 | **`fe25519_sq`** — 10-limb Curve25519 field squaring ($2^{25.5}$ radix, optimized squaring with $19 \times \text{high}$ modular reduction). | 1 caller / 0 callees |
| `0x600e1730` |  156 | Crypto / Curve25519 | **`fe25519_carry`** — Curve25519 field carry propagation: carries overflow bits across all 10 limbs (`>> 26`, `>> 25`), reducing limb values modulo $2^{255} - 19$. | 2 callers / 0 callees |
| `0x600e17cc` |  100 | Crypto / Curve25519 | **`fe25519_add`** — 10-limb field addition: adds corresponding limbs element-wise. | 5 callers / 0 callees |
| `0x600e1830` |  158 | Crypto / Curve25519 | **`fe25519_sub`** — 10-limb field subtraction: subtracts corresponding limbs element-wise with borrow/bias addition ($2 \times p$) to prevent underflow. | 5 callers / 0 callees |
| `0x600e18ce` |  286 | Crypto / Curve25519 | **`fe25519_frombytes`** — Converts 32-byte little-endian byte array to 10-limb $2^{25.5}$ radix representation (limbs with 26/25 bits: `& 0x3ffffff`, `& 0x1ffffff`). | 1 caller / 0 callees |
| `0x600e19ec` |   38 | Crypto / Curve25519 | **`fe25519_cmov`** — Constant-time conditional move for 10-limb field element: `out[i] = (b[i] ^ out[i]) & -b_flag ^ out[i]`. | 1 caller / 0 callees |
| `0x600e1a12` |  328 | Crypto / Curve25519 | **`fe25519_invert`** — Field element inversion modulo $2^{255} - 19$ using Fermat's Little Theorem ($a^{2^{255}-21}$ via square-and-multiply chain with `fe25519_sq` and `fe25519_mul`). | 2 callers / 2 callees |
| `0x600e1b5a` |  146 | Crypto / Ed25519 | ~~**`ge25519_p2_dbl`** — Ed25519 point doubling on projective coordinates (`X, Y, Z`): computes $2P$ via `fe25519_add`, `fe25519_sub`, `fe25519_mul`, `fe25519_carry`.~~ ⚠️ **misidentified, corrected QA session 90** — real point doubling (`ge_p2_dbl`) takes exactly one input point and uses only squarings (`fe_sq`/`fe_sq2`), never a general multiply. This function takes **three** parameters (`out, P, Q`) and calls `fe25519_mul` (`0x600e0e02`) — never used by real doubling. Its actual shape (`fe_add(t,P.Y,P.X); fe_sub(u,P.Y,P.X); fe_mul(·,t,Q.field@0); fe_mul(·,u,Q.field@0x28); fe_mul(·,Q.field@0x50,P.T@0x78); ...`) is the defining structure of extended-coordinate **point ADDITION** of a `p3` point `P` and a cached point `Q` (real ref10 `ge_add`/`ge_madd` family: `fe_mul(r->Z, P.Y+P.X, Q.YplusX); fe_mul(r->Y, P.Y-P.X, Q.YminusX); fe_mul(r->T, Q.T2d, P.T); ...`) producing a `p1p1` result, not a doubling of a single point. ⚠️ **Update, QA session 91**: session 91's new `ge25519_add_p3_cached` (`0x600e1cd4`) is structurally near-identical to this function except it additionally multiplies `P.Z@0x50 * Q.Z@0x50` (doubled) where *this* function instead just self-doubles `P.Z` directly with no multiply — exactly the documented difference between real ref10 `ge_add` (full 4-field cached point, needs `P.Z·Q.Z`) and `ge_madd` (3-field "precomp" table with `Q.Z` implicitly 1, so `t0 = P.Z+P.Z` needs no multiply). This resolves the "left unconfirmed" question below: this function (`0x600e1b5a`) is **`ge25519_madd`** (p3 + precomp mixed addition), and `0x600e1cd4` is the full `ge25519_add` (p3 + cached addition). | 1 caller / 4 callees |
| `0x600e1bec` |   20 | Crypto / Ed25519 | ~~**`ge25519_p3_0`** — Ed25519 neutral/identity point initializer: sets `X = 0, Y = 1, Z = 1, T = 0`.~~ ⚠️ **misidentified, corrected QA session 90** — the decompiled body (`thunk_EXT_FUN_0000b5ba(param_1+1,0,0x24); *param_1=1;`) is **byte-for-byte identical** to this same wave's own `fe25519_1` (`0x600e1c08`): it zeroes exactly one 10-limb (40-byte) field element's limbs 1–9 and sets limb 0 to 1. It does not touch 160 bytes (4 field elements) as a full extended-point identity would require — it is a second, separately-compiled instance of "set a single field element to 1," not a point initializer. The real identity-point setup (X=0,Y=1,Z=1,T=0) most likely lives in the shared caller `FUN_60087964`, which calls both this function and `fe25519_0`/`fe25519_1`-shaped helpers to assemble the four fields itself. | 1 caller / 1 callee |
| `0x600e1c00` |    8 | Crypto / Curve25519 | **`fe25519_0`** — Zeroes 40-byte (10-limb) field element via `memset_zero`. | 1 caller / 1 callee |
| `0x600e1c08` |   20 | Crypto / Curve25519 | **`fe25519_1`** — Sets field element to 1 (limb 0 = 1, limbs 1..9 = 0). | 1 caller / 1 callee |
| `0x600e1c1c` |   44 | Crypto / Curve25519 | **`fe25519_copy_and_invert`** — Copies 40-byte (10-limb) field element and computes its modular inverse via `fe25519_invert`. | 1 caller / 1 callee |
| `0x600e1c48` |   74 | Crypto / Ed25519 | ~~**`ge25519_p3_to_p2`** — Converts extended point $(X, Y, Z, T)$ to affine/projective $(X/Z, Y/Z)$ by inverting $Z$ via `fe25519_invert` and multiplying coordinates.~~ ⚠️ **misidentified, corrected QA session 90** — the body does invert `Z` and compute `X/Z`, `Y/Z` as the claim says, but it doesn't stop there: it then packs `Y/Z` to 32 output bytes via `FUN_600875a0` and **XORs the low bit of packed `X/Z` into the top bit of the last output byte** (`*(byte*)(param_1+0x1f) ^= local_a8[0]<<7`). That XOR-sign-bit-into-last-byte step is the unmistakable, textbook signature of Ed25519 **point compression / serialization** (`ge_p3_tobytes` — the function that produces a 32-byte compressed public key or signature `R`), not a bare coordinate-format conversion that leaves the result as two separate field elements. Renamed in spirit to `ge25519_p3_tobytes`. | 1 caller / 3 callees |
| `0x600e1c92` |   66 | Crypto / Ed25519 | ~~**`ge25519_p3_to_cached`** — Converts point $(X, Y, Z, T)$ to precomputed/cached representation $(Y+X, Y-X, 2dXY, 2Z)$ via `fe25519_mul`.~~ ⚠️ **misidentified, corrected QA session 90** — the real `ge_p3_to_cached` needs one add, one sub, one copy, and one multiply by the curve constant `d2`; this body has **zero** add/sub calls and multiplies by no constant. It computes exactly four products from the extended-point fields `(X@0, Y@0x28, Z@0x50, T@0x78)`: `X·T`, `Y·Z`, `Z·T`, `X·Y` — a bit-exact match, in this exact order, to the real ref10 **`ge_p1p1_to_p3`** formula (`r->X=X·T; r->Y=Y·Z; r->Z=Z·T; r->T=X·Y`), which resolves a "completed point" (`p1p1`) intermediate — the output of an add/double formula — into the extended `p3` representation. Renamed in spirit to `ge25519_p1p1_to_p3`. | 1 caller / 1 callee |

## Session 91 (Wave 61) — X25519 Key Derivation, Bitsliced AES Engine, Ed25519 Scalar Math & Curve25519 Montgomery Ladder (20 functions, 6,354 bytes)

Decompiled and documented 20 functions (6,354 bytes across `0x600e1cd4`–`0x600e643a`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e1cd4` |  158 | Crypto / Ed25519 | **`ge25519_add_p3_cached`** — Extended-coordinate point addition combining $P \in \mathcal{E}(p3)$ and precomputed $Q \in \mathcal{E}(\text{cached})$, producing $P + Q$ in $p1p1$ representation via `fe25519_add`, `fe25519_sub`, `fe25519_mul`, `fe25519_carry`. | 1 caller / 4 callees |
| `0x600e1dde` |  118 | Crypto / X25519 | **`x25519_key_derive_public`** — X25519 public key derivation from private scalar: clamps 32-byte secret (`k[0] &= 0xf8; k[31] = (k[31] & 0x7f) \| 0x40`), computes base-point scalar multiplication via `ge25519_scalarmult_base` (`0x60087964`), converts Edwards $(X, Y, Z)$ to Montgomery $u = (Z+Y)/(Z-Y)$ via `fe25519_invert` and `fe25519_mul`, and serializes to 32 bytes via `fe25519_tobytes`. Called by `p_x25519_asn1__60085c98`. | 1 caller / 6 callees |
| `0x600e1e54` |   10 | Crypto / Util | **`crypto_constant_time_is_zero_u32`** — Constant-time 32-bit zero test: computes `(val - 1 & ~val) >> 31`, returning `-1` (`0xffffffff`) if `val == 0`, else `0`. | 5 callers / 0 callees |
| `0x600e1e5e` |   28 | Crypto / Util | **`crypto_xor_words_16b`** — 16-byte bitwise XOR accumulator: XORs 4 32-bit words from source into destination buffer in-place. | 2 callers / 0 callees |
| `0x600e1e7a` |  584 | Crypto / AES | **`crypto_aes_bitsliced_sbox`** — Boyar-Peralta bitsliced AES S-box computation using boolean logic gates for constant-time side-channel resistance. | 3 callers / 0 callees |
| `0x600e20c2` |  100 | Crypto / AES | **`crypto_aes_bitsliced_shiftrows`** — Bitsliced AES ShiftRows byte transposition across state words. | 1 caller / 0 callees |
| `0x600e2126` |   50 | Crypto / AES | **`crypto_aes_bitsliced_mixcolumns_1`** — Bitsliced AES MixColumns linear diffusion matrix transformation. | 1 caller / 0 callees |
| `0x600e2158` |   50 | Crypto / AES | **`crypto_aes_bitsliced_mixcolumns_2`** — Bitsliced AES inverse/alternative MixColumns transformation. | 1 caller / 0 callees |
| `0x600e218a` |   16 | Crypto / AES | **`crypto_aes_bitsliced_rotate_2`** — Bitsliced 2-bit state word permutation. | 2 callers / 0 callees |
| `0x600e219a` |   16 | Crypto / AES | **`crypto_aes_bitsliced_rotate_4`** — Bitsliced nibble swap / 4-bit permutation. | 2 callers / 0 callees |
| `0x600e21aa` |  248 | Crypto / AES | **`crypto_aes_bitsliced_subbytes`** — Bitsliced AES SubBytes layer applying bit permutations and S-box core logic. | 2 callers / 2 callees |
| `0x600e22a2` |   76 | Crypto / AES | **`crypto_aes_bitsliced_round_encrypt`** — Complete bitsliced AES encryption round combining SubBytes, ShiftRows, MixColumns, and AddRoundKey. | 3 callers / 4 callees |
| `0x600e22ee` |   20 | Crypto / Util | **`crypto_xor_128b`** — 128-bit (16-byte) block XOR: `dst[i] = src1[i] ^ src2[i]`. | 3 callers / 0 callees |
| `0x600e2308` |   14 | Crypto / Util | **`crypto_constant_time_select_u32`** — Constant-time 32-bit 2-to-1 multiplexer: `*dst = a ^ (-sel & (b ^ a))`. Selects `b` if `sel == 1`, else `a`. | 5 callers / 0 callees |
| `0x600e5208` |  642 | Crypto / Curve25519 | ~~**`crypto_curve25519_ladder_step`** — Montgomery ladder differential addition and point doubling step ($X_2, Z_2, X_3, Z_3$) using `fe25519` arithmetic.~~ ⚠️ **misidentified, corrected QA session 91** — this function's **sole callee is `crypto_constant_time_select_u32`** (`0x600e2308`); it makes **zero** calls to any `fe25519_*` function. A real Montgomery ladder step is *defined* by `fe_add`/`fe_sub`/`fe_mul`/`fe_sq` calls on 10-limb (40-byte) field elements — none appear here. The actual body operates on `param_2`/`param_3` as 8×32-bit-word (256-bit) integers: a full carry-chain **addition** across all 8 words, followed by an `& 0xff`-masked conditional-subtract correction and a `crypto_constant_time_select_u32` pick between the raw sum and the corrected sum — the defining shape of constant-time **256-bit scalar addition with conditional modular reduction**, not point/field arithmetic. Given its "$X,Y,Z$"-named siblings below share this exact structure and its exact caller pair, this is very likely part of Ed25519's **scalar** (mod `L`, the group order) arithmetic toolkit, not Curve25519's Montgomery `u`-coordinate ladder. Real identity left as "256-bit scalar add-with-conditional-reduce," not renamed to a specific ref10 function. ⚠️ **Open question, added QA session 92**: session 92's `crypto_ed25519_scalar_table_lookup` (`0x600e69c2`) is a confirmed-correct, well-evidenced constant-time lookup over a table of **3×32-byte ("point"-shaped) entries** — real scalarmult-table infrastructure — while `crypto_ed25519_scalarmult_step_add`/`crypto_ed25519_scalar_pack_step` (below) show this add/sub-mod toolkit operating on the *same* 3-coordinate structures. So this cluster is structurally complete and internally consistent (table lookup + cmov + is_zero + copy + pack/unpack + add-mod + sub-mod + select) but is **definitively not built on the established `fe25519_*`/`ge25519_*` Curve25519/Ed25519 stack** (sessions 90–91). Two live hypotheses, neither confirmed: (a) a genuinely separate/portable 8-word Curve25519 or Ed25519-scalar implementation variant, or (b) BoringSSL's *generic* `EC_POINT`/`bcm.c`-style scalar-multiplication code for an unrelated curve (e.g. a NIST prime curve), misattributed to "Ed25519" by naming proximity alone. Recommend a future session check the actual modulus/constant literals used in the add/sub-with-conditional-correction routines against known Curve25519/Ed25519-`L` values vs. P-256/other-curve values to resolve this. | 2 callers / 1 callee |
| `0x600e548a` |  474 | Crypto / Curve25519 | ~~**`crypto_curve25519_cswap_and_add`** — Constant-time conditional swap and ladder addition iteration for scalar multiplication.~~ ⚠️ **misidentified, corrected QA session 91** — the body contains **no swap logic at all** (no bit-controlled exchange of two coordinate pairs, the defining behavior of a real Montgomery-ladder `cswap`) and **no callees**. It is a straight-line, 8-word (256-bit) **subtraction** (`param_2 - param_3`) with the identical `& 0xff`-masked conditional-correction idiom seen in `crypto_curve25519_ladder_step` (`0x600e5208`, corrected above) — i.e. constant-time 256-bit scalar subtraction with conditional modular correction. It shares **both** of its callers exactly with the mis-identified "ladder_step," reinforcing that these are companion primitives in the same 256-bit scalar-arithmetic toolkit (add/sub mod something), not Curve25519 point-coordinate operations. Real identity left as "256-bit scalar subtract-with-conditional-correction." | 2 callers / 0 callees |
| `0x600e5664` |  394 | Crypto / Ed25519 | **`crypto_ed25519_scalar_reduce_512`** — 512-bit (64-byte) scalar modular reduction modulo the group order $L = 2^{252} + 27742317777372353535851937790883648493$. | 2 callers / 0 callees |
| `0x600e57ee` | 2998 | Crypto / Ed25519 | ~~**`crypto_ed25519_scalarmult_variable_base`** — Variable-base scalar multiplication $[s]P$ on Ed25519 with 4-bit comb / windowed multiplication.~~ ⚠️ **misidentified, corrected QA session 91** — across its entire **2,998-byte** body (the largest single decompiled function in this repository), the **only callee is `crypto_constant_time_select_u32`** (`0x600e2308`) — zero calls to any `fe25519_*` field-arithmetic function and zero calls to any `ge25519_*` point-arithmetic function. Elliptic-curve scalar multiplication is *defined* by repeated point doubling/addition through the field layer; a function that never touches it structurally cannot be computing `[s]P`. It shares its exact caller pair (`FUN_6008d3d4`, `FUN_600eb1e4`) with `crypto_ed25519_scalar_frombytes` (`0x600e643a`, confirmed correct this session — a 32-byte→8-word scalar unpacker), reinforcing that this function operates purely in the 256-bit **scalar** (word-array) domain, not the point domain. Combined with the two corrected neighbors above (256-bit scalar add/sub-with-conditional-reduce) and the existing `crypto_ed25519_scalar_reduce_512` (`0x600e5664`), the far more likely real role is a large multi-precision **scalar modular arithmetic** routine — plausibly a full multiply-and-reduce mod `L` (the ~3000-byte size is consistent with the wide NxN-word product plus reduction such a routine needs, e.g. EdDSA signing's `S = r + k·a mod L` step) — but the precise ref10 equivalent is left unconfirmed rather than guessed. | 2 callers / 1 callee |
| `0x600e63a4` |  150 | Crypto / Ed25519 | **`crypto_ed25519_scalar_tobytes`** — Serializes 8 32-bit words (256-bit scalar) to 32 little-endian bytes. Resized from 44B + 106B spurious split to 150B (`0x600e63a4`..`0x600e6439`). | 6 callers / 0 callees |
| `0x600e643a` |  208 | Crypto / Ed25519 | **`crypto_ed25519_scalar_frombytes`** — Deserializes 32 little-endian bytes into 8 32-bit scalar words (`r[0..7]`). | 6 callers / 0 callees |

## Session 92 (Wave 62) — Bitsliced AES State Transformations, Ed25519 Scalar Array Ops & Memory Free Wrapper (20 functions, 1,434 bytes)

Decompiled and documented 20 functions (1,434 bytes across `0x600e650a`–`0x600e6cf2`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e650a` |   32 | Crypto / Ed25519 | **`crypto_ed25519_scalar_is_zero_256`** — Constant-time zero test for 256-bit scalar: computes bitwise OR reduction `param_1[0] \| ... \| param_1[7]`, returning 0 if scalar is all zeros, non-zero otherwise. Called by `FUN_600e66be`. | 1 caller / 0 callees |
| `0x600e652a` |   20 | Crypto / Ed25519 | **`crypto_ed25519_scalar_copy_256`** — Copies 256-bit scalar (8 32-bit words, 32 bytes) from source to destination buffer. | 5 callers / 0 callees |
| `0x600e653e` |  148 | Crypto / Ed25519 | **`crypto_ed25519_scalar_cmov_256`** — Constant-time conditional move for 256-bit scalar: invokes `crypto_constant_time_select_u32` (`0x600e2308`) word-by-word across all 8 32-bit words with selector `param_2 != 0`. | 3 callers / 1 callee |
| `0x600e68ac` |  146 | Crypto / Ed25519 | **`crypto_ed25519_scalarmult_step_add`** — Scalar multiplication point addition wrapper: unpacks input scalars via `FUN_600e643a`, invokes point addition via `FUN_600e66be`, and packs output via `FUN_600e63a4`. ⚠️ **note, QA session 92** — mechanically accurate (unpack→step→pack), but confirms and extends the session-91 finding below: it unpacks **3** separate 0x44-byte-strided sub-fields of its input into 32-byte/8-word buffers (the same "scalar"-domain representation as `crypto_curve25519_ladder_step`/`crypto_curve25519_cswap_and_add`), and its inner step function `FUN_600e66be` is the exact same function session 91 found calling those two mis-labeled "Montgomery ladder" primitives. This is a 3-coordinate ("point"-shaped) structure being manipulated entirely through the 8-word scalar-arithmetic toolkit — **never** through `fe25519_*`/`ge25519_*`. See the open question flagged on `crypto_curve25519_ladder_step`'s row. | 0 callers / 3 callees |
| `0x600e693e` |   88 | Crypto / Ed25519 | **`crypto_ed25519_scalar_pack_step`** — Scalar multiplication step wrapper: deserializes 32-byte buffers via `FUN_600e643a`, performs step calculation via `FUN_600e65d2`, and packs result via `FUN_600e63a4`. ⚠️ **note, QA session 92** — same pattern as `crypto_ed25519_scalarmult_step_add` above: 3×0x44-byte-strided fields unpacked into the scalar-domain, inner step via `FUN_600e65d2` (session 91's other common caller of the "ladder"-labeled primitives). Same open question applies. | 0 callers / 3 callees |
| `0x600e6996` |   22 | Crypto / ASN.1 | **`crypto_asn1_error_dispatch_wrapper_1`** — ASN.1 error reporting trampoline forwarding error code and line info to `thunk_EXT_FUN_0000af88`. | 2 callers / 1 callee |
| `0x600e69ac` |   22 | Crypto / ASN.1 | **`crypto_asn1_error_dispatch_wrapper_2`** — ASN.1 error reporting wrapper passing context parameters to `thunk_EXT_FUN_0000af88`. | 2 callers / 1 callee |
| `0x600e69c2` |   88 | Crypto / Ed25519 | **`crypto_ed25519_scalar_table_lookup`** — Constant-time precomputed table lookup for windowed multiplication: zeroes 96-byte scratch buffer via `thunk_EXT_FUN_0000af90` and performs constant-time scalar selection across table entries via `FUN_600e653e`. | 2 callers / 2 callees |
| `0x600e6a1a` |    8 | Crypto / Util | **`crypto_memmove_wrapper`** — Bounded memory move helper: checks `param_3 != 0` and calls `memmove` (`thunk_EXT_FUN_0000b588`). | 2 callers / 1 callee |
| `0x600e6a22` |   40 | Crypto / Heap | **`crypto_heap_free_checked`** — Checked memory free helper: inspects pointer non-null and calls heap free (`thunk_EXT_FUN_0000ac5e` / `thunk_EXT_FUN_0000b208`). Called by 14+ crypto modules across ASN.1, BCM, and EC. | 14 callers / 1 callee |
| `0x600e6a90` |   24 | Crypto / Util | **`crypto_get_bit_at_index`** — Reads single bit at index `param_2` from 256-bit byte buffer `param_1`: `param_1[param_2 >> 3] >> (param_2 & 7) & 1` if `param_2 < 256`, else 0. | 3 callers / 0 callees |
| `0x600e6aa8` |   26 | Crypto / AES | **`crypto_aes_bitsliced_swap_step`** — Bitsliced permutation 2-word bit swap: `uVar1 = (*param_2 ^ (*param_1 >> 1)) & 0x55555555; *param_1 ^= uVar1 << 1; *param_2 ^= uVar1;`. | 1 caller / 0 callees |
| `0x600e6ac2` |   48 | Crypto / AES | **`crypto_aes_bitsliced_transpose_pairs`** — Applies `crypto_aes_bitsliced_swap_step` across 8 32-bit words (4 pairs) for state transposition. | 4 callers / 1 callee |
| `0x600e6af2` |   72 | Crypto / AES | **`crypto_aes_bitsliced_sbox_transpose`** — Transposes 8 words via `crypto_aes_bitsliced_transpose_pairs`, applies bitsliced S-box (`0x600e1e7a`), and transposes back. | 1 caller / 3 callees |
| `0x600e6b3a` |  138 | Crypto / AES | **`crypto_aes_bitsliced_key_expand_step`** — Bitsliced AES round key schedule expansion step with pair transposition. | 4 callers / 1 callee |
| `0x600e6bc4` |   38 | Crypto / AES | **`crypto_aes_bitsliced_bit_permute_1`** — 32-bit word bit permutation using masks `0xcc00cc` (shift 6) and `0xf0f0` (shift 12). | 1 caller / 0 callees |
| `0x600e6bea` |  158 | Crypto / AES | **`crypto_aes_bitsliced_pack_state`** — Packs standard 128-bit AES state words into bitsliced matrix representation using `crypto_aes_bitsliced_bit_permute_1`. | 2 callers / 1 callee |
| `0x600e6c88` |   68 | Crypto / AES | **`crypto_aes_bitsliced_init_state`** — Initializes bitsliced state matrix for `param_3` blocks, zeroing and packing with `crypto_aes_bitsliced_pack_state` and transposing with `crypto_aes_bitsliced_transpose_pairs`. | 5 callers / 3 callees |
| `0x600e6ccc` |   38 | Crypto / AES | **`crypto_aes_bitsliced_bit_permute_2`** — Inverse 32-bit word bit permutation using masks `0xf0f0` (shift 12) and `0xcc00cc` (shift 6). | 1 caller / 0 callees |
| `0x600e6cf2` |  210 | Crypto / AES | **`crypto_aes_bitsliced_unpack_state`** — Unpacks bitsliced state matrix back into standard 128-bit AES block byte representation using `crypto_aes_bitsliced_bit_permute_2`. | 5 callers / 2 callees |

## Session 93 (Wave 63) — Bitsliced AES-GCM Encrypt/Decrypt Engine & OpenSSL BIGNUM Arithmetic Primitives (20 functions, 1,506 bytes)

Decompiled and documented 20 functions (1,506 bytes across `0x600e6dfe`–`0x600e7434`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e6dfe` |   40 | Crypto / AES | **`crypto_aes_gcm_mode_dispatch_encrypt`** — AES-GCM encryption acceleration dispatcher: checks hardware acceleration via `FUN_600ec354`, forwarding to HW engine `0x6013d130` if available, else bitsliced SW fallback `0x600e6dc4`. Resized from 102B spurious split to 40B (`0x600e6dfe`..`0x600e6e25`). | 0 callers / 1 callee |
| `0x600e6e26` |  174 | Crypto / AES | **`crypto_aes_gcm_encrypt_blocks`** — Multi-block AES-GCM counter-mode encryption loop: performs bitsliced state transformation, key schedule expansion (`0x600e6b3a`), block XORs (`0x600e22ee`), and round encryption (`0x600e22a2`). | 0 callers / 5 callees |
| `0x600e6edc` |  158 | Crypto / BN | ~~**`crypto_bn_add_words_with_carry`** — BigNum multi-word addition with full carry propagation across 32-bit limbs using `crypto_constant_time_is_zero_u32` (`0x600e1e54`).~~ ⚠️ **misidentified, corrected QA session 93** — there is no `+`/carry logic anywhere in the body and no output array is ever written; the function returns a single `uint` flag. Per-word it computes `is_zero(a[i]^b[i])` (via the confirmed `crypto_constant_time_is_zero_u32`) and a constant-time less-than bit-trick (`(a-b^a|(a^b))^a >> 31 | 1`), then constant-time-selects: propagate the running result while words are equal, take the fresh per-word result the moment a mismatch is found. This is the textbook shape of a **constant-time multi-word (BIGNUM) comparison** (real BoringSSL equivalent: something in the `bn_less_than_words`/`BN_ucmp` family) — including a tail section handling unequal operand lengths (`param_2` vs `param_4` word counts) by checking whether the longer operand has any nonzero words past the shorter one's length. Not renamed to a specific ref name; real behavior described instead. | 2 callers / 1 callee |
| `0x600e6f7a` |  262 | Crypto / AES | **`crypto_aes_bitsliced_full_round_decrypt`** — Complete bitsliced AES decryption round combining ShiftRows (`0x600e20c2`), SubBytes (`0x600e21aa`), MixColumns (`0x600e2158`), nibble rotate (`0x600e219a`), and round key XORs (`0x600e1e5e`). | 1 caller / 6 callees |
| `0x600e70ba` |   40 | Crypto / AES | **`crypto_aes_gcm_mode_dispatch_decrypt`** — AES-GCM decryption acceleration dispatcher: checks hardware acceleration via `FUN_600ec354`, forwarding to HW engine `0x6008ee70` or bitsliced SW fallback `0x600e7080`. Resized from 136B spurious split to 40B (`0x600e70ba`..`0x600e70e1`). | 0 callers / 1 callee |
| `0x600e70e2` |  312 | Crypto / AES | **`crypto_aes_gcm_decrypt_blocks`** — Multi-block AES-GCM counter-mode decryption loop: handles bitsliced key expansion (`0x600e6b3a`), state initialization (`0x600e6c88`), round decryption (`0x600e6f7a`), and state unpacking (`0x600e6cf2`). Resized from 106B spurious entry (`0x600e7124`) to 312B (`0x600e70e2`..`0x600e7219`). | 0 callers / 7 callees |
| `0x600e721a` |    8 | Crypto / BN | **`crypto_bn_ctx_clear_20b`** — BigNum context helper: zeroes 20-byte context structure using `memset_zero` (`thunk_EXT_FUN_0000af90`). | 4 callers / 1 callee |
| `0x600e7222` |   24 | Crypto / BN | **`crypto_bn_ctx_init`** — BigNum context initializer: zeroes 20-byte context header at `param_1 + 0x24` via `0x600e721a` and clears context state fields at `+0xc0` and `+0x110`. | 0 callers / 1 callee |
| `0x600e723a` |   60 | Crypto / BN | **`crypto_bn_free`** — OpenSSL `BN_free` / `BN_clear_free`: checks pointer non-null, securely wipes limb memory via `thunk_EXT_FUN_0000ac52` if `flags & 2` is set, and frees via `thunk_EXT_FUN_0000ac5e`. | 2 callers / 2 callees |
| `0x600e7276` |   92 | Crypto / BN | **`crypto_bn_count_bits_u32`** — OpenSSL `BN_num_bits_word`: returns bit length (1..32) of 32-bit unsigned word using binary-search shift/mask reduction. | 3 callers / 0 callees |
| `0x600e72d2` |   32 | Crypto / BN | **`crypto_bn_is_zero_limbs`** — Tests if BigNum limbs from index `param_2` through `top` are all zero. | 4 callers / 0 callees |
| `0x600e72f2` |   10 | Crypto / BN | **`crypto_bn_is_negative`** — OpenSSL `BN_is_negative`: checks BigNum negative sign flag (`*(int*)(param_1 + 0xc) != 0`). | 1 caller / 0 callees |
| `0x600e732a` |   44 | Crypto / BN | **`crypto_bn_dup`** — OpenSSL `BN_dup`: allocates new BIGNUM via `bcm__6008b384`, copies value via `FUN_600e72fc`, and returns duplicate (or frees via `FUN_600e6a22` on error). | 0 callers / 3 callees |
| `0x600e7356` |   28 | Crypto / BN | **`crypto_bn_set_word_1`** — OpenSSL `BN_set_word` 1-limb core: expands capacity via `bcm__6008b43c`, sets limb 0, clears sign (`neg = 0`), and sets `top = 1`. Created as new function (`0x600e7356`..`0x600e7371`). | 2 callers / 1 callee |
| `0x600e7372` |   16 | Crypto / BN | **`crypto_bn_set_word`** — OpenSSL `BN_set_word`: if scalar != 0 calls `crypto_bn_set_word_1`, else zeroes `top` and sign. | 3 callers / 1 callee |
| `0x600e7382` |    6 | Crypto / BN | **`crypto_bn_set_one`** — OpenSSL `BN_one`: sets BigNum to 1 via `crypto_bn_set_word_1(param_1, 1)`. | 3 callers / 1 callee |
| `0x600e7388` |   36 | Crypto / BN | **`crypto_bn_copy_words`** — Copies `param_3` words from buffer `param_2` into BigNum `param_1` after expanding capacity via `bcm__6008b43c`. | 1 caller / 2 callees |
| `0x600e73ac` |  102 | Crypto / BN | ~~**`crypto_bn_set_bit`** — OpenSSL `BN_set_bit`: sets bit at index `param_4` in BigNum `param_1`, allocating and expanding limbs as necessary.~~ ⚠️ **misidentified, corrected QA session 93** — real `BN_set_bit` just twiddles one bit in one limb; this function instead zeroes the destination (`param_2` words) and loops **`1 << param_5`** times, each iteration computing `is_zero(index ^ param_4)` (via the confirmed `crypto_constant_time_is_zero_u32`) as an all-ones/all-zeros mask and OR-accumulating the matching table entry (`param_2` words wide, stride `param_2*4`) into the destination — the textbook shape of a **constant-time precomputed-table select** (choose the `param_4`-th of `2^param_5` entries in constant time), not a single-bit setter. Strongly corroborated: the sole caller, `bcm__6008c334`, sits immediately after `analysis/bruce-crypto.md`'s session-9 entry for `0x6008c0d8` ("`BN_mod_exp`-shaped: sliding-window modexp, stack **power-table (up to 32 entries)**..." — `32 = 2^5`, matching this function's `1 << param_5` loop exactly), suggesting this is the real windowed-modexp power-table selector, not `BN_set_bit`. Real identity described rather than renamed. | 1 caller / 3 callees |
| `0x600e7412` |   34 | Crypto / BN | ~~**`crypto_bn_init_zero`** — OpenSSL `BN_init`: initializes BigNum header structure `(d = NULL, top = 0, dmax = 0, neg = 0, flags = 0)`.~~ ⚠️ **misidentified, corrected QA session 93** — real `BN_init` needs exactly one parameter (the struct to zero); this function takes **five** (`dst, mask, srcA, srcB, count`) and its body is a loop `dst[i] = (srcA[i]^srcB[i]) & mask ^ srcB[i]` for `i` in `[0, count)` — the exact `crypto_constant_time_select_u32` masking formula applied word-by-word across a caller-supplied-length array. It is the general, variable-length form of `crypto_ed25519_scalar_cmov_256` (`0x600e653e`, hardcoded to 8 words) — a generic **constant-time N-word array select**, not a zero-initializer. Its 11 callers (spanning `0x600e7xxx`–`0x600e9xxx`, both this BIGNUM neighborhood and the earlier Ed25519-scalar cluster) are consistent with a shared, reused primitive rather than a narrow `BN_init`. Real identity described rather than renamed. | 11 callers / 0 callees |
| `0x600e7434` |   28 | Crypto / BN | **`crypto_bn_normalize_top`** — Normalizes BigNum limb count: decrements `top` while highest limbs are zero. | 4 callers / 0 callees |

## Session 94 (Wave 64) — OpenSSL BIGNUM Core Arithmetic, Context Allocator & Comba Multiplier (20 functions, 1,380 bytes)

Decompiled and documented 20 functions (1,380 bytes across `0x600e7450`–`0x600e7930`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e7450` |   36 | Crypto / BN | **`crypto_bn_num_bits`** — OpenSSL `BN_num_bits`: returns total bit length of BigNum `(top - 1) * 32 + BN_num_bits_word(d[top - 1])`, returning 0 if BigNum is zero / empty. | 12 callers / 2 callees |
| `0x600e7474` |   12 | Crypto / BN | **`crypto_bn_num_bytes`** — OpenSSL `BN_num_bytes`: returns byte length `(BN_num_bits(param_1) + 7) >> 3`. | 7 callers / 1 callee |
| `0x600e7480` |   16 | Crypto / BN | ~~**`crypto_bn_get_word`** — OpenSSL `BN_get_word`: returns lowest 32-bit limb `d[0]` if `top > 0`, else 0.~~ ⚠️ **misidentified, corrected QA session 94** — the function is `void` and returns nothing at all, an immediate disqualifier for `BN_get_word` (whose entire defining purpose is to return a `BN_ULONG` value). Real body: calls the confirmed `crypto_bn_normalize_top` (`0x600e7434`) and **writes** the freshly-recomputed top count back into the struct's own `+4` (top) field, additionally clearing the `+0xc` (`neg`) field if the recomputed top is 0. This is an internal "commit normalized top back to the struct, fixing up the sign-of-zero invariant" mutation helper (akin to `bn_check_top`/post-operation top-fixup), not the public read-only `BN_get_word` getter. Real identity described rather than renamed. | 10 callers / 1 callee |
| `0x600e7490` |  116 | Crypto / BN | **`crypto_bn_bin2bn`** — OpenSSL `BN_bin2bn`: converts big-endian byte array `param_1` of length `param_2` into BigNum `param_3` (allocating or expanding as needed). | 4 callers / 3 callees |
| `0x600e7504` |   68 | Crypto / BN | **`crypto_bn_bn2bin_padded`** — OpenSSL `BN_bn2bin_padded`: converts BigNum `param_3` to big-endian byte array `param_1` of fixed length `param_2` with leading zero-padding. | 1 caller / 1 callee |
| `0x600e7548` |   12 | Crypto / BN | **`crypto_bn_ucmp_core`** — OpenSSL `BN_ucmp` core helper: compares two BigNum limb arrays via `FUN_600e6edc(a->d, a->top, b->d, b->top)`. | 7 callers / 1 callee |
| `0x600e7554` |   52 | Crypto / BN | **`crypto_bn_cmp`** — OpenSSL `BN_cmp`: signed BigNum comparison taking sign flags into account (`neg`), returning -1, 0, or 1. | 8 callers / 1 callee |
| `0x600e7588` |   16 | Crypto / BN | **`crypto_bn_ucmp_less_than`** — Constant-time BigNum unsigned less-than test: returns 1 if `a < b`, else 0. | 2 callers / 1 callee |
| `0x600e7598` |   42 | Crypto / BN | **`crypto_bn_is_word`** — OpenSSL `BN_is_word`: checks if BigNum equals scalar word `param_2` (compares `d[0] == param_2` and verifies all remaining limbs are zero). | 4 callers / 0 callees |
| `0x600e75c8` |   22 | Crypto / BN | **`crypto_bn_set_negative`** — OpenSSL `BN_set_negative`: sets or clears negative sign flag `param_1->neg` based on `param_2` (clears sign if value is zero via `FUN_600e75c2`). | 1 caller / 1 callee |
| `0x600e75de` |  138 | Crypto / BN | **`crypto_bn_rshift`** — OpenSSL `BN_rshift`: right shifts BigNum by `param_2` bits, shifting whole words and fractional bit offsets, normalizing with `BN_normalize_top`. | 2 callers / 5 callees |
| `0x600e7668` |  134 | Crypto / BN | **`crypto_bn_lshift`** — OpenSSL `BN_lshift`: left shifts BigNum by `param_2` bits with limb expansion via `bcm__6008b43c`. | 3 callers / 4 callees |
| `0x600e76ee` |   24 | Crypto / BN | **`crypto_bn_is_one`** — OpenSSL `BN_is_one`: returns true if BigNum is positive and equals 1 (`!neg && BN_is_word(1)`). | 3 callers / 1 callee |
| `0x600e7718` |   78 | Crypto / BN | **`crypto_bn_ctx_get`** — OpenSSL `BN_CTX_get`: allocates temporary BIGNUM from `BN_CTX` stack pool (19 callers across crypto and ECC modules). | 19 callers / 1 callee |
| `0x600e7766` |   38 | Crypto / BN | **`crypto_bn_ctx_alloc_pool_entry`** — Allocates and expands a BIGNUM entry in `BN_CTX` pool. | 3 callers / 2 callees |
| `0x600e778c` |   52 | Crypto / BN | **`crypto_bn_ctx_ensure_capacity`** — Ensures `BN_CTX` pool has sufficient capacity for `param_2` limbs. | 2 callers / 3 callees |
| `0x600e77c0` |   20 | Crypto / BN | **`crypto_bn_ctx_end`** — OpenSSL `BN_CTX_end`: ends `BN_CTX` scope, unwinding stack pointer to previous frame. | 19 callers / 0 callees |
| `0x600e77d4` |  206 | Crypto / BN | **`crypto_bn_mul_add_words`** — OpenSSL `bn_mul_add_words`: multiplies word array by single limb `param_4` and adds to destination array with 64-bit accumulator. | 3 callers / 0 callees |
| `0x600e78a2` |  142 | Crypto / BN | **`crypto_bn_mul_words`** — OpenSSL `bn_mul_words`: multiplies word array by single limb `param_4` storing product in destination array with 64-bit accumulator. | 3 callers / 0 callees |
| `0x600e7930` |  156 | Crypto / BN | ~~**`crypto_bn_mul_comba`** — OpenSSL `bn_mul_comba` / BigNum multi-precision multiplication: multiplies two multi-word BigNums using Comba multiplication with `bn_mul_words` and `bn_mul_add_words`.~~ ⚠️ **misidentified, corrected QA session 94** — real `bn_mul_comba4`/`bn_mul_comba8` are fixed-size (exactly 4 or 8 limbs), fully inline, with **no length parameters and no calls to `bn_mul_words`/`bn_mul_add_words`**. This function instead takes **two explicit length parameters** (`param_3`, `param_5`), dynamically compares and swaps the two operands so the shorter one drives the outer loop, and composes calls to the confirmed `crypto_bn_mul_words` (first word) and `crypto_bn_mul_add_words` (remaining words, 4-way unrolled) — the defining shape of the **generic, variable-length schoolbook multiplier** (real BoringSSL/OpenSSL name: `bn_mul_normal`), not the specialized fixed-size Comba routine. The underlying multiply-accumulate mechanics and callee identities are correct; only the specific-algorithm name is wrong. | 4 callers / 3 callees |

## Session 95 (Wave 65) — OpenSSL Comba Squaring, Modular Shift / Reduction & Comba8 Multiplier (20 functions, 3,184 bytes)

Decompiled and documented 20 functions (3,184 bytes across `0x600e79cc`–`0x600e80e2`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e79cc` |  102 | Crypto / BN | ~~**`crypto_bn_sqr_comba4`** — OpenSSL `bn_sqr_comba4`: 4-limb (128-bit) unrolled Comba squaring with cross-product doubling and 64-bit accumulators.~~ ⚠️ **misidentified, corrected QA session 95** — real `bn_sqr_comba4` is fixed-size (exactly 4 limbs), fully unrolled, no loop, no length parameter, and computes the FULL square including doubled cross-products. This function instead takes an explicit variable length (`param_3`) in a 4-way-unrolled loop and computes **only** each element's own square (`param_2[i]²` → a 64-bit value at `param_1[i]`) — no cross-terms at all. It's a generic "square every word of an array independently" utility, not multi-precision Comba squaring. | 1 caller / 0 callees |
| `0x600e7a32` |  234 | Crypto / BN | ~~**`crypto_bn_sqr_comba8`** — OpenSSL `bn_sqr_comba8`: 8-limb (256-bit) unrolled Comba squaring with cross-product doubling and 64-bit accumulators (10 callers across ECC curves).~~ ⚠️ **misidentified, corrected QA session 95** — not a squaring routine at all. Real body: a genuine variable-length (`param_4`), 4-way-unrolled elementwise **addition-with-carry** across two separate input arrays (`param_1[i] = param_2[i] + param_3[i] + carry`, via `CARRY4`) — this is the real **`bn_add_words`**. See `crypto_bn_usub` below for the knock-on effect. | 10 callers / 0 callees |
| `0x600e7b1c` |  102 | Crypto / BN | ~~**`crypto_bn_usub`** — OpenSSL `BN_usub`: unsigned BigNum subtraction `r = a - b` (`a >= b`) with borrow propagation.~~ ⚠️ **misidentified, corrected QA session 95** — its sole callee is `0x600e7a32` (just corrected above to the real `bn_add_words`), and its own logic (length comparison, carry propagation through the longer operand's remaining words, final carry stored as an extra output limb) is the exact real **`BN_uadd`** (unsigned addition) algorithm — there is no subtraction anywhere in this function. Directly confirmed against the real `BN_usub`: `bcm__6008b60c` (called by this wave's own `crypto_bn_add`, see below) genuinely calls `bn_sub_words` (`0x600e7c2c`, confirmed correct) with the real `a>=b` precondition check and an error-log call on violation — that is the actual `BN_usub`. | 1 caller / 2 callees |
| `0x600e7b82` |   20 | Crypto / BN | ~~**`crypto_bn_sub`** — OpenSSL `BN_sub`: signed BigNum subtraction wrapper with top fixup via `0x600e7480`.~~ ⚠️ **name swapped with `crypto_bn_add` (`0x600e7ccc`), corrected QA session 95** — this function calls `0x600e7b1c` (just corrected above to the real `BN_uadd` core) then fixes up top via `0x600e7480` — the exact shape of an unsigned-**add** outer wrapper, not subtraction. Its and `crypto_bn_add`'s names are swapped: this one is really the `BN_add`-family wrapper, `0x600e7ccc` is really the `BN_sub`-family wrapper. | 2 callers / 2 callees |
| `0x600e7b96` |  150 | Crypto / BN | **`crypto_bn_sqr_normal`** — OpenSSL `bn_sqr_normal`: generic variable-length squaring dispatcher routing fixed 4/8-limb sizes to Comba (`0x600e79cc`/`0x600e7a32`) or schoolbook loop. ⚠️ **note, QA session 95** — this function's own top-level identity holds up (it genuinely computes a variable-length square via "double the cross-terms by self-addition, then add the diagonal squares" — a real, correct algorithm), but its two named sub-components are wrong per the corrections above: it doubles cross-terms by calling the real `bn_add_words` (`0x600e7a32`, self-added) rather than any Comba routine, and adds diagonal terms via the real per-word-array-squarer (`0x600e79cc`), not `bn_sqr_comba4`. Not itself struck through; cross-reference only. | 3 callers / 4 callees |
| `0x600e7c2c` |  160 | Crypto / BN | **`crypto_bn_sub_words`** — OpenSSL `bn_sub_words`: word array subtraction `r[i] = a[i] - b[i]` returning final borrow (11 callers). | 11 callers / 0 callees |
| `0x600e7ccc` |   20 | Crypto / BN | ~~**`crypto_bn_add`** — OpenSSL `BN_add`: signed BigNum addition wrapper calling `bcm__6008b60c` (`BN_uadd`) and `0x600e7480`.~~ ⚠️ **name swapped with `crypto_bn_sub` (`0x600e7b82`), corrected QA session 95** — its own cited callee, `bcm__6008b60c`, was read directly this session and is genuine **`BN_usub`**, not `BN_uadd` as this row's own description guessed: it calls the confirmed `bn_sub_words` (`0x600e7c2c`), enforces the real `a>=b` precondition, and error-logs via the established diagnostic call on violation — textbook unsigned subtraction, not addition. This function is really the `BN_sub`-family wrapper; `0x600e7b82` (corrected above) is really the `BN_add`-family wrapper. | 3 callers / 2 callees |
| `0x600e7ce0` |   86 | Crypto / BN | ~~**`crypto_bn_sub_dispatcher`** — Signed BigNum subtraction dispatcher taking operand signs into account (`a - b`).~~ ⚠️ **name swapped with `crypto_bn_add_dispatcher` (`0x600e7d36`), corrected QA session 95** — fully traced: when the two operands' signs are **equal**, this calls `0x600e7b82` (corrected above to the real `BN_add`-wrapper) and keeps the shared sign; when signs **differ**, it magnitude-compares (via the confirmed comparison core) and calls `0x600e7ccc` (corrected above to the real `BN_sub`-wrapper) on the larger-minus-smaller, assigning the winning operand's sign. That is exactly real **`BN_add`**'s sign-dispatch algorithm (same sign → unsigned add; different signs → subtract magnitudes, sign follows the larger). This function is really the `BN_add` dispatcher; `0x600e7d36` is really the `BN_sub` dispatcher. | 1 caller / 3 callees |
| `0x600e7d36` |   98 | Crypto / BN | ~~**`crypto_bn_add_dispatcher`** — Signed BigNum addition dispatcher taking operand signs into account (`a + b`).~~ ⚠️ **name swapped with `crypto_bn_sub_dispatcher` (`0x600e7ce0`), corrected QA session 95** — fully traced: when signs are **equal**, this magnitude-compares and calls `0x600e7ccc` (real `BN_sub`-wrapper) on the larger-minus-smaller; when signs **differ**, it calls `0x600e7b82` (real `BN_add`-wrapper) directly. That is exactly real **`BN_sub`**'s sign-dispatch algorithm (same sign → subtract magnitudes; different signs → unsigned add). This function is really the `BN_sub` dispatcher; `0x600e7ce0` is really the `BN_add` dispatcher. | 2 callers / 3 callees |
| `0x600e7d98` |   40 | Crypto / BN | **`crypto_bn_mod_sub_quick_core`** — Modular subtraction quick core: computes `a - b` via `bn_sub_words` (`0x600e7c2c`) with conditional addition of modulus `m` via `0x600e7412`. | 2 callers / 2 callees |
| `0x600e7dc0` |   42 | Crypto / BN | **`crypto_bn_mod_add_quick_core`** — Modular addition quick core: computes `a + b` with conditional subtraction of modulus `m` via `0x600e7412`. | 3 callers / 2 callees |
| `0x600e7dea` |   36 | Crypto / BN | **`crypto_bn_mod_lshift1_quick`** — OpenSSL `BN_mod_lshift1_quick`: computes `2*a mod m` via 1-bit shift and conditional subtraction (`0x600e7dc0`). | 2 callers / 2 callees |
| `0x600e7e0e` |  124 | Crypto / BN | **`crypto_bn_mod_lshift_quick`** — OpenSSL `BN_mod_lshift_quick`: computes `(a << n) mod m` by iterative doubling and modular reduction with `BN_CTX` temporary allocation. | 2 callers / 6 callees |
| `0x600e7e8a` |   18 | Crypto / BN | **`crypto_bn_mod_lshift1_wrapper`** — Wrapper calling `crypto_bn_mod_lshift_quick(r, a, 1, m, ctx)`. | 3 callers / 1 callee |
| `0x600e7e9c` |   48 | Crypto / BN | **`crypto_bn_mod_lshift1`** — OpenSSL `BN_mod_lshift1`: validates arguments, clones BigNum if needed, and calls `crypto_bn_mod_lshift1_wrapper`. | 1 caller / 2 callees |
| `0x600e7ecc` |   50 | Crypto / BN | **`crypto_bn_mod_lshift_quick_step`** — Multi-step modular left-shift step using `crypto_bn_sub_words` and constant-time selection. | 2 callers / 3 callees |
| `0x600e7efe` |  124 | Crypto / BN | **`crypto_bn_mod_lshift_quick_loop`** — Iterative modular left-shift loop with `BN_CTX` temporary allocation. | 1 caller / 6 callees |
| `0x600e7f7a` |  288 | Crypto / BN | **`crypto_bn_div_word_by_limb`** — Multi-precision division step by single limb with remainder accumulation and subtraction. | 1 caller / 1 callee |
| `0x600e809a` |   72 | Crypto / BN | **`crypto_bn_mod_word_step`** — Modular reduction step using `crypto_bn_div_word_by_limb` and constant-time word selection (`0x600e7412`). | 2 callers / 2 callees |
| `0x600e80e2` | 1370 | Crypto / BN | **`crypto_bn_mul_comba8`** — OpenSSL `bn_mul_comba8`: 8-limb by 8-limb (256-bit by 256-bit) fully unrolled Comba multiplication with 64-bit accumulators. | 4 callers / 0 callees |

## Session 96 (Wave 66) — OpenSSL Karatsuba / Comba Squaring & Montgomery Reduction Engine (20 functions, 4,234 bytes)

Decompiled and documented 20 functions (4,234 bytes across `0x600e863c`–`0x600e9680`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e863c` |  446 | Crypto / BN | **`crypto_bn_mul_part_recursive_step1`** — OpenSSL `bn_mul_part_recursive` (step 1): Karatsuba recursive multi-precision multiplication splitting operands and invoking recursive sub-multiplications. | 3 callers / 8 callees |
| `0x600e87fa` |  510 | Crypto / BN | **`crypto_bn_mul_part_recursive_step2`** — OpenSSL `bn_mul_part_recursive` (step 2): recombination and carry-propagation phase of Karatsuba recursive multiplication. | 2 callers / 9 callees |
| `0x600e89f8` |  386 | Crypto / BN | **`crypto_bn_mul_recursive`** — OpenSSL `bn_mul_recursive`: recursive Karatsuba multiplication driver routing 8-limb base cases to `bn_mul_comba8` (`0x600e80e2`). | 2 callers / 10 callees |
| `0x600e8b7a` | 1328 | Crypto / BN | **`crypto_bn_sqr_comba8`** — OpenSSL `bn_sqr_comba8`: true 8-limb (256-bit) fully unrolled Comba squaring routine with cross-product doubling and 64-bit accumulators. | 3 callers / 0 callees |
| `0x600e90aa` |  316 | Crypto / BN | **`crypto_bn_sqr_comba4`** — OpenSSL `bn_sqr_comba4`: true 4-limb (128-bit) fully unrolled Comba squaring routine with cross-product doubling and 64-bit accumulators. | 2 callers / 0 callees |
| `0x600e91e6` |  228 | Crypto / BN | **`crypto_bn_sqr_recursive`** — OpenSSL `bn_sqr_recursive`: recursive Karatsuba squaring driver routing 4/8-limb base cases to `bn_sqr_comba4`/`bn_sqr_comba8`. | 2 callers / 6 callees |
| `0x600e92ca` |   38 | Crypto / BN | **`crypto_bn_mont_ctx_new`** — OpenSSL `BN_MONT_CTX_new`: allocates and initializes a 48-byte (`0x30`) Montgomery reduction context structure (`BN_MONT_CTX`). | 2 callers / 3 callees |
| `0x600e92f0` |   30 | Crypto / BN | **`crypto_bn_mont_ctx_free`** — OpenSSL `BN_MONT_CTX_free`: frees Montgomery reduction context structure and its internal BIGNUM limbs (9 callers). | 9 callers / 2 callees |
| `0x600e930e` |   30 | Crypto / BN | **`crypto_bn_mont_ctx_clear_field`** — Montgomery context field destructor: frees nested Montgomery context at `param_1 + 0x110` and clears memory. | 0 callers / 2 callees |
| `0x600e932c` |   66 | Crypto / BN | **`crypto_bn_mod_exp_mont_init`** — OpenSSL `BN_MONT_CTX_set` / Montgomery setup: calculates $R^2 \pmod N$ and Montgomery constant $N_0'$ using `BN_CTX`. | 3 callers / 5 callees |
| `0x600e936e` |   92 | Crypto / BN | **`crypto_bn_mont_ctx_set`** — OpenSSL `BN_MONT_CTX_set` wrapper: configures Montgomery modulus, expands limbs, and initializes Montgomery parameters. | 1 caller / 2 callees |
| `0x600e93ca` |   74 | Crypto / BN | **`crypto_bn_mod_exp_mont_mul_core`** — Constant-time Montgomery reduction / multiplication core with scratch buffer zeroing via `OPENSSL_cleanse`. | 3 callers / 5 callees |
| `0x600e9414` |  162 | Crypto / BN | **`crypto_bn_mont_inv_n0`** — Computes Montgomery inverse constant $N_0' = -N^{-1} \pmod{2^{32}}$ using Newton-Raphson iteration / modular inverse over 64 bits. | 1 caller / 0 callees |
| `0x600e94b6` |   20 | Crypto / BN | **`crypto_bn_mul_wrapper`** — OpenSSL `BN_mul` wrapper calling `crypto_bn_mul_recursive` (`0x600e89f8`) with top fixup (`0x600e7480`). | 1 caller / 2 callees |
| `0x600e94ca` |  120 | Crypto / BN | ~~**`crypto_bn_gcd`** — OpenSSL `BN_gcd`: computes greatest common divisor $\gcd(a, b)$ using binary Euclidean algorithm with `BN_CTX`.~~ ⚠️ **misidentified, corrected QA session 96** — the body contains no binary-Euclidean halving/subtracting loop at all; it's a thin `BN_CTX`-scoped wrapper (`crypto_bn_ctx_get`/`_end`, confirmed session 94) whose sole computational callee is `bcm__6008b79c` — already independently documented in `analysis/bruce-crypto.md` since **session 9** as `"BN_mod_inverse-shaped: extended binary-GCD/Lehmer-style modular inverse"` (medium confidence), not plain GCD. This wrapper's post-processing (`crypto_bn_is_one` on the result, then a `crypto_bn_cmp`/sign check against `param_4`) is the shape of "compute a modular inverse and check whether it exists/is valid" (the GCD-equals-1 invertibility test), not a general `gcd(a,b)` computation. Real identity left unconfirmed rather than renamed, pending a closer look at `bcm__6008b79c` itself; note the *general area* is legitimately GCD/modular-inverse-adjacent, just not the specific `BN_gcd` API. | 1 caller / 7 callees |
| `0x600e9542` |   58 | Crypto / BN | **`crypto_bn_mul_dispatcher`** — OpenSSL `BN_mul` dispatcher: validates operand lengths, routing 8-limb multiplies to `bn_mul_comba8` (`0x600e80e2`) or generic `bn_mul_normal` (`0x600e7930`). | 1 caller / 3 callees |
| `0x600e957c` |  224 | Crypto / BN | **`crypto_bn_sqr`** — OpenSSL `BN_sqr`: top-level BigNum squaring function routing 4/8-limb to Comba (`0x600e90aa`/`0x600e8b7a`), Karatsuba (`0x600e91e6`), or normal (`0x600e7b96`). | 2 callers / 9 callees |
| `0x600e965c` |   16 | Crypto / BN | **`crypto_bn_sqr_trampoline`** — Trampoline calling `bcm__6008ba20` (`BN_sqr`). | 2 callers / 1 callee |
| `0x600e966c` |   20 | Crypto / BN | **`crypto_bn_sqr_wrapper`** — BigNum squaring wrapper calling `crypto_bn_sqr` (`0x600e957c`) with top fixup (`0x600e7480`). | 2 callers / 2 callees |
| `0x600e9680` |   70 | Crypto / BN | **`crypto_bn_sqr_stack_dispatcher`** — Stack-allocated BigNum squaring dispatcher: routes 4/8-limb to Comba (`0x600e90aa`/`0x600e8b7a`) or normal (`0x600e7b96`) with stack clearing. | 1 caller / 5 callees |

## Session 97 (Wave 67) — OpenSSL Montgomery Multiplication, Exponentiation & Bitwise Utilities (20 functions, 1,686 bytes)

Decompiled and documented 20 functions (1,686 bytes across `0x600e96c6`–`0x600e9bc2`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e96c6` |   84 | Crypto / BN | **`crypto_bn_mod_mul_montgomery`** — OpenSSL `BN_mod_mul_montgomery`: performs Montgomery modular multiplication $r = a \cdot b \cdot R^{-1} \pmod N$ using `BN_MONT_CTX`. | 5 callers / 5 callees |
| `0x600e971a` |   18 | Crypto / BN | **`crypto_bn_mod_mul_montgomery_wrapper`** — OpenSSL `BN_mod_mul_montgomery` wrapper. | 0 callers / 1 callee |
| `0x600e972c` |   26 | Crypto / BN | **`crypto_bn_to_montgomery`** — OpenSSL `BN_to_montgomery`: converts BigNum $a$ to Montgomery representation $a \cdot R \pmod N$. | 3 callers / 1 callee |
| `0x600e9746` |   26 | Crypto / BN | **`crypto_bn_from_montgomery`** — OpenSSL `BN_from_montgomery`: converts BigNum from Montgomery representation $a \cdot R^{-1} \pmod N$. | 3 callers / 1 callee |
| `0x600e9760` |  126 | Crypto / BN | **`crypto_bn_mod_exp_simple`** — Simple square-and-multiply modular exponentiation core. | 3 callers / 2 callees |
| `0x600e97de` |  108 | Crypto / BN | **`crypto_bn_mod_exp_word`** — OpenSSL `BN_mod_exp_mont_word`: modular exponentiation with single-word base in Montgomery domain. | 1 caller / 4 callees |
| `0x600e984a` |   90 | Crypto / BN | **`crypto_bn_mod_mul_wrapper`** — Modular multiplication wrapper: computes product and reduces modulo $m$ using `BN_CTX`. | 2 callers / 6 callees |
| `0x600e98a4` |   34 | Crypto / BN | **`crypto_bn_mod_sqr_wrapper`** — Modular squaring wrapper: computes square via `BN_sqr` and reduces modulo $m$ via `bcm__6008bbdc` (`BN_mod`). | 2 callers / 2 callees |
| `0x600e98c6` |  134 | Crypto / BN | **`crypto_bn_mod_exp_mont_consttime`** — Constant-time Montgomery modular exponentiation core for cryptographic operations. | 1 caller / 7 callees |
| `0x600e994c` |   48 | Crypto / BN | ~~**`crypto_bn_copy_limbs_reverse`** — Word-array reversal / copy utility.~~ ⚠️ **misidentified, corrected QA session 97** — no reversal happens anywhere; the body computes `dest[i] = (src[i+1] << 31) | (src[i] >> 1)` for each word (with the top output word getting just `src[top] >> 1`, no incoming bit) — the textbook cross-word-carry shape of a **multi-word right-shift-by-1-bit** (`>>1`) over a `param_3`-word array, not a reversal (a real reversal would swap `dest[i]=src[N-1-i]` with no bit-shifting at all). Real identity: an internal `BN_rshift1`-style word-array shifter. | 2 callers / 0 callees |
| `0x600e997c` |   38 | Crypto / BN | ~~**`crypto_bn_copy_limbs_reverse_cmov`** — Conditional word-array reversal using `crypto_bn_copy_limbs_reverse` and `crypto_constant_time_select_u32` (`0x600e7412`).~~ ⚠️ **misidentified, corrected QA session 97** — inherits the error above: its first callee (`0x600e994c`) is the real right-shift-by-1 primitive, not a reversal, so this function is "right-shift-by-1, then constant-time-select the result vs. the original" — plausible use: conditionally halving a value (e.g. inside a modular-inverse/GCD-style routine that halves only when even) — not a conditional reversal. | 1 caller / 2 callees |
| `0x600e99a2` |  116 | Crypto / BN | **`crypto_bn_mod_exp_mont_driver`** — OpenSSL `BN_mod_exp_mont` driver: computes $a^p \pmod m$ in Montgomery domain with context setup. | 1 caller / 7 callees |
| `0x600e9a16` |   42 | Crypto / BN | ~~**`crypto_bn_copy_reverse`** — BigNum reverse copy helper: allocates capacity and copies limbs in reverse order, fixing up top.~~ ⚠️ **misidentified, corrected QA session 97** — same root cause: its limb-copying callee (`0x600e994c`) is the real right-shift-by-1 primitive, not reversal. This function (expand capacity via `bcm__6008b43c`, shift the source limbs right by 1 into the new buffer, copy over `top`/`neg`, commit via the confirmed `crypto_bn_get_word`/top-fixup helper `0x600e7480`) is the real shape of **`BN_rshift1`** (allocate-and-return `a >> 1`), not a reversal. | 1 caller / 3 callees |
| `0x600e9a40` |   78 | Crypto / BN | **`crypto_bn_set_bit_raw`** — Sets single bit at index `param_2` in limb array, expanding buffer as needed. ✅ **note, QA session 97**: confirmed correct, and appropriately hedged (describes behavior rather than asserting the OpenSSL name). This is very likely the *real* `BN_set_bit` — closing an open thread from session 93, where `crypto_bn_set_bit` (at the unrelated address `0x600e73ac`) was found to actually be a constant-time table selector, not `BN_set_bit`. This function's body (bounds-check, word-index derivation via `>>5`, buffer expansion + zero-fill of newly-added words, `OR (1 << (idx & 0x1f))` into the target word) is the textbook real algorithm. | 2 callers / 1 callee |
| `0x600e9a8e` |  102 | Crypto / BN | **`crypto_bn_mont_ctx_init_from_bignum`** — Initializes Montgomery context parameters ($R, R^2, N_0'$) directly from modulus BigNum. | 1 caller / 6 callees |
| `0x600e9af4` |   40 | Crypto / BN | **`crypto_bn_mont_ctx_create_from_bignum`** — Allocates new `BN_MONT_CTX` and initializes from BigNum modulus. | 2 callers / 3 callees |
| `0x600e9b1c` |   70 | Crypto / BN | **`crypto_bn_mont_ctx_init_consttime`** — Constant-time Montgomery context initializer with limb shift. | 1 caller / 3 callees |
| `0x600e9b62` |   70 | Crypto / BN | **`crypto_bn_mont_ctx_create_consttime`** — Allocates new `BN_MONT_CTX` and initializes with constant-time parameters. | 2 callers / 5 callees |
| `0x600e9ba8` |   26 | Crypto / BN | **`crypto_bn_is_bit_set`** — OpenSSL `BN_is_bit_set`: tests if bit at index `param_3` is set in limb array of length `param_2` (5 callers). | 5 callers / 0 callees |
| `0x600e9bc2` |  410 | Crypto / BN | **`crypto_bn_mod_exp_mont_sliding_window`** — Full windowed Montgomery modular exponentiation engine with precomputed power table. | 1 caller / 7 callees |

## Session 98 (Wave 68) — OpenSSL EVP Cipher Framework & DES / 3DES Encryption Engine (20 functions, 2,464 bytes)

Decompiled and documented 20 functions (2,464 bytes across `0x600e9d5c`–`0x600ea6f8`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600e9d5c` |   26 | Crypto / BN | **`crypto_bn_mod_exp_mont_step_trampoline`** — Trampoline forwarding to windowed Montgomery modular exponentiation engine `0x600e9bc2`. | 1 caller / 2 callees |
| `0x600e9d76` |   96 | Crypto / BN | **`crypto_bn_mod_exp_mont_consttime_core`** — Constant-time sliding-window Montgomery exponentiation helper. | 2 callers / 3 callees |
| `0x600e9dd6` |   20 | Crypto / BN | **`crypto_bn_mod_exp_mont_consttime_wrapper`** — Trampoline setting up modulus and calling `crypto_bn_mod_exp_mont_consttime_core` (`0x600e9d76`). Created as new function (`0x600e9dd6`..`0x600e9de9`). | 0 callers / 1 callee |
| `0x600e9dea` |   16 | Crypto / BN | **`crypto_bn_is_bit_set_checked`** — Bounds-checked wrapper around `crypto_bn_is_bit_set` (`0x600e9ba8`). | 4 callers / 1 callee |
| `0x600e9dfa` |    8 | Crypto / EVP | **`crypto_evp_cipher_ctx_zero`** — OpenSSL `EVP_CIPHER_CTX_init`: zeroes 136-byte (`0x88`) cipher context structure via `thunk_EXT_FUN_0000af90`. | 1 caller / 1 callee |
| `0x600e9e02` |   34 | Crypto / EVP | **`crypto_evp_cipher_ctx_cleanup`** — OpenSSL `EVP_CIPHER_CTX_cleanup`: invokes cipher context cleanup callback and frees allocation. | 2 callers / 2 callees |
| `0x600e9e24` |  248 | Crypto / EVP | **`crypto_evp_cipher_update_core`** — OpenSSL `EVP_CipherUpdate` core: performs stream/block cipher buffering and block processing. | 1 caller / 1 callee |
| `0x600e9f1c` |  198 | Crypto / EVP | **`crypto_evp_cipher_final_core`** — OpenSSL `EVP_CipherFinal_ex` core: handles block padding and finalization. | 1 caller / 2 callees |
| `0x600e9fe2` |   18 | Crypto / EVP | **`crypto_evp_cipher_ctx_free`** — OpenSSL `EVP_CIPHER_CTX_free`: frees cipher context via `bcm__6008c834`. | 1 caller / 1 callee |
| `0x600e9ff4` |    4 | Crypto / EVP | **`crypto_evp_cipher_ctx_get_flags`** — Returns cipher flags `*(int*)(param_1 + 0xc)`. | 1 caller / 0 callees |
| `0x600e9ff8` |   16 | Crypto / DES | **`crypto_des_ecb_cipher_wrapper`** — Single-DES ECB mode wrapper forwarding to DES engine `0x6008c9e0`. | 0 callers / 1 callee |
| `0x600ea008` |   42 | Crypto / DES | **`crypto_des_ede3_ecb_cipher_wrapper`** — Triple-DES (3DES / EDE3) ECB mode wrapper calling DES engine `0x6008c9e0` three times with 3 key schedules. | 0 callers / 1 callee |
| `0x600ea032` |  182 | Crypto / DES | ~~**`crypto_des_initial_permute`** — DES Initial Permutation (IP) bit-permutation engine with bit-slice transformations.~~ ⚠️ **scope drastically understated, corrected QA session 98** — the IP identification itself is exact and bit-confirmed (the mask/shift sequence `0x0f0f0f0f`(4)→`0xffff`(16)→`0x33333333`(2)→`0xff00ff`(8)→`0x55555555`(1) is a bit-for-bit match to OpenSSL's real `PERM_OP`-based `IP()` macro), but the function doesn't stop there: after the IP it calls the Feistel round-function `FUN_6008893c` **three times** with mode flags `(1,0,1)` — Encrypt-Decrypt-Encrypt, the classic **3DES-EDE** construction — and then applies the exact-inverse-order mask sequence (a bit-for-bit match to the real `FP()` macro) before returning. This is the **complete 3DES-EDE3 single-block encrypt** operation (IP → E·D·E → FP), not a bare permutation step. Its sibling `0x600ea0e8` (below) is the matching decrypt operation. | 1 caller / 1 callee |
| `0x600ea0e8` |  184 | Crypto / DES | ~~**`crypto_des_final_permute`** — DES Final Permutation (FP / $IP^{-1}$) bit-permutation engine.~~ ⚠️ **scope drastically understated, corrected QA session 98** — identical structure to `0x600ea032` above: real, bit-confirmed IP macro, then **three** calls to the same Feistel round-function `FUN_6008893c` with mode flags `(0,1,0)` — Decrypt-Encrypt-Decrypt, the exact inverse-key-order counterpart to `0x600ea032`'s `(1,0,1)` — then the real FP macro. This is the **complete 3DES-EDE3 single-block decrypt** operation, not a bare permutation step; both functions are called from this same wave's `crypto_des_ede3_cbc_encrypt_blocks` (`0x600ea438`) as its actual per-block encrypt/decrypt engines. | 1 caller / 1 callee |
| `0x600ea1a0` |  634 | Crypto / DES | **`crypto_des_cbc_encrypt_blocks`** — Single-DES CBC mode multi-block encryption/decryption loop with XOR chaining. Resized from 616B to 634B (`0x600ea1a0`..`0x600ea419`). | 1 caller / 1 callee |
| `0x600ea41a` |   30 | Crypto / DES | **`crypto_des_cbc_cipher_wrapper`** — OpenSSL `EVP_des_cbc` cipher callback wrapper forwarding to `0x600ea1a0`. | 0 callers / 1 callee |
| `0x600ea438` |  638 | Crypto / DES | **`crypto_des_ede3_cbc_encrypt_blocks`** — Triple-DES (3DES / EDE3) CBC mode multi-block encryption/decryption loop with 3-key EDE round chaining. Resized from 620B to 638B (`0x600ea438`..`0x600ea6b5`). | 1 caller / 2 callees |
| `0x600ea6b6` |   46 | Crypto / DES | **`crypto_des_ede3_cbc_cipher_wrapper`** — OpenSSL `EVP_des_ede3_cbc` cipher callback wrapper forwarding to `0x600ea438`. Created as new function (`0x600ea6b6`..`0x600ea6e3`). | 0 callers / 1 callee |
| `0x600ea6e4` |   20 | Crypto / Heap | **`crypto_heap_alloc_16b_struct`** — Allocates and initializes a 16-byte memory structure. | 1 caller / 2 callees |
| `0x600ea6f8` |    4 | Crypto / Heap | **`thunk_crypto_heap_alloc_16b_struct`** — Trampoline to `0x600ea6e4`. | 1 caller / 1 callee |

## Session 99 (Wave 69) — OpenSSL Elliptic Curve (EC) Group, Point & ECDSA Framework (20 functions, 410 bytes)

Decompiled and documented 20 functions (410 bytes across `0x600ea6fc`–`0x600ea892`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ea6fc` |   22 | Crypto / EC | **`crypto_ec_key_destructor_trampoline`** — Cleans up EC key sub-structures and frees key object via `thunk_EXT_FUN_0000ac5e`. | 1 caller / 2 callees |
| `0x600ea712` |   24 | Crypto / EC | **`crypto_ec_key_init_wrapper`** — Initializes EC key object calling `bcm__6008cb7c`. | 1 caller / 2 callees |
| `0x600ea72a` |   32 | Crypto / EC | **`crypto_ec_method_get_curve_name`** — Invokes `ec_method->get_curve_name` function pointer (`+0x14`). | 2 callers / 1 callee |
| `0x600ea74a` |   18 | Crypto / EC | **`crypto_ec_group_get_curve_name`** — Wrapper extracting curve name from EC group structure. | 1 caller / 2 callees |
| `0x600ea75c` |   30 | Crypto / EC | **`crypto_ecdsa_sig_free`** — OpenSSL `ECDSA_SIG_free`: frees `r` and `s` BigNums (`0x600e6a22`) and signature structure. | 2 callers / 2 callees |
| `0x600ea77a` |   42 | Crypto / EC | **`crypto_ecdsa_sig_new`** — OpenSSL `ECDSA_SIG_new`: allocates `ECDSA_SIG` struct (8 bytes) and initializes `r` and `s` BigNums (`bcm__6008b384`). | 1 caller / 3 callees |
| `0x600ea7a4` |   64 | Crypto / EC | **`crypto_ec_group_clear_free_internal`** — Frees EC group internal fields: Montgomery context (`0x600e92f0`), BigNum parameters (`0x600e6a22`), and method structures. | 5 callers / 4 callees |
| `0x600ea7e4` |   22 | Crypto / EC | **`crypto_ec_group_ensure_generator_order`** — Checks and computes generator order if uninitialized (`FUN_600867a4`). | 2 callers / 1 callee |
| `0x600ea7fa` |    4 | Crypto / EC | **`crypto_ec_group_get_generator_offset`** — Returns pointer to generator point `param_1 + 8` (3 callers). ⚠️ **confidence caveat, QA session 99** — this exact 4-byte body (`return param_1+8`) is already independently attributed, in this very file, to a **different** logical role: row `0x600e0822` (`crypto_ed25519_key_decode`, Ed25519/ASN.1) cites this same function as part of Ed25519 key-structure parsing, and row `0x600e049a` (`gotham_connection_close_and_notify`, Gotham/Connection) cites it as part of a connection-cleanup cascade — neither is EC-related. This is very likely identical-code-folding of a trivial one-line offset accessor across three unrelated structure types, not evidence any one framing is "the" real one; treat the specific "generator" role as unconfirmed. | 3 callers / 0 callees |
| `0x600ea7fe` |    4 | Crypto / EC | **`crypto_ec_group_get_cofactor`** — Returns cofactor BigNum `*(param_1 + 0x1c)`. | 1 caller / 0 callees |
| `0x600ea802` |   24 | Crypto / EC | **`crypto_ec_group_free`** — OpenSSL `EC_GROUP_free`: clears group internal fields via `0x600ea7a4` and frees memory. | 6 callers / 2 callees |
| `0x600ea81a` |    6 | Crypto / EC | **`crypto_ec_point_method_dispatch_3c`** — Indirect branch/dispatch through `EC_METHOD->+0x3c`. | 1 caller / 0 callees |
| `0x600ea820` |   72 | Crypto / EC | **`crypto_ec_point_mul_generator`** — Computes scalar multiplication of generator point on elliptic curve using `EC_METHOD->+0xc`. | 1 caller / 2 callees |
| `0x600ea868` |    6 | Crypto / EC | **`crypto_ec_error_trampoline`** — Sets return code 0 and calls error handler `0x6008cd78`. Created as new function (`0x600ea868`..`0x600ea86d`). | 2 callers / 0 callees |
| `0x600ea86e` |   12 | Crypto / EC | **`crypto_ec_group_init_generator`** — Initializes generator point on group via `0x600867a4(param_1 + 0x18)`. | 1 caller / 1 callee |
| `0x600ea87a` |   12 | Crypto / EC | **`crypto_ec_group_is_custom_curve`** — Returns flag bit `*(param_1->extra + 0x1c) & 1`. Created as new function (`0x600ea87a`..`0x600ea885`). | 0 callers / 0 callees |
| `0x600ea886` |    4 | Crypto / EC | **`crypto_ec_point_get_x`** — Accessor returning pointer/word at `*param_1` (6 callers). ⚠️ **confidence caveat, QA session 99** — of its 6 callers, at least 3 (`0x600e080c`=`crypto_ed25519_pubkey_import`, `0x600e0822`=`crypto_ed25519_key_decode`, `0x600e084e`=`crypto_ed25519_key_compare`) are already independently attributed in this file to **Ed25519 key-material** access, not EC point coordinates — and one of *those* rows explicitly describes this function as extracting "key material lengths and pointers." A trivial one-line `return *param_1` body can't itself distinguish "EC point X" from any other offset-0 field of any other struct; this is very likely identical-code-folding across unrelated structure types (Ed25519 key blobs, generic offset-0 fields) rather than confirmed EC-point-specific behavior. Treat the "X coordinate" role as one of several plausible, unconfirmed interpretations. | 6 callers / 0 callees |
| `0x600ea88a` |    4 | Crypto / EC | **`crypto_ec_point_get_z`** — Accessor returning word at `*(param_1 + 8)`. ✅ note, QA session 99: unlike its siblings below, this one's sole known caller (`ec_asn1__0x600917a0`) is itself genuinely EC/ASN.1-attributed, so the EC framing is comparatively better supported here — though the body alone still can't independently confirm the specific "Z coordinate" role. | 1 caller / 0 callees |
| `0x600ea88e` |    4 | Crypto / EC | **`crypto_ec_point_get_y`** — Accessor returning word at `*(param_1 + 4)`. ⚠️ **confidence caveat, QA session 99** — one of its 2 callers is `0x600e084e` (`crypto_ed25519_key_compare`), already independently attributed in this file to Ed25519 key-material comparison, not EC point access — same identical-code-folding concern as `crypto_ec_point_get_x` above; treat the "Y coordinate" role as unconfirmed. | 2 callers / 0 callees |
| `0x600ea892` |    4 | Crypto / EC | **`crypto_ec_point_get_field_10`** — Accessor returning word at `*(param_1 + 0x10)`. | 1 caller / 0 callees |

## Session 100 (Wave 70) — OpenSSL Elliptic Curve (EC) Jacobian Point Arithmetic & Scalar Multiplication (20 functions, 2,224 bytes)

Decompiled and documented 20 functions (2,224 bytes across `0x600ea896`–`0x600eafdc`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ea896` |    6 | Crypto / EC | **`crypto_ec_point_method_dispatch_40`** — Indirect branch/dispatch through `EC_METHOD->+0x40`. | 1 caller / 0 callees |
| `0x600ea89c` |   30 | Crypto / EC | **`crypto_ec_point_add_field_words`** — EC field limb addition with carry wrapping. | 3 callers / 1 callee |
| `0x600ea8ba` |   30 | Crypto / EC | **`crypto_ec_point_sub_field_words`** — EC field limb subtraction with borrow wrapping. | 3 callers / 1 callee |
| `0x600ea8d8` |  610 | Crypto / EC | **`crypto_ec_point_dbl_jacobian`** — EC point doubling in Jacobian / projective coordinates on short Weierstrass curve ($y^2 = x^3 + ax + b$). | 4 callers / 4 callees |
| `0x600eab3a` |   30 | Crypto / EC | ~~**`crypto_ec_point_is_at_infinity`** — Tests if EC point is the point at infinity $\mathcal{O}$ ($Z = 0$).~~ ⚠️ **boolean sense inverted, corrected QA session 100** — traced precisely: OR-reduce the field's words, then `~is_zero(OR)` via the confirmed `crypto_constant_time_is_zero_u32`. `is_zero` returns all-1s when the field is all-zero and `0` otherwise; the outer `~` flips that, so this function returns **all-1s when the field is nonzero** (finite) and **0 when the field is all-zero** (infinity) — the exact opposite sense of "is at infinity." Confirmed by its caller `crypto_ec_point_set_to_infinity` (`0x600eab58`), which uses this result directly as an AND-mask to zero out a computed coordinate — that only works if the mask is 0 exactly when the point *was already* at infinity, i.e. if this function is really "is-finite"/"is-not-at-infinity." Real identity: tests whether the point is **NOT** at infinity ($Z \neq 0$). | 3 callers / 1 callee |
| `0x600eab58` |   52 | Crypto / EC | **`crypto_ec_point_set_to_infinity`** — Sets point coordinates to $(0,0,0)$ or identity representation. Created as new function (`0x600eab58`..`0x600eab8b`). | 0 callers / 2 callees |
| `0x600eab8c` |   24 | Crypto / EC | **`crypto_ec_point_cmov_jacobian`** — Constant-time conditional move (`cmov`) of Jacobian point coordinates. | 2 callers / 1 callee |
| `0x600eaba4` |  556 | Crypto / EC | **`crypto_ec_point_add_jacobian`** — EC point addition in Jacobian / projective coordinates ($P + Q$). | 3 callers / 7 callees |
| `0x600eadd0` |   30 | Crypto / EC | **`crypto_ec_point_cmp_field_words`** — Compares field words of two point coordinates using `memcmp` (`thunk_EXT_FUN_0000b554`). | 3 callers / 1 callee |
| `0x600eadee` |  232 | Crypto / EC | **`crypto_ec_point_cmp_jacobian`** — Tests equivalence of two Jacobian points $P = Q$ by comparing projective coordinates ($X_1 Z_2^2 \equiv X_2 Z_1^2 \pmod p$). Created as new function (`0x600eadee`..`0x600eaed5`). | 0 callers / 1 callee |
| `0x600eaed6` |   30 | Crypto / EC | **`crypto_ec_point_cmp_affine_words`** — Compares affine coordinates using `memcmp`. | 1 caller / 1 callee |
| `0x600eaef4` |   20 | Crypto / EC | **`crypto_ec_field_mul_montgomery`** — EC field Montgomery multiplication wrapper. | 1 caller / 1 callee |
| `0x600eaf08` |   24 | Crypto / EC | **`crypto_ec_field_sqr_montgomery`** — EC field Montgomery squaring wrapper. | 1 caller / 1 callee |
| `0x600eaf20` |    6 | Crypto / EC | **`crypto_ec_point_method_dispatch_34`** — Indirect branch through `EC_METHOD->+0x34`. | 1 caller / 0 callees |
| `0x600eaf26` |   24 | Crypto / EC | **`crypto_ec_point_invert_wrapper`** — EC point inversion wrapper ($P \mapsto -P$). Created as new function (`0x600eaf26`..`0x600eaf3d`). | 0 callers / 2 callees |
| `0x600eaf3e` |    6 | Crypto / EC | **`crypto_ec_point_method_dispatch_38`** — Indirect branch through `EC_METHOD->+0x38`. | 1 caller / 0 callees |
| `0x600eaf44` |   74 | Crypto / EC | **`crypto_ec_key_set_public_key_affine`** — Sets public key affine coordinates on EC key structure. | 1 caller / 2 callees |
| `0x600eaf8e` |   38 | Crypto / EC | **`crypto_ec_point_zero_jacobian`** — Zeroes 3 coordinate limbs ($X, Y, Z$) of Jacobian point (3 blocks of 68 bytes). | 3 callers / 1 callee |
| `0x600eafb4` |   40 | Crypto / EC | **`crypto_ec_point_copy_jacobian`** — Copies 3 coordinate limbs ($X, Y, Z$) of Jacobian point (3 blocks of 68 bytes). | 6 callers / 1 callee |
| `0x600eafdc` |  362 | Crypto / EC | **`crypto_ec_point_mul_comb`** — Comb / windowed scalar multiplication engine for elliptic curve points ($k \cdot P$). | 0 callers / 9 callees |

## Session 101 (Wave 71) — OpenSSL Elliptic Curve (EC) Group Verification, wNAF Scalar Multiplication & MD5 Digest Engine (20 functions, 2,064 bytes)

Decompiled and documented 20 functions (2,064 bytes across `0x600eb146`–`0x600eb8bc`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600eb146` |   16 | Crypto / EC | **`crypto_ec_point_mul_comb_wrapper`** — Trampoline wrapper invoking `crypto_ec_point_mul_comb` (`0x600eafdc`). Created as new function (`0x600eb146`..`0x600eb155`). | 0 callers / 1 callee |
| `0x600eb156` |   60 | Crypto / EC | **`crypto_ec_point_precompute_comb_table`** — Computes multiples / table of points for Comb scalar multiplication. | 1 caller / 3 callees |
| `0x600eb192` |   10 | Crypto / EC | **`crypto_ec_point_neg_jacobian_wrapper`** — Negates $Y$ coordinate of Jacobian point via `0x600eab58`. Created as new function (`0x600eb192`..`0x600eb19b`). | 1 caller / 1 callee |
| `0x600eb19c` |   56 | Crypto / EC | **`crypto_ec_point_table_lookup_sign`** — Table lookup for signed scalar multipliers, applying negation (`0x600eb192`) when digit is negative. Boundary adjusted from 118B to 56B (`0x600eb19c`..`0x600eb1d3`). | 1 caller / 2 callees |
| `0x600eb1d4` |   16 | Crypto / EC | **`crypto_ec_point_is_at_infinity_wrapper`** — Tests whether EC point is at infinity ($Z = 0$) with boolean result (0=finite, 1=infinity). (9 callers). | 9 callers / 1 callee |
| `0x600eb1e4` |  156 | Crypto / EC | **`crypto_ec_point_validate_order`** — Validates that point has expected subgroup order ($n \cdot P = \mathcal{O}$) or matches curve params. | 0 callers / 7 callees |
| `0x600eb280` |  240 | Crypto / EC | **`crypto_ec_point_is_on_curve_jacobian`** — Evaluates curve equation $Y^2 \equiv X^3 + a X Z^4 + b Z^6 \pmod p$ in Jacobian coordinates to verify that $P$ lies on the curve. Created as new function (`0x600eb280`..`0x600eb36f`). | 0 callers / 4 callees |
| `0x600eb370` |   52 | Crypto / EC | **`crypto_ec_point_cmp_jacobian_core`** — Core point equality comparison testing infinity flags and delegating to projective coordinate comparison `0x600eadee`. (Real comparison target tail-called by `bcm__6008db08`). | 2 callers / 2 callees |
| `0x600eb3a4` |   92 | Crypto / EC | **`crypto_ec_group_cmp_parameters`** — Compares elliptic curve group parameters ($p, a, b, G$). Created as new function (`0x600eb3a4`..`0x600eb3ff`). | 2 callers / 3 callees |
| `0x600eb400` |   40 | Crypto / EC | **`crypto_ec_group_cmp`** — OpenSSL `EC_GROUP_cmp`: checks pointer equality, curve IDs, and field parameters via `0x600eb3a4`. Boundary adjusted from 132B to 40B (`0x600eb400`..`0x600eb427`). | 1 caller / 1 callee |
| `0x600eb428` |   40 | Crypto / EC | **`crypto_ec_point_method_check`** — Validates that two EC points share the same `EC_METHOD` and group context (10 callers across `bcm.c`). | 10 callers / 1 callee |
| `0x600eb450` |   44 | Crypto / EC | **`crypto_ec_point_dup`** — OpenSSL `EC_POINT_dup`: allocates a new point and copies coordinates from source. | 1 caller / 3 callees |
| `0x600eb47c` |   52 | Crypto / EC | **`crypto_ec_point_is_on_curve_affine`** — Checks if affine coordinates satisfy the curve equation. | 1 caller / 3 callees |
| `0x600eb4b0` |  178 | Crypto / EC | **`crypto_ec_point_is_on_curve_montgomery`** — Checks if Montgomery-form coordinates satisfy curve equation. Created as new function (`0x600eb4b0`..`0x600eb561`). | 0 callers / 8 callees |
| `0x600eb562` |   38 | Crypto / EC | **`crypto_ec_wnaf_digit_helper`** — Extracts sign and digit magnitude for wNAF recoding. | 1 caller / 0 callees |
| `0x600eb588` |  466 | Crypto / EC | **`crypto_ec_compute_wnaf`** — Computes width-$w$ Non-Adjacent Form (wNAF) representation of a scalar BigNum. | 0 callers / 12 callees |
| `0x600eb75a` |  116 | Crypto / EC | **`crypto_ec_wnaf_precompute_table`** — Precomputes table of odd multiples $\{P, 3P, 5P, \dots, (2^w - 1)P\}$ for wNAF scalar multiplication. | 2 callers / 1 callee |
| `0x600eb7ce` |  232 | Crypto / EC | **`crypto_ec_point_mul_wnaf`** — Variable-time wNAF scalar multiplication engine ($k \cdot P$). | 0 callers / 8 callees |
| `0x600eb8b6` |    6 | Crypto / Digest | **`crypto_md5_init_wrapper`** — OpenSSL `EVP_DigestInit` wrapper for MD5: loads context (`+4`) and tail-calls `MD5_Init` (`0x6008de78`). Created as new function (`0x600eb8b6`..`0x600eb8bb`). | 0 callers / 0 callees |
| `0x600eb8bc` |  154 | Crypto / Digest | **`crypto_md5_update_core`** — OpenSSL `MD5_Update` streaming digest update engine (processes 64-byte blocks via compression function `0x600898ec`). Created as new function (`0x600eb8bc`..`0x600eb955`). | 0 callers / 3 callees |

## Session 102 (Wave 72) — OpenSSL MD5 Completion, RC4 Stream Cipher, CMAC Authentication & SHA1 Update (20 functions, 1,728 bytes)

Decompiled and documented 20 functions (1,728 bytes across `0x600eb956`–`0x600ebf7c`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600eb956` |    6 | Crypto / Digest | **`crypto_md5_update_wrapper`** — OpenSSL `EVP_DigestUpdate` wrapper for `MD5_Update`: loads context (`+4`) and tail-calls `0x600eb8bc`. Created as new function (`0x600eb956`..`0x600eb95b`). | 0 callers / 1 callee |
| `0x600eb95c` |  198 | Crypto / Digest | **`crypto_md5_final_core`** — OpenSSL `MD5_Final` engine: pads input with `0x80`, appends 64-bit length in bits, and emits 16-byte digest. Created as new function (`0x600eb95c`..`0x600eba21`). | 1 caller / 2 callees |
| `0x600eba22` |   10 | Crypto / Digest | **`crypto_md5_final_wrapper`** — OpenSSL `EVP_DigestFinal` wrapper for `MD5_Final`: loads context (`+4`) and tail-calls `0x600eb95c`. Created as new function (`0x600eba22`..`0x600eba2b`). | 0 callers / 1 callee |
| `0x600eba2c` |  188 | Crypto / Cipher | ~~**`crypto_rc4_set_key`** — OpenSSL `RC4_set_key` / stream cipher S-box key scheduling algorithm (KSA).~~ ⚠️ **misidentified, corrected QA session 102** — real RC4 KSA is a byte-serial 256-entry S-box permutation with no concept of "blocks," an IV, or a block-cipher callback. This function instead processes the input in **16-byte blocks**, XORing each block with the *previous* block (classic CBC chaining) and invoking a **caller-supplied block-cipher callback** (`param_6`) on each block — the defining shape of generic **CBC-mode encryption** (real BoringSSL equivalent: `CRYPTO_cbc128_encrypt`), used generically with whatever block cipher is plugged in via the callback. No RC4 S-box, no key-dependent permutation, nothing byte-serial. | 2 callers / 3 callees |
| `0x600ebae8` |  334 | Crypto / Cipher | ~~**`crypto_rc4_crypt_blocks`** — OpenSSL `RC4` pseudo-random generation algorithm (PRGA) stream encryption/decryption loop.~~ ⚠️ **misidentified, corrected QA session 102** — same evidence class as `crypto_rc4_set_key` above: 16-byte block processing via a block-cipher callback, plus explicit overlapping-buffer safety handling (saving the ciphertext block as the next IV before it can be overwritten) — the standard shape of generic **CBC-mode decryption** (`CRYPTO_cbc128_decrypt`), not RC4's byte-serial keystream XOR (which needs no IV, no blocks, and no buffer-overlap handling at all). | 2 callers / 3 callees |
| `0x600ebc36` |   56 | Crypto / Cipher | ~~**`crypto_rc4_cipher_wrapper`** — OpenSSL EVP cipher wrapper for RC4: checks key length and invokes `RC4` / `RC4_set_key`.~~ ⚠️ **misidentified, corrected QA session 102** — dispatches on an encrypt/decrypt direction flag to the two corrected functions above (real CBC encrypt/decrypt engines), with a per-context block-cipher function pointer and IV location — real RC4 has no encrypt/decrypt direction distinction (both are the identical XOR-with-keystream operation) and no IV, so a direction-dispatching wrapper cannot be RC4-specific. This is the generic `EVP_CIPHER`-level CBC-mode dispatch glue, not an RC4 wrapper. | 0 callers / 2 callees |
| `0x600ebc6e` |  102 | Crypto / MAC | ~~**`crypto_poly1305_donna_mul`** — Poly1305 modular multiplication step ($d = a \cdot r \pmod{2^{130}-5}$) or CMAC subkey generation.~~ ⚠️ **narrowed, corrected QA session 102** — the body only **doubles** a 128-bit value across 4 words (carry-propagated left-shift-by-1) and conditionally XORs the constant `0xc2000000` based on the pre-shift top bit; there is no second operand, no multiply-accumulate, and no 130-bit/5-limb arithmetic anywhere — ruling out Poly1305-donna's multiply (which needs an actual `a·r` product across limbs). This is exactly the **AES-CMAC subkey-generation doubling step** (`K1 = double(L)`, `K2 = double(K1)`, GF(2^128) doubling with polynomial reduction) — real identity is CMAC subkey generation only, not Poly1305. | 1 caller / 0 callees |
| `0x600ebcd4` |  100 | Crypto / MAC | **`crypto_cmac_init_ex`** — OpenSSL `CMAC_Init` / subkey initialization. | 1 caller / 2 callees |
| `0x600ebd38` |  112 | Crypto / MAC | **`crypto_cmac_update`** — OpenSSL `CMAC_Update` streaming block processing engine. | 2 callers / 2 callees |
| `0x600ebda8` |   84 | Crypto / MAC | **`crypto_cmac_final`** — OpenSSL `CMAC_Final` completion and MAC output generator. | 0 callers / 2 callees |
| `0x600ebdfc` |  296 | Crypto / MAC | **`crypto_cmac_one_shot`** — Complete one-shot `CMAC` computation function. | 0 callers / 3 callees |
| `0x600ebf24` |    8 | Crypto / MAC | **`crypto_cmac_ctx_cleanup`** — OpenSSL `CMAC_CTX_cleanup`: securely cleanses context (280 bytes via `0x6013cfb0`). | 0 callers / 1 callee |
| `0x600ebf2c` |    8 | Crypto / Cipher | **`crypto_cipher_key_cleanup`** — Cleanses and frees cipher key buffer if non-null. Boundary adjusted from 266B to 8B (`0x600ebf2c`..`0x600ebf33`). | 1 caller / 0 callees |
| `0x600ebf34` |   30 | Crypto / EC | **`crypto_ecdsa_sig_clear_free`** — Frees `ECDSA_SIG` struct and BigNums (`r` and `s`). | 1 caller / 2 callees |
| `0x600ebf52` |    6 | Crypto / Digest | **`crypto_sha1_init_wrapper`** — OpenSSL `EVP_DigestInit` wrapper for SHA1: loads context (`+4`) and tail-calls `SHA1_Init` (`0x600e7450`). Created as new function (`0x600ebf52`..`0x600ebf57`). | 0 callers / 1 callee |
| `0x600ebf58` |   12 | Crypto / EC | **`crypto_ec_group_get_cofactor_flag`** — Returns low bit of group cofactor field (`*(group + 0x28) & 1`). | 1 caller / 0 callees |
| `0x600ebf64` |    6 | Crypto / Digest | **`crypto_sha1_ctx_load_wrapper`** — Loads SHA1 context (`+4`) and tail-calls `0x600e7474`. Created as new function (`0x600ebf64`..`0x600ebf69`). | 1 caller / 1 callee |
| `0x600ebf6a` |   12 | Crypto / EC | **`crypto_ec_method_dispatch_14`** — Method dispatcher invoking `ec_method->+0x14` or falling back to `0x600ebf64`. Created as new function (`0x600ebf6a`..`0x600ebf75`). | 0 callers / 1 callee |
| `0x600ebf76` |    6 | Crypto / EC | **`crypto_ec_error_trampoline_8ed74`** — Error handler trampoline calling `0x6008ed74(0)`. Created as new function (`0x600ebf76`..`0x600ebf7b`). | 2 callers / 0 callees |
| `0x600ebf7c` |  154 | Crypto / Digest | **`crypto_sha1_update_core`** — OpenSSL `SHA1_Update` streaming digest update engine (processes 64-byte blocks via compression function `0x60089fc8`). | 2 callers / 3 callees |

## Session 103 (Wave 73) — OpenSSL SHA-2/SHA-384/SHA-512 Digest Engines & ASN.1 / X509 Parser Framework (20 functions, 1,856 bytes)

Decompiled and documented 20 functions (1,856 bytes across `0x600ec016`–`0x600ec740`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ec016` |  278 | Crypto / Digest | **`crypto_sha256_final_core`** — OpenSSL `SHA256_Final` / `SHA224_Final` / `SHA1_Final` completion engine: pads input with `0x80`, appends 64-bit length, and outputs big-endian digest (28/32 bytes). | 2 callers / 2 callees |
| `0x600ec12c` |  180 | Crypto / Digest | **`crypto_sha512_update_core`** — OpenSSL `SHA512_Update` / `SHA384_Update` streaming digest update engine (processes 128-byte blocks via compression function `0x6004cdb8`). Created as new function (`0x600ec12c`..`0x600ec1df`). | 1 caller / 2 callees |
| `0x600ec1e0` |  316 | Crypto / Digest | **`crypto_sha512_final_core`** — OpenSSL `SHA512_Final` / `SHA384_Final` completion engine: pads input with `0x80`, appends 128-bit length, and outputs big-endian digest (48/64 bytes). Created as new function (`0x600ec1e0`..`0x600ec31b`). | 1 caller / 2 callees |
| `0x600ec31c` |   46 | Crypto / Digest | **`crypto_sha384_one_shot`** — OpenSSL `SHA384` one-shot digest calculation function. Created as new function (`0x600ec31c`..`0x600ec349`). | 1 caller / 4 callees |
| `0x600ec34a` |   10 | Crypto / ASN1 | **`crypto_asn1_is_tag_10`** — Checks if tag value equals `0x10` (ASN.1 SEQUENCE). | 1 caller / 0 callees |
| `0x600ec354` |   16 | Crypto / ASN1 | ~~**`crypto_asn1_check_type_10`** — Checks if ASN.1 item type at `+0xf0` equals `10`.~~ ⚠️ **misidentified, corrected QA session 103** — this function has nothing to do with ASN.1. Its 3 callers are `crypto_aes_gcm_mode_dispatch_encrypt` (`0x600e6dfe`) and `crypto_aes_gcm_mode_dispatch_decrypt` (`0x600e70ba`), both already independently attributed in this file (sessions 98/103's own AES-GCM rows) as calling this function specifically to "check hardware acceleration." The struct being checked is an `EVP_CIPHER_CTX`-shaped context, and offset `+0xf0` reads its cipher-mode field; `10` matches real OpenSSL/BoringSSL's `EVP_CIPH_GCM_MODE` enum value — this is a **cipher-mode/hardware-acceleration gate**, not an ASN.1 type check. The "checks equals 10" superficial resemblance to the neighboring, genuinely-ASN.1 `crypto_asn1_is_tag_10` (`0x600ec34a`, which correctly checks for the real SEQUENCE tag `0x10`=16, a different value) appears to be a coincidental naming/grouping choice, not a real relationship — note the two check *different* values (10 decimal here vs. `0x10`/16 there). | 3 callers / 0 callees |
| `0x600ec364` |   36 | Crypto / ASN1 | **`crypto_asn1_set_type_10`** — Sets ASN.1 item type to `10` and initializes pointers. | 2 callers / 0 callees |
| `0x600ec388` |    4 | Crypto / ASN1 | **`thunk_crypto_asn1_set_type_10`** — Trampoline thunk to `crypto_asn1_set_type_10` (`0x600ec364`). | 0 callers / 1 callee |
| `0x600ec38c` |  172 | Crypto / ASN1 | **`crypto_asn1_item_copy_data`** — Copies ASN.1 item data buffer. | 1 caller / 1 callee |
| `0x600ec438` |  220 | Crypto / ASN1 | **`crypto_asn1_item_pack_data`** — Packs and serializes ASN.1 item data buffer into output structure. | 1 caller / 1 callee |
| `0x600ec514` |  112 | Crypto / ASN1 | **`crypto_asn1_integer_to_uint32`** — Converts ASN.1 INTEGER structure (`ASN1_INTEGER`) to 32-bit unsigned integer with bounds checking. | 1 caller / 0 callees |
| `0x600ec584` |    6 | Crypto / ASN1 | **`crypto_asn1_error_trampoline_91c90`** — Trampoline calling error handler `0x60091c90(0)`. Resized from 122B to 6B (`0x600ec584`..`0x600ec589`). | 1 caller / 0 callees |
| `0x600ec58a` |   72 | Crypto / ASN1 | **`crypto_asn1_item_free_fields`** — Frees allocated buffers and fields within ASN.1 item structure. | 2 callers / 1 callee |
| `0x600ec5d2` |   46 | Crypto / ASN1 | **`crypto_asn1_boolean_set`** — Sets boolean value in ASN.1 structure (`0xff` for true, `0x00` for false). | 1 caller / 1 callee |
| `0x600ec600` |  166 | Crypto / ASN1 | **`crypto_asn1_put_object_header`** — OpenSSL `ASN1_put_object`: encodes tag, class, and length header bytes into DER stream. | 3 callers / 0 callees |
| `0x600ec6a6` |   20 | Crypto / ASN1 | **`crypto_asn1_put_eoc`** — Encodes ASN.1 End-Of-Contents (`0x00, 0x00`) bytes. | 3 callers / 0 callees |
| `0x600ec6ba` |   66 | Crypto / ASN1 | **`crypto_asn1_object_size`** — OpenSSL `ASN1_object_size`: computes total DER encoded size given tag, length, and construct flag. | 3 callers / 0 callees |
| `0x600ec6fc` |   36 | Crypto / ASN1 | **`crypto_asn1_string_set_data`** — Sets data pointer and length on `ASN1_STRING` structure. | 0 callers / 1 callee |
| `0x600ec720` |   32 | Crypto / ASN1 | **`crypto_asn1_string_free`** — OpenSSL `ASN1_STRING_free`: frees data buffer and string structure (5 callers). | 5 callers / 1 callee |
| `0x600ec740` |   22 | Crypto / ASN1 | **`crypto_asn1_check_eoc`** — Checks if current DER stream position points to End-Of-Contents (`0x00, 0x00`) markers (5 callers). | 5 callers / 0 callees |

## Session 104 (Wave 74) — OpenSSL ASN.1 String Ops, Template Coders (d2i/i2d) & Type Instantiation (20 functions, 1,128 bytes)

Decompiled and documented 20 functions (1,128 bytes across `0x600ec756`–`0x600ecbb6`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ec756` |   34 | Crypto / ASN1 | **`crypto_asn1_string_copy_wrapper`** — OpenSSL `ASN1_STRING_copy`: duplicates string buffer and sets length/flags. | 1 caller / 1 callee |
| `0x600ec778` |   52 | Crypto / ASN1 | **`crypto_asn1_string_dup`** — OpenSSL `ASN1_STRING_dup`: allocates new `ASN1_STRING` container and duplicates contents. | 0 callers / 1 callee |
| `0x600ec7ac` |   30 | Crypto / ASN1 | **`crypto_asn1_string_cmp`** — OpenSSL `ASN1_STRING_cmp`: compares lengths and contents via `memcmp` (`0x6013d168`). | 0 callers / 1 callee |
| `0x600ec7ca` |  234 | Crypto / ASN1 | **`crypto_asn1_template_d2i`** — OpenSSL ASN.1 template DER-to-internal decoder step (`asn1_template_d2i` / `asn1_template_noexp_d2i`). Boundary adjusted to 234B (`0x600ec7ca`..`0x600ec8b3`). | 1 caller / 3 callees |
| `0x600ec8b4` |  166 | Crypto / ASN1 | **`crypto_asn1_template_i2d`** — OpenSSL ASN.1 template internal-to-DER encoder step (`asn1_template_i2d`). | 1 caller / 4 callees |
| `0x600ec95a` |  106 | Crypto / ASN1 | **`crypto_asn1_item_i2d`** — OpenSSL `ASN1_item_i2d`: encodes top-level ASN.1 item to DER buffer. | 0 callers / 2 callees |
| `0x600ec9c4` |    6 | Crypto / ASN1 | **`crypto_asn1_item_i2d_wrapper`** — Wrapper for `ASN1_item_i2d` passing default length/output pointers. Created as new function (`0x600ec9c4`..`0x600ec9c9`). | 0 callers / 0 callees |
| `0x600ec9ca` |   34 | Crypto / ASN1 | **`crypto_asn1_primitive_free_dispatch`** — Dispatches custom primitive destructor callback (`item->funcs->prim_free`). | 2 callers / 1 callee |
| `0x600ec9ec` |   22 | Crypto / ASN1 | **`crypto_asn1_item_combine_free_wrapper`** — Wrapper invoking `ASN1_item_combine_free` (`0x60090940`). Created as new function (`0x600ec9ec`..`0x600eca01`). | 0 callers / 1 callee |
| `0x600eca02` |    6 | Crypto / ASN1 | **`crypto_asn1_item_free`** — OpenSSL `ASN1_item_free`: frees ASN.1 item and sub-fields (`0x60090940(val, it, 0)`). | 2 callers / 1 callee |
| `0x600eca08` |   78 | Crypto / ASN1 | **`crypto_asn1_template_free`** — OpenSSL `asn1_template_free`: iterates sequence/set of template items and frees each member. | 4 callers / 4 callees |
| `0x600eca56` |   48 | Crypto / ASN1 | **`crypto_asn1_primitive_new_default`** — Sets default primitive values (NULL/BOOLEAN/INTEGER). Created as new function (`0x600eca56`..`0x600eca85`). | 1 caller / 0 callees |
| `0x600eca86` |   56 | Crypto / ASN1 | **`crypto_asn1_template_new`** — OpenSSL `asn1_template_new`: initializes optional/default template fields. Boundary adjusted to 56B (`0x600eca86`..`0x600ecabd`). | 1 caller / 1 callee |
| `0x600ecabe` |  140 | Crypto / ASN1 | **`crypto_asn1_primitive_new`** — OpenSSL `asn1_primitive_new`: allocates and initializes primitive ASN.1 types (BIGNUM, OBJECT, STRING, INTEGER). Boundary adjusted to 140B (`0x600ecabe`..`0x600ecb49`). | 0 callers / 3 callees |
| `0x600ecb4a` |    6 | Crypto / ASN1 | **`crypto_asn1_item_new`** — OpenSSL `ASN1_item_new`: allocates and instantiates new ASN.1 structure (`tasn_new.c`). Created as new function (`0x600ecb4a`..`0x600ecb4f`). | 2 callers / 0 callees |
| `0x600ecb50` |   30 | Crypto / ASN1 | **`crypto_asn1_item_new_wrapper`** — Wrapper allocating new ASN.1 item and returning allocated pointer. Created as new function (`0x600ecb50`..`0x600ecb6d`). | 0 callers / 1 callee |
| `0x600ecb6e` |    4 | Crypto / ASN1 | **`thunk_crypto_asn1_string_free`** — Trampoline thunk to `ASN1_STRING_free` (`0x600ec720`). Created as new function (`0x600ecb6e`..`0x600ecb71`). | 0 callers / 0 callees |
| `0x600ecb72` |   34 | Crypto / ASN1 | **`crypto_asn1_get_field_ptr`** — Computes offset pointer to struct field given template header and base address. | 2 callers / 0 callees |
| `0x600ecb94` |   34 | Crypto / ASN1 | **`crypto_asn1_get_enc_ptr`** — Returns pointer to cached ASN.1 encoding structure if present. | 4 callers / 0 callees |
| `0x600ecbb6` |    8 | Crypto / ASN1 | **`crypto_asn1_get_field_val`** — Reads word at struct offset specified by template item. | 3 callers / 0 callees |

## Session 105 (Wave 75) — OpenSSL ASN.1 Cached Encoding, Base64 Decoding & Dynamic Memory Buffers (20 functions, 906 bytes)

Decompiled and documented 20 functions (906 bytes across `0x600ecbbe`–`0x600ecf0a`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ecbbe` |   12 | Crypto / ASN1 | **`crypto_asn1_set_field_ptr`** — Stores computed field pointer into struct offset defined by template item. | 1 caller / 0 callees |
| `0x600ecbca` |   14 | Crypto / ASN1 | **`crypto_asn1_set_field_modified`** — Sets modified/dirty flag bit (`*ptr = 1`) on struct field resolved via `0x600ecb72`. | 0 callers / 1 callee |
| `0x600ecbd8` |   20 | Crypto / ASN1 | **`crypto_asn1_template_callback_dispatch`** — Invokes custom ASN.1 callback handler (`0x600867c8`) if field present. | 1 caller / 2 callees |
| `0x600ecbec` |   34 | Crypto / ASN1 | **`crypto_asn1_clear_enc_modified`** — Clears modified flag bit in cached ASN.1 encoding structure (`ASN1_ENCODING`). | 0 callers / 1 callee |
| `0x600ecc0e` |   50 | Crypto / ASN1 | **`crypto_asn1_enc_free`** — Frees cached DER encoding buffer (`enc->enc`) and resets length/flags. | 1 caller / 2 callees |
| `0x600ecc40` |   88 | Crypto / ASN1 | **`crypto_asn1_enc_save`** — Saves DER stream bytes into cached ASN.1 encoding structure (`ASN1_ENCODING`). | 1 caller / 4 callees |
| `0x600ecc98` |   60 | Crypto / ASN1 | **`crypto_asn1_enc_restore`** — Copies cached DER encoding bytes to output buffer if valid (`ASN1_ENCODING` restore). Boundary adjusted from 40B to 60B (`0x600ecc98`..`0x600eccd3`). | 1 caller / 2 callees |
| `0x600eccd4` |   14 | Crypto / ASN1 | **`crypto_asn1_get_seq_ptr`** — Computes pointer to sequence element field within ASN.1 struct. | 3 callers / 0 callees |
| `0x600ecce2` |  114 | Crypto / Base64 | **`crypto_b64_decode_char`** — OpenSSL `EVP_DecodeBase64Char`: constant-time Base64 character-to-6-bit-value decode helper. | 1 caller / 0 callees |
| `0x600ecd54` |  190 | Crypto / Base64 | **`crypto_b64_decode_block`** — OpenSSL `EVP_DecodeBlock`: decodes 4-character Base64 quad into up to 3 raw bytes with padding handling (`=`). | 1 caller / 1 callee |
| `0x600ece12` |    8 | Crypto / ASN1 | **`crypto_asn1_ctx_init`** — Initializes ASN.1 parser context (clears 56 bytes via `memset`). | 1 caller / 1 callee |
| `0x600ece1a` |    4 | Crypto / ASN1 | **`thunk_crypto_asn1_ctx_init`** — Trampoline thunk to `crypto_asn1_ctx_init` (`0x600ece12`). | 1 caller / 1 callee |
| `0x600ece1e` |   30 | Crypto / ASN1 | **`crypto_asn1_ctx_validate`** — Validates ASN.1 context state flags and header tag. | 1 caller / 0 callees |
| `0x600ece3c` |   36 | Crypto / ASN1 | **`crypto_asn1_item_d2i_fp_wrapper`** — DER-to-internal wrapper loading item from stream via `0x600ed10a` and `0x600e7504`. | 2 callers / 2 callees |
| `0x600ece60` |   24 | Crypto / ASN1 | **`crypto_asn1_key_container_free`** — Frees allocated ASN.1 key buffer and outer container (`vPortFree`). | 2 callers / 1 callee |
| `0x600ece78` |   42 | Crypto / Buffer | **`crypto_buf_mem_grow_clean`** — OpenSSL `BUF_MEM_grow_clean`: expands dynamic memory buffer and cleanses new space. | 3 callers / 2 callees |
| `0x600ecea2` |    4 | Crypto / Buffer | **`thunk_crypto_buf_mem_grow_clean`** — Trampoline thunk to `BUF_MEM_grow_clean` (`0x600ece78`). | 3 callers / 1 callee |
| `0x600ecea6` |   78 | Crypto / Buffer | **`crypto_buf_mem_grow`** — OpenSSL `BUF_MEM_grow`: expands dynamic memory buffer capacity with power-of-two growth. | 1 caller / 1 callee |
| `0x600ecef4` |   22 | Crypto / Buffer | **`crypto_buf_mem_write_advance`** — Advances `BUF_MEM` write position and length counter. | 4 callers / 1 callee |
| `0x600ecf0a` |   62 | Crypto / ASN1 | **`crypto_asn1_put_integer_core`** — Serializes 32-bit integer into ASN.1 DER integer stream. | 3 callers / 1 callee |

## Session 106 (Wave 76) — OpenSSL / BoringSSL CBB (ByteBuilder) & CBS (ByteString) ASN.1 DER Engines (20 functions, 1,138 bytes)

Decompiled and documented 20 functions (1,138 bytes across `0x600ecf48`–`0x600ed3a0`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ecf48` |    8 | Crypto / CBB | ~~**`crypto_cbb_cleanup`** — OpenSSL/BoringSSL `CBB_cleanup`: zero-initializes CBB structure (36 bytes via `memset`).~~ ⚠️ **corrected, QA session 106** — disassembly-confirmed the size literal is `movs r2,#0x10` (16, not 36): the body is only `thunk_EXT_FUN_0000b5ba(param_1,0,0x10)`, zeroing the caller-supplied 16-byte CBB struct in place, with no allocation. This is BoringSSL's `CBB_zero`, not `CBB_cleanup` — the real cleanup/free function is `0x600ecf8c` below (labels effectively swapped). | 1 caller / 1 callee |
| `0x600ecf50` |   60 | Crypto / CBB | ~~**`crypto_cbb_add_asn1_bitstring`** — Serializes bitstring into `CBB` with unused-bits prefix byte.~~ ⚠️ **corrected, QA session 106** — no bitstring-specific logic exists anywhere in the body (no unused-bits prefix byte, no tag write). It calls `0x600ecf48` (zero the struct), allocates a data buffer of the caller-requested capacity plus a 16-byte shared-buffer header via `FUN_600e092c` (malloc-shaped), and wires the header's `{buf, len=0, cap, flags=1}` fields into `*param_1`. This is BoringSSL's `CBB_init(cbb, initial_capacity)` — the CBB constructor, not a bitstring serializer. | 2 callers / 3 callees |
| `0x600ecf8c` |   34 | Crypto / CBB | ~~**`crypto_cbb_add_asn1_bool`** — Serializes boolean value into `CBB` (`0xff` / `0x00`).~~ ⚠️ **corrected, QA session 106** — no `0xff`/`0x00` write exists anywhere in the body. It checks the top-level/`is_child` flag (offset `+0xe`) and, only for a non-child CBB, conditionally frees the data buffer (gated on the shared header's `can_resize` flag) and the shared header itself via `thunk_EXT_FUN_0000ac5e` (established free thunk), then nulls the pointer. This is BoringSSL's real `CBB_cleanup` — see the `0x600ecf48` correction above, where this exact behavior/name pair got swapped onto the wrong addresses. | 3 callers / 1 callee |
| `0x600ecfae` |  236 | Crypto / CBB | ~~**`crypto_cbb_add_asn1_tag`** — OpenSSL/BoringSSL `CBB_add_asn1`: writes ASN.1 tag and reserves length field in CBB stream (25 callers across key/algorithm serializers).~~ ⚠️ **corrected, QA session 106** — the body is self-recursive (flushes a child CBB via a recursive call to itself first), never writes a tag byte, and instead back-patches the DER length field a parent left behind — writing the `0x80`/`0x81`/`0x82`/`0x83`/`0x84` long-form-length markers and calling a `memmove`-shaped thunk (`thunk_EXT_FUN_0000b588`) to shift data when the true length needs a different byte-width than reserved. Called as the very first step by nearly every other function in this cluster (25 callers), exactly matching real `CBB_flush`'s role — every mutating CBB call begins `if (!CBB_flush(cbb)) ...`. This is `CBB_flush`, not `CBB_add_asn1` (the real tag-writing function is `0x600ed1b4` below). | 25 callers / 3 callees |
| `0x600ed09a` |   68 | Crypto / CBB | ~~**`crypto_cbb_add_asn1_oid`** — Serializes `ASN1_OBJECT` / OID into `CBB`.~~ ⚠️ **corrected, QA session 106** — no OID/object-identifier encoding logic exists in the body: it flushes (`0x600ecfae`), extracts the shared buffer's data pointer and length into the caller's out-parameters, clears the internal pointer (so the following free doesn't double-free), and calls `0x600ecf8c` (the real `CBB_cleanup`, per the correction above). This is BoringSSL's `CBB_finish(cbb, out_data, out_len)` — the label already (mis)assigned to `0x600ed1b4` below actually belongs here. | 2 callers / 2 callees |
| `0x600ed0de` |   44 | Crypto / CBB | ~~**`crypto_cbb_add_asn1_null`** — OpenSSL/BoringSSL `CBB_add_asn1_null` / empty element serializer (13 callers).~~ ⚠️ **corrected, QA session 106** — the body is generic: flush, reserve `param_3` bytes via the established `FUN_600ecef4` ("advances write position/length"), then — only if `param_3 != 0` — `memcpy` (`thunk_EXT_FUN_0000b572`) `param_3` bytes from `param_2` into the reserved region. This is the real, generic `CBB_add_bytes(cbb, data, len)`; its 13 callers are ASN.1 key/algorithm encoders that happen to invoke it with `len=0` when writing an empty NULL parameter after a preceding tag-only `CBB_add_asn1` call elsewhere — a call-site pattern, not this function's own fixed identity. | 13 callers / 3 callees |
| `0x600ed10a` |   32 | Crypto / CBB | **`crypto_cbb_add_bytes`** — OpenSSL/BoringSSL `CBB_add_bytes`: appends byte array into `CBB`. ⚠️ **corrected, QA session 106** — the body only calls flush + `FUN_600ecef4(*param_1,param_2,param_3)` and returns; there is no `memcpy` anywhere in it (unlike `0x600ed0de` above, which does copy). Its own incoming `param_2` is passed straight through as the out-parameter that receives the newly-reserved write pointer, not as a source buffer. This matches BoringSSL's `CBB_add_space(cbb, out_data, len)` — reserve space and hand back a pointer for the caller to fill in directly — not `CBB_add_bytes` (the real `add_bytes`, which does copy, is `0x600ed0de` above). | 2 callers / 2 callees |
| `0x600ed12a` |   30 | Crypto / CBB | **`crypto_cbb_add_u8`** — OpenSSL/BoringSSL `CBB_add_u8`: appends 8-bit unsigned byte to `CBB` (14 callers). | 14 callers / 2 callees |
| `0x600ed148` |  108 | Crypto / CBB | ~~**`crypto_cbb_add_asn1_time`** — Serializes date/time struct into 2-digit/4-digit ASCII date format.~~ ⚠️ **corrected, QA session 106** — no ASCII/decimal conversion exists anywhere in the body (no `+ '0'`, no date-field logic). It computes the number of 7-bit groups needed for a 64-bit value via a multi-word right-shift-by-7 loop, then emits each group as a byte with the continuation bit (`0x80`) set on all but the final group, via repeated calls to the established `CBB_add_u8` (`0x600ed12a`). This is base-128 variable-length-quantity encoding — BoringSSL's internal `cbb_add_base128_integer`-shaped helper, used for ASN.1 high tag numbers (and OID sub-identifiers) — confirmed as the real high-tag-number-path callee from `0x600ed1b4`'s own body (see below), not a date/time formatter. | 1 caller / 1 callee |
| `0x600ed1b4` |  118 | Crypto / CBB | ~~**`crypto_cbb_finish`** — OpenSSL/BoringSSL `CBB_finish`: closes nested child CBB, computes DER length, and commits buffer (17 callers).~~ ⚠️ **corrected, QA session 106** — the body flushes (`0x600ecfae`), computes the ASN.1 tag byte's class/constructed bits, and writes either a single tag byte (low tag number < 31, via the established `CBB_add_u8`) or a `0x1f` marker plus a base-128-encoded tag number (high tag number, via `0x600ed148` above), then allocates and zero-initializes (`thunk_EXT_FUN_0000b5ba`, 16 bytes — the same `CBB_zero` shape as `0x600ecf48`) a brand-new child `CBB` and links it into the parent (`is_child=1`, parent's child-pointer field set, child-offset saved). This is a close structural match to real `CBB_add_asn1(cbb, out_contents, tag)` — not `CBB_finish` (the real finish function, which extracts the final buffer rather than creating children, is `0x600ed09a` above). | 17 callers / 4 callees |
| `0x600ed22a` |   30 | Crypto / CBB | **`crypto_cbb_add_u16`** — OpenSSL/BoringSSL `CBB_add_u16`: appends 16-bit big-endian integer to `CBB`. | 0 callers / 2 callees |
| `0x600ed248` |   30 | Crypto / CBB | ~~**`crypto_cbb_add_u24`** — OpenSSL/BoringSSL `CBB_add_u24`: appends 24-bit big-endian integer to `CBB`.~~ ⚠️ **corrected, QA session 106** — disassembly-confirmed the byte-count literal is `movs r3,#4` (4, not 3). This function is byte-identical in shape to `0x600ed12a`/`0x600ed22a` (established `CBB_add_u8`/`CBB_add_u16`, literals `1`/`2` respectively) with only the byte-count literal changed. A 3-byte `add_u24` would need literal `3`; `4` matches `CBB_add_u32` instead. | 0 callers / 2 callees |
| `0x600ed266` |  128 | Crypto / CBB | **`crypto_cbb_add_asn1_uint64`** — OpenSSL/BoringSSL `CBB_add_asn1_uint64`: serializes unsigned 64-bit integer in big-endian DER format with minimal length encoding (7 callers). | 7 callers / 3 callees |
| `0x600ed2e6` |   76 | Crypto / CBS | **`crypto_cbs_get_u16`** — OpenSSL/BoringSSL `CBS_get_u16`: parses 16-bit big-endian integer from `CBS`. ⚠️ *(caveat, QA session 106)* — the byte count consumed is a runtime parameter (`param_3`), not a literal baked into this function; the body is a generic "consume N bytes, accumulate big-endian into a 64-bit pair" reader that works for any `N` ≤ 8, not a fixed-16-bit-only reader. Its real callers (`0x600ed42c`, `0x600ed462`, not yet decompiled) presumably pass a literal `2` for the `CBS_get_u16` use case, but the function itself is the generic engine likely shared behind `CBS_get_u8`/`u16`/`u24`/`u32`. | 2 callers / 0 callees |
| `0x600ed332` |   72 | Crypto / CBB | ~~**`crypto_cbb_add_asn1_bignum`** — Serializes `BIGNUM` into ASN.1 INTEGER DER format.~~ ⚠️ **corrected, QA session 106** — real DER INTEGER encoding is raw big-endian *binary* (exactly what `0x600ed266` above correctly implements). This function does something else entirely: it repeatedly divides a 64-bit value by 10 via `FUN_6004c814` — the codebase's independently-established (`bruce-crypto.md`, `BN_div`-shaped long division) 2-word/1-word divide primitive — extracting decimal digits (`+ '0'`) into a 24-byte stack buffer, then hands the resulting ASCII decimal string to `0x600ed0de` (the real `CBB_add_bytes`, per the correction above). This is a decimal-integer-to-ASCII-string ("itoa") formatter, not a DER/BIGNUM binary encoder. | 1 caller / 2 callees |
| `0x600ed37a` |    6 | Crypto / CBS | **`crypto_cbs_init`** — OpenSSL/BoringSSL `CBS_init`: initializes `CBS` with data pointer and byte length. | 2 callers / 0 callees |
| `0x600ed380` |   24 | Crypto / CBS | **`crypto_cbs_skip`** — OpenSSL/BoringSSL `CBS_skip` / `CBS_get_bytes`: advances `CBS` read pointer by $N$ bytes with bounds check. Boundary adjusted from 14B to 24B. | 2 callers / 0 callees |
| `0x600ed398` |    4 | Crypto / CBS | **`crypto_cbs_data`** — OpenSSL/BoringSSL `CBS_data`: returns data pointer from `CBS` (`return *cbs`, 9 callers). | 9 callers / 0 callees |
| `0x600ed39c` |    4 | Crypto / CBS | **`crypto_cbs_len`** — OpenSSL/BoringSSL `CBS_len`: returns remaining length from `CBS` (`return *(cbs + 4)`, 14 callers). | 14 callers / 0 callees |
| `0x600ed3a0` |   26 | Crypto / CBS | **`crypto_cbs_mem_equal`** — OpenSSL/BoringSSL `CBS_mem_equal`: constant-time comparison of `CBS` against raw buffer. | 1 caller / 1 callee |

**⚠️ QA session 106 note on the CBB cluster:** 9 of the 14 CBB (ByteBuilder) rows above were corrected — the wave's initial pass assigned plausible per-function ASN.1-content-type names (bitstring, boolean, OID, time, NULL, bignum) to what turned out to be BoringSSL's small set of *generic* CBB lifecycle/plumbing primitives (`CBB_zero`, `CBB_init`, `CBB_cleanup`, `CBB_flush`, `CBB_add_asn1`, `CBB_finish`, `CBB_add_bytes`, `CBB_add_space`) plus one internal helper (`cbb_add_base128_integer`) and one unrelated ASCII-decimal formatter — none of which write type-specific ASN.1 content themselves. The re-derivation above is self-consistent end-to-end (each function's callees/callers now line up with its corrected identity, e.g. `0x600ed1b4`'s two tag-encoding paths call exactly the two functions — `0x600ed12a` and `0x600ed148` — this correction identifies as the low/high tag-number writers) and was cross-checked against three independent lines of evidence: literal disassembly (the `0x600ecf48`/`0x600ed248` byte-count corrections), an established cross-file citation (`FUN_6004c814` as the `BN_div`-shaped divide primitive in `bruce-crypto.md`, confirming `0x600ed332`'s digit-extraction loop), and internal caller-set consistency (the three functions sharing callers `0x60091ddc`/`0x60090fd0` are exactly the CBB-lifecycle triad `CBB_init`/`CBB_cleanup`/`CBB_finish` a top-level serializer entry point would call). The 5 CBS (ByteString) rows and `crypto_cbb_add_u8`/`add_u16`/`add_asn1_uint64` were independently verified and are unaffected.

## Session 107 (Wave 77) — OpenSSL / BoringSSL CBS ASN.1 Parsers, CBB/CBS Unicode Codecs & EVP_BytesToKey (22 functions, 1,532 bytes)

Decompiled and documented 22 functions (1,532 bytes across `0x600ed3ba`–`0x600ed9b6`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ed3ba` |   28 | Crypto / CBS | **`crypto_cbs_get_u8`** — BoringSSL `CBS_get_u8`: consumes single 8-bit unsigned byte from CBS stream, advancing data pointer and decrementing length (7 callers). | 7 callers / 0 callees |
| `0x600ed3d6` |   86 | Crypto / CBS | **`crypto_cbs_get_base128_integer`** — BoringSSL internal `cbs_get_base128_integer`: decodes variable-length 7-bit VLQ base-128 integer with MSB continuation bit into 64-bit unsigned integer; enforces non-minimal encoding rejection (rejects leading `0x80` byte for 0) and 64-bit overflow checks. Inverse of session 106's `cbb_add_base128_integer` (`0x600ed148`). | 2 callers / 1 callee |
| `0x600ed42c` |   24 | Crypto / CBS | **`crypto_cbs_get_u32`** — BoringSSL `CBS_get_u32`: consumes 32-bit big-endian unsigned integer from CBS stream via generic integer reader `0x600ed2e6` (`len=4`). | 1 caller / 1 callee |
| `0x600ed444` |   30 | Crypto / CBS | **`crypto_cbs_get_bytes`** — BoringSSL `CBS_get_bytes`: bounds-checks CBS remaining length against requested length, slices out child CBS slice and advances parent read pointer by `len` bytes. | 1 caller / 0 callees |
| `0x600ed462` |  230 | Crypto / CBS | **`crypto_cbs_get_asn1_element`** — BoringSSL internal `cbs_get_asn1_element`: core ASN.1 TLV parser with DER/BER mode switch (`param_5 = is_ber`). Parses tag via `0x60090f78`, reads length byte via `0x600ed3ba`, handles short-form (< 128) and long-form (up to 4 length octets via `0x600ed2e6`), enforces strict DER minimal encoding rules, supports BER indefinite length (`0x80`), and extracts element slice via `0x600ed444`. | 1 caller / 4 callees |
| `0x600ed548` |   14 | Crypto / CBS | **`crypto_cbs_get_asn1_element_der`** — BoringSSL `CBS_get_asn1_element`: thin wrapper invoking `0x600ed462` with stack argument `is_ber = 0` (strict DER encoding enforcement). | 1 caller / 1 callee |
| `0x600ed556` |   52 | Crypto / CBS | **`crypto_cbs_get_asn1`** — BoringSSL `CBS_get_asn1`: parses next ASN.1 element via `0x600ed548`, validates that tag matches `tag_to_match`, and advances `out` slice past tag/length header via `0x600ed380` (`CBS_skip`) to leave only payload contents (12 callers across X509/ASN.1 parsers). | 12 callers / 2 callees |
| `0x600ed58a` |   42 | Crypto / CBS | **`crypto_cbs_peek_asn1_tag`** — BoringSSL `CBS_peek_asn1_tag`: non-destructive tag inspector; parses tag from temporary copy of CBS via `0x60090f78` without consuming bytes from input CBS. | 3 callers / 1 callee |
| `0x600ed5b4` |  122 | Crypto / CBS | **`crypto_cbs_get_asn1_uint64`** — BoringSSL `CBS_get_asn1_uint64`: parses ASN.1 INTEGER (tag 2 via `0x600ed556`), enforces DER positive-sign and minimal leading-zero encoding rules, accumulates 64-bit big-endian value with overflow checking (3 callers). | 3 callers / 1 callee |
| `0x600ed62e` |   40 | Crypto / CBS | **`crypto_cbs_get_optional_asn1`** — BoringSSL `CBS_get_optional_asn1`: peeks tag via `0x600ed58a`; if present, parses element via `0x600ed556` and sets `*out_present = 1`; if absent, leaves CBS intact and sets `*out_present = 0`. | 1 caller / 2 callees |
| `0x600ed656` | ~~28~~ **24** ⚠️ *(corrected, QA)* | Crypto / String | **`crypto_cbs_is_valid_code_point`** — BoringSSL Unicode code point validator: validates `cp < 0x110000`, noncharacter exclusion (`cp & 0xFFFE != 0xFFFE` and `cp` not in `0xFDD0..0xFDEF`), and (via genuine compiler fallthrough into the separately-callable `0x600ed66e`) UTF-16 surrogate exclusion (`cp` not in `0xD800..0xDFFF`). Behavioral claim confirmed correct by disassembly, but the claimed 28-byte size overlaps 4 bytes into `0x600ed66e`'s own body — real boundary is `0x600ed656`–`0x600ed66e` (24B); a 4-byte shared "return invalid" tail (`movs r0,#0; bx lr`) at `0x600ed67e`–`0x600ed682`, reached by three internal branches from this function, is unclaimed by any census entry. Caller count is also undercounted (4 claimed vs. 6 real — `0x600ed840` and `0x600ed866` both disassembly-confirmed to call this function and already list it in their own callee sections, just not reciprocally listed here, likely because their boundaries were defined later in this same session). ~~4 callers~~ **6 callers** / 0 callees |
| `0x600ed66e` |   16 | Crypto / String | **`crypto_cbs_is_not_surrogate`** — UTF-16 surrogate range exclusion predicate: returns true if 16-bit code unit is outside `0xD800..0xDFFF` (`cp - 0xD800 > 0x7FF`). | 1 caller / 0 callees |
| `0x600ed682` |  160 | Crypto / CBS | **`crypto_cbs_get_utf8`** — BoringSSL internal `cbs_get_utf8`: decodes complete UTF-8 sequence (1 to 4 bytes via `0x600ed3ba`) into 32-bit Unicode code point; enforces `0x80..0xBF` continuation byte framing, overlong encoding rejection against threshold minimums (`0x80`, `0x800`, `0x10000`), and code point validity via `0x600ed656`. | 0 callers / 2 callees |
| `0x600ed722` |   26 | Crypto / CBS | **`crypto_cbs_get_latin1`** — BoringSSL internal `cbs_get_latin1`: consumes 8-bit byte via `0x600ed3ba` (`CBS_get_u8`) and zero-extends to 32-bit Unicode code point. | 0 callers / 1 callee |
| `0x600ed73c` |   34 | Crypto / CBS | **`crypto_cbs_get_ucs2_be`** — BoringSSL internal `cbs_get_ucs2_be`: consumes 16-bit big-endian integer via `thunk_EXT_FUN_0000b09a` (`cbs_get_u16`), validates non-surrogate code point via `0x600ed656`, and returns 32-bit Unicode code point. | 0 callers / 2 callees |
| `0x600ed75e` |   24 | Crypto / CBS | **`crypto_cbs_get_utf32_be`** — BoringSSL internal `cbs_get_utf32_be`: consumes 32-bit big-endian integer via `0x600ed42c` (`CBS_get_u32`), validates code point via `0x600ed656`, and returns 32-bit Unicode code point. | 1 caller / 2 callees |
| `0x600ed776` |   30 | Crypto / CBB | **`crypto_cbb_get_utf8_len`** — UTF-8 encoded length calculator: returns byte count required for Unicode code point (1 byte for `< 0x80`, 2 bytes for `< 0x800`, 3 bytes for `< 0x10000`, 4 bytes otherwise). | 1 caller / 0 callees |
| `0x600ed794` |  148 | Crypto / CBB | **`crypto_cbb_add_utf8`** — BoringSSL `CBB_add_utf8`: validates code point via `0x600ed656`, encodes 1 to 4 UTF-8 bytes using standard prefix masks (`0x00`, `0xC0`, `0xE0`, `0xF0`) and continuation bytes (`0x80 | (bits & 0x3F)`), emitting bytes via `0x600ed12a` (`CBB_add_u8`). | 0 callers / 2 callees |
| `0x600ed828` |   24 | Crypto / CBB | **`crypto_cbb_add_latin1`** — BoringSSL internal `cbb_add_latin1`: validates code point `< 0x100` (fits in 8-bit Latin-1 / ISO-8859-1), emits byte via `0x600ed12a` (`CBB_add_u8`). | 1 caller / 1 callee |
| `0x600ed840` |   38 | Crypto / CBB | **`crypto_cbb_add_ucs2_be`** — BoringSSL internal `cbb_add_ucs2_be`: validates code point `< 0x10000` and validates code point via `0x600ed656`, emits 16-bit big-endian integer via `0x600ed22a` (`CBB_add_u16`). Defined function boundary in `FixSpuriousSplits.java` and `bruce_functions.csv`. | 0 callers / 2 callees |
| `0x600ed866` |   26 | Crypto / CBB | **`crypto_cbb_add_utf32_be`** — BoringSSL internal `cbb_add_utf32_be`: validates code point via `0x600ed656`, emits 32-bit big-endian integer via `0x600ed248` (`CBB_add_u32`). Defined function boundary in `FixSpuriousSplits.java` and `bruce_functions.csv`. | 0 callers / 2 callees |
| `0x600ed880` |  310 | Crypto / EVP | **`crypto_evp_bytes_to_key`** — OpenSSL / BoringSSL `EVP_BytesToKey`: password-based key derivation function (PBKDF1 / classic OpenSSL EVP key derivation for encrypted PEM files). Initializes `EVP_MD_CTX` on stack (`0x6013d0d8`), digests passphrase and optional 8-byte salt (`0x6013d298`), iterates `count` times via `bcm__6008cb7c` and `0x600ea72a` (`EVP_DigestFinal_ex`), derives required key and IV bytes, cleanses intermediate buffer via `0x6013cfb0` (`OPENSSL_cleanse`), cleans context via `0x6013d020` (`EVP_MD_CTX_cleanup`), and returns key length. Called by `pem_lib__60085f2c`. | 1 caller / 6 callees |

**⚠️ QA session 107 note:** 21 of the 22 functions above were independently re-verified against raw disassembly (not just the decompiled pseudocode) and confirmed correct — including two functions (`crypto_cbb_add_utf8`/`0x600ed794` and, by extension, its sibling `cbb_add_ucs2_be`/`cbb_add_utf32_be`) whose Ghidra-rendered pseudocode looked alarming out of context (a `bool`-returning callee, `0x600ed656`, treated as if it returned a 40–56-bit value with huge comparison thresholds); disassembling `0x600ed794` byte-for-byte confirmed this is a benign decompiler type-inference artifact around the boolean call result — the real machine code is a clean, textbook 1/2/3/4-byte UTF-8 encoder with correct overlong-sequence rejection, matching the claim exactly. `crypto_evp_bytes_to_key`/`0x600ed880` (310B, the wave's largest) was traced statement-by-statement against real OpenSSL `EVP_BytesToKey` (the `addmd`/count-loop/digest-init-update-final/key-then-IV-split/cleanse structure) and matches precisely. **One correction**: `crypto_cbs_is_valid_code_point`/`0x600ed656`'s claimed size (28B) and caller count (4) were both wrong — see the corrected row above; this is a pre-existing census boundary bug first surfaced by this session finally decompiling the address, not something this wave introduced. `GHIDRA-TODO: resize 0x600ed656 to 24 bytes (real end 0x600ed66e, confirmed via disassembly) and regenerate its caller list (should include 0x600ed840 and 0x600ed866); the orphaned 4-byte shared-tail block at 0x600ed67e-0x600ed682 doesn't need its own function boundary (it's a pure internal-branch target, never called), but note it if the boundary-fix tooling flags it as a gap.`

## Session 108 (Wave 78) — OpenSSL / BoringSSL LHASH Engine, EC Point Serialization & X.509 Name Helpers (24 functions, 800 bytes)

Decompiled and documented 24 functions (800 bytes across `0x600ed9b6`–`0x600edcd6`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ed9b6` |   74 | Crypto / ASN1 | **`crypto_asn1_object_size`** — Calculates DER length/header byte count and total encoded size for public key / ASN.1 object via `0x600e7474`. | 0 callers / 1 callee |
| `0x600eda00` |   28 | Crypto / CBS | **`crypto_cbs_get_asn1_bignum`** — BoringSSL internal `cbs_get_asn1_bignum`: allocates new `BIGNUM` via `0x6008b384` (`BN_new`), parses unsigned integer from CBS via `0x60090dd8` (`bn_asn1__60090dd8`). | 1 caller / 2 callees |
| `0x600eda1c` |   72 | Crypto / CBS | **`crypto_cbs_mem_equal_ignore_leading_zeros`** — Compares CBS buffer against a raw byte buffer, skipping leading zero bytes in both inputs before constant-time comparison via `0x600ed3a0` (`CBS_mem_equal`). | 1 caller / 4 callees |
| `0x600eda64` |   56 | Crypto / CBS | **`crypto_cbs_is_valid_der_uint`** — Validates that a CBS slice contains a valid positive DER integer (non-negative sign bit in byte 0, and no redundant zero padding if length > 1). | 1 caller / 2 callees |
| `0x600eda9c` |   86 | Crypto / CBB | **`crypto_cbb_add_asn1_ec_point`** — BoringSSL `CBB_add_asn1_ec_point`: queries required point encoding size via `0x6008d5e0` (`EC_POINT_point2oct`), reserves space via `0x600ed10a` (`CBB_add_space`), and serializes point octets. | 2 callers / 2 callees |
| `0x600edaf2` |    4 | Crypto / LHASH | **`crypto_lh_num_items`** — BoringSSL `lh_num_items`: returns `lh->num_items` (`return *lh`). | 0 callers / 0 callees |
| `0x600edaf6` |    4 | Crypto / LHASH | ~~**`crypto_lh_num_buckets`** — BoringSSL internal `lh_num_buckets`: returns `lh->num_buckets` (`return *(lh + 4)`).~~ ⚠️ **misidentified, corrected QA session 108** — disassembly-confirmed body (`ldr r0,[r0,#4]; bx lr`) is correct as pure behavior, but `crypto_lh_rehash` (`0x600edb6e`) and `crypto_lh_find` (`0x600edb2a`), both decompiled this same wave, unambiguously and doubly confirm offset+4 is the **bucket array pointer** (read/written as a base pointer indexed by `iVar*4`) and offset+8 (`param_1[2]`) is the real `num_buckets` (used as a loop bound in `lh_rehash` and as the modulus in `lh_find`'s `hash % num_buckets`, and written with the literal new-bucket-count argument on resize). Real behavior: `lh->buckets` (the bucket array pointer accessor), not `num_buckets`. | 0 callers / 0 callees |
| `0x600edafa` |    2 | Crypto / LHASH | **`crypto_lh_noop_stub_1`** — Trivial return stub (`bx lr`). | 0 callers / 0 callees |
| `0x600edafc` |    2 | Crypto / LHASH | **`crypto_lh_noop_stub_2`** — Trivial return stub (`bx lr`). | 0 callers / 0 callees |
| `0x600edafe` |   38 | Crypto / Stack | ~~**`crypto_lh_get_item_at_index`** — Retrieves item from internal stack/list at index `param_2`, bounds-checking against `0x600e0ab2` count and calling `0x600e0ab8`.~~ ⚠️ **misidentified, corrected QA session 108** — has nothing to do with LHASH; `0x600e0ab2`/`0x600e0ab8` are already independently established (well before this session) as `crypto_stack_num_elements`/`crypto_stack_value_at_index` (`OPENSSL_sk_num`/`OPENSSL_sk_value`), and disassembly confirms this function dereferences `param_1` once (a pointer-to-stack-pointer), bounds-checks the index against `sk_num`, then genuinely tail-calls (`b.w`, not `bl`) `sk_value` with exactly 2 real arguments — structurally identical to the already-corrected `crypto_stack_sort_and_find`→"bounds-checked indexed getter" finding on `0x600e0ce4` (session 90). This is a second instance of that same generic bounds-checked `OPENSSL_sk` indexed getter, not an LHASH primitive; its sole caller (`ex_data__600919d4`) suggests it more plausibly serves the `ex_data.c` extra-data-slot subsystem. | 1 caller / 2 callees |
| `0x600edb24` |    6 | Crypto / LHASH | **`crypto_lh_clear_items`** — Zeroes item count field `*param_1 = 0`. | 1 caller / 0 callees |
| `0x600edb2a` |   68 | Crypto / LHASH | **`crypto_lh_find`** — BoringSSL `lh_find` / `get_node`: hashes input data via `(*hash_fn)(arg, data)`, computes bucket index modulo `num_buckets`, walks linked list matching nodes via `(*cmp_fn)(arg, node->data, data)`, and returns pointer to node pointer. | 2 callers / 0 callees |
| `0x600edb6e` |   90 | Crypto / LHASH | **`crypto_lh_rehash`** — BoringSSL internal `lh_rehash`: allocates new bucket array of size `new_num_buckets * 4` via `0x600e092c`, zeroes memory via `0x6013cf90`, re-indexes and chains all existing nodes into new buckets, frees old bucket array via `0x6013d208`, and updates hash table descriptors. Defined function boundary in `FixSpuriousSplits.java` and `bruce_functions.csv`. | 1 caller / 3 callees |
| `0x600edbc8` |   44 | Crypto / LHASH | **`crypto_lh_rehash_check`** — BoringSSL internal `lh_rehash_check`: load factor monitor; triggers bucket doubling if `num_items / num_buckets >= 3`, or halving if empty and `num_buckets > 16`, invoking `0x600edb6e` (`lh_rehash`). Resized from 134B to 44B in `FixSpuriousSplits.java` and `bruce_functions.csv`. | 1 caller / 1 callee |
| `0x600edbf4` |   26 | Crypto / LHASH | **`crypto_lh_retrieve`** — BoringSSL `lh_retrieve`: invokes `0x600edb2a` (`get_node`), dereferences found node and returns payload data pointer (or NULL if absent). | 2 callers / 1 callee |
| `0x600edc0e` |   54 | Crypto / LHASH | **`crypto_lh_delete`** — BoringSSL `lh_delete`: invokes `0x600edb2a` (`get_node`), unlinks matching node from bucket list, frees node via `0x6013d208`, decrements `num_items`, triggers rehash check via `0x600edbc8`, and returns deleted data pointer. | 1 caller / 3 callees |
| `0x600edc44` |    8 | Crypto / LHASH | **`crypto_lh_call_hash_thunk`** — Indirect call trampoline for hash function callback: jumps to `(*hash_fn)(arg1, arg2)`. Defined function boundary in `FixSpuriousSplits.java` and `bruce_functions.csv`. | 0 callers / 0 callees |
| `0x600edc4c` |    6 | Crypto / LHASH | **`crypto_lh_call_cmp_thunk`** — Indirect call trampoline for comparison function callback: jumps to `(*cmp_fn)(arg1)`. Defined function boundary in `FixSpuriousSplits.java` and `bruce_functions.csv`. | 0 callers / 0 callees |
| `0x600edc52` |   22 | Crypto / X509 | **`crypto_x509_name_entry_cmp`** — OpenSSL `X509_NAME_ENTRY_cmp`: compares length field at offset `+0xc`; if equal and nonzero, compares payload string bytes via `0x6013d168` (`memcmp`). | 1 caller / 1 callee |
| `0x600edc68` |   12 | Crypto / X509 | **`crypto_x509_name_get_entry_type`** — Looks up object identifier / type descriptor via `0x60091c10` (`obj__60091c10`), returns type word `*puVar1`. | 1 caller / 1 callee |
| `0x600edc74` |   12 | Crypto / X509 | **`crypto_x509_name_get_entry_value`** — Looks up object identifier / type descriptor via `0x60091c10` (`obj__60091c10`), returns value word `puVar1[1]`. | 0 callers / 1 callee |
| `0x600edc80` |    8 | Crypto / X509 | **`crypto_x509_name_find_entry_fallback`** — Error fallback trampoline returning -1: tail-calls `func_0x60091d08(-1)`. Defined function boundary in `FixSpuriousSplits.java` and `bruce_functions.csv`. | 0 callers / 0 callees |
| `0x600edc88` |   20 | Crypto / X509 | **`crypto_x509_name_encode_entry`** — Trampoline setting up entry encoding stack frame and calling `0x60091ddc`. | 1 caller / 1 callee |
| `0x600edc9c` |   58 | Crypto / X509 | **`crypto_x509_name_entry_memcmp`** — Checks tag type `param_1 == 3`, validates string length via `0x6004cb28` (`strlen`), compares payload bytes via `0x6013d168` (`memcmp`), returns true if match. | 1 caller / 2 callees |

**⚠️ QA session 108 note:** the Session 107 `GHIDRA-TODO` is confirmed fully resolved — `0x600ed656` is now genuinely 24 bytes with all 6 real callers listed (verified against the committed `.c` file and census). Backbone clean across all 24 new functions (800 bytes, no overlaps, perfectly contiguous `0x600ed9b6`–`0x600edcd6`). The EC point serializer (`crypto_cbb_add_asn1_ec_point`, `0x600eda9c`) and the DER-integer validator (`crypto_cbs_is_valid_der_uint`, `0x600eda64`) were traced in full and are precise, textbook matches to real BoringSSL (`CBB_add_asn1_ec_point`'s query-size/reserve/serialize/verify-length pattern; the DER-integer sign+minimal-encoding bit arithmetic). `crypto_cbs_mem_equal_ignore_leading_zeros` (`0x600eda1c`) was disassembled to resolve an apparent discarded-return-value question (Ghidra declares it `void`): the final instruction is a genuine `bl #0x600ed3a0` immediately followed by `pop {..,pc}` with r0 untouched, confirming the comparison result *is* propagated to the caller — the `void` signature is a benign decompiler type-inference gap, not evidence of dropped output. **Two corrections**, both in the LHASH cluster, both confirmed at the disassembly level and both by cross-referencing this same wave's own other functions rather than fresh speculation — see the struck-through rows above: `crypto_lh_num_buckets` (`0x600edaf6`) actually returns the bucket-array *pointer* (offset+4), not `num_buckets` (which `crypto_lh_rehash`/`crypto_lh_find` — decompiled in this same wave — unambiguously place at offset+8); and `crypto_lh_get_item_at_index` (`0x600edafe`) isn't LHASH at all — it's another instance of the already-established generic bounds-checked `OPENSSL_sk` indexed getter (`0x600e0ab2`/`0x600e0ab8`, the same shape session 90 corrected for `0x600e0ce4`), most likely serving `ex_data.c`. No `GHIDRA-TODO` needed for either — both are identification-only fixes, not boundary issues. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,074 committed decomp files (467,496 bytes, 0 duplicates, 0 mismatches vs. census) — matches the doc's claimed 65.42% exactly. **Reliability read**: a genuinely strong, cross-corroborated wave — the two LHASH cluster fields recur across three independently-decompiled functions each, and both fresh findings surfaced from noticing an internal contradiction between this wave's own rows rather than needing any external reference, the same high-value check that has repeatedly paid off in this doc's history (sessions 73, 83, 90, 91, 92, 93, 103, 106).

## Session 109 (Wave 79) — JSMN JSON Parser, RTOS Mutex / Event Loop & HCI Transport Primitives (18 functions, 1,442 bytes)

Decompiled and documented 18 functions (1,442 bytes across `0x600edcd6`–`0x600ee278`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600edcd6` |  758 | JSON / Parser | **`crypto_jsmn_parse`** — JSMN lightweight JSON tokenizer/parser: scans JSON string `param_2` (length `param_3`), matches object delimiters (`{`, `}`), array delimiters (`[`, `]`), strings (`"` with `\` escape parsing), primitives/numbers/booleans, key-value separators (`:`), and comma separators (`,`), populating 16-byte `jsmntok_t` token structs at `param_4`, returning token count or negative error code. | 1 caller / 0 callees |
| `0x600edfcc` |   14 | JSON / Parser | **`crypto_jsmn_init`** — JSMN parser initializer: initializes `jsmn_parser` fields (`pos = 0`, `toknext = 0`, `toksuper = -1`). | 1 caller / 0 callees |
| `0x600edfda` |    4 | Crypto / CRC | **`thunk_crc32_calc`** — Trampoline thunk to `0x600921b8` (Broadcom IEEE 802.3 CRC32 calculation engine with slicing-by-8 optimization). | 1 caller / 0 callees |
| `0x600edfde` |   32 | OS / Sync | **`os_mutex_create`** — Dynamically allocates 8-byte mutex/sync structure via `0x6013d038` (`malloc`), zero-initializes with memory barrier (`dmb ish`), and returns handle in `*param_1` (or `ENOMEM` / 12 on failure). | 1 caller / 1 callee |
| `0x600edffe` |   30 | OS / Sync | **`os_cond_wait_infinite`** — Acquires mutex via `0x6013d328` (`pthread_mutex_lock`), if successful tail-calls `0x6013d0c8` (`pthread_cond_timedwait` with infinite timeout `0xffffffff`). Resized from 34B to 30B in `FixSpuriousSplits.java` and `bruce_functions.csv`. | 1 caller / 2 callees |
| `0x600ee01c` |   60 | OS / Event | **`os_event_queue_drain_work_items`** — Locks queue mutex `0x6013d2d0`, drains singly-linked list of pending work nodes at `param_1 + 0x2c`, invokes work callback `(**(code**)node[2])()`, unlinks doubly-linked tracking list, frees node via `0x6013cff0`, and unlocks mutex via `0x6013d0e0`. | 1 caller / 3 callees |
| `0x600ee058` |   10 | OS / Event | **`os_event_callback_invoke`** — Indirect call trampoline: if `param_2 != 0`, invokes function pointer `*param_1` with context argument `param_1[1]`. | 1 caller / 0 callees |
| `0x600ee062` |   86 | OS / Event | **`os_event_dispatcher_worker`** — Event loop processing cycle: locks mutex `0x6013d2d0`, checks termination flag `+0x1c`, dispatches timer list at `*param_1` via `0x600ca5cc`, drains callbacks at `+0x28` via `0x600ee058`, drains work items via `0x600ee01c`, signals completion or frees queue via `0x600ca27c`/`0x6013cff0`, and unlocks mutex. | 0 callers / 8 callees |
| `0x600ee0b8` |    4 | OS / Event | **`os_event_noop_stub`** — Trivial return 0 stub (`movs r0, #0; bx lr`). | 0 callers / 0 callees |
| `0x600ee0bc` |   12 | OS / Transport | **`os_channel_set_priority`** — Validates priority `param_2 < 3`; if valid sets `*(param_1 + 4) = param_2` and returns 0, else returns `0x16` (`EINVAL`). | 0 callers / 0 callees |
| `0x600ee0c8` |   56 | OS / Sync | **`os_event_handle_release`** — Atomic event handle release: uses `ldrex/strex` loop to swap `*param_1` with 0; if previous handle was valid, destroys event condition variable via `0x6013d0f0` and frees handle memory via `0x6013cff0`. | 2 callers / 2 callees |
| `0x600ee100` |   22 | BT / Transport | **`bt_transport_init_wrapper`** — Calls `0x6013d0a8` and tail-calls transport initialization routine `0x60092528`. | 1 caller / 2 callees |
| `0x600ee116` |   22 | BT / Transport | **`bt_transport_setup_tx_buffer`** — Calls `0x60092594` and configures 300-byte TX packet buffer pool via `0x6013d068(param_1, 300)`. | 0 callers / 2 callees |
| `0x600ee12c` |   22 | BT / Transport | **`bt_transport_setup_rx_buffer`** — Calls `0x600925a8` and configures 2560-byte RX ACL packet buffer pool via `0x6013d068(param_1, 2560)`. | 0 callers / 2 callees |
| `0x600ee142` |   72 | OS / Queue | **`async_work_queue_thread_loop`** — Async worker thread loop: blocks receiving work message from OS queue `*(param_1 + 0xb0)` via `0x6013d268`, dispatches work callback, handles synchronous completion signaling via mutex lock `0x601017fc`, status write at `+0x60`, memory barriers, and cond signal `0x60101832`. | 0 callers / 3 callees |
| `0x600ee18a` |   52 | OS / Queue | **`async_work_queue_post`** — Posts work request `param_2` with memory barrier to OS message queue `*(param_1 + 0xb0)` via `0x6013d0e8` (`os_queue_send`). | 1 caller / 1 callee |
| `0x600ee1be` |   64 | Device / Dispatch | **`device_type_dispatcher`** — Checks device/packet type: if `type == 1` calls `0x60098668(arg)`, if `type == 2` calls `0x600eff9c(arg)`, returns 1 on success, 0 on unknown type. | 1 caller / 2 callees |
| `0x600ee1fe` |  122 | Device / Dispatch | **`device_packet_handler`** — Inspects packet identifier `param_1`: if `param_1 == 6` calls `0x600eff14(param_2, ...)`, otherwise dispatches to `0x600985f8(param_2, ...)`. | 1 caller / 2 callees |

## Session 110 (Wave 80) — Broadcom BTM Lock Wrappers & BTA GATT Client/Server Service Builders (13 functions, 1,572 bytes)

Decompiled and documented 13 functions (1,572 bytes across `0x600ee278`–`0x600ee89c`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ee278` |   32 | BTM / Status | **`btm_is_device_up_locked`** — Broadcom BTM `BTM_IsDeviceUp` wrapper: acquires BTM mutex via `0x600d9378`, queries device status via `0x600a01a0` (`BTM_IsDeviceUp`), and releases mutex via `0x600d937c`. | 2 callers / 3 callees |
| `0x600ee298` |   80 | BTA / DM | **`bta_dm_remove_device_if_idle_locked`** — Broadcom BTA Device Manager helper: acquires mutex via `0x600d9378`, checks if device profile connections 1 and 2 are inactive via `0x600f045e`; if idle, purges device record via `0x600f16ae`, releases mutex, and returns true. | 1 caller / 4 callees |
| `0x600ee2e8` |   14 | BTA / DM Search | ~~**`bta_gattc_app_register_app1`** — Broadcom BTA GATT Client: calls `0x60096290(1)` (`BTA_GATTC_AppRegister` for client application ID 1).~~ ⚠️ **misidentified, corrected QA session 110** — `0x60096290` is already independently established in `bruce-bta-stack.md` as `bta_dm_search_set_state_flag` ("clears search state flag at `DAT_600962b4 + 200 + param_1`"), a BTA DM Search primitive with no connection to GATT client app registration. Real behavior: a thin wrapper clearing DM-search state flag slot 1. | 0 callers / 1 callee |
| `0x600ee2f6` |   14 | BTA / DM Search | ~~**`bta_gattc_app_register_app2`** — Broadcom BTA GATT Client: calls `0x60096290(2)` (`BTA_GATTC_AppRegister` for client application ID 2).~~ ⚠️ **misidentified, corrected QA session 110** — same finding as `0x600ee2e8` above; clears DM-search state flag slot 2, not GATTC app registration. | 0 callers / 1 callee |
| `0x600ee304` |   58 | BTA / DM PM (likely) | ~~**`bta_gattc_map_status_to_event`** — Converts transport status flags (`0x4` -> 2, `0x10` -> 1, `& 0x20` -> 0, default -> 3) to internal GATTC event codes.~~ ⚠️ **subsystem likely misidentified, QA session 110** — this function's own two callers, `0x6009362c` and `0x600936d4`, are both already established in `bruce-bta-stack.md` as BTA DM Power Management code (a find-and-deactivate table search, and a PM-state-persistence-shaped helper, respectively), not GATTC — strongly suggesting this mapper converts an HCI power-mode-change status byte into an internal BTA DM PM sub-state code, not a "GATTC event." The mechanical mapping itself (`4→2, 0x10→1, &0x20→3, else→0`) is accurate; only the "GATTC" subsystem label is in doubt. Real identity left unconfirmed rather than guessed. | 2 callers / 0 callees |
| `0x600ee33e` |  250 | BTA / DM PM (likely) | ~~**`bta_gattc_conn_state_machine_update`** — Updates GATT client connection control block (`0x600944c0` / `bta_gattc_find_clcb`), setting encryption/auth bits at `+0xb`, `+0x18`, `+0x19`, and dispatching callbacks `0x6009362c`, `0x600936d4`, `0x60093d20`.~~ ⚠️ **subsystem likely misidentified, QA session 110** — all three named callees are already independently established in `bruce-bta-stack.md` as BTA DM Power Management code (`0x6009362c`: 3-slot table search + deactivate; `0x600936d4`: PM-state-persistence-shaped; `0x60093d20`: "PM state handler, park/sniff mode negotiation") — none confirmed GATTC. `0x600944c0` itself is only established as a generic linear-search-table-walker (its own earlier "PM negotiate mode" claim was separately QA-corrected away), not confirmed GATTC either. The function's own 3-bit field manipulation at `+0xb` (clear bits 0-2, then set bit 1 or bit 2 depending on a flag) fits a power/link-mode sub-state encoding (active/sniff/park-style) far better than a GATT connection-state machine, which real BTA/GATTC code represents with a richer enum. Real identity/subsystem left unconfirmed; "connection state machine" and "encryption/auth bits" framing not supported by any independent evidence. | 0 callers / 4 callees |
| `0x600ee438` |   34 | BTA / DM PM (likely) | ~~**`bta_gattc_dispatch_error_event`** — Dispatches error status callback via `0x60093d20(param_1 + 8, status, 3)`.~~ ⚠️ **subsystem likely misidentified, QA session 110** — its sole callee, `0x60093d20`, is already established in `bruce-bta-stack.md` as the BTA DM Power Management state handler (park/sniff mode negotiation), not a GATTC callback dispatcher. Very likely a thin BTA DM PM helper (invokes the PM state handler with a fixed reason code `3`), not a "GATTC error event." | 0 callers / 1 callee |
| `0x600ee45a` |  110 | BTA / GATTC | **`bta_gattc_count_matching_services`** — Iterates service array `*(param_1 + 0x28)` of count `*(param_1 + 0x2f)`, matches 16/128-bit UUIDs via `0x600ef2da`, and returns matching service count. | 1 caller / 1 callee |
| `0x600ee4c8` |   90 | BTA / GATTC | **`bta_gattc_count_primary_services`** — Walks primary services linked list at `*(param_1 + 0x1c)`, extracts UUIDs via `0x600ef4ae`, compares via `0x600ef2da`, and returns count. | 1 caller / 2 callees |
| `0x600ee522` |   88 | BTA / GATTC | **`bta_gattc_count_secondary_services`** — Walks secondary services linked list at `*(param_1 + 4)`, extracts UUIDs via `0x600ef4ae`, compares via `0x600ef2da`, and returns count. | 1 caller / 2 callees |
| `0x600ee57a` |  254 | BTA / GATTC | **`bta_gattc_add_char_descriptor`** — Constructs 48-byte (`0x30`) characteristic descriptor structure: validates/expands buffer via `0x60094754`, writes start/end handles, properties, 20-byte UUID via `0x6013d3a0` (`memcpy`), 4-byte aligns write pointer, and links into descriptor chain. | 2 callers / 2 callees |
| `0x600ee678` |  434 | BTA / GATTC | **`bta_gattc_add_service_element`** — Constructs GATT service attribute record (`uuid_len + 0x10` bytes): validates buffer capacity via `0x60094754`, stores handle and type flags, formats 16-bit (little-endian) or 128-bit (`memcpy`) UUID, links into primary/secondary list via `0x600ee4c8`/`0x600ee522`, and chains into GATT service database. | 4 callers / 4 callees |
| `0x600ee82a` |  114 | BTA / GATTC | **`bta_gattc_get_service_handle_range`** — Extracts 16-bit start and end attribute handles from indexed GATT service descriptor at `*(param_1 + 0x28) + index * 28`. | 1 caller / 0 callees |

**⚠️ QA session 110 note:** this wave's subsystem attribution splits cleanly into two halves that turn out to be wrong and right, respectively — caught entirely by cross-referencing this wave's own callees against already-established `bruce-bta-stack.md` entries, no fresh disassembly needed. **Correct (6 of 13, the GATT service-database-builder cluster)**: `bta_gattc_count_matching_services`/`_primary_services`/`_secondary_services` and `bta_gattc_add_char_descriptor`/`add_service_element`/`get_service_handle_range` are all strongly, multiply cross-validated as genuine BTA GATTC — `0x60094754` (called by `add_char_descriptor`/`add_service_element`) is already independently named `bta_gattc_alloc_cache_buf`; `0x60094c5c` (already named `bta_gattc_rebuild_cache`) is a direct, confirmed caller of both `add_char_descriptor` and `add_service_element`, exactly the relationship you'd expect from a cache-rebuild routine reconstructing the service database; and `0x60094a3c`'s own pre-existing doc entry already flagged, before this session, that its callees sit in "the unrelated `0x600eexxx` range (decompile-status run #3)" — precisely this wave's address range, closing the loop from a third independent direction. `btm_is_device_up_locked` (`0x600ee278`) is also confirmed correct: its callee `0x600a01a0` is the long-established, heavily-scrutinized `BTM_IsDeviceUp` (`btm_cb+0x881` state field, confirmed since session 31), and the two ITCM thunks it wraps (`0x600d9378`/`0x600d937c`) are the equally long-established `portENTER_CRITICAL`/`portEXIT_CRITICAL` pair. `bta_dm_remove_device_if_idle_locked` (`0x600ee298`) is internally consistent but its callees are undecompiled elsewhere, so it's accepted without independent cross-validation either way. **Wrong (5 of 13, the middle "GATTC event/state" cluster)**: see the struck-through corrections above — `0x600ee2e8`/`0x600ee2f6` (claimed `BTA_GATTC_AppRegister`) definitively call `0x60096290`, already established as the unrelated `bta_dm_search_set_state_flag`; and `0x600ee304`/`0x600ee33e`/`0x600ee438` (claimed GATTC status-mapping/connection-state-machine/error-dispatch) all call functions already established as BTA DM Power Management code (park/sniff mode negotiation, a 3-slot PM table search-and-deactivate, and a PM-persistence helper) — none confirmed GATTC. Corrected in place with appropriately hedged real-subsystem labels (`BTA / DM Search`, `BTA / DM PM (likely)`) rather than guessed replacement names, since only the *subsystem* is well-evidenced here, not a specific confirmed replacement identity for each function. No `GHIDRA-TODO` needed (identification-only, no boundary issues). Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,104 committed decomp files (470,458 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 65.84% exactly. **Reliability read**: the largest correction count since session 106 (5 of 13 rows), and a useful reminder that thematic proximity (this whole cluster sits between two genuinely-GATTC address ranges) is not evidence on its own — the wave's initial pass appears to have extended the surrounding "GATTC" theme across the entire address range rather than checking each function's own actual callees against the doc's existing, already-verified citations, exactly the failure mode this project's history keeps finding to be the single highest-value check available.

## Session 111 (Wave 81) — Broadcom BTA GATTC Service Discovery Engine & Cache Builder (12 functions, 1,362 bytes)

Decompiled and documented 12 functions (1,362 bytes across `0x600ee89c`–`0x600eedee`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ee89c` |   86 | BTA / GATTC | **`bta_gattc_search_service_dispatcher`** — Service discovery dispatcher: queries a lookup helper via `0x6009506c` ⚠️ *(name unconfirmed, QA session 111 — this address is already independently established in `bruce-bta-stack.md` as a generic, QA-corrected "single-key linear search, 6-entry table" with 9 callers spanning what was originally, and wrongly, assumed to be an entire BTM-Power-Management-specific cluster; the specific name `bta_gattc_find_srvc_cache` asserted here is unconfirmed and not supported by that entry — this wave's *use* of it to look up a GATTC state field is plausible and unproblematic, but the function itself may well be a shared utility, not GATTC-owned)*; if discovery active (`state == 2`) delegates to `0x600ee8f2`, else calls `0x6009496c` (already independently established as `bta_gattc_sdp_service_disc`, confirming the SDP-vs-GATT discovery dispatch shape). | 1 caller / 3 callees |
| `0x600ee8f2` |  136 | BTA / GATTC | **`bta_gattc_send_discovery_request`** — Formats 24-byte discovery request structure, sets handle ranges (`1..0xffff` for service discovery, or queries range via `0x600ee82a` for included/characteristic/descriptor discovery), and calls `0x600f39fc` (`GATT_Discover`). | 4 callers / 3 callees |
| `0x600ee97a` |   34 | BTA / GATTC | **`bta_gattc_discover_inc_services`** — Dispatches included services discovery request via `0x600ee8f2(conn_id, cache, 3)` (`GATT_DISC_INC_SRVC`). | 1 caller / 1 callee |
| `0x600ee99c` |   42 | BTA / GATTC | **`bta_gattc_discover_characteristics`** — Clears characteristic count `cache[0x30] = 0` and calls `0x600ee8f2(conn_id, cache, 4)` (`GATT_DISC_CHAR`). | 1 caller / 1 callee |
| `0x600ee9c6` |   48 | BTA / GATTC | **`bta_gattc_discover_char_descriptors`** — Calls `0x600ee8f2(conn_id, cache, 5)` (`GATT_DISC_CHAR_DSCPT`); if discovery returns non-zero error or complete, advances via `0x600eeb42`. | 2 callers / 2 callees |
| `0x600ee9f6` |  176 | BTA / GATTC | **`bta_gattc_explore_service_step`** — Service exploration state progression: adds characteristic descriptor via `0x600ee57a`, chains into included services search `0x600ee97a`; when all services explored, transitions state and posts `BTA_GATTC_DISC_COMP_EVT` (`0x1d13`) via `0x600d9198`. | 4 callers / 4 callees |
| `0x600eeaa6` |   42 | BTA / GATTC | **`bta_gattc_start_char_discovery`** — Advances discovery index `cache[0x2d] = cache[0x2f]` and triggers characteristic discovery via `0x600ee99c`. | 1 caller / 1 callee |
| `0x600eead0` |  114 | BTA / GATTC | **`bta_gattc_process_char_disc_response`** — Characteristic discovery response handler: if no descriptors (`cache[0x30] == 0`) advances to next service via `0x600ee9f6`, otherwise adds service element via `0x600ee678` and initiates descriptor search via `0x600ee9c6`. | 1 caller / 3 callees |
| `0x600eeb42` |  150 | BTA / GATTC | **`bta_gattc_process_descriptor_disc_response`** — Descriptor discovery response handler: decrements descriptor counter `cache[0x30]--`; if done advances service index and calls `0x600ee9f6`, else advances descriptor index `cache[0x2d]++`, adds element via `0x600ee678`, and continues descriptor search via `0x600ee9c6`. | 2 callers / 3 callees |
| `0x600eebd8` |  130 | BTA / GATTC | **`bta_gattc_is_handle_in_service_table`** — Checks if handle range `[param_2, param_3]` matches or collides with any registered service in cache table `*(param_1 + 0x28)`. | 1 caller / 0 callees |
| `0x600eec5a` |  192 | BTA / GATTC | **`bta_gattc_add_service_to_cache`** — Adds discovered primary/secondary service to 30-slot cache table: stores start/end handles, service type, calculates duplicate count via `0x600ee45a`, and copies 20-byte UUID via `memcpy` (`0x6013d3a0`). | 2 callers / 2 callees |
| `0x600eed1a` |  212 | BTA / GATTC | **`bta_gattc_add_char_to_cache`** — Adds discovered characteristic to cache table: stores handle, properties, 20-byte UUID, and fixes up preceding characteristic's end handle when multiple characteristics are present in a service. | 1 caller / 1 callee |

**⚠️ QA session 111 note:** this wave picks up exactly where session 110's *confirmed-correct* half left off, and the cross-validation compounds nicely as a result. Every one of this wave's own functions either calls directly into, or is called by, session 110's independently-confirmed GATTC cluster: `0x600ee9f6` calls the confirmed `bta_gattc_add_char_descriptor` (`0x600ee57a`); `0x600eead0`/`0x600eeb42` both call the confirmed `bta_gattc_add_service_element` (`0x600ee678`); `0x600ee8f2` calls the confirmed `bta_gattc_get_service_handle_range` (`0x600ee82a`); `0x600eec5a` calls the confirmed `bta_gattc_count_matching_services` (`0x600ee45a`). A fresh, independent name-check landed one more genuine confirmation: `0x600ee89c`'s callee `0x6009496c` is already independently established in `bruce-bta-stack.md` as `bta_gattc_sdp_service_disc`, exactly matching this function's own SDP-vs-GATT discovery dispatch shape. The whole cluster also shares one consistent struct layout (base at `param_1+0x28`, count at `+0x2e`/`+0x2f`, 28-byte (`0x1c`) stride, start/end handle fields at `+0x14`/`+0x16`) with session 110's confirmed functions, reinforcing that this is genuinely the same GATT service/characteristic cache table throughout. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,116 committed decomp files (471,820 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 66.03% exactly. **One soft finding**: `0x600ee89c`'s row asserted the specific name `bta_gattc_find_srvc_cache` for its callee `0x6009506c` — but that address is already independently established as a generic, QA-corrected "single-key linear search, 6-entry table" with 9 callers, part of a whole cluster of addresses originally (and, per that same prior QA pass, wrongly) assumed to be BTM-Power-Management-specific write/configure functions that turned out to all be generic read-only search helpers. A specific GATTC-exclusive name isn't supported by that entry or by the caller count; flagged in place as unconfirmed rather than struck through, since the wave's actual *use* of the function (look up a state field, branch on it) is unproblematic regardless of who else calls it. **Reliability read**: the strongest kind of confirmation this pipeline produces — not a single spec-primitive match, but an entire 12-function wave whose own call graph repeatedly, independently threads back into a cluster the *previous* session's QA had already verified byte-by-byte, with zero contradictions found this time.

## Session 112 (Wave 82) — Broadcom BTA GATTC Service Database Query & Connection Control Block Lifecycle (11 functions, 1,826 bytes)

Decompiled and documented 11 functions (1,826 bytes across `0x600eedee`–`0x600ef510`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600eedee` |  280 | BTA / GATTC | **`bta_gattc_find_char_handle_by_uuid`** — Characteristic handle lookup: searches service database at `param_1 + 0xc`, matching service UUID via `0x600ef546` and attribute/descriptor UUIDs via `0x600ef2da` (`bta_gattc_uuid_compare`), returning the attribute handle (or 0 if not found). | 4 callers / 3 callees |
| `0x600eef06` |  244 | BTA / GATTC | **`bta_gattc_find_service_entry_by_handle`** — Attribute handle lookup: searches service database for handle `param_2`; copies 28-byte service record to `param_3` via `memcpy` (`0x6013d3a0`), and extracts characteristic and descriptor UUIDs via `0x600ef4ae`. | 4 callers / 3 callees |
| `0x600eeffa` |  162 | BTA / GATTC | **`bta_gattc_broadcast_service_changed`** — Broadcasts `BTA_GATTC_SRVC_CHG_EVT` (event 7): iterates service list at `*(param_1 + 0x10) + 0xc`, checks UUID match via `0x600ef2da`, formats 0x2b0-byte event structure, and dispatches to client callback `*(param_1 + 6)`. | 0 callers / 3 callees |
| `0x600ef09c` |   88 | BTA / GATTC | **`bta_gattc_format_service_cache_entry`** — Service cache entry formatter: writes start handle `+0x14`, end handle `+0x16`, type `+0x18`, property `+0x19`, instance ID `+0x1a`, flags `+0x1b`, and copies 20-byte UUID via `0x6013d3a0` (`memcpy`). | 1 caller / 1 callee |
| `0x600ef0f4` |  486 | BTA / GATTC | **`bta_gattc_notify_service_discovery_results`** — Discovery results paginator: batches up to 10 discovered service/characteristic entries per event via `0x600ef09c`, posts `BTA_GATTC_DISC_RES_EVT` (`0x1d15`) to BTA event queue via `0x600d9202`, updating pagination index at `+0x32`. | 2 callers / 3 callees |
| `0x600ef2da` |  182 | BTA / GATTC | **`bta_gattc_uuid_compare`** — UUID comparator: compares 16-bit values directly if both 16-bit; converts 16-bit to 128-bit Bluetooth Base UUID via `0x60094f14` if mixed; compares 16-byte payloads via `memcmp` (`0x6013d168`). | 8 callers / 2 callees |
| `0x600ef390` |   60 | BTA / GATTC | **`bta_gattc_find_or_alloc_clcb`** — Client control block accessor: queries existing block via `0x60094ffc` (`bta_gattc_find_clcb`), if not found allocates new block via `0x600950bc` (`bta_gattc_alloc_clcb`). | 2 callers / 2 callees |
| `0x600ef3cc` |  128 | BTA / GATTC | **`bta_gattc_free_clcb`** — Client control block release: decrements server cache and connection block reference counts, ~~cancels timer via `0x600aa648` (`bta_sys_stop_timer`)~~ ⚠️ **misidentified, corrected QA session 112** — `0x600aa648` is already independently established in `bruce-bta-stack.md`, unhedged, as `gatt_release_sr_cmd` ("Frees pending GATT server command buffer if active", 12 callers), not a BTA system timer primitive. Real behavior: releases any pending GATT server command buffer associated with the field at `+0x14` (plausible cleanup during control-block teardown, arguably more apt for a "free" routine than a timer cancel), and zero-clears 32-byte control block via `0x6013cf90` (`memset`). | 3 callers / 2 callees |
| `0x600ef44c` |   42 | BTA / GATTC | **`bta_gattc_get_clcb_from_conn_id`** — Control block getter: queries control block by connection ID via `0x6009506c` and returns `clcb->p_bta_gattc_cb` (`*(iVar1 + 0x10)`). | 3 callers / 1 callee |
| `0x600ef476` |   56 | BTA / GATTC | **`bta_gattc_register_notify_filter`** — Notification registration filter: registers notification filter callback at `*(param_1 + 0x14)` and sets registration flag bit 0 at `+0x18`. | 6 callers / 0 callees |
| `0x600ef4ae` |   98 | BTA / GATTC | **`bta_gattc_extract_uuid`** — Attribute UUID extractor: reads length from attribute element; formats 16-bit integer from little-endian bytes if length == 2, or copies 16 bytes via `memcpy` (`0x6013d3a0`) if 128-bit. | 4 callers / 2 callees |

**⚠️ QA session 112 note:** this wave decompiles two functions (`bta_gattc_uuid_compare`/`0x600ef2da`, `bta_gattc_extract_uuid`/`0x600ef4ae`) that sessions 110 and 111's *already-confirmed-correct* functions had been calling all along without either side being independently verified until now — and both hold up precisely, closing the loop from the other direction. `bta_gattc_extract_uuid`'s 20-byte output layout (type tag at offset 0, value at offset 4) exactly matches what `bta_gattc_uuid_compare` expects as input, and both exactly match the record layout `bta_gattc_add_service_to_cache` (session 111) writes — its `memcpy(record_base, &uuid_value, 0x14)` call writes a UUID structure starting at the record's *own* offset 0, with the start/end handle fields (`+0x14`/`+0x16`) immediately following the 20-byte UUID block, which is exactly the shape `bta_gattc_broadcast_service_changed` (this wave) relies on when it passes a raw service-record pointer directly as a "UUID" argument. `bta_gattc_uuid_compare`'s Base-UUID-conversion callee, `0x60094f14`, is a nice non-contradicting elaboration of an existing QA correction rather than a conflict: that address was previously corrected (independent of this session) from a claimed "read link policy" to "copies a fixed 16-byte template into param_1" — a bare template-copy description that didn't need to account for a second argument, since the correction was refuting a different claim; this wave's own call site (`FUN_60094f14(dest, uuid16)`) is fully consistent with that established finding while additionally showing the template gets a 16-bit value inserted into it, which is exactly Bluetooth SIG's real Base-UUID-expansion mechanism (`0000xxxx-0000-1000-8000-00805F9B34FB`) — the two findings compose rather than conflict. The GATT event-code sequence is also self-consistent: this wave's `0x1d15` (`BTA_GATTC_DISC_RES_EVT`) sits immediately after session 111's confirmed `0x1d13` (`BTA_GATTC_DISC_COMP_EVT`) in the same small enum space. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,127 committed decomp files (473,646 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 66.28% exactly. **One correction**: `bta_gattc_free_clcb`'s row asserted `0x600aa648` = `bta_sys_stop_timer`, but that address is already independently, unhedgedly established in `bruce-bta-stack.md` as `gatt_release_sr_cmd` ("frees pending GATT server command buffer if active", 12 callers) — a completely different operation (buffer release, not timer cancellation). Corrected in place. **Reliability read**: a genuinely productive wave for cross-validation — the two new UUID-handling primitives retroactively confirm two full prior sessions' worth of already-QA'd functions from the callee side, while the one miss (a specific, unhedged pre-existing identity not checked before being contradicted) is a reminder that even in a strongly self-consistent cluster, each individual callee citation still needs its own check against the doc's existing entries.

## Session 113 (Wave 83) — Broadcom BTA GATTC Service ID Comparators, Background Connection Management & Cache Teardown (12 functions, 1,312 bytes)

Decompiled and documented 12 functions (1,312 bytes across `0x600ef510`–`0x600efa30`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600ef510` |   54 | BTA / GATTC | **`bta_gattc_service_id_compare`** — Service ID comparator: compares service instance ID (`param_1[0x14] == param_2[0x14]`) and UUID via `0x600ef2da` (`bta_gattc_uuid_compare`). | 2 callers / 1 callee |
| `0x600ef546` |   54 | BTA / GATTC | **`bta_gattc_service_type_and_id_compare`** — Service type and ID comparator: compares service type byte (`param_1[0x18] == param_2[0x18]`) and delegates ID/UUID comparison to `0x600ef510`. | 2 callers / 1 callee |
| `0x600ef57c` |   66 | BTA / GATTC | **`bta_gattc_service_full_compare`** — Service record comparator: compares service handle range via `0x600ef510(param_1 + 0x1c, param_2 + 0x1c)` and service type/ID via `0x600ef546(param_1, param_2)`. | 1 caller / 2 callees |
| `0x600ef5be` |  138 | BTA / GATTC | **`bta_gattc_find_bg_conn_device`** — Background connection table search (4 entries, 60-byte stride): validates `in_use != 0`, compares BD_ADDR via `0x600efcfe` (`bdcmp`), and service record via `0x600ef57c`. | 1 caller / 2 callees |
| `0x600ef648` |  164 | BTA / GATTC | **`bta_gattc_clear_bg_conn_device`** — Background connection table entry clear: retrieves connection parameters via `0x600f3e00` (`bta_gattc_get_conn_info`), looks up server control block via `0x60094f58`, matches BD_ADDR via `0x600efcfe`, and zeroes 60-byte record via `0x6013cf90` (`memset`). | 1 caller / 4 callees |
| `0x600ef6ec` |  268 | BTA / GATTC | **`bta_gattc_parse_char_ext_prop_response`** — Characteristic extended properties response parser: checks UUID against `0x2905` (`GATT_UUID_CHAR_EXT_PROP`) via `0x600ef2da`; if matching, parses 16-bit handles and resolves service descriptors via `0x600eef06` (`bta_gattc_find_service_entry_by_handle`). | 1 caller / 2 callees |
| `0x600ef7f8` |  168 | BTA / GATTC | **`bta_gattc_send_open_close_cback`** — Formats 0x2b0-byte BTA event structure with status, conn_id, and BD_ADDR copy via `0x600efcc6` (`bdcpy`), executing client callback with event 2 (`BTA_GATTC_OPEN_EVT` / `BTA_GATTC_CLOSE_EVT`). | 5 callers / 2 callees |
| `0x600ef8a0` |   40 | BTA / GATTC | **`bta_gattc_find_or_create_srvc_cache`** — Server cache accessor: searches server cache by BD_ADDR via `0x60095588`, if not found allocates new cache via `0x60095534`. | 1 caller / 2 callees |
| `0x600ef8c8` |   56 | BTA / GATTC | **`bta_gattc_clear_srvc_cache`** — Server cache clear: searches server cache by BD_ADDR via `0x60095588`, if found clears active flag and 6-byte BD_ADDR via `0x6013cf90` (`memset`). | 1 caller / 2 callees |
| `0x600ef900` |  116 | BTA / GATTC | **`bta_gattc_find_clcb_by_bd_addr`** — Client control block accessor: if `param_1[0xf] == 1` queries cache via `0x600ef8a0`; queries `0x60094ffc`, if null checks capacity via `0x6009547c` and allocates via `0x600950bc`. | 1 caller / 4 callees |
| `0x600ef974` |   72 | BTA / GATTC | **`bta_gattc_find_clcb_by_cif`** — Client control block lookup: clears server cache via `0x600ef8c8`, looks up control block by connection ID via `0x6009506c`, if null looks up by app ID/BD_ADDR via `0x60094ffc`. | 1 caller / 3 callees |
| `0x600ef9bc` |  116 | BTA / GATTC | **`bta_gattc_alloc_bg_conn_slot`** — Background connection slot allocator (10 slots, 28-byte stride at `+0x15b`/`+0x15d`): marks in-use `slot[0x15d] = 1`, stores app ID `slot[0x15b] = param_2`, returns slot index (0..9) or 0xff if full. | 1 caller / 0 callees |

**⚠️ QA session 113 note:** zero corrections — every cross-reference to an already-established (and, in several cases, previously QA-*corrected*) address in this wave turned out consistent, several strikingly so. `bta_gattc_service_id_compare`/`bta_gattc_service_type_and_id_compare` correctly compose `bta_gattc_uuid_compare` (session 112) and each other, and `0x600ef546`'s row is exactly the same address session 112's confirmed `bta_gattc_find_char_handle_by_uuid` (`0x600eedee`) had already been calling as "matches service" — closing another loop between sessions. `bta_gattc_parse_char_ext_prop_response`'s literal `0x2905` is the real Bluetooth SIG "Characteristic Extended Properties" descriptor UUID, an exact spec match. `bta_gattc_find_or_create_srvc_cache`'s two-step composition (`0x60095588` then, on failure, `0x60095534`) is a precise semantic match to those two addresses' own already-established (and QA-corrected) identities in `bruce-bta-stack.md` — "a pure read-only linear search" and "searches a table for the first empty slot and inserts," respectively — a textbook find-then-insert "find_or_create" pattern, from a completely unrelated earlier correction that had nothing to do with GATTC when it was made. `bta_gattc_clear_bg_conn_device`'s use of `0x60094f58` (also already established/corrected as a matching-entry-pointer search) as a lookup step before operating on a nested sub-array is likewise consistent, not contradictory. Every callee citation in this wave to a shared/generic utility (`0x6009506c`, `0x60094ffc`, `0x60095588`, `0x60095534`, `0x60094f58`, `0x6009547c`) is appropriately functional/hedged rather than asserting a fresh specific name, avoiding the exact over-claiming pattern sessions 111/112 each found once. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,139 committed decomp files (474,958 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 66.46% exactly. **Reliability read**: the fourth wave in a row in this GATTC address range, and the cross-validation keeps compounding rather than degrading — a good sign that the underlying subsystem identification (once corrected in session 110) is now solid ground for this whole neighborhood.

## Session 114 (Wave 84) — Broadcom BTA GATTC Cache Queries, Address Primitives & DM Power Management (10 functions, 998 bytes)

Decompiled and documented 10 functions (998 bytes across `0x600efa30`–`0x600efe16`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600efa30` |   82 | BTA / GATTC | **`bta_gattc_find_bg_conn_slot_by_app_id`** — Background connection lookup: searches 10-slot table (32-byte stride at `param_1 + 4`), matching `app_id` at `+0x20`, returning slot index (0..9) or 0xff if not found. ⚠️ *(flagged, not corrected, QA session 114 — disassembly-confirmed (`lsls r3,r3,#5` = `×0x20`) that for iteration `i` the "occupied" check reads `param_1 + i*0x20 + 4` while the "`app_id`" check reads `param_1 + i*0x20 + 0x20` — the second address is dimensionally the same as slot `(i+1)`'s own base, not a field within slot `i`'s own 0x20-byte span, and unlike the genuinely neighbor-comparing `bta_gattc_find_srvc_cache_by_handle_range` (`0x600efaf6`, this same wave), there's no `i<9` guard before this access. Real semantics left unresolved — possibly a pairing with the next slot is intentional, possibly the field-offset description is imprecise — flagged for a future session with more context (e.g. once `0x600ff09c`, the sole caller, is decompiled) rather than guessed here.)* | 1 caller / 0 callees |
| `0x600efa82` |  116 | BTA / GATTC | **`bta_gattc_find_srvc_cache_by_handle`** — Service cache handle query: searches 10-slot cache table (28-byte stride at `param_1 + 0x144`), matching start handle `param_2 == slot[0x158]`, returning slot pointer (`slot + 0x144`) or 0. | 1 caller / 0 callees |
| `0x600efaf6` |  292 | BTA / GATTC | **`bta_gattc_find_srvc_cache_by_handle_range`** — Service cache range query: iterates 10-slot cache table to find which slot's handle interval `[slot[i].start_handle, slot[i+1].start_handle)` contains handle `param_2`; returns matching cache slot pointer. | 1 caller / 0 callees |
| `0x600efc1a` |  172 | BTA / GATTC | **`bta_gattc_uuid_equals`** — 16/128-bit UUID comparator with Base UUID expansion via `0x60095ae8` and 16-byte `memcmp` (`0x6013d168`). | 1 caller / 2 callees |
| `0x600efcc6` |   56 | BTA / Core | **`bta_bdcpy`** — Core 6-byte Bluetooth Device Address (`BD_ADDR`) copy helper (`memcpy(dest, src, 6)`). | 43 callers / 0 callees |
| `0x600efcfe` |   68 | BTA / Core | **`bta_bdcmp`** — Core 6-byte Bluetooth Device Address (`BD_ADDR`) equality comparator (`memcmp(addr1, addr2, 6)`). Returns 0 on match, -1 on mismatch. | 23 callers / 0 callees |
| `0x600efd42` |   32 | BTA / DM Search | ~~**`bta_dm_disable_search_if_device_up`** — DM Search state clear: calls `0x600ee278` (`btm_is_device_up_locked`); if active, clears search flag 0 via `0x60095f38` (`bta_dm_search_set_state_flag(0)`).~~ ⚠️ **misidentified, corrected QA session 114** — `0x60095f38` is a completely different address from the already-established `bta_dm_search_set_state_flag` (`0x60096290`, session 110), and its own decompiled body (3 callees: allocates a message via `FUN_6006dbac`, branches on its own parameter to set a type code of 2 or 5 or else frees the message, then conditionally posts via `FUN_600962dc`) bears no resemblance to `bta_dm_search_set_state_flag`'s real shape (a single direct byte-write, 0 callees). `0x60095f38` is already independently established in `bruce-bta-stack.md` as `bta_sys_hw_btm_cback`, a callback/message-post function — real behavior: after confirming the device is up, invokes `bta_sys_hw_btm_cback(0)` (posting status code 0), not clearing a search flag. | 0 callers / 2 callees |
| `0x600efd62` |   44 | BTA / DM PM | **`bta_dm_pm_init_record`** — Power Management record init: calls `0x600d9310`, sets handle at `+0xc` and timeout at `+0x14`. | 1 caller / 1 callee |
| `0x600efd8e` |   90 | BTA / DM PM | **`bta_dm_pm_register_app`** — Power Management app registration: allocates timer/record via `0x6006e154` if empty, sets PM spec via `0x6006e3b0`, unlinks old node via `0x6006e2d0`, updates node handle/timeout, and enqueues node via `0x6006e214`. | 1 caller / 4 callees |
| `0x600efde8` |   46 | BTA / DM PM | **`bta_dm_pm_deregister_app`** — Power Management app deregistration: unlinks application node from PM queue via `0x6006e2d0`; if queue empty, releases PM timer/record resources via `0x6006e160`. | 1 caller / 2 callees |

**⚠️ QA session 114 note:** a wave with genuinely mixed results — the two UUID/address utility functions hold up precisely (one of them, unusually, ended up *fixing* a stale entry elsewhere rather than being wrong itself), but one BTA DM Search claim conflates two distinct addresses and one background-connection search has an unresolved offset oddity. `bta_bdcpy`/`bta_bdcmp` (`0x600efcc6`/`0x600efcfe`) are confirmed exactly — both are plain 6-byte copy/compare loops, and their caller lists independently confirm two guesses from session 113 (`0x600ef7f8`'s "bdcpy" and `0x600ef5be`/`0x600ef648`'s "bdcmp"), plus `bta_bdcmp`'s ~23 callers include most of the "BTM/PM"-labeled generic-search cluster established across sessions 30-36, nicely explaining what those searches' "key" comparisons actually are. `bta_gattc_uuid_equals` (`0x600efc1a`) triggered the most interesting finding of the session: its callee `0x60095ae8` appeared to contradict a detailed, specific-sounding session-30 QA correction in `bruce-bta-stack.md` claiming it's part of an unrelated "event-ID constructor/listener" cluster — but fresh disassembly of `0x60095ae8`'s current 64 bytes shows a clean template-copy-plus-value-insert shape matching Base-UUID expansion exactly, and the old note turned out to be a boilerplate paragraph mechanically copy-pasted across 6 different addresses in that range (its own cited evidence was specific to a *different* address, `0x600959cc`) — corrected in `bruce-bta-stack.md`, with `bta_gattc_uuid_equals`'s own claim in this doc confirmed rather than changed. **One confirmed correction**: `bta_dm_disable_search_if_device_up` (`0x600efd42`) claimed its callee `0x60095f38` was the already-established `bta_dm_search_set_state_flag` — but that name belongs to a different address (`0x60096290`, session 110), and `0x60095f38`'s own body (message alloc/type-branch/post, 3 callees) is nothing like that simple flag-setter's shape (0 callees, one direct byte-write); `0x60095f38` is itself already independently established as `bta_sys_hw_btm_cback`. Corrected in place. **One flagged, unresolved finding**: `bta_gattc_find_bg_conn_slot_by_app_id` (`0x600efa30`) has a disassembly-confirmed offset oddity — its "app_id" comparison field sits exactly where the *next* iteration's slot would begin under its own 0x20-byte stride, with no bounds-guard for the last iteration (unlike the same wave's `bta_gattc_find_srvc_cache_by_handle_range`, which correctly guards its own genuine neighbor-slot lookahead). Left unresolved pending more context rather than guessing a replacement identity. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,149 committed decomp files (475,956 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 66.60% exactly. **Reliability read**: a genuinely productive, if messier, wave than the previous four clean ones — three separate findings of three different characters (a real misidentification, a resolved-in-the-wave's-favor contradiction with stale doc content, and an unresolved structural anomaly), showing that even a subsystem address range that's been reliably GATTC for four straight sessions can still throw a curveball, and that cross-referencing existing doc entries cuts both ways — sometimes it catches the new wave's error, sometimes it catches an old error the new wave's fresh disassembly happens to expose.

## Session 115 (Wave 85) — Broadcom BTA DM Power Management & Vendor HCI Dispatchers (14 functions, 1,264 bytes)

Decompiled and documented 14 functions (1,264 bytes across `0x600efe16`–`0x600f033a`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600efe16` |   14 | BTA / DM PM | **`bta_dm_pm_dummy_stub`** — 14-byte no-op handler stub. | 1 caller / 0 callees |
| `0x600efe24` |   26 | BTA / DM PM | **`bta_dm_pm_set_conn_params`** — PM connection parameters dispatcher: delegates to ~~`0x60096e38` (`bta_dm_pm_set_params`)~~ ⚠️ **wrong callee name, corrected QA session 115** — `0x60096e38` is already independently established, unhedged, in `bruce-bta-stack.md` as `hcisu_h4_send_msg_now` (H4 UART HCI transport send), not a PM-specific "set_params" function. Real behavior: this function is a thin pass-through that forwards its two arguments directly to the generic H4 transport send primitive; the "PM connection parameters" framing for the *enclosing* function is now unconfirmed rather than established, since its sole action is a generic transport send, not anything visibly PM-specific. | 1 caller / 1 callee |
| `0x600efe4c` |   76 | BTA / DM PM | **`bta_dm_pm_start_scan_or_inquiry`** — Starts search/inquiry via `0x600976f8` (`bta_dm_search_start`), returning 0 on success or 5 on failure. | 2 callers / 1 callee |
| `0x600efe98` |   86 | BTA / DM PM | **`bta_dm_pm_handle_scan_evt`** — Inquiry/scan response event filter: validates event header and updates filter via `0x6009c1d4`. | 0 callers / 1 callee |
| `0x600eff14` |  136 | BTA / DM PM | **`bta_dm_pm_update_link_policy`** — Link policy updater: queries link block via `0x60098ec8`, updates PM state at `+0x148`, checks state via `0x6009837c`, and configures policy mask via `0x60098530`. | 1 caller / 3 callees |
| `0x600eff9c` |   30 | BTA / DM PM | **`bta_dm_pm_set_power_mode`** — Configures active power mode with flag `0x80` via `0x60098284`. | 1 caller / 1 callee |
| `0x600effba` |   98 | BTA / Vendor | **`bta_dm_send_vs_cmd_fcbb`** — Vendor-specific HCI dispatcher: formats 0x2a-byte payload for opcode `0xfcbb` and dispatches via `0x600a1394` (`BTM_VendorSpecificCommand`). | 1 caller / 2 callees |
| `0x600f001c` |   22 | BTA / DM PM | **`bta_dm_pm_return_0`** — PM status helper returning constant 0. | 1 caller / 0 callees |
| `0x600f0032` |   22 | BTA / DM PM | **`bta_dm_pm_return_3`** — PM status helper returning constant 3. | 1 caller / 0 callees |
| `0x600f0048` |  118 | BTA / Vendor | **`bta_dm_send_vs_cmd_fc7e`** — Vendor-specific HCI dispatcher: formats 3-byte payload for opcode `0xfc7e` and dispatches via `0x600a1394` (`BTM_VendorSpecificCommand`). | 1 caller / 1 callee |
| `0x600f00be` |   14 | BTA / DM PM | **`bta_dm_pm_dummy_stub_2`** — 14-byte no-op handler stub. | 1 caller / 0 callees |
| `0x600f00cc` |  256 | BTA / Vendor | **`bta_dm_pm_send_vs_mode_cmd`** — Vendor-specific PM mode dispatcher: finds link block via ~~`0x600bb6dc` (`btm_pm_find_rec`)~~ ⚠️ **wrong callee name, corrected QA session 115** — `0x600bb6dc` is already independently established, unhedged, in `bruce-bta-stack.md` as `l2cu_find_lcb_by_bd_addr` ("searches 4-entry LCB table (stride 164B) by 6-byte BD_ADDR", 26 callers), an L2CAP Link Control Block lookup, not a PM record lookup. The vendor-opcode-dispatch portion of this function (`0xfc57`/`0xfd1a` via the confirmed `BTM_VendorSpecificCommand`, `0x600a1394`) remains well-evidenced and unchanged, sends vendor HCI opcode `0xfc57` (mode 1, 3B) or `0xfd1a` (mode 2, 4B) via `0x600a1394`, and triggers mode update via `0x600b8f0c`. | 1 caller / 3 callees |
| `0x600f01cc` |  134 | BTA / DM PM | **`bta_dm_pm_get_device_address`** — Device address extractor: extracts 6-byte BD_ADDR from control block based on address type at `+0x7a` (`+0x74`, `+0x6c`, or `+0x10`) via `memcpy` (`0x6013d3a0`). | 1 caller / 1 callee |
| `0x600f0252` |  232 | BTA / DM PM | **`bta_dm_pm_set_sniff_subrating`** — Sniff subrating configuration: checks flags via ~~`0x600a1354` (`BTM_ReadLocalSupportedFeatures`)~~ ⚠️ **wrong callee name, corrected QA session 115** — `0x600a1354` is already independently established, unhedged, in `bruce-bta-stack.md` as `BTM_GetHciHandle` ("returns HCI handle table pointer / base handle", 6 callers, 0 callees), not a supported-features query. The bits masked here (`0x20`/`0x40`/sign bit/`pbVar1[1]&1`) are therefore being read from whatever struct that handle-table pointer leads to, not a local-supported-features bitmask; real meaning of those specific bits is unconfirmed. The overall "sniff subrating" framing for this function remains well-supported independently (5 callers, several already-established as BTA DM PM/ACL-adjacent: `0x60093a30`, `0x600c2d5c`, `0x600a6d70`), masks unsupported flags, looks up link block via `0x60098ec8` (already independently established/corrected as the real "find LCB by BD_ADDR" lookup), and invokes `0x600b2f80` (`BTM_SetSniffSubrating`). | 5 callers / 3 callees |

**⚠️ QA session 115 note:** three confirmed wrong callee-name citations, all caught the same way — cross-checking against `bruce-bta-stack.md`'s existing, unhedged, already-established entries rather than fresh disassembly. `bta_dm_send_vs_cmd_fcbb`/`bta_dm_send_vs_cmd_fc7e` correctly cite `0x600a1394` as `BTM_VendorSpecificCommand` (matches the established entry exactly, and their formatted-payload-plus-dispatch shape is precise), which makes the contrast with the three misses below more notable — the correct citation shows the wave *can* check the appendix, it just didn't do so consistently. **Three corrections**: `bta_dm_pm_set_conn_params` (`0x600efe24`) claimed its callee `0x60096e38` was `bta_dm_pm_set_params`, but that address is already established as `hcisu_h4_send_msg_now` (generic H4 UART transport send) — the enclosing function is a thin pass-through to a transport primitive, not visibly PM-specific at all; `bta_dm_pm_send_vs_mode_cmd` (`0x600f00cc`) claimed `0x600bb6dc` was `btm_pm_find_rec`, but it's already established as `l2cu_find_lcb_by_bd_addr` (an L2CAP LCB lookup); `bta_dm_pm_set_sniff_subrating` (`0x600f0252`) claimed `0x600a1354` was `BTM_ReadLocalSupportedFeatures`, but it's already established as `BTM_GetHciHandle`. All three corrected in place; in each case the *enclosing* function's own higher-level framing was left intact where still independently supported (vendor-opcode dispatch, caller-cluster corroboration) rather than being struck through wholesale, since only the specific mis-cited callee identity was contradicted, not the surrounding evidence. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,163 committed decomp files (477,220 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 66.78% exactly. Also noted two small (14B and 38B) unclaimed gaps in the census within this wave's own address range (`0x600efe3e`–`0x600efe4c`, `0x600efeee`–`0x600eff14`) — confirmed genuinely absent from the census (not merely un-decompiled), most likely alignment padding or small not-yet-defined functions; not flagged as an error since the wave's own byte/function totals are unaffected either way. **Reliability read**: the second consecutive wave with real findings after four clean ones — a useful reminder that this specific check (cross-referencing every named callee against the existing appendix, not just the ones that "feel" uncertain) needs to be applied uniformly, since this wave got the vendor-command citations right while missing three other, equally-checkable ones in the same write-up.

## Session 116 (Wave 86) — Broadcom BTA DM Bluetooth LE Link Management, BLE Addresses & Scanning (14 functions, 1,004 bytes)

Decompiled and documented 14 functions (1,004 bytes across `0x600f033a`–`0x600f0726`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f033a` |  168 | BTA / DM | **`bta_dm_acl_change`** — ACL connection change handler: finds device block via `0x6009feb8` or `0x600f1746`, updates mode count, copies 8-byte descriptors via `0x6013d3a0` (`memcpy`), updates link policy via `0x600a8494`, and conditionally calls ~~`0x600bc7e8` (`l2cu_update_lcb_4_gatts`)~~ ⚠️ **wrong callee name, corrected QA session 116** — `0x600bc7e8` is already independently established, unhedged, in `bruce-bta-stack.md` as `l2cu_release_lcb` ("frees link control block and returns it to pool", 4 callers), the opposite operation from "update." Real behavior: conditionally *releases* an L2CAP link control block, not updating one for GATTS. | 3 callers / 5 callees |
| `0x600f03e2` |   36 | BTA / DM PM | **`bta_dm_pm_sniff_mode_event`** — Sniff mode event forwarder: calls ~~`0x600b29b8` (`BTM_PM_OnSniffSubratingEvt`)~~ ⚠️ **wrong callee name, corrected QA session 116** — `0x600b29b8` is already independently established, unhedged, in `bruce-bta-stack.md` as `btsnd_hcic_rmt_ext_features` (named and opcode-verified, HCI `0x041c`, "Read Remote Extended Features") — a raw HCI command sender with no connection to sniff-subrating events. Real behavior: this function sends the HCI Read Remote Extended Features command; the enclosing function's own "sniff mode event forwarder" framing is now unconfirmed. | 2 callers / 1 callee |
| `0x600f0406` |   88 | BTA / DM PM | **`bta_dm_pm_set_sniff_policy`** — Sniff policy setter: queries link block via ~~`0x60098ec8` (`l2cu_find_lcb_by_bd_addr`)~~ ⚠️ **wrong callee name, corrected QA session 116** — `l2cu_find_lcb_by_bd_addr` is already an independently, unhedged-established *different* address (`0x600bb6dc`, "4-entry LCB table, stride **164B**"); `0x60098ec8` is a separate, previously-corrected lookup over a table with a different stride (**0x14c** = 332B, per its own `bruce-bta-stack.md` entry) — the two are not the same function despite a superficially similar "find by BD_ADDR" shape. `0x60098ec8`'s own established identity remains the generic "find LCB by BD_ADDR" table-scan lookup, just not under this specific formal name. sets latency at `+0x10c`, and invokes `0x600b3a80` (`BTM_SetQoS`, address not independently found elsewhere — left as originally claimed, unconfirmed rather than contradicted). | 2 callers / 2 callees |
| `0x600f045e` |   44 | BTA / DM PM | **`bta_dm_pm_is_link_active`** — Link activity checker: returns whether link control block exists for `param_1` via `0x60098ec8`. | 5 callers / 1 callee |
| `0x600f048a` |   48 | BTA / DM PM | **`bta_dm_pm_get_hci_handle`** — HCI handle lookup: returns 16-bit connection handle from link control block via `0x60098ec8` (or `0xffff` if not found). | 5 callers / 1 callee |
| `0x600f04ba` |   42 | BTA / DM PM | **`bta_dm_pm_get_link_spec_ptr`** — Link spec pointer getter: returns pointer to sub-structure at `+0x10e` via `0x60098ec8` (or 0 if not found). | 1 caller / 1 callee |
| `0x600f04e4` |  110 | BTA / DM PM | **`bta_dm_pm_disconnect_link`** — Link disconnect dispatcher: gets HCI handle via `0x600f048a`, checks device record via `0x6009ff18`, and calls ~~`0x600b218c` (`BTM_SecDisconnect` / `btm_sec_disconnect` with reason `0x13`)~~ ⚠️ **wrong callee name, corrected QA session 116** — `0x600b218c` is already independently established, unhedged, in `bruce-bta-stack.md` as `btsnd_hcic_disconnect` (named and opcode-verified, HCI `0x0406`), the raw HCI command sender, not the higher-level `BTM_SecDisconnect`/`btm_sec_disconnect` API layer — its real 2-argument signature (`handle`, `reason`) matches this call site exactly (`FUN_600b218c(sVar1, 0x13)`). Real behavior: this function directly sends the HCI Disconnect command with reason `0x13`, rather than calling through a separate security-layer disconnect API. | 2 callers / 3 callees |
| `0x600f0552` |   22 | BTA / DM PM | **`bta_dm_pm_return_0_stub`** — Constant 0 return helper. | 1 caller / 0 callees |
| `0x600f0568` |  114 | BTA / DM PM | **`bta_dm_pm_set_encryption`** — Encryption dispatcher: queries device record via `0x6009ff18`, validates security flags `{1, 2, 4, 0x10, 0x20, 0x40}`, calls `0x6009ad00` (`bta_dm_set_encryption`), and conditionally calls `0x6009f6c0`. | 1 caller / 3 callees |
| `0x600f05da` |   64 | BTA / DM PM | **`bta_dm_pm_get_local_ble_addr`** — Local BLE address getter: queries link block via `0x60098ec8`, copies 6-byte BD_ADDR from `+0x12f` via `0x6013d3a0` (`memcpy`), returns address type byte from `+0x135`. | 2 callers / 2 callees |
| `0x600f061a` |   72 | BTA / DM PM | **`bta_dm_pm_get_peer_ble_addr`** — Peer BLE address getter: queries link block via `0x60098ec8`, copies 6-byte BD_ADDR from `+0x136` via `0x6013d3a0` (`memcpy`), returns address type byte from `+0x13c`. | 3 callers / 2 callees |
| `0x600f0662` |   44 | SMP (BTA wrapper) | ~~**`bta_dm_ble_set_bg_conn_type`** — Background connection type setter: converts boolean `param_2` (0 or 9) and delegates to `0x600c0640` (`bta_dm_ble_set_bg_conn_type`).~~ ⚠️ **misidentified, corrected QA session 116** — `0x600c0640` is already independently established, unhedged, in `bruce-bta-stack.md` as `SMP_PasskeyReply` ("processes user passkey entry reply; validates state `0x02` and emits event `0x15` to `smp_sm_event`"), a Security Manager Protocol pairing API — nothing to do with background-connection-type configuration. Real behavior: converts a boolean into a fixed reply value (0 or 9) and forwards to `SMP_PasskeyReply`, almost certainly a thin BTA-layer wrapper around the SMP passkey-reply API (e.g. accept/reject or a fixed "OOB"-style passkey response), not `bta_dm_ble_set_bg_conn_type`. Real identity left unconfirmed rather than guessed. | 1 caller / 1 callee |
| `0x600f068e` |   78 | SMP (BTA wrapper) | ~~**`bta_dm_ble_observe`** — BLE observation starter: queries device record via `0x6009ff18`, sets flag `0x200` at `+0x2a`, calls `0x600c0698` (`bta_dm_ble_observe`).~~ ⚠️ **misidentified, corrected QA session 116** — `0x600c0698` is already independently established, unhedged, in `bruce-bta-stack.md` as `SMP_ConfirmReply` ("processes user confirmation reply; validates passkey value <= 999,999 and routes to `smp_sm_event` event `0x25` or stores DHKey check"), an SMP pairing API — not a BLE-observation starter. `0x6009ff18` is itself already independently established/corrected as the generic "find device record by BD_ADDR" lookup (not device-record-specific to observation), consistent with a pairing-flow function that needs to look up the peer device by address first. Real behavior: looks up the device record, sets a flag, and forwards the user's confirmation to `SMP_ConfirmReply` — a thin BTA-layer wrapper around SMP numeric-confirmation, not `bta_dm_ble_observe`. Real identity left unconfirmed rather than guessed. | 1 caller / 2 callees |
| `0x600f06dc` |   74 | SMP (BTA wrapper) | ~~**`bta_dm_ble_scan`** — BLE scan starter: queries device record via `0x6009ff18`, sets flag `0x200` at `+0x2a`, calls `0x600c073c` (`bta_dm_ble_scan`).~~ ⚠️ **misidentified, corrected QA session 116** — `0x600c073c` is already independently established, unhedged, in `bruce-bta-stack.md` as `SMP_NumericComparisonReply` ("processes user Numeric Comparison accept/reject reply; validates state `0x06` and dispatches event `0x23` or error `0x0c`"), an SMP pairing API — not a BLE scan starter. This function shares the exact same template as `0x600f068e` above (find device record via the confirmed generic `0x6009ff18` lookup, set the same `0x200` flag at `+0x2a`, forward to an SMP user-response API), strongly suggesting `0x600f0662`/`0x600f068e`/`0x600f06dc` are a coherent trio of BTA-layer wrappers around `SMP_PasskeyReply`/`SMP_ConfirmReply`/`SMP_NumericComparisonReply` respectively, not a "BLE background-conn-type / observe / scan" cluster at all. Real identity left unconfirmed rather than guessed. | 1 caller / 2 callees |

**⚠️ QA session 116 note:** a major-correction wave — 7 of 14 rows cite a callee under the wrong name, all caught by cross-referencing `bruce-bta-stack.md`'s existing, unhedged, already-established entries. **Most consequential**: the entire final "BLE Device Addresses & Scanning Dispatchers" trio (`0x600f0662`/`0x600f068e`/`0x600f06dc`, claimed `bta_dm_ble_set_bg_conn_type`/`bta_dm_ble_observe`/`bta_dm_ble_scan`) turns out to be misattributed wholesale — all three call already-independently-established Security Manager Protocol (SMP) pairing-reply APIs (`SMP_PasskeyReply`, `SMP_ConfirmReply`, `SMP_NumericComparisonReply` respectively), not BLE scan/observe/connection-type functions at all, and all three share one coherent template (look up a device record via the confirmed generic `0x6009ff18`, optionally set a flag, forward to the SMP reply API) — a real, well-evidenced BTA-layer-wraps-SMP-user-response-API cluster, not a BLE-scanning one. **Four more individual corrections**: `bta_dm_acl_change`'s `0x600bc7e8` citation ("l2cu_update_lcb_4_gatts") is actually the established `l2cu_release_lcb` (frees, not updates); `bta_dm_pm_sniff_mode_event`'s `0x600b29b8` citation ("BTM_PM_OnSniffSubratingEvt") is actually the established `btsnd_hcic_rmt_ext_features` (a Read Remote Extended Features HCI sender, unrelated to sniff subrating); `bta_dm_pm_set_sniff_policy`'s `0x60098ec8` citation ("l2cu_find_lcb_by_bd_addr") reuses a name that's already independently established for a *different* address (`0x600bb6dc`, confirmed via a differing table stride — 164B vs. `0x60098ec8`'s own already-established 332B); and `bta_dm_pm_disconnect_link`'s `0x600b218c` citation ("BTM_SecDisconnect / btm_sec_disconnect") is actually the established lower-layer `btsnd_hcic_disconnect` (a raw HCI opcode sender, whose real 2-argument `(handle, reason)` signature matches this call site exactly), not the higher security-API layer. All 7 corrected in place; the enclosing functions' own higher-level framing was left intact only where nothing specifically contradicted it (e.g. `bta_dm_acl_change`'s overall shape), and struck through where the wrong callee identity undermined the whole claim (the SMP trio). Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,177 committed decomp files (478,224 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 66.92% exactly. **Reliability read**: the largest correction count since session 106/110 — a strong indication the "check every named callee against the existing appendix" step was skipped almost entirely for this wave rather than applied inconsistently (as in session 115), since 7 of the roughly 9 specifically-named callee citations in this wave turned out wrong; the SMP-trio finding in particular is a good example of why checking is worth the effort — the wrong "BLE scan/observe" framing was thematically plausible enough (this section sits right after genuinely-BLE-address functions) that it would have been easy to accept at face value.

## Session 117 (Wave 87) — Broadcom BTA DM BLE Connection Parameters, Security & Pairing Dispatchers (12 functions, 1,544 bytes)

Decompiled and documented 12 functions (1,544 bytes across `0x600f0726`–`0x600f0d2e`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f0726` |  272 | BTA / DM BLE | **`bta_dm_ble_set_conn_params`** — BLE connection parameter validator & updater: validates min interval (`5 < param_2 < 0xc81`), max interval (`5 < param_3 < 0xc81`), latency (`param_4 < 0x1f5`), timeout (`9 < param_5 < 0xc81`, default 2000), stores into device record (`0x6009ff18`) at `+0xe6`, `+0xe8`, `+0xea`, `+0xec`. | 2 callers / 1 callee |
| `0x600f0836` |  218 | BTA / DM | **`bta_dm_get_device_addr_type`** — Resolves device transport/address type (public vs random) using device record lookup (`0x6009ff18`) and inquiry database query (`0x600a21e4` / `BTM_InqDbRead`). | 9 callers / 3 callees |
| `0x600f0910` |   90 | BTA / DM | **`bta_dm_is_ble_device`** — Checks whether device has active BLE link block (`0x60098ec8`) or resolves to BLE transport type via `0x600f0836`. | 3 callers / 2 callees |
| `0x600f096a` |   42 | BTA / DM Sec | **`bta_dm_set_sec_flags`** — Sets security auth state byte at `+0x61` in device record (`0x6009ff18`). | 1 caller / 1 callee |
| `0x600f0994` |   64 | BTA / DM Sec | **`bta_dm_get_sec_flags`** — Retrieves security auth flags from device record (`0x6009ff18`): byte `+0x60` (transport 1) or `+0x61` (transport 2). | 1 caller / 1 callee |
| `0x600f09d4` |  126 | BTA / DM BLE | **`bta_dm_ble_crypto_cback`** — Formats 20-byte crypto completion event (status, length 8/16, opcode `param_2`, payload) and dispatches to caller callback `param_3`. | 1 caller / 2 callees |
| `0x600f0a52` |   70 | BTA / DM | **`bta_dm_inc_device_counter`** — Increments packet/event counter in device record (`0x6009ff18`): `+0xdc` (`param_2 == 0`) or `+0xe0`. | 2 callers / 1 callee |
| `0x600f0a98` |   48 | BTA / DM | **`bta_dm_get_device_type_byte`** — Reads device property/flags byte at `+0x7b` from device record (`0x6009ff18`). | 1 caller / 1 callee |
| `0x600f0ac8` |   62 | BTA / DM | **`bta_dm_get_device_feature_word`** — Reads 16-bit attribute word at `+0xd6` from device record (`0x6009ff18`). | 2 callers / 1 callee |
| `0x600f0b06` |  178 | BTA / DM Sec | **`bta_dm_check_sec_auth_level`** — Evaluates recorded security auth level (`+0x2a`/`+0xd8` in device record `0x6009ff18`) against required capability `param_2`. | 3 callers / 1 callee |
| `0x600f0bb8` |  204 | BTA / DM Sec | **`bta_dm_sec_encrypt_or_pair`** — BLE security initiator: if already bonded and auth level matches (`0x600f0b06`), initiates encryption via `0x6009afd4` (`btm_ble_start_encrypt`); otherwise initiates SMP pairing via `0x600c0578` (`SMP_Pair`). | 1 caller / 4 callees |
| `0x600f0c84` |  170 | BTA / DM Sec | **`bta_dm_ble_enc_cmpl_cback`** — BLE encryption complete handler: processes random value via `0x600c03d8` (`smp_proc_rand`), updates security state, notifies pending waiters via `0x600f1f82`, and dispatches GATT encryption notification via `0x600ac22c` (`gatt_notify_enc_cmpl`). | 1 caller / 4 callees |

**⚠️ QA session 117 note:** zero corrections — a strong turnaround from session 116's major-correction wave, and direct evidence the appendix-check step was genuinely applied this time. All five specifically-named callee citations in this wave check out exactly against already-established `bruce-bta-stack.md` entries: `0x600a21e4` = `BTM_InqDbRead` (exact), `0x6009afd4` = `btm_ble_start_encrypt`-shaped (exact, hedged consistently with the established entry's own hedge), `0x600c0578` = `SMP_Pair`/`smp_pair_req` (exact), `0x600c03d8` = `smp_proc_rand` (exact), `0x600ac22c` = `gatt_notify_enc_cmpl` (exact). Notably, this wave's `bta_dm_sec_encrypt_or_pair`/`bta_dm_ble_enc_cmpl_cback` correctly land on the *real* SMP cluster (`0x600c0578`/`0x600c03d8`) immediately adjacent to the three SMP addresses (`0x600c0640`/`0x600c0698`/`0x600c073c`) session 116 found mislabeled as BLE scan/observe functions — a good sign the wave now has this address neighborhood right. The pervasive `0x6009ff18` device-record lookups throughout this wave are consistent with its own already-established, QA-corrected identity (generic "find device record by BD_ADDR"), and the struct-offset usage (`+0x50`, `+0x52`, `+0x54`, `+0x60`, `+0x61`, `+0x7b`, `+0xd6`, `+0xd8`, `+0xd9`, `+0xdc`, `+0xe0`, `+0xe6`–`+0xec`, `+0xf4`) is internally consistent across all 9 functions that touch it, with no offset collisions or contradictions found. `bta_dm_is_ble_device`'s use of `0x60098ec8` with both argument `1` and `2` (checking a BR/EDR-transport LCB then a BLE-transport LCB before falling back to address-type resolution) is a coherent, sensible composition. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,189 committed decomp files (479,768 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 67.14% exactly. **Reliability read**: exactly the kind of wave that makes the appendix-cross-check worth doing every time — a wave adjacent to two consecutive sessions with real findings (115, 116) turning out clean removes any temptation to assume the neighborhood is now unreliable by default; each wave still needs to be judged on its own citations.

## Session 118 (Wave 88) — Broadcom BTA DM BLE Connection Lifecycle, RPA Resolution & Activity Control (12 functions, 1,706 bytes)

Decompiled and documented 12 functions (1,706 bytes across `0x600f0d2e`–`0x600f13d8`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f0d2e` |  320 | BTA / DM BLE | **`bta_dm_ble_conn_cmpl_evt_handler`** — Parses HCI LE Connection Complete event (handle, role, peer address type, 6-byte BD_ADDR, interval, latency, timeout); invokes `0x6009b290` (ACL link-record creator) and `0x600f7cea` (L2CAP BLE connection complete handler). | 0 callers / 3 callees |
| `0x600f0e6e` |   42 | BTA / DM BLE | **`bta_dm_ble_reset_state`** — Resets active BLE connection state (`0x6009c790`) and discovery tags (`0x6009ed00`) on link disconnect. | 2 callers / 2 callees |
| `0x600f0e98` |  142 | BTA / DM BLE | **`bta_dm_ble_verify_signature`** — Verifies BLE signed data: computes AES-CMAC (`0x600c09f0`) using CSRK at `+0x9c`, checks 8-byte signature via `memcmp` (`0x6013d168`), and increments device packet counter (`0x600f0a52`). | 1 caller / 4 callees |
| `0x600f0f26` |   34 | BTA / DM BLE | **`bta_dm_ble_gen_random_addr`** — Requests controller randomness via `0x600b1368` (`btsnd_hcic_ble_rand`) and triggers random address update (`0x6009bb50`). | 3 callers / 2 callees |
| `0x600f0f48` |   70 | BTA / DM | **`bta_dm_set_pseudo_addr`** — Populates 6-byte pseudo address at `+0x64` in device record (`0x6009ff18`) if currently zero. | 3 callers / 2 callees |
| `0x600f0f8e` |  172 | BTA / DM BLE | **`bta_dm_ble_match_rpa`** — Resolves BLE Resolvable Private Address (`& 0xc0 == 0x40`) against IRK at `+0x7c` via `0x600fbc02` (ah function) and sets pseudo address (`0x600f0f48`) on match. | 1 caller / 3 callees |
| `0x600f103a` |  270 | BTA / DM BLE | **`bta_dm_ble_set_rand_address`** — Stores random address into device record (`+0x74`/`+0x7a` via `0x6009ff18`) and updates active BLE LCB (`+0x136`/`+0x13c` via `0x60098ec8`). | 2 callers / 4 callees |
| `0x600f1148` |  468 | BTA / DM BLE | **`bta_dm_ble_update_white_list`** — Updates controller whitelist: removes device via `0x600b1090` (`btsnd_hcic_ble_remove_from_white_list`) or adds via `0x60098718`, resolving RPA/identity address and updating flag `+0x72`. | 1 caller / 5 callees |
| `0x600f131c` |   24 | BTA / DM | **`bta_dm_send_fixed_chnl_data`** — Forwards data over L2CAP fixed channel 4 (SMP/ATT) via `0x600b50d0` (`L2CA_SendFixedChnlData`). | 1 caller / 1 callee |
| `0x600f1334` |   66 | BTA / DM BLE | **`bta_dm_ble_stop_activity`** — Stops BLE activities by bitmask: cancels direct conn (`0x6009c444`), stops scanning (`0x6009c59c`), disables advertising (`0x6009e8fc`). | 1 caller / 3 callees |
| `0x600f1376` |   36 | BTA / DM BLE | **`bta_dm_ble_restart_activity`** — Restarts BLE connection (`0x6009c71c`) and advertising (`0x6009e84c`) activities. | 1 caller / 2 callees |
| `0x600f139a` |   62 | BTA / DM BLE | **`bta_dm_ble_enqueue_op`** — Enqueues BLE operations into BTM queue via `0x6009c2c0` and `0x6009c124`. | 3 callers / 2 callees |

**⚠️ QA session 118 note:** zero corrections — a second consecutive clean wave, with every checkable citation holding up. `bta_dm_ble_update_white_list`'s `0x600b1090` citation matches the already-established, opcode-verified `btsnd_hcic_ble_remove_from_white_list` (HCI `0x2012`) exactly; `bta_dm_ble_verify_signature`'s `0x600c09f0` citation matches the already-confirmed `AES-CMAC` primitive exactly. `bta_dm_ble_conn_cmpl_evt_handler`'s `0x6009b290` citation ("ACL link-record creator") is appropriately hedged and matches the established "ACL link-record creation/population helper... very likely `btm_acl_created`-shaped" description without over-claiming a specific formal name. **One claim disassembled fresh rather than cross-referenced**, since it wasn't yet in the appendix: `bta_dm_ble_match_rpa`'s citation of `0x600fbc02` as "the `ah` function" (the Bluetooth-spec Resolvable Private Address hash) is well-supported — disassembly shows a thin 56-byte argument-marshalling wrapper that tail-calls `0x600c0ac4`, which is already independently established as `smp_encrypt_data` (a named SMP function) — exactly matching the real Bluetooth spec definition `ah(k, r) = e(k, r')`, i.e. AES-128 encryption of a padded value, which is precisely what a thin wrapper around a generic "encrypt data" primitive should look like. `bta_dm_send_fixed_chnl_data`'s `0x600b50d0` citation ("`L2CA_SendFixedChnlData`") is a more specific gloss than the established "L2CAP-internal channel/CCB lookup-and-dispatch helper" entry, but not contradicted by it — left as-is rather than corrected, since a public "send on fixed channel" API plausibly does exactly "look up the CCB, then dispatch." Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,201 committed decomp files (481,474 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 67.38% exactly. **Reliability read**: continues the recovery from session 116 — two waves in a row with genuinely-checked citations, including one where the claim required fresh disassembly rather than an appendix hit and still held up precisely.

## Session 119 (Wave 89) — Broadcom BTA DM Advertising Parser, EIR/AD TLV Matcher & Device/Feature Init (12 functions, 960 bytes)

Decompiled and documented 12 functions (960 bytes across `0x600f13d8`–`0x600f17a4`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f13d8` |  164 | BTA / DM BLE | **`bta_dm_ble_adv_pkt_handler`** — Parses LE Advertising / Direct Advertising Report event (event_type, addr_type, reversed 6-byte BD_ADDR, payload pointer); forwards to `0x6009e4d0` (BTM inquiry/advertisement result processor). | 0 callers / 2 callees |
| `0x600f147c` |  124 | BTM / BLE Adv | **`BTM_CheckEirData`** — Searches Bluetooth Extended Inquiry Response (EIR) / BLE Advertising Data (AD) TLV structures for matching AD type `param_2`, returning pointer to payload and length `*param_3`. | 3 callers / 0 callees |
| `0x600f14f8` |  154 | BTA / DM BLE | **`bta_dm_ble_sec_event_dispatch`** — Formats 249-byte security event buffer and dispatches to BTM connection security listeners (`0x600a30f0` / `0x600a59d0`). | 0 callers / 4 callees |
| `0x600f1592` |   30 | BTA / DM BLE | **`bta_dm_ble_stop_scan`** — Stops BLE scanning: disables scan via `0x600b0da8` (`btsnd_hcic_ble_set_scan_enable(0, 1)`), clears discovery flag `0x180` (`0x6009ec14`), and resets scan parameters (`0x6009bfb0`). | 4 callers / 3 callees |
| `0x600f15b0` |  150 | BTA / DM BLE | **`bta_dm_ble_set_rand_address_from_inq`** — Dequeues discovery device record address (`0x6009ef10`) and updates random address table and active BLE LCB (`0x600f103a`). | 2 callers / 2 callees |
| `0x600f1646` |  104 | BTA / DM BLE | **`bta_dm_ble_disc_evt_dispatcher`** — Dispatches discovery events (`0x02`, `0x03`, `0x04`, `0x0d`) to appropriate BTM handlers (`0x6009f124`, `0x6009f1fc`, `0x6009f27c`, `0x600f15b0`). | 0 callers / 4 callees |
| `0x600f16ae` |   82 | BTA / DM | **`bta_dm_remove_device`** — Device unbonding / removal: verifies no active link on either transport (`0x600f045e`), clears security record (`0x600f172a`), and deletes stored NVRAM link keys (`0x600a1560`). | 3 callers / 4 callees |
| `0x600f1700` |   42 | BTA / DM | **`bta_dm_get_device_key_ptr`** — Returns pointer to 16-byte link key buffer at `+0x2c` in device record (`0x6009ff18`) for target BD_ADDR. | 3 callers / 1 callee |
| `0x600f172a` |   28 | BTA / DM | **`bta_dm_clear_sec_record`** — Clears security auth level word at `+0x2a` and zeroes BLE security credentials (`0x600f2080`). | 1 caller / 1 callee |
| `0x600f1746` |   40 | BTA / DM | **`bta_dm_find_or_alloc_device_record`** — Looks up device record by BD_ADDR (`0x6009ff18`) or allocates a free record slot (`0x6009fcf4`) if not already present. | 17 callers / 2 callees |
| `0x600f177a` |   12 | BTA / DM | **`bta_dm_read_buf_size`** — Initiates controller buffer size read query via `0x600a01f0` (`btm_read_buf_size_trigger`). | 1 caller / 1 callee |
| `0x600f1786` |   30 | BTA / DM | **`bta_dm_init_feature_query`** — Initializes feature query state bits (`0x600a0d68` / `btm_feature_query_init`) and launches the feature-query FSM sequence (`0x600a0cac` / `btm_feature_query_fsm`). | 2 callers / 2 callees |

**⚠️ QA session 119 note:** zero corrections — a third consecutive clean wave. Every checkable named citation matches the established appendix exactly: `0x600a01f0` = `btm_read_buf_size_trigger`, `0x600a0d68` = `btm_feature_query_init`, `0x600a0cac` = `btm_feature_query_fsm` (all exact, unhedged matches). `bta_dm_remove_device`'s citation of `0x600a1560` as `BTM_DeleteStoredLinkKey` is a particularly satisfying confirmation — this address's own entry (session 33 QA, 84+ sessions ago) explicitly struck through an original "`BTM_ReadTxPower`" claim after disassembly showed it actually sends the HCI Delete Stored Link Key opcode, and concluded "real identity is very likely a link-key-deletion API (e.g. `BTM_DeleteStoredLinkKey`)" — exactly the name this wave independently arrived at. `bta_dm_ble_adv_pkt_handler`'s citation of `0x6009e4d0` ("BTM inquiry/advertisement result processor") is consistent with, though slightly broader than, the established "BTM inquiry-control helper... consistent with an inquiry-results/timeout handler" — not contradicted. `BTM_CheckEirData`'s TLV-walking logic (length-byte + type-byte + payload, matching against a target AD type) is self-evidently correct against the real Bluetooth EIR/AD data format regardless of appendix cross-referencing — no external check needed to confirm this shape. `bta_dm_find_or_alloc_device_record`'s claimed composition (try the confirmed generic `0x6009ff18` lookup, fall back to `0x6009fcf4` allocation) is independently corroborated by session 116's own write-up, which already showed `0x600f033a` falling back to this exact function when a different, simpler lookup failed — a coherent "plain find, then find-or-alloc" escalation pattern across two sessions' worth of functions. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,213 committed decomp files (482,434 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 67.51% exactly. **Reliability read**: third clean wave in a row — the appendix-cross-check discipline that recovered after session 116 continues to hold, and this session added a nice example of a claim being confirmed not by a fresh citation but by a correction made all the way back in session 33.

## Session 120 (Wave 90) — Broadcom BTA DM Security State Queries, HCI Parameters & Connection Dispatchers (14 functions, 974 bytes)

Decompiled and documented 14 functions (974 bytes across `0x600f17a4`–`0x600f1b72`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f17a4` |   54 | BTA / DM | **`bta_dm_dispatch_cback`** — Formats 8-byte callback event structure `{param_2, param_3, param_1}` and dispatches to callback function pointer `param_4`. | 2 callers / 0 callees |
| `0x600f17da` |   38 | BTM / Radio | **`BTM_SetPageTimeout`** — Sends HCI Write Page Timeout (`0x0c18`) via `0x600b3548` (`btsnd_hcic_write_page_tout`). | 1 caller / 1 callee |
| `0x600f1800` |   84 | BTA / DM | **`bta_dm_sec_conn_req_handler`** — Routes incoming connection request (BR/EDR vs BLE) with inquiry database lookup (`0x600a26ec`), calling `0x6009de30` (BLE) or `0x600a3014` (BR/EDR). | 8 callers / 3 callees |
| `0x600f1854` |   68 | BTM / Inquiry | **`BTM_SetInquiryTxPower`** — Validates inquiry TX power range (-70 to +20 dBm) and sends HCI Write Inquiry Transmit Power Level (`0x0c59`) via `0x600b4798` (`btsnd_hcic_write_inq_tx_power`). | 1 caller / 1 callee |
| `0x600f1898` |   38 | BTA / DM Sec | **`bta_dm_is_device_authenticated`** — Tests authentication state bit (`+0x2a & 2`) in device record. | 2 callers / 0 callees |
| `0x600f18be` |   38 | BTA / DM Sec | **`bta_dm_is_device_encrypted`** — Tests encryption state bit (`+0x2a & 4`) in device record. | 2 callers / 0 callees |
| `0x600f18e4` |   38 | BTA / DM Sec | **`bta_dm_is_device_bonded`** — Tests bonding / link key present bit (`+0x2a & 1`) in device record. | 2 callers / 0 callees |
| `0x600f190a` |   66 | BTA / DM Sec | **`bta_dm_test_service_sec_bit`** — Tests service security requirement bit in 32-bit word bitmap at `param_1 + 4`. | 2 callers / 0 callees |
| `0x600f194c` |   74 | BTA / DM Sec | **`bta_dm_get_sec_level`** — Retrieves security authentication level byte for target transport from device record auth word `+0x2a` via `0x6009ff18`. | 4 callers / 1 callee |
| `0x600f1996` |   60 | BTA / DM Sec | **`bta_dm_sec_register_service`** — Registers service security requirements into BTM security database via `0x600a40c4`. | 2 callers / 1 callee |
| `0x600f19d2` |   60 | BTA / DM Sec | **`bta_dm_sec_cancel_pending_op`** — Clears pending security operation flag `+0xef = 0` on link disconnect via `0x6009ff18`. | 1 caller / 1 callee |
| `0x600f1a0e` |  198 | BTA / DM Sec | **`bta_dm_sec_auth_cmpl_handler`** — Handles SMP/GAP pairing & authentication completion: sets bonded bit `+0x2a |= 1`, stores key/service mask, and completes security procedure (`0x600a7b44` / `0x600f1f82`). | 1 caller / 3 callees |
| `0x600f1ad4` |   96 | BTA / DM Sec | **`bta_dm_sec_set_security`** — Validates requested transport capability against device address type (`0x600f0836`) and sets link security requirements via `0x600a44bc`. | 1 caller / 2 callees |
| `0x600f1b34` |   62 | BTA / DM Sec | **`bta_dm_sec_set_security_auto_transport`** — Automatically determines active transport (`0x600f0910` / `bta_dm_is_ble_device`) and sets link security requirements via `0x600a44bc`. | 1 caller / 2 callees |

**⚠️ QA session 120 note:** zero corrections — a fourth consecutive clean wave, with two exact real-spec-constant matches beyond the usual appendix cross-checks. `BTM_SetInquiryTxPower`'s callee `0x600b4798` matches the established, string-xref-named `btsnd_hcic_write_inq_tx_power` exactly, and both of this row's own numeric claims independently check out against the real Bluetooth spec: the cited opcode `0x0c59` is the textbook-correct HCI opcode for Write Inquiry Transmit Power Level (OGF `0x03` &lt;&lt; 10 | OCF `0x59`), and the validated range `-70` to `+20` dBm (`param_1 < -0x46 || 0x14 < param_1`, i.e. reject outside `[-70, 20]`) is the exact valid range the spec defines for this parameter. `BTM_SetPageTimeout`'s cited opcode `0x0c18` is likewise the textbook-correct value for Write Page Timeout, though its callee `0x600b3548` isn't yet in the appendix to cross-reference directly. `bta_dm_sec_conn_req_handler`'s two branches correctly route to `0x6009de30` (BLE) and `0x600a3014` (already established "very likely `btm_accept_connection`/`btm_sec_rcv_conn_req`-shaped"), and its `0x600a26ec` citation matches the established `btm_inq_find_raw_entry` behaviorally without over-asserting the formal name. Two pre-existing forward-references paid off: `0x600a40c4`'s appendix entry already cited "caller `FUN_600f1996`" and `0x600a44bc`'s already cited "called from... `0x600f1ad4`/`0x600f1b34`" — both relationships confirmed exactly by this wave's own decompiled bodies, evidence the doc's existing citations were sound even before these callers existed as committed functions. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,227 committed decomp files (483,408 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 67.65% exactly. **Reliability read**: fourth clean wave in a row since the session-116 recovery, and the two independently-checkable spec constants (opcode + dBm range) in the same row is about as strong a confirmation as a single function claim gets in this pipeline.

## Session 121 (Wave 91) — Broadcom BTA DM Security Procedures, Encryption Initiation & Key Management (15 functions, 1,416 bytes)

Decompiled and documented 15 functions (1,416 bytes across `0x600f1b72`–`0x600f20f6`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f1b72` |  370 | BTM / Security | **`BTM_SetEncryption`** — Initiates link encryption for target transport (BR/EDR vs BLE): returns success immediately if already encrypted, calls `0x600f0bb8` (BLE) or `0x600a7b44` (BR/EDR), or enqueues if busy via `0x600a8228` (`btm_sec_queue_encrypt_request`). | 3 callers / 5 callees |
| `0x600f1ce4` |  194 | BTM / Security | **`bta_dm_sec_disconnect`** — Security-layer link disconnect: updates security state `+0x50` and issues HCI Disconnect via `0x600b218c` (`btsnd_hcic_disconnect`). | 6 callers / 1 callee |
| `0x600f1da6` |  126 | BTA / DM | **`bta_dm_store_link_key_type`** — Parses HCI link key notification and updates key type metadata at `+0x59` in device record (`0x600f1746`). | 1 caller / 1 callee |
| `0x600f1e24` |   96 | BTA / DM | **`bta_dm_update_clock_offset`** — Updates 16-bit clock offset field `+0xe` in device record (`0x6009feb8`) and inquiry database (`0x600a21e4` / `BTM_InqDbRead`). | 1 caller / 2 callees |
| `0x600f1e84` |   72 | BTM / Security | **`bta_dm_sec_connect_dev`** — Initiates BR/EDR security connection via `0x600a3014` (`btm_sec_rcv_conn_req`/connect initiator) with state tracking at `+0x50`. | 2 callers / 1 callee |
| `0x600f1ecc` |   36 | BTM / Security | **`bta_dm_sec_start_auth`** — Sets security state `+0x50 = 1` and issues HCI Authentication Requested via `0x600b264c` (`btsnd_hcic_auth_request`, HCI `0x0411`). | 2 callers / 1 callee |
| `0x600f1ef0` |   48 | BTM / Security | **`bta_dm_sec_start_encrypt`** — Issues HCI Set Connection Encryption (`0x0413`) via `0x600b26d0` (`btsnd_hcic_set_conn_encrypt`) and sets state `+0x50 = 2`. | 1 caller / 1 callee |
| `0x600f1f20` |   60 | BTA / DM Sec | **`bta_dm_is_service_mask_empty`** — Checks whether two 32-bit service mask words at `param_1` are both `-1` (all ones / empty). | 1 caller / 0 callees |
| `0x600f1f5c` |   38 | BTA / DM Sec | **`bta_dm_get_service_mask_ptr`** — Returns pointer to service security mask at `+4` in device record (`0x6009ff18`). | 2 callers / 1 callee |
| `0x600f1f82` |  102 | BTM / Security | **`bta_dm_sec_notify_cback`** — Fires security completion callback at `+0xf4` with status and context, then drains pending security request queue (`0x600a5760` / `btm_sec_check_pending_reqs`). | 8 callers / 1 callee |
| `0x600f1fe8` |   60 | BTA / DM | **`bta_dm_parse_handle_stub`** — Parses 12-bit connection handle from byte stream. | 1 caller / 0 callees |
| `0x600f2024` |   38 | BTA / DM Sec | **`bta_dm_is_open_service`** — Checks if service PSM/channel is open/unauthenticated (`0x0001` SDP or `0x0021` GAP/GATT). | 2 callers / 0 callees |
| `0x600f204a` |   54 | BTA / DM Sec | **`bta_dm_get_default_sec_mask`** — Returns default security mask combined with `param_1` (`0x1046` for BR/EDR, `0x2070` for BLE). | 2 callers / 0 callees |
| `0x600f2080` |   44 | BTA / DM BLE | **`bta_dm_ble_clear_keys`** — Clears byte `+0x7b = 0`, zeroes 104 bytes of BLE security keys at `+0x7c`, and resets resolving list state (`0x6009f8c8`). | 3 callers / 2 callees |
| `0x600f20ac` |   74 | BTA / DM Sec | **`bta_dm_is_device_mitm_protected`** — Checks if link has MITM protection (bit `0x1000` for BLE, bit `0x10` for BR/EDR on auth word `+0x2a` via `0x6009ff18`). | 5 callers / 1 callee |

**⚠️ QA session 121 note:** zero corrections — a fifth consecutive clean wave. Four citations match the established appendix exactly and unhedged: `0x600b218c`=`btsnd_hcic_disconnect` (opcode-verified `0x0406`), `0x600a21e4`=`BTM_InqDbRead`, `0x600a8228`=`btm_sec_queue_encrypt_request` (named), `0x600a5760`=`btm_sec_check_pending_reqs` (named). `bta_dm_sec_connect_dev`'s citation of `0x600a3014` as "`btm_sec_rcv_conn_req`/connect initiator" matches its established, consistently-hedged "very likely `btm_accept_connection`/`btm_sec_rcv_conn_req`-shaped" description. Two more claims aren't yet in the appendix but check out against the real Bluetooth spec directly: `bta_dm_sec_start_auth`'s cited opcode `0x0411` is the textbook-correct HCI Authentication Requested opcode (OGF `0x01` &lt;&lt; 10 | OCF `0x11`), and `bta_dm_sec_start_encrypt`'s cited `0x0413` is likewise correct for HCI Set Connection Encryption (OCF `0x13`) — both plausible, uncontradicted identifications for their respective callees (`0x600b264c`/`0x600b26d0`). Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,242 committed decomp files (484,820 bytes, 0 duplicates, 0 mismatches vs. census) — matches the doc's claimed 67.84% exactly. **One minor, informational note**: the wave's own commit-message headline total (15 functions, 1,416 bytes) is a 4-byte hand-count slip — the actual sum of this wave's 15 census sizes is 1,412 bytes; every individual address/size in the table above is correct, and the cumulative repository-wide totals (which are computed from file headers, not the commit's hand count) are unaffected, so no doc content needed correcting — flagged only for awareness, matching the same minor-arithmetic-slip pattern seen in a few earlier sessions (e.g. 31, 50). **Reliability read**: fifth clean wave in a row since the session-116 recovery — the appendix-cross-check discipline continues to hold solidly across this whole BTA DM security stretch.

## Session 122 (Wave 92) — Broadcom BTA DM HCI Event Handlers & Event Table Dispatchers (15 functions, 1,084 bytes)

Decompiled and documented 15 functions (1,084 bytes across `0x600f20f6`–`0x600f2532`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f20f6` |   42 | BTA / DM Inq | **`bta_dm_inq_cmpl_evt`** — Handles HCI Inquiry Complete event (`0x01`): forwards status byte to `0x600a2f3c` (`btm_process_inq_complete`). | 1 caller / 1 callee |
| `0x600f2120` |   28 | BTA / DM Inq | **`bta_dm_inq_result_evt`** — Handles HCI Inquiry Result event (`0x02`): forwards result buffer to `0x600a2ab0` (standard inquiry result parser, mode 0). | 1 caller / 1 callee |
| `0x600f213c` |   28 | BTA / DM Inq | **`bta_dm_inq_result_rssi_evt`** — Handles HCI Inquiry Result with RSSI event (`0x22`): forwards result buffer to `0x600a2ab0` (inquiry result with RSSI parser, mode 1). | 1 caller / 1 callee |
| `0x600f2158` |   98 | BTA / DM Conn | **`bta_dm_disconn_cmpl_evt`** — Handles HCI Disconnection Complete event (`0x05`): parses 12-bit handle and 8-bit reason, notifying L2CAP (`0x600b8ba4` / `l2c_link_hci_disc_comp`) and BTM (`0x600a730c`). | 1 caller / 2 callees |
| `0x600f21ba` |   72 | BTA / DM Sec | **`bta_dm_auth_cmpl_evt`** — Handles HCI Authentication Complete event (`0x06`): extracts status and handle, forwarding to `0x600a67ec` (`btm_sec_auth_complete`). | 1 caller / 1 callee |
| `0x600f2202` |   96 | BTA / DM RNR | **`bta_dm_rmt_name_cmpl_evt`** — Handles HCI Remote Name Request Complete event (`0x07`): extracts status, reverses 6-byte BD_ADDR, and delivers remote name string payload (`0x600a30f0` / `0x600a59d0`). | 1 caller / 2 callees |
| `0x600f2262` |   96 | BTA / DM Sec | **`bta_dm_enc_change_evt`** — Handles HCI Encryption Change event (`0x08`): extracts status, handle, and encryption mode (0=OFF, 1=ON BR/EDR, 2=ON AES-CCM LE), updating security state (`0x60099584` / `0x600a6b20`). | 1 caller / 2 callees |
| `0x600f22c2` |   72 | BTA / DM Sec | **`bta_dm_link_key_change_cmpl_evt`** — Handles HCI Change Connection Link Key Complete event (`0x09`): extracts status and handle, updating state via `0x600994b8`. | 1 caller / 1 callee |
| `0x600f230a` |   84 | BTA / DM Sec | **`bta_dm_master_link_key_cmpl_evt`** — Handles HCI Master Link Key Complete event (`0x0a`): extracts status, handle, and key flag, notifying waiters via `0x600a6aa4` (`btm_sec_link_key_notification`). | 1 caller / 1 callee |
| `0x600f235e` |   26 | BTA / DM ACL | **`bta_dm_read_rmt_features_cmpl_evt`** — Handles HCI Read Remote Supported Features Complete event (`0x0b`): forwards feature mask buffer to `0x60099a1c` (`btm_acl_read_remote_features_complete`). | 1 caller / 1 callee |
| `0x600f2378` |   90 | BTA / DM ACL | **`bta_dm_read_rmt_ext_features_cmpl_evt`** — Handles HCI Read Remote Extended Features Complete event (`0x23`): routes success to `0x60099adc` or failure to `0x60099bb8`. | 1 caller / 2 callees |
| `0x600f23d2` |   26 | BTA / DM ACL | **`bta_dm_read_rmt_version_cmpl_evt`** — Handles HCI Read Remote Version Information Complete event (`0x0c`): delivers LMP version/manufacturer buffer to `0x600998ec`. | 1 caller / 1 callee |
| `0x600f23ec` |  278 | BTA / DM QoS | **`bta_dm_qos_setup_cmpl_evt`** — Handles HCI QoS Setup Complete event (`0x0d`): parses 18-byte flow specification struct (flags, service type, token rate, peak bandwidth, latency, delay variation) and dispatches via `0x6009a154`. | 1 caller / 1 callee |
| `0x600f2502` |   24 | BTA / DM | **`bta_dm_hci_event_null_handler`** — No-op stub handler in HCI event dispatch table at `0x600a89f0`. | 1 caller / 0 callees |
| `0x600f251a` |   24 | BTA / DM | **`bta_dm_hci_event_stub_handler`** — No-op stub handler in HCI event dispatch table at `0x600a89f0`. | 1 caller / 0 callees |

**⚠️ QA session 122 note:** zero corrections — a sixth consecutive clean wave, and one of the most thoroughly self-evidencing waves in this pipeline's history. All 15 functions share one caller, `0x600a89f0` (a genuine HCI event dispatch table), and all 13 non-stub rows cite a specific HCI event code — every single one matches the real Bluetooth Core Spec Event Code table exactly: `0x01` Inquiry Complete, `0x02` Inquiry Result, `0x22` Inquiry Result with RSSI, `0x05` Disconnection Complete, `0x06` Authentication Complete, `0x07` Remote Name Request Complete, `0x08` Encryption Change, `0x09` Change Connection Link Key Complete, `0x0a` Master Link Key Complete, `0x0b` Read Remote Supported Features Complete, `0x23` Read Remote Extended Features Complete, `0x0c` Read Remote Version Information Complete, `0x0d` QoS Setup Complete — thirteen independently-checkable exact spec matches in one wave. Four callee citations also match the established appendix exactly and unhedged: `0x600a2f3c`=`btm_process_inq_complete`, `0x600b8ba4`=`l2c_link_hci_disc_comp`, `0x600a6aa4`=`btm_sec_link_key_notification`, `0x60099a1c`=`btm_acl_read_remote_features_complete` (QA-verified). Three pre-existing forward-references in the appendix also paid off, each anticipating one of this wave's own caller relationships before it was decompiled: `0x600a67ec`'s entry already cited "called from HCI event sub-handler `0x600f21ba`", `0x600a2ab0`'s already cited callers `0x600f2120`/`0x600f213c`, and `0x600a730c`'s already cited caller `FUN_600f2158` — all three confirmed exactly. `0x600994b8` and `0x6009a154` are both cited only functionally (no formal name re-asserted), correctly avoiding restating their already-corrected wrong original names, and `0x6009a154`'s "generic async-completion dispatcher with an optional payload" corrected identity is nicely reinforced by this wave's own context (a QoS Setup Complete handler firing a completion callback with parsed QoS parameters as payload is exactly that shape). **One soft observation, not a correction**: `bta_dm_auth_cmpl_evt`'s citation of `0x600a67ec` as "`btm_sec_auth_complete`" asserts a more specific name than the established entry's own vaguer "ACL/encryption-change-style handler" hedge — plausible given the confirmed Authentication-Complete-event calling context (a real refinement of an uncommitted guess, not a contradiction), but not yet an appendix-confirmed exact match either. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,257 committed decomp files (485,904 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 68.00% exactly, a milestone crossing. **Reliability read**: sixth clean wave in a row since the session-116 recovery — this session's density of independently-checkable exact matches (13 spec event codes + 4 appendix names + 3 forward-references) is about as strong a wave-wide confirmation as this pipeline produces.

## Session 123 (Wave 93) — Broadcom BTA DM HCI Command Complete Opcode Dispatcher & Event Handlers (14 functions, 1,958 bytes)

Decompiled and documented 14 functions (1,958 bytes across `0x600f2532`–`0x600f2cd8`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f2532` | 1272 | BTA / DM HCI | **`bta_dm_hci_cmd_cmpl_evt`** — Main HCI Command Complete event (`0x0e`) opcode switch router: parses opcode and dispatches to over 30 BTM/BTA complete handlers (`0x600a125c`, `0x600a32d4`, `0x600a1648`, `0x600a2f3c`, `0x600a5714`, `0x600a2884`, `0x600a15b8`, `0x600a038c`, `0x6009a2c8`, `0x600a1698`, `0x600a11c0`, `0x600a0fd4`, `0x600c70ac`, etc.). | 2 callers / 34 callees |
| `0x600f2a2a` |   14 | BTA / DM | **`bta_dm_hci_event_null_handler`** — No-op stub handler. | 1 caller / 0 callees |
| `0x600f2a38` |   42 | BTA / DM HCI | **`bta_dm_hw_error_evt`** — Handles HCI Hardware Error event (`0x10`): notifies inquiry filters via `0x600a17c0` (`btm_notify_inquiry_filter_complete`) and triggers device reset if up (`0x600a01a0` / `0x600a014c` / `BTM_DeviceReset`). | 1 caller / 3 callees |
| `0x600f2a62` |   24 | BTA / DM | **`bta_dm_hci_event_null_handler`** — No-op stub handler in HCI event table (`0x600a89f0`). | 1 caller / 0 callees |
| `0x600f2a7a` |  102 | BTA / DM ACL | **`bta_dm_page_scan_rep_mode_chg_evt`** — Handles HCI Page Scan Repetition Mode Change event (`0x20`): parses status, BD_ADDR, and mode, notifying L2CAP (`0x600b9358` / `l2c_link_send_to_lower`) and BTM ACL (`0x60099dd0`). | 1 caller / 2 callees |
| `0x600f2ae0` |   26 | BTA / DM L2CAP | **`bta_dm_num_compl_pkts_evt`** — Handles HCI Number of Completed Packets event (`0x13`): forwards buffer to L2CAP flow controller (`0x600b9938` / `l2c_link_hci_num_compl_pkts`). | 1 caller / 1 callee |
| `0x600f2afa` |  112 | BTA / DM Policy | **`bta_dm_mode_chg_evt`** — Handles HCI Mode Change event (`0x14`): parses status, handle, mode (Active/Hold/Sniff/Park), and interval, notifying BTM via `0x600a3d8c`. | 1 caller / 1 callee |
| `0x600f2b6a` |   56 | BTA / DM Sec | **`bta_dm_return_link_keys_evt`** — Handles HCI Return Link Keys event (`0x15`): delivers stored keys buffer to BTM via `0x600a16fc`. | 1 caller / 1 callee |
| `0x600f2ba2` |   70 | BTA / DM Sec | **`bta_dm_pin_code_req_evt`** — Handles HCI PIN Code Request event (`0x16`): reverses 6-byte BD_ADDR and requests PIN from upper layer (`0x600f8bd4` / `0x600a7870`). | 1 caller / 2 callees |
| `0x600f2be8` |   60 | BTA / DM Sec | **`bta_dm_link_key_req_evt`** — Handles HCI Link Key Request event (`0x17`): reverses 6-byte BD_ADDR and queries stored link key via `0x600a7634` (`btm_sec_link_key_req`). | 1 caller / 1 callee |
| `0x600f2c24` |  108 | BTA / DM Sec | **`bta_dm_link_key_notification_evt`** — Handles HCI Link Key Notification event (`0x18`): reverses 6-byte BD_ADDR, 16-byte link key, and delivers key type via `0x600a74dc`. | 1 caller / 1 callee |
| `0x600f2c90` |   24 | BTA / DM | **`bta_dm_hci_event_null_handler`** — No-op stub handler in HCI event table (`0x600a89f0`). | 1 caller / 0 callees |
| `0x600f2ca8` |   24 | BTA / DM | **`bta_dm_hci_event_null_handler`** — No-op stub handler in HCI event table (`0x600a89f0`). | 1 caller / 0 callees |
| `0x600f2cc0` |   24 | BTA / DM | **`bta_dm_hci_event_null_handler`** — No-op stub handler in HCI event table (`0x600a89f0`). | 1 caller / 0 callees |

**⚠️ QA session 123 note:** zero corrections needed to this wave's own claims — every one of them held up, several precisely — but two significant *pre-existing* `bruce-bta-stack.md` entries turned out stale, superseded by the fresh calling context this wave's decompiles provide (a seventh consecutive clean wave for this doc, with the interesting findings landing on old entries elsewhere instead). Five callee citations match the established appendix exactly: `0x600a17c0`=`btm_notify_inquiry_filter_complete`, `0x600a01a0`=`BTM_IsDeviceUp`, `0x600a014c`=`BTM_DeviceReset`, `0x600b9358`=`l2c_link_send_to_lower`, `0x600a7634`=`btm_sec_link_key_req`. Beyond the appendix, this wave continues session 122's streak of exact real-spec HCI event code matches — `0x10` Hardware Error, `0x13` Number of Completed Packets, `0x14` Mode Change, `0x15` Return Link Keys, `0x16` PIN Code Request, `0x17` Link Key Request, `0x18` Link Key Notification, `0x20` Page Scan Repetition Mode Change, and the umbrella `0x0e` Command Complete for the giant 1272-byte opcode router — all textbook-correct. **Two stale appendix entries corrected** (in `analysis/bruce-bta-stack.md`, not this doc): `0x600a16fc` was previously guessed as `btm_ble_read_resolving_list_complete` from its body shape alone (reverse 6-byte + 16-byte fields per entry); this wave's decompile of its sole caller, `bta_dm_return_link_keys_evt` (`0x600f2b6a`), shows it's dispatched from the classic HCI event table at the slot for event `0x15` (Return Link Keys) — whose real wire format is exactly `num_keys` × {BD_ADDR, Link_Key}, matching the reversal loop precisely; real identity is Return-Link-Keys array processing, not BLE resolving-list/IRK handling. Similarly `0x600a74dc` was previously described only by its final, conditional action (calling the confirmed `btsnd_hcic_rmt_name_req`), leading to a "remote-name-request flow" framing; reading its full 336-byte body against this wave's new context (`bta_dm_link_key_notification_evt`, HCI event `0x18`) shows its primary action is finding the device record and storing a 16-byte link key plus key type into it — the remote-name request is a genuine but secondary, conditionally-gated follow-up step in the pairing sequence, not the function's main purpose. Both corrected in place with full evidence; this wave's own claims for `0x600f2b6a`/`0x600f2c24` needed no changes — they were the more accurate identifications all along. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join across all 3,271 committed decomp files (487,862 bytes, 0 duplicates, 0 mismatches vs. census) — matches the wave's claimed 68.27% exactly. **Reliability read**: a genuinely productive session in the "cross-reference cuts both ways" category (like session 114) — this wave's own content was uniformly solid, and the value came from using its fresh calling-context evidence to upgrade two isolated, shape-only guesses elsewhere in the doc into properly-grounded identifications.

## Session 124 (Wave 94) — Broadcom BTA DM HCI Event Handlers & LE-Meta Sub-Dispatchers (21 functions, 868 bytes)

Decompiled and documented 21 functions (868 bytes across `0x600f2cd8`–`0x600f303c`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f2cd8` |  128 | BTA / DM HCI | **`bta_dm_read_clock_offset_cmpl_evt`** — Handles HCI Read Clock Offset Complete event (`0x1c`): parses handle and clock offset, updating ACL record (`0x60099d8c`) and device/inquiry records (`0x600f1e24` / `bta_dm_update_clock_offset`). | 1 caller / 2 callees |
| `0x600f2d58` |   24 | BTA / DM | **`bta_dm_hci_event_null_handler`** — No-op stub handler in HCI event table (`0x600a89f0`). | 1 caller / 0 callees |
| `0x600f2d70` |   64 | BTA / DM ACL | **`bta_dm_conn_packet_type_chg_evt`** — Handles HCI Connection Packet Type Changed event (`0x1d`): extracts connection handle and invokes `0x600f8a96`. | 1 caller / 1 callee |
| `0x600f2db0` |   24 | BTA / DM | **`bta_dm_hci_event_null_handler`** — No-op stub handler in HCI event table (`0x600a89f0`). | 1 caller / 0 callees |
| `0x600f2dc8` |   24 | BTA / DM | **`bta_dm_hci_event_null_handler`** — No-op stub handler in HCI event table (`0x600a89f0`). | 1 caller / 0 callees |
| `0x600f2de0` |   26 | BTA / DM Sec | **`bta_dm_link_key_notification_alt_evt`** — Link key notification handler forwarding buffer to `0x600f1da6` (`bta_dm_store_link_key_type`). | 1 caller / 1 callee |
| `0x600f2dfa` |   26 | BTA / DM SCO | **`bta_dm_sync_conn_cmpl_evt`** — Handles HCI Synchronous Connection Complete event (`0x2c`): forwards buffer to `0x600a5ec8` (`btm_sco_conn_complete`). | 1 caller / 1 callee |
| `0x600f2e14` |   26 | BTA / DM SCO | **`bta_dm_sync_conn_chg_evt`** — Handles HCI Synchronous Connection Changed event (`0x2d`): forwards buffer to `0x600a6184` (`btm_sco_conn_changed`). | 1 caller / 1 callee |
| `0x600f2e2e` |   28 | BTA / DM Policy | **`bta_dm_sniff_subrating_evt`** — Handles HCI Sniff Subrating event (`0x2e`): forwards mode 2 and buffer to `0x600a62cc`. | 1 caller / 1 callee |
| `0x600f2e4a` |   28 | BTA / DM Inq | **`bta_dm_ext_inq_result_evt`** — Handles HCI Extended Inquiry Result event (`0x2f`): forwards mode 4 and buffer to `0x600a62cc`. | 1 caller / 1 callee |
| `0x600f2e66` |   28 | BTA / DM Sec | **`bta_dm_enc_key_refresh_cmpl_evt`** — Handles HCI Encryption Key Refresh Complete event (`0x30`): forwards mode 3 and buffer to `0x600a62cc`. | 1 caller / 1 callee |
| `0x600f2e82` |   26 | BTA / DM Sec | **`bta_dm_io_cap_req_evt`** — Handles HCI IO Capability Request event (`0x31`, event-code slot well-supported by its sequential position 0x30/0x31/0x32/0x33 among neighboring rows): ~~forwards buffer to `0x600a6598` (`btm_sec_io_cap_req`)~~ ⚠️ `0x600a6598`'s own body (BD_ADDR reversal into a stack buffer, then invoking the `btm_sec_cb+0x1134` callback with a **hardcoded literal event code `5`**, no IO-capability-specific fields read anywhere) is byte-for-byte the already-established `bruce-bta-stack.md` `btm_sec_rmt_name_failed`-shaped generic security-completion notifier, not an IO-cap-specific handler. *(corrected, QA session 124)* | 1 caller / 1 callee |
| `0x600f2e9c` |   88 | BTA / DM Sec | **`bta_dm_io_cap_rsp_evt`** — Handles HCI IO Capability Response event (`0x32`): extracts connection handle and role, notifying BTM security via `0x60099cc0`. | 1 caller / 1 callee |
| `0x600f2ef4` |   26 | BTA / DM Sec | **`bta_dm_user_conf_req_evt`** — Handles HCI User Confirmation Request event (`0x33`, event-code slot well-supported positionally): ~~forwards buffer to `0x600a65f4` (`btm_sec_user_conf_req`)~~ ⚠️ `0x600a65f4` parses a BD_ADDR + a single HCI **status/reason byte** (special-casing `0x18` Pairing Not Allowed vs. success vs. a BD_ADDR-mismatch path) and invokes the same `btm_sec_cb+0x1134` callback mechanism as `0x600a6598` with a hardcoded literal event code `8` — it never reads a Numeric_Value field, which a real User Confirmation Request (BD_ADDR + 6-digit numeric value to display) would require. Matches the already-established, hedged `bruce-bta-stack.md` "link-key/security-completion event handler... not conclusively named" entry; not `btm_sec_user_conf_req`. *(corrected, QA session 124)* | 1 caller / 1 callee |
| `0x600f2f0e` |   28 | BTA / DM | **`bta_dm_hci_event_null_handler`** — No-op stub handler in HCI event table (`0x600a89f0`). | 1 caller / 0 callees |
| `0x600f2f2a` |   86 | BTA / DM Sec | **`bta_dm_simple_pairing_cmpl_evt`** — Handles HCI Simple Pairing Complete event (`0x36`): extracts status and handle, notifying BTM security via `0x600a6b20` (`btm_sec_enc_change_complete`). | 1 caller / 1 callee |
| `0x600f2f80` |   26 | BTA / DM Inq | **`bta_dm_inq_result_ext_evt`** — Handles HCI Extended Inquiry Result event dispatcher forwarding buffer to `0x6009e3f0` (`btm_process_inq_results`). | 1 caller / 1 callee |
| `0x600f2f9a` |   32 | BTA / DM BLE | **`bta_dm_ble_conn_cmpl_evt`** — Handles HCI LE Connection Complete event (`0x3e`/subevent `0x01`): forwards buffer and mode 0 to `0x6009b368`. | 1 caller / 1 callee |
| `0x600f2fba` |   32 | BTA / DM BLE | **`bta_dm_ble_enh_conn_cmpl_evt`** — Handles HCI LE Enhanced Connection Complete event (`0x3e`/subevent `0x0a`): forwards buffer and mode 1 to `0x6009b368`. | 1 caller / 1 callee |
| `0x600f2fda` |   72 | BTA / DM BLE | **`bta_dm_ble_adv_report_evt`** — Handles HCI LE Advertising Report event (`0x3e`/subevent `0x02`): extracts handle and status, notifying `0x600f7d46`. | 1 caller / 1 callee |
| `0x600f3022` |   26 | BTA / DM BLE | **`bta_dm_ble_conn_update_cmpl_evt`** — Handles HCI LE Connection Update Complete event (`0x3e`/subevent `0x03`): forwards buffer to `0x6009eab4`. | 1 caller / 1 callee |

**⚠️ QA session 124 note:** Backbone clean — all 21 addresses/sizes match the census exactly, summing to the claimed 868 bytes, in one fully contiguous run (`0x600f2cd8`–`0x600f303c`) with zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,292 functions / 488,730 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 68.39% exactly.

**Major finding — a systemic "LE-Meta sub-dispatch" mislabel affecting 5 *pre-existing* `bruce-bta-stack.md` entries, not this wave's own rows**: this wave's own event-table entry point, `0x600a89f0` (the top-level HCI event dispatcher), is correctly documented as having BOTH a classic top-level event switch AND a nested LE-Meta (event `0x3e`) sub-switch. But a full grep for "LE-Meta" across `bruce-bta-stack.md` turned up several older entries describing their *caller* as living inside that nested LE-Meta sub-dispatch — when, per this wave's own freshly-confirmed classic-event handlers, those same callers are actually classic (non-`0x3e`) event handlers. Traced and corrected all 5 instances, cross-referencing this wave's own new rows as ground truth for which handler is classic vs. LE:
- `0x600a5ec8` (line 111) — real caller `0x600f2dfa` is this wave's own `bta_dm_sync_conn_cmpl_evt`, the classic handler for HCI event `0x2c` (Synchronous Connection Complete), not an LE-Meta subevent; `btm_sco_conn_complete`-shaped.
- `0x600a62cc` (line 112) — real callers `0x600f2e2e`/`0x600f2e4a`/`0x600f2e66` are this wave's own classic handlers for events `0x2e`/`0x2f`/`0x30`.
- `0x600a6184` (line 421) — real caller `0x600f2e14` is this wave's own `bta_dm_sync_conn_chg_evt`, classic event `0x2d` (Synchronous Connection Changed); `btm_sco_conn_changed`-shaped.
- `0x600a730c` (line 423, first mislabeled instance noted session 122) — real caller `0x600f2158` is the previously-confirmed `bta_dm_disconn_cmpl_evt`, classic event `0x05`.
- `0x600b9938` (line 453, first mislabeled instance noted session 123) — real caller `0x600f2ae0` is the previously-confirmed `bta_dm_num_compl_pkts_evt`, classic event `0x13`; `l2c_link_hci_num_compl_pkts`-shaped.

All 5 corrected in place in `analysis/bruce-bta-stack.md` with their real (classic) caller and event code. No `GHIDRA-TODO` needed — identification-only, no boundary issues.

**Two further findings, this wave's own rows — both share one underlying shape**: `0x600f2e82` (`bta_dm_io_cap_req_evt`, HCI event `0x31`) claimed its callee `0x600a6598` as `btm_sec_io_cap_req`, and `0x600f2ef4` (`bta_dm_user_conf_req_evt`, event `0x33`) claimed its callee `0x600a65f4` as `btm_sec_user_conf_req` — both event-code identifications are well-supported by their sequential positioning among neighboring rows (`0x30`/`0x31`/`0x32`/`0x33` in order), but neither callee's own body supports the specific formal name given. `0x600a6598`'s body (BD_ADDR reversal, then a callback invoked via `btm_sec_cb+0x1134` with a hardcoded literal event code `5`, no IO-capability-specific fields anywhere) is byte-for-byte the already-established `btm_sec_rmt_name_failed`-shaped generic security-completion notifier. `0x600a65f4`'s body parses a BD_ADDR + a single HCI status/reason byte (special-casing `0x18` Pairing Not Allowed) and invokes the *same* `btm_sec_cb+0x1134` callback mechanism with a different hardcoded literal event code (`8`) — it never reads a Numeric_Value field, which a real User Confirmation Request handler would need, and the already-established (independently, from an earlier session, hedged as "not conclusively named") `bruce-bta-stack.md` entry for this address matches this description exactly. The real SSP user-confirmation logic is already confirmed to live in the separate, already-established `0x600a4a20` (auto-accept/reject via `btsnd_hcic_user_conf_reply`). Both corrected in place; strengthened `0x600a65f4`'s `bruce-bta-stack.md` entry with the new cross-referencing evidence rather than re-hedging it further. Likely explanation for both: `0x600a6598`/`0x600a65f4` are plausibly two members of one small family of shared, generic "notify security-layer completion via a hardcoded event code" helpers reused across several different HCI security event slots, not event-specific named handlers — the same "identity assigned from the calling event slot rather than from what the body computes" failure mode flagged repeatedly in this pipeline's crypto-cluster QA passes (sessions 90–106), now also confirmed in the BTA DM event-handler cluster.

Spot-checked the remaining named citations: `0x6009e3f0` (cited by `bta_dm_inq_result_ext_evt`) is an exact match to the already-established `btm_process_inq_results`. `0x6009b368` (cited by both LE Connection Complete handlers) has an existing, correctly-scoped generic entry ("LE connection-complete-style event parser") consistent with serving two related LE event subtypes — left as-is. `0x60099cc0`'s already-corrected (prior session) generic "conditionally forwards via indirect callback" description remains consistent with this wave's non-specific "notifying BTM security via `0x60099cc0`" phrasing — no new conflict. `0x6009eab4`'s prior QA correction (not `BTM_SecAuthenticate`) is untouched by this wave, which cites it without asserting any specific name — consistent.

**Reliability read**: the headline finding this session is structural rather than per-function — a labeling assumption ("caller lives in the LE-Meta sub-dispatch") that was baked into 5 different `bruce-bta-stack.md` rows across several earlier sessions, only exposed once this wave's own fresh classic-event decompiles gave concrete ground truth for what those callers actually are. The two per-function findings continue a now well-established pattern in this specific event-handler cluster: an event slot's own identification (well-supported by sequential positioning) doesn't transfer to its callee's identification without independently reading the callee's body — both `0x600a6598` and `0x600a65f4` turned out to be shared generic notifiers, not the event-specific names their calling context suggested.

## Session 125 (Wave 95) — Broadcom BTA DM / GATTC Subsystems & SMP Key / Signature Verification (16 functions, 1,508 bytes)

Decompiled and documented 16 functions (1,508 bytes across `0x600f303c`–`0x600f3620`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f303c` |   94 | BTA / DM BLE | **`bta_dm_ble_read_remote_features_cmpl_evt`** — Handles HCI LE Read Remote Features Complete event (`0x3e`/subevent `0x04`): unpacks handle and 8-byte feature buffer, updating BTM BLE state via `0x6009af60`. | 1 caller / 1 callee |
| `0x600f309a` |  178 | BTA / DM BLE | **`bta_dm_ble_rc_param_req_evt`** — Handles HCI LE Remote Connection Parameter Request event (`0x3e`/subevent `0x05`): unpacks handle, conn_interval_min/max, latency, and timeout, notifying `0x600f7f74`. | 1 caller / 1 callee |
| `0x600f314c` |  122 | BTA / DM BLE | **`bta_dm_ble_data_length_change_evt`** — Handles HCI LE Data Length Change event (`0x3e`/subevent `0x07`): unpacks handle, max_tx_octets, and max_rx_octets, notifying `0x600f808c`. | 1 caller / 1 callee |
| `0x600f31c6` |   32 | BTA / DM | **`bta_dm_init_services`** — Stack subsystem init coordinator: calls `btm_sec_init` (`0x600a333c`), `btm_sec_dev_rec_init` (`0x600bb1f8`), `sdp_init` (`0x600bdd9c`), `gatt_init_subsystem` (`0x600ad610`), `btm_ble_sec_init` (`0x600c04f4`), and discovery init (`0x6009eda4`). | 1 caller / 6 callees |
| `0x600f31e6` |   72 | BTA / GATTC | ~~**`bta_gattc_cfg_param_setter`** — GATT client configuration parameter updater: sets configuration values and notifies GATT core via `0x600aa8f0`.~~ ⚠️ `0x600aa8f0` is already independently established (`bruce-bta-stack.md`) as the GAP service's characteristic-value **READ**-getter (walks a 4-entry table, switches on UUID `0x2a00`/`0x2a01`/`0x2a04`/`0x2aa6`, returns the characteristic's value) — there is no "set"/write semantics anywhere in that callee. This function's real shape is a thin **read-request builder/dispatcher**: it populates an output struct (`param_3`) with a handle and an optional extra field from the input request (`param_2`), then performs the read via `0x600aa8f0` and returns its result — not a config "setter." *(corrected, QA session 125)* | 0 callers / 1 callee |
| `0x600f322e` |  124 | BTA / GATTC | **`bta_gattc_read_char_descr`** — GATT client read descriptor/value initiator: calls `0x600aa8a4` to resolve attribute handle, formats `tGATT_READ_PARAM`, and initiates read via `GATTC_Read` (`0x600ab620`). | 3 callers / 3 callees |
| `0x600f32aa` |  110 | BTA / GATTC | **`bta_gattc_read_cb_dispatcher`** — GATT client read callback dispatcher: invokes registered completion callback (`blx r4`), continuing multi-read chain via `0x600f322e` or cleaning up via `0x600f3da6` / `0x600aa800`. | 2 callers / 3 callees |
| `0x600f3318` |   96 | BTA / GATTC | **`bta_gattc_register_service_read`** — GATT client service read manager: finds client control block via `0x600aa6f0`, setting handle and triggering read via `0x600f322e` or closing via `0x600f32aa`. | 0 callers / 4 callees |
| `0x600f3378` |  308 | BTA / GATTC | **`bta_gattc_read_cmpl_handler`** — GATT client read complete dispatcher: routes characteristic values for UUID `0x2a04` (Peripheral Preferred Conn Params -> `0x600f0726` / ~~`bta_dm_ble_update_conn_params`~~ ⚠️ `0x600f0726` is already independently established (session 117, QA-confirmed clean) as `bta_dm_ble_set_conn_params`, not `_update_`; the 4-value (min/max interval, latency, timeout) argument shape cited here matches that established signature exactly, only the specific name was wrong. *(corrected, QA session 125)*), `0x2aa6` (Central Address Resolution), and `0x2a00` (Device Name -> `0x6004cb28` `strlen`), delivering results via `0x600f32aa`. Strong spec corroboration: all three UUIDs (`0x2a04`, `0x2aa6`, `0x2a00`) match the real Bluetooth SIG GATT characteristic assignments exactly, and the same trio (plus `0x2a01`) is independently used by the already-established GAP read-getter `0x600aa8f0`. | 0 callers / 4 callees |
| `0x600f34ac` |   30 | BTA / GATTC | **`bta_gattc_read_conn_params`** — GATT client query helper: requests characteristic UUID `0x2a04` via `0x600aae30`. | 1 caller / 1 callee |
| `0x600f34ca` |   32 | BTA / GATTC | **`bta_gattc_read_device_name`** — GATT client query helper: requests characteristic UUID `0x2a00` via `0x600aae30`. | 1 caller / 1 callee |
| `0x600f34ea` |   24 | BTA / GATTC | ~~**`bta_gattc_start_service_disc_pri`** — GATT client primary service discovery trigger: calls `0x600aaf38(0, param_1)`.~~ ⚠️ `0x600aaf38` is already independently established (`bruce-bta-stack.md`) as `gap_process_gatt_operation_comp`, a 2-slot **completion**-callback dispatcher — its own body (read directly this QA pass) invokes a registered callback for slot 0/1 with the transformed data, then deactivates that slot via `0x600f351a` (this wave's own, correctly-identified `bta_gattc_cleanup_conn_rec`). There is no discovery-request construction or GATT send anywhere in it. Real behavior of `0x600f34ea`/`0x600f3502` is signaling **completion** of a pending slot-0/slot-1 operation, not triggering/starting one — direction is backward. *(corrected, QA session 125)* | 0 callers / 1 callee |
| `0x600f3502` |   24 | BTA / GATTC | ~~**`bta_gattc_start_service_disc_sec`** — GATT client secondary service discovery trigger: calls `0x600aaf38(1, param_1)`.~~ ⚠️ Same correction as `0x600f34ea` above — `0x600aaf38` is a completion dispatcher, not a discovery trigger. *(corrected, QA session 125)* | 0 callers / 1 callee |
| `0x600f351a` |   38 | BTA / GATTC | **`bta_gattc_cleanup_conn_rec`** — GATT client connection record cleanup helper: clears pending state flags at `+0x4`, `+0xf`. | 1 caller / 0 callees |
| `0x600f3540` |  110 | GATT / SMP | **`gatt_sec_derive_keys`** — GATT / SMP crypto key derivation helper: resolves attribute handles via `gatt_find_hdl_buffer_by_app_id` (`0x600af3f4`) and invokes `0x600f52ee`. | 1 caller / 2 callees |
| `0x600f35ae` |  114 | GATT / SMP | **`gatt_sec_verify_signature`** — GATT / SMP signature verification helper: validates auth flags (`0x40` signed write / `0x180` MITM/encryption) and invokes `0x600f539c`. | 3 callers / 2 callees |

**⚠️ QA session 125 note:** Backbone clean — all 16 addresses/sizes match the census exactly, summing to the claimed 1,508 bytes, fully contiguous `0x600f303c`–`0x600f3620`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,308 functions / 490,238 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 68.60% exactly.

**Three findings, all caught by cross-checking this wave's named callees against `bruce-bta-stack.md`'s existing entries (the standing highest-value check in this pipeline):**

1. `0x600f31e6` (claimed `bta_gattc_cfg_param_setter`) claims to be a "configuration parameter... setter" that "notifies GATT core" via `0x600aa8f0` — but `0x600aa8f0` is already independently established as the GAP service's characteristic-value **READ**-getter (walks a 4-entry table keyed by handle, switches on UUID `0x2a00`/`0x2a01`/`0x2a04`/`0x2aa6`, returns the value) — there is no write/set semantics in that callee at all. Reading `0x600f31e6`'s own body confirms it: it populates an output struct with a handle (and optionally one extra field) from its input, then calls the READ-getter and returns its result — a read-request builder/dispatcher, not a setter.

2. `0x600f34ea`/`0x600f3502` (claimed `bta_gattc_start_service_disc_pri`/`_sec`, "service discovery triggers") both call `0x600aaf38`, already independently established as `gap_process_gatt_operation_comp`, a 2-slot **completion**-callback dispatcher. Read `0x600aaf38`'s own body directly this pass: for slot 0/1, if active, it transforms the input data by a stored type code, invokes the slot's registered callback, then **deactivates the slot** by calling `0x600f351a` — this wave's own, correctly-identified `bta_gattc_cleanup_conn_rec` (which clears the exact `+4`/`+0xf` callback-pointer/active-flag fields `0x600aaf38` just finished using). This is unambiguously a completion-signaling pattern (invoke-then-deactivate), not a discovery-initiation one — no discovery request is ever constructed or sent. The two functions' real role is signaling completion of a pending slot-0/slot-1 operation, direction backward from the claim.

3. `0x600f3378`'s citation of `0x600f0726` as `bta_dm_ble_update_conn_params` doesn't match: that address is already independently established (session 117, QA-confirmed clean with zero corrections) as `bta_dm_ble_set_conn_params`. The underlying call itself is correct — the 4-value (min interval, max interval, latency, timeout) argument shape unpacked here from the real Peripheral Preferred Connection Parameters (UUID `0x2a04`) characteristic matches that established function's own signature exactly — only the specific name ("update" vs. "set") was wrong.

All three corrected in place; no `GHIDRA-TODO` needed (identification-only, no boundary issues).

**Confirmed correct / positive corroboration**: `0x600ab620` matches the established `GATTC_Read`-shaped identity exactly (used by `bta_gattc_read_char_descr`/`0x600f322e`). `0x600af3f4` matches the established `gatt_find_hdl_buffer_by_app_id` exactly (used by both `gatt_sec_derive_keys`/`0x600f3540` and `gatt_sec_verify_signature`/`0x600f35ae`). `0x600aae30` matches the established `gap_read_attr_value` exactly, and its two new callers (`0x600f34ac`/`0x600f34ca`) cite real Bluetooth SIG UUIDs (`0x2a04` Peripheral Preferred Connection Parameters, `0x2a00` Device Name) that also independently match the UUID table already read out of `0x600aa8f0`'s own body — good cross-consistency. `0x600f322e`'s citation of `0x600aa8a4` as "resolve attribute handle" is a reasonable informal restatement of the established `gap_dequeue_operation` ("dequeues next pending GATT client operation and frees queue node") — dequeuing naturally yields the handle to act on next; not flagged as an error. The `bta_dm_init_services` (`0x600f31c6`) cluster's six callee citations (`btm_sec_init`/`btm_sec_dev_rec_init`/`sdp_init`/`gatt_init_subsystem`/`btm_ble_sec_init`, plus the unnamed `0x6009eda4`) all match their established `bruce-bta-stack.md` identities exactly; notably `0x6009eda4` was QA-corrected in an earlier session from a wrong RSSI-processing name to a generic "struct zero-and-default-init function" with "0 real callers" — this wave gives it its first real, well-fitting caller (a subsystem-init coordinator invoking a generic init/zero routine), a nice confirming callback on that earlier correction. `0x600f3378`'s three routed UUIDs (`0x2a04`, `0x2aa6`, `0x2a00`) all independently match real Bluetooth SIG GATT characteristic assignments.

**Reliability read**: a moderate-correction wave (3 of 16 rows) with a shared root cause across findings 1 and 2 — both misread a callee's *direction* (read vs. write in #1, completion vs. initiation in #2) despite the callee already having a clear, previously-verified established identity one grep away. Finding 3 is the pipeline's now-familiar "informal synonym instead of the established name" citation slip. All three were caught purely by the standing "check every named callee against the existing appendix" technique, without needing fresh disassembly.

## Session 126 (Wave 96) — Broadcom GATT Server Value Indications/Notifications & Client Discovery/Connection APIs (14 functions, 1,922 bytes)

Decompiled and documented 14 functions (1,922 bytes across `0x600f3620`–`0x600f3da6`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f3620` |   94 | GATT / SMP | **`gatt_sec_verify_key_attr`** — GATT / SMP security attribute key validator: looks up handle buffer via `gatt_find_hdl_buffer_by_app_id` (`0x600af3f4`), validates key length (2, 4, 16), and calls `0x600f5446`. | 2 callers / 2 callees |
| `0x600f367e` |  340 | GATT / Server | **`gatts_send_handle_value_indication`** — GATT server handle value indication sender: validates registration (`0x600afd28`) and connection (`0x600af7c8`), formats indication packet, and transmits or queues via `0x600c7eb8` / `0x600ff9fe` / `0x600af2d0`. | 3 callers / 6 callees |
| `0x600f37d2` |  254 | GATT / Server | **`gatts_send_handle_value_notification`** — GATT server handle value notification sender: validates registration (`0x600afd28`) and connection (`0x600af7c8`), formats notification packet, and transmits via `0x600c7eb8` / `0x600ff9fe`. | 1 caller / 4 callees |
| `0x600f38d0` |  124 | GATT / Server | **`gatts_send_response`** — GATT server send response API: validates transaction ID `param_2 == *(int *)(iVar3 + 0x2c)` and sends server response via `0x600f622a`. | 2 callers / 3 callees |
| `0x600f394c` |   14 | GATT / Client | **`gattc_configure_mtu`** — ⚠️ **QA session 126 confirms and strengthens this wave's own "spurious split" note with byte-level proof**: direct disassembly of `0x600f394c`'s real prologue (`push {r7,lr}; sub sp,#0x18; add r7,sp,#0`) through its single real epilogue (`pop {r7,pc}` at `0x600f39fa`) shows ONE continuous, unbroken instruction stream — no branch, no return, and critically **no second prologue** anywhere at `0x600f395a` (the instruction there, `strh r3,[r7,#4]`, is a mid-stream continuation of the `mov r3,r2` two instructions earlier, not a function start). The real function is **176 bytes, `0x600f394c`–`0x600f39fc`**, with the single genuine caller `0x600fe00e` and the 5 callees `0x600f395a`'s row below lists (`0x600ffada`, `0x600afd84`, `0x600af7c8`, `0x600afd28`, `0x600afdf8`). `0x600f395a`'s claimed separate caller `0x60134420` is a distinct, currently-unresolved puzzle — see the row below. GATT client MTU exchange initiator: validates MTU range (23..517), allocates holding record via `0x600afdf8`, checks connection state (`+0x13 == 2`), and transmits MTU Request via `0x600ffada`. *(corrected, QA session 126)* | 1 caller / 5 callees |
| `0x600f395a` |  162 | GATT / Client | ~~**`gattc_configure_mtu_body`** — GATT client MTU exchange initiator body (continuation fragment of `0x600f394c`)~~ ⚠️ Not an independent function — see `0x600f394c` above, its true single owner (176 bytes total). **Unresolved puzzle, GHIDRA-TODO**: `0x600f394c`'s claimed caller `0x60134420` genuinely contains a raw `bl #0x600f395a` instruction at `0x6013444e` (disassembly-confirmed) — but at that exact call site, register r7 (used inside this address's rendered pseudocode as if it were a frame pointer) holds the unrelated literal `0xff` (set by `movs r7,#0xff` earlier in `0x60134420` and never reassigned before the call), which cannot be a valid frame-pointer value. Either `0x60134420`'s own disassembly desyncs somewhere before this point (plausible — a naive linear disassembly of that function hits clearly-garbage VFP/coprocessor instructions shortly afterward, consistent with an un-skipped literal pool or jump table), or a genuinely different mechanism is in play. This needs interactive Ghidra investigation (proper jump-table/xref analysis) that exceeds what QA can resolve from raw bytes alone — **GHIDRA-TODO: investigate the true target/mechanism of `0x60134420`'s `bl 0x600f395a` at `0x6013444e`, and merge `0x600f394c`/`0x600f395a` into one 176-byte function once resolved.** | 1 caller / 5 callees |
| `0x600f39fc` |  178 | GATT / Client | **`gattc_init_discovery`** — GATT client service discovery initiator: validates client and connection records (`0x600af7c8`, `0x600afd28`), allocates holding record (`0x600afdf8`), and initiates search via `0x600ac524`. | 2 callers / 5 callees |
| `0x600f3aae` |   44 | GATT / Client | ⚠️ **QA session 126**: confirmed a genuine boundary problem beyond what this wave's own "continuation fragment" note captured. Disassembly shows `0x600f3aae` itself has **no prologue** (opens with `ldr r3,[r7]`, referencing r7 as an already-valid frame pointer) — but more concretely, its claimed 44-byte end (`0x600f3ada`) is **not** where the real code stops: the next two instructions, previously read as the unclaimed "4-byte gap" before `0x600f3ade`, are genuine code (`0x600f3ada: mov sp,r7; 0x600f3adc: pop {r4,r5,r7,pc}`) — the real epilogue for whatever function this is, ending exactly where `0x600f3ade`'s own confirmed-genuine `push {r7,lr}` prologue begins. So this fragment's real span is at least `0x600f3aae`–`0x600f3ade` (46 bytes, not 44), and its true starting prologue (which must push `r4,r5,r7,lr` to match the confirmed pop) lies somewhere **before** `0x600f3aae`, not yet located. `0x600f39fc` (the immediately-preceding census entry) is independently confirmed complete and self-contained on its own terms, so this isn't simply an extension of that function either. **GHIDRA-TODO: locate this fragment's true prologue/entry point** (likely reached via an indirect/jump-table branch given the missing direct-call prologue) **and correct the `0x600f3aae` boundary** (currently 44 bytes, missing at least 2 trailing bytes of confirmed real code). ~~`gattc_discover_services_by_uuid` — GATT client UUID service discovery continuation fragment: formats UUID request parameters and forwards to `0x600ac524`~~ (underlying operation description plausible but unverifiable as an independent function until the boundary is resolved). | 1 caller / 1 callee |
| `0x600f3ade` |   44 | GATT / Client | ~~**`gattc_search_services`** — GATT client primary service discovery trigger: allocates holding record via `0x600afdf8` and starts discovery via `0x600f46b4`.~~ ⚠️ **QA session 128**: `0x600f46b4` is now confirmed (session 128) to send an ATT **Execute Write Request** (opcode `0x18`), not a discovery request — this function sets an operation-type field (`+0x31 = 4`) immediately before calling it, consistent with kicking off a queued/reliable write's execution, not starting service discovery. The setup steps (validate registration/connection, allocate a holding record via `0x600afdf8`) remain plausible for beginning *some* GATT client operation, but "search_services"/"starts discovery" is not supported by its actual callee; real purpose left unconfirmed rather than re-guessed. *(corrected, QA session 128)* | 1 caller / 1 callee |
| `0x600f3b0a` |  110 | GATT / Client | ⚠️ **QA session 126**: same missing-prologue red flag as `0x600f3aae` above (disassembly opens with `mov r0,r3; bl 0x600afd28`, referencing `[r7,...]` offsets and an undeclared `in_r3` with no `push`/frame setup at this address) — this is a genuine mid-function fragment, not an independent function, but its true owner/entry point is unresolved (part of the same `0x60134420`-adjacent puzzle as `0x600f395a` above). **GHIDRA-TODO: locate this fragment's true prologue/entry point.** ~~`gattc_search_services_body` — GATT client primary service discovery trigger body: validates registration and starts discovery via `0x600f46b4`~~ (underlying operation plausible but unverifiable independently until resolved). | 1 caller / 4 callees |
| `0x600f3b78` |  102 | GATT / Client | **`gattc_mtu_confirmation_cb`** — GATT client MTU exchange confirmation callback: stops timer `0x600aa3cc(local_10 + 0xe0)`, delivers completion event `0x1e` via `0x600ffada`, and clears flag `+0x96`. | 3 callers / 3 callees |
| `0x600f3bde` |  100 | GATT / Core | ~~**`gatt_disc_cmpl_handler`** — GATT disconnection completion handler: resolves connection record via `0x600af814`, disconnecting fixed channel 4 (`0x600f7a9c` / `0x600b4f34`) or L2CAP channel (`0x600b4ec4`).~~ ⚠️ Two of the three callees this row itself cites are already independently established with descriptions that flatly contradict "disconnecting": `0x600b4f34` is `l2c_link_update_conn_params` — "**updates** BLE link connection latency/supervision timeout **parameters**" — and `0x600b4ec4` is `l2c_set_local_mtu_veneer` — a veneer to `l2c_set_local_mtu`, i.e. **sets** the MTU. Neither tears a connection down. Real behavior is far more likely a connection-parameter/MTU **reconfiguration dispatcher** (choosing between updating link params, an unestablished `0x600f7a9c`, or setting local MTU, based on the channel-type field `+0x18`), not a disconnection handler. *(corrected, QA session 126)* | 2 callers / 4 callees |
| `0x600f3c42` |  104 | GATT / Core | **`gatt_connect_dev`** — GATT connect / listen initiator: routes connection requests to `0x600f74a8` or background connection listener `0x600f5b32`. | 6 callers / 3 callees |
| `0x600f3caa` |  252 | GATT / Core | **`gatt_disconnect_dev`** — GATT disconnect / unlisten initiator: walks registered connection list and disconnects via `0x600f7278` or `0x600f7052`. | 5 callers / 6 callees |

**⚠️ QA session 126 note:** Backbone: all 14 addresses/sizes match the census exactly, summing to the claimed 1,922 bytes, but with one small structural wrinkle the byte-sum check doesn't catch on its own — a genuine 4-byte "gap" between `0x600f3aae`'s claimed end and `0x600f3ade`'s claimed start turned out, on investigation (see below), to be real code, not padding. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,322 functions / 492,160 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 68.87% exactly (the split-boundary finding below doesn't change the byte total, only the function-count/identity accounting, consistent with every prior finding of this class in this pipeline).

**Major finding — confirmed spurious function-boundary split, `0x600f394c`/`0x600f395a`, plus a related unresolved cluster.** This wave's own write-up already flagged `0x600f394c`/`0x600f395a` as a "spurious split" / "continuation fragment" — QA confirmed that framing is exactly right, with byte-level proof: direct disassembly of `0x600f394c`'s real prologue through its single real epilogue (`pop {r7,pc}` at `0x600f39fa`) shows one continuous, unbroken 176-byte instruction stream with no second prologue anywhere at `0x600f395a` (the instruction there is a mid-stream continuation of an assignment begun two instructions earlier). The real function is `0x600f394c`–`0x600f39fc` (176 bytes), with the single genuine caller `0x600fe00e`. **A second, harder puzzle surfaced while confirming this**: `0x600f395a`'s own claimed caller, `0x60134420`, genuinely contains a raw `bl #0x600f395a` instruction — but at that exact call site, register r7 holds an unrelated literal value (`0xff`) set earlier in `0x60134420` and never reassigned, which can't be a valid frame pointer for the code at `0x600f395a`. This is most likely explained by `0x60134420`'s own disassembly desyncing somewhere before that point (a naive linear disassembly of it hits clearly-garbage VFP/coprocessor instructions shortly after, consistent with an un-skipped literal pool or jump table) — but resolving it needs interactive Ghidra jump-table/xref analysis beyond what QA can do from raw bytes. **Two more functions in the same neighborhood, `0x600f3aae` and `0x600f3b0a`, show the identical missing-prologue red flag** (both open referencing `[r7,...]`/an undeclared register with no `push`/frame setup) — and investigating `0x600f3aae` specifically turned up a concrete, useful result: the "4-byte gap" noted in the backbone check between `0x600f3aae`'s claimed 44-byte end and `0x600f3ade`'s start is **not padding** — it's the real epilogue (`mov sp,r7; pop {r4,r5,r7,pc}`) for whichever function `0x600f3aae` belongs to, extending its true span to at least `0x600f3aae`–`0x600f3ade` (46 bytes) with its true prologue still unlocated (not simply the tail of the immediately-preceding, independently-complete `0x600f39fc`). All corrected/flagged in place with `GHIDRA-TODO`s for the boundary work; the underlying GATT-client MTU-exchange/service-discovery *themes* these fragments describe remain plausible, just unverifiable as independent-function claims until the real boundaries are resolved.

**Second finding**: `0x600f3bde` (claimed `gatt_disc_cmpl_handler`, "GATT disconnection completion handler") cites three callees, two of which are already independently established with descriptions that flatly contradict "disconnecting": `0x600b4f34` is `l2c_link_update_conn_params` ("updates BLE link connection latency/supervision timeout parameters") and `0x600b4ec4` is `l2c_set_local_mtu_veneer` (sets the MTU). Neither tears down a connection. Real behavior is much more likely a connection-parameter/MTU reconfiguration dispatcher, selecting among link-param-update, an unestablished third callee, and MTU-set based on a channel-type field. Corrected in place.

**Confirmed correct / positive corroboration** (non-fragment functions): `0x600aa3cc` matches the established `btu_stop_timer` exactly (`0x600f3b78`'s "stops timer `0x600aa3cc(local_10 + 0xe0)`" claim). `0x600afdf8`/`0x600afd28`/`0x600afd84`/`0x600af7c8` (GATT core registration/discovery/connection-holding-record primitives) are all used consistently with their established identities across this wave's MTU/discovery cluster. `0x600af2d0` (`gatt_add_pending_ind`) and `0x600c7eb8` (`bta_sys_dispatch_event`) are both consistent with this wave's "transmits or queues" framing for `gatts_send_handle_value_indication`/`_notification`.

No `GHIDRA-TODO` needed for the `gatt_disc_cmpl_handler` mislabel (identification-only). Two `GHIDRA-TODO`s filed for the boundary cluster: (1) investigate the true target/mechanism of `0x60134420`'s `bl 0x600f395a` and merge `0x600f394c`/`0x600f395a` into one 176-byte function once resolved; (2) locate `0x600f3aae`'s and `0x600f3b0a`'s true prologues/entry points and correct their boundaries.

**Reliability read**: a substantial-finding wave, but a good example of the write-up's own honesty helping rather than hindering — this wave's "spurious split"/"continuation fragment"/"_body" language for the boundary cluster already signaled awareness of a problem, and QA's contribution was supplying byte-level proof, discovering the fragment actually extends further (the "gap" resolution), and surfacing the deeper `0x60134420` puzzle that the write-up's framing didn't capture. The `gatt_disc_cmpl_handler` finding continues this pipeline's now-familiar pattern: correct callee citations, wrong verb/purpose for the enclosing function, caught by reading the cited callees' own established descriptions rather than trusting the name's plausibility.

## Session 127 (Wave 97) — Broadcom GATT Connection Management & Server Request / Client Discovery Handlers (15 functions, 1,404 bytes)

Decompiled and documented 15 functions (1,404 bytes across `0x600f3da6`–`0x600f4322`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f3da6` |   90 | GATT / Core | **`gatt_deregister_conn`** — GATT client connection deregisterer: detaches app channel via `0x600f5a98`, checks if connection active via `0x600f6dc6`, and tears down link via `0x600f592e` if empty. | 4 callers / 4 callees |
| `0x600f3e00` |  106 | GATT / Core | **`gatt_get_conn_info`** — GATT connection information getter (`GATT_GetConnectionInfor`): looks up `0x600afd28` (registration) and `0x600af7c8` (discovery), copies 6-byte BD_ADDR (`+0xd`), returns app_id and transport (`+0x13`). | 7 callers / 3 callees |
| `0x600f3e6a` |  108 | GATT / Core | **`gatt_get_conn_id_by_bd_addr`** — GATT connection ID lookup by BD_ADDR: looks up registration (`0x600afd28`) and connection (`0x600af814`), checks link state (`0x600f6132 == 4`), packs conn_id (`CONCAT11(tcb_idx, app_id)`). | 6 callers / 3 callees |
| `0x600f3ed6` |   96 | GATT / Core | **`gatt_listen_cmd`** — GATT listen initiator (`GATT_Listen`): updates listen mode flag `*(iVar1 + 0x2e)` or starts background connection via `0x600f74a8`, updating link controller via `0x600b076c`. | 3 callers / 3 callees |
| `0x600f3f36` |   26 | GATT / Discovery | **`gattc_zero_disc_record`** — GATT discovery record zeroer: zeroes 18-byte record `memset(param_1, 0, 0x12)`. | 2 callers / 1 callee |
| `0x600f3f50` |   32 | GATT / Discovery | **`gattc_free_disc_record`** — GATT discovery record cleaner: deregisters connection via `0x600f3da6` and zeroes record via `0x600f3f36`. | 2 callers / 2 callees |
| `0x600f3f70` |  232 | GATT / Server | **`gatts_process_req_dispatcher`** — GATT server request processing dispatcher: switches on GATT request opcode (Read `0x600abcb4`, Write `0x600abd38`), formatting and sending response via `0x600f38d0`. | 0 callers / 4 callees |
| `0x600f4058` |  104 | GATT / Discovery | **`gattc_disc_cmpl_step`** — GATT client discovery step callback: finds record via `0x600abc48`, clearing on failure (`0x600f3f36`) or advancing discovery step via `0x600abdac`. | 0 callers / 3 callees |
| `0x600f40c0` |  138 | GATT / Discovery | **`gattc_parse_char_descr_disc`** — GATT client characteristic / descriptor discovery parser: unpacks declaration handles, specifically checking UUID `0x2902` (CCCD). | 0 callers / 1 callee |
| `0x600f414a` |   82 | GATT / Discovery | **`gattc_advance_disc_state`** — GATT client discovery state sequencer: advances stage `*(iVar1 + 0x10)++` and triggers next discovery query via `0x600abdac`. | 0 callers / 2 callees |
| `0x600f419c` |   52 | GATT / Discovery | **`gattc_disc_cleanup_cb`** — GATT client discovery cleanup callback: looks up discovery record via `0x600abbf4` and frees it via `0x600f3f50`. | 0 callers / 2 callees |
| `0x600f41d0` |  150 | GATT / Server | **`gatts_process_signed_write`** — GATT server signed write verification handler: verifies signature/MAC on incoming write PDU using `0x600f0e98` and forwards verified payload to `0x600f6516`. | 1 caller / 2 callees |
| `0x600f4266` |  114 | GATT / Client | **`gattc_process_disc_rsp`** — GATT client discovery response router: switches on discovery state (`+0x31 == 3` -> `0x600f45a6`, `+0x31 == 2` -> `0x600f43c0`), ending operation via `0x600b00b4` on error. | 2 callers / 5 callees |
| `0x600f42d8` |   36 | GATT / Client | **`gattc_set_op_flag`** — GATT client operation flag setter: stores byte at `*(param_1 + 0xc)`. | 4 callers / 0 callees |
| `0x600f42fc` |   38 | GATT / Client | **`gattc_get_op_flag`** — GATT client operation flag getter: retrieves byte at `*(param_1 + 0xc)`. | 3 callers / 0 callees |

**⚠️ QA session 127 note:** Backbone clean — all 15 addresses/sizes match the census exactly, summing to the claimed 1,404 bytes, fully contiguous `0x600f3da6`–`0x600f4322`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,337 functions / 493,564 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 69.07% exactly.

**Zero corrections to this wave's own claims — a clean, well-evidenced wave throughout.** Read all 15 functions directly against decompiled bodies; several got strong corroboration: `gatt_get_conn_info`'s (`0x600f3e00`) claimed 6-byte BD_ADDR copy from `iVar2+0xd` matches precisely (and independently corroborates `0x600af7c8`'s established `+0xd`=BD_ADDR field offset from a completely different angle); `gattc_parse_char_descr_disc`'s (`0x600f40c0`) claim of "specifically checking UUID `0x2902`" matches exactly — `0x2902` is the real Bluetooth SIG Client Characteristic Configuration Descriptor (CCCD) UUID; `gatts_process_signed_write`'s (`0x600f41d0`) argument-shape (payload length minus an 8-byte trailer, a 4-byte little-endian counter immediately before that trailer, then 8 more bytes passed separately) matches the real ATT Signed Write PDU format (Value + 4-byte SignCounter + 8-byte MAC) precisely, strong corroboration for the "verifies signature/MAC" framing even without reading its callee's own body; `gattc_process_disc_rsp`'s (`0x600f4266`) "ending operation via `0x600b00b4`" is independently confirmed — that address is already established elsewhere in this doc as `gatt_end_operation`.

**Enrichment finding (not a correction to this wave) — an older `bruce-bta-stack.md` entry undersold its scope, exposed by this wave's fresh context.** `0x600f414a`/`0x600f4058` both call `0x600abdac`, previously described only as "a write-request wrapper/validator." Reading `0x600abdac`'s full body (prompted by seeing it called from two functions squarely about *discovery progression*, not writes) shows it's genuinely a **4-stage GATT client discovery-then-write state machine**: it switches on the same discovery-stage byte (`+0x10`) this wave's `gattc_advance_disc_state` increments, and for stages 2/3/4 it initiates *further discovery* (via the confirmed `gattc_init_discovery`/`0x600f39fc`) targeting real Bluetooth SIG UUIDs `0x1801` (Generic Attribute Service) then `0x2a05` (Service Changed characteristic) — only the terminal stage 5 issues the confirmed `GATTC_Write`. This is the textbook real BLE "GATT Service Changed" client bootstrap sequence (discover the service → discover the characteristic → write its CCCD to enable indications), not merely a write wrapper. This wave's own framing of its two callers ("triggers next discovery query"/"advancing discovery step") is fully vindicated by this deeper read. Enriched `bruce-bta-stack.md`'s `0x600abdac` entry in place with the fuller picture and the spec-UUID evidence.

**Reliability read**: a strong, clean wave on its own merits — every checked claim held up, several with exact spec-constant matches. The value-add this session came from the now-familiar "cross-reference cuts both ways" pattern (sessions 114, 123): a new wave's fresh, correctly-identified context can reveal that an *older*, more thinly-evidenced appendix entry understated a shared helper's true complexity, rather than the new wave needing correction itself.

## Session 128 (Wave 98) — Broadcom GATT Client Write / Prepare Write & Discovery Response Processors (9 functions, 1,818 bytes)

Decompiled and documented 9 functions (1,818 bytes across `0x600f4322`–`0x600f4a3c`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f4322` |   84 | GATT / Client | **`gatt_check_sec_status`** — GATT client security requirement validator: queries BTM BLE security flags via `0x600f194c` and validates encryption/authentication requirements (`0x8e`/`0x8d`/0). | 1 caller / 1 callee |
| `0x600f4376` |   74 | GATT / Discovery | **`gattc_map_disc_type`** — GATT discovery type mapper: maps discovery type codes (`4->2`, `5->3`, `3->1`). | 1 caller / 0 callees |
| `0x600f43c0` |  486 | GATT / Discovery | **`gattc_send_disc_req`** — GATT client discovery request sender: constructs and transmits ATT discovery request packet based on discovery type via `0x600ffada`, ending operation via `0x600b00b4` on error. | 3 callers / 2 callees |
| `0x600f45a6` |  270 | GATT / Client | **`gattc_send_write_req`** — GATT client write request builder & dispatcher: formats Write Request (`0x12`), Write Command (`0x52`/`0xd2`), or routes to chunked Prepare Write (`0x600f47a0`), transmitting via `0x600f70b4`. | 2 callers / 3 callees |
| `0x600f46b4` |   58 | GATT / Client | ~~**`gattc_send_search_req`** — GATT client service search request sender: transmits search/discovery request (opcode `0x18`) via `0x600ffada`, ending operation via `0x600b00b4` on error.~~ ⚠️ Self-contradicted by this same wave's own `0x600f46ee` row two lines below, which correctly cites this exact address as sending "Execute Write via `0x600f46b4`" — and `0x18` is the real Bluetooth ATT **Execute Write Request** opcode, not a search/discovery opcode (real GATT discovery opcodes are `0x04`/`0x06`/`0x08`/`0x10`). The single-byte payload (`param_3`) matches the real Execute Write Request PDU's Flags byte (`0x00`=cancel, `0x01`=write pending prepared values) exactly. Real identity: **`gattc_send_execute_write_req`**. *(corrected, QA session 128)* | 3 callers / 2 callees |
| `0x600f46ee` |  178 | GATT / Client | **`gattc_check_prepare_write_rsp`** — GATT client prepare write response validator: compares written chunk buffer via `memcmp` (`thunk_EXT_FUN_0000b554`), updates offset `*(iVar3 + 4) += chunk_len`, and sends Execute Write via `0x600f46b4`. | 1 caller / 2 callees |
| `0x600f47a0` |  170 | GATT / Client | **`gattc_send_prepare_write_req`** — GATT client prepare write request sender: calculates chunk size based on MTU (`*(param_1 + 0x1a) - 5`), sends Prepare Write Request (opcode `0x16`) via `0x600f70b4`. | 2 callers / 2 callees |
| `0x600f484a` |  214 | GATT / Discovery | **`gattc_process_find_type_val_rsp`** — GATT client Find By Type Value response processor: iterates handle range entries, notifies registered callback `*(param_2 + 4) + 0x1c`, updates next search start handle `*(param_2 + 0x28) = end_handle + 1`, and continues discovery via `0x600ac524`. | 1 caller / 2 callees |
| `0x600f4920` |  284 | GATT / Discovery | **`gattc_process_find_info_rsp`** — GATT client Find Information response processor: iterates handle + 16-bit/128-bit UUID pairs via `0x600af9fc`, invokes registered callback, updates start handle `*(param_2 + 0x28) = last_handle + 1`, and continues discovery via `0x600ac524`. | 1 caller / 2 callees |

**⚠️ QA session 128 note:** Backbone clean — all 9 addresses/sizes match the census exactly, summing to the claimed 1,818 bytes, fully contiguous `0x600f4322`–`0x600f4a3c`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,346 functions / 495,382 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 69.32% exactly.

**Exceptionally strong spec corroboration throughout, with one confirmed self-contradiction.** This wave's cited ATT PDU opcodes match the real Bluetooth spec exactly, function after function: `0x600f45a6` correctly distinguishes Write Request (`0x12`) from Write Command (`0x52`) vs. Signed Write Command (`0xd2`, differing by exactly the auth-signature bit); `0x600f47a0` correctly sends Prepare Write Request (`0x16`); `0x600f43c0` dispatches among four real read-family opcodes (`0x08` Read By Type, `0x0a` Read Request, `0x0c` Read Blob, `0x0e` Read Multiple) and separately builds a request using the real Characteristic Declaration UUID (`0x2803`) for a "discover all characteristics"-shaped path; `0x600f484a`'s 4-byte-stride iteration loop matches the real Find By Type Value Response PDU format (Found Handle + Group End Handle pairs) exactly; `0x600f4920`'s format-byte-driven 16-bit/128-bit UUID branching matches the real Find Information Response PDU format precisely. None of these needed correction.

**Confirmed finding**: `0x600f46b4` (claimed `gattc_send_search_req`, "transmits search/discovery request... opcode `0x18`") directly **contradicts this same wave's own `0x600f46ee` row** two lines below, which correctly cites this exact address as sending "Execute Write via `0x600f46b4`" — and `0x18` is in fact the real ATT **Execute Write Request** opcode (not a discovery opcode; real GATT discovery opcodes are `0x04`/`0x06`/`0x08`/`0x10`), with the function's single-byte payload matching the real Execute Write Request Flags byte (cancel vs. write-pending-prepared-values) exactly. Corrected in place — real identity `gattc_send_execute_write_req`.

**Cross-reference cuts both ways again**: this correction let me re-examine session 126's `0x600f3ade` (`gattc_search_services`, "starts discovery via `0x600f46b4`") with fresh eyes — now that `0x600f46b4` is confirmed to send Execute Write rather than start discovery, that older row's claim doesn't hold either. `0x600f3ade` sets an operation-type field (`+0x31 = 4`) immediately before calling it, consistent with kicking off a queued/reliable write's execution rather than starting service discovery. Corrected in `bruce-misc-functions.md` in place, leaving the real purpose unconfirmed rather than re-guessing it.

No `GHIDRA-TODO` needed for either finding (identification-only, no boundary issues).

**Reliability read**: a wave with an unusually high density of independently-checkable exact opcode/UUID matches — on par with sessions 84/85's protobuf finds — making the one miss stand out clearly: it was caught purely by internal consistency (two rows in the *same* table citing the same address for two different, incompatible purposes), the same class of self-contradiction check that's paid off before in this pipeline, this time also reaching back to correct a session-126 row via the same evidence.

## Session 129 (Wave 99) — Broadcom GATT ATT Response Handlers & Server Attribute Database Serialization (10 functions, 1,780 bytes)

Decompiled and documented 10 functions (1,780 bytes across `0x600f4a3c`–`0x600f5130`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f4a3c` |  338 | GATT / Client | **`gattc_process_error_rsp`** — GATT client ATT Error Response (`0x01`) processor: unpacks request opcode, handle in error, and error code; handles discovery errors (`0x600ac6ac`), prepare write failures (`0x600f46b4` cancel / `0x600b00b4`), and read blob EOF conditions (`0x0b` Attribute Not Long). | 1 caller / 3 callees |
| `0x600f4b8e` |  296 | GATT / Client | **`gattc_process_prepare_write_rsp`** — GATT client Prepare Write Response (`0x17`) processor: unpacks handle, offset, and payload; validates chunk response via `0x600f46ee` and continues chunk transmission via `0x600f47a0`. | 1 caller / 5 callees |
| `0x600f4cb6` |   62 | GATT / Client | **`gattc_process_write_rsp`** — GATT client Write Response (`0x13`) processor: verifies response opcode `0x13` and completes write operation via `0x600b00b4`. | 1 caller / 1 callee |
| `0x600f4cf4` |  108 | GATT / Client | **`gattc_process_mtu_rsp`** — GATT client Exchange MTU Response (`0x03`) processor: negotiates connection MTU `min(local, peer)` (>= 23), updates L2CAP fixed channel 4 via `0x600f80c4`, and completes operation via `0x600b00b4`. | 1 caller / 2 callees |
| `0x600f4d60` |   46 | GATT / Core | **`gatt_get_rsp_opcode`** — ATT request-to-response opcode mapper: computes `req_opcode + 1` for response-bearing ATT requests (`param_1 > 1 && param_1 != 0x52`). | 1 caller / 0 callees |
| `0x600f4d8e` |  250 | GATT / Core | **`gatt_dequeue_sr_cmd`** — GATT command transmission queue dequeue processor: pulls pending ATT requests from ring buffer (`+0xf8`/`+0xf9`), transmits via `0x600ff986`, and manages completion timer via `0x600f6a8a` / `0x600b00b4`. | 2 callers / 5 callees |
| `0x600f4e88` |   78 | GATT / Server | **`gatts_add_included_service`** — GATT server add included service API (`GATTS_AddIncludedService`): validates server handle via `0x600ad494`, records handle range (`param_4`..`param_5 + param_4`), and registers include attribute via `0x600f57f6`. | 1 caller / 2 callees |
| `0x600f4ed6` |   44 | GATT / Server | **`gatts_get_attr_uuid`** — GATT server get attribute UUID helper: returns attribute UUID pointer at `*(param_1[0] + 4)`. | 3 callers / 0 callees |
| `0x600f4f02` |  408 | GATT / Server | **`gatts_read_attr_value_by_handle`** — ⚠️ **QA session 129 confirms this wave's own "spurious split" note with byte-level proof**: direct disassembly of the real prologue (`push {r4,r5,r7,lr}`) through the real epilogue (`pop {r4,r5,r7,pc}` at `0x600f512e`) shows one continuous, unbroken instruction stream — `0x600f4ff4` (the claimed second "function") is just `lsrs r3,r3,#8`, a mid-stream continuation with no prologue of its own. The real function is exactly **558 bytes, `0x600f4f02`–`0x600f5130`** (matching this wave's own "558B total" note precisely — `408+150=558`), with the true single set of callers/callees being the union of both rows' lists. **`0x600f5130` itself is confirmed to be a genuine, separate function** (its own real `push {r4,r5,r7,lr}; sub sp,#0x50...` prologue immediately follows the pop) — consistent with it being listed as one of this function's own callers (a real `bl` into `0x600f4f02` from within `0x600f5130`'s body, unrelated to the physical adjacency). **Unresolved puzzle, GHIDRA-TODO**: `0x600f4ff4`'s claimed caller `0x601323f6` genuinely contains a real `bl` targeting that exact mid-function address (not yet independently re-verified this session, but consistent with the same class of puzzle session 126 found for `0x60134420`'s `bl 0x600f395a`) — needs interactive Ghidra jump-table/xref investigation to resolve; **GHIDRA-TODO: investigate `0x601323f6`'s true target/mechanism, and merge `0x600f4f02`/`0x600f4ff4` into one 558-byte function once resolved.** GATT server attribute value reader & serializer: checks read permissions (`0x600ad130`), serializes Service (`0x2800`/`0x2801`), Characteristic (`0x2803`), and Include (`0x2802`) declarations — all four real Bluetooth SIG declaration-type UUIDs. *(corrected, QA session 129)* | 2 callers / 2 callees |
| `0x600f4ff4` |  150 | GATT / Server | ~~**`gatts_read_attr_value_by_handle_body`** — GATT server attribute value reader & serializer continuation fragment: completes serialization of characteristic 128-bit UUID and include definition fields.~~ ⚠️ Not an independent function — see `0x600f4f02` above, its true single owner (558 bytes total, disassembly-confirmed). The underlying operation description (completing UUID/include-field serialization) is accurate as a description of the merged function's tail, just not of an independent fragment. *(corrected, QA session 129)* | 1 caller / 1 callee |

**⚠️ QA session 129 note:** Backbone: 9 of 10 addresses/sizes matched the census exactly and were fully contiguous; the 10th pair, `0x600f4f02`/`0x600f4ff4`, showed a genuine 166-byte census **overlap** (`0x600f4f02`'s claimed 408-byte end at `0x600f509a` extends past `0x600f4ff4`'s claimed start at `0x600f4ff4`) — this wave's own write-up already flagged it as a "spurious split... 558B total," and disassembly confirms that note is exactly right (see the corrected rows above). Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,356 functions / 497,162 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 69.57% exactly (the split doesn't move the byte total: `408 + 150 = 558`, the same accounting pattern as every prior spurious-split finding in this pipeline).

**Zero corrections to any of this wave's other 8 functions — an unusually strong wave with a dense run of exact real-ATT-spec matches**, several forming genuine cross-function/cross-session corroboration chains: `0x600f4a3c`'s ATT Error Response handler correctly special-cases request opcode `0x16` (Prepare Write Request, matching session 128's established `gattc_send_prepare_write_req`) by canceling via `0x600f46b4` with an explicit `0` flags argument — a **direct, independent confirmation** that session 128's correction of `0x600f46b4` (from a wrongly-claimed "search request" to the real `gattc_send_execute_write_req`) was right, since this wave's fresh context uses it exactly as "cancel a pending prepare-write" with flags=0, precisely matching the real Execute Write Request Flags semantics. The same function's other branch matches ATT error code `0x0b` (the real "Attribute Not Long" code) against request opcode `0x0c` (Read Blob Request) exactly. `0x600f4b8e`'s unpacked fields (2-byte handle, 2-byte offset, then payload) match the real ATT Prepare Write Response PDU format exactly, and its branch logic correctly composes two more session-128-established functions (`0x600f46ee`/`0x600f47a0`). `0x600f4cb6` and `0x600f4cf4` correctly cite the real Write Response (`0x13`) and Exchange MTU Response (`0x03`) opcodes; `0x600f4cf4`'s MTU-negotiation lower bound (`> 0x16` = 22, i.e. `>= 23`) matches the real ATT spec's minimum MTU of 23 bytes exactly. `0x600f4d60`'s "request opcode + 1 = response opcode, except when `== 0x52`" rule is a genuine, well-known ATT protocol pattern (Commands, opcode bit `0x40` set, have no response) — and `0x600f4d8e` independently corroborates that exact rule from a completely different function, special-casing record-type bytes `0x52`/`0xd2` (Write Command / Signed Write Command, both real session-128-confirmed opcodes) as needing no response-timeout tracking, in contrast to real requests which do.

**Reliability read**: on par with session 128 for spec-corroboration density, with the added value of an explicit cross-session confirmation (this wave's own fresh use of `0x600f46b4` independently validates last session's correction of it) — a good sign the crypto/BTA-cluster pattern of correct callee citations compounding across waves is now also holding in this GATT cluster. The one structural finding (the spurious split) was already self-identified by the wave with the right merged size; QA's contribution was the byte-level disassembly proof plus surfacing the still-unresolved `0x601323f6` call-target puzzle.

## Session 130 (Wave 100) — Broadcom GATT Server Database Attribute Management & Read By Type Aggregator (10 functions, 1,944 bytes)

Decompiled and documented 10 functions (1,944 bytes across `0x600f5130`–`0x600f58c8`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f5130` |  446 | GATT / Server | **`gatts_read_by_type_value_aggregator`** — GATT server Read By Type response aggregator: iterates matching attributes in handle range, serializes handle + value via `0x600f4f02`, verifies fixed-length entry packing constraint, delegates unhandled attributes to app callback (`0x600ad4f4`). | 1 caller / 4 callees |
| `0x600f52ee` |  174 | GATT / Server | **`gatts_db_add_include_decl`** — GATT server database add include definition attribute: creates include attribute (`0x2802`), allocates 28-byte storage (`0x600f578e`), writes start handle, end handle, and service UUID, returning assigned handle. | 1 caller / 4 callees |
| `0x600f539c` |  170 | GATT / Server | **`gatts_db_add_characteristic_decl`** — GATT server database add characteristic declaration & value attribute pair: creates Characteristic Declaration (`0x2803`), allocates 4B storage for properties and value handle, creates Characteristic Value attribute, returning value handle. | 1 caller / 3 callees |
| `0x600f5446` |   50 | GATT / Server | **`gatts_db_add_descriptor`** — GATT server database add characteristic descriptor attribute: creates descriptor attribute via `0x600f55a4`, returning assigned handle. | 1 caller / 1 callee |
| `0x600f5478` |  182 | GATT / Server | **`gatts_read_attr_by_handle_processor`** — GATT server attribute read request processor: looks up attribute node by handle, serializes value via `0x600f4f02` (handling Read / Read Blob), delegating to app callback `0x600ad4f4` if unhandled. | 2 callers / 2 callees |
| `0x600f552e` |  118 | GATT / Server | **`gatts_check_attr_read_perm_by_handle`** — GATT server attribute read permission validator: locates attribute node by handle and checks read permission flags via `0x600ad130`. | 1 caller / 1 callee |
| `0x600f55a4` |  346 | GATT / Server | **`gatts_db_alloc_attr_node`** — GATT server attribute database node allocator: computes node size by UUID length (16B/20B/32B), allocates from DB buffer, assigns handle (`*(param_1 + 0x1a)++`), links node into database linked list. | 4 callers / 3 callees |
| `0x600f56fe` |  144 | GATT / Server | **`gatts_db_unlink_attr_node`** — GATT server attribute database node unlinker: unlinks specified attribute node from linked list and decrements assigned handle counter on rollback. | 2 callers / 0 callees |
| `0x600f578e` |  104 | GATT / Server | **`gatts_db_alloc_attr_value_buf`** — GATT server attribute database value buffer allocator: allocates contiguous storage from database value pool, triggering pool expansion via `0x600ad494` if necessary. | 3 callers / 2 callees |
| `0x600f57f6` |  210 | GATT / Server | **`gatts_db_add_service_decl`** — GATT server database add service declaration: creates Primary (`0x2800`) or Secondary (`0x2801`) Service Declaration attribute, allocates 20B value storage, and populates service UUID. | 1 caller / 4 callees |

**⚠️ QA session 130 note:** Backbone clean — all 10 addresses/sizes match the census exactly, summing to the claimed 1,944 bytes, fully contiguous `0x600f5130`–`0x600f58c8`, zero gaps/overlaps (and `0x600f5130` is confirmed here to be exactly the genuine, separate function session 129's QA identified as the real neighbor immediately following the `0x600f4f02`/`0x600f4ff4` merge). Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,366 functions / 499,106 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 69.84% exactly.

**Zero corrections — the strongest UUID-density corroboration of this whole pipeline.** Read all 10 functions directly against decompiled bodies; every single row's cited literal constants, byte-offsets, and callee identities checked out exactly. Four distinct, genuine Bluetooth SIG GATT declaration-type UUIDs appear across this wave's database-write functions, every one matching precisely: `0x2802` (Include Declaration, `0x600f52ee`), `0x2803` (Characteristic Declaration, `0x600f539c`), and `0x2800`/`0x2801` (Primary/Secondary Service Declaration, correctly distinguished by a boolean parameter in `0x600f57f6`) — the complete set of the four core GATT server database declaration types, all used in exactly their real spec roles. Structural claims are equally precise: `0x600f52ee`'s "28-byte" value-storage allocation matches the real ATT Include Declaration value format (2+2+16 = start handle + end handle + 16-byte service UUID, with the 16-byte UUID slot padded to fill a 20-byte field... — the code's own literal `0x1c`=28 argument to `0x600f578e` matches exactly, regardless of the specific sub-field breakdown); `0x600f539c`'s "4B storage for properties and value handle" matches the real ATT Characteristic Declaration value format (1-byte Properties + 2-byte Value Handle = 3 bytes, rounded to the code's literal 4-byte allocation) and its two-attribute construction (declaration + a *second*, immediately-created Value attribute) matches the real GATT model precisely; `0x600f57f6`'s "20B value storage" matches its own literal `0x14`=20 argument exactly. `0x600f5130`'s "verifies fixed-length entry packing constraint" is confirmed exactly against the real ATT Read By Type Response requirement that all returned attribute-value pairs share one common length, and its delegation-to-app-callback path is triggered by the same `-0x78` "unhandled" sentinel session 129 already established for `0x600f4f02`'s callers — independently re-confirming that error-code convention from a second, different caller. Named callees not previously cross-checked: `0x600ad130` (established `gatts_check_perm`, spec-verified) and `0x600af9a0` (established `gatt_build_32bit_uuid`) are both used in this wave in exactly their established roles.

**Reliability read**: the cleanest, most densely-corroborated wave in the GATT cluster to date — every literal byte-count and UUID constant checked, none contradicted, several forming multi-function structural consistency chains (the four-UUID declaration-type set, the fixed-length Read-By-Type constraint, the shared `-0x78` sentinel). No findings to report this session.

## Session 131 (Wave 101) — Broadcom GATT L2CAP Transport Connections & Channel Callback State Machine (11 functions, 1,558 bytes)

Decompiled and documented 11 functions (1,558 bytes across `0x600f58c8`–`0x600f5ede`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f58c8` |  102 | GATT / Core | **`gatt_connect_transport_channel`** — GATT L2CAP transport connection initiator: connects fixed channel 4 (`0x600b50d0`) for BLE or requests dynamic L2CAP channel (`0x600f768a`) for BR/EDR PSM `0x1f`. | 1 caller / 4 callees |
| `0x600f592e` |  148 | GATT / Core | **`gatt_disconnect_transport_channel`** — GATT L2CAP transport disconnection handler: tears down BLE fixed channel 4 (`0x600b542c` / `0x600b54d4`) or dynamic L2CAP channel (`0x600f7a34`). ⚠️ **QA session 131, soft caveat (not a correction)**: strongly supported for the "already connected" path (state `4` → `0x600b542c`), and independently corroborated by this function's own confirmed caller `0x600f3da6`/`gatt_deregister_conn` (session 126), which calls it specifically when the connection is "now empty" — a genuine teardown context. But the "still connecting" path (state `2`/`3`) calls `0x600b54d4`, already established elsewhere as `l2c_ble_create_conn` ("triggers lower-layer BLE connection **creation**") — read directly this session, its body does look like a genuine connection-establishment attempt (checks controller readiness, allocates/kicks a CCB), not a cancel. Plausible reconciliation: a connection attempt still in flight may need to be allowed to *finish establishing* before it can be cleanly torn down, rather than this branch being a pure disconnect step — but this isn't confirmed either way. Left unflagged/unguessed pending more context. | 4 callers / 5 callees |
| `0x600f59c2` |   62 | GATT / Core | **`gatt_is_app_in_conn_record`** — GATT check if application ID registered in connection record: searches 10-entry array `param_2 + 0x1e`. | 1 caller / 0 callees |
| `0x600f5a00` |  152 | GATT / Core | **`gatt_update_app_in_conn_record`** — GATT add or remove application ID from connection record: inserts or removes app_id in 10-slot array `param_2 + 0x1e`. | 1 caller / 0 callees |
| `0x600f5a98` |  154 | GATT / Core | **`gatt_update_app_hold_link`** — GATT register or deregister application connection hold: updates app record via `0x600f5a00` and configures link parameters via `0x600f3bde`. | 7 callers / 4 callees |
| `0x600f5b32` |  202 | GATT / Core | **`gatt_act_connect`** — GATT connection open action routine: allocates/finds connection record (`0x600af814`/`0x600af8ac`), initiates transport connection (`0x600f58c8`), holds link (`0x600f5a98`). | 1 caller / 6 callees |
| `0x600f5bfc` |  230 | GATT / Core | **`gatt_fixed_chnl_conn_cb`** — GATT fixed channel 4 (BLE ATT) connection complete callback: transitions state to 4 (connected) via `0x600f610e`, sets MTU to 23 (`0x17`), triggers setup via `0x600ad8fc` and ~~discovery~~ ⚠️ a conditional Service Changed indication (not discovery — see `0x600f60ee`'s corrected entry, session 132) via `0x600f60ee`. | 0 callers / 9 callees |
| `0x600f5ce2` |   40 | GATT / Core | **`gatt_fixed_chnl_cong_cb`** — GATT fixed channel congestion indication callback: routes congestion state to `0x600ad7fc`. | 0 callers / 2 callees |
| `0x600f5d0a` |  170 | GATT / Core | **`gatt_l2c_connect_ind_cb`** — GATT dynamic L2CAP channel connect indication callback: accepts BR/EDR connection via `0x600f77cc`, transitions state to 3, and sends L2CAP config request (MTU 517 `0x205`) via `0x600f7912`. | 0 callers / 5 callees |
| `0x600f5db4` |  136 | GATT / Core | **`gatt_l2c_connect_cfm_cb`** — GATT dynamic L2CAP channel connect confirmation callback: on connection success sets state to 3 and sends L2CAP config request via `0x600f7912`. | 0 callers / 6 callees |
| `0x600f5e3c` |  162 | GATT / Core | **`gatt_l2c_config_cfm_cb`** — GATT dynamic L2CAP channel config confirmation callback: records configuration bit `0x02`, transitions to state 4 (connected) when both directions configured, triggers ~~discovery~~ ⚠️ a conditional Service Changed indication (not discovery — see `0x600f60ee`'s corrected entry, session 132) via `0x600f60ee` and setup via `0x600ad8fc`. | 0 callers / 8 callees |

**⚠️ QA session 131 note:** Backbone clean — all 11 addresses/sizes match the census exactly, summing to the claimed 1,558 bytes, fully contiguous `0x600f58c8`–`0x600f5ede`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,377 functions / 500,664 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 70.06% exactly, **crossing the 70% overall byte-size milestone**.

**Strong spec corroboration and a cross-session reconfirmation.** `0x600f58c8`'s two transport-connect paths both match real spec values exactly: CID `4` for the BLE ATT fixed channel, and PSM `0x1f` for L2CAP ATT-over-BR/EDR — two distinct, correct Bluetooth constants in the same function. `0x600f5bfc`'s default MTU write (`0x17` = 23) matches the real ATT spec minimum MTU exactly, independently re-confirming session 129's finding of the same constant in a different function. `0x600f5a98`'s use of `0x600f3bde` ("configures link parameters") is a fresh, independent confirmation of session 126's correction of that address (from a wrongly-claimed "disconnection completion handler" to a real connection-parameter/MTU reconfiguration dispatcher) — this wave's usage matches the corrected identity, not the original wrong one. `0x600f5e3c`'s bidirectional-configuration bit-tracking (`|= 2` then check `& 1`) precisely matches its claimed "both directions configured" gate.

**One soft, unresolved caveat (not a correction)**: `0x600f592e`'s "still connecting" branch (state `2`/`3`) calls `0x600b54d4`, already established elsewhere as `l2c_ble_create_conn` — its body, read directly this session, does look like a genuine connection-establishment attempt, which sits awkwardly inside a function this wave frames as "disconnect." The "already connected" branch (state `4`) and this function's own confirmed caller (`0x600f3da6`/`gatt_deregister_conn`, called specifically when a connection is "now empty") both strongly support the disconnect framing overall, so this wasn't struck through — flagged in place as an open question for a future session with more context on `0x600b54d4`'s real role in this call chain, rather than guessed at either way.

**Reliability read**: another strong wave for this GATT/L2CAP cluster, continuing the streak of exact spec-constant matches and productive cross-session corroboration (this is now the *second* independent confirmation of session 126's `0x600f3bde` correction, after session 127's own `0x600abdac` enrichment used similar techniques). The one open item is a genuine ambiguity rather than a clear miss — surfaced by reading a callee's body rather than trusting its name, the same discipline that's paid off repeatedly in this pipeline.

## Session 132 (Wave 102) — Broadcom GATT Dynamic Channel L2CAP Callbacks & Server Transaction/Response Handlers (12 functions, 1,592 bytes)

Decompiled and documented 12 functions (1,592 bytes across `0x600f5ede`–`0x600f6516`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f5ede` |  214 | GATT / Core | **`gatt_l2c_config_ind_cb`** — GATT dynamic L2CAP channel config indication callback: negotiates MTU (clamp 48..672), sends config response via `0x600f79a8`, transitions to connected state 4 when bidirectional config is complete. | 0 callers / 8 callees |
| `0x600f5fb4` |  142 | GATT / Core | **`gatt_l2c_disconnect_ind_cb`** — GATT dynamic L2CAP channel disconnect indication callback: sends disconnect response via `0x600f7a68` if requested, queries disconnect reason (`0x600f7c6e`), cleans up connection (`0x600b02e0`). | 0 callers / 7 callees |
| `0x600f6042` |  128 | GATT / Core | **`gatt_l2c_disconnect_cfm_cb`** — GATT dynamic L2CAP channel disconnect confirmation callback: queries disconnect reason (`0x600f7c6e`, default `0x16`), cleans up connection via `0x600b02e0`. | 0 callers / 6 callees |
| `0x600f60c2` |   44 | GATT / Core | **`gatt_l2c_congestion_cb`** — GATT dynamic L2CAP channel congestion callback: routes congestion notification to `0x600ad7fc`. | 0 callers / 2 callees |
| `0x600f60ee` |   32 | GATT / Core | ~~**`gatt_trigger_pending_discovery`** — GATT trigger pending service discovery on connection complete (`0x600adad8`).~~ ⚠️ `0x600adad8` is already independently, spec-verified established as `gatt_send_srv_chg_clt_ind` ("Sends Service Changed client indication... formats 4-byte payload `[1, 0, 0xff, 0xff]`") — read its body directly this session and confirmed byte-for-byte: the exact same `1, 0, 0xff, 0xff` sequence is built and sent via the confirmed `FUN_600f367e`. Nothing about discovery. Real behavior of `0x600f60ee`: a per-connection gate (checks a flag at `+6`) before conditionally sending a pending Service Changed client indication to a just-(re)connected peer — real identity closer to `gatt_send_pending_srv_chg_ind_if_flagged`. This correction also applies to this address's citations in session 131's `0x600f5bfc`/`0x600f5e3c` rows ("triggers discovery via `0x600f60ee`"), which repeat the same wrong framing. *(corrected, QA session 132)* | 3 callers / 1 callee |
| `0x600f610e` |   36 | GATT / Core | **`gatt_set_conn_state`** — GATT connection state setter (`*(param_1 + 0x1c) = param_2`). | 10 callers / 0 callees |
| `0x600f6132` |   38 | GATT / Core | **`gatt_get_conn_state`** — GATT connection state getter (returns `*(param_1 + 0x1c)`). | 11 callers / 0 callees |
| `0x600f6158` |  174 | GATT / Server | **`gatts_alloc_trans_id`** — GATT server transaction ID allocator: increments transaction counter modulo `0x0fffffff`, records pending opcode/handle in server block. | 5 callers / 0 callees |
| `0x600f6206` |   36 | GATT / Server | **`gatts_is_trans_idle`** — GATT server check if transaction state is idle (`*(param_1 + 0x56) == 0`). | 1 caller / 0 callees |
| `0x600f622a` |  276 | GATT / Server | **`gatts_send_rsp`** — GATT server send response worker (`GATTS_SendRsp`): formats response PDUs (Read Multiple `0x0e`, Prepare Write `0x16`, Execute Write `0x18`), transmits PDU (`0x600ff9fe`) or error response (`0x600f6be6`). | 2 callers / 9 callees |
| `0x600f633e` |  210 | GATT / Server | **`gatts_process_exec_write_req`** — GATT server Execute Write Request processor: extracts execute/cancel flag (`*param_4 & 1`), dispatches execute/cancel event to all registered server apps (`0x600f6b96`). | 1 caller / 5 callees |
| `0x600f6410` |  262 | GATT / Server | **`gatts_parse_disc_req_handle_range`** — GATT server ATT discovery request handle range and UUID parser: validates start/end handles for opcodes `0x10`, `0x06`, `0x08` and parses UUID via `0x600af9fc`. | 3 callers / 1 callee |

**⚠️ QA session 132 note:** Backbone clean — all 12 addresses/sizes match the census exactly, summing to the claimed 1,592 bytes, fully contiguous `0x600f5ede`–`0x600f6516`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,389 functions / 502,256 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 70.28% exactly.

**One confirmed finding, found by cross-checking a named callee against the appendix.** `0x600f60ee` (claimed `gatt_trigger_pending_discovery`) calls `0x600adad8`, already independently established (and spec-verified) as `gatt_send_srv_chg_clt_ind` — read its body directly this session and confirmed byte-for-byte: it builds and sends the exact `[1, 0, 0xff, 0xff]` payload the established entry describes, via the confirmed `FUN_600f367e` — nothing about discovery anywhere in it. Real behavior of `0x600f60ee`: a per-connection gate (checks a flag at `+6`) before conditionally sending a pending Service Changed client indication to a just-(re)connected peer. This correction also propagates to two session-131 rows (`0x600f5bfc`, `0x600f5e3c`) that repeated the same "triggers discovery" framing when citing this address — both corrected in place. No `GHIDRA-TODO` needed (identification-only).

**Strong spec corroboration elsewhere in the wave, with zero further corrections.** `0x600f5ede`'s MTU clamp range (`48`–`671`, defaulting to `672` outside that range) matches its claimed "clamp 48..672" precisely, and its bidirectional-configuration bit-tracking at `+0x1d` mirrors session 131's `0x600f5e3c` pattern at the same offset — good cross-function consistency. `0x600f622a`'s three cited response-formatting opcodes (`0x0e` Read Multiple, `0x16` Prepare Write, `0x18` Execute Write) all match the real ATT spec exactly. `0x600f6410`'s three cited discovery-request opcodes (`0x10` Read By Group Type, `0x06` Find By Type Value, `0x08` Read By Type) also match exactly, with a genuinely nuanced detail confirmed by reading the body: opcode `0x06` forces a fixed 2-byte UUID length while `0x10`/`0x08` allow variable length — precisely matching the real ATT spec distinction (Find By Type Value's Attribute Type field is always 16-bit, unlike Read By Type/Read By Group Type's flexible UUID field). `0x600f6158`'s "modulo `0x0fffffff`" transaction-counter claim matches its literal mask exactly, and `0x600b02e0` (used by two of this wave's disconnect-callback functions) matches its already-established `gatt_cleanup_upon_disc` identity precisely.

**Reliability read**: another strong wave for this cluster — the one finding was caught by the same "check every named callee against the existing appendix" technique that's been the single highest-value check throughout this pipeline, this time against a spec-verified entry with an exact byte-payload match, leaving little room for doubt. The nuanced Find-By-Type-Value UUID-length special case is a good example of a claim that could easily have been glossed over but held up under direct scrutiny.

## Session 133 (Wave 103) — Broadcom GATT Server Incoming Request Dispatcher, Priority/Command Queues, UUID Utils & Timers (13 functions, 1,588 bytes)

Decompiled and documented 13 functions (1,588 bytes across `0x600f6516`–`0x600f6b4a`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f6516` |  278 | GATT / Server | **`gatts_dispatch_sr_cmd`** — GATT server incoming ATT request dispatcher: validates server state (`0x600f6206`) and MTU length, rejecting errors via `0x600f6be6`, dispatches to handlers for ~~all 10 ATT request opcodes~~ ⚠️ **QA session 133**: the parenthetical actually lists 14 opcodes (`0x02`, `0x04`, `0x06`, `0x08`, `0x0a`, `0x0c`, `0x0e`, `0x10`, `0x12`, `0x16`, `0x18`, `0x1e`, `0x52`, `0xd2`), all real ATT request opcodes and all confirmed dispatched in the body — "10" is the *callee* count (the call-graph column, correct at "10 callees"), not the opcode count; two of those 10 callees (`0x600f6206`, `0x600f6be6`) are the validation gate and error-reject calls, not opcode handlers, and two opcode PAIRS share one handler each (`0x06`/`0x10` both call `FUN_600ae4e0`; `0x0a`/`0x0c`/`0x12`/`0x16`/`0x52`/`0xd2` all fall through to `FUN_600aee8c`) — hence 14 opcodes routing through only 8 distinct handler functions. A hand-count slip in the prose, not a functional error; all opcodes and callees independently confirmed correct. *(corrected, QA session 133)* | 2 callers / 10 callees |
| `0x600f662c` |   60 | GATT / Core | **`gatt_update_prio_queue_tail`** — GATT priority queue tail updater: scans list starting at `param_1 + 4` and updates tail pointer `*param_1`. | 2 callers / 0 callees |
| `0x600f6668` |  194 | GATT / Core | **`gatt_prio_queue_enqueue`** — GATT priority queue sorted enqueue: inserts node into doubly-linked priority list sorted by priority/handle, updates tail via `0x600f662c`. | 1 caller / 1 callee |
| `0x600f672a` |  136 | GATT / Core | **`gatt_prio_queue_dequeue_node`** — GATT priority queue remove node: unlinks node from doubly-linked priority list, updates tail via `0x600f662c`. | 1 caller / 1 callee |
| `0x600f67b2` |  184 | GATT / Server | **`gatts_enqueue_sr_cmd`** — GATT server command queue sorted enqueue: inserts entry sorted descending by timeout/sequence into server queue `param_1`. | 2 callers / 0 callees |
| `0x600f686a` |  134 | GATT / Server | **`gatts_dequeue_sr_cmd_entry`** — GATT server command queue remove entry: unlinks entry from server queue `param_1` and decrements count. | 2 callers / 0 callees |
| `0x600f68f0` |  256 | GATT / Core | **`gatt_uuid_compare`** — Universal GATT UUID matcher: compares 16-bit, 32-bit, and 128-bit UUIDs, expanding to 128-bit Bluetooth Base UUIDs via `0x600af95c`/`0x600af9a0` and comparing 16 bytes (`0x6013d168`). | 7 callers / 3 callees |
| `0x600f69f0` |  154 | GATT / Core | **`gatt_serialize_uuid`** — GATT serialize UUID: formats 16-bit (2B LE), 32-bit (16B Base UUID via `0x600af9a0`), or 128-bit (16B raw) into output buffer. | 4 callers / 1 callee |
| `0x600f6a8a` |   38 | GATT / Client | **`gatt_start_rsp_timer`** — GATT start client response timer: arms 30-second timer (`0x1e`) for timer event `0x31` (`BTU_TTYPE_ATT_WAIT_FOR_RSP`) at `param_1 + 200` via `0x600aa340`. | 2 callers / 1 callee |
| `0x600f6ab0` |   38 | GATT / Client | **`gatt_start_ind_ack_timer`** — GATT start indication confirmation timer: arms 30-second timer (`0x1e`) for timer event `0x31` at `param_1 + 0x74` via `0x600aa340`. | 1 caller / 1 callee |
| `0x600f6ad6` |   38 | GATT / Server | **`gatts_start_sr_rsp_timer`** — GATT server start application response timer: arms 30-second timer (`0x1e`) for timer event `0x35` (`BTU_TTYPE_ATT_SR_RSP`) at `param_1 + 0xe0` via `0x600aa340`. | 1 caller / 1 callee |
| `0x600f6afc` |   26 | GATT / Core | **`gatt_rsp_timeout_disconnect`** — GATT response timeout handler: tears down transport connection via `0x600f592e`. | 0 callers / 1 callee |
| `0x600f6b16` |   52 | GATT / Core | **`gatt_ind_ack_timeout_handler`** — GATT indication confirmation timeout processor: clears pending flag `+0x96` and processes timeout event via `0x600ffada`. | 0 callers / 1 callee |

**⚠️ QA session 133 note:** Backbone clean — all 13 addresses/sizes match the census exactly, summing to the claimed 1,588 bytes, fully contiguous `0x600f6516`–`0x600f6b4a`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,402 functions / 503,844 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 70.51% exactly.

**One minor correction — a hand-count slip, not a functional error.** `0x600f6516`'s prose claimed "10 ATT request opcodes" but its own parenthetical lists 14 (all real ATT request opcodes, all confirmed independently dispatched in the body). Traced the dispatch logic fully: 14 opcodes route through only 8 distinct handler functions — `0x06`/`0x10` share one handler (`FUN_600ae4e0`), and `0x0a`/`0x0c`/`0x12`/`0x16`/`0x52`/`0xd2` all fall through to one shared handler (`FUN_600aee8c`) — plus 2 more non-handler calls (the validation gate `0x600f6206` and the error-reject `0x600f6be6`), totaling the claimed "10 callees" exactly. The "10" figure was simply describing the wrong count (callees, not opcodes). Corrected in place; no behavioral claim needed changing.

**Strong corroboration elsewhere, zero further corrections.** `0x600f68f0`'s "Universal GATT UUID matcher" precisely composes two already-established UUID-expansion helpers (`0x600af9a0`=`gatt_build_32bit_uuid`, confirmed session 130) plus the established memcmp thunk to normalize-then-compare UUIDs of any width — exactly matching real GATT UUID-comparison semantics. `0x600f69f0`'s three UUID-serialization branches (2-byte LE, 32-bit-via-Base-UUID, 16-byte raw) match precisely, and it's independently corroborated by its caller `0x600f4f02` (session 129's confirmed `gatts_read_attr_value_by_handle`), which needs exactly this UUID-formatting logic to build attribute-read responses. `0x600aa340`, cited by all three timer-start functions, matches its already-established `btu_start_timer` identity exactly — the "arms a timer" framing is consistent, not the opposite-direction mismatch a naming coincidence with the *different*, already-established `0x600aa3cc`/`btu_stop_timer` might have suggested at a glance (checked and ruled out explicitly). `0x600f6afc`'s "response timeout → disconnect via `0x600f592e`" is a well-evidenced real-world trigger for that function's disconnect behavior, reinforcing (not contradicting) session 131's overall framing of `0x600f592e` even though that session's "still connecting" branch caveat remains separately unresolved. `0x600f67b2`'s descending-sort-order claim was traced through its comparison logic and confirmed exactly.

**Reliability read**: a clean wave overall — the one finding is cosmetic (an arithmetic slip in the prose, the same low-severity class as sessions 31/50/121), and every functional/behavioral claim checked out, several with strong cross-session corroboration reinforcing prior sessions' work rather than needing correction themselves.

## Session 134 (Wave 104) — Broadcom GATT Link Security, App Callbacks, SDP Registration & Prepare/Execute State (15 functions, 1,518 bytes)

Decompiled and documented 15 functions (1,518 bytes across `0x600f6b4a`–`0x600f7138`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f6b4a` |   76 | GATT / Security | **`gatt_get_link_sec_info`** — GATT link security query: queries BTM security level (masked with `0x34`) via `0x600f194c` (established `bta_dm_get_sec_level`) and ~~encryption key size~~ ⚠️ `0x600f0994` is already independently established as `bta_dm_get_sec_flags` ("Retrieves security auth flags from device record: byte `+0x60` (transport 1) or `+0x61` (transport 2)") — read its body directly this session and confirmed it exactly: looks up the device record via the confirmed `0x6009ff18`, then returns the raw `+0x60`/`+0x61` byte selected by transport, with no key-size computation anywhere. Real second value queried is the device's security **auth flags**, not an encryption key size. *(corrected, QA session 134)* | 4 callers / 2 callees |
| `0x600f6b96` |   80 | GATT / Server | **`gatts_invoke_app_cback`** — GATT server dispatch application callback: locates registration record (`0x600afd28`) and invokes `p_app_cb(conn_id, trans_id, op_code, p_data)`. | 5 callers / 1 callee |
| `0x600f6be6` |  102 | GATT / Server | **`gatts_send_error_rsp`** — GATT server send ATT Error Response (`0x01`): builds error response via `0x600c7eb8`, transmits via `0x600ff9fe`, optionally clears transaction (`0x600adc88`). | 11 callers / 3 callees |
| `0x600f6c4c` |  336 | GATT / Server | **`gatt_create_sdp_record`** — GATT SDP record creator: registers Bluetooth SDP record for GATT service with Service Class UUID, Protocol Descriptor List (L2CAP PSM `0x1f`, ATT `0x0007`), and Public Browse Group (`0x1002`). | 1 caller / 6 callees |
| `0x600f6d9c` |   42 | GATT / Client | **`gatt_clcb_dealloc`** — GATT client control block deallocator: zeros 96-byte (`0x60`) CLCB structure if allocated. | 6 callers / 1 callee |
| `0x600f6dc6` |   62 | GATT / Core | **`gatt_num_apps_holding_link`** — GATT application hold counter: counts number of active non-zero app entries in 10-slot array `param_1 + 0x1e`. | 7 callers / 0 callees |
| `0x600f6e04` |   70 | GATT / Server | **`gatts_copy_prep_to_exec_flags`** — GATT server copy prepare write flags to execute write response flags (`+0x8c` -> `+0x58`). | 1 caller / 0 callees |
| `0x600f6e4a` |   76 | GATT / Server | **`gatts_is_all_exec_rsp_rcvd`** — GATT server check if all application execute write responses received (all `+0x58` entries zero). | 1 caller / 0 callees |
| `0x600f6e96` |   76 | GATT / Server | **`gatts_is_prep_queue_empty`** — GATT server check if prepare write buffer queue is empty (all `+0x8c` entries zero). | 1 caller / 0 callees |
| `0x600f6ee2` |   56 | GATT / Server | **`gatts_clear_exec_rsp_flags`** — GATT server clear all execute write response flags (`+0x58` array of 10 entries zeroed). | 3 callers / 0 callees |
| `0x600f6f1a` |   56 | GATT / Server | **`gatts_clear_prep_write_flags`** — GATT server clear all prepare write application flags (`+0x8c` array of 10 entries zeroed). | 1 caller / 0 callees |
| `0x600f6f52` |  128 | GATT / Server | **`gatts_update_exec_rsp_flags`** — GATT server update execute write response tracking counter for application ID at `+0x58 + (app_id - 1)`. | 2 callers / 1 callee |
| `0x600f6fd2` |  128 | GATT / Server | **`gatts_update_prep_write_flags`** — GATT server update prepare write buffer tracking counter for application ID at `+0x8c + (app_id - 1)`. | 1 caller / 1 callee |
| `0x600f7052` |   98 | GATT / Core | **`gatt_cancel_open_dev`** — GATT cancel pending connection request action: removes app hold via `0x600f5a98`, tears down transport if no apps remaining via `0x600f592e`. | 1 caller / 5 callees |
| `0x600f70b4` |  132 | GATT / Client | **`gattc_build_and_send_write_req`** — GATT client write request builder and event dispatcher: copies write buffer and dispatches via `0x600ffada`. | 2 callers / 2 callees |

**⚠️ QA session 134 note:** Backbone clean — all 15 addresses/sizes match the census exactly, summing to the claimed 1,518 bytes, fully contiguous `0x600f6b4a`–`0x600f7138`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,417 functions / 505,362 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 70.72% exactly.

**One confirmed finding**: `0x600f6b4a`'s second callee, `0x600f0994`, was described as returning "encryption key size" — but that address is already independently established as `bta_dm_get_sec_flags` ("Retrieves security auth flags from device record: byte `+0x60` (transport 1) or `+0x61` (transport 2)"). Read its body directly this session and confirmed it precisely: looks up the device record via the confirmed `0x6009ff18`, then returns the raw `+0x60`/`+0x61` byte selected by transport — no key-size arithmetic anywhere. Corrected in place; the enclosing function's overall "link security query" framing remains sound (it genuinely queries two different security-related fields — level, then flags — just not level-then-key-size).

**Excellent cross-session consistency and strong spec corroboration elsewhere, zero further corrections.** This wave reuses three separate 10-slot per-application array conventions already established in sessions 131–133 (`+0x1e` app-hold tracking, `+0x58` execute-write-response flags, `+0x8c` prepare-write flags) with perfect internal consistency across 8 of this wave's own functions (get/set/clear/copy operations all agreeing on the same offsets and semantics). `0x600f6c4c`'s SDP record builder independently confirms **four** distinct real Bluetooth SIG constants in one function: `0x1002` (PublicBrowseGroup UUID), `0x1f` (L2CAP ATT-over-BR/EDR PSM, matching this wave's own earlier confirmed uses), `0x0100` (L2CAP protocol UUID), and `0x0007` (ATT protocol UUID) — a Protocol Descriptor List correctly encoding both L2CAP and ATT protocol layers. `0x600f7052`'s hold-then-count-then-teardown sequence correctly composes three already-established functions from this cluster (`0x600f5a98`, `0x600f6dc6`, `0x600f592e`) with argument conventions matching each one's own established semantics exactly (e.g. passing `param_3=0` to `0x600f5a98` correctly matches session 131's confirmed "remove" convention).

**Reliability read**: another strong wave — the one finding was caught by the standing appendix cross-check against a well-evidenced, specific existing entry, and the wave's dense reuse of established offset/argument conventions across its own 15 functions (not just against prior sessions) is itself a form of self-consistency that held up throughout.

## Session 135 (Wave 105) — Broadcom GATT Background Auto-Connect/Listen, BTU VSC Builder & L2CAP Connection Request (11 functions, 1,684 bytes)

Decompiled and documented 11 functions (1,684 bytes across `0x600f7138`–`0x600f77cc`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f7138` |   68 | GATT / Core | **`gatt_is_app_in_listen_list`** — GATT check if application ID registered in background listen list (`param_1[0..9]`), gated by active listen flag `+0x1a`. | 1 caller / 0 callees |
| `0x600f717c` |  252 | GATT / Core | **`gatt_add_bg_conn_dev`** — GATT add device to background auto-connection or white-list: adds app to background record and starts auto-connect (`0x600f139a`) or updates white-list (`0x6009ca80`). | 1 caller / 4 callees |
| `0x600f7278` |   62 | GATT / Core | ~~**`gatt_start_listen_dev`** — GATT start background listen on device: unholds direct link (`0x600f5a98`) and registers background listen (`0x600f74a8`).~~ ⚠️ **QA session 135**: self-contradicted by this same wave's own `0x600f74a8` row — `0x600f7278` calls `FUN_600f74a8(param_1, 0, param_2, 1)`, passing literal `0` as the second argument, but `0x600f74a8`'s own confirmed dispatch logic (`if (param_2 == '\0') { calls the confirmed gatt_remove_bg_conn_dev }`) means this triggers the **remove** path, not registration. Independently corroborated by the caller context: `0x600f7278`'s sole caller is `0x600f3caa`, already independently established (session 126) as `gatt_disconnect_dev` — "disconnect / unlisten initiator... disconnects via `0x600f7278`" — a disconnect context, not a listen-start one. Real behavior: unholds the direct link and removes background/white-list tracking for a device being disconnected — closer to `gatt_disconnect_and_unlisten_dev` than "start listen." *(corrected, QA session 135)* | 1 caller / 3 callees |
| `0x600f72b6` |   74 | GATT / Core | **`gatt_num_apps_listening_dev`** — GATT count number of applications listening for device in background white-list array `+0..9`. | 1 caller / 1 callee |
| `0x600f7300` |   90 | GATT / Core | **`gatt_get_first_listening_app`** — GATT get first application ID listening for device in background white-list array `+0..9`. | 1 caller / 1 callee |
| `0x600f735a` |  334 | GATT / Core | **`gatt_remove_bg_conn_dev`** — GATT remove device from background auto-connection or white-list: unlinks app, stops auto-conn (`0x600f139a`) or removes from white-list (`0x6009ca80`), freeing record if empty. | 1 caller / 4 callees |
| `0x600f74a8` |  130 | GATT / Core | **`gatt_update_auto_connect_dev`** — GATT auto-connect / listen dispatcher: adds (`0x600f717c`) or removes (`0x600f735a`) background device registration, holding active link if connected. | 3 callers / 5 callees |
| `0x600f752a` |  150 | HCI / BTU | **`btu_hcif_send_vsc`** — Broadcom BTU vendor-specific HCI command formatter and transmitter: builds VSC (`0xfc00 | param_2`) packet and sends via `0x600a9234`. | 1 caller / 1 callee |
| `0x600f75c0` |  202 | L2CAP / Core | **`L2CA_Register`** — Broadcom L2CAP layer PSM registration API: allocates RCB (`0x600bc1a8`/`0x600bc158`), stores 11 callback pointers (44B), assigns fixed/dynamic PSM. | 2 callers / 2 callees |
| `0x600f768a` |   34 | L2CAP / Core | **`L2CA_ConnectReq`** — Broadcom L2CAP connection request API wrapper: delegates to `0x600f76ac(param_1, param_2, 0)`. | 1 caller / 1 callee |
| `0x600f76ac` |  288 | L2CAP / Core | **`L2CA_ErtmConnectReq`** — Broadcom L2CAP connection request implementation: allocates CCB (`0x600bbd3c`), configures ERTM QoS parameters, triggers state machine via `0x600b5e00`, and returns local CID. | 1 caller / 8 callees |

**⚠️ QA session 135 note:** Backbone clean — all 11 addresses/sizes match the census exactly, summing to the claimed 1,684 bytes, fully contiguous `0x600f7138`–`0x600f77cc`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,428 functions / 507,046 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 70.96% exactly.

**One confirmed finding, self-contradicted within the same wave's own table.** `0x600f7278` (claimed `gatt_start_listen_dev`, "registers background listen") calls `0x600f74a8` with a literal `0` second argument — but `0x600f74a8`'s own row in this same table (confirmed by reading its body) documents that `param_2 == 0` selects the **remove** path (the confirmed `gatt_remove_bg_conn_dev`), not registration. Independently corroborated by the caller context: `0x600f7278`'s sole caller is `0x600f3caa`, already established (session 126) as `gatt_disconnect_dev` — a disconnect context, not a listen-start one. Real behavior: unholds the direct link and removes background/white-list tracking for a device being disconnected. Corrected in place; no `GHIDRA-TODO` needed (identification-only).

**Strong spec corroboration elsewhere, zero further corrections.** `0x600f752a`'s VSC opcode construction (`(param_2>>8) | 0xfc`) matches the real HCI convention that all Vendor-Specific Command opcodes carry OGF `0x3F` in their upper byte exactly. `0x600f75c0`'s PSM validation bitmask (`param_1 & 0x101 == 1`) matches the real L2CAP spec's PSM-validity rule (odd least-significant bit, clear bit 8) precisely, its dynamic-PSM search range (`> 0x1000`, stepping by 2 to stay odd) matches the real spec's dynamic-PSM allocation range exactly, and its "11 callback pointers (44B)" claim matches its own literal copy loop exactly. `0x600f76ac` correctly composes the already-established `BTM_IsDeviceUp` (confirmed since session 119) as a precondition check and the confirmed `L2CA_Register`'s own RCB allocator (`0x600bc1a8`) from this same wave's row — cross-checking cleanly against a sibling function decompiled in the same session.

**Reliability read**: a wave with a real, well-caught finding — an internal self-contradiction between two of the wave's own rows, reinforced by an independent cross-session caller check — sitting alongside multiple precise, independently-checkable Bluetooth spec matches (VSC opcode convention, L2CAP PSM validity rule, dynamic-PSM range) that held up without correction.

## Session 136 (Wave 106) — Broadcom L2CAP Connect/Config/Disconnect APIs, Priority & BLE Parameter Updaters (15 functions, 1,468 bytes)

Decompiled and documented 15 functions (1,468 bytes across `0x600f77cc`–`0x600f7d88`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f77cc` |   58 | L2CAP / Core | **`L2CA_ConnectRsp`** — Broadcom L2CAP connection response API wrapper: delegates to `0x600f7806(param_1..5, 0)`. | 2 callers / 1 callee |
| `0x600f7806` |  268 | L2CAP / Core | **`L2CA_ErtmConnectRsp`** — Broadcom L2CAP connection response implementation: validates CCB, initializes ERTM parameters, and sends positive (`0x16`) or negative (`0x17`) connect response event. | 1 caller / 4 callees |
| `0x600f7912` |  150 | L2CAP / Core | **`L2CA_ConfigReq`** — Broadcom L2CAP configuration request API: validates configuration (`0x600f8450`), clamps MTU to 584, copies config block, and dispatches event `0x18`. | 4 callers / 4 callees |
| `0x600f79a8` |  140 | L2CAP / Core | **`L2CA_ConfigRsp`** — Broadcom L2CAP configuration response API: handles positive (`0x19`) or negative (`0x1a`) configuration responses, clearing rejected options. | 2 callers / 2 callees |
| `0x600f7a34` |   52 | L2CAP / Core | **`L2CA_DisconnectReq`** — Broadcom L2CAP disconnect request API: looks up CCB and sends disconnect request event `0x1b`. | 4 callers / 2 callees |
| `0x600f7a68` |   52 | L2CAP / Core | **`L2CA_DisconnectRsp`** — Broadcom L2CAP disconnect response API: looks up CCB and sends disconnect response event `0x1c`. | 2 callers / 2 callees |
| `0x600f7a9c` |  138 | L2CAP / Core | **`L2CA_SetTxPriority`** — Broadcom L2CAP channel transmit priority configurator: updates priority field `+0x120` and kicks transmit queue (`0x600fa0d6`). | 1 caller / 2 callees |
| `0x600f7b26` |   34 | L2CAP / Core | **`L2CA_DataWrite`** — Broadcom L2CAP dynamic channel data transmit API: writes data packet to channel via `0x600bb3b4(cid, p_buf, 0)`. | 5 callers / 1 callee |
| `0x600f7b48` |  144 | L2CAP / Core | **`L2CA_UpdateBleConnParams`** — Broadcom L2CAP BLE connection parameter update request API: stores interval/latency/timeout parameters into LCB, sets flag `+0x38 |= 2`, and sends update via `0x600b5844`. | 2 callers / 3 callees |
| `0x600f7bd8` |  106 | L2CAP / Core | **`L2CA_EnableBleUpdateParams`** — Broadcom L2CAP enable or disable BLE connection parameter updates: sets (`+0x38 |= 1`) or clears (`+0x38 &= ~1`) hold flag. | 4 callers / 2 callees |
| `0x600f7c42` |   44 | L2CAP / Core | **`L2CA_GetBleConnRole`** — Broadcom L2CAP get BLE connection link role: returns role byte `*(p_lcb + 10)` or `0xff` if not found. | 4 callers / 1 callee |
| `0x600f7c6e` |   50 | L2CAP / Core | **`L2CA_GetDisconnectReason`** — Broadcom L2CAP get link disconnect reason code: returns status word `*(p_lcb + 0x30)`. | 2 callers / 1 callee |
| `0x600f7ca0` |   74 | L2CAP / Core | **`L2CA_ConnectBleLink`** — Broadcom L2CAP handle BLE link connection completion: sets connected state `4`, starts supervision timer (`0x60099c0c`), and notifies L2CAP link up (`0x600bc994`). | 2 callers / 4 callees |
| `0x600f7cea` |   92 | L2CAP / Core | **`L2CA_BleConnParamsRsp`** — Broadcom L2CAP process BLE connection parameter update response: notifies BTM (`0x6009ec54`) and sends positive (`0x600b5540`) or negative (`0x600b5720`) update response. | 2 callers / 3 callees |
| `0x600f7d46` |   66 | L2CAP / Core | **`L2CA_ClearBleUpdateParamsPending`** — Broadcom L2CAP clear BLE connection parameter update in-progress state: clears flag `+0x38 &= ~4` via `0x600bcbe0` and `0x600b5844`. | 1 caller / 2 callees |

**⚠️ QA session 136 note:** Backbone clean — all 15 addresses/sizes match the census exactly, summing to the claimed 1,468 bytes, fully contiguous `0x600f77cc`–`0x600f7d88`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,443 functions / 508,514 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 71.16% exactly.

**Zero corrections to this wave's own claims — but a significant "cross-reference cuts both ways" finding in an older appendix entry, exposed by this wave's fresh context.** `0x600f7b26` (`L2CA_DataWrite`, "writes data packet to channel via `0x600bb3b4`") calls an address already established in `bruce-bta-stack.md` as `l2cu_disconnect_ccb` ("Initiates disconnect sequence for channel control block") — a direct contradiction with "write data." Read `0x600bb3b4`'s body directly: it looks up the CCB, checks the packet length against the channel's MTU field, tags the buffer header, and — if the channel isn't congested — dispatches event `0x1e` through the confirmed central state-machine dispatcher `l2c_csm_execute`; failure paths log via the established `__FILE__`/line-number log helper and discard the buffer. No disconnect-reason field, no teardown/state-4 logic anywhere — this is a genuine data-transmit operation. Corrected the older entry in `bruce-bta-stack.md` in place; this wave's own `L2CA_DataWrite` framing needed no change.

**Strong spec/mechanism corroboration throughout, all confirmed correct.** `0x600f7912`'s MTU clamp value (`0x248` = 584) matches its claimed "clamps MTU to 584" exactly. `0x600b5e00` (already established as the central L2CAP channel state-machine dispatcher `l2c_csm_execute`) is the mechanism behind essentially every "sends event `0xNN`" claim across this wave's connect/config/disconnect API wrappers — confirming those framings are grounded in a real, already-verified dispatch mechanism, not a guess. `0x600b5844` (already established as the L2CAP-side handler that issues the real HCI LE Connection Update command) matches this wave's three BLE-parameter-update functions (`0x600f7b48`, `0x600f7bd8`, `0x600f7d46`) precisely. `0x600f7c6e`'s "disconnect reason" framing is independently reconfirmed by its own established callers from session 132 (`gatt_l2c_disconnect_ind_cb`/`_cfm_cb`), which already describe calling it for exactly that purpose.

**Reliability read**: another strong wave for the L2CAP API-surface cluster — every one of the wave's own 15 rows checked out, and the one real finding (a wrong, unhedged appendix entry from an earlier session) was caught the same way sessions 114/123/127 caught similar cases: reading a callee's own body when the calling context didn't fit the established label, rather than trusting either source at face value.

## Session 137 (Wave 107) — Broadcom L2CAP BLE Signaling Parser, Parameter Updaters & ERTM Flow Control (15 functions, 1,736 bytes)

Decompiled and documented 15 functions (1,736 bytes across `0x600f7d88`–`0x600f8450`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f7d88` |  424 | L2CAP / BLE | **`l2c_ble_process_sig_cmd`** — Broadcom L2CAP BLE signaling packet processor: parses opcode `0x12` (`L2CAP_CMD_BLE_UPDATE_REQ`), validates 4 connection interval/latency/timeout ranges against spec, sends response (`0x600f8208`), and handles opcode `0x13` (`L2CAP_CMD_BLE_UPDATE_RSP`). | 1 caller / 4 callees |
| `0x600f7f30` |   68 | L2CAP / BLE | **`l2c_ble_start_create_conn`** — Broadcom L2CAP BLE connection initiation scheduler: checks scanner/adv state (`0x6009c778`), initiates connection (`0x600b59ec`) or queues request (`0x6009c7c8`). | 1 caller / 4 callees |
| `0x600f7f74` |  150 | L2CAP / BLE | **`l2c_ble_send_conn_param_req`** — Broadcom L2CAP execute or defer BLE connection parameter update: issues HCI command (`0x600b16c4`) or notifies BTM (`0x600b1804`). | 1 caller / 3 callees |
| `0x600f800a` |  130 | L2CAP / BLE | **`l2c_ble_update_data_len`** — Broadcom L2CAP BLE data length recomputer: scans fixed channels, clamps max length to 251 (`0xfb`), and updates controller via `0x6009ac8c`. | 1 caller / 1 callee |
| `0x600f808c` |   56 | L2CAP / BLE | **`l2c_ble_set_conn_interval`** — Broadcom L2CAP record BLE connection interval: stores interval `param_2` into LCB field `+0x36`. | 1 caller / 1 callee |
| `0x600f80c4` |   94 | L2CAP / BLE | **`L2CA_SetFixedChannelTxDataLength`** — Broadcom L2CAP set fixed channel transmit data length: updates CCB field `+0x122` (clamped to 251) and recomputes link data length (`0x600f800a`). | 2 callers / 2 callees |
| `0x600f8122` |  230 | L2CAP / BLE | **`l2c_ble_send_peer_conn_param_upd_req`** — Broadcom L2CAP format and send BLE connection parameter update request packet: builds 8-byte signaling PDU (`0x12`), arms 30s timer, and sends via `0x600b9408`. | 1 caller / 4 callees |
| `0x600f8208` |   92 | L2CAP / BLE | **`l2c_ble_send_peer_conn_param_upd_rsp`** — Broadcom L2CAP format and send BLE connection parameter update response packet: builds 2-byte signaling PDU (`0x13`) and sends via `0x600b9408`. | 1 caller / 2 callees |
| `0x600f8264` |   44 | L2CAP / ERTM | **`l2c_fcs_compute_frame`** — Broadcom L2CAP ERTM frame check sequence computation helper: calculates FCS CRC16 over packet payload via `0x600b72cc`. | 2 callers / 1 callee |
| `0x600f8290` |   52 | L2CAP / ERTM | **`l2c_fcs_compute_frame_with_hdr`** — Broadcom L2CAP ERTM frame check sequence computation with header: calculates CRC16 over header + payload via `0x600b72cc`. | 2 callers / 1 callee |
| `0x600f82c4` |   38 | L2CAP / ERTM | **`l2c_ertm_stop_ack_timer`** — Broadcom L2CAP ERTM stop acknowledgement timer: stops active timer at `+0x100` via `0x600aa4c4`. | 6 callers / 1 callee |
| `0x600f82ea` |   64 | L2CAP / ERTM | **`l2c_ertm_is_chan_congested`** — Broadcom L2CAP ERTM congestion check: tests if unacked I-frame count `+0xcc` reaches window size `+0x7f` or window closed `+0xb6 == 1`. | 4 callers / 0 callees |
| `0x600f832a` |  118 | L2CAP / ERTM | **`l2c_ertm_process_retrans_timeout`** — Broadcom L2CAP ERTM handle retransmission timeout: increments retry counter `+0xb4`, triggers disconnect if exceeded (`0x600f9db4`) or sends poll S-frame (`0x600b7674`). | 1 caller / 2 callees |
| `0x600f83a0` |   82 | L2CAP / ERTM | **`l2c_ertm_process_ack_timeout`** — Broadcom L2CAP ERTM handle delayed ack timeout: sends acknowledgement S-frame via `0x600b7674` if unacknowledged frames pending. | 1 caller / 1 callee |
| `0x600f83f2` |   94 | L2CAP / ERTM | **`l2cu_filter_channel_modes`** — Broadcom L2CAP filter allowed channel modes against peer feature mask: masks out FCS/ERTM bits if peer features lack support. | 4 callers / 0 callees |

**⚠️ QA session 137 note:** Backbone clean — all 15 addresses/sizes match the census exactly, summing to the claimed 1,736 bytes, fully contiguous `0x600f7d88`–`0x600f8450`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,458 functions / 510,250 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 71.40% exactly.

**Zero corrections — the strongest real-spec numeric-constant density of this cluster to date.** `0x600f7d88`'s four connection-parameter validation ranges match the real BLE Core Spec Connection Parameter Update Request bounds exactly: interval_min/max both `6`–`0xc80` (3200), latency `≤500`, timeout `10`–`0xc80`, plus the correctly-required `interval_max ≥ interval_min` check — five independently-checkable exact spec matches in one function. Its two handled opcodes (`0x12`/`0x13`) match the real L2CAP signaling codes for Connection Parameter Update Request/Response exactly. `0x600f8122`/`0x600f8208` build and send those exact two PDUs with the real spec's exact payload sizes (8 bytes for the 4-field request, 2 bytes for the single-field response) — cross-validated within the same wave, since `0x600f7d88` calls `0x600f8208` directly for its own response path. `0x600f800a`/`0x600f80c4`'s data-length clamp (`0xfb` = 251) matches the real BLE Data Length Extension maximum PDU payload exactly. `0x600f8122`'s 30-second timer arms through the already-established `btu_start_timer`, and `0x600f7d88`'s opcode-`0x13` handler stops it through the already-established `btu_stop_timer` — a complete, correctly-paired arm/disarm cycle across two functions. `0x600bb7e4` (already established as an L2CAP I-frame buffer-construction primitive that "writes the L2CAP basic/FCR header") matches this wave's "builds... signaling PDU" framing precisely.

**One soft observation, not a correction**: `0x600b9408`, already established as "a common sub-routine across the GATT-cache handlers" (16 callers, deliberately hedged/generic), gets two new callers from this wave in an unrelated L2CAP-signaling-send context. The established note's own hedging already accommodates broad reuse as a generic dispatch primitive, so this isn't a contradiction — just a scope extension worth noting for whoever eventually gives this address a firmer identity.

**Reliability read**: an outstanding wave — five independently-checkable exact numeric-range matches in a single function (`0x600f7d88`) is close to the strongest single-function spec corroboration this whole pipeline has produced, on par with sessions 72/78/84's flagship confirmations.

## Session 138 (Wave 108) — Broadcom L2CAP ERTM/FCR Configuration Negotiation & Channel Security Callbacks (7 functions, 1,690 bytes)

Decompiled and documented 7 functions (1,690 bytes across `0x600f8450`–`0x600f8aea`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f8450` |  344 | L2CAP / ERTM | **`l2cu_validate_fcr_config`** — Broadcom L2CAP validate & negotiate ERTM/FCR configuration: filters allowed modes (`0x600f83f2`), checks MTU/MPS, sets default MPS (1010), clamps MPS to 572, and copies options to CCB `+0x32`. | 1 caller / 2 callees |
| `0x600f85a8` |   80 | L2CAP / ERTM | **`l2c_fcr_adj_monitor_retrans_timeouts`** — Broadcom L2CAP set ERTM retransmission and monitor timer defaults: sets monitor timer to 12000 ms (`+0x38`) and retrans timer to 2000 ms (`+0x36`). | 2 callers / 0 callees |
| `0x600f85f8` |  108 | L2CAP / ERTM | **`l2c_fcr_adj_our_rsp_options`** — Broadcom L2CAP populate FCR response options structure: sets timer defaults (`0x600f85a8`) and copies negotiated mode/window/MPS fields into config structure. | 1 caller / 1 callee |
| `0x600f8664` |  340 | L2CAP / ERTM | **`l2cu_process_unacceptable_fcr_rsp`** — Broadcom L2CAP process unacceptable FCR config response: decrements retry count `+0x11c`, renegotiates fallback mode (Streaming -> ERTM -> Basic), re-arms 30s timer, or disconnects (`0x600f9db4`). | 1 caller / 4 callees |
| `0x600f87b8` |  562 | L2CAP / ERTM | **`l2cu_check_fcr_config_req`** — Broadcom L2CAP validate peer incoming FCR config request: verifies proposed mode, adjusts MPS against MTU/buffer pool (`sVar1 - 25`), returns 1 (acceptable), 0 (unacceptable fallback), or 2 (reject). | 1 caller / 1 callee |
| `0x600f89ea` |  172 | L2CAP / Core | **`l2c_link_sec_comp`** — Broadcom L2CAP BR/EDR channel security check completion callback: walks LCB channel list and dispatches event 7 (`L2CEVT_SEC_COMP`) or 8 (`L2CEVT_SEC_COMP_FAIL`) via `0x600b5e00`. | 0 callers / 4 callees |
| `0x600f8a96` |   84 | L2CAP / Core | **`l2c_ble_link_sec_comp`** — Broadcom L2CAP BLE link security status update: walks active channels for handle (`0x600bcbe0`) and dispatches event 6 (`L2CEVT_L2CA_CONNECT_PND`) via `0x600b5e00`. | 1 caller / 2 callees |

**⚠️ QA session 138 note:** Backbone clean — all 7 addresses/sizes match the census exactly, summing to the claimed 1,690 bytes, fully contiguous `0x600f8450`–`0x600f8aea`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,465 functions / 511,940 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 71.64% exactly.

**Zero corrections — a dense run of exact numeric-constant matches, several cross-validating this wave's own or a prior session's work.** `0x600f8450`'s two MPS constants (`0x3f2`=1010 default, `0x23c`=572 clamp) both match its own claim exactly, and it correctly composes session 137's own confirmed `l2cu_filter_channel_modes` (`0x600f83f2`). `0x600f85a8`'s two timer values (12000ms monitor, 2000ms retransmission) match its claim exactly. `0x600f8664`'s mode-fallback cascade (Streaming→ERTM→Basic, decoded from the mode-enum values 4→3→0) matches precisely, its "re-arms 30s timer" claim is confirmed via the already-established `btu_start_timer` with literal duration `0x1e`, and its Basic-mode MTU clamp reuses the exact `0x248`=584 constant session 137's `0x600f7912` independently established. `0x600f87b8`'s "sVar1 − 25" MPS-adjustment claim matches its literal `0x19`(25) subtraction exactly, in a buffer-pool-size-lookup context. `0x600f89ea`/`0x600f8a96` both correctly identify `0x600b5e00` as the dispatch mechanism (the already-established central L2CAP state-machine dispatcher `l2c_csm_execute`), and `0x600f8a96` correctly cites `0x600bcbe0` as the already-established `l2cu_find_lcb_by_handle`.

**One unconfirmed (not flagged) detail**: `0x600f8a96`'s claimed enum name for its dispatched event 6, `L2CEVT_L2CA_CONNECT_PND`, sits oddly next to the function's own name (`l2c_ble_link_sec_comp`, implying a security-completion event) — but with no independent string-table or cross-call-site evidence available to confirm or refute the *specific* enum label for event code 6, this is left unflagged rather than guessed at either way; the function's underlying mechanics (handle lookup, channel walk, event dispatch through the confirmed state machine) are solidly evidenced regardless of the exact label.

**Reliability read**: another strong wave — dense, independently-checkable numeric-constant corroboration throughout, plus two instances of correctly reusing session 137's own established functions/constants, showing this L2CAP ERTM/FCR sub-cluster's internal consistency is holding up wave over wave.

## Session 139 (Wave 109) — Broadcom L2CAP Link Timers & Signaling Packet Builders (9 functions, 1,168 bytes)

Decompiled and documented 9 functions (1,168 bytes across `0x600f8aea`–`0x600f8f7a`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f8aea` |  190 | L2CAP / Link | **`l2c_link_timeout_disconnect`** — Broadcom L2CAP physical link disconnect timeout handler: checks connecting channels or tx queue, and dispatches event 0x13 (`L2CEVT_LP_DISCONNECT_IND`) via `0x600b5e00` to all open CCBs. | 1 caller / 3 callees |
| `0x600f8ba8` |   44 | L2CAP / Core | **`L2CA_GetLinkRole`** — Broadcom L2CAP get BR/EDR link role: queries role byte `*(p_lcb + 10)` (0=master, 1=slave) or 0xff via `0x600bb6dc`. | 1 caller / 1 callee |
| `0x600f8bd4` |   54 | L2CAP / Link | **`l2c_link_check_idle_timer`** — Broadcom L2CAP link idle timer manager: starts 120s timer (`0x78`) on BR/EDR link via `0x600aa340` if no active channels open. | 4 callers / 2 callees |
| `0x600f8c0a` |   42 | L2CAP / Link | **`l2c_link_set_tx_active`** — Broadcom L2CAP set link transmit activity status: updates byte `*(p_lcb + 0x16)` for BR/EDR link. | 4 callers / 1 callee |
| `0x600f8c34` |   54 | L2CAP / Signaling | **`l2cu_adj_sig_id`** — Broadcom L2CAP validate signaling transaction identifier: ensures command identifier `*(p_lcb + 0xb)` is non-zero (increments 0 to 1). | 6 callers / 0 callees |
| `0x600f8c6a` |  202 | L2CAP / Signaling | **`l2cu_send_peer_cmd_reject`** — Broadcom L2CAP format & send Command Reject signaling packet (opcode 1): encodes reject reason (not understood, MTU exceeded, invalid CID), optional CIDs/MTU, and transmits via `0x600b9408`. | 3 callers / 2 callees |
| `0x600f8d34` |  180 | L2CAP / Signaling | **`l2cu_send_peer_connect_req`** — Broadcom L2CAP format & send Connection Request signaling packet (opcode 2): advances transaction ID (`0x600f8c34`), encodes PSM and Source CID (4 bytes), and sends via `0x600b9408`. | 3 callers / 3 callees |
| `0x600f8de8` |  232 | L2CAP / Signaling | **`l2cu_send_peer_connect_rsp`** — Broadcom L2CAP format & send Connection Response signaling packet (opcode 3): encodes Dest CID, Source CID, Result, and Status (8 bytes), sets pending flag if needed, and sends via `0x600b9408`. | 3 callers / 2 callees |
| `0x600f8ed0` |  170 | L2CAP / Signaling | **`l2cu_send_peer_connect_rsp_neg`** — Broadcom L2CAP format & send negative Connection Response signaling packet (opcode 3): encodes Dest CID 0, remote Source CID, and error reason (8 bytes) via `0x600b9408`. | 1 caller / 2 callees |

**⚠️ QA session 139 note:** Backbone clean — all 9 addresses/sizes match the census exactly, summing to the claimed 1,168 bytes, fully contiguous `0x600f8aea`–`0x600f8f7a`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,474 functions / 513,108 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 71.80% exactly.

**Zero corrections — the real L2CAP Command Reject reason-code table and Connection Request/Response formats both matched exactly, function by function.** `0x600f8c6a`'s three-way reason-code branch (`1`→2 extra bytes, `2`→4 extra bytes, else→0 extra bytes) matches the real L2CAP spec's Command Reject table precisely: Reason `0x0000` (Command not understood, no data), `0x0001` (Signaling MTU exceeded, 2-byte Actual MTU), `0x0002` (Invalid CID, 4-byte Local+Remote CID pair) — and its opcode literal (`1`) matches the real Command Reject opcode exactly. `0x600f8d34`'s Connection Request payload (PSM + Source CID, 4 bytes total, opcode `2`) and `0x600f8de8`/`0x600f8ed0`'s Connection Response payload (Dest CID + Source CID + Result + Status, 8 bytes total, opcode `3`) both match the real spec's exact field layouts and sizes — and the positive/negative response pair is well-differentiated (the negative variant correctly zeroes Dest CID and Status while filling Source CID and the error reason). `0x600f8bd4`'s idle-timer duration (`0x78`=120 seconds) matches its own claim exactly. `0x600f8c34`'s "ensure non-zero signaling ID" behavior matches the real L2CAP spec requirement that identifier `0x00` is reserved and illegal. `0x600f8ba8`/session 138's `L2CA_GetBleConnRole` are confirmed structural siblings (same `*(p_lcb+10)` field, same `0xff` default, differing only in the BR/EDR-vs-BLE mode argument to the shared lookup function), and this wave's own `0x600f8c0a` (`+0x16` = tx-active flag) directly confirms the field `0x600f8aea` reads for its "checks... tx queue" gate.

**Reliability read**: an outstanding wave for spec corroboration — the Command Reject reason-code/extra-data-length table is a rich, multi-branch match (three distinct reason codes, three distinct data lengths, all correct simultaneously), and the Connection Request/Response payload-size matches are similarly exact, making this one of the most thoroughly spec-verified waves in the L2CAP cluster.

## Session 140 (Wave 110) — Broadcom L2CAP Configuration Request & Response Signaling Packet Formatters (2 functions, 2,444 bytes)

Decompiled and documented 2 functions (2,444 bytes across `0x600f8f7a`–`0x600f9906`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f8f7a` | 1,256 | L2CAP / Signaling | **`l2cu_send_peer_config_req`** — Broadcom L2CAP format & send Configuration Request signaling packet (opcode 4): calculates option lengths, advances transaction ID (`0x600f8c34`), serializes TLV options (MTU, Flush Timeout, QoS, FCR, FCS, Extended Flow Spec), and transmits via `0x600b9408`. | 3 callers / 3 callees |
| `0x600f9462` | 1,188 | L2CAP / Signaling | **`l2cu_send_peer_config_rsp`** — Broadcom L2CAP format & send Configuration Response signaling packet (opcode 5): encodes Source CID, Flags, Result code, and serializes response TLV options (MTU, Flush Timeout, QoS, FCR with local timer overrides, Extended Flow Spec) via `0x600b9408`. | 2 callers / 2 callees |

**⚠️ QA session 140 note:** Backbone clean — both addresses/sizes match the census exactly, summing to the claimed 2,444 bytes, fully contiguous `0x600f8f7a`–`0x600f9906`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,476 functions / 515,552 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 72.15% exactly.

**Zero corrections — an exceptionally precise match to the complete real L2CAP Configuration Request/Response wire formats, likely among the strongest confirmations in this whole pipeline.** `0x600f8f7a` correctly builds all six real L2CAP configuration option types with their exact TLV lengths, traced directly against the byte-accumulator logic: MTU (type `1`, 2-byte data → 4-byte TLV), Flush Timeout (type `2`, 2 bytes → 4), QoS (type `3`, 22 bytes → `0x18`=24), FCR (type `4`, 9 bytes → `0xb`=11), FCS (type `5`, 1 byte → 3), and Extended Flow Spec (type `6`, 16 bytes → `0x12`=18) — six independently-checkable option-type/length pairs, every one exact, and the opcode literal (`4`) matches the real Configuration Request opcode precisely. `0x600f9462` matches the real Configuration Response's fixed 6-byte header (Source CID + Flags + Result, each 2 bytes, summing to the code's own `local_a+6` length calculation) exactly, its opcode literal (`5`) matches the real Configuration Response opcode, and it reuses the same five option types (correctly omitting FCS, matching real-world response behavior). Its FCR option's "local timer override" claim is independently confirmed: the two timer fields written come from the LCB's own `+0x36`/`+0x38` offsets — the exact RetransTimer/MonitorTimer fields session 138's `0x600f85a8` already established — rather than from the peer's requested values, a genuine, spec-consistent negotiation detail (the response echoes the local side's own timers) that also cross-validates session 138's field offsets from a completely independent angle. `0x600f8f7a`'s transaction-ID advance correctly reuses session 139's own confirmed `l2cu_adj_sig_id`.

**Reliability read**: a flagship-tier wave — two large, intricate wire-format-serialization functions, both matched byte-for-byte against the real Bluetooth L2CAP Configuration Request/Response specification across all six option types, with an added cross-session field-offset confirmation baked in. This is the kind of dense, multi-point exact-match evidence that leaves essentially no room for a wrong identification.

## Session 141 (Wave 111) — Broadcom L2CAP Disconnect/Echo/Info Signaling, Channel Link Lists & Idle Management (9 functions, 1,810 bytes)

Decompiled and documented 9 functions (1,810 bytes across `0x600f9906`–`0x600fa018`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600f9906` |  232 | L2CAP / Signaling | **`l2cu_send_peer_disc_req`** — Broadcom L2CAP format & send Disconnection Request signaling packet (opcode 6): advances transaction ID (`0x600f8c34`), flushes pending basic tx queue, and sends 4-byte PDU (Dest CID, Source CID) via `0x600b9408`. | 5 callers / 5 callees |
| `0x600f99ee` |  130 | L2CAP / Signaling | **`l2cu_send_peer_disc_rsp`** — Broadcom L2CAP format & send Disconnection Response signaling packet (opcode 7): formats 4-byte PDU (Dest CID, Source CID) and sends via `0x600b9408`. | 3 callers / 2 callees |
| `0x600f9a70` |  118 | L2CAP / Signaling | **`l2cu_send_peer_echo_req`** — Broadcom L2CAP format & send Echo Request signaling packet (opcode 8): advances transaction ID, copies optional data payload, and sends via `0x600b9408`. | 1 caller / 3 callees |
| `0x600f9ae6` |  118 | L2CAP / Signaling | **`l2cu_send_peer_info_req`** — Broadcom L2CAP format & send Information Request signaling packet (opcode 10): advances transaction ID, sets pending flag `+0xa3 = 1`, encodes 2-byte InfoType, and sends via `0x600b9408`. | 2 callers / 3 callees |
| `0x600f9b5c` |  242 | L2CAP / Core | **`l2cu_link_ccb`** — Broadcom L2CAP channel queue manager: inserts CCB into priority-ordered LCB channel doubly-linked list (`+0x5c`) sorted by `tx_priority` byte (`+0xa4`). | 1 caller / 0 callees |
| `0x600f9c4e` |  200 | L2CAP / Core | **`l2cu_unlink_ccb`** — Broadcom L2CAP channel queue manager: unlinks CCB from LCB channel doubly-linked list (`+0x5c`), updating head/tail/interior pointers. | 1 caller / 0 callees |
| `0x600f9d16` |  158 | L2CAP / Link | **`l2c_link_check_idle_by_handle`** — Broadcom L2CAP physical link idle disconnect controller: checks LCB by handle (`0x600bcbe0`), issues HCI Disconnect (`0x600b218c` reason 0x13), sets state 5 (DISCONNECTING), and arms 30s timer. | 4 callers / 3 callees |
| `0x600f9db4` |   60 | L2CAP / Core | **`l2cu_disconnect_and_free_ccb`** — Broadcom L2CAP channel teardown handler: for dynamic CIDs (`> 0x3f`), sends Disconnect Request PDU (`0x600f9906`), releases CCB (`0x600bc00c`), and invokes upper-layer disconnect callback. | 8 callers / 2 callees |
| `0x600f9df0` |  552 | L2CAP / Core | **`l2cu_process_peer_cfg_req`** — Broadcom L2CAP process incoming peer Configuration Request options: validates MTU (min 48, clamp 584), Flush TO, QoS, and FCR options (`0x600f87b8`), returning 1 (SUCCESS), 0 (UNACCEPTABLE), or 2 (REJECT). | 2 callers / 2 callees |

**⚠️ QA session 141 note:** Backbone clean — all 9 addresses/sizes match the census exactly, summing to the claimed 1,810 bytes, fully contiguous `0x600f9906`–`0x600fa018`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,485 functions / 517,362 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 72.40% exactly.

**Zero corrections — a fifth consecutive clean/near-clean wave, continuing the L2CAP signaling cluster's exceptional real-spec corroboration streak.** `0x600f9906`/`0x600f99ee` correctly build the real L2CAP Disconnection Request/Response PDUs (opcodes `6`/`7`, both 4-byte Dest-CID+Source-CID payloads, matching the real spec exactly). `0x600f9a70`/`0x600f9ae6` correctly build Echo Request (opcode `8`, variable-length optional payload) and Information Request (opcode `10`=`0xa`, 2-byte InfoType) — all four opcodes and payload shapes match the real spec precisely. `0x600f9ae6`'s pending-flag write (`+0xa3 = 1`) is independently confirmed against session 139's own `0x600f8aea`, which reads that exact field as its own gate condition before allowing a link-idle timeout — a sensible real behavior (don't time out a link while an info exchange is outstanding) cross-validated from the reader's side. `0x600f9d16`'s HCI Disconnect call composes the already-established `btsnd_hcic_disconnect` (`0x600b218c`, confirmed session 116) with reason code `0x13` — the real HCI "Remote User Terminated Connection" reason value. `0x600f9db4`'s dynamic-CID boundary check (`> 0x3f`) matches the real L2CAP spec's reserved/dynamic CID split (fixed CIDs `0x0000`–`0x003F`, dynamic starting at `0x0040`) exactly, and it correctly reuses this wave's own confirmed `l2cu_send_peer_disc_req`. `0x600f9df0`'s MTU bounds (min `48`, clamp `584`) match exactly, with the `584` constant being a direct reuse of session 137's own independently-established value, and its FCR-option delegation correctly reuses session 138's own confirmed `l2cu_check_fcr_config_req` (`0x600f87b8`), with the three-way return-code semantics (`1`=success, `0`=unacceptable, `2`=reject) matching precisely.

**Reliability read**: this wave sits at the tail of an unusually strong five-session run (137–141) for the L2CAP signaling cluster — every wave in that stretch has been zero-correction, with a dense, compounding web of exact real-spec matches and cross-session constant/function reuse that keeps checking out cleanly every time it's re-verified from a new angle.

## Session 142 (Wave 112) — Broadcom L2CAP Link & MPS Adjusters, BLE Idle Timers, and SDP Parsing/Serialization (16 functions, 1,422 bytes)

Decompiled and documented 16 functions (1,422 bytes across `0x600fa018`–`0x600fa5a6`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600fa018` |   76 | L2CAP / Core | **`l2c_csm_adj_config_rsp_options`** — Broadcom L2CAP config response option merger: merges QoS options into CCB and invokes FCR response options adjustment (`0x600f85f8`). | 1 caller / 1 callee |
| `0x600fa064` |  114 | L2CAP / Core | **`l2cu_adjust_out_mps`** — Broadcom L2CAP outbound MPS optimizer: queries controller ACL buffer size (`0x60099fdc`) and aligns MPS (`+0x118`) to packet payload boundaries. | 1 caller / 1 callee |
| `0x600fa0d6` |  262 | L2CAP / BLE | **`l2c_ble_link_check_idle_timer`** — Broadcom L2CAP check BLE link idle state across fixed channels (0..3): starts 30s timeout or initiates HCI disconnect (`0x600b218c` opcode 0x13) via `0x600aa340` / `0x600aa3cc`. | 4 callers / 5 callees |
| `0x600fa1dc` |  158 | L2CAP / Core | **`l2cu_get_next_ccb_to_tx`** — Broadcom L2CAP select next ready-to-transmit channel: traverses priority queue (`+0x5c`), checks congestion, suspension, and ERTM flow control (`0x600f82ea`). | 1 caller / 2 callees |
| `0x600fa27a` |   30 | SDP / Core | **`sdp_feature_is_supported_stub`** — Broadcom SDP / profile capability query stub: returns 1 (constant true). | 2 callers / 0 callees |
| `0x600fa298` |   26 | SDP / Core | **`sdp_feature_is_disabled_stub`** — Broadcom SDP / profile capability query stub: returns 0 (constant false). | 2 callers / 0 callees |
| `0x600fa2b2` |   26 | SDP / Core | **`sdp_attr_disabled_stub_1`** — Broadcom SDP attribute query stub: returns 0. | 1 caller / 0 callees |
| `0x600fa2cc` |   24 | SDP / Core | **`sdp_attr_disabled_stub_2`** — Broadcom SDP attribute query stub: returns 0. | 2 callers / 0 callees |
| `0x600fa2e4` |   28 | SDP / Core | **`sdp_attr_disabled_stub_3`** — Broadcom SDP attribute query stub: returns 0. | 2 callers / 0 callees |
| `0x600fa300` |   28 | SDP / Core | **`sdp_attr_disabled_stub_4`** — Broadcom SDP attribute query stub: returns 0. | 1 caller / 0 callees |
| `0x600fa31c` |   28 | SDP / Core | **`sdp_get_default_attr_len`** — Broadcom SDP default attribute length query: returns 8. | 1 caller / 0 callees |
| `0x600fa338` |   22 | SDP / Core | **`sdp_attr_disabled_stub_5`** — Broadcom SDP attribute query stub: returns 0. | 1 caller / 0 callees |
| `0x600fa34e` |  154 | SDP / Core | **`sdpu_find_uuid_in_seq`** — Broadcom SDP recursive UUID search in data element sequence: parses elements via `0x600bfb4c`, checks UUID match (`0x600bfc34`), recurses on sequences (type 6) up to depth 4. | 2 callers / 3 callees |
| `0x600fa3e8` |   88 | SDP / Core | **`sdpu_find_attr_in_rec`** — Broadcom SDP locate attribute in service record within ID range `[param_2, param_3]`. | 3 callers / 0 callees |
| `0x600fa440` |  296 | SDP / Core | **`sdpu_build_protocol_desc_list`** — Broadcom SDP serialize Protocol Descriptor List: builds Data Element Sequence (0x35), UUID16 (0x19), RFCOMM 1-byte channel (type 8), and L2CAP 2-byte PSM (type 9). | 1 caller / 0 callees |
| `0x600fa568` |   62 | SDP / Core | **`sdp_conn_close`** — Broadcom SDP close connection: finds SDP CCB (`0x600bf2d8`), disconnects L2CAP CID if requested (`0x600f7a68`), and releases SDP CCB (`0x600bf374`). | 0 callers / 3 callees |

**⚠️ QA session 142 note:** Backbone clean — all 16 addresses/sizes match the census exactly, summing to the claimed 1,422 bytes, fully contiguous `0x600fa018`–`0x600fa5a6`, zero gaps/overlaps. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,501 functions / 518,784 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 72.60% exactly.

**Zero corrections — the SDP subsystem's first appearance in this cluster is matched to the real SDP Data Element Sequence binary encoding formula with unusual precision.** `0x600fa440`'s DES header bytes (`0x35`, `0x19`, `8`, `9`) all match the real SDP `type<<3 | size_descriptor` encoding formula exactly across four distinct element types: `0x35` = Sequence(6)/next-byte-length(5), `0x19` = UUID(3)/2-byte(1), `8` = UnsignedInt(1)/1-byte(0) for the claimed RFCOMM channel field, `9` = UnsignedInt(1)/2-byte(1) for the claimed L2CAP PSM field — a first-principles-verifiable match, not merely a plausible label, since the formula itself is independently checkable against the real Bluetooth SDP spec. `0x600fa34e`'s recursive search correctly distinguishes DES type `3` (UUID, terminal match check) from type `6` (Sequence, recurse) — the same real type values — with its depth-4 recursion limit matching exactly. `0x600fa018` reuses the exact QoS field offsets (`+0x60`/`100`/`0x68`/`0x6c`/`0x70`/`0x74`) established across sessions 137/141 and correctly delegates to session 138's own confirmed `l2c_fcr_adj_our_rsp_options`. `0x600fa1dc` reuses session 141's confirmed priority-ordered channel list (`+0x5c`) and session 137's confirmed ERTM-congestion checker (`0x600f82ea`) and ERTM mode value (`+0x7e == 3`). `0x600fa568` correctly reuses session 137's own confirmed `L2CA_DisconnectRsp` (`0x600f7a68`). The seven trivial constant-return SDP stub functions (`0x600fa27a`/`0x600fa298`/`0x600fa2b2`/`0x600fa2cc`/`0x600fa2e4`/`0x600fa300`/`0x600fa338`) are all correctly, hedgedly labeled as generic stubs matching their literal return values exactly.

**One low-confidence, unflagged nuance**: `0x600fa0d6`'s claim that it "initiates HCI disconnect... via `0x600b218c`" is only partly precise — the function's primary disconnect call is a different address (`FUN_600a7268`), with `0x600b218c` (the already-confirmed `btsnd_hcic_disconnect`) appearing only as a secondary check inside one branch, both using the same reason code `0x13`. Not struck through, since `0x600b218c` genuinely does appear in the function doing genuinely disconnect-related work — but the citation slightly overstates its role as the primary mechanism.

**Reliability read**: a sixth consecutive strong wave (137–142) for this signaling/SDP corner of the codebase, and the SDP DES encoding-formula match is a particularly rigorous confirmation — the kind that would be very hard to produce by coincidence across four independently-checkable header bytes.

## Session 143 (Wave 113) — Broadcom SDP Request Dispatcher, Attribute Range Evaluators & BTM Security Policy Handlers (11 functions, 1,516 bytes)

Decompiled and documented 11 functions (1,516 bytes across `0x600fa5a6`–`0x600fab92`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600fa5a6` |   32 | SDP / Core | **`sdp_disconnect_req`** — Broadcom SDP disconnect L2CAP CID (`0x600f7a34`) and release SDP control block (`0x600bf374`). | 0 callers / 2 callees |
| `0x600fa5c6` |  246 | SDP / Core | **`sdpu_process_incoming_pdu`** — Broadcom SDP server PDU dispatcher: parses header, arms 30s timer, dispatches PDU 2 (Search), PDU 4 (Attr), PDU 6 (SearchAttr), or sends SDP error response (`0x600bf5a4`). | 1 caller / 5 callees |
| `0x600fa6bc` |   36 | SDP / Core | **`sdpu_clear_cont_state`** — Broadcom SDP reset continuation offset (`+0x2c = 0`) and zero continuation token buffer (`+0x30`). | 3 callers / 1 callee |
| `0x600fa6e0` |   92 | SDP / Core | **`sdpu_get_active_record_resp_size`** — Broadcom SDP calculate total response byte length for all matching service records (`0x600bd4bc` / `0x600fa73c`). | 1 caller / 2 callees |
| `0x600fa73c` |  162 | SDP / Core | **`sdpu_get_attrib_seq_len`** — Broadcom SDP calculate serialized byte length of requested attributes in service record matching ID ranges. | 3 callers / 2 callees |
| `0x600fa7de` |  248 | BTM / Security | **`btm_sec_clr_service_bits`** — Broadcom BTM clear service security requirement bits: updates local (`+0x1b4`) and remote (`+0x1b5`) security bitmasks based on role and direction. | 7 callers / 0 callees |
| `0x600fa8d6` |  492 | BTM / Security | **`btm_sec_check_security_callback`** — Broadcom BTM security callback evaluator: executes security callback with state (`+0x2a`), updates flags, evaluates BLE encryption, and triggers BTM events (`0x600c1a34`). | 0 callers / 2 callees |
| `0x600faac2` |   74 | BTM / Security | **`btm_sec_set_pin_type`** — Broadcom BTM PIN code handler: configures PIN length (~~1..15~~ ⚠️ the code's own bound is `< 0xf`(15), strictly less than, so the valid range is `1..14`, not `1..15` — a minor off-by-one in the stated range; the underlying mechanism is otherwise correctly described. *(corrected, QA session 143)*) and triggers event 5 via `0x600c1b74`. | 0 callers / 1 callee |
| `0x600fab0c` |   28 | BTM / Security | ⚠️ **QA session 143 confirms a genuine spurious boundary split with disassembly proof**: direct disassembly of the real prologue (`push {r7,lr}`) through the real epilogue (`pop {r7,pc}` at `0x600fab3c`) shows one continuous, unbroken instruction stream — `0x600fab28` (the claimed second "function") is `ldr r0,[r7,#0xc]`, a mid-stream continuation with no prologue of its own, reached only by a conditional branch (`beq`) from earlier in this same function, not by any `bl` call. The real function is exactly **50 bytes, `0x600fab0c`–`0x600fab3e`** (matching `28+22=50`), calling `FUN_6009ff18` to resolve a device record, conditionally calling `FUN_600f2080` if found, then unconditionally calling `FUN_600c1b74(1, param_1)` — a clean 2-argument call (this wave's own `0x600fab28` row already described this tail correctly; `0x600fab0c`'s own claimed body, by contrast, showed `extraout_r2`/`extraout_r3` register-tracking artifacts, the same red flag class, now explained by the same boundary bug). **`0x600fab3e` is confirmed a genuine, separate function** (its own real `push {r7,lr}` prologue immediately follows the pop), matching this wave's own `btm_sec_auth_complete` row. **GHIDRA-TODO: merge `0x600fab0c`/`0x600fab28` into one 50-byte function.** ~~**`btm_sec_bond_cancel_entry`** — Broadcom BTM bond cancellation helper (head): cancels bond timer/device entry via `0x6009ff18` and notifies security dispatcher.~~ *(corrected, QA session 143)* | 0 callers / 2 callees |
| `0x600fab28` |   22 | BTM / Security | ~~**`btm_sec_bond_cancel_exit`** — Broadcom BTM bond cancellation helper (exit branch): calls `0x600f2080` and `0x600c1b74(1, dev_rec)`.~~ ⚠️ Not an independent function — see `0x600fab0c` above, its true single owner (50 bytes total, disassembly-confirmed). The underlying operation description is accurate as a description of the merged function's tail, just not of an independent fragment. *(corrected, QA session 143)* | 1 caller / 2 callees |
| `0x600fab3e` |   84 | BTM / Security | **`btm_sec_auth_complete`** — Broadcom BTM authorization completion dispatcher: masks security requirement bits against capabilities and triggers security callback event 2 (`0x600c1b74`). | 2 callers / 2 callees |

**⚠️ QA session 143 note:** Backbone: all 11 addresses/sizes matched the census exactly and were fully contiguous. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,512 functions / 520,300 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed 72.81% exactly (the boundary split below doesn't change the byte total: `28+22=50`).

**Confirmed spurious boundary split, disassembly-proven.** `0x600fab0c` (claimed "bond cancel entry (head)") and `0x600fab28` (claimed "bond cancel exit branch") — the "(head)"/"(exit branch)" naming already hinted at a relationship, but neither row explicitly flagged a split. Direct disassembly confirms it precisely: one continuous instruction stream from `0x600fab0c`'s real prologue through the single real epilogue at `0x600fab3c`, with `0x600fab28` being a mid-stream instruction reached only by a conditional branch, no prologue of its own. Real function: `0x600fab0c`–`0x600fab3e` (50 bytes), and this also resolves `0x600fab0c`'s own `extraout_r2`/`extraout_r3` register-tracking artifacts (the same underlying boundary bug) — the real tail call is a clean `FUN_600c1b74(1, param_1)`, matching what the `0x600fab28` row had already (correctly) described. `0x600fab3e` confirmed a genuine, separate function immediately after. Corrected in place; `GHIDRA-TODO: merge 0x600fab0c/0x600fab28 into one 50-byte function.`

**One minor correction**: `0x600faac2`'s claimed PIN-length range "1..15" doesn't match its own bound (`< 0xf`=15, strictly less than), so the real valid range is `1..14`. Minor off-by-one, not a functional misidentification; corrected in place.

**Strong corroboration elsewhere.** `0x600fa5c6` correctly identifies three real SDP PDU type values (`2`=Service Search Request, `4`=Service Attribute Request, `6`=Service Search Attribute Request) with correct real names, plus a matching real SDP error code (`3`=`SDP_INVALID_REQUEST_SYNTAX`) for the unrecognized-PDU fallback. `0x600fa5a6` reuses session 137's own confirmed `L2CA_DisconnectReq`. `0x600fa6e0`/`0x600fa73c` correctly compose each other and session 142's own confirmed `sdpu_find_attr_in_rec`. `0x600faac2`'s event code (`5`) and `0x600fab3e`'s event code (`2`) both cite `0x600c1b74` consistently as a security-callback event dispatcher across two independently-decompiled functions.

**Reliability read**: a moderate wave — one genuine structural finding (caught via the now-familiar `extraout_rN`/mid-stream-continuation signature) and one trivial off-by-one, set against several solid real-SDP-spec matches and cross-session function reuse.

## Session 144 (Wave 114) — Broadcom BTM Security Event Dispatchers, Key Notification (LTK/IRK/CSRK) & Auth Result Handlers (13 functions, 818 bytes)

Decompiled and documented 13 functions (818 bytes across `0x600fab92`–`0x600faec4`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600fab92` |   26 | BTM / Security | **`btm_sec_disp_evt_3`** — Broadcom BTM security event 3 dispatcher: passes security event 3 to `0x600c1b74`. | 0 callers / 1 callee |
| `0x600fabac` |   26 | BTM / Security | **`btm_sec_disp_evt_4`** — Broadcom BTM security event 4 dispatcher: passes security event 4 (auth/link key request) to `0x600c1b74`. | 2 callers / 1 callee |
| `0x600fabc6` |   26 | BTM / Security | **`btm_sec_disp_evt_12`** — Broadcom BTM security event 12 dispatcher: passes security event 12 (key missing / passkey) to `0x600c1b74`. | 1 caller / 1 callee |
| `0x600fabe0` |   26 | BTM / Security | **`btm_sec_disp_evt_15`** — Broadcom BTM security event 15 dispatcher: passes security event 15 (numeric comparison) to `0x600c1b74`. | 1 caller / 1 callee |
| `0x600fabfa` |   26 | BTM / Security | **`btm_sec_disp_evt_13`** — Broadcom BTM security event 13 dispatcher: passes security event 13 (user confirmation) to `0x600c1b74`. | 0 callers / 1 callee |
| `0x600fac14` |   36 | BTM / Security | **`btm_sec_disp_evt_14`** — Broadcom BTM security event 14 dispatcher: stores remote I/O capabilities (`+0x197`) and passes event 14 to `0x600c1b74`. | 0 callers / 1 callee |
| `0x600fac38` |  140 | BTM / Security | **`btm_sec_link_key_notification`** — Broadcom BTM link key notification & persistent key storage handler: clears auth mask (`0x600fa7de`), fires events 6/7, copies 16-byte link key, saves key via `0x6009ad00`, and advances security state (`0x600fb848`). | 0 callers / 5 callees |
| `0x600facc4` |   98 | BTM / Security | **`btm_sec_process_irk`** — Broadcom BTM process BLE Identity Resolving Key (IRK): clears privacy mask (`0x600fa7de`), fires events 8/9, saves 32-byte identity structure via `0x6009ad00`, and advances security state (`0x600fb848`). | 0 callers / 4 callees |
| `0x600fad26` |  108 | BTM / Security | **`btm_sec_process_csrk`** — Broadcom BTM process BLE Connection Signature Resolving Key (CSRK): clears signature mask (`0x600fa7de`), fires event 10, saves ~~16-byte~~ ⚠️ the call's own literal size argument to `0x6009ad00` is `0x40`(64), not 16 — the 16-byte value copied in via `thunk_EXT_FUN_0000b572` (matching the real 16-byte CSRK size) is only part of a larger 64-byte region being saved (likely CSRK plus additional fields/padding the decompiler doesn't fully surface as named locals); the save size claim is corrected to 64 bytes, though the CSRK *value* itself is still genuinely 16 bytes. *(corrected, QA session 144)* via `0x6009ad00`, and advances security state (`0x600fb848`). | 1 caller / 5 callees |
| `0x600fad92` |   36 | BTM / Security | **`btm_sec_update_link_info`** — Broadcom BTM update device link parameters in security database (`0x6009b0a8`). | 0 callers / 1 callee |
| `0x600fadb6` |  188 | BTM / Security | **`btm_sec_check_sec_req`** — Broadcom BTM evaluate security requirements & encryption policy: queries requirements via `0x600f0b06`, checks BLE encryption, sets auth mask 0x0f (`+0x1b4`/`+0x1b5`), sets state `+0x2a = 2`, or triggers events `0x17`/`0x18`. | 0 callers / 3 callees |
| `0x600fae72` |   50 | BTM / Security | **`btm_sec_auth_result_handler`** — Broadcom BTM process authentication response: on success sets state `+0x2a = 1`, on failure triggers event `0x17` via `0x600c1a34`. | 0 callers / 1 callee |
| `0x600faea4` |   32 | BTM / Security | **`btm_sec_set_pin_len`** — Broadcom BTM store PIN code length for device security record: writes `*(param_1 + 0x25) = *param_2`. | 0 callers / 0 callees |

**⚠️ QA session 144 note:** Backbone: all 13 addresses/sizes matched the census exactly and were fully contiguous. Independently re-derived `bruce-decompile-status.md`'s totals via a fresh header-parsed join (3,524 functions / 521,118 bytes, 0 mismatches, 0 duplicates, 0 non-census addresses) — matches the wave's claimed byte increment exactly.

**Housekeeping confirmed**: session 143's `GHIDRA-TODO` (merge `0x600fab0c`/`0x600fab28`) is resolved at the boundary level — the census now shows one genuine 50-byte entry at `0x600fab0c`, and `FUN_600fab28.c` has been removed. **But the decompiled content itself is still stale**: `FUN_600fab0c.c` still shows the same `extraout_r2`/`extraout_r2_00`/`extraout_r3` artifacts from before the merge, with a fabricated 5-argument `FUN_600c1b74(1,param_1,uVar2,uVar3,param_2)` call — session 143's own direct disassembly already established the true tail is a clean 2-argument `FUN_600c1b74(1, param_1)`. This is the same "boundary fix lands, pseudocode content doesn't automatically follow" pattern documented several times earlier in this pipeline (e.g., session 52's `raise`/`_raise_r` saga) — noted for whoever next touches this address; no action needed from this wave's own 13 functions.

**One confirmed numeric correction**: `0x600fad26`'s claimed "16-byte CSRK structure" save size doesn't match its own literal argument to `0x6009ad00`, which is `0x40`(64), not `0x10`(16) — the 16-byte value genuinely copied in beforehand (matching the real BLE CSRK size) is only part of a larger 64-byte region actually being saved. Corrected in place.

**Strong corroboration elsewhere**: `0x600fac38`'s 16-byte link-key copy/save size matches the real Bluetooth Link Key size exactly, and `0x600facc4`'s 32-byte identity-structure save is consistent with an internal aggregate (IRK + address info + padding). `0x600fadb6`'s auth-mask value (`0x0f`) and state value (`+0x2a = 2`) both match their own literal stores exactly, and its two cited event codes (`0x17`/`0x18`) are consistent with `0x600fae72`'s independently-decompiled use of the same `0x17` code for an authentication-failure path — two functions in the same wave agreeing on one event's meaning.

**Reliability read**: a light wave overall (many tiny, structurally-verifiable dispatcher stubs), with one genuine numeric-literal correction and a useful cross-session status update on an already-tracked boundary issue.

## Session 145 (Wave 115) — Broadcom SMP Pairing Request Parser & Key Exchange Handlers (Confirm, Random, Public Key, DHKey, LTK, IRK, CSRK) (12 functions, 1,658 bytes)

Decompiled and documented 12 functions (1,658 bytes across `0x600faec4`–`0x600fb53e`):

| Address | Bytes | Subsystem | Functional Role & Evidence | Call graph |
|---|---:|---|---|---|
| `0x600faec4` |  488 | BTM / SMP | **`btm_sec_process_pairing_req`** — Broadcom BTM / SMP parse Pairing Request PDU: unpacks IO Cap (`+0x18d`), OOB (`+0x18f`), AuthReq (`+0x191`), MaxKeySize (`+0x1b0`), InitKeyDist (`+0x1b2`), RespKeyDist (`+0x1b3`), validates parameters (`0x600c2304`), checks BLE encryption policy, negotiates key masks, and determines pairing method (`0x600fcbfa`). | 0 callers / 7 callees |
| `0x600fb0ac` |  100 | BTM / SMP | **`btm_sec_process_smp_confirm`** — Broadcom BTM / SMP store peer 16-byte Confirm value at `*(param_1 + 0x3d)` and set flag `*(param_1 + 0x28) |= 8`. | 0 callers / 2 callees |
| `0x600fb110` |   80 | BTM / SMP | **`btm_sec_process_smp_random`** — Broadcom BTM / SMP store peer 16-byte Random value at `*(param_1 + 0x4d)`. | 0 callers / 2 callees |
| `0x600fb160` |  134 | BTM / SMP | **`btm_sec_process_peer_public_key`** — Broadcom BTM / SMP Secure Connections store peer 64-byte ECC P-256 Public Key coordinates (X at `+0x14d`, Y at `+0x16d`), set flag `*(param_1 + 0x28) |= 0x40`, and continue SC pairing (`0x600fbae0`). | 0 callers / 3 callees |
| `0x600fb1e6` |  100 | BTM / SMP | **`btm_sec_process_dhkey_check`** — Broadcom BTM / SMP Secure Connections store peer 16-byte DHKey Check value at `*(param_1 + 0xbd)` and set flag `*(param_1 + 0x28) |= 0x80`. | 0 callers / 2 callees |
| `0x600fb24a` |  100 | BTM / SMP | **`btm_sec_process_commitment`** — Broadcom BTM / SMP Secure Connections store peer 16-byte Commitment value at `*(param_1 + 0xfd)` and set flag `*(param_1 + 0x28) |= 0x20`. | 0 callers / 2 callees |
| `0x600fb2ae` |   92 | BTM / SMP | **`btm_sec_process_enc_key_size`** — Broadcom BTM / SMP store negotiated encryption key size at `*(param_1 + 0x198)` and set state `+0x2a = 8`. | 0 callers / 2 callees |
| `0x600fb30a` |   60 | BTM / SMP | **`btm_sec_process_peer_ltk`** — Broadcom BTM / SMP store peer 16-byte Long Term Key (LTK) at `*(param_1 + 0x1c6)` and advance state machine (`0x600fb848`). | 0 callers / 1 callee |
| `0x600fb346` |  184 | BTM / SMP | **`btm_sec_process_master_id`** — Broadcom BTM / SMP store Master Identification (2-byte EDIV, 8-byte Rand), persist link key record via `0x6009ad00`, and advance state machine (`0x600fb848`). | 0 callers / 4 callees |
| `0x600fb3fe` |   60 | BTM / SMP | **`btm_sec_process_peer_irk`** — Broadcom BTM / SMP store peer 16-byte Identity Resolving Key (IRK) at `*(param_1 + 0x1b6)` and advance state machine (`0x600fb848`). | 0 callers / 1 callee |
| `0x600fb43a` |  150 | BTM / SMP | **`btm_sec_process_id_addr`** — Broadcom BTM / SMP store peer Identity Address & 6-byte BD_ADDR, persist identity record via `0x6009ad00`, and advance state machine (`0x600fb848`). | 0 callers / 4 callees |
| `0x600fb4d0` |  110 | BTM / SMP | **`btm_sec_process_peer_csrk`** — Broadcom BTM / SMP store peer 16-byte Connection Signature Resolving Key (CSRK), persist signing record via `0x6009ad00`, and advance state machine (`0x600fb848`). | 0 callers / 4 callees |













































































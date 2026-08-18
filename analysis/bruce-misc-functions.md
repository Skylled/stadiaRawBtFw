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




















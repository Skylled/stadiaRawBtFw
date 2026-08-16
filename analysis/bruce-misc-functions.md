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

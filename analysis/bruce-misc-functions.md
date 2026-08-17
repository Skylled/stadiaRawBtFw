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

## Session 22: `battery_service.cc` — the BLE GATT-side battery/charging-status characteristic (3/3 decompiled)

`battery_service.cc` was `bruce-decompile-status.md`'s §3a rank-3 cheap-win target (506 remaining bytes, 0/3). All 3 attributed functions are now decompiled (`analysis/decomp/battery_service__*.c`), confirming the plausibility note that doc's own commentary raised: this really is "a plausible BLE GATT-side counterpart to `battery_gauge_bq2742X.cc`'s I2C fuel-gauge driver" — except it turns out to drive the **BQ25601 charger chip** (the same one `thermal.cc`, session 20, already documents disabling on a thermal fault), not the BQ2742x fuel gauge.

| Function | Bytes | Role |
|---|---:|---|
| `battery_service__6007ffd0` | 226 | **The periodic tick / GATT-notify driver**, called from `FUN_6005acf4` — the same function `application_state.cc`'s session-19 write-up already flags as a "charger/battery-shaped query" feeding Application-state event `0xb`. Calls the poll function below, reads a charge-percentage-shaped field (`FUN_600deecc`) and a "significant change" flag (`FUN_600def50`), and on an actual VBUS-presence transition logs `"State(USB_CHARGING) changed from <bool> to <bool>"` before calling `FUN_6007ff34(param_1, &value)` — a GATT-characteristic-notify-shaped call (single-byte payload) pushing the new charging state out to connected clients. Calls the same notify function again with a distinct fixed code on the separate "significant change" flag. |
| `battery_service__6007fcec` | 180 | **VBUS/charger-presence poll**, rate-limited to once per 5 real-time seconds. Calls `FUN_600684bc` (still undecompiled, presumably a `battery_charger_bq25601.cc` status-read) to get a presence boolean; when a separate cached flag byte's low bit differs and a debounce check (`FUN_600cc8f8`) passes, updates the cached copy (`FUN_600cc984`) and logs the transition with the numeric status code. |
| `battery_service__6007fdb0` | 100 | **"Long charge mode" toggle.** On an actual state change, logs `"Entering"`/`"Exiting"` `"... long charge mode"` and writes the corresponding command (`0x1004`/`0x10fe`) directly to the charger chip via **`battery_charger_bq25601__600683f4`** — confirming `battery_service.cc` and `thermal.cc` share the same underlying charger driver/chip, not two independent charging paths. |

**Net:** `battery_service.cc` is the **BLE GATT-side battery/charging-status characteristic** — periodically polls VBUS presence off the BQ25601 charger chip and, on a state change, notifies connected GATT clients of the new charging state, plus exposes a "long charge mode" (presumably a battery-longevity/reduced-current mode) toggle that writes directly to the charger chip. Confirms and closes the "plausible BLE GATT-side counterpart" open note `bruce-decompile-status.md`'s §3a table previously flagged for this file — and clarifies it's the charger chip (`battery_charger_bq25601.cc`, still undecompiled), not the fuel gauge (`battery_gauge_bq2742X.cc`, session 21), that it actually drives.

## Session 22: `mpu.cc` — the Cortex-M7 MPU + I/D-cache bring-up routine (1/1 decompiled)

`mpu.cc` was `bruce-decompile-status.md`'s §3a rank-10 cheap-win target (440 remaining bytes, its one attributed function). Now decompiled (`analysis/decomp/mpu__600cb030.c`). Genuinely new territory — the first piece of low-level ARM cache/MPU-management code mapped in this project, distinct from `bruce-itcm.md`'s ITCM-copy boot sequence (which runs even earlier and doesn't touch the MPU/cache at all).

`mpu__600cb030` (440B) — the **Cortex-M7 MPU (Memory Protection Unit) + I/D-cache reconfiguration routine**, called from `xbara__600cbdc8` (the same function `bruce-io-paths.md` documents as the button/pin-registration bring-up routine — i.e. this runs once during early board bring-up, alongside GPIO/XBAR setup). Confirmed by its own log strings, `"Failed to disable MPU region %d!"` / `"Failed to enable default MPU region %d!"`. Saves/restores interrupt-enable state around the whole sequence, then: disables the I-cache and D-cache (clearing enable bits on two SCB-shaped registers), performs a full **invalidate-by-set/way loop** over the cache (the classic Cortex-M7 nested set/way-invalidate idiom, writing to a cache-maintenance register), disables any previously-configured MPU regions one at a time (`FUN_600cafcc`, logging per-region failures), fetches a **board-specific MPU region table** from `gotham_16mb_mimxrt10xx_mpu__6006f660` (an attributed-but-undecompiled sibling file — confirming that file really is a per-board MPU region-table provider, as its name suggests) and programs each entry (`FUN_600cafec`, RBAR/RASR-shaped region-base/attribute register writes, logging per-region failures), re-enables the MPU, re-invalidates and re-enables both caches, and finally restores the saved interrupt-enable state.

**Net:** the firmware's one-time MPU + cache bring-up — disable caches, tear down any stale MPU config, invalidate cache, load and program the board's real MPU region table (the "16 MB" in `gotham_16mb_mimxrt10xx_mpu.cc`'s name almost certainly refers to the 16 MB QSPI flash's memory-map region, consistent with CLAUDE.md's hardware baseline), then re-enable everything. `gotham_16mb_mimxrt10xx_mpu.cc` (1 function, 132 bytes, still undecompiled) is the natural, very cheap next hop to see the actual region table (flash/RAM/peripheral memory-map split) this function programs.

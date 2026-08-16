# Bruce — HID I/O and rumble paths (session 2 decompilation)

Decompiled C for every function cited here is in `analysis/decomp/`. Ghidra project regenerable per `bruce-ghidra.md`.

## Confirmed

### HID input report transmit — `hid_input_target.cc` @ 0x60058aa8
Sends a HID input report. For a report of length ≥ 4: copies the report words into a global double-buffer (`DAT_60058b5c`), calls the transport send (`thunk_EXT_FUN_00007a2c(handle, 6, …)`), and on success writes **0x10000000 to a memory-mapped register `DAT_60058b60` followed by DSB/ISB** — i.e. rings a hardware "report ready" doorbell to kick the USB/DMA transmit. Small (<4 byte) reports take a separate formatting path.

### Rumble / haptics output path
- **`haptics_cluster.cc` @ 0x6006581c** — init/enable of the **two-motor cluster** (left + right). Zeroes both channel states (offsets 8/9 and 0x10/0x11), registers a timer callback (`obj+0x68`), and enables both actuators (`FUN_600d6c76` ×2) with "failed to enable left/right haptic" logging. Driven by a timer (`timer__60074658`).
- **`haptics.cc` @ 0x600656a0** — per-motor enable/disable/stop ("failed to enable/stop … haptic", `RumbleStop`).
- **`haptics.cc` @ 0x600655dc** — the strength scaler. Maps requested intensity (float 0..1) to a motor drive level with a floor, then **reads battery voltage over I2C** (`thunk_EXT_FUN_00001ea4(handle, reg=4, wbuf, 1, rbuf, 2, timeout=200)`) and **compensates the drive for battery level** (`drive = ref * level / Vbat`), clamped to a max. This is the "Failed to get battery voltage, can't scale haptics" code. Net effect: rumble feel stays consistent as the battery drains.

So the output path is: host HID output report (report ID 5, two u16 magnitudes) → timer-scheduled → `haptics_cluster` drives L/R motors → `haptics` scales each by battery-compensated intensity over I2C.

### Application state machine (from the state table initializer `FUN_600674d0` @ 0x600674d0)
The controller's internal states, revealed by the table's name strings: `RumbleNoLedChange`, `FactoryReset`, `Charging`, `ConnectedDim`, `PendingUserInput`, `CancelAutolink`, `CastError`, `DiscoveryFailed` (each entry = handler + name + params). Useful for mapping LED/behavior states later.

### USB *host* gamepad drivers
`switch_pro_controller.cc` @ 0x60070ad0+ is the USB-host driver that parses an *attached* Switch Pro controller (owns the "Ignoring report id: %u" / "Ignoring input report" strings). DualShock 3 and Steam Controller host drivers likewise present. (These are host-side, not the Stadia's own device reports.)

### ITCM-resident HAL primitives — resolved (session 5)
Pervasive calls like `thunk_EXT_FUN_00007a2c`, `thunk_EXT_FUN_00001ea4`, `thunk_EXT_FUN_0000737c`, `thunk_EXT_FUN_0000b572` target low addresses (0x0000xxxx) — hot HAL/RTOS routines copied into ITCM at boot. **The boot copy and mapping are now found: see `analysis/bruce-itcm.md`** (`flash_addr = itcm_addr + 0x6004081c`, use `MapItcmAddr.java` + `Decompile.java`). Confirmed so far: `00001ea4` = I2C transfer `(handle, reg, wbuf, wlen, rbuf, rlen, timeout)`; `00007a2c` = a bus/queue transaction `(handle, cmd, arg, out, timeout)` over two `queue.c` primitives; `0000737c` = FreeRTOS PendSV-trigger (context-switch request); `0000b572`/`0000b5ba` = memcpy/memset. Also resolved directly for this doc: **`thunk_EXT_FUN_00001c18`** (ITCM `0x1c18` → flash `0x60042434`) = peripheral-ID→ADC-base-address lookup, `FUN_60042434(0)=0x400C4000` (ADC1), `FUN_60042434(1)=0x400C8000` (ADC2) — confirms the ADC bring-up chain below down to the HAL level.

## Corrections to earlier assumptions
- **`keys.cc` is a typed config key-value store, NOT gamepad buttons.** `keys__60066070` = `Get(key_id, out, size)` with a switch on value-type. The physical button/stick sampling path is elsewhere and still unmapped.

## HID report format (decoded from firmware, session 3)
Report descriptor is embedded at flash **0x60103BA0** (decoder: `analysis/ghidra_scripts/decode_hid_descriptor.py`). USB and BLE descriptors are byte-identical. This is the authoritative gamepad I/O format and matches the live device (11-byte input report).

**Input report ID 3 (controller→host), 11 bytes total:**
| Byte | Field |
|---|---|
| 0 | Report ID = 3 |
| 1 | bits[0:4] D-pad hat (0–7, 8=null; 315°/8); bits[4:8] pad |
| 2–3 | 15 buttons (1 bit each, Button-page usages in order `0x12,0x11,0x14,0x13,0x0d,0x0c,0x0b,0x0f,0x0e,0x08,0x07,0x05,0x04,0x02,0x01`) + 1 pad bit |
| 4 | Left stick X (1–255) |
| 5 | Left stick Y |
| 6 | Right stick Z (X) |
| 7 | Right stick Rz (Y) |
| 8 | L2 analog (Simulation "Brake", 0–255) |
| 9 | R2 analog (Simulation "Accelerator", 0–255) |
| 10 | bit0 Vol+ (Consumer 0xE9), bit1 Vol− (0xEA), bit2 Play/Pause (0xCD), bits[3:8] pad |

**Output report ID 5 (host→controller):** PID page, 2× uint16 (max 65535) = the two rumble magnitudes. Feeds the haptics path above.

*DS4-spoof relevance:* this is the exact source layout a DS4 emulator would re-pack into DS4's report (analog sticks are 8-bit here vs DS4's 8-bit too; triggers 8-bit; no motion/touchpad, as expected).

## Input subsystem construction — `timer__60073bf0` @ 0x60073bf0 (2,492 bytes)
The constructor for the main input/HID task object. It: builds the USB device descriptor (embeds `"Google LLC"`, `"Stadia Controller rev. A"`); calls `FUN_600723b4(param_1+0x284, 0)` early on to build the board's GPIO/ADC pin table (see "Board/ADC/GPIO bring-up chain" below — this is the real hardware-facing part); registers 6 bit-packed fields via repeated `FUN_600717a0(...)` with function-pointer-looking values in the **0x600d… region** (`PTR_LAB_600d5636`, `600d51f4`, `600d4560`, `600d8f9e`, `600d99ee`, …) as their config; and starts a **"Haptic pulse"** timer (1000 units, `timers__600cad24`). **Session 5 correction:** the `FUN_600717a0` fields are *not* HID-report field descriptors and the 0x600d pointers are *not* GPIO/ADC sampler callbacks — see the correction section below. The real board/pin/ADC-channel setup is `FUN_600723b4`, called earlier in this same constructor.

## Input calibration — `input_calibration.cc` (~0x60058e78–0x6005990c, mostly unbounded)
Handles joystick & trigger calibration: `calibration_in/out`, `deadzone_in/out`, per-axis config keys `c_left_joystick_x/y`, `c_right_joystick_x/y`, `c_left_trigger`, `c_right_trigger` (stored in the `keys.cc` config KV store), parsed from a calibration protobuf. Logs "No joystick/trigger calibration found". So raw ADC stick/trigger values are calibrated + deadzoned before going into report ID 3.

## `FUN_600717a0` / iVar7 / iVar12 correction (session 5) — this is calibration storage, not sampling
Followed up the session-4 lead (`iVar7`=`obj+0x36e4`, `iVar12`=`obj+0x3684`, shared across all 6 `FUN_600717a0(...)` calls in `timer__60073bf0`). Decompiled `FUN_600717a0` @ 0x600717a0: it builds a 10-word record `{vtable, iVar7, bit_begin, bit_count, flags, iVar12, range[4]}`. The shared vtable is `DAT_600717d0` → **0x60108a58**, and its member functions (`FUN_600d808e`, `mimxrt10xx_flash_memory__60067f5c`/`60068024`, `FUN_600d80f4`, `FUN_600d8018`, `FUN_600d8014`) are all attributed to **`mimxrt10xx_flash_memory.cc`** — block read/write/erase with a per-block XOR/AES encrypt path (`*(param+0x24)==1` branch). Confirmed by tracing the two context objects back to their real constructors in `main()`/`xbara__600cbdc8` (see below): `iVar7` (`obj+0x36e4`) is built by `FUN_6005f9a8`, logged at boot as **`"flash"`**; `iVar12` (`obj+0x3684`) is built by `FUN_6005f3e0`, logged as **`"encrypt_engine"`** (DCP-backed, matches the `dcp_encryption_engine.cc`-attributed functions elsewhere in the map). So this whole subtree is the **calibration-blob schema stored in encrypted flash** (6 bit-packed fields, widths 4/34/8/4/4/4 bits — plausibly the 6 calibration values `c_left_joystick_x/y`, `c_right_joystick_x/y`, `c_left_trigger`, `c_right_trigger` from `input_calibration.cc` above), not a HID-report field list. The `0x600d8xxx`/`0x600d9bxxx` glue functions chased in session 4 (`FUN_600d8052`, `FUN_600d9bc6`, `FUN_600d9b8e`, …) are all thin dispatchers into this same flash vtable. Dead end for sampling — closes that lead for good.

## Board/ADC/GPIO bring-up chain (session 5, confirmed, init-time only)
- **`main__60051168`** @ 0x60051168 — top-level init entry (candidate answer to the long-standing "main event loop" search, though it's straight-line bring-up code, not a loop). Calls **`xbara__600cbdc8`** @ 0x600cbdc8 (src: `board.cc`/`xbara.h`), which is the one-shot hardware bring-up: TRNG init, MPU init, board-revision detection (`board__60071a30`, reads 3 GPIO pins via `FUN_600ce24c`, packs into a 2-bit ID, must equal 3), then a long sequence of named peripheral inits gated through `board__60071580(ok, name_ptr)` (success/fail logger) — `qos`, `usart1`, `i2c1`, `i2c2`, `dma_mux`, `sai1`, `line_out_dma`, `mic_in_dma`, **`adc1`** (`FUN_600d4724` @ `obj+0xae0`), **`adc2`** (`obj+0xcdc`), `flash` (`obj+0x36e4` — see above), `encrypt_engine` (`obj+0x3684` — see above), `partition table`, etc.
- **ADC peripheral init** — `FUN_600d4724` (called twice, once per ADC instance) resolves a peripheral-ID byte to a base address via `thunk_EXT_FUN_00001c18` (ITCM `0x1c18` → flash `0x60042434`, a 2-entry lookup: `0`→`0x400C4000`, `1`→`0x400C8000`) and calls `FUN_600522b8`, which writes ADC configuration registers at **base+0x44/+0x48**. Confirmed base addresses in the raw image: **ADC1 = 0x400C4000**, **ADC2 = 0x400C8000** (i.MX RT106x SAR ADC, matches the reference manual). This is one-shot config (averaging/clock select bits from an 11-byte flag struct), not a per-sample read.
- **Per-channel ADC/pin table** — `timer__60073bf0` itself calls **`FUN_600723b4`** @ 0x600723b4 (as `FUN_600723b4(param_1+0x284, 0)`, *before* the calibration-store section) — a 6 KB function that configures dozens of GPIO pins (I2C/audio/charger/jack-detect, via `FUN_60071478`/`FUN_600714ec`/`FUN_60071538`/`FUN_600722b0`/`FUN_60071660`/`FUN_60071718`) and registers **8 ADC channels** via `adc__60071f74(dest, flag_byte, channel_num, group)` @ 0x60071f74 (src: `adc.h`): channel numbers **0xc, 7, 6, 8, 9, 10, 0xb, 0xf**. Six of these are the natural candidates for LX/LY/RX/RY/L2/R2; the other two are likely battery-voltage or thermal sense (battery voltage is otherwise read over I2C per the haptics section above, so this may be a secondary/backup path, or thermal). `adc__60071f74` does a binary search of a channel table at `DAT_6007206c` and forwards the matched entry's 7 fields into `FUN_60071478` (generic pin/channel descriptor constructor) — this is still **pin/channel setup**, not a runtime read.
- **GPIO primitives** — `FUN_600ce24c` @ 0x600ce24c is the generic "read one GPIO bit" primitive: `**(uint**)(pin+0x20) >> (*(pin+0x18)&0xff) & 1` (dereferences a DR-register pointer stored at pin-object+0x20, shifts by the bit index at +0x18). All of its call sites found so far are boot-time (board-rev straps, sensor-presence checks in `main`/`xbara__600cbdc8`/`board__60071a30`) — no periodic caller located yet. `io_pin__6005fe04` (src: `io_pin.cc`) is the pin **configuration** function (sets GPIO direction + IOMUXC pad-mux bits from sorted lookup tables) and, when the pin object has `param_1[8] != 0`, also **registers a GPIO interrupt** (`FUN_600532f0`) — suggesting buttons may be edge-interrupt-driven rather than polled, which would explain why no periodic "sample all buttons" task has turned up.
- **Confirmed i.MX RT106x MMIO bases present in the image**: GPIO1–5 = 0x401B8000 / 0x401BC000 / 0x401C0000 / 0x401C4000 / 0x400C0000; ADC1/ADC2 = 0x400C4000 / 0x400C8000; XBARA1 = 0x403BC000; IOMUXC pad registers 0x401F80CC / 0x401F82BC — all referenced from two parallel 5-entry "GPIO bank" tables at **0x60108a70–0x60108a80** and **0x60109210–0x60109220**.

## GPIO button-IRQ dispatch chain (session 8, confirmed) — the ISR/registration half of the button-read-path thread, now closed

Followed up the two session-7 leads (`FUN_60071624`'s board-bring-up call, and the never-decompiled ISR `FUN_600532f0`) via the NVIC vector table rather than call-graph guessing. Method: the vector table lives at the image's very start (`0x60040000`+); for Cortex-M, vector index `16+N` (file/address offset `(16+N)*4`) holds IRQ N's handler pointer. Read directly off the raw image (no Ghidra needed for this survey) for every i.MX RT106x IRQ number that could plausibly touch ADC or GPIO, per the reference manual:

| IRQ(s) | Name(s) | Vector target |
|---|---|---|
| 67, 68 | ADC1, ADC2 | `0x60040630` (default/unused) |
| 72–79 | GPIO1_INT0–INT7 (individual-pin IRQs) | `0x60040630` (default/unused) |
| 117–120 | ADC_ETC_IRQ0–2, ADC_ETC_ERROR | `0x60040630` (default/unused) |
| 80 | GPIO1_Combined_0_15 | `0x600d499c` |
| 81 | GPIO1_Combined_16_31 | `0x60040630` (default/unused) |
| 82 | GPIO2_Combined_0_15 | `0x600d49a6` |
| 83 | GPIO2_Combined_16_31 | `0x6005fde0` |
| 84 | GPIO3_Combined_0_15 | `0x600d49b0` |
| 85 | GPIO3_Combined_16_31 | `0x60040630` (default/unused) |
| 86 | GPIO4_Combined_0_15 | `0x600d49ba` |
| 87 | GPIO4_Combined_16_31 | `0x6005fdec` |
| 88 | GPIO5_Combined_0_15 | `0x600d49c4` |
| 89 | GPIO5_Combined_16_31 | `0x6005fdf8` |

`0x60040630` (`FUN_60040630`, called via 13 `thunk_FUN_60040630` veneers) is confirmed to be a bare `while(true){}` — the generic "spurious/unused IRQ" trap. **Firmware-wide negative result: ADC1/ADC2 and ADC_ETC interrupts are never used, and neither are the individual per-pin GPIO IRQs (72–79) — only the 8 "combined bank" GPIO IRQs are wired to real handlers.** This confirms buttons are interrupt-driven via the *combined* GPIO-bank vectors, and rules out an ADC-interrupt or per-pin-GPIO-interrupt path entirely — ADC sampling must be polled or DMA-driven with no completion IRQ.

### The 8 ISR trampolines → shared ITCM dispatcher
All 8 real handlers (`0x600d499c/49a6/49b0/49ba/49c4` for the lower-16 half of GPIO1–5, `0x6005fde0/fdec/fdf8` for the upper-16 half of GPIO2/4/5 — GPIO1/3's upper halves are unused) decompile to the same shape: mask/clear the target bank's **ISR register** (`bank_base+0x18`, confirmed i.MX RT GPIO Interrupt Status Register offset) to isolate the 16-bit half they own, then call through a function-pointer variable loaded from flash `0x6013d3ac`, passing `(context=0x200064c0, bank_index)` with bank_index 1–5 matching GPIO1–5 (each function hardcodes its own index — confirmed by reading all 8 bodies).

Ghidra flags **"Could not recover jumptable at 0x6013d3a8 / Too many branches"** on every one of these — the same corruption symptom `bruce-misc-functions.md` already flagged around `FUN_601054dc`/`FUN_60134420` in the neighboring `0x6013cxxx`–`0x6013dxxx` veneer cluster (this is in fact the *same* cluster). Raw-byte inspection resolved it cleanly: `0x6013d3a0`–`0x6013d3e0` is not a switch jump table at all, it's an ordinary run of `LDR PC,[PC,#0]` linker veneers (the same `thunk_EXT_FUN_0000xxxx`-style 8-byte stub used everywhere else: 4-byte `LDR PC,[PC,#0]` instruction + 4-byte inline literal target), and Ghidra's jump-table heuristic misfires on the repeated `5f f8 00 f0` opcode bytes. The veneer actually invoked (the one at `0x6013d3a8`, literal at `0x6013d3ac`) resolves to ITCM offset **`0x8a74`** (bytes `75 8a 00 00`, thumb bit set) → via `MapItcmAddr.java` (`flash = itcm + 0x6004081c`) → **flash `0x60049290`**, a function Ghidra had never defined before this session.

### The shared per-pin ISR dispatcher — `FUN_60049290` (flash `0x60049290`, ITCM `0x8a74`) — new function, confirmed
```c
void FUN_60049290(int param_1,int param_2,uint param_3)
{
  int iVar1, iVar2 = 0;
  uint uVar3 = 1;
  do {
    if (((uVar3 & param_3) != 0) &&
       (iVar1 = *(int *)(param_1 + param_2 * 0x80 + -0x7c + iVar2 * 4), iVar1 != 0)) {
      (**(code **)(iVar1 + 4))(*(undefined4 *)(iVar1 + 8));
    }
    iVar2 = iVar2 + 1;
    uVar3 = uVar3 << 1;
  } while (iVar2 != 0x20);
}
```
Given `(context table base, 1-indexed GPIO-bank number, 32-bit "which pins fired" bitmap)`, for every set bit it computes a flat slot `(bank-1)*0x80 + 4 + pin*4` into a table starting at `context`, and — if that slot holds a non-null pointer — calls `(*(slot+4))(*(slot+8))`, i.e. **invokes a per-pin registered callback function pointer with a per-pin registered argument.** This is the generic GPIO-edge → software-callback dispatch mechanism. (Caveat: the ISR trampolines' own decompilation only shows 2 visible args at the call site — the same jump-table-corruption artifact above also cost Ghidra the 3rd argument at the *call* site, even though `FUN_60049290`'s own body unambiguously takes and uses 3. The mechanism is not in doubt; the exact register that carries the fired-pin bitmap at each call site would need a manual jump-table/veneer fix in Ghidra to pin down byte-for-byte.)

### Pin-IRQ registration — `FUN_60060040` (flash `0x60060040`) — confirms the `FUN_60071624` lead from `bruce-misc-functions.md`
`bruce-misc-functions.md` flagged `FUN_60071624` (16 board-bring-up calls right after GPIO-IRQ pin config) as "plausibly NVIC interrupt-registration." **Confirmed.** `FUN_60060040`, called from `FUN_60071624` and from `FUN_6006efd4`, given a pin-descriptor object:
- Reads the pin's assigned shared IRQ number (u16 at pin+0x2c), validated by `FUN_600d49e4`: `return (*p - 0x50) < 10 || *p < 0x10;` — i.e. **IRQ 80–89 or IRQ <16** — 80–89 is *exactly* the 10 combined-GPIO-bank IRQ numbers surveyed above. Tight, direct confirmation this is GPIO-combined-IRQ-specific registration code.
- Sets the corresponding bit in the real **NVIC ISER register array at `0xE000E100`** (`*(u32*)(0xE000E100 + (irq>>5)*4) = 1<<(irq&0x1f)`, both address and shift/mask pattern are the textbook Cortex-M "enable IRQ N" idiom), with DSB/ISB barriers.
- If the pin object carries a stale previous registration (bookkeeping fields at +0x34/+0x38), clears that old slot's bit in the old GPIO bank's **IMR (Interrupt Mask Register, `bank_base+0x14`)**.
- Computes a flat slot index via **`platform__6005ff5c(port, pin)`**, whose body's return expression `param_2 + (param_1 + 0x7ffffff) * 0x20` is `(port-1)*32 + pin` under mod-2³² arithmetic (plus range-validated logging: port must be 1–5, pin <32), and stores the pin-object pointer into `context_table + 4 + slot*4` — exactly the table `FUN_60049290` reads back from.

`FUN_60071624(pin_obj, shared_ctx)` itself: unpacks 7 words of `pin_obj` and calls `FUN_60060040(DAT_6007165c, pin_obj[0..6], shared_ctx)`, then `FUN_600d9b7c(pin_obj)` (→ `io_pin__6005fe04` mux/IMR/ICR config + `FUN_6005f534`, a sibling NVIC-enable/IMR-set helper with the same shape as `FUN_60060040` but without the eviction logic).

### The callback table base is the board singleton itself, and it's `.bss`
`DAT_6007165c` (`FUN_60071624`'s table base), `DAT_6005fddc` (the ISR dispatcher's context arg), and `DAT_600cbdc4`/`uVar8` (the giant object base threaded through all of `xbara__600cbdc8`, `board.cc`'s hardware bring-up function that this doc's session-5 section already covers) are **all the same literal RAM constant: `0x200064c0`.** So the flat 160-slot IRQ-callback table (bytes `0x0`–`0x280` of this object) and the ~40 individually-named peripheral sub-objects `board__60071580` walks (`usart1` at `+0xd70`, `i2c1` at `+0xe48`, `adc1`/`adc2` at `+0xae0`/`+0xcdc`, `flash`/`encrypt_engine` at `+0x36e4`/`+0x3684` — the session-5 calibration-store finding — etc.) are all members of **one big board-singleton C++ object at fixed RAM address `0x200064c0`.**

Per `analysis/bruce-itcm.md`'s already-cross-validated `Reset_Handler` RAM layout (`.data`: flash `0x6013d5a8` → RAM `0x20002740`–`0x20003fd8`; `.bss` zero: RAM `0x20004020`–`0x2002a824`), **`0x200064c0` falls inside `.bss`**, not `.data`. So this board object is zero-initialized at boot — **none of its member values, including any pin's registered callback function-pointer/argument, exist anywhere in the static flash image as literal bytes.** They must be written by runtime constructor/init code that hasn't been located yet, executed sometime before `xbara__600cbdc8`/`main__60051168` runs.

### Confirmed IRQ-registered pin offsets
From `xbara__600cbdc8`'s tail (the `FUN_60071624` call sequence, cross-checked against the earlier `FUN_600d9b7c` calls on the same objects): **17 distinct sub-object offsets within the board singleton** get registered for edge-IRQ dispatch — `+0x284, +0x2c0, +0x2fc, +0x338, +0x374, +0x3b0, +0x3ec, +0x428, +0x4a0, +0x464, +0x4dc, +0x518, +0x554, +0x590, +0x5cc, +0x608, +0x644` (i.e. RAM `0x20006744`–`0x20006b04`). A handful of the `FUN_60071624` call sites in the decompilation go through what looks like a corrupted `piVar16[...]` stack-array indirection (likely a decompiler artifact from register/stack-slot reuse across this 1.1 KB function, not real pointer-array indirection) — the *set* of 17 offsets is reliable, the exact pin↔call-site pairing for that subset is not fully untangled.

Corroborating evidence these are real physical buttons/digital inputs, not incidental config pins: **5 of these same offsets (`+0x374, +0x3ec, +0x428, +0x4a0, +0x518`) are read directly as raw GPIO input bits via `FUN_600ce24c`** (the "read one GPIO bit" primitive from the session-5 section) earlier in the same function — reading current state once at boot, then arming edge-IRQ for future changes on the same pins. Exactly the pattern you'd expect for buttons.

### What's still open (this is now the precise, narrow next target)
1. **Who writes each pin sub-object's callback function-pointer/argument (offsets +4/+8) at runtime.** Since the board object is `.bss`, this can't be static data — it needs a constructor call located somewhere between `Reset_Handler`'s `.bss`-zero loop and `xbara__600cbdc8`. Candidates: a C++ global-constructor/init-array table (not yet located for this image), or a dedicated per-peripheral constructor function not yet attributed to a source file. **This is now the direct predecessor of the still-missing report-packing function** — find the callback, read what it touches, and the button→report link should follow quickly.
2. ADC conversion trigger/result read: still unlocated, but now narrowed by the negative IRQ result above — it's polling or DMA-driven, definitively not interrupt-driven.
3. **Report-packing function**: still unidentified — most efficiently reached by continuing from (1) now, rather than more heuristic function-size/pattern sweeps.

## Open / next targets (superseded in part by the session-8 section above — kept for history)
- ~~**ADC conversion trigger + result read**~~ — narrowed (session 8): confirmed *not* interrupt-driven (see above); still not located.
- ~~**Button read path**~~ — **the registration+dispatch mechanism is now fully mapped (session 8, see above).** What remains is the callback itself.
- **Report-packing function**: still unidentified — whatever combines calibrated stick/trigger values + button state into the final 11-byte report ID 3 buffer (`hid_input_target.cc` @ 0x60058aa8 only *transmits* an already-built report).
- ~~`FUN_6004cdb8` (15.6 KB, near image start)~~ — **decompiled (session 4): this is SHA-512/384 compression, not an event loop.** See `analysis/bruce-crypto.md` — bruce statically links BoringSSL SHA-512 + Ed25519 keygen/ASN.1. `main__60051168` (session 5, this doc) is straight-line init, not a loop either — the real per-frame dispatch loop is still unidentified.
- ~~Map ITCM blob~~ — **done, `analysis/bruce-itcm.md`** (session 5, parallel thread).

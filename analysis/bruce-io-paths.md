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
- Reads the pin's assigned shared IRQ number (u16 at pin+0x2c) and checks it via `FUN_600d49e4`: `return (*p - 0x50) < 10 || *p < 0x10;` — i.e. **IRQ 80–89 or IRQ <16** — 80–89 is *exactly* the 10 combined-GPIO-bank IRQ numbers surveyed above.
- **Correction (post-hoc audit, verified against raw flash bytes):** the block gated on this check is *not* an ISER "enable" for the combined-bank case — it's the opposite on both counts. (1) It only runs when `FUN_600d49e4` returns **false** (`iVar2==0`), i.e. for IRQs *outside* {<16, 80–89} — it is skipped entirely for the combined-bank IRQs this section is about. (2) The address it writes, `DAT_600600bc + ((irq>>5)+0x20)*4`, is not ISER: `DAT_600600bc` = `0xE000E100` (confirmed by reading the raw flash literal at that address — `0x200bc` in the image, bytes `00 e1 00 e0`), but the extra `+0x20` words (`0x80` bytes) is exactly the CMSIS `NVIC_Type` stride from `ISER[]` to `ICER[]`, so this is `NVIC_DisableIRQ(irq)` for the non-shared case, not an enable. The real, correctly-formed NVIC enable for these pins — `0xE000E100 + (irq>>5)*4`, no offset, confirmed via `DAT_6005f5c8` = `0xE000E100` in the raw image — plus IRQ-priority setup (AIRCR PRIGROUP read via `DAT_6005f5c4` = `0xE000ED00`, SHPR3 via `DAT_6005f5d0` = `0xE000ED14`) is in the sibling function `FUN_6005f534` (see the `FUN_60071624` paragraph below), which runs unconditionally for *every* registered pin, combined-bank or not. This doesn't change the overall chain/table-dispatch finding below, but `FUN_60060040` itself is registration bookkeeping (table-slot write + stale-slot cleanup), not the NVIC-enable step.
- If the pin object carries a stale previous registration (bookkeeping fields at +0x34/+0x38), clears that old slot's bit in the old GPIO bank's **IMR (Interrupt Mask Register, `bank_base+0x14`)** — `DAT_600600c0` confirmed (raw image) to be the same 5-entry GPIO1–5 base-address table (`0x401B8000/0x401BC000/0x401C0000/0x401C4000/0x400C0000`) used elsewhere in this doc.
- Computes a flat slot index via **`platform__6005ff5c(port, pin)`**, whose body's return expression `param_2 + (param_1 + 0x7ffffff) * 0x20` is `(port-1)*32 + pin` under mod-2³² arithmetic (plus range-validated logging: port must be 1–5, pin <32), and stores ~~the pin-object pointer~~ **(correction, session 9 below: it's the shared *context* argument, not the pin object — see "GPIO button-IRQ callback registration" section)** into `context_table + 4 + slot*4` — exactly the table `FUN_60049290` reads back from.

`FUN_60071624(pin_obj, shared_ctx)` itself: unpacks 7 words of `pin_obj` and calls `FUN_60060040(DAT_6007165c, pin_obj[0..6], shared_ctx)`, then `FUN_600d9b7c(pin_obj)` (→ `io_pin__6005fe04` mux/IMR/ICR config + `FUN_6005f534`, a sibling NVIC-enable/IMR-set helper with the same shape as `FUN_60060040` but without the eviction logic).

### The callback table base is the board singleton itself, and it's `.bss`
`DAT_6007165c` (`FUN_60071624`'s table base), `DAT_6005fddc` (the ISR dispatcher's context arg), and `DAT_600cbdc4`/`uVar8` (the giant object base threaded through all of `xbara__600cbdc8`, `board.cc`'s hardware bring-up function that this doc's session-5 section already covers) are **all the same literal RAM constant: `0x200064c0`.** So the flat 160-slot IRQ-callback table (bytes `0x0`–`0x280` of this object) and the ~40 individually-named peripheral sub-objects `board__60071580` walks (`usart1` at `+0xd70`, `i2c1` at `+0xe48`, `adc1`/`adc2` at `+0xae0`/`+0xcdc`, `flash`/`encrypt_engine` at `+0x36e4`/`+0x3684` — the session-5 calibration-store finding — etc.) are all members of **one big board-singleton C++ object at fixed RAM address `0x200064c0`.**

Per `analysis/bruce-itcm.md`'s already-cross-validated `Reset_Handler` RAM layout (`.data`: flash `0x6013d5a8` → RAM `0x20002740`–`0x20003fd8`; `.bss` zero: RAM `0x20004020`–`0x2002a824`), **`0x200064c0` falls inside `.bss`**, not `.data`. So this board object is zero-initialized at boot — **none of its member values, including any pin's registered callback function-pointer/argument, exist anywhere in the static flash image as literal bytes.** They must be written by runtime constructor/init code that hasn't been located yet, executed sometime before `xbara__600cbdc8`/`main__60051168` runs.

### Confirmed IRQ-registered pin offsets
From `xbara__600cbdc8`'s tail (the `FUN_60071624` call sequence, cross-checked against the earlier `FUN_600d9b7c` calls on the same objects): **17 distinct sub-object offsets within the board singleton** get registered for edge-IRQ dispatch — `+0x284, +0x2c0, +0x2fc, +0x338, +0x374, +0x3b0, +0x3ec, +0x428, +0x4a0, +0x464, +0x4dc, +0x518, +0x554, +0x590, +0x5cc, +0x608, +0x644` (i.e. RAM `0x20006744`–`0x20006b04`). A handful of the `FUN_60071624` call sites in the decompilation go through what looks like a corrupted `piVar16[...]` stack-array indirection (likely a decompiler artifact from register/stack-slot reuse across this 1.1 KB function, not real pointer-array indirection) — the *set* of 17 offsets is reliable, the exact pin↔call-site pairing for that subset is not fully untangled.

Corroborating evidence these are real physical buttons/digital inputs, not incidental config pins: **5 of these same offsets (`+0x374, +0x3ec, +0x428, +0x4a0, +0x518`) are read directly as raw GPIO input bits via `FUN_600ce24c`** (the "read one GPIO bit" primitive from the session-5 section) earlier in the same function — reading current state once at boot, then arming edge-IRQ for future changes on the same pins. Exactly the pattern you'd expect for buttons.

### What's still open as of session 8 (superseded by session 9 below, kept for history)
1. ~~Who writes each pin sub-object's callback function-pointer/argument (offsets +4/+8) at runtime.~~ — **found, session 9 below** (short answer: a generic no-op, by default).
2. ADC conversion trigger/result read: still unlocated, but now narrowed by the negative IRQ result above — it's polling or DMA-driven, definitively not interrupt-driven.
3. **Report-packing function**: still unidentified.

## GPIO button-IRQ callback registration (session 9, confirmed) — the constructor is found; it writes a no-op default

Followed the exact session-8 target: who writes the per-pin table entries' `+4`/`+8` (callback fn ptr / arg) that `FUN_60049290` invokes. Found it — **`timer__60073bf0`** (the input/HID-task object constructor already covered above, under "Input subsystem construction") — but the answer complicates the picture rather than closing it: the value written is a literal no-op stub, and every other explanation examined leads to the same still-open question about what (if anything) later overrides it.

### Correction to session 8: the table stores one *shared context* object, not a per-pin pointer

`FUN_60060040` (the function `FUN_60071624` calls to actually populate a table slot) has a **9-argument** calling convention that Ghidra's decompiler recovers wrong — it only names `param_1` (r0) and silently drops two of the five stack-passed arguments it doesn't see referenced, which made the session-8 read of this function (via its broken pseudo-C) plausible but incorrect. Manually disassembled the raw Thumb-2 at flash `0x60060040` (session constraints ruled out `-import`, so this and the rest of this section's ISA-level detail come from disassembling the already-extracted `bruce_pvt_a_prod_signed.bin` directly with Capstone, cross-checked against the existing Ghidra decompile):

```
0x60060040: sub sp,#0x10 ; push {r4,r5,r6,lr}      ; r5=r0(table_base), r6=[sp,#0x30]=9th incoming arg (ctx)
0x60060050: ldr r4,[r6]                             ; r4 = *ctx   (ctx's own "descriptor" field)
0x60060052: add.w r0,r4,#0x2c ; bl FUN_600d49e4      ; check IRQ# at descriptor+0x2c against {<16, 80-89}
0x6006005a: cbnz r0,#0x80                            ; skip the next block when the check is TRUE (matches)
0x6006005c..7c: (only when check is FALSE, i.e. IRQ outside {<16,80-89}) NVIC_DisableIRQ(irq) via ICER
                (DAT_600600bc=0xE000E100=NVIC base, +0x80-byte ICER stride — see the corrected
                "Pin-IRQ registration" writeup above; this is a disable for the *non*-combined-bank
                case, not an enable for the combined-bank one)
0x60060080..9c: if descriptor+0x34 != 0, clear a stale prior GPIO-bank IMR bit
0x6006009e: ldrd r0,r1,[sp,#0x28]                   ; r0=port=pin[5](=pin_obj+0x14), r1=pin_num=pin[6](=pin_obj+0x18)
0x600600a2: bl platform__6005ff5c                   ; slot = (port-1)*32 + pin_num
0x600600a6: add.w r0,r5,r0,lsl#2                    ; r0 = table_base + slot*4
0x600600aa: str r6,[r0,#4]                          ; table[slot+4] = r6 = ctx  <-- NOT the pin object
```

`FUN_60071624(pin_obj, ctx)` forwards `pin_obj[0..6]` plus `ctx` as that 9th argument; `xbara__600cbdc8`'s loop of 17 calls computes `iVar3 = uVar8 + 0x38b8` **once**, before the loop, and reuses that identical value as `ctx` for every one of the 17 `FUN_60071624(pin, iVar3)` calls. **Consequence: all 17 button-pin table slots end up holding the exact same pointer, `board_singleton + 0x38b8` (RAM `0x20009d78`).** `FUN_60049290`'s per-pin dispatch (session 8) therefore isn't actually per-pin in effect — the fired-pin bitmap only selects *whether* to invoke the callback, never *which* callback; every one of the 17 registered button pins, on any edge, calls the exact same `(*(0x20009d78+4))(*(0x20009d78+8))`.

### The context object's constructor — `timer__60073bf0` @ 0x60073bf0

Confirmed `timer__60073bf0`'s `param_1` **is** the board singleton (`0x200064c0`): it's called as `timer__60073bf0(0x200064c0)` from `FUN_600748ec` (literal `DAT_60074904 = 0x200064c0`, read directly from the image), and independently its `+0x284`/`+0x3684` sub-offset accesses match `xbara__600cbdc8`'s exactly. Near the top of the function (`analysis/decomp/timer__60073bf0.c` lines 58-69) it initializes **four** identical 12-byte `{descriptor_ptr, callback_fn, callback_arg}` triples:

| Object | RAM addr (`0x200064c0+off`) | `descriptor` field → | callback (`+4`) | arg (`+8`) |
|---|---|---|---|---|
| ctx_A | `+0x38b8` = `0x20009d78` | board+0x374 (one of the 17 button pins) | `0x600ce232` | `0` |
| ctx_B | `+0x38c4` = `0x20009d84` | board+0x6d8 | `0x600ce232` | `0` |
| ctx_C | `+0x38d0` = `0x20009d90` | board+0x714 | `0x600ce232` | `0` |
| ctx_D | `+0x38dc` = `0x20009d9c` | board+0x9c8 | `0x600ce232` | `0` |

`0x600ce232`, raw-disassembled (Ghidra had mis-bounded it as a bogus 2-byte "function" — not trusted as-is): the single instruction **`bx lr`**, i.e. a real, literal no-op. **At construction time, `ctx_A` — the object every button-GPIO edge interrupt dispatches through — has a callback that does nothing and returns immediately.**

This is not a one-off artifact: the literal `0x600ce233` (its Thumb-bit address, as stored in a function pointer) appears **35 times total** in the image (verified by direct byte-scan of `bruce_pvt_a_prod_signed.bin`) — 1 of those is `DAT_60073e08` itself, the single literal-pool slot `timer__60073bf0` loads once and reuses for all four `ctx_A`–`ctx_D` writes (confirmed: reading that address in the raw image gives exactly `0x600ce233`), leaving **34 other, independent occurrences** elsewhere in the image, matching the original count. It's the codebase's generic "unset event handler" default, reused by many unrelated constructors. Spot-checking the surrounding words at each of the 34 supports this: several sites sit directly in code (preceded/followed by Thumb instruction encodings — ordinary function-local literal pools), and one cluster, flash `0x6013e2e8`–`0x6013e9fc`, is a clean repeated table of a dozen `{RAM pointer, 0x600ce233, 0}` triples — the exact same 3-word shape as `ctx_A`–`ctx_D` above, just belonging to a different, not-yet-identified object. None of these other 34 sites have been decompiled to C yet (`analysis/decomp/*.c` has no reference to `FUN_600ce232`/`0x600ce232` outside its own file), so this corroboration is at the raw-byte level, not source level — consistent with a C++ idiom of "default this delegate to a no-op; a real subscriber overwrites it later," not proof the button path is inert by itself.

`xbara__600cbdc8` uses `ctx_A` (`+0x38b8`) as the shared registration context for all 17 button pins, and separately self-registers `ctx_C` (`+0x38d0`) via `FUN_6006efd4(uVar8+0x38d0)` — a related single-object variant of the same registration (`FUN_6006efd4(self)` dereferences `*self` for the pin descriptor and passes `self` as its own context, then calls the same `FUN_60060040`). `ctx_B`/`ctx_D` are untouched anywhere in `xbara__600cbdc8`'s decompiled body; `FUN_6006efd4` is also called from `usb_port_controller_tusb320__6006b3e8` (not yet decompiled), so one or both of `ctx_B`/`ctx_D` may belong to the USB-C port-controller's IRQ line rather than buttons. (Verification-pass addendum: `xbara__600cbdc8` also calls `FUN_6006efd4(iVar3)` — i.e. `FUN_6006efd4(ctx_A)` — right after the 17-call block, at `analysis/decomp/xbara__600cbdc8.c` line 237. Since `ctx_A`'s own descriptor field is `board+0x374`, which is already one of the 17 registered button-pin offsets, this self-registration computes the identical table slot and writes the identical value [`ctx_A`] that one of the 17 `FUN_60071624` calls already wrote — a redundant/idempotent double-write, not a conflicting one, so it doesn't change any conclusion above.)

### What's confirmed vs. still open

**Confirmed (byte-level, via raw disassembly + decompile):**
- `FUN_60060040`'s real 9-argument shape and its `table[slot] = ctx` store (corrects session 8's "stores the pin-object pointer" to "stores the shared context object").
- All 17 registered button pins share one context object, `board+0x38b8` (RAM `0x20009d78`).
- That object's callback/arg fields are initialized by `timer__60073bf0` to a literal no-op (`0x600ce232` = `bx lr`) and `0`.
- No currently-decompiled function (~500 of ~5,000 in the image) writes to `board+0x38b8..0x38e4` other than `timer__60073bf0`'s own initializer (checked by grepping all of `analysis/decomp/*.c` for those offsets) — i.e. no override has been found yet, but ~90% of the image is still undecompiled, so this isn't a negative proof.
- Direct-literal search for the absolute RAM addresses of all four contexts and their `+4`/`+8` fields across the entire flash image: **zero hits for `ctx_A`/`ctx_B`/`ctx_C` and all `+4`/`+8` fields; two hits for the bare `ctx_D` address (`0x20009d9c`)** (re-checked, session-9-verification pass: both sit outside any function's bounds per `bruce_functions.csv` — flash `0x6005c078`, immediately preceded by the literal `0x200064c0` [the board-singleton base itself, suggesting a `{base, end}` bounds pair rather than a callback-table write — `0x20009d9c` is also exactly `ctx_C + 0xc`, i.e. "one past the end of ctx_C", a plausible loop-bound value independent of ctx_D]; and flash `0x6005cbbc`, flanked by an unrelated code pointer and what looks like a string address, with no obvious structural meaning found). Neither looks like a `table[slot]=fn` style store on inspection, but this wasn't confirmed by decompiling whatever function actually contains these words, so it's not a fully closed question. Otherwise: if an override exists, it's built via register-relative arithmetic (`base_ptr + 0x38b8`, computed at runtime), not a compiled-in literal, so it's invisible to address-literal grep and needs either a targeted decompile sweep or the Ghidra GUI (typing the singleton as a real struct so its xref engine can trace field-level access) to find.

**Two live hypotheses, not yet decided between:**
1. **A real override exists**, most likely a small generic `SetCallback(obj, fn, arg)`-shaped setter (a 2-3 word store, easy to miss in a function-size-ranked sweep), called from whatever starts the input/HID task once it's ready to handle button events — i.e. a sibling of `timer__60073bf0` that actually *runs* the object it constructs, not yet located.
2. **No override exists, and the no-op is intentional** — the combined-bank GPIO interrupts exist purely to wake the CPU from a low-power `WFI` sleep state (nothing needs to happen in the ISR itself), and actual button-state sampling happens in a still-unlocated **periodic polling task** that runs whenever the CPU is awake. This would also explain why `FUN_600ce24c` ("read one GPIO bit") has no periodic caller found yet (session 5/8), and it unifies with the ADC path: ADC is already confirmed (session 8) to be polled/DMA rather than IRQ-driven, so one shared poll task reading both ADC channels and these same button GPIOs on a timer tick is a plausible single mechanism for both still-missing pieces.

**Next step, under either hypothesis:** find `timer__60073bf0`'s sibling that actually **starts/runs** the input/HID task (look for a FreeRTOS task-create call — `xTaskCreate`-shaped, per the `tasks.c` primitives in `bruce-itcm.md` — taking this same `0x200064c0`-rooted object as its parameter). `timer__60073bf0` itself is confirmed pure object construction (straight-line field stores, no loop, no task-create call in its own body). Either the override (hypothesis 1) or the polling loop (hypothesis 2) most likely lives in that task's body. **Report-packing function: still not located** — this is the most direct lead toward it, but it hasn't been reached yet.

## InputTask found: creation, Run() loop, sampling, and button bit-packing (session 10)

Followed the session-9 target — "find `timer__60073bf0`'s sibling that starts the input/HID task" — and it turned out to be a **wrong scent to follow literally**: `timer__60073bf0`/`FUN_600748ec` construct the **board singleton** (`0x200064c0`), a different C++ object from the one that actually owns button/ADC sampling. The real task lives in a completely separate object, found instead via the method's suggested shortcut (search for a task-name string): the string **`"InputTask"`** at flash `0x6011b13a` has exactly one xref, from **`main__60051240`** (`src: main.cc`), which is the real task-creation call site. This section documents the whole chain now traced from there: task creation → the task's `Run()` method → per-tick axis sampling → button bit-packing → the still-open final report-send hop.

### Task creation — confirmed FreeRTOS `xTaskCreateStatic`

`main__60051240` (flash `0x60051240`, newly decompiled this session), near its end:
```c
uVar6 = FUN_60076400();               // uVar6 = DAT_60076404 = 0x200108a8 (the InputTask object, RAM)
FUN_6010177a(uVar6, DAT_600515a0, 0xd); // DAT_600515a0 = "InputTask" string; priority = 0xd = 13
```
- `FUN_60076400` (4 bytes) is a trivial getter: `return DAT_60076404;` — `DAT_60076404` is a flash literal whose value is `0x200108a8`, a RAM address. **This is the InputTask singleton object pointer**, distinct from the board singleton `0x200064c0`.
- `FUN_6010177a` (32 bytes) wraps its call in a scheduler-suspend/yield bracket (`thunk_EXT_FUN_0000713c` .. `FUN_600cc178(...)` .. `thunk_EXT_FUN_0000728c`) — this same wrapper is called from ~10 other subsystems (`system_tasks__60058574`, `gatt_manager_task__60080cdc`, `usb_host_worker__6006525c`, `usb_audio_receive/send`, `synapse_audio_processor`, `receiver__6007f540`) — i.e. it's the codebase's **generic `CreateAndRegisterTask(obj, name, priority)` helper**.
- `FUN_600cc178` (66 bytes), given `(obj, name, priority)`: reads a **task-descriptor sub-object** at `obj+0x5c` (stack size in words at `+0xd0`, checked `>= 0x800` bytes; static stack buffer pointer at `+0xcc`), and calls:
  ```c
  tasks__600ca1f8(DAT_600cc1bc /*shared entry trampoline, see below*/, name, stackWords,
                   obj /*pvParameters*/, priority, stackBuffer, taskDescriptor /*=TCB buffer*/);
  ```
  storing the resulting handle at `obj+0x58`.
- **`tasks__600ca1f8`** (`src: tasks.c`, 124 bytes) is **confirmed `xTaskCreateStatic`** by shape: it `configASSERT`s two params for non-null (matching `puxStackBuffer != NULL` / `pxTaskBuffer != NULL`) at embedded line numbers **599 and 600**, takes the right parameter count/order (task-code fn ptr, name, stack-word-count, `pvParameters`, priority, stack-buffer ptr, TCB-buffer ptr), stores the stack pointer into the TCB, and on success calls `FUN_600ca0fc` (`prvInitialiseNewTask`-shaped: 5 params + handle-out + TCB, matches the real signature) then `FUN_600c9fd8` (`prvAddNewTaskToReadyList`-shaped: one arg, the TCB). **Correction (post-hoc audit):** the doc previously claimed 599/600 are "the exact line numbers of those two asserts in upstream FreeRTOS `tasks.c`" — checked against 14 tagged `FreeRTOS/FreeRTOS-Kernel` releases (V9.0.0 through V10.6.2, both the top-level and `FreeRTOS/Source/tasks.c` layouts), and **none of them puts these two asserts at exactly line 599/600** (closest: V9.0.0 at 597/598, V10.1.1 at 606/607; most cluster around 575–592). So the specific "exact upstream line match" claim doesn't hold up against any publicly available tagged release — this firmware likely vendors a slightly different (e.g. NXP MCUXpresso SDK-bundled) copy of `tasks.c` with a different line count, which wasn't checked. The identification of this function as `xTaskCreateStatic` itself is unaffected — it rests on the structural/parameter/call-sequence match above, which is solid independent of the line-number coincidence.
- **`DAT_600cc1bc` = `0x60101761`** (thumb) is the *same* task-entry function pointer passed for every caller of this generic helper — i.e. every "Task"-wrapped C++ object in this firmware (InputTask, GattManagerTask, UsbHostWorker, the audio-receive/send tasks, SynapseAudioProcessor, Receiver, SystemTasks) shares one FreeRTOS entry point:
  ```c
  // FUN_60101760 @ 0x60101760 — the generic task-entry trampoline
  void FUN_60101760(int *param_1)   // param_1 = pvParameters = the C++ "Task" object
  {
    (**(code **)(*param_1 + 8))();   // call object->vtable[2]() — the virtual Run() method
    FUN_60101832(param_1 + 1);       // post-Run cleanup/notify
    do { tasks__600ca5cc(0); } while (true); // defensive self-delete loop if Run() ever returns
  }
  ```
  This confirms the codebase's task model: a generic `Task` base class with a virtual `Run()` at vtable slot `+8` (3rd vtable entry after the Itanium ABI's implicit slots), and FreeRTOS just calls it once through this one shared trampoline.

### The InputTask object and its `Run()` method

`FUN_600769ec` (350 bytes) is the InputTask constructor's tail (three BLE/GATT-address-shaped sub-structures get zeroed/registered via `FUN_601017e8`, then): `*piVar4 = DAT_60076b6c;` where `piVar4 = DAT_60076b68 = 0x200108a8` — **this stores the object's vtable pointer**, confirmed by reading the vtable at its literal value **`0x6010a088`** directly out of the flash image:

| vtable slot | value | meaning |
|---|---|---|
| `+0x00` | `0x600763e9` | flash fn (input_task.cc address range) — likely dtor/GetName |
| `+0x04` | `0x600dac53` | flash fn |
| **`+0x08`** | `0x2acd` (**ITCM** address, thumb) → flash `0x600432e8` | **`FUN_600432e8` = `Run()`, confirmed below** |
| `+0x0c` | `0x24bd` (ITCM) → flash `0x60042cd8` | small helper, ends up calling `xEventGroupSetBits(evtgrp, 1)` — looks like a public `Notify()`/`RequestSample()` method |
| `+0x10` | `0xffffffa0` | not a pointer — Itanium-ABI secondary-vtable "offset-to-top" (-0x60), i.e. this is a **multiple-inheritance vtable group**, not one flat table |
| `+0x14` | `0x0` | RTTI ptr (null) |
| `+0x18` | `0x2521` (ITCM) → flash `0x60042d3c` | near-identical twin of the `+0x0c` helper — the secondary base's equivalent slot |
| `+0x24..+0x2c` | `0x6007694d`/`0x600dacf7`/`0x600dad0f` | further flash fns, not chased this session |

Slot `+0x08` resolving to an **ITCM address** (post-boot-copy RAM `0x2acc`, source flash `0x600432e8` per the established `flash = itcm + 0x6004081c` mapping) explains why no direct `BL` caller was ever found for it in earlier sessions — **it's purely virtual-dispatched**, never called by a literal branch anywhere in the image (confirmed: zero literal hits for its thumb address across the whole flash).

### `FUN_600432e8` — InputTask's `Run()` method, confirmed

```
src attribution: PTR_s_input_task_cc_600435dc = "input_task.cc" (embedded string, cited directly in the body)
```
Body, read in full (750 bytes):
1. Checks a calibration-load flag (`func_0x6004c224`); if it failed, logs **`"Failed to load calibration from K..."`** at `input_task.cc` line `0xdd` = 221.
2. Registers 3 `{obj, fn}` callback pairs via `func_0x6004c37c`/`6004c13c`/`6004c194` (not chased further this session).
3. **Starts the periodic HID-poll software timer**: `uVar7 = *(param_1 + 0x3a4); FUN_60048248(uVar7, 1, now_ms, 0, 10);` — `FUN_60048248` is `thunk_EXT_FUN_00007a2c`'s resolved flash target (already confirmed in `bruce-itcm.md` as a FreeRTOS timer/queue command-send front-end); **command code `1` = `tmrCOMMAND_START`** in upstream FreeRTOS `timers.c` — this starts the same timer whose *period* is set elsewhere (see `input_task__60076438` below) from the **`HidPollMs`** config key (default 16 ms if unset — `"FAILED to get poll period setting for "` log, already catalogued in this doc's string list).
4. **Main loop**: `xEventGroupWaitBits(evtgrp = *(param_1+0x78), bits=0xF, clearOnExit=true, waitForAll=false, ticksToWait=portMAX_DELAY)` via `FUN_6004703c` (already resolved in `bruce-itcm.md` as the `xEventGroupWaitBits`-shaped helper) — blocks until any of 4 event bits fires, then dispatches:
   - **bit 0 (`0x1`)**: sets a "config dirty" flag.
   - **bit 1 (`0x2`) — the periodic poll tick.** Calls `FUN_60043028` (see next section) to sample+calibrate the analog axes; if it reports a change, calls `FUN_60049522` (button-combo/long-press detector — compares old vs. new 17-byte snapshots of the sample state and dispatches numbered events like `3`/`0xf`/`4`/`5`/`9` to an app-state-machine handler object at `param_1+0x244`, matching strings elsewhere in the image such as `"Y button held; enter setup mode."`/`"WAKE_REASON: Button press"`); otherwise, if fully idle (all 4 stick/trigger-center fields `== 0x800` and all digital fields zero), toggles an idle/dim flag via `param_1+0x418`.
   - **bit 2 (`0x4`)**: re-checks/re-logs the calibration-load failure.
   - **bit 3 (`0x8`)**: calls **`func_0x6004c0cc(param_1, &flag)`** — this is a `LDR PC,[PC]` veneer (flash `0x6004c0cc`, ITCM `0xb8b0`, part of a small run of ITCM→flash call veneers at `0x6004c0b0`–`0x6004c0fc`) whose literal target is **`0x600dad26` = `FUN_600dad26`**, the InputTask command-queue handler (below).

This confirms hypothesis 2 from session 9 for the **analog axes**: they're sampled on a plain periodic timer tick, not via GPIO interrupt. (Whether digital buttons are populated the same way, via the same-region leaf calls not yet fully chased, or independently via the session-8/9 GPIO-IRQ path, is **still open** — see below.)

### `FUN_60043028` — calibrated axis sampling (confirmed)

Called from `Run()`'s bit-1 branch. Reads/updates 4 stick fields (`+0x224/+0x228/+0x22c/+0x230`, checked against `0x800` = center) and 2 trigger fields (`+0x234/+0x238`) — **exactly the 6 analog channels** already flagged as LX/LY/RX/RY/L2/R2 candidates in the session-5 ADC bring-up survey. Uses `FUN_600492ee`, a binary-search-plus-linear-interpolation routine over a lookup table (matches `input_calibration.cc`'s described calibration-curve role exactly). If the sample changed, calls `FUN_60042d44` (next section) and `FUN_60049522` (combo detector, above). (These 6 writes target `_DAT_60043234 + offset`, a separately-loaded global literal, not literally the `param_1` local — but `_DAT_60043234`'s value, read directly from the flash image, is `0x200108a8`, i.e. it *is* the same InputTask singleton address `param_1` always holds, so this is a distinction without a runtime difference.)

**Correction (post-hoc audit):** contrary to what this doc previously claimed in "Still open" below, `FUN_60043028` does **not** touch only the 6 analog fields — reading its full body (`analysis/decomp/FUN_60043028.c`), it also writes **two of the 19 button-bitfield booleans that `FUN_60042d44` packs**: `*(char *)(_DAT_60043234 + 0x21a) = (char)uVar17;` and `*(char *)(_DAT_60043234 + 0x21b) = (char)uVar16;`, right alongside the trigger writes. `uVar17`/`uVar16` come from a threshold check on the two trigger-calibration interpolation results (`iVar5`/`iVar6` from `FUN_600492ee`, compared against `0x401`) rather than a raw GPIO read, so their semantic identity (real "trigger digital-click" buttons vs. an internal calibration-validity flag) is still unconfirmed — but they are unambiguously part of the same `param_1+0x210..+0x222` boolean block `FUN_60042d44` bit-packs (specifically, they're 2 of byte A's 3 bits: `b(0x21d) | b(0x21a)<<1 | b(0x21b)<<2`). So the write site for 2/19 fields is already found; 17/19 remain open. See "Still open" #1 below, corrected accordingly.

### `FUN_60042d44` — digital button/D-pad bit-packing (confirmed, matches report layout bit-for-bit)

```c
// 3-byte packed value from 19 individual boolean fields at param_1+0x210..+0x222:
local_2c = CONCAT12(
    /* byte A, 3 bits */  b(0x21d) | b(0x21a)<<1 | b(0x21b)<<2,
    CONCAT11(
      /* byte B_hi */ b(0x221) | b(0x220)<<1 | b(0x21f)<<2 | b(0x21e)<<3 | b(0x222)<<4 | b(0x218)<<5 | b(0x219)<<6 | (param_1+0x21c)<<7,
      /* byte B_lo */ b(0x210) | b(0x211)<<1 | b(0x212)<<2 | b(0x213)<<3 | b(0x216)<<4 | b(0x217)<<5 | b(0x214)<<6 | (param_1+0x215)<<7));
*(DAT_60042e58 + ring_index*8)     = timestamp;   // param_2
*(DAT_60042e58 + ring_index*8 + 4) = local_2c;
ring_index = (ring_index + 1) & 0xf;              // 16-slot ring, IRQ-disable-guarded
```
**Byte A (3 bits) structurally matches the report's D-pad hat nibble** (needs exactly 3 raw bits to encode 0–7); **bytes B_hi/B_lo (16 bits) structurally match the report's 15-button-plus-pad bitfield** (bytes 2–3 of report ID 3). This is a strong, bit-count-exact match to the HID report layout documented earlier in this file — but note it writes into a **16-slot timestamped ring buffer** (`DAT_60042e58`/`DAT_60042e54`, IRQ-safe), not directly into a final wire-format buffer. No consumer of this ring buffer was located this session (see "Still open" below) — so this is confirmed as *part of* the report-assembly pipeline, not proven to be its final stage.

### `FUN_600dad26` — InputTask's command-queue handler (confirmed, corrects a session-9 gap)

Reached from `Run()`'s bit-3 branch (via the `0x6004c0cc` veneer above). A `while(xQueueGenericReceive(*(param_1+0xec), &cmd, 0) == 1)` loop (uses the already-confirmed `thunk_EXT_FUN_00006d2c` = `xQueueGenericReceive`), dispatching on a command byte:
- **`2`** ("(re)configure"): stops the current handler object at `param_1+0x240` (calls its vtable`+0xc`), installs a new handler pointer; if non-null, calls **`input_task__600764fc`** (re-reads the **`HidPollMs`** config key via `keys__60066070`/`key_value_store__600cb598`, falling back to `0x10`=16 on failure) → **`input_task__60076438`** (computes the derived timer-period value and calls `thunk_EXT_FUN_00007a2c(timer_handle=+0x3a4, cmd=4, period_ms, 0, 10)` — **command `4` = `tmrCOMMAND_CHANGE_PERIOD`**, confirming `+0x3a4` is indeed the poll timer and this is `xTimerChangePeriod`), then **Start()s the new handler** (`vtable+0xc`, arg = `param_1+0x60`).
- **`3`/`4`**: set/clear an enable flag at `param_1+0x248`.

This resolves the session-9 open question about who drives `input_task__600764fc`/`60076438` — it's this command handler, itself reached from the InputTask `Run()` loop, not from the GPIO-IRQ dispatch chain investigated in sessions 8/9.

### Still open

1. **Exact digital-button source.** **Corrected (post-hoc audit):** `FUN_60043028` (the per-tick sampler) is not analog-only after all — it also writes 2 of the 19 boolean fields consumed by `FUN_60042d44` (offsets `+0x21a`/`+0x21b`, derived from a threshold check on the trigger-calibration interpolation results, not an obvious raw GPIO read — see the correction in the `FUN_60043028` section above). The other 17 of 19 boolean fields (`+0x210..+0x219`, `+0x21c..+0x222` minus `0x21a`/`0x21b`) still weren't traced to their write site this session (candidates: another un-chased leaf call inside `FUN_60043028` alongside the ones already read, or the session-8/9 GPIO-IRQ path after all, writing into the *InputTask* object rather than the *board* object the earlier sessions were looking at — these are two different singletons, which may be why the override was never found by literal-searching board-relative offsets).
2. **The final report-assembly + send call.** `hid_input_target__60058aa8` (`src: hid_input_target.cc`, previously documented) is confirmed to take `(uint16_t *report_words, uint length)` and transmit via a queue-send + hardware doorbell. Its only two callers found are trivial 1-line pass-through stubs, **`FUN_600df4b6`** (flash `0x600df4b6`) and **`FUN_60058b7a`** (flash `0x60058b7a`) — both call it with what the decompiler shows as zero arguments (almost certainly a decompiler artifact losing pass-through register args, the same class of bug already seen elsewhere in this codebase, e.g. `FUN_60060040`'s dropped arguments in session 9). **Neither stub's own caller was found** — no literal reference to either stub's address exists anywhere in the flash image, and Ghidra's xref engine reports no references either, meaning they're reached via a mechanism invisible to both literal search and Ghidra's default analysis (likely a PC-relative `ADR`-computed pointer, or a vtable slot on an object not yet typed by Ghidra). **This is the most direct remaining lead on the report-packing function** — whoever calls one of these two stubs, with the assembled report buffer in r0, *is* (or immediately follows) the producer this project has been looking for since session 3. Best next steps: type the InputTask object as a real Ghidra struct so its xref engine can trace field-level access to the still-unidentified `+0x244` "app state machine handler" vtable (dispatched from `FUN_60049522`) and the `+0x240`/`+0x60` handler installed by `FUN_600dad26`'s command `2` path — one of those handler objects' vtables plausibly contains one of the two stubs.
3. Whether `FUN_60049522`'s `+0x244` handler dispatch ultimately reaches the report send indirectly (e.g. a state-machine transition that triggers a send) is unconfirmed — plausible given it's fed directly from the same per-tick sample-changed path, but not traced.

## Report-packing thread: transmit caller (GATT path) found + digital-button write-site fully closed (session 11)

Followed both session-10 leads. **Result: the digital-button write-site thread is fully closed, byte-for-byte.** The transmit-caller thread is substantially advanced — one complete, confirmed caller chain found for one of the two known `hid_input_target__60058aa8` callers — but not 100% closed (see "Still open" at the end).

### Correction to session 10: both "caller stub" addresses were mid-instruction artifacts, not real function entry points

Session 10 named the two callers of `hid_input_target__60058aa8` as `FUN_600df4b6` and `FUN_60058b7a`, noting neither had a findable caller. Manually disassembling around both addresses (Capstone, cross-checked against Ghidra) showed **both addresses are mid-body**, not real entry points — an instance of the same class of bug already seen with `FUN_600ce232` (session 9):

- **`0x600df4b6`** sits 6 bytes into the real function, which actually starts at **`0x600df4b0`**: `ldrd r0,r1,[r1]` (unpack a `{ptr,len}` struct pointed to by r1) → `push {r3,lr}` → `bl hid_input_target__60058aa8` → `pop {r3,pc}`. Immediately after it, `0x600df4c0` is a **second, separate entry point** — a bare `b.w 0x600df4b0` thunk — that Ghidra, once pointed at the correct address, auto-named `thunk_FUN_600df4b0`. Both decompile identically: `hid_input_target__60058aa8(*param_2, param_2[1], ...)`.
- **`0x60058b7a`** sits mid-body too; the real function starts at **`0x60058b68`**: checks a tag byte (`*param_1==5`), and if set calls `hid_input_target__60058aa8(param_1+1)` (skip the tag byte), else takes a separate small-report logging path. Ghidra confirms this as `FUN_60058b68`, 100 bytes, still with zero found callers even at the corrected boundary.

Re-ran exhaustive reference search (direct `BL`/`B.W`, raw 4-byte literal scan of the whole 1 MB image for both odd/even address forms, and a full-image `MOVW`/`MOVT` pair scan) against the *corrected* addresses. Result diverged sharply between the two:

### Part A — `thunk_FUN_600df4b0`'s real caller, traced byte-for-byte to `gatt_server.cc`

The literal scan hit: **flash `0x6008144c` contains the raw 4-byte value `0x600df4c1`** (the thumb-bit address of `thunk_FUN_600df4b0`). That address is the last of a run of 10 consecutive literal-pool words (`0x60081428`–`0x6008144c`) immediately following a small function at **`0x600813cc`–`0x60081428`** (92 bytes). Manually matched each of that function's 10 `LDR rX,[PC,#imm]` instructions to its Thumb PC-relative target and confirmed all 10 land exactly on those 10 words (no ambiguity). Ghidra decompile of `0x600813cc` (`FUN_600813cc`):

```c
undefined4 FUN_600813cc(char *param_1)
{
  if (*param_1 == '\0') {           // lazy-init guard, keyed by caller-supplied flag byte
    *param_1 = '\x01';
    iVar2 = DAT_6008142c;            // = 0x2000385c (RAM) — a fixed, shared object
    *(iVar2 + 0x178) = ...; *(iVar2 + 0x17c) = param_1; *(iVar2 + 0x19c) = PTR_LAB_600df4fc...;
    *(iVar2 + 0x1a0) = param_1; *(iVar2 + 0x140) = param_1; *(iVar2 + 0x138) = param_1;
    *(iVar2 + 0x118) = param_1; *(iVar2 + 0x48)  = PTR_LAB_600df4fc...; *(iVar2 + 0x4c)  = param_1;
    *(iVar2 + 0x68)  = PTR_LAB_600df4f4...;        *(iVar2 + 0x6c)  = param_1;
    *(iVar2 + 0xac)  = PTR_LAB_600df4f0...;        *(iVar2 + 0xb0)  = param_1;
    *(iVar2 + 0x13c) = PTR_LAB_600df53e...; *(iVar2 + 0x134) = PTR_LAB_600df4ec...;
    *(iVar2 + 0xf8)  = PTR_LAB_600df54c...; *(iVar2 + 0xfc)  = param_1;
    *(iVar2 + 0x114) = PTR_thunk_FUN_600df4b0_1_6008144c;   // <-- the report-send thunk
  }
  return 0;
}
```

This is a one-time "install a generic attribute-callback table onto a fixed object at RAM `0x2000385c`" routine, installing ~10 function-pointer fields (all targeting a cluster of small argument-shuffling thunks at `0x600df4ec`–`0x600df550` that further branch into `0x600816xx`–`0x6008193c`) plus several `param_1`-as-context fields. **Field `+0x114` is set to `thunk_FUN_600df4b0`** — the wrapper that unpacks a `{report_ptr, length}` struct and calls `hid_input_target__60058aa8`.

`FUN_600813cc`'s own (Ghidra-confirmed) caller is **`gatt_server__60081ab4`** (src: `gatt_server.cc`), which calls it as `FUN_600813cc(DAT_60081c68)` deep in its body, gated behind system-readiness checks (a charge/thermal-state flag, an I2C probe via `FUN_600d4330`, and `gatt_server__6005d9d0` calls) — i.e. this is live, reachable BLE GATT-server bring-up code, not dead code. `gatt_server__60081ab4` itself is called from `FUN_60081c6c`.

**Confirmed, byte-level:** `gatt_server__60081ab4` → `FUN_600813cc` → object `0x2000385c` field `+0x114` = `thunk_FUN_600df4b0` → `FUN_600df4b0` → `hid_input_target__60058aa8(report_ptr, length)`.

**Inferred, not proven:** that object `0x2000385c` is a per-characteristic GATT attribute descriptor and field `+0x114` is specifically its "read/notify value" callback (i.e. the BLE-side plumbing for the HID Input Report characteristic notify). This is well-motivated — the `{ptr,len}` calling convention through `FUN_600df4b0` matches a generic "get current value to send" callback shape, and the surrounding fields (`+0x48/+0x4c`, `+0x68/+0x6c`, `+0xac/+0xb0`, `+0x118`, `+0x134/+0x138/+0x13c/+0x140`, `+0x178/+0x17c/+0x19c/+0x1a0`) look like a standard multi-slot GATT characteristic op-table — but it was **not** cross-checked against a UUID or "Input Report"-named string this session, and the actual runtime trigger (what BLE event calls through `object+0x114`) was not found: a targeted search for `LDR rX,[rY,#0x114]` immediately followed by `BLX rX`/`BX rX` anywhere in the image returned zero hits (the load and the call are evidently not register-adjacent, or go through an intermediate `MOV`).

`FUN_60058b68` (the corrected second caller) remains **fully unreferenced** by every method tried (direct branch, literal scan both address parities, `MOVW`/`MOVT` construction) even after boundary correction. This is a confirmed negative, not a methodology artifact — it may be dead code, or reached via a mechanism not covered by these searches (e.g. a `TBB`/`TBH` relative jump table, which stores byte/halfword offsets rather than absolute addresses).

### Part B — the digital-button write site, fully closed

`FUN_600769ec` (InputTask's constructor tail, session 10) calls **`FUN_600765a4`** (908 bytes; not decompiled in session 10) as `FUN_600765a4(piVar4)` with the InputTask object itself. Decompiling it revealed the exact missing write site.

**Step 1 — 17 per-pin descriptors, one per session-8 button pin.** Starting at InputTask **`+0x24c`**, `FUN_600765a4` builds **17 consecutive 5-word (0x14-byte) descriptors**, one per call to a family of trivial 4-byte getter functions (`FUN_60084acc`, `FUN_60084ad4`, …, `FUN_60084b4c` — 17 of them, all `return DAT_xxxx;`). Reading each getter's literal constant directly out of the flash image and subtracting the board-singleton base (`0x200064c0`, per session 8) gives an **exact, complete bijection with all 17 board-object button-pin offsets session 8 found registered for GPIO edge-IRQ** (`+0x284, +0x2c0, +0x2fc, +0x338, +0x374, +0x3b0, +0x3ec, +0x428, +0x4a0, +0x464, +0x4dc, +0x518, +0x554, +0x590, +0x5cc, +0x608, +0x644` — all 17, no extras, no misses). Each descriptor is `{pin_object_ptr, debounced_state_byte, debounce_deadline, index_ptr, target_write_ptr}`, and `target_write_ptr` is set to one of InputTask's own boolean fields, covering **17 of the 19** offsets `FUN_60042d44` (session 10) reads — every one of `+0x210`–`+0x222` **except** `+0x21a`/`+0x21b`.

**Step 2 — the poll+debounce loop.** `FUN_60043028` (InputTask's confirmed per-tick analog sampler, session 10) opens by calling **`FUN_60042ee0`**, which walks exactly this descriptor array:
```c
for (iVar7 = param_1 + 0x24c; iVar7 != param_1 + 0x3a0; iVar7 = iVar7 + 0x14) {
    bVar2 = func_0x600494e6(param_1, param_2, iVar7);   // param_2 = current tick timestamp
    bVar5 |= bVar2;                    // "any pin changed"
    bVar6 |= **(byte **)(iVar7 + 0x10); // OR of all current debounced button states
}
```
`(param_1+0x3a0) - (param_1+0x24c) = 0x154 = 17 * 0x14` — exactly the 17 descriptors from Step 1.

**Step 3 — the per-pin read, debounce, and write, confirmed instruction-for-instruction.** `FUN_600494e6(param_1, tick, descriptor_ptr)`:
```c
if ((uint)param_3[2] <= param_2) {                 // debounce deadline elapsed
    uVar4 = ~(**(uint**)(*param_3 + 0x20) >> (*(uint*)(*param_3+0x18) & 0xff)) & 1;
    // ^ same GPIO-bit primitive as FUN_600ce24c (session 5), but inline and INVERTED (active-low)
    if (*(byte*)(param_3+1) != uVar4) {
        *(char*)(param_3+1) = (char)uVar4;          // update debounced state
        param_3[2] = param_2 + debounce_interval;   // re-arm debounce deadline
    }
}
bVar1 = *(byte*)(param_3+1);
bVar2 = *(byte*)param_3[4];                          // previous value at the target field
if (bVar1 == 0) bVar1 = *(byte*)param_3[3];          // idle-state override via the index slot
*(byte*)param_3[4] = bVar1;                          // <-- WRITE into InputTask+0x21x
return bVar2 ^ bVar1;                                 // changed?
```
`*param_3 + 0x20` / `*(param_3)+0x18` is the exact same `pin_base+0x20` (GPIO data-register pointer) / `pin_base+0x18` (bit index) pair `FUN_600ce24c` uses — confirming this reads the **same physical GPIO pins** session 8 mapped, just polled instead of interrupt-driven, and **inverted** (button pressed ⇒ GPIO reads 0 ⇒ inverted to 1).

**The remaining 2 fields (`+0x21a`, `+0x21b`)** are written directly inside `FUN_60043028` itself (not via this descriptor mechanism), from `uVar17`/`uVar16` — booleans set when the left/right analog trigger ADC readings exceed a fixed threshold (`0x401`) — i.e. these are almost certainly **digital "L2/R2 fully pressed" click bits derived from the analog trigger channels**, not physical buttons.

**This fully confirms session 9's Hypothesis 2, at the byte level (not just plausibility):** the GPIO combined-bank edge-IRQs (sessions 8–9) wire to a no-op (`0x600ce232` = `bx lr`) and are not the button-sampling mechanism; the real sampling is this periodic poll+debounce running once per `HidPollMs` tick (default 16 ms, per session 10) inside InputTask's `Run()` loop, reusing the exact same 17 physical GPIO pin objects the IRQ path registered. The IRQs most likely exist only to wake the CPU from sleep between poll ticks, as hypothesized.

### What this means for the central thread

Combined with session 10, the full confirmed pipeline is now:

**GPIO pins (board object, 17 of them) → periodic poll+debounce (`FUN_600494e6`/`FUN_60042ee0`, run from `FUN_60043028` each `HidPollMs` tick) → InputTask digital-button fields `+0x210..+0x222` (17 of 19; the other 2 come from analog-trigger thresholding in `FUN_60043028` directly) + calibrated analog axes `+0x224..+0x238` → `FUN_60042d44` bit-packs the digital fields into a 3-byte hat+15-button value (matches the report layout bit-for-bit) → [ring buffer / final-assembly step, see below] → `hid_input_target__60058aa8(report_words, length)` → hardware doorbell.**

Two gaps keep this from being a *fully* closed, single unbroken chain:
1. `FUN_60042d44` still writes to its 16-slot timestamped ring buffer, not directly to a wire-format buffer — no consumer of that ring buffer was found this session either.
2. The confirmed GATT caller chain (Part A) proves *a* real, reachable path from BLE-server bring-up down to the transmit call, and its calling convention (`{ptr,len}`) is consistent with being fed the assembled report — but the exact function that builds that `{ptr,len}` pair from the ring buffer + analog fields, and the runtime BLE event that triggers `object(0x2000385c)+0x114`, were not located.

**Given both explicit halves of this session's task:** the digital-button write-site is **fully closed** (byte-level, both the descriptors' pin identities and the read/debounce/write logic are confirmed). The transmit-caller side is **substantially advanced but not fully closed** — one of the two known callers of `hid_input_target__60058aa8` now has a complete, confirmed, non-dead caller chain (GATT server bring-up), the first time any caller of that transmit function has been traced past a bare "stub with unfindable caller." The other known caller (`FUN_60058b68`) and the exact final-assembly function remain open.

## Open / next targets (superseded in part by the session-8/10/11 sections above — kept for history)
- ~~**ADC conversion trigger + result read**~~ — **found, session 10**: `FUN_60043028`, driven by a plain periodic FreeRTOS software-timer tick (the `HidPollMs`-configured poll timer at InputTask object `+0x3a4`), not an interrupt. See "InputTask found" section above.
- ~~**Button read path**~~ — **the registration+dispatch mechanism is fully mapped (session 8)**; the *periodic task that consumes it* is now also found (session 10, `FUN_600432e8`), but the exact write site for the 19 digital-button boolean fields is still open (see "Still open" #1 above) — it may turn out to be the session 8/9 GPIO-IRQ path after all, just landing on the InputTask object rather than the board object those sessions were inspecting.
- **Report-packing function**: **narrowed, not yet closed (session 10)** — found the button/D-pad bit-packer (`FUN_60042d44`, bit-for-bit matches the report's hat-nibble + 15-button-bitfield layout) and confirmed `hid_input_target__60058aa8`'s real `(report_words, length)` signature, but the function that assembles the full 11-byte buffer and calls it is still unidentified; narrowed to two candidate pass-through stubs (`FUN_600df4b6`, `FUN_60058b7a`) whose own callers aren't found by either literal search or Ghidra xrefs. See "Still open" #2 above.
- ~~`FUN_6004cdb8` (15.6 KB, near image start)~~ — **decompiled (session 4): this is SHA-512/384 compression, not an event loop.** See `analysis/bruce-crypto.md` — bruce statically links BoringSSL SHA-512 + Ed25519 keygen/ASN.1. `main__60051168` (session 5, this doc) is straight-line init, not a loop either. **Found, session 10:** the real per-tick input dispatch loop is `FUN_600432e8` (InputTask's `Run()` method, virtual-dispatched, started from `main__60051240`'s `xTaskCreateStatic` call) — see above. (A generic firmware-wide "main loop" doesn't really exist; each FreeRTOS task, including this one, has its own.)
- ~~Map ITCM blob~~ — **done, `analysis/bruce-itcm.md`** (session 5, parallel thread).

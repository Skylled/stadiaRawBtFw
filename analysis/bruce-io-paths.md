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

## Open / next targets
- **ADC conversion trigger + result read**: found the one-shot ADC1/ADC2 *configuration* (`FUN_600522b8`, base+0x44/+0x48) and the per-channel *pin/channel descriptor* setup (`adc__60071f74`, 8 channels incl. the 6 stick/trigger candidates), but not yet the runtime call that starts a conversion (write to `HCn`) and reads the result register (`Rn`) each frame. Likely reached through further un-decompiled `adc.h` functions or an ITCM HAL thunk (`thunk_EXT_FUN_...`) — see the ITCM gap below.
- **Button read path**: `io_pin__6005fe04` shows pins can be configured for GPIO interrupts (`FUN_600532f0`), which suggests buttons are edge-interrupt-driven, not polled — worth decompiling `FUN_600532f0` and the NVIC vector table next to see if there's an ISR that updates a shared button-state bitmap, rather than looking for a periodic "sample" task.
- **Report-packing function**: still unidentified — whatever combines calibrated stick/trigger values + button state into the final 11-byte report ID 3 buffer (`hid_input_target.cc` @ 0x60058aa8 only *transmits* an already-built report).
- ~~`FUN_6004cdb8` (15.6 KB, near image start)~~ — **decompiled (session 4): this is SHA-512/384 compression, not an event loop.** See `analysis/bruce-crypto.md` — bruce statically links BoringSSL SHA-512 + Ed25519 keygen/ASN.1. `main__60051168` (session 5, this doc) is straight-line init, not a loop either — the real per-frame dispatch loop is still unidentified.
- ~~Map ITCM blob~~ — **done, `analysis/bruce-itcm.md`** (session 5, parallel thread). Use `MapItcmAddr.java` + `Decompile.java` to resolve the remaining ADC-result-read and GPIO-IRQ-registration thunks (`FUN_600532f0` and whatever it calls are good next candidates to check for ITCM HAL calls).

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

### ITCM-resident HAL primitives (analysis gap)
Pervasive calls like `thunk_EXT_FUN_00007a2c`, `thunk_EXT_FUN_00001ea4`, `thunk_EXT_FUN_0000737c`, `thunk_EXT_FUN_0000b572` target low addresses (0x0000xxxx) that are **not in the static flash image** — hot HAL/RTOS routines copied into ITCM at boot. Signatures inferred from call sites: `00001ea4` = I2C transfer `(handle, reg, wbuf, wlen, rbuf, rlen, timeout)`; `00007a2c` = a bus/queue transaction `(handle, cmd, arg, out, timeout)`. To recover these, next step is to find the boot-time ITCM copy (memcpy of a flash blob → 0x00000000 region) and map that blob.

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
The constructor for the main input/HID task object. It: builds the USB device descriptor (embeds `"Google LLC"`, `"Stadia Controller rev. A"`); registers ~14 input-field channels via repeated `FUN_600717a0(...)` (matching the descriptor's hat/buttons/axes/triggers/consumer fields); installs per-field sampler callbacks as function pointers into the **0x600d… region** (`PTR_LAB_600d5636`, `600d51f4`, `600d4560`, `600d8f9e`, `600d99ee`, …); and starts a **"Haptic pulse"** timer (1000 units, `timers__600cad24`). The actual per-frame reading of buttons/sticks/triggers happens in those 0x600d callbacks (next target).

## Input calibration — `input_calibration.cc` (~0x60058e78–0x6005990c, mostly unbounded)
Handles joystick & trigger calibration: `calibration_in/out`, `deadzone_in/out`, per-axis config keys `c_left_joystick_x/y`, `c_right_joystick_x/y`, `c_left_trigger`, `c_right_trigger` (stored in the `keys.cc` config KV store), parsed from a calibration protobuf. Logs "No joystick/trigger calibration found". So raw ADC stick/trigger values are calibrated + deadzoned before going into report ID 3.

## Open / next targets
- **Per-field samplers**: trace the `0x600d…` callback pointers installed by `timer__60073bf0` — these read the raw buttons (GPIO) and stick/trigger ADC values that get calibrated and packed into report ID 3.
- **ADC path**: `adc.h` is inlined; find the i.MX RT ADC/LPADC register reads feeding the stick/trigger channels.
- **`FUN_6004cdb8`** (15.6 KB, near image start) — still unread; likely a major event/dispatch loop.
- **Map ITCM blob** to resolve the `thunk_EXT_FUN_0000xxxx` HAL primitives (find the boot memcpy of a flash blob → 0x0 region).

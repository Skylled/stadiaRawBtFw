# Stadia Controller — live device probe log

Raw, per-stage documentation of real controllers over USB. Goal: characterize each
USB/boot mode, the data readable and actions available at each, and confirm the HAB
(secure-boot) state. Companion to `analysis/firmware-map.md`; hardware facts summarized
in Claude memory `stadia-hardware-baseline` / `stadia-flashing-protocol`.

## Host / tooling
- macOS (Darwin 24.5.0), Apple Silicon.
- spsdk **3.10.0** binaries at `/Library/Frameworks/Python.framework/Versions/3.13/bin`:
  `sdphost`, `blhost`, `nxpdevscan`, `nxpfuses`, plus `python3` + `pyusb`/`libusb`.
- All probes below are **read-only** (no flash writes). Nothing was programmed/erased.

## Controllers under test — per-unit fingerprints (normal mode `0x18D1:0x9400`)
Serial from the USB device descriptor; FW build from vendor control request `bRequest 0x81`
(**`bmRequestType 0xA1` = class/interface, IN, 4 B little-endian** = firmware build number;
the vendor-recipient forms `0xC1`/`0xC0` return the `0xDEADDEAD` stub). `bcdDevice 0x0100`,
Manufacturer "Google LLC", Product "Stadia Controller rev. A" on all four.

| Tag | Notes | Serial | FW build (0x81) | image |
|-----|-------|--------|-----------------|-------|
| Black | primary; full HAB workup + tamper A/B | `9B260YCAC6SBVQ` | 337784 | bruce (BT) |
| Founder | earliest commercial batch | `99100YCAC296Y5` | 337784 | bruce (BT) |
| Premiere | Premiere Edition | `9A050YCAC2KB6R` | 337784 | bruce (BT) |
| Wasabi | 4th unit | `99170YCAC56LWF` | 337784 | bruce (BT) |

The **serial is the only real per-unit differentiator** (each unique; all share the middle
segment `YCAC`). Firmware build (337784, bruce/BT), `bcdDevice`, and HAB state are identical
across all four — the fleet is uniform in security posture and firmware.

## USB / boot-mode state machine (observed on Black)
| Mode | VID:PID | Product string | How to enter | Secure state |
|------|---------|----------------|--------------|--------------|
| Normal firmware | `0x18D1:0x9400` | "Stadia Controller rev. A" | plug in, no buttons | — |
| Google 2nd-stage **Bootloader** | `0x18D1:0x946B` | "Bootloader" | **hold a button while plugging in, LED off** | runs from flash `~0x60800000` |
| NXP mask-ROM **SDP** | `0x1FC9:0x0135` | "SP Blank RT Family" (chip MXRT106X) | from any state: **Options(⋯)+Assistant+A+Y** | `error-status` HAB word = **0x12343412 → CLOSED/locked** |
| NXP **KBOOT** flashloader | `0x15A2:0x0073` | "USB COMPOSITE DEVICE" (K2.7.0) | SDP: write-file `restricted_ivt_flashloader.bin`→`0x20000000`, jump `0x20000400` | signed loader authenticated & ran under closed HAB |

Notes:
- The three-**lines** "Menu" button and the three-**dots** "Options" button BOTH land in `0x946B`
  when simply held during plug-in. Reaching **SDP** requires the 4-button chord
  **Options+Assistant+A+Y**. (Earlier confusion: Menu-held → `0x946B`, mistaken for SDP.)
- Clean exit from any bootloader: `blhost … reset` (reboots to normal FW), or unplug +
  hold **Stadia** button ~10 s.
- **The controller is battery-backed: unplugging USB does NOT power-cycle the MCU.** A
  bootloader/SDP state therefore *persists across a USB replug* (the chip keeps running on
  battery), and LED stays off with no button held. To truly return to normal firmware you must
  force a hardware reset — hold the **Stadia** button ~10 s (or `blhost reset` after loading a
  flashloader). This explains a unit found still in SDP on a plain replug, and the mid-transition
  "limbo" (device vanished from USB) seen when a chord was pressed from within `0x946B`.

---

# Black controller

## Stage: Normal firmware — `0x18D1:0x9400`
- "Stadia Controller rev. A", Google LLC, bcdDevice 0x0100, 480 Mb/s, serial `9B260YCAC6SBVQ`.
- Composite `bDeviceClass 0xEF`: iface0 = vendor class `0xFF` (raw/flash channel),
  iface1 = HID class 3 (gamepad). Matches prior static analysis.

## Stage: Google 2nd-stage "Bootloader" — `0x18D1:0x946B`  (2026-08-15T21:07–21:09Z)
Entered by holding **Options (⋯)** while plugging USB (LED stays OFF). Same mode reached
via the Menu button previously.

Descriptors:
- `bcdDevice 0x0001`, Manufacturer "Google Inc.", Product "**Bootloader**", Serial "serial-not-set".
- `bDeviceClass 0xEF / sub 0x02 / proto 0x01` (IAD composite), 1 config, maxpower 250 (500 mA).
- iface 0: class `0xFF` sub 0 proto 0 — **bulk** IN `0x87` / OUT `0x07`, wMaxPacketSize **512**.
- iface 1: class `0x03` (HID) sub 0 proto 0 — **interrupt** IN `0x83` / OUT `0x03`, mps 64, interval 6.

Read-only action probe (pyusb control transfers):
- `GET_STATUS(dev)` → `0x0001` (self-powered). `GET_CONFIGURATION` → 1.
- **BOS descriptor present (57 B), advertises two platform capabilities:**
  - **WebUSB** — GUID `{3408B638-09A9-47A0-8BFD-A0768815B665}`, bcdVersion 0x0100, **bVendorCode 0x01**, iLandingPage 0x00 (no landing URL).
  - **Microsoft OS 2.0** — GUID `{D8DD60DF-4589-4CC7-9CD2-659D9E648A9F}`.
  - ⇒ Bootloader is driven by **WebUSB vendor requests**, not raw fastboot. (Raw fastboot
    ASCII `getvar:…` written to bulk OUT `0x07` earlier just **timed out** → not fastboot.)
- **HID report descriptor read (iface1) returns no valid descriptor** — the over-long read
  returned a stale RAM/DMA buffer that **leaks live pointers**: `0x60813d98`, `0x60805ea9`,
  `0x60805b39`, `0x6080a06b`, `0x60809e31` (all in **Bootloader-A flash `0x60800000–0x60814000`**)
  + SRAM `0x200016d0`, `0x2000918c`, `0x20004520`, `0x20001660`. ⇒ this 2nd-stage bootloader
  **executes from `~0x60800000`** (the "Bootloader A" partition in the flash map).
- Normal-FW vendor requests are **stubbed**: `bRequest 0x81` (fw version, len 4) and `0x84`
  (battery, len 2) both return sentinel **`0xDEADDEAD`** for every bmRequestType variant
  (0xC1/0xA1/0xC0/0xA0) → the app vendor protocol is absent in this mode.

Open thread: map the WebUSB vendor protocol (bVendorCode 0x01) on the bulk pipe — this is
the channel the browser flasher uses to talk to `0x946B`. Not needed for the HAB question.

## Stage: NXP mask-ROM SDP — `0x1FC9:0x0135`  (2026-08-15, earlier session)
- "SP Blank RT Family", chip family **MXRT106X**.
- `sdphost error-status` → **Status (HAB mode) = 0x12343412 "HAB Is Enabled (Locked)"**;
  Response 0xF0F0F0F0 "HAB Success". (Open/unsecured would be `0x56787856`.) ⇒ **HAB CLOSED.**
- `write-file 0x20000000 restricted_ivt_flashloader.bin` → "Write File Success" (0x88888888).
- `jump-address 0x20000400` → prints "HAB Is Enabled (Locked)" and the **signed** flashloader
  **authenticated and executed** (device re-enumerated to KBOOT). An unsigned image would be
  rejected here — this is the pending positive-control test.

## Stage: NXP KBOOT flashloader — `0x15A2:0x0073`  (2026-08-15, earlier session)
- "USB COMPOSITE DEVICE"; `get-property 1` → **CurrentVersion K2.7.0**.
- `get-property 7` AvailableCommands `0x56FDF` = FlashEraseAll, FlashEraseRegion, ReadMemory,
  WriteMemory, FillMemory, GetProperty, ReceiveSBFile, Execute, Call, Reset, SetProperty,
  FlashProgramOnce, FlashReadOnce, ConfigureMemory, GenerateKeyBlob.
- `get-property 12` Reserved Regions: `0x20002000–0x20016D08` (83.3 kiB), `0x20208000–0x20216FFF` (60 kiB).
- **Fuse/OCOTP reads are blocked by this restricted loader:** `read-memory 0x401F4400 …`
  → "Memory Range Invalid" (0x27D8); `flash-read-once 0 4` and `efuse-read-once 0`
  → "Unknown Command" (0x2710) despite the bitmask advertising FlashReadOnce. ⇒ raw SRK-hash
  bytes not extractable via this loader; SDP HAB-mode word is the authoritative signal.
- `reset` → returns cleanly to normal firmware `0x18D1:0x9400`.

## Stage: Positive-control — tampered vs signed, same SDP session  (2026-08-15T21:15–21:16Z)
Direct proof that the closed ROM rejects unsigned code. Both images loaded to SRAM over the
**same** `0x1FC9:0x0135` SDP connection; the only difference was one corrupted byte.
HAB status legend (2nd word of `sdphost error-status`): `0xF0`=SUCCESS, `0x33`=FAILURE,
`0x69`=WARNING (each byte repeated x4).

| Step | Image | Action | Result |
|------|-------|--------|--------|
| baseline | — | `error-status` | HAB mode `0x12343412` (locked); HAB status **`0xF0F0F0F0` SUCCESS** |
| tamper | `restricted_ivt_flashloader.bin` w/ byte[0x8000] `0xA4→0x5B`, IVT `d1002041` intact | `write-file 0x20000000` → `jump-address 0x20000400` | write OK (`0x88888888`); **did NOT become KBOOT — stayed in SDP**; `error-status` HAB status now **`0x33333333` FAILURE** |
| signed | untouched `restricted_ivt_flashloader.bin` | `write-file` → `jump-address` (same session) | **re-enumerated to KBOOT `0x15A2:0x0073` K2.7.0** → authenticated & ran |
| cleanup | — | `blhost reset` | back to normal FW `0x18D1:0x9400` |

Notes: the ROM authenticated the good image immediately after the failure (HAB fail-state
not sticky, no power-cycle needed). The controller was never bricked and needed no recovery.

## Verdict (Black)
**HAB is CLOSED / secure boot locked — proven two ways.** (1) SDP `error-status` HAB-mode word
`0x12343412` = enabled/locked. (2) Positive control: a 1-byte-corrupted flashloader produced
HAB status `0x33333333` (FAILURE) and did not execute, while the untouched signed image
authenticated and ran (KBOOT) in the same session. **Only Google-RSA-4096-signed images boot;
unsigned/custom firmware cannot run on-device.** Approach A (on-device custom firmware) is dead
at the fuse layer, independent of the PS5 auth wall.

---

# Other controllers (to test)
Repeat the stage sequence per unit; note especially the **early-batch** controller in case its
fuses/HAB differ. Fast path per unit: enter SDP (Options+Assistant+A+Y, direct-to-Mac port) →
`sdphost error-status` (HAB-mode word 0x12343412 vs 0x56787856) → optionally the tamper/signed
A/B. Record VID:PID at each mode + serial.

| Tag | Batch/notes | Normal serial | SDP HAB-mode word | Verdict |
|-----|-------------|---------------|-------------------|---------|
| Black | primary | 9B260YCAC6SBVQ | `0x12343412` (closed) | CLOSED — unsigned rejected (tamper A/B) |
| Founder | early commercial batch | (SDP; N/A) | `0x12343412` (closed) | CLOSED — HAB status `0xF0F0F0F0` clean; quick check, no A/B (2026-08-15T21:18Z) |
| Premiere | Premiere Edition | (SDP; N/A) | `0x12343412` (closed) | CLOSED — HAB status `0xF0F0F0F0` clean; quick check (2026-08-15T21:20Z) |
| Wasabi | 4th unit | (SDP; N/A) | `0x12343412` (closed) | CLOSED — HAB status `0xF0F0F0F0` clean; quick check (2026-08-15T21:22Z) |

**Sweep result: 4/4 controllers HAB-closed** (Black, Founder [earliest batch], Premiere, Wasabi).
Black additionally proven to reject a tampered image (HAB_FAILURE). No unit deviates → the
locked secure-boot configuration is uniform across the retail Stadia Controller fleet sampled.

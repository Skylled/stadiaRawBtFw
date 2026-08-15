# CLAUDE.md — Stadia Controller firmware RE

Orientation for working in this repo. Deep technical findings live in `analysis/*.md`; read those for detail rather than duplicating them here.

## What this is
This started as a dump of the Google Stadia Controller's official firmware (`bruce_*` = Bluetooth-mode, plus flashloaders). The active work is **reverse-engineering and documenting that firmware** — a preservation effort the owner cares about in its own right. The original "make it work on a PS5 (spoofing a DualShock 4)" idea is now a secondary/aspirational angle: it's blocked at the **PlayStation console-authentication layer**, not by anything in the Stadia firmware (see `analysis/` + the detailed reasoning in Claude memory). Don't relitigate the PS5 feasibility question without new information.

Scope: this is legitimate RE of firmware the owner possesses, for understanding/preservation/personal-use compatibility. Keep it that way.

Work happens on the **`firmware-re`** branch (not `main`).

## Hardware in one line
NXP **i.MX RT106x** (Cortex-M7), execute-in-place from a 16 MB Winbond **W25Q128JW** QSPI flash mapped at **0x60000000**; Broadcom **BCM43458** BT/Wi-Fi radio; FreeRTOS; firmware is HAB-signed (RSA-4096) but **not encrypted**. Full detail in Claude memory (`stadia-hardware-baseline`) and `analysis/firmware-map.md`.

## Repo layout
- `bruce_pvt_a_prod_signed.bin`, `restricted_ivt_flashloader.bin`, `flashloader_fcb_get_vendor_id.bin` — original committed dumps (repo root).
- `reference_firmware/` — firmware recovered from the Wayback Machine (Google's asset host is dead): `bruce` dev/stage/prod (code-identical, differ only in the HAB signature block), the two `gotham` Wi-Fi OTA images (`pvt-a`/`pvt-b`), and the W25Q128JW FlexSPI config block.
- `analysis/` — all RE work:
  - `firmware-map.md` — top-level structural map; `bruce` (BT) vs `gotham` (Wi-Fi, a full embedded WebRTC cloud-streaming client).
  - `bruce-ghidra.md` — Ghidra workspace details, function/module map, re-run recipes.
  - `bruce-io-paths.md` — decompiled HID input/output + rumble + input-subsystem findings; **the current working document**.
  - `ghidra_scripts/` — headless GhidraScripts (Java) + `decode_hid_descriptor.py`.
  - `ghidra/` — the Ghidra project **and generated CSV/TXT outputs**. The project database (`*.gpr`, `*.rep/`) and `*.log` are **git-ignored** (regenerable); the `bruce_*.csv`/`.txt` outputs are committed.
  - `decomp/` — decompiled C for functions of interest (committed).

## Ghidra workspace — how to drive it
Ghidra 12.x (Homebrew). **Must run on JDK 21** (the system default JDK is too new and Ghidra will misbehave):
```bash
export JAVA_HOME="/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home"
HL=/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless
```
Load params for any Stadia image: raw `BinaryLoader`, **base 0x60040000**, processor **`ARM:LE:32:Cortex`** (Cortex-M7 Thumb-2). (`gotham` pvt-b links at 0x60840000 instead.)

Import + analyze + map (from repo root):
```bash
"$HL" analysis/ghidra bruce -import reference_firmware/bruce_pvt_a_prod_signed.bin -overwrite \
  -loader BinaryLoader -loader-baseAddr 0x60040000 -processor ARM:LE:32:Cortex \
  -scriptPath analysis/ghidra_scripts -preScript SeedCortexM.java -postScript DumpMap.java
```
Then run scripts against the existing project without re-analyzing (`-process ... -noanalysis`):
```bash
# who references a data address (e.g. a string)
"$HL" analysis/ghidra bruce -process bruce_pvt_a_prod_signed.bin -noanalysis \
  -scriptPath analysis/ghidra_scripts -postScript FindRef.java 0x601230e7
# decompile functions -> analysis/decomp/*.c (creates a function if none exists at the addr)
"$HL" analysis/ghidra bruce -process bruce_pvt_a_prod_signed.bin -noanalysis \
  -scriptPath analysis/ghidra_scripts -postScript Decompile.java 0x60073bf0 0x600656a0
```
Open the GUI with `JAVA_HOME=… /opt/homebrew/opt/ghidra/libexec/ghidraRun` and open the `analysis/ghidra` project. The scripts hardcode output paths under `/Users/kyle/Repos/stadiaRawBtFw/analysis/`; adjust if the repo moves.

Custom scripts: `SeedCortexM` (parse the Cortex-M vector table before analysis), `DumpMap` (function/string CSVs), `AnnotateFromFilenames` (attribute functions to source files via leaked `__FILE__` strings — the core navigability trick), `FindRef` (xrefs to an address), `Decompile` (dump C + callers/callees).

## Conventions & gotchas
- **Never commit the Ghidra DB** (it's ~23 MB and regenerable) — the `analysis/.gitignore` handles `*.gpr`, `*.rep/`, `*.log`. Do commit the scripts, `.md` writeups, CSV/TXT outputs, and `decomp/*.c`.
- Commit messages end with the `Co-Authored-By: Claude Opus 4.8` trailer (see git log for the pattern). Work on `firmware-re`; don't commit to `main`.
- **`getImageBase()` is 0** for a raw `BinaryLoader` import — use `getMinAddress()` for the load address (this bit `SeedCortexM` once).
- Function attribution comes from leaked `__FILE__` strings, so a function's *file* is reliable but the file's *purpose* may not be — verify by reading. Known trap: **`keys.cc` is a typed config key-value store, not gamepad buttons.**
- Pervasive `thunk_EXT_FUN_0000xxxx` calls target low addresses (0x0000xxxx) **not present in the static flash image** — these are hot HAL/RTOS routines (I2C, queues) copied into tightly-coupled memory at boot. Recovering them means finding the boot-time memcpy of a flash blob into the 0x0 region.
- The HID report descriptor is embedded at flash **0x60103BA0**; `analysis/ghidra_scripts/decode_hid_descriptor.py` decodes it.

## Current status & next targets
The BT firmware's gamepad I/O is largely mapped: HID report format (input ID 3 / rumble output ID 5), the input-subsystem constructor, calibration, and the rumble/haptics path — all in `analysis/bruce-io-paths.md`. Open threads, in rough priority:
1. Trace the per-field **sampler callbacks** (`0x600d…` function pointers installed by `timer__60073bf0`) that read raw button GPIOs and stick/trigger ADC values.
2. Decompile `FUN_6004cdb8` (15.6 KB, near image start) — likely the main event/dispatch loop.
3. Map the **ITCM blob** to resolve the `thunk_EXT_FUN_0000xxxx` HAL primitives.
4. Longer term: apply the same workflow to the `gotham` Wi-Fi firmware (the cloud-streaming stack).

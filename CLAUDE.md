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
  - `bruce-crypto.md` — the embedded BoringSSL crypto stack (SHA-512, Curve25519/Ed25519 field+point arithmetic, the generic `EVP_PKEY_ASN1_METHOD` registry) — traced bottom-up from the largest functions in the image.
  - `bruce-itcm.md` — the boot-time ITCM copy (`Reset_Handler`'s `memcpy(0x0, 0x6004081c, 0xbdf8)`) and resolved `thunk_EXT_FUN_0000xxxx` HAL primitives.
  - `bruce-decompile-status.md` — **the master tracking doc for the full-decompile goal**: data-driven attributed/decompiled coverage stats (by function count and by byte size) across all ~5,000 functions, per-source-file gap table, and ranked list of the biggest unattributed contiguous address ranges. Regenerate/re-consult this before picking the next chunk of work rather than guessing.
  - `bruce-misc-functions.md` — grab-bag write-ups for decompiled functions that don't fit an existing doc's theme yet (haptics tick-path detail, sleep driver, misc input-ctor helpers, etc.).
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

Custom scripts: `SeedCortexM` (parse the Cortex-M vector table before analysis), `DumpMap` (function/string CSVs), `AnnotateFromFilenames` (attribute functions to source files via leaked `__FILE__` strings — the core navigability trick), `FindRef` (xrefs to an address), `Decompile` (dump C + callers/callees), `MapItcmAddr` (map an ITCM address 0x0000xxxx to its flash address per `bruce-itcm.md` — accepts bare offsets or `thunk_EXT_FUN_0000xxxx` names).

## Conventions & gotchas
- **Never commit the Ghidra DB** (it's ~23 MB and regenerable) — the `analysis/.gitignore` handles `*.gpr`, `*.rep/`, `*.log`. Do commit the scripts, `.md` writeups, CSV/TXT outputs, and `decomp/*.c`.
- Commit messages end with the `Co-Authored-By: Claude Opus 4.8` trailer (see git log for the pattern). Work on `firmware-re`; don't commit to `main`.
- **`getImageBase()` is 0** for a raw `BinaryLoader` import — use `getMinAddress()` for the load address (this bit `SeedCortexM` once).
- Function attribution comes from leaked `__FILE__` strings, so a function's *file* is reliable but the file's *purpose* may not be — verify by reading. Known trap: **`keys.cc` is a typed config key-value store, not gamepad buttons.**
- Pervasive `thunk_EXT_FUN_0000xxxx` calls target low addresses (0x0000xxxx) — these are hot HAL/RTOS routines (I2C, queues, memcpy/memset, FreeRTOS task-yield) copied into ITCM at boot. **Resolved (session 5, `analysis/bruce-itcm.md`):** `Reset_Handler` copies flash `0x6004081c`–`0x6004c614` to ITCM `0x0`–`0xbdf8`, so `flash_addr = itcm_addr + 0x6004081c` — the bytes are already in the static image at that flash offset, no overlay needed. Use `MapItcmAddr.java` then `Decompile.java` on the resulting flash address to resolve any given thunk; 142 of 155 done so far (all distinct thunk targets — the remaining gap is duplicate veneer stubs into already-resolved targets, not unresolved code).
- The HID report descriptor is embedded at flash **0x60103BA0**; `analysis/ghidra_scripts/decode_hid_descriptor.py` decodes it.

## Current status & next targets
**Standing goal (session 6+): fully decompile and document `bruce` to the extent it could be recompiled bit-for-bit given Google's signing keys.** Per `analysis/bruce-decompile-status.md` (session 6): of ~4,995 functions, only ~22% of the image's code by byte size is understood in any way (attributed to a source file and/or decompiled) — **~78% (515 KB across ~4,500 functions) is completely unmapped.** That doc is the live tracking checklist; consult it before starting new work rather than re-deriving scope here. Treat this as a large, ongoing, multi-session effort — delegate well-scoped chunks to subagents rather than doing bulk decompilation inline, and only one agent at a time may hold the Ghidra project open (`analysis/ghidra/bruce.rep` is a single-writer file-based DB — concurrent `analyzeHeadless -process` invocations will conflict).

The BT firmware's gamepad I/O is largely mapped: HID report format (input ID 3 / rumble output ID 5), the input-subsystem constructor, calibration, and the rumble/haptics path — all in `analysis/bruce-io-paths.md`. Session 4/5 mapped a second major subsystem: bruce statically links a substantial chunk of BoringSSL (SHA-512, Curve25519/Ed25519, generic EVP/ASN.1 registry — `analysis/bruce-crypto.md`) and the ITCM boot-copy blob is now fully mapped (`analysis/bruce-itcm.md`). Open threads, in rough priority:
0. **Highest-leverage target: the unattributed block `0x600921b8`–`0x600c9cc4`** — 1,076 functions, 204 KB, 89.6% code density, only 2 decompiled (`analysis/bruce-decompile-status.md` §3b run #1). Bigger than every other unmapped block combined except one. Already contains `FUN_600ba1c4` (confirmed session 6: a connection-protocol TLV parser feeding `state_machine.cc` events) and `FUN_600c8fd8` (confirmed session 6: strong shape/string evidence for **NIST P-256 modular reduction**, Solinas-style — relevant to BLE Secure Connections ECDH, a more relevant find than the X25519/Ed25519 stack in `bruce-crypto.md`). Too big for retail decompile-and-read — next step is module identification (xrefs into it from attributed code, `__FILE__` strings inside it) before mass-decompiling.
1. Find the runtime **button/ADC read path**. Two false leads now closed (`analysis/bruce-io-paths.md`): the `0x600d…` pointers in `timer__60073bf0` are haptics-timer glue, and the `obj+0x36e4`/`obj+0x3684` sub-objects passed to `FUN_600717a0` turned out to be the *encrypted-flash calibration-blob* store, not HID field descriptors. Real progress: found the ADC1/ADC2 bring-up (`board.cc`/`xbara.h`, confirmed MMIO bases 0x400C4000/0x400C8000) and 8 registered ADC channels including the 6 stick/trigger candidates — but still no runtime conversion-trigger/result-read call found. Also found `io_pin.cc` registers GPIO **interrupts** on some pins, hinting buttons may be edge-IRQ-driven rather than polled. Session 6 swept the entire ITCM blob (FreeRTOS core + HAL) and found **no direct ADC/GPIO/NVIC register access there** — the ISR/interrupt-registration code must live outside the ITCM blob. New lead (session 6, `analysis/bruce-misc-functions.md`): `FUN_60071624` makes 16 board-bring-up calls immediately after GPIO-IRQ pin config — plausibly the NVIC registration call — next step is decompiling the ISR (`FUN_600532f0`) and this lead's callees.
2. **Report-packing function** — still unidentified: whatever combines calibrated stick/trigger + button state into the final 11-byte report ID 3 buffer (`hid_input_target.cc` only transmits an already-built report). Not found in the session-6 sweep of undocumented decomp'd functions either.
3. Find the real **main event/dispatch loop** — the "biggest unread function" heuristic that flagged `FUN_6004cdb8` was a dead end (it's SHA-512 compression, not a dispatcher; see `analysis/bruce-crypto.md` for why). Fresh candidates from a re-sorted size survey are noted in `analysis/bruce-ghidra.md`.
4. ~~Map the ITCM blob~~ — done (sessions 5–6): boot copy is `memcpy(0x0, 0x6004081c, 0xbdf8)`; all 142 distinct veneer targets resolved (`analysis/bruce-itcm.md`). Surfaced a previously-unknown on-device microphone/audio DSP subsystem (FFT, IIR/CIC filters, WebRTC-style noise-suppression gain control — shared with `gotham`, likely for the Assistant-button mic) plus the runtime FlexSPI/QSPI flash driver and the FreeRTOS PendSV/scheduler core.
5. Find what (if anything) actually calls into the Ed25519/EVP crypto stack at runtime — every traced call path currently dead-ends 1-2 hops up with no further caller found (`analysis/bruce-crypto.md`); worth another look once more of the BT pairing / OTA-update code is mapped. (The P-256 find in item 0 is a separate, more likely candidate for the *actual* BLE pairing crypto in active use.)
6. `FUN_601054dc` (`analysis/bruce-ghidra.md`) is confirmed (session 6) to be genuine disassembly corruption — likely an unrecognized Thumb-2 `TBB`/`TBH` jump table — not a real function boundary. Needs a manual jump-table fixup in Ghidra before it's usable, not another blind decompile attempt.
7. Longer term: apply the same workflow to the `gotham` Wi-Fi firmware (the cloud-streaming stack).

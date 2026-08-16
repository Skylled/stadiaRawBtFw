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
**Standing goal (session 6+): fully decompile and document `bruce` to the extent it could be recompiled bit-for-bit given Google's signing keys.** Per `analysis/bruce-decompile-status.md` (regenerated session 8): of ~4,995 functions, **35.4% of the image's code by byte size is now understood in some way** (up from 22.0% at session 6) — mostly from locating the BTA/BTE Bluetooth stack (below). A more precise "truly unidentified, no module guess at all" figure is **47.7%** once functions already identified-but-not-yet-decompiled (mainly the rest of the BTA/BTE stack) are separated out from genuinely unknown code. That doc is the live tracking checklist; consult it before starting new work rather than re-deriving scope here. Treat this as a large, ongoing, multi-session effort — delegate well-scoped chunks to subagents rather than doing bulk decompilation inline, and only one agent at a time may hold the Ghidra project open (`analysis/ghidra/bruce.rep` is a single-writer file-based DB — concurrent `analyzeHeadless -process` invocations will conflict).

The BT firmware's gamepad I/O is largely mapped: HID report format (input ID 3 / rumble output ID 5), the input-subsystem constructor, calibration, and the rumble/haptics path — all in `analysis/bruce-io-paths.md`. Sessions 4-7 mapped three more major subsystems: the BoringSSL crypto stack (`analysis/bruce-crypto.md`), the ITCM boot-copy blob (fully resolved, `analysis/bruce-itcm.md`), and — the big one — the statically-linked **Broadcom BTA/BTE Bluetooth stack**, located and identified with very high confidence at `0x600921b8`–`0x600c9cc4` (HCI/BTM/GATT/SDP/SMP/L2CAP/EC-crypto; 327 of 1,076 functions decompiled, ~46% by byte size — `analysis/bruce-bta-stack.md`). Open threads, in rough priority:
1. **Report-packing function (still the top priority, now narrowed to two candidate call sites).** Sessions 8-9 mapped the GPIO button-IRQ chain (NVIC → shared ITCM dispatcher `FUN_60049290` → a 160-slot callback table on the **board singleton**, RAM `0x200064c0`, populated only with a generic no-op by `timer__60073bf0`). **Session 10 found that thread's premise was a dead end to chase further** — the actual periodic input/HID task is a **separate C++ singleton, `InputTask` (RAM `0x200108a8`)**, unrelated to the board object, task-created from **`main__60051240`** via a confirmed **`xTaskCreateStatic`** (`tasks__600ca1f8`, byte/line-number-matched against upstream FreeRTOS `tasks.c`). InputTask's `Run()` method (**`FUN_600432e8`**, reached only via virtual dispatch — vtable slot `+8`) starts a `HidPollMs`-configured software timer and loops on `xEventGroupWaitBits`; its periodic-tick branch calls **`FUN_60043028`** (confirmed calibrated axis/trigger sampling — the item-2 target below, now resolved) which, on change, calls **`FUN_60042d44`** — a button/D-pad bit-packer whose 3-byte output is a bit-for-bit structural match to the report's hat-nibble + 15-button bitfield, though it writes into an intermediate 16-slot ring buffer, not directly to the wire. The final assembly-into-11-bytes-and-call-`hid_input_target__60058aa8` site is still unidentified, but narrowed to two trivial pass-through stubs (`FUN_600df4b6`, `FUN_60058b7a`) whose own callers can't be found via literal search or Ghidra xrefs (likely a not-yet-typed vtable). Also still open: exactly where the 19 digital-button boolean fields (consumed by `FUN_60042d44`) get written — not visibly inside `FUN_60043028`, so possibly the session-8/9 GPIO-IRQ path after all, just landing on the InputTask object rather than the board object those sessions inspected. Full detail in `analysis/bruce-io-paths.md`'s "InputTask found: creation, Run() loop, sampling, and button bit-packing (session 10)" section.
2. ~~Find the real main event/dispatch loop~~ — **resolved for the BT stack (session 7):** `FUN_600a9fce` is `btu_task`, BTE's GKI-mailbox message pump (self-logs `"btu_task"`; dispatches HCI events and ACL/L2CAP data). The overall RTOS scheduler-level main loop (if distinct from this) is still unconfirmed, but the BT-stack dispatch loop specifically is done — the earlier `FUN_6004cdb8` "biggest unread function" lead was a dead end (SHA-512 compression, see `analysis/bruce-crypto.md`).
3. ~~Map the ITCM blob~~ — done (sessions 5–6): boot copy is `memcpy(0x0, 0x6004081c, 0xbdf8)`; all 142 distinct veneer targets resolved (`analysis/bruce-itcm.md`). Surfaced a previously-unknown on-device microphone/audio DSP subsystem (FFT, IIR/CIC filters, WebRTC-style noise-suppression gain control — shared with `gotham`, likely for the Assistant-button mic) plus the runtime FlexSPI/QSPI flash driver and the FreeRTOS PendSV/scheduler core.
4. ~~Find what calls into the EC crypto stack~~ — **resolved (session 7):** traced `smp_data_ind` → `smp_sm_event` (SMP's FSM dispatcher) → BLE-RAND-seeded ECDH keypair generation → confirmed EC scalar multiplication → the P-256/P-192 modular-reduction helpers, end-to-end. SMP's LE Secure Connections pairing is the real runtime consumer of the P-256 stack found in item 5 below — a more likely "live" curve than the Ed25519/X25519 stack in `analysis/bruce-crypto.md`, which still has no confirmed caller.
5. **Continue the BTA/BTE stack sweep** (`analysis/bruce-bta-stack.md`) — 749 of 1,076 functions in the block remain, though the highest-value "named via leaked string table" ones are now mostly exhausted (only unnamed/generic helpers likely remain, lower value per function). L2CAP is now located (`0x600b5xxx`–`0x600b9fxx`, corrected from an earlier "GATT-client cache" mislabel) but not deeply read. BTA_GATTS server API surface only partially covered.
6. `FUN_601054dc` (`analysis/bruce-ghidra.md`) is confirmed (session 6) to be genuine disassembly corruption — likely an unrecognized Thumb-2 `TBB`/`TBH` jump table — not a real function boundary. Needs a manual jump-table fixup in Ghidra before it's usable, not another blind decompile attempt.
7. `analysis/bruce-decompile-status.md`'s top-line/per-file stats are stale as of session 6 — only the §3b run #1 row has been kept current through session 7. Regenerate the full doc once a session has spare capacity; overall coverage is meaningfully higher now than the ~22%-by-size figure it currently states.
8. Longer term: apply the same workflow to the `gotham` Wi-Fi firmware (the cloud-streaming stack).

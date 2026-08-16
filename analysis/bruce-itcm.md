# Bruce — the ITCM boot copy and `thunk_EXT_FUN_0000xxxx` resolution (session 5)

Decompiled C for every function cited here is in `analysis/decomp/`. Ghidra project regenerable per `bruce-ghidra.md`. New script: `analysis/ghidra_scripts/MapItcmAddr.java`.

## Confirmed: the copy loop

`Reset_Handler` (`0x60040500`) decompiles cleanly (`analysis/decomp/Reset_Handler.c`). After a soft-reset check, it runs a sequence of standard Cortex-M/CMSIS startup copy loops before jumping to the real init code. The relevant one:

```c
puVar4 = &DAT_6004081c;
for (puVar6 = (undefined4 *)0x0; (int)puVar6 < 0xbdf8; puVar6 = puVar6 + 1) {
  *puVar6 = *puVar4;
  puVar4 = puVar4 + 1;
}
```

i.e. a word-at-a-time `memcpy(dst=0x00000000, src=0x6004081c, size=0xbdf8)`:

- **Source (flash):** `0x6004081c` – `0x6004c614` (file offset `0x81c` – `0xc614` in `bruce_pvt_a_prod_signed.bin`)
- **Destination:** `0x00000000` – `0x0000bdf8` (ITCM, per CLAUDE.md's working theory)
- **Size:** `0xbdf8` = 48,632 bytes (~47.5 KiB), copied as 12,158 words

**Mapping formula:** `flash_addr = itcm_addr + 0x6004081c`, for `itcm_addr` in `[0, 0xbdf8)`. Automated by the new script `MapItcmAddr.java` (also accepts `thunk_EXT_FUN_0000xxxx` names directly).

The constants were cross-checked against the image's literal pool right after `Reset_Handler` (file offset `0x60c`/`0x610`/`0x614`, dumped with `xxd`): word at `0x60040610` = `0x00000000` (dest), `0x6004060c` = `0x6004081c` (src), `0x60040614` = `0x0000bdf8` (size) — all three match the decompiled constants exactly. The same literal pool also confirmed the adjacent loops: a `.data` copy (flash `0x6013d5a8` → RAM `0x20002740`–`0x20003fd8`), a `.bss` zero (RAM `0x20004020`–`0x2002a824`), a stack-paint fill (`0xAABBAABB` from `0x2002a828` to `SP-0x40 = 0x2002b7e8`, SP itself = `0x2002b828`, matching the SP already noted in `bruce-ghidra.md`), and finally a call through `*0x6004062c` = `0x6004c701` → `FUN_6004c700`, the real second-stage init (already listed as a `Reset_Handler` callee). `FUN_6004c700`'s block starts at flash `0x6004c700`, right after the copied ITCM region ends (`0x6004c614`) — the linker placed the ITCM-resident blob as one contiguous chunk immediately before normal `.text`, which is exactly what you'd expect from an `.itcm`/`.ramfunc` linker-script section.

## Confirmed: how call sites reach ITCM code (the veneer table)

`thunk_EXT_FUN_0000xxxx` isn't a raw address Ghidra invented — it's the *name* Ghidra gives after auto-resolving a real two-stage call:

1. Call sites `BL` to a small **veneer** function living at a normal, reachable flash address (mostly clustered at `0x6013cee8`–`0x6013d4e0`, right near the end of the image; a handful of earlier ones sit right after `Reset_Handler`, e.g. `0x60040644`).
2. The veneer is 4–8 bytes of code that loads the absolute ITCM target and branches to it — e.g. at `0x6013cee8`: `5f f8 00 f0` = Thumb-2 `LDR.W PC,[PC,#0]`, immediately followed by the literal word `0000af91` (i.e. target `0x0000af90`, Thumb bit set). Earlier veneers use the 4-byte Thumb-1 idiom `LDR r0,[pc,#N]; BX r0` instead (e.g. `0x60040644` → literal at `0x60040748` = `0x00000e51` → target `0x00000e50`).

Ghidra's function/thunk analysis walks through both hops and reports the *ultimate* low address in the name (`thunk_EXT_FUN_0000xxxx`), and `Function.getCallingFunctions()` already resolves through the whole chain to the real caller — no manual veneer-chasing needed once you have the ITCM→flash mapping.

**`bruce_functions.csv` lists 155 such veneers**, targeting ITCM offsets from `0x348` to `0xb5ca` — every single one falls inside the `[0, 0xbdf8)` range copied by the loop above, which is strong independent confirmation this is the right copy. Ghidra's ordinary auto-analysis had already disassembled **235 functions** inside the flash-resident copy source range `0x6004081c`–`0x6004c614` (it's just contiguous code in the image); resolving a thunk is therefore just "decompile the function at the mapped flash address" — **no Ghidra overlay/new memory block was needed.**

## Resolved thunk targets (10, via `MapItcmAddr.java` + `Decompile.java`)

18 of the 235 in-blob functions already carry `__FILE__`-string attribution (`bruce_srcmap.csv`): **7 to `queue.c`, 9 to `tasks.c`, 2 to `heap_5_improved.c`** — i.e. the blob is, as suspected, FreeRTOS's hottest primitives plus a HAL layer. Resolved by decompiling the mapped flash address:

| Thunk | ITCM addr | Flash addr | Resolved to |
|---|---|---|---|
| `thunk_EXT_FUN_0000737c` | `0x737c` | `0x60047b98` | **`tasks__60047b98`** (src: `tasks.c`) — checks a flag, calls a queue/notify helper and two more `tasks.c` routines, and on one path writes `0x10000000` to a MMIO register then `DSB`/`ISB` — the classic Cortex-M `SCB->ICSR = PENDSVSET` pattern FreeRTOS uses to force a context switch. Matches the "ring a hardware doorbell" idiom already seen in `hid_input_target` (`bruce-io-paths.md`). |
| `thunk_EXT_FUN_0000b5ba` | `0xb5ba` | `0x6004bdd6` | **`memset`**-shaped: byte-fill loop over `[param_1, param_1+param_3)` with `param_2`. |
| `thunk_EXT_FUN_0000b572` | `0xb572` | `0x6004bd8e` | **`memcpy`**-shaped: byte-copy loop, `param_1 ← param_2`, length `param_3`. |
| `thunk_EXT_FUN_0000af88` | `0xaf88` | `0x6004b7a4` | Thin wrapper: `if (len != 0) memcpy(...)` (calls the `memcpy` above). |
| `thunk_EXT_FUN_0000af90` | `0xaf90` | `0x6004b7ac` | Sibling wrapper: `if (len != 0) memset(...)` (inlined fill loop, same shape as the standalone `memset`). |
| `thunk_EXT_FUN_0000ac52` | `0xac52` | `0x6004b46e` | **`bzero`/`OPENSSL_cleanse`**-shaped: `if (len != 0) { zero-fill loop }`. Corroborates `bruce-crypto.md`'s inference (`FUN_600ec31c`'s one-shot `SHA512()` calls this thunk to wipe its stack context). |
| `thunk_EXT_FUN_0000714c` | `0x714c` | `0x60047968` | Trivial 6-byte getter: `return *DAT_60047970;` (single global word — likely a tick-count/state accessor). |
| `thunk_EXT_FUN_00007c58` | `0x7c58` | `0x60048474` | Lock-guarded field read: `lock(); v = *(obj+0x20); unlock(); return v;` — a mutex-protected accessor. |
| `thunk_EXT_FUN_00007a2c` | `0x7a2c` | `0x60048248` | **Bus/queue transaction** (already inferred in `bruce-io-paths.md` from call-site shape `(handle, cmd, arg, out, timeout)`); decompiles to exactly that — branches on `param_2` and calls **`queue__60047290`**/**`queue__600473e4`** (both `src: queue.c`), i.e. it's a thin front-end over two FreeRTOS-queue primitives. |
| `thunk_EXT_FUN_00001ea4` | `0x1ea4` | `0x600426c0` | **I2C transfer** (already inferred in `bruce-io-paths.md`). Fully confirmed here: references string literals `"i2c.cc"`, `"Delaying I2C until startup time"`, and `"I2c operations only supported af[ter startup]"` right in the decompiled body. |

## Open

- Not all 155 veneer targets have been individually decompiled — the remaining ~145 are addressable in one line each via `MapItcmAddr.java` + `Decompile.java` now that the mapping is known; only the highest-value/most-cited ones were pulled this session.
- The 236-byte gap between the copy's flash end (`0x6004c614`) and the next function boundary (`0x6004c620`) is presumably alignment padding / a data literal, not investigated further.
- The `.data`/`.bss`/stack-paint loops in `Reset_Handler` were read off the literal pool for cross-validation but not written up in depth — out of scope for this thread (ITCM only).

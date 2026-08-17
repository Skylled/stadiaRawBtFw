# PIPELINE.md — Two-model decompile/QA pipeline (Gemini ⇄ Claude)

The RE work now runs as **two independent, long-lived autonomous loops** that hand work back and forth through git, deliberately paced so neither model spends its whole token budget inside one 5-hour reset window. This lets both sides run under a `/goal`-style long loop indefinitely.

- **Gemini** owns the **Ghidra / decompilation** half → `PIPELINE-GEMINI-GHIDRA.md`
- **Claude** owns the **QA / adversarial-verification** half → `PIPELINE-CLAUDE-QA.md`

Only Gemini ever opens the Ghidra project (`analysis/ghidra/bruce.rep`, single-writer). Claude works purely from committed files (`analysis/decomp/*.c`, the raw `.bin`, the CSVs, `bruce_strings.txt`) and never runs Ghidra. So the two halves can never contend for the lock — the coordination below is about *sequencing*, not locking.

## Why alternate (and why the long wait)
Strict alternation — **decompile → QA → decompile → QA → …**, never two decompile waves in a row — is what keeps errors from compounding. Sessions 29 and 30 shipped the *same* error classes precisely because 30 was decompiled before 29 was QA'd; the feedback never reached the decompiler in time. Alternation guarantees every wave is verified before the next one builds on it, and it lets the decompiler *learn* from each QA before repeating. The long idle poll (below) spreads the two models' token spend across several 5-hour resets instead of burning either budget at once.

## The turn protocol — git is the single source of truth
Each turn ends with **exactly one tagged commit** as that turn's final commit:
- Gemini decompile wave → subject starts with **`[WAVE] session NN:`**
- Claude QA pass       → subject starts with **`[QA] session NN:`** (same `NN` as the wave it verified)

`NN` continues the session numbering in `CLAUDE.md` (last was 30, so the next wave is `session 31`).

**Whose turn is it?** From the repo root:
```bash
git log --format='%s' | grep -m1 -E '^\[(WAVE|QA)\]'
```
- Starts with `[QA]`   → **Gemini's turn** — the last wave is verified; decompile the next one.
- Starts with `[WAVE]` → **Claude's turn** — a wave is waiting to be QA'd.
- **Empty** (no tags yet) → **bootstrap** (see below).

## The wait rule (the throttle) — `POLL_INTERVAL = 45 minutes`
On every wake-up:
1. Compute whose turn it is (command above).
2. **Not your turn?** Do nothing — no Ghidra, no edits, no commit. Wait one `POLL_INTERVAL` (~45 min), then re-check. Repeat.
3. **Your turn?** Do your turn's work (per your role file), finish with your single tagged commit, then go back to step 1 — you'll now find it's the other model's turn and wait.

`POLL_INTERVAL` is the one tunable knob. One full cycle (`[WAVE]`→`[QA]`) runs ~1–1.5 h, so each model acts only a handful of times per 5-hour window. Raise it (60–90 min) if either budget still runs hot; lower it if the pipeline feels sluggish. **Change it in both role files if you change it here.**

## Bootstrap (first run — 2026-08-17)
No `[WAVE]`/`[QA]` tags exist yet, and Session 30 (`37895eb`) is decompiled but **not** QA'd under this protocol (Gemini's own self-QA does not count — the whole point is an *independent* verifier). So **Claude goes first**: QA Session 30, commit `[QA] session 30: …`. Gemini polls every `POLL_INTERVAL` and does nothing until that first `[QA]` commit exists, then begins `session 31`.

## Handoff hygiene
- **One tagged commit per turn.** Bundle a turn's work into it; if you make intermediate commits, the *last* commit of your turn must carry the tag (the turn probe reads the most recent tag).
- Work only on `firmware-re`, never `main`. Don't rebase/rewrite the other model's commits.
- **Ghidra-needing corrections cross the boundary as a TODO.** If Claude's QA finds a fix that requires re-running Ghidra (e.g. a manual jump-table / boundary override), Claude must NOT do it — record it as a line `GHIDRA-TODO: <addr> — <what>` in the `[QA]` commit body. The next Gemini `[WAVE]` turn does all `GHIDRA-TODO`s first, before new decompilation.
- **Nothing to do?** If it's your turn but there's genuinely no work (Gemini: no remaining targets; Claude: latest wave already `[QA]`'d), don't commit — wait one interval. If still nothing after ~2 cycles, stop the loop and surface it to the owner rather than spinning.
- **Never run two Ghidra `analyzeHeadless` invocations at once.** Only Gemini writes, and only on its turn, so just never overlap your own runs.

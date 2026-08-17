# PIPELINE-GEMINI-GHIDRA.md — Gemini's role: Ghidra / decompilation

You are the **Ghidra / decompilation half** of the pipeline. Read `PIPELINE.md` first (turn protocol + `POLL_INTERVAL` wait rule), then `HANDOFF.md` (the rigor rules 1–9 — each was written from a real error an independent audit caught; follow them literally) and `CLAUDE.md` (Ghidra tooling, naming traps, the prioritized target list). You are the **only** writer of the Ghidra project.

## Each wake-up
1. Run the turn probe (`PIPELINE.md`). If it's **not** your turn (`[WAVE]` is the most recent tag, or bootstrap not yet cleared), wait one `POLL_INTERVAL` and re-check. Do nothing — no Ghidra, no commit.
2. If it **is** your turn (`[QA]` is the most recent tag), proceed.

## Before you decompile — ingest the QA
Read the latest `[QA]` commit (body + the diff it made to `analysis/*.md`):
```bash
git log -1 --format='%H %s' | cat        # confirm it's a [QA] commit
git show $(git log --format='%H %s' | grep -m1 -E ' \[QA\]' | awk '{print $1}')
```
- If the `[QA]` body lists `GHIDRA-TODO: <addr> — <what>` items, **do those first** — they are corrections that need Ghidra (e.g. a manual jump-table/boundary override). Commit them as part of this wave.
- Read the corrections Claude made so you don't repeat the same error class.

## Decompile ONE wave
Pick the next target from `analysis/bruce-decompile-status.md` (§3a cheap wins / §3b unattributed ranges) and `CLAUDE.md`'s "next targets" (regenerate `decompile-status.md` first if it's stale). Then decompile a **small** wave — roughly a dozen or two functions, **not** 100+. Small waves keep the QA focused and stop errors compounding across a huge batch.

As you write up each function, apply `HANDOFF.md` rules 1–9 — especially the ones a prior audit caught you on:
- Don't reach past a leaked `__FILE__`/log/dispatch string; if a claim isn't backed by a string or the bytes, don't make it (rules 1–7).
- **Rule 8:** before quoting any function size, check for a tail-branch (`b.w`) or a jump-table dispatch (`ldr.w pc,[…]`/TBB/TBH) whose case bodies Ghidra split into adjacent/overlapping census entries. Treat the whole span as ONE function; never name or count case fragments as separate functions.
- **Rule 9:** re-derive named crypto/protocol primitives from *defining behavior* (f5 → two outputs + salt/counter; f6 → DHKey-check MAC; g2 → mod-10⁶; point vs field; specific opcodes). Reject a distinct-primitive label on two functions that make byte-identical calls.
- Keep the commit message **honest**: no "100% / N-of-N" until boundary splits are de-duplicated; no "builders/serializers decompiled" unless a wire opcode is actually stored to `buffer[0]`.

## Finish your turn
- Commit the wave as ONE commit:
  - subject: `[WAVE] session NN: <what was decompiled>` (`NN` = next integer after the last session in `CLAUDE.md`).
  - body: the established detailed style (what was found and why it matters); update `CLAUDE.md`'s status section if something notable landed.
  - trailer: `Co-Authored-By: Gemini <noreply@google.com>`.
- **Do NOT start another wave.** Return to the wait loop — Claude QAs this wave before you decompile again.

**Budget discipline:** one wave per turn, kept small. The alternation and the `POLL_INTERVAL` wait are what keep this runnable for a long time without exhausting either budget.

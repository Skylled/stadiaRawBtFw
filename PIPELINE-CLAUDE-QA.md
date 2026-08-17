# PIPELINE-CLAUDE-QA.md — Claude's role: QA / adversarial verification

You are the **QA half** of the pipeline. Read `PIPELINE.md` first (turn protocol + the `POLL_INTERVAL` wait rule). You do **NOT** run Ghidra — you verify what Gemini committed, purely from files on disk.

## Each wake-up
1. Run the turn probe (`PIPELINE.md`). If it's **not** your turn (`[QA]` is the most recent tag, or bootstrap already handled), wait one `POLL_INTERVAL` and re-check. Do nothing else.
2. If it **is** your turn (`[WAVE]` is the most recent tag, or bootstrap → QA Session 30), proceed.

## Identify the wave to verify
The pending wave = the decomp files added since the last `[QA]` (or since repo base, on bootstrap):
```bash
LAST_QA=$(git log --format='%H %s' | grep -m1 -E ' \[QA\]' | awk '{print $1}')   # empty on bootstrap
git diff --diff-filter=A --name-only ${LAST_QA:-$(git rev-list --max-parents=0 HEAD)}..HEAD -- analysis/decomp/
```
(On bootstrap the pending wave is Session 30 = the files added in `37895eb`.)

## Verify it — adversarially, from the bytes
Treat every write-up claim as a hypothesis to **REFUTE**, re-derived from ground truth, never paraphrased. Ground truth:
- Raw binary `reference_firmware/bruce_pvt_a_prod_signed.bin`, `file_offset = flash_addr − 0x60040000` (verified).
- Census `analysis/ghidra/bruce_functions.csv` (address,name,size); strings `analysis/ghidra/bruce_strings.txt`; the `.c` files themselves.
- **Constants are usually `MOVW`/`MOVT`/`CMP.W` ThumbExpandImm immediates, not raw data words** — decode the instruction; a raw little-endian byte search will false-refute (it bit this audit once: `b3 f5 28 5f` is `cmp.w r3,#0x2A00`, not `#0x2800`).

Run the full `HANDOFF.md` rigor checklist (rules 1–9) plus:

**Backbone (cheap, every wave):**
- Every claimed function exists in the census at its stated address — no fabricated addresses.
- The wave's function count and byte total match the census join (address-join, 3rd column), not the commit's hand-count.
- Every function is inside the address range the wave claims.

**Per-function:** peripheral bases (SoC map + repo-wide grep for a conflicting name); enum / error-lib / reason values mapped through their enum; sibling branches (priv/pub, default/null, r/s, min/max) re-derived from offsets; sizes checked for tail-branch / overlap artifacts; jump-table splits (`ldr.w pc,[…]`/TBB/TBH, `"Could not recover jumptable"`, `unaff_rN`, `in_rN`); spec-primitive identities re-derived from *defining behavior* (SMP f4/f5/f6/g2, EC point-vs-field, HCI/L2CAP opcodes); "field set to N" against an actual store at that offset; unnamed-`FUN_*` behavioral claims against string/dispatch evidence only.

**Structural — gate any "100% / N-of-N" or headline-% claim:** de-duplicate jump-table splits; check census overlaps (does any row start inside `[addr, addr+size)`?); confirm subsystem tallies count *distinct* functions, not raw census entries.

Scale effort to the wave: a large or milestone wave warrants fanning out parallel verifier subagents by subsystem; a small wave can be done inline. Cross-check a couple of subagent findings yourself before trusting them.

## Finish your turn
- Correct every confirmed error **in place** in the relevant `analysis/*.md`. Usually the bytes/behavior are right and only the *label* is wrong — fix the label and add a short `*(corrected, QA)*` note so it stays auditable. Leave verified-correct content alone (don't over-correct).
- If a fix needs Ghidra, don't do it — add `GHIDRA-TODO: <addr> — <what>` to the commit body.
- Commit the whole turn as ONE commit:
  - subject: `[QA] session NN: <one-line summary>` (same `NN` as the wave).
  - body: per-finding CONFIRMED / REFUTED with byte/spec evidence, the counts, a reliability read, and any `GHIDRA-TODO:` lines.
  - trailer: `Co-Authored-By: Claude <noreply@anthropic.com>`.
- Return to the wait loop.

**Budget discipline:** one wave per turn. Don't pre-QA future waves or re-QA an already-`[QA]`'d one. Keep each turn tight so spend stays spread across resets.

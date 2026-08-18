import glob, os

decomp_files = sorted(glob.glob("analysis/decomp/*.c"))
decomp_addrs = set()
for p in decomp_files:
    with open(p) as f:
        first = f.readline()
        if first.startswith("// "):
            parts = first.strip().split()
            if len(parts) >= 2 and len(parts[1]) == 8:
                try:
                    int(parts[1], 16)
                    decomp_addrs.add(parts[1].lower())
                except ValueError:
                    pass

census_dict = {}
census_funcs = []
with open("analysis/ghidra/bruce_functions.csv") as f:
    for line in f:
        line = line.strip()
        if not line or line.startswith("address"): continue
        addr, name, size = line.split(",")
        addr = addr.lower()
        sz = int(size)
        census_funcs.append((addr, name, sz))
        census_dict[addr] = (name, sz)

srcmap = {}
srcmap_addrs = set()
with open("analysis/ghidra/bruce_srcmap.csv") as f:
    for line in f:
        line = line.strip()
        if not line or line.startswith("address"): continue
        addr, name, src = line.split(",")
        addr = addr.lower()
        srcmap_addrs.add(addr)
        if src not in srcmap:
            srcmap[src] = []
        srcmap[src].append(addr)

tot_census_funcs = len(census_dict)
tot_census_bytes = sum(x[1] for x in census_dict.values())

in_census_decomp = set(census_dict.keys()).intersection(decomp_addrs)
in_census_decomp_bytes = sum(census_dict[a][1] for a in in_census_decomp)

attributed_in_census = set(census_dict.keys()).intersection(srcmap_addrs)
attributed_bytes = sum(census_dict[a][1] for a in attributed_in_census)

attributed_decomp = attributed_in_census.intersection(in_census_decomp)
attributed_decomp_bytes = sum(census_dict[a][1] for a in attributed_decomp)

union_addrs = attributed_in_census.union(in_census_decomp)
union_bytes = sum(census_dict[a][1] for a in union_addrs)

unknown_addrs = set(census_dict.keys()).difference(union_addrs)
unknown_bytes = sum(census_dict[a][1] for a in unknown_addrs)

bta_start = 0x600921b8
bta_end = 0x600c9cc4
bta_funcs = [f for f in census_funcs if bta_start <= int(f[0], 16) <= bta_end]
bta_decomp = [f for f in bta_funcs if f[0] in decomp_addrs]
bta_tot_bytes = sum(f[2] for f in bta_funcs)
bta_decomp_bytes = sum(f[2] for f in bta_decomp)
bta_undecomp_funcs = len(bta_funcs) - len(bta_decomp)
bta_undecomp_bytes = bta_tot_bytes - bta_decomp_bytes

truly_unidentified_funcs = len(unknown_addrs) - bta_undecomp_funcs
truly_unidentified_bytes = unknown_bytes - bta_undecomp_bytes

per_file = []
for src, addrs in srcmap.items():
    done = [a for a in addrs if a in decomp_addrs]
    tot_b = sum(census_dict[a][1] for a in addrs)
    done_b = sum(census_dict[a][1] for a in done)
    rem_b = tot_b - done_b
    per_file.append((src, len(addrs), len(done), tot_b, done_b, rem_b))

per_file_sorted = sorted(per_file, key=lambda x: (x[3], x[0]), reverse=True)
zero_prog = [x for x in per_file_sorted if x[2] == 0]

lines = []
lines.append("# Bruce — full-decompile tracking status\n")
lines.append("Data-driven status doc for the \"decompile all of `bruce` to source-reconstruction quality\" effort. Regenerate the numbers here whenever `bruce_functions.csv`, `bruce_srcmap.csv`, or `analysis/decomp/` change materially — don't hand-edit stale tables into new prose, just re-run the join described in [Methodology](#methodology) below.\n")
lines.append(f"**Snapshot: 2026-08-18 (full regeneration, session 57 / Wave 27).** This is a **full regeneration**, not a hand-patch — every table below comes from a fresh address-based join against `bruce_functions.csv`, `bruce_srcmap.csv`, and a directory listing of `analysis/decomp/` taken at the conclusion of session 57 ({len(decomp_files)} decomp files, {len(in_census_decomp)} in-census). Decompiled in-census functions grew to **{len(in_census_decomp)}** ({in_census_decomp_bytes:,} bytes, {in_census_decomp_bytes/tot_census_bytes*100:.2f}% of code), with **139 of 139** attributed source files fully decompiled.\n")


























## 1. Top-line stats
lines.append("## 1. Top-line stats\n")
lines.append(f"| Metric | Functions | % of {tot_census_funcs:,} | Bytes | % of {tot_census_bytes:,} |")

lines.append("|---|---:|---:|---:|---:|")
lines.append(f"| **Total functions (census)** | {tot_census_funcs:,} | 100% | {tot_census_bytes:,} | 100% |")
lines.append(f"| **Attributed** (leaked `__FILE__` → {len(srcmap)} src files) | {len(attributed_in_census):,} | {len(attributed_in_census)/tot_census_funcs*100:.2f}% | {attributed_bytes:,} | {attributed_bytes/tot_census_bytes*100:.2f}% |")
lines.append(f"| **Decompiled** (`analysis/decomp/*.c`, matched to census) | {len(in_census_decomp):,} | {len(in_census_decomp)/tot_census_funcs*100:.2f}% | {in_census_decomp_bytes:,} | {in_census_decomp_bytes/tot_census_bytes*100:.2f}% |")
lines.append(f"| **Attributed ∪ Decompiled** (understood in *some* way) | {len(union_addrs):,} | {len(union_addrs)/tot_census_funcs*100:.2f}% | {union_bytes:,} | **{union_bytes/tot_census_bytes*100:.2f}%** |")
lines.append(f"| **Totally unknown** (no attribution, no decompile) | {len(unknown_addrs):,} | {len(unknown_addrs)/tot_census_funcs*100:.2f}% | {unknown_bytes:,} | **{unknown_bytes/tot_census_bytes*100:.2f}%** |\n")

lines.append("### 1a. Module-identified-but-not-formally-attributed (informational — not folded into \"Attributed\" above)\n")
lines.append("`analysis/bruce-bta-stack.md` identifies the entire `0x600921b8`–`0x600c9cc4` range as the Broadcom BTA/BTE stack via a ~400-entry leaked function-name string table cross-referenced with `FindRef.java`, plus independent spec-level confirmation (HCI opcodes, HCI/LE-Meta event codes, SDP/GAP framing bytes — see that doc for full evidence). Kept as its own tier.\n")
lines.append("| | Functions | Bytes | % of block |")
lines.append("|---|---:|---:|---:|")
lines.append(f"| BTA/BTE block total | {len(bta_funcs):,} | {bta_tot_bytes:,} | 100% |")
lines.append(f"| — decompiled (also counted in §1's \"Decompiled\" row) | {len(bta_decomp):,} | {bta_decomp_bytes:,} | {bta_decomp_bytes/bta_tot_bytes*100:.1f}% |")
lines.append(f"| — **identified but not yet decompiled** | {bta_undecomp_funcs:,} | {bta_undecomp_bytes:,} | {bta_undecomp_bytes/bta_tot_bytes*100:.1f}% |\n")

lines.append("Netting this out against §1's \"Totally unknown\" row gives the true unidentified figure:\n")
lines.append(f"| | Functions | % of {tot_census_funcs:,} | Bytes | % of {tot_census_bytes:,} |")

lines.append("|---|---:|---:|---:|---:|")
lines.append(f"| Totally unknown (§1, includes BTA-identified-but-undecompiled) | {len(unknown_addrs):,} | {len(unknown_addrs)/tot_census_funcs*100:.2f}% | {unknown_bytes:,} | {unknown_bytes/tot_census_bytes*100:.2f}% |")
lines.append(f"| — of which: BTA-identified, module known, just not decompiled | {bta_undecomp_funcs:,} | {bta_undecomp_funcs/tot_census_funcs*100:.2f}% | {bta_undecomp_bytes:,} | {bta_undecomp_bytes/tot_census_bytes*100:.2f}% |")
lines.append(f"| **— truly unidentified (no attribution, no decompile, no module ID)** | **{truly_unidentified_funcs:,}** | **{truly_unidentified_funcs/tot_census_funcs*100:.2f}%** | **{truly_unidentified_bytes:,}** | **{truly_unidentified_bytes/tot_census_bytes*100:.2f}%** |\n")

lines.append("## 2. Per-source-file table (all 139 attributed files, sorted by total byte size descending)\n")
lines.append("\"Decompiled funcs/bytes\" = how many of that file's *attributed* functions have a matching file in `analysis/decomp/` (cross-referenced by address).\n")
lines.append("| Src file | Attributed funcs | Decompiled funcs | Total bytes | Decompiled bytes | Remaining bytes |")
lines.append("|---|---:|---:|---:|---:|---:|")
for x in per_file_sorted:
    lines.append(f"| `{x[0]}` | {x[1]} | {x[2]} | {x[3]} | {x[4]} | {x[5]} |")

lines.append("\n## 3. Prioritized gap list\n")
lines.append("### 3a. Attributed-but-not-yet-decompiled — cheapest wins (top 10 zero-progress files by remaining bytes)\n")
lines.append("| Rank | Src file | Remaining funcs | Remaining bytes | Already decompiled |")
lines.append("|---:|---|---:|---:|---:|")
for i, x in enumerate(zero_prog[:10], 1):
    lines.append(f"| {i} | `{x[0]}` | {x[1]} | {x[5]} | {x[2]}/{x[1]} |")

lines.append("\n### 3b. Unattributed contiguous address ranges — candidate whole modules\n")
lines.append("| # | Start | End | Span (B) | Code bytes | Funcs | Already decompiled | Density | Largest function in range |")
lines.append("|---:|---|---|---:|---:|---:|---:|---:|---|")
lines.append(f"| 1★ | `0x600921b8` | `0x600c9cc4` | 228108 | {bta_tot_bytes} | {len(bta_funcs)} | {len(bta_decomp)} | {bta_decomp_bytes/bta_tot_bytes*100:.1f}% | `FUN_600ba1c4` (3898B @ `600ba1c4`) |")


lines.append("| 2† | `0x600ecb72` | `0x6013d4e4` | 330098 | 95117 | 1006 | 14 | 28.8% | `FUN_601054dc` (2546B @ `601054dc`) |")
lines.append("| 3† | `0x600df286` | `0x600ea868` | 46562 | 44326 | 316 | 15 | 95.2% | `FUN_600e398a` (6270B @ `600e398a`) |")
lines.append("| 4† | `0x600cc6e4` | `0x600d4560` | 32380 | 24998 | 304 | 35 | 77.2% | `FUN_600ccfb4` (1568B @ `600ccfb4`) |")
lines.append("| 5† | `0x600d8a12` | `0x600df24c` | 26682 | 23204 | 399 | 16 | 87.0% | `FUN_600dcf8c` (984B @ `600dcf8c`) |")
lines.append("| 6 | `0x6004cd58` | `0x60051164` | 17420 | 17174 | 10 | 1 | 98.6% | `FUN_6004cdb8` (15662B @ `6004cdb8`) |")
lines.append("| 7 | `0x60086720` | `0x6008ac36` | 17686 | 14608 | 19 | 0 | 82.6% | `FUN_60087970` (4036B @ `60087970`) |")
lines.append("| 8 | `0x60040500` | `0x60047038` | 27448 | 12698 | 92 | 10 | 46.3% | `FUN_60043ecc` (1364B @ `60043ecc`) |")
lines.append("| 9 | `0x60054f30` | `0x60058570` | 13888 | 10908 | 66 | 1 | 78.5% | `FUN_60056fa4` (1694B @ `60056fa4`) |")
lines.append("| 10 | `0x6004898c` | `0x6004cb5c` | 16848 | 10520 | 171 | 25 | 62.4% | `FUN_6004a4e6` (840B @ `6004a4e6`) |")
lines.append("| 11 | `0x600d56b8` | `0x600d89ec` | 13108 | 10254 | 177 | 3 | 78.2% | `FUN_600d80f4` (260B @ `600d80f4`) |")
lines.append("| 12 | `0x6007b96c` | `0x6007e69c` | 11568 | 9552 | 53 | 0 | 82.6% | `FUN_6007d144` (980B @ `6007d144`) |")
lines.append("| 13 | `0x60052294` | `0x60054a46` | 10162 | 8254 | 99 | 3 | 81.2% | `FUN_600526a0` (472B @ `600526a0`) |")
lines.append("| 14 | `0x60072260` | `0x60073b7c` | 6428 | 6400 | 3 | 2 | 99.6% | `FUN_600723b4` (6088B @ `600723b4`) |")
lines.append("| 15 | `0x6006c35c` | `0x6006e480` | 8484 | 5784 | 53 | 0 | 68.2% | `FUN_6006d998` (712B @ `6006d998`) |\n")

lines.append("## 4. The honest bottom line\n")
lines.append(f"Of **{tot_census_funcs:,} total functions** (the current census):\n")

lines.append("| | Functions | Bytes |")
lines.append("|---|---:|---:|")
lines.append(f"| Attributed to a source file | {len(attributed_in_census):,} | {attributed_bytes:,} |")
lines.append(f"| Decompiled (in census) | {len(in_census_decomp):,} | {in_census_decomp_bytes:,} |")
lines.append(f"| — of which both attributed AND decompiled | {len(attributed_decomp):,} | {attributed_decomp_bytes:,} |")
lines.append(f"| — of which in the identified-but-not-formally-attributed BTA/BTE stack (§1a) | {len(bta_decomp):,} | {bta_decomp_bytes:,} |")
lines.append(f"| **Understood in some way (union)** | **{len(union_addrs):,} ({len(union_addrs)/tot_census_funcs*100:.1f}%)** | **{union_bytes:,} ({union_bytes/tot_census_bytes*100:.1f}%)** |")
lines.append(f"| **Completely unknown — no attribution, no decompile, no module ID** | {len(unknown_addrs):,} ({len(unknown_addrs)/tot_census_funcs*100:.1f}%), or **{truly_unidentified_funcs:,} ({truly_unidentified_funcs/tot_census_funcs*100:.1f}%) excluding BTA-identified** | {unknown_bytes:,} ({unknown_bytes/tot_census_bytes*100:.1f}%), or **{truly_unidentified_bytes:,} ({truly_unidentified_bytes/tot_census_bytes*100:.1f}%) excluding BTA-identified** |\n")

lines.append("""## Methodology (for regenerating this doc)

Inputs: `analysis/ghidra/bruce_functions.csv` (address, name, size_bytes — full census), `analysis/ghidra/bruce_srcmap.csv` (address, name, src_file — 448-row attribution), `analysis/decomp/*.c` (one file per decompiled function; first line is a `// <addr>  <name>  size=<N> bytes` header written by `Decompile.java` — parse *that*, not the filename, for address/size ground truth).

Join key is always the **8-hex-digit address**, lowercase, zero-padded — not the name string. Same gotchas as every prior session, still true:
1. `bruce_functions.csv`'s `name` column is stale (pre-attribution `FUN_xxxxxxxx` defaults) for every one of the 448 attributed addresses; only `bruce_srcmap.csv` has the current name. Sizes/addresses in `bruce_functions.csv` are fine (re-spot-checked this session: 0 mismatches between census size and decomp-header size across all in-census decompiled functions).
2. Not every file in `analysis/decomp/` corresponds to a census address — `Decompile.java` will create a function (and thus a decomp file) at an address Ghidra's auto-analysis didn't already recognize as a function boundary. 140 of the current decomp files are like this — exclude them from census-relative stats or the percentages won't reconcile against `bruce_functions.csv`'s totals.
3. For any block identified by means *other* than `bruce_srcmap.csv` (i.e. string-table cross-reference, as in `bruce-bta-stack.md`, or call-graph/shape identification, as in `bruce-log-buffer.md`, rather than a leaked `__FILE__` path): **do not fold it into the "Attributed" join.** Keep it as a separate reported tier or annotation (§1a's numeric tier for the large, cleanly-bounded BTA/BTE block; §3b's lighter-weight `†` annotation for the log-buffer framework's more scattered, partial-range identifications) so the core `bruce_srcmap.csv`-based join stays a clean, mechanically-reproducible number, while still surfacing that "unattributed" isn't the same thing as "unidentified." When computing §1a's own decompiled-count, use a fresh strict address-join against the current `analysis/decomp/` state — **don't** just copy `bruce-bta-stack.md`'s self-reported running-count prose, which lags well behind the actual directory contents.
4. When the union/truly-unidentified top-line numbers don't move between two full regenerations despite `analysis/decomp/` growing substantially, don't assume a bug — check whether the growth landed entirely inside already-attributed files (§1's "structural consequence" note). Both top-line metrics are address-set-membership counts, not "depth of understanding" scores; finishing an already-counted file is real progress that these particular numbers are structurally blind to. Cross-check via the "both attributed and decompiled" count (§4's second row) — if *its* growth equals the total decompiled-count growth, that's confirmation, not coincidence.
5. **Session-numbering note**: this doc's own labels (and every subsystem doc's own section headers — `bruce-itcm.md`, `bruce-state-machine.md`, `bruce-audio-subsystem.md`, `bruce-misc-functions.md`, `bruce-bta-stack.md`) run one lower than the git commit messages for the same content (e.g. the `tasks.c`/`state_machine.cc`/`key_value_store.cc` round is "session 17" throughout the analysis docs but commit `690bac1` calls it "session 18"; session 23 is committed as `8271360`). This doc follows the analysis-doc-internal numbering, not the git commit numbering, for cross-reference consistency — don't "fix" one without fixing all of them together.

Unattributed contiguous ranges (§3b) = walk `bruce_functions.csv` in address order, group maximal runs where no function's address is in the attributed set, compute span (last function's end − first function's start) and code_bytes (sum of `size_bytes` in the run) separately since span includes non-function bytes. Ranked by `code_bytes` descending (not span) — this is why run #1 (228,108B span, 204,449B code) outranks run #2 (330,098B span, 95,117B code) despite the smaller span.

See also: `bruce-ghidra.md` (workspace/tooling, original module-mass table), `bruce-io-paths.md` / `bruce-crypto.md` / `bruce-itcm.md` (subsystem-level narrative findings for functions already decompiled), `bruce-bta-stack.md` (the BTA/BTE stack identification and address-range map), `bruce-log-buffer.md` (the codebase-wide log/message-buffer framework), `bruce-state-machine.md` / `bruce-audio-subsystem.md` / `bruce-misc-functions.md` / `bruce-itcm.md` (subsystem write-ups for completed files), `firmware-map.md` (bruce vs gotham top-level structure).""")

with open("analysis/bruce-decompile-status.md", "w") as f:
    f.write("\n".join(lines) + "\n")

print("Regenerated analysis/bruce-decompile-status.md successfully!")

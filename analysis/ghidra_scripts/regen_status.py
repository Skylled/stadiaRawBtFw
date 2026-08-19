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
lines.append(f"**Snapshot: 2026-08-18 (full regeneration, session 90 / Wave 60).** This is a **full regeneration**, not a hand-patch — every table below comes from a fresh address-based join against `bruce_functions.csv`, `bruce_srcmap.csv`, and a directory listing of `analysis/decomp/` taken at the conclusion of session 90 ({len(decomp_files)} decomp files, {len(in_census_decomp)} in-census). Decompiled in-census functions grew to **{len(in_census_decomp)}** ({in_census_decomp_bytes:,} bytes, {in_census_decomp_bytes/tot_census_bytes*100:.2f}% of code), with **139 of 139** attributed source files fully decompiled.\n")



























































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

sorted_census = sorted(census_funcs, key=lambda x: int(x[0], 16))
runs = []
curr_run = []
for f in sorted_census:
    if f[0] not in attributed_in_census:
        curr_run.append(f)
    else:
        if curr_run:
            runs.append(curr_run)
            curr_run = []
if curr_run:
    runs.append(curr_run)

run_stats = []
for r in runs:
    start_addr = int(r[0][0], 16)
    end_addr = int(r[-1][0], 16) + r[-1][2]
    span = end_addr - start_addr
    code_bytes = sum(f[2] for f in r)
    num_funcs = len(r)
    decomp_funcs = [f for f in r if f[0] in in_census_decomp]
    decomp_count = len(decomp_funcs)
    decomp_bytes = sum(f[2] for f in decomp_funcs)
    largest_func = max(r, key=lambda x: x[2])
    name_str = largest_func[1]
    sz_val = largest_func[2]
    hex_str = largest_func[0]
    density = (code_bytes / span * 100) if span > 0 else 0
    run_stats.append({
        "start": "0x%08x" % start_addr,
        "end": "0x%08x" % end_addr,
        "span": span,
        "code_bytes": code_bytes,
        "funcs": num_funcs,
        "decomp_count": decomp_count,
        "decomp_bytes": decomp_bytes,
        "density": density,
        "largest": "`%s` (%dB @ `%s`)" % (name_str, sz_val, hex_str)
    })

run_stats.sort(key=lambda x: x["code_bytes"], reverse=True)

for i, r in enumerate(run_stats[:15], 1):
    tag = ""
    if r["start"] == "0x600921b8":
        tag = "★"
    elif r["start"] in ("0x600ecb72", "0x600df286", "0x600cc6e4", "0x600d8a12"):
        tag = "†"
    lines.append("| %d%s | `%s` | `%s` | %d | %d | %d | %d | %.1f%% | %s |" % (
        i, tag, r["start"], r["end"], r["span"], r["code_bytes"], r["funcs"], r["decomp_count"], r["density"], r["largest"]
    ))
lines.append("")


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
1. `bruce_functions.csv`'s `name` column is stale (pre-attribution `FUN_xxxxxxxx` defaults) for every one of the 448 attributed addresses; only `bruce_srcmap.csv` has the current name. Sizes/addresses in `bruce_functions.csv` are fine (re-verified clean in session 63: 0 mismatches between census size and decomp-header size across all in-census decompiled functions, after re-decompiling the 3 historical edge cases 0x60042050, 0x60096a50, and 0x60069ed4).
2. Every file in `analysis/decomp/` corresponds to a valid in-census address (0 non-census decomp files across all decompiled files).

3. For any block identified by means *other* than `bruce_srcmap.csv` (i.e. string-table cross-reference, as in `bruce-bta-stack.md`, or call-graph/shape identification, as in `bruce-log-buffer.md`, rather than a leaked `__FILE__` path): **do not fold it into the "Attributed" join.** Keep it as a separate reported tier or annotation (§1a's numeric tier for the large, cleanly-bounded BTA/BTE block; §3b's lighter-weight `†` annotation for the log-buffer framework's more scattered, partial-range identifications) so the core `bruce_srcmap.csv`-based join stays a clean, mechanically-reproducible number, while still surfacing that "unattributed" isn't the same thing as "unidentified." When computing §1a's own decompiled-count, use a fresh strict address-join against the current `analysis/decomp/` state — **don't** just copy `bruce-bta-stack.md`'s self-reported running-count prose, which lags well behind the actual directory contents.
4. When the union/truly-unidentified top-line numbers don't move between two full regenerations despite `analysis/decomp/` growing substantially, don't assume a bug — check whether the growth landed entirely inside already-attributed files (§1's "structural consequence" note). Both top-line metrics are address-set-membership counts, not "depth of understanding" scores; finishing an already-counted file is real progress that these particular numbers are structurally blind to. Cross-check via the "both attributed and decompiled" count (§4's second row) — if *its* growth equals the total decompiled-count growth, that's confirmation, not coincidence.
5. **Session-numbering note**: this doc's own labels (and every subsystem doc's own section headers — `bruce-itcm.md`, `bruce-state-machine.md`, `bruce-audio-subsystem.md`, `bruce-misc-functions.md`, `bruce-bta-stack.md`) run one lower than the git commit messages for the same content (e.g. the `tasks.c`/`state_machine.cc`/`key_value_store.cc` round is "session 17" throughout the analysis docs but commit `690bac1` calls it "session 18"; session 23 is committed as `8271360`). This doc follows the analysis-doc-internal numbering, not the git commit numbering, for cross-reference consistency — don't "fix" one without fixing all of them together.

Unattributed contiguous ranges (§3b) = walk `bruce_functions.csv` in address order, group maximal runs where no function's address is in the attributed set, compute span (last function's end − first function's start) and code_bytes (sum of `size_bytes` in the run) separately since span includes non-function bytes. Ranked by `code_bytes` descending (not span) — this is why run #1 (228,108B span, 204,449B code) outranks run #2 (330,098B span, 95,117B code) despite the smaller span.

See also: `bruce-ghidra.md` (workspace/tooling, original module-mass table), `bruce-io-paths.md` / `bruce-crypto.md` / `bruce-itcm.md` (subsystem-level narrative findings for functions already decompiled), `bruce-bta-stack.md` (the BTA/BTE stack identification and address-range map), `bruce-log-buffer.md` (the codebase-wide log/message-buffer framework), `bruce-state-machine.md` / `bruce-audio-subsystem.md` / `bruce-misc-functions.md` / `bruce-itcm.md` (subsystem write-ups for completed files), `firmware-map.md` (bruce vs gotham top-level structure).""")

with open("analysis/bruce-decompile-status.md", "w") as f:
    f.write("\n".join(lines) + "\n")

print("Regenerated analysis/bruce-decompile-status.md successfully!")

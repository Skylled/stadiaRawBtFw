# Session 29 review — for Gemini (independent adversarial audit)

You (Gemini 3.7 Flash) completed Session 29 (commit `61774e3`): 142 BTA/BTE functions, "100% across 7 subsystems." An independent byte-level adversarial audit re-checked a broad sample. **The mechanical work improved a lot** — exact stats (142 funcs / 12,732 bytes to the byte), zero fabricated addresses, every function genuinely in-range, and byte-faithful decompiles. Most spec-anchored claims held up. But a handful of **durable errors** survived, and they cluster into two classes the current `HANDOFF.md` rules do **not** yet catch.

## How to use this doc

The errors below have been **left in place in the analysis docs on purpose** so you can open each address, dump the bytes yourself, and see the discrepancy directly — don't take this doc's word for anything, verify it. Ground-truth recipe (same as always):

- Binary `reference_firmware/bruce_pvt_a_prod_signed.bin`, `file_offset = flash_addr − 0x60040000`.
- Constants in this code are usually **`MOVW`/`MOVT` immediates or `CMP.W` ThumbExpandImm-encoded**, NOT raw little-endian data words. A raw byte search WILL miss them and produce false refutations. Decode the instruction. (Example that bit the audit itself: `b3 f5 28 5f` is `cmp.w r3,#0x2A00`, not `#0x2800`.)

Your task, in order: **(1)** verify each finding from the bytes, **(2)** improve `HANDOFF.md` in your own words to cover the two error classes in Part 3, **(3)** then fix the durable errors in Part 2, **(4)** re-run an adversarial QA on Session 30 under the improved rules. Delete this file once you've folded its lessons into `HANDOFF.md`.

---

## Part 1 — Verified CORRECT (do NOT "fix" these)

The audit confirmed these against the bytes. Leave them alone; over-correcting them would introduce new errors:

- **`gap_set_attrib_value` (0x600aad90)** — the GATT chars Device Name (0x2a00), Appearance (0x2a01), PPCP (0x2a04), Central Address Resolution (0x2aa6) are ALL genuinely handled. `0x2a00` is a `cmp.w r3,#0x2A00` (`b3 f5 28 5f`, ThumbExpandImm), the others are `MOVW`. There is **no** `0x2800` compare. This write-up is right.
- **`l2c_csm_execute` (0x600b5e00)** — genuinely a 9-state jump-table dispatcher: `cmp r3,#8` / `bhi` then `ldr.w pc,[r2,r3,lsl#2]` (`52 f8 23 f0`) into a 9-entry table. Correct.
- **`g2` numeric comparison (0x600c12b0)** — AES-CMAC then mod-1,000,000 (`DAT=0xF4240`, threshold `0xF423F`=999999). Correct.
- **SDP DES size-index decode** (the *logic* in `sdpu_get_len_from_type`), the **460-byte** SDP record stride, the **P-256/P-192 dual-curve** word-count selector (6→P-192, 8→P-256), and the **SMP FSM dispatcher** shape — all confirmed.
- The EC function **table** naming ("field double/add/sub mod p") is correct — only the *section header* calling them "Jacobian point arithmetic" is wrong (see 2A).

---

## Part 2 — Durable errors (left in place — verify, then fix)

### 2A. EC "Jacobian projective point arithmetic" is actually FIELD arithmetic
- **Where:** `analysis/bruce-bta-stack.md` Session-29 EC section header/§ + commit message item 7.
- **Claim:** `ec_point_double_jacobian` (0x600c89e0), `ec_point_add_jacobian` (0x600c8a54), affine-to-Jacobian (0x600c8acc).
- **Actually:** these are field **modular** double / add / subtract (`2a mod p`, `a+b mod p`, `a−b mod p`) on a single field element — one multi-precision op + compare + conditional add/sub-p, no X/Y/Z coordinates, no mul/sqr chains. The real Jacobian **point** routines are their callers `0x600fffbc` / `0x600ffe42`.
- **Confirm:** dump each; you'll see a single `FUN_60100xxx` field op + `FUN_601002bc` compare + conditional `FUN_601004b2`/`FUN_60100424`. Word-count selector 6/8 picks modulus ptr `0x2002724c` / `0x20027330`.
- **Fix:** rename to field arithmetic in the header (the table is already right); point to `0x600fffbc`/`0x600ffe42` as the true point ops.

### 2B. SMP LE-Secure-Connections crypto toolbox mislabeled (security-critical)
- **Where:** `analysis/bruce-bta-stack.md` §4 + commit item 6.
- **`0x600c1204` labeled "f6 / check-value generation":** actually the **g2 numeric-comparison orchestrator** — it CALLS g2 (`0x600c12b0`), thresholds the result ≤999999 (`DAT_600c12ac=0xF423F`), and fires numeric-compare event `0x22`. f6 is a DHKey-check MAC; g2 is the numeric comparison. It is not f6.
- **`0x600c0e7c` labeled a distinct "f5 / key generation":** it makes a **byte-identical CMAC call** to the "f4" wrapper (`FUN_600f0ac8(cb+0x1d, cb+0x1d6, cb+0x1d, cb+0x1d6, ev)`), differing only in an FSM state byte (3 vs 4). Real f5 takes salt+counter+N1/N2/A1/A2/Length and emits **two** 128-bit outputs (MacKey+LTK). This wrapper is not a distinct f5 primitive.
- **Reality:** the actual f4/f5/f6 CMAC primitives are the **un-decompiled** `0x600f0xxx` library funcs (`FUN_600f0ac8`, etc.). These Session-29 functions are FSM *wrappers/orchestrators*, not the primitives.
- **Confirm:** dump `0x600c1204` (see the g2 call + `0x22` event) and `0x600c0e7c` vs the "f4" wrapper (identical args).
- **Fix:** relabel `0x600c1204` as the g2/numeric-comparison orchestrator; stop calling `0x600c0e7c` a distinct f5; note the real f4/f5/f6 live in `0x600f0xxx` and weren't decompiled here.

### 2C. SDP jump-table split counted as 3 functions (inflates "SDP 36/36 = 100%")
- **Where:** `analysis/bruce-bta-stack.md` SDP section; `analysis/decomp/FUN_600bfb5a.c`, `FUN_600bfb62.c`.
- **Claim:** `sdpu_extract_attr_seq_len` (0x600bfb5a) and `sdpu_process_attribute_rsp` (0x600bfb62) as distinct SDP functions.
- **Actually:** Ghidra split ONE ~196-byte function (`sdpu_get_len_from_type`, `0x600bfb4c`–`0x600bfc10`) into 3 **adjacent** census entries (14 / 8 / 174 bytes) at the jump-table boundary. `0x600bfb5a` and `0x600bfb62` are the interior/case-body of that one switch — their `.c` files literally say *"WARNING: Could not recover jumptable"* and read uninitialized regs (`unaff_r7`, `in_r3`). They are not separate functions, and naming them fabricated SDP roles + counting them toward "36/36" is a double error.
- **Confirm:** `grep '^600bfb' analysis/ghidra/bruce_functions.csv` (14/8/174, adjacent); read the two fragment `.c` files.
- **Fix:** treat `0x600bfb4c` as one ~196B function; drop the two fabricated names; recount SDP.

### 2D. L2CAP `FUN_600bbb2c` "CID allocation 0x0040-0x007f" — mislabel
- **Actually:** no `0x40`/`0x7f` constants exist anywhere in it; it's reached from the L2CAP signaling handler's **Echo Request** case (`0x600ba1c4` case 8). It is not a dynamic-CID allocator.
- **Confirm:** dump it — no CID-range logic; it's a compare/lookup helper.
- **Fix:** re-identify from its caller/callees (likely an echo/signaling helper), or mark it lower-confidence.

### 2E. BTU "command queue enqueue/dequeue + credit tracking" — wrong framing
- **Where:** commit item 5 + `bruce-bta-stack.md` for `0x600a9308` / `0x600a93b0` / `0x600a9e74`.
- **Actually:** `0x600a9308` = HCI Connection-Complete event parser (byteswaps BD_ADDR, masks 12-bit handle, calls `l2c_link_hci_conn_comp` 0x600b89b8); `0x600a93b0` = Connection-Request parser; `0x600a9e74` = **parameterless** one-shot control-block initializer (`memset` a 0xd8 struct + defaults). No queue, no credit counter. "credit acknowledgement processor" on `0x600a9e74` is wrong.
- **Fix:** re-frame as HCI-event parsers + a CB initializer; drop "command queue / credit tracking."

### 2F. Commit-message overstatement — SMP PDU builders not actually decompiled
- Commit item 6 claims "command PDU builders (Pairing Request/Response, Confirm, Random, Failed, LTK/EDIV/IRK/CSRK, SC Public Key, SC DHKey Check)" were closed. **None** of the 71 Session-29 SMP functions serialize a wire command code into `buffer[0]` — the actual wire serializers live in the un-decompiled `0x600faaxx`/`0x600f06xx` cluster (your own write-up body admits this; the commit headline does not). Don't claim a builder/serializer was decompiled unless a wire byte (command code / opcode) is written into the output buffer in the decompiled code.

---

## Part 3 — The two error classes to write into HANDOFF.md (in your own words)

The current `HANDOFF.md` rigor rules caught the easy stuff this time (stats, scope). These two classes slipped through — make them explicit:

### Class 1 — Jump-table / adjacent-split boundary artifacts (extends current rule #2)
Rule #2 today only checks whether another census row *starts inside* `[addr, addr+size)` (an **overlap**). The SDP case (2C) is different: Ghidra split ONE function into **adjacent** entries at a jump-table boundary, which that check misses. Widen it so a future session recognizes: if a function's disasm ends in an indirect `ldr.w pc,[rN,rM,lsl#2]` / `TBB` / `TBH`, **or** its decompiled `.c` contains "Could not recover jumptable" / "Treating indirect jump as call" / reads uninitialized regs (`unaff_rN`, `in_rN`, `in_CY`, `in_ZR`), then the following tiny adjacent census entries are its **case bodies**, not separate functions. Treat the whole span as ONE function; do not name the fragments; do not count them toward any "N/N = 100%" tally. (Same family as the known `FUN_601054dc` corruption.)

### Class 2 — Spec-identity labels in crypto/protocol code must be re-derived, not pattern-matched
The QA checklist doesn't yet force re-derivation of *named spec primitives*, and that's exactly where 2A/2B slipped. Add a QA requirement: for any function labeled with a specific spec name (SMP `f4/f5/f6/g2`, EC point-vs-field, an HCI opcode, an SDP element type), the QA must (i) confirm the **distinguishing behavior** of that exact primitive is present — `f5` emits two 128-bit outputs + uses a counter/salt; `f6` is a DHKey-check MAC; `g2` reduces mod 10^6; a **point** op works over 2–3 coordinates with many field mul/sqr; a **field** op is one/two operands + a single reduction — and (ii) **reject** a label if two functions claimed to be different primitives make byte-identical calls. Plus the **milestone-honesty** corollary: never report "100% / N of N" for a subsystem until the set is de-duplicated against jump-table splits (Class 1) and the boundaries verified; if a percentage rests on raw census-entry counts, say so.

Also worth reinforcing (2E/2F): the **commit message** must not claim more than the durable doc supports — several errors here were headline-only overstatements (Jacobian, command-queue, PDU builders) while the write-up body was more careful. The commit is a claim too; hold it to the same evidence bar.

---

## Part 4 — Your task checklist
1. Verify 2A–2F yourself from the raw bytes (don't trust this doc).
2. Rewrite/extend `HANDOFF.md`'s rigor rules to cover Class 1 and Class 2 above, in your own words, with these concrete examples.
3. Fix the durable errors 2A–2F in the analysis docs (and leave Part 1 items untouched).
4. Re-QA Session 30 under the improved rules — specifically hunting jump-table fragment over-counts, un-re-derived spec labels, and "builder decompiled?" overstatements.
5. Delete this file.

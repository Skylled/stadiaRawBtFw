# Bruce — embedded BoringSSL crypto (session 4; `bcm.c` correction + BIGNUM/EC map added session 9)

Decompiled C for every function cited here is in `analysis/decomp/`.

## Session 9: `bcm.c` is BoringSSL's BIGNUM + EC library, *not* a Broadcom BT chip driver

`bruce-ghidra.md` and `bruce-decompile-status.md` both characterized the 52-function, 11,548-byte `bcm.c`-attributed block as "the Broadcom BT chip HCI/patchram driver" — a reasonable-looking guess from the filename alone, made before anyone had actually decompiled a single one of its functions. All 52 are now decompiled (`analysis/decomp/bcm__*.c`) and read. **The guess was wrong, in exactly the way CLAUDE.md's `keys.cc` gotcha warns about**: `bcm.c` is a bare filename with no path, and BoringSSL happens to have a real source file at that exact bare name — `crypto/fipsmodule/bcm.c`, the "**B**oring**C**rypto **M**odule": a single translation unit that `#include`s dozens of individual algorithm-implementation files (`bn_*.c`, `ec.c`, `ec_key.c`, parts of `evp_enc.c`, etc.) so the whole FIPS-140 validation boundary compiles/link as one object. Every `__FILE__`-based debug/error string baked into any of those algorithms by the preprocessor therefore reads literally `"bcm.c"`, regardless of which original algorithm file the code came from — the same bare-filename collision that made `keys.cc` (a typed config store) look like gamepad-button code.

**Evidence it's BoringSSL BIGNUM/EC, not a radio driver:**
1. **The single leaked string is bare `"bcm.c"`** at flash `0x6012867d` (`analysis/ghidra/bruce_strings.txt`), cross-referenced from all 52 functions — no path component, consistent with a `#include`-aggregated FIPS module file rather than a normal source tree layout.
2. **Every function's error path is OpenSSL/BoringSSL's `ERR_put_error(lib, func, reason, file, line)` idiom**, called through `FUN_600e0552(lib, 0, func_or_reason, DAT_xxxx, line, ...)` with a literal 5-int-plus-varargs shape — and the `lib` codes split cleanly by cluster: the raw-bignum functions all pass `lib=3` (`ERR_LIB_BN`), while the EC/EVP cluster passes `0xf`/`0x1e`/`4` — internally consistent with which BoringSSL sub-library each function actually belongs to, not arbitrary.
3. **Struct shapes are exact matches for known BoringSSL types**: a 20-byte alloc-and-zero pattern (`bcm__6008b384`) matches `struct bignum_st {BN_ULONG *d; int top; int dmax; int neg; int flags;}` exactly (5×4 bytes on this 32-bit target); point-format parsing checks the byte values `0x02`/`0x03`/`0x04` (`bcm__6008e910`) — the exact SEC1 compressed/uncompressed EC point-octet tags; a curve-group cache (`bcm__6008d7ac`) loops over exactly **4** built-in entries, matching BoringSSL's actual built-in curve count (P-224/P-256/P-384/P-521).
4. **Direct call edges to/from other already-attributed BoringSSL source files**: `bcm__6008ccb4`/`bcm__6008cfd4`/`bcm__6008db50`/`bcm__6008e910`/`bcm__600ea868` are called from `ec_asn1__60091580` (`ec_asn1.c`); `bcm__6008c728` is called from `pem_lib__60085f2c` (`pem_lib.c`); `bcm__600ea868`/`bcm__600ebf76` call `ex_data__600919d4` (`ex_data.c`, BoringSSL's generic `CRYPTO_EX_DATA` object-constructor mechanism used by `RSA_new`/`EC_KEY_new`-style functions). All three are already-confirmed BoringSSL files, not Bluetooth code.
5. **Zero HCI/UART/patchram vocabulary anywhere in the 52 functions** — no baud-rate constants, no H4 packet-type bytes, no firmware-hex patch buffers, no UART MMIO register access. Contrast with the real, confirmed Broadcom chip-transport code, which does show exactly that vocabulary: `hcisu_h4_send_msg_now` (`0x60096e38`, `bruce-bta-stack.md`) — a real Broadcom-adjacent function, just a different, unattributed address range from this one, not a duplicate of it.

Net: **`bcm.c` is BoringSSL's generic multi-precision-integer (BIGNUM) library plus its generic short-Weierstrass EC_GROUP/EC_POINT/EC_KEY layer**, with a small EVP block-cipher-padding cluster mixed in (consistent with "bcm.c" being one aggregated translation unit spanning several logical BoringSSL subsystems, not one coherent module by original design). This corrects `bruce-ghidra.md`'s module-mass table and `bruce-decompile-status.md`'s file-list description (both updated to point here); the real Broadcom BT chip/HCI layer is the material documented separately in `bruce-bta-stack.md`.

### Function map (all 52 decompiled; confidence noted per row — "high" = multiple independent shape/spec matches, "medium" = single strong shape match, name not spec-verified)

**BIGNUM core** (allocation, word-array arithmetic primitives):

| Address | Bytes | Identification | Confidence |
|---|---:|---|---|
| `0x6008b384` | 48 | `BN_new`-shaped: alloc+zero the 20-byte `bignum_st`, set `flags=1` (`BN_FLG_MALLOCED`) | high |
| `0x6008b570` | 150 | `BN_CTX_get`-shaped: pool-based BIGNUM allocator from a `BN_CTX`, grows the pool via the fn above | high |
| `0x6008b50c` | 50 | `BN_CTX_new`-shaped: alloc+zero a 24-byte `BN_CTX` | medium |
| `0x6008b43c` | 118 | `bn_wexpand`-shaped: grow `d` to ≥N words (realloc+copy+free), respects a static-data flag bit | high |
| `0x6008b4b8` | 78 | `bn_resize_words`-shaped: extend/truncate `top`, zero-fill new words via `bn_wexpand` | medium |
| `0x6008b3d4` | 100 | `bn_set_words`-shaped: raw word-array copy-out into a caller buffer | medium |
| `0x6008b60c` | 152 | `bn_usub`-shaped: unsigned word-array subtract-with-borrow | high |
| `0x6008b6a8` | 138 | `bn_mul_add_words`-shaped: schoolbook long-multiplication carry-propagate inner loop | high |
| `0x6008b738` | 94 | `bn_sqr`-shaped: squares a BIGNUM via the multiply-accumulate loop above | medium |
| `0x6008b970` | 124 | BN copy/normalize helper — computes and caches a derived 8-byte value (bit-length/word-count pair) | medium |
| `0x6008b9f0` | 44 | signed add/sub sign-check dispatcher (checks both operands' `neg` flag before combining) | medium |
| `0x6008ba20` | 120 | Montgomery/modular-multiply dispatcher — squares if both operands are the same pointer, else multiplies; huge fan-in from the modexp functions below | high |
| `0x6008bae0` | 172 | `BN_lshift`-shaped: word+bit left shift | high |
| `0x6008bb90` | 72 | word-array copy/shift helper, sibling of `BN_lshift` | medium |
| `0x6008bbdc` | 800 | `BN_div`-shaped: Knuth Algorithm-D long division, 64-bit quotient-digit refinement via a 2-word/1-word divide primitive (`FUN_6004c814`) | high |
| `0x6008bf44` | 398 | binary-GCD core (bit-parity conditional-subtract loop) — feeds `BN_gcd`/modular-inverse machinery | medium |
| `0x6008b79c` | 398 | `BN_mod_inverse`-shaped: extended binary-GCD/Lehmer-style modular inverse | medium |
| `0x6008c5fc` | 290 | Kronecker/Jacobi-symbol computation (binary-GCD-style loop with running sign flip) — feeds the `BN_mod_sqrt` non-residue search below | medium |

**Modular exponentiation:**

| Address | Bytes | Identification | Confidence |
|---|---:|---|---|
| `0x6008c0d8` | 628 | `BN_mod_exp`-shaped: sliding-window modexp, stack power-table (up to 32 entries), square-and-multiply main loop reading exponent bits via a `BN_is_bit_set`-shaped callee | high |
| `0x6008c334` | 706 | constant-time windowed modexp (`BN_mod_exp_mont_consttime`-shaped): heap-allocated flat power table + fixed-width table-gather via the raw-word-copy helper, i.e. the constant-time-access variant | high |

**EC — `EC_GROUP`/`EC_POINT`/`EC_KEY`, generic short-Weierstrass layer:**

| Address | Bytes | Identification | Confidence |
|---|---:|---|---|
| `0x6008d7ac` | 642 | `EC_GROUP_new_by_curve_name`-shaped: mutex-guarded cache of exactly 4 built-in curve groups (matches BoringSSL's real built-in-curve count: P-224/256/384/521) | high |
| `0x6008cbfc` | 126 | `EC_GROUP_new`-shaped: allocs a 344-byte (`0x158`) `EC_GROUP`, calls the method's `group_init` vtable slot | medium |
| `0x6008cb7c` | 66 | group/field-method rebind helper (swaps method vtable ptr + per-method extra-data block, re-inits) | medium |
| `0x6008ccb4` | 40 | method-dispatch trampoline (group-method vtable slot `+0x1c`); direct caller is already-attributed `ec_asn1__60091580` | high |
| `0x6008ac40` | 62 | `BN_MONT_CTX_new`-shaped: allocs an 88-byte Montgomery-context struct | medium |
| `0x6008cf98` | 54 | Montgomery-context computation helper (`BN_MONT_CTX_set`-shaped) | medium |
| `0x6008cfd4` | 100 | wraps the two above — installs/caches a field's Montgomery context; caller is `ec_asn1__60091580` | medium |
| `0x6008d120` | 258 | `ec_GFp_simple_group_set_curve`-shaped: installs p/a/b curve parameters into an `EC_GROUP`, detects the `a=-3` fast-path (flag consistent with the same flag read by `0x6008d6f8`/`0x6008e700` below) | high |
| `0x6008d228` | 122 | `ec_GFp_mont_group_set_curve`-shaped: `BN_CTX_new` + Montgomery-context-for-field + calls the fn above — matches BoringSSL's real two-layer `ec_GFp_mont_group_set_curve`→`ec_GFp_simple_group_set_curve` call structure | high |
| `0x6008db50` | 216 | `EC_GROUP_set_generator`-shaped: installs generator point + order + cofactor | medium |
| `0x6008d2a8` | 82 | `EC_POINT_new`-shaped: allocs a 208-byte (`0xd0`) point struct, calls method init | medium |
| `0x6008d300` | 76 | `EC_POINT_copy`-shaped (copies a 68-byte precomp/extra block) | medium |
| `0x6008d6b8` | 58 | small point-init-or-reinit dispatcher, sibling of `EC_POINT_new` | medium |
| `0x6008ce70` | 66 | field-element encode helper: BIGNUM → group's internal (Montgomery) field representation via a method vtable slot | medium |
| `0x6008d6f8` | 292 | Jacobian→affine coordinate recovery: field inversion via a Fermat's-little-theorem exponentiation chain, calling the group's `field_mul`/`field_sqr` method-vtable slots directly, branching on the `a=-3` flag | medium |
| `0x6008d730` | 118 | `EC_POINT_get_affine_coordinates_GFp`-shaped: wraps the coordinate recovery above + `EC_POINT_copy` | medium |
| `0x6008da3c` | 52 | method-match check + `EC_POINT_set_to_infinity`-shaped | medium |
| `0x6008da74` | 56 | `EC_POINT_copy`-shaped (alternate/simpler path) | medium |
| `0x6008dab0` | 82 | `EC_POINT_dup`-shaped | medium |
| `0x6008db08` | 300 | `EC_POINT_cmp`-shaped: method-match guard + point-equality compare, returns `-1` on mismatch | high |
| `0x6008e164` | 248 | `BN_rand`-shaped: builds an N-bit random BIGNUM honoring the classic `top`∈{-1,0,1} / `bottom`(force-odd) constraints — used for random EC scalar generation | high |
| `0x6008e264` | 1160 | `BN_mod_sqrt`-shaped: Tonelli-Shanks modular square root (quadratic-residue search, ~80-iteration bound, using the Kronecker/Jacobi helper above) — the single biggest function in the file | high |
| `0x6008e700` | 524 | `EC_POINT_set_compressed_coordinates_GFp`-shaped: evaluates `y²=x³+ax+b` (with the `a=-3` fast path), calls `BN_mod_sqrt`, fixes the sign/parity bit | high |
| `0x6008e910` | 326 | `EC_POINT_oct2point`-shaped: parses a SEC1 octet string (`0x02`/`0x03` compressed, `0x04` uncompressed — byte-exact match), dispatches to the compressed/uncompressed path | high |
| `0x6008eb24` | 560 | `EC_KEY_check_key`-shaped: point/key consistency check via three chained multiply-and-compare steps | medium |
| `0x600ea868` | 134 | small `CRYPTO_EX_DATA`-backed object constructor (calls already-attributed `ex_data__600919d4`) | medium |
| `0x600ebf76` | 156 | larger (152-byte) `CRYPTO_EX_DATA`-backed object constructor — `EC_KEY_new`-shaped by size/field layout | medium |

**EVP block-cipher padding/init cluster** (smaller, distinct sub-group — PEM private-key decryption, not EC math):

| Address | Bytes | Identification | Confidence |
|---|---:|---|---|
| `0x6008c728` | 194 | PKCS#7 de-padding (validates trailing pad bytes, copies unpadded plaintext) — `EVP_DecryptFinal_ex`-shaped; **caller is `pem_lib__60085f2c`** (PEM decode of an encrypted key), tying this cluster to PEM private-key decryption | medium |
| `0x6008c7f0` | 64 | cipher-method vtable getter/dispatch (`EVP_CIPHER_CTX`-shaped) | medium |
| `0x6008c834` | 276 | `EVP_CipherInit_ex`-shaped: cipher-mode switch (cases 0-5 matching the classic ECB/CBC/CFB/OFB/CTR/stream-mode enum), key/IV setup | medium |
| `0x6008cce0` | 146 | point-coordinate byte-reversal serializer (little-endian BIGNUM limbs → big-endian octets) feeding `EC_POINT_point2oct` below | medium |
| `0x6008d5e0` | 212 | `EC_POINT_point2oct`-shaped: handles SEC1 point formats 2 (compressed) and 4 (uncompressed) exactly, computes output length, packs X (and Y) coordinates, sets the compressed-format parity byte from Y's LSB | high |

**Bottom line for the "find what calls the EC crypto stack" open thread (item 5 in CLAUDE.md's status list)**: this block is the generic *library* layer (BIGNUM + EC math), not a call site — it doesn't resolve who invokes it. But it does strengthen the P-256 lead from `bruce-bta-stack.md` (SMP's ECDH keypair-gen chain `FUN_600c0f34`→`FUN_600c1030`→`FUN_600c8798`, and the P-256/P-192 field-reduction pair at `0x600c8fd8`/`0x600c8b24`): those BTA-block functions almost certainly call down into (or duplicate/inline) primitives from *this* generic EC layer, or a curve-specialized sibling of it. Worth checking direct call edges between the two blocks next session.

## Confirmed: a full SHA-512 + Ed25519 stack is compiled in

Traced bottom-up from the largest unattributed function in the image:

- **`FUN_6004cdb8` @ 0x6004cdb8 (15,662 bytes)** — the SHA-512/SHA-384 compression function. Confirmed by the tell-tale signature: 128-byte (`0x80`) block stride, 64-bit lanes built with `CONCAT44` of two 32-bit halves, the SHA-512 Σ0/Σ1 rotate constants (28/34/39 and 14/18/41) and σ0/σ1 message-schedule rotates (1/8/7 and 19/61/6), 80 rounds, 8×64-bit state words. This single function is most of the image's largest-unread-function list from session 1.
- **`FUN_600e6a52` @ 0x600e6a52** — `GET_UINT64_BE`: loads 8 bytes from the message block and byte-swaps into a big-endian 64-bit word. Only caller: the compression function above.
- **`FUN_600ec12c` @ 0x600ec12c** — `SHA512_Update`-equivalent: buffers input, tracks a 64-bit bit-length counter at ctx+0x40/0x44, calls the compressor on each full 128-byte block.
- **`FUN_600ec1e0` @ 0x600ec1e0** — `SHA512_Final`-equivalent: appends the `0x80` pad byte, zero-pads to the length field, packs the bit-count big-endian into the last 16 bytes, runs a final compress, then serializes the digest. Branches on a digest-size field (ctx+0xd4): `0x30` → 48-byte output (**SHA-384**), `0x40` → 64-byte output (**SHA-512**) — this shared-context, size-switched pattern matches BoringSSL's `sha512.c` (one context struct backs both `SHA384_*` and `SHA512_*`).
- **`FUN_600ec31c` @ 0x600ec31c** — one-shot `SHA512(data, len, out)`: stack context → Update → Final → `thunk_EXT_FUN_0000ac52` (a cleanse/wipe of the stack context, i.e. `OPENSSL_cleanse`).
- **`FUN_600e1d72` @ 0x600e1d72** — **Ed25519 keypair-from-seed**: `SHA512()` the 32-byte seed, then RFC 8032 clamp (`buf[0] &= 0xf8`, `buf[31] = buf[31] & 0x7f | 0x40`), scalar-mult the curve basepoint by the clamped scalar (`FUN_60087964`), encode the resulting point (`FUN_600e1c48`), and pack `{public key (32B) || seed (32B)}` into the 64-byte "expanded" private key layout BoringSSL uses for Ed25519.
- **`p_ed25519_asn1__60085728` @ 0x60085728** (src: `p_ed25519_asn1.c`) — `ED25519_keypair_from_seed`'s ASN.1-layer wrapper: builds a raw-key `EVP_PKEY` object from a 32-byte private key blob (`pkey_ed25519_set_priv_key`-shaped).
- **`p_ed25519_asn1__60085780` @ 0x60085780** (src: `p_ed25519_asn1.c`) — a PKCS#8/ASN.1 private-key decode entry point (`ed25519_priv_decode`-shaped): parses a DER structure via three small ASN.1 helpers (`FUN_600ed398/600ed39c/600ed556`), then hands the raw key to the function above.

Net: **bruce statically links a real Ed25519 implementation (SHA-512, RFC 8032 keygen, ASN.1/PKCS#8 decode)** — this is BoringSSL's `p_ed25519_asn1.c` / `crypto/curve25519` glue, not something Google wrote for the controller specifically.

## Resolved: it's the generic BoringSSL algorithm registry — no live call path found

`FindRef` on `0x60085780` initially showed **zero** cross-references, because Ghidra hadn't typed the containing data as pointers. A raw byte search of the flash image for `0x60085781`/`0x60085729` (Thumb-bit-set pointer literals) found the real reference at flash **0x6010b91c–0x60110b3c**: a `struct evp_pkey_asn1_method_st` laid out back-to-back with a sibling RSA struct at 0x6010b95c. Confirmed via **two independent exact matches**, not just pointer proximity:
- The Ed25519 struct's `pkey_id` field = `0x3b5` = **949 = `NID_ED25519`**, and its inline `oid[9]` bytes are `2B 65 70` = the DER content of OID **1.3.101.112** (`id-Ed25519`, RFC 8032/8410).
- The adjacent RSA struct's `pkey_id` = `6` = **`NID_rsaEncryption`**, oid bytes `2A 86 48 86 F7 0D 01 01 01` = OID **1.2.840.113549.1.1.1**.

This is BoringSSL's static `EVP_PKEY_ASN1_METHOD` table (one struct per supported key algorithm), and the Ed25519 struct's `priv_decode` slot holds `p_ed25519_asn1__60085780` — exactly where BoringSSL wires it up. The dispatcher **`FUN_60084fc0`** (an `EVP_PKEY_asn1_find`-by-NID lookup, called from **`evp__6008506c`**, already attributed to `evp.c`) has explicit cases for NID `0x198` (EC), `6` (RSA), `0x74` (DSA), `0x3b4` (X25519), and `0x3b5` (**ED25519**) — so the registry is complete and correctly wired for all five algorithms.

**But tracing further up dead-ends**: `evp__6008506c` has exactly one caller in the call graph, `FUN_600e06ee` — and it hardcodes NID **`0x74` (DSA)**, not ED25519. `FUN_600e06ee` itself has **no callers found**. So every path from a live bruce entry point down into this table currently dead-ends one or two hops up, for every algorithm, not just Ed25519.

**Conclusion**: this is very likely the generic BoringSSL EVP/ASN.1 algorithm-registry machinery pulled in wholesale because gotham's TLS 1.3/DTLS/X.509 stack needs it (`firmware-map.md`: bruce shares 168 of gotham's 173 source files) — present in bruce's link but with **no static-analysis-confirmed live caller**, consistent with it being linked-but-dormant rather than an active bruce feature. This *doesn't* rule out reflection through a not-yet-resolved indirect call (e.g. a vtable BoringSSL builds at runtime), same caveat as the `thunk_EXT_FUN_0000xxxx` ITCM primitives. Not worth further manual byte-hunting without a specific lead; revisit if BT pairing/OTA-update tracing turns up a call into `evp.c` or `p_ed25519_asn1.c` from a different angle.

## Curve25519 field/point arithmetic — the other two "largest unread functions"

`bruce-ghidra.md` session 1 flagged `FUN_600e398a` (6,270 bytes) and `FUN_600e2316` (5,748 bytes) as the other top-size unattributed functions, alongside `FUN_6004cdb8`, and guessed all three might be event/dispatch loops. **They're not — all three are this same crypto stack.** Decompiled session 4:
- **`FUN_600e398a`** (2 params: out, in) = `fe_sq` — Curve25519 field-element square, BoringSSL's generic (non-51-bit-limb) reference implementation.
- **`FUN_600e2316`** (3 params: out, a, b) = `fe_mul` — field-element multiply, same family.
- Both are called exclusively from **`FUN_600e65d2`** and **`FUN_600e66be`**, which chain `fe_mul`/`fe_sq`/`fe_add`(`FUN_600e5208`)/`fe_sub`(`FUN_600e548a`) in the exact sequence of the `ref10` Ed25519 **Edwards point doubling/addition formulas** (`ge_p3_dbl`-shaped: `A=X²,B=Y²,C=2Z²,...`). So this confirms the prediction below: one shared elliptic-curve core (field ops + point ops) backs both the Ed25519 signing path and (presumably) X25519 ECDH.

**This closes out the "find the main event loop by biggest unread function" search — the top 4 candidates from session 1 were all crypto, not dispatch code.** Re-survey `bruce_functions.csv` by size excluding the `0x6004cdb8`/`0x600e2xxx`–`0x600e6xxx` crypto range for the next main-loop candidate, or switch heuristics (e.g. highest fan-out/callee-count, or functions referencing FreeRTOS queue-receive primitives in a loop).

## Session 15: `tasn_dec.c` — the ASN.1 template-based DER decoder

`tasn_dec.c` is BoringSSL's `crypto/asn1/tasn_dec.c` — the generic `ASN1_ITEM`-template-driven DER decoder, the decode-side counterpart of `tasn_new.c` (allocation; attributed but still undecompiled) and the various `p_*_asn1.c`/`ec_asn1.c`/`pem_lib.c` per-algorithm wrappers already covered above. All 7 of the file's attributed functions are now decompiled (was 0/7, `bruce-decompile-status.md`'s #1 cheap-win target); confirmed BoringSSL identity from the exact control-flow/parameter shape of upstream `tasn_dec.c`'s internal helper chain:

- **`tasn_dec__6008f370`** (310B) — `asn1_check_tlen`-shaped: parses/verifies a BER/DER tag-length header, caching the parsed length/tag/class fields into a caller-owned "context" struct (`param_11`) so a re-entrant caller can skip re-parsing. Called from 5 of the file's other 6 functions (all but `asn1_ex_c2i`-shaped `tasn_dec__6008f5e8`, which doesn't need its own tag/length parse).
- **`tasn_dec__6008f4ac`** (292B, self-recursive) — `asn1_collect`-shaped: recursively walks a constructed/indefinite-length BER value, accumulating child TLVs into a growable buffer (`thunk_FUN_600ece78` = buffer-grow, `thunk_EXT_FUN_0000b572` = memcpy).
- **`tasn_dec__6008f5e8`** (412B) — `asn1_ex_c2i`-shaped: the primitive-type content-to-internal-object converter — a big switch on ASN.1 universal tag number dispatching to type-specific decoders (`a_int.c`'s `a_int__6008ef7c` for INTEGER/ENUMERATED, `a_bitstr.c`'s `a_bitstr__6008ee9c` for BIT STRING, `a_object.c`'s `a_object__6008f0d8` for OBJECT IDENTIFIER, plus inline BOOLEAN/NULL/generic-`ASN1_STRING` handling).
- **`tasn_dec__6008f794`** (640B) — `asn1_item_embed_d2i`'s tagged-value entry point: resolves implicit-vs-explicit tagging, then calls the two functions above.
- **`tasn_dec__6008fa18`** (1410B, largest) — the real recursive `asn1_item_embed_d2i` core: switches on the `ASN1_ITEM`'s `itype` (0=PRIMITIVE, 1/6=SEQUENCE/NDEF_SEQUENCE — confirmed by the decompiled `case 1: case 6:` merge, matching BoringSSL's real `ASN1_ITYPE_SEQUENCE`/`ASN1_ITYPE_NDEF_SEQUENCE` pair, 2=CHOICE, 4=EXTERN — confirmed by its 8-argument passthrough call matching the real `asn1_ex_d2i(pval, in, len, it, tag, aclass, opt, ctx)` callback signature exactly, 5=MSTRING — the multi-string tag-bitmask lookup at case 5's `DAT_6008fcf8` table matches `ASN1_ITYPE_MSTRING`'s accepted-tag bitmap idiom exactly; case 3 is a separate 3-argument-callback path, not independently identified), walking an `ASN1_TEMPLATE` array for SEQUENCE/CHOICE members and recursing per field. (Audit correction: an earlier draft of this row mislabeled the case values as "1/5=SEQUENCE/NDEF_SEQUENCE, 3=MSTRING" — self-contradictory with its own MSTRING evidence, which the decompiled code places in case 5, not case 3; corrected here after re-reading `tasn_dec__6008fa18.c`.)
- **`tasn_dec__6008ffc0`** (514B) — `asn1_template_ex_d2i`-shaped: SEQUENCE-OF/SET-OF repeated-field decode, looping `tasn_dec__6008fa18` per element into a growable `STACK_OF()`-style list (`FUN_600e0aac`/`FUN_600e0ab2`/`FUN_600e0be8`, generic stack/list primitives).
- **`tasn_dec__600901c8`** (278B) — `asn1_template_noexp_d2i`-shaped thin wrapper: checks the `ASN1_TFLG_EXPLICIT` (`0x10`) flag bit and either delegates straight to `tasn_dec__6008ffc0` or unwraps the explicit tag itself first.

All 7 share the same error-reporting idiom already seen throughout the crypto stack (`FUN_600e0552`, an `ERR_put_error`-shaped call taking a fixed library code `0xc` = `ERR_LIB_ASN1` plus function/reason codes and `__FILE__`/`__LINE__`-style literals) — consistent with genuine unmodified BoringSSL source, not a stripped reimplementation. This is very likely what the already-documented `ed25519_priv_decode`/PKCS#8 path (`p_ed25519_asn1__60085780`, above) bottoms out into at runtime, though — per the "no live call path found" section above — no confirmed live caller into *any* of this ASN.1 machinery has been traced yet from a real bruce entry point.

## Session 19: `ec_asn1.c` — the EC key/parameter ASN.1 codec (5/5 decompiled)

`ec_asn1.c` was `bruce-decompile-status.md`'s #5 cheap-win target (1,630 remaining bytes, 0/5). All 5 attributed functions are now decompiled (`analysis/decomp/ec_asn1__*.c`). It's BoringSSL's `crypto/ec_extra/ec_asn1.c` — the EC-specific X9.62 ASN.1 layer sitting directly on top of the generic template-driven ASN.1 decoder (`tasn_dec.c`, session 15) and the generic BIGNUM/EC math (`bcm.c`, session 9), and it cleanly closes the gap between them:

| Function | Bytes | Role |
|---|---:|---|
| `ec_asn1__60091238` | 108 | Curve-OID → `EC_GROUP` lookup (`ec2groupid`/named-curve branch of `d2i_ECPKParameters`-shaped): parses a decoded OBJECT IDENTIFIER, walks the same fixed 4-entry built-in-curve table `bcm.c`'s `EC_GROUP_new_by_curve_name`-shaped `bcm__6008d7ac` uses (via `FUN_6008cbe0`), matches OID bytes, returns the cached `EC_GROUP*`. |
| `ec_asn1__600912a8` | 132 | The inverse (`i2d_ECPKParameters`'s named-curve path): `EC_GROUP*` → OID, same 4-entry table matched by pointer instead of bytes, then DER-encodes the OID via `tasn_dec.c`'s sibling primitive-encode helpers (`FUN_600ed1b4`/`FUN_600ed0de`). |
| `ec_asn1__60091330` | 580 | `d2i_ECParameters`-shaped: decodes a full X9.62 `ECParameters` SEQUENCE (version / fieldID / curve `{a, b, seed}` / base-point OCTET STRING / order / cofactor), falling back to `ec_asn1__60091238`'s named-curve shortcut when the structure is just a curve OID — the real dual-path (explicit-vs-named) `d2i_ECParameters` behavior. |
| `ec_asn1__60091580` | 530 | `d2i_ECPrivateKey`-shaped (largest of the 5): decodes an `ECPrivateKey` SEQUENCE (version=1, `privateKey` OCTET STRING, optional `[0]` explicit parameters/named-curve OID, optional `[1]` public-key `BIT STRING`), builds a live `EC_KEY` via `bcm.c`'s constructors (`bcm__600ea868`/`6008d6b8`/`6008d2a8`/`6008cfd4`/`6008ccb4`/`6008e910`/`6008db50`), and derives the public key from the private scalar when the DER didn't carry one. |
| `ec_asn1__600917a0` | 280 | `i2d_ECPrivateKey`-shaped: the encode counterpart — builds the SEQUENCE (version, private-key octets, optional parameters, optional public-key bit string), using `ec_asn1__600912a8` for the parameters field. |

All five share the crypto stack's uniform `FUN_600e0552` (`ERR_put_error`-shaped, `lib=0xf` = `ERR_LIB_EC`) error-reporting idiom, reinforcing the unmodified-upstream-BoringSSL read on this whole cluster. This gives a complete, confirmed decode-to-live-`EC_KEY` (and back) path for the standalone X9.62 EC private-key wire format — combined with `tasn_dec.c` + `bcm.c`, the ASN.1↔library boundary for EC keys specifically is now fully mapped (PEM/PKCS#8 wrapping around it, `pem_lib.c`, is still undecompiled). **No caller into any of these 5 functions was found this session** — same standing "no confirmed live entry point into the BoringSSL/ASN.1 machinery" result as everywhere else in this doc.

## Session 20: `pem_lib.c` — the PEM (base64 armor + encrypted-key header) codec (3/3 decompiled)

`pem_lib.c` was `bruce-decompile-status.md`'s #2 cheap-win target (1,458 remaining bytes, 0/3). All 3 attributed functions are now decompiled (`analysis/decomp/pem_lib__*.c`). It's BoringSSL's `crypto/pem/pem_lib.c` — the outermost PEM-armor layer that `pem_lib__60085f2c` (already referenced from `bcm__6008c728`'s caller list above) sits inside — confirming the file's identity end-to-end, not just the one function already cross-referenced.

| Function | Bytes | Role |
|---|---:|---|
| `pem_lib__60086038` | 376 | `PEM_get_EVP_CIPHER_INFO`-shaped: parses the legacy `"Proc-Type: 4,ENCRYPTED"` / `"DEK-Info: <cipher-name>,<hex-IV>"` header pair out of a decoded PEM text block, looks up the named cipher (`FUN_60085eb8`), validates its IV length is ≤ 8 bytes (`FUN_600e9ff4`), and hex-decodes the IV into the caller's `EVP_CIPHER_INFO`-shaped output struct. Uses `FUN_601024b4` (a `strncmp`-shaped literal-prefix matcher) throughout — the exact same idiom every other ASN.1/PEM file in this stack uses for tag/keyword matching. |
| `pem_lib__60085f2c` | 258 | `PEM_do_header`-shaped: given the parsed cipher-info above and a passphrase callback (`param_4`, defaulting to `DAT_60086030` if null), invokes the callback to obtain the passphrase, derives a key via `FUN_600ed880` (an `EVP_BytesToKey`-shaped legacy KDF — single/double MD5-style key derivation from passphrase+salt, not itself decompiled this session), then decrypts the PEM payload in place via a generic `EVP_CIPHER_CTX`-shaped init/update/final sequence (`FUN_600e9dfa`/`FUN_600e9fe2`/`FUN_600e9f1c`/`FUN_600e9e02`) and finally strips PKCS#7 padding through **`bcm__6008c728`** — closing the loop with `bruce-crypto.md`'s own earlier cross-reference of that call edge. |
| `pem_lib__600861c0` | 824 | `PEM_read_bio`-shaped (largest of the 3): the actual line-oriented PEM parser — reads a `BIO` (`bio__60084c40`, `bio.c`) line by line hunting for `"-----BEGIN "`/`"-----END "` markers, extracts the object-type name between them, accumulates any RFC822-style header lines (stops at the first blank line, matching the `"Proc-Type"`/`"DEK-Info"` headers `pem_lib__60086038` later parses) into one growable buffer and the base64 body into another (three `buf.c`-shaped growable buffers via `buf__60090ef4`/`FUN_600ece78`/`FUN_600ece60`), then base64-decodes the body (`FUN_60090d24`/`FUN_600ece1e`) before handing the caller back `(header, name, decoded_data, len)`. |

**Net**: this is unmodified, standard BoringSSL PEM-decode machinery (armor parsing → optional legacy-encrypted-key header/passphrase/KDF/decrypt → base64 decode), sitting directly above `pem_lib__60085f2c`'s already-documented call into `bcm.c`'s de-padding helper and presumably feeding `tasn_dec.c`/`ec_asn1.c`/`p_ed25519_asn1.c`'s DER decoders once the base64 armor is stripped — i.e. `pem_lib.c` is the "read a `-----BEGIN ... KEY-----` file" front door for the whole ASN.1/EC/Ed25519 stack documented above. Same standing caveat as everywhere else in this doc: **no caller into any of these 3 functions was found this session** — nothing in `bruce`'s decompiled call graph so far invokes `PEM_read_bio`, consistent with this whole cluster being present-in-the-link but not confirmed live on the BT-only controller.

## Session 22: `p_x25519_asn1.c` — the X25519 `EVP_PKEY_ASN1_METHOD` (4/4 decompiled)

`p_x25519_asn1.c` was `bruce-decompile-status.md`'s §3a rank-5 cheap-win target (492 remaining bytes, 0/4). All 4 attributed functions are now decompiled (`analysis/decomp/p_x25519_asn1__*.c`) — this closes the "Related, unexplored" open note below that flagged `p_x25519.c`/`p_x25519_asn1.c` as not yet traced. It's BoringSSL's `crypto/curve25519/p_x25519_asn1.c`, structurally parallel to the already-documented `p_ed25519_asn1.c` — same `ASN1_ITEM`-template primitive-encode calls (`FUN_600ed1b4`/`FUN_600ed266`/`FUN_600ed0de`, shared with `tasn_dec.c`/`ec_asn1.c`), same error idiom (`FUN_600e0552`, `lib=6`=`ERR_LIB_EVP`).

| Function | Bytes | Role |
|---|---:|---|
| `p_x25519_asn1__60085b50` | 168 | `x25519_pub_encode`-shaped: encodes a public-key object into DER, writing a fixed 3-byte OID literal matching X25519's `1.3.101.110` OID content bytes. |
| `p_x25519_asn1__60085c04` | 136 | `x25519_pub_decode`-shaped counterpart: parses the DER wrapper back out and validates the embedded 32-byte raw public key. |
| `p_x25519_asn1__60085d00` | 88 | `x25519_priv_decode`-shaped: unwraps a PKCS#8 private-key octet string via the same `tasn_dec.c`-family helpers (`FUN_600ed39c`/`FUN_600ed556`/`FUN_600ed398`), then hands the raw bytes to the function below. |
| `p_x25519_asn1__60085c98` | 100 | **The raw-key `EVP_PKEY` constructor.** Validates the key is exactly 32 bytes, allocates a 0x41-byte internal key struct, copies the 32-byte scalar in at offset `0x20` (leaving the first 32 bytes for a derived/cached public key — the same `{pub(32)‖priv(32)}` internal layout `FUN_600e1d72`'s Ed25519 keypair code already uses), sets a "has private key" flag, and installs it via `FUN_600e0904` (`EVP_PKEY_assign`-shaped). |

**Net:** a complete, structurally-parallel sibling of `p_ed25519_asn1.c`, sharing the same standing caveat as the rest of this document — the generic EVP/ASN.1 registry's dispatcher (see "Resolved: it's the generic BoringSSL algorithm registry" above) has an explicit case for NID `0x3b4` (X25519) wired to this file's `priv_decode` slot, but **no confirmed live caller** into any of these 4 functions was found, same status as ED25519's NID `0x3b5`.

## Session 22: `tasn_new.c` — the ASN.1 template-based allocator, `tasn_dec.c`'s allocate-side counterpart (2/2 decompiled)

`tasn_new.c` was `bruce-decompile-status.md`'s §3a rank-8 cheap-win target (464 remaining bytes, 0/2). Both attributed functions are now decompiled (`analysis/decomp/tasn_new__*.c`). It's BoringSSL's `crypto/asn1/tasn_new.c` — the generic `ASN1_ITEM`-template-driven **allocator**, the exact allocate-side counterpart to the already-documented `tasn_dec.c` decoder: same `ASN1_ITEM`/`itype` switch shape (case 0 = raw-typedef recursion, 1/6 = SEQUENCE/NDEF_SEQUENCE member-array walk with per-member recursion, 2 = CHOICE — selects and constructs one member via a callback, 3/4 = external/callback-constructed types, 5 = primitive `ASN1_STRING`-shaped alloc via `FUN_600ecabe`), the same `ASN1_TFLG_*`-shaped bitmask tests (`&0x306`/`&0x300`/`&6`/`&0x400`), and the same `FUN_600e0552` (`ERR_put_error`, `lib=0xc`=`ERR_LIB_ASN1`) error idiom as `tasn_dec.c`.

- **`tasn_new__600ecb4a`** (366B) — the outer public entry point, `ASN1_item_ex_new`-shaped, **called directly by `tasn_dec__6008fa18`** — confirming the decode path really does call this allocator at runtime whenever it needs a fresh SEQUENCE/CHOICE instance mid-parse, a real (not just plausible) tie between the two files.
- **`tasn_new__60090c3c`** (98B, self-recursive) — the field-recursion body the outer entry point (and itself, for nested SEQUENCE members) calls per `ASN1_TEMPLATE` array entry.

**Net:** closes out the ASN.1 template engine's other half — decode (`tasn_dec.c`) and allocate (`tasn_new.c`) are now both fully mapped and confirmed to call into each other directly, reinforcing the "unmodified upstream BoringSSL" read on this whole cluster. Same standing caveat as everywhere else in this doc: no confirmed live caller into `tasn_dec.c`'s own entry points has been traced from a real bruce entry point, so this doesn't change the "present in the link, not confirmed live" verdict for the ASN.1/EC/Ed25519/X25519 stack as a whole.

## Related, unexplored
- HAB4 boot signing is RSA-4096 (confirmed via the CSF block, see project memory) and lives in NXP's boot ROM, **not** in this image — so any RSA/EC code found in bruce itself would be an *application-layer* use, separate from secure boot.
- ~~BoringSSL's X25519 (`p_x25519.c`...) shares the same field/point arithmetic core... not yet traced whether X25519 has a live caller~~ — **resolved (session 22, above):** `p_x25519_asn1.c` (the ASN.1-layer wrapper, not `p_x25519.c`'s raw ECDH primitives) is now fully decompiled; same "registered, not confirmed live" status as ED25519.

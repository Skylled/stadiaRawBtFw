# Bruce — embedded BoringSSL crypto (session 4)

Decompiled C for every function cited here is in `analysis/decomp/`.

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

## Related, unexplored
- HAB4 boot signing is RSA-4096 (confirmed via the CSF block, see project memory) and lives in NXP's boot ROM, **not** in this image — so any RSA/EC code found in bruce itself would be an *application-layer* use, separate from secure boot.
- BoringSSL's X25519 (`p_x25519.c`, attributed in `bruce-ghidra.md`'s module list) shares the same field/point arithmetic core confirmed above — not yet traced whether X25519 (NID `0x3b4`) has a live caller any more than ED25519 (`0x3b5`) does.

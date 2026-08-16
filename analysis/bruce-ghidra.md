# Bruce (Bluetooth firmware) — Ghidra analysis, session 1

## Workspace
- Ghidra 12.1.2 (Homebrew), runs on `openjdk@21` (default system JDK is 26, too new — must export `JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home`).
- Headless binary: `/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless`
- Project: `analysis/ghidra/` (project name `bruce`), program `bruce_pvt_a_prod_signed.bin`.
- Load config: raw `BinaryLoader`, base **0x60040000**, language **ARM:LE:32:Cortex** (Cortex-M7, Thumb-2).
- Scripts in `analysis/ghidra_scripts/`: `SeedCortexM.java` (preScript, vector table), `DumpMap.java` (postScript, function/string dump), `AnnotateFromFilenames.java` (source-file attribution).
- Reopen in GUI: `JAVA_HOME=… /opt/homebrew/opt/ghidra/libexec/ghidraRun` then open the `analysis/ghidra` project.

Re-run from scratch:
```
export JAVA_HOME="/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home"
HL=/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless
"$HL" analysis/ghidra bruce -import reference_firmware/bruce_pvt_a_prod_signed.bin -overwrite \
  -loader BinaryLoader -loader-baseAddr 0x60040000 -processor ARM:LE:32:Cortex \
  -scriptPath analysis/ghidra_scripts -preScript SeedCortexM.java -postScript DumpMap.java
# then annotate (no re-analysis):
"$HL" analysis/ghidra bruce -process bruce_pvt_a_prod_signed.bin -noanalysis \
  -scriptPath analysis/ghidra_scripts -postScript AnnotateFromFilenames.java
```

## Results
- **5,137 functions** (4,829 from auto-analysis + 249 seeded from the Cortex-M vector table + more from propagation), **3,110 defined strings**.
- **Reset_Handler @ 0x60040500** (labeled). SP = 0x2002B828. Vector table = first ~0x3E4 bytes.
- **448 functions attributed to 139 source files** via leaked `__FILE__` strings (each renamed `<stem>__<addr>` + a `src: <path>` comment). Outputs: `analysis/ghidra/bruce_functions.csv`, `bruce_strings.txt`, `bruce_srcmap.csv`.

### Module mass (attributed functions per source file, top)
| Functions | Source file | Subsystem |
|---|---|---|
| 52 | `bcm.c` | **Not** a Broadcom BT chip driver — see correction in `bruce-crypto.md`: this is BoringSSL's `crypto/fipsmodule/bcm.c` ("BoringCrypto Module") aggregate file, i.e. BIGNUM + generic EC_GROUP/EC_POINT/EC_KEY code (biggest module by function count) |
| 19 | `tasks.c` | FreeRTOS scheduler |
| 19 | `keys.cc` | button/key input handling |
| 16 | `adapter.cc` | Bluetooth adapter/controller logic |
| 12 | `queue.c` | FreeRTOS queues |
| 11 | `state_machine.cc` | app state machine |
| 9 | `usb_host_audio.cc` | USB host audio |
| 8 | `usb_host_audio_topology.cc`, `usb_audio_receive.cc`, `gatt_server.cc` | USB audio, BLE GATT (HID-over-GATT) |
| 7 | `tasn_dec.c`, `device_info.cc` | ASN.1 decode, BT device info |
| 6 | `key_value_store.cc`, `audio_states.cc`, `application_state.cc` | NVS, audio/app state |
| 5 | `usb_device.cc`, `timers.c`, `sai.cc`, `headphone_state_machine.cc`, `gotham.cc`, `ec_asn1.c` | USB device, timers, I2S audio, headphone SM, app framework, ECC ASN.1 |
| 4 | `usb_port_controller_tusb320.cc`, `thermal.cc`, `remote_device_db.cc`, `receiver.cc`, `http_flash_writer.cc`, `heap_5_improved.c`, `p_x25519/ed25519_asn1.c` | USB-C, thermal, pairing DB, OTA flash writer, heap, Curve25519/Ed25519 |

## Next-session targets
- **Largest functions** (likely dispatchers/event loops) — **dead end, all resolved as crypto (session 4)**: `FUN_6004cdb8` (15,662B, SHA-512/384 compress), `FUN_600e398a` (6,270B, Curve25519 `fe_sq`), `FUN_600e2316` (5,748B, Curve25519 `fe_mul`) — full chain in `analysis/bruce-crypto.md`. `FUN_600723b4` (6,088B) is *not* crypto — it's called from the input-subsystem ctor `timer__60073bf0` and calls `adc__60071f74`, so it's part of the input/ADC field-registration path (see `analysis/bruce-io-paths.md`). The raw biggest-function heuristic is exhausted for finding a main event loop; next pass should exclude the now-identified crypto address range (`0x6004cdb8`, `0x600e2000`–`0x600e6fff`) and either re-sort by size or switch heuristic (fan-out/callee-count, or functions polling a FreeRTOS queue in a loop).
- **Re-sorted by size excluding known crypto**, three fresh leads (decompiled to `analysis/decomp/`, not yet analyzed in depth):
  - `FUN_600ba1c4` (3,898B, src range `0x600bxxxx`) — takes `(obj, byte *buf, ushort len)`; callees are all unattributed `0x600bxxxx`/`0x600fxxxx` functions. Shape (byte-buffer + length + many small bitfield-looking locals) suggests a **protocol packet parser/serializer** — candidate for HCI/GATT/SDP framing.
  - `FUN_600c8fd8` (2,764B, `0x600c8fd8`) — `(uint *out, uint *in)` with a long chain of 32-bit add-with-carry ops and a `DAT_600c9238` constant. Shape resembles **big-number field arithmetic** again, but a different pattern than the Curve25519 fe_mul/fe_sq already identified — possible **P-256 field-arithmetic** candidate (would matter: NIST P-256 is what BT LE Secure Connections ECDH actually uses, unlike the Ed25519/X25519 traced in `bruce-crypto.md`).
  - `FUN_601054dc` (2,546B, `0x601054dc`) — decompiled with multiple Ghidra warnings ("bad instruction data", many unreachable blocks) — likely a function-boundary/disassembly issue rather than real obfuscation; single caller `FUN_60134420` near the `thunk_EXT_FUN_0000xxxx` ITCM-thunk cluster (`0x6013cxxx`–`0x6013dxxx`). Low confidence, needs boundary fix before it's useful.
- Trace the **HID input path**: `keys.cc` + `gatt_server.cc` (BLE) + `usb_device.cc` (USB HID) → how a button press becomes report ID 3; and output report ID 5 → rumble.
- Map the **vendor USB interface** (class 0xFF, bulk EP7) command handler.
- Improve attribution: propagate names via call graph (callers of an attributed leaf), and decode the build-info/version struct.

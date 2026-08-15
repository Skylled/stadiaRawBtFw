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
| 52 | `bcm.c` | Broadcom BT chip driver (HCI/patchram) — biggest module |
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
- **Largest functions** (likely dispatchers/event loops), un-attributed so far: `FUN_6004cdb8` (15,662 bytes — near image start, prime suspect for a main event/USB-BT dispatcher), `FUN_600e398a` (6,270), `FUN_600723b4` (6,088), `FUN_600e2316` (5,748). Decompile these first.
- Trace the **HID input path**: `keys.cc` + `gatt_server.cc` (BLE) + `usb_device.cc` (USB HID) → how a button press becomes report ID 3; and output report ID 5 → rumble.
- Map the **vendor USB interface** (class 0xFF, bulk EP7) command handler.
- Improve attribution: propagate names via call graph (callers of an attributed leaf), and decode the build-info/version struct.

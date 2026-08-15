# Stadia Controller Firmware — Structural Map (session 1)

Derived from static analysis of the firmware images in `reference_firmware/`. Hardware/flash background lives in the project memory; this doc is the firmware structure itself.

## Images & load layout

| Image | Codename | Role | Size | Initial SP | Reset_Handler | Flash slot |
|---|---|---|---|---|---|---|
| `bruce_pvt_a_prod_signed.bin` (+dev/stage) | **bruce** | Bluetooth-mode gamepad FW | 1,050,984 | 0x2002B828 | 0x60040501 | App A (0x60040000) |
| `ota…gotham-pvt-a….bin` | **gotham** | Wi-Fi/cloud stock FW (HW rev A) | 4,163,944 | 0x2003F688 | 0x60040501 | App A (0x60040000) |
| `ota…gotham-pvt-b….bin` | **gotham** | Wi-Fi/cloud stock FW (HW rev B) | 4,163,944 | 0x2003F688 | 0x60840501 | App B (0x60840000) |

Notes:
- All images begin at the Cortex-M7 **vector table** (SP, then Reset_Handler with Thumb bit). The FCB + IVT that precede the app in flash (0x60000000–0x60040000) are shipped separately (the flashloader/FCB blobs).
- **gotham pvt-A vs pvt-B are the same firmware linked at two different flash slots** (App A vs App B). The only early-vector difference is the base offset (`…0460…` → `…8460…`, i.e. +0x800000). The pvt-a/pvt-b split is a hardware-revision *flash-layout* change, not two different codebases.
- gotham uses more RAM than bruce (higher initial SP), consistent with the much larger streaming workload.
- bruce (BT) is essentially a **subset** of gotham: of bruce's 173 source-file strings, 168 also appear in gotham (only 5 are BT-only). The end-of-life Bluetooth firmware is the shared base platform with the entire Wi-Fi/cloud stack stripped out.

## The headline: gotham is a full embedded cloud-gaming streaming client

The Wi-Fi firmware leaks ~546 source filenames (built from Google's `google3` monorepo via Bazel — paths like `bazel-out/armv7em-py2-opt/bin/google3/…` and `/workspace/checkout/gotham/source/yeti/…`; target arch **armv7em** = Cortex-M7). It is not "a gamepad that talks to a phone" — it is a self-contained WebRTC streaming endpoint running on a microcontroller. Subsystems, by leaked module names:

- **lwIP TCP/IP stack** — `tcp*.c`, `udp.c`, `ip4*/ip6*`, `dhcp.c/dhcp6.c`, `dns.c`, `sntp.c`, `etharp/ethernet/ethip6`, `icmp*/igmp/mld6/nd6`, `netif/netbuf/pbuf/sockets/tcpip/memp`, `host_network*`, `api_lib/api_msg`.
- **WebRTC / real-time transport** — `webrtc_channel`, `webrtc_connection_impl`, `webrtc_sdp_handler`, `webrtc_stun`, `ice_connectivity_checker`, `dtls_socket/method/record/processor`, `srtp_codec`, `rtp_packet/sender/buffer`, `sctp_socket/protocol/utils` + bundled `third_party/usrsctp` (SCTP data channels), `muxed_channel`, `keepalive_runner`, `remote_clock/monotonic_remote_clock`.
- **BoringSSL + TLS 1.3 / DTLS** — `ssl_*.cc`, `tls13_*.cc`, `tls_*.cc`, `handshake*`, `d1_*` (DTLS record), `e_chacha20poly1305`, `hkdf`, `rsa_pss/rsa_signing`, `ecdh_extra`, `p_ec/p_ed25519/p_rsa/p_x25519`, full ASN.1/X.509 (`x509*`, `v3_*`, `a_*`, `pkcs8`, `pem_pkey`), `jwt`, `crypto_utils`.
- **Opus audio + voice chat** — `audio_encoder_opus`, `audio_decoder_opus`, `opus_*`, `audio_playback_manager`, `gotham_audio_player`, `pcm_frame_assembler`, `jitter_buffer`, `mixer`, `udp_audio_packet_processor`, `microphone_manager`, `headset_manager`, `party_chat_manager`, `yeti_audio_bridge/sink`. (This is why the controller has a 3.5mm jack + mic — it could do party voice chat directly.)
- **Protobuf / RPC** — full protobuf runtime + nanopb, plus generated Google protos (`chrome/cloudcast/*` — "cloudcast" is the internal Cast/Stadia streaming codename; `logs/proto/chrome/cloudcast/*` telemetry protos), `rpc_endpoint/responder/request_sender`, `wire_*`, `json*`, `xml_parser`.
- **Stadia/"Yeti" app layer** — `yeti_http_client/input/runnable/platform`, `gotham_rtc_session_impl`, `streaming_client`, `discovery_client`, `display_connection`, `input_relay`, `game_feedback_relay`, `input_protocol_message_endpoint`, `application_impl`, plus **OOBE** (out-of-box Wi-Fi setup): `oobe_task/server/model/crypto/analytics`. ("Yeti" = Google's internal codename for Stadia; "gotham" for this controller platform.)
- **Wi-Fi driver** — `bcm_wifi.c`, `bcm_wifi_preinit.c` (Broadcom BCM43458), `wifi_base/info/scan/security`, `network_monitor`, `connectivity_manager*`.
- **OTA self-update + telemetry** — `ota_state_machine`, `update_checker/task/settings`, `version_checker`, Google **clearcut** logging (`clearcut_logger/uploader`, `batcher`, `scheduler`), `analytics`, `*_event_logger`, `throttled_logger`, `windowed_histogram`.

Shared base platform (present in BOTH bruce and gotham) — the parts relevant to a BT-only custom firmware: FreeRTOS (heap_5), the Google-forked Broadcom **BTA** Bluetooth stack (GATT/L2CAP/RFCOMM/SPP/HFP/SDP), USB device + **USB host** stack with gamepad drivers (DualShock 3 / Switch Pro / Valve Steam Controller), HID gamepad, and hardware drivers (BQ25601 charger, BQ2742x gauge, LP5562 LED, TUSB320 USB-C, WM8904 codec, TS3A227E headset detect).

## Open threads for next sessions
- Load `bruce` into Ghidra at base 0x60040000 (Cortex-M7/Thumb-2) and `gotham` likewise; auto-analyze. Use the leaked `.cc` filenames (referenced by nearby log/assert strings) to name functions.
- Decode the build-info struct (agent-reported markers didn't match a naive search — revisit; version/build likely near the tail before the CSF block).
- Map the vendor-specific USB interface (class 0xFF, bulk EP7) command set — the firmware/streaming channel; cross-reference with `input_protocol_message_endpoint` / `input_relay`.
- Extract & version the BCM43458 patchram blob (`BTA_PatchRam`; string `;BCM43458F 37.4MHz Google Gotham BT4.2 [Version: 0054.0161]`).
- Diff gotham pvt-a vs pvt-b beyond the base-offset relocation to find real per-HW-rev changes.

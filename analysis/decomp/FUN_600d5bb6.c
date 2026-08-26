// 600d5bb6  FUN_600d5bb6  size=16 bytes
// --- callers ---
//   600d6460 FUN_600d6460
//   600641a8 usb_host_audio_topology__600641a8
//   600644dc usb_host_audio_topology__600644dc
// --- callees ---


uint FUN_600d5bb6(byte *param_1)

{
  return (uint)*param_1 | (uint)param_1[1] << 8 | (uint)param_1[2] << 0x10;
}



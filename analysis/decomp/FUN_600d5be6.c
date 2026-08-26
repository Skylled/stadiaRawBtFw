// 600d5be6  FUN_600d5be6  size=30 bytes
// --- callers ---
//   600d6256 FUN_600d6256
//   600641a8 usb_host_audio_topology__600641a8
// --- callees ---


bool FUN_600d5be6(byte *param_1,byte *param_2)

{
  if (*param_1 != *param_2) {
    return *param_1 < *param_2;
  }
  return param_1[1] < param_2[1];
}



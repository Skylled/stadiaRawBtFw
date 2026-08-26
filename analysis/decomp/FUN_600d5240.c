// 600d5240  FUN_600d5240  size=18 bytes
// --- callers ---
//   600620b4 usb_device_audio__600620b4
//   6007a040 usb_audio_receive__6007a040
//   600d5358 FUN_600d5358
//   600d5284 FUN_600d5284
//   60079f1c usb_audio_receive__60079f1c
//   6007a2c0 frames__6007a2c0
//   60061ed4 usb_device_audio__60061ed4
//   6007a504 usb_audio_receive__6007a504
//   6007a62c usb_audio_receive__6007a62c
//   600d5386 FUN_600d5386
// --- callees ---


bool FUN_600d5240(char *param_1)

{
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  return *param_1 != '\0';
}



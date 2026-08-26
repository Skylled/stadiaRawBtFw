// 600d53ae  FUN_600d53ae  size=22 bytes
// --- callers ---
//   600620b4 usb_device_audio__600620b4
//   60081868 FUN_60081868
//   6007a2c0 frames__6007a2c0
//   60061ed4 usb_device_audio__60061ed4
//   60061fc0 usb_device_audio__60061fc0
//   6007ec28 FUN_6007ec28
//   6007a118 usb_audio_receive__6007a118
//   60077a48 FUN_60077a48
//   6006c340 remote_device_db__6006c340
//   60077948 FUN_60077948
//   6007ec48 receiver__6007ec48
//   6007b600 synapse_audio_processor__6007b600
//   60081808 FUN_60081808
//   6007a504 usb_audio_receive__6007a504
// --- callees ---
//   601016f0 FUN_601016f0


undefined4 * FUN_600d53ae(undefined4 *param_1)

{
  FUN_601016f0(0x1e,*param_1,param_1[1],param_1 + 2);
  return param_1;
}



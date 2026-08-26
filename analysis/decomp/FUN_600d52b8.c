// 600d52b8  FUN_600d52b8  size=12 bytes
// --- callers ---
//   6007a62c usb_audio_receive__6007a62c
// --- callees ---


void FUN_600d52b8(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0x94) = *param_2;
  *(undefined4 *)(param_1 + 0x98) = uVar1;
  return;
}



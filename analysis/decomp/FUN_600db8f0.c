// 600db8f0  FUN_600db8f0  size=18 bytes
// --- callers ---
//   6007a62c usb_audio_receive__6007a62c
// --- callees ---


uint FUN_600db8f0(int param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0x9c8) - *(int *)(param_1 + 0x9c0);
  if (uVar1 < 0xc0) {
    uVar1 = 0;
  }
  return uVar1;
}



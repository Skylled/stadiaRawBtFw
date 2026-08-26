// 600d5386  FUN_600d5386  size=40 bytes
// --- callers ---
//   6007a62c usb_audio_receive__6007a62c
// --- callees ---
//   600d5364 FUN_600d5364
//   600d5240 FUN_600d5240


void FUN_600d5386(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_2[1];
  *(undefined4 *)(param_1 + 0x84) = *param_2;
  *(undefined4 *)(param_1 + 0x88) = uVar2;
  if ((*(char *)(param_1 + 0xad) != '\0') && (iVar1 = FUN_600d5240(param_1 + 0xb0,5), iVar1 == 0)) {
    FUN_600d5364((undefined4 *)(param_1 + 0x84));
  }
  return;
}



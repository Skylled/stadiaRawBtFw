// 600d5284  FUN_600d5284  size=52 bytes
// --- callers ---
//   6007a62c usb_audio_receive__6007a62c
// --- callees ---
//   600d5240 FUN_600d5240


void FUN_600d5284(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_2[1];
  *(undefined4 *)(param_1 + 0x8c) = *param_2;
  *(undefined4 *)(param_1 + 0x90) = uVar2;
  if ((*(char *)(param_1 + 0xad) != '\0') && (iVar1 = FUN_600d5240(param_1 + 0xaf,5), iVar1 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x600d52b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 0x8c))(*(undefined4 *)(param_1 + 0x90),0,0);
    return;
  }
  return;
}



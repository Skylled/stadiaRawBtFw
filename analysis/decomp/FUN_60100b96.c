// 60100b96  FUN_60100b96  size=26 bytes
// --- callers ---
//   60100e08 FUN_60100e08
//   600cb270 FUN_600cb270
//   60100be2 FUN_60100be2
//   60100bb0 FUN_60100bb0
// --- callees ---
//   60100b24 FUN_60100b24


int FUN_60100b96(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *extraout_r2;
  
  iVar1 = FUN_60100b24(*(undefined1 *)(param_1 + 0x59),8,param_1,param_4,param_4);
  return *(int *)(*(int *)(*extraout_r2 + 4) + 4) + iVar1 * -2;
}



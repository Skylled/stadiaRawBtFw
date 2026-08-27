// 6005dbbc  FUN_6005dbbc  size=42 bytes
// --- callers ---
//   60080fb8 FUN_60080fb8
// --- callees ---
//   6004cb28 FUN_6004cb28
//   60101fd8 FUN_60101fd8
//   6005db20 FUN_6005db20


void FUN_6005dbbc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_6004cb28(param_2);
  uVar2 = 0x7fffffff - *(int *)(param_1 + 4);
  if (uVar2 < uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_60101fd8(DAT_6005dbe8);
  }
  FUN_6005db20(param_1,param_2,uVar1,uVar2,param_4);
  return;
}



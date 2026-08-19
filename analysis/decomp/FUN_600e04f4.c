// 600e04f4  FUN_600e04f4  size=46 bytes
// --- callers ---
//   600e064c FUN_600e064c
//   600e05bc FUN_600e05bc
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   6013cf60 thunk_EXT_FUN_000066b8


void FUN_600e04f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r2;
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = thunk_EXT_FUN_000066b8();
  iVar1 = (int)uVar2;
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x100) != *(int *)(iVar1 + 0x104)) {
      iVar1 = iVar1 + *(int *)(iVar1 + 0x100) * 0x10;
      thunk_EXT_FUN_0000ac5e(*(undefined4 *)(iVar1 + 4));
      *(undefined4 *)(iVar1 + 4) = param_1;
      return;
    }
  }
  thunk_EXT_FUN_0000ac5e(param_1,(int)((ulonglong)uVar2 >> 0x20),extraout_r2,param_4);
  return;
}



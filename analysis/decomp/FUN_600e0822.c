// 600e0822  FUN_600e0822  size=32 bytes
// --- callers ---
// --- callees ---
//   600e7450 FUN_600e7450
//   600ea886 FUN_600ea886
//   600ea7fa FUN_600ea7fa
//   6013cff8 thunk_EXT_FUN_0000ac1e


undefined4 FUN_600e0822(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600ea886(*(undefined4 *)(param_1 + 8));
  if (iVar1 != 0) {
    FUN_600ea7fa();
    uVar2 = FUN_600e7450();
    return uVar2;
  }
  thunk_EXT_FUN_0000ac1e();
  return 0;
}



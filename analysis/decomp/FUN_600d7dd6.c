// 600d7dd6  FUN_600d7dd6  size=38 bytes
// --- callers ---
// --- callees ---
//   600ea712 FUN_600ea712
//   600ea6f8 thunk_FUN_600ea6e4


undefined4 FUN_600d7dd6(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = thunk_FUN_600ea6e4();
  *(int *)(param_1 + 0xc) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 8;
  }
  else {
    iVar1 = FUN_600ea712(iVar1,*(undefined4 *)(param_1 + 8));
    if (iVar1 == 0) {
      uVar2 = 0xd;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



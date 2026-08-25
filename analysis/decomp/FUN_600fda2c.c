// 600fda2c  FUN_600fda2c  size=140 bytes
// --- callers ---
// --- callees ---
//   60094d24 FUN_60094d24
//   600f3e6a FUN_600f3e6a
//   600f3c42 FUN_600f3c42


void FUN_600fda2c(undefined2 *param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_12c [6];
  undefined2 local_126;
  
  iVar1 = FUN_600f3c42(*(undefined1 *)(*(int *)(param_1 + 6) + 5),param_2 + 8,1,
                       *(undefined1 *)(param_2 + 0x10));
  if (iVar1 == 0) {
    FUN_60094d24(param_1,0x1d01,param_2);
  }
  else {
    iVar1 = FUN_600f3e6a(*(undefined1 *)(*(int *)(param_1 + 6) + 5),param_2 + 8,param_1,
                         *(undefined1 *)(param_2 + 0x10));
    if (iVar1 != 0) {
      local_126 = *param_1;
      FUN_60094d24(param_1,0x1d0d,auStack_12c);
    }
  }
  return;
}



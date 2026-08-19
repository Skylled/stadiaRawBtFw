// 600da40c  FUN_600da40c  size=24 bytes
// --- callers ---
// --- callees ---
//   60074d3c FUN_60074d3c
//   6013d310 thunk_EXT_FUN_0000b52a


void FUN_600da40c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  FUN_60074d3c(iVar1);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b52a(iVar1);
    return;
  }
  return;
}



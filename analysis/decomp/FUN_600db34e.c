// 600db34e  FUN_600db34e  size=30 bytes
// --- callers ---
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a


void FUN_600db34e(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (*(int *)(iVar1 + 0xa8) != iVar1 + 0xb0) {
    thunk_EXT_FUN_0000b52a();
  }
  thunk_EXT_FUN_0000b52a(iVar1);
  return;
}



// 600d5b1e  FUN_600d5b1e  size=38 bytes
// --- callers ---
//   600d5b1e FUN_600d5b1e
//   600d5b44 FUN_600d5b44
// --- callees ---
//   600d5b1e FUN_600d5b1e
//   6013d310 thunk_EXT_FUN_0000b52a


void FUN_600d5b1e(undefined4 param_1,int param_2)

{
  int iVar1;
  
  while (param_2 != 0) {
    FUN_600d5b1e(param_1,*(undefined4 *)(param_2 + 0xc));
    iVar1 = *(int *)(param_2 + 8);
    if (*(int *)(param_2 + 0x14) != 0) {
      FUN_60101c56();
    }
    thunk_EXT_FUN_0000b52a(param_2);
    param_2 = iVar1;
  }
  return;
}



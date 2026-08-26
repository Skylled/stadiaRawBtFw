// 600d6634  FUN_600d6634  size=36 bytes
// --- callers ---
//   600d6634 FUN_600d6634
//   600d6658 FUN_600d6658
// --- callees ---
//   600d6634 FUN_600d6634
//   600d5bca FUN_600d5bca
//   6013d310 thunk_EXT_FUN_0000b52a


void FUN_600d6634(undefined4 param_1,int param_2)

{
  int iVar1;
  
  while (param_2 != 0) {
    FUN_600d6634(param_1,*(undefined4 *)(param_2 + 0xc));
    iVar1 = *(int *)(param_2 + 8);
    FUN_600d5bca(*(undefined4 *)(param_2 + 0x28));
    thunk_EXT_FUN_0000b52a(param_2);
    param_2 = iVar1;
  }
  return;
}



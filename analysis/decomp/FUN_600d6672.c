// 600d6672  FUN_600d6672  size=38 bytes
// --- callers ---
//   600d6866 FUN_600d6866
//   600d6672 FUN_600d6672
// --- callees ---
//   600d5fc2 FUN_600d5fc2
//   6013d310 thunk_EXT_FUN_0000b52a
//   600d6672 FUN_600d6672


void FUN_600d6672(undefined4 param_1,int param_2)

{
  int iVar1;
  
  while (param_2 != 0) {
    FUN_600d6672(param_1,*(undefined4 *)(param_2 + 0xc));
    iVar1 = *(int *)(param_2 + 8);
    FUN_600d5fc2(param_2 + 0x10);
    thunk_EXT_FUN_0000b52a(param_2);
    param_2 = iVar1;
  }
  return;
}



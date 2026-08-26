// 600d5af4  FUN_600d5af4  size=42 bytes
// --- callers ---
//   600d5b44 FUN_600d5b44
//   600d5af4 FUN_600d5af4
// --- callees ---
//   600d5828 FUN_600d5828
//   600d5af4 FUN_600d5af4
//   6013d310 thunk_EXT_FUN_0000b52a


void FUN_600d5af4(undefined4 param_1,int param_2)

{
  int iVar1;
  
  while (param_2 != 0) {
    FUN_600d5af4(param_1,*(undefined4 *)(param_2 + 0xc));
    iVar1 = *(int *)(param_2 + 8);
    FUN_600d5828(*(undefined4 *)(param_2 + 0x28));
    FUN_600d5828(*(undefined4 *)(param_2 + 0x1c));
    thunk_EXT_FUN_0000b52a(param_2);
    param_2 = iVar1;
  }
  return;
}



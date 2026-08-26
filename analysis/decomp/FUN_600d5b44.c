// 600d5b44  FUN_600d5b44  size=60 bytes
// --- callers ---
//   600d5b80 FUN_600d5b80
// --- callees ---
//   600d5b1e FUN_600d5b1e
//   600d5828 FUN_600d5828
//   6013d068 thunk_EXT_FUN_0000b52e
//   600d5af4 FUN_600d5af4


int FUN_600d5b44(int param_1)

{
  int iVar1;
  
  FUN_600d5828(*(undefined4 *)(param_1 + 0x6c));
  FUN_600d5828(*(undefined4 *)(param_1 + 0x60));
  iVar1 = *(int *)(param_1 + 0x58);
  if (iVar1 != 0) {
    FUN_600d5b1e(iVar1,*(undefined4 *)(iVar1 + 8));
    thunk_EXT_FUN_0000b52e(iVar1,0x18);
  }
  iVar1 = *(int *)(param_1 + 0x54);
  if (iVar1 != 0) {
    FUN_600d5af4(iVar1,*(undefined4 *)(iVar1 + 8));
    thunk_EXT_FUN_0000b52e(iVar1,0x18);
  }
  return param_1;
}



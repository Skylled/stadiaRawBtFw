// 600edc52  FUN_600edc52  size=22 bytes
// --- callers ---
//   600e0cac FUN_600e0cac
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


int FUN_600edc52(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_2 + 0xc);
  if ((iVar1 == 0) && (*(int *)(param_1 + 0xc) != 0)) {
    iVar1 = thunk_EXT_FUN_0000b554(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_2 + 0x10));
    return iVar1;
  }
  return iVar1;
}



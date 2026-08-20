// 600eadd0  FUN_600eadd0  size=30 bytes
// --- callers ---
//   600eadee FUN_600eadee
//   6008d6f8 bcm__6008d6f8
//   600eb400 FUN_600eb400
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


bool FUN_600eadd0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x28) << 2;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = thunk_EXT_FUN_0000b554(param_2,param_3,iVar1,param_2,param_4);
  }
  return iVar1 == 0;
}



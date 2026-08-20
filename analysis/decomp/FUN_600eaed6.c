// 600eaed6  FUN_600eaed6  size=30 bytes
// --- callers ---
//   600eb47c FUN_600eb47c
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


bool FUN_600eaed6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc) << 2;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = thunk_EXT_FUN_0000b554(param_2,param_3,iVar1,param_2,param_4);
  }
  return iVar1 == 0;
}



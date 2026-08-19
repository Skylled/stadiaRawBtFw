// 600dde0c  FUN_600dde0c  size=50 bytes
// --- callers ---
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588


void FUN_600dde0c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2 + 0x104;
  thunk_EXT_FUN_0000b588(param_1,param_2,0x104);
  if (iVar1 != param_2 + 0x208) {
    thunk_EXT_FUN_0000b588(param_1 + 0x104,iVar1,(param_2 + 0x208) - iVar1);
  }
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  return;
}



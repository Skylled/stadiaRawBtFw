// 600d35a0  FUN_600d35a0  size=54 bytes
// --- callers ---
//   601025a8 FUN_601025a8
// --- callees ---
//   6013d128 thunk_EXT_FUN_00007f58
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d180 thunk_EXT_FUN_000080d8


int FUN_600d35a0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    thunk_EXT_FUN_000080d8();
    iVar1 = 0;
  }
  else {
    iVar1 = thunk_EXT_FUN_00007f58(param_3);
    if ((iVar1 != 0) && (param_2 != 0)) {
      thunk_EXT_FUN_0000b572(iVar1,param_2,param_3);
      thunk_EXT_FUN_000080d8(param_2);
    }
  }
  return iVar1;
}



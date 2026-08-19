// 600d9b4c  FUN_600d9b4c  size=16 bytes
// --- callers ---
//   600723b4 FUN_600723b4
//   600722b0 FUN_600722b0
//   60071660 FUN_60071660
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600d9b4c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = thunk_EXT_FUN_0000b5ba(param_1,0,0x50,param_4,param_4);
  *(undefined4 *)(iVar1 + 0x50) = 0;
  return;
}



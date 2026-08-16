// 600d9b6c  FUN_600d9b6c  size=16 bytes
// --- callers ---
//   600723b4 FUN_600723b4
//   60073bf0 timer__60073bf0
//   600722b0 FUN_600722b0
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600d9b6c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = thunk_EXT_FUN_0000b5ba(param_1,0,0x50,param_4,param_4);
  *(undefined4 *)(iVar1 + 0x50) = 0;
  return;
}



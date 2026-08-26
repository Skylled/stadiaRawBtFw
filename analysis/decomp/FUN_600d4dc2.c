// 600d4dc2  FUN_600d4dc2  size=38 bytes
// --- callers ---
//   6005990c sleep_driver__6005990c
// --- callees ---
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6013cef0 thunk_EXT_FUN_0000887a
//   6006073c FUN_6006073c


undefined4 FUN_600d4dc2(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 local_14;
  
  uVar1 = param_1;
  local_14 = param_1;
  thunk_EXT_FUN_0000b4c2();
  uVar1 = FUN_6006073c(param_1,param_2,extraout_r2,extraout_r3,uVar1);
  thunk_EXT_FUN_0000887a(&local_14);
  return uVar1;
}



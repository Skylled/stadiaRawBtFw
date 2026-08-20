// 600e6af2  FUN_600e6af2  size=72 bytes
// --- callers ---
//   6008af3c FUN_6008af3c
// --- callees ---
//   600e1e7a FUN_600e1e7a
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600e6ac2 FUN_600e6ac2


void FUN_600e6af2(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 local_30;
  undefined1 auStack_2c [4];
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_18;
  
  thunk_EXT_FUN_0000b5ba(auStack_2c,0,0x1c);
  local_30 = *param_2;
  local_28 = param_2[1];
  local_20 = param_2[2];
  local_18 = param_2[3];
  FUN_600e6ac2(&local_30);
  FUN_600e1e7a(&local_30);
  FUN_600e6ac2(&local_30);
  *param_1 = local_30;
  param_1[1] = local_28;
  param_1[2] = local_20;
  param_1[3] = local_18;
  return;
}



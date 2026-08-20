// 600e6996  FUN_600e6996  size=22 bytes
// --- callers ---
//   600eba2c FUN_600eba2c
//   600ebae8 FUN_600ebae8
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88


undefined4 FUN_600e6996(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = param_2;
  uStack_8 = param_3;
  thunk_EXT_FUN_0000af88(&local_c,param_1,4,param_4,param_1);
  return local_c;
}



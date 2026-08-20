// 600ec31c  FUN_600ec31c  size=46 bytes
// --- callers ---
//   600e1d72 FUN_600e1d72
// --- callees ---
//   600ec12c FUN_600ec12c
//   60050b70 FUN_60050b70
//   600ec1e0 FUN_600ec1e0
//   6013cfb0 thunk_EXT_FUN_0000ac52


undefined4 FUN_600ec31c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 extraout_r1;
  undefined1 auStack_e8 [220];
  
  FUN_60050b70(auStack_e8);
  FUN_600ec12c(auStack_e8,param_1,extraout_r1);
  FUN_600ec1e0(param_3,auStack_e8);
  thunk_EXT_FUN_0000ac52(auStack_e8,0xd8);
  return param_3;
}



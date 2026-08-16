// 600d9c0a  FUN_600d9c0a  size=112 bytes
// --- callers ---
//   60073bf0 timer__60073bf0
// --- callees ---
//   600d9b5c FUN_600d9b5c
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4 *
FUN_600d9c0a(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  FUN_600d9b5c(param_1 + 1);
  *(undefined1 *)(param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x59) = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  thunk_EXT_FUN_0000b5ba(param_1 + 0x1a,0,0x50,0,param_4);
  thunk_EXT_FUN_0000b5ba(param_1 + 0x2e,0,0xa0);
  param_1[0x2e] = 0xffffffff;
  param_1[0x2f] = 0xffffffff;
  thunk_EXT_FUN_0000b5ba(param_1 + 0x56,0,0x960);
  *(undefined1 *)(param_1 + 0x2ae) = 0;
  thunk_EXT_FUN_0000b5ba((int)param_1 + 0xab9,0,0x10);
  thunk_EXT_FUN_0000b5ba((int)param_1 + 0xac9,0,0x40);
  return param_1;
}



// 600d951c  FUN_600d951c  size=40 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4
FUN_600d951c(undefined4 param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  thunk_EXT_FUN_0000b5ba(param_2 + 2,0,0x2e);
  *param_2 = 2;
  param_2[4] = (char)((uint)param_3 >> 8);
  param_2[3] = (char)((uint)param_4 >> 8);
  param_2[1] = 3;
  return 0;
}



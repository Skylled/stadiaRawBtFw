// 600d9850  FUN_600d9850  size=46 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4
FUN_600d9850(undefined4 param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  thunk_EXT_FUN_0000b5ba(param_2,0,0xd);
  *param_2 = 9;
  param_2[3] = 9;
  param_2[8] = (char)((uint)param_3 >> 8);
  param_2[5] = 3;
  param_2[9] = (char)((uint)param_4 >> 8);
  param_2[10] = 0xff;
  return 0;
}



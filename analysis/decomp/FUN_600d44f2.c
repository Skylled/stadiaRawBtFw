// 600d44f2  FUN_600d44f2  size=94 bytes
// --- callers ---
//   60080ee8 FUN_60080ee8
//   600810bc types__600810bc
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined1 * FUN_600d44f2(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  thunk_EXT_FUN_0000b5ba(param_1 + 8,0,0x1f);
  param_1[8] = 9;
  *(undefined4 *)(param_1 + 0x28) = 0;
  thunk_EXT_FUN_0000b5ba(param_1 + 0x2c,0,0x1f);
  param_1[0x2c] = 2;
  param_1[0x4b] = 0;
  thunk_EXT_FUN_0000b5ba(param_1 + 0x4c,0,0x1f);
  param_1[0x6b] = 0;
  thunk_EXT_FUN_0000b5ba(param_1 + 0x6c,0,0x1f);
  param_1[0x8b] = 0;
  return param_1;
}



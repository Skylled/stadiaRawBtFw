// 600decf8  FUN_600decf8  size=30 bytes
// --- callers ---
//   6007f540 receiver__6007f540
//   6007f454 receiver__6007f454
// --- callees ---
//   6013d3c8 thunk_EXT_FUN_00001680


void FUN_600decf8(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = param_1[1];
  *param_1 = 0;
  param_1[1] = 0;
  uStack_8 = param_3;
  thunk_EXT_FUN_00001680(&local_c);
  return;
}



// 600d31e6  FUN_600d31e6  size=28 bytes
// --- callers ---
//   600d3202 FUN_600d3202
//   60057ee4 FUN_60057ee4
// --- callees ---
//   6013d3e0 thunk_EXT_FUN_00008802
//   600d15e8 FUN_600d15e8


void FUN_600d31e6(undefined1 *param_1,undefined4 param_2)

{
  undefined4 uStack_c;
  
  uStack_c = param_2;
  thunk_EXT_FUN_00008802((int)&uStack_c + 3);
  *param_1 = 0;
  FUN_600d15e8(uStack_c._3_1_);
  return;
}



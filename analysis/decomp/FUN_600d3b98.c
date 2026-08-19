// 600d3b98  FUN_600d3b98  size=24 bytes
// --- callers ---
//   6005a9fc FUN_6005a9fc
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588


void FUN_600d3b98(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  if (param_3 == 1) {
    *param_1 = *param_2;
  }
  else if (param_3 != 0) {
    thunk_EXT_FUN_0000b588();
    return;
  }
  return;
}



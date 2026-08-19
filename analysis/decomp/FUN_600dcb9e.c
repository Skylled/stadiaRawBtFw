// 600dcb9e  FUN_600dcb9e  size=24 bytes
// --- callers ---
//   600dcbf8 FUN_600dcbf8
//   600dcc10 FUN_600dcc10
// --- callees ---
//   6013d068 thunk_EXT_FUN_0000b52e
//   6013d310 thunk_EXT_FUN_0000b52a


void FUN_600dcb9e(int *param_1)

{
  if (*param_1 != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  thunk_EXT_FUN_0000b52e(param_1,0xc);
  return;
}



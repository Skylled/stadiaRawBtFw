// 600ea6fc  FUN_600ea6fc  size=22 bytes
// --- callers ---
//   60067dc4 FUN_60067dc4
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   6013d020 thunk_EXT_FUN_0000b070


void FUN_600ea6fc(int param_1)

{
  if (param_1 != 0) {
    thunk_EXT_FUN_0000b070();
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  return;
}



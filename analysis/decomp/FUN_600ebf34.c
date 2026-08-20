// 600ebf34  FUN_600ebf34  size=30 bytes
// --- callers ---
//   6008ea5c FUN_6008ea5c
// --- callees ---
//   600e6a22 FUN_600e6a22
//   6013d208 thunk_EXT_FUN_0000ac5e


void FUN_600ebf34(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_600e6a22(*param_1);
    FUN_600e6a22(param_1[1]);
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  return;
}



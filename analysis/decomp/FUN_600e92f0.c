// 600e92f0  FUN_600e92f0  size=30 bytes
// --- callers ---
//   6008c334 bcm__6008c334
//   600e9b62 FUN_600e9b62
//   6008c0d8 bcm__6008c0d8
//   600e9af4 FUN_600e9af4
//   600ea7a4 FUN_600ea7a4
//   600910dc FUN_600910dc
//   600e930e FUN_600e930e
//   6008d228 bcm__6008d228
//   6008ea5c FUN_6008ea5c
// --- callees ---
//   600e6a22 FUN_600e6a22
//   6013d208 thunk_EXT_FUN_0000ac5e


void FUN_600e92f0(int param_1)

{
  if (param_1 != 0) {
    FUN_600e6a22();
    FUN_600e6a22(param_1 + 0x14);
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  return;
}



// 600d9b5c  FUN_600d9b5c  size=16 bytes
// --- callers ---
//   600723b4 FUN_600723b4
//   60073bf0 timer__60073bf0
//   60072260 FUN_60072260
//   600d9c0a FUN_600d9c0a
// --- callees ---
//   601017e8 FUN_601017e8


int FUN_600d9b5c(int param_1)

{
  *(undefined4 *)(param_1 + 0x50) = 0;
  FUN_601017e8();
  return param_1;
}



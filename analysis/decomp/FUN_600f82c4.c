// 600f82c4  FUN_600f82c4  size=38 bytes
// --- callers ---
//   600b7374 FUN_600b7374
//   600b7b48 FUN_600b7b48
//   600b7800 FUN_600b7800
//   600b7674 FUN_600b7674
//   600b7cba FUN_600b7cba
//   600bbd3c FUN_600bbd3c
// --- callees ---
//   600aa4c4 FUN_600aa4c4


void FUN_600f82c4(int param_1)

{
  if (*(char *)(param_1 + 0x116) != '\0') {
    FUN_600aa4c4(param_1 + 0x100);
  }
  return;
}



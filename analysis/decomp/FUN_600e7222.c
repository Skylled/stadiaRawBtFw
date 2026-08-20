// 600e7222  FUN_600e7222  size=24 bytes
// --- callers ---
// --- callees ---
//   600e721a FUN_600e721a


undefined4 FUN_600e7222(int param_1)

{
  FUN_600e721a(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  return 1;
}



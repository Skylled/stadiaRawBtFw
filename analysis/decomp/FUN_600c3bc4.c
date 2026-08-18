// 600c3bc4  FUN_600c3bc4  size=50 bytes
// --- callers ---
//   600c3b88 FUN_600c3b88
//   600c309c FUN_600c309c
//   600c41c0 FUN_600c41c0
// --- callees ---
//   600c5f64 FUN_600c5f64


void FUN_600c3bc4(void)

{
  if (*DAT_600c3bf8 != 0) {
    (*(code *)*DAT_600c3bf8)(6,0);
  }
  if (*(char *)((int)DAT_600c3bf8 + 0x149) != '\0') {
    FUN_600c5f64(DAT_600c3bfc);
  }
  return;
}



// 600a0fd4  FUN_600a0fd4  size=96 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a0cac FUN_600a0cac


void FUN_600a0fd4(void)

{
  if ((*(byte *)(DAT_600a1034 + 0x88e) & 2) != 0) {
    *(byte *)(DAT_600a1034 + 0x88e) = *(byte *)(DAT_600a1034 + 0x88e) & 0xfd;
    if ((*(byte *)(DAT_600a1034 + 0x824) & 1) != 0) {
      *(byte *)(DAT_600a1034 + 0x88e) = *(byte *)(DAT_600a1034 + 0x88e) | 0x20;
    }
    FUN_600a0cac();
  }
  return;
}



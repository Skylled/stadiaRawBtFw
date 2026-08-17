// 600a1038  FUN_600a1038  size=96 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a0cac FUN_600a0cac


void FUN_600a1038(void)

{
  if ((*(byte *)(DAT_600a1098 + 0x88e) & 4) != 0) {
    *(byte *)(DAT_600a1098 + 0x88e) = *(byte *)(DAT_600a1098 + 0x88e) & 0xfb;
    if ((*(byte *)(DAT_600a1098 + 0x88e) & 8) != 0) {
      *(byte *)(DAT_600a1098 + 0x88e) = *(byte *)(DAT_600a1098 + 0x88e) & 0xf7;
    }
    FUN_600a0cac();
  }
  return;
}



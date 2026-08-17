// 600a24c8  FUN_600a24c8  size=122 bytes
// --- callers ---
//   600a6184 FUN_600a6184
// --- callees ---
//   600b1ef8 FUN_600b1ef8
//   600a1cac FUN_600a1cac


void FUN_600a24c8(void)

{
  if (*(char *)(DAT_600a2544 + 0x1113) != '\0') {
    if (*(char *)(DAT_600a2544 + 0x1111) == '\x03') {
      if ((*(byte *)(DAT_600a2544 + 0x1112) & 8) == 0) {
        if ((*(byte *)(DAT_600a2544 + 0x1112) & 3) != 0) {
          FUN_600b1ef8();
        }
      }
      else {
        FUN_600a1cac();
      }
    }
    *(byte *)(DAT_600a2544 + 0x1112) = *(byte *)(DAT_600a2544 + 0x1112) | 4;
  }
  return;
}



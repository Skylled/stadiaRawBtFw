// 600a804c  FUN_600a804c  size=98 bytes
// --- callers ---
//   600a67ec FUN_600a67ec
//   600a74dc FUN_600a74dc
//   600a6d70 FUN_600a6d70
//   600a8108 FUN_600a8108
// --- callees ---
//   600b33a4 FUN_600b33a4
//   600b3790 FUN_600b3790


void FUN_600a804c(void)

{
  if (*(char *)(DAT_600a80b0 + 0x1178) != '\0') {
    *(undefined1 *)(DAT_600a80b0 + 0x1178) = 0;
    FUN_600b3790(*(char *)(DAT_600a80b0 + 0x1174) == '\x03');
  }
  if (*(char *)(DAT_600a80b0 + 0x1179) != '\0') {
    *(undefined1 *)(DAT_600a80b0 + 0x1179) = 0;
    FUN_600b33a4(*(undefined1 *)(DAT_600a80b0 + 0xf9));
  }
  return;
}



// 600968b0  FUN_600968b0  size=122 bytes
// --- callers ---
//   60096e38 FUN_60096e38
// --- callees ---
//   6006ec00 FUN_6006ec00
//   600969e0 FUN_600969e0
//   600d9380 FUN_600d9380
//   60096594 FUN_60096594


undefined4 FUN_600968b0(void)

{
  if (((*(char *)(DAT_6009692c + 100) != '\0') && (*(char *)(DAT_6009692c + 0x67) != '\0')) &&
     ((*(char *)(DAT_6009692c + 0x89) == '\x01' ||
      ((*(char *)(DAT_6009692c + 0x89) == '\x02' || (*(char *)(DAT_6009692c + 0x89) == '\a')))))) {
    FUN_6006ec00(4,1,*(char *)(DAT_6009692c + 0x8c) != '\0');
    FUN_600d9380(0x14);
  }
  FUN_60096594();
  *(undefined1 *)(DAT_6009692c + 0x67) = 0;
  FUN_600969e0(0);
  return 1;
}



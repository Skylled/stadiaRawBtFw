// 60096858  FUN_60096858  size=84 bytes
// --- callers ---
//   6006ba0c FUN_6006ba0c
// --- callees ---
//   6006ec00 FUN_6006ec00


void FUN_60096858(void)

{
  if ((*(char *)(DAT_600968ac + 100) != '\0') &&
     (((*(char *)(DAT_600968ac + 0x89) == '\x01' || (*(char *)(DAT_600968ac + 0x89) == '\x02')) ||
      (*(char *)(DAT_600968ac + 0x89) == '\a')))) {
    FUN_6006ec00(4,1,*(char *)(DAT_600968ac + 0x8c) == '\0');
  }
  return;
}



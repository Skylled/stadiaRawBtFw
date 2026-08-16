// 600aa4f4  FUN_600aa4f4  size=44 bytes
// --- callers ---
//   600a9fce FUN_600a9fce
// --- callees ---
//   600aa534 FUN_600aa534
//   6006e160 FUN_6006e160
//   6006be9c FUN_6006be9c


void FUN_600aa4f4(void)

{
  FUN_600aa534(DAT_600aa520);
  FUN_6006be9c(DAT_600aa528,DAT_600aa524);
  if (*(int *)(DAT_600aa52c + 0x40) == 0) {
    FUN_6006e160(2);
    FUN_6006be9c(DAT_600aa528,DAT_600aa530);
  }
  return;
}



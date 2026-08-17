// 600a109c  FUN_600a109c  size=64 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a0cac FUN_600a0cac


void FUN_600a109c(void)

{
  if ((*(byte *)(DAT_600a10dc + 0x88e) & 0x20) != 0) {
    *(byte *)(DAT_600a10dc + 0x88e) = *(byte *)(DAT_600a10dc + 0x88e) & 0xdf;
    FUN_600a0cac();
  }
  return;
}



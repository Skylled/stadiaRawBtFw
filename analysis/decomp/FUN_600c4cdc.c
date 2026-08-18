// 600c4cdc  FUN_600c4cdc  size=50 bytes
// --- callers ---
// --- callees ---
//   600c2f68 FUN_600c2f68


void FUN_600c4cdc(void)

{
  if (*(short *)(DAT_600c4d10 + 0x242) == 0x200) {
    *(undefined1 *)(DAT_600c4d10 + 0x264) = 1;
    *(undefined2 *)(DAT_600c4d10 + 0x242) = 0;
    FUN_600c2f68(DAT_600c4d14);
  }
  return;
}



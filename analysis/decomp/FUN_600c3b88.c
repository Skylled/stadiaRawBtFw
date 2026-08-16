// 600c3b88  FUN_600c3b88  size=52 bytes
// --- callers ---
// --- callees ---
//   600c3bc4 FUN_600c3bc4
//   6006ddd8 FUN_6006ddd8


void FUN_600c3b88(void)

{
  if (*(int *)(DAT_600c3bbc + 0x14) != 0) {
    FUN_6006ddd8(*(undefined4 *)(DAT_600c3bbc + 0x14),DAT_600c3bc0,0x815);
    *(undefined4 *)(DAT_600c3bbc + 0x14) = 0;
  }
  FUN_600c3bc4(0);
  return;
}



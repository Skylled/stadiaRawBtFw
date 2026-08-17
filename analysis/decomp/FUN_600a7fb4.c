// 600a7fb4  FUN_600a7fb4  size=72 bytes
// --- callers ---
// --- callees ---
//   600f1f82 FUN_600f1f82
//   600a7b44 FUN_600a7b44


void FUN_600a7fb4(void)

{
  char cVar1;
  
  *(undefined4 *)(DAT_600a7ffc + 0x1160) = 0;
  cVar1 = FUN_600a7b44(*(undefined4 *)(DAT_600a7ffc + 0x114c));
  if (cVar1 != '\x01') {
    FUN_600f1f82(*(undefined4 *)(DAT_600a7ffc + 0x114c),cVar1,0);
  }
  return;
}



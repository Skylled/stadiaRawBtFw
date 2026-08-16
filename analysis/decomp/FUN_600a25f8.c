// 600a25f8  FUN_600a25f8  size=64 bytes
// --- callers ---
//   600a29a0 FUN_600a29a0
//   600a2338 FUN_600a2338
//   600a1efc FUN_600a1efc
//   600a2f3c FUN_600a2f3c
// --- callees ---
//   6006ddd8 FUN_6006ddd8


void FUN_600a25f8(void)

{
  int iVar1;
  
  iVar1 = DAT_600a2638;
  if (*(int *)(DAT_600a2638 + 0x60) != 0) {
    FUN_6006ddd8(*(undefined4 *)(DAT_600a2638 + 0x60),DAT_600a263c,0x683);
    *(undefined4 *)(iVar1 + 0x60) = 0;
  }
  *(undefined2 *)(iVar1 + 100) = 0;
  *(undefined2 *)(iVar1 + 0x66) = 0;
  return;
}



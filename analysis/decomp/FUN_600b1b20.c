// 600b1b20  FUN_600b1b20  size=96 bytes
// --- callers ---
//   6009f3c0 FUN_6009f3c0
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b1b20(void)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xb,DAT_600b1b80,0x427);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x29;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_600a9234(0,iVar1,0,(undefined1 *)(iVar1 + 10),iVar1 + 0xb);
  }
  return iVar1 != 0;
}



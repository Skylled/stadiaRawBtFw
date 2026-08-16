// 600b1b84  FUN_600b1b84  size=96 bytes
// --- callers ---
//   600a027c FUN_600a027c
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b1b84(void)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xb,DAT_600b1be4,0x43c);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x2a;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_600a9234(0,iVar1,0,(undefined1 *)(iVar1 + 10),iVar1 + 0xb);
  }
  return iVar1 != 0;
}



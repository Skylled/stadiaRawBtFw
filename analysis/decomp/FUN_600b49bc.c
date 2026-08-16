// 600b49bc  FUN_600b49bc  size=96 bytes
// --- callers ---
//   600a01f0 FUN_600a01f0
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b49bc(void)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xb,DAT_600b4a1c,0xc2d);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 5;
    *(undefined1 *)(iVar1 + 9) = 0x10;
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_600a9234(0,iVar1,0,(undefined1 *)(iVar1 + 10),iVar1 + 0xb);
  }
  return iVar1 != 0;
}



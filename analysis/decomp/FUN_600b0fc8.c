// 600b0fc8  FUN_600b0fc8  size=96 bytes
// --- callers ---
//   600b54d4 FUN_600b54d4
//   6009c444 FUN_6009c444
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b0fc8(void)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xb,DAT_600b1028,0x175);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0xe;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_600a9234(0,iVar1,0,(undefined1 *)(iVar1 + 10),iVar1 + 0xb);
  }
  return iVar1 != 0;
}



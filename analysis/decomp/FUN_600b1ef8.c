// 600b1ef8  FUN_600b1ef8  size=94 bytes
// --- callers ---
//   6009e4d0 FUN_6009e4d0
//   600a2ab0 FUN_600a2ab0
//   600a1efc FUN_600a1efc
//   600a24c8 FUN_600a24c8
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b1ef8(void)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xb,DAT_600b1f58,0x61);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 3;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 2;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 0;
    FUN_600a9234(0,iVar1,0,(undefined1 *)(iVar1 + 10),iVar1 + 0xb);
  }
  return iVar1 != 0;
}



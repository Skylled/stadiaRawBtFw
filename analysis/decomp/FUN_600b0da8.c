// 600b0da8  FUN_600b0da8  size=126 bytes
// --- callers ---
//   600f1592 FUN_600f1592
//   6009e6c0 FUN_6009e6c0
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b0da8(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xd,DAT_600b0e28,0x133);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 5;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0xc;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 2;
    *(undefined1 *)(iVar1 + 0xb) = param_1;
    *(undefined1 *)(iVar1 + 0xc) = param_2;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



// 600b1640  FUN_600b1640  size=126 bytes
// --- callers ---
//   6009a8ec FUN_6009a8ec
//   600a0cac FUN_600a0cac
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b1640(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xd,DAT_600b16c0,0x2ed);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 5;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x6d;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 2;
    *(undefined1 *)(iVar1 + 0xb) = param_1;
    *(undefined1 *)(iVar1 + 0xc) = param_2;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



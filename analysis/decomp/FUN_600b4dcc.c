// 600b4dcc  FUN_600b4dcc  size=110 bytes
// --- callers ---
//   600a0cac FUN_600a0cac
// --- callees ---
//   600a9234 FUN_600a9234
//   6006dbac FUN_6006dbac


bool FUN_600b4dcc(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xc,DAT_600b4e3c,0x1047);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 4;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x7a;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 1;
    *(undefined1 *)(iVar1 + 0xb) = param_1;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



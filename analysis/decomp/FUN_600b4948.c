// 600b4948  FUN_600b4948  size=110 bytes
// --- callers ---
//   600a031c FUN_600a031c
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b4948(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xc,DAT_600b49b8,0xc17);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 4;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 4;
    *(undefined1 *)(iVar1 + 9) = 0x10;
    *(undefined1 *)(iVar1 + 10) = 1;
    *(undefined1 *)(iVar1 + 0xb) = param_1;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



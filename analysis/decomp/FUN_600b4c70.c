// 600b4c70  FUN_600b4c70  size=110 bytes
// --- callers ---
//   600a1b68 FUN_600a1b68
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b4c70(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xc,DAT_600b4ce0,0xe27);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 4;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x43;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 1;
    *(undefined1 *)(iVar1 + 0xb) = param_1;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



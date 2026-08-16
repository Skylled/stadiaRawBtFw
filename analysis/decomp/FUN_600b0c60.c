// 600b0c60  FUN_600b0c60  size=110 bytes
// --- callers ---
//   6009e84c FUN_6009e84c
//   6009e8fc FUN_6009e8fc
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b0c60(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xc,DAT_600b0cd0,0x101);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 4;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 10;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 1;
    *(undefined1 *)(iVar1 + 0xb) = param_1;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



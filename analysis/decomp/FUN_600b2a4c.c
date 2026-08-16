// 600b2a4c  FUN_600b2a4c  size=128 bytes
// --- callers ---
//   60098f88 FUN_60098f88
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b2a4c(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xd,DAT_600b2acc,0x278);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 5;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x1d;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 2;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



// 600b1cf0  FUN_600b1cf0  size=128 bytes
// --- callers ---
//   600a0600 FUN_600a0600
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b1cf0(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xd,DAT_600b1d70,0x495);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 5;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x2e;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 2;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



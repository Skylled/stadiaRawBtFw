// 600b4e40  FUN_600b4e40  size=74 bytes
// --- callers ---
//   600a8494 FUN_600a8494
// --- callees ---
//   6006dbac FUN_6006dbac


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_600b4e40(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xd,_DAT_600b4ec0,0x1077);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 5;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x7b;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 2;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



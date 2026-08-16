// 600b3a80  FUN_600b3a80  size=166 bytes
// --- callers ---
//   600f0406 FUN_600f0406
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b3a80(undefined1 param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xf,DAT_600b3b28,0x839);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 7;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x37;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 4;
    *(char *)(iVar1 + 0xb) = (char)param_2;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_2 >> 8);
    *(char *)(iVar1 + 0xd) = (char)param_3;
    *(char *)(iVar1 + 0xe) = (char)((ushort)param_3 >> 8);
    FUN_600a9234(param_1,iVar1);
  }
  return iVar1 != 0;
}



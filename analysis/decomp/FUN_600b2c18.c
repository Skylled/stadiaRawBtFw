// 600b2c18  FUN_600b2c18  size=260 bytes
// --- callers ---
//   600a3a38 FUN_600a3a38
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b2c18(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x15,DAT_600b2d1c,0x329);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 0xd;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 3;
    *(undefined1 *)(iVar1 + 9) = 8;
    *(undefined1 *)(iVar1 + 10) = 10;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    *(char *)(iVar1 + 0xd) = (char)param_2;
    *(char *)(iVar1 + 0xe) = (char)((ushort)param_2 >> 8);
    *(char *)(iVar1 + 0xf) = (char)param_3;
    *(char *)(iVar1 + 0x10) = (char)((ushort)param_3 >> 8);
    *(char *)(iVar1 + 0x11) = (char)param_4;
    *(char *)(iVar1 + 0x12) = (char)((ushort)param_4 >> 8);
    *(char *)(iVar1 + 0x13) = (char)param_5;
    *(char *)(iVar1 + 0x14) = (char)((ushort)param_5 >> 8);
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



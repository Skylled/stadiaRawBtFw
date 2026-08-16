// 600b16c4  FUN_600b16c4  size=316 bytes
// --- callers ---
//   600f7f74 FUN_600f7f74
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b16c4(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5,undefined2 param_6,undefined2 param_7)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x19,DAT_600b1800,0x34d);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 0x11;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x20;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0xe;
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
    *(char *)(iVar1 + 0x15) = (char)param_6;
    *(char *)(iVar1 + 0x16) = (char)((ushort)param_6 >> 8);
    *(char *)(iVar1 + 0x17) = (char)param_7;
    *(char *)(iVar1 + 0x18) = (char)((ushort)param_7 >> 8);
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



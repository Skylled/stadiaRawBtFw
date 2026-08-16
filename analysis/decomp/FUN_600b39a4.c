// 600b39a4  FUN_600b39a4  size=214 bytes
// --- callers ---
//   600a0484 FUN_600a0484
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b39a4(undefined2 param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x12,DAT_600b3a7c,0x7ec);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 10;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x33;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 7;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    *(undefined1 *)(iVar1 + 0xd) = param_2;
    *(char *)(iVar1 + 0xe) = (char)param_3;
    *(char *)(iVar1 + 0xf) = (char)((ushort)param_3 >> 8);
    *(char *)(iVar1 + 0x10) = (char)param_4;
    *(char *)(iVar1 + 0x11) = (char)((ushort)param_4 >> 8);
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



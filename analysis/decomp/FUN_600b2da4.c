// 600b2da4  FUN_600b2da4  size=192 bytes
// --- callers ---
//   600a3a38 FUN_600a3a38
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b2da4(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x11,DAT_600b2e64,0x35a);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 9;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 5;
    *(undefined1 *)(iVar1 + 9) = 8;
    *(undefined1 *)(iVar1 + 10) = 6;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    *(char *)(iVar1 + 0xd) = (char)param_2;
    *(char *)(iVar1 + 0xe) = (char)((ushort)param_2 >> 8);
    *(char *)(iVar1 + 0xf) = (char)param_3;
    *(char *)(iVar1 + 0x10) = (char)((ushort)param_3 >> 8);
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



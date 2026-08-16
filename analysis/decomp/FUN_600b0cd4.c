// 600b0cd4  FUN_600b0cd4  size=208 bytes
// --- callers ---
//   6009bfb0 FUN_6009bfb0
//   6009c59c FUN_6009c59c
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b0cd4(undefined1 param_1,undefined2 param_2,undefined2 param_3,undefined1 param_4,
                 undefined1 param_5)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x12,DAT_600b0da4,0x119);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 10;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0xb;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 7;
    *(undefined1 *)(iVar1 + 0xb) = param_1;
    *(char *)(iVar1 + 0xc) = (char)param_2;
    *(char *)(iVar1 + 0xd) = (char)((ushort)param_2 >> 8);
    *(char *)(iVar1 + 0xe) = (char)param_3;
    *(char *)(iVar1 + 0xf) = (char)((ushort)param_3 >> 8);
    *(undefined1 *)(iVar1 + 0x10) = param_4;
    *(undefined1 *)(iVar1 + 0x11) = param_5;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



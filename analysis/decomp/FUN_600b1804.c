// 600b1804  FUN_600b1804  size=144 bytes
// --- callers ---
//   600f7f74 FUN_600f7f74
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b1804(undefined2 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xe,DAT_600b1894,0x369);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 6;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x21;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 3;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    *(undefined1 *)(iVar1 + 0xd) = param_2;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



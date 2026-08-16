// 600b2f80  FUN_600b2f80  size=162 bytes
// --- callers ---
//   600f0252 FUN_600f0252
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b2f80(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xf,DAT_600b3024,0x3e9);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 7;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0xd;
    *(undefined1 *)(iVar1 + 9) = 8;
    *(undefined1 *)(iVar1 + 10) = 4;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    *(char *)(iVar1 + 0xd) = (char)param_2;
    *(char *)(iVar1 + 0xe) = (char)((ushort)param_2 >> 8);
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



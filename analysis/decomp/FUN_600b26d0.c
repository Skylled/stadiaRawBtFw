// 600b26d0  FUN_600b26d0  size=144 bytes
// --- callers ---
//   6009931c FUN_6009931c
//   600994b8 FUN_600994b8
//   60099dd0 FUN_60099dd0
//   600f1ef0 FUN_600f1ef0
//   6009a5b0 FUN_6009a5b0
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b26d0(undefined2 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xe,DAT_600b2760,0x1d3);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 6;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x13;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 3;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    *(undefined1 *)(iVar1 + 0xd) = param_2;
    FUN_600a9234(0,iVar1);
  }
  return iVar1 != 0;
}



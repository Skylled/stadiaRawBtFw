// 600b218c  FUN_600b218c  size=148 bytes
// --- callers ---
//   600f9d16 FUN_600f9d16
//   600f1ce4 FUN_600f1ce4
//   600b6378 FUN_600b6378
//   600b8d7c FUN_600b8d7c
//   600f04e4 FUN_600f04e4
//   600fa0d6 FUN_600fa0d6
//   60099dd0 FUN_60099dd0
//   600a7268 FUN_600a7268
//   60099584 FUN_60099584
// --- callees ---
//   600a9234 FUN_600a9234
//   6009a804 FUN_6009a804
//   6006dbac FUN_6006dbac


bool FUN_600b218c(undefined2 param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0xe,DAT_600b2220,0xcd);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 6;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 6;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 3;
    *(char *)(iVar1 + 0xb) = (char)param_1;
    *(char *)(iVar1 + 0xc) = (char)((ushort)param_1 >> 8);
    *(undefined1 *)(iVar1 + 0xd) = param_2;
    FUN_600a9234(0,iVar1);
    FUN_6009a804(1);
  }
  return iVar1 != 0;
}



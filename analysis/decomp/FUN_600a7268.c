// 600a7268  FUN_600a7268  size=154 bytes
// --- callers ---
//   600a62cc FUN_600a62cc
//   600b5720 FUN_600b5720
//   600b5540 FUN_600b5540
//   600b8d7c FUN_600b8d7c
//   600fa0d6 FUN_600fa0d6
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600f1ce4 FUN_600f1ce4
//   6009feb8 FUN_6009feb8
//   600b218c FUN_600b218c


undefined4 FUN_600a7268(undefined2 param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_6009feb8(param_1);
  if (iVar1 == 0) {
    FUN_600b218c(param_1,param_2);
    uVar3 = 0;
  }
  else if (((*(char *)(DAT_600a7304 + 0x118c) == '\0') ||
           (iVar2 = thunk_EXT_FUN_0000b554(DAT_600a7308,iVar1 + 0x10,6), iVar2 != 0)) ||
          ((*(byte *)(DAT_600a7304 + 0x118d) & 1) == 0)) {
    uVar3 = FUN_600f1ce4(iVar1,param_2,param_1);
  }
  else {
    *(byte *)(DAT_600a7304 + 0x118d) = *(byte *)(DAT_600a7304 + 0x118d) | 4;
    uVar3 = 2;
  }
  return uVar3;
}



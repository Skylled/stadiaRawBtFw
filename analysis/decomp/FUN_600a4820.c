// 600a4820  FUN_600a4820  size=348 bytes
// --- callers ---
//   600a4a20 FUN_600a4a20
//   600c2d00 FUN_600c2d00
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600a5670 FUN_600a5670
//   6009ff18 FUN_6009ff18
//   600a2180 FUN_600a2180
//   600f8c0a FUN_600f8c0a
//   600f1ce4 FUN_600f1ce4
//   600c05e4 FUN_600c05e4
//   600b2224 FUN_600b2224


undefined4 FUN_600a4820(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_6009ff18(param_1);
  if ((iVar1 == 0) || (iVar2 = thunk_EXT_FUN_0000b554(DAT_600a497c,param_1,6), iVar2 != 0)) {
    uVar3 = 7;
  }
  else if (*(char *)(DAT_600a4980 + 0x118d) < '\0') {
    if ((*(char *)(iVar1 + 0x50) == '\x01') && (iVar1 = FUN_600c05e4(param_1), iVar1 != 0)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 6;
    }
  }
  else {
    if ((*(char *)(DAT_600a4980 + 0x118c) == '\x03') &&
       ((*(byte *)(DAT_600a4980 + 0x118d) & 1) != 0)) {
      FUN_600a5670();
      return 0;
    }
    if ((*(char *)(DAT_600a4980 + 0x118c) == '\0') || ((*(byte *)(DAT_600a4980 + 0x118d) & 1) == 0))
    {
      uVar3 = 6;
    }
    else if (*(short *)(iVar1 + 0xc) == -1) {
      if ((*(byte *)(DAT_600a4980 + 0x118d) & 4) == 0) {
        if (*(char *)(DAT_600a4980 + 0x118c) == '\x01') {
          FUN_600a2180();
          *(byte *)(DAT_600a4980 + 0x118d) = *(byte *)(DAT_600a4980 + 0x118d) | 0x40;
          uVar3 = 1;
        }
        else {
          uVar3 = 0xb;
        }
      }
      else {
        iVar1 = FUN_600b2224(param_1);
        if (iVar1 == 0) {
          uVar3 = 3;
        }
        else {
          uVar3 = 1;
        }
      }
    }
    else if ((*(char *)(iVar1 + 0x50) == '\x06') || (*(char *)(iVar1 + 0x50) == '\t')) {
      uVar3 = 1;
    }
    else if ((*(byte *)(DAT_600a4980 + 0x118d) & 4) == 0) {
      FUN_600f8c0a(param_1,0);
      uVar3 = 0xb;
    }
    else {
      uVar3 = FUN_600f1ce4(iVar1,0x13,*(undefined2 *)(iVar1 + 0xc));
    }
  }
  return uVar3;
}



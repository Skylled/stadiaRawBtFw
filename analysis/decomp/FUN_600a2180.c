// 600a2180  FUN_600a2180  size=94 bytes
// --- callers ---
//   600a4820 FUN_600a4820
// --- callees ---
//   6009decc FUN_6009decc
//   600b28b0 FUN_600b28b0
//   600f0910 FUN_600f0910


undefined4 FUN_600a2180(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = DAT_600a21e0;
  if (*(char *)(DAT_600a21e0 + 0x32) == '\0') {
    uVar3 = 6;
  }
  else {
    iVar1 = FUN_600f0910(DAT_600a21e0 + 0x2c);
    if (iVar1 == 0) {
      iVar2 = FUN_600b28b0(iVar2 + 0x2c);
      if (iVar2 == 0) {
        uVar3 = 3;
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      iVar2 = FUN_6009decc(iVar2 + 0x2c);
      if (iVar2 == 0) {
        uVar3 = 7;
      }
      else {
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}



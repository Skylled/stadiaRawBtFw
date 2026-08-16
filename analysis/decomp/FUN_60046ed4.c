// 60046ed4  FUN_60046ed4  size=54 bytes
// --- callers ---
// --- callees ---
//   6004bdd6 FUN_6004bdd6


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_60046ed4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = func_0x60046f10(0);
  if ((iVar1 == 0) && (iVar2 = func_0x6004bfac(0x10c), iVar2 != 0)) {
    FUN_6004bdd6(iVar2,0,0x10c);
    iVar3 = func_0x6004c2e4(0,iVar2,_DAT_60046f0c);
    if (iVar3 != 0) {
      iVar1 = iVar2;
    }
  }
  return iVar1;
}



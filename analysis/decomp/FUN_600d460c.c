// 600d460c  FUN_600d460c  size=70 bytes
// --- callers ---
//   60061d38 FUN_60061d38
//   6005ebe0 FUN_6005ebe0
//   60061b78 FUN_60061b78
// --- callees ---


int FUN_600d460c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = 0;
  iVar3 = 9;
  do {
    iVar2 = iVar1 + iVar3 >> 1;
    iVar4 = *(int *)(param_1 + iVar2 * 0xc);
    if (iVar4 == param_2) {
      return param_1 + iVar2 * 0xc;
    }
    if (param_2 < iVar4) {
      iVar3 = iVar2 + -1;
    }
    else {
      iVar1 = iVar2 + 1;
    }
  } while (iVar1 < iVar3);
  if ((param_2 < *(int *)(param_1 + iVar1 * 0xc)) && (iVar1 != 0)) {
    iVar1 = iVar1 + -1;
  }
  return iVar1 * 0xc + param_1;
}



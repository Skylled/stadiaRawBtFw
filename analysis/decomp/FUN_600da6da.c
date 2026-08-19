// 600da6da  FUN_600da6da  size=68 bytes
// --- callers ---
// --- callees ---


int FUN_600da6da(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *(int *)(param_1 + 0x74);
  iVar5 = 3;
  iVar3 = 0;
  do {
    iVar1 = iVar3 + iVar5 >> 1;
    iVar6 = *(int *)(iVar2 + iVar1 * 8);
    if (param_2 == iVar6) goto LAB_600da6f2;
    if (param_2 < iVar6) {
      iVar5 = iVar1 + -1;
    }
    else {
      iVar3 = iVar1 + 1;
    }
  } while (iVar3 < iVar5);
  iVar1 = iVar3;
  if ((param_2 < *(int *)(iVar2 + iVar3 * 8)) && (iVar3 != 0)) {
    iVar1 = iVar3 + -1;
  }
LAB_600da6f2:
  piVar4 = (int *)(iVar2 + iVar1 * 8);
  if (param_2 != *piVar4) {
    piVar4 = (int *)(iVar2 + 0x20);
  }
  return piVar4[1];
}



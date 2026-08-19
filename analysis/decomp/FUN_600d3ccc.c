// 600d3ccc  FUN_600d3ccc  size=68 bytes
// --- callers ---
// --- callees ---


int FUN_600d3ccc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *(int *)(param_1 + 0x70);
  iVar5 = 0xd;
  iVar3 = 0;
  do {
    iVar1 = iVar3 + iVar5 >> 1;
    iVar6 = *(int *)(iVar2 + iVar1 * 8);
    if (param_2 == iVar6) goto LAB_600d3ce4;
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
LAB_600d3ce4:
  piVar4 = (int *)(iVar2 + iVar1 * 8);
  if (param_2 != *piVar4) {
    piVar4 = (int *)(iVar2 + 0x70);
  }
  return piVar4[1];
}



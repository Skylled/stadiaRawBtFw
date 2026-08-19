// 600da4ac  FUN_600da4ac  size=54 bytes
// --- callers ---
//   600da4fc FUN_600da4fc
//   600da4e2 FUN_600da4e2
// --- callees ---


int FUN_600da4ac(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = 0xc;
  do {
    iVar1 = iVar2 + iVar3 >> 1;
    iVar4 = *(int *)(param_1 + iVar1 * 8);
    if (iVar4 == param_2) goto LAB_600da4c2;
    if (param_2 < iVar4) {
      iVar3 = iVar1 + -1;
    }
    else {
      iVar2 = iVar1 + 1;
    }
  } while (iVar2 < iVar3);
  iVar1 = iVar2;
  if ((param_2 < *(int *)(param_1 + iVar2 * 8)) && (iVar2 != 0)) {
    iVar1 = iVar2 + -1;
  }
LAB_600da4c2:
  return param_1 + iVar1 * 8;
}



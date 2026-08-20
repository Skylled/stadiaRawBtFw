// 600e7434  FUN_600e7434  size=28 bytes
// --- callers ---
//   6008bbdc bcm__6008bbdc
//   600e7450 FUN_600e7450
//   600e7480 FUN_600e7480
//   600e75de FUN_600e75de
// --- callees ---


int FUN_600e7434(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1[1];
  iVar2 = iVar3 << 2;
  while ((0 < iVar3 && (iVar1 = *param_1 + iVar2, iVar2 = iVar2 + -4, *(int *)(iVar1 + -4) == 0))) {
    iVar3 = iVar3 + -1;
  }
  return iVar3;
}



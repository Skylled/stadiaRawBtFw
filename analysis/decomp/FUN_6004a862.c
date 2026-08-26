// 6004a862  FUN_6004a862  size=120 bytes
// --- callers ---
//   6004a4e6 FUN_6004a4e6
// --- callees ---


void FUN_6004a862(int param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  
  piVar1 = *(int **)(param_2 + 4);
  iVar4 = *piVar1;
  param_3 = param_3 + piVar1[5] + iVar4;
  iVar4 = (param_3 - iVar4 * (param_3 / iVar4)) * 0xc;
  pfVar3 = *(float **)(piVar1[1] + iVar4);
  uVar2 = 1;
  iVar4 = *(int *)(piVar1[1] + iVar4 + 4) - (int)pfVar3 >> 2;
  if (iVar4 == 0) {
    pfVar3 = (float *)0x0;
  }
  for (; uVar2 < iVar4 - 1U; uVar2 = uVar2 + 1) {
    pfVar5 = pfVar3 + 2;
    if (-1 < (int)((uint)(*pfVar3 < pfVar3[2]) << 0x1f)) {
      pfVar5 = pfVar3;
    }
    if (*pfVar5 * 3.0 < pfVar3[1]) {
      iVar6 = *(int *)(param_1 + uVar2 * 4) + 1;
    }
    else {
      iVar6 = 0;
    }
    *(int *)(param_1 + uVar2 * 4) = iVar6;
    pfVar3 = pfVar3 + 1;
  }
  return;
}



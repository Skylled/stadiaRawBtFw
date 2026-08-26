// 6004a04c  FUN_6004a04c  size=154 bytes
// --- callers ---
//   6004a0e6 FUN_6004a0e6
// --- callees ---


void FUN_6004a04c(uint param_1,float *param_2,int param_3,int param_4)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  iVar1 = 0;
  pfVar2 = param_2 + param_1;
  for (uVar5 = 2; pfVar4 = param_2 + 2, uVar5 < param_1 >> 1; uVar5 = uVar5 + 2) {
    iVar1 = iVar1 + (uint)(param_3 << 1) / (param_1 >> 1);
    fVar6 = *pfVar4 - pfVar2[-2];
    pfVar3 = pfVar2 + -2;
    fVar8 = param_2[3] + pfVar2[-1];
    fVar10 = *(float *)(param_4 + iVar1 * 4);
    fVar7 = 0.5 - *(float *)(iVar1 * -4 + param_3 * 4 + param_4);
    fVar9 = -(fVar8 * fVar10) + fVar7 * fVar6;
    fVar6 = fVar10 * fVar6 + fVar7 * fVar8;
    *pfVar4 = *pfVar4 - fVar9;
    param_2[3] = param_2[3] - fVar6;
    *pfVar3 = *pfVar3 + fVar9;
    pfVar2[-1] = pfVar2[-1] - fVar6;
    pfVar2 = pfVar3;
    param_2 = pfVar4;
  }
  return;
}



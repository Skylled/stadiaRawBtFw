// 600dd5a0  FUN_600dd5a0  size=188 bytes
// --- callers ---
// --- callees ---


void FUN_600dd5a0(uint param_1,float *param_2,int param_3,int param_4)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  uVar5 = param_1 >> 1;
  iVar6 = 0;
  param_2[1] = -param_2[1];
  pfVar2 = param_2 + param_1;
  pfVar1 = param_2;
  for (uVar7 = 2; pfVar4 = pfVar1 + 2, uVar7 < uVar5; uVar7 = uVar7 + 2) {
    iVar6 = iVar6 + (uint)(param_3 << 1) / uVar5;
    fVar10 = pfVar1[3] + pfVar2[-1];
    pfVar3 = pfVar2 + -2;
    fVar12 = *pfVar4 - pfVar2[-2];
    fVar8 = *(float *)(param_4 + iVar6 * 4);
    fVar9 = 0.5 - *(float *)(iVar6 * -4 + param_3 * 4 + param_4);
    fVar11 = fVar8 * fVar10 + fVar9 * fVar12;
    fVar8 = -(fVar12 * fVar8) + fVar9 * fVar10;
    *pfVar4 = *pfVar4 - fVar11;
    pfVar1[3] = fVar8 - pfVar1[3];
    *pfVar3 = *pfVar3 + fVar11;
    pfVar2[-1] = fVar8 - pfVar2[-1];
    pfVar2 = pfVar3;
    pfVar1 = pfVar4;
  }
  param_2[uVar5 + 1] = -param_2[uVar5 + 1];
  return;
}



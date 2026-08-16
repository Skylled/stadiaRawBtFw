// 60043a58  FUN_60043a58  size=140 bytes
// --- callers ---
// --- callees ---


void FUN_60043a58(int param_1,float *param_2,float *param_3,float *param_4,undefined4 param_5,
                 float *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  fVar4 = fRam60043aec;
  fVar3 = fRam60043ae8;
  fVar2 = fRam60043ae4;
  pfVar5 = (float *)(param_1 + 0x12bc);
  pfVar6 = (float *)(param_1 + 0x1af0);
  do {
    fVar9 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    fVar10 = *pfVar6;
    fVar7 = pfVar6[0x81];
    fVar11 = *param_3;
    param_3 = param_3 + 1;
    fVar8 = *param_2;
    param_2 = param_2 + 1;
    if (fVar11 < fVar8) {
      fVar1 = fVar11 + fVar2;
    }
    else {
      *param_6 = 0.0;
      fVar1 = fVar11;
    }
    if (fVar11 < fVar8) {
      *param_6 = fVar8 / fVar1 - 1.0;
    }
    fVar8 = *param_6;
    param_6 = param_6 + 1;
    *param_4 = fVar8 * fVar3 + (fVar7 / (fVar10 + fVar2)) * fVar9 * fVar4;
    param_4 = param_4 + 1;
    pfVar6 = pfVar6 + 1;
  } while (pfVar5 != (float *)(param_1 + 0x14c0));
  return;
}



// 60044440  FUN_60044440  size=390 bytes
// --- callers ---
// --- callees ---
//   6004bda4 FUN_6004bda4
//   6004c1bc thunk_FUN_600dd6a0
//   6004a35c FUN_6004a35c


void FUN_60044440(int param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  int *piVar10;
  uint in_fpscr;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float local_234 [129];
  float fStack_30;
  
  fVar2 = DAT_600445cc;
  fVar1 = DAT_600445c8;
  piVar10 = (int *)(param_1 + 0xe18);
  pfVar8 = (float *)(param_1 + 0x60c);
  iVar6 = *(int *)(param_1 + 0xe28) + 1;
  if (199 < iVar6) {
    iVar6 = 200;
  }
  *(int *)(param_1 + 0xe28) = iVar6;
  FUN_6004a35c(param_2,0x81,local_234,0x81);
  do {
    fVar3 = DAT_600445d0;
    piVar10 = piVar10 + 1;
    iVar6 = *piVar10;
    fVar11 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
    fVar14 = 1.0;
    pfVar4 = local_234;
    pfVar5 = pfVar8 + -0x183;
    pfVar7 = pfVar8;
    do {
      fVar12 = *pfVar5;
      in_fpscr = in_fpscr & 0xfffffff;
      if (1.0 < fVar12) {
        fVar14 = fVar1 / fVar12;
      }
      fVar13 = *pfVar4;
      pfVar4 = pfVar4 + 1;
      if (fVar12 <= 1.0) {
        fVar14 = fVar1;
      }
      fVar14 = fVar14 / (fVar11 + 1.0);
      if (*pfVar7 < fVar13) {
        fVar14 = fVar14 * 0.25;
      }
      else {
        fVar14 = -fVar14 * 0.75;
      }
      *pfVar7 = *pfVar7 + fVar14;
      fVar14 = *pfVar7;
      if (ABS(fVar13 - fVar14) < fVar2) {
        fVar14 = (fVar3 + fVar11 * *pfVar5) / (fVar11 + 1.0);
        *pfVar5 = fVar14;
      }
      pfVar5 = pfVar5 + 1;
      pfVar7 = pfVar7 + 1;
    } while (pfVar4 != &fStack_30);
    iVar9 = param_1 + 0xc18;
    if ((199 < iVar6) && (*piVar10 = 0, 199 < *(int *)(param_1 + 0xe28))) {
      thunk_FUN_600dd6a0(pfVar8,0x81,iVar9,0x81);
    }
    pfVar8 = pfVar8 + 0x81;
    *piVar10 = *piVar10 + 1;
  } while (pfVar8 != (float *)(param_1 + 0xc18));
  if (*(int *)(param_1 + 0xe28) < 200) {
    thunk_FUN_600dd6a0(param_1 + 0xa14,0x81,iVar9,0x81);
  }
  if (param_1 + 0xe1c == iVar9) {
    return;
  }
  FUN_6004bda4(param_3,iVar9,(param_1 + 0xe1c) - iVar9);
  return;
}



// 60043af0  FUN_60043af0  size=462 bytes
// --- callers ---
// --- callees ---
//   600454c4 FUN_600454c4
//   6004898c FUN_6004898c


void FUN_60043af0(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float ****ppppfVar2;
  float ****ppppfVar3;
  float *pfVar4;
  float ****ppppfVar5;
  float *pfVar6;
  undefined4 in_cr0;
  undefined4 in_cr9;
  undefined4 in_cr13;
  float fVar7;
  float fVar8;
  float ***pppfVar9;
  float ***pppfVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float ***pppfStack_25c;
  undefined4 uStack_258;
  float **appfStack_254 [130];
  
  fVar1 = fRam60043cc0;
  fVar18 = *(float *)(param_1 + 0x18d4);
  fVar17 = *(float *)(param_1 + 0x18d8);
  fVar16 = *(float *)(param_1 + 0x18dc);
  fVar15 = *(float *)(param_1 + 0x18e0);
  fVar11 = *(float *)(param_1 + 0x18e4);
  fVar14 = *(float *)(param_1 + 0x18e8);
  pfVar6 = param_2 + 0x81;
  pfVar4 = (float *)(param_1 + 0x20fc);
  fVar12 = fRam60043cc4;
  do {
    fVar8 = *param_2;
    param_2 = param_2 + 1;
    fVar13 = *param_3;
    param_3 = param_3 + 1;
    fVar8 = fVar8 + fVar8;
    fVar7 = (float)FUN_600454c4();
    fVar7 = (-fVar7 + (fVar13 + 1.0) * (fVar8 / (fVar8 + 1.0 + fVar1))) - *pfVar4;
    fVar8 = *pfVar4 + fVar7 * 0.5;
    *pfVar4 = fVar8;
    pfVar4 = pfVar4 + 1;
    fVar12 = fVar12 + fVar8;
  } while (pfVar6 != param_2);
  ppppfVar5 = (float ****)appfStack_254;
  fVar12 = fVar12 / fRam60043cc8;
  fVar8 = 8.0;
  *(float *)(param_1 + 0x2304) = fVar12;
  coprocessor_function2(10,3,0,in_cr0,in_cr9,in_cr13);
  fVar12 = (float)FUN_6004898c((fVar12 - fVar18) * fVar7);
  coprocessor_function2(10,3,0,in_cr0,in_cr9,in_cr13);
  fVar17 = (float)FUN_6004898c((fVar17 - *(float *)(param_1 + 0x230c)) * (fVar12 + 1.0));
  if (-1 < (int)((uint)(*(float *)(param_1 + 0x2308) < fVar16) << 0x1f)) {
    fVar8 = 4.0;
  }
  fVar16 = (float)FUN_6004898c((*(float *)(param_1 + 0x2308) - fVar16) * fVar8);
  ppppfVar3 = (float ****)(param_1 + 0x2300);
  ppppfVar2 = &pppfStack_25c;
  pppfStack_25c = (float ***)0x3f800000;
  pppfVar9 = (float ***)
             ((float)*ppppfVar3 +
             ((fVar11 * (fVar17 + 1.0) * 0.5 + fVar15 * (fVar12 + 1.0) * 0.5 +
              fVar14 * (fVar16 + 1.0) * 0.5) - (float)*ppppfVar3) * fRam60043ccc);
  *ppppfVar3 = pppfVar9;
  appfStack_254[0] = (float **)pppfRam60043cd0;
  if ((float)pppfVar9 <= 1.0) {
    ppppfVar2 = ppppfVar3;
  }
  if ((int)((uint)((float)*ppppfVar2 < (float)pppfRam60043cd0) << 0x1f) < 0) {
    ppppfVar2 = ppppfVar5;
  }
  pppfVar9 = *ppppfVar2;
  *ppppfVar3 = pppfVar9;
  uStack_258 = 0x81;
  pppfStack_25c = (float ***)ppppfVar5;
  func_0x6004a38e((float *)(param_1 + 0x20fc),0x81,ppppfVar5,0x81);
  pfVar4 = (float *)(param_1 + 0x5818);
  do {
    pppfVar10 = *ppppfVar5;
    ppppfVar5 = ppppfVar5 + 1;
    *pfVar4 = 1.0 / ((float)pppfVar10 * ((1.0 - (float)pppfVar9) / ((float)pppfVar9 + fVar1)) + 1.0)
    ;
    pfVar4 = pfVar4 + 1;
  } while ((float *)(param_1 + 0x5a1c) != pfVar4);
  return;
}



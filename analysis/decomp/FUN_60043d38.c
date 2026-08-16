// 60043d38  FUN_60043d38  size=224 bytes
// --- callers ---
// --- callees ---


void FUN_60043d38(int param_1,float *param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *unaff_r5;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fStack_14;
  
  fVar3 = fRam60043e24;
  fVar2 = fRam60043e1c;
  pfVar6 = (float *)(param_1 + 0x5818);
  pfVar4 = (float *)(param_1 + 0x1af0);
  fVar9 = fRam60043e18;
  do {
    fVar8 = *pfVar6;
    pfVar6 = pfVar6 + 1;
    fVar7 = *pfVar4;
    pfVar5 = pfVar4 + 1;
    fStack_14 = (fVar7 * fVar8 + *param_2 * (1.0 - fVar8)) * (1.0 - fVar9) + fVar7 * fVar9;
    coprocessor_function2(10,3,1,in_cr6,in_cr2,in_cr1);
    if ((int)((uint)(fVar8 < fVar2) << 0x1f) < 0) {
      unaff_r5 = pfVar4 + 0x20a;
      *unaff_r5 = *unaff_r5 + (*param_2 - *unaff_r5) * fVar3;
    }
    if (fVar7 == fVar9) {
      *param_3 = fStack_14;
    }
    else {
      fVar9 = (*pfVar4 * fVar8 + *param_2 * (1.0 - fVar8)) * (1.0 - fVar7) + *pfVar4 * fVar7;
      iVar1 = (uint)(fStack_14 < fVar9) << 0x1f;
      *param_3 = fVar9;
      if (iVar1 < 0) {
        unaff_r5 = &fStack_14;
      }
      if (-1 < iVar1) {
        unaff_r5 = param_3;
      }
      unaff_r5 = (float *)*unaff_r5;
      *param_3 = (float)unaff_r5;
    }
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
    pfVar4 = pfVar5;
    fVar9 = fVar7;
  } while ((float *)(param_1 + 0x1cf4) != pfVar5);
  return;
}



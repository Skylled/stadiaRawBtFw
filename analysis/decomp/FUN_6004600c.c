// 6004600c  FUN_6004600c  size=410 bytes
// --- callers ---
//   60043834 FUN_60043834
// --- callees ---


int FUN_6004600c(float param_1,float *param_2,int *param_3)

{
  float fVar1;
  float *pfVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  undefined4 in_cr0;
  undefined4 in_cr6;
  undefined4 in_cr7;
  float fVar12;
  float fVar13;
  float fVar14;
  
  fVar14 = 1.0;
  if (param_1 == 1.0) {
    iVar9 = 0;
  }
  else {
    iVar9 = 0;
    fVar13 = param_2[1];
    iVar8 = param_3[1];
    coprocessor_function2(10,0,1,in_cr7,in_cr7,in_cr6);
    iVar10 = (iVar8 - *param_3 >> 2) * DAT_600461a8;
    for (; pfVar5 = DAT_600461b8, pfVar6 = DAT_600461b4, fVar1 = DAT_600461b0, fVar12 = DAT_600461ac
        , piVar3 = (int *)*param_3, iVar9 < iVar10; iVar9 = iVar9 + 1) {
      fVar14 = param_2[3];
      fVar12 = *param_2;
      pfVar6 = (float *)piVar3[iVar9 * 3];
      iVar4 = piVar3[iVar9 * 3 + 1] - (int)pfVar6;
      if (iVar4 == 0) {
        if (fVar14 == param_1) {
          pfVar6 = (float *)0x0;
          goto LAB_60046186;
        }
        pfVar6 = (float *)0x0;
LAB_60046076:
        if (fVar14 < param_1) {
          pfVar5 = (float *)(iVar4 + (int)pfVar6);
          for (; pfVar5 != pfVar6; pfVar6 = pfVar6 + 1) {
            fVar14 = fVar14 + fVar12;
            coprocessor_function2(10,7,4,in_cr7,in_cr7,in_cr0);
            *pfVar6 = *pfVar6 * fVar14;
          }
        }
        else {
          pfVar5 = (float *)(iVar4 + (int)pfVar6);
          for (; pfVar5 != pfVar6; pfVar6 = pfVar6 + 1) {
            fVar14 = fVar14 + fVar13;
            if (-1 < (int)((uint)(param_1 < fVar14) << 0x1f)) {
              fVar14 = param_1;
            }
            *pfVar6 = *pfVar6 * fVar14;
          }
        }
      }
      else {
        if (fVar14 != param_1) goto LAB_60046076;
LAB_60046186:
        pfVar5 = (float *)(iVar4 + (int)pfVar6);
        for (; fVar14 = param_1, pfVar5 != pfVar6; pfVar6 = pfVar6 + 1) {
          *pfVar6 = *pfVar6 * param_1;
        }
      }
    }
    pfVar7 = (float *)*piVar3;
    iVar9 = 0;
    iVar10 = piVar3[1] - (int)pfVar7;
    if (iVar10 == 0) {
      pfVar7 = (float *)0x0;
    }
    pfVar2 = (float *)(iVar10 + (int)pfVar7);
    while (pfVar7 != pfVar2) {
      fVar13 = *pfVar7;
      pfVar7 = pfVar7 + 1;
      if ((DAT_600461ac <= fVar13) || (fVar13 <= DAT_600461b0)) {
        iVar9 = iVar9 + 1;
      }
    }
    iVar8 = DAT_600461a8 * (iVar8 - (int)piVar3 >> 2);
    for (iVar10 = 0; iVar10 < iVar8; iVar10 = iVar10 + 1) {
      pfVar7 = (float *)piVar3[iVar10 * 3];
      iVar4 = piVar3[iVar10 * 3 + 1] - (int)pfVar7;
      if (iVar4 == 0) {
        pfVar7 = (float *)0x0;
      }
      pfVar2 = (float *)(iVar4 + (int)pfVar7);
      for (; pfVar2 != pfVar7; pfVar7 = pfVar7 + 1) {
        pfVar11 = pfVar7;
        if (*pfVar7 <= fVar1) {
          pfVar11 = pfVar6;
        }
        iVar4 = (uint)(*pfVar11 < fVar12) << 0x1f;
        *pfVar7 = *pfVar11;
        if (iVar4 < 0) {
          pfVar11 = pfVar7;
        }
        if (-1 < iVar4) {
          pfVar11 = pfVar5;
        }
        *pfVar7 = *pfVar11;
      }
    }
    param_2[3] = fVar14;
  }
  return iVar9;
}



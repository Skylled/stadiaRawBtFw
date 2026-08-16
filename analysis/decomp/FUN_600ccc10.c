// 600ccc10  FUN_600ccc10  size=606 bytes
// --- callers ---
//   600ccb7c FUN_600ccb7c
//   600cca80 FUN_600cca80
// --- callees ---
//   600ccfb4 FUN_600ccfb4
//   600cd9ac FUN_600cd9ac


int FUN_600ccc10(float param_1,float *param_2)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  float local_1c;
  float local_18;
  float local_14;
  
  fVar5 = DAT_600cce98;
  fVar7 = DAT_600cce80;
  fVar3 = ABS(param_1);
  if ((int)fVar3 <= DAT_600cce70) {
    *param_2 = param_1;
    param_2[1] = 0.0;
    return 0;
  }
  if ((int)fVar3 <= DAT_600cce74) {
    if ((int)param_1 < 1) {
      fVar3 = param_1 + DAT_600cce78;
      if (((uint)param_1 & 0x7ffffff0) != DAT_600cce7c) {
        fVar5 = fVar3 + DAT_600cce80;
        *param_2 = fVar5;
        param_2[1] = (fVar3 - fVar5) + fVar7;
        return -1;
      }
      fVar3 = fVar3 + DAT_600cce94;
      fVar7 = fVar3 + DAT_600cce98;
      *param_2 = fVar7;
      param_2[1] = (fVar3 - fVar7) + fVar5;
      return -1;
    }
    fVar3 = param_1 - DAT_600cce78;
    if (((uint)param_1 & 0x7ffffff0) == DAT_600cce7c) {
      fVar3 = fVar3 - DAT_600cce94;
      fVar7 = fVar3 - DAT_600cce98;
      *param_2 = fVar7;
      param_2[1] = (fVar3 - fVar7) - fVar5;
      return 1;
    }
    fVar5 = fVar3 - DAT_600cce80;
    *param_2 = fVar5;
    param_2[1] = (fVar3 - fVar5) - fVar7;
    return 1;
  }
  iVar1 = (int)fVar3 >> 0x17;
  if (DAT_600cce84 < (int)fVar3) {
    if (0x7f7fffff < (uint)fVar3) {
      param_2[1] = param_1 - param_1;
      *param_2 = param_1 - param_1;
      return 0;
    }
    fVar3 = (float)((int)fVar3 + (iVar1 + -0x86) * -0x800000);
    local_1c = (float)VectorSignedToFloat((int)fVar3,(byte)(in_fpscr >> 0x16) & 3);
    fVar7 = (fVar3 - local_1c) * DAT_600cce88;
    local_18 = (float)VectorSignedToFloat((int)fVar7,(byte)(in_fpscr >> 0x16) & 3);
    local_14 = (fVar7 - local_18) * DAT_600cce88;
    if (local_14 == 0.0) {
      if (local_18 == 0.0) {
        uVar2 = 1;
      }
      else {
        uVar2 = 2;
      }
    }
    else {
      uVar2 = 3;
    }
    iVar1 = FUN_600ccfb4(&local_1c,param_2,iVar1 + -0x86,uVar2,2,DAT_600cce8c);
    if (-1 < (int)param_1) {
      return iVar1;
    }
    *param_2 = -*param_2;
    param_2[1] = -param_2[1];
    return -iVar1;
  }
  fVar7 = (float)FUN_600cd9ac();
  iVar9 = (int)(fVar7 * DAT_600cce90 + 0.5);
  fVar6 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = -fVar6;
  fVar7 = fVar7 + fVar3 * DAT_600cce78;
  fVar5 = fVar6 * DAT_600cce80;
  if (((0x1f < iVar9) ||
      (fVar8 = fVar7 - fVar5,
      ((uint)param_1 & 0x7fffff00) == *(uint *)(DAT_600cce9c + (iVar9 + -1) * 4))) &&
     (fVar8 = fVar7 - fVar5, 8 < (int)(iVar1 - ((uint)ABS(fVar8) >> 0x17)))) {
    fVar4 = fVar7 + fVar3 * DAT_600cce94;
    fVar5 = -((fVar7 - fVar4) + fVar3 * DAT_600cce94) + fVar6 * DAT_600cce98;
    fVar8 = fVar4 - fVar5;
    if ((int)(iVar1 - ((uint)ABS(fVar8) >> 0x17)) < 0x1a) {
      *param_2 = fVar8;
      fVar7 = fVar4;
      goto LAB_600ccdb0;
    }
    fVar7 = fVar4 + fVar3 * DAT_600ccea0;
    fVar5 = -((fVar4 - fVar7) + fVar3 * DAT_600ccea0) + fVar6 * DAT_600ccea4;
    fVar8 = fVar7 - fVar5;
  }
  *param_2 = fVar8;
LAB_600ccdb0:
  fVar5 = (fVar7 - fVar8) - fVar5;
  param_2[1] = fVar5;
  if ((int)param_1 < 0) {
    *param_2 = -fVar8;
    param_2[1] = -fVar5;
    iVar9 = -iVar9;
  }
  return iVar9;
}



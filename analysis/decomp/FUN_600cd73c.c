// 600cd73c  FUN_600cd73c  size=562 bytes
// --- callers ---
// --- callees ---


float FUN_600cd73c(float param_1)

{
  int iVar1;
  float fVar2;
  uint in_fpscr;
  undefined4 in_cr0;
  undefined4 in_cr6;
  undefined4 in_cr7;
  float fVar3;
  float fVar4;
  uint uVar5;
  float in_s15;
  
  fVar2 = ABS(param_1);
  if ((uint)DAT_600cd970 < (uint)fVar2) {
    if (0x7f800000 < (uint)fVar2) {
      return param_1 + param_1;
    }
    if (fVar2 == INFINITY) {
      coprocessor_function2(10,2,1,in_cr0,in_cr0,in_cr7);
      return param_1;
    }
    if ((int)param_1 < 0) {
      in_fpscr = in_fpscr & 0xfffffff;
      if (param_1 + DAT_600cd9a8 < 0.0) {
        return -1.0;
      }
      fVar2 = -0.5;
    }
    else {
      if ((uint)DAT_600cd974 < (uint)fVar2) {
        return DAT_600cd9a0 * DAT_600cd9a0;
      }
      fVar2 = 0.5;
    }
LAB_600cd842:
    uVar5 = (uint)(fVar2 + param_1 * DAT_600cd978);
    fVar3 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
    fVar2 = param_1 + -fVar3 * DAT_600cd998;
    in_s15 = fVar3 * DAT_600cd99c;
  }
  else {
    if ((uint)fVar2 <= (uint)DAT_600cd97c) {
      if ((uint)fVar2 < 0x33000000) {
        return param_1 - ((param_1 + DAT_600cd9a0) - (param_1 + DAT_600cd9a0));
      }
      uVar5 = 0;
      goto LAB_600cd77e;
    }
    if ((uint)DAT_600cd994 < (uint)fVar2) {
      fVar2 = -0.5;
      coprocessor_function2(10,2,4,in_cr7,in_cr6,in_cr7);
      goto LAB_600cd842;
    }
    if ((int)param_1 < 0) {
      fVar2 = param_1 + DAT_600cd998;
      uVar5 = 0xffffffff;
      in_s15 = DAT_600cd9a4;
    }
    else {
      fVar2 = param_1 - DAT_600cd998;
      uVar5 = 1;
      in_s15 = DAT_600cd99c;
    }
  }
  param_1 = fVar2 - in_s15;
  in_s15 = (fVar2 - param_1) - in_s15;
LAB_600cd77e:
  fVar4 = param_1 * param_1 * 0.5;
  fVar2 = (DAT_600cd990 +
          (DAT_600cd98c + (DAT_600cd988 + (DAT_600cd984 + fVar4 * DAT_600cd980) * fVar4) * fVar4) *
          fVar4) * fVar4 + 1.0;
  fVar3 = -(param_1 * 0.5) * fVar2 + 3.0;
  fVar2 = ((fVar2 - fVar3) / (-param_1 * fVar3 + 6.0)) * fVar4;
  if (uVar5 == 0) {
    return param_1 - (-fVar4 + param_1 * fVar2);
  }
  fVar4 = (-in_s15 + (fVar2 - in_s15) * param_1) - fVar4;
  if (uVar5 == 0xffffffff) {
    return (param_1 - fVar4) * 0.5 + -0.5;
  }
  if (uVar5 == 1) {
    if ((int)((uint)(param_1 < -0.25) << 0x1f) < 0) {
      return (fVar4 - (param_1 + 0.5)) * -2.0;
    }
    return (param_1 - fVar4) * 2.0 + 1.0;
  }
  iVar1 = uVar5 * 0x800000;
  if (uVar5 + 1 < 0x3a) {
    if (0x16 < (int)uVar5) {
      return (float)((int)((param_1 - (fVar4 + (float)((0x7f - uVar5) * 0x800000))) + 1.0) + iVar1);
    }
    return (float)((int)((float)(0x3f800000 - (0x1000000 >> (uVar5 & 0xff))) - (fVar4 - param_1)) +
                  iVar1);
  }
  return (float)((int)(1.0 - (fVar4 - param_1)) + iVar1) - 1.0;
}



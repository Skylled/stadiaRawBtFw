// 600cceb0  FUN_600cceb0  size=226 bytes
// --- callers ---
//   600cca80 FUN_600cca80
//   600ccb7c FUN_600ccb7c
// --- callees ---


float FUN_600cceb0(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = ABS(param_1);
  if ((uint)fVar1 < 0x32000000) {
    if ((int)param_1 == 0) {
      return 1.0;
    }
    fVar3 = param_1 * param_1;
    fVar3 = (DAT_600ccfa8 +
            fVar3 * (DAT_600ccfa4 +
                    fVar3 * (DAT_600ccfa0 +
                            fVar3 * (DAT_600ccf9c + fVar3 * (DAT_600ccf98 + fVar3 * DAT_600ccf94))))
            ) * fVar3;
  }
  else {
    fVar4 = param_1 * param_1;
    fVar3 = (DAT_600ccfa8 +
            (DAT_600ccfa4 +
            (DAT_600ccfa0 + (DAT_600ccf9c + (DAT_600ccf98 + fVar4 * DAT_600ccf94) * fVar4) * fVar4)
            * fVar4) * fVar4) * fVar4;
    if (DAT_600ccfac < (int)fVar1) {
      if (DAT_600ccfb0 < (int)fVar1) {
        fVar2 = 0.71875;
        fVar1 = 0.28125;
      }
      else {
        fVar1 = (float)((int)fVar1 - 0x1000000);
        fVar2 = 1.0 - fVar1;
      }
      return fVar2 - ((-fVar1 + fVar4 * 0.5) - (-(param_2 * param_1) + fVar4 * fVar3));
    }
  }
  return 1.0 - (-(-(param_2 * param_1) + param_1 * param_1 * fVar3) + param_1 * param_1 * 0.5);
}



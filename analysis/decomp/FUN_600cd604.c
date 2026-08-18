// 600cd604  FUN_600cd604  size=114 bytes
// --- callers ---
//   600cca80 FUN_600cca80
//   600ccb7c FUN_600ccb7c
// --- callees ---


float FUN_600cd604(float param_1,float param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if ((0x31ffffff < (uint)ABS(param_1)) || ((int)param_1 != 0)) {
    fVar3 = param_1 * param_1;
    fVar1 = param_1 * fVar3;
    fVar2 = DAT_600cd688 +
            (DAT_600cd684 + (DAT_600cd680 + (DAT_600cd67c + fVar3 * DAT_600cd678) * fVar3) * fVar3)
            * fVar3;
    if (param_3 == 0) {
      return param_1 + (DAT_600cd690 + fVar3 * fVar2) * fVar1;
    }
    param_1 = param_1 - (-param_2 + (-(fVar2 * fVar1) + param_2 * 0.5) * fVar3 +
                        fVar1 * DAT_600cd68c);
  }
  return param_1;
}



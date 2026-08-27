// 6004898c  FUN_6004898c  size=170 bytes
// --- callers ---
//   60043ecc FUN_60043ecc
//   60043af0 FUN_60043af0
// --- callees ---
//   6004c044 thunk_FUN_600cd9ac
//   6004c32c thunk_FUN_600cd73c


float FUN_6004898c(float param_1)

{
  float fVar1;
  
  fVar1 = ABS(param_1);
  if (0x7f7fffff < (uint)fVar1) {
    if ((int)param_1 < 0) {
      fVar1 = 1.0 / param_1 - 1.0;
    }
    else {
      fVar1 = 1.0 / param_1 + 1.0;
    }
    return fVar1;
  }
  if (DAT_60048a38 < (int)fVar1) {
    fVar1 = 1.0;
  }
  else {
    if ((uint)fVar1 < 0x24000000) {
      return (param_1 + 1.0) * param_1;
    }
    if ((uint)fVar1 < 0x3f800000) {
      fVar1 = (float)thunk_FUN_600cd9ac();
      fVar1 = (float)thunk_FUN_600cd73c(fVar1 * -2.0);
      fVar1 = -fVar1 / (fVar1 + 2.0);
    }
    else {
      fVar1 = (float)thunk_FUN_600cd9ac();
      fVar1 = (float)thunk_FUN_600cd73c(fVar1 + fVar1);
      fVar1 = 1.0 - 2.0 / (fVar1 + 2.0);
    }
  }
  if ((int)param_1 < 0) {
    fVar1 = -fVar1;
  }
  return fVar1;
}



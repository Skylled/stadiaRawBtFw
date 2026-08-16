// 60045e30  FUN_60045e30  size=24 bytes
// --- callers ---
// --- callees ---


float FUN_60045e30(float *param_1)

{
  float *pfVar1;
  float fVar2;
  
  pfVar1 = param_1 + 0x10;
  fVar2 = fRam60045e48;
  while (param_1 = param_1 + 1, pfVar1 != param_1) {
    fVar2 = fVar2 + *param_1;
  }
  return fVar2;
}



// 60049bee  FUN_60049bee  size=68 bytes
// --- callers ---
//   60043834 FUN_60043834
// --- callees ---


float FUN_60049bee(float *param_1,int param_2)

{
  float *pfVar1;
  float *pfVar2;
  
  pfVar1 = param_1 + param_2;
  pfVar2 = param_1;
  if (pfVar1 != param_1) {
    while( true ) {
      pfVar2 = pfVar2 + 1;
      if (pfVar1 == pfVar2) break;
      if ((int)((uint)(ABS(*param_1) < ABS(*pfVar2)) << 0x1f) < 0) {
        param_1 = pfVar2;
      }
    }
  }
  return *param_1;
}



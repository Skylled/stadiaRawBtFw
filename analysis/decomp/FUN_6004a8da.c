// 6004a8da  FUN_6004a8da  size=36 bytes
// --- callers ---
// --- callees ---


void FUN_6004a8da(float param_1,int param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  
  pfVar1 = param_3 + 0x41;
  if (param_1 < 0.0) {
    param_1 = *(float *)(param_2 + 4);
  }
  do {
    fVar2 = *param_3;
    param_3 = param_3 + 1;
    *param_4 = fVar2 * param_1;
    param_4 = param_4 + 1;
  } while (param_3 != pfVar1);
  return;
}



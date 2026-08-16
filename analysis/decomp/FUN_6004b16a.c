// 6004b16a  FUN_6004b16a  size=118 bytes
// --- callers ---
// --- callees ---


void FUN_6004b16a(float *param_1,float *param_2,int param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  
  pfVar1 = param_4 + param_3;
  for (; param_4 != pfVar1; param_4 = param_4 + 1) {
    fVar3 = *param_2;
    param_2 = param_2 + 1;
    *param_4 = param_1[5] * *param_1 + param_1[4] * fVar3 + param_1[6] * param_1[1] +
               -param_1[7] * param_1[2] + -param_1[8] * param_1[3];
    fVar2 = *param_1;
    *param_1 = fVar3;
    param_1[1] = fVar2;
    param_1[3] = param_1[2];
    param_1[2] = *param_4;
  }
  return;
}



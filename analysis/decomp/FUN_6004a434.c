// 6004a434  FUN_6004a434  size=120 bytes
// --- callers ---
//   6004a4ac FUN_6004a4ac
// --- callees ---


void FUN_6004a434(undefined4 param_1,float *param_2,int param_3,float *param_4,undefined4 param_5,
                 float *param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  
  pfVar1 = param_4 + param_3;
  for (; param_4 != pfVar1; param_4 = param_4 + 1) {
    fVar3 = *param_2;
    param_2 = param_2 + 1;
    *param_4 = param_6[1] * param_6[5] + *param_6 * fVar3 + param_6[2] * param_6[6] +
               -param_6[3] * param_6[7] + -param_6[4] * param_6[8];
    fVar2 = param_6[5];
    param_6[5] = fVar3;
    param_6[6] = fVar2;
    param_6[8] = param_6[7];
    param_6[7] = *param_4;
  }
  return;
}



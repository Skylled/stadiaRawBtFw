// 600ddb8e  FUN_600ddb8e  size=20 bytes
// --- callers ---
//   600dd83c FUN_600dd83c
// --- callees ---


void FUN_600ddb8e(int *param_1,int param_2)

{
  float fVar1;
  
  fVar1 = *(float *)(param_2 + 0x6c);
  *param_1 = param_2;
  param_1[1] = (int)(1.0 / fVar1);
  return;
}



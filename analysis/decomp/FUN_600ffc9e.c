// 600ffc9e  FUN_600ffc9e  size=96 bytes
// --- callers ---
//   600ffd60 FUN_600ffd60
// --- callees ---


void FUN_600ffc9e(uint *param_1,uint *param_2)

{
  *param_1 = *param_1 ^ *param_2;
  param_1[1] = param_2[1] ^ param_1[1];
  param_1[2] = param_2[2] ^ param_1[2];
  param_1[3] = param_2[3] ^ param_1[3];
  return;
}



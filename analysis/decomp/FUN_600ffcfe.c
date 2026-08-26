// 600ffcfe  FUN_600ffcfe  size=98 bytes
// --- callers ---
//   600ffd7a FUN_600ffd7a
// --- callees ---


void FUN_600ffcfe(uint *param_1,uint *param_2,uint *param_3)

{
  *param_1 = *param_2 ^ *param_3;
  param_1[1] = param_3[1] ^ param_2[1];
  param_1[2] = param_3[2] ^ param_2[2];
  param_1[3] = param_3[3] ^ param_2[3];
  return;
}



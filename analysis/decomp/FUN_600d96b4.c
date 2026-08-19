// 600d96b4  FUN_600d96b4  size=24 bytes
// --- callers ---
//   600d9700 FUN_600d9700
// --- callees ---


float * FUN_600d96b4(float *param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = (uint)(*param_1 < *param_2) << 0x1f;
  if (iVar1 < 0) {
    param_1 = (float *)0x1;
  }
  if (-1 < iVar1) {
    param_1 = (float *)0x0;
  }
  return param_1;
}



// 6004b37c  FUN_6004b37c  size=24 bytes
// --- callers ---
//   6004b394 FUN_6004b394
// --- callees ---


float * FUN_6004b37c(float *param_1,float *param_2)

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



// 600ccb10  FUN_600ccb10  size=102 bytes
// --- callers ---
//   600cc4a8 FUN_600cc4a8
// --- callees ---


float FUN_600ccb10(float param_1,float *param_2)

{
  float fVar1;
  uint uVar2;
  
  uVar2 = ((uint)ABS(param_1) >> 0x17) - 0x7f;
  if (0x16 < (int)uVar2) {
    *param_2 = param_1;
    return (float)((uint)param_1 & 0x80000000);
  }
  if (-1 < (int)uVar2) {
    uVar2 = DAT_600ccb78 >> (uVar2 & 0xff);
    if (((uint)param_1 & uVar2) != 0) {
      fVar1 = (float)((uint)param_1 & ~uVar2);
      *param_2 = fVar1;
      return param_1 - fVar1;
    }
    *param_2 = param_1;
    return (float)((uint)param_1 & 0x80000000);
  }
  *param_2 = (float)((uint)param_1 & 0x80000000);
  return param_1;
}



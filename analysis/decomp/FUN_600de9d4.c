// 600de9d4  FUN_600de9d4  size=102 bytes
// --- callers ---
// --- callees ---


void FUN_600de9d4(undefined4 *param_1)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  
  if (0 < (int)param_1[0xd]) {
    iVar1 = param_1[0xd] + -1;
    param_1[0xd] = iVar1;
    if (iVar1 == 0) {
      param_1[6] = param_1[3];
      param_1[7] = param_1[4];
      param_1[8] = param_1[5];
      *param_1 = param_1[3];
      param_1[1] = param_1[4];
      param_1[2] = param_1[5];
    }
    else {
      fVar2 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
      fVar2 = fVar2 * (float)param_1[10];
      param_1[1] = (1.0 - fVar2) * (float)param_1[4] + (float)param_1[7] * fVar2;
      param_1[2] = (1.0 - fVar2) * (float)param_1[5] + (float)param_1[8] * fVar2;
    }
  }
  return;
}



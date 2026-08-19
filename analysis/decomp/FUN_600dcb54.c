// 600dcb54  FUN_600dcb54  size=74 bytes
// --- callers ---
// --- callees ---


void FUN_600dcb54(float param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  float fVar3;
  
  if (*param_2 < param_3) {
    param_2[6] = param_2[3];
    param_2[5] = (int)((float)param_2[1] * param_1);
    return;
  }
  iVar1 = param_2[6];
  uVar2 = iVar1 - 1;
  param_2[6] = uVar2 & ~((int)uVar2 >> 0x1f);
  if (iVar1 < 2) {
    fVar3 = (float)param_2[4];
    if ((int)((uint)((float)param_2[5] * (float)param_2[2] < (float)param_2[4]) << 0x1f) < 0) {
      fVar3 = (float)param_2[5] * (float)param_2[2];
    }
    param_2[5] = (int)fVar3;
  }
  return;
}



// 600dc9c0  FUN_600dc9c0  size=184 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600dc9c0(float param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 in_cr0;
  undefined4 in_cr7;
  float fVar3;
  float fVar4;
  
  if (param_1 <= 0.0) {
    return param_2[7];
  }
  if (*(char *)(param_2 + 6) == '\0') {
    fVar3 = (float)param_2[7];
    if (param_3 == 2) {
      if (param_1 <= fVar3) {
        fVar4 = fVar3 + (float)param_2[3] * (param_1 - fVar3);
        param_2[8] = param_2[5];
        if (-1 < (int)((uint)(fVar3 * (float)param_2[2] < fVar4) << 0x1f)) {
          fVar4 = fVar3 * (float)param_2[2];
        }
        param_2[7] = fVar4;
      }
      else {
        iVar1 = param_2[8];
        uVar2 = iVar1 - 1;
        param_2[8] = uVar2 & ~((int)uVar2 >> 0x1f);
        if (iVar1 < 2) {
          if (-1 < (int)((uint)(param_1 < fVar3 * (float)param_2[1]) << 0x1f)) {
            param_1 = fVar3 * (float)param_2[1];
          }
          param_2[7] = param_1;
        }
      }
    }
    else {
      param_2[7] = (float)param_2[4] * fVar3;
    }
    coprocessor_function2(10,3,1,in_cr0,in_cr0,in_cr7);
  }
  else {
    *(undefined1 *)(param_2 + 6) = 0;
    coprocessor_function2(10,3,0,in_cr0,in_cr0,in_cr7);
  }
  param_2[7] = *param_2;
  return *param_2;
}



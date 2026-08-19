// 600dca98  FUN_600dca98  size=150 bytes
// --- callers ---
// --- callees ---


float FUN_600dca98(float param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = *(float *)(param_2 + 0x18);
  if (param_1 != 0.0) {
    if ((int)((uint)(fVar4 < param_1) << 0x1f) < 0) {
      *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x14);
      *(undefined1 *)(param_2 + 0x20) = 0;
      *(float *)(param_2 + 0x18) = fVar4 + *(float *)(param_2 + 8) * (param_1 - fVar4);
    }
    else {
      iVar1 = *(int *)(param_2 + 0x1c);
      uVar2 = iVar1 - 1;
      *(uint *)(param_2 + 0x1c) = uVar2 & ~((int)uVar2 >> 0x1f);
      if (((param_3 == 0) && (iVar1 < 2)) || (*(char *)(param_2 + 0x20) != '\0')) {
        fVar3 = fVar4 + *(float *)(param_2 + 0x10) * (param_1 - fVar4);
        fVar4 = fVar4 * *(float *)(param_2 + 0xc);
        if (-1 < (int)((uint)(fVar3 < fVar4) << 0x1f)) {
          fVar4 = fVar3;
        }
        *(float *)(param_2 + 0x18) = fVar4;
      }
    }
    fVar4 = *(float *)(param_2 + 4);
    if (-1 < (int)((uint)(*(float *)(param_2 + 0x18) < *(float *)(param_2 + 4)) << 0x1f)) {
      fVar4 = *(float *)(param_2 + 0x18);
    }
    *(float *)(param_2 + 0x18) = fVar4;
  }
  return fVar4;
}



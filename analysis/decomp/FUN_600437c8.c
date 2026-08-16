// 600437c8  FUN_600437c8  size=98 bytes
// --- callers ---
// --- callees ---


void FUN_600437c8(int param_1,uint param_2,int param_3)

{
  float fVar1;
  uint uVar2;
  float *pfVar3;
  float fStack_10;
  float fStack_c;
  
  fVar1 = fRam60043830;
  fStack_c = fRam6004382c;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1) {
    pfVar3 = (float *)(param_1 + uVar2 * 4);
    if ((int)((uint)(*pfVar3 < fStack_c) << 0x1f) < 0) {
      pfVar3 = &fStack_c;
    }
    if (fVar1 < *pfVar3) {
      pfVar3 = &fStack_10;
    }
    *(short *)(param_3 + uVar2 * 2) = (short)(int)*pfVar3;
  }
  return;
}



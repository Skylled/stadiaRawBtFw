// 600ddbc4  FUN_600ddbc4  size=132 bytes
// --- callers ---
//   6007dac0 FUN_6007dac0
// --- callees ---


void FUN_600ddbc4(int *param_1,int *param_2,int param_3,float *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  
  iVar3 = *param_2;
  iVar1 = param_3 - *(int *)(*param_1 + 0x98);
  iVar4 = param_2[5] + iVar3;
  iVar2 = iVar4;
  if (-1 < iVar1) {
    iVar2 = iVar4 + iVar1;
  }
  iVar4 = param_3 + *(int *)(*param_1 + 0x9c) + 1 + iVar4;
  iVar2 = iVar2 - iVar3 * (iVar2 / iVar3);
  pfVar5 = param_4;
  do {
    pfVar6 = pfVar5 + 1;
    *pfVar5 = 0.0;
    pfVar5 = pfVar6;
  } while (pfVar6 != param_4 + 0x41);
  while (iVar2 != iVar4 - iVar3 * (iVar4 / iVar3)) {
    pfVar6 = *(float **)(param_2[1] + iVar2 * 0xc);
    for (pfVar5 = param_4; param_4 + 0x41 != pfVar5; pfVar5 = pfVar5 + 1) {
      fVar7 = *pfVar6;
      pfVar6 = pfVar6 + 1;
      fVar8 = *pfVar5;
      if ((int)((uint)(*pfVar5 < fVar7) << 0x1f) < 0) {
        fVar8 = fVar7;
      }
      *pfVar5 = fVar8;
    }
    if (iVar2 < iVar3 + -1) {
      iVar2 = iVar2 + 1;
    }
    else {
      iVar2 = 0;
    }
  }
  return;
}



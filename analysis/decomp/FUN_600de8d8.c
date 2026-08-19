// 600de8d8  FUN_600de8d8  size=182 bytes
// --- callers ---
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588


void FUN_600de8d8(int param_1,uint param_2,uint param_3,float *param_4,float *param_5)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  int *piVar6;
  float fVar7;
  
  pfVar2 = param_4 + 0x41;
  pfVar1 = param_4;
  do {
    pfVar5 = pfVar1 + 1;
    *pfVar1 = 0.0;
    pfVar1 = pfVar5;
  } while (pfVar2 != pfVar5);
  piVar6 = *(int **)(param_1 + 4);
  uVar4 = 0;
  iVar3 = piVar6[5];
  while (uVar4 != param_2) {
    pfVar5 = *(float **)(piVar6[1] + iVar3 * 0xc);
    for (pfVar1 = param_4; pfVar2 != pfVar1; pfVar1 = pfVar1 + 1) {
      fVar7 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      *pfVar1 = *pfVar1 + fVar7;
    }
    uVar4 = uVar4 + 1;
    if (iVar3 < *piVar6 + -1) {
      iVar3 = iVar3 + 1;
    }
    else {
      iVar3 = 0;
    }
  }
  if (pfVar2 != param_4) {
    thunk_EXT_FUN_0000b588(param_5,param_4,(int)pfVar2 - (int)param_4);
  }
  while (uVar4 < param_3) {
    piVar6 = *(int **)(param_1 + 4);
    pfVar2 = *(float **)(piVar6[1] + iVar3 * 0xc);
    for (pfVar1 = param_5; param_5 + 0x41 != pfVar1; pfVar1 = pfVar1 + 1) {
      fVar7 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      *pfVar1 = *pfVar1 + fVar7;
    }
    uVar4 = uVar4 + 1;
    if (iVar3 < *piVar6 + -1) {
      iVar3 = iVar3 + 1;
    }
    else {
      iVar3 = 0;
    }
  }
  return;
}



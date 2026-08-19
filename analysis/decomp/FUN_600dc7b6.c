// 600dc7b6  FUN_600dc7b6  size=270 bytes
// --- callers ---
//   6007c698 FUN_6007c698
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588


void FUN_600dc7b6(float *param_1,int param_2,int param_3,float *param_4,int param_5)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  float fVar9;
  
  for (pfVar2 = param_4; param_4 + 0xa0 != pfVar2; pfVar2 = pfVar2 + 1) {
    *pfVar2 = 0.0;
  }
  pfVar3 = (float *)(param_5 + (0xf - param_3) * 4);
  for (pfVar2 = param_4; pfVar5 = param_1, pfVar7 = pfVar3, pfVar2 != param_4 + param_3;
      pfVar2 = pfVar2 + 1) {
    do {
      pfVar1 = pfVar5 + 1;
      *pfVar2 = *pfVar2 + *pfVar7 * *pfVar5;
      pfVar5 = pfVar1;
      pfVar7 = pfVar7 + -4;
    } while (param_1 + 4 != pfVar1);
    pfVar3 = pfVar3 + 1;
  }
  iVar8 = 0;
  do {
    iVar4 = (iVar8 >> 2) + 1;
    if (3 < iVar4) {
      iVar4 = 4;
    }
    pfVar3 = param_1;
    pfVar5 = (float *)(param_2 + iVar8 * 4);
    do {
      fVar9 = *pfVar3;
      pfVar3 = pfVar3 + 1;
      *pfVar2 = *pfVar2 + *pfVar5 * fVar9;
      pfVar5 = pfVar5 + -4;
    } while (param_1 + iVar4 != pfVar3);
    pfVar3 = (float *)(param_5 + (iVar8 + 0xf + iVar4 * -4) * 4);
    for (pfVar5 = param_1 + iVar4; param_1 + 4 != pfVar5; pfVar5 = pfVar5 + 1) {
      *pfVar2 = *pfVar2 + *pfVar3 * *pfVar5;
      pfVar3 = pfVar3 + -4;
    }
    iVar8 = iVar8 + 1;
    pfVar2 = pfVar2 + 1;
  } while ((uint)(iVar8 + param_3) < 0x10);
  pfVar1 = param_4 + 0x10;
  pfVar3 = (float *)(param_2 + (0x10 - param_3) * 4);
  pfVar2 = param_1;
  pfVar7 = pfVar3;
  do {
    do {
      pfVar6 = pfVar2 + 1;
      *pfVar1 = *pfVar1 + *pfVar3 * *pfVar2;
      pfVar2 = pfVar6;
      pfVar3 = pfVar3 + -4;
    } while (pfVar5 != pfVar6);
    pfVar1 = pfVar1 + 1;
    pfVar3 = pfVar7 + 1;
    pfVar2 = param_1;
    pfVar7 = pfVar3;
  } while (param_4 + 0xa0 != pfVar1);
  thunk_EXT_FUN_0000b588(param_5,param_2 + 0x244,0x3c);
  return;
}



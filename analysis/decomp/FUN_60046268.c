// 60046268  FUN_60046268  size=98 bytes
// --- callers ---
//   60045738 FUN_60045738
// --- callees ---
//   6004aee0 FUN_6004aee0
//   6004c18c thunk_FUN_600dcd1c


void FUN_60046268(undefined4 param_1,float *param_2,int param_3,int param_4,undefined4 param_5)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float afStack_218 [64];
  float afStack_118 [65];
  
  pfVar2 = afStack_218;
  do {
    pfVar3 = pfVar2 + 1;
    *pfVar2 = 0.0;
    pfVar2 = pfVar3;
  } while (pfVar3 != afStack_118);
  if (param_4 == 0) {
    thunk_FUN_600dcd1c(param_2,param_2 + param_3,pfVar3,0,param_2,param_3);
  }
  else if (param_4 == 1) {
    pfVar1 = param_2 + param_3;
    pfVar2 = DAT_600462cc;
    for (; pfVar1 != param_2; param_2 = param_2 + 1) {
      fVar4 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      *pfVar3 = *param_2 * fVar4;
      pfVar3 = pfVar3 + 1;
    }
  }
  FUN_6004aee0(param_1,afStack_218,param_5);
  return;
}



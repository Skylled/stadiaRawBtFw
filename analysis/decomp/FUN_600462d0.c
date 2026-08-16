// 600462d0  FUN_600462d0  size=156 bytes
// --- callers ---
// --- callees ---
//   6004aee0 FUN_6004aee0
//   6004c18c thunk_FUN_600dcd1c


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_600462d0(undefined4 param_1,float *param_2,int param_3,float *param_4,int param_5,
                 int param_6,undefined4 param_7)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float afStack_220 [129];
  
  if (param_6 == 0) {
    thunk_FUN_600dcd1c(param_4,param_4 + param_5,afStack_220,param_4,param_2,param_3);
    thunk_FUN_600dcd1c(param_2,param_2 + param_3,afStack_220 + param_5);
  }
  else if (param_6 == 2) {
    pfVar1 = afStack_220;
    pfVar3 = param_4 + param_5;
    pfVar2 = _DAT_6004636c;
    for (; pfVar3 != param_4; param_4 = param_4 + 1) {
      fVar4 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      *pfVar1 = *param_4 * fVar4;
      pfVar1 = pfVar1 + 1;
    }
    pfVar3 = param_2 + param_3;
    pfVar1 = afStack_220 + param_5;
    pfVar2 = _DAT_6004636c + param_5;
    for (; param_2 != pfVar3; param_2 = param_2 + 1) {
      fVar4 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      *pfVar1 = *param_2 * fVar4;
      pfVar1 = pfVar1 + 1;
    }
  }
  FUN_6004aee0(param_1,afStack_220,param_7);
  return;
}



// 6004a38e  FUN_6004a38e  size=54 bytes
// --- callers ---
//   60043af0 FUN_60043af0
// --- callees ---
//   600454ec FUN_600454ec


void FUN_6004a38e(float *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *extraout_r1;
  float *pfVar1;
  float *extraout_r2;
  float *pfVar2;
  float *extraout_r3;
  undefined4 extraout_s0;
  undefined4 *puVar3;
  
  pfVar1 = param_1 + param_2;
  pfVar2 = param_1;
  puVar3 = param_3;
  while (pfVar2 != pfVar1) {
    param_1 = (float *)FUN_600454ec(-*pfVar2,param_1,param_3,pfVar1,pfVar2 + 1,puVar3,param_4);
    *extraout_r1 = extraout_s0;
    param_3 = extraout_r1 + 1;
    pfVar1 = extraout_r2;
    pfVar2 = extraout_r3;
  }
  return;
}



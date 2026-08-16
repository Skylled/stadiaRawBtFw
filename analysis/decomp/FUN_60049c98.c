// 60049c98  FUN_60049c98  size=178 bytes
// --- callers ---
//   60043ecc FUN_60043ecc
// --- callees ---
//   6004a34c FUN_6004a34c
//   6004a0e6 FUN_6004a0e6


void FUN_60049c98(int param_1,float *param_2,undefined4 param_3,float *param_4,undefined4 param_5,
                 float *param_6,undefined4 param_7,float *param_8)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  
  FUN_6004a0e6(0x100,1,param_2,param_1 + 0x14cc,param_1 + 0x16cc);
  *param_6 = 0.0;
  fVar3 = *param_2;
  *param_4 = fVar3;
  *param_8 = ABS(fVar3) + 1.0;
  param_6[0x80] = 0.0;
  fVar3 = param_2[1];
  param_4[0x80] = fVar3;
  param_8[0x80] = ABS(fVar3) + 1.0;
  pfVar1 = param_2;
  do {
    param_6 = param_6 + 1;
    param_8 = param_8 + 1;
    param_4 = param_4 + 1;
    pfVar2 = pfVar1 + 2;
    *param_4 = pfVar1[2];
    fVar3 = pfVar1[3];
    *param_6 = fVar3;
    fVar3 = (float)FUN_6004a34c(fVar3 * fVar3 + *param_4 * *param_4);
    *param_8 = fVar3 + 1.0;
    pfVar1 = pfVar2;
  } while (pfVar2 != param_2 + 0xfe);
  return;
}



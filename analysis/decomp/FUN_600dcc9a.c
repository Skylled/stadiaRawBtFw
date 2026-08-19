// 600dcc9a  FUN_600dcc9a  size=130 bytes
// --- callers ---
//   6007c7f4 FUN_6007c7f4
// --- callees ---


undefined4 FUN_600dcc9a(uint *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  float *pfVar4;
  float *pfVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  
  uVar2 = *param_1;
  pfVar5 = (float *)(param_2 + uVar2 * 4);
  pfVar4 = (float *)(param_4 + uVar2 * 4);
  uVar3 = 0;
  uVar6 = 0;
  for (; uVar2 < param_1[1]; uVar2 = uVar2 + 1) {
    fVar8 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    fVar7 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    if (((int)((uint)(fVar7 < (float)param_1[2] * fVar8) << 0x1f) < 0) &&
       ((int)((uint)(fVar8 < fVar7 * (float)param_1[2]) << 0x1f) < 0)) {
      uVar6 = uVar6 + 1;
    }
    else if (fVar8 * (float)param_1[3] < fVar7) {
      uVar3 = uVar3 + 1;
    }
  }
  if (param_1[4] < uVar6) {
    uVar1 = 2;
  }
  else if (param_1[5] < uVar3) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



// 600de2a2  FUN_600de2a2  size=178 bytes
// --- callers ---
//   6007c7f4 FUN_6007c7f4
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588


void FUN_600de2a2(int param_1,float *param_2,int param_3,int param_4)

{
  int iVar1;
  float *pfVar2;
  float *extraout_r3;
  float *pfVar3;
  float *pfVar4;
  undefined4 in_cr7;
  float fVar5;
  float fVar6;
  float fVar7;
  
  pfVar4 = (float *)(param_1 + 0x14);
  if (param_4 == 0) {
    pfVar2 = param_2 + param_3;
    pfVar3 = pfVar4;
    while (pfVar2 != param_2) {
      fVar7 = *pfVar3;
      fVar6 = *param_2;
      param_2 = param_2 + 1;
      fVar5 = fVar6 - fVar7;
      if ((int)((uint)(fVar7 < fVar6) << 0x1f) < 0) {
        coprocessor_function2(10,7,4,in_cr7,in_cr7,in_cr7);
        fVar7 = fVar7 + *(float *)(param_1 + 4) * fVar5;
      }
      else {
        fVar6 = fVar7 * *(float *)(param_1 + 8);
        fVar7 = fVar7 + *(float *)(param_1 + 0xc) * fVar5;
        if (-1 < (int)((uint)(fVar6 < fVar7) << 0x1f)) {
          fVar7 = fVar6;
        }
      }
      *pfVar3 = fVar7;
      pfVar3 = pfVar3 + 1;
    }
  }
  else {
    pfVar3 = param_2 + param_3;
    if (param_2 != pfVar3) {
      thunk_EXT_FUN_0000b588(pfVar4);
      pfVar3 = extraout_r3;
    }
  }
  for (; pfVar4 != (float *)(param_1 + 0xf4); pfVar4 = pfVar4 + 1) {
    iVar1 = (uint)(*pfVar4 < *(float *)(param_1 + 0x10)) << 0x1f;
    if (-1 < iVar1) {
      pfVar3 = pfVar4;
    }
    if (iVar1 < 0) {
      pfVar3 = (float *)(param_1 + 0x10);
    }
    pfVar3 = (float *)*pfVar3;
    *pfVar4 = (float)pfVar3;
  }
  return;
}



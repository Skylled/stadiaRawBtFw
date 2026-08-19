// 600dd364  FUN_600dd364  size=282 bytes
// --- callers ---
// --- callees ---
//   600dcf8c FUN_600dcf8c
//   6013d010 thunk_EXT_FUN_0000954a


void FUN_600dd364(uint param_1,float *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  float *pfVar2;
  uint uVar3;
  float *pfVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  if (param_1 < 9) {
    uVar3 = 2;
  }
  else {
    thunk_EXT_FUN_0000954a();
    uVar3 = 8;
    while (uVar3 << 2 < param_1) {
      FUN_600dcf8c(param_1,uVar3,param_2,param_3,param_4);
      uVar3 = uVar3 << 2;
    }
  }
  if (uVar3 * 4 - param_1 == 0) {
    uVar1 = 0;
    pfVar2 = (float *)((int)((int)param_2 + param_1) + param_1);
    pfVar4 = (float *)((int)param_2 + param_1);
    pfVar5 = (float *)(param_1 + (int)pfVar2);
    while( true ) {
      if (uVar3 <= uVar1) break;
      uVar1 = uVar1 + 2;
      fVar12 = param_2[1] + pfVar4[1];
      fVar13 = param_2[1] - pfVar4[1];
      fVar10 = *param_2 + *pfVar4;
      fVar11 = *param_2 - *pfVar4;
      fVar6 = *pfVar2 + *pfVar5;
      fVar9 = *pfVar2 - *pfVar5;
      fVar7 = pfVar2[1] + pfVar5[1];
      fVar8 = pfVar2[1] - pfVar5[1];
      *param_2 = fVar10 + fVar6;
      param_2[1] = fVar12 + fVar7;
      pfVar2[1] = fVar12 - fVar7;
      *pfVar2 = fVar10 - fVar6;
      *pfVar4 = fVar11 - fVar8;
      pfVar4[1] = fVar13 + fVar9;
      *pfVar5 = fVar11 + fVar8;
      pfVar5[1] = fVar13 - fVar9;
      pfVar2 = pfVar2 + 2;
      param_2 = param_2 + 2;
      pfVar4 = pfVar4 + 2;
      pfVar5 = pfVar5 + 2;
    }
  }
  else {
    uVar1 = 0;
    pfVar2 = param_2 + uVar3;
    while( true ) {
      if (uVar3 <= uVar1) break;
      fVar12 = *param_2;
      uVar1 = uVar1 + 2;
      fVar7 = *pfVar2;
      fVar6 = param_2[1];
      fVar10 = pfVar2[1];
      *param_2 = fVar12 + fVar7;
      param_2[1] = pfVar2[1] + fVar6;
      *pfVar2 = fVar12 - fVar7;
      pfVar2[1] = fVar6 - fVar10;
      param_2 = param_2 + 2;
      pfVar2 = pfVar2 + 2;
    }
  }
  return;
}



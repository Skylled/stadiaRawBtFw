// 600ce596  FUN_600ce596  size=54 bytes
// --- callers ---
//   60051a50 FUN_60051a50
// --- callees ---


void FUN_600ce596(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  uVar1 = *param_1;
  uVar3 = param_1[1];
  uVar6 = param_1[2];
  uVar9 = param_1[3];
  uVar2 = param_1[4];
  uVar4 = param_1[5];
  uVar7 = param_1[6];
  uVar10 = param_1[7];
  uVar12 = param_1[8];
  uVar5 = param_2[1];
  uVar8 = param_2[2];
  uVar11 = param_2[3];
  *param_1 = *param_2;
  param_1[1] = uVar5;
  param_1[2] = uVar8;
  param_1[3] = uVar11;
  uVar5 = param_2[5];
  uVar8 = param_2[6];
  uVar11 = param_2[7];
  param_1[4] = param_2[4];
  param_1[5] = uVar5;
  param_1[6] = uVar8;
  param_1[7] = uVar11;
  param_1[8] = param_2[8];
  *param_2 = uVar1;
  param_2[1] = uVar3;
  param_2[2] = uVar6;
  param_2[3] = uVar9;
  param_2[4] = uVar2;
  param_2[5] = uVar4;
  param_2[6] = uVar7;
  param_2[7] = uVar10;
  param_2[8] = uVar12;
  return;
}



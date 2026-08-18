// 600ce440  FUN_600ce440  size=72 bytes
// --- callers ---
//   60051b50 stats__60051b50
//   600ce488 FUN_600ce488
// --- callees ---


void FUN_600ce440(undefined4 *param_1)

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
  uint uVar10;
  
  uVar10 = param_1[2];
  uVar1 = *param_1;
  uVar3 = param_1[1];
  uVar5 = param_1[2];
  uVar7 = param_1[3];
  uVar2 = param_1[4];
  uVar4 = param_1[5];
  uVar6 = param_1[6];
  uVar8 = param_1[7];
  uVar9 = param_1[8];
  while (uVar10 < (uint)param_1[-7]) {
    *param_1 = param_1[-9];
    param_1[1] = param_1[-8];
    param_1[2] = param_1[-7];
    param_1[3] = param_1[-6];
    param_1[4] = param_1[-5];
    param_1[5] = param_1[-4];
    param_1[6] = param_1[-3];
    param_1[7] = param_1[-2];
    param_1[8] = param_1[-1];
    param_1 = param_1 + -9;
  }
  *param_1 = uVar1;
  param_1[1] = uVar3;
  param_1[2] = uVar5;
  param_1[3] = uVar7;
  param_1[4] = uVar2;
  param_1[5] = uVar4;
  param_1[6] = uVar6;
  param_1[7] = uVar8;
  param_1[8] = uVar9;
  return;
}



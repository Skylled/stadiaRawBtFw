// 600e20c2  FUN_600e20c2  size=100 bytes
// --- callers ---
//   600e6f7a FUN_600e6f7a
// --- callees ---


void FUN_600e20c2(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar3 = param_1[2];
  uVar8 = param_1[3];
  uVar10 = param_1[4];
  uVar5 = param_1[5];
  uVar4 = param_1[6];
  uVar9 = param_1[7];
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar7 = uVar1 ^ uVar8;
  uVar6 = uVar2 ^ uVar10;
  *param_1 = ~(uVar3 ^ uVar5 ^ uVar9);
  param_1[1] = uVar4 ^ uVar7;
  param_1[3] = uVar1 ^ uVar3 ^ uVar5;
  param_1[2] = ~(uVar9 ^ uVar6);
  param_1[4] = uVar2 ^ uVar8 ^ uVar4;
  param_1[5] = uVar3 ^ uVar10 ^ uVar9;
  param_1[6] = uVar5 ^ uVar7;
  param_1[7] = uVar4 ^ uVar6;
  return;
}



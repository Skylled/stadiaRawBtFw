// 600c8b24  FUN_600c8b24  size=1198 bytes
// --- callers ---
//   601005ac FUN_601005ac
// --- callees ---
//   601002bc FUN_601002bc
//   601004b2 FUN_601004b2


void FUN_600c8b24(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar1 = DAT_600c8d90;
  *param_1 = *param_2 + param_2[6];
  uVar3 = *param_1;
  uVar4 = *param_2;
  *param_1 = *param_1 + param_2[10];
  param_1[1] = (uint)(uVar3 < uVar4) + (uint)(*param_1 < param_2[10]) + param_2[1];
  uVar3 = param_1[1];
  uVar5 = param_2[1];
  param_1[1] = param_2[7] + param_1[1];
  uVar4 = param_1[1];
  uVar6 = param_2[7];
  param_1[1] = param_2[0xb] + param_1[1];
  param_1[2] = (uint)(uVar3 < uVar5) + (uint)(uVar4 < uVar6) + (uint)(param_1[1] < param_2[0xb]) +
               param_2[2];
  uVar3 = param_1[2];
  uVar6 = param_2[2];
  param_1[2] = param_2[6] + param_1[2];
  uVar4 = param_1[2];
  uVar7 = param_2[6];
  param_1[2] = param_2[8] + param_1[2];
  uVar5 = param_1[2];
  uVar8 = param_2[8];
  param_1[2] = param_2[10] + param_1[2];
  param_1[3] = (uint)(uVar3 < uVar6) + (uint)(uVar4 < uVar7) + (uint)(uVar5 < uVar8) +
               (uint)(param_1[2] < param_2[10]) + param_2[3];
  uVar3 = param_1[3];
  uVar6 = param_2[3];
  param_1[3] = param_2[7] + param_1[3];
  uVar4 = param_1[3];
  uVar7 = param_2[7];
  param_1[3] = param_2[9] + param_1[3];
  uVar5 = param_1[3];
  uVar8 = param_2[9];
  param_1[3] = param_2[0xb] + param_1[3];
  param_1[4] = (uint)(uVar3 < uVar6) + (uint)(uVar4 < uVar7) + (uint)(uVar5 < uVar8) +
               (uint)(param_1[3] < param_2[0xb]) + param_2[4];
  uVar3 = param_1[4];
  uVar5 = param_2[4];
  param_1[4] = param_2[8] + param_1[4];
  uVar4 = param_1[4];
  uVar6 = param_2[8];
  param_1[4] = param_2[10] + param_1[4];
  param_1[5] = (uint)(uVar3 < uVar5) + (uint)(uVar4 < uVar6) + (uint)(param_1[4] < param_2[10]) +
               param_2[5];
  uVar3 = param_1[5];
  uVar5 = param_2[5];
  param_1[5] = param_2[9] + param_1[5];
  uVar4 = param_1[5];
  uVar6 = param_2[9];
  param_1[5] = param_2[0xb] + param_1[5];
  uVar3 = (uint)(uVar3 < uVar5) + (uint)(uVar4 < uVar6) + (uint)(param_1[5] < param_2[0xb]);
  *param_1 = *param_1 + uVar3;
  param_1[1] = (uint)(*param_1 < uVar3) + param_1[1];
  param_1[2] = (uint)(param_1[1] < (uint)(*param_1 < uVar3)) + param_1[2];
  param_1[2] = uVar3 + param_1[2];
  param_1[3] = (uint)(param_1[2] < uVar3) + param_1[3];
  uVar3 = (uint)(param_1[3] < (uint)(param_1[2] < uVar3));
  param_1[4] = uVar3 + param_1[4];
  uVar3 = (uint)(param_1[4] < uVar3);
  param_1[5] = uVar3 + param_1[5];
  if (param_1[5] < uVar3) {
    FUN_601004b2(param_1,param_1,uVar1,6);
  }
  else {
    iVar2 = FUN_601002bc(param_1,uVar1,6);
    if (-1 < iVar2) {
      FUN_601004b2(param_1,param_1,uVar1,6);
    }
  }
  return;
}



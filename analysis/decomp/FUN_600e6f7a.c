// 600e6f7a  FUN_600e6f7a  size=262 bytes
// --- callers ---
//   600e70e2 FUN_600e70e2
// --- callees ---
//   600e20c2 FUN_600e20c2
//   600e219a FUN_600e219a
//   600e1e7a FUN_600e1e7a
//   600e1e5e FUN_600e1e5e
//   600e2158 FUN_600e2158
//   600e21aa FUN_600e21aa


void FUN_600e6f7a(int param_1,int param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  uint extraout_r2_01;
  uint extraout_r2_02;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  
  iVar10 = param_1 + param_2 * 0x20;
  FUN_600e1e5e(param_3,iVar10);
  while( true ) {
    param_2 = param_2 + -1;
    FUN_600e2158(param_3);
    FUN_600e20c2(param_3);
    iVar10 = iVar10 + -0x20;
    FUN_600e1e7a();
    uVar1 = FUN_600e20c2();
    if (param_2 == 0) break;
    FUN_600e1e5e(param_3,iVar10);
    uVar6 = *param_3;
    uVar7 = param_3[4];
    uVar13 = FUN_600e219a(uVar6,param_3[1],param_3[5]);
    uVar12 = param_3[2];
    uVar11 = param_3[3];
    uVar9 = param_3[6];
    uVar8 = param_3[7];
    uVar14 = FUN_600e219a((int)((ulonglong)uVar13 >> 0x20));
    uVar2 = FUN_600e219a(uVar12);
    uVar3 = FUN_600e219a(uVar11);
    uVar4 = FUN_600e219a(uVar7);
    uVar15 = FUN_600e219a(extraout_r2_00);
    uVar5 = FUN_600e219a(uVar9,(int)((ulonglong)uVar15 >> 0x20),extraout_r2_01 ^ uVar8);
    uVar5 = uVar9 ^ uVar5;
    uVar16 = FUN_600e219a(uVar8);
    uVar8 = (uint)uVar16 ^ uVar8;
    *param_3 = uVar6 ^ uVar5;
    param_3[1] = (uint)((ulonglong)uVar16 >> 0x20) ^ uVar5 ^ uVar8;
    param_3[2] = (uint)uVar13 ^ uVar6 ^ uVar12 ^ uVar8;
    param_3[3] = uVar5 ^ (uint)uVar14 ^ (uint)((ulonglong)uVar14 >> 0x20) ^ uVar11;
    param_3[4] = uVar2 ^ uVar12 ^ uVar7 ^ uVar5 ^ uVar8;
    param_3[5] = uVar8 ^ uVar11 ^ extraout_r2 ^ uVar3;
    param_3[6] = uVar7 ^ uVar9 ^ uVar4;
    param_3[7] = extraout_r2_02 ^ (uint)uVar15;
    FUN_600e21aa(param_3);
  }
  FUN_600e1e5e(uVar1,param_1);
  return;
}



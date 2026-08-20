// 600e21aa  FUN_600e21aa  size=248 bytes
// --- callers ---
//   600e22a2 FUN_600e22a2
//   600e6f7a FUN_600e6f7a
// --- callees ---
//   600e219a FUN_600e219a
//   600e218a FUN_600e218a


void FUN_600e21aa(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  int extraout_r2_02;
  int extraout_r2_03;
  int extraout_r2_04;
  int extraout_r2_05;
  int extraout_r2_06;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  
  uVar8 = *param_1;
  uVar13 = param_1[1];
  uVar7 = param_1[6];
  uVar10 = param_1[4];
  uVar9 = param_1[5];
  uVar12 = param_1[2];
  uVar11 = param_1[3];
  uVar1 = FUN_600e218a(uVar8,param_1[7],param_1);
  uVar8 = uVar8 ^ uVar1;
  uVar2 = FUN_600e218a(uVar13);
  uVar13 = uVar13 ^ uVar2;
  uVar3 = FUN_600e218a(uVar12);
  uVar12 = uVar12 ^ uVar3;
  uVar4 = FUN_600e218a(uVar11);
  uVar11 = uVar11 ^ uVar4;
  uVar5 = FUN_600e218a(uVar10);
  uVar10 = uVar10 ^ uVar5;
  uVar6 = FUN_600e218a(uVar9);
  uVar9 = uVar9 ^ uVar6;
  uVar14 = FUN_600e218a(uVar7);
  uVar7 = uVar7 ^ (uint)uVar14;
  uVar15 = FUN_600e218a((int)((ulonglong)uVar14 >> 0x20));
  uVar16 = FUN_600e219a(uVar8,(uint)((ulonglong)uVar15 >> 0x20) ^ (uint)uVar15);
  *extraout_r2 = (uint)uVar16 ^ uVar1 ^ (uint)((ulonglong)uVar16 >> 0x20);
  uVar16 = FUN_600e219a(uVar13);
  *(uint *)(extraout_r2_00 + 4) = uVar8 ^ (uint)uVar16 ^ uVar2 ^ (uint)((ulonglong)uVar16 >> 0x20);
  uVar1 = FUN_600e219a(uVar12);
  *(uint *)(extraout_r2_01 + 8) = uVar1 ^ uVar3 ^ uVar13;
  uVar16 = FUN_600e219a(uVar11);
  *(uint *)(extraout_r2_02 + 0xc) =
       (uint)uVar16 ^ uVar4 ^ uVar12 ^ (uint)((ulonglong)uVar16 >> 0x20);
  uVar16 = FUN_600e219a(uVar10);
  *(uint *)(extraout_r2_03 + 0x10) =
       (uint)uVar16 ^ uVar5 ^ uVar11 ^ (uint)((ulonglong)uVar16 >> 0x20);
  uVar1 = FUN_600e219a(uVar9);
  *(uint *)(extraout_r2_04 + 0x14) = uVar1 ^ uVar6 ^ uVar10;
  uVar16 = FUN_600e219a(uVar7);
  *(uint *)(extraout_r2_05 + 0x18) = (uint)uVar14 ^ (uint)uVar16 ^ uVar9;
  uVar1 = FUN_600e219a((int)((ulonglong)uVar16 >> 0x20));
  *(uint *)(extraout_r2_06 + 0x1c) = uVar7 ^ uVar1 ^ (uint)uVar15;
  return;
}



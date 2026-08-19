// 600e0e02  FUN_600e0e02  size=1190 bytes
// --- callers ---
//   600e1b5a FUN_600e1b5a
//   600e1c92 FUN_600e1c92
//   600e1cd4 FUN_600e1cd4
//   600877e8 FUN_600877e8
//   60087964 FUN_60087964
//   600e1dde FUN_600e1dde
//   600e1c48 FUN_600e1c48
//   600e1a12 FUN_600e1a12
// --- callees ---


void FUN_600e0e02(uint *param_1,uint *param_2,uint *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint local_a8;
  uint local_98;
  uint local_88;
  uint local_78;
  uint local_70;
  undefined4 local_60;
  uint local_58;
  uint local_50;
  uint local_48;
  
  uVar3 = param_2[9];
  uVar4 = param_3[9];
  uVar5 = uVar4 * 0x26;
  uVar6 = param_3[8];
  uVar7 = uVar6 * 0x13;
  uVar8 = param_3[7];
  uVar9 = uVar8 * 0x26;
  uVar10 = param_3[6];
  uVar11 = uVar10 * 0x13;
  uVar12 = param_3[5];
  uVar13 = uVar12 * 0x26;
  uVar14 = param_3[4];
  uVar15 = uVar14 * 0x13;
  uVar16 = param_3[3];
  uVar17 = param_3[2];
  uVar18 = param_3[1];
  uVar19 = param_2[8];
  uVar20 = uVar4 * 0x13;
  uVar32 = param_2[1];
  uVar21 = uVar8 * 0x13;
  uVar27 = *param_3;
  uVar22 = param_2[7];
  uVar23 = param_2[6];
  uVar24 = uVar18 << 1;
  uVar25 = uVar16 << 1;
  uVar26 = *param_2;
  uVar29 = param_2[4];
  uVar28 = param_2[5];
  uVar31 = param_2[2];
  uVar30 = param_2[3];
  uVar1 = (ulonglong)uVar26 * (ulonglong)uVar27 +
          (ulonglong)uVar32 * (ulonglong)uVar5 +
          (ulonglong)uVar31 * (ulonglong)uVar7 +
          (ulonglong)uVar30 * (ulonglong)uVar9 +
          (ulonglong)uVar29 * (ulonglong)uVar11 +
          (ulonglong)uVar28 * (ulonglong)uVar13 +
          (ulonglong)uVar23 * (ulonglong)uVar15 +
          (ulonglong)uVar22 * (ulonglong)(uVar16 * 0x26) +
          (ulonglong)(uVar18 * 0x26) * (ulonglong)uVar3 +
          (ulonglong)(uVar17 * 0x13) * (ulonglong)uVar19;
  local_60 = (undefined4)uVar1;
  uVar1 = (ulonglong)uVar26 * (ulonglong)uVar18 +
          (ulonglong)uVar27 * (ulonglong)uVar32 +
          (ulonglong)uVar31 * (ulonglong)uVar20 +
          (ulonglong)uVar30 * (ulonglong)uVar7 +
          (ulonglong)uVar29 * (ulonglong)uVar21 +
          (ulonglong)uVar28 * (ulonglong)uVar11 +
          (ulonglong)uVar23 * (ulonglong)(uVar12 * 0x13) +
          (ulonglong)uVar22 * (ulonglong)uVar15 +
          (ulonglong)(uVar17 * 0x13) * (ulonglong)uVar3 +
          (ulonglong)(uVar16 * 0x13) * (ulonglong)uVar19 + (uVar1 >> 0x1a);
  local_58 = (uint)uVar1;
  uVar1 = (ulonglong)uVar26 * (ulonglong)uVar17 +
          (ulonglong)uVar24 * (ulonglong)uVar32 +
          (ulonglong)uVar27 * (ulonglong)uVar31 +
          (ulonglong)uVar30 * (ulonglong)uVar5 +
          (ulonglong)uVar29 * (ulonglong)uVar7 +
          (ulonglong)uVar28 * (ulonglong)uVar9 +
          (ulonglong)uVar23 * (ulonglong)uVar11 +
          (ulonglong)uVar22 * (ulonglong)uVar13 +
          (ulonglong)(uVar16 * 0x26) * (ulonglong)uVar3 + (ulonglong)uVar15 * (ulonglong)uVar19 +
          (uVar1 >> 0x19);
  local_50 = (uint)uVar1;
  uVar1 = (ulonglong)uVar26 * (ulonglong)uVar16 +
          (ulonglong)uVar17 * (ulonglong)uVar32 +
          (ulonglong)uVar18 * (ulonglong)uVar31 +
          (ulonglong)uVar27 * (ulonglong)uVar30 +
          (ulonglong)uVar29 * (ulonglong)uVar20 +
          (ulonglong)uVar28 * (ulonglong)uVar7 +
          (ulonglong)uVar23 * (ulonglong)uVar21 +
          (ulonglong)uVar22 * (ulonglong)uVar11 +
          (ulonglong)uVar15 * (ulonglong)uVar3 + (ulonglong)uVar19 * (ulonglong)(uVar12 * 0x13) +
          (uVar1 >> 0x1a);
  local_70 = (uint)uVar1;
  uVar1 = (ulonglong)uVar26 * (ulonglong)uVar14 +
          (ulonglong)uVar25 * (ulonglong)uVar32 +
          (ulonglong)uVar17 * (ulonglong)uVar31 +
          (ulonglong)uVar24 * (ulonglong)uVar30 +
          (ulonglong)uVar27 * (ulonglong)uVar29 +
          (ulonglong)uVar28 * (ulonglong)uVar5 +
          (ulonglong)uVar23 * (ulonglong)uVar7 +
          (ulonglong)uVar22 * (ulonglong)uVar9 +
          (ulonglong)uVar13 * (ulonglong)uVar3 + (ulonglong)uVar11 * (ulonglong)uVar19 +
          (uVar1 >> 0x19);
  local_48 = (uint)uVar1;
  uVar1 = (ulonglong)uVar26 * (ulonglong)uVar12 +
          (ulonglong)uVar14 * (ulonglong)uVar32 +
          (ulonglong)uVar16 * (ulonglong)uVar31 +
          (ulonglong)uVar17 * (ulonglong)uVar30 +
          (ulonglong)uVar18 * (ulonglong)uVar29 +
          (ulonglong)uVar27 * (ulonglong)uVar28 +
          (ulonglong)uVar23 * (ulonglong)uVar20 +
          (ulonglong)uVar22 * (ulonglong)uVar7 +
          (ulonglong)uVar11 * (ulonglong)uVar3 + (ulonglong)uVar19 * (ulonglong)uVar21 +
          (uVar1 >> 0x1a);
  local_98 = (uint)uVar1;
  uVar1 = (ulonglong)uVar26 * (ulonglong)uVar10 +
          (ulonglong)(uVar12 << 1) * (ulonglong)uVar32 +
          (ulonglong)uVar14 * (ulonglong)uVar31 +
          (ulonglong)uVar25 * (ulonglong)uVar30 +
          (ulonglong)uVar17 * (ulonglong)uVar29 +
          (ulonglong)uVar24 * (ulonglong)uVar28 +
          (ulonglong)uVar27 * (ulonglong)uVar23 +
          (ulonglong)uVar22 * (ulonglong)uVar5 +
          (ulonglong)uVar9 * (ulonglong)uVar3 + (ulonglong)uVar7 * (ulonglong)uVar19 +
          (uVar1 >> 0x19);
  local_78 = (uint)uVar1;
  uVar1 = (ulonglong)uVar26 * (ulonglong)uVar8 +
          (ulonglong)uVar10 * (ulonglong)uVar32 +
          (ulonglong)uVar12 * (ulonglong)uVar31 +
          (ulonglong)uVar14 * (ulonglong)uVar30 +
          (ulonglong)uVar16 * (ulonglong)uVar29 +
          (ulonglong)uVar17 * (ulonglong)uVar28 +
          (ulonglong)uVar18 * (ulonglong)uVar23 +
          (ulonglong)uVar27 * (ulonglong)uVar22 +
          (ulonglong)uVar7 * (ulonglong)uVar3 + (ulonglong)uVar19 * (ulonglong)uVar20 +
          (uVar1 >> 0x1a);
  local_a8 = (uint)uVar1;
  uVar1 = (ulonglong)uVar26 * (ulonglong)uVar6 +
          (ulonglong)(uVar8 << 1) * (ulonglong)uVar32 +
          (ulonglong)uVar10 * (ulonglong)uVar31 +
          (ulonglong)(uVar12 << 1) * (ulonglong)uVar30 +
          (ulonglong)uVar14 * (ulonglong)uVar29 +
          (ulonglong)uVar25 * (ulonglong)uVar28 +
          (ulonglong)uVar17 * (ulonglong)uVar23 +
          (ulonglong)uVar24 * (ulonglong)uVar22 +
          (ulonglong)uVar5 * (ulonglong)uVar3 + (ulonglong)uVar19 * (ulonglong)uVar27 +
          (uVar1 >> 0x19);
  local_88 = (uint)uVar1;
  lVar2 = (ulonglong)uVar4 * (ulonglong)uVar26 +
          (ulonglong)uVar6 * (ulonglong)uVar32 +
          (ulonglong)uVar8 * (ulonglong)uVar31 +
          (ulonglong)uVar10 * (ulonglong)uVar30 +
          (ulonglong)uVar12 * (ulonglong)uVar29 +
          (ulonglong)uVar14 * (ulonglong)uVar28 +
          (ulonglong)uVar16 * (ulonglong)uVar23 +
          (ulonglong)uVar17 * (ulonglong)uVar22 +
          (ulonglong)uVar27 * (ulonglong)uVar3 + (ulonglong)uVar19 * (ulonglong)uVar18 +
          (uVar1 >> 0x1a);
  uVar4 = (uint)lVar2;
  uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
  lVar2 = (ulonglong)(uVar4 >> 0x19 | uVar3 * 0x80) * 0x13 +
          (CONCAT44((uVar3 >> 0x19) * 0x13,local_60) & 0xffffffff03ffffff);
  uVar3 = (uint)lVar2;
  *param_1 = uVar3 & 0x3ffffff;
  uVar3 = (uVar3 >> 0x1a | (int)((ulonglong)lVar2 >> 0x20) * 0x40) + (local_58 & 0x1ffffff);
  param_1[1] = uVar3 & 0x1ffffff;
  param_1[2] = (local_50 & 0x3ffffff) + (uVar3 >> 0x19);
  param_1[3] = local_70 & 0x1ffffff;
  param_1[9] = uVar4 & 0x1ffffff;
  param_1[4] = local_48 & 0x3ffffff;
  param_1[5] = local_98 & 0x1ffffff;
  param_1[6] = local_78 & 0x3ffffff;
  param_1[7] = local_a8 & 0x1ffffff;
  param_1[8] = local_88 & 0x3ffffff;
  return;
}



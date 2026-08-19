// 600e12a8  FUN_600e12a8  size=1160 bytes
// --- callers ---
//   600e1a12 FUN_600e1a12
// --- callees ---


void FUN_600e12a8(uint *param_1,uint *param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
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
  uint local_b0;
  uint local_ac;
  uint local_a0;
  uint local_90;
  uint local_68;
  uint local_64;
  uint local_58;
  
  uVar11 = param_2[9];
  uVar8 = uVar11 * 0x26;
  uVar12 = param_2[8];
  uVar25 = param_2[6];
  uVar13 = uVar12 * 0x13;
  uVar27 = uVar12 * 0x26;
  uVar14 = param_2[7];
  uVar15 = uVar14 * 0x26;
  uVar16 = uVar25 * 0x13;
  uVar30 = param_2[4];
  uVar24 = param_2[5];
  uVar17 = uVar25 << 1;
  uVar18 = uVar30 << 1;
  uVar19 = param_2[3];
  uVar20 = uVar19 << 1;
  uVar21 = param_2[2];
  uVar9 = param_2[1];
  uVar3 = uVar14 * 2;
  uVar4 = uVar24 * 2;
  uVar10 = *param_2;
  lVar1 = (ulonglong)uVar30 * (ulonglong)(uVar25 * 0x26);
  local_64 = (uint)CARRY4(uVar16,uVar16);
  lVar2 = (ulonglong)(uVar24 * 0x26) * (ulonglong)uVar24 + (ulonglong)uVar10 * (ulonglong)uVar10 +
          CONCAT44(uVar30 * local_64 + (int)((ulonglong)lVar1 >> 0x20),(int)lVar1);
  uVar22 = (uint)lVar2;
  uVar28 = (uint)((ulonglong)uVar21 * (ulonglong)uVar27);
  local_ac = (uint)CARRY4(uVar13,uVar13);
  uVar26 = uVar28 + uVar22;
  lVar1 = (ulonglong)uVar19 * (ulonglong)uVar15 + (ulonglong)uVar8 * (ulonglong)uVar9;
  uVar23 = (uint)lVar1;
  uVar29 = uVar26 + uVar23 * 2;
  uVar22 = uVar21 * local_ac + (int)((ulonglong)uVar21 * (ulonglong)uVar27 >> 0x20) +
           (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar28,uVar22) +
           (int)((ulonglong)lVar1 >> 0x20) * 2 + (uint)CARRY4(uVar23,uVar23) +
           (uint)CARRY4(uVar26,uVar23 * 2);
  lVar1 = (ulonglong)uVar24 * (ulonglong)(uVar25 * 0x26);
  uVar5 = (ulonglong)uVar10 * (ulonglong)(uVar9 << 1) +
          (ulonglong)uVar30 * (ulonglong)uVar15 + (ulonglong)uVar8 * (ulonglong)uVar21 +
          CONCAT44(uVar24 * local_64 + (int)((ulonglong)lVar1 >> 0x20),(int)lVar1) +
          CONCAT44(uVar19 * local_ac + (int)((ulonglong)uVar19 * (ulonglong)uVar27 >> 0x20),
                   (int)((ulonglong)uVar19 * (ulonglong)uVar27)) +
          CONCAT44(uVar22 >> 0x1a,uVar29 >> 0x1a | uVar22 * 0x40);
  lVar1 = (ulonglong)uVar10 * (ulonglong)(uVar21 << 1) +
          (ulonglong)uVar25 * (ulonglong)uVar16 + (ulonglong)uVar9 * (ulonglong)(uVar9 << 1);
  uVar16 = (uint)lVar1;
  uVar26 = (uint)((ulonglong)uVar30 * (ulonglong)uVar27);
  uVar23 = uVar26 + uVar16;
  lVar2 = (ulonglong)uVar24 * (ulonglong)uVar15 + (ulonglong)uVar8 * (ulonglong)uVar19;
  uVar22 = (uint)lVar2;
  local_68 = (uint)uVar5;
  uVar6 = (uVar5 >> 0x19) +
          CONCAT44((int)((ulonglong)lVar2 >> 0x20) * 2 + (uint)CARRY4(uVar22,uVar22) +
                   uVar30 * local_ac + (int)((ulonglong)uVar30 * (ulonglong)uVar27 >> 0x20) +
                   (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar26,uVar16) +
                   (uint)CARRY4(uVar22 * 2,uVar23),uVar22 * 2 + uVar23);
  uVar5 = (ulonglong)uVar10 * (ulonglong)uVar20 +
          (ulonglong)(uVar21 << 1) * (ulonglong)uVar9 +
          (ulonglong)uVar25 * (ulonglong)uVar15 + (ulonglong)uVar8 * (ulonglong)uVar30 +
          CONCAT44(uVar24 * local_ac + (int)((ulonglong)uVar24 * (ulonglong)uVar27 >> 0x20),
                   (int)((ulonglong)uVar24 * (ulonglong)uVar27)) + (uVar6 >> 0x1a);
  local_ac = (uint)CARRY4(uVar13,uVar13);
  local_58 = (uint)uVar5;
  uVar5 = (ulonglong)(uVar19 << 2) * (ulonglong)uVar9 +
          (ulonglong)uVar10 * (ulonglong)uVar18 +
          (ulonglong)uVar21 * (ulonglong)uVar21 +
          (ulonglong)uVar15 * (ulonglong)uVar14 +
          ((ulonglong)
           (uVar8 * CARRY4(uVar24,uVar24) + (int)((ulonglong)uVar8 * (ulonglong)uVar4 >> 0x20)) <<
           0x20 | (ulonglong)uVar8 * (ulonglong)uVar4 & 0xffffffff) +
          CONCAT44(uVar25 * local_ac + (int)((ulonglong)uVar25 * (ulonglong)uVar27 >> 0x20),
                   (int)((ulonglong)uVar25 * (ulonglong)uVar27)) + (uVar5 >> 0x19);
  local_90 = (uint)uVar5;
  lVar1 = (ulonglong)uVar9 * (ulonglong)uVar18 +
          (ulonglong)uVar25 * (ulonglong)uVar8 + (ulonglong)uVar20 * (ulonglong)uVar21 +
          CONCAT44(uVar14 * local_ac + (int)((ulonglong)uVar14 * (ulonglong)uVar27 >> 0x20),
                   (int)((ulonglong)uVar14 * (ulonglong)uVar27)) +
          (ulonglong)uVar4 * (ulonglong)uVar10 + (uVar5 >> 0x1a);
  uVar15 = (uint)lVar1;
  uVar27 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar5 = (ulonglong)uVar9 * (ulonglong)(uVar24 << 2) +
          (ulonglong)uVar10 * (ulonglong)uVar17 +
          (ulonglong)uVar21 * (ulonglong)uVar18 +
          (ulonglong)uVar20 * (ulonglong)uVar19 +
          (ulonglong)uVar12 * (ulonglong)uVar13 +
          ((ulonglong)
           (uVar8 * CARRY4(uVar14,uVar14) + (int)((ulonglong)uVar8 * (ulonglong)uVar3 >> 0x20)) <<
           0x20 | (ulonglong)uVar8 * (ulonglong)uVar3 & 0xffffffff) +
          CONCAT44(uVar27 >> 0x19,uVar15 >> 0x19 | uVar27 * 0x80);
  uVar7 = (ulonglong)uVar9 * (ulonglong)uVar17 +
          (ulonglong)uVar12 * (ulonglong)uVar8 + (ulonglong)uVar19 * (ulonglong)uVar18 +
          (ulonglong)uVar4 * (ulonglong)uVar21;
  local_b0 = (uint)uVar5;
  lVar1 = (ulonglong)uVar3 * (ulonglong)uVar10 + (uVar7 & 0xffffffff);
  lVar1 = (uVar5 >> 0x1a) +
          CONCAT44((int)(uVar7 >> 0x20) + (int)((ulonglong)lVar1 >> 0x20),(int)lVar1);
  uVar13 = (uint)lVar1;
  uVar27 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar5 = (ulonglong)(uVar14 << 2) * (ulonglong)uVar9 +
          (ulonglong)(uVar24 << 2) * (ulonglong)uVar19 +
          (ulonglong)uVar10 * (ulonglong)(uVar12 << 1) +
          (ulonglong)uVar30 * (ulonglong)uVar30 +
          (ulonglong)uVar8 * (ulonglong)uVar11 + (ulonglong)uVar17 * (ulonglong)uVar21 +
          CONCAT44(uVar27 >> 0x19,uVar13 >> 0x19 | uVar27 * 0x80);
  local_a0 = (uint)uVar5;
  uVar5 = (uVar5 >> 0x1a) +
          (ulonglong)(uVar11 << 1) * (ulonglong)uVar10 +
          (ulonglong)uVar17 * (ulonglong)uVar19 + (ulonglong)uVar9 * (ulonglong)(uVar12 << 1) +
          (ulonglong)uVar4 * (ulonglong)uVar30 + (ulonglong)uVar3 * (ulonglong)uVar21;
  uVar7 = uVar5 >> 0x19;
  lVar1 = (uVar7 & 0xffffffff) * 0x13 +
          (CONCAT44((int)(uVar7 >> 0x20) * 0x13,uVar29) & 0xffffffff03ffffff);
  uVar27 = (uint)lVar1;
  *param_1 = uVar27 & 0x3ffffff;
  uVar27 = (uVar27 >> 0x1a | (int)((ulonglong)lVar1 >> 0x20) * 0x40) + (local_68 & 0x1ffffff);
  param_1[7] = uVar13 & 0x1ffffff;
  param_1[2] = ((uint)uVar6 & 0x3ffffff) + (uVar27 >> 0x19);
  param_1[1] = uVar27 & 0x1ffffff;
  param_1[3] = local_58 & 0x1ffffff;
  param_1[4] = local_90 & 0x3ffffff;
  param_1[5] = uVar15 & 0x1ffffff;
  param_1[6] = local_b0 & 0x3ffffff;
  param_1[8] = local_a0 & 0x3ffffff;
  param_1[9] = (uint)uVar5 & 0x1ffffff;
  return;
}



// 600e643a  FUN_600e643a  size=208 bytes
// --- callers ---
//   6008d3d4 FUN_6008d3d4
//   600eb1e4 FUN_600eb1e4
//   6008dc2c FUN_6008dc2c
//   600eb588 FUN_600eb588
//   600e68ac FUN_600e68ac
//   600e693e FUN_600e693e
// --- callees ---


void FUN_600e643a(int *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  byte bVar20;
  byte bVar21;
  byte bVar22;
  byte bVar23;
  byte bVar24;
  byte bVar25;
  byte bVar26;
  byte bVar27;
  byte bVar28;
  
  bVar1 = param_2[0x1e];
  bVar2 = param_2[0x1f];
  bVar3 = param_2[0x1b];
  bVar4 = param_2[0x17];
  bVar5 = param_2[0x1c];
  bVar6 = param_2[0x13];
  bVar7 = param_2[0x1d];
  bVar8 = param_2[0xf];
  bVar9 = param_2[0x1a];
  bVar22 = param_2[7];
  bVar23 = param_2[3];
  bVar10 = param_2[0x18];
  bVar11 = param_2[0x19];
  bVar12 = param_2[0x16];
  bVar13 = param_2[0x14];
  bVar14 = param_2[0x15];
  bVar15 = param_2[0x12];
  bVar16 = param_2[0x10];
  bVar17 = param_2[0x11];
  bVar18 = param_2[0xe];
  bVar19 = param_2[0xc];
  bVar20 = param_2[0xd];
  bVar24 = param_2[6];
  bVar25 = param_2[4];
  bVar26 = param_2[5];
  bVar27 = param_2[2];
  bVar28 = *param_2;
  bVar21 = param_2[1];
  param_1[2] = (uint)param_2[10] * 0x10000 + (uint)param_2[0xb] * 0x1000000 + (uint)param_2[8] +
               (uint)param_2[9] * 0x100;
  param_1[3] = (uint)bVar18 * 0x10000 + (uint)bVar8 * 0x1000000 + (uint)bVar19 +
               (uint)bVar20 * 0x100;
  *param_1 = (uint)bVar27 * 0x10000 + (uint)bVar23 * 0x1000000 + (uint)bVar28 + (uint)bVar21 * 0x100
  ;
  param_1[1] = (uint)bVar24 * 0x10000 + (uint)bVar22 * 0x1000000 + (uint)bVar25 +
               (uint)bVar26 * 0x100;
  param_1[4] = (uint)bVar15 * 0x10000 + (uint)bVar6 * 0x1000000 + (uint)bVar16 +
               (uint)bVar17 * 0x100;
  param_1[5] = (uint)bVar12 * 0x10000 + (uint)bVar4 * 0x1000000 + (uint)bVar13 +
               (uint)bVar14 * 0x100;
  param_1[6] = (uint)bVar9 * 0x10000 + (uint)bVar3 * 0x1000000 + (uint)bVar10 + (uint)bVar11 * 0x100
  ;
  param_1[7] = (uint)bVar1 * 0x10000 + (uint)bVar2 * 0x1000000 + (uint)bVar5 + (uint)bVar7 * 0x100;
  return;
}



// 600e18ce  FUN_600e18ce  size=286 bytes
// --- callers ---
//   60087964 FUN_60087964
// --- callees ---


void FUN_600e18ce(uint *param_1,byte *param_2)

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
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  uVar16 = (uint)param_2[2] * 0x10000 + (uint)param_2[3] * 0x1000000 + (uint)*param_2 +
           (uint)param_2[1] * 0x100;
  bVar5 = param_2[0xe];
  uVar12 = (uint)param_2[0x12] * 0x10000 + (uint)param_2[0x13] * 0x1000000 + (uint)param_2[0x10] +
           (uint)param_2[0x11] * 0x100;
  bVar6 = param_2[0x1c];
  bVar7 = param_2[0x1f];
  uVar15 = (uint)param_2[5] * 0x4000 + (uint)param_2[6] * 0x400000 + (uint)param_2[4] * 0x40 +
           (uVar16 >> 0x1a);
  uVar14 = (uint)param_2[8] * 0x2000 + (uint)param_2[9] * 0x200000 + (uint)param_2[7] * 0x20 +
           (uVar15 >> 0x19);
  bVar1 = param_2[0xf];
  bVar2 = param_2[0xd];
  uVar13 = (uint)param_2[0xb] * 0x800 + (uint)param_2[0xc] * 0x80000 + (uint)param_2[10] * 8 +
           (uVar14 >> 0x1a);
  uVar11 = (uint)param_2[0x15] * 0x8000 + (uint)param_2[0x16] * 0x800000 +
           (uint)param_2[0x14] * 0x80 + (uVar12 >> 0x19);
  bVar3 = param_2[0x1b];
  uVar10 = (uint)param_2[0x18] * 0x2000 + (uint)param_2[0x19] * 0x200000 +
           (uint)param_2[0x17] * 0x20 + (uVar11 >> 0x1a);
  bVar8 = param_2[0x1a];
  bVar9 = param_2[0x1e];
  bVar4 = param_2[0x1d];
  *param_1 = uVar16 & 0x3ffffff;
  uVar16 = (uint)bVar3 * 0x1000 + (uint)bVar6 * 0x100000 + (uint)bVar8 * 0x10 + (uVar10 >> 0x19);
  param_1[1] = uVar15 & 0x1ffffff;
  param_1[2] = uVar14 & 0x3ffffff;
  param_1[5] = uVar12 & 0x1ffffff;
  param_1[6] = uVar11 & 0x3ffffff;
  param_1[7] = uVar10 & 0x1ffffff;
  param_1[3] = uVar13 & 0x1ffffff;
  param_1[4] = (uint)bVar5 * 0x400 + (uint)bVar1 * 0x40000 + (uint)bVar2 * 4 + (uVar13 >> 0x19);
  param_1[8] = uVar16 & 0x3ffffff;
  param_1[9] = (uint)bVar9 * 0x400 + (uint)bVar7 * 0x40000 + (uint)bVar4 * 4 + (uVar16 >> 0x1a);
  return;
}



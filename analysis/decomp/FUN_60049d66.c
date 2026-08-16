// 60049d66  FUN_60049d66  size=742 bytes
// --- callers ---
// --- callees ---


void FUN_60049d66(uint param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  
  fVar8 = param_2[1] + param_2[3];
  fVar17 = param_2[1] - param_2[3];
  fVar7 = *param_2 + param_2[2];
  fVar5 = param_2[4] + param_2[6];
  fVar14 = *param_2 - param_2[2];
  fVar12 = param_2[4] - param_2[6];
  fVar6 = param_2[5] + param_2[7];
  fVar10 = param_2[5] - param_2[7];
  *param_2 = fVar7 + fVar5;
  param_2[4] = fVar7 - fVar5;
  param_2[1] = fVar8 + fVar6;
  param_2[5] = fVar8 - fVar6;
  param_2[2] = fVar14 - fVar10;
  param_2[6] = fVar14 + fVar10;
  param_2[3] = fVar17 + fVar12;
  param_2[7] = fVar17 - fVar12;
  fVar5 = param_2[9] + param_2[0xb];
  fVar14 = param_2[9] - param_2[0xb];
  fVar17 = param_2[8] + param_2[10];
  fVar10 = param_3[2];
  fVar6 = param_2[0xc] + param_2[0xe];
  fVar18 = param_2[8] - param_2[10];
  fVar15 = param_2[0xc] - param_2[0xe];
  fVar8 = param_2[0xd] + param_2[0xf];
  fVar12 = param_2[0xd] - param_2[0xf];
  fVar7 = fVar14 + fVar15;
  param_2[8] = fVar17 + fVar6;
  param_2[0xd] = fVar17 - fVar6;
  fVar6 = fVar18 - fVar12;
  fVar15 = fVar15 - fVar14;
  param_2[9] = fVar5 + fVar8;
  param_2[0xc] = fVar8 - fVar5;
  fVar18 = fVar18 + fVar12;
  param_2[10] = (fVar6 - fVar7) * fVar10;
  param_2[0xb] = (fVar6 + fVar7) * fVar10;
  param_2[0xe] = (fVar15 - fVar18) * fVar10;
  param_2[0xf] = (fVar18 + fVar15) * fVar10;
  pfVar1 = param_3;
  pfVar2 = param_3;
  while( true ) {
    pfVar4 = pfVar1 + 4;
    pfVar3 = param_2 + 0x10;
    if (param_1 <= (uint)((int)pfVar4 - (int)param_3)) break;
    fVar5 = *pfVar4;
    fVar11 = pfVar2[3];
    fVar13 = pfVar1[5];
    fVar14 = param_2[0x11] + param_2[0x13];
    fVar9 = param_2[0x11] - param_2[0x13];
    fVar8 = fVar5 + -(fVar11 + fVar11) * fVar13;
    fVar12 = -fVar13 + (fVar11 + fVar11) * fVar5;
    fVar7 = param_2[0x14] + param_2[0x16];
    fVar19 = pfVar2[2];
    fVar17 = *pfVar3 + param_2[0x12];
    fVar6 = *pfVar3 - param_2[0x12];
    fVar18 = param_2[0x14] - param_2[0x16];
    fVar10 = param_2[0x15] + param_2[0x17];
    fVar15 = param_2[0x15] - param_2[0x17];
    fVar16 = fVar17 - fVar7;
    *pfVar3 = fVar17 + fVar7;
    fVar17 = fVar14 - fVar10;
    param_2[0x11] = fVar14 + fVar10;
    fVar10 = fVar9 + fVar18;
    param_2[0x14] = -(fVar17 * fVar11) + fVar19 * fVar16;
    fVar7 = fVar6 - fVar15;
    param_2[0x15] = fVar11 * fVar16 + fVar19 * fVar17;
    param_2[0x12] = -(fVar10 * fVar13) + fVar5 * fVar7;
    fVar9 = fVar9 - fVar18;
    param_2[0x13] = fVar13 * fVar7 + fVar5 * fVar10;
    fVar6 = fVar6 + fVar15;
    param_2[0x16] = -(fVar9 * fVar12) + fVar8 * fVar6;
    fVar10 = param_2[0x1d] + param_2[0x1f];
    fVar13 = param_2[0x1d] - param_2[0x1f];
    fVar17 = param_2[0x18] + param_2[0x1a];
    param_2[0x17] = fVar12 * fVar6 + fVar8 * fVar9;
    fVar7 = param_2[0x18] - param_2[0x1a];
    fVar5 = pfVar1[6];
    fVar6 = pfVar1[7];
    fVar12 = fVar5 + -(fVar19 + fVar19) * fVar6;
    fVar14 = -fVar6 + (fVar19 + fVar19) * fVar5;
    fVar18 = param_2[0x19] + param_2[0x1b];
    fVar16 = param_2[0x19] - param_2[0x1b];
    fVar8 = param_2[0x1c] + param_2[0x1e];
    fVar9 = param_2[0x1c] - param_2[0x1e];
    fVar15 = fVar17 - fVar8;
    param_2[0x18] = fVar17 + fVar8;
    fVar8 = fVar18 - fVar10;
    param_2[0x19] = fVar18 + fVar10;
    fVar10 = fVar7 - fVar13;
    param_2[0x1c] = -(fVar8 * fVar19) + -fVar11 * fVar15;
    fVar17 = fVar16 + fVar9;
    param_2[0x1d] = fVar19 * fVar15 + -fVar11 * fVar8;
    param_2[0x1b] = fVar6 * fVar10 + fVar5 * fVar17;
    fVar7 = fVar7 + fVar13;
    param_2[0x1a] = -(fVar17 * fVar6) + fVar5 * fVar10;
    fVar16 = fVar16 - fVar9;
    param_2[0x1e] = -(fVar16 * fVar14) + fVar12 * fVar7;
    param_2[0x1f] = fVar14 * fVar7 + fVar12 * fVar16;
    param_2 = pfVar3;
    pfVar1 = pfVar4;
    pfVar2 = pfVar2 + 2;
  }
  return;
}



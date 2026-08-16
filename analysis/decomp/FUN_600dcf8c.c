// 600dcf8c  FUN_600dcf8c  size=984 bytes
// --- callers ---
//   600dd364 FUN_600dd364
// --- callees ---


void FUN_600dcf8c(uint param_1,uint param_2,float *param_3,int param_4)

{
  uint uVar1;
  float *pfVar2;
  float *pfVar3;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  float *pfVar10;
  float *pfVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  
  uVar9 = 0;
  uVar1 = param_2 * 4;
  pfVar2 = param_3 + param_2;
  pfVar3 = pfVar2 + param_2;
  pfVar5 = pfVar2 + param_2 + param_2;
  pfVar6 = param_3;
  while( true ) {
    if (param_2 <= uVar9) break;
    uVar9 = uVar9 + 2;
    fVar16 = pfVar6[1] + pfVar2[1];
    fVar24 = pfVar6[1] - pfVar2[1];
    fVar14 = *pfVar6 + *pfVar2;
    fVar21 = *pfVar6 - *pfVar2;
    fVar12 = *pfVar3 + *pfVar5;
    fVar20 = *pfVar3 - *pfVar5;
    fVar13 = pfVar3[1] + pfVar5[1];
    fVar18 = pfVar3[1] - pfVar5[1];
    *pfVar6 = fVar14 + fVar12;
    pfVar6[1] = fVar16 + fVar13;
    pfVar3[1] = fVar16 - fVar13;
    *pfVar3 = fVar14 - fVar12;
    *pfVar2 = fVar21 - fVar18;
    pfVar2[1] = fVar24 + fVar20;
    *pfVar5 = fVar21 + fVar18;
    pfVar5[1] = fVar24 - fVar20;
    pfVar2 = pfVar2 + 2;
    pfVar3 = pfVar3 + 2;
    pfVar5 = pfVar5 + 2;
    pfVar6 = pfVar6 + 2;
  }
  fVar12 = *(float *)(param_4 + 8);
  uVar9 = uVar1;
  pfVar2 = param_3 + param_2 * 7;
  pfVar3 = param_3 + param_2 * 6;
  pfVar5 = param_3 + param_2 * 4;
  pfVar6 = param_3 + param_2 * 5;
  while( true ) {
    if (param_2 * 5 <= uVar9) break;
    uVar9 = uVar9 + 2;
    fVar13 = pfVar5[1] + pfVar6[1];
    fVar21 = pfVar5[1] - pfVar6[1];
    fVar24 = *pfVar5 + *pfVar6;
    fVar25 = *pfVar5 - *pfVar6;
    fVar14 = *pfVar3 + *pfVar2;
    fVar22 = *pfVar3 - *pfVar2;
    fVar18 = pfVar3[1] + pfVar2[1];
    fVar20 = pfVar3[1] - pfVar2[1];
    fVar16 = fVar21 + fVar22;
    *pfVar5 = fVar24 + fVar14;
    fVar22 = fVar22 - fVar21;
    pfVar5[1] = fVar13 + fVar18;
    pfVar3[1] = fVar24 - fVar14;
    fVar14 = fVar25 - fVar20;
    *pfVar3 = fVar18 - fVar13;
    fVar25 = fVar25 + fVar20;
    *pfVar6 = (fVar14 - fVar16) * fVar12;
    pfVar6[1] = (fVar14 + fVar16) * fVar12;
    *pfVar2 = (fVar22 - fVar25) * fVar12;
    pfVar2[1] = (fVar25 + fVar22) * fVar12;
    pfVar2 = pfVar2 + 2;
    pfVar3 = pfVar3 + 2;
    pfVar5 = pfVar5 + 2;
    pfVar6 = pfVar6 + 2;
  }
  pfVar3 = param_3 + param_2 * 0xc;
  pfVar2 = param_3 + param_2 * 4 + param_2 * 4;
  uVar9 = param_2 * 9;
  iVar7 = param_4;
  for (uVar4 = param_2 * 8; uVar4 < param_1; uVar4 = uVar4 + uVar1 + uVar1) {
    fVar16 = *(float *)(param_4 + 0x10);
    fVar14 = *(float *)(param_4 + 0x14);
    fVar20 = *(float *)(iVar7 + 0xc);
    fVar18 = *(float *)(iVar7 + 8);
    fVar13 = fVar16 + -(fVar20 + fVar20) * fVar14;
    fVar12 = -fVar14 + (fVar20 + fVar20) * fVar16;
    pfVar5 = pfVar2 + param_2 * 2;
    pfVar6 = pfVar2 + param_2 * 2 + param_2;
    uVar8 = uVar4;
    pfVar10 = pfVar3 + param_2 * -3;
    pfVar11 = pfVar2;
    while( true ) {
      if (uVar9 <= uVar8) break;
      uVar8 = uVar8 + 2;
      fVar22 = pfVar11[1] + pfVar10[1];
      fVar19 = pfVar11[1] - pfVar10[1];
      fVar25 = *pfVar11 + *pfVar10;
      fVar26 = *pfVar11 - *pfVar10;
      fVar21 = *pfVar5 + *pfVar6;
      fVar17 = *pfVar5 - *pfVar6;
      fVar24 = pfVar5[1] + pfVar6[1];
      fVar15 = pfVar5[1] - pfVar6[1];
      fVar23 = fVar25 - fVar21;
      *pfVar11 = fVar25 + fVar21;
      fVar25 = fVar22 - fVar24;
      pfVar11[1] = fVar22 + fVar24;
      *pfVar5 = -(fVar25 * fVar20) + fVar18 * fVar23;
      fVar21 = fVar19 + fVar17;
      pfVar5[1] = fVar20 * fVar23 + fVar18 * fVar25;
      fVar24 = fVar26 - fVar15;
      fVar26 = fVar26 + fVar15;
      *pfVar10 = -(fVar21 * fVar14) + fVar16 * fVar24;
      pfVar10[1] = fVar14 * fVar24 + fVar16 * fVar21;
      fVar19 = fVar19 - fVar17;
      *pfVar6 = -(fVar19 * fVar12) + fVar13 * fVar26;
      pfVar6[1] = fVar12 * fVar26 + fVar13 * fVar19;
      pfVar5 = pfVar5 + 2;
      pfVar6 = pfVar6 + 2;
      pfVar10 = pfVar10 + 2;
      pfVar11 = pfVar11 + 2;
    }
    fVar16 = *(float *)(param_4 + 0x18);
    fVar14 = *(float *)(param_4 + 0x1c);
    fVar13 = fVar16 + -(fVar18 + fVar18) * fVar14;
    fVar12 = -fVar14 + (fVar18 + fVar18) * fVar16;
    pfVar5 = pfVar2 + param_2 * 7;
    pfVar6 = pfVar2 + param_2 * 5;
    uVar8 = uVar4 + uVar1;
    pfVar10 = pfVar3 + param_2 * 2;
    pfVar11 = pfVar3;
    while( true ) {
      if (uVar9 + uVar1 <= uVar8) break;
      uVar8 = uVar8 + 2;
      fVar25 = pfVar11[1] + pfVar6[1];
      fVar21 = pfVar11[1] - pfVar6[1];
      fVar15 = *pfVar11 + *pfVar6;
      fVar26 = *pfVar11 - *pfVar6;
      fVar24 = *pfVar10 + *pfVar5;
      fVar19 = *pfVar10 - *pfVar5;
      fVar22 = pfVar10[1] + pfVar5[1];
      fVar17 = pfVar10[1] - pfVar5[1];
      fVar23 = fVar15 - fVar24;
      *pfVar11 = fVar15 + fVar24;
      fVar15 = fVar25 - fVar22;
      pfVar11[1] = fVar25 + fVar22;
      *pfVar10 = -(fVar15 * fVar18) + -fVar20 * fVar23;
      fVar24 = fVar21 + fVar19;
      pfVar10[1] = fVar18 * fVar23 + -fVar20 * fVar15;
      fVar22 = fVar26 - fVar17;
      fVar26 = fVar26 + fVar17;
      *pfVar6 = -(fVar24 * fVar14) + fVar16 * fVar22;
      pfVar6[1] = fVar14 * fVar22 + fVar16 * fVar24;
      fVar21 = fVar21 - fVar19;
      *pfVar5 = -(fVar21 * fVar12) + fVar13 * fVar26;
      pfVar5[1] = fVar12 * fVar26 + fVar13 * fVar21;
      pfVar5 = pfVar5 + 2;
      pfVar6 = pfVar6 + 2;
      pfVar10 = pfVar10 + 2;
      pfVar11 = pfVar11 + 2;
    }
    pfVar3 = pfVar3 + param_2 * 8;
    param_4 = param_4 + 0x10;
    pfVar2 = pfVar2 + param_2 * 8;
    uVar9 = uVar9 + uVar1 + uVar1;
    iVar7 = iVar7 + 8;
  }
  return;
}



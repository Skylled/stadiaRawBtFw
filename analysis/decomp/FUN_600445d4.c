// 600445d4  FUN_600445d4  size=890 bytes
// --- callers ---
//   60049814 FUN_60049814
// --- callees ---


void FUN_600445d4(int *param_1,int param_2,undefined4 param_3,undefined2 *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined2 *puVar11;
  int iVar13;
  int iVar14;
  short *psVar15;
  int *piVar16;
  int local_800;
  int local_7f0 [497];
  undefined2 *puVar12;
  
  iVar13 = 0;
  local_800 = param_1[0xc];
  iVar8 = param_1[3];
  iVar3 = local_800;
  iVar5 = *param_1;
  iVar14 = param_1[2];
  iVar9 = param_1[1];
  do {
    iVar6 = iVar3;
    iVar1 = ((iVar6 - iVar9) + 0x2000 >> 0xe) * 0xbea + iVar5;
    iVar3 = iVar1 - iVar14 >> 0xe;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 1;
    }
    iVar4 = iVar3 * 0x2498 + iVar9;
    iVar3 = iVar4 - iVar8 >> 0xe;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 1;
    }
    iVar8 = iVar3 * 0x3ad7 + iVar14;
    *(int *)((int)local_7f0 + iVar13 * 2 + 0x40) = iVar8 >> 1;
    iVar3 = param_2 + iVar13;
    iVar13 = iVar13 + 4;
    iVar3 = *(short *)(iVar3 + 2) * 0x8000 + 0x4000;
    iVar5 = iVar6;
    iVar14 = iVar4;
    iVar9 = iVar1;
  } while (iVar13 != 0x3c0);
  piVar16 = local_7f0;
  *param_1 = iVar6;
  param_1[1] = iVar1;
  param_1[2] = iVar4;
  param_1[3] = iVar8;
  iVar9 = param_1[7];
  iVar8 = 0;
  iVar3 = param_1[6];
  iVar5 = param_1[4];
  piVar10 = piVar16;
  iVar14 = param_1[5];
  do {
    iVar13 = iVar8 * 4;
    iVar8 = iVar8 + 1;
    iVar1 = *(short *)(param_2 + iVar13) * 0x8000 + 0x4000;
    iVar13 = ((iVar1 - iVar14) + 0x2000 >> 0xe) * 0x335 + iVar5;
    iVar5 = iVar13 - iVar3 >> 0xe;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar6 = iVar5 * 0x17de + iVar14;
    iVar5 = iVar6 - iVar9 >> 0xe;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar9 = iVar5 * 0x305e + iVar3;
    piVar10[0x10] = piVar10[0x10] + (iVar9 >> 1) >> 0xf;
    iVar3 = iVar6;
    iVar5 = iVar1;
    piVar10 = piVar10 + 2;
    iVar14 = iVar13;
  } while (iVar8 != 0xf0);
  param_1[4] = iVar1;
  param_1[5] = iVar13;
  param_1[6] = iVar6;
  param_1[7] = iVar9;
  iVar8 = param_1[0xb];
  iVar3 = 0;
  iVar5 = param_1[8];
  iVar14 = param_1[10];
  iVar9 = param_1[9];
  do {
    iVar1 = *(short *)(param_2 + iVar3 * 4) * 0x8000 + 0x4000;
    iVar13 = ((iVar1 - iVar9) + 0x2000 >> 0xe) * 0xbea + iVar5;
    iVar5 = iVar13 - iVar14 >> 0xe;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar6 = iVar5 * 0x2498 + iVar9;
    iVar5 = iVar6 - iVar8 >> 0xe;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar8 = iVar5 * 0x3ad7 + iVar14;
    iVar4 = iVar3 + 1;
    local_7f0[iVar3 * 2 + 0x11] = iVar8 >> 1;
    iVar3 = iVar4;
    iVar5 = iVar1;
    iVar14 = iVar6;
    iVar9 = iVar13;
  } while (iVar4 != 0xf0);
  param_1[8] = iVar1;
  param_1[9] = iVar13;
  param_1[10] = iVar6;
  param_1[0xb] = iVar8;
  iVar9 = param_1[0xf];
  iVar3 = param_1[0xe];
  iVar5 = param_1[0xd];
  iVar14 = 0;
  do {
    psVar15 = (short *)(param_2 + 2);
    param_2 = param_2 + 4;
    iVar1 = *psVar15 * 0x8000 + 0x4000;
    iVar8 = ((iVar1 - iVar5) + 0x2000 >> 0xe) * 0x335 + local_800;
    iVar13 = iVar8 - iVar3 >> 0xe;
    if (iVar13 < 0) {
      iVar13 = iVar13 + 1;
    }
    iVar13 = iVar13 * 0x17de + iVar5;
    iVar6 = iVar14 + 8;
    iVar5 = iVar13 - iVar9 >> 0xe;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar9 = iVar5 * 0x305e + iVar3;
    *(int *)((int)local_7f0 + iVar14 + 0x44) =
         *(int *)((int)local_7f0 + iVar14 + 0x44) + (iVar9 >> 1) >> 0xf;
    iVar3 = iVar13;
    iVar5 = iVar8;
    iVar14 = iVar6;
    local_800 = iVar1;
  } while (iVar6 != 0x780);
  param_1[0xe] = iVar13;
  param_1[0xf] = iVar9;
  param_1[0xc] = iVar1;
  param_1[0xd] = iVar8;
  piVar10 = local_7f0 + 8;
  piVar2 = param_1 + 0x10;
  do {
    piVar7 = piVar2 + 2;
    iVar3 = piVar2[1];
    *piVar10 = *piVar2;
    piVar10[1] = iVar3;
    piVar10 = piVar10 + 2;
    piVar2 = piVar7;
  } while (piVar7 != param_1 + 0x18);
  piVar2 = local_7f0 + 0x1e8;
  piVar10 = param_1 + 0x10;
  do {
    iVar3 = *piVar2;
    iVar5 = piVar2[1];
    piVar2 = piVar2 + 2;
    *piVar10 = iVar3;
    piVar10[1] = iVar5;
    piVar10 = piVar10 + 2;
  } while (piVar2 != local_7f0 + 0x1f0);
  piVar10 = local_7f0 + 8;
  iVar3 = 0;
  do {
    iVar14 = 0x4000;
    iVar5 = 0;
    do {
      iVar9 = iVar5 * 2;
      piVar2 = piVar10 + iVar5;
      iVar5 = iVar5 + 1;
      iVar14 = *piVar2 * (int)*(short *)(DAT_60044950 + iVar9) + iVar14;
    } while (iVar5 != 8);
    *(int *)((int)local_7f0 + iVar3) = iVar14;
    iVar5 = 0x4000;
    piVar2 = piVar10;
    psVar15 = DAT_60044954;
    do {
      piVar2 = piVar2 + 1;
      psVar15 = psVar15 + 1;
      iVar5 = *piVar2 * (int)*psVar15 + iVar5;
    } while (piVar10 + 8 != piVar2);
    iVar14 = iVar3 + 8;
    piVar10 = piVar10 + 3;
    *(int *)((int)local_7f0 + iVar3 + 4) = iVar5;
    iVar3 = iVar14;
  } while (iVar14 != 0x500);
  iVar9 = 0;
  iVar8 = param_1[0x1b];
  iVar3 = param_1[0x1a];
  iVar5 = param_1[0x19];
  iVar14 = param_1[0x18];
  do {
    iVar1 = local_7f0[iVar9 * 2];
    iVar13 = ((iVar1 - iVar5) + 0x2000 >> 0xe) * 0xbea + iVar14;
    iVar14 = iVar13 - iVar3 >> 0xe;
    if (iVar14 < 0) {
      iVar14 = iVar14 + 1;
    }
    iVar6 = iVar14 * 0x2498 + iVar5;
    iVar5 = iVar6 - iVar8 >> 0xe;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 1;
    }
    iVar8 = iVar5 * 0x3ad7 + iVar3;
    local_7f0[iVar9 * 2] = iVar8 >> 1;
    iVar9 = iVar9 + 1;
    iVar3 = iVar6;
    iVar5 = iVar13;
    iVar14 = iVar1;
  } while (iVar9 != 0xa0);
  param_1[0x1a] = iVar6;
  param_1[0x1b] = iVar8;
  iVar8 = param_1[0x1f];
  param_1[0x18] = iVar1;
  param_1[0x19] = iVar13;
  iVar3 = 0;
  iVar5 = param_1[0x1e];
  iVar14 = param_1[0x1d];
  iVar9 = param_1[0x1c];
  do {
    iVar13 = iVar3 + 8;
    iVar6 = *(int *)((int)local_7f0 + iVar3 + 4);
    iVar1 = ((iVar6 - iVar14) + 0x2000 >> 0xe) * 0x335 + iVar9;
    iVar9 = iVar1 - iVar5 >> 0xe;
    if (iVar9 < 0) {
      iVar9 = iVar9 + 1;
    }
    iVar4 = iVar9 * 0x17de + iVar14;
    iVar14 = iVar4 - iVar8 >> 0xe;
    if (iVar14 < 0) {
      iVar14 = iVar14 + 1;
    }
    iVar8 = iVar14 * 0x305e + iVar5;
    *(int *)((int)local_7f0 + iVar3 + 4) = iVar8 >> 1;
    iVar3 = iVar13;
    iVar5 = iVar4;
    iVar14 = iVar1;
    iVar9 = iVar6;
  } while (iVar13 != 0x500);
  param_1[0x1e] = iVar4;
  param_1[0x1f] = iVar8;
  param_1[0x1c] = iVar6;
  param_1[0x1d] = iVar1;
  iVar3 = DAT_60044958;
  puVar11 = param_4;
  do {
    puVar12 = puVar11 + 2;
    iVar5 = *piVar16;
    piVar10 = piVar16 + 1;
    iVar14 = piVar16[2] + piVar16[3] >> 0xf;
    piVar16 = piVar16 + 4;
    iVar5 = iVar5 + *piVar10 >> 0xf;
    if (iVar5 < iVar3) {
      iVar5 = iVar3;
    }
    if (0x7ffe < iVar5) {
      iVar5 = 0x7fff;
    }
    if (iVar14 < iVar3) {
      iVar14 = iVar3;
    }
    *puVar11 = (short)iVar5;
    if (0x7ffe < iVar14) {
      iVar14 = 0x7fff;
    }
    puVar11[1] = (short)iVar14;
    puVar11 = puVar12;
  } while (param_4 + 0xa0 != puVar12);
  return;
}



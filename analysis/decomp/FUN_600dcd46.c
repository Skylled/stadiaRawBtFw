// 600dcd46  FUN_600dcd46  size=582 bytes
// --- callers ---
//   6007d5fc FUN_6007d5fc
// --- callees ---


void FUN_600dcd46(uint param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  int *piVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  
  iVar5 = 1;
  *param_2 = 0;
  while( true ) {
    if (param_1 <= (uint)(iVar5 * 8)) break;
    param_1 = param_1 >> 1;
    piVar2 = param_2 + iVar5;
    do {
      piVar10 = piVar2 + 1;
      *piVar2 = piVar2[-iVar5] + param_1;
      piVar2 = piVar10;
    } while (param_2 + iVar5 * 2 != piVar10);
    iVar5 = iVar5 << 1;
  }
  iVar6 = iVar5 * 2;
  if (iVar5 * 8 - param_1 == 0) {
    iVar7 = 0;
    piVar2 = param_2;
    do {
      iVar3 = *piVar2;
      iVar12 = iVar7 * 2;
      for (iVar11 = 0; iVar11 != iVar7; iVar11 = iVar11 + 1) {
        iVar1 = iVar3 + iVar11 * 2;
        iVar4 = param_2[iVar11] + iVar12;
        iVar18 = iVar1 * 4;
        iVar1 = iVar1 + iVar6;
        iVar8 = iVar4 * 4;
        puVar13 = (undefined4 *)(param_3 + iVar18);
        puVar15 = (undefined4 *)(param_3 + iVar8);
        puVar14 = (undefined4 *)(iVar18 + 4 + param_3);
        uVar19 = *puVar13;
        puVar9 = (undefined4 *)(iVar8 + 4 + param_3);
        uVar20 = *puVar14;
        uVar16 = *puVar9;
        *puVar13 = *puVar15;
        *puVar14 = uVar16;
        iVar8 = iVar1 * 4;
        *puVar15 = uVar19;
        iVar1 = iVar1 + iVar6;
        *puVar9 = uVar20;
        puVar13 = (undefined4 *)(param_3 + iVar8);
        uVar19 = *puVar13;
        iVar4 = iVar4 + iVar5 * 4;
        puVar14 = (undefined4 *)(iVar8 + 4 + param_3);
        iVar8 = iVar4 * 4;
        uVar20 = *puVar14;
        iVar4 = iVar4 + iVar5 * -2;
        puVar15 = (undefined4 *)(param_3 + iVar8);
        puVar9 = (undefined4 *)(iVar8 + 4 + param_3);
        uVar16 = *puVar9;
        *puVar13 = *puVar15;
        *puVar14 = uVar16;
        iVar18 = iVar1 * 4;
        *puVar15 = uVar19;
        *puVar9 = uVar20;
        iVar8 = iVar4 * 4;
        puVar13 = (undefined4 *)(param_3 + iVar18);
        puVar15 = (undefined4 *)(param_3 + iVar8);
        puVar14 = (undefined4 *)(iVar18 + 4 + param_3);
        uVar19 = *puVar13;
        puVar9 = (undefined4 *)(iVar8 + 4 + param_3);
        uVar20 = *puVar14;
        iVar1 = (iVar1 + iVar6) * 4;
        uVar16 = *puVar9;
        *puVar13 = *puVar15;
        *puVar14 = uVar16;
        *puVar15 = uVar19;
        *puVar9 = uVar20;
        puVar13 = (undefined4 *)(param_3 + iVar1);
        uVar19 = *puVar13;
        puVar9 = (undefined4 *)(iVar1 + 4 + param_3);
        uVar16 = *puVar9;
        iVar1 = (iVar4 + iVar5 * 4) * 4;
        puVar14 = (undefined4 *)(param_3 + iVar1);
        puVar15 = (undefined4 *)(iVar1 + 4 + param_3);
        uVar20 = *puVar15;
        *puVar13 = *puVar14;
        *puVar9 = uVar20;
        *puVar14 = uVar19;
        *puVar15 = uVar16;
      }
      iVar7 = iVar7 + 1;
      piVar2 = piVar2 + 1;
      iVar3 = iVar6 + iVar12 + iVar3;
      iVar12 = iVar3 * 4;
      iVar3 = (iVar3 + iVar6) * 4;
      puVar13 = (undefined4 *)(param_3 + iVar12);
      puVar14 = (undefined4 *)(param_3 + iVar3);
      puVar9 = (undefined4 *)(iVar12 + 4 + param_3);
      uVar16 = *puVar13;
      puVar15 = (undefined4 *)(iVar3 + 4 + param_3);
      uVar20 = *puVar9;
      uVar19 = *puVar15;
      *puVar13 = *puVar14;
      *puVar9 = uVar19;
      *puVar14 = uVar16;
      *puVar15 = uVar20;
    } while (iVar5 != iVar7);
  }
  else {
    piVar2 = param_2;
    for (iVar7 = 1; iVar7 != iVar5; iVar7 = iVar7 + 1) {
      piVar17 = piVar2 + 1;
      puVar9 = (undefined4 *)(param_3 + (piVar2[1] + iVar6) * 4);
      puVar15 = (undefined4 *)(param_3 + piVar2[1] * 4);
      piVar10 = param_2;
      do {
        piVar2 = piVar10 + 1;
        uVar20 = *puVar15;
        iVar3 = *piVar10 + iVar7 * 2;
        uVar16 = puVar15[1];
        iVar12 = iVar3 * 4;
        puVar14 = (undefined4 *)(param_3 + iVar12);
        iVar3 = (iVar3 + iVar6) * 4;
        puVar13 = (undefined4 *)(iVar12 + 4 + param_3);
        uVar19 = *puVar13;
        *puVar15 = *puVar14;
        puVar15[1] = uVar19;
        *puVar14 = uVar20;
        *puVar13 = uVar16;
        puVar14 = (undefined4 *)(param_3 + iVar3);
        uVar19 = *puVar9;
        uVar16 = puVar9[1];
        puVar13 = (undefined4 *)(iVar3 + 4 + param_3);
        uVar20 = *puVar13;
        *puVar9 = *puVar14;
        puVar9[1] = uVar20;
        *puVar14 = uVar19;
        *puVar13 = uVar16;
        puVar9 = puVar9 + 2;
        puVar15 = puVar15 + 2;
        piVar10 = piVar2;
      } while (piVar17 != piVar2);
    }
  }
  return;
}



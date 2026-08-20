// 600e5664  FUN_600e5664  size=394 bytes
// --- callers ---
//   6008dc2c FUN_6008dc2c
//   600eb588 FUN_600eb588
// --- callees ---


void FUN_600e5664(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
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
  
  iVar4 = *param_2;
  uVar12 = -(uint)(iVar4 != 0);
  uVar11 = uVar12 - param_2[1];
  uVar2 = -(-(uint)(uVar12 < (uint)param_2[1]) - (uint)(iVar4 != 0)) & 0xff;
  uVar12 = -uVar2;
  uVar16 = uVar12 - param_2[2];
  uVar2 = -(-(uint)(uVar12 < (uint)param_2[2]) - (uint)(uVar2 != 0)) & 0xff;
  uVar12 = -uVar2;
  uVar7 = uVar12 - param_2[3];
  uVar2 = -(-(uint)(uVar12 < (uint)param_2[3]) - (uint)(uVar2 != 0)) & 0xff;
  uVar12 = -uVar2;
  uVar8 = uVar12 - param_2[4];
  uVar2 = -(-(uint)(uVar12 < (uint)param_2[4]) - (uint)(uVar2 != 0)) & 0xff;
  uVar12 = -uVar2;
  uVar9 = uVar12 - param_2[5];
  uVar2 = -(-(uint)(uVar12 < (uint)param_2[5]) - (uint)(uVar2 != 0)) & 0xff;
  uVar12 = -uVar2;
  uVar10 = uVar12 - param_2[6];
  uVar5 = param_2[7];
  uVar12 = -(-(uint)(uVar12 < (uint)param_2[6]) - (uint)(uVar2 != 0)) & 0xff;
  uVar1 = -uVar12;
  uVar3 = -(uint)(uVar1 < uVar5) - (uint)(uVar12 != 0);
  uVar12 = (uint)CARRY4(uVar3,-iVar4);
  uVar14 = uVar3 + uVar11;
  uVar6 = (uint)CARRY4(uVar3,uVar11) + (uint)CARRY4(uVar14,uVar12);
  uVar15 = uVar3 + uVar16;
  uVar18 = (uint)CARRY4(uVar3,uVar16) + (uint)CARRY4(uVar15,uVar6);
  uVar2 = (uint)CARRY4(uVar18,uVar7);
  uVar11 = (uint)CARRY4(uVar2,uVar8);
  uVar13 = (uint)(char)((byte)uVar3 & 1);
  uVar16 = (uint)CARRY4(uVar11,uVar9);
  uVar17 = uVar13 + uVar10;
  *param_1 = uVar3 + -iVar4;
  param_1[1] = uVar14 + uVar12;
  param_1[2] = uVar15 + uVar6;
  param_1[3] = uVar18 + uVar7;
  param_1[4] = uVar2 + uVar8;
  param_1[5] = uVar11 + uVar9;
  param_1[6] = uVar16 + uVar17;
  param_1[7] = uVar3 + (uVar1 - uVar5) + (uint)CARRY4(uVar13,uVar10) + (uint)CARRY4(uVar16,uVar17);
  return;
}



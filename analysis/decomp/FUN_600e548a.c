// 600e548a  FUN_600e548a  size=474 bytes
// --- callers ---
//   600e65d2 FUN_600e65d2
//   600e66be FUN_600e66be
// --- callees ---


void FUN_600e548a(int *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
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
  
  uVar18 = *param_2 - *param_3;
  uVar1 = (uint)(*param_2 < *param_3);
  uVar7 = param_2[1] - uVar1;
  uVar13 = uVar7 - param_3[1];
  uVar7 = -(-(uint)(uVar7 < param_3[1]) - (uint)(param_2[1] < uVar1)) & 0xff;
  uVar1 = param_2[2] - uVar7;
  uVar14 = uVar1 - param_3[2];
  uVar7 = -(-(uint)(uVar1 < param_3[2]) - (uint)(param_2[2] < uVar7)) & 0xff;
  uVar1 = param_2[3] - uVar7;
  uVar16 = uVar1 - param_3[3];
  uVar1 = -(-(uint)(uVar1 < param_3[3]) - (uint)(param_2[3] < uVar7)) & 0xff;
  uVar7 = param_2[4] - uVar1;
  uVar8 = uVar7 - param_3[4];
  uVar1 = -(-(uint)(uVar7 < param_3[4]) - (uint)(param_2[4] < uVar1)) & 0xff;
  uVar7 = param_2[5] - uVar1;
  uVar9 = uVar7 - param_3[5];
  uVar1 = -(-(uint)(uVar7 < param_3[5]) - (uint)(param_2[5] < uVar1)) & 0xff;
  uVar7 = param_2[6] - uVar1;
  uVar10 = uVar7 - param_3[6];
  uVar5 = param_3[7];
  uVar1 = -(-(uint)(uVar7 < param_3[6]) - (uint)(param_2[6] < uVar1)) & 0xff;
  uVar2 = param_2[7] - uVar1;
  uVar4 = -(uint)(uVar2 < uVar5) - (uint)(param_2[7] < uVar1);
  uVar1 = (uint)CARRY4(uVar4,uVar18);
  uVar15 = uVar4 + uVar13;
  uVar11 = (uint)CARRY4(uVar4,uVar13) + (uint)CARRY4(uVar1,uVar15);
  uVar12 = uVar4 + uVar14;
  uVar6 = (uint)CARRY4(uVar4,uVar14) + (uint)CARRY4(uVar12,uVar11);
  uVar7 = (uint)CARRY4(uVar6,uVar16);
  uVar3 = (uint)(char)((byte)uVar4 & 1);
  uVar13 = (uint)CARRY4(uVar7,uVar8);
  uVar14 = (uint)CARRY4(uVar13,uVar9);
  uVar17 = uVar3 + uVar10;
  *param_1 = uVar18 + uVar4;
  param_1[1] = uVar1 + uVar15;
  param_1[2] = uVar12 + uVar11;
  param_1[3] = uVar6 + uVar16;
  param_1[4] = uVar7 + uVar8;
  param_1[5] = uVar13 + uVar9;
  param_1[6] = uVar14 + uVar17;
  param_1[7] = uVar4 + (uVar2 - uVar5) + (uint)CARRY4(uVar3,uVar10) + (uint)CARRY4(uVar14,uVar17);
  return;
}



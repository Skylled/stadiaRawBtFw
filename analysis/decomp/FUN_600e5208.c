// 600e5208  FUN_600e5208  size=642 bytes
// --- callers ---
//   600e65d2 FUN_600e65d2
//   600e66be FUN_600e66be
// --- callees ---
//   600e2308 FUN_600e2308


void FUN_600e5208(undefined4 *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
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
  bool bVar19;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [2];
  
  uVar16 = param_2[1] + param_3[1];
  uVar18 = *param_3 + *param_2;
  uVar10 = (uint)CARRY4(*param_2,*param_3);
  uVar1 = uVar10 + uVar16;
  uVar10 = (uint)CARRY4(param_2[1],param_3[1]) + (uint)CARRY4(uVar10,uVar16);
  uVar16 = param_2[2] + param_3[2];
  uVar2 = uVar16 + uVar10;
  uVar10 = (uint)CARRY4(param_2[2],param_3[2]) + (uint)CARRY4(uVar16,uVar10);
  uVar16 = param_2[3] + param_3[3];
  uVar3 = uVar16 + uVar10;
  uVar10 = (uint)CARRY4(param_2[3],param_3[3]) + (uint)CARRY4(uVar16,uVar10);
  uVar16 = param_2[4] + param_3[4];
  uVar4 = uVar16 + uVar10;
  uVar10 = (uint)CARRY4(param_2[4],param_3[4]) + (uint)CARRY4(uVar16,uVar10);
  uVar16 = param_2[5] + param_3[5];
  uVar5 = uVar16 + uVar10;
  uVar10 = (uint)CARRY4(param_2[5],param_3[5]) + (uint)CARRY4(uVar16,uVar10);
  uVar16 = param_2[6] + param_3[6];
  uVar6 = uVar16 + uVar10;
  uVar11 = (uint)CARRY4(param_2[6],param_3[6]) + (uint)CARRY4(uVar16,uVar10);
  uVar12 = param_2[7] + param_3[7];
  uVar7 = uVar12 + uVar11;
  uVar10 = -((0xfffffffe < uVar18) - 1) & 0xff;
  uVar13 = uVar1 - uVar10;
  uVar10 = -((-1 - (uint)(uVar1 < uVar10)) + (uint)(0xfffffffe < uVar13)) & 0xff;
  uVar14 = uVar2 - uVar10;
  uVar17 = -((-1 - (uint)(uVar2 < uVar10)) + (uint)(0xfffffffe < uVar14)) & 0xff;
  uVar10 = (uint)(uVar3 < uVar17);
  uVar16 = (uint)(uVar4 < uVar10);
  uVar9 = (uint)(uVar5 < uVar16);
  iVar8 = uVar6 - uVar9;
  uVar15 = -((-1 - (uint)(uVar6 < uVar9)) + (uint)(iVar8 != 0)) & 0xff;
  uVar9 = uVar7 - uVar15;
  bVar19 = (byte)(CARRY4(param_2[7],param_3[7]) + CARRY4(uVar12,uVar11)) <
           (byte)-((-1 - (uVar7 < uVar15)) + (0xfffffffe < uVar9));
  FUN_600e2308(&local_48,bVar19,uVar18 + 1);
  FUN_600e2308(&local_44,bVar19,uVar13 + 1,uVar1);
  FUN_600e2308(&local_40,bVar19,uVar14 + 1,uVar2);
  FUN_600e2308(&local_3c,bVar19,uVar3 - uVar17,uVar3);
  FUN_600e2308(&local_38,bVar19,uVar4 - uVar10,uVar4);
  FUN_600e2308(&local_34,bVar19,uVar5 - uVar16,uVar5);
  FUN_600e2308(&local_30,bVar19,iVar8 + -1,uVar6);
  FUN_600e2308(local_2c,bVar19,uVar9 + 1,uVar7);
  *param_1 = local_48;
  param_1[1] = local_44;
  param_1[2] = local_40;
  param_1[3] = local_3c;
  param_1[4] = local_38;
  param_1[5] = local_34;
  param_1[6] = local_30;
  param_1[7] = local_2c[0];
  return;
}



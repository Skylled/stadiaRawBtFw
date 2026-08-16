// 600c8fd8  FUN_600c8fd8  size=2764 bytes
// --- callers ---
//   601005ac FUN_601005ac
// --- callees ---
//   60100424 FUN_60100424
//   601004b2 FUN_601004b2
//   601002bc FUN_601002bc


void FUN_600c8fd8(uint *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
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
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  bool bVar27;
  bool bVar28;
  uint local_c;
  
  uVar4 = DAT_600c9238;
  uVar9 = param_2[0xf] + param_2[0xe] + param_2[0xd];
  bVar1 = (param_2[0xe] + param_2[0xd] < param_2[0xe]) + (uVar9 < param_2[0xf]);
  uVar10 = param_2[9] + param_2[8];
  bVar27 = uVar10 < param_2[9];
  uVar11 = param_2[10] + param_2[9];
  uVar12 = param_2[10];
  uVar13 = param_2[0xb] + param_2[10];
  uVar14 = param_2[0xb];
  uVar15 = param_2[0xc] + uVar9;
  bVar2 = bVar1 + (uVar15 < param_2[0xc]);
  uVar16 = param_2[0xb] + uVar15;
  bVar3 = (bVar2 + (uVar16 < param_2[0xb])) - (uVar16 < param_2[0xf]);
  uVar16 = uVar16 - param_2[0xf];
  uVar17 = param_2[10] + uVar16;
  uVar18 = param_2[10];
  uVar19 = param_2[0xe];
  uVar20 = param_2[0xe];
  *param_1 = *param_2;
  *param_1 = *param_1 + uVar10;
  iVar21 = (((uint)bVar27 + (uint)(*param_1 < uVar10)) - (uint)(*param_1 < uVar16)) - (uint)bVar3;
  *param_1 = *param_1 - uVar16;
  if (iVar21 < 0) {
    bVar28 = param_2[1] < (uint)-iVar21;
    param_1[1] = param_2[1] + iVar21;
  }
  else {
    param_1[1] = iVar21 + param_2[1];
    bVar28 = param_1[1] < param_2[1];
  }
  local_c = (uint)bVar28;
  param_1[1] = uVar11 + param_1[1];
  iVar21 = (((uint)(uVar11 < uVar12) + local_c + (param_1[1] < uVar11)) -
           (uint)(param_1[1] < uVar15)) - (uint)bVar2;
  param_1[1] = param_1[1] - uVar15;
  if (iVar21 < 0) {
    bVar28 = param_2[2] < (uint)-iVar21;
    param_1[2] = param_2[2] + iVar21;
  }
  else {
    param_1[2] = iVar21 + param_2[2];
    bVar28 = param_1[2] < param_2[2];
  }
  local_c = (uint)bVar28;
  param_1[2] = uVar13 + param_1[2];
  iVar21 = (((uint)(uVar13 < uVar14) + local_c + (param_1[2] < uVar13)) - (uint)(param_1[2] < uVar9)
           ) - (uint)bVar1;
  param_1[2] = param_1[2] - uVar9;
  if (iVar21 < 0) {
    bVar28 = param_2[3] < (uint)-iVar21;
    param_1[3] = param_2[3] + iVar21;
  }
  else {
    param_1[3] = iVar21 + param_2[3];
    bVar28 = param_1[3] < param_2[3];
  }
  local_c = (uint)bVar28;
  param_1[3] = uVar16 + param_1[3];
  uVar22 = param_1[3];
  param_1[3] = param_2[0xb] + param_1[3];
  uVar5 = param_1[3];
  uVar23 = param_2[0xb];
  param_1[3] = param_2[0xc] + param_1[3];
  uVar6 = param_1[3];
  uVar24 = param_2[0xc];
  uVar7 = param_1[3];
  uVar25 = param_2[0xe];
  param_1[3] = param_1[3] - param_2[0xe];
  uVar8 = param_1[3];
  uVar26 = param_2[0xf];
  param_1[3] = param_1[3] - param_2[0xf];
  iVar21 = (((((uint)bVar3 + local_c + (uVar22 < uVar16) + (uint)(uVar5 < uVar23) +
              (uint)(uVar6 < uVar24)) - (uint)(uVar7 < uVar25)) - (uint)(uVar8 < uVar26)) -
           (uint)(param_1[3] < uVar10)) - (uint)bVar27;
  param_1[3] = param_1[3] - uVar10;
  if (iVar21 < 0) {
    bVar28 = param_2[4] < (uint)-iVar21;
    param_1[4] = param_2[4] + iVar21;
  }
  else {
    param_1[4] = iVar21 + param_2[4];
    bVar28 = param_1[4] < param_2[4];
  }
  local_c = (uint)bVar28;
  param_1[4] = uVar15 + param_1[4];
  uVar6 = param_1[4];
  uVar16 = param_1[4];
  uVar7 = param_2[0xf];
  param_1[4] = param_1[4] - param_2[0xf];
  param_1[4] = param_2[0xc] + param_1[4];
  uVar5 = param_1[4];
  uVar8 = param_2[0xc];
  param_1[4] = param_2[0xd] + param_1[4];
  iVar21 = (((((uint)bVar2 + local_c + (uVar6 < uVar15)) - (uint)(uVar16 < uVar7)) +
             (uint)(uVar5 < uVar8) + (uint)(param_1[4] < param_2[0xd])) -
           (uint)(param_1[4] < uVar11)) - (uint)(uVar11 < uVar12);
  param_1[4] = param_1[4] - uVar11;
  if (iVar21 < 0) {
    bVar28 = param_2[5] < (uint)-iVar21;
    param_1[5] = param_2[5] + iVar21;
  }
  else {
    param_1[5] = iVar21 + param_2[5];
    bVar28 = param_1[5] < param_2[5];
  }
  local_c = (uint)bVar28;
  param_1[5] = uVar9 + param_1[5];
  uVar12 = param_1[5];
  param_1[5] = param_2[0xd] + param_1[5];
  uVar11 = param_1[5];
  uVar15 = param_2[0xd];
  param_1[5] = param_2[0xe] + param_1[5];
  iVar21 = (((uint)bVar1 + local_c + (uVar12 < uVar9) + (uint)(uVar11 < uVar15) +
            (uint)(param_1[5] < param_2[0xe])) - (uint)(param_1[5] < uVar13)) -
           (uint)(uVar13 < uVar14);
  param_1[5] = param_1[5] - uVar13;
  if (iVar21 < 0) {
    bVar28 = param_2[6] < (uint)-iVar21;
    param_1[6] = param_2[6] + iVar21;
  }
  else {
    param_1[6] = iVar21 + param_2[6];
    bVar28 = param_1[6] < param_2[6];
  }
  local_c = (uint)bVar28;
  param_1[6] = uVar9 + param_1[6];
  uVar13 = param_1[6];
  param_1[6] = param_2[0xe] + param_1[6];
  uVar11 = param_1[6];
  uVar14 = param_2[0xe];
  param_1[6] = param_2[0xe] + param_1[6];
  uVar12 = param_1[6];
  uVar15 = param_2[0xe];
  param_1[6] = param_2[0xf] + param_1[6];
  iVar21 = (((uint)bVar1 + local_c + (uVar13 < uVar9) + (uint)(uVar11 < uVar14) +
             (uint)(uVar12 < uVar15) + (uint)(param_1[6] < param_2[0xf])) -
           (uint)(param_1[6] < uVar10)) - (uint)bVar27;
  param_1[6] = param_1[6] - uVar10;
  if (iVar21 < 0) {
    bVar27 = param_2[7] < (uint)-iVar21;
    param_1[7] = param_2[7] + iVar21;
  }
  else {
    param_1[7] = iVar21 + param_2[7];
    bVar27 = param_1[7] < param_2[7];
  }
  local_c = (uint)bVar27;
  param_1[7] = param_2[0xf] + param_1[7];
  uVar9 = param_1[7];
  uVar12 = param_2[0xf];
  param_1[7] = param_2[0xf] + param_1[7];
  uVar10 = param_1[7];
  uVar13 = param_2[0xf];
  param_1[7] = param_2[0xf] + param_1[7];
  uVar11 = param_1[7];
  uVar14 = param_2[0xf];
  param_1[7] = param_2[8] + param_1[7];
  local_c = ((local_c + (uVar9 < uVar12) + (uint)(uVar10 < uVar13) + (uint)(uVar11 < uVar14) +
             (uint)(param_1[7] < param_2[8])) - (uint)(param_1[7] < uVar17 - uVar20)) -
            (uint)(byte)((bVar3 + (uVar17 < uVar18)) - (uVar17 < uVar19));
  param_1[7] = param_1[7] - (uVar17 - uVar20);
  if ((int)local_c < 0) {
    for (; local_c != 0; local_c = local_c + 1) {
      FUN_60100424(param_1,param_1,uVar4,8);
    }
  }
  else if (local_c != 0) {
    for (; local_c != 0; local_c = local_c + -1) {
      FUN_601004b2(param_1,param_1,uVar4,8);
    }
  }
  iVar21 = FUN_601002bc(param_1,uVar4,8);
  if (-1 < iVar21) {
    FUN_601004b2(param_1,param_1,uVar4,8);
  }
  return;
}



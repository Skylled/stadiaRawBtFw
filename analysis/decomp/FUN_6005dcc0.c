// 6005dcc0  FUN_6005dcc0  size=488 bytes
// --- callers ---
// --- callees ---
//   60050c18 FUN_60050c18
//   6005dbec FUN_6005dbec
//   600653f0 FUN_600653f0
//   600cb598 key_value_store__600cb598
//   601019da FUN_601019da
//   60101a64 FUN_60101a64
//   600cc8f8 FUN_600cc8f8
//   6010138c FUN_6010138c
//   60101a80 FUN_60101a80
//   600d4566 FUN_600d4566
//   600cc3cc FUN_600cc3cc
//   600cc984 FUN_600cc984
//   600cc450 FUN_600cc450
//   600d3534 FUN_600d3534
//   601010c8 FUN_601010c8


char FUN_6005dcc0(int param_1)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined1 local_13c;
  undefined1 local_13b;
  short local_13a;
  undefined4 local_138;
  int local_134;
  undefined2 *local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined1 local_124;
  undefined1 local_123;
  undefined2 local_122;
  undefined1 local_120;
  
  DataMemoryBarrier(0x1b);
  uVar8 = *DAT_6005dea8 & 1;
  if (((*DAT_6005dea8 & 1) == 0) && (iVar3 = FUN_600cc8f8(), iVar3 != 0)) {
    piVar4 = (int *)FUN_600653f0();
    pbVar1 = DAT_6005dea8;
    for (; piVar4[1] != uVar8; uVar8 = uVar8 + 1) {
      piVar7 = *(int **)(*piVar4 + uVar8 * 4);
      iVar3 = *piVar7;
      if ((*(char *)(iVar3 + 8) == '\x04') && (*(char *)(iVar3 + 9) == '\x01')) {
        iVar3 = piVar7[2];
        goto LAB_6005dcfe;
      }
    }
    iVar3 = 0;
LAB_6005dcfe:
    *DAT_6005deac = iVar3;
    FUN_600cc984(pbVar1);
  }
  piVar4 = DAT_6005deac;
  local_13c = 0;
  local_13b = 0;
  local_138 = 0;
  local_134 = 0x20;
  iVar3 = FUN_60101a80(*(undefined4 *)(param_1 + 0x14));
  local_130 = &local_122;
  iVar9 = *piVar4;
  local_12c = 0xff;
  local_124 = 0;
  local_122 = 0x7d7b;
  local_123 = 0;
  local_120 = 0;
  local_13a = 0;
  local_128 = 2;
  cVar2 = FUN_601010c8(iVar9,PTR_s_BookkeepVer_6005deb0,&local_13a);
  if (cVar2 != '\0') {
    return cVar2;
  }
  if (local_13a == 8) {
    cVar2 = key_value_store__600cb598(iVar9,PTR_s_BookkeepVer_6005deb0,&local_138,8,0);
    if (cVar2 != '\0') {
      return cVar2;
    }
    if ((((local_138 & 0xffff) != 0) || (local_138._2_2_ != 2)) || (local_134 != 0x20)) {
      return '\t';
    }
    FUN_60101a64(&local_130);
    uVar5 = FUN_600cc450(&local_130,PTR_s_key_6012497a_0x16_6005deb4,PTR_s_BookkeepVer_6005deb0);
    uVar5 = FUN_600d3534(uVar5,PTR_s_major_6005deb8,local_138 & 0xffff);
    piVar7 = (int *)FUN_600d3534(uVar5,PTR_s_minor_6005debc,local_138._2_2_);
    iVar9 = local_134;
    iVar10 = piVar7[2];
    iVar6 = FUN_600cc3cc(piVar7,PTR_s_fingerprint_size_6005dec0);
    if (iVar6 != 0) {
      uVar5 = FUN_60050c18(iVar9,0,piVar7[2] + *piVar7,piVar7[1] - piVar7[2]);
      FUN_601019da(piVar7,uVar5,iVar10,0x7d);
    }
    FUN_6010138c(param_1,piVar7);
    iVar9 = *piVar4;
    local_13a = 0;
    cVar2 = FUN_601010c8(iVar9,PTR_s_BookkeepMeta_6005dec4,&local_13a);
    if (cVar2 != '\0') {
      return cVar2;
    }
    if (local_13a == 2) {
      cVar2 = key_value_store__600cb598(iVar9,PTR_s_BookkeepMeta_6005dec4,&local_13c,2,0);
      if (cVar2 != '\0') {
        return cVar2;
      }
      FUN_60101a64(&local_130);
      uVar5 = FUN_600cc450(&local_130,PTR_s_key_6012497a_0x16_6005deb4,PTR_s_BookkeepMeta_6005dec4);
      uVar5 = FUN_600d4566(uVar5,DAT_6005dec8,local_13c);
      uVar5 = FUN_600d4566(uVar5,PTR_s_backup_6005decc,local_13b);
      FUN_6010138c(param_1,uVar5);
      FUN_6005dbec(*piVar4,PTR_s_AppAMeta_6005ded0,&local_130);
      uVar5 = FUN_600cc450(&local_130,PTR_s_key_6012497a_0x16_6005deb4,PTR_s_AppAMeta_6005ded0);
      FUN_6010138c(param_1,uVar5);
      FUN_6005dbec(*piVar4,PTR_s_AppBMeta_6005ded4,&local_130);
      uVar5 = FUN_600cc450(&local_130,PTR_s_key_6012497a_0x16_6005deb4,PTR_s_AppBMeta_6005ded4);
      FUN_6010138c(param_1,uVar5);
      return *(char *)(iVar3 + 0xd);
    }
  }
  return '\x03';
}



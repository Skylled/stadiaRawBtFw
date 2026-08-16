// 600d89ec  adapter__600d89ec  size=746 bytes
// src: adapter.cc
// --- callers ---
//   600d8a12 FUN_600d8a12
//   60069780 adapter__60069780
// --- callees ---
//   60101818 FUN_60101818
//   60092e90 FUN_60092e90
//   6006a5c8 gatt_server__6006a5c8
//   600d8994 FUN_600d8994
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60051120 FUN_60051120
//   600cc8f8 FUN_600cc8f8
//   60093258 FUN_60093258
//   600cc984 FUN_600cc984
//   601017fc FUN_601017fc
//   600932bc FUN_600932bc
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d37b8 FUN_600d37b8
//   6010165c FUN_6010165c
//   600d37ac FUN_600d37ac
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6013cf40 thunk_EXT_FUN_00007d10
//   60069104 FUN_60069104


/* src: adapter.cc */

undefined4 adapter__600d89ec(int param_1,char *param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 local_130;
  undefined1 auStack_128 [4];
  undefined4 *local_124;
  undefined4 *puStack_120;
  undefined4 *local_104;
  undefined2 local_100;
  char local_fe;
  undefined1 uStack_fd;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  char *local_f0;
  undefined4 local_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 local_dc;
  char local_d8;
  char *local_d4;
  undefined2 local_d0 [8];
  uint local_c0;
  undefined4 local_bc;
  undefined2 local_b8;
  undefined1 auStack_b4 [144];
  char local_24;
  
  iVar4 = FUN_600d8994(param_1 + 0x110);
  if (iVar4 == 0) {
    return 9;
  }
  thunk_EXT_FUN_0000b5ba(auStack_128,0,0x2c);
  local_fc = 0;
  local_f4 = 0;
  local_f0 = (char *)0x0;
  thunk_EXT_FUN_0000b5ba(&local_ec,0,0x1c);
  local_f8 = thunk_EXT_FUN_0000b5ba(local_d0,0,0x10);
  puStack_120 = &local_fc;
  local_c0 = 0;
  local_124 = &local_f4;
  local_104 = &local_ec;
  thunk_EXT_FUN_0000b4c2(param_1 + 0x1ed4);
  local_c0 = 0;
  if (*param_2 != '\0') {
    local_fe = param_2[1];
    local_c0 = 2;
  }
  uVar8 = *(uint *)(param_2 + 4);
  if (uVar8 - 1 < 0xfffffffd || uVar8 == 0xfffffffe) {
    if (uVar8 < 0x20) {
      thunk_EXT_FUN_0000b572(&local_bc,param_2 + 9,uVar8);
      *(undefined1 *)((int)&local_bc + uVar8) = 0;
      FUN_60092e90(&local_bc);
      local_c0 = local_c0 | 1;
    }
    else {
      FUN_60051120(&local_bc,DAT_60069548,0x16b,3);
      FUN_600d37ac(auStack_b4,DAT_6006954c);
      FUN_600d37b8(&local_bc);
      if (local_24 != '\0') goto LAB_60069420;
    }
  }
  if (param_2[0x2c] == '\x03') {
    uVar7 = 1;
  }
  else {
    if (param_2[0x2c] != '\x02') goto LAB_60069420;
    uVar7 = 0;
  }
  if ((*(uint *)(param_2 + 0x28) & 0x7fffffff) != 0) {
    uVar8 = *(uint *)(param_2 + 0x28) & 0x7fffffff;
    if (8 < uVar8) goto LAB_60069420;
    pcVar5 = param_2 + 0x2d;
    for (uVar6 = 0; uVar8 != uVar6; uVar6 = uVar6 + 1) {
      local_d0[uVar6] = *(undefined2 *)pcVar5;
      pcVar5 = pcVar5 + 2;
    }
    local_fc._0_2_ = CONCAT11(uVar7,(char)uVar8);
    local_c0 = local_c0 | 0x40;
  }
  uVar8 = (uint)(byte)param_2[0x4b];
  if (uVar8 != 0) {
    if (((uVar8 == 1) || (param_2[0x4d] != -1)) || ((uint)(byte)param_2[0x4c] != uVar8 - 1))
    goto LAB_60069420;
    local_f4 = CONCAT31(local_f4._1_3_,param_2[0x4b] - 2);
    local_f0 = param_2 + 0x4e;
    local_c0 = local_c0 | 4;
  }
  bVar1 = param_2[0x6b];
  if (bVar1 != 0) {
    if (bVar1 < 5) goto LAB_60069420;
    local_b8 = *(undefined2 *)(param_2 + 0x6e);
    local_bc = 0;
    gatt_server__6006a5c8(&local_140,&local_bc);
    local_ec = local_140;
    uStack_e8 = uStack_13c;
    uStack_e4 = uStack_138;
    uStack_e0 = uStack_134;
    local_dc = local_130;
    local_d4 = param_2 + 0x70;
    local_c0 = local_c0 | 0x100;
    local_d8 = bVar1 - 4;
  }
  if (param_2[0x8b] != '\0') {
    local_c0 = local_c0 | 8;
  }
LAB_60069420:
  if (*(char *)(param_1 + 0x10c) != '\0') {
    local_100 = *(undefined2 *)(param_1 + 0x10a);
    local_c0 = local_c0 | 0x800;
  }
  if (*(char *)(param_1 + 0x1f28) == '\0') {
    local_c0 = local_c0 & 0xffffdfff;
  }
  else {
    local_c0 = local_c0 | 0x2000;
  }
  if (*(char *)(param_1 + 0x1f2f) == '\0') {
    uVar8 = 0x100;
  }
  else {
    uVar8 = 0x200;
  }
  if (param_3 == 0) {
    uVar6 = 0xffffffbf;
  }
  else {
    uVar6 = 0xfffffffd;
  }
  local_c0 = (local_c0 | uVar8) & uVar6;
  thunk_EXT_FUN_00007d10(param_1 + 0x1ed4);
  if (param_3 == 0) {
    if (((int)(local_c0 << 0x1c) < 0) && (cVar3 = FUN_60069104(&uStack_fd), cVar3 != '\0')) {
      FUN_6010165c(0x28,DAT_60069548,0x128,DAT_60069560);
      local_c0 = local_c0 & 0xfffffff7;
    }
    pbVar2 = DAT_60069564;
    bVar1 = *DAT_60069564;
    DataMemoryBarrier(0x1b);
    if (((bVar1 & 1) == 0) && (iVar4 = FUN_600cc8f8(DAT_60069564), iVar4 != 0)) {
      *(uint *)(DAT_60069568 + 0x50) = bVar1 & 1;
      FUN_601017fc();
      FUN_600cc984(pbVar2);
    }
    FUN_60093258(local_c0,auStack_128,DAT_6006956c);
    iVar4 = DAT_60069568;
  }
  else {
    if (((int)(local_c0 << 0x1c) < 0) && (cVar3 = FUN_60069104(&uStack_fd), cVar3 != '\0')) {
      FUN_6010165c(0x28,DAT_60069548,0x113,DAT_60069550);
      local_c0 = local_c0 & 0xfffffff7;
    }
    pbVar2 = DAT_60069554;
    bVar1 = *DAT_60069554;
    DataMemoryBarrier(0x1b);
    if (((bVar1 & 1) == 0) && (iVar4 = FUN_600cc8f8(DAT_60069554), iVar4 != 0)) {
      *(uint *)(DAT_60069558 + 0x50) = bVar1 & 1;
      FUN_601017fc();
      FUN_600cc984(pbVar2);
    }
    FUN_600932bc(local_c0,auStack_128,DAT_6006955c);
    iVar4 = DAT_60069558;
  }
  FUN_60101818(iVar4);
  return 0;
}



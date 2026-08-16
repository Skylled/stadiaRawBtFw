// 6005b1c0  application_state__6005b1c0  size=552 bytes
// src: application_state.cc
// --- callers ---
//   6005b8dc application_state__6005b8dc
// --- callees ---
//   6005f120 FUN_6005f120
//   600d37b8 FUN_600d37b8
//   60065db0 FUN_60065db0
//   600cbb14 FUN_600cbb14
//   600d3a16 thunk_FUN_60059eb8
//   60065dd8 FUN_60065dd8
//   600d3dd8 FUN_600d3dd8
//   600849a4 state_machine__600849a4
//   600d3b3a FUN_600d3b3a
//   600d6e14 FUN_600d6e14
//   60101198 FUN_60101198
//   6005b150 application_state__6005b150
//   60059f98 reboot_reason__60059f98
//   600d37ac FUN_600d37ac
//   600d3e22 FUN_600d3e22
//   6010165c FUN_6010165c
//   600d382e FUN_600d382e
//   60101b76 FUN_60101b76
//   600678e0 FUN_600678e0
//   6005a010 FUN_6005a010


/* src: application_state.cc */

void application_state__6005b1c0(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  byte local_b8 [4];
  int local_b4;
  int local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [144];
  
  reboot_reason__60059f98(&local_b0,0);
  *(undefined2 *)(param_1 + 0x10c) = (undefined2)local_ac;
  *(int *)(param_1 + 0x108) = local_b0;
  *(undefined1 *)(param_1 + 0x10e) = local_ac._2_1_;
  if (*(char *)(param_1 + 0x10d) != '\0') {
    uVar4 = FUN_60065db0(0x27);
    uVar5 = FUN_60065dd8(0x27);
    FUN_60101198(uVar4,uVar5,DAT_6005b3f0,4);
  }
  iVar7 = DAT_6005b3f8;
  switch(*(undefined4 *)(param_1 + 0x108)) {
  case 1:
    local_b0 = 0;
    cVar2 = FUN_600d382e(0x18,&local_b0);
    if (cVar2 == '\x05') {
      uVar5 = 0xef;
      uVar4 = DAT_6005b3f4;
LAB_6005b230:
      FUN_6010165c(0x1e,DAT_6005b3f8,uVar5,uVar4);
    }
    else {
      if (cVar2 != '\0') {
        uVar5 = 0xf2;
        uVar4 = DAT_6005b400;
        goto LAB_6005b230;
      }
      if (local_b0 == DAT_6005b404) {
        FUN_6010165c(0x1e,DAT_6005b3f8,0x21d,DAT_6005b408);
        cVar2 = *(char *)(param_1 + 0x10c);
        goto joined_r0x6005b310;
      }
    }
    FUN_6010165c(0x14,DAT_6005b3f8,0x213,DAT_6005b3fc);
    uVar1 = *(undefined1 *)(param_1 + 0x10c);
    uVar4 = FUN_6005a010();
    thunk_FUN_60059eb8(2,uVar1,uVar4);
    FUN_6005f120(5);
    uVar4 = FUN_6005a010();
    thunk_FUN_60059eb8(0,0,uVar4);
    if (*(char *)(param_1 + 0x10c) == '\0') {
      return;
    }
    uVar4 = 0xd;
    goto LAB_6005b27c;
  case 2:
    FUN_6010165c(0x14,DAT_6005b3f8,0x226,DAT_6005b40c);
    iVar6 = FUN_600d6e14(0x27);
    if (iVar6 != 0) {
      local_b4 = 0;
      bVar3 = FUN_600d382e(0x27,&local_b4);
      if (bVar3 == 0) {
        if (local_b4 == DAT_6005b404) {
          FUN_6010165c(0x14,iVar7,0x229,DAT_6005b414);
          cVar2 = *(char *)(param_1 + 0x10c);
          uVar4 = FUN_6005a010();
          thunk_FUN_60059eb8(4,0,uVar4);
          if (cVar2 == '\0') {
            local_ac = 6;
          }
          else {
            local_ac = 7;
          }
          local_b0 = 1;
          goto LAB_6005b34e;
        }
      }
      else {
        local_b0 = iVar7;
        local_ac = 0x111;
        FUN_600d3b3a(auStack_a8);
        FUN_600d37ac(auStack_a8,DAT_6005b410);
        local_b8[0] = bVar3;
        uVar4 = FUN_600cbb14(local_b8);
        FUN_60101b76(auStack_a8,uVar4);
        FUN_600d37b8(&local_b0);
      }
    }
    cVar2 = *(char *)(param_1 + 0x10c);
joined_r0x6005b310:
    if (cVar2 != '\0') {
LAB_6005b2ac:
      local_b0 = 0;
      local_ac = 0xd;
LAB_6005b34e:
      FUN_600d3dd8(local_b0,local_ac);
      return;
    }
    break;
  case 3:
    uVar4 = 0;
    goto LAB_6005b27c;
  case 5:
    FUN_6010165c(0x14,DAT_6005b3f8,0x23a,DAT_6005b418);
    if (*(char *)(param_1 + 0x10c) != '\0') {
      FUN_6010165c(0x14,DAT_6005b3f8,0x241,DAT_6005b41c);
      iVar7 = application_state__6005b150();
      if (iVar7 != 0) {
        local_b0 = 1;
        local_ac = 7;
        goto LAB_6005b34e;
      }
      goto LAB_6005b2ac;
    }
    iVar7 = application_state__6005b150();
    if (iVar7 != 0) {
      local_b0 = 1;
      local_ac = 6;
      goto LAB_6005b34e;
    }
    break;
  case 6:
    uVar4 = 0x10;
    goto LAB_6005b27c;
  }
  if (((**(uint **)(DAT_6005b420 + 0x9bc) >> (*(uint *)(DAT_6005b420 + 0x9b4) & 0xff) & 1) == 0) &&
     (*(int *)(DAT_6005b420 + 0x4328) != 2)) {
    iVar7 = FUN_600678e0();
    if (iVar7 == 0) {
      uVar4 = 0;
    }
    else {
      FUN_600d3e22(DAT_6005b424,0x10,iVar7);
      uVar4 = 0xf;
    }
  }
  else {
    uVar4 = 0x10;
  }
LAB_6005b27c:
  state_machine__600849a4(param_1 + 8,uVar4,0);
  return;
}



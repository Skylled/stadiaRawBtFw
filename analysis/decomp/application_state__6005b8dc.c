// 6005b8dc  application_state__6005b8dc  size=770 bytes
// src: application_state.cc
// --- callers ---
// --- callees ---
//   60076400 FUN_60076400
//   6005b1c0 application_state__6005b1c0
//   6007f8e4 pattern_player__6007f8e4
//   6008099c state_machine__6008099c
//   6005ad74 application_state__6005ad74
//   6013cf40 thunk_EXT_FUN_00007d10
//   600d3dd8 FUN_600d3dd8
//   60074ba8 FUN_60074ba8
//   6005acf4 FUN_6005acf4
//   600df0f0 FUN_600df0f0
//   6013cf80 thunk_EXT_FUN_0000714c
//   600dffe8 FUN_600dffe8
//   600d3d9a FUN_600d3d9a
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600d8df2 FUN_600d8df2
//   6013d0b0 thunk_EXT_FUN_00001ea4
//   600ca9dc FUN_600ca9dc
//   6007f870 FUN_6007f870
//   6005bdac FUN_6005bdac
//   6005ad30 FUN_6005ad30
//   6005d1e4 thermal__6005d1e4
//   6013d158 thunk_EXT_FUN_00001ae4
//   600849a4 state_machine__600849a4
//   60080180 wakelock__60080180
//   600d3d54 FUN_600d3d54
//   60082b3c FUN_60082b3c
//   6005af04 pattern_player__6005af04
//   6005b850 application_state__6005b850
//   60079a3c FUN_60079a3c
//   6010165c FUN_6010165c
//   600670f4 gotham_patterns__600670f4
//   600d4e64 FUN_600d4e64


/* src: application_state.cc */

void application_state__6005b8dc(int param_1,uint param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_2c [2];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_2c[0] = param_2;
  uVar2 = FUN_600ca9dc();
  uVar3 = FUN_60079a3c(local_2c);
  thunk_EXT_FUN_00001ae4(5,uVar2,2,0,uVar3);
  uVar2 = FUN_6005ad30(local_2c[0]);
  FUN_600d8df2(DAT_6005bbfc,uVar2);
  application_state__6005b850(param_1);
  iVar4 = FUN_6007f870();
  if ((*(char *)(iVar4 + 300) != '\0') && (local_2c[0] == 8)) {
    uVar2 = FUN_6007f870();
    if (*(int *)(*(int *)(param_1 + 0x118) + 0x184) == 0) {
      uVar3 = 9;
    }
    else {
      uVar3 = 0xf;
    }
    uVar3 = gotham_patterns__600670f4(uVar3);
    pattern_player__6005af04(uVar2,7,uVar3);
  }
  uVar2 = DAT_6005bc08;
  iVar4 = param_1 + 8;
  switch(local_2c[0]) {
  case 0:
    application_state__6005b1c0(param_1);
    break;
  case 2:
    FUN_60074ba8(4);
    FUN_600d3d54(*(undefined4 *)(param_1 + 0x8c));
    wakelock__60080180(*(undefined4 *)(param_1 + 0x80));
    break;
  case 4:
    iVar5 = FUN_60082b3c();
    if (iVar5 == 1) {
      FUN_6010165c(0x14,DAT_6005bc08,0x2b3,DAT_6005bc0c);
      local_20 = 0;
      local_1c = 3;
    }
    else {
      if (iVar5 != 2) {
        FUN_6010165c(0x14,DAT_6005bc08,0x2b9,DAT_6005bc14);
        break;
      }
      FUN_6010165c(0x14,DAT_6005bc08,0x2b6,DAT_6005bc10);
      local_20 = 0;
      local_1c = 2;
    }
    goto LAB_6005ba78;
  case 5:
    local_20 = 6;
    goto LAB_6005b9b0;
  case 6:
    FUN_600d3d54(*(undefined4 *)(param_1 + 0xcc));
    local_20 = 6;
    local_1c = 1;
    goto LAB_6005ba78;
  case 7:
    *(undefined1 *)(param_1 + 0x11c) = 0;
    FUN_6010165c(0x14,uVar2,0x2c8,DAT_6005bc18);
    FUN_600d4e64(DAT_6005bc1c);
    break;
  case 8:
    FUN_60074ba8(0xc);
    FUN_6005bdac();
    local_20 = 6;
    local_1c = 4;
    FUN_600d3dd8(6,4);
    wakelock__60080180(*(undefined4 *)(param_1 + 0x80));
    uVar6 = thunk_EXT_FUN_0000714c();
    if ((((uVar6 % 1000) * 1000 + 500) / 1000 + (uVar6 / 1000) * 1000 < 10000) &&
       (*(char *)(DAT_6005bc00 + 0x4362) != '\0')) {
      local_24 = CONCAT31(local_24._1_3_,0x1c);
      cVar1 = thunk_EXT_FUN_00001ea4
                        (*(undefined4 *)(DAT_6005bc00 + 0x4348),
                         *(undefined1 *)(DAT_6005bc00 + 0x434c),&local_24,1,&local_20,2,200);
      if ((cVar1 == '\0') && ((short)local_20 == 100)) {
        FUN_6010165c(0x14,DAT_6005bc08,0x299,DAT_6005bc04);
        FUN_6005bdac();
        local_20 = 1;
        local_1c = 2;
        goto LAB_6005ba78;
      }
    }
    break;
  case 9:
    wakelock__60080180(*(undefined4 *)(param_1 + 0x80));
    local_20 = 1;
LAB_6005b9b0:
    local_1c = 0;
    goto LAB_6005ba78;
  case 10:
    wakelock__60080180(*(undefined4 *)(param_1 + 0x80));
    local_1c = 1;
    local_20 = 1;
LAB_6005ba78:
    FUN_600d3dd8(local_20,local_1c);
    break;
  case 0xb:
    FUN_6005acf4(&local_20,*(undefined4 *)(param_1 + 0x118));
    if (local_20._1_1_ == '\0') {
      uVar2 = 0x11;
    }
    else {
      uVar2 = 10;
    }
    goto LAB_6005ba92;
  case 0xc:
    if (*(int *)(*(int *)(param_1 + 0x118) + 0x184) == 0) {
      state_machine__600849a4(iVar4,0x13);
    }
    thermal__6005d1e4(*(undefined4 *)(param_1 + 0x118));
    break;
  case 0xd:
    uVar2 = FUN_6007f870();
    uVar3 = gotham_patterns__600670f4(0xd);
    local_20 = DAT_6005bc20;
    local_1c = 0;
    thunk_EXT_FUN_0000b4c2(uVar2);
    pattern_player__6007f8e4(uVar2,1,uVar3,0,local_20,local_1c);
    thunk_EXT_FUN_00007d10(uVar2);
    FUN_600d4e64(DAT_6005bc1c);
    uVar2 = 0x12;
LAB_6005ba92:
    state_machine__600849a4(iVar4,uVar2,0);
  }
  if (local_2c[0] == 2) {
    uVar2 = 1;
  }
  else if (local_2c[0] == 7) {
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  application_state__6005ad74(param_1,uVar2);
  uVar2 = DAT_6005bc28;
  if (local_2c[0] != 7) {
    uVar2 = DAT_6005bc2c;
  }
  FUN_600df0f0(DAT_6005bc24,uVar2);
  if (local_2c[0] < 0xd) {
    uVar6 = 1 << (local_2c[0] & 0xff);
    if ((uVar6 & 0x1902) == 0) {
      if ((int)(uVar6 << 0x1d) < 0) {
        iVar5 = FUN_60076400();
        *(undefined4 *)(iVar5 + 0x3fc) = 0;
        goto LAB_6005bbb0;
      }
      goto LAB_6005bbf0;
    }
    iVar5 = FUN_60076400();
    uVar2 = 0x17a;
  }
  else {
LAB_6005bbf0:
    iVar5 = FUN_60076400();
    uVar2 = 4000;
  }
  *(undefined4 *)(iVar5 + 0x3fc) = uVar2;
LAB_6005bbb0:
  iVar4 = FUN_600dffe8(iVar4,local_2c[0]);
  if (iVar4 != 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x84);
    iVar4 = FUN_600d3d9a(param_1);
    if (iVar4 == 0) {
      local_24 = 5;
    }
    else {
      local_24 = 4;
    }
    state_machine__6008099c(uVar2,&local_24);
  }
  return;
}



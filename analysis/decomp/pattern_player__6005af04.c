// 6005af04  pattern_player__6005af04  size=190 bytes
// src: pattern_player.h
// --- callers ---
//   6005b8dc application_state__6005b8dc
// --- callees ---
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600d37b8 FUN_600d37b8
//   600cbb14 FUN_600cbb14
//   6013cf40 thunk_EXT_FUN_00007d10
//   6010165c FUN_6010165c
//   600d3b3a FUN_600d3b3a
//   600d3d7c FUN_600d3d7c
//   6007f8e4 pattern_player__6007f8e4
//   600d37ac FUN_600d37ac


/* src: pattern_player.h */

void pattern_player__6005af04(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  byte local_b8 [4];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 auStack_ac [144];
  byte local_1c;
  
  thunk_EXT_FUN_0000b4c2();
  bVar1 = FUN_600d3d7c(*(undefined4 *)(param_1 + 0x58));
  if (bVar1 != 0) {
    local_b4 = DAT_6005afc4;
    local_b0 = 0x67;
    local_b8[0] = bVar1;
    FUN_600d3b3a(auStack_ac);
    local_1c = local_b8[0];
    uVar2 = FUN_600cbb14(local_b8);
    FUN_600d37ac(auStack_ac,uVar2);
    FUN_600d37ac(auStack_ac,DAT_6005afc8);
    FUN_600d37ac(auStack_ac,DAT_6005afcc);
    FUN_600d37b8(&local_b4);
  }
  *(undefined4 *)(param_1 + 0x94) = 7;
  local_b4 = DAT_6005afd0;
  *(undefined1 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  local_b0 = 0;
  pattern_player__6007f8e4(param_1,param_2,param_3,1,local_b4,0);
  FUN_6010165c(0x14,DAT_6005afc4,0x70,DAT_6005afd4);
  thunk_EXT_FUN_00007d10(param_1);
  return;
}



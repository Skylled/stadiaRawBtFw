// 6007f8e4  pattern_player__6007f8e4  size=308 bytes
// src: pattern_player.cc
// --- callers ---
//   6005b794 application_state__6005b794
//   6005ac84 FUN_6005ac84
//   600ce26a FUN_600ce26a
//   6005af04 pattern_player__6005af04
//   6005b8dc application_state__6005b8dc
// --- callees ---
//   600dee00 FUN_600dee00
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   6010165c FUN_6010165c
//   600dee28 FUN_600dee28
//   600d37ac FUN_600d37ac
//   60101740 FUN_60101740
//   60051120 FUN_60051120
//   600d37b8 FUN_600d37b8


/* src: pattern_player.cc */

void pattern_player__6007f8e4
               (int param_1,int param_2,int *param_3,uint param_4,undefined4 param_5,
               undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 *local_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined1 local_a0;
  undefined1 local_9f;
  undefined1 local_9e [138];
  
  if ((*(uint *)(DAT_6007fa18 + 4) & 0x1ff) != 0) {
    local_b4 = DAT_6007fa1c;
    local_a0 = 0;
    local_b0 = 0x3c;
    local_ac = local_9e;
    local_9f = 0;
    local_9e[0] = 0;
    local_a8 = 0x80;
    uStack_a4 = 0;
    FUN_600d37ac(&local_ac,DAT_6007fa20);
    FUN_60101740(&local_b4);
  }
  if (*(char *)(param_1 + 300) == '\0') {
    if (*(int *)(param_1 + 0x11c) == 0) {
      iVar1 = param_1 + 0x98 + *(int *)(param_1 + 0x94) * 0x10;
    }
    else {
      iVar1 = param_1 + 0x118;
    }
    uVar4 = *(undefined4 *)(iVar1 + 4);
    iVar1 = param_1 + param_2 * 0x10;
    if ((*(int **)(iVar1 + 0x9c) != param_3) || (*(byte *)(iVar1 + 0x98) != param_4)) {
      *(int **)(iVar1 + 0x9c) = param_3;
      iVar3 = param_1 + param_2 * 0x10;
      *(char *)(iVar1 + 0x98) = (char)param_4;
      *(undefined4 *)(iVar3 + 0xa0) = param_5;
      *(undefined4 *)(iVar3 + 0xa4) = param_6;
      if (*(int *)(param_1 + 0x11c) == 0) {
        if (param_2 <= *(int *)(param_1 + 0x94)) {
          FUN_600dee28(param_1,uVar4);
          iVar1 = thunk_EXT_FUN_00007a2c(*(undefined4 *)(param_1 + 0x58),4,1,0,10);
          if (iVar1 == 0) {
            FUN_60051120(&local_b4,DAT_6007fa1c,0x54,4);
            FUN_600d37ac(&local_ac,DAT_6007fa34);
            FUN_600d37b8(&local_b4);
          }
          uVar2 = FUN_600dee00(*(undefined4 *)(param_1 + 0x58));
          if ((uVar2 & 0xff) != 0) {
            FUN_60051120(&local_b4,DAT_6007fa1c,0x56,uVar2);
            FUN_600d37ac(&local_ac,DAT_6007fa38);
            FUN_600d37b8(&local_b4);
          }
        }
      }
      else {
        FUN_6010165c(0x1e,DAT_6007fa1c,0x50,DAT_6007fa30);
      }
    }
  }
  else {
    iVar1 = DAT_6007fa2c;
    if ((param_3 != (int *)0x0) && (iVar1 = (**(code **)(*param_3 + 8))(param_3), iVar1 == 0)) {
      iVar1 = DAT_6007fa24;
    }
    FUN_6010165c(10,DAT_6007fa1c,0x3f,DAT_6007fa28,iVar1);
  }
  return;
}



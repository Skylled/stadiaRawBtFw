// 600849a4  state_machine__600849a4  size=266 bytes
// src: state_machine.cc
// --- callers ---
//   60074ba8 FUN_60074ba8
//   6005b8dc application_state__6005b8dc
//   6005bdb4 gotham_task__6005bdb4
//   6005b1c0 application_state__6005b1c0
// --- callees ---
//   600840d4 FUN_600840d4
//   600840a4 FUN_600840a4
//   600dff54 FUN_600dff54
//   600e008a FUN_600e008a
//   600d37ac FUN_600d37ac
//   600848bc state_machine__600848bc
//   600d3b24 FUN_600d3b24
//   600d3b3a FUN_600d3b3a
//   600dff76 FUN_600dff76
//   60084644 state_machine__60084644
//   6013cfe8 thunk_EXT_FUN_0000ab28
//   600e00ca FUN_600e00ca


/* src: state_machine.cc */

void state_machine__600849a4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined4 *puVar2;
  undefined1 auStack_c0 [8];
  undefined4 local_b8;
  undefined1 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [148];
  
  state_machine__600848bc();
  if (*(char *)(param_1 + 0x58) == '\0') {
    state_machine__60084644(param_1,param_2,param_3);
    FUN_600e008a(param_1);
  }
  else {
    if (*(char *)(param_1 + 0x5b) != '\0') {
      local_b0 = DAT_60084ab0;
      local_ac = 0x5a;
      FUN_600d3b3a(auStack_a8);
      FUN_600d37ac(auStack_a8,*(undefined4 *)(param_1 + 4));
      FUN_600d37ac(auStack_a8,DAT_60084ab4);
      thunk_EXT_FUN_0000ab28(auStack_c0,param_1 + 0x1c);
      uVar1 = FUN_600840a4(param_1,auStack_c0);
      FUN_600d37ac(auStack_a8,uVar1);
      FUN_600d37ac(auStack_a8,DAT_60084ab8);
      uVar1 = 0;
      if (*(char *)(param_1 + 0x20) != '\0') {
        uVar1 = *(undefined4 *)(param_1 + 0x1c);
      }
      FUN_600dff54(auStack_a8,uVar1);
      FUN_600d37ac(auStack_a8,DAT_60084abc);
      FUN_600d37ac(auStack_a8,DAT_60084ac0);
      FUN_600dff76(auStack_a8,extraout_r1,*(undefined4 *)(param_1 + 0x28),
                   *(undefined4 *)(param_1 + 0x2c));
      FUN_600d37ac(auStack_a8,DAT_60084ac4);
      FUN_600d37ac(auStack_a8,DAT_60084ac8);
      local_b4 = 1;
      local_b8 = param_2;
      uVar1 = FUN_600840d4(param_1,&local_b8);
      FUN_600d37ac(auStack_a8,uVar1);
      FUN_600d37ac(auStack_a8,DAT_60084ab8);
      FUN_600dff54(auStack_a8,param_2);
      FUN_600d37ac(auStack_a8,DAT_60084abc);
      FUN_600d3b24(&local_b0);
    }
    puVar2 = *(undefined4 **)(param_1 + 0x48);
    if (puVar2 == (undefined4 *)(*(int *)(param_1 + 0x50) + -8)) {
      local_b0 = param_2;
      local_ac = param_3;
      FUN_600e00ca(param_1 + 0x30,&local_b0);
    }
    else {
      *puVar2 = param_2;
      puVar2[1] = param_3;
      *(undefined4 **)(param_1 + 0x48) = puVar2 + 2;
    }
  }
  return;
}



// 600841d0  state_machine__600841d0  size=190 bytes
// src: state_machine.cc
// --- callers ---
//   600843c8 state_machine__600843c8
// --- callees ---
//   600840a4 FUN_600840a4
//   600dff54 FUN_600dff54
//   600d37ac FUN_600d37ac
//   6013d320 thunk_EXT_FUN_0000ab42
//   6013d358 thunk_EXT_FUN_0000ab36
//   600d3b24 FUN_600d3b24
//   600d3b3a FUN_600d3b3a
//   600dff76 FUN_600dff76
//   600dff98 FUN_600dff98
//   6013cfe8 thunk_EXT_FUN_0000ab28


/* src: state_machine.cc */

void state_machine__600841d0(int *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 extraout_r1;
  int *piVar4;
  undefined1 auStack_b0 [8];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [148];
  
  piVar4 = param_1 + 7;
  if (*(char *)((int)param_1 + 0x5b) != '\0') {
    local_a8 = DAT_60084290;
    local_a4 = 0x12f;
    FUN_600d3b3a(auStack_a0);
    FUN_600d37ac(auStack_a0,param_1[1]);
    FUN_600d37ac(auStack_a0,DAT_60084294);
    thunk_EXT_FUN_0000ab28(auStack_b0,piVar4);
    uVar1 = FUN_600840a4(param_1,auStack_b0);
    FUN_600d37ac(auStack_a0,uVar1);
    FUN_600d37ac(auStack_a0,DAT_60084298);
    iVar3 = 0;
    if ((char)param_1[8] != '\0') {
      iVar3 = param_1[7];
    }
    FUN_600dff54(auStack_a0,iVar3);
    FUN_600d37ac(auStack_a0,DAT_6008429c);
    FUN_600d37ac(auStack_a0,DAT_600842a0);
    FUN_600dff76(auStack_a0,extraout_r1,param_1[10],param_1[0xb]);
    FUN_600d37ac(auStack_a0,DAT_600842a4);
    FUN_600d37ac(auStack_a0,DAT_600842a8);
    FUN_600d3b24(&local_a8);
  }
  puVar2 = (undefined4 *)thunk_EXT_FUN_0000ab36(piVar4);
  (**(code **)(*param_1 + 0x24))(param_1,*puVar2);
  thunk_EXT_FUN_0000ab28(auStack_b0,piVar4);
  FUN_600dff98(&local_a8,param_1,auStack_b0);
  thunk_EXT_FUN_0000ab42(piVar4,&local_a8);
  return;
}



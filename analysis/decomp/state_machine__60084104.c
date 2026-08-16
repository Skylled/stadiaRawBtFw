// 60084104  state_machine__60084104  size=176 bytes
// src: state_machine.cc
// --- callers ---
//   600e002e FUN_600e002e
//   600843c8 state_machine__600843c8
// --- callees ---
//   600840a4 FUN_600840a4
//   600dff54 FUN_600dff54
//   6013d320 thunk_EXT_FUN_0000ab42
//   600d37ac FUN_600d37ac
//   600d3b24 FUN_600d3b24
//   600d3b3a FUN_600d3b3a
//   600dff76 FUN_600dff76
//   6013cfe8 thunk_EXT_FUN_0000ab28


/* src: state_machine.cc */

void state_machine__60084104(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined1 auStack_b0 [8];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [144];
  
  local_a4 = CONCAT31(local_a4._1_3_,1);
  local_a8 = param_2;
  thunk_EXT_FUN_0000ab42(param_1 + 7,&local_a8);
  if (*(char *)((int)param_1 + 0x5b) != '\0') {
    local_a8 = DAT_600841b4;
    local_a4 = 0x127;
    FUN_600d3b3a(auStack_a0);
    FUN_600d37ac(auStack_a0,param_1[1]);
    FUN_600d37ac(auStack_a0,DAT_600841b8);
    thunk_EXT_FUN_0000ab28(auStack_b0,param_1 + 7);
    uVar1 = FUN_600840a4(param_1,auStack_b0);
    FUN_600d37ac(auStack_a0,uVar1);
    FUN_600d37ac(auStack_a0,DAT_600841bc);
    iVar2 = 0;
    if ((char)param_1[8] != '\0') {
      iVar2 = param_1[7];
    }
    FUN_600dff54(auStack_a0,iVar2);
    FUN_600d37ac(auStack_a0,DAT_600841c0);
    FUN_600d37ac(auStack_a0,DAT_600841c4);
    FUN_600dff76(auStack_a0,extraout_r1,param_1[10],param_1[0xb]);
    FUN_600d37ac(auStack_a0,DAT_600841c8);
    FUN_600d37ac(auStack_a0,DAT_600841cc);
    FUN_600d3b24(&local_a8);
  }
  (**(code **)(*param_1 + 0x20))(param_1,param_2);
  return;
}



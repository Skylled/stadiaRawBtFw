// 600843c8  state_machine__600843c8  size=594 bytes
// src: state_machine.cc
// --- callers ---
//   60084644 state_machine__60084644
// --- callees ---
//   600840d4 FUN_600840d4
//   600840a4 FUN_600840a4
//   600dff54 FUN_600dff54
//   60084104 state_machine__60084104
//   600d37ac FUN_600d37ac
//   6013d320 thunk_EXT_FUN_0000ab42
//   600d3b24 FUN_600d3b24
//   600e002e FUN_600e002e
//   600842ac state_machine__600842ac
//   600dff98 FUN_600dff98
//   6013cfe8 thunk_EXT_FUN_0000ab28
//   600841d0 state_machine__600841d0
//   600d3b3a FUN_600d3b3a
//   600dff76 FUN_600dff76


/* src: state_machine.cc */

void state_machine__600843c8(int param_1,undefined4 param_2,int param_3,int param_4,char param_5)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  uint uVar2;
  uint uVar3;
  uint local_120;
  uint local_11c;
  int local_118;
  uint local_114;
  undefined4 local_110;
  undefined1 local_10c;
  int local_108;
  char local_104 [4];
  int local_100;
  undefined1 local_fc;
  int local_c0 [2];
  undefined1 auStack_b8 [148];
  
  if (*(char *)(param_1 + 0x5a) != '\0') {
    local_c0[0] = DAT_6008461c;
    local_c0[1] = 0xe3;
    FUN_600d3b3a(auStack_b8);
    FUN_600d37ac(auStack_b8,*(undefined4 *)(param_1 + 4));
    FUN_600d37ac(auStack_b8,DAT_60084620);
    thunk_EXT_FUN_0000ab28(&local_118,param_1 + 0x1c);
    uVar1 = FUN_600840a4(param_1,&local_118);
    FUN_600d37ac(auStack_b8,uVar1);
    FUN_600d37ac(auStack_b8,DAT_60084624);
    uVar1 = 0;
    if (*(char *)(param_1 + 0x20) != '\0') {
      uVar1 = *(undefined4 *)(param_1 + 0x1c);
    }
    FUN_600dff54(auStack_b8,uVar1);
    FUN_600d37ac(auStack_b8,DAT_60084628);
    FUN_600d37ac(auStack_b8,DAT_6008462c);
    FUN_600dff76(auStack_b8,extraout_r1,*(undefined4 *)(param_1 + 0x28),
                 *(undefined4 *)(param_1 + 0x2c));
    FUN_600d37ac(auStack_b8,DAT_60084630);
    local_10c = 1;
    local_110 = param_2;
    uVar1 = FUN_600840d4(param_1,&local_110);
    FUN_600d37ac(auStack_b8,uVar1);
    FUN_600d37ac(auStack_b8,DAT_60084624);
    FUN_600dff54(auStack_b8,param_2);
    FUN_600d37ac(auStack_b8,DAT_60084628);
    FUN_600d37ac(auStack_b8,DAT_60084634);
    local_104[0] = '\x01';
    local_108 = param_3;
    uVar1 = FUN_600840a4(param_1,&local_108);
    FUN_600d37ac(auStack_b8,uVar1);
    FUN_600d37ac(auStack_b8,DAT_60084624);
    FUN_600dff54(auStack_b8,param_3);
    FUN_600d37ac(auStack_b8,DAT_60084628);
    FUN_600d37ac(auStack_b8,DAT_60084638);
    local_fc = 1;
    local_100 = param_4;
    uVar1 = FUN_600840a4(param_1,&local_100);
    FUN_600d37ac(auStack_b8,uVar1);
    FUN_600d37ac(auStack_b8,DAT_60084624);
    FUN_600dff54(auStack_b8,param_4);
    FUN_600d37ac(auStack_b8,DAT_60084628);
    uVar1 = DAT_60084640;
    if (param_5 != '\0') {
      uVar1 = DAT_6008463c;
    }
    FUN_600d37ac(auStack_b8,uVar1);
    FUN_600d3b24(local_c0);
  }
  state_machine__600842ac(param_1,param_3,0x10,&local_100,&local_120);
  state_machine__600842ac(param_1,param_4,0x10,local_c0,&local_11c);
  uVar2 = local_11c;
  if (local_120 <= local_11c) {
    uVar2 = local_120;
  }
  for (uVar3 = 0; ((&local_100)[uVar3] == local_c0[uVar3] && (uVar2 != uVar3)); uVar3 = uVar3 + 1) {
  }
  if (uVar3 == 0) {
    local_118 = 0;
    local_114 = 0;
  }
  else {
    local_118 = *(int *)(local_104 + uVar3 * 4);
    local_114 = CONCAT31(local_114._1_3_,1);
    if ((param_5 != '\0') && ((local_118 == param_3 || (local_118 == param_4)))) {
      thunk_EXT_FUN_0000ab28(&local_110,&local_118);
      FUN_600dff98(&local_108,param_1,&local_110);
      thunk_EXT_FUN_0000ab42(&local_118,&local_108);
    }
  }
  while ((*(char *)(param_1 + 0x20) != '\0' &&
         (((local_114 & 0xff) == 0 || (*(int *)(param_1 + 0x1c) != local_118))))) {
    state_machine__600841d0(param_1);
  }
  uVar2 = *(uint *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x28) = uVar2 + 1;
  *(uint *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (uint)(0xfffffffe < uVar2);
  thunk_EXT_FUN_0000ab28(&local_108,param_1 + 0x1c);
  if (local_104[0] == '\0') {
    uVar2 = 0xffffffff;
  }
  else {
    for (uVar2 = 0; (local_c0[uVar2] != local_108 && (uVar2 != local_11c)); uVar2 = uVar2 + 1) {
    }
    if (local_11c == uVar2) {
      uVar2 = 0xffffffff;
    }
  }
  while (uVar2 = uVar2 + 1, uVar2 < local_11c) {
    state_machine__60084104(param_1,local_c0[uVar2]);
  }
  FUN_600e002e(param_1);
  return;
}



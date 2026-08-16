// 60084644  state_machine__60084644  size=594 bytes
// src: state_machine.cc
// --- callers ---
//   600e008a FUN_600e008a
//   600849a4 state_machine__600849a4
// --- callees ---
//   600840d4 FUN_600840d4
//   601016f0 FUN_601016f0
//   600840a4 FUN_600840a4
//   600dff54 FUN_600dff54
//   600d37ac FUN_600d37ac
//   6013d320 thunk_EXT_FUN_0000ab42
//   6013d358 thunk_EXT_FUN_0000ab36
//   600d3b24 FUN_600d3b24
//   600843c8 state_machine__600843c8
//   600dff98 FUN_600dff98
//   6013cfe8 thunk_EXT_FUN_0000ab28
//   600d3b3a FUN_600d3b3a
//   600dff76 FUN_600dff76


/* src: state_machine.cc */

void state_machine__60084644(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int *piVar5;
  undefined1 auStack_d4 [4];
  char local_d0;
  undefined1 auStack_cc [8];
  undefined4 local_c4;
  undefined1 local_c0;
  undefined4 local_bc;
  char local_b8;
  char local_b4;
  undefined1 local_b3;
  char local_b2;
  undefined4 local_b0;
  undefined4 local_ac;
  char local_a8;
  undefined1 local_a7;
  char local_a6;
  
  piVar5 = param_1 + 7;
  if (*(char *)((int)param_1 + 0x5b) != '\0') {
    local_b0 = DAT_60084898;
    local_ac = 0x81;
    FUN_600d3b3a(&local_a8);
    FUN_600d37ac(&local_a8,param_1[1]);
    FUN_600d37ac(&local_a8,DAT_6008489c);
    thunk_EXT_FUN_0000ab28(&local_c4,piVar5);
    uVar1 = FUN_600840a4(param_1,&local_c4);
    FUN_600d37ac(&local_a8,uVar1);
    FUN_600d37ac(&local_a8,DAT_600848a0);
    iVar4 = 0;
    if ((char)param_1[8] != '\0') {
      iVar4 = param_1[7];
    }
    FUN_600dff54(&local_a8,iVar4);
    FUN_600d37ac(&local_a8,DAT_600848a4);
    FUN_600d37ac(&local_a8,DAT_600848a8);
    FUN_600dff76(&local_a8,extraout_r1,param_1[10],param_1[0xb]);
    FUN_600d37ac(&local_a8,DAT_600848ac);
    FUN_600d37ac(&local_a8,DAT_600848b0);
    local_b8 = 1;
    local_bc = param_2;
    uVar1 = FUN_600840d4(param_1,&local_bc);
    FUN_600d37ac(&local_a8,uVar1);
    FUN_600d37ac(&local_a8,DAT_600848a0);
    FUN_600dff54(&local_a8,param_2);
    FUN_600d37ac(&local_a8,DAT_600848a4);
    FUN_600d3b24(&local_b0);
  }
  thunk_EXT_FUN_0000ab28(&local_b0,piVar5);
  FUN_600840a4(param_1,&local_b0);
  *(undefined1 *)(param_1 + 0x16) = 1;
  thunk_EXT_FUN_0000ab28(auStack_d4,piVar5);
  local_b8 = '\0';
  local_b4 = '\0';
  local_b3 = 0;
  local_b2 = '\0';
  while (local_d0 != '\0') {
    puVar2 = (undefined4 *)thunk_EXT_FUN_0000ab36(auStack_d4);
    (**(code **)(*param_1 + 0x1c))(&local_b0,param_1,*puVar2,param_2,param_3);
    thunk_EXT_FUN_0000ab42(&local_bc,&local_b0);
    local_b4 = local_a8;
    local_b3 = local_a7;
    local_b2 = local_a6;
    if (local_a6 != '\0') break;
    thunk_EXT_FUN_0000ab28(&local_c4,auStack_d4);
    FUN_600dff98(&local_b0,param_1,&local_c4);
    thunk_EXT_FUN_0000ab42(auStack_d4,&local_b0);
  }
  if ((local_b2 == '\0') && (*(char *)((int)param_1 + 0x5a) != '\0')) {
    local_b0 = DAT_60084898;
    local_ac = 0x9a;
    FUN_600d3b3a(&local_a8);
    FUN_600d37ac(&local_a8,param_1[1]);
    FUN_600d37ac(&local_a8,DAT_6008489c);
    thunk_EXT_FUN_0000ab28(auStack_cc,piVar5);
    uVar1 = FUN_600840a4(param_1,auStack_cc);
    FUN_600d37ac(&local_a8,uVar1);
    FUN_600d37ac(&local_a8,DAT_600848a0);
    iVar4 = 0;
    if ((char)param_1[8] != '\0') {
      iVar4 = param_1[7];
    }
    FUN_600dff54(&local_a8,iVar4);
    FUN_600d37ac(&local_a8,DAT_600848a4);
    FUN_600d37ac(&local_a8,DAT_600848a8);
    FUN_600dff76(&local_a8,extraout_r1_00,param_1[10],param_1[0xb]);
    FUN_600d37ac(&local_a8,DAT_600848ac);
    FUN_600d37ac(&local_a8,DAT_600848b4);
    local_c0 = 1;
    local_c4 = param_2;
    uVar1 = FUN_600840d4(param_1,&local_c4);
    FUN_600d37ac(&local_a8,uVar1);
    FUN_600d37ac(&local_a8,DAT_600848a0);
    FUN_600dff54(&local_a8,param_2);
    FUN_600d37ac(&local_a8,DAT_600848a4);
    FUN_600d37ac(&local_a8,DAT_600848b8);
    FUN_601016f0(0x1e,local_b0,local_ac,&local_a8);
  }
  if ((local_b4 != '\0') && (local_b8 != '\0')) {
    puVar2 = (undefined4 *)thunk_EXT_FUN_0000ab36(auStack_d4);
    puVar3 = (undefined4 *)thunk_EXT_FUN_0000ab36(&local_bc);
    state_machine__600843c8(param_1,param_2,*puVar2,*puVar3,local_b3);
  }
  *(undefined1 *)(param_1 + 0x16) = 0;
  return;
}



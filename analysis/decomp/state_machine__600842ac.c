// 600842ac  state_machine__600842ac  size=256 bytes
// src: state_machine.cc
// --- callers ---
//   600843c8 state_machine__600843c8
// --- callees ---
//   600840a4 FUN_600840a4
//   600dff54 FUN_600dff54
//   600d37ac FUN_600d37ac
//   6013d320 thunk_EXT_FUN_0000ab42
//   6013d358 thunk_EXT_FUN_0000ab36
//   600d3b3a FUN_600d3b3a
//   600dff76 FUN_600dff76
//   60101740 FUN_60101740
//   600dff98 FUN_600dff98
//   6013cfe8 thunk_EXT_FUN_0000ab28


/* src: state_machine.cc */

void state_machine__600842ac
               (int param_1,undefined4 param_2,int param_3,undefined4 *param_4,int *param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 extraout_r1;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_c8;
  char local_c4;
  undefined1 auStack_c0 [8];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined1 auStack_b0 [144];
  
  if (param_3 == 0) {
    local_b8 = DAT_600843ac;
    local_b4 = 200;
    FUN_600d3b3a(auStack_b0);
    FUN_600d37ac(auStack_b0,*(undefined4 *)(param_1 + 4));
    FUN_600d37ac(auStack_b0,DAT_600843b0);
    thunk_EXT_FUN_0000ab28(auStack_c0,param_1 + 0x1c);
    uVar1 = FUN_600840a4(param_1,auStack_c0);
    FUN_600d37ac(auStack_b0,uVar1);
    FUN_600d37ac(auStack_b0,DAT_600843b4);
    uVar1 = 0;
    if (*(char *)(param_1 + 0x20) != '\0') {
      uVar1 = *(undefined4 *)(param_1 + 0x1c);
    }
    FUN_600dff54(auStack_b0,uVar1);
    FUN_600d37ac(auStack_b0,DAT_600843b8);
    FUN_600d37ac(auStack_b0,DAT_600843bc);
    FUN_600dff76(auStack_b0,extraout_r1,*(undefined4 *)(param_1 + 0x28),
                 *(undefined4 *)(param_1 + 0x2c));
    FUN_600d37ac(auStack_b0,DAT_600843c0);
    FUN_600d37ac(auStack_b0,DAT_600843c4);
    FUN_60101740(&local_b8);
    if (param_5 != (int *)0x0) {
      *param_5 = 0;
    }
  }
  else {
    local_c4 = '\x01';
    puVar3 = param_4;
    local_c8 = param_2;
    for (iVar4 = 0; (local_c4 != '\0' && (iVar4 != param_3)); iVar4 = iVar4 + 1) {
      puVar2 = (undefined4 *)thunk_EXT_FUN_0000ab36(&local_c8);
      *puVar3 = *puVar2;
      thunk_EXT_FUN_0000ab28(auStack_c0,&local_c8);
      FUN_600dff98(&local_b8,param_1,auStack_c0);
      thunk_EXT_FUN_0000ab42(&local_c8,&local_b8);
      puVar3 = puVar3 + 1;
    }
    if (param_4 != puVar3) {
      for (; puVar3 = puVar3 + -1, param_4 < puVar3; param_4 = param_4 + 1) {
        uVar1 = *param_4;
        *param_4 = *puVar3;
        *puVar3 = uVar1;
      }
    }
    if (param_5 != (int *)0x0) {
      *param_5 = iVar4;
    }
  }
  return;
}



// 600848bc  state_machine__600848bc  size=204 bytes
// src: state_machine.cc
// --- callers ---
//   600849a4 state_machine__600849a4
// --- callees ---
//   600840a4 FUN_600840a4
//   600dff54 FUN_600dff54
//   600e008a FUN_600e008a
//   600d37ac FUN_600d37ac
//   600d3b24 FUN_600d3b24
//   600e002e FUN_600e002e
//   600d3b3a FUN_600d3b3a
//   600dff76 FUN_600dff76
//   6013cfe8 thunk_EXT_FUN_0000ab28


/* src: state_machine.cc */

void state_machine__600848bc(int param_1)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  int iVar2;
  undefined1 auStack_b0 [8];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [148];
  
  if (*(char *)(param_1 + 0x59) == '\0') {
    iVar2 = param_1 + 0x1c;
    if (*(char *)(param_1 + 0x5b) != '\0') {
      local_a8 = DAT_60084988;
      local_a4 = 0x24;
      FUN_600d3b3a(auStack_a0);
      FUN_600d37ac(auStack_a0,*(undefined4 *)(param_1 + 4));
      FUN_600d37ac(auStack_a0,DAT_6008498c);
      thunk_EXT_FUN_0000ab28(auStack_b0,iVar2);
      uVar1 = FUN_600840a4(param_1,auStack_b0);
      FUN_600d37ac(auStack_a0,uVar1);
      FUN_600d37ac(auStack_a0,DAT_60084990);
      uVar1 = 0;
      if (*(char *)(param_1 + 0x20) != '\0') {
        uVar1 = *(undefined4 *)(param_1 + 0x1c);
      }
      FUN_600dff54(auStack_a0,uVar1);
      FUN_600d37ac(auStack_a0,DAT_60084994);
      FUN_600d37ac(auStack_a0,DAT_60084998);
      FUN_600dff76(auStack_a0,extraout_r1,*(undefined4 *)(param_1 + 0x28),
                   *(undefined4 *)(param_1 + 0x2c));
      FUN_600d37ac(auStack_a0,DAT_6008499c);
      FUN_600d37ac(auStack_a0,DAT_600849a0);
      FUN_600d3b24(&local_a8);
    }
    thunk_EXT_FUN_0000ab28(&local_a8,iVar2);
    FUN_600840a4(param_1,&local_a8);
    thunk_EXT_FUN_0000ab28(&local_a8,iVar2);
    FUN_600840a4(param_1,&local_a8);
    *(undefined1 *)(param_1 + 0x59) = 1;
    FUN_600e002e(param_1);
    FUN_600e008a(param_1);
  }
  return;
}



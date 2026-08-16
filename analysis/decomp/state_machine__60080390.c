// 60080390  state_machine__60080390  size=138 bytes
// src: state_machine.cc
// --- callers ---
//   600df264 state_machine__600df264
// --- callees ---
//   600d37ac FUN_600d37ac
//   60101740 FUN_60101740


/* src: state_machine.cc */

undefined1 * state_machine__60080390(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  uint uStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [130];
  
  uVar2 = param_2 - 1;
  if (uVar2 < 3) {
    uVar4 = 1;
    uStack_a0 = 1;
    if (uVar2 < 2) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar4 = 0;
    if (param_2 == 5) {
      uStack_a0 = 1;
    }
    else {
      uStack_a0 = (uint)(param_2 == 0);
    }
    uVar3 = 0;
  }
  *(undefined2 *)(param_1 + 2) = 0;
  uVar1 = (undefined1)uStack_a0;
  if ((uVar2 < 3) && (uStack_a0 == 0)) {
    local_b0 = DAT_6008041c;
    local_ac = 0x58;
    local_a8 = local_9a;
    local_a4 = 0x80;
    local_9c = uVar1;
    local_9b = uVar1;
    local_9a[0] = uVar1;
    FUN_600d37ac(&local_a8,DAT_60080420);
    FUN_60101740(&local_b0);
  }
  *param_1 = uVar4;
  param_1[1] = uVar1;
  *(uint *)(param_1 + 4) = (uint)(param_2 != 1);
  *(undefined4 *)(param_1 + 8) = uVar3;
  return param_1;
}



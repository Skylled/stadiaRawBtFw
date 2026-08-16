// 60069964  adapter__60069964  size=196 bytes
// src: adapter.cc
// --- callers ---
// --- callees ---
//   600d37b8 FUN_600d37b8
//   60051120 FUN_60051120
//   6010165c FUN_6010165c
//   600d37ac FUN_600d37ac
//   600d8994 FUN_600d8994
//   60068f88 activation_sequence__60068f88


/* src: adapter.cc */

void adapter__60069964(int param_1,undefined4 *param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  
  iVar1 = FUN_600d8994(param_1 + 0x110);
  if (iVar1 == 0) {
    FUN_6010165c(0x28,DAT_60069a2c,0x335,DAT_60069a30,DAT_60069a28);
  }
  else {
    uVar2 = *param_2;
    uVar3 = param_2[1];
    uVar4 = param_2[2];
    uVar5 = param_2[3];
    uVar6 = param_2[4];
    uVar7 = *(uint *)(param_1 + 0x1e6c);
    if (uVar7 < 10) {
      local_b4 = CONCAT22(local_b4._2_2_,param_3);
      *(uint *)(param_1 + 0x1e6c) = uVar7 + 1;
      puVar8 = (undefined4 *)(param_1 + 0x1d18 + uVar7 * 0x20);
      local_9c = 0;
      uStack_98 = 0xffff;
      *puVar8 = local_b4;
      puVar8[1] = uVar2;
      puVar8[2] = uVar3;
      puVar8[3] = uVar4;
      puVar8[4] = uVar5;
      puVar8[5] = uVar6;
      puVar8[6] = 0;
      puVar8[7] = 0xffff;
      *(int *)(param_1 + 0x1e70) = *(int *)(param_1 + 0x1e70) + -1;
      local_b0 = uVar2;
      uStack_ac = uVar3;
      uStack_a8 = uVar4;
      local_a4 = uVar5;
      local_a0 = uVar6;
    }
    else {
      FUN_60051120(&local_b4,DAT_60069a2c,0x339,8);
      FUN_600d37ac(&uStack_ac,DAT_60069a34);
      FUN_600d37b8(&local_b4);
    }
    if (*(int *)(param_1 + 0x1e6c) == 1) {
      activation_sequence__60068f88(param_1 + 0x1d18,param_1 + 0x13c,param_1 + 0x1e74);
    }
  }
  return;
}



// 60068f04  activation_sequence__60068f04  size=124 bytes
// src: activation_sequence.cc
// --- callers ---
//   60068f88 activation_sequence__60068f88
// --- callees ---
//   60101740 FUN_60101740
//   60101b76 FUN_60101b76


/* src: activation_sequence.cc */

void activation_sequence__60068f04(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  int iStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [134];
  
  iStack_a0 = *(int *)(param_1 + 0x154);
  if (iStack_a0 == 0) {
    local_b0 = DAT_60068f80;
    local_9c = 0;
    local_ac = 0x87;
    local_a8 = local_9a;
    local_9b = 0;
    local_9a[0] = 0;
    local_a4 = 0x80;
    FUN_60101b76(&local_a8,DAT_60068f84);
    FUN_60101740(&local_b0);
  }
  iVar5 = *(int *)(param_1 + 0x154);
  iVar3 = iVar5 + -1;
  *(int *)(param_1 + 0x154) = iVar3;
  if (iVar3 != 0) {
    iVar8 = 0;
    for (iVar3 = (param_1 + iVar5 * 0x20) - (param_1 + 0x20) >> 5; 0 < iVar3; iVar3 = iVar3 + -1) {
      puVar7 = (undefined4 *)(param_1 + 0x20 + iVar8);
      puVar6 = (undefined4 *)(param_1 + iVar8);
      iVar8 = iVar8 + 0x20;
      uVar1 = puVar7[1];
      uVar2 = puVar7[2];
      uVar4 = puVar7[3];
      *puVar6 = *puVar7;
      puVar6[1] = uVar1;
      puVar6[2] = uVar2;
      puVar6[3] = uVar4;
      uVar1 = puVar7[5];
      uVar2 = puVar7[6];
      uVar4 = puVar7[7];
      puVar6[4] = puVar7[4];
      puVar6[5] = uVar1;
      puVar6[6] = uVar2;
      puVar6[7] = uVar4;
    }
  }
  return;
}



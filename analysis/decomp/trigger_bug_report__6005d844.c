// 6005d844  trigger_bug_report__6005d844  size=286 bytes
// src: trigger_bug_report.cc
// --- callers ---
//   6005e810 FUN_6005e810
// --- callees ---
//   600d3618 FUN_600d3618
//   600d7cc4 FUN_600d7cc4
//   600d7cdc FUN_600d7cdc
//   60061794 FUN_60061794
//   6013d310 thunk_EXT_FUN_0000b52a
//   60101b76 FUN_60101b76
//   60101740 FUN_60101740
//   6004cd58 FUN_6004cd58
//   600cc450 FUN_600cc450
//   6005d7c8 FUN_6005d7c8


/* src: trigger_bug_report.cc */

void trigger_bug_report__6005d844(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined1 *local_c8 [2];
  undefined1 auStack_c0 [16];
  undefined1 **local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  int iStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [134];
  
  if (param_1 == 0) {
    local_9c = 0;
    local_b0 = DAT_6005d964;
    local_9b = 0;
    local_ac = 0x44;
    local_a8 = local_9a;
    local_9a[0] = 0;
    local_a4 = 0x80;
    iStack_a0 = param_1;
    FUN_60101b76(&local_a8,DAT_6005d968);
    FUN_60101740(&local_b0);
  }
  uVar1 = FUN_600cc450(param_1,DAT_6005d970,DAT_6005d96c);
  uVar7 = DAT_6005d97c;
  uVar5 = DAT_6005d978;
  uVar1 = FUN_600cc450(uVar1,DAT_6005d974);
  uVar2 = FUN_600cc450(uVar1,DAT_6005d984,DAT_6005d980);
  iVar3 = FUN_600d7cc4();
  uVar1 = uVar5;
  if (iVar3 == 0) {
    uVar1 = uVar7;
  }
  uVar1 = FUN_600cc450(uVar2,DAT_6005d988,uVar1);
  iVar4 = FUN_600d7cdc();
  iVar3 = DAT_6005d98c;
  if (iVar4 == 0) {
    uVar5 = uVar7;
  }
  iVar4 = 0x14;
  uVar5 = FUN_600cc450(uVar1,DAT_6005d990,uVar5);
  uVar6 = FUN_60061794();
  iVar9 = 0;
  do {
    iVar8 = iVar9 + iVar4 >> 1;
    uVar10 = (uint)*(byte *)(iVar3 + iVar8 * 8);
    if (uVar6 == uVar10) {
      iVar8 = iVar8 * 8;
      goto LAB_6005d8e2;
    }
    if (uVar6 < uVar10) {
      iVar4 = iVar8 + -1;
    }
    else {
      iVar9 = iVar8 + 1;
    }
  } while (iVar9 < iVar4);
  if ((uVar6 < *(byte *)(iVar3 + iVar9 * 8)) && (iVar9 != 0)) {
    iVar9 = iVar9 + -1;
  }
  iVar8 = iVar9 << 3;
LAB_6005d8e2:
  uVar5 = FUN_600cc450(uVar5,DAT_6005d994,*(undefined4 *)(iVar3 + iVar8 + 4));
  uVar7 = FUN_6004cd58();
  FUN_6005d7c8(local_c8,DAT_6005d99c,0x10,DAT_6005d998,uVar7);
  uVar5 = FUN_600cc450(uVar5,DAT_6005d9a0,local_c8[0]);
  uVar7 = FUN_600d3618();
  FUN_6005d7c8(&local_b0,DAT_6005d99c,0x10,DAT_6005d998,uVar7);
  FUN_600cc450(uVar5,DAT_6005d9a4,local_b0);
  if (local_b0 != &local_a8) {
    thunk_EXT_FUN_0000b52a();
  }
  if (local_c8[0] != auStack_c0) {
    thunk_EXT_FUN_0000b52a();
  }
  return;
}



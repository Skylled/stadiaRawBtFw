// 6005e7e0  bug_report__6005e7e0  size=170 bytes
// src: bug_report.cc
// --- callers ---
//   6005f728 FUN_6005f728
// --- callees ---
//   60083730 FUN_60083730
//   60101740 FUN_60101740
//   6005e1c0 FUN_6005e1c0
//   60101b76 FUN_60101b76
//   600cc29c FUN_600cc29c


/* src: bug_report.cc */

void bug_report__6005e7e0(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 local_b4 [2];
  int local_b0;
  uint local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [138];
  
  iVar2 = FUN_6005e1c0(0);
  uVar3 = FUN_60083730(param_1,param_2,DAT_6005e80c);
  if (uVar3 != 0) {
    if (0x27f7 < (uint)(DAT_6005e390 + iVar2)) {
      local_b0 = DAT_6005e394;
      local_ac = 0x91;
      local_a8 = local_9a;
      local_a4 = 0x80;
      uStack_a0 = 0;
      local_9c = 0;
      local_9b = 0;
      local_9a[0] = 0;
      FUN_60101b76(&local_a8,DAT_6005e398);
      FUN_60101740(&local_b0);
    }
    *(short *)(iVar2 + -4) = (short)uVar3;
    local_ac = uVar3 & 0xffff;
    *(undefined1 *)(iVar2 + -8) = 0xd5;
    *(undefined1 *)(iVar2 + -7) = 0xba;
    *(undefined2 *)(iVar2 + -6) = 2;
    local_b4[0] = 0xffff;
    local_b0 = iVar2;
    uVar1 = FUN_600cc29c(local_b4,iVar2,local_ac);
    *(undefined2 *)(iVar2 + -2) = uVar1;
    return;
  }
  return;
}



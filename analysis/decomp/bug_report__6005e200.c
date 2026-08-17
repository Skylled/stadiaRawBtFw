// 6005e200  bug_report__6005e200  size=82 bytes
// src: bug_report.cc
// --- callers ---
//   6005e3d0 bug_report__6005e3d0
//   6005e734 FUN_6005e734
//   6005e58c bug_report__6005e58c
//   600d4664 FUN_600d4664
// --- callees ---
//   60101740 FUN_60101740
//   60101b76 FUN_60101b76


/* src: bug_report.cc */

uint bug_report__6005e200(byte *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 local_a8;
  undefined4 local_a4;
  byte *local_a0;
  undefined4 local_9c;
  uint uStack_98;
  byte local_94;
  byte local_93;
  byte local_92 [134];
  
  local_94 = *param_1;
  uStack_98 = (uint)local_94;
  if (uStack_98 == 0) {
    local_a8 = DAT_6005e254;
    local_a4 = 0x152;
    local_a0 = local_92;
    local_9c = 0x80;
    local_93 = local_94;
    local_92[0] = local_94;
    FUN_60101b76(&local_a0,DAT_6005e258);
    FUN_60101740(&local_a8);
  }
  uVar1 = (uint)*param_1;
  iVar2 = param_2 - uVar1 * (param_2 / uVar1);
  if (iVar2 != 0) {
    param_2 = (param_2 + uVar1) - iVar2;
  }
  return param_2;
}



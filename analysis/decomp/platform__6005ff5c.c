// 6005ff5c  platform__6005ff5c  size=164 bytes
// src: platform.h
// --- callers ---
//   60060040 FUN_60060040
// --- callees ---
//   60101b76 FUN_60101b76
//   60101740 FUN_60101740


/* src: platform.h */

int platform__6005ff5c(uint param_1,uint param_2)

{
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [134];
  
  if (param_1 == 0) {
    local_a4 = 0x26;
  }
  else {
    if (param_1 < 6) goto LAB_6005ff96;
    local_a4 = 0x27;
  }
  uStack_98 = 0;
  local_a0 = local_92;
  local_a8 = DAT_60060000;
  local_92[0] = 0;
  local_93 = 0;
  local_94 = 0;
  local_9c = 0x80;
  FUN_60101b76(&local_a0,DAT_60060004);
  FUN_60101740(&local_a8);
LAB_6005ff96:
  if (0x1f < param_2) {
    local_a8 = DAT_60060000;
    local_a4 = 0x29;
    local_a0 = local_92;
    local_9c = 0x80;
    uStack_98 = 0;
    local_94 = 0;
    local_93 = 0;
    local_92[0] = 0;
    FUN_60101b76(&local_a0,DAT_60060004);
    FUN_60101740(&local_a8);
  }
  return param_2 + (param_1 + 0x7ffffff) * 0x20;
}



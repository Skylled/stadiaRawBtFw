// 60058754  buffer__60058754  size=128 bytes
// src: buffer.h
// --- callers ---
//   600587e4 FUN_600587e4
// --- callees ---
//   6010162e FUN_6010162e
//   60058600 FUN_60058600
//   60101b76 FUN_60101b76
//   60101b4c FUN_60101b4c
//   600d3618 FUN_600d3618


/* src: buffer.h */

void buffer__60058754(undefined1 *param_1,undefined4 param_2)

{
  undefined *local_ac;
  undefined4 local_a8;
  undefined2 local_a4;
  undefined1 local_a2;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [130];
  
  *param_1 = 1;
  local_a0 = local_92;
  local_94 = 0;
  local_93 = 0;
  local_92[0] = 0;
  local_9c = 0x80;
  uStack_98 = 0;
  local_a2 = 0x14;
  local_ac = PTR_s_buffer_h_600587d8;
  local_a4 = 0x7b;
  FUN_60101b76(&local_a0,PTR_s___Dumping_log_entries___600587d4);
  local_a8 = FUN_600d3618();
  FUN_6010162e(param_2,&local_ac);
  FUN_60058600(param_1,PTR_LAB_600d35b0_1_600587dc,param_2);
  FUN_60101b4c(&local_a0);
  FUN_60101b76(&local_a0,PTR_s___Log_dump_completed___600587e0);
  local_a8 = FUN_600d3618();
  FUN_6010162e(param_2,&local_ac);
  *param_1 = 0;
  return;
}



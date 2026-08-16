// 60058574  system_tasks__60058574  size=100 bytes
// src: system_tasks.cc
// --- callers ---
//   600cbdd4 init__600cbdd4
// --- callees ---
//   60101b76 FUN_60101b76
//   60101740 FUN_60101740
//   6010177a FUN_6010177a
//   600cbe5c FUN_600cbe5c


/* src: system_tasks.cc */

void system_tasks__60058574(void)

{
  int iVar1;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 *local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a [130];
  
  FUN_6010177a(DAT_600585dc,DAT_600585d8,4);
  FUN_6010177a(DAT_600585e4,DAT_600585e0,5);
  local_a0 = DAT_600585e8;
  local_9c = DAT_600585ec;
  iVar1 = FUN_600cbe5c(DAT_600585dc,DAT_600585e8,DAT_600585ec);
  if (iVar1 == -1) {
    local_a0 = DAT_600585f0;
    local_9c = 0x5d;
    local_98 = local_8a;
    local_94 = 0x80;
    uStack_90 = 0;
    local_8c = 0;
    local_8b = 0;
    local_8a[0] = 0;
    FUN_60101b76(&local_98,DAT_600585f4);
    FUN_60101740(&local_a0);
  }
  return;
}



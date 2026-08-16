// 60074e6c  audio_states__60074e6c  size=80 bytes
// src: audio_states.cc
// --- callers ---
//   600da44c FUN_600da44c
//   600da460 FUN_600da460
// --- callees ---
//   60101b76 FUN_60101b76
//   601016f0 FUN_601016f0
//   6013d3c8 thunk_EXT_FUN_00001680


/* src: audio_states.cc */

undefined4 * audio_states__60074e6c(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [134];
  
  *param_1 = DAT_60074ebc;
  uVar1 = DAT_60074ec0;
  local_a0 = local_92;
  local_9c = 0x80;
  uStack_98 = 0;
  local_94 = 0;
  local_93 = 0;
  local_92[0] = 0;
  FUN_60101b76(&local_a0,DAT_60074ec4);
  FUN_601016f0(0x14,uVar1,0x3d,&local_a0);
  thunk_EXT_FUN_00001680(param_1 + 0x17);
  return param_1;
}



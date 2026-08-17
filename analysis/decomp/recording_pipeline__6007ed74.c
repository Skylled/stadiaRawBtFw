// 6007ed74  recording_pipeline__6007ed74  size=50 bytes
// src: recording_pipeline.cc
// --- callers ---
//   60075088 audio_states__60075088
// --- callees ---
//   6007ec78 FUN_6007ec78
//   60101b76 FUN_60101b76
//   60051120 FUN_60051120
//   600d37b8 FUN_600d37b8


/* src: recording_pipeline.cc */

undefined4 * recording_pipeline__6007ed74(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 auStack_a4 [8];
  undefined1 auStack_9c [148];
  
  *param_1 = param_2;
  uVar1 = FUN_6007ec78();
  if ((uVar1 & 0xff) != 0) {
    FUN_60051120(auStack_a4,DAT_6007eda8,0x1e,uVar1);
    FUN_60101b76(auStack_9c,DAT_6007edac);
    FUN_600d37b8(auStack_a4);
  }
  return param_1;
}



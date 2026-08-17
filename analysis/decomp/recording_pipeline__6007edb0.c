// 6007edb0  recording_pipeline__6007edb0  size=58 bytes
// src: recording_pipeline.cc
// --- callers ---
// --- callees ---
//   6007ec78 FUN_6007ec78
//   60101b76 FUN_60101b76
//   60051120 FUN_60051120
//   600d37b8 FUN_600d37b8


/* src: recording_pipeline.cc */

int recording_pipeline__6007edb0(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 auStack_a4 [8];
  undefined1 auStack_9c [148];
  
  DataMemoryBarrier(0x1b);
  *(undefined4 *)(param_1 + 4) = param_2;
  DataMemoryBarrier(0x1b);
  uVar1 = FUN_6007ec78();
  if ((uVar1 & 0xff) != 0) {
    FUN_60051120(auStack_a4,DAT_6007edec,0x25,uVar1);
    FUN_60101b76(auStack_9c,DAT_6007edf0);
    FUN_600d37b8(auStack_a4);
  }
  return param_1;
}



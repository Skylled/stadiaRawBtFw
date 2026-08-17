// 6006b630  sound_codec_wm8904__6006b630  size=116 bytes
// src: sound_codec_wm8904.cc
// --- callers ---
//   60074658 timer__60074658
// --- callees ---
//   60101b76 FUN_60101b76
//   600d37b8 FUN_600d37b8
//   600d903e FUN_600d903e
//   60051120 FUN_60051120
//   6010165c FUN_6010165c


/* src: sound_codec_wm8904.cc */

undefined1 sound_codec_wm8904__6006b630(int param_1)

{
  uint uVar1;
  short local_ae;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [144];
  undefined1 local_14;
  
  if (*(char *)(param_1 + 0xc) == '\0') {
    local_ae = 0;
    uVar1 = FUN_600d903e(param_1,0,&local_ae,200);
    if ((uVar1 & 0xff) == 0) {
      if (local_ae == -0x76fc) {
        FUN_6010165c(10,DAT_6006b6a4,0xcd,DAT_6006b6b0);
        *(undefined1 *)(param_1 + 0xc) = 1;
        local_14 = 0;
      }
      else {
        FUN_6010165c(0x1e,DAT_6006b6a4,0xc9,DAT_6006b6ac);
        local_14 = 5;
      }
    }
    else {
      FUN_60051120(auStack_ac,DAT_6006b6a4,0xc5,uVar1);
      FUN_60101b76(auStack_a4,DAT_6006b6a8);
      FUN_600d37b8(auStack_ac);
    }
  }
  else {
    local_14 = 0;
  }
  return local_14;
}



// 6006b4dc  sound_codec_wm8904__6006b4dc  size=68 bytes
// src: sound_codec_wm8904.cc
// --- callers ---
//   6006b528 FUN_6006b528
// --- callees ---
//   6013cef8 thunk_EXT_FUN_0000737c
//   600d8fa6 FUN_600d8fa6
//   6010165c FUN_6010165c


/* src: sound_codec_wm8904.cc */

undefined4 sound_codec_wm8904__6006b4dc(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    uVar1 = FUN_600d8fa6(param_2,(char)param_1[1],*(undefined2 *)((int)param_1 + 6),200,param_1);
  }
  else {
    if (iVar2 == 1) {
      thunk_EXT_FUN_0000737c((short)param_1[1]);
    }
    else {
      if (iVar2 != 2) {
        return 0xd;
      }
      FUN_6010165c(0x14,DAT_6006b520,0x3f,DAT_6006b524,param_1[1],param_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}



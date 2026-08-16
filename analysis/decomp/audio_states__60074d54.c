// 60074d54  audio_states__60074d54  size=44 bytes
// src: audio_states.cc
// --- callers ---
// --- callees ---
//   60079c50 FUN_60079c50
//   6013d3c8 thunk_EXT_FUN_00001680
//   6010165c FUN_6010165c
//   600da590 FUN_600da590


/* src: audio_states.cc */

void audio_states__60074d54(int param_1,undefined4 param_2)

{
  int iVar1;
  int local_10;
  undefined4 uStack_c;
  
  local_10 = param_1;
  uStack_c = param_2;
  FUN_60079c50(&local_10);
  iVar1 = local_10;
  thunk_EXT_FUN_00001680(&uStack_c);
  if (iVar1 == 0) {
    FUN_6010165c(0x28,DAT_60074d84,799,DAT_60074d80);
  }
  else {
    FUN_600da590(DAT_60074d88);
  }
  return;
}



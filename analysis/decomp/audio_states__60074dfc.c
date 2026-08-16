// 60074dfc  audio_states__60074dfc  size=56 bytes
// src: audio_states.cc
// --- callers ---
// --- callees ---
//   6010165c FUN_6010165c
//   60074b6c FUN_60074b6c
//   60079c50 FUN_60079c50
//   6013d3c8 thunk_EXT_FUN_00001680


/* src: audio_states.cc */

void audio_states__60074dfc(int param_1,undefined4 param_2)

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
    FUN_6010165c(0x14,DAT_60074e38,0x327,DAT_60074e34);
  }
  else {
    FUN_60079c50(&local_10);
    FUN_60074b6c(local_10);
    thunk_EXT_FUN_00001680(&uStack_c);
  }
  return;
}



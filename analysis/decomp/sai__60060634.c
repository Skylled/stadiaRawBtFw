// 60060634  sai__60060634  size=100 bytes
// src: sai.cc
// --- callers ---
//   6007e794 FUN_6007e794
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6010165c FUN_6010165c
//   600cf9c6 FUN_600cf9c6
//   60060500 FUN_60060500


/* src: sai.cc */

void sai__60060634(undefined4 *param_1)

{
  int extraout_r1;
  
  if (*(char *)(param_1 + 0x3e) == '\0') {
    FUN_6010165c(0x1e,DAT_60060664,0xb2,DAT_60060660);
    return;
  }
  FUN_60060500(*(undefined1 *)*param_1,param_1 + 4);
  FUN_600cf9c6();
  thunk_EXT_FUN_0000b5ba(extraout_r1 + 0x14,0,0xa0);
  thunk_EXT_FUN_0000b5ba(extraout_r1 + 0xb4,0,0x20);
  thunk_EXT_FUN_0000b5ba(extraout_r1 + 0xd4,0,0x10);
  *(undefined1 *)(extraout_r1 + 0xe4) = 0;
  *(undefined1 *)(extraout_r1 + 0xe5) = 0;
  return;
}



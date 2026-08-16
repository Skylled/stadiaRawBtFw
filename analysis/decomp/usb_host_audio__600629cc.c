// 600629cc  usb_host_audio__600629cc  size=60 bytes
// src: usb_host_audio.cc
// --- callers ---
// --- callees ---
//   6010165c FUN_6010165c
//   6013cf40 thunk_EXT_FUN_00007d10
//   60101832 FUN_60101832


/* src: usb_host_audio.cc */

void usb_host_audio__600629cc(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_4 == 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x10c) + 3) = *(undefined1 *)(*(int *)(param_1 + 0x10c) + 2);
  }
  else {
    FUN_6010165c(0x1e,DAT_60062a0c,0x163,DAT_60062a08);
    *(undefined1 *)(*(int *)(param_1 + 0x10c) + 2) = *(undefined1 *)(*(int *)(param_1 + 0x10c) + 3);
  }
  FUN_60101832(*(int *)(param_1 + 0x10c) + 4);
  thunk_EXT_FUN_00007d10(param_1 + 0x974);
  return;
}



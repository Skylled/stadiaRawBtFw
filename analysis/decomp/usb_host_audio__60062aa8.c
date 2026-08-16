// 60062aa8  usb_host_audio__60062aa8  size=98 bytes
// src: usb_host_audio.cc
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   6010165c FUN_6010165c
//   60062a10 usb_host_audio__60062a10
//   60062a74 usb_host_audio__60062a74


/* src: usb_host_audio.cc */

void usb_host_audio__60062aa8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_60062b0c;
  FUN_6010165c(0x14,DAT_60062b0c,0x464,DAT_60062b10);
  usb_host_audio__60062a10(param_1);
  usb_host_audio__60062a74(*(undefined1 *)(param_1 + 0x12d));
  FUN_6010165c(0x14,uVar1,0x467,DAT_60062b14);
  usb_host_audio__60062a10(param_1 + 100);
  usb_host_audio__60062a74(*(undefined1 *)(param_1 + 0x185));
  FUN_6010165c(0x14,uVar1,0x46a,DAT_60062b18);
  usb_host_audio__60062a10(param_1 + 200);
  usb_host_audio__60062a74(*(undefined1 *)(param_1 + 0x1dd));
  return;
}



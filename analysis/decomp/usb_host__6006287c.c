// 6006287c  usb_host__6006287c  size=64 bytes
// src: usb_host.cc
// --- callers ---
//   60060fe8 usb_device__60060fe8
// --- callees ---
//   6006525c usb_host_worker__6006525c
//   600d37b8 FUN_600d37b8
//   60057ee4 FUN_60057ee4
//   60051120 FUN_60051120
//   60101b76 FUN_60101b76


/* src: usb_host.cc */

undefined1 usb_host__6006287c(int param_1)

{
  int iVar1;
  undefined1 auStack_a4 [8];
  undefined1 auStack_9c [144];
  undefined1 local_c;
  
  iVar1 = FUN_60057ee4(2,param_1 + 0x9c,DAT_600628bc);
  if (iVar1 == 0) {
    usb_host_worker__6006525c();
    local_c = 0;
  }
  else {
    FUN_60051120(auStack_a4,DAT_600628c0,0x77,2);
    FUN_60101b76(auStack_9c,DAT_600628c4);
    FUN_600d37b8(auStack_a4);
  }
  return local_c;
}



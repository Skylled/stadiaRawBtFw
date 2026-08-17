// 60060f28  usb_device__60060f28  size=82 bytes
// src: usb_device.cc
// --- callers ---
//   60074658 timer__60074658
// --- callees ---
//   601016f0 FUN_601016f0
//   60101b76 FUN_60101b76
//   6009267c FUN_6009267c


/* src: usb_device.cc */

void usb_device__60060f28(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined1 *local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a [134];
  
  *(undefined4 *)(param_1 + 0x90) = 1;
  cVar2 = FUN_6009267c(1);
  uVar1 = DAT_60060f7c;
  if (cVar2 != '\0') {
    local_98 = local_8a;
    local_94 = 0x80;
    uStack_90 = 0;
    local_8c = 0;
    local_8b = 0;
    local_8a[0] = 0;
    FUN_60101b76(&local_98,DAT_60060f80);
    FUN_601016f0(0x28,uVar1,0xd9,&local_98);
  }
  return;
}



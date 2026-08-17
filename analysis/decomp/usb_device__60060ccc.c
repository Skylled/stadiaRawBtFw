// 60060ccc  usb_device__60060ccc  size=110 bytes
// src: usb_device.cc
// --- callers ---
//   600718e8 FUN_600718e8
// --- callees ---
//   600524d0 FUN_600524d0
//   600d16c4 FUN_600d16c4
//   60101740 FUN_60101740
//   60101b76 FUN_60101b76
//   60052624 FUN_60052624


/* src: usb_device.cc */

void usb_device__60060ccc(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 local_ac;
  undefined1 local_aa;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [130];
  
  iVar2 = DAT_60060d44;
  iVar1 = DAT_60060d40;
  local_ac = 0x306;
  local_aa = 3;
  FUN_60052624(0,DAT_60060d3c);
  FUN_600524d0(0,DAT_60060d3c);
  *(int *)(iVar1 + 0x10) = iVar2;
  FUN_600d16c4(*(undefined1 *)(param_1 + 0x10),DAT_60060d48,&local_ac);
  if (*(int *)(iVar1 + 0x10) != iVar2) {
    local_a8 = DAT_60060d4c;
    local_a4 = 0x6e;
    local_a0 = local_92;
    local_9c = 0x80;
    uStack_98 = 0;
    local_94 = 0;
    local_93 = 0;
    local_92[0] = 0;
    FUN_60101b76(&local_a0,DAT_60060d50);
    FUN_60101740(&local_a8);
  }
  return;
}



// 60060bf4  usb_device__60060bf4  size=114 bytes
// src: usb_device.cc
// --- callers ---
// --- callees ---
//   60101740 FUN_60101740
//   60101b76 FUN_60101b76
//   6004cb28 FUN_6004cb28


/* src: usb_device.cc */

void usb_device__60060bf4(int param_1,int *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  undefined4 local_9c;
  int iStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [130];
  
  if (*param_2 == 0) {
    local_a8 = DAT_60060c68;
    local_94 = 0;
    local_a4 = 0x28;
    local_a0 = local_92;
    local_93 = 0;
    local_92[0] = 0;
    local_9c = 0x80;
    iStack_98 = *param_2;
    FUN_60101b76(&local_a0,DAT_60060c6c);
    FUN_60101740(&local_a8);
  }
  pcVar2 = (char *)*param_2;
  cVar1 = FUN_6004cb28(param_1);
  pcVar3 = (char *)(param_1 + -1);
  pcVar2[1] = '\x03';
  *pcVar2 = (cVar1 + '\x01') * '\x02';
  param_2[1] = 2;
  while( true ) {
    pcVar3 = pcVar3 + 1;
    if (*pcVar3 == '\0') break;
    pcVar2[2] = *pcVar3;
    pcVar2[3] = '\0';
    param_2[1] = param_2[1] + 2;
    pcVar2 = pcVar2 + 2;
  }
  return;
}



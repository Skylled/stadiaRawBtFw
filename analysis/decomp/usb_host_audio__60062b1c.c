// 60062b1c  usb_host_audio__60062b1c  size=110 bytes
// src: usb_host_audio.cc
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   6010165c FUN_6010165c
//   600d571c FUN_600d571c
//   60055ad0 FUN_60055ad0


/* src: usb_host_audio.cc */

void usb_host_audio__60062b1c(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  *(char *)(param_1 + 0x104) = (char)param_2;
  if (param_2 == 3) {
    uVar3 = 0x84;
  }
  else if (param_2 == 4) {
    uVar3 = 0x81;
  }
  else if (param_2 == 2) {
    uVar3 = 0x83;
  }
  else {
    uVar3 = 0x82;
  }
  iVar1 = FUN_60055ad0(*(undefined4 *)(*(int *)(param_1 + 0x970) + 0x20),
                       **(undefined1 **)(param_1 + 0x108),DAT_60062b90,uVar3,DAT_60062b8c,param_1,
                       param_3);
  if (iVar1 == 0) {
    return;
  }
  puVar2 = PTR_s_speaker_60062b98;
  if (**(int **)(param_1 + 0x970) != 0) {
    puVar2 = PTR_DAT_60062b94;
  }
  FUN_6010165c(0x28,PTR_s_usb_host_audio_cc_60062b9c,0x43e,
               PTR_s_Feature_unit_request_error_on__s_60062ba0,puVar2,uVar3);
  FUN_600d571c(param_1);
  return;
}



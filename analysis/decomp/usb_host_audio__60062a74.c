// 60062a74  usb_host_audio__60062a74  size=36 bytes
// src: usb_host_audio.cc
// --- callers ---
//   60062aa8 usb_host_audio__60062aa8
// --- callees ---
//   6010165c FUN_6010165c


/* src: usb_host_audio.cc */

void usb_host_audio__60062a74(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_60062a98;
  if (param_1 == 0) {
    puVar1 = PTR_s_False_60062a9c;
  }
  FUN_6010165c(0x14,PTR_s_usb_host_audio_cc_60062aa0,0x460,PTR_s_Mute_change_supported___s_60062aa4,
               puVar1,param_2,param_3);
  return;
}



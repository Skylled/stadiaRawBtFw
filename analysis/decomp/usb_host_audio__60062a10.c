// 60062a10  usb_host_audio__60062a10  size=78 bytes
// src: usb_host_audio.cc
// --- callers ---
//   60062aa8 usb_host_audio__60062aa8
// --- callees ---
//   6010165c FUN_6010165c


/* src: usb_host_audio.cc */

void usb_host_audio__60062a10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_60062a64;
  if (*(char *)(param_1 + 1) == '\0') {
    puVar1 = PTR_s_False_60062a60;
  }
  FUN_6010165c(0x14,PTR_s_usb_host_audio_cc_60062a68,0x455,
               PTR_s_Volume_change_supported___s_60062a6c,puVar1,param_2,param_3,param_4);
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_6010165c(0x14,PTR_s_usb_host_audio_cc_60062a68,0x45b,
                 PTR_s_Min___d__Max____d__Res____d__Cur_60062a70,(int)*(short *)(param_1 + 8),
                 (int)*(short *)(param_1 + 10),(int)*(short *)(param_1 + 6),
                 (int)*(short *)(param_1 + 0xc));
  }
  return;
}



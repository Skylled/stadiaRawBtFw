// 6007a254  usb_audio_receive__6007a254  size=92 bytes
// src: usb_audio_receive.cc
// --- callers ---
// --- callees ---
//   600cc160 FUN_600cc160
//   601017b4 FUN_601017b4
//   6010165c FUN_6010165c
//   600db8d8 FUN_600db8d8
//   6005e12c FUN_6005e12c


/* src: usb_audio_receive.cc */

undefined4 *
usb_audio_receive__6007a254
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  char cVar4;
  
  puVar2 = PTR_PTR_6007a2b0;
  *param_1 = PTR_PTR_6007a2b0;
  puVar1 = param_1 + 1;
  *puVar1 = puVar2 + 0x20;
  puVar3 = PTR_s_usb_audio_receive_cc_6007a2b8;
  puVar2 = PTR_s_Timeout_waiting_for_the_USB_audi_6007a2b4;
  if (param_1[0x17] != 0) {
    FUN_600db8d8(puVar1);
    while (cVar4 = FUN_601017b4(puVar1,1000), cVar4 != '\0') {
      FUN_6010165c(0x28,puVar3,0x34,puVar2,param_4);
    }
  }
  if (param_1[600] != 0) {
    FUN_6005e12c();
  }
  if (param_1[0x1b] != 0) {
    FUN_6005e12c();
  }
  param_1[1] = PTR_DAT_6007a2bc;
  FUN_600cc160(puVar1);
  return param_1;
}



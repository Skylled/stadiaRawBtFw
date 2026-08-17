// 6007ad34  usb_audio_send__6007ad34  size=230 bytes
// src: usb_audio_send.cc
// --- callers ---
//   60075088 audio_states__60075088
// --- callees ---
//   601017e8 FUN_601017e8
//   6010177a FUN_6010177a
//   6005c44c FUN_6005c44c
//   6013d378 thunk_EXT_FUN_0000b532
//   601017fc FUN_601017fc
//   6010165c FUN_6010165c


/* src: usb_audio_send.cc */

undefined4 * usb_audio_send__6007ad34(undefined4 *param_1)

{
  int *piVar1;
  undefined *puVar2;
  undefined *puVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  piVar1 = DAT_6007ae1c;
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  if (*DAT_6007ae1c == 0) {
    puVar5 = (undefined4 *)thunk_EXT_FUN_0000b532(0x1128);
    puVar2 = PTR_DAT_6007ae28;
    puVar5[0x16] = 0;
    *puVar5 = puVar2;
    puVar5[1] = PTR_DAT_6007ae2c;
    FUN_601017fc();
    puVar2 = PTR_LAB_6007ae30;
    *(undefined1 *)(puVar5 + 0x19) = 1;
    *puVar5 = puVar2;
    puVar5[0x2e] = 0;
    puVar5[1] = puVar2 + 0x18;
    puVar5[0x17] = 0;
    puVar5[0x18] = 0;
    FUN_601017e8(puVar5 + 0x1a);
    *(undefined1 *)(puVar5 + 0x214) = 1;
    puVar5[0x31] = (int)puVar5 + 0xce;
    puVar5[0x32] = 0x3c0;
    puVar5[0x248] = puVar5 + 0x24a;
    puVar5[0x249] = 0x200;
    puVar5[0x18] = puVar5 + 0x215;
    puVar2 = PTR_LAB_6007ae34;
    *puVar5 = PTR_LAB_6007ae34;
    puVar5[0x2f] = 0;
    puVar5[0x30] = 0;
    puVar5[1] = puVar2 + 0x18;
    puVar6 = (undefined4 *)thunk_EXT_FUN_0000b532(0x14);
    *puVar6 = PTR_PTR_6007ae38;
    puVar3 = PTR_s_Usb_Audio_Sender_6007ae40;
    puVar2 = PTR_LAB_6007ac8c_1_6007ae3c;
    puVar6[1] = 1;
    puVar6[2] = 1;
    puVar6[3] = puVar2;
    puVar6[4] = puVar5;
    cVar4 = FUN_6010177a(puVar5 + 1,puVar3,0x1b);
    if (cVar4 != '\0') {
      FUN_6005c44c(puVar6);
      puVar5 = (undefined4 *)0x0;
      puVar6 = (undefined4 *)0x0;
    }
    DataMemoryBarrier(0x1b);
    *piVar1 = (int)puVar5;
    DataMemoryBarrier(0x1b);
    *param_1 = puVar5;
    param_1[1] = puVar6;
  }
  else {
    FUN_6010165c(0x28,PTR_s_usb_audio_send_cc_6007ae24,0x5d,
                 PTR_s_USB_Audio_send_task_already_acti_6007ae20);
    *param_1 = 0;
    param_1[1] = 0;
  }
  return param_1;
}



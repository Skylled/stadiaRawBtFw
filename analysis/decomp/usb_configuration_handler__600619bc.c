// 600619bc  usb_configuration_handler__600619bc  size=112 bytes
// src: usb_configuration_handler.cc
// --- callers ---
// --- callees ---
//   6005bdac FUN_6005bdac
//   6010165c FUN_6010165c
//   600dffe8 FUN_600dffe8


/* src: usb_configuration_handler.cc */

undefined4 usb_configuration_handler__600619bc(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_6005bdac();
  iVar1 = FUN_600dffe8(iVar1 + 0x448,7);
  if (iVar1 == 0) {
    if (*(char *)(DAT_60061a38 + 0x4344) == '\0') {
      *param_2 = DAT_60061a4c;
      uVar2 = 0x50;
    }
    else if (*(char *)(DAT_60061a38 + 0x4345) == '\0') {
      FUN_6010165c(0x14,DAT_60061a30,0x36,DAT_60061a44);
      *param_2 = DAT_60061a48;
      uVar2 = 0xcc;
    }
    else {
      FUN_6010165c(0x14,DAT_60061a30,0x30,DAT_60061a3c);
      *param_2 = DAT_60061a40;
      uVar2 = 0x11f;
    }
  }
  else {
    FUN_6010165c(0x14,DAT_60061a30,0x28,DAT_60061a2c);
    *param_2 = DAT_60061a34;
    uVar2 = 0x28;
  }
  param_2[1] = uVar2;
  return 0;
}



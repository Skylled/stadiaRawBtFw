// 60060f84  usb_device__60060f84  size=64 bytes
// src: usb_device.cc
// --- callers ---
//   60060fe8 usb_device__60060fe8
// --- callees ---
//   600d105e FUN_600d105e
//   6010165c FUN_6010165c
//   600550e4 FUN_600550e4
//   601017fc FUN_601017fc


/* src: usb_device.cc */

undefined4
usb_device__60060f84(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600550e4(*(undefined1 *)(param_1 + 0x10),param_1 + 4,param_1 + 0x98,param_4,param_4);
  if (iVar1 == 0) {
    FUN_601017fc(param_1 + 0xac);
    *(undefined4 *)(param_1 + 0xa0) = DAT_60060fcc;
    *(int *)(param_1 + 0xa4) = param_1;
    FUN_600d105e(*(undefined4 *)(param_1 + 0x98));
    uVar2 = 0;
  }
  else {
    FUN_6010165c(0x28,DAT_60060fc8,0xe1,DAT_60060fc4);
    uVar2 = 2;
  }
  return uVar2;
}



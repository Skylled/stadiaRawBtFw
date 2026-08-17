// 60060fe8  usb_device__60060fe8  size=208 bytes
// src: usb_device.cc
// --- callers ---
//   600d4e86 FUN_600d4e86
//   60064924 FUN_60064924
// --- callees ---
//   600d5456 FUN_600d5456
//   6005f534 FUN_6005f534
//   60060f84 usb_device__60060f84
//   600d1066 FUN_600d1066
//   60060c70 FUN_60060c70
//   6010165c FUN_6010165c
//   600551b8 FUN_600551b8
//   6006287c usb_host__6006287c
//   600d4e4c FUN_600d4e4c


/* src: usb_device.cc */

void usb_device__60060fe8(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((*(int *)(param_1 + 0x90) != param_2) && (*(int *)(param_1 + 0x90) != 0)) {
    FUN_60060c70(param_1 + 0x14);
    if (*(int *)(param_1 + 0x90) == 2) {
      FUN_600d1066(*(undefined4 *)(param_1 + 0x98));
      FUN_600551b8(*(undefined1 *)(param_1 + 0x10));
    }
    else if (*(int *)(param_1 + 0x90) == 3) {
      FUN_600d5456(param_1);
    }
    *(undefined4 *)(param_1 + 0x90) = 1;
    *(undefined1 *)(param_1 + 0x94) = 0;
    if (param_2 == 2) {
      cVar1 = usb_device__60060f84(param_1);
      if (cVar1 != '\0') {
        uVar2 = 0x11d;
        uVar3 = DAT_600610b8;
LAB_6006103e:
        FUN_6010165c(0x28,DAT_600610bc,uVar2,uVar3);
        return;
      }
      FUN_600d4e4c(param_1 + 0x114,1);
      uVar2 = 0x121;
      uVar3 = DAT_600610c0;
    }
    else if (param_2 == 3) {
      cVar1 = usb_host__6006287c(param_1);
      if (cVar1 != '\0') {
        uVar2 = 0x124;
        uVar3 = DAT_600610c4;
        goto LAB_6006103e;
      }
      FUN_600d4e4c(param_1 + 0x114);
      uVar2 = 0x128;
      uVar3 = DAT_600610c8;
    }
    else {
      FUN_600d4e4c(param_1 + 0x114,2);
      uVar2 = 299;
      uVar3 = DAT_600610cc;
    }
    FUN_6010165c(0x14,DAT_600610bc,uVar2,uVar3);
    *(int *)(param_1 + 0x90) = param_2;
    if (param_2 != 1) {
      FUN_6005f534(param_1 + 0x14);
    }
  }
  return;
}



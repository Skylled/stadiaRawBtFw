// 6007a040  usb_audio_receive__6007a040  size=166 bytes
// src: usb_audio_receive.cc
// --- callers ---
//   6007a62c usb_audio_receive__6007a62c
// --- callees ---
//   6010165c FUN_6010165c
//   60061fc0 usb_device_audio__60061fc0
//   60079f1c usb_audio_receive__60079f1c
//   600d5240 FUN_600d5240


/* src: usb_audio_receive.cc */

uint usb_audio_receive__6007a040(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  
  uVar1 = usb_audio_receive__60079f1c();
  if (*(char *)(param_1 + 0x19d7) == '\0') {
    iVar2 = FUN_600d5240(param_1 + 0x70,5);
    if ((iVar2 == 0) && (0xcc0 < uVar1 - 0x180)) {
      if (uVar1 < 0x900) {
        uVar4 = 1;
      }
      else {
        uVar4 = 0xff;
      }
      *(undefined1 *)(param_1 + 0x19d7) = uVar4;
      goto LAB_6007a076;
    }
  }
  else {
LAB_6007a076:
    if (*(char *)(param_1 + 0x19d7) < '\0') {
      uVar3 = DAT_6007a0ac;
      if (0x900 < uVar1) goto LAB_60079ff0;
    }
    else {
      if (*(char *)(param_1 + 0x19d7) == '\0') goto LAB_6007a08a;
      uVar3 = DAT_6007a0a8;
      if (uVar1 < 0x900) goto LAB_60079ff0;
    }
    *(undefined1 *)(param_1 + 0x19d7) = 0;
  }
LAB_6007a08a:
  uVar3 = 0x60000;
LAB_60079ff0:
  if ((DAT_6007a030 & uVar3) == 0) {
    *(uint *)(param_1 + 0x19f4) = uVar3;
    uVar1 = usb_device_audio__60061fc0(DAT_6007a034,&stack0xfffffff4,4,0x19f4,param_1);
    if ((uVar1 & 0xff) == 0xe) {
      FUN_6010165c(0x14,DAT_6007a03c,0x14f,DAT_6007a038);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}



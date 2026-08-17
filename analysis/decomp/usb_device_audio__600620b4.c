// 600620b4  usb_device_audio__600620b4  size=102 bytes
// src: usb_device_audio.cc
// --- callers ---
//   6007a118 usb_audio_receive__6007a118
// --- callees ---
//   60101ba2 FUN_60101ba2
//   600d4946 FUN_600d4946
//   600d5240 FUN_600d5240
//   60050c18 FUN_60050c18
//   600d0624 FUN_600d0624
//   600d53ae FUN_600d53ae
//   600d37ac FUN_600d37ac
//   600d3b3a FUN_600d3b3a


/* src: usb_device_audio.cc */

undefined4 usb_device_audio__600620b4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_a0;
  undefined4 local_9c;
  int local_98;
  int local_94;
  int iStack_90;
  
  iVar1 = FUN_600d5240(param_1 + 0xaf,5);
  if (iVar1 == 0) {
    uVar2 = 10;
  }
  else {
    uVar3 = FUN_600d0624(*(undefined4 *)(param_1 + 4),5);
    uVar2 = 0;
    if (uVar3 != 0) {
      local_a0 = DAT_6006211c;
      local_9c = 0x1cc;
      FUN_600d3b3a(&local_98);
      FUN_600d37ac(&local_98,DAT_60062120);
      uVar2 = FUN_60050c18(uVar3 & 0xff,0,iStack_90 + local_98,local_94 - iStack_90);
      FUN_60101ba2(&local_98,uVar2);
      FUN_600d53ae(&local_a0);
      uVar2 = FUN_600d4946(uVar3);
    }
  }
  return uVar2;
}



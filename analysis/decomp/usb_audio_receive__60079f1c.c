// 60079f1c  usb_audio_receive__60079f1c  size=122 bytes
// src: usb_audio_receive.cc
// --- callers ---
//   6007a62c usb_audio_receive__6007a62c
//   6007a2c0 frames__6007a2c0
//   6007a040 usb_audio_receive__6007a040
// --- callees ---
//   600d5240 FUN_600d5240
//   601016f0 FUN_601016f0
//   600d37ac FUN_600d37ac


/* src: usb_audio_receive.cc */

uint usb_audio_receive__60079f1c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [130];
  
  uVar3 = *(uint *)(param_1 + 0x9c0) & 0xffffffe0;
  iVar2 = FUN_600d5240(param_1 + 0x70,5);
  if ((iVar2 == 0) || (0x8ff < uVar3)) {
    iVar2 = FUN_600d5240(param_1 + 0x70,5);
    uVar1 = DAT_60079f98;
    if (iVar2 != 0) {
      local_a0 = local_92;
      local_9c = 0x80;
      uStack_98 = 0;
      local_94 = 0;
      local_93 = 0;
      local_92[0] = 0;
      FUN_600d37ac(&local_a0,DAT_60079f9c);
      FUN_601016f0(0x14,uVar1,0x82,&local_a0);
    }
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x70) = 0;
    DataMemoryBarrier(0x1b);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



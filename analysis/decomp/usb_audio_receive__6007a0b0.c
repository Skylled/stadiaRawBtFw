// 6007a0b0  usb_audio_receive__6007a0b0  size=86 bytes
// src: usb_audio_receive.cc
// --- callers ---
//   6007a62c usb_audio_receive__6007a62c
// --- callees ---
//   600d37b8 FUN_600d37b8
//   6010165c FUN_6010165c
//   600d3618 FUN_600d3618
//   60051120 FUN_60051120
//   600d52f0 FUN_600d52f0
//   600d37ac FUN_600d37ac


/* src: usb_audio_receive.cc */

uint usb_audio_receive__6007a0b0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [152];
  
  uVar1 = FUN_600d52f0(DAT_6007a108);
  if ((uVar1 & 0xff) == 0xe) {
    FUN_6010165c(0x14,PTR_s_usb_audio_receive_cc_6007a110,0xf7,
                 PTR_s_UsbAudioReceiverTask_finished_re_6007a10c);
  }
  else if ((uVar1 & 0xff) != 0) {
    FUN_60051120(auStack_ac,PTR_s_usb_audio_receive_cc_6007a110,0xf9,uVar1);
    FUN_600d37ac(auStack_a4,PTR_s_UsbAudio_receive_failed_6007a114);
    FUN_600d37b8(auStack_ac);
  }
  uVar2 = FUN_600d3618();
  DataMemoryBarrier(0x1b);
  *(undefined4 *)(param_1 + 0x964) = uVar2;
  DataMemoryBarrier(0x1b);
  return uVar1;
}



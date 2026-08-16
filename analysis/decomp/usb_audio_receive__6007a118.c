// 6007a118  usb_audio_receive__6007a118  size=284 bytes
// src: usb_audio_receive.cc
// --- callers ---
//   6007a62c usb_audio_receive__6007a62c
// --- callees ---
//   600db896 FUN_600db896
//   600cc8f8 FUN_600cc8f8
//   600d37b8 FUN_600d37b8
//   600d3618 FUN_600d3618
//   60051120 FUN_60051120
//   600620b4 usb_device_audio__600620b4
//   600cc984 FUN_600cc984
//   600d37ac FUN_600d37ac
//   600d53ae FUN_600d53ae


/* src: usb_audio_receive.cc */

uint usb_audio_receive__6007a118(int param_1)

{
  undefined *puVar1;
  byte *pbVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined *local_b4;
  undefined4 local_b0;
  undefined1 *local_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined1 local_a0;
  undefined1 local_9f;
  undefined1 local_9e [138];
  
  uVar4 = FUN_600d3618();
  DataMemoryBarrier(0x1b);
  *(undefined4 *)(param_1 + 0x964) = uVar4;
  uVar4 = DAT_6007a234;
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  *(undefined1 *)(param_1 + 0x94b) = 1;
  DataMemoryBarrier(0x1b);
  uVar5 = usb_device_audio__600620b4(uVar4);
  pbVar2 = DAT_6007a244;
  puVar1 = PTR_s_usb_audio_receive_cc_6007a238;
  uVar8 = uVar5 & 0xff;
  if (uVar8 == 10) {
    uVar8 = 0;
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x94b) = 0;
    DataMemoryBarrier(0x1b);
    *(int *)(param_1 + 0x1a04) = *(int *)(param_1 + 0x1a04) + 1;
  }
  else if (uVar8 == 0) {
    *(undefined1 *)(param_1 + 0x19d6) = 1;
    puVar3 = DAT_6007a248;
    *(int *)(param_1 + 0x19fc) = *(int *)(param_1 + 0x19fc) + 1;
    DataMemoryBarrier(0x1b);
    if (((*pbVar2 & 1) == 0) && (iVar6 = FUN_600cc8f8(pbVar2), iVar6 != 0)) {
      *puVar3 = 0;
      FUN_600cc984(pbVar2);
    }
    uVar5 = FUN_600d3618();
    local_b4 = PTR_s_usb_audio_receive_cc_6007a238;
    if (*puVar3 + 5000 <= uVar5) {
      *puVar3 = uVar5;
      local_b0 = 0xea;
      local_ac = local_9e;
      local_a8 = 0x80;
      uStack_a4 = 0;
      local_a0 = 0;
      local_9f = 0;
      local_9e[0] = 0;
      FUN_600d37ac(&local_ac,DAT_6007a24c);
      FUN_600db896(&local_ac,*(undefined4 *)(param_1 + 0x19fc));
      FUN_600d37ac(&local_ac,DAT_6007a250);
      FUN_600d53ae(&local_b4);
    }
  }
  else {
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x94b) = 0;
    piVar7 = (int *)(param_1 + 0x1a00);
    DataMemoryBarrier(0x1b);
    *piVar7 = *piVar7 + 1;
    FUN_60051120(&local_b4,puVar1,0xe4,uVar5);
    FUN_600d37ac(&local_ac,PTR_s_UsbAudio_receive_cancel_failed__6007a23c);
    FUN_600db896(&local_ac,*piVar7);
    FUN_600d37ac(&local_ac,PTR_s_errors_6007a240);
    FUN_600d37b8(&local_b4);
  }
  return uVar8;
}



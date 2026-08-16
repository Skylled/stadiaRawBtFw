// 6007a504  usb_audio_receive__6007a504  size=270 bytes
// src: usb_audio_receive.cc
// --- callers ---
//   6007a62c usb_audio_receive__6007a62c
// --- callees ---
//   600cc8f8 FUN_600cc8f8
//   600d37b8 FUN_600d37b8
//   600dba24 FUN_600dba24
//   600d3618 FUN_600d3618
//   60050c18 FUN_60050c18
//   60051120 FUN_60051120
//   600cc984 FUN_600cc984
//   600d5240 FUN_600d5240
//   60101ba2 FUN_60101ba2
//   600dbb64 FUN_600dbb64
//   600d37ac FUN_600d37ac
//   600d53ae FUN_600d53ae


/* src: usb_audio_receive.cc */

void usb_audio_receive__6007a504(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined *local_b4;
  undefined4 local_b0;
  undefined1 *local_ac;
  int local_a8;
  int iStack_a4;
  undefined1 local_a0;
  undefined1 local_9f;
  undefined1 local_9e [138];
  
  uVar7 = *(uint *)(param_1 + 0x954);
  iVar4 = FUN_600d5240(param_1 + 0x70,5);
  puVar3 = DAT_6007a618;
  pbVar2 = DAT_6007a614;
  if (iVar4 == 0) {
    if (uVar7 < 2) {
      uVar7 = 2;
    }
    iVar4 = uVar7 - 1;
    if ((uint)(*(int *)(param_1 + 0x9c8) - *(int *)(param_1 + 0x9c0)) <
        (uint)(*(int *)(param_1 + 0x950) + iVar4 * 0xc0)) {
      bVar1 = *DAT_6007a614;
      DataMemoryBarrier(0x1b);
      if (((bVar1 & 1) == 0) && (iVar5 = FUN_600cc8f8(DAT_6007a614), iVar5 != 0)) {
        *puVar3 = bVar1 & 1;
        FUN_600cc984(pbVar2);
      }
      uVar7 = FUN_600d3618();
      local_b4 = PTR_s_usb_audio_receive_cc_6007a61c;
      if (*puVar3 + 5000 <= uVar7) {
        *puVar3 = uVar7;
        local_b0 = 0x128;
        local_ac = local_9e;
        local_a0 = 0;
        local_9f = 0;
        local_9e[0] = 0;
        local_a8 = 0x80;
        iStack_a4 = 0;
        FUN_600d37ac(&local_ac,PTR_s_Not_enough_room_in_buffer_to_fil_6007a620);
        uVar6 = FUN_60050c18(iVar4,0,local_ac + iStack_a4,local_a8 - iStack_a4);
        FUN_60101ba2(&local_ac,uVar6);
        FUN_600d37ac(&local_ac,PTR_s_ms_audio_gap_6007a624);
        FUN_600d53ae(&local_b4);
      }
    }
    else {
      uVar7 = FUN_600dbb64(param_1,iVar4 * 0x30);
      if ((uVar7 & 0xff) != 0) {
        FUN_60051120(&local_b4,PTR_s_usb_audio_receive_cc_6007a61c,0x12e,uVar7);
        FUN_600d37ac(&local_ac,PTR_s_USB_Audio_discontinuity_linear_i_6007a628);
        FUN_600d37b8(&local_b4);
      }
      *(int *)(param_1 + 0x19f0) = iVar4 * 0x30 + *(int *)(param_1 + 0x19f0);
    }
  }
  else {
    FUN_600dba24(param_1 + 0x9bc,*(undefined4 *)(param_1 + 0x9c0));
    *(undefined4 *)(param_1 + 0x19d2) = 0;
  }
  return;
}



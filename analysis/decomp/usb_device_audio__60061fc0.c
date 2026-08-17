// 60061fc0  usb_device_audio__60061fc0  size=222 bytes
// src: usb_device_audio.cc
// --- callers ---
//   6007a040 usb_audio_receive__6007a040
// --- callees ---
//   600d0602 FUN_600d0602
//   600d4946 FUN_600d4946
//   600d521e FUN_600d521e
//   600615bc FUN_600615bc
//   600cc984 FUN_600cc984
//   600d53ae FUN_600d53ae
//   600d37ac FUN_600d37ac
//   600d5252 FUN_600d5252
//   600d3b3a FUN_600d3b3a
//   600cc8f8 FUN_600cc8f8


/* src: usb_device_audio.cc */

undefined4 usb_device_audio__60061fc0(int param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  byte *pbVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  undefined *local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [144];
  
  if (param_3 == 4) {
    if (*(char *)(param_1 + 0xad) != '\0') {
      pcVar6 = (char *)(param_1 + 0xb0);
      DataMemoryBarrier(0x1b);
      do {
        ExclusiveAccess(pcVar6);
        cVar2 = *pcVar6;
        bVar3 = (bool)hasExclusiveAccess(pcVar6);
      } while (!bVar3);
      *pcVar6 = '\x01';
      DataMemoryBarrier(0x1b);
      if (cVar2 == '\0') {
        *(undefined4 *)(param_1 + 800) = *param_2;
        DataMemoryBarrier(0x1b);
        *(undefined1 *)(param_1 + 0xb0) = 1;
        DataMemoryBarrier(0x1b);
        iVar7 = FUN_600d0602(*(undefined4 *)(param_1 + 4),5,param_1 + 800,4);
        if (iVar7 == 0) {
          return 0;
        }
        DataMemoryBarrier(0x1b);
        *(undefined1 *)(param_1 + 0xb0) = 0;
        pbVar4 = DAT_600620a0;
        DataMemoryBarrier(0x1b);
        bVar1 = *DAT_600620a0;
        DataMemoryBarrier(0x1b);
        if (((bVar1 & 1) == 0) && (iVar8 = FUN_600cc8f8(DAT_600620a0), iVar8 != 0)) {
          *DAT_600620a4 = bVar1 & 1;
          FUN_600cc984(pbVar4);
        }
        iVar8 = FUN_600d5252(DAT_600620a4,5000);
        if (iVar8 != 0) {
          local_a8 = PTR_s_usb_device_audio_cc_600620a8;
          local_a4 = 0x18e;
          FUN_600d3b3a(auStack_a0);
          FUN_600d37ac(auStack_a0,PTR_s_Failed_to_send_USB_audio_feedbac_600620ac);
          FUN_600d521e(auStack_a0,iVar7);
          FUN_600d37ac(auStack_a0,PTR_DAT_600620b0);
          uVar5 = FUN_600615bc(iVar7);
          FUN_600d37ac(auStack_a0,uVar5);
          FUN_600d53ae(&local_a8);
        }
        uVar5 = FUN_600d4946(iVar7);
        return uVar5;
      }
    }
    uVar5 = 0xe;
  }
  else {
    uVar5 = 3;
  }
  return uVar5;
}



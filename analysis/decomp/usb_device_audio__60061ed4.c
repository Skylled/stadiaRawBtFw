// 60061ed4  usb_device_audio__60061ed4  size=216 bytes
// src: usb_device_audio.cc
// --- callers ---
// --- callees ---
//   600d4946 FUN_600d4946
//   600d521e FUN_600d521e
//   600d5240 FUN_600d5240
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d05e0 FUN_600d05e0
//   600615bc FUN_600615bc
//   600cc984 FUN_600cc984
//   600d53ae FUN_600d53ae
//   600d37ac FUN_600d37ac
//   600d5252 FUN_600d5252
//   600d3b3a FUN_600d3b3a
//   600cc8f8 FUN_600cc8f8


/* src: usb_device_audio.cc */

undefined4 usb_device_audio__60061ed4(int param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  byte bVar1;
  byte *pbVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined *local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [144];
  
  if (param_3 == 0) {
    uVar3 = 3;
  }
  else {
    iVar4 = FUN_600d5240(param_1 + 0xae,5);
    if ((iVar4 == 0) && (*(char *)(param_1 + 0xac) != '\0')) {
      *param_4 = 0;
      if (0x5f < param_3) {
        param_3 = 0x60;
      }
      thunk_EXT_FUN_0000b572(param_1 + 0xc0,param_2,param_3);
      iVar4 = FUN_600d05e0(*(undefined4 *)(param_1 + 4),6,param_1 + 0xc0,param_3);
      pbVar2 = DAT_60061fac;
      if (iVar4 == 0) {
        DataMemoryBarrier(0x1b);
        *(undefined1 *)(param_1 + 0xae) = 1;
        DataMemoryBarrier(0x1b);
        *param_4 = param_3;
        uVar3 = 0;
      }
      else {
        bVar1 = *DAT_60061fac;
        DataMemoryBarrier(0x1b);
        if (((bVar1 & 1) == 0) && (iVar5 = FUN_600cc8f8(DAT_60061fac), iVar5 != 0)) {
          *DAT_60061fb0 = bVar1 & 1;
          FUN_600cc984(pbVar2);
        }
        iVar5 = FUN_600d5252(DAT_60061fb0,5000);
        if (iVar5 != 0) {
          local_b0 = PTR_s_usb_device_audio_cc_60061fb4;
          local_ac = 0x16a;
          FUN_600d3b3a(auStack_a8);
          FUN_600d37ac(auStack_a8,PTR_s_Failed_to_send_USB_audio__60061fb8);
          FUN_600d521e(auStack_a8,iVar4);
          FUN_600d37ac(auStack_a8,PTR_DAT_60061fbc);
          uVar3 = FUN_600615bc(iVar4);
          FUN_600d37ac(auStack_a8,uVar3);
          FUN_600d53ae(&local_b0);
        }
        uVar3 = FUN_600d4946(iVar4);
      }
    }
    else {
      uVar3 = 0xe;
    }
  }
  return uVar3;
}



// 600626e4  usb_host__600626e4  size=362 bytes
// src: usb_host.cc
// --- callers ---
// --- callees ---
//   6010165c FUN_6010165c
//   600cc984 FUN_600cc984
//   600d33b2 FUN_600d33b2
//   60064dac usb_host_hid__60064dac
//   600cc8f8 FUN_600cc8f8
//   600637cc FUN_600637cc
//   60062674 usb_host__60062674


/* src: usb_host.cc */

int usb_host__600626e4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  int iVar8;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  pbVar4 = DAT_60062878;
  DataMemoryBarrier(0x1b);
  bVar2 = *DAT_60062878 & 1;
  if (((*DAT_60062878 & 1) == 0) &&
     (iVar5 = FUN_600cc8f8(DAT_60062878), pbVar3 = DAT_60062854, iVar5 != 0)) {
    *DAT_60062854 = bVar2;
    pbVar3[1] = bVar2;
    FUN_600cc984(pbVar4);
  }
  pbVar4 = DAT_60062854;
  switch(param_3) {
  case 1:
    FUN_6010165c(0x14,DAT_6006285c,0x3c,DAT_60062858);
    iVar5 = usb_host_hid__60064dac(param_1,param_2,1);
    if (iVar5 == 0) {
      FUN_6010165c(0x14,DAT_6006285c,0x40,DAT_60062860);
      DAT_60062854[1] = 1;
      return 0;
    }
    iVar5 = FUN_600637cc(param_1,param_2,1);
    if (iVar5 != 0) {
      return iVar5;
    }
    FUN_6010165c(0x14,DAT_6006285c,0x48,DAT_60062864);
    *DAT_60062854 = 1;
    return 0;
  case 2:
    iVar5 = usb_host__60062674(*(undefined2 *)DAT_60062854,param_1,param_2,2);
    iVar8 = DAT_60062874;
    *(undefined4 *)(DAT_60062874 + 0x3ef4) = 0;
    *pbVar4 = 0;
    *(undefined1 *)(iVar8 + 0x3ef8) = 0;
    pbVar4[1] = 0;
    *(undefined2 *)(iVar8 + 0x3eec) = *(undefined2 *)pbVar4;
    pcVar7 = *(code **)(iVar8 + 0x3efc);
    uVar6 = 5;
    break;
  case 3:
    iVar5 = usb_host__60062674(*(undefined2 *)DAT_60062854,param_1,param_2,3);
    if (iVar5 != 0) {
      return iVar5;
    }
    FUN_600d33b2(param_1,0xb,&local_24);
    FUN_600d33b2(param_1,10,&local_20);
    uVar6 = DAT_6006285c;
    local_1c = CONCAT22((short)local_20,(short)local_24);
    DataMemoryBarrier(0x1b);
    *DAT_6006286c = local_1c;
    DataMemoryBarrier(0x1b);
    FUN_6010165c(0x14,uVar6,0x5b,DAT_60062870,local_24,local_20);
    iVar8 = DAT_60062874;
    uVar1 = *(undefined2 *)pbVar4;
    *(undefined4 *)(DAT_60062874 + 0x3ef4) = param_1;
    *(undefined1 *)(iVar8 + 0x3ef8) = 0;
    *(undefined2 *)(iVar8 + 0x3eec) = uVar1;
    pcVar7 = *(code **)(iVar8 + 0x3efc);
    uVar6 = 4;
    iVar5 = 0;
    break;
  case 4:
    FUN_6010165c(0x14,DAT_6006285c,0x4e,DAT_60062868);
  default:
    return 0;
  }
  (*pcVar7)(*(undefined4 *)(iVar8 + 0x3f00),uVar6);
  return iVar5;
}



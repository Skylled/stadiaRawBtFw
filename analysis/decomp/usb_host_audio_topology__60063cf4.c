// 60063cf4  usb_host_audio_topology__60063cf4  size=212 bytes
// src: usb_host_audio_topology.cc
// --- callers ---
//   60063e24 usb_host_audio_topology__60063e24
// --- callees ---
//   600d5d08 FUN_600d5d08
//   60063be8 FUN_60063be8
//   6010165c FUN_6010165c
//   60063b48 FUN_60063b48


/* src: usb_host_audio_topology.cc */

undefined4 * usb_host_audio_topology__60063cf4(undefined4 *param_1,undefined1 param_2,byte *param_3)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int extraout_r2;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  *param_1 = param_3;
  uVar2 = 0;
  *(undefined1 *)(param_1 + 1) = param_2;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 7) = 0xff;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (param_3 == (byte *)0x0) {
switchD_60063d38_caseD_7:
    uVar2 = 0;
    goto LAB_60063d7e;
  }
  uVar6 = (uint)*param_3;
  if ((uVar6 < 4) || (param_3[1] != 0x24)) goto LAB_60063d7e;
  bVar1 = param_3[2];
  iVar3 = FUN_60063be8(bVar1);
  uVar2 = 0;
  if (iVar3 == 0) goto LAB_60063d7e;
  iVar3 = FUN_60063b48(bVar1);
  switch(iVar3) {
  case 1:
  case 4:
    uVar5 = 0xc;
    break;
  case 2:
    uVar5 = 0x11;
    break;
  case 3:
    uVar5 = 9;
    break;
  case 5:
  case 6:
    if (uVar6 < 6) goto switchD_60063d38_caseD_9;
    uVar2 = 0;
    if (*(byte *)(extraout_r2 + 4) == 0) goto LAB_60063d7e;
    uVar5 = *(byte *)(extraout_r2 + 4) + 5;
    break;
  default:
    goto switchD_60063d38_caseD_7;
  case 9:
switchD_60063d38_caseD_9:
    uVar5 = 6;
    break;
  case 10:
    uVar5 = 10;
    break;
  case 0xe:
  case 0xf:
    if (uVar6 < 8) goto switchD_60063d38_caseD_10;
    uVar5 = (uint)*(byte *)(extraout_r2 + 6);
    if (uVar5 == 0) {
      uVar2 = 0;
      goto LAB_60063d7e;
    }
    if (iVar3 == 0xe) {
      uVar5 = uVar5 + 0xc;
    }
    else {
      uVar5 = uVar5 + 0xf;
    }
    break;
  case 0x10:
switchD_60063d38_caseD_10:
    uVar5 = 8;
    break;
  case 0x11:
    if (uVar6 < 6) goto switchD_60063d38_caseD_9;
    uVar2 = 0;
    if (*(byte *)(extraout_r2 + 4) == 0) goto LAB_60063d7e;
    uVar5 = *(byte *)(extraout_r2 + 4) + 7;
    break;
  case 0x12:
    uVar5 = 7;
  }
  if (uVar6 < uVar5) {
    uVar6 = iVar3 - 1U & 0xff;
    uVar4 = DAT_60063de4;
    if (uVar6 < 0x13) {
      uVar4 = *(undefined4 *)(DAT_60063de0 + uVar6 * 4);
    }
    FUN_6010165c(0x28,DAT_60063ddc,0x12f,DAT_60063de8,uVar4);
  }
  if (*(byte *)*param_1 < uVar5) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
LAB_60063d7e:
  *(undefined1 *)((int)param_1 + 5) = uVar2;
  FUN_600d5d08(param_1);
  return param_1;
}



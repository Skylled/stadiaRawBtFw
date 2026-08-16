// 6006408c  usb_host_audio_topology__6006408c  size=120 bytes
// src: usb_host_audio_topology.cc
// --- callers ---
//   600d61c8 FUN_600d61c8
//   600d614a FUN_600d614a
// --- callees ---
//   600d6100 FUN_600d6100
//   600d5c6a FUN_600d5c6a
//   600d6028 FUN_600d6028
//   60063dec FUN_60063dec
//   6010165c FUN_6010165c
//   600d5c16 FUN_600d5c16


/* src: usb_host_audio_topology.cc */

undefined4 * usb_host_audio_topology__6006408c(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_19;
  
  param_1[2] = 0;
  local_19 = (undefined1)param_3;
  *param_1 = 0;
  param_1[1] = 0;
  iVar2 = FUN_600d6028(*(undefined4 *)(param_2 + 0x54),&local_19,param_3,0,param_1,param_2,param_3);
  uVar1 = local_19;
  if (*(int *)(param_2 + 0x54) + 4 == iVar2) {
    uVar4 = 0x3f7;
    uVar3 = DAT_60064104;
LAB_600640be:
    FUN_6010165c(0x28,DAT_60064108,uVar4,uVar3,uVar1);
  }
  else {
    uVar3 = FUN_60063dec(*(int *)(param_2 + 0x54),&local_19);
    iVar2 = FUN_600d5c16();
    if (iVar2 == 0) {
      iVar2 = FUN_600d5c6a(uVar3);
      if (iVar2 == 0) {
        uVar4 = 0x3ff;
        uVar3 = DAT_6006410c;
        goto LAB_600640be;
      }
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    FUN_600d6100(param_2,uVar1,param_1,uVar3);
  }
  return param_1;
}



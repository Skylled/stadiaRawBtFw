// 60064110  usb_host_audio_topology__60064110  size=142 bytes
// src: usb_host_audio_topology.cc
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   600d5e14 FUN_600d5e14
//   600d5cbe FUN_600d5cbe
//   6010165c FUN_6010165c
//   600d5cfc FUN_600d5cfc
//   600d6612 FUN_600d6612


/* src: usb_host_audio_topology.cc */

undefined4 * usb_host_audio_topology__60064110(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *local_28;
  int local_24;
  undefined4 uStack_20;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  local_28 = param_1;
  uStack_20 = param_3;
  if (*(char *)(param_2 + 0x78) == '\0') {
    local_24 = param_2;
    FUN_6010165c(0x28,DAT_600641a4,0x377,DAT_600641a0);
  }
  else {
    iVar4 = *(int *)(param_2 + 0x54);
    local_24 = *(int *)(iVar4 + 0xc);
    while (iVar1 = local_24, local_24 != iVar4 + 4) {
      iVar3 = local_24 + 0x14;
      iVar2 = FUN_600d5cbe(iVar3);
      if (iVar2 == 0) {
        iVar2 = FUN_600d5cfc(iVar3);
        if (iVar2 != 0) {
          local_28 = (undefined4 *)CONCAT22(local_28._2_2_,0x100);
          local_28 = (undefined4 *)CONCAT31(local_28._1_3_,*(undefined1 *)(iVar1 + 0x10));
          FUN_600d6612(param_1,&local_28);
          local_28 = (undefined4 *)CONCAT22(local_28._2_2_,0x200);
          local_28 = (undefined4 *)CONCAT31(local_28._1_3_,*(undefined1 *)(iVar1 + 0x10));
          goto LAB_60064166;
        }
      }
      else {
        local_28 = (undefined4 *)CONCAT22(local_28._2_2_,0x100);
        local_28 = (undefined4 *)CONCAT31(local_28._1_3_,*(undefined1 *)(iVar1 + 0x10));
LAB_60064166:
        FUN_600d6612(param_1,&local_28);
      }
      FUN_600d5e14(&local_24);
    }
  }
  return param_1;
}



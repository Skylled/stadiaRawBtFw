// 60064438  usb_host_audio_topology__60064438  size=156 bytes
// src: usb_host_audio_topology.cc
// --- callers ---
//   600d67e8 FUN_600d67e8
//   60064438 usb_host_audio_topology__60064438
// --- callees ---
//   600d5cbe FUN_600d5cbe
//   600d6750 FUN_600d6750
//   600d6028 FUN_600d6028
//   60063dec FUN_60063dec
//   60064438 usb_host_audio_topology__60064438
//   6010165c FUN_6010165c
//   60063c58 FUN_60063c58
//   600d5cc4 FUN_600d5cc4


/* src: usb_host_audio_topology.cc */

void usb_host_audio_topology__60064438
               (int param_1,undefined1 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 local_29;
  undefined1 auStack_28 [12];
  
  local_29 = param_2;
  iVar1 = FUN_600d6028(*(undefined4 *)(param_1 + 0x54),&local_29);
  if ((*(int *)(param_1 + 0x54) + 4 != iVar1) &&
     (iVar1 = FUN_60063dec(*(int *)(param_1 + 0x54),&local_29), *(char *)(iVar1 + 6) == '\0')) {
    *(undefined1 *)(iVar1 + 6) = 1;
    FUN_60063c58(param_4,&local_29);
    iVar1 = FUN_60063dec(*(undefined4 *)(param_1 + 0x54),&local_29);
    iVar2 = FUN_600d5cbe();
    if (iVar2 == 0) {
      iVar2 = FUN_600d5cc4(iVar1);
      if (iVar2 == 0) {
        FUN_6010165c(0x28,DAT_600644d8,0x3ee,DAT_600644d4);
      }
      else {
        puVar5 = *(undefined1 **)(iVar1 + 0x18);
        for (puVar4 = *(undefined1 **)(iVar1 + 0x14); puVar4 != puVar5; puVar4 = puVar4 + 1) {
          usb_host_audio_topology__60064438(param_1,*puVar4,param_3,param_4);
        }
      }
    }
    else {
      FUN_600d6750(auStack_28,param_3,param_4);
    }
    uVar3 = *(undefined4 *)(param_1 + 0x54);
    *(int *)(param_4 + 4) = *(int *)(param_4 + 4) + -1;
    iVar1 = FUN_60063dec(uVar3,&local_29);
    *(undefined1 *)(iVar1 + 6) = 0;
  }
  return;
}



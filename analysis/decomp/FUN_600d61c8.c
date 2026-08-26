// 600d61c8  FUN_600d61c8  size=142 bytes
// --- callers ---
//   600644dc usb_host_audio_topology__600644dc
// --- callees ---
//   6006408c usb_host_audio_topology__6006408c
//   60063dec FUN_60063dec
//   600d6028 FUN_600d6028
//   600d5c3c FUN_600d5c3c
//   600d5c70 FUN_600d5c70
//   600d5fc2 FUN_600d5fc2


int FUN_600d61c8(int param_1,undefined1 param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 local_29 [4];
  undefined1 local_25;
  undefined1 *local_24;
  undefined1 *puStack_20;
  
  local_29[0] = param_2;
  iVar1 = FUN_600d6028(*(undefined4 *)(param_1 + 0x54),local_29);
  if (*(int *)(param_1 + 0x54) + 4 == iVar1) {
    iVar1 = 0;
  }
  else {
    FUN_60063dec(*(int *)(param_1 + 0x54),local_29);
    iVar2 = FUN_600d5c70();
    iVar1 = 0;
    if (iVar2 != 0) {
      usb_host_audio_topology__6006408c(&local_24,param_1,local_29[0]);
      do {
        do {
          if (local_24 == puStack_20) {
            iVar1 = 0;
            goto LAB_600d6240;
          }
          puVar3 = local_24 + 1;
          local_25 = *local_24;
          iVar1 = FUN_600d6028(*(undefined4 *)(param_1 + 0x54),&local_25);
          local_24 = puVar3;
        } while (*(int *)(param_1 + 0x54) + 4 == iVar1);
        FUN_60063dec(*(int *)(param_1 + 0x54),&local_25);
        iVar1 = FUN_600d5c3c();
      } while (iVar1 == 0);
      *param_3 = local_25;
LAB_600d6240:
      FUN_600d5fc2(&local_24);
    }
  }
  return iVar1;
}



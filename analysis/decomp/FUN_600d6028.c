// 600d6028  FUN_600d6028  size=42 bytes
// --- callers ---
//   6006408c usb_host_audio_topology__6006408c
//   600d61c8 FUN_600d61c8
//   600d614a FUN_600d614a
//   600641a8 usb_host_audio_topology__600641a8
//   600d654c FUN_600d654c
//   600d6074 FUN_600d6074
//   60063e24 usb_host_audio_topology__60063e24
//   60064438 usb_host_audio_topology__60064438
//   600644dc usb_host_audio_topology__600644dc
//   600d62f8 FUN_600d62f8
// --- callees ---


int FUN_600d6028(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 + 4;
  iVar1 = iVar2;
  iVar3 = *(int *)(param_1 + 8);
  while (iVar3 != 0) {
    if (*(byte *)(iVar3 + 0x10) < *param_2) {
      iVar3 = *(int *)(iVar3 + 0xc);
    }
    else {
      iVar1 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
  }
  if ((iVar2 == iVar1) || (*param_2 < *(byte *)(iVar1 + 0x10))) {
    iVar1 = iVar2;
  }
  return iVar1;
}



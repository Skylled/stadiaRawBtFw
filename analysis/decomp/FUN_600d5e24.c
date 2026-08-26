// 600d5e24  FUN_600d5e24  size=38 bytes
// --- callers ---
//   60063e24 usb_host_audio_topology__60063e24
// --- callees ---
//   60063c08 usb_host_audio_topology__60063c08
//   600d5e14 FUN_600d5e14


void FUN_600d5e24(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_14;
  undefined4 uStack_10;
  
  iVar1 = *(int *)(param_1 + 0x54);
  local_14 = *(int *)(iVar1 + 0xc);
  uStack_10 = param_3;
  while (iVar1 + 4 != local_14) {
    usb_host_audio_topology__60063c08(local_14 + 0x14);
    FUN_600d5e14(&local_14);
  }
  return;
}



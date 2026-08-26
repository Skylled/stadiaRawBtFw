// 600d6052  FUN_600d6052  size=34 bytes
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   60063e24 usb_host_audio_topology__60063e24


void FUN_600d6052(int param_1,int *param_2,int param_3)

{
  char cVar1;
  
  cVar1 = usb_host_audio_topology__60063e24(param_1,param_3);
  if (cVar1 == '\0') {
    *param_2 = *(int *)(param_1 + 0x5c) + (uint)*(byte *)(*(int *)(param_1 + 0x60) + param_3) * 0x40
    ;
  }
  return;
}



// 600d55fa  FUN_600d55fa  size=60 bytes
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---


void FUN_600d55fa(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x970);
  if ((*(char *)(iVar1 + 0x35) == '\0') || (*(char *)(iVar1 + 0x36) != '\0')) {
    if ((*(char *)(iVar1 + 0x99) == '\0') || (*(char *)(iVar1 + 0x9a) != '\0')) {
      if ((*(char *)(iVar1 + 0xfd) == '\0') || (*(char *)(iVar1 + 0xfe) != '\0')) {
        iVar1 = 0;
      }
      else {
        iVar1 = iVar1 + 0xfc;
      }
    }
    else {
      iVar1 = iVar1 + 0x98;
    }
  }
  else {
    iVar1 = iVar1 + 0x34;
  }
  *(int *)(param_1 + 0x108) = iVar1;
  return;
}



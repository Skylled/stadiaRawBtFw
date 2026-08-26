// 600d57d4  FUN_600d57d4  size=84 bytes
// --- callers ---
// --- callees ---
//   600d56ae usb_host_worker__600d56ae


void FUN_600d57d4(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x970);
  if (param_4 == 0) {
    if (*(char *)(iVar2 + 0x41c) == '\0') {
      if (*(int *)(iVar2 + 0x420) != *(int *)(iVar2 + 0x424)) {
        *(int *)(iVar2 + 0x424) = *(int *)(iVar2 + 0x424) + -2;
      }
    }
    else {
      *(undefined1 *)(iVar2 + 0x41c) = 0;
    }
    if (*(int *)(*(int *)(param_1 + 0x970) + 0x420) == *(int *)(*(int *)(param_1 + 0x970) + 0x424))
    {
      uVar1 = 1;
    }
    else {
      uVar1 = 7;
    }
  }
  else if (*(char *)(iVar2 + 0x410) == '\0') {
    uVar1 = 1;
  }
  else {
    uVar1 = 8;
  }
  usb_host_worker__600d56ae(param_1,uVar1);
  return;
}



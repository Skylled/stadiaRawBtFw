// 600d56b8  FUN_600d56b8  size=54 bytes
// --- callers ---
//   600d5714 FUN_600d5714
//   600d56ee FUN_600d56ee
//   600d56f6 FUN_600d56f6
// --- callees ---
//   600d56ae usb_host_worker__600d56ae


void FUN_600d56b8(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 == 0) ||
     (iVar2 = *(int *)(param_1 + 0x78) + 1, *(int *)(param_1 + 0x78) = iVar2, 2 < iVar2)) {
    *(undefined4 *)(param_1 + 0x78) = 0;
    if ((param_2 == 0) || (param_3 == 0)) {
      if (*(char *)(param_1 + 0x7c) == '\0') {
        uVar1 = 1;
      }
      else {
        uVar1 = 2;
      }
    }
    else {
      uVar1 = 8;
    }
  }
  else {
    uVar1 = 7;
  }
  usb_host_worker__600d56ae(param_1,uVar1);
  return;
}



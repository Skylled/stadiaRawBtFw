// 600d0602  FUN_600d0602  size=34 bytes
// --- callers ---
//   60061fc0 usb_device_audio__60061fc0
// --- callees ---
//   600d1090 FUN_600d1090


int FUN_600d0602(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 3;
  }
  else if (*(char *)((int)param_1 + 0x1d) == '\0') {
    *(undefined1 *)((int)param_1 + 0x1d) = 1;
    iVar1 = FUN_600d1090(*param_1);
    if (iVar1 != 0) {
      *(undefined1 *)((int)param_1 + 0x1d) = 0;
    }
  }
  else {
    iVar1 = 2;
  }
  return iVar1;
}



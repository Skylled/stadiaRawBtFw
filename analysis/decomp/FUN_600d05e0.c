// 600d05e0  FUN_600d05e0  size=34 bytes
// --- callers ---
//   60061ed4 usb_device_audio__60061ed4
// --- callees ---
//   600d1090 FUN_600d1090


int FUN_600d05e0(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 3;
  }
  else if (*(char *)((int)param_1 + 0x1b) == '\0') {
    *(undefined1 *)((int)param_1 + 0x1b) = 1;
    iVar1 = FUN_600d1090(*param_1);
    if (iVar1 != 0) {
      *(undefined1 *)((int)param_1 + 0x1b) = 0;
    }
  }
  else {
    iVar1 = 2;
  }
  return iVar1;
}



// 600d4946  FUN_600d4946  size=68 bytes
// --- callers ---
//   600d4f6c FUN_600d4f6c
//   60061ed4 usb_device_audio__60061ed4
//   600d52f0 FUN_600d52f0
//   600620b4 usb_device_audio__600620b4
//   600d4f84 FUN_600d4f84
//   60061fc0 usb_device_audio__60061fc0
//   600d4f98 FUN_600d4f98
// --- callees ---


undefined4 FUN_600d4946(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return 0;
  case 1:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
    return 0xd;
  case 2:
  case 6:
    return 0xe;
  case 3:
  case 4:
  case 5:
  case 7:
  case 8:
    return 3;
  case 9:
    return 4;
  case 10:
    return 8;
  default:
    return 2;
  }
}



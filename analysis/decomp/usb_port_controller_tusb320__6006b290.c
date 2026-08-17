// 6006b290  usb_port_controller_tusb320__6006b290  size=78 bytes
// src: usb_port_controller_tusb320.cc
// --- callers ---
// --- callees ---
//   600d8f64 FUN_600d8f64
//   600926a0 FUN_600926a0
//   6010165c FUN_6010165c
//   600d8ed4 FUN_600d8ed4


/* src: usb_port_controller_tusb320.cc */

void usb_port_controller_tusb320__6006b290(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_600d8f64();
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  if ((*(char *)(param_1 + 0x182) == '\0') && (iVar1 != 0)) {
    if (iVar1 == 2) {
      FUN_600926a0(param_1 + 0x11c);
    }
    else if (iVar1 == 3) {
      FUN_6010165c(0x28,DAT_6006b2e4,0x29,DAT_6006b2e0);
    }
  }
  else {
    FUN_600d8ed4(param_1);
  }
  DataMemoryBarrier(0x1b);
  *(undefined1 *)(param_1 + 0x182) = 0;
  DataMemoryBarrier(0x1b);
  return;
}



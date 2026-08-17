// 6006525c  usb_host_worker__6006525c  size=36 bytes
// src: usb_host_worker.cc
// --- callers ---
//   60064dac usb_host_hid__60064dac
//   6006287c usb_host__6006287c
//   600637cc FUN_600637cc
// --- callees ---
//   6010165c FUN_6010165c
//   6010177a FUN_6010177a


/* src: usb_host_worker.cc */

void usb_host_worker__6006525c(void)

{
  int iVar1;
  
  iVar1 = DAT_60065280;
  if (*(int *)(DAT_60065280 + 0x58) == 0) {
    FUN_6010165c(0x14,DAT_60065284,0x59,DAT_60065288);
    FUN_6010177a(iVar1,DAT_6006528c,0x1b);
    return;
  }
  return;
}



// 60062674  usb_host__60062674  size=100 bytes
// src: usb_host.cc
// --- callers ---
//   600626e4 usb_host__600626e4
// --- callees ---
//   6010165c FUN_6010165c
//   60064dac usb_host_hid__60064dac
//   600637cc FUN_600637cc


/* src: usb_host.cc */

int usb_host__60062674(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (((param_1 & 0xffff) >> 8 != 0) &&
     (iVar1 = usb_host_hid__60064dac(param_2,param_3,param_4,param_4,param_1,param_2,param_3),
     iVar1 != 0)) {
    FUN_6010165c(0x1e,DAT_600626dc,0x27,DAT_600626d8,param_4,iVar1);
  }
  iVar2 = 0;
  if (((param_1 & 0xff) != 0) && (iVar2 = FUN_600637cc(param_2,param_3,param_4), iVar2 != 0)) {
    FUN_6010165c(0x1e,DAT_600626dc,0x2f,DAT_600626e0,param_4,iVar2);
  }
  if (iVar1 != iVar2) {
    iVar2 = 1;
  }
  return iVar2;
}



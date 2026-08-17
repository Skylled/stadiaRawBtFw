// 6006b3e8  usb_port_controller_tusb320__6006b3e8  size=202 bytes
// src: usb_port_controller_tusb320.cc
// --- callers ---
//   60074658 timer__60074658
// --- callees ---
//   6013cef8 thunk_EXT_FUN_0000737c
//   6009267c FUN_6009267c
//   600d8e6c FUN_600d8e6c
//   600d8e2c FUN_600d8e2c
//   6005f534 FUN_6005f534
//   6006efd4 FUN_6006efd4
//   600d8f24 FUN_600d8f24
//   601017fc FUN_601017fc
//   600d37b8 FUN_600d37b8
//   6006b350 usb_port_controller_tusb320__6006b350
//   6005fe04 io_pin__6005fe04
//   600d49ce FUN_600d49ce
//   600d37ac FUN_600d37ac
//   6010165c FUN_6010165c
//   60051120 FUN_60051120


/* src: usb_port_controller_tusb320.cc */

uint usb_port_controller_tusb320__6006b3e8(undefined4 *param_1)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  byte local_ad;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [144];
  byte local_14;
  
  if (*(char *)(param_1 + 0x60) == '\0') {
    uVar3 = FUN_6009267c(1);
    if ((uVar3 & 0xff) == 0) {
      FUN_601017fc(param_1 + 0x4a);
      uVar1 = DAT_6006b4b4;
      param_1[0x48] = param_1;
      param_1[0x47] = uVar1;
      FUN_6006efd4(param_1 + 2);
      iVar4 = param_1[1];
      io_pin__6005fe04(iVar4);
      FUN_6005f534(iVar4 + 0x2c);
      FUN_600d49ce(*param_1);
      *(undefined1 *)(param_1 + 0x60) = 1;
      thunk_EXT_FUN_0000737c(0x78);
      cVar2 = usb_port_controller_tusb320__6006b350(param_1);
      if (cVar2 != '\0') {
        FUN_6010165c(0x1e,DAT_6006b4b8,0x3c,DAT_6006b4bc);
        FUN_600d8e2c(param_1,*(undefined1 *)(param_1 + 7));
      }
      uVar3 = FUN_600d8e6c(param_1,10,&local_ad,0);
      if ((uVar3 & 0xff) == 0) {
        local_ad = local_ad | 2;
        FUN_600d8f24(param_1,10,local_ad,uVar3);
        uVar3 = 0;
      }
      else {
        FUN_60051120(auStack_ac,DAT_6006b4b8,0x42);
        FUN_600d37ac(auStack_a4,DAT_6006b4c0);
        uVar3 = (uint)local_14;
        FUN_600d37b8(auStack_ac);
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



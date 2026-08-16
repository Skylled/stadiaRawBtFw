// 600648b0  usb_host_hid__600648b0  size=104 bytes
// src: usb_host_hid.cc
// --- callers ---
// --- callees ---
//   60101832 FUN_60101832
//   601017fc FUN_601017fc
//   600d68fe FUN_600d68fe
//   600d1ea2 FUN_600d1ea2
//   6010165c FUN_6010165c


/* src: usb_host_hid.cc */

void usb_host_hid__600648b0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  if (param_2 == 0) {
    FUN_601017fc(param_1 + 0x1e4);
    FUN_60101832(param_1 + 0x1e4);
    FUN_601017fc(param_1 + 0x238);
    FUN_60101832(param_1 + 0x238);
    *(undefined4 *)(param_1 + 0x2b4) = 0;
    iVar1 = FUN_600d1ea2(*(undefined4 *)(param_1 + 0xf0),param_1 + 0xf4);
    if (iVar1 != 0) {
      FUN_600d68fe(param_1,8);
      return;
    }
    uVar3 = 0x18a;
    uVar2 = 0x14;
    puVar4 = PTR_s_USB_HID_attached_60064918;
  }
  else {
    if (param_2 != 8) {
      return;
    }
    uVar3 = 0xdc;
    uVar2 = 0x28;
    puVar4 = PTR_s_Exiting_invalid_state_60064920;
  }
  FUN_6010165c(uVar2,PTR_s_usb_host_hid_cc_6006491c,uVar3,puVar4);
  return;
}



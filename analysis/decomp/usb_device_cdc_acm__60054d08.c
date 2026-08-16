// 60054d08  usb_device_cdc_acm__60054d08  size=98 bytes
// src: usb_device_cdc_acm.c
// --- callers ---
//   600551b8 FUN_600551b8
// --- callees ---
//   600d168e thunk_FUN_600d1662
//   6010165c FUN_6010165c
//   600d06d6 FUN_600d06d6


/* src: usb_device_cdc_acm.c */

undefined4 usb_device_cdc_acm__60054d08(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 3;
  }
  else {
    iVar1 = thunk_FUN_600d1662(param_1[4]);
    if (iVar1 != 0) {
      FUN_6010165c(0x28,DAT_60054d70,0x27a,DAT_60054d6c);
    }
    iVar1 = thunk_FUN_600d1662(param_1[6]);
    if (iVar1 != 0) {
      FUN_6010165c(0x28,DAT_60054d70,0x27e,DAT_60054d6c);
    }
    iVar1 = thunk_FUN_600d1662(param_1[8]);
    if (iVar1 != 0) {
      FUN_6010165c(0x28,DAT_60054d70,0x282,DAT_60054d6c);
    }
    uVar2 = FUN_600d06d6(param_1);
    *param_1 = 0;
    param_1[1] = 0;
    *(undefined1 *)(param_1 + 10) = 0;
    *(undefined1 *)((int)param_1 + 0x2a) = 0;
  }
  return uVar2;
}



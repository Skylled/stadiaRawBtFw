// 600d0624  FUN_600d0624  size=52 bytes
// --- callers ---
//   600620b4 usb_device_audio__600620b4
// --- callees ---
//   600d15e8 FUN_600d15e8
//   600d10a4 FUN_600d10a4
//   6013d3e0 thunk_EXT_FUN_00008802


int FUN_600d0624(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 *puVar2;
  undefined4 uStack_14;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 3;
  }
  else {
    puVar2 = param_1;
    uStack_14 = param_2;
    thunk_EXT_FUN_00008802((int)&uStack_14 + 3);
    iVar1 = 0;
    if ((*(char *)(param_1 + 7) != '\0') &&
       (iVar1 = FUN_600d10a4(*param_1,param_2,extraout_r2,extraout_r3,puVar2), iVar1 == 0)) {
      *(undefined1 *)(param_1 + 7) = 0;
    }
    FUN_600d15e8(uStack_14._3_1_);
  }
  return iVar1;
}



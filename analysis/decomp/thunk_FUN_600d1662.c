// 600d168e  thunk_FUN_600d1662  size=4 bytes
// --- callers ---
//   600d2d94 FUN_600d2d94
//   600563b8 FUN_600563b8
//   600d3202 FUN_600d3202
//   60057ee4 FUN_60057ee4
//   60054d08 usb_device_cdc_acm__60054d08
//   60056d74 FUN_60056d74
// --- callees ---


bool thunk_FUN_600d1662(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if (param_1 != (undefined4 *)0x0) {
    uStack_14 = param_2;
    uStack_10 = param_3;
    thunk_EXT_FUN_00007018(*param_1);
    thunk_EXT_FUN_00008802((int)&uStack_14 + 3);
    *(undefined1 *)(param_1 + 0x15) = 0;
    FUN_600d15e8(uStack_14._3_1_);
  }
  return param_1 == (undefined4 *)0x0;
}



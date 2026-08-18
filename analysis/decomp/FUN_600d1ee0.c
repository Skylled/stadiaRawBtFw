// 600d1ee0  FUN_600d1ee0  size=100 bytes
// --- callers ---
//   600649d4 usb_host_hid__600649d4
// --- callees ---
//   600d15e4 thunk_EXT_FUN_000080d8
//   600d332a FUN_600d332a
//   600569e4 FUN_600569e4
//   600d3256 FUN_600d3256


undefined4 FUN_600d1ee0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 3;
  }
  else {
    if (param_2 == (undefined4 *)0x0) {
      FUN_600569e4();
    }
    else {
      uVar1 = param_4;
      if (param_2[4] != 0) {
        FUN_600d332a(*param_2,param_2[4],0,param_4,param_4);
        uVar1 = param_4;
        FUN_600d3256(*param_2,param_2[4]);
        param_4 = 0;
        param_2[4] = 0;
      }
      if (param_2[5] != 0) {
        FUN_600d332a(*param_2,param_2[5],0,param_4,uVar1);
        FUN_600d3256(*param_2,param_2[5]);
        param_2[5] = 0;
      }
      if ((param_2[3] != 0) && (param_2[0xc] != 0)) {
        FUN_600d332a(*param_2);
      }
      FUN_600569e4(param_1,param_2[2]);
      thunk_EXT_FUN_000080d8(param_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}



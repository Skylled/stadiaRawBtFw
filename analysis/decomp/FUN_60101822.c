// 60101822  FUN_60101822  size=16 bytes
// --- callers ---
//   600649d4 usb_host_hid__600649d4
//   600d4df0 FUN_600d4df0
//   600db1ee FUN_600db1ee
//   600696d0 adapter__600696d0
//   601017b4 FUN_601017b4
// --- callees ---
//   6013d270 thunk_EXT_FUN_00006e5c


bool FUN_60101822(int param_1)

{
  int iVar1;
  
  iVar1 = thunk_EXT_FUN_00006e5c(*(undefined4 *)(param_1 + 0x50));
  return iVar1 == 1;
}



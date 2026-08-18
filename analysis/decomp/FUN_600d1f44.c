// 600d1f44  FUN_600d1f44  size=20 bytes
// --- callers ---
//   600649d4 usb_host_hid__600649d4
// --- callees ---


undefined2 FUN_600d1f44(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  
  if ((param_1 != 0) && (param_2 == 3)) {
    if (param_3 == 1) {
      uVar1 = *(undefined2 *)(param_1 + 0x34);
    }
    else {
      uVar1 = *(undefined2 *)(param_1 + 0x36);
    }
    return uVar1;
  }
  return 0;
}



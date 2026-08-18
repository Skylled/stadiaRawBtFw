// 600d19ce  FUN_600d19ce  size=28 bytes
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---


undefined2 FUN_600d19ce(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  
  if (param_1 == 0) {
    return 3;
  }
  if (param_2 != 1) {
    return 0;
  }
  if (param_3 == 1) {
    uVar1 = *(undefined2 *)(param_1 + 0x60);
  }
  else {
    uVar1 = *(undefined2 *)(param_1 + 0x62);
  }
  return uVar1;
}



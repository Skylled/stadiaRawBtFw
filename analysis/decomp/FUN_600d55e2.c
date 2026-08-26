// 600d55e2  FUN_600d55e2  size=24 bytes
// --- callers ---
//   60062e28 FUN_60062e28
//   6006318c usb_host_audio__6006318c
//   600d58ac FUN_600d58ac
// --- callees ---


void FUN_600d55e2(int param_1,int param_2)

{
  *(char *)(param_1 + 0x10) = (char)param_2;
  *(uint *)(param_1 + 0x14) =
       param_2 * (*(uint *)(param_1 + 0xc) / 1000) * (uint)(*(byte *)(param_1 + 5) >> 3);
  return;
}



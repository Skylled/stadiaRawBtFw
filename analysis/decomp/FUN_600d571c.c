// 600d571c  FUN_600d571c  size=14 bytes
// --- callers ---
//   6006318c usb_host_audio__6006318c
//   60062b1c usb_host_audio__60062b1c
// --- callees ---
//   600d56ae usb_host_worker__600d56ae


void FUN_600d571c(int param_1)

{
  *(undefined1 *)(*(int *)(param_1 + 0x108) + 1) = 0;
  usb_host_worker__600d56ae(param_1,1);
  return;
}



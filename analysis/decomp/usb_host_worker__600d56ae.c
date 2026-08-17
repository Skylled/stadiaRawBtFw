// 600d56ae  usb_host_worker__600d56ae  size=64 bytes
// src: usb_host_worker.cc
// --- callers ---
//   600d56b8 FUN_600d56b8
//   6006384c FUN_6006384c
//   600d571c FUN_600d571c
//   600d57d4 FUN_600d57d4
//   600637cc FUN_600637cc
//   6006318c usb_host_audio__6006318c
//   60063400 FUN_60063400
// --- callees ---
//   6013d0e8 thunk_EXT_FUN_00006a74
//   6010165c FUN_6010165c


/* src: usb_host_worker.cc */

void usb_host_worker__600d56ae(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_14;
  
  local_14 = *(undefined4 *)(param_1 + 0xe4);
  iVar1 = thunk_EXT_FUN_00006a74
                    (*(undefined4 *)(DAT_600652c8 + 0xb0),&local_14,0,0,local_14,
                     *(undefined4 *)(param_1 + 0xe8),param_2);
  if (iVar1 != 1) {
    FUN_6010165c(0x28,DAT_600652d0,0x1a,DAT_600652cc);
  }
  return;
}



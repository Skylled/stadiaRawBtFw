// 600d6658  FUN_600d6658  size=26 bytes
// --- callers ---
//   600644dc usb_host_audio_topology__600644dc
//   600d67e8 FUN_600d67e8
// --- callees ---
//   600d6634 FUN_600d6634
//   6013d068 thunk_EXT_FUN_0000b52e


void FUN_600d6658(int param_1)

{
  if (param_1 != 0) {
    FUN_600d6634(param_1,*(undefined4 *)(param_1 + 8));
    thunk_EXT_FUN_0000b52e(param_1,0x18);
    return;
  }
  return;
}



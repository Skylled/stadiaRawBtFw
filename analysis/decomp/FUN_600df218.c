// 600df218  FUN_600df218  size=12 bytes
// --- callers ---
//   6008099c state_machine__6008099c
//   600805e4 state_machine__600805e4
//   600df264 state_machine__600df264
// --- callees ---


undefined4 FUN_600df218(int param_1)

{
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  return *(undefined4 *)(param_1 + 4);
}



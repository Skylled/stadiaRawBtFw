// 600d8db2  FUN_600d8db2  size=30 bytes
// --- callers ---
//   600d7ad6 FUN_600d7ad6
// --- callees ---
//   6006b10c led_driver_lp5562__6006b10c


void FUN_600d8db2(int param_1,undefined4 param_2,undefined4 param_3)

{
  DataMemoryBarrier(0x1b);
  *(undefined1 *)(param_1 + 0x14) = 0;
  DataMemoryBarrier(0x1b);
  led_driver_lp5562__6006b10c(param_1,0,0,0,0,param_2,param_3);
  return;
}



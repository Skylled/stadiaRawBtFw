// 600d8d5a  FUN_600d8d5a  size=88 bytes
// --- callers ---
// --- callees ---
//   6006b10c led_driver_lp5562__6006b10c


void FUN_600d8d5a(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5)

{
  char cVar1;
  
  cVar1 = led_driver_lp5562__6006b10c();
  if (cVar1 == '\0') {
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x14) = 1;
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x10) = param_2;
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x11) = param_3;
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x12) = param_4;
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0x13) = param_5;
    DataMemoryBarrier(0x1b);
  }
  return;
}



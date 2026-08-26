// 600d49ce  FUN_600d49ce  size=10 bytes
// --- callers ---
//   60068a00 battery_gauge_bq2742X__60068a00
//   6006b3e8 usb_port_controller_tusb320__6006b3e8
//   600d6c76 FUN_600d6c76
// --- callees ---
//   6005fe04 io_pin__6005fe04


void FUN_600d49ce(int param_1)

{
  *(undefined1 *)(param_1 + 0x25) = 1;
  io_pin__6005fe04();
  return;
}



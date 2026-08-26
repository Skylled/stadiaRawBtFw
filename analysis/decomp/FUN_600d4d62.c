// 600d4d62  FUN_600d4d62  size=54 bytes
// --- callers ---
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   6005fe04 io_pin__6005fe04


undefined4 FUN_600d4d62(int param_1)

{
  io_pin__6005fe04(param_1 + 4);
  io_pin__6005fe04(param_1 + 0x30);
  io_pin__6005fe04(param_1 + 0x5c);
  if (*(char *)(param_1 + 0x88) != '\0') {
    io_pin__6005fe04(param_1 + 0x8c);
  }
  io_pin__6005fe04(param_1 + 0xb8);
  return 0;
}



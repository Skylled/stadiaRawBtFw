// 600efd62  FUN_600efd62  size=44 bytes
// --- callers ---
//   60095df4 FUN_60095df4
// --- callees ---
//   600d9310 FUN_600d9310


void FUN_600efd62(int param_1,ushort param_2,undefined1 param_3)

{
  FUN_600d9310(param_1);
  *(uint *)(param_1 + 0xc) = (uint)param_2;
  *(undefined1 *)(param_1 + 0x14) = param_3;
  return;
}



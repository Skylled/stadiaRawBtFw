// 600db9bc  FUN_600db9bc  size=24 bytes
// --- callers ---
// --- callees ---
//   600db8e8 FUN_600db8e8


void FUN_600db9bc(int param_1)

{
  DataMemoryBarrier(0x1b);
  *(undefined1 *)(param_1 + 0x94a) = 1;
  DataMemoryBarrier(0x1b);
  FUN_600db8e8();
  return;
}



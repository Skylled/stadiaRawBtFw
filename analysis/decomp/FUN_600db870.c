// 600db870  FUN_600db870  size=16 bytes
// --- callers ---
//   600db8d8 FUN_600db8d8
// --- callees ---


void FUN_600db870(int param_1)

{
  DataMemoryBarrier(0x1b);
  *(undefined1 *)(param_1 + 0x60) = 0;
  DataMemoryBarrier(0x1b);
  return;
}



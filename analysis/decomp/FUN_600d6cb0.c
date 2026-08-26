// 600d6cb0  FUN_600d6cb0  size=26 bytes
// --- callers ---
// --- callees ---
//   600926a0 FUN_600926a0


void FUN_600d6cb0(int param_1,int param_2)

{
  DataMemoryBarrier(0x1b);
  *(byte *)(param_1 + 0xcc) = (byte)param_2 ^ 1;
  DataMemoryBarrier(0x1b);
  if (param_2 != 0) {
    FUN_600926a0(param_1 + 0x68);
    return;
  }
  return;
}



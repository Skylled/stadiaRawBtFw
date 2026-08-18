// 600cfb42  FUN_600cfb42  size=14 bytes
// --- callers ---
//   600607b8 FUN_600607b8
//   60060804 srtc__60060804
// --- callees ---


void FUN_600cfb42(int param_1,int param_2)

{
  if (param_2 << 0x1d < 0) {
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 1;
  }
  return;
}



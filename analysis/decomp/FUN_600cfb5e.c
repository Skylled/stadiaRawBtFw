// 600cfb5e  FUN_600cfb5e  size=14 bytes
// --- callers ---
//   60060940 FUN_60060940
// --- callees ---


void FUN_600cfb5e(int param_1,int param_2)

{
  if (param_2 << 0x1d < 0) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) & 0xfffffffd;
  }
  return;
}



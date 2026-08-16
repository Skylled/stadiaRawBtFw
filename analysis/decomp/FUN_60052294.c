// 60052294  FUN_60052294  size=32 bytes
// --- callers ---
//   600522b8 FUN_600522b8
// --- callees ---


void FUN_60052294(uint param_1,int param_2)

{
  *(uint *)(DAT_600522b4 + (param_1 >> 8) * 4) =
       *(uint *)(DAT_600522b4 + (param_1 >> 8) * 4) & ~(3 << (param_1 & 0x1f)) |
       param_2 << (param_1 & 0x1f);
  return;
}



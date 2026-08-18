// 600cf224  FUN_600cf224  size=16 bytes
// --- callers ---
//   60053b50 FUN_60053b50
// --- callees ---


uint FUN_600cf224(int param_1)

{
  return *(uint *)(param_1 + 0x28) >> 0x10 & 0xc3 | *(uint *)(param_1 + 0x14);
}



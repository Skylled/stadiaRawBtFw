// 600cfafe  FUN_600cfafe  size=20 bytes
// --- callers ---
//   600607b8 FUN_600607b8
// --- callees ---


uint FUN_600cfafe(int param_1)

{
  uint uVar1;
  
  uVar1 = (*(uint *)(param_1 + 0x14) & 3) >> 1;
  if (*(int *)(param_1 + 0x14) << 0x1f < 0) {
    uVar1 = uVar1 | 2;
  }
  return uVar1;
}



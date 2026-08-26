// 600d800e  FUN_600d800e  size=6 bytes
// --- callers ---
//   60067f20 FUN_60067f20
//   600d80d0 FUN_600d80d0
// --- callees ---


uint FUN_600d800e(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  return uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
}



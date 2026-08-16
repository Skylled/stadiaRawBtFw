// 600e6a6c  FUN_600e6a6c  size=36 bytes
// --- callers ---
//   6008c0d8 bcm__6008c0d8
//   600e9bc2 FUN_600e9bc2
// --- callees ---


undefined4 FUN_600e6a6c(int param_1)

{
  undefined4 uVar1;
  
  if (0x29f < param_1) {
    return 6;
  }
  if (0xef < param_1) {
    return 5;
  }
  if (0x4f < param_1) {
    return 4;
  }
  if (param_1 < 0x18) {
    uVar1 = 1;
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}



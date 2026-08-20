// 600e9ba8  FUN_600e9ba8  size=26 bytes
// --- callers ---
//   600eafdc FUN_600eafdc
//   600e9dea FUN_600e9dea
//   6008e264 bcm__6008e264
//   600e9bc2 FUN_600e9bc2
//   600eb75a FUN_600eb75a
// --- callees ---


uint FUN_600e9ba8(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (param_3 >> 5 < param_2) {
    uVar1 = *(uint *)(param_1 + (param_3 >> 5) * 4) >> (param_3 & 0x1f) & 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



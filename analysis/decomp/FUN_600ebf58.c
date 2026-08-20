// 600ebf58  FUN_600ebf58  size=12 bytes
// --- callers ---
//   6008eb24 bcm__6008eb24
// --- callees ---


uint FUN_600ebf58(int *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*param_1 != 0) {
    uVar1 = *(uint *)(*param_1 + 0x28) & 1;
  }
  return uVar1;
}



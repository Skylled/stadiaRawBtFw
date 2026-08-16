// 600e7706  FUN_600e7706  size=18 bytes
// --- callers ---
//   6008e700 bcm__6008e700
//   6008e264 bcm__6008e264
//   6008c5fc bcm__6008c5fc
//   6008c0d8 bcm__6008c0d8
//   6008c334 bcm__6008c334
//   60086824 FUN_60086824
//   6008d120 bcm__6008d120
//   6008b970 bcm__6008b970
// --- callees ---


uint FUN_600e7706(undefined4 *param_1)

{
  uint uVar1;
  
  if ((int)param_1[1] < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)*param_1 & 1;
  }
  return uVar1;
}



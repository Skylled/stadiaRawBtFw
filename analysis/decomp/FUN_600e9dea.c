// 600e9dea  FUN_600e9dea  size=16 bytes
// --- callers ---
//   6008e264 bcm__6008e264
//   6008c334 bcm__6008c334
//   6008c5fc bcm__6008c5fc
//   6008c0d8 bcm__6008c0d8
// --- callees ---
//   600e9ba8 FUN_600e9ba8


undefined4 FUN_600e9dea(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (-1 < param_2) {
    uVar1 = FUN_600e9ba8(*param_1,param_1[1]);
    return uVar1;
  }
  return 0;
}



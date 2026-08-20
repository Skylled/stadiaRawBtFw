// 600e7372  FUN_600e7372  size=16 bytes
// --- callers ---
//   600e7668 FUN_600e7668
//   6008e264 bcm__6008e264
//   600e75de FUN_600e75de
// --- callees ---
//   600e7356 FUN_600e7356


undefined4 FUN_600e7372(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = FUN_600e7356();
    return uVar1;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return 1;
}



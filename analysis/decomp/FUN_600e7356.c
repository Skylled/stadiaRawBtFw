// 600e7356  FUN_600e7356  size=28 bytes
// --- callers ---
//   600e7382 FUN_600e7382
//   600e7372 FUN_600e7372
// --- callees ---
//   6008b43c bcm__6008b43c


void FUN_600e7356(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = bcm__6008b43c(param_1,1,param_3,param_4,param_4);
  if (iVar1 != 0) {
    param_1[3] = 0;
    *(undefined4 *)*param_1 = param_2;
    param_1[1] = 1;
  }
  return;
}



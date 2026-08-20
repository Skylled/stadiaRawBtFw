// 600e7ccc  FUN_600e7ccc  size=20 bytes
// --- callers ---
//   600e7ce0 FUN_600e7ce0
//   6008e700 bcm__6008e700
//   600e7d36 FUN_600e7d36
// --- callees ---
//   600e7480 FUN_600e7480
//   6008b60c bcm__6008b60c


bool FUN_600e7ccc(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = bcm__6008b60c();
  if (iVar1 != 0) {
    FUN_600e7480(param_1);
  }
  return iVar1 != 0;
}



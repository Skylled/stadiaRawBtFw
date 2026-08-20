// 600e7598  FUN_600e7598  size=42 bytes
// --- callers ---
//   6008e264 bcm__6008e264
//   600e76ee FUN_600e76ee
//   6008c334 bcm__6008c334
//   6008c0d8 bcm__6008c0d8
// --- callees ---


bool FUN_600e7598(undefined4 *param_1,uint param_2)

{
  int iVar1;
  
  if (param_1[1] != 0) {
    param_2 = *(uint *)*param_1 ^ param_2;
    for (iVar1 = 1; iVar1 < (int)param_1[1]; iVar1 = iVar1 + 1) {
      param_2 = param_2 | ((uint *)*param_1)[iVar1];
    }
  }
  return param_2 == 0;
}



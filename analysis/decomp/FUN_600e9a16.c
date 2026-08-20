// 600e9a16  FUN_600e9a16  size=42 bytes
// --- callers ---
//   6008e264 bcm__6008e264
// --- callees ---
//   600e994c FUN_600e994c
//   600e7480 FUN_600e7480
//   6008b43c bcm__6008b43c


bool FUN_600e9a16(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = bcm__6008b43c(param_1,param_2[1],param_3,param_4,param_4);
  if (iVar1 != 0) {
    FUN_600e994c(*param_1,*param_2,param_2[1]);
    param_1[1] = param_2[1];
    param_1[3] = param_2[3];
    FUN_600e7480(param_1);
  }
  return iVar1 != 0;
}



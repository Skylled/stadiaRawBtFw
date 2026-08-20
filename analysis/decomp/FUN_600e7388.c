// 600e7388  FUN_600e7388  size=36 bytes
// --- callers ---
//   6008bf44 bcm__6008bf44
// --- callees ---
//   6008b43c bcm__6008b43c
//   600e6a1a FUN_600e6a1a


bool FUN_600e7388(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = bcm__6008b43c(param_1,param_3);
  if (iVar1 != 0) {
    FUN_600e6a1a(*param_1,param_2,param_3 << 2);
    param_1[1] = param_3;
    param_1[3] = 0;
  }
  return iVar1 != 0;
}



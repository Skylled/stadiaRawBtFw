// 600eda00  FUN_600eda00  size=28 bytes
// --- callers ---
//   60091160 FUN_60091160
// --- callees ---
//   60090dd8 bn_asn1__60090dd8
//   6008b384 bcm__6008b384


void FUN_600eda00(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_r2;
  
  iVar1 = bcm__6008b384();
  *param_2 = iVar1;
  if (iVar1 != 0) {
    bn_asn1__60090dd8(param_1,iVar1,extraout_r2,param_4);
    return;
  }
  return;
}



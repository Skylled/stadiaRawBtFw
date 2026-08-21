// 600ece3c  FUN_600ece3c  size=36 bytes
// --- callers ---
//   60090e6c bn_asn1__60090e6c
//   600917a0 ec_asn1__600917a0
// --- callees ---
//   600e7504 FUN_600e7504
//   600ed10a FUN_600ed10a


undefined4 FUN_600ece3c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_14 = param_2;
  uStack_10 = param_3;
  iVar1 = FUN_600ed10a(param_1,&local_14,param_2,param_4,param_1);
  uVar2 = 0;
  if ((iVar1 != 0) && (iVar1 = FUN_600e7504(local_14,param_2,param_3), uVar2 = 0, iVar1 != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



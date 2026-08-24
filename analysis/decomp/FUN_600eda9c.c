// 600eda9c  FUN_600eda9c  size=86 bytes
// --- callers ---
//   60085470 FUN_60085470
//   600917a0 ec_asn1__600917a0
// --- callees ---
//   600ed10a FUN_600ed10a
//   6008d5e0 bcm__6008d5e0


bool FUN_600eda9c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_24 [2];
  
  iVar1 = bcm__6008d5e0(param_2,param_3,param_4,0,0,param_5);
  if ((iVar1 == 0) || (iVar2 = FUN_600ed10a(param_1,local_24,iVar1), iVar2 == 0)) {
    bVar3 = false;
  }
  else {
    iVar2 = bcm__6008d5e0(param_2,param_3,param_4,local_24[0],iVar1,param_5);
    bVar3 = iVar2 == iVar1;
  }
  return bVar3;
}



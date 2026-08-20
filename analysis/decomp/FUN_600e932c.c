// 600e932c  FUN_600e932c  size=66 bytes
// --- callers ---
//   6008c334 bcm__6008c334
//   6008c0d8 bcm__6008c0d8
//   600e936e FUN_600e936e
// --- callees ---
//   600e7718 FUN_600e7718
//   6008b738 bcm__6008b738
//   600e77c0 FUN_600e77c0
//   600e72fc FUN_600e72fc
//   6008b570 bcm__6008b570


undefined4 FUN_600e932c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  
  FUN_600e7718(param_4);
  iVar1 = bcm__6008b570(param_4);
  if ((iVar1 == 0) || (iVar2 = FUN_600e72fc(iVar1,param_2), iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = bcm__6008b738(param_1,iVar1,param_3);
  }
  FUN_600e77c0(param_4,uVar3);
  return extraout_r1;
}



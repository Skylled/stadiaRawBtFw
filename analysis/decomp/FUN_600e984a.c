// 600e984a  FUN_600e984a  size=90 bytes
// --- callers ---
//   6008e264 bcm__6008e264
//   6008e700 bcm__6008e700
// --- callees ---
//   600e94b6 FUN_600e94b6
//   600e77c0 FUN_600e77c0
//   600e966c FUN_600e966c
//   600e7718 FUN_600e7718
//   6008b570 bcm__6008b570
//   6008bf00 FUN_6008bf00


undefined4
FUN_600e984a(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  bool bVar3;
  
  FUN_600e7718(param_5);
  iVar1 = bcm__6008b570(param_5);
  if (iVar1 != 0) {
    if (param_2 == param_3) {
      iVar2 = FUN_600e966c(iVar1,param_2,param_5);
    }
    else {
      iVar2 = FUN_600e94b6(iVar1,param_2,param_3,param_5);
    }
    if (iVar2 != 0) {
      iVar1 = FUN_6008bf00(param_1,iVar1,param_4,param_5);
      bVar3 = iVar1 != 0;
      goto LAB_600e9868;
    }
  }
  bVar3 = false;
LAB_600e9868:
  FUN_600e77c0(param_5,bVar3);
  return extraout_r1;
}



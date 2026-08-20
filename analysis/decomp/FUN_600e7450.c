// 600e7450  FUN_600e7450  size=36 bytes
// --- callers ---
//   6008e264 bcm__6008e264
//   60086824 FUN_60086824
//   600e0822 FUN_600e0822
//   6008bbdc bcm__6008bbdc
//   600eb7ce FUN_600eb7ce
//   6008d120 bcm__6008d120
//   600eafdc FUN_600eafdc
//   60090e6c bn_asn1__60090e6c
//   600e7474 FUN_600e7474
//   600e9b1c FUN_600e9b1c
//   6008c0d8 bcm__6008c0d8
//   600e97de FUN_600e97de
// --- callees ---
//   600e7276 FUN_600e7276
//   600e7434 FUN_600e7434


int FUN_600e7450(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_600e7434();
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = FUN_600e7276(*(undefined4 *)(*param_1 + (iVar1 + 0x3fffffff) * 4));
    iVar2 = iVar2 + (iVar1 + -1) * 0x20;
  }
  return iVar2;
}



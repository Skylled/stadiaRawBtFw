// 600e9b62  FUN_600e9b62  size=70 bytes
// --- callers ---
//   6008c0d8 bcm__6008c0d8
//   6008c334 bcm__6008c334
// --- callees ---
//   600e9b1c FUN_600e9b1c
//   6008b4b8 bcm__6008b4b8
//   600e92f0 FUN_600e92f0
//   6008b970 bcm__6008b970
//   600e92ca FUN_600e92ca


int FUN_600e9b62(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_600e92ca();
  if ((((iVar1 == 0) || (iVar2 = bcm__6008b970(iVar1,param_1), iVar2 == 0)) ||
      (iVar2 = FUN_600e9b1c(iVar1,*(int *)(iVar1 + 0x18) << 6,iVar1 + 0x14,param_2), iVar2 == 0)) ||
     (iVar2 = bcm__6008b4b8(iVar1,*(undefined4 *)(iVar1 + 0x18)), iVar2 == 0)) {
    FUN_600e92f0(iVar1);
    iVar1 = 0;
  }
  return iVar1;
}



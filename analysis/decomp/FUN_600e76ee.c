// 600e76ee  FUN_600e76ee  size=24 bytes
// --- callers ---
//   6008e264 bcm__6008e264
//   6008c5fc bcm__6008c5fc
//   600e94ca FUN_600e94ca
// --- callees ---
//   600e7598 FUN_600e7598


undefined4 FUN_600e76ee(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = FUN_600e7598(param_1,1,param_3,0,param_4);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



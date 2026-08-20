// 600e7ce0  FUN_600e7ce0  size=86 bytes
// --- callers ---
//   6008e264 bcm__6008e264
// --- callees ---
//   600e7ccc FUN_600e7ccc
//   600e7548 FUN_600e7548
//   600e7b82 FUN_600e7b82


undefined4 FUN_600e7ce0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_2 + 0xc);
  iVar4 = *(int *)(param_3 + 0xc);
  if (iVar4 == iVar2) {
    uVar1 = FUN_600e7b82();
    *(int *)(param_1 + 0xc) = iVar4;
  }
  else {
    iVar4 = param_2;
    iVar3 = param_3;
    if (iVar2 != 0) {
      iVar4 = param_3;
      iVar3 = param_2;
    }
    iVar2 = FUN_600e7548(iVar4,iVar3,param_3,iVar2,param_4);
    if (iVar2 < 0) {
      iVar2 = FUN_600e7ccc(param_1,iVar3,iVar4);
      if (iVar2 != 0) {
        *(undefined4 *)(param_1 + 0xc) = 1;
        return 1;
      }
    }
    else {
      iVar2 = FUN_600e7ccc(param_1,iVar4,iVar3);
      if (iVar2 != 0) {
        *(undefined4 *)(param_1 + 0xc) = 0;
        return 1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



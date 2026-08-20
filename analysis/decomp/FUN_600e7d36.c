// 600e7d36  FUN_600e7d36  size=98 bytes
// --- callers ---
//   6008e264 bcm__6008e264
//   6008d7ac bcm__6008d7ac
// --- callees ---
//   600e7ccc FUN_600e7ccc
//   600e7548 FUN_600e7548
//   600e7b82 FUN_600e7b82


undefined4 FUN_600e7d36(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_3 + 0xc);
  if (*(int *)(param_2 + 0xc) == 0) {
    uVar4 = 0;
    iVar2 = param_3;
    iVar3 = param_2;
    if (iVar1 == 0) goto LAB_600e7d62;
  }
  else {
    iVar2 = param_2;
    iVar3 = param_3;
    if (iVar1 != 0) {
LAB_600e7d62:
      iVar1 = FUN_600e7548(iVar3,iVar2,param_3,iVar1,param_4);
      if (-1 < iVar1) {
        iVar1 = FUN_600e7ccc(param_1,iVar3,iVar2);
        if (iVar1 != 0) {
          *(undefined4 *)(param_1 + 0xc) = 0;
          return 1;
        }
        return 0;
      }
      iVar1 = FUN_600e7ccc(param_1,iVar2,iVar3);
      if (iVar1 == 0) {
        return 0;
      }
      *(undefined4 *)(param_1 + 0xc) = 1;
      return 1;
    }
    uVar4 = 1;
  }
  iVar1 = FUN_600e7b82(param_1,param_2,param_3);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0xc) = uVar4;
  return 1;
}



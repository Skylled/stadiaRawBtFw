// 600e936e  FUN_600e936e  size=92 bytes
// --- callers ---
//   6008c334 bcm__6008c334
// --- callees ---
//   6008b43c bcm__6008b43c
//   600e932c FUN_600e932c


undefined4 FUN_600e936e(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  if ((0 < *(int *)(param_2 + 0x18)) &&
     (*(int *)(*(int *)(param_2 + 0x14) + (*(int *)(param_2 + 0x18) + 0x3fffffff) * 4) < 0)) {
    iVar1 = bcm__6008b43c();
    uVar3 = 0;
    if (iVar1 != 0) {
      piVar2 = *(int **)(param_2 + 0x14);
      piVar5 = (int *)*param_1;
      iVar1 = *(int *)(param_2 + 0x18);
      *piVar5 = -*piVar2;
      for (iVar4 = 1; iVar4 < iVar1; iVar4 = iVar4 + 1) {
        piVar5[iVar4] = ~piVar2[iVar4];
      }
      uVar3 = 1;
      param_1[1] = iVar1;
      param_1[3] = 0;
    }
    return uVar3;
  }
  uVar3 = FUN_600e932c(param_1,param_2,param_2,param_3);
  return uVar3;
}



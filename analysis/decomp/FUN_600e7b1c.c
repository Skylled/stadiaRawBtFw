// 600e7b1c  FUN_600e7b1c  size=102 bytes
// --- callers ---
//   600e7b82 FUN_600e7b82
// --- callees ---
//   600e7a32 FUN_600e7a32
//   6008b43c bcm__6008b43c


undefined4 FUN_600e7b1c(int *param_1,int *param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  
  iVar4 = param_2[1];
  piVar6 = (int *)param_3[1];
  piVar8 = param_3;
  piVar1 = piVar6;
  if ((int)piVar6 <= iVar4) {
    piVar8 = param_2;
    piVar1 = param_3;
  }
  iVar10 = piVar8[1];
  if ((int)piVar6 <= iVar4) {
    param_2 = piVar1;
  }
  iVar9 = param_2[1];
  iVar4 = bcm__6008b43c(param_1,iVar10 + 1,iVar4,piVar1,param_4);
  uVar3 = 0;
  if (iVar4 != 0) {
    iVar5 = *param_2;
    iVar4 = *piVar8;
    param_1[1] = iVar10 + 1;
    uVar2 = FUN_600e7a32(*param_1,iVar4,iVar5,iVar9);
    iVar4 = *param_1;
    iVar5 = iVar9 << 2;
    for (; iVar9 < iVar10; iVar9 = iVar9 + 1) {
      iVar7 = *(uint *)(*piVar8 + iVar5) + uVar2;
      uVar2 = (uint)CARRY4(*(uint *)(*piVar8 + iVar5),uVar2);
      *(int *)(iVar4 + iVar5) = iVar7;
      iVar5 = iVar5 + 4;
    }
    *(uint *)(iVar4 + iVar10 * 4) = uVar2;
    uVar3 = 1;
  }
  return uVar3;
}



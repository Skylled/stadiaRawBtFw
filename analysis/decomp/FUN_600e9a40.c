// 600e9a40  FUN_600e9a40  size=78 bytes
// --- callers ---
//   600e9b1c FUN_600e9b1c
//   600e9a8e FUN_600e9a8e
// --- callees ---
//   6008b43c bcm__6008b43c


undefined4 FUN_600e9a40(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((int)param_2 < 0) {
LAB_600e9a48:
    uVar1 = 0;
  }
  else {
    iVar5 = (int)param_2 >> 5;
    if (param_1[1] <= iVar5) {
      iVar2 = bcm__6008b43c(param_1,iVar5 + 1,param_3,param_1[1],param_4);
      if (iVar2 == 0) goto LAB_600e9a48;
      iVar4 = param_1[1];
      iVar2 = *param_1;
      iVar3 = iVar4 << 2;
      for (; iVar4 <= iVar5; iVar4 = iVar4 + 1) {
        *(undefined4 *)(iVar2 + iVar3) = 0;
        iVar3 = iVar3 + 4;
      }
      param_1[1] = iVar5 + 1;
    }
    uVar1 = 1;
    *(uint *)(*param_1 + iVar5 * 4) = *(uint *)(*param_1 + iVar5 * 4) | 1 << (param_2 & 0x1f);
  }
  return uVar1;
}



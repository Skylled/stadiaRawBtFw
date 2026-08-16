// 6008b60c  bcm__6008b60c  size=152 bytes
// src: bcm.c
// --- callers ---
//   6008eb24 bcm__6008eb24
//   600e7ccc FUN_600e7ccc
// --- callees ---
//   600e7c2c FUN_600e7c2c
//   6008b43c bcm__6008b43c
//   600e72d2 FUN_600e72d2
//   600e0552 FUN_600e0552


/* src: bcm.c */

undefined4 bcm__6008b60c(int *param_1,int *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_2[1];
  iVar5 = param_3[1];
  if ((iVar6 < (int)param_3[1]) &&
     (iVar1 = FUN_600e72d2(param_3,iVar6,param_3,param_4,param_1,param_2,param_3), iVar5 = iVar6,
     iVar1 == 0)) {
    FUN_600e0552(3,0,100,DAT_6008b6a4,0xe8);
    uVar4 = 0;
  }
  else {
    iVar6 = bcm__6008b43c(param_1,iVar6);
    uVar4 = 0;
    if (iVar6 != 0) {
      uVar2 = FUN_600e7c2c(*param_1,*param_2,*param_3,iVar5);
      iVar6 = param_2[1];
      iVar1 = iVar5 << 2;
      for (; iVar5 < iVar6; iVar5 = iVar5 + 1) {
        uVar3 = *(uint *)(*param_2 + iVar1);
        *(uint *)(*param_1 + iVar1) = uVar3 - uVar2;
        uVar2 = (uint)(uVar3 < uVar2);
        iVar1 = iVar1 + 4;
      }
      if (uVar2 == 0) {
        param_1[1] = iVar6;
        uVar4 = 1;
        param_1[3] = 0;
      }
      else {
        uVar4 = 0;
        FUN_600e0552(3,0,100,DAT_6008b6a4,0xfb);
      }
    }
  }
  return uVar4;
}



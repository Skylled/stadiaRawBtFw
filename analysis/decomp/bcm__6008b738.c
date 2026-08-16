// 6008b738  bcm__6008b738  size=94 bytes
// src: bcm.c
// --- callers ---
//   6008ba20 bcm__6008ba20
//   600e932c FUN_600e932c
// --- callees ---
//   6008b43c bcm__6008b43c
//   6008b6a8 bcm__6008b6a8
//   600e0552 FUN_600e0552
//   6008b4b8 bcm__6008b4b8


/* src: bcm.c */

undefined4 bcm__6008b738(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2[3] == 0) {
    if (*(int *)(param_3 + 0x18) == 0) {
      param_1[1] = 0;
      uVar2 = 1;
    }
    else {
      iVar1 = bcm__6008b4b8(param_2,*(int *)(param_3 + 0x18) << 1,param_3,param_4,param_1,param_2,
                            param_3);
      uVar2 = 0;
      if ((iVar1 != 0) &&
         (iVar1 = bcm__6008b43c(param_1,*(undefined4 *)(param_3 + 0x18)), iVar1 != 0)) {
        uVar2 = *(undefined4 *)(param_3 + 0x18);
        param_1[1] = uVar2;
        param_1[3] = 0;
        uVar2 = bcm__6008b6a8(*param_1,uVar2,*param_2,param_2[1],param_3);
      }
    }
  }
  else {
    uVar2 = 0;
    FUN_600e0552(3,0,0x6d,DAT_6008b798,0x142);
  }
  return uVar2;
}



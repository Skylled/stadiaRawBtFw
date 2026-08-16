// 6008bb90  bcm__6008bb90  size=72 bytes
// src: bcm.c
// --- callers ---
//   6008e264 bcm__6008e264
//   6008bbdc bcm__6008bbdc
//   6008c5fc bcm__6008c5fc
// --- callees ---
//   6008b43c bcm__6008b43c
//   600e9760 FUN_600e9760
//   600e0552 FUN_600e0552
//   600e7480 FUN_600e7480


/* src: bcm.c */

undefined4 bcm__6008bb90(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 < 0) {
    FUN_600e0552(3,0,0x6d,DAT_6008bbd8,0x9e);
    uVar1 = 0;
  }
  else {
    iVar2 = bcm__6008b43c(param_1,param_2[1],param_3,param_4,param_1,param_2);
    uVar1 = 0;
    if (iVar2 != 0) {
      FUN_600e9760(*param_1,*param_2,param_3,param_2[1]);
      param_1[3] = param_2[3];
      param_1[1] = param_2[1];
      FUN_600e7480(param_1);
      uVar1 = 1;
    }
  }
  return uVar1;
}



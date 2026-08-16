// 6008b43c  bcm__6008b43c  size=118 bytes
// src: bcm.c
// --- callers ---
//   600e7efe FUN_600e7efe
//   600e7668 FUN_600e7668
//   600e7766 FUN_600e7766
//   6008e164 bcm__6008e164
//   6008b60c bcm__6008b60c
//   600e7388 FUN_600e7388
//   6008bbdc bcm__6008bbdc
//   600e9a40 FUN_600e9a40
//   6008b738 bcm__6008b738
//   600e7490 FUN_600e7490
//   600e73ac FUN_600e73ac
//   600e936e FUN_600e936e
//   600e7b1c FUN_600e7b1c
//   6008bae0 bcm__6008bae0
//   600e7e0e FUN_600e7e0e
//   600e89f8 FUN_600e89f8
//   600e98c6 FUN_600e98c6
//   600e9a16 FUN_600e9a16
//   6008bb90 bcm__6008bb90
//   6008c0d8 bcm__6008c0d8
//   6008b79c bcm__6008b79c
//   600e72fc FUN_600e72fc
//   600e957c FUN_600e957c
//   6008b4b8 bcm__6008b4b8
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e092c FUN_600e092c
//   600e0552 FUN_600e0552


/* src: bcm.c */

undefined4 bcm__6008b43c(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if ((uint)param_1[2] < param_2) {
    if (param_2 < 0x1000000) {
      if ((param_1[4] & 2U) == 0) {
        uVar5 = param_2;
        iVar1 = FUN_600e092c(param_2 << 2);
        if (iVar1 == 0) {
          FUN_600e0552(3,0,0x41,DAT_6008b4b4,0x16d,uVar5,param_3);
          return 0;
        }
        thunk_EXT_FUN_0000af88(iVar1,*param_1,param_1[1] << 2);
        thunk_EXT_FUN_0000ac5e(*param_1);
        *param_1 = iVar1;
        param_1[2] = param_2;
        goto LAB_6008b4ae;
      }
      uVar2 = 0x6a;
      uVar4 = 0x167;
    }
    else {
      uVar2 = 0x66;
      uVar4 = 0x162;
    }
    uVar3 = 0;
    FUN_600e0552(3,0,uVar2,DAT_6008b4b4,uVar4,param_2,param_3);
  }
  else {
LAB_6008b4ae:
    uVar3 = 1;
  }
  return uVar3;
}



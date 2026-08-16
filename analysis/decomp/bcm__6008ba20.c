// 6008ba20  bcm__6008ba20  size=120 bytes
// src: bcm.c
// --- callers ---
//   6008c0d8 bcm__6008c0d8
//   600e965c FUN_600e965c
//   6008c334 bcm__6008c334
// --- callees ---
//   600e77c0 FUN_600e77c0
//   600e7718 FUN_600e7718
//   6008b570 bcm__6008b570
//   6008b9f0 bcm__6008b9f0
//   6008b738 bcm__6008b738
//   600e0552 FUN_600e0552
//   600e957c FUN_600e957c


/* src: bcm.c */

undefined4
bcm__6008ba20(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  bool bVar3;
  undefined4 uVar4;
  
  if ((*(int *)(param_2 + 0xc) != 0) || (*(int *)(param_3 + 0xc) != 0)) {
    FUN_600e0552(3,0,0x6d,DAT_6008ba98,0x1a4,param_2);
    return 0;
  }
  uVar4 = param_1;
  FUN_600e7718(param_5);
  iVar1 = bcm__6008b570(param_5);
  if (iVar1 != 0) {
    if (param_2 == param_3) {
      iVar2 = FUN_600e957c(iVar1,param_2,param_5);
    }
    else {
      iVar2 = bcm__6008b9f0(iVar1,param_2,param_3,param_5,uVar4);
    }
    if (iVar2 != 0) {
      iVar1 = bcm__6008b738(param_1,iVar1,param_4);
      bVar3 = iVar1 != 0;
      goto LAB_6008ba62;
    }
  }
  bVar3 = false;
LAB_6008ba62:
  FUN_600e77c0(param_5,bVar3);
  return extraout_r1;
}



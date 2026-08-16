// 6008da3c  bcm__6008da3c  size=52 bytes
// src: bcm.c
// --- callers ---
//   6008db50 bcm__6008db50
// --- callees ---
//   600e0552 FUN_600e0552
//   600eb428 FUN_600eb428
//   600eb1d4 FUN_600eb1d4


/* src: bcm.c */

undefined4
bcm__6008da3c(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600eb428(param_1,*param_2,param_3,param_4,param_1,param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = FUN_600eb1d4(param_1,param_2 + 1);
    return uVar2;
  }
  FUN_600e0552(0xf,0,0x6a,DAT_6008da70,0x2ee);
  return 0;
}



// 6008d6f8  bcm__6008d6f8  size=52 bytes
// src: bcm.c
// --- callers ---
//   6008db50 bcm__6008db50
//   6008d730 bcm__6008d730
// --- callees ---
//   600eb280 FUN_600eb280
//   600e0552 FUN_600e0552
//   600eb428 FUN_600eb428


/* src: bcm.c */

undefined4
bcm__6008d6f8(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600eb428(param_1,*param_2,param_3,param_4,param_1,param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = FUN_600eb280(param_1,param_2 + 1);
    return uVar2;
  }
  FUN_600e0552(0xf,0,0x6a,DAT_6008d72c,0x2f7);
  return 0;
}



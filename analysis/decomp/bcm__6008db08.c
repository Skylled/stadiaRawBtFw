// 6008db08  bcm__6008db08  size=68 bytes
// src: bcm.c
// --- callers ---
//   6008db50 bcm__6008db50
//   600e084e FUN_600e084e
// --- callees ---
//   600e0552 FUN_600e0552
//   600eb370 FUN_600eb370
//   600eb428 FUN_600eb428


/* src: bcm.c */

undefined4
bcm__6008db08(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600eb428(param_1,*param_2,param_3,param_4,param_1,param_2);
  if ((iVar1 == 0) && (iVar1 = FUN_600eb428(param_1,*param_3), iVar1 == 0)) {
    uVar2 = FUN_600eb370(param_1,param_2 + 1,param_3 + 1);
    return uVar2;
  }
  FUN_600e0552(0xf,0,0x6a,DAT_6008db4c,0x301);
  return 0xffffffff;
}



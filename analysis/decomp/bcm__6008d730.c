// 6008d730  bcm__6008d730  size=118 bytes
// src: bcm.c
// --- callers ---
//   6008e700 bcm__6008e700
//   6008d7ac bcm__6008d7ac
//   6008e910 bcm__6008e910
// --- callees ---
//   6008d300 bcm__6008d300
//   6008d6f8 bcm__6008d6f8
//   600e0552 FUN_600e0552
//   600eb428 FUN_600eb428
//   600eafb4 FUN_600eafb4


/* src: bcm.c */

undefined4
bcm__6008d730(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600eb428(param_1,*param_2,param_3,param_4,param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = bcm__6008d300(param_1,param_2 + 1,param_3,param_4);
    uVar2 = 0;
    if (iVar1 != 0) {
      iVar1 = bcm__6008d6f8(param_1,param_2,param_5);
      if (iVar1 == 0) {
        if (*(int *)(param_1 + 4) != 0) {
          FUN_600eafb4(param_2 + 1,*(int *)(param_1 + 4) + 4);
        }
        FUN_600e0552(0xf,0,0x78,DAT_6008d7a8,0x332);
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  else {
    uVar2 = 0;
    FUN_600e0552(0xf,0,0x6a,DAT_6008d7a8,0x321);
  }
  return uVar2;
}



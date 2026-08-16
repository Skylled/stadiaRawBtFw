// 6008da74  bcm__6008da74  size=56 bytes
// src: bcm.c
// --- callers ---
//   600eb450 FUN_600eb450
// --- callees ---
//   600e0552 FUN_600e0552
//   600eb428 FUN_600eb428
//   600eafb4 FUN_600eafb4


/* src: bcm.c */

undefined4
bcm__6008da74(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600eb428(*param_1,*param_2,param_3,param_4,param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (param_1 != param_2) {
      FUN_600eafb4(param_1 + 1,param_2 + 1);
    }
    uVar2 = 1;
  }
  else {
    FUN_600e0552(0xf,0,0x6a,DAT_6008daac,0x2ca);
    uVar2 = 0;
  }
  return uVar2;
}



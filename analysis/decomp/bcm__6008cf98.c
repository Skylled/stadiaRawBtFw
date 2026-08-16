// 6008cf98  bcm__6008cf98  size=54 bytes
// src: bcm.c
// --- callers ---
//   6008cfd4 bcm__6008cfd4
// --- callees ---
//   600e0552 FUN_600e0552
//   600e7588 FUN_600e7588
//   6008b3d4 bcm__6008b3d4


/* src: bcm.c */

undefined4 bcm__6008cf98(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = bcm__6008b3d4(param_2,*(undefined4 *)(param_1 + 0xc),param_3,param_4,param_1,param_2,
                        param_3);
  if ((iVar1 == 0) ||
     (iVar1 = FUN_600e7588(param_2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc)),
     iVar1 == 0)) {
    FUN_600e0552(0xf,0,0x85,DAT_6008cfd0,0x1c);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



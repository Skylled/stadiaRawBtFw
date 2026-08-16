// 6008b4b8  bcm__6008b4b8  size=78 bytes
// src: bcm.c
// --- callers ---
//   600e9b62 FUN_600e9b62
//   600e9a8e FUN_600e9a8e
//   6008bf44 bcm__6008bf44
//   6008b738 bcm__6008b738
//   600e778c FUN_600e778c
// --- callees ---
//   6008b43c bcm__6008b43c
//   600e72d2 FUN_600e72d2
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e0552 FUN_600e0552


/* src: bcm.c */

undefined4 bcm__6008b4b8(int *param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  if (param_2 < (uint)param_1[1]) {
    iVar1 = FUN_600e72d2();
    if (iVar1 == 0) {
      FUN_600e0552(3,0,0x66,DAT_6008b508,0x1a0);
      return 0;
    }
  }
  else {
    piVar2 = param_1;
    uVar3 = param_2;
    iVar1 = bcm__6008b43c();
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = param_1[1];
    thunk_EXT_FUN_0000af90(*param_1 + iVar1 * 4,0,(param_2 - iVar1) * 4,iVar1,piVar2,uVar3);
  }
  param_1[1] = param_2;
  return 1;
}



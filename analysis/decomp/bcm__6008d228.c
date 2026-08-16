// 6008d228  bcm__6008d228  size=122 bytes
// src: bcm.c
// --- callers ---
// --- callees ---
//   6008b50c bcm__6008b50c
//   6008b544 FUN_6008b544
//   600e0552 FUN_600e0552
//   600e9af4 FUN_600e9af4
//   600e92f0 FUN_600e92f0
//   6008d120 bcm__6008d120


/* src: bcm.c */

int bcm__6008d228(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = param_2;
  FUN_600e92f0(*(undefined4 *)(param_1 + 0x110));
  *(undefined4 *)(param_1 + 0x110) = 0;
  iVar2 = 0;
  if ((param_5 == 0) && (param_5 = bcm__6008b50c(), iVar2 = param_5, param_5 == 0)) {
    return 0;
  }
  iVar1 = FUN_600e9af4(param_2,param_5);
  *(int *)(param_1 + 0x110) = iVar1;
  if (iVar1 == 0) {
    FUN_600e0552(0xf,0,3,DAT_6008d2a4,0x6e);
    iVar1 = 0;
  }
  else {
    iVar1 = bcm__6008d120(param_1,param_2,param_3,param_4,param_5,uVar3);
    if (iVar1 == 0) {
      FUN_600e92f0(*(undefined4 *)(param_1 + 0x110));
      *(undefined4 *)(param_1 + 0x110) = 0;
    }
  }
  FUN_6008b544(iVar2);
  return iVar1;
}



// 60090f24  buf__60090f24  size=78 bytes
// src: buf.c
// --- callers ---
//   600ece78 FUN_600ece78
// --- callees ---
//   600e093e FUN_600e093e
//   600e0552 FUN_600e0552


/* src: buf.c */

undefined4 buf__60090f24(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(uint *)(param_1 + 8) < param_2) {
    if (param_2 < 0xfffffffd) {
      uVar2 = (param_2 + 3) / 3;
      if ((uVar2 & 0x3fffffff) == uVar2) {
        iVar1 = FUN_600e093e(*(undefined4 *)(param_1 + 4),uVar2 << 2,param_3,3,param_1,param_2);
        if (iVar1 != 0) {
          *(int *)(param_1 + 4) = iVar1;
          *(uint *)(param_1 + 8) = uVar2 << 2;
          goto LAB_60090f6e;
        }
        uVar3 = 0x6e;
      }
      else {
        uVar3 = 0x68;
      }
    }
    else {
      uVar3 = 0x61;
    }
    FUN_600e0552(7,0,0x41,DAT_60090f74,uVar3);
    uVar3 = 0;
  }
  else {
LAB_60090f6e:
    uVar3 = 1;
  }
  return uVar3;
}



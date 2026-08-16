// 6008cce0  bcm__6008cce0  size=146 bytes
// src: bcm.c
// --- callers ---
//   6008d5e0 bcm__6008d5e0
// --- callees ---
//   600e7474 FUN_600e7474
//   600e0552 FUN_600e0552


/* src: bcm.c */

undefined4
bcm__6008cce0(int *param_1,int param_2,int param_3,uint *param_4,uint param_5,undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 auStack_a9 [68];
  undefined1 auStack_65 [73];
  
  uVar1 = FUN_600e7474(param_1 + 9);
  if (param_5 < uVar1) {
    FUN_600e0552(0xf,0,100,DAT_6008cd74,0x401);
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      puVar4 = (undefined1 *)0x0;
    }
    else {
      puVar4 = auStack_a9 + 1;
    }
    if (param_3 == 0) {
      puVar5 = (undefined1 *)0x0;
    }
    else {
      puVar5 = auStack_65 + 1;
    }
    iVar3 = (**(code **)(*param_1 + 0xc))(param_1,param_6,puVar4,puVar5);
    uVar2 = 0;
    if (iVar3 != 0) {
      if (param_2 != 0) {
        for (uVar6 = 0; uVar6 != uVar1; uVar6 = uVar6 + 1) {
          *(undefined1 *)(param_2 + uVar6) = auStack_a9[uVar1 - uVar6];
        }
      }
      if (param_3 != 0) {
        for (uVar6 = 0; uVar6 != uVar1; uVar6 = uVar6 + 1) {
          *(undefined1 *)(param_3 + uVar6) = auStack_65[uVar1 - uVar6];
        }
      }
      *param_4 = uVar1;
      uVar2 = 1;
    }
  }
  return uVar2;
}



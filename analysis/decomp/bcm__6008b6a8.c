// 6008b6a8  bcm__6008b6a8  size=138 bytes
// src: bcm.c
// --- callers ---
//   600e96c6 FUN_600e96c6
//   600e93ca FUN_600e93ca
//   6008b738 bcm__6008b738
// --- callees ---
//   600e7d98 FUN_600e7d98
//   600e0552 FUN_600e0552
//   600e77d4 FUN_600e77d4


/* src: bcm.c */

undefined4 bcm__6008b6a8(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  
  iVar6 = *(int *)(param_5 + 0x18);
  if ((iVar6 == param_2) && (param_4 == iVar6 * 2)) {
    puVar10 = (uint *)(param_3 + iVar6 * 4);
    iVar5 = *(int *)(param_5 + 0x28);
    uVar1 = *(undefined4 *)(param_5 + 0x14);
    iVar7 = 0;
    puVar8 = puVar10;
    while (puVar8 != (uint *)(param_3 + iVar6 * 8)) {
      iVar2 = FUN_600e77d4(puVar8 + -iVar6,uVar1,iVar6,iVar5 * puVar8[-iVar6]);
      uVar4 = *puVar8;
      uVar3 = iVar2 + uVar4 + iVar7;
      puVar9 = puVar8 + 1;
      *puVar8 = uVar3;
      if (uVar4 != uVar3) {
        iVar7 = 1;
      }
      puVar8 = puVar9;
      if (uVar4 < uVar3) {
        iVar7 = 0;
      }
    }
    FUN_600e7d98(param_1,puVar10,iVar7,uVar1,iVar6);
    uVar1 = 1;
  }
  else {
    FUN_600e0552(3,0,0x42,DAT_6008b734,0x125);
    uVar1 = 0;
  }
  return uVar1;
}



// 6008bf44  bcm__6008bf44  size=398 bytes
// src: bcm.c
// --- callers ---
//   600e99a2 FUN_600e99a2
// --- callees ---
//   600e77c0 FUN_600e77c0
//   600e7c2c FUN_600e7c2c
//   600e7718 FUN_600e7718
//   6008b570 bcm__6008b570
//   600e72fc FUN_600e72fc
//   600e7412 FUN_600e7412
//   600e7388 FUN_600e7388
//   600e0552 FUN_600e0552
//   600e997c FUN_600e997c
//   6008b4b8 bcm__6008b4b8


/* src: bcm.c */

undefined4 bcm__6008bf44(int param_1,int *param_2,int param_3,int param_4,undefined4 param_5)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uVar8;
  undefined4 extraout_r1;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  
  uVar13 = *(uint *)(param_4 + 4);
  if ((int)*(uint *)(param_4 + 4) < (int)*(uint *)(param_3 + 4)) {
    uVar13 = *(uint *)(param_3 + 4);
  }
  if (uVar13 == 0) {
    *param_2 = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    return 1;
  }
  FUN_600e7718(param_5);
  piVar2 = (int *)bcm__6008b570(param_5);
  piVar3 = (int *)bcm__6008b570(param_5);
  puVar4 = (undefined4 *)bcm__6008b570(param_5);
  if (((((piVar2 != (int *)0x0) && (piVar3 != (int *)0x0)) && (puVar4 != (undefined4 *)0x0)) &&
      ((iVar5 = FUN_600e72fc(piVar2,param_3), iVar5 != 0 &&
       (iVar5 = FUN_600e72fc(piVar3,param_4), iVar5 != 0)))) &&
     ((iVar5 = bcm__6008b4b8(piVar2,uVar13), iVar5 != 0 &&
      ((iVar5 = bcm__6008b4b8(piVar3,uVar13), iVar5 != 0 &&
       (iVar5 = bcm__6008b4b8(puVar4,uVar13), iVar5 != 0)))))) {
    uVar10 = *(int *)(param_3 + 4) * 0x20;
    uVar11 = *(int *)(param_4 + 4) * 0x20;
    if (!CARRY4(uVar10,uVar11)) {
      iVar5 = 0;
      iVar16 = 0;
      while( true ) {
        puVar7 = (uint *)*piVar2;
        puVar9 = (uint *)*piVar3;
        if (iVar5 == uVar10 + uVar11) break;
        uVar15 = (int)((*puVar7 & *puVar9) << 0x1f) >> 0x1f;
        iVar6 = FUN_600e7c2c(*puVar4,puVar7,puVar9,uVar13);
        FUN_600e7412(*piVar2,iVar6 - 1U & uVar15,*puVar4,*piVar2,uVar13);
        iVar5 = iVar5 + 1;
        FUN_600e7c2c(*puVar4,*piVar3,*piVar2,uVar13);
        FUN_600e7412(*piVar3,-iVar6 & uVar15,*puVar4,*piVar3,uVar13);
        uVar12 = *(uint *)*piVar3;
        uVar15 = *(uint *)*piVar2 & 1;
        iVar16 = iVar16 + (uVar15 - 1 & ~-(uVar12 & 1) & 1);
        FUN_600e997c((uint *)*piVar2,uVar15 - 1,*puVar4,uVar13);
        FUN_600e997c(*piVar3,(uVar12 & 1) - 1,*puVar4,uVar13);
      }
      puVar14 = puVar9 + -1;
      uVar10 = 0;
      do {
        puVar1 = puVar7 + uVar10;
        uVar10 = uVar10 + 1;
        puVar14 = puVar14 + 1;
        *puVar14 = *puVar1 | *puVar14;
      } while (uVar10 < uVar13);
      *param_2 = iVar16;
      uVar8 = FUN_600e7388(param_1,puVar9,uVar13);
      goto LAB_6008bf90;
    }
    FUN_600e0552(3,0,0x66,DAT_6008c0d4,0x4e);
  }
  uVar8 = 0;
LAB_6008bf90:
  FUN_600e77c0(param_5,uVar8);
  return extraout_r1;
}



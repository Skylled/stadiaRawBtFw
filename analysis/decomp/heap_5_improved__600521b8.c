// 600521b8  heap_5_improved__600521b8  size=254 bytes
// src: heap_5_improved.c
// --- callers ---
//   600cdb74 FUN_600cdb74
// --- callees ---
//   601016a2 FUN_601016a2
//   600d4698 FUN_600d4698


/* src: heap_5_improved.c */

void heap_5_improved__600521b8(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int extraout_r3;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 *puVar14;
  
  if (((*(int *)(DAT_600521ec + 0x260) == 0x6c0000) ||
      (puVar6 = DAT_600521fc, puVar7 = *(undefined4 **)(DAT_600521ec + 0x260),
      *(undefined4 **)(DAT_600521ec + 0x260) == DAT_600521f0)) &&
     (iVar5 = FUN_600d4698(), puVar6 = DAT_600521f4, puVar7 = DAT_600521f4, iVar5 == 0)) {
    puVar6 = DAT_600521f8;
  }
  piVar2 = DAT_600cc7e8;
  puVar14 = puVar6;
  if (*DAT_600cc7e8 != 0) {
    FUN_601016a2(DAT_600cc7f0,0x2aa,DAT_600cc7ec,*DAT_600cc7e8,puVar6,puVar6,puVar7);
  }
  puVar4 = DAT_600cc808;
  uVar3 = DAT_600cc7f0;
  iVar13 = 0;
  iVar5 = 0;
  puVar1 = puVar14;
  while( true ) {
    iVar10 = puVar1[1];
    if (iVar10 == 0) break;
    puVar12 = (undefined4 *)*puVar1;
    iVar9 = (int)puVar12 << 0x1d;
    puVar8 = puVar12;
    if (iVar9 != 0) {
      puVar8 = (undefined4 *)((int)puVar12 + 7U & 0xfffffff8);
      iVar10 = (int)puVar12 + (iVar10 - (int)puVar8);
    }
    if (iVar13 == 0) {
      *puVar4 = puVar8;
      puVar4[1] = 0;
    }
    else {
      if (*piVar2 == 0) {
        FUN_601016a2(uVar3,0x2cb,DAT_600cc7ec,iVar9,puVar6,puVar14,puVar7);
        iVar9 = extraout_r3;
      }
      if (puVar8 <= (undefined4 *)*piVar2) {
        FUN_601016a2(uVar3,0x2ce,DAT_600cc7ec,iVar9,puVar6,puVar14,puVar7);
      }
    }
    puVar12 = (undefined4 *)*piVar2;
    puVar11 = (undefined4 *)((int)puVar8 + iVar10 + -8 & 0xfffffff8);
    *puVar11 = 0;
    puVar11[1] = 0;
    *piVar2 = (int)puVar11;
    *puVar8 = puVar11;
    puVar8[1] = (int)puVar11 - (int)puVar8;
    if (puVar12 != (undefined4 *)0x0) {
      *puVar12 = puVar8;
    }
    iVar5 = iVar5 + ((int)puVar11 - (int)puVar8);
    iVar13 = iVar13 + 1;
    puVar1 = puVar1 + 2;
  }
  *DAT_600cc7f4 = iVar5;
  *DAT_600cc7f8 = iVar5;
  *DAT_600cc7fc = iVar5;
  puVar1 = DAT_600cc800;
  *DAT_600cc800 = puVar14;
  if (iVar5 == 0) {
    FUN_601016a2(DAT_600cc7f0,0x2f9,DAT_600cc7ec,puVar1,puVar6,puVar14,puVar7);
  }
  *DAT_600cc804 = 0x80000000;
  return;
}



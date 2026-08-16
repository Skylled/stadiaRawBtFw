// 60049052  FUN_60049052  size=116 bytes
// --- callers ---
// --- callees ---
//   60048774 heap_5_improved__60048774
//   6004c084 thunk_FUN_601016a2


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_60049052(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int extraout_r3;
  int *piVar9;
  uint uVar10;
  undefined4 unaff_r4;
  int *piVar11;
  undefined4 unaff_r5;
  uint uVar12;
  undefined4 unaff_r6;
  uint uVar13;
  uint uVar14;
  
  piVar1 = DAT_60048848;
  uVar14 = param_1;
  if (8 < param_1) {
    for (; 1 < uVar14; uVar14 = uVar14 >> 1) {
      if ((int)(uVar14 << 0x1f) < 0) goto LAB_60048884;
    }
    param_4 = param_1;
    if (8 < param_1) {
      uVar14 = param_1 - 1;
      iVar8 = heap_5_improved__60048774(param_2 + 8 + param_1);
      if (iVar8 == 0) {
LAB_60048884:
        uVar10 = 0;
      }
      else {
        uVar10 = iVar8 + 8;
        if ((uVar10 & uVar14) != 0) {
          uVar10 = uVar10 + (uVar14 & ~uVar10) + 1;
        }
        if ((uVar10 & uVar14) != 0) {
          thunk_FUN_601016a2(_DAT_600488d4,0x1bb,_DAT_600488d0);
        }
        *(undefined4 *)(uVar10 - 4) = 0xffffffff;
        *(int *)(uVar10 - 8) = iVar8 + -8;
      }
      return uVar10;
    }
  }
  iVar8 = *DAT_60048848;
  if (iVar8 == 0) {
    thunk_FUN_601016a2(DAT_60048850,0xf3,DAT_6004884c,0,param_4,unaff_r4,unaff_r5,unaff_r6);
    iVar8 = extraout_r3;
  }
  if (param_2 == 0xffffffff) {
    thunk_FUN_601016a2(DAT_60048850,0xf4,DAT_6004884c,iVar8,param_4,unaff_r4,unaff_r5,unaff_r6);
  }
  FUN_60047958();
  puVar2 = DAT_60048858;
  uVar14 = *DAT_60048854;
  if (((uVar14 & param_2) == 0) && (param_2 != 0)) {
    uVar10 = param_2 + 8;
    if ((param_2 & 7) != 0) {
      uVar10 = (uVar10 & 0xfffffff8) + 8;
    }
    param_2 = uVar10;
    if ((uVar10 != 0) && (uVar13 = *DAT_60048858, uVar10 <= uVar13)) {
      piVar4 = DAT_6004885c;
      piVar5 = (int *)*DAT_6004885c;
      do {
        piVar11 = piVar5;
        piVar9 = piVar4;
        uVar7 = piVar11[1];
        if (uVar10 <= uVar7) break;
        piVar4 = piVar11;
        piVar5 = (int *)*piVar11;
      } while ((int *)*piVar11 != (int *)0x0);
      if ((int *)*piVar1 != piVar11) {
        iVar8 = *piVar9;
        *piVar9 = *piVar11;
        uVar12 = iVar8 + 8;
        param_2 = uVar7;
        if (0x10 < uVar7 - uVar10) {
          *(uint *)((int)piVar11 + uVar10 + 4) = uVar7 - uVar10;
          piVar11[1] = uVar10;
          FUN_60048684((int)piVar11 + uVar10,0);
          param_2 = uVar10;
        }
        puVar3 = DAT_60048860;
        uVar10 = piVar11[1];
        uVar13 = uVar13 - uVar10;
        uVar7 = *DAT_60048860;
        *puVar2 = uVar13;
        piVar11[1] = uVar14 | uVar10;
        *piVar11 = 0;
        if (uVar13 < uVar7) {
          *puVar3 = uVar13;
        }
        if (uVar13 < *DAT_60048864) {
          *DAT_60048864 = uVar13;
        }
        goto LAB_60048820;
      }
    }
  }
  uVar12 = 0;
LAB_60048820:
  tasks__60047aa8();
  if (uVar12 == 0) {
    uVar6 = heap_5_improved__600cc6a0();
    thunk_FUN_60052230(param_2,uVar6);
    heap_support__60052254();
  }
  return uVar12;
}



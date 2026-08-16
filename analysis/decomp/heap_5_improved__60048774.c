// 60048774  heap_5_improved__60048774  size=210 bytes
// src: heap_5_improved.c
// --- callers ---
//   6004723c queue__6004723c
//   60049052 FUN_60049052
// --- callees ---
//   6004c36c thunk_FUN_60052230
//   6004bfc4 heap_support__60052254
//   60047958 FUN_60047958
//   60047aa8 tasks__60047aa8
//   60048684 FUN_60048684
//   6004c084 thunk_FUN_601016a2
//   6004c3c4 heap_5_improved__600cc6a0


/* src: heap_5_improved.c */

int heap_5_improved__60048774(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  int *piVar11;
  uint uVar12;
  uint uVar13;
  
  piVar1 = DAT_60048848;
  iVar8 = *DAT_60048848;
  if (iVar8 == 0) {
    thunk_FUN_601016a2(DAT_60048850,0xf3,DAT_6004884c,0,param_4);
    iVar8 = extraout_r3;
  }
  if (param_1 == 0xffffffff) {
    thunk_FUN_601016a2(DAT_60048850,0xf4,DAT_6004884c,iVar8,param_4);
  }
  FUN_60047958();
  puVar2 = DAT_60048858;
  uVar13 = *DAT_60048854;
  if (((uVar13 & param_1) == 0) && (param_1 != 0)) {
    uVar10 = param_1 + 8;
    if ((param_1 & 7) != 0) {
      uVar10 = (uVar10 & 0xfffffff8) + 8;
    }
    param_1 = uVar10;
    if ((uVar10 != 0) && (uVar12 = *DAT_60048858, uVar10 <= uVar12)) {
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
        iVar8 = iVar8 + 8;
        param_1 = uVar7;
        if (0x10 < uVar7 - uVar10) {
          *(uint *)((int)piVar11 + uVar10 + 4) = uVar7 - uVar10;
          piVar11[1] = uVar10;
          FUN_60048684((int)piVar11 + uVar10,0);
          param_1 = uVar10;
        }
        puVar3 = DAT_60048860;
        uVar10 = piVar11[1];
        uVar12 = uVar12 - uVar10;
        uVar7 = *DAT_60048860;
        *puVar2 = uVar12;
        piVar11[1] = uVar13 | uVar10;
        *piVar11 = 0;
        if (uVar12 < uVar7) {
          *puVar3 = uVar12;
        }
        if (uVar12 < *DAT_60048864) {
          *DAT_60048864 = uVar12;
        }
        goto LAB_60048820;
      }
    }
  }
  iVar8 = 0;
LAB_60048820:
  tasks__60047aa8();
  if (iVar8 == 0) {
    uVar6 = heap_5_improved__600cc6a0();
    thunk_FUN_60052230(param_1,uVar6);
    heap_support__60052254();
  }
  return iVar8;
}



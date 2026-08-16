// 60047974  tasks__60047974  size=256 bytes
// src: tasks.c
// --- callers ---
//   60047aa8 tasks__60047aa8
//   600485f8 FUN_600485f8
// --- callees ---
//   6004bb1a FUN_6004bb1a
//   6004c084 thunk_FUN_601016a2
//   6004904c FUN_6004904c
//   6004c024 thunk_FUN_600ca0d8
//   6004bb60 FUN_6004bb60


/* src: tasks.c */

undefined4 tasks__60047974(void)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 in_r3;
  uint uVar8;
  undefined4 uVar9;
  
  if (*DAT_60047a74 == 0) {
    uVar8 = *DAT_60047a78 + 1;
    *DAT_60047a78 = uVar8;
    piVar1 = DAT_60047a7c;
    if (uVar8 == 0) {
      if (*(int *)*DAT_60047a7c != 0) {
        thunk_FUN_601016a2(DAT_60047a84,0xb50,DAT_60047a80,*(int *)*DAT_60047a7c,in_r3);
      }
      piVar2 = DAT_60047a88;
      iVar7 = *piVar1;
      *piVar1 = *DAT_60047a88;
      *piVar2 = iVar7;
      *DAT_60047a8c = *DAT_60047a8c + 1;
      thunk_FUN_600ca0d8();
    }
    puVar5 = DAT_60047aa4;
    piVar2 = DAT_60047a94;
    puVar3 = DAT_60047a90;
    piVar1 = DAT_60047a7c;
    uVar9 = 0;
    if (*DAT_60047a90 <= uVar8) {
      while (*(int *)*piVar1 != 0) {
        iVar7 = *(int *)(*(int *)(*piVar1 + 0xc) + 0xc);
        if (uVar8 < *(uint *)(iVar7 + 4)) {
          *puVar3 = *(uint *)(iVar7 + 4);
          goto LAB_600479c2;
        }
        FUN_6004bb60(iVar7 + 4);
        if (*(int *)(iVar7 + 0x28) != 0) {
          FUN_6004bb60(iVar7 + 0x18);
        }
        iVar4 = DAT_60047a98;
        uVar6 = *(uint *)(iVar7 + 0x2c);
        *puVar5 = 1 << (uVar6 & 0xff) | *puVar5;
        FUN_6004bb1a(uVar6 * 0x14 + iVar4,iVar7 + 4);
        if (*(uint *)(*piVar2 + 0x2c) <= *(uint *)(iVar7 + 0x2c)) {
          uVar9 = 1;
        }
      }
      *puVar3 = 0xffffffff;
    }
LAB_600479c2:
    if (1 < *(uint *)(DAT_60047a98 + *(int *)(*piVar2 + 0x2c) * 0x14)) {
      uVar9 = 1;
    }
    if (*DAT_60047a9c == 0) {
      FUN_6004904c();
    }
  }
  else {
    uVar9 = 0;
    *DAT_60047a9c = *DAT_60047a9c + 1;
    FUN_6004904c();
  }
  if (*DAT_60047aa0 != 0) {
    uVar9 = 1;
  }
  return uVar9;
}



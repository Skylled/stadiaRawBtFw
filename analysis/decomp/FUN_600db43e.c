// 600db43e  FUN_600db43e  size=300 bytes
// --- callers ---
//   600db56a FUN_600db56a
// --- callees ---
//   600d6c68 FUN_600d6c68
//   600d379e FUN_600d379e
//   6013d0d0 thunk_EXT_FUN_00008ad2


void FUN_600db43e(int param_1,undefined1 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int local_30;
  undefined1 *local_2c;
  undefined4 uStack_28;
  
  local_30 = param_1;
  local_2c = param_2;
  uStack_28 = param_3;
  thunk_EXT_FUN_00008ad2();
  puVar7 = *(undefined1 **)(param_1 + 0x8c);
  *param_2 = 1;
  param_2[4] = 1;
  *(undefined1 **)(param_2 + 8) = puVar7;
  if (*(uint *)(param_1 + 0x7c) <= *(uint *)(param_1 + 0x80)) {
    uVar4 = *(undefined4 *)(param_1 + 0x7c);
    param_2[0xc] = 1;
    *(undefined4 *)(param_2 + 0x10) = uVar4;
    param_2[0x14] = 1;
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x80);
  }
  param_2[0x1c] = 1;
  local_2c = puVar7;
  if (*(undefined1 **)(param_1 + 4) < puVar7) {
    if (puVar7 < *(undefined1 **)(param_1 + 100)) {
      piVar9 = (int *)(param_1 + 4);
      iVar6 = 0xd;
      while (iVar10 = iVar6, 0 < iVar10) {
        iVar6 = iVar10 >> 1;
        iVar11 = FUN_600d379e(piVar9 + iVar6 * 2,&local_2c);
        if (iVar11 != 0) {
          piVar9 = piVar9 + iVar6 * 2 + 2;
          iVar6 = (iVar10 - iVar6) + -1;
        }
      }
      iVar6 = ((piVar9[1] - piVar9[-1]) * ((int)puVar7 - piVar9[-2])) / (*piVar9 - piVar9[-2]) +
              piVar9[-1];
    }
    else {
      iVar6 = *(int *)(param_1 + 0x68);
    }
  }
  else {
    iVar6 = *(int *)(param_1 + 8);
  }
  *(int *)(param_2 + 0x24) = iVar6;
  uVar5 = *(uint *)(param_1 + 0x84);
  uVar3 = *(uint *)(param_1 + 0x88);
  param_2[0x20] = 1;
  if (uVar5 <= uVar3) {
    *(uint *)(param_2 + 0x2c) = uVar5;
    param_2[0x28] = 1;
    param_2[0x30] = 1;
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_1 + 0x88);
  }
  iVar11 = *(int *)(param_1 + 0x6c);
  param_2[0x38] = 1;
  iVar10 = *(int *)(param_1 + 0x74);
  if (iVar11 < iVar6) {
    if (iVar6 < iVar10) {
      piVar9 = (int *)(param_1 + 0x6c);
      iVar1 = 2;
      local_30 = iVar6;
      while (iVar8 = iVar1, 0 < iVar8) {
        iVar1 = iVar8 >> 1;
        iVar2 = FUN_600d6c68(piVar9 + iVar1 * 2,&local_30);
        if (iVar2 != 0) {
          piVar9 = piVar9 + iVar1 * 2 + 2;
          iVar1 = (iVar8 - iVar1) + -1;
        }
      }
      iVar6 = ((piVar9[1] - piVar9[-1]) * (iVar6 - piVar9[-2])) / (*piVar9 - piVar9[-2]) +
              piVar9[-1];
    }
    else {
      iVar6 = *(int *)(param_1 + 0x78);
    }
  }
  else {
    iVar6 = *(int *)(param_1 + 0x70);
  }
  *(int *)(param_2 + 0x3c) = iVar6;
  *(int *)(param_2 + 0x48) = iVar11;
  param_2[0x40] = 1;
  param_2[0x44] = 1;
  param_2[0x4c] = 1;
  *(int *)(param_2 + 0x50) = iVar10;
  return;
}



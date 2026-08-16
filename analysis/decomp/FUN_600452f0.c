// 600452f0  FUN_600452f0  size=328 bytes
// --- callers ---
//   6004a31a FUN_6004a31a
// --- callees ---


void FUN_600452f0(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 uVar12;
  int local_38 [5];
  
  iVar5 = 0;
  local_38[0] = *DAT_60045438;
  local_38[1] = DAT_60045438[1];
  local_38[2] = DAT_60045438[2];
  local_38[3] = DAT_60045438[3];
  do {
    iVar11 = local_38[iVar5];
    for (iVar4 = 0; iVar4 != iVar5; iVar4 = iVar4 + 1) {
      iVar2 = (iVar11 + iVar4 * 2) * 4;
      iVar3 = (local_38[iVar4] + iVar5 * 2) * 4;
      puVar9 = (undefined4 *)(iVar2 + 4 + param_2);
      uVar8 = *(undefined4 *)(param_2 + iVar2);
      puVar1 = (undefined4 *)(iVar3 + 4 + param_2);
      uVar7 = *puVar9;
      uVar12 = *puVar1;
      *(undefined4 *)(param_2 + iVar2) = *(undefined4 *)(param_2 + iVar3);
      *puVar9 = uVar12;
      *(undefined4 *)(param_2 + iVar3) = uVar8;
      *puVar1 = uVar7;
      puVar6 = (undefined4 *)(iVar2 + 0x20 + param_2);
      puVar9 = (undefined4 *)(iVar2 + 0x24 + param_2);
      puVar10 = (undefined4 *)(iVar3 + 0x40 + param_2);
      puVar1 = (undefined4 *)(iVar3 + 0x44 + param_2);
      uVar8 = *puVar6;
      uVar7 = *puVar9;
      uVar12 = *puVar1;
      *puVar6 = *puVar10;
      *puVar9 = uVar12;
      *puVar10 = uVar8;
      *puVar1 = uVar7;
      puVar6 = (undefined4 *)(iVar2 + 0x40 + param_2);
      puVar9 = (undefined4 *)(iVar2 + 0x44 + param_2);
      puVar10 = (undefined4 *)(iVar3 + 0x20 + param_2);
      puVar1 = (undefined4 *)(iVar3 + 0x24 + param_2);
      uVar8 = *puVar6;
      uVar7 = *puVar9;
      uVar12 = *puVar1;
      *puVar6 = *puVar10;
      *puVar9 = uVar12;
      *puVar10 = uVar8;
      *puVar1 = uVar7;
      puVar6 = (undefined4 *)(iVar2 + 0x60 + param_2);
      puVar9 = (undefined4 *)(iVar2 + 100 + param_2);
      puVar10 = (undefined4 *)(iVar3 + 0x60 + param_2);
      puVar1 = (undefined4 *)(iVar3 + 100 + param_2);
      uVar12 = *puVar6;
      uVar8 = *puVar9;
      uVar7 = *puVar1;
      *puVar6 = *puVar10;
      *puVar9 = uVar7;
      *puVar10 = uVar12;
      *puVar1 = uVar8;
    }
    iVar5 = (iVar5 * 2 + 8 + iVar11) * 4;
    puVar1 = (undefined4 *)(iVar5 + 4 + param_2);
    uVar8 = *(undefined4 *)(param_2 + iVar5);
    puVar9 = (undefined4 *)(iVar5 + 0x20 + param_2);
    puVar6 = (undefined4 *)(iVar5 + 0x24 + param_2);
    uVar7 = *puVar1;
    *(undefined4 *)(param_2 + iVar5) = *puVar9;
    *puVar1 = *puVar6;
    *puVar9 = uVar8;
    *puVar6 = uVar7;
    iVar5 = iVar4 + 1;
  } while (iVar5 != 4);
  return;
}



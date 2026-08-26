// 60049b3c  FUN_60049b3c  size=178 bytes
// --- callers ---
//   60049994 FUN_60049994
//   60049a4a FUN_60049a4a
// --- callees ---
//   6004bf64 thunk_FUN_6007c4c8
//   6004c3ec thunk_FUN_6007c3e0


void FUN_60049b3c(uint *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  int *piVar10;
  int *piVar11;
  
  puVar9 = param_1;
  piVar10 = param_2;
  piVar11 = param_3;
  for (uVar7 = 0; uVar7 < *param_1; uVar7 = uVar7 + 1) {
    iVar5 = uVar7 * 0xc;
    uVar4 = param_1[1];
    iVar3 = *(int *)(uVar4 + iVar5);
    iVar6 = *(int *)(uVar4 + iVar5 + 4);
    uVar2 = *(undefined4 *)(*param_3 + iVar5);
    iVar1 = *param_3 + iVar5;
    *(undefined4 *)(iVar1 + 4) = uVar2;
    iVar6 = (0x40 - (iVar6 - iVar3 >> 2)) * 4;
    uVar8 = (uint)puVar9 & 0xffffff00;
    thunk_FUN_6007c4c8(iVar1,uVar2,*(undefined4 *)(uVar4 + iVar5),*(undefined4 *)(uVar4 + iVar5 + 4)
                       ,uVar8,piVar10,piVar11);
    iVar1 = *(int *)(*param_2 + uVar7 * 8);
    uVar8 = uVar8 & 0xffffff00;
    thunk_FUN_6007c3e0(*param_3 + iVar5,
                       (*(int *)(param_1[1] + iVar5 + 4) - *(int *)(param_1[1] + iVar5)) +
                       *(int *)(*param_3 + iVar5),iVar1,iVar1 + iVar6,uVar8);
    uVar2 = *(undefined4 *)(param_1[1] + iVar5);
    iVar5 = param_1[1] + iVar5;
    iVar3 = *param_2;
    *(undefined4 *)(iVar5 + 4) = uVar2;
    iVar1 = *(int *)(iVar3 + uVar7 * 8);
    puVar9 = (uint *)(uVar8 & 0xffffff00);
    thunk_FUN_6007c3e0(iVar5,uVar2,iVar1 + iVar6,iVar1 + *(int *)(uVar7 * 8 + iVar3 + 4) * 4,puVar9)
    ;
  }
  return;
}



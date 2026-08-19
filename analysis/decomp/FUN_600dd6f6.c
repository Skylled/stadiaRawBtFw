// 600dd6f6  FUN_600dd6f6  size=152 bytes
// --- callers ---
// --- callees ---
//   6013d368 thunk_EXT_FUN_00009304
//   6007d78c FUN_6007d78c


void FUN_600dd6f6(uint *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int *piVar8;
  int *piVar9;
  
  puVar7 = param_1;
  piVar8 = param_2;
  piVar9 = param_3;
  for (uVar4 = 0; uVar4 < *param_1; uVar4 = uVar4 + 1) {
    iVar5 = uVar4 * 0xc;
    iVar6 = *(int *)(param_1[1] + iVar5);
    iVar2 = *(int *)(param_1[1] + iVar5 + 4);
    thunk_EXT_FUN_00009304
              (iVar6,iVar2,*(undefined4 *)(*param_3 + uVar4 * 8),*param_3,puVar7,piVar8,piVar9);
    iVar3 = (0x50 - (iVar2 - iVar6 >> 2)) * 4;
    thunk_EXT_FUN_00009304
              (*(int *)(*param_2 + iVar5),*(int *)(*param_2 + iVar5) + iVar3,
               *(int *)(*param_3 + uVar4 * 8) +
               (*(int *)(param_1[1] + iVar5 + 4) - *(int *)(param_1[1] + iVar5)));
    uVar1 = *(undefined4 *)(param_1[1] + iVar5);
    iVar2 = param_1[1] + iVar5;
    iVar6 = *param_2;
    *(undefined4 *)(iVar2 + 4) = uVar1;
    puVar7 = (uint *)((uint)puVar7 & 0xffffff00);
    FUN_6007d78c(iVar2,uVar1,*(int *)(iVar6 + iVar5) + iVar3,*(undefined4 *)(iVar6 + iVar5 + 4));
  }
  return;
}



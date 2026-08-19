// 600dc76c  FUN_600dc76c  size=74 bytes
// --- callers ---
// --- callees ---
//   6007c4c8 FUN_6007c4c8


void FUN_600dc76c(uint *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  
  puVar6 = param_1;
  piVar7 = param_2;
  for (uVar5 = 0; uVar5 < *param_1; uVar5 = uVar5 + 1) {
    iVar4 = uVar5 * 0xc;
    uVar2 = *(undefined4 *)(*param_2 + iVar4);
    iVar1 = *param_2 + iVar4;
    uVar3 = param_1[1];
    *(undefined4 *)(iVar1 + 4) = uVar2;
    puVar6 = (uint *)((uint)puVar6 & 0xffffff00);
    FUN_6007c4c8(iVar1,uVar2,*(undefined4 *)(uVar3 + iVar4),*(undefined4 *)(uVar3 + iVar4 + 4),
                 puVar6,piVar7);
    *(undefined4 *)(param_1[1] + iVar4 + 4) = *(undefined4 *)(param_1[1] + iVar4);
  }
  return;
}



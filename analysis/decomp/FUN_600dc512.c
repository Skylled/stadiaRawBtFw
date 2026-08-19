// 600dc512  FUN_600dc512  size=92 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600dc512(int param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  
  piVar5 = (int *)(param_1 + 8);
  DataMemoryBarrier(0x1b);
  if (*(int *)(param_1 + 8) == 0) {
    uVar4 = 0;
  }
  else {
    iVar8 = *(int *)(param_1 + 4);
    iVar7 = *(int *)(param_1 + 0xc);
    uVar1 = *(undefined2 *)param_2;
    puVar6 = (undefined4 *)(iVar7 + iVar8 * 4);
    uVar2 = *(undefined2 *)((int)param_2 + 2);
    *param_2 = *puVar6;
    *(undefined2 *)(iVar7 + iVar8 * 4) = uVar1;
    *(undefined2 *)((int)puVar6 + 2) = uVar2;
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(piVar5);
      bVar3 = (bool)hasExclusiveAccess(piVar5);
    } while (!bVar3);
    *piVar5 = *piVar5 + -1;
    iVar7 = *(int *)(param_1 + 4) + 1;
    *(int *)(param_1 + 4) = iVar7;
    if (iVar7 == *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
    uVar4 = 1;
  }
  return uVar4;
}



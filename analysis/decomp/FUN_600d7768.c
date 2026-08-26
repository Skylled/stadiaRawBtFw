// 600d7768  FUN_600d7768  size=14 bytes
// --- callers ---
// --- callees ---


int FUN_600d7768(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *(uint *)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 8);
  *(uint *)(param_1 + 4) = uVar4 + 1;
  uVar5 = *(uint *)(iVar3 + 4);
  if (uVar4 < uVar5) {
    uVar4 = uVar4 - uVar5 * (uVar4 / uVar5);
    uVar5 = 0;
    puVar1 = *(undefined4 **)(iVar3 + 0x1c0);
    while ((uint)puVar1[1] <= uVar4) {
      uVar4 = uVar4 - puVar1[1];
      uVar5 = (uVar5 + 1) % 0x11;
      puVar1 = *(undefined4 **)(iVar3 + uVar5 * 4 + 0x1c0);
    }
    iVar2 = (**(code **)*puVar1)();
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar3 + 8);
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



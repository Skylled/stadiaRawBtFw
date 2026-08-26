// 60101c6e  FUN_60101c6e  size=10 bytes
// --- callers ---
// --- callees ---


void FUN_60101c6e(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  func_0x600cc9d4();
  uVar5 = FUN_60101c66();
  piVar2 = (int *)((ulonglong)uVar5 >> 0x20);
  iVar1 = (int)uVar5;
  iVar4 = *(int *)(iVar1 + 0xc);
  iVar3 = *(int *)(iVar4 + 8);
  *(int *)(iVar1 + 0xc) = iVar3;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 4) = iVar1;
  }
  *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar1 + 4);
  if (*piVar2 == iVar1) {
    *piVar2 = iVar4;
  }
  else {
    iVar3 = *(int *)(iVar1 + 4);
    if (*(int *)(iVar3 + 8) == iVar1) {
      *(int *)(iVar3 + 8) = iVar4;
    }
    else {
      *(int *)(iVar3 + 0xc) = iVar4;
    }
  }
  *(int *)(iVar4 + 8) = iVar1;
  *(int *)(iVar1 + 4) = iVar4;
  return;
}



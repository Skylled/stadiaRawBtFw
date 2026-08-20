// 600eb7ce  FUN_600eb7ce  size=232 bytes
// --- callers ---
// --- callees ---
//   600e7450 FUN_600e7450
//   600eb75a FUN_600eb75a
//   600eafb4 FUN_600eafb4
//   600ea8d8 FUN_600ea8d8
//   600eaba4 FUN_600eaba4
//   600eb19c FUN_600eb19c
//   600eb156 FUN_600eb156
//   600eaf8e FUN_600eaf8e


void FUN_600eb7ce(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_11dc [204];
  char acStack_1110 [532];
  char acStack_efc [532];
  undefined1 auStack_ce8 [1632];
  undefined1 auStack_688 [1636];
  
  uVar2 = FUN_600e7450(param_1 + 8);
  iVar3 = *(int *)(param_1 + 4);
  uVar4 = uVar2 + 1;
  FUN_600eb75a(param_1,acStack_1110,param_3,uVar2,4);
  FUN_600eb156(param_1,auStack_ce8,iVar3 + 4);
  bVar1 = true;
  FUN_600eb75a(param_1,acStack_efc,param_5,uVar2,4);
  FUN_600eb156(param_1,auStack_688,param_4);
  for (; uVar2 < uVar4; uVar2 = uVar2 - 1) {
    if (!bVar1) {
      FUN_600ea8d8(param_1,param_2,param_2);
    }
    if (acStack_1110[uVar2] != '\0') {
      FUN_600eb19c(param_1,auStack_11dc,auStack_ce8);
      if (bVar1) {
        bVar1 = false;
        FUN_600eafb4(param_2,auStack_11dc);
      }
      else {
        FUN_600eaba4(param_1,param_2,param_2,auStack_11dc);
      }
    }
    if (acStack_efc[uVar2] != '\0') {
      FUN_600eb19c(param_1,auStack_11dc,auStack_688);
      if (bVar1) {
        bVar1 = false;
        FUN_600eafb4(param_2,auStack_11dc);
      }
      else {
        FUN_600eaba4(param_1,param_2,param_2,auStack_11dc);
      }
    }
  }
  if (bVar1) {
    FUN_600eaf8e(param_2);
  }
  return;
}



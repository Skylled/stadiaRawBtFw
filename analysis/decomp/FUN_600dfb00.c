// 600dfb00  FUN_600dfb00  size=126 bytes
// --- callers ---
//   600df674 FUN_600df674
//   600df9c2 FUN_600df9c2
//   60082814 FUN_60082814
//   600df810 FUN_600df810
//   600dfb7e FUN_600dfb7e
// --- callees ---
//   600dfadc FUN_600dfadc


undefined4 FUN_600dfb00(undefined4 *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  piVar3 = (int *)param_1[1];
  if (*piVar3 == 0) {
    uVar2 = 0;
  }
  else {
    iVar4 = *(int *)((int)piVar3 + 0x19);
    param_1[1] = (int)piVar3 + 0x19;
    if (iVar4 == 0) {
      FUN_600dfadc(param_1,*param_1,param_1[3]);
      uVar2 = 0;
    }
    else {
      bVar1 = *(byte *)(piVar3 + 1);
      iVar4 = *(int *)((int)piVar3 + 0xd);
      iVar5 = *(int *)((int)piVar3 + 0x1e);
      if ((((bVar1 & 0x30) != 0x30) || ((*(byte *)((int)piVar3 + 0x1d) & 0x30) != 0x30)) ||
         (iVar5 != -1)) {
        if ((bVar1 & 0xf0) == 0x20) {
          iVar4 = *(int *)((int)piVar3 + 0x11) * iVar4;
        }
        else if ((bVar1 & 0xc0) == 0x80) {
          iVar4 = 4;
        }
        if ((bVar1 & 0x30) == 0) {
          param_1[2] = param_1[2] + 1;
        }
        iVar4 = iVar4 + iVar5 + param_1[4];
        param_1[4] = iVar4;
        param_1[5] = iVar4 + *(int *)((int)piVar3 + 0x22);
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}



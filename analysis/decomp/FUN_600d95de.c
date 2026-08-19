// 600d95de  FUN_600d95de  size=102 bytes
// --- callers ---
// --- callees ---
//   600d95b2 FUN_600d95b2


int FUN_600d95de(byte *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_19;
  
  if (*param_1 < param_2) {
    if (param_2 < param_1[8]) {
      iVar1 = 2;
      while (iVar3 = iVar1, 0 < iVar3) {
        iVar1 = iVar3 >> 1;
        iVar2 = FUN_600d95b2(param_1 + iVar1 * 8,&local_19);
        if (iVar2 != 0) {
          param_1 = param_1 + iVar1 * 8 + 8;
          iVar1 = (iVar3 - iVar1) + -1;
        }
      }
      iVar1 = (int)((*(int *)(param_1 + 4) - *(int *)(param_1 + -4)) * (param_2 - param_1[-8])) /
              (int)((uint)*param_1 - (uint)param_1[-8]) + *(int *)(param_1 + -4);
    }
    else {
      iVar1 = *(int *)(param_1 + 0xc);
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
  }
  return iVar1;
}



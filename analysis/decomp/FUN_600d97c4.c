// 600d97c4  FUN_600d97c4  size=102 bytes
// --- callers ---
//   60070bf4 FUN_60070bf4
// --- callees ---
//   600d97a6 FUN_600d97a6


int FUN_600d97c4(ushort *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_1a [2];
  
  if (*param_1 < param_2) {
    if (param_2 < param_1[8]) {
      iVar1 = 3;
      while (iVar3 = iVar1, 0 < iVar3) {
        iVar1 = iVar3 >> 1;
        iVar2 = FUN_600d97a6(param_1 + iVar1 * 4,local_1a);
        if (iVar2 != 0) {
          param_1 = param_1 + iVar1 * 4 + 4;
          iVar1 = (iVar3 - iVar1) + -1;
        }
      }
      iVar1 = (int)((*(int *)(param_1 + 2) - *(int *)(param_1 + -2)) * (param_2 - param_1[-4])) /
              (int)((uint)*param_1 - (uint)param_1[-4]) + *(int *)(param_1 + -2);
    }
    else {
      iVar1 = *(int *)(param_1 + 10);
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 2);
  }
  return iVar1;
}



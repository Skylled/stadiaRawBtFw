// 600daeea  FUN_600daeea  size=80 bytes
// --- callers ---
//   600daf3a FUN_600daf3a
//   600daf9e FUN_600daf9e
// --- callees ---
//   60101d4a thunk_FUN_60101ccc


int * FUN_600daeea(int *param_1,int param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = true;
  iVar2 = *(int *)(param_2 + 8);
  iVar3 = param_2 + 4;
  while (iVar2 != 0) {
    bVar1 = *param_3 < *(int *)(iVar2 + 0x10);
    iVar3 = iVar2;
    if (bVar1) {
      iVar2 = *(int *)(iVar2 + 8);
    }
    else {
      iVar2 = *(int *)(iVar2 + 0xc);
    }
  }
  iVar2 = iVar3;
  if (bVar1) {
    if (*(int *)(param_2 + 0xc) == iVar3) goto LAB_600daf16;
    iVar2 = thunk_FUN_60101ccc(iVar3);
  }
  if (*param_3 <= *(int *)(iVar2 + 0x10)) {
    *param_1 = iVar2;
    param_1[1] = 0;
    return param_1;
  }
LAB_600daf16:
  *param_1 = 0;
  param_1[1] = iVar3;
  return param_1;
}



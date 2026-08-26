// 6010088c  FUN_6010088c  size=116 bytes
// --- callers ---
//   600ca844 FUN_600ca844
// --- callees ---
//   6010080a FUN_6010080a
//   6010084a FUN_6010084a


undefined4 FUN_6010088c(int *param_1,code *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0) {
      return 0;
    }
    iVar1 = (*param_2)(param_1[1]);
    if (((iVar1 != 0) && (iVar1 = FUN_6010080a(param_1[1],param_2), iVar1 == 0)) &&
       (iVar1 = (*param_2)(*(undefined4 *)(param_1[1] + 4)), iVar1 != 0)) {
      piVar2 = *(int **)(param_1[1] + 4);
      param_1[1] = (int)piVar2;
      if (piVar2 == param_1 + 2) {
        param_1[1] = param_1[3];
      }
      iVar4 = *(int *)(param_1[1] + 0xc);
      iVar1 = FUN_6010084a(iVar4,param_2);
      if (iVar1 == 0) {
        while( true ) {
          piVar2 = *(int **)(param_1[1] + 4);
          param_1[1] = (int)piVar2;
          if (param_1 + 2 == piVar2) {
            param_1[1] = param_1[3];
          }
          iVar3 = *(int *)(param_1[1] + 0xc);
          iVar1 = FUN_6010084a(iVar3,param_2);
          if (iVar1 != 0) break;
          if (iVar4 == iVar3) {
            return 0;
          }
        }
        return 1;
      }
    }
  }
  return 1;
}



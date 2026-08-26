// 6010095a  FUN_6010095a  size=88 bytes
// --- callers ---
//   600ca72c FUN_600ca72c
// --- callees ---
//   600ca6b0 FUN_600ca6b0


int FUN_6010095a(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  if (*param_2 != 0) {
    iVar3 = 0;
    piVar2 = *(int **)(param_2[1] + 4);
    param_2[1] = (int)piVar2;
    if (piVar2 == param_2 + 2) {
      param_2[1] = param_2[3];
    }
    iVar5 = *(int *)(param_2[1] + 0xc);
    do {
      iVar1 = iVar3 * 0x24;
      iVar3 = iVar3 + 1;
      piVar2 = *(int **)(param_2[1] + 4);
      param_2[1] = (int)piVar2;
      if (param_2 + 2 == piVar2) {
        param_2[1] = param_2[3];
      }
      iVar4 = *(int *)(param_2[1] + 0xc);
      FUN_600ca6b0(iVar4,iVar1 + param_1,1,param_3,param_4);
    } while (iVar5 != iVar4);
  }
  return iVar3;
}



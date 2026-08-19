// 600dc682  FUN_600dc682  size=96 bytes
// --- callers ---
//   6007c1d4 FUN_6007c1d4
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588
//   600dc65c FUN_600dc65c


void FUN_600dc682(undefined4 *param_1,int param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = (int *)*param_1;
  piVar3 = piVar5;
  for (iVar4 = param_2; iVar4 != 0; iVar4 = iVar4 + -1) {
    iVar2 = *param_3;
    iVar1 = param_3[1];
    *piVar3 = 0;
    piVar3[1] = 0;
    piVar3[2] = 0;
    FUN_600dc65c(piVar3,iVar1 - iVar2 >> 2);
    iVar2 = *param_3;
    iVar1 = *piVar3;
    iVar6 = param_3[1] - iVar2;
    if (param_3[1] != iVar2) {
      iVar1 = thunk_EXT_FUN_0000b588(iVar1,iVar2,iVar6,iVar1,param_4);
    }
    piVar3[1] = iVar1 + iVar6;
    piVar3 = piVar3 + 3;
  }
  param_1[1] = piVar5 + param_2 * 3;
  return;
}



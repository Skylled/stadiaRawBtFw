// 600dc486  FUN_600dc486  size=80 bytes
// --- callers ---
//   6007bf68 FUN_6007bf68
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532
//   6013d238 thunk_EXT_FUN_0000b588
//   60101fcc FUN_60101fcc


int * FUN_600dc486(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_2[1] - *param_2;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar1 = 0;
  if (iVar2 >> 2 != 0) {
    if (0x3fffffff < (uint)(iVar2 >> 2)) {
      FUN_60101fcc();
    }
    iVar1 = thunk_EXT_FUN_0000b532(iVar2);
  }
  *param_1 = iVar1;
  param_1[1] = iVar1;
  param_1[2] = iVar2 + iVar1;
  iVar2 = *param_2;
  iVar3 = param_2[1] - iVar2;
  if (param_2[1] != iVar2) {
    iVar1 = thunk_EXT_FUN_0000b588(iVar1,iVar2,iVar3);
  }
  param_1[1] = iVar1 + iVar3;
  return param_1;
}



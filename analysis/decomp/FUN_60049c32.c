// 60049c32  FUN_60049c32  size=20 bytes
// --- callers ---
//   60043834 FUN_60043834
//   6004a4e6 FUN_6004a4e6
// --- callees ---


void FUN_60049c32(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_2;
  iVar2 = param_2[1] - iVar1 >> 2;
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  *param_1 = iVar1;
  param_1[1] = iVar2;
  return;
}



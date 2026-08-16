// 60049800  FUN_60049800  size=20 bytes
// --- callers ---
//   60049994 FUN_60049994
//   60049a4a FUN_60049a4a
//   60049814 FUN_60049814
// --- callees ---


void FUN_60049800(int *param_1,int *param_2)

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



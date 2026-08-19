// 600de766  FUN_600de766  size=20 bytes
// --- callers ---
// --- callees ---


void FUN_600de766(int *param_1,int *param_2)

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



// 600dfadc  FUN_600dfadc  size=36 bytes
// --- callers ---
//   600df918 FUN_600df918
//   600df674 FUN_600df674
//   600df9c2 FUN_600df9c2
//   60082814 FUN_60082814
//   600dfb00 FUN_600dfb00
//   600df810 FUN_600df810
// --- callees ---


bool FUN_600dfadc(undefined4 *param_1,int *param_2,int param_3)

{
  *param_1 = param_2;
  param_1[1] = param_2;
  param_1[2] = 0;
  param_1[3] = param_3;
  param_3 = param_3 + *(int *)((int)param_2 + 5);
  param_1[4] = param_3;
  param_1[5] = param_3 + *(int *)((int)param_2 + 9);
  return *param_2 != 0;
}



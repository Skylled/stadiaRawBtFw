// 6010135a  FUN_6010135a  size=50 bytes
// --- callers ---
//   6005eaf8 FUN_6005eaf8
//   601013d0 FUN_601013d0
//   6005ea2c FUN_6005ea2c
//   6005e810 FUN_6005e810
//   6005edb8 FUN_6005edb8
// --- callees ---


int * FUN_6010135a(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  *param_1 = param_2;
  iVar1 = *(int *)(param_2 + 8);
  param_1[1] = *(int *)(param_2 + 4);
  param_1[2] = iVar1;
  param_1[3] = param_3;
  param_1[4] = param_4;
  param_1[5] = param_5;
  param_1[6] = param_6;
  return param_1;
}



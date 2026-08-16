// 6004a31a  FUN_6004a31a  size=50 bytes
// --- callers ---
//   6004aee0 FUN_6004aee0
// --- callees ---
//   600451dc FUN_600451dc
//   600452f0 FUN_600452f0
//   6004a27c FUN_6004a27c


void FUN_6004a31a(undefined4 param_1,float *param_2)

{
  float fVar1;
  
  FUN_600452f0();
  FUN_6004a27c(param_1,param_2);
  FUN_600451dc(param_2);
  fVar1 = *param_2;
  *param_2 = fVar1 + param_2[1];
  param_2[1] = fVar1 - param_2[1];
  return;
}



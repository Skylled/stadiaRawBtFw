// 60049c46  FUN_60049c46  size=82 bytes
// --- callers ---
// --- callees ---
//   6004c18c thunk_FUN_600dcd1c


void FUN_60049c46(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  thunk_FUN_600dcd1c(*param_1,param_1[1],param_4);
  thunk_FUN_600dcd1c(param_2,param_2 + param_3 * 4,(param_1[1] - *param_1) + param_4);
  thunk_FUN_600dcd1c(param_4 + (param_5 - (param_1[1] - *param_1 >> 2)) * 4,param_4 + param_5 * 4);
  return;
}



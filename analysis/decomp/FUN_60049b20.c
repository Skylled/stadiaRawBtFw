// 60049b20  FUN_60049b20  size=28 bytes
// --- callers ---
//   60045508 FUN_60045508
// --- callees ---
//   6004bda4 FUN_6004bda4


int FUN_60049b20(int param_1,int param_2,int param_3)

{
  if (param_2 != param_1) {
    param_3 = FUN_6004bda4(param_3,param_1,param_2 - param_1);
  }
  return param_3 + (param_2 - param_1);
}



// 60049d4a  FUN_60049d4a  size=28 bytes
// --- callers ---
//   60043ecc FUN_60043ecc
// --- callees ---
//   6004bda4 FUN_6004bda4


int FUN_60049d4a(int param_1,int param_2,int param_3)

{
  if (param_2 != param_1) {
    param_3 = FUN_6004bda4(param_3,param_1,param_2 - param_1);
  }
  return param_3 + (param_2 - param_1);
}



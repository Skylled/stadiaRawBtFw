// 600dc74e  FUN_600dc74e  size=30 bytes
// --- callers ---
//   6007c4c8 FUN_6007c4c8
//   6007c3e0 FUN_6007c3e0
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588


int FUN_600dc74e(int param_1,int param_2,int param_3)

{
  param_3 = param_3 - (param_2 - param_1);
  if (param_2 != param_1) {
    param_3 = thunk_EXT_FUN_0000b588(param_3,param_1,param_2 - param_1);
  }
  return param_3;
}



// 600dc372  FUN_600dc372  size=28 bytes
// --- callers ---
//   6007b9d4 FUN_6007b9d4
//   6007ba54 FUN_6007ba54
// --- callees ---
//   6013d238 thunk_EXT_FUN_0000b588


int FUN_600dc372(int param_1,int param_2,int param_3)

{
  if (param_2 != param_1) {
    param_3 = thunk_EXT_FUN_0000b588(param_3,param_1,param_2 - param_1);
  }
  return param_3 + (param_2 - param_1);
}



// 600ecbb6  FUN_600ecbb6  size=8 bytes
// --- callers ---
//   60090940 FUN_60090940
//   6008fa18 tasn_dec__6008fa18
//   600902e4 FUN_600902e4
// --- callees ---


undefined4 FUN_600ecbb6(int *param_1,int param_2)

{
  return *(undefined4 *)(*param_1 + *(int *)(param_2 + 4));
}



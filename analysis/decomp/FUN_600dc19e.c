// 600dc19e  FUN_600dc19e  size=34 bytes
// --- callers ---
//   600dc38e FUN_600dc38e
//   600dc1c0 FUN_600dc1c0
// --- callees ---
//   60101fcc FUN_60101fcc
//   6013d378 thunk_EXT_FUN_0000b532


void FUN_600dc19e(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 != 0) {
    if (param_2 < 0) {
      FUN_60101fcc();
    }
    iVar1 = thunk_EXT_FUN_0000b532(param_2 * 2);
  }
  *param_1 = iVar1;
  param_1[1] = iVar1;
  param_1[2] = iVar1 + param_2 * 2;
  return;
}



// 600dc65c  FUN_600dc65c  size=38 bytes
// --- callers ---
//   600dc682 FUN_600dc682
//   6007dc50 FUN_6007dc50
//   6007e5c8 FUN_6007e5c8
//   600dc6e2 FUN_600dc6e2
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532
//   60101fcc FUN_60101fcc


void FUN_600dc65c(int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 != 0) {
    if (0x3fffffff < param_2) {
      FUN_60101fcc();
    }
    iVar1 = thunk_EXT_FUN_0000b532(param_2 * 4);
  }
  *param_1 = iVar1;
  param_1[1] = iVar1;
  param_1[2] = iVar1 + param_2 * 4;
  return;
}



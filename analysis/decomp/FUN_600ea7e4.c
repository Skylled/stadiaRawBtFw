// 600ea7e4  FUN_600ea7e4  size=22 bytes
// --- callers ---
//   6008d6b8 bcm__6008d6b8
//   6008d2a8 bcm__6008d2a8
// --- callees ---
//   600867a4 FUN_600867a4


int FUN_600ea7e4(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x1c) == 0)) {
    FUN_600867a4(param_1 + 0x10c);
  }
  return param_1;
}



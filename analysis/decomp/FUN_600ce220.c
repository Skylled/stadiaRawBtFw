// 600ce220  FUN_600ce220  size=18 bytes
// --- callers ---
//   6005e904 FUN_6005e904
// --- callees ---
//   600ce1f8 FUN_600ce1f8


int FUN_600ce220(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 4;
  FUN_600ce1f8();
  return param_1;
}



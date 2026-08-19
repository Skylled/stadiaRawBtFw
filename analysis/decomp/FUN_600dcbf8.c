// 600dcbf8  FUN_600dcbf8  size=24 bytes
// --- callers ---
//   600dbfba FUN_600dbfba
// --- callees ---
//   600dd65e FUN_600dd65e
//   600dcb9e FUN_600dcb9e


int FUN_600dcbf8(int param_1)

{
  FUN_600dd65e(param_1 + 0x150);
  if (*(int *)(param_1 + 0x48) != 0) {
    FUN_600dcb9e();
  }
  return param_1;
}



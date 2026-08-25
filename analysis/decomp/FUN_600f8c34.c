// 600f8c34  FUN_600f8c34  size=54 bytes
// --- callers ---
//   600f9ae6 FUN_600f9ae6
//   600f9a70 FUN_600f9a70
//   600f8122 FUN_600f8122
//   600f8d34 FUN_600f8d34
//   600f9906 FUN_600f9906
//   600f8f7a FUN_600f8f7a
// --- callees ---


void FUN_600f8c34(int param_1,byte param_2)

{
  if (((param_2 & 2) != 0) && (*(char *)(param_1 + 0xb) == '\0')) {
    *(char *)(param_1 + 0xb) = *(char *)(param_1 + 0xb) + '\x01';
  }
  return;
}



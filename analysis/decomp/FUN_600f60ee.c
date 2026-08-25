// 600f60ee  FUN_600f60ee  size=32 bytes
// --- callers ---
//   600f5ede FUN_600f5ede
//   600f5e3c FUN_600f5e3c
//   600f5bfc FUN_600f5bfc
// --- callees ---
//   600adad8 FUN_600adad8


void FUN_600f60ee(int param_1)

{
  if (*(char *)(param_1 + 6) != '\0') {
    FUN_600adad8(param_1);
  }
  return;
}



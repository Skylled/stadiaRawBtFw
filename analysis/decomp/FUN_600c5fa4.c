// 600c5fa4  FUN_600c5fa4  size=70 bytes
// --- callers ---
//   600c5ff4 FUN_600c5ff4
// --- callees ---
//   600c5db0 FUN_600c5db0
//   600c5cd8 FUN_600c5cd8


void FUN_600c5fa4(char *param_1)

{
  *(undefined2 *)(DAT_600c5ff0 + 0x14a) = *(undefined2 *)(param_1 + 2);
  if (*param_1 == '\0') {
    FUN_600c5cd8(*(undefined2 *)(param_1 + 2));
  }
  else {
    FUN_600c5db0(0xffff,*param_1);
  }
  return;
}



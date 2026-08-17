// 600969e0  FUN_600969e0  size=54 bytes
// --- callers ---
//   600968b0 FUN_600968b0
//   60096e38 FUN_60096e38
// --- callees ---
//   6009655c FUN_6009655c


void FUN_600969e0(char param_1)

{
  *(char *)(DAT_60096a18 + 0x66) = param_1;
  if ((*(char *)(DAT_60096a18 + 0x67) == '\x01') && (param_1 != '\0')) {
    *(undefined1 *)(DAT_60096a18 + 0x67) = 2;
    FUN_6009655c();
  }
  return;
}



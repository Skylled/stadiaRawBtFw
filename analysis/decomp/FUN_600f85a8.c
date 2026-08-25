// 600f85a8  FUN_600f85a8  size=80 bytes
// --- callers ---
//   600f85f8 FUN_600f85f8
//   600b6900 FUN_600b6900
// --- callees ---


void FUN_600f85a8(int param_1)

{
  if (*(char *)(param_1 + 0x11e) != '\0') {
    if ((*(char *)(param_1 + 0x32) == '\x03') || (*(char *)(param_1 + 0x7e) == '\x03')) {
      *(undefined2 *)(param_1 + 0x38) = 12000;
      *(undefined2 *)(param_1 + 0x36) = 2000;
    }
    else {
      *(undefined2 *)(param_1 + 0x38) = 0;
      *(undefined2 *)(param_1 + 0x36) = 0;
    }
  }
  return;
}



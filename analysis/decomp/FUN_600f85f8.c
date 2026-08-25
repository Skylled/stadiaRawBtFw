// 600f85f8  FUN_600f85f8  size=108 bytes
// --- callers ---
//   600fa018 FUN_600fa018
// --- callees ---
//   600f85a8 FUN_600f85a8


void FUN_600f85f8(int param_1,int param_2)

{
  FUN_600f85a8(param_1);
  *(undefined1 *)(param_2 + 0x24) = *(undefined1 *)(param_1 + 0x11e);
  if (*(char *)(param_2 + 0x24) != '\0') {
    *(undefined1 *)(param_2 + 0x26) = *(undefined1 *)(param_1 + 0x7e);
    *(undefined1 *)(param_2 + 0x27) = *(undefined1 *)(param_1 + 0x7f);
    *(undefined1 *)(param_2 + 0x28) = *(undefined1 *)(param_1 + 0x80);
    *(undefined2 *)(param_2 + 0x2e) = *(undefined2 *)(param_1 + 0x86);
    *(undefined2 *)(param_2 + 0x2a) = *(undefined2 *)(param_1 + 0x36);
    *(undefined2 *)(param_2 + 0x2c) = *(undefined2 *)(param_1 + 0x38);
  }
  return;
}



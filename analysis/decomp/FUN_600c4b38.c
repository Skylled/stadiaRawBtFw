// 600c4b38  FUN_600c4b38  size=58 bytes
// --- callers ---
// --- callees ---
//   600c4b7c FUN_600c4b7c
//   6009633c FUN_6009633c


void FUN_600c4b38(int param_1)

{
  if (*(char *)(param_1 + 0xc) == '\0') {
    FUN_6009633c(DAT_600c4b78);
  }
  else {
    *(undefined1 *)(DAT_600c4b74 + 0x104) = *(undefined1 *)(param_1 + 8);
    *(undefined2 *)(DAT_600c4b74 + 0x106) = *(undefined2 *)(param_1 + 10);
    FUN_600c4b7c(0);
  }
  return;
}



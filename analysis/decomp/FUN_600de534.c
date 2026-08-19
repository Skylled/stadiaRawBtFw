// 600de534  FUN_600de534  size=22 bytes
// --- callers ---
//   600de54a FUN_600de54a
// --- callees ---


void FUN_600de534(int param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 10000;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (*(char *)(param_1 + 1) != '\0') {
    *(undefined1 *)(param_1 + 0x24) = 0;
  }
  return;
}



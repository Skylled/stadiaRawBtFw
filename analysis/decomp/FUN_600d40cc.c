// 600d40cc  FUN_600d40cc  size=20 bytes
// --- callers ---
//   6005bdb4 gotham_task__6005bdb4
//   6005c15c FUN_6005c15c
// --- callees ---


void FUN_600d40cc(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x110) = param_2;
  if (*(char *)(param_1 + 0x114) != '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 0x114) = 1;
  return;
}



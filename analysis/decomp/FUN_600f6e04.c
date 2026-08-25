// 600f6e04  FUN_600f6e04  size=70 bytes
// --- callers ---
//   600f633e FUN_600f633e
// --- callees ---


void FUN_600f6e04(int param_1)

{
  undefined1 local_9;
  
  if (param_1 != 0) {
    for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
      if (*(char *)((uint)local_9 + param_1 + 0x8c) != '\0') {
        *(undefined1 *)((uint)local_9 + param_1 + 0x58) = 1;
      }
    }
  }
  return;
}



// 600f6ee2  FUN_600f6ee2  size=56 bytes
// --- callers ---
//   600f622a FUN_600f622a
//   600f6f52 FUN_600f6f52
//   600adeb4 FUN_600adeb4
// --- callees ---


void FUN_600f6ee2(int param_1)

{
  undefined1 local_9;
  
  if (param_1 != 0) {
    for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
      *(undefined1 *)((uint)local_9 + param_1 + 0x58) = 0;
    }
  }
  return;
}



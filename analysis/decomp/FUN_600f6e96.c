// 600f6e96  FUN_600f6e96  size=76 bytes
// --- callers ---
//   600f633e FUN_600f633e
// --- callees ---


undefined1 FUN_600f6e96(int param_1)

{
  byte local_a;
  undefined1 local_9;
  
  local_9 = 1;
  if (param_1 == 0) {
    local_9 = 0;
  }
  else {
    for (local_a = 0; local_a < 10; local_a = local_a + 1) {
      if (*(char *)((uint)local_a + param_1 + 0x8c) != '\0') {
        return 0;
      }
    }
  }
  return local_9;
}



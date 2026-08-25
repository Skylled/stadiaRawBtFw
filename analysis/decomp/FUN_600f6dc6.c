// 600f6dc6  FUN_600f6dc6  size=62 bytes
// --- callers ---
//   600f5b32 FUN_600f5b32
//   600f3da6 FUN_600f3da6
//   600ab9b8 FUN_600ab9b8
//   600f3caa FUN_600f3caa
//   600ad8fc FUN_600ad8fc
//   600f7052 FUN_600f7052
//   600f5a98 FUN_600f5a98
// --- callees ---


char FUN_600f6dc6(int param_1)

{
  undefined1 local_a;
  undefined1 local_9;
  
  local_a = '\0';
  for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
    if (*(char *)((uint)local_9 + param_1 + 0x1e) != '\0') {
      local_a = local_a + '\x01';
    }
  }
  return local_a;
}



// 60094fac  FUN_60094fac  size=74 bytes
// --- callers ---
//   600c67ac FUN_600c67ac
//   600c65b0 FUN_600c65b0
// --- callees ---


char FUN_60094fac(void)

{
  undefined1 local_a;
  undefined1 local_9;
  
  local_a = '\0';
  for (local_9 = 0; local_9 < 4; local_9 = local_9 + 1) {
    if (*(char *)((uint)local_9 * 0x10c + DAT_60094ff8 + 100) != '\0') {
      local_a = local_a + '\x01';
    }
  }
  return local_a;
}



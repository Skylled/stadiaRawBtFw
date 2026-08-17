// 600935dc  FUN_600935dc  size=74 bytes
// --- callers ---
// --- callees ---


char FUN_600935dc(void)

{
  char local_a;
  byte local_9;
  
  local_a = '\0';
  for (local_9 = 0; local_9 < *DAT_60093628; local_9 = local_9 + 1) {
    if (DAT_60093628[(uint)local_9 * 10 + 7] == 0x11) {
      local_a = local_a + '\x01';
    }
  }
  return local_a;
}



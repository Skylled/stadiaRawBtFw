// 600af85c  FUN_600af85c  size=74 bytes
// --- callers ---
//   600af8ac FUN_600af8ac
// --- callees ---


byte FUN_600af85c(void)

{
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (9 < local_9) {
      return 0xff;
    }
    if (*(char *)((uint)local_9 * 0x10c + DAT_600af8a8 + 0xfa) == '\0') break;
    local_9 = local_9 + 1;
  }
  return local_9;
}



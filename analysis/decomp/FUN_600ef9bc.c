// 600ef9bc  FUN_600ef9bc  size=116 bytes
// --- callers ---
//   600ff09c FUN_600ff09c
// --- callees ---


byte FUN_600ef9bc(int param_1,undefined1 param_2)

{
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (9 < local_9) {
      return 0xff;
    }
    if (*(char *)((uint)local_9 * 0x1c + param_1 + 0x15d) == '\0') break;
    local_9 = local_9 + 1;
  }
  *(undefined1 *)((uint)local_9 * 0x1c + param_1 + 0x15d) = 1;
  *(undefined1 *)((uint)local_9 * 0x1c + param_1 + 0x15b) = param_2;
  return local_9;
}



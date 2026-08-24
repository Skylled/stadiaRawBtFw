// 600efa30  FUN_600efa30  size=82 bytes
// --- callers ---
//   600ff09c FUN_600ff09c
// --- callees ---


byte FUN_600efa30(int param_1,char param_2)

{
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (9 < local_9) {
      return 0xff;
    }
    if ((*(char *)((uint)local_9 * 0x20 + param_1 + 4) != '\0') &&
       (param_2 == *(char *)((uint)local_9 * 0x20 + param_1 + 0x20))) break;
    local_9 = local_9 + 1;
  }
  return local_9;
}



// 600efa82  FUN_600efa82  size=116 bytes
// --- callers ---
//   600959cc FUN_600959cc
// --- callees ---


int FUN_600efa82(int param_1,short param_2)

{
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (9 < local_9) {
      return 0;
    }
    if ((*(char *)((uint)local_9 * 0x1c + param_1 + 0x15d) != '\0') &&
       (param_2 == *(short *)((uint)local_9 * 0x1c + param_1 + 0x158))) break;
    local_9 = local_9 + 1;
  }
  return (uint)local_9 * 0x1c + param_1 + 0x144;
}



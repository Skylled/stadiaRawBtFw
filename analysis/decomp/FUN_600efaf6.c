// 600efaf6  FUN_600efaf6  size=292 bytes
// --- callers ---
//   600ff21c FUN_600ff21c
// --- callees ---


int FUN_600efaf6(int param_1,ushort param_2)

{
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (9 < local_9) {
      return 0;
    }
    if ((((((local_9 < 9) && (*(char *)((uint)local_9 * 0x1c + param_1 + 0x15d) != '\0')) &&
          (*(char *)((local_9 + 1) * 0x1c + param_1 + 0x15d) != '\0')) &&
         ((*(ushort *)((uint)local_9 * 0x1c + param_1 + 0x158) <= param_2 &&
          (param_2 < *(ushort *)((local_9 + 1) * 0x1c + param_1 + 0x158))))) ||
        (((local_9 < 9 &&
          ((*(char *)((uint)local_9 * 0x1c + param_1 + 0x15d) != '\0' &&
           (*(char *)((local_9 + 1) * 0x1c + param_1 + 0x15d) == '\0')))) &&
         (*(ushort *)((uint)local_9 * 0x1c + param_1 + 0x158) <= param_2)))) ||
       ((local_9 == 9 && (*(ushort *)(param_1 + 0x254) <= param_2)))) break;
    local_9 = local_9 + 1;
  }
  return (uint)local_9 * 0x1c + param_1 + 0x144;
}



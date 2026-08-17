// 600bf2d8  FUN_600bf2d8  size=74 bytes
// --- callers ---
//   600be060 FUN_600be060
//   600bdf3c FUN_600bdf3c
//   600fa568 FUN_600fa568
//   600be100 FUN_600be100
// --- callees ---


char * FUN_600bf2d8(short param_1)

{
  char *local_10;
  ushort local_a;
  
  local_a = 0;
  local_10 = DAT_600bf324;
  while( true ) {
    if (2 < local_a) {
      return (char *)0x0;
    }
    if ((*local_10 != '\0') && (param_1 == *(short *)(local_10 + 0x22))) break;
    local_a = local_a + 1;
    local_10 = local_10 + 0x3c;
  }
  return local_10;
}



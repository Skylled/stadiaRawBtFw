// 600bc710  FUN_600bc710  size=74 bytes
// --- callers ---
//   600b8ba4 FUN_600b8ba4
// --- callees ---


char * FUN_600bc710(char param_1)

{
  char *local_10;
  ushort local_a;
  
  local_10 = DAT_600bc75c;
  local_a = 0;
  while( true ) {
    if (3 < local_a) {
      return (char *)0x0;
    }
    if ((*local_10 != '\0') && (param_1 == local_10[1])) break;
    local_a = local_a + 1;
    local_10 = local_10 + 0xa4;
  }
  return local_10;
}



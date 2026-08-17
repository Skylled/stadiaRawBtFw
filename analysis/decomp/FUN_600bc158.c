// 600bc158  FUN_600bc158  size=76 bytes
// --- callers ---
//   600f75c0 FUN_600f75c0
// --- callees ---


char * FUN_600bc158(undefined2 param_1)

{
  ushort local_e;
  char *local_c;
  
  local_c = DAT_600bc1a4;
  local_e = 0;
  while( true ) {
    if (5 < local_e) {
      return (char *)0x0;
    }
    if (*local_c == '\0') break;
    local_e = local_e + 1;
    local_c = local_c + 0x34;
  }
  *local_c = '\x01';
  *(undefined2 *)(local_c + 2) = param_1;
  return local_c;
}



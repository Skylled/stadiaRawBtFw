// 600bc1a8  FUN_600bc1a8  size=74 bytes
// --- callers ---
//   600f76ac FUN_600f76ac
//   600f75c0 FUN_600f75c0
//   600ba1c4 FUN_600ba1c4
// --- callees ---


char * FUN_600bc1a8(short param_1)

{
  ushort local_e;
  char *local_c;
  
  local_c = DAT_600bc1f4;
  local_e = 0;
  while( true ) {
    if (5 < local_e) {
      return (char *)0x0;
    }
    if ((*local_c != '\0') && (param_1 == *(short *)(local_c + 2))) break;
    local_e = local_e + 1;
    local_c = local_c + 0x34;
  }
  return local_c;
}



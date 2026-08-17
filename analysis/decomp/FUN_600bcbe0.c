// 600bcbe0  FUN_600bcbe0  size=74 bytes
// --- callers ---
//   600f7f74 FUN_600f7f74
//   600f9d16 FUN_600f9d16
//   600b9e28 FUN_600b9e28
//   600b8ba4 FUN_600b8ba4
//   600f7d46 FUN_600f7d46
//   600f8a96 FUN_600f8a96
//   600f808c FUN_600f808c
//   600b9938 FUN_600b9938
//   600b9d94 FUN_600b9d94
// --- callees ---


char * FUN_600bcbe0(short param_1)

{
  char *local_10;
  int local_c;
  
  local_10 = DAT_600bcc2c;
  local_c = 0;
  while( true ) {
    if (3 < local_c) {
      return (char *)0x0;
    }
    if ((*local_10 != '\0') && (param_1 == *(short *)(local_10 + 2))) break;
    local_c = local_c + 1;
    local_10 = local_10 + 0xa4;
  }
  return local_10;
}



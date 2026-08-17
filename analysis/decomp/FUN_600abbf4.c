// 600abbf4  FUN_600abbf4  size=78 bytes
// --- callers ---
//   600f40c0 FUN_600f40c0
//   600f419c FUN_600f419c
//   600f414a FUN_600f414a
// --- callees ---


short * FUN_600abbf4(short param_1)

{
  short *local_10;
  byte local_9;
  
  local_9 = 0;
  local_10 = DAT_600abc44;
  while( true ) {
    if (9 < local_9) {
      return (short *)0x0;
    }
    if (((char)local_10[1] != '\0') && (param_1 == *local_10)) break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 9;
  }
  return local_10;
}



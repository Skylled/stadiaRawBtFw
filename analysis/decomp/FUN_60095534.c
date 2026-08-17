// 60095534  FUN_60095534  size=80 bytes
// --- callers ---
//   600ef8a0 FUN_600ef8a0
// --- callees ---
//   600efcc6 FUN_600efcc6


char * FUN_60095534(undefined4 param_1)

{
  char *local_10;
  byte local_9;
  
  local_10 = DAT_60095584;
  local_9 = 0;
  while( true ) {
    if (9 < local_9) {
      return (char *)0x0;
    }
    if (*local_10 == '\0') break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 7;
  }
  *local_10 = '\x01';
  FUN_600efcc6(local_10 + 1,param_1);
  return local_10;
}



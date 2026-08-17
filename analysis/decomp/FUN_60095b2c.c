// 60095b2c  FUN_60095b2c  size=74 bytes
// --- callers ---
//   600ff4de FUN_600ff4de
//   600ff21c FUN_600ff21c
//   600ff482 FUN_600ff482
//   600ff3a2 FUN_600ff3a2
//   600fefac FUN_600fefac
//   600ff31a FUN_600ff31a
//   600ff404 FUN_600ff404
// --- callees ---


char * FUN_60095b2c(char param_1)

{
  char *local_10;
  byte local_9;
  
  local_9 = 0;
  local_10 = DAT_60095b78;
  while( true ) {
    if (9 < local_9) {
      return (char *)0x0;
    }
    if ((*local_10 != '\0') && (param_1 == local_10[0x1c])) break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 0x20;
  }
  return local_10;
}



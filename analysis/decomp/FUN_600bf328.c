// 600bf328  FUN_600bf328  size=72 bytes
// --- callers ---
//   600bde90 FUN_600bde90
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


char * FUN_600bf328(void)

{
  char *local_10;
  ushort local_a;
  
  local_a = 0;
  local_10 = DAT_600bf370;
  while( true ) {
    if (2 < local_a) {
      return (char *)0x0;
    }
    if (*local_10 == '\0') break;
    local_a = local_a + 1;
    local_10 = local_10 + 0x3c;
  }
  thunk_EXT_FUN_0000b5ba(local_10,0,0x3c);
  *(char **)(local_10 + 0x18) = local_10;
  return local_10;
}



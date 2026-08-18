// 600b059c  FUN_600b059c  size=78 bytes
// --- callers ---
//   600f717c FUN_600f717c
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


int FUN_600b059c(undefined4 param_1)

{
  byte local_d;
  int local_c;
  
  local_c = DAT_600b05ec;
  local_d = 0;
  while( true ) {
    if (2 < local_d) {
      return 0;
    }
    if (*(char *)(local_c + 0x1a) == '\0') break;
    local_d = local_d + 1;
    local_c = local_c + 0x1b;
  }
  *(undefined1 *)(local_c + 0x1a) = 1;
  thunk_EXT_FUN_0000b572(local_c + 0x14,param_1,6);
  return local_c;
}



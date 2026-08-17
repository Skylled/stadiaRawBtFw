// 600aa7a0  FUN_600aa7a0  size=92 bytes
// --- callers ---
//   600aae30 FUN_600aae30
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572


int FUN_600aa7a0(undefined4 param_1)

{
  int local_10;
  byte local_9;
  
  local_9 = 0;
  local_10 = DAT_600aa7fc;
  while( true ) {
    if (5 < local_9) {
      return local_10;
    }
    if (*(char *)(local_10 + 0x10) == '\0') break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 0x20;
  }
  thunk_EXT_FUN_0000b5ba(local_10,0,0x20);
  *(undefined1 *)(local_10 + 0x10) = 1;
  thunk_EXT_FUN_0000b572(local_10,param_1,6);
  return local_10;
}



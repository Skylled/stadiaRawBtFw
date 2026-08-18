// 600af390  FUN_600af390  size=96 bytes
// --- callers ---
//   600ab110 FUN_600ab110
//   600ab088 FUN_600ab088
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


int FUN_600af390(void)

{
  int local_10;
  byte local_9;
  
  local_10 = DAT_600af3f0 + 0xc30;
  local_9 = 0;
  while( true ) {
    if (9 < local_9) {
      return 0;
    }
    if (*(char *)((uint)local_9 * 0x58 + DAT_600af3f0 + 0xc84) == '\0') break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 0x58;
  }
  thunk_EXT_FUN_0000b5ba(local_10,0,0x58);
  *(undefined1 *)(local_10 + 0x54) = 1;
  return local_10;
}



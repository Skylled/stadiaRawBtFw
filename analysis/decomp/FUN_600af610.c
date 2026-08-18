// 600af610  FUN_600af610  size=154 bytes
// --- callers ---
//   600adbfc FUN_600adbfc
//   600abb14 FUN_600abb14
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined1 FUN_600af610(byte param_1,undefined4 param_2,byte *param_3,undefined1 *param_4)

{
  byte local_9;
  
  local_9 = param_1;
  while( true ) {
    if (9 < local_9) {
      return 0;
    }
    if ((*(char *)((uint)local_9 * 0x10c + DAT_600af6ac + 0xfa) != '\0') &&
       (*(char *)((uint)local_9 * 0x10c + DAT_600af6ac + 0x1c) == '\x04')) break;
    local_9 = local_9 + 1;
  }
  thunk_EXT_FUN_0000b572(param_2,(uint)local_9 * 0x10c + DAT_600af6ac + 0xd,6);
  *param_3 = local_9;
  *param_4 = *(undefined1 *)((uint)local_9 * 0x10c + DAT_600af6ac + 0x13);
  return 1;
}



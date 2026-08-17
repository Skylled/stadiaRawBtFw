// 600a80b4  FUN_600a80b4  size=80 bytes
// --- callers ---
//   600a6720 FUN_600a6720
// --- callees ---


int FUN_600a80b4(char param_1)

{
  int local_10;
  int local_c;
  
  local_c = DAT_600a8104;
  local_10 = 0;
  while( true ) {
    if (7 < local_10) {
      return 0;
    }
    if (((*(ushort *)(local_c + 0x2a) & 0x80) != 0) && (param_1 == *(char *)(local_c + 0x50)))
    break;
    local_10 = local_10 + 1;
    local_c = local_c + 0xfc;
  }
  return local_c;
}



// 600a7e8c  FUN_600a7e8c  size=86 bytes
// --- callers ---
//   600a4c5c FUN_600a4c5c
// --- callees ---


int FUN_600a7e8c(int param_1)

{
  int local_10;
  int local_c;
  
  local_c = DAT_600a7ee4;
  local_10 = 0;
  while( true ) {
    if (0xd < local_10) {
      return 0;
    }
    if ((((*(ushort *)(local_c + 0xe) & 0x80) != 0) &&
        (*(short *)(local_c + 0xc) == *(short *)(param_1 + 0xc))) && (param_1 != local_c)) break;
    local_10 = local_10 + 1;
    local_c = local_c + 0x14;
  }
  return local_c;
}



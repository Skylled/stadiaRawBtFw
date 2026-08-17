// 600a223c  FUN_600a223c  size=64 bytes
// --- callers ---
//   600a2280 FUN_600a2280
//   600c3450 FUN_600c3450
// --- callees ---


int FUN_600a223c(void)

{
  int local_10;
  ushort local_a;
  
  local_10 = DAT_600a227c;
  local_a = 0;
  while( true ) {
    if (0x1d < local_a) {
      return 0;
    }
    if (*(char *)(local_10 + 0x2e) != '\0') break;
    local_a = local_a + 1;
    local_10 = local_10 + 0x30;
  }
  return local_10 + 8;
}



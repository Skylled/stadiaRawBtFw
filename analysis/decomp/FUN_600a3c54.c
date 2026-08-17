// 600a3c54  FUN_600a3c54  size=118 bytes
// --- callers ---
//   600a3cd0 FUN_600a3cd0
// --- callees ---
//   600a3a38 FUN_600a3a38


void FUN_600a3c54(void)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (3 < local_c) {
      return;
    }
    if (*(char *)(local_c * 0x24 + DAT_600a3ccc + 0x66c) < '\0') break;
    local_c = local_c + 1;
  }
  *(byte *)(local_c * 0x24 + DAT_600a3ccc + 0x66c) =
       *(byte *)(local_c * 0x24 + DAT_600a3ccc + 0x66c) & 0x7f;
  FUN_600a3a38(0x80,local_c,0);
  return;
}



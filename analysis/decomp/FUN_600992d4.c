// 600992d4  FUN_600992d4  size=66 bytes
// --- callers ---
//   600a014c FUN_600a014c
// --- callees ---
//   600b8ba4 FUN_600b8ba4


void FUN_600992d4(void)

{
  ushort local_e;
  undefined2 *local_c;
  
  local_c = DAT_60099318;
  for (local_e = 0; local_e < 4; local_e = local_e + 1) {
    if (*(char *)(local_c + 0x94) != '\0') {
      FUN_600b8ba4(*local_c,3);
    }
    local_c = local_c + 0xa6;
  }
  return;
}



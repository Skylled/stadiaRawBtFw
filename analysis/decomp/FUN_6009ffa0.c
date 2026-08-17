// 6009ffa0  FUN_6009ffa0  size=186 bytes
// --- callers ---
//   6009fcf4 FUN_6009fcf4
// --- callees ---


uint * FUN_6009ffa0(void)

{
  int local_18;
  uint local_14;
  uint *local_10;
  uint *local_c;
  
  local_c = DAT_600a005c;
  local_10 = DAT_600a005c;
  local_14 = 0xffffffff;
  for (local_18 = 0; local_18 < 8; local_18 = local_18 + 1) {
    if ((((*(ushort *)((int)local_c + 0x2a) & 0x80) != 0) &&
        ((*(ushort *)((int)local_c + 0x2a) & 0x1010) == 0)) && (*local_c < local_14)) {
      local_10 = local_c;
      local_14 = *local_c;
    }
    local_c = local_c + 0x3f;
  }
  if (local_14 == 0xffffffff) {
    local_c = DAT_600a005c;
    for (local_18 = 0; local_18 < 8; local_18 = local_18 + 1) {
      if (((*(ushort *)((int)local_c + 0x2a) & 0x80) != 0) && (*local_c < local_14)) {
        local_10 = local_c;
        local_14 = *local_c;
      }
      local_c = local_c + 0x3f;
    }
  }
  return local_10;
}



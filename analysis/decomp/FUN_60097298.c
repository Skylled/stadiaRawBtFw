// 60097298  FUN_60097298  size=340 bytes
// --- callers ---
//   60098d8c FUN_60098d8c
// --- callees ---


char FUN_60097298(ushort *param_1)

{
  byte bVar1;
  byte bVar2;
  byte local_11;
  ushort local_10;
  byte local_d;
  ushort local_c;
  char local_9;
  
  local_c = *param_1;
  local_d = 0;
  local_10 = *(ushort *)(DAT_600973ec + 0xadc);
  local_11 = 0;
  if (((local_c == 0) || (0x200 < local_c)) || ((local_c - 1 & local_c) != 0)) {
    local_9 = '\0';
  }
  else {
    for (; local_c != 0; local_c = local_c >> 1) {
      local_11 = local_11 + 1;
    }
    if ((*(byte *)(DAT_600973f0 + (local_11 - 1) * 2) &
        *(byte *)((uint)*(byte *)((local_11 - 1) * 2 + DAT_600973f0 + 1) + DAT_600973ec + 0x839)) ==
        0) {
      local_9 = '\0';
    }
    else {
      local_9 = '\x01';
      for (; local_10 != 0; local_10 = local_10 >> 1) {
        if ((local_10 & 1) != 0) {
          bVar2 = *(byte *)(DAT_600973f0 + ((uint)local_11 * 0xb + (uint)local_d) * 2);
          bVar1 = *(byte *)(((uint)local_11 * 0xb + (uint)local_d) * 2 + DAT_600973f0 + 1);
          if (((bVar2 != 0) && (bVar1 != 0)) &&
             ((bVar2 & *(byte *)((uint)bVar1 + DAT_600973ec + 0x839)) == 0)) {
            local_9 = '\0';
            break;
          }
        }
        local_d = local_d + 1;
      }
      if ((local_9 == '\0') &&
         ((uint)DAT_600973f4[3] * 0x1000000 +
          (uint)*DAT_600973f4 + (uint)DAT_600973f4[1] * 0x100 + (uint)DAT_600973f4[2] * 0x10000 == 0
         )) {
        local_9 = *(char *)(DAT_600973ec + 0xa68);
      }
    }
  }
  return local_9;
}



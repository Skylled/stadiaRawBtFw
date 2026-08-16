// 600998ec  FUN_600998ec  size=204 bytes
// --- callers ---
//   600f23d2 FUN_600f23d2
// --- callees ---


void FUN_600998ec(char *param_1)

{
  int local_10;
  short *local_c;
  
  local_c = DAT_600999b8;
  if (*param_1 == '\0') {
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      if (((char)local_c[0x94] != '\0') &&
         ((ushort)((ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1]) == *local_c)) {
        *(char *)((int)local_c + 0x127) = param_1[3];
        local_c[0x84] = (ushort)(byte)param_1[5] * 0x100 + (ushort)(byte)param_1[4];
        local_c[0x85] = (ushort)(byte)param_1[7] * 0x100 + (ushort)(byte)param_1[6];
        return;
      }
      local_c = local_c + 0xa6;
    }
  }
  return;
}



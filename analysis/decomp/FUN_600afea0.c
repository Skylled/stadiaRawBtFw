// 600afea0  FUN_600afea0  size=114 bytes
// --- callers ---
//   600f5ede FUN_600f5ede
//   600f6042 FUN_600f6042
//   600f5e3c FUN_600f5e3c
//   600ad8b0 FUN_600ad8b0
//   600f60c2 FUN_600f60c2
//   600f5fb4 FUN_600f5fb4
//   600f5db4 FUN_600f5db4
// --- callees ---


int FUN_600afea0(short param_1)

{
  ushort local_a;
  
  local_a = 0;
  while( true ) {
    if (9 < local_a) {
      return 0;
    }
    if ((*(char *)((uint)local_a * 0x10c + DAT_600aff14 + 0xfa) != '\0') &&
       (param_1 == *(short *)((uint)local_a * 0x10c + DAT_600aff14 + 0x18))) break;
    local_a = local_a + 1;
  }
  return (uint)local_a * 0x10c + DAT_600aff14;
}



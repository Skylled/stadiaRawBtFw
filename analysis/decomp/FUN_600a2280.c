// 600a2280  FUN_600a2280  size=116 bytes
// --- callers ---
//   600c3e84 FUN_600c3e84
// --- callees ---
//   600a223c FUN_600a223c


int FUN_600a2280(int param_1)

{
  int iVar1;
  ushort local_e;
  int local_c;
  
  if (param_1 == 0) {
    iVar1 = FUN_600a223c();
  }
  else {
    local_e = (short)DAT_600a22f8 * (short)((param_1 + -8) - DAT_600a22f4 >> 4) + 1;
    local_c = (uint)local_e * 0x30 + DAT_600a22fc + 0xb5c;
    for (; local_e < 0x1e; local_e = local_e + 1) {
      if (*(char *)(local_c + 0x2e) != '\0') {
        return local_c + 8;
      }
      local_c = local_c + 0x30;
    }
    iVar1 = 0;
  }
  return iVar1;
}



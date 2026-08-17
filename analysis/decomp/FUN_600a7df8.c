// 600a7df8  FUN_600a7df8  size=138 bytes
// --- callers ---
//   600a4c5c FUN_600a4c5c
// --- callees ---


int FUN_600a7df8(char param_1,short param_2)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_c = DAT_600a7e84;
  if (((param_1 == '\0') || (*(int *)(DAT_600a7e88 + 0x1aa8) == 0)) ||
     (param_2 != *(short *)(*(int *)(DAT_600a7e88 + 0x1aa8) + 0xc))) {
    for (local_10 = 0; local_10 < 0xe; local_10 = local_10 + 1) {
      if (((*(ushort *)(local_c + 0xe) & 0x80) != 0) && (param_2 == *(short *)(local_c + 0xc))) {
        return local_c;
      }
      local_c = local_c + 0x14;
    }
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(DAT_600a7e88 + 0x1aa8);
  }
  return iVar1;
}



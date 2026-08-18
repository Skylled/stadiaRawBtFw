// 600afb50  FUN_600afb50  size=122 bytes
// --- callers ---
//   600adeb4 FUN_600adeb4
//   600ab564 FUN_600ab564
//   600ad4f4 FUN_600ad4f4
// --- callees ---


byte FUN_600afb50(ushort param_1)

{
  byte local_9;
  
  local_9 = 0;
  while ((local_9 < 10 &&
         (((*(char *)((uint)local_9 * 0x28 + DAT_600afbcc + 0xaa9) == '\0' ||
           (param_1 < *(ushort *)((uint)local_9 * 0x28 + DAT_600afbcc + 0xaa4))) ||
          (*(ushort *)((uint)local_9 * 0x28 + DAT_600afbcc + 0xaa6) < param_1))))) {
    local_9 = local_9 + 1;
  }
  return local_9;
}



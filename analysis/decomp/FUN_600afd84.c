// 600afd84  FUN_600afd84  size=110 bytes
// --- callers ---
//   600ab620 FUN_600ab620
//   600f395a FUN_600f395a
//   600f39fc FUN_600f39fc
//   600ab778 FUN_600ab778
//   600f3b0a FUN_600f3b0a
// --- callees ---


undefined1 FUN_600afd84(short param_1)

{
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (5 < local_9) {
      return 0;
    }
    if ((*(char *)(DAT_600afdf4 + (uint)local_9 * 0x60 + 0x12a4) != '\0') &&
       (param_1 == *(short *)(DAT_600afdf4 + (uint)local_9 * 0x60 + 0x126c))) break;
    local_9 = local_9 + 1;
  }
  return 1;
}



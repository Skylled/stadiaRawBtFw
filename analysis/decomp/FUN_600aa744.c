// 600aa744  FUN_600aa744  size=86 bytes
// --- callers ---
//   600f3378 FUN_600f3378
// --- callees ---


int FUN_600aa744(short param_1)

{
  int local_10;
  byte local_9;
  
  local_9 = 0;
  for (local_10 = DAT_600aa79c;
      (local_9 < 6 &&
      (((*(char *)(local_10 + 0x10) == '\0' || (*(char *)(local_10 + 0x11) == '\0')) ||
       (param_1 != *(short *)(local_10 + 0xc))))); local_10 = local_10 + 0x20) {
    local_9 = local_9 + 1;
  }
  return local_10;
}



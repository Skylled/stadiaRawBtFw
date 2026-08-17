// 600b076c  FUN_600b076c  size=178 bytes
// --- callers ---
//   600f3ed6 FUN_600f3ed6
// --- callees ---
//   600a1e9c FUN_600a1e9c
//   6009c848 FUN_6009c848
//   6009dc14 FUN_6009dc14


char FUN_600b076c(void)

{
  undefined1 auStack_1a [2];
  undefined1 auStack_18 [3];
  char local_15;
  ushort local_14;
  byte local_11;
  int local_10;
  byte local_9;
  
  local_10 = DAT_600b0820;
  local_11 = 0;
  for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
    if ((*(char *)(local_10 + 0x2d) != '\0') && (local_11 < *(byte *)(local_10 + 0x2e))) {
      local_11 = *(byte *)(local_10 + 0x2e);
    }
    local_10 = local_10 + 0x30;
  }
  if ((local_11 == 0xff) || (local_11 == 0)) {
    local_15 = FUN_6009c848(0);
  }
  else {
    local_15 = FUN_6009c848(3);
  }
  if (local_15 != '\0') {
    local_14 = FUN_600a1e9c(auStack_18,auStack_1a);
    if (local_11 == 0) {
      if ((local_14 & 0x100) == 0) {
        local_14 = local_14 & 0xfeff;
      }
    }
    else {
      local_14 = local_14 | 0x100;
    }
    FUN_6009dc14(local_14);
  }
  return local_15;
}



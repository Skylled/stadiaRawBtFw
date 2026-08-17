// 600adbfc  FUN_600adbfc  size=134 bytes
// --- callers ---
//   600ab424 FUN_600ab424
//   600ab318 FUN_600ab318
// --- callees ---
//   600af1d8 FUN_600af1d8
//   600adad8 FUN_600adad8
//   600af610 FUN_600af610
//   600af6b0 FUN_600af6b0


void FUN_600adbfc(void)

{
  int iVar1;
  undefined1 uStack_19;
  undefined1 auStack_18 [7];
  byte local_11;
  int local_10;
  char local_a;
  byte local_9;
  
  local_a = '\0';
  if (*(int *)(DAT_600adc84 + 0x1558) != 0) {
    if (*(short *)(DAT_600adc84 + 0x1550) != 0) {
      FUN_600af1d8();
      local_9 = 0;
      while (iVar1 = FUN_600af610(local_9,auStack_18,&local_11,&uStack_19), iVar1 != 0) {
        local_10 = (uint)local_11 * 0x10c + DAT_600adc84;
        local_a = FUN_600af6b0(local_10);
        if (local_a == '\0') {
          FUN_600adad8(auStack_18);
        }
        local_11 = local_11 + 1;
        local_9 = local_11;
      }
    }
  }
  return;
}



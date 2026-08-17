// 60095f9c  FUN_60095f9c  size=130 bytes
// --- callers ---
// --- callees ---
//   60092e5c FUN_60092e5c
//   60092de8 FUN_60092de8


void FUN_60095f9c(void)

{
  byte local_9;
  
  for (local_9 = 0; local_9 < 7; local_9 = local_9 + 1) {
    if ((1 << local_9 & *(uint *)(DAT_60096058 + 0x134)) != 0) {
      switch(local_9) {
      case 0:
        FUN_60092e5c();
      }
    }
  }
  for (local_9 = 0; local_9 < 7; local_9 = local_9 + 1) {
    if ((1 << local_9 & *(uint *)(DAT_60096058 + 0x134)) != 0) {
      switch(local_9) {
      case 0:
        FUN_60092de8(0);
      }
    }
  }
  return;
}



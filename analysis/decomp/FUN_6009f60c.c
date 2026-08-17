// 6009f60c  FUN_6009f60c  size=50 bytes
// --- callers ---
//   6009f93c FUN_6009f93c
// --- callees ---
//   6009f4e4 FUN_6009f4e4
//   60098284 FUN_60098284
//   600b1c7c FUN_600b1c7c


void FUN_6009f60c(void)

{
  int iVar1;
  
  iVar1 = FUN_6009f4e4();
  if (iVar1 != 0) {
    if ((*(byte *)(DAT_6009f640 + 0x831) & 0x40) == 0) {
      FUN_60098284(1,1);
    }
    else {
      FUN_600b1c7c(1);
    }
  }
  return;
}



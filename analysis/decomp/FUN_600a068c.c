// 600a068c  FUN_600a068c  size=144 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a0298 FUN_600a0298
//   600a027c FUN_600a027c
//   600b0824 FUN_600b0824
//   600a0bc4 FUN_600a0bc4
//   600aa3cc FUN_600aa3cc


void FUN_600a068c(char *param_1)

{
  int iVar1;
  char *local_1c;
  
  FUN_600aa3cc(DAT_600a071c);
  if (*param_1 == '\0') {
    for (iVar1 = 0; local_1c = param_1 + 1, iVar1 < 8; iVar1 = iVar1 + 1) {
      *(char *)(DAT_600a0720 + iVar1) = *local_1c;
      param_1 = local_1c;
    }
  }
  if ((*(byte *)(DAT_600a0724 + 0x831) & 0x40) == 0) {
    if ((*(byte *)(DAT_600a0724 + 0x831) & 0x20) == 0) {
      FUN_600b0824(DAT_600a0728);
      if (*(int *)(DAT_600a072c + 0xd4) == 0) {
        FUN_600a0bc4();
      }
      else {
        (**(code **)(DAT_600a072c + 0xd4))(2,0);
      }
    }
    else {
      FUN_600a0298();
    }
  }
  else {
    FUN_600a027c();
  }
  return;
}



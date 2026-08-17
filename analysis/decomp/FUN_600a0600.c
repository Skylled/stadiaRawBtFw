// 600a0600  FUN_600a0600  size=128 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600b1cf0 FUN_600b1cf0
//   600a0298 FUN_600a0298
//   600a0bc4 FUN_600a0bc4
//   600aa3cc FUN_600aa3cc
//   6009fa34 FUN_6009fa34


void FUN_600a0600(char *param_1)

{
  FUN_600aa3cc(DAT_600a0680);
  if (*param_1 == '\0') {
    *(char *)(DAT_600a0684 + 0xa6b) = param_1[1];
    FUN_6009fa34(*(undefined1 *)(DAT_600a0684 + 0xa6b));
    FUN_600b1cf0(900);
  }
  if ((*(byte *)(DAT_600a0684 + 0x831) & 0x20) == 0) {
    if (*(int *)(DAT_600a0688 + 0xd4) == 0) {
      FUN_600a0bc4();
    }
    else {
      (**(code **)(DAT_600a0688 + 0xd4))(2,0);
    }
  }
  else {
    FUN_600a0298();
  }
  return;
}



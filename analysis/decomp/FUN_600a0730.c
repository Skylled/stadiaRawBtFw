// 600a0730  FUN_600a0730  size=112 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600b0824 FUN_600b0824
//   600a0bc4 FUN_600a0bc4
//   600aa3cc FUN_600aa3cc


void FUN_600a0730(char *param_1)

{
  FUN_600aa3cc(DAT_600a07a0);
  if (*param_1 == '\0') {
    *(ushort *)(DAT_600a07a4 + 0xaee) = (ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1];
  }
  FUN_600b0824(DAT_600a07a8);
  if (*(int *)(DAT_600a07ac + 0xd4) == 0) {
    FUN_600a0bc4();
  }
  else {
    (**(code **)(DAT_600a07ac + 0xd4))(2,0);
  }
  return;
}



// 6009a114  FUN_6009a114  size=60 bytes
// --- callers ---
//   600c269c FUN_600c269c
// --- callees ---


undefined4 FUN_6009a114(int param_1)

{
  if (param_1 == 0) {
    *(undefined4 *)(DAT_6009a150 + 0x644) = 0;
  }
  else {
    if (*(int *)(DAT_6009a150 + 0x644) != 0) {
      return 2;
    }
    *(int *)(DAT_6009a150 + 0x644) = param_1;
  }
  return 0;
}



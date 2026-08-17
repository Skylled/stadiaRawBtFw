// 600bd118  FUN_600bd118  size=48 bytes
// --- callers ---
//   6006d588 FUN_6006d588
// --- callees ---


undefined1 FUN_600bd118(char param_1)

{
  if (param_1 != -1) {
    *(char *)(DAT_600bd148 + 0x380) = param_1;
    *DAT_600bd14c = param_1;
  }
  return *(undefined1 *)(DAT_600bd148 + 0x380);
}



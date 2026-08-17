// 600bd484  FUN_600bd484  size=48 bytes
// --- callers ---
//   6006d588 FUN_6006d588
// --- callees ---


undefined1 FUN_600bd484(char param_1)

{
  if (param_1 != -1) {
    *(char *)(DAT_600bd4b4 + 0xf94) = param_1;
    *DAT_600bd4b8 = param_1;
  }
  return *(undefined1 *)(DAT_600bd4b4 + 0xf94);
}



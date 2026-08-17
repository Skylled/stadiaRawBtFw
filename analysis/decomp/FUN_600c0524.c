// 600c0524  FUN_600c0524  size=44 bytes
// --- callers ---
//   6006d588 FUN_6006d588
// --- callees ---


undefined1 FUN_600c0524(char param_1)

{
  if (param_1 != -1) {
    *(char *)(DAT_600c0550 + 0x1c) = param_1;
    *DAT_600c0554 = param_1;
  }
  return *(undefined1 *)(DAT_600c0550 + 0x1c);
}



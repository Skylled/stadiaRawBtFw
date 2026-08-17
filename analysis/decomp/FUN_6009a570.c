// 6009a570  FUN_6009a570  size=56 bytes
// --- callers ---
//   6006d588 FUN_6006d588
// --- callees ---


undefined1 FUN_6009a570(char param_1)

{
  if (param_1 != -1) {
    *(char *)(DAT_6009a5a8 + 0x1abc) = param_1;
    *DAT_6009a5ac = param_1;
  }
  return *(undefined1 *)(DAT_6009a5a8 + 0x1abc);
}



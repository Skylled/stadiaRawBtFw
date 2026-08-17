// 600aa678  FUN_600aa678  size=48 bytes
// --- callers ---
//   6006d588 FUN_6006d588
// --- callees ---


undefined1 FUN_600aa678(char param_1)

{
  if (param_1 != -1) {
    *(char *)(DAT_600aa6a8 + 0x28) = param_1;
    *DAT_600aa6ac = param_1;
  }
  return *(undefined1 *)(DAT_600aa6a8 + 0x28);
}



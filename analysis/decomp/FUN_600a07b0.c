// 600a07b0  FUN_600a07b0  size=80 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600b1d74 FUN_600b1d74
//   600a0228 FUN_600a0228


void FUN_600a07b0(char *param_1)

{
  if (*param_1 == '\0') {
    *(char *)(DAT_600a0800 + 0x9c5) = param_1[1];
    *(undefined1 *)(DAT_600a0800 + 0x9c4) = *(undefined1 *)(DAT_600a0800 + 0x9c5);
  }
  FUN_600b1d74(0,1,1);
  FUN_600a0228();
  return;
}



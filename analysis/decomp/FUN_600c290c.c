// 600c290c  FUN_600c290c  size=192 bytes
// --- callers ---
// --- callees ---
//   600a1900 FUN_600a1900
//   600a407c FUN_600a407c
//   600a1d3c FUN_600a1d3c


void FUN_600c290c(int param_1)

{
  if (*(short *)(param_1 + 8) != 0xff) {
    FUN_600a1900(*(undefined2 *)(param_1 + 8),*(undefined2 *)(DAT_600c29cc + 0x272),
                 *(undefined2 *)(DAT_600c29cc + 0x270));
  }
  if (*(short *)(param_1 + 10) != 0xff) {
    FUN_600a1d3c(*(undefined2 *)(param_1 + 10),*(undefined2 *)(DAT_600c29cc + 0x26e),
                 *(undefined2 *)(DAT_600c29cc + 0x26c));
  }
  if (*(char *)(param_1 + 0xc) != -1) {
    if (*(char *)(param_1 + 0xc) == '\0') {
      *(undefined1 *)(DAT_600c29cc + 0x245) = 1;
    }
    else {
      *(undefined1 *)(DAT_600c29cc + 0x245) = 0;
    }
  }
  if (*(char *)(param_1 + 0xd) != -1) {
    if (*(char *)(param_1 + 0xd) == '\0') {
      *(undefined1 *)(DAT_600c29cc + 0x246) = 0;
    }
    else {
      *(undefined1 *)(DAT_600c29cc + 0x246) = 1;
    }
  }
  if ((*(char *)(param_1 + 0xc) != -1) || (*(char *)(param_1 + 0xd) != -1)) {
    FUN_600a407c(*(char *)(DAT_600c29cc + 0x245) == '\0',*(undefined1 *)(DAT_600c29cc + 0x246));
  }
  return;
}



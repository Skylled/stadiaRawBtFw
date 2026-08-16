// 60096624  FUN_60096624  size=226 bytes
// --- callers ---
//   6006ba0c FUN_6006ba0c
// --- callees ---
//   600d931a FUN_600d931a


void FUN_60096624(void)

{
  *(undefined1 *)(DAT_60096708 + 100) = 0;
  *(undefined1 *)(DAT_60096708 + 0x66) = 0;
  *(undefined1 *)(DAT_60096708 + 0x65) = 0;
  *(undefined4 *)(DAT_60096708 + 0x80) = 0;
  *(undefined4 *)(DAT_60096708 + 0x84) = 0;
  *(undefined1 *)(DAT_60096708 + 0x67) = 0;
  *(undefined1 *)(DAT_60096708 + 0x89) = 1;
  if (*DAT_6009670c == '\0') {
    *(undefined1 *)(DAT_60096708 + 0x8a) = 0x18;
    *(undefined1 *)(DAT_60096708 + 0x8b) = 0x18;
  }
  else {
    *(char *)(DAT_60096708 + 0x8a) = *DAT_6009670c;
    *(char *)(DAT_60096708 + 0x8b) = *DAT_6009670c;
  }
  *(undefined1 *)(DAT_60096708 + 0x8c) = 1;
  *(undefined1 *)(DAT_60096708 + 0x8d) = 1;
  *(undefined1 *)(DAT_60096708 + 0x8e) = 1;
  *(undefined1 *)(DAT_60096708 + 0x8f) = 1;
  *(undefined1 *)(DAT_60096708 + 0x90) = 0;
  *(undefined1 *)(DAT_60096708 + 0x91) = 0;
  *(undefined1 *)(DAT_60096708 + 0x92) = 5;
  *(undefined1 *)(DAT_60096708 + 0x93) = 5;
  *(undefined1 *)(DAT_60096708 + 0x94) = 1;
  if (*DAT_60096710 == 0) {
    *(undefined2 *)(DAT_60096708 + 0x96) = 200;
  }
  else {
    *(short *)(DAT_60096708 + 0x96) = *DAT_60096710;
  }
  FUN_600d931a(DAT_60096714);
  return;
}



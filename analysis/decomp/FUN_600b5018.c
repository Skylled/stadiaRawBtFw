// 600b5018  FUN_600b5018  size=94 bytes
// --- callers ---
//   600c53f8 FUN_600c53f8
// --- callees ---


undefined1 FUN_600b5018(byte param_1)

{
  if ((param_1 & 0xc0) != 0xc0) {
    if ((char)param_1 < '\0') {
      *(undefined1 *)(DAT_600b5078 + 0xe9d) = 0;
    }
    if ((param_1 & 0x40) != 0) {
      *(undefined1 *)(DAT_600b5078 + 0xe9d) = 1;
    }
  }
  if ((param_1 == 0) || (param_1 == 1)) {
    *(byte *)(DAT_600b5078 + 0xe9c) = param_1;
  }
  return *(undefined1 *)(DAT_600b5078 + 0xe9c);
}



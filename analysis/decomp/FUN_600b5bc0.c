// 600b5bc0  FUN_600b5bc0  size=68 bytes
// --- callers ---
//   600a0520 FUN_600a0520
// --- callees ---


void FUN_600b5bc0(short param_1)

{
  undefined2 local_a;
  
  local_a = param_1;
  if (param_1 == 0) {
    local_a = 1;
    *(short *)(DAT_600b5c04 + 0xe9e) = *(short *)(DAT_600b5c04 + 0xe9e) + -1;
  }
  *(short *)(DAT_600b5c04 + 0xf4a) = local_a;
  *(undefined2 *)(DAT_600b5c04 + 0xf4c) = *(undefined2 *)(DAT_600b5c04 + 0xf4a);
  return;
}



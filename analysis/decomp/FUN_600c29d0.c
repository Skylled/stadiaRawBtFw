// 600c29d0  FUN_600c29d0  size=84 bytes
// --- callers ---
// --- callees ---
//   600a17ec FUN_600a17ec


void FUN_600c29d0(int param_1)

{
  *(undefined2 *)(DAT_600c2a24 + 0x26c) = *(undefined2 *)(param_1 + 8);
  *(undefined2 *)(DAT_600c2a24 + 0x26e) = *(undefined2 *)(param_1 + 10);
  *(undefined2 *)(DAT_600c2a24 + 0x270) = *(undefined2 *)(param_1 + 0xc);
  *(undefined2 *)(DAT_600c2a24 + 0x272) = *(undefined2 *)(param_1 + 0xe);
  FUN_600a17ec(*(undefined2 *)(DAT_600c2a24 + 0x270),*(undefined2 *)(DAT_600c2a24 + 0x272),
               *(undefined2 *)(DAT_600c2a24 + 0x26c),*(undefined2 *)(DAT_600c2a24 + 0x26e));
  return;
}



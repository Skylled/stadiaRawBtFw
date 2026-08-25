// 600f83f2  FUN_600f83f2  size=94 bytes
// --- callers ---
//   600b6550 FUN_600b6550
//   600f8450 FUN_600f8450
//   600b61c4 FUN_600b61c4
//   600b5ec8 FUN_600b5ec8
// --- callees ---


undefined1 FUN_600f83f2(int param_1)

{
  if ((*(uint *)(*(int *)(param_1 + 300) + 0x20) & 8) == 0) {
    *(byte *)(param_1 + 0xa8) = *(byte *)(param_1 + 0xa8) & 0xf7;
  }
  if ((*(uint *)(*(int *)(param_1 + 300) + 0x20) & 0x10) == 0) {
    *(byte *)(param_1 + 0xa8) = *(byte *)(param_1 + 0xa8) & 0xef;
  }
  return *(undefined1 *)(param_1 + 0xa8);
}



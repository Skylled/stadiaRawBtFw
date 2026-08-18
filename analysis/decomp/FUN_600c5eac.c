// 600c5eac  FUN_600c5eac  size=62 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60094650 FUN_60094650


void FUN_600c5eac(void)

{
  if (*(short *)(DAT_600c5eec + 0x14a) != -1) {
    FUN_60094650(*(undefined2 *)(DAT_600c5eec + 0x14a));
  }
  thunk_EXT_FUN_0000b5ba(DAT_600c5ef0,0,6);
  *(undefined2 *)(DAT_600c5eec + 0x14a) = 0xffff;
  return;
}



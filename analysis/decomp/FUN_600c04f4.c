// 600c04f4  FUN_600c04f4  size=38 bytes
// --- callers ---
//   600f31c6 FUN_600f31c6
// --- callees ---
//   600c8610 FUN_600c8610
//   600c1738 FUN_600c1738
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600c04f4(void)

{
  thunk_EXT_FUN_0000b5ba(DAT_600c051c,0,0x204);
  *(undefined1 *)(DAT_600c051c + 0x1c) = *DAT_600c0520;
  FUN_600c1738();
  FUN_600c8610(8);
  return;
}



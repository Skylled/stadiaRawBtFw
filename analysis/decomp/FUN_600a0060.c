// 600a0060  FUN_600a0060  size=88 bytes
// --- callers ---
//   600a333c FUN_600a333c
// --- callees ---
//   600a01c4 FUN_600a01c4
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600a0060(void)

{
  thunk_EXT_FUN_0000b5ba(DAT_600a00b8,0,0xf9);
  *(undefined4 *)(DAT_600a00b8 + 0x714) = 1;
  *(undefined4 *)(DAT_600a00b8 + 0x730) = 2;
  *(undefined4 *)(DAT_600a00b8 + 0x74c) = 4;
  *(undefined2 *)(DAT_600a00b8 + 0xaf0) = 0xcc18;
  *(undefined2 *)(DAT_600a00b8 + 0xaf2) = 0x3f;
  *(undefined1 *)(DAT_600a00b8 + 0x1ab9) = 0xff;
  *(undefined1 *)(DAT_600a00b8 + 0x1aba) = 0xff;
  FUN_600a01c4();
  return;
}



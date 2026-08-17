// 600a9e74  FUN_600a9e74  size=92 bytes
// --- callers ---
//   6006bf74 FUN_6006bf74
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600a9e74(void)

{
  undefined4 local_c;
  
  thunk_EXT_FUN_0000b5ba(DAT_600a9ed0,0,0xd8);
  *(undefined2 *)(DAT_600a9ed0 + 0x5a) = 0x2a4;
  *(undefined2 *)(DAT_600a9ed0 + 0x5e) = 0x1f;
  *(undefined1 *)(DAT_600a9ed0 + 0x61) = *DAT_600a9ed4;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    *(undefined2 *)(local_c * 0x34 + DAT_600a9ed0 + 0xb8) = 1;
  }
  return;
}



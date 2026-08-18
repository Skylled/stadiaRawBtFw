// 600bb1f8  FUN_600bb1f8  size=164 bytes
// --- callers ---
//   600f31c6 FUN_600f31c6
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600bb1f8(void)

{
  short local_a;
  
  thunk_EXT_FUN_0000b5ba(DAT_600bb29c,0,0xf5c);
  *(undefined2 *)(DAT_600bb29c + 0xf56) = 0xfff;
  for (local_a = 0; local_a < 7; local_a = local_a + 1) {
    *(undefined1 **)(DAT_600bb29c + local_a * 0x158 + 0x3c0) =
         DAT_600bb29c + (local_a + 1) * 0x158 + 0x29c;
  }
  *(undefined4 *)(DAT_600bb29c + 0xe94) = DAT_600bb2a0;
  *(undefined4 *)(DAT_600bb29c + 0xe98) = DAT_600bb2a4;
  *(undefined2 *)(DAT_600bb29c + 0xf58) = 0x40;
  DAT_600bb29c[0xe9c] = 1;
  *(undefined2 *)(DAT_600bb29c + 0xea0) = 3;
  *DAT_600bb29c = *DAT_600bb2a8;
  DAT_600bb29c[0xf4e] = 0x70;
  return;
}



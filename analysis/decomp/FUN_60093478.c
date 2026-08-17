// 60093478  FUN_60093478  size=110 bytes
// --- callers ---
//   600c269c FUN_600c269c
// --- callees ---
//   60095c14 FUN_60095c14
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600a337c FUN_600a337c


void FUN_60093478(void)

{
  undefined1 local_a;
  undefined1 local_9;
  
  thunk_EXT_FUN_0000b5ba(DAT_600934e8,0,0x65);
  if (*(char *)(*DAT_600934ec + 1) != '\0') {
    FUN_60095c14(DAT_600934f0);
    FUN_600a337c(3,DAT_600934f8,DAT_600934f4);
  }
  for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
    for (local_a = 0; local_a < 3; local_a = local_a + 1) {
      *(undefined1 *)((uint)local_a + (uint)local_9 * 0x5c + DAT_600934fc + 0x170) = 0x32;
    }
  }
  return;
}



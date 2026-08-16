// 60093500  FUN_60093500  size=210 bytes
// --- callers ---
//   600c51d0 FUN_600c51d0
// --- callees ---
//   60095c14 FUN_60095c14
//   6009633c FUN_6009633c
//   600a337c FUN_600a337c


void FUN_60093500(void)

{
  undefined1 local_a;
  undefined1 local_9;
  
  FUN_600a337c(4,DAT_600935d4,0);
  FUN_60095c14(0);
  for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
    if (*(char *)((uint)local_9 * 0x5c + DAT_600935d8 + 0x180) != '\0') {
      for (local_a = 0; local_a < 3; local_a = local_a + 1) {
        FUN_6009633c((uint)local_a * 0x18 + (uint)local_9 * 0x5c + 0x128 + DAT_600935d8);
        *(undefined1 *)((uint)local_a + (uint)local_9 * 0x5c + DAT_600935d8 + 0x170) = 0x32;
        *(undefined1 *)((uint)local_a + (uint)local_9 * 0x5c + DAT_600935d8 + 0x176) = 0;
      }
      *(undefined1 *)((uint)local_9 * 0x5c + DAT_600935d8 + 0x179) = 0;
      *(undefined1 *)((uint)local_9 * 0x5c + DAT_600935d8 + 0x180) = 0;
    }
  }
  return;
}



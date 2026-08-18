// 60094374  FUN_60094374  size=324 bytes
// --- callers ---
// --- callees ---
//   600962dc FUN_600962dc
//   600efcc6 FUN_600efcc6
//   6006dbac FUN_6006dbac


void FUN_60094374(int param_1)

{
  undefined2 *puVar1;
  byte local_a;
  byte local_9;
  
  for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
    if (*(char *)((uint)local_9 * 0x5c + DAT_600944b8 + 0x180) != '\0') {
      for (local_a = 0; local_a < 3; local_a = local_a + 1) {
        if (param_1 == (uint)local_a * 0x18 + (uint)local_9 * 0x5c + 0x128 + DAT_600944b8) {
          *(char *)((uint)local_9 * 0x5c + DAT_600944b8 + 0x179) =
               *(char *)((uint)local_9 * 0x5c + DAT_600944b8 + 0x179) + -1;
          *(undefined1 *)((uint)local_a + (uint)local_9 * 0x5c + DAT_600944b8 + 0x170) = 0x32;
          break;
        }
      }
      if (*(char *)((uint)local_9 * 0x5c + DAT_600944b8 + 0x179) == '\0') {
        *(undefined1 *)((uint)local_9 * 0x5c + DAT_600944b8 + 0x180) = 0;
      }
      if (local_a < 3) break;
    }
  }
  if ((local_9 != 3) &&
     (puVar1 = (undefined2 *)FUN_6006dbac(0x10,DAT_600944bc,0x3cc), puVar1 != (undefined2 *)0x0)) {
    *puVar1 = 0x112;
    *(undefined1 *)(puVar1 + 7) =
         *(undefined1 *)((uint)local_a + (uint)local_9 * 0x5c + DAT_600944b8 + 0x176);
    FUN_600efcc6(puVar1 + 4,(uint)local_9 * 0x5c + DAT_600944b8 + 0x17a);
    FUN_600962dc(puVar1);
  }
  return;
}



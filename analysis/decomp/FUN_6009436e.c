// 6009436e  FUN_6009436e  size=2 bytes
// --- callers ---
// --- callees ---


void FUN_6009436e(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined2 *puVar1;
  byte bStack_a;
  byte bStack_9;
  
  *param_3 = param_2;
  for (bStack_9 = 0; bStack_9 < 3; bStack_9 = bStack_9 + 1) {
    if (*(char *)((uint)bStack_9 * 0x5c + DAT_600944b8 + 0x180) != '\0') {
      for (bStack_a = 0; bStack_a < 3; bStack_a = bStack_a + 1) {
        if (param_1 == (uint)bStack_a * 0x18 + (uint)bStack_9 * 0x5c + 0x128 + DAT_600944b8) {
          *(char *)((uint)bStack_9 * 0x5c + DAT_600944b8 + 0x179) =
               *(char *)((uint)bStack_9 * 0x5c + DAT_600944b8 + 0x179) + -1;
          *(undefined1 *)((uint)bStack_a + (uint)bStack_9 * 0x5c + DAT_600944b8 + 0x170) = 0x32;
          break;
        }
      }
      if (*(char *)((uint)bStack_9 * 0x5c + DAT_600944b8 + 0x179) == '\0') {
        *(undefined1 *)((uint)bStack_9 * 0x5c + DAT_600944b8 + 0x180) = 0;
      }
      if (bStack_a < 3) break;
    }
  }
  if ((bStack_9 != 3) &&
     (puVar1 = (undefined2 *)FUN_6006dbac(0x10,DAT_600944bc,0x3cc), puVar1 != (undefined2 *)0x0)) {
    *puVar1 = 0x112;
    *(undefined1 *)(puVar1 + 7) =
         *(undefined1 *)((uint)bStack_a + (uint)bStack_9 * 0x5c + DAT_600944b8 + 0x176);
    FUN_600efcc6(puVar1 + 4,(uint)bStack_9 * 0x5c + DAT_600944b8 + 0x17a);
    FUN_600962dc(puVar1);
  }
  return;
}



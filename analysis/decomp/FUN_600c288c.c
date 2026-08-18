// 600c288c  FUN_600c288c  size=114 bytes
// --- callers ---
// --- callees ---
//   600f04e4 FUN_600f04e4
//   60099d18 FUN_60099d18
//   60096314 FUN_60096314


void FUN_600c288c(void)

{
  int iVar1;
  undefined1 local_9;
  
  iVar1 = FUN_60099d18();
  if (iVar1 != 0) {
    for (local_9 = 0; local_9 < *(byte *)(DAT_600c2900 + 0xe4); local_9 = local_9 + 1) {
      FUN_600f04e4((uint)local_9 * 0x20 + DAT_600c2900 + 4,
                   *(undefined1 *)((uint)local_9 * 0x20 + DAT_600c2900 + 0x22));
    }
  }
  *(undefined1 *)(DAT_600c2900 + 0x108) = 0;
  *(undefined4 *)(DAT_600c2900 + 0x114) = DAT_600c2904;
  FUN_60096314(DAT_600c2908,0,0x78);
  return;
}



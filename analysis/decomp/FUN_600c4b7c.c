// 600c4b7c  FUN_600c4b7c  size=200 bytes
// --- callers ---
//   600c4b38 FUN_600c4b38
// --- callees ---
//   6009a254 FUN_6009a254
//   60096314 FUN_60096314
//   6009a1dc FUN_6009a1dc


void FUN_600c4b7c(void)

{
  undefined1 local_9;
  
  if ((*(byte *)(DAT_600c4c44 + 0x104) & 1) != 0) {
    for (local_9 = 0; local_9 < *(byte *)(DAT_600c4c44 + 0xe4); local_9 = local_9 + 1) {
      FUN_6009a1dc((uint)local_9 * 0x20 + DAT_600c4c44 + 4,
                   *(undefined1 *)((uint)local_9 * 0x20 + DAT_600c4c44 + 0x22),
                   PTR_FUN_600c5228_1_600c4c48);
    }
  }
  if ((*(byte *)(DAT_600c4c44 + 0x104) & 2) != 0) {
    for (local_9 = 0; local_9 < *(byte *)(DAT_600c4c44 + 0xe4); local_9 = local_9 + 1) {
      if (*(char *)((uint)local_9 * 0x20 + DAT_600c4c44 + 0x22) == '\x01') {
        FUN_6009a254((uint)local_9 * 0x20 + DAT_600c4c44 + 4,PTR_FUN_600c527c_1_600c4c4c);
      }
    }
  }
  if (*(short *)(DAT_600c4c44 + 0x106) != 0) {
    *(undefined **)(DAT_600c4c44 + 0xf4) = PTR_FUN_600c4b7c_1_600c4c50;
    FUN_60096314(DAT_600c4c54,0,(uint)*(ushort *)(DAT_600c4c44 + 0x106) * 1000);
  }
  return;
}



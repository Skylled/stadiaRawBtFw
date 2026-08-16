// 600c53f8  FUN_600c53f8  size=236 bytes
// --- callers ---
//   600c4da8 FUN_600c4da8
// --- callees ---
//   600b5018 FUN_600b5018
//   6009931c FUN_6009931c


void FUN_600c53f8(void)

{
  byte bVar1;
  bool bVar2;
  undefined1 local_9;
  
  bVar2 = false;
  bVar1 = *(char *)(DAT_600c54e4 + 0xe4) - *(char *)(DAT_600c54e4 + 0xe5);
  if (*(char *)(DAT_600c54e4 + 0xe4) == *(char *)(DAT_600c54e4 + 0xe5)) {
    FUN_600b5018(1);
  }
  else {
    if ((*(char *)(*DAT_600c54e8 + 2) == '\0') ||
       ((*(char *)(DAT_600c54e4 + 0x244) != '\0' && (1 < bVar1)))) {
      FUN_600b5018(0);
      bVar2 = true;
    }
    for (local_9 = 0; local_9 < *(byte *)(DAT_600c54e4 + 0xe4); local_9 = local_9 + 1) {
      if ((*(char *)((uint)local_9 * 0x20 + DAT_600c54e4 + 0xc) == '\x01') &&
         (*(char *)((uint)local_9 * 0x20 + DAT_600c54e4 + 0x22) == '\x01')) {
        if ((!bVar2) &&
           ((*(char *)((uint)local_9 * 0x20 + DAT_600c54e4 + 0xd) != '\0' &&
            (*(char *)(*DAT_600c54e8 + 2) == '\x01')))) {
          FUN_600b5018(0);
          bVar2 = true;
        }
        if ((*(char *)((uint)local_9 * 0x20 + DAT_600c54e4 + 0xd) == '\x02') || (1 < bVar1)) {
          FUN_6009931c((uint)local_9 * 0x20 + DAT_600c54e4 + 4,0,0);
        }
      }
    }
    if (!bVar2) {
      FUN_600b5018(1);
    }
  }
  return;
}



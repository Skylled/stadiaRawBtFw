// 600a5760  FUN_600a5760  size=210 bytes
// --- callers ---
//   600a8108 FUN_600a8108
//   600f1f82 FUN_600f1f82
// --- callees ---
//   600d9246 FUN_600d9246
//   600bc7e8 FUN_600bc7e8
//   60098ec8 FUN_60098ec8
//   600a51a8 FUN_600a51a8
//   600f1b72 FUN_600f1b72
//   600d9250 FUN_600d9250
//   6006ddd8 FUN_6006ddd8


void FUN_600a5760(void)

{
  int iVar1;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int local_1c;
  
  if (*(char *)(DAT_600a5834 + 0x118c) == '\0') {
    if (*(char *)(DAT_600a5834 + 0x117a) != '\0') {
      *(undefined1 *)(DAT_600a5834 + 0x117a) = 0;
      FUN_600bc7e8(0);
    }
    local_28 = *(undefined4 *)(DAT_600a5834 + 0x1ad0);
    uStack_24 = *(undefined4 *)(DAT_600a5834 + 0x1ad4);
    uStack_20 = *(undefined4 *)(DAT_600a5834 + 0x1ad8);
    FUN_600d9246(DAT_600a5838);
    while( true ) {
      local_1c = FUN_600d9250(&local_28);
      if (local_1c == 0) break;
      iVar1 = FUN_60098ec8(local_1c + 1,*(undefined1 *)(local_1c + 0x1c));
      if (iVar1 != 0) {
        if (*(short *)(local_1c + 8) == 0) {
          FUN_600f1b72(local_1c + 1,*(undefined1 *)(local_1c + 0x1c),*(undefined4 *)(local_1c + 0xc)
                       ,*(undefined4 *)(local_1c + 0x10));
        }
        else {
          FUN_600a51a8(local_1c + 1,*(undefined2 *)(local_1c + 8),*(undefined1 *)(local_1c + 10),
                       *(undefined4 *)(local_1c + 0x14),*(undefined4 *)(local_1c + 0x18),
                       *(undefined4 *)(local_1c + 0xc),*(undefined4 *)(local_1c + 0x10));
        }
      }
      FUN_6006ddd8(local_1c,DAT_600a583c,0xdf0);
    }
  }
  return;
}



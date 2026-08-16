// 6009f124  FUN_6009f124  size=210 bytes
// --- callers ---
//   600f1646 FUN_600f1646
//   600f2532 FUN_600f2532
// --- callees ---
//   6009fa34 FUN_6009fa34
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_6009f124(char *param_1,ushort param_2)

{
  byte bVar1;
  byte local_9;
  
  if (*param_1 == '\0') {
    if (2 < param_2) {
      bVar1 = param_1[2];
      if (*(char *)(DAT_6009f1f8 + 0xa6b) == '\0') {
        FUN_6009fa34(bVar1);
      }
      if ((bVar1 & 7) == 0) {
        bVar1 = bVar1 >> 3;
      }
      else {
        bVar1 = (bVar1 >> 3) + 1;
      }
      thunk_EXT_FUN_0000b5ba(*(undefined4 *)(DAT_6009f1f8 + 0xa70),0,bVar1);
    }
    *(undefined1 *)(DAT_6009f1f8 + 0xa6c) = *(undefined1 *)(DAT_6009f1f8 + 0xa6b);
    for (local_9 = 0; local_9 < 8; local_9 = local_9 + 1) {
      *(byte *)(DAT_6009f1f8 + (uint)local_9 * 0xfc + 0x133a) =
           *(byte *)(DAT_6009f1f8 + (uint)local_9 * 0xfc + 0x133a) & 0xfd;
    }
  }
  return;
}



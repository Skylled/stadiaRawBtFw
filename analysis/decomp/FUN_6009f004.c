// 6009f004  FUN_6009f004  size=132 bytes
// --- callers ---
//   6009f08c FUN_6009f08c
// --- callees ---


byte FUN_6009f004(void)

{
  byte bVar1;
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (*(byte *)(DAT_6009f088 + 0xa6b) <= local_9) {
      return local_9;
    }
    bVar1 = local_9 >> 3;
    if (((int)(uint)*(byte *)((uint)bVar1 + *(int *)(DAT_6009f088 + 0xa70)) >> (local_9 & 7) & 1U)
        == 0) break;
    local_9 = local_9 + 1;
  }
  *(byte *)((uint)bVar1 + *(int *)(DAT_6009f088 + 0xa70)) =
       (byte)(1 << (local_9 & 7)) | *(byte *)((uint)bVar1 + *(int *)(DAT_6009f088 + 0xa70));
  return local_9;
}



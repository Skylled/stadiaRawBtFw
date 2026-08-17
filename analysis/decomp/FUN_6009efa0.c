// 6009efa0  FUN_6009efa0  size=94 bytes
// --- callers ---
//   6009f08c FUN_6009f08c
// --- callees ---


void FUN_6009efa0(byte param_1)

{
  if (param_1 < *(byte *)(DAT_6009f000 + 0xa6b)) {
    *(byte *)((uint)(param_1 >> 3) + *(int *)(DAT_6009f000 + 0xa70)) =
         ~(byte)(1 << (param_1 & 7)) &
         *(byte *)((uint)(param_1 >> 3) + *(int *)(DAT_6009f000 + 0xa70));
  }
  return;
}



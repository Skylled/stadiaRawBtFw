// 600c6380  FUN_600c6380  size=92 bytes
// --- callers ---
//   600fe05a FUN_600fe05a
//   600fe930 FUN_600fe930
// --- callees ---


void FUN_600c6380(int param_1)

{
  int iVar1;
  undefined1 local_9;
  
  iVar1 = DAT_600c63dc;
  for (local_9 = 0; local_9 < 6; local_9 = local_9 + 1) {
    if (param_1 == *(int *)((local_9 + 0x25) * 0x20 + iVar1)) {
      *(undefined1 *)((uint)local_9 * 0x20 + iVar1 + 0x4ad) = 0;
      *(undefined1 *)((uint)local_9 * 0x20 + iVar1 + 0x4ac) = 3;
    }
  }
  return;
}



// 6009c240  FUN_6009c240  size=122 bytes
// --- callers ---
//   6009c59c FUN_6009c59c
//   6009c444 FUN_6009c444
// --- callees ---
//   600f045e FUN_600f045e


char FUN_6009c240(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_a;
  undefined1 local_9;
  
  iVar1 = DAT_6009c2bc;
  local_a = '\0';
  for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
    if (((*(char *)((uint)local_9 * 9 + iVar1 + 0x100) != '\0') &&
        ((*(byte *)((uint)local_9 * 9 + iVar1 + 0xfe) & 2) != 0)) &&
       (iVar2 = FUN_600f045e((uint)local_9 * 9 + 0xf8 + iVar1,2), iVar2 == 0)) {
      local_a = local_a + '\x01';
    }
  }
  return local_a;
}



// 600f72b6  FUN_600f72b6  size=74 bytes
// --- callers ---
//   600f3caa FUN_600f3caa
// --- callees ---
//   600b0548 FUN_600b0548


char FUN_600f72b6(undefined4 param_1)

{
  int iVar1;
  undefined1 local_a;
  undefined1 local_9;
  
  local_a = '\0';
  iVar1 = FUN_600b0548(param_1);
  if (iVar1 != 0) {
    for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
      if (*(char *)(iVar1 + (uint)local_9) != '\0') {
        local_a = local_a + '\x01';
      }
    }
  }
  return local_a;
}



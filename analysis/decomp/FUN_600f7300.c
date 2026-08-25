// 600f7300  FUN_600f7300  size=90 bytes
// --- callers ---
//   600f3caa FUN_600f3caa
// --- callees ---
//   600b0548 FUN_600b0548


undefined1 FUN_600f7300(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  byte local_9;
  
  iVar1 = FUN_600b0548(param_1);
  if (iVar1 != 0) {
    for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
      if (*(char *)(iVar1 + (uint)local_9) != '\0') {
        *param_2 = *(undefined1 *)(iVar1 + (uint)local_9);
        return 1;
      }
    }
  }
  return 0;
}



// 60047834  queue__60047834  size=42 bytes
// src: queue.c
// --- callers ---
//   6004b8ce FUN_6004b8ce
// --- callees ---
//   600488f4 heap_5_improved__600488f4
//   6004c084 thunk_FUN_601016a2
//   6004780c FUN_6004780c


/* src: queue.c */

void queue__60047834(int param_1)

{
  if (param_1 == 0) {
    thunk_FUN_601016a2(DAT_60047864,0x799,DAT_60047860);
  }
  FUN_6004780c(param_1);
  if (*(char *)(param_1 + 0x46) == '\0') {
    heap_5_improved__600488f4(param_1);
    return;
  }
  return;
}



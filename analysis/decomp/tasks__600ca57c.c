// 600ca57c  tasks__600ca57c  size=30 bytes
// src: tasks.c
// --- callers ---
//   60083730 FUN_60083730
// --- callees ---
//   601016a2 FUN_601016a2


/* src: tasks.c */

int tasks__600ca57c(int param_1)

{
  if (param_1 == 0) {
    param_1 = *DAT_600ca59c;
    if (param_1 == 0) {
      FUN_601016a2(DAT_600ca5a4,0x91b,DAT_600ca5a0);
    }
  }
  return param_1 + 0x34;
}



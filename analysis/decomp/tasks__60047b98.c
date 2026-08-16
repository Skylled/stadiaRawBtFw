// 60047b98  tasks__60047b98  size=64 bytes
// src: tasks.c
// --- callers ---
// --- callees ---
//   600478cc FUN_600478cc
//   6004c084 thunk_FUN_601016a2
//   60047958 FUN_60047958
//   60047aa8 tasks__60047aa8


/* src: tasks.c */

void tasks__60047b98(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (*DAT_60047bdc != 0) {
      thunk_FUN_601016a2(DAT_60047be4,0x542,DAT_60047be0);
    }
    FUN_60047958();
    FUN_600478cc(param_1,0);
    iVar1 = tasks__60047aa8();
    if (iVar1 != 0) {
      return;
    }
  }
  *DAT_60047bd8 = 0x10000000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}



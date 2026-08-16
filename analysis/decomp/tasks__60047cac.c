// 60047cac  tasks__60047cac  size=44 bytes
// src: tasks.c
// --- callers ---
//   60047548 FUN_60047548
//   60047678 queue__60047678
//   60047290 queue__60047290
// --- callees ---
//   6004bb32 FUN_6004bb32
//   600478cc FUN_600478cc
//   6004c084 thunk_FUN_601016a2


/* src: tasks.c */

void tasks__60047cac(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    thunk_FUN_601016a2(DAT_60047cdc,0xc7d,DAT_60047cd8);
  }
  FUN_6004bb32(param_1,*DAT_60047ce0 + 0x18);
  FUN_600478cc(param_2,1);
  return;
}



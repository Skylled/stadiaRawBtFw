// 60047d3c  tasks__60047d3c  size=54 bytes
// src: tasks.c
// --- callers ---
//   6004bc98 FUN_6004bc98
// --- callees ---
//   600478cc FUN_600478cc
//   6004bb1a FUN_6004bb1a
//   6004c084 thunk_FUN_601016a2


/* src: tasks.c */

void tasks__60047d3c(int param_1,undefined4 param_2,int param_3)

{
  if (param_1 == 0) {
    thunk_FUN_601016a2(DAT_60047d78,0xca8,DAT_60047d74);
  }
  FUN_6004bb1a(param_1,*DAT_60047d7c + 0x18);
  if (param_3 != 0) {
    param_2 = 0xffffffff;
  }
  FUN_600478cc(param_2,param_3);
  return;
}



// 60047ce4  tasks__60047ce4  size=72 bytes
// src: tasks.c
// --- callers ---
//   6004703c FUN_6004703c
// --- callees ---
//   600478cc FUN_600478cc
//   6004bb1a FUN_6004bb1a
//   6004c084 thunk_FUN_601016a2


/* src: tasks.c */

void tasks__60047ce4(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    thunk_FUN_601016a2(DAT_60047d30,0xc8e,DAT_60047d2c);
  }
  if (*DAT_60047d34 == 0) {
    thunk_FUN_601016a2(DAT_60047d30,0xc92,DAT_60047d2c);
  }
  iVar1 = *DAT_60047d38;
  *(uint *)(*DAT_60047d38 + 0x18) = param_2 | 0x80000000;
  FUN_6004bb1a(param_1,iVar1 + 0x18);
  FUN_600478cc(param_3,1);
  return;
}



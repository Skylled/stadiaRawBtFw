// 6004723c  queue__6004723c  size=74 bytes
// src: queue.c
// --- callers ---
//   6004b8ce FUN_6004b8ce
// --- callees ---
//   6004c084 thunk_FUN_601016a2
//   60048774 heap_5_improved__60048774
//   600471bc queue__600471bc


/* src: queue.c */

int * queue__6004723c(int param_1,int param_2,undefined1 param_3,undefined4 param_4)

{
  int *piVar1;
  
  if (param_1 == 0) {
    thunk_FUN_601016a2(DAT_6004728c,0x16c,DAT_60047288,param_4,param_4);
  }
  piVar1 = (int *)heap_5_improved__60048774(param_2 * param_1 + 0x50);
  if (piVar1 != (int *)0x0) {
    *(undefined1 *)((int)piVar1 + 0x46) = 0;
    if (param_2 == 0) {
      *piVar1 = (int)piVar1;
    }
    else {
      *piVar1 = (int)(piVar1 + 0x14);
    }
    piVar1[0xf] = param_1;
    piVar1[0x10] = param_2;
    queue__600471bc(piVar1,1);
    *(undefined1 *)(piVar1 + 0x13) = param_3;
  }
  return piVar1;
}



// 600471bc  queue__600471bc  size=114 bytes
// src: queue.c
// --- callers ---
//   6004723c queue__6004723c
// --- callees ---
//   6004c084 thunk_FUN_601016a2
//   60047d80 tasks__60047d80
//   6004bb04 FUN_6004bb04
//   60048580 FUN_60048580
//   600485c8 FUN_600485c8


/* src: queue.c */

undefined4 queue__600471bc(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    thunk_FUN_601016a2(DAT_60047234,0xfb,DAT_60047230,param_4,param_4);
  }
  FUN_60048580();
  iVar1 = *param_1;
  param_1[2] = iVar1;
  iVar2 = param_1[0x10] * param_1[0xf];
  param_1[1] = iVar1 + iVar2;
  param_1[3] = (iVar2 - param_1[0x10]) + iVar1;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 0x11) = 0xff;
  *(undefined1 *)((int)param_1 + 0x45) = 0xff;
  if (param_2 == 0) {
    if ((param_1[4] != 0) && (iVar1 = tasks__60047d80(param_1 + 4), iVar1 != 0)) {
      *DAT_60047238 = 0x10000000;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
    }
  }
  else {
    FUN_6004bb04(param_1 + 4);
    FUN_6004bb04(param_1 + 9);
  }
  FUN_600485c8();
  return 1;
}



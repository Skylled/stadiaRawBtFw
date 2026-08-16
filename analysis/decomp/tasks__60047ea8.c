// 60047ea8  tasks__60047ea8  size=98 bytes
// src: tasks.c
// --- callers ---
//   60047548 FUN_60047548
//   60047678 queue__60047678
//   60047290 queue__60047290
// --- callees ---
//   60048580 FUN_60048580
//   6004c084 thunk_FUN_601016a2
//   60047e90 FUN_60047e90
//   600485c8 FUN_600485c8


/* src: tasks.c */

undefined4 tasks__60047ea8(int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1 == (int *)0x0) {
    thunk_FUN_601016a2(DAT_60047f10,0xd43,DAT_60047f0c);
  }
  if (param_2 == (uint *)0x0) {
    thunk_FUN_601016a2(DAT_60047f10,0xd44,DAT_60047f0c);
  }
  FUN_60048580();
  uVar2 = *param_2;
  if (uVar2 == 0xffffffff) {
LAB_60047ef8:
    uVar3 = 0;
  }
  else {
    if ((*param_1 == *DAT_60047f18) || (*DAT_60047f14 < (uint)param_1[1])) {
      uVar1 = *DAT_60047f14 - param_1[1];
      if (uVar1 < uVar2) {
        *param_2 = uVar2 - uVar1;
        FUN_60047e90(param_1);
        goto LAB_60047ef8;
      }
      *param_2 = 0;
    }
    uVar3 = 1;
  }
  FUN_600485c8();
  return uVar3;
}



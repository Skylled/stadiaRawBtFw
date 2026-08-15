// 60076438  input_task__60076438  size=170 bytes
// src: input_task.cc
// --- callers ---
//   600765a4 FUN_600765a4
//   600764fc input_task__600764fc
// --- callees ---
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   600d3b24 FUN_600d3b24
//   600dac68 FUN_600dac68


/* src: input_task.cc */

undefined4 input_task__60076438(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [144];
  
  if (param_2 == 0) {
    uVar2 = 3;
  }
  else {
    iVar1 = thunk_EXT_FUN_00007a2c(*(undefined4 *)(param_1 + 0x3a4),4,param_2,0,10);
    if (iVar1 == 0) {
      uVar2 = 4;
    }
    else {
      if (param_2 < 5) {
        *(undefined4 *)(param_1 + 100) = 10;
      }
      else {
        *(undefined4 *)(param_1 + 100) = 0;
      }
      *(uint *)(param_1 + 0x68) = (uint)(*(int *)(param_1 + 100) << 0xc) / 100;
      *(uint *)(param_1 + 0x6c) = param_2 * 2 + -1;
      local_a8 = DAT_600764e4;
      local_a4 = 0x2a6;
      FUN_600d3b3a(auStack_a0);
      FUN_600d37ac(auStack_a0,DAT_600764e8);
      FUN_600dac68(auStack_a0,param_2);
      FUN_600d37ac(auStack_a0,DAT_600764ec);
      FUN_600dac68(auStack_a0,*(undefined4 *)(param_1 + 0x68));
      FUN_600d37ac(auStack_a0,DAT_600764f0);
      FUN_600dac68(auStack_a0,*(undefined4 *)(param_1 + 100));
      FUN_600d37ac(auStack_a0,DAT_600764f4);
      FUN_600dac68(auStack_a0,*(undefined4 *)(param_1 + 0x6c));
      FUN_600d37ac(auStack_a0,DAT_600764f8);
      FUN_600d3b24(&local_a8);
      uVar2 = 0;
    }
  }
  return uVar2;
}



// 600ca5cc  tasks__600ca5cc  size=176 bytes
// src: tasks.c
// --- callers ---
//   60101760 FUN_60101760
//   600ee062 FUN_600ee062
// --- callees ---
//   6013d0a0 thunk_EXT_FUN_000073cc
//   601016a2 FUN_601016a2
//   600ca0d8 FUN_600ca0d8
//   6013d188 thunk_EXT_FUN_0000b2fe
//   6013d140 thunk_EXT_FUN_0000b344
//   6013d360 thunk_EXT_FUN_00007d64
//   6013d000 thunk_EXT_FUN_00007dac


/* src: tasks.c */

void tasks__600ca5cc(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = DAT_600ca67c;
  thunk_EXT_FUN_00007d64();
  if (param_1 == 0) {
    param_1 = *piVar1;
  }
  iVar3 = thunk_EXT_FUN_0000b344(param_1 + 4);
  if (iVar3 == 0) {
    if (*(int *)(DAT_600ca680 + *(uint *)(param_1 + 0x2c) * 0x14) == 0) {
      *DAT_600ca684 = *DAT_600ca684 & ~(1 << (*(uint *)(param_1 + 0x2c) & 0xff));
    }
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    thunk_EXT_FUN_0000b344(param_1 + 0x18);
  }
  thunk_EXT_FUN_0000b2fe(DAT_600ca688,param_1 + 4);
  if (*(char *)(param_1 + 200) == '\x01') {
    *(undefined1 *)(param_1 + 200) = 0;
  }
  piVar2 = DAT_600ca68c;
  thunk_EXT_FUN_00007dac();
  if (*piVar2 != 0) {
    thunk_EXT_FUN_00007d64();
    FUN_600ca0d8();
    thunk_EXT_FUN_00007dac();
  }
  if (*piVar1 == param_1) {
    if (*piVar2 == 0) {
      if (*DAT_600ca688 != *DAT_600ca6a0) {
        thunk_EXT_FUN_000073cc();
        return;
      }
      *piVar1 = 0;
    }
    else {
      if (*DAT_600ca690 != 0) {
        FUN_601016a2(DAT_600ca698,0x6d5,DAT_600ca694);
      }
      *DAT_600ca69c = 0x10000000;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
    }
  }
  return;
}



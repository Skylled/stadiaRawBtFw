// 600ca27c  tasks__600ca27c  size=164 bytes
// src: tasks.c
// --- callers ---
//   6010179a FUN_6010179a
//   600cc160 FUN_600cc160
//   600ee062 FUN_600ee062
// --- callees ---
//   601016a2 FUN_601016a2
//   600ca1b4 tasks__600ca1b4
//   600ca0d8 FUN_600ca0d8
//   6013d188 thunk_EXT_FUN_0000b2fe
//   6013d140 thunk_EXT_FUN_0000b344
//   6013d360 thunk_EXT_FUN_00007d64
//   6013d000 thunk_EXT_FUN_00007dac


/* src: tasks.c */

void tasks__600ca27c(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_600ca320;
  thunk_EXT_FUN_00007d64();
  if (param_1 == 0) {
    param_1 = *piVar1;
  }
  iVar2 = thunk_EXT_FUN_0000b344(param_1 + 4);
  if (iVar2 == 0) {
    if (*(int *)(DAT_600ca324 + *(uint *)(param_1 + 0x2c) * 0x14) == 0) {
      *DAT_600ca328 = *DAT_600ca328 & ~(1 << (*(uint *)(param_1 + 0x2c) & 0xff));
    }
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    thunk_EXT_FUN_0000b344(param_1 + 0x18);
  }
  *DAT_600ca32c = *DAT_600ca32c + 1;
  if (*piVar1 == param_1) {
    thunk_EXT_FUN_0000b2fe(DAT_600ca330,param_1 + 4);
    *DAT_600ca334 = *DAT_600ca334 + 1;
  }
  else {
    *DAT_600ca34c = *DAT_600ca34c + -1;
    tasks__600ca1b4(param_1);
    FUN_600ca0d8();
  }
  thunk_EXT_FUN_00007dac();
  if ((*DAT_600ca338 != 0) && (*piVar1 == param_1)) {
    if (*DAT_600ca33c != 0) {
      FUN_601016a2(DAT_600ca344,0x4d8,DAT_600ca340);
    }
    *DAT_600ca348 = 0x10000000;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}



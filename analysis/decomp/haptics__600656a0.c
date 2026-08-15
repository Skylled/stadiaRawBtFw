// 600656a0  haptics__600656a0  size=144 bytes
// src: haptics.cc
// --- callers ---
//   6006573c haptics__6006573c
//   600d6cca FUN_600d6cca
// --- callees ---
//   600d4cae FUN_600d4cae
//   600d4b28 FUN_600d4b28
//   600d37b8 FUN_600d37b8
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   600cedd8 FUN_600cedd8
//   60051120 FUN_60051120
//   6013cef8 thunk_EXT_FUN_0000737c
//   60101b76 FUN_60101b76
//   600d4c3a FUN_600d4c3a


/* src: haptics.cc */

void haptics__600656a0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [152];
  
  iVar2 = thunk_EXT_FUN_00007a2c(*(undefined4 *)(param_1 + 0x68),3,0,0,10);
  if (iVar2 != 1) {
    FUN_60051120(auStack_ac,DAT_60065730,0x27,4);
    FUN_60101b76(auStack_a4,DAT_60065734);
    FUN_600d37b8(auStack_ac);
  }
  iVar2 = *(int *)(param_1 + 4);
  if (*(char *)(iVar2 + 10) == '\0') {
LAB_600656e8:
    if (*(char *)(iVar2 + 0x38) == '\0') goto LAB_600656fa;
    cVar1 = FUN_600d4cae(iVar2,0);
    if (cVar1 == '\0') goto LAB_600656fa;
  }
  else {
    cVar1 = FUN_600d4c3a(iVar2,0);
    if (cVar1 == '\0') goto LAB_600656e8;
  }
  FUN_60051120(auStack_ac,DAT_60065730,0x28);
  FUN_60101b76(auStack_a4,DAT_60065738);
  FUN_600d37b8(auStack_ac);
LAB_600656fa:
  thunk_EXT_FUN_0000737c(1);
  FUN_600cedd8(*(undefined4 *)(*(int *)(param_1 + 8) + 0x20),
               *(undefined4 *)(*(int *)(param_1 + 8) + 0x18),1);
  FUN_600d4b28(*(undefined4 *)(param_1 + 4));
  return;
}



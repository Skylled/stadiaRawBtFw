// 600658b4  haptics_cluster__600658b4  size=202 bytes
// src: haptics_cluster.cc
// --- callers ---
//   600d6d2a FUN_600d6d2a
// --- callees ---
//   600cae38 timers__600cae38
//   600d6cca FUN_600d6cca
//   6007053c external_controller__6007053c
//   600d37ac FUN_600d37ac
//   600d37b8 FUN_600d37b8
//   60051120 FUN_60051120
//   600d6cf8 FUN_600d6cf8
//   6013d2a0 thunk_EXT_FUN_00007a2c


/* src: haptics_cluster.cc */

uint haptics_cluster__600658b4(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_b4 [8];
  undefined1 auStack_ac [144];
  byte local_1c;
  
  if (*(char *)(param_2 + 1) != '\0') {
    *(undefined2 *)(param_1 + 8) = *param_2;
  }
  if (*(char *)(param_3 + 1) != '\0') {
    *(undefined2 *)(param_1 + 0x10) = *param_3;
  }
  iVar1 = timers__600cae38(*(undefined4 *)(param_1 + 0xd4));
  iVar2 = thunk_EXT_FUN_00007a2c(*(undefined4 *)(param_1 + 0xd4),3,0,0,10);
  if (iVar2 == 1) {
    if (iVar1 != 0) {
      if (*(char *)(param_2 + 1) == '\0') {
        *(undefined2 *)(param_1 + 8) = 0;
        uVar3 = FUN_600d6cca(*(undefined4 *)(param_1 + 4));
        if ((uVar3 & 0xff) != 0) {
          return uVar3;
        }
      }
      if (*(char *)(param_3 + 1) == '\0') {
        *(undefined2 *)(param_1 + 0x10) = 0;
        uVar3 = FUN_600d6cca(*(undefined4 *)(param_1 + 0xc));
        if ((uVar3 & 0xff) != 0) {
          return uVar3;
        }
      }
    }
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    if ((*(char *)(param_1 + 0xcc) == '\0') ||
       (((*(char *)(param_2 + 1) == '\0' ||
         (uVar3 = FUN_600d6cf8(*(undefined4 *)(param_1 + 4),*(undefined2 *)(param_1 + 8)),
         (uVar3 & 0xff) == 0)) &&
        ((*(char *)(param_3 + 1) == '\0' ||
         (uVar3 = FUN_600d6cf8(*(undefined4 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0x10)),
         (uVar3 & 0xff) == 0)))))) {
      uVar3 = 0;
      external_controller__6007053c(*(undefined2 *)(param_1 + 8),*(undefined2 *)(param_1 + 0x10));
    }
  }
  else {
    FUN_60051120(auStack_b4,DAT_60065980,0x45,4);
    FUN_600d37ac(auStack_ac,DAT_60065984);
    uVar3 = (uint)local_1c;
    FUN_600d37b8(auStack_b4);
  }
  return uVar3;
}



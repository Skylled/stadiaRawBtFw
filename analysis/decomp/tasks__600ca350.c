// 600ca350  tasks__600ca350  size=98 bytes
// src: tasks.c
// --- callers ---
//   600ca7d0 FUN_600ca7d0
//   600ca6b0 FUN_600ca6b0
// --- callees ---
//   601016a2 FUN_601016a2
//   6013d360 thunk_EXT_FUN_00007d64
//   6013d000 thunk_EXT_FUN_00007dac


/* src: tasks.c */

undefined4 tasks__600ca350(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_601016a2(DAT_600ca3b8,0x56e,DAT_600ca3b4,param_4,param_4);
  }
  if (*DAT_600ca3bc == param_1) {
    uVar1 = 0;
  }
  else {
    thunk_EXT_FUN_00007d64();
    iVar2 = *(int *)(param_1 + 0x14);
    thunk_EXT_FUN_00007dac();
    if ((iVar2 == *DAT_600ca3c0) || (iVar2 == *DAT_600ca3c4)) {
      uVar1 = 2;
    }
    else if (iVar2 == DAT_600ca3c8) {
      if (*(int *)(param_1 + 0x28) == 0) {
        uVar1 = 3;
      }
      else {
        uVar1 = 2;
      }
    }
    else if (iVar2 == DAT_600ca3cc) {
      uVar1 = 4;
    }
    else if (iVar2 == 0) {
      uVar1 = 4;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



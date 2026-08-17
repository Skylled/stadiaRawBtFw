// 600cae38  timers__600cae38  size=38 bytes
// src: timers.c
// --- callers ---
//   600df014 FUN_600df014
//   60081868 FUN_60081868
//   600658b4 haptics_cluster__600658b4
//   60081808 FUN_60081808
//   6005990c sleep_driver__6005990c
// --- callees ---
//   601016a2 FUN_601016a2
//   6013d000 thunk_EXT_FUN_00007dac
//   6013d360 thunk_EXT_FUN_00007d64


/* src: timers.c */

bool timers__600cae38(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_601016a2(DAT_600cae64,0x3b6,DAT_600cae60);
  }
  thunk_EXT_FUN_00007d64();
  iVar1 = *(int *)(param_1 + 0x14);
  thunk_EXT_FUN_00007dac();
  return iVar1 != 0;
}



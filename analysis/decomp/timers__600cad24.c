// 600cad24  timers__600cad24  size=104 bytes
// src: timers.c
// --- callers ---
//   600721e8 timer__600721e8
//   600511c8 timer__600511c8
//   60081450 timer__60081450
//   6005afd8 timer__6005afd8
//   60082ff4 timer__60082ff4
//   60073bf0 timer__60073bf0
//   6007fb34 timer__6007fb34
//   60074658 timer__60074658
//   60058e0c timer__60058e0c
// --- callees ---
//   601016a2 FUN_601016a2
//   601007b6 FUN_601007b6
//   600cac50 FUN_600cac50


/* WARNING: Removing unreachable block (ram,0x600cad3c) */
/* src: timers.c */

undefined4 *
timers__600cad24(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 *param_6)

{
  if (param_6 == (undefined4 *)0x0) {
    FUN_601016a2(DAT_600cad90,0x14a,DAT_600cad8c,0x30,param_1);
  }
  else {
    if (param_2 == 0) {
      FUN_601016a2(DAT_600cad90,0x168,DAT_600cad8c,0x30,param_1);
    }
    FUN_600cac50();
    *param_6 = param_1;
    param_6[9] = param_5;
    param_6[8] = param_4;
    param_6[6] = param_2;
    param_6[7] = param_3;
    FUN_601007b6(param_6 + 1);
    *(undefined1 *)(param_6 + 0xb) = 1;
  }
  return param_6;
}



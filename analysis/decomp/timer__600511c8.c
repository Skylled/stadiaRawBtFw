// 600511c8  timer__600511c8  size=108 bytes
// src: timer.h
// --- callers ---
//   600761d4 FUN_600761d4
//   60080a78 FUN_60080a78
//   6005d694 FUN_6005d694
//   60080278 FUN_60080278
//   6005cd20 FUN_6005cd20
//   600765a4 FUN_600765a4
// --- callees ---
//   60101740 FUN_60101740
//   600cad24 timers__600cad24
//   600ce2a0 FUN_600ce2a0


/* src: timer.h */

void timer__600511c8(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,undefined4 param_7)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined1 auStack_b0 [152];
  
  *param_1 = param_7;
  param_1[2] = param_4;
  param_1[3] = param_5;
  if (param_3 == 0) {
    FUN_600ce2a0(auStack_b0,DAT_60051238,DAT_60051234,0x4c);
    FUN_60101740(auStack_b0);
  }
  iVar1 = timers__600cad24(param_2,param_3,param_6,param_1,DAT_6005123c,param_1 + 4);
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    FUN_600ce2a0(auStack_b0,DAT_60051238,DAT_60051234,0x4f);
    FUN_60101740(auStack_b0);
  }
                    /* WARNING: Could not recover jumptable at 0x60051232. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}



// 600721e8  timer__600721e8  size=108 bytes
// src: timer.h
// --- callers ---
//   60072260 FUN_60072260
// --- callees ---
//   60101740 FUN_60101740
//   600cad24 timers__600cad24
//   600ce2a0 FUN_600ce2a0


/* src: timer.h */

undefined4 *
timer__600721e8(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5,undefined1 param_6,undefined4 param_7)

{
  int iVar1;
  undefined1 auStack_b0 [152];
  
  *param_1 = param_7;
  param_1[2] = param_4;
  param_1[3] = param_5;
  if (param_3 == 0) {
    FUN_600ce2a0(auStack_b0,PTR_s_CHECK_failed_60122ce9_9_60072258,PTR_s_timer_h_60072254,0x4c);
    FUN_60101740(auStack_b0);
  }
  iVar1 = timers__600cad24(param_2,param_3,param_6,param_1,PTR_LAB_600d9aa0_1_6007225c,param_1 + 4);
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    FUN_600ce2a0(auStack_b0,PTR_s_CHECK_failed_60122ce9_9_60072258,PTR_s_timer_h_60072254,0x4f);
    FUN_60101740(auStack_b0);
  }
  return param_1;
}



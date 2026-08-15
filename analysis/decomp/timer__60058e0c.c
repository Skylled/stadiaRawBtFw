// 60058e0c  timer__60058e0c  size=108 bytes
// src: timer.h
// --- callers ---
// --- callees ---
//   600cad24 timers__600cad24
//   600ce2a0 FUN_600ce2a0
//   60101740 FUN_60101740


/* src: timer.h */

undefined4 *
timer__60058e0c(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5,undefined1 param_6,undefined4 param_7)

{
  int iVar1;
  undefined1 auStack_b0 [152];
  
  *param_1 = param_7;
  param_1[2] = param_4;
  param_1[3] = param_5;
  if (param_3 == 0) {
    FUN_600ce2a0(auStack_b0,PTR_s_CHECK_failed_60122ce9_9_60058e7c,PTR_s_timer_h_60058e78,0x4c);
    FUN_60101740(auStack_b0);
  }
  iVar1 = timers__600cad24(param_2,param_3,param_6,param_1,PTR_LAB_600d36c4_1_60058e80,param_1 + 4);
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    FUN_600ce2a0(auStack_b0,PTR_s_CHECK_failed_60122ce9_9_60058e7c,PTR_s_timer_h_60058e78,0x4f);
    FUN_60101740(auStack_b0);
  }
  return param_1;
}



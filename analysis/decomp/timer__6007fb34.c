// 6007fb34  timer__6007fb34  size=164 bytes
// src: timer.h
// --- callers ---
//   6007fbe4 FUN_6007fbe4
// --- callees ---
//   60101740 FUN_60101740
//   600cad24 timers__600cad24
//   600d37ac FUN_600d37ac


/* src: timer.h */

undefined4 *
timer__6007fb34(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5,undefined1 param_6,undefined4 param_7)

{
  undefined *local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  int iStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [130];
  
  *param_1 = param_7;
  param_1[2] = param_4;
  param_1[3] = param_5;
  if (param_3 == 0) {
    local_b0 = PTR_s_timer_h_6007fbd8;
    local_9c = 0;
    local_ac = 0x4c;
    local_a8 = local_9a;
    local_9b = 0;
    local_9a[0] = 0;
    local_a4 = 0x80;
    iStack_a0 = param_3;
    FUN_600d37ac(&local_a8,PTR_s_CHECK_failed_60122ce9_9_6007fbdc);
    FUN_60101740(&local_b0);
  }
  iStack_a0 = timers__600cad24(param_2,param_3,param_6,param_1,PTR_LAB_600dedee_1_6007fbe0,
                               param_1 + 4);
  param_1[1] = iStack_a0;
  if (iStack_a0 == 0) {
    local_9c = 0;
    local_b0 = PTR_s_timer_h_6007fbd8;
    local_9b = 0;
    local_ac = 0x4f;
    local_a8 = local_9a;
    local_9a[0] = 0;
    local_a4 = 0x80;
    FUN_600d37ac(&local_a8,PTR_s_CHECK_failed_60122ce9_9_6007fbdc);
    FUN_60101740(&local_b0);
  }
  return param_1;
}



// 60082ff4  timer__60082ff4  size=116 bytes
// src: timer.h
// --- callers ---
// --- callees ---
//   60074ec8 FUN_60074ec8
//   60101740 FUN_60101740
//   600cad24 timers__600cad24
//   600d37ac FUN_600d37ac


/* src: timer.h */

undefined4 * timer__60082ff4(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined *local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  undefined4 local_9c;
  int iStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [134];
  
  puVar1 = DAT_60083068;
  iVar3 = param_3[1];
  *DAT_60083068 = *param_3;
  puVar1[1] = iVar3;
  if (iVar3 != 0) {
    FUN_60074ec8();
  }
  puVar2 = DAT_6008306c;
  puVar4 = DAT_6008306c + 2;
  *DAT_6008306c = param_1;
  puVar2[1] = param_2;
  iStack_98 = timers__600cad24(PTR_s_BleDbWriteTmr_60083074,2000,0,puVar2 + -3,
                               PTR_LAB_600dfc56_1_60083070,puVar4);
  puVar1[2] = iStack_98;
  if (iStack_98 == 0) {
    local_94 = 0;
    local_a8 = PTR_s_timer_h_60083078;
    local_93 = 0;
    local_a4 = 0x4f;
    local_a0 = local_92;
    local_92[0] = 0;
    local_9c = 0x80;
    FUN_600d37ac(&local_a0,PTR_s_CHECK_failed_60122ce9_9_6008307c);
    FUN_60101740(&local_a8);
  }
  return DAT_60083068;
}



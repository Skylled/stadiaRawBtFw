// 6005afd8  timer__6005afd8  size=298 bytes
// src: timer.h
// --- callers ---
//   6005bc74 FUN_6005bc74
// --- callees ---
//   600d3b3a FUN_600d3b3a
//   60101740 FUN_60101740
//   600cad24 timers__600cad24
//   600d37ac FUN_600d37ac
//   60083fd0 FUN_60083fd0
//   6013d310 thunk_EXT_FUN_0000b52a


/* src: timer.h */

undefined4 * timer__6005afd8(undefined4 *param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined1 local_a0;
  undefined1 local_9f;
  
  local_a8 = *DAT_6005b104;
  uStack_a4 = DAT_6005b104[1];
  local_a0 = *(undefined1 *)(DAT_6005b104 + 2);
  local_ac = 9;
  local_9f = 0;
  *param_1 = PTR_DAT_6005b108;
  local_b0 = &local_a8;
  FUN_60083fd0(param_1 + 2,&local_b0);
  param_1[2] = PTR_PTR_6005b10c;
  puVar1 = PTR_DAT_6005b110;
  param_1[0x19] = param_1;
  *param_1 = puVar1;
  param_1[0x1a] = PTR_DAT_6005b114;
  param_1[0x1b] = PTR_DAT_6005b118;
  param_1[0x1c] = PTR_DAT_6005b11c;
  param_1[0x1d] = PTR_DAT_6005b120;
  if (local_b0 != &local_a8) {
    thunk_EXT_FUN_0000b52a();
  }
  uVar2 = DAT_6005b128;
  *param_1 = PTR_PTR_6005b124;
  uVar4 = DAT_6005b14c;
  param_1[0x20] = DAT_6005b12c;
  uVar3 = DAT_6005b130;
  param_1[0x1e] = 0;
  param_1[0x25] = uVar3;
  *(undefined1 *)(param_1 + 0x1f) = 0;
  param_1[0x22] = 0;
  param_1[0x24] = uVar2;
  iVar5 = timers__600cad24(DAT_6005b138,DAT_6005b134,0,param_1 + 0x22,uVar4,param_1 + 0x26);
  param_1[0x23] = iVar5;
  if (iVar5 == 0) {
    local_b0 = (undefined4 *)PTR_s_timer_h_6005b13c;
    local_ac = 0x4f;
    FUN_600d3b3a(&local_a8);
    FUN_600d37ac(&local_a8,PTR_s_CHECK_failed_60122ce9_9_6005b140);
    FUN_60101740(&local_b0);
  }
  puVar1 = PTR_LAB_6005ab5c_1_6005b144;
  param_1[0x34] = uVar2;
  param_1[0x35] = puVar1;
  param_1[0x32] = 0;
  iVar5 = timers__600cad24(DAT_6005b148,30000,0,param_1 + 0x32,uVar4,param_1 + 0x36);
  param_1[0x33] = iVar5;
  if (iVar5 == 0) {
    local_b0 = (undefined4 *)PTR_s_timer_h_6005b13c;
    local_ac = 0x4f;
    FUN_600d3b3a(&local_a8);
    FUN_600d37ac(&local_a8,PTR_s_CHECK_failed_60122ce9_9_6005b140);
    FUN_60101740(&local_b0);
  }
  param_1[0x46] = param_2;
  param_1[0x42] = 0;
  *(undefined1 *)(param_1 + 0x43) = 0;
  *(undefined1 *)((int)param_1 + 0x10d) = 0;
  *(undefined1 *)((int)param_1 + 0x10e) = 0;
  *(undefined1 *)(param_1 + 0x45) = 0;
  *(undefined1 *)(param_1 + 0x47) = 1;
  *(undefined1 *)((int)param_1 + 0x62) = 1;
  return param_1;
}



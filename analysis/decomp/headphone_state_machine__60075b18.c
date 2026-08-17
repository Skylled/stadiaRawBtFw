// 60075b18  headphone_state_machine__60075b18  size=194 bytes
// src: headphone_state_machine.cc
// --- callers ---
//   60075ae0 FUN_60075ae0
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532
//   60083fd0 FUN_60083fd0
//   600d37ac FUN_600d37ac
//   60101740 FUN_60101740
//   6013d310 thunk_EXT_FUN_0000b52a
//   601017e8 FUN_601017e8


/* src: headphone_state_machine.cc */

undefined4 * headphone_state_machine__60075b18(undefined4 *param_1,int param_2)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 **ppuVar3;
  undefined1 **ppuVar4;
  undefined4 *puVar5;
  undefined1 **local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  int iStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [134];
  undefined4 *puVar6;
  
  local_b0 = &local_a8;
  local_b0 = (undefined1 **)thunk_EXT_FUN_0000b532(0x16);
  local_a8 = (undefined1 *)0x15;
  puVar2 = (undefined4 *)(PTR_s_HeadphoneStateMachine_60075bdc + 0x14);
  ppuVar3 = local_b0;
  puVar5 = (undefined4 *)PTR_s_HeadphoneStateMachine_60075bdc;
  do {
    puVar6 = puVar5 + 1;
    ppuVar4 = ppuVar3 + 1;
    *ppuVar3 = (undefined1 *)*puVar5;
    ppuVar3 = ppuVar4;
    puVar5 = puVar6;
  } while (puVar6 != puVar2);
  *(undefined1 *)ppuVar4 = *(undefined1 *)puVar6;
  local_ac = 0x15;
  *(undefined1 *)((int)local_b0 + 0x15) = 0;
  *param_1 = PTR_DAT_60075be0;
  FUN_60083fd0(param_1 + 2,&local_b0);
  param_1[2] = PTR_PTR_60075be4;
  puVar1 = PTR_DAT_60075be8;
  param_1[0x19] = param_1;
  *param_1 = puVar1;
  param_1[0x1a] = DAT_60075bec;
  param_1[0x1b] = DAT_60075bf0;
  param_1[0x1c] = DAT_60075bf4;
  param_1[0x1d] = DAT_60075bf8;
  if (local_b0 != &local_a8) {
    thunk_EXT_FUN_0000b52a();
  }
  puVar1 = PTR_PTR_60075bfc;
  param_1[0x1e] = param_2;
  *param_1 = puVar1;
  param_1[0x34] = 0;
  param_1[0x1f] = 0;
  FUN_601017e8(param_1 + 0x20);
  *(undefined1 *)(param_1 + 0x35) = 0;
  if (param_2 == 0) {
    local_b0 = (undefined1 **)PTR_s_headphone_state_machine_cc_60075c00;
    local_9c = 0;
    local_ac = 0x11;
    local_a8 = local_9a;
    local_9b = 0;
    local_9a[0] = 0;
    local_a4 = 0x80;
    iStack_a0 = param_2;
    FUN_600d37ac(&local_a8,PTR_s_CHECK_failed_60122ce9_9_60075c04);
    FUN_60101740(&local_b0);
  }
  *(undefined1 *)((int)param_1 + 0x62) = 1;
  return param_1;
}



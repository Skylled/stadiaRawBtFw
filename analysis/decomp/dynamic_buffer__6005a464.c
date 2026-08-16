// 6005a464  dynamic_buffer__6005a464  size=90 bytes
// src: dynamic_buffer.h
// --- callers ---
//   6004cbf0 device_info__6004cbf0
//   6005a6b0 device_info__6005a6b0
// --- callees ---
//   600d3b3a FUN_600d3b3a
//   6013d038 thunk_EXT_FUN_00008832
//   600d37ac FUN_600d37ac
//   60101740 FUN_60101740


/* src: dynamic_buffer.h */

undefined4 * dynamic_buffer__6005a464(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [144];
  
  *param_1 = DAT_6005a4c0;
  uVar1 = thunk_EXT_FUN_00008832(param_2);
  param_1[3] = param_2;
  param_1[6] = 0;
  pcVar2 = *(code **)(param_3 + 8);
  param_1[1] = uVar1;
  param_1[2] = param_2;
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(param_1 + 4,param_3,2);
    param_1[7] = *(undefined4 *)(param_3 + 0xc);
    param_1[6] = *(undefined4 *)(param_3 + 8);
  }
  if (param_1[1] == 0) {
    local_a8 = DAT_6005a4c4;
    local_a4 = 0x45;
    FUN_600d3b3a(auStack_a0);
    FUN_600d37ac(auStack_a0,DAT_6005a4c8);
    FUN_60101740(&local_a8);
  }
  return param_1;
}



// 600da424  FUN_600da424  size=40 bytes
// --- callers ---
//   60075088 audio_states__60075088
// --- callees ---
//   6013d3c8 thunk_EXT_FUN_00001680


undefined4 * FUN_600da424(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  *param_2 = 0;
  param_2[1] = 0;
  *param_1 = uVar1;
  local_c = param_1[1];
  param_1[1] = uVar2;
  thunk_EXT_FUN_00001680(&local_c);
  return param_1;
}



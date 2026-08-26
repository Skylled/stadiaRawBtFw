// 600d5fd2  FUN_600d5fd2  size=56 bytes
// --- callers ---
//   60063e24 usb_host_audio_topology__60063e24
// --- callees ---
//   600d5fc2 FUN_600d5fc2


void FUN_600d5fd2(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = *param_1;
  local_10 = param_1[1];
  *param_1 = 0;
  local_c = param_1[2];
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = *param_2;
  *param_2 = 0;
  uVar1 = param_1[1];
  param_1[1] = param_2[1];
  param_2[1] = uVar1;
  uVar1 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = uVar1;
  FUN_600d5fc2(&local_14);
  return;
}



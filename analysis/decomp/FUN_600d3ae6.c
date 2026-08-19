// 600d3ae6  FUN_600d3ae6  size=28 bytes
// --- callers ---
//   6005a6b0 device_info__6005a6b0
//   60067a68 gotham__60067a68
//   60067d14 gotham__60067d14
//   60067b50 gotham__60067b50
//   60067c3c gotham__60067c3c
// --- callees ---
//   600cbb14 FUN_600cbb14
//   60101b76 FUN_60101b76


undefined4 FUN_600d3ae6(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 uVar2;
  undefined4 local_c;
  
  uVar2 = param_1;
  local_c = param_2;
  uVar1 = FUN_600cbb14(&local_c);
  FUN_60101b76(param_1,uVar1,extraout_r2,extraout_r3,uVar2);
  return param_1;
}



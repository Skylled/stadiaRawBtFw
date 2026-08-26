// 600d5e14  FUN_600d5e14  size=16 bytes
// --- callers ---
//   600d6100 FUN_600d6100
//   60063e24 usb_host_audio_topology__60063e24
//   600d5e24 FUN_600d5e24
//   60064110 usb_host_audio_topology__60064110
//   600d67e8 FUN_600d67e8
// --- callees ---
//   60101cfa FUN_60101cfa


undefined4 * FUN_600d5e14(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60101cfa(*param_1);
  *param_1 = uVar1;
  return param_1;
}



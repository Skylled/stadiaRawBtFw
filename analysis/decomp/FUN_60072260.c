// 60072260  FUN_60072260  size=66 bytes
// --- callers ---
//   60073bf0 timer__60073bf0
// --- callees ---
//   600721e8 timer__600721e8
//   600d9b5c FUN_600d9b5c


undefined1 *
FUN_60072260(undefined4 param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  *param_2 = 0;
  *(undefined4 *)(param_2 + 4) = param_3;
  *(undefined4 *)(param_2 + 8) = param_4;
  FUN_600d9b5c(param_2 + 0xc);
  puVar1 = PTR_LAB_6007143c_1_600722a4;
  *(undefined4 *)(param_2 + 0x60) = param_1;
  timer__600721e8(param_2 + 100,PTR_s_Haptic_watchdog_600722ac,5000,PTR_LAB_600d99cc_1_600722a8,
                  puVar1,0,param_2);
  return param_2;
}



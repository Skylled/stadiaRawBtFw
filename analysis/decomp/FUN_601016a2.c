// 601016a2  FUN_601016a2  size=78 bytes
// --- callers ---
//   600ca1b4 tasks__600ca1b4
//   6006012c pwm__6006012c
//   60068b80 battery_gauge_bq2742X__60068b80
//   60080b24 gatt_manager_task__60080b24
//   600cbdd4 init__600cbdd4
//   600ca5cc tasks__600ca5cc
//   600c9de4 queue__600c9de4
//   600835ac private_heap__600835ac
//   60083534 private_heap__60083534
//   600cacb8 timers__600cacb8
//   60061a98 hardware_timer__60061a98
//   6006044c reset__6006044c
//   600c9d44 event_groups__600c9d44
//   600600f8 pwm__600600f8
//   600cc6a0 heap_5_improved__600cc6a0
//   600cae38 timers__600cae38
//   600cad94 timers__600cad94
//   6005d9a8 gatt_service_handle__6005d9a8
//   600ca350 tasks__600ca350
//   600ca4ac tasks__600ca4ac
//   600521b8 heap_5_improved__600521b8
//   600ca27c tasks__600ca27c
//   600cad24 timers__600cad24
//   600cb030 mpu__600cb030
//   600c9ef0 queue__600c9ef0
//   60083568 private_heap__60083568
//   600ca3d0 FUN_600ca3d0
//   600cae18 timers__600cae18
//   60060518 sai__60060518
//   600ca9e8 tasks__600ca9e8
//   60078340 firmware_image_upload__60078340
//   60060170 xbara__60060170
//   600c9e6c queue__600c9e6c
//   60060b64 uart__60060b64
//   600c9eac queue__600c9eac
//   600c9d88 event_groups__600c9d88
//   600c9f94 queue__600c9f94
//   600ca57c tasks__600ca57c
//   600cc5ac FUN_600cc5ac
//   600ca5a8 tasks__600ca5a8
//   600cab44 tasks__600cab44
//   6005d714 trigger_bug_report__6005d714
//   600600c4 pwm__600600c4
//   600cbdc8 xbara__600cbdc8
//   6006e484 gki_ft__6006e484
//   600583c0 FUN_600583c0
//   60051824 exit__60051824
//   600ca1f8 tasks__600ca1f8
//   600604dc reset__600604dc
// --- callees ---
//   600cc090 FUN_600cc090
//   6005856c FUN_6005856c
//   600cc124 FUN_600cc124
//   600cbfa0 FUN_600cbfa0
//   60101bfc FUN_60101bfc


void FUN_601016a2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int local_20;
  undefined4 local_1c;
  
  uVar1 = FUN_6005856c();
  FUN_600cc090(&local_20,uVar1,0x32,param_1,param_2,0);
  if (local_20 != 0) {
    FUN_60101bfc(local_20 + 0xc,param_3);
    FUN_600cbfa0(local_1c,local_20);
    FUN_600cc124(*(undefined4 *)(local_20 + 0xc),param_1,param_2);
  }
  return;
}



// 600d8322  FUN_600d8322  size=60 bytes
// --- callers ---
//   60068698 FUN_60068698
//   6006849c FUN_6006849c
//   600684e0 battery_charger_bq25601__600684e0
//   600682f4 battery_charger_bq25601__600682f4
//   600d838a FUN_600d838a
//   60068374 battery_charger_bq25601__60068374
//   600684bc FUN_600684bc
//   60068674 FUN_60068674
//   60068278 battery_charger_bq25601__60068278
//   60068470 FUN_60068470
//   600686e4 FUN_600686e4
//   600683f4 battery_charger_bq25601__600683f4
//   6006859c FUN_6006859c
//   60068604 FUN_60068604
//   600685d0 FUN_600685d0
//   60068528 FUN_60068528
// --- callees ---
//   6013d0b0 thunk_EXT_FUN_00001ea4


void FUN_600d8322(undefined4 *param_1,undefined1 *param_2)

{
  char cVar1;
  undefined1 local_14 [3];
  undefined1 local_11 [5];
  
  local_11[0] = 0;
  local_14[0] = *param_2;
  cVar1 = thunk_EXT_FUN_00001ea4(*param_1,*(undefined1 *)(param_1 + 1),local_14,1,local_11,1,200);
  if (cVar1 == '\0') {
    **(undefined1 **)(param_2 + 4) = local_11[0];
  }
  return;
}



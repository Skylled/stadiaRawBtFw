// 600cedd8  FUN_600cedd8  size=22 bytes
// --- callers ---
//   6006ec50 FUN_6006ec50
//   600d8c0a FUN_600d8c0a
//   600656a0 haptics__600656a0
//   600532f0 FUN_600532f0
//   60068a00 battery_gauge_bq2742X__60068a00
//   6006b02c led_driver_lp5562__6006b02c
//   6006ec00 FUN_6006ec00
//   600510c0 FUN_600510c0
//   6006573c haptics__6006573c
//   6005990c sleep_driver__6005990c
// --- callees ---


void FUN_600cedd8(uint *param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = 1 << (param_2 & 0xff);
  if (param_3 == 0) {
    uVar1 = *param_1 & ~uVar1;
  }
  else {
    uVar1 = uVar1 | *param_1;
  }
  *param_1 = uVar1;
  return;
}



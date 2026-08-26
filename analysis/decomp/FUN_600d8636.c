// 600d8636  FUN_600d8636  size=52 bytes
// --- callers ---
//   600d86ba FUN_600d86ba
//   60068cb4 battery_gauge_bq2742X__60068cb4
//   600d866a FUN_600d866a
// --- callees ---
//   600d4330 FUN_600d4330
//   600d84ce FUN_600d84ce
//   6013cef8 thunk_EXT_FUN_0000737c


uint FUN_600d8636(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = FUN_600d84ce(param_1,0,param_2,200);
  if ((uVar1 & 0xff) == 0) {
    thunk_EXT_FUN_0000737c(5);
    uVar1 = FUN_600d4330(param_1,0,param_3,200);
    if ((uVar1 & 0xff) == 0) {
      thunk_EXT_FUN_0000737c(5);
      uVar1 = 0;
    }
  }
  return uVar1;
}



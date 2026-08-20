// 600ea802  FUN_600ea802  size=24 bytes
// --- callers ---
//   6008d7ac bcm__6008d7ac
//   600eb450 FUN_600eb450
//   60085528 FUN_60085528
//   6008db50 bcm__6008db50
//   6008ce00 FUN_6008ce00
//   6008dab0 bcm__6008dab0
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600ea7a4 FUN_600ea7a4


void FUN_600ea802(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_600ea7a4(*param_1);
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  return;
}



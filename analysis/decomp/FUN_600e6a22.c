// 600e6a22  FUN_600e6a22  size=40 bytes
// --- callers ---
//   600e930e FUN_600e930e
//   600ebf34 FUN_600ebf34
//   60091580 ec_asn1__60091580
//   600e7490 FUN_600e7490
//   6008ea5c FUN_6008ea5c
//   600e732a FUN_600e732a
//   6008b570 bcm__6008b570
//   600ea75c FUN_600ea75c
//   600e92f0 FUN_600e92f0
//   6008ce00 FUN_6008ce00
//   600ea7a4 FUN_600ea7a4
//   6008e264 bcm__6008e264
//   6008eb24 bcm__6008eb24
//   6008d7ac bcm__6008d7ac
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e


void FUN_600e6a22(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if (-1 < (int)(param_1[4] << 0x1e)) {
      thunk_EXT_FUN_0000ac5e(*param_1);
    }
    if ((param_1[4] & 1) != 0) {
      thunk_EXT_FUN_0000ac5e(param_1);
      return;
    }
    *param_1 = 0;
  }
  return;
}



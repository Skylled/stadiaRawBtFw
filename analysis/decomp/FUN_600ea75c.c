// 600ea75c  FUN_600ea75c  size=30 bytes
// --- callers ---
//   600ea77a FUN_600ea77a
//   60084d34 ecdsa_asn1__60084d34
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e6a22 FUN_600e6a22


void FUN_600ea75c(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_600e6a22(*param_1);
    FUN_600e6a22(param_1[1]);
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  return;
}



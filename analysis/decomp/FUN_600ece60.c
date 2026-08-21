// 600ece60  FUN_600ece60  size=24 bytes
// --- callers ---
//   600861c0 pem_lib__600861c0
//   60086b98 FUN_60086b98
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e


void FUN_600ece60(int param_1)

{
  if (param_1 != 0) {
    thunk_EXT_FUN_0000ac5e(*(undefined4 *)(param_1 + 4));
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  return;
}



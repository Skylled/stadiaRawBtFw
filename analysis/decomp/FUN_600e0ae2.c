// 600e0ae2  FUN_600e0ae2  size=24 bytes
// --- callers ---
//   600eca08 FUN_600eca08
//   600919d4 ex_data__600919d4
//   600e0bfe FUN_600e0bfe
//   600e0afa FUN_600e0afa
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e


void FUN_600e0ae2(int param_1)

{
  if (param_1 != 0) {
    thunk_EXT_FUN_0000ac5e(*(undefined4 *)(param_1 + 4));
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  return;
}



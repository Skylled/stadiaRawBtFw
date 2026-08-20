// 600ec720  FUN_600ec720  size=32 bytes
// --- callers ---
//   6008ef7c a_int__6008ef7c
//   60091ddc FUN_60091ddc
//   6008f5e8 tasn_dec__6008f5e8
//   6008ee9c a_bitstr__6008ee9c
//   6009089c FUN_6009089c
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e


void FUN_600ec720(int param_1)

{
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 8) != 0) && (-1 < *(int *)(param_1 + 0xc) << 0x1b)) {
      thunk_EXT_FUN_0000ac5e();
    }
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  return;
}



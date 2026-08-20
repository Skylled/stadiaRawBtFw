// 600ec58a  FUN_600ec58a  size=72 bytes
// --- callers ---
//   6008f0d8 a_object__6008f0d8
//   6009089c FUN_6009089c
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e


void FUN_600ec58a(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (param_1[5] << 0x1d < 0) {
      if (*param_1 != 0) {
        thunk_EXT_FUN_0000ac5e();
      }
      if (param_1[1] != 0) {
        thunk_EXT_FUN_0000ac5e();
      }
      *param_1 = 0;
      param_1[1] = 0;
    }
    if (param_1[5] << 0x1c < 0) {
      if (param_1[4] != 0) {
        thunk_EXT_FUN_0000ac5e();
      }
      param_1[3] = 0;
      param_1[4] = 0;
    }
    if (param_1[5] << 0x1f < 0) {
      thunk_EXT_FUN_0000ac5e(param_1);
      return;
    }
  }
  return;
}



// 600e723a  FUN_600e723a  size=60 bytes
// --- callers ---
//   6008e264 bcm__6008e264
//   600910dc FUN_600910dc
// --- callees ---
//   6013cfb0 thunk_EXT_FUN_0000ac52
//   6013d208 thunk_EXT_FUN_0000ac5e


void FUN_600e723a(int *param_1)

{
  if (param_1 == (int *)0x0) {
    return;
  }
  if (*param_1 != 0) {
    if (param_1[4] << 0x1e < 0) {
      thunk_EXT_FUN_0000ac52(*param_1,param_1[2] << 2);
    }
    else {
      thunk_EXT_FUN_0000ac5e();
    }
  }
  if (param_1[4] << 0x1f < 0) {
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  thunk_EXT_FUN_0000ac52(param_1,0x14);
  return;
}



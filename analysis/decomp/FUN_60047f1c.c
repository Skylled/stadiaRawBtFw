// 60047f1c  FUN_60047f1c  size=18 bytes
// --- callers ---
//   60046fa4 FUN_60046fa4
// --- callees ---


void FUN_60047f1c(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 < 2) {
    if (param_1 == 0) {
      param_1 = *DAT_60047f30;
    }
    *(undefined4 *)(param_1 + (param_2 + 0x16) * 4) = param_3;
  }
  return;
}



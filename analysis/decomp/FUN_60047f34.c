// 60047f34  FUN_60047f34  size=22 bytes
// --- callers ---
//   60046fa4 FUN_60046fa4
// --- callees ---


undefined4 FUN_60047f34(int param_1,int param_2)

{
  if (param_2 < 2) {
    if (param_1 == 0) {
      param_1 = *DAT_60047f4c;
    }
    return *(undefined4 *)(param_1 + (param_2 + 0x16) * 4);
  }
  return 0;
}



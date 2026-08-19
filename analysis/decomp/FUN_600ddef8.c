// 600ddef8  FUN_600ddef8  size=20 bytes
// --- callers ---
// --- callees ---


void FUN_600ddef8(int param_1,int param_2)

{
  *(char *)(param_1 + 0x31c) = (char)param_2;
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 800) = *(undefined4 *)(param_1 + 4);
    return;
  }
  *(undefined4 *)(param_1 + 800) = 0;
  return;
}



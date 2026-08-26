// 600d46fe  FUN_600d46fe  size=38 bytes
// --- callers ---
//   6005e810 FUN_6005e810
//   6005e8d8 FUN_6005e8d8
//   6005eaf8 FUN_6005eaf8
//   6005edb8 FUN_6005edb8
//   6005e904 FUN_6005e904
//   6005ea2c FUN_6005ea2c
// --- callees ---


void FUN_600d46fe(int *param_1)

{
  *param_1 = (int)param_1 + 0xe;
  *(undefined1 *)((int)param_1 + 0xe) = 0x6e;
  param_1[1] = 0xff;
  *(undefined1 *)((int)param_1 + 0xf) = 0x75;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 4) = 0x6c;
  *(undefined1 *)((int)param_1 + 0x11) = 0x6c;
  param_1[2] = 4;
  return;
}



// 600d3888  FUN_600d3888  size=32 bytes
// --- callers ---
//   60059280 FUN_60059280
//   600d38c8 FUN_600d38c8
// --- callees ---


void FUN_600d3888(int *param_1)

{
  *param_1 = (int)param_1 + 0xe;
  *(undefined1 *)((int)param_1 + 0xe) = 0x7b;
  param_1[1] = 0xff;
  *(undefined1 *)((int)param_1 + 0xf) = 0x7d;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[2] = 2;
  return;
}



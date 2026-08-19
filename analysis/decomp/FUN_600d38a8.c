// 600d38a8  FUN_600d38a8  size=32 bytes
// --- callers ---
//   600593f4 FUN_600593f4
//   600d38c8 FUN_600d38c8
// --- callees ---


void FUN_600d38a8(int *param_1)

{
  *param_1 = (int)param_1 + 0xe;
  *(undefined1 *)((int)param_1 + 0xe) = 0x5b;
  param_1[1] = 0xff;
  *(undefined1 *)((int)param_1 + 0xf) = 0x5d;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[2] = 2;
  return;
}



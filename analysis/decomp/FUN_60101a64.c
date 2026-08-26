// 60101a64  FUN_60101a64  size=28 bytes
// --- callers ---
//   600cbccc FUN_600cbccc
//   600cbb7c FUN_600cbb7c
//   6005dbec FUN_6005dbec
//   6005ebe0 FUN_6005ebe0
//   60051b50 stats__60051b50
//   600cbc60 FUN_600cbc60
//   600cbc18 FUN_600cbc18
//   60051890 FUN_60051890
//   600cbbc0 FUN_600cbbc0
//   6007f7a0 FUN_6007f7a0
//   60101a80 FUN_60101a80
//   6005dcc0 FUN_6005dcc0
// --- callees ---


void FUN_60101a64(int *param_1)

{
  *(undefined1 *)*param_1 = 0x7b;
  *(undefined1 *)(*param_1 + 1) = 0x7d;
  *(undefined1 *)(*param_1 + 2) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  param_1[2] = 2;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  return;
}



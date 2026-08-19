// 600dd7ca  FUN_600dd7ca  size=50 bytes
// --- callers ---
//   6007c1d4 FUN_6007c1d4
// --- callees ---
//   6007d9e8 FUN_6007d9e8
//   600dd83c FUN_600dd83c


undefined4 * FUN_600dd7ca(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  param_1[2] = param_3;
  FUN_6007d9e8();
  FUN_600dd83c(param_1 + 0x22,param_2,param_3);
  param_1[0x4d3] = 0;
  return param_1;
}



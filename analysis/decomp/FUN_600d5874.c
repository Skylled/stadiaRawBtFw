// 600d5874  FUN_600d5874  size=30 bytes
// --- callers ---
//   60062e28 FUN_60062e28
// --- callees ---
//   601017fc FUN_601017fc


undefined1 * FUN_600d5874(undefined1 *param_1,undefined1 param_2)

{
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 0x60) = 0;
  FUN_601017fc();
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return param_1;
}



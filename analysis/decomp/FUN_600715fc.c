// 600715fc  FUN_600715fc  size=36 bytes
// --- callers ---
//   60073bf0 timer__60073bf0
// --- callees ---
//   601017fc FUN_601017fc


undefined4 * FUN_600715fc(undefined4 *param_1)

{
  *param_1 = DAT_60071620;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[0x17] = 0;
  FUN_601017fc();
  *(undefined1 *)(param_1 + 0x18) = 0;
  return param_1;
}



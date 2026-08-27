// 600cc160  FUN_600cc160  size=20 bytes
// --- callers ---
//   60058558 FUN_60058558
//   6007a254 usb_audio_receive__6007a254
//   6007ea1c FUN_6007ea1c
//   6007f41c FUN_6007f41c
//   600583f0 FUN_600583f0
//   6007ac28 FUN_6007ac28
//   60065234 FUN_60065234
//   6007b164 FUN_6007b164
//   60092594 FUN_60092594
//   6005ce30 FUN_6005ce30
//   6005bc58 FUN_6005bc58
//   6007758c FUN_6007758c
//   60080af8 gatt_manager_task__60080af8
//   6005ccd8 FUN_6005ccd8
//   600763b0 FUN_600763b0
// --- callees ---
//   600ca27c tasks__600ca27c


undefined4 * FUN_600cc160(undefined4 *param_1)

{
  *param_1 = DAT_600cc174;
  if (param_1[0x16] != 0) {
    tasks__600ca27c();
  }
  return param_1;
}



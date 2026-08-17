// 60095d4c  FUN_60095d4c  size=76 bytes
// --- callers ---
//   600ff4de FUN_600ff4de
//   600ff21c FUN_600ff21c
//   600fe496 FUN_600fe496
//   600c68fc FUN_600c68fc
// --- callees ---


void FUN_60095d4c(undefined1 param_1,undefined1 param_2,undefined4 param_3)

{
  if (*(int *)(DAT_60095d98 + 0x13c) != 0) {
    (**(code **)(DAT_60095d98 + 0x13c))(7,param_1,param_2,param_3);
  }
  if (*(int *)(DAT_60095d98 + 0x140) != 0) {
    (**(code **)(DAT_60095d98 + 0x140))(7,param_1,param_2,param_3);
  }
  return;
}



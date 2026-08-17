// 600965b4  FUN_600965b4  size=108 bytes
// --- callers ---
// --- callees ---
//   60096594 FUN_60096594


void FUN_600965b4(int param_1)

{
  if ((**(char **)(param_1 + 4) != '\0') && (*(int *)(DAT_60096620 + 0x80) != 0)) {
    (**(code **)(DAT_60096620 + 0x80))(1);
    *(undefined4 *)(DAT_60096620 + 0x80) = 0;
  }
  *(undefined1 *)(DAT_60096620 + 100) = *(undefined1 *)(DAT_60096620 + 0x65);
  if (*(char *)(DAT_60096620 + 100) == '\0') {
    FUN_60096594();
  }
  if (*(int *)(DAT_60096620 + 0x80) != 0) {
    (**(code **)(DAT_60096620 + 0x80))(0);
    *(undefined4 *)(DAT_60096620 + 0x80) = 0;
  }
  return;
}



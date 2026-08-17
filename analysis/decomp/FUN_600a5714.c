// 600a5714  FUN_600a5714  size=70 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a5670 FUN_600a5670


void FUN_600a5714(char *param_1)

{
  if (*param_1 == '\0') {
    FUN_600a5670();
  }
  else if (*(int *)(DAT_600a575c + 0x1130) != 0) {
    (**(code **)(DAT_600a575c + 0x1130))(10);
  }
  return;
}



// 600a8000  FUN_600a8000  size=72 bytes
// --- callers ---
//   600a59d0 FUN_600a59d0
//   600a6d70 FUN_600a6d70
// --- callees ---


void FUN_600a8000(int param_1)

{
  if (*(int *)(DAT_600a8048 + 0x1120) != 0) {
    (**(code **)(DAT_600a8048 + 0x1120))
              (param_1 + 0x10,param_1 + 0x16,param_1 + 0x2c,param_1 + 0x19,
               *(undefined1 *)(param_1 + 0x57));
  }
  return;
}



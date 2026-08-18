// 600cf38e  FUN_600cf38e  size=28 bytes
// --- callers ---
//   6006eb00 FUN_6006eb00
//   600ce780 FUN_600ce780
// --- callees ---
//   600538b4 FUN_600538b4


void FUN_600cf38e(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0x18) == 0) {
    FUN_600538b4(param_1,0x8300000);
  }
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined1 *)(param_2 + 0x2d) = 2;
  return;
}



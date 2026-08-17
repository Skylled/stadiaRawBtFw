// 600a0344  FUN_600a0344  size=68 bytes
// --- callers ---
// --- callees ---
//   600a01c4 FUN_600a01c4


void FUN_600a0344(int param_1)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x10) == 1) {
    FUN_600a01c4();
  }
  else if (*(int *)(param_1 + 0x10) == 2) {
    pcVar1 = *(code **)(DAT_600a0388 + 0x738);
    *(undefined4 *)(DAT_600a0388 + 0x738) = 0;
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(0);
    }
  }
  return;
}



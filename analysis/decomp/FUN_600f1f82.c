// 600f1f82  FUN_600f1f82  size=102 bytes
// --- callers ---
//   600f0c84 FUN_600f0c84
//   600a6b20 FUN_600a6b20
//   600a6d70 FUN_600a6d70
//   600a59d0 FUN_600a59d0
//   600f1a0e FUN_600f1a0e
//   6009b5b4 FUN_6009b5b4
//   600a67ec FUN_600a67ec
//   600a7fb4 FUN_600a7fb4
// --- callees ---
//   600a5760 FUN_600a5760


void FUN_600f1f82(int param_1,undefined1 param_2,char param_3)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0xf4);
  if (*(int *)(param_1 + 0xf4) != 0) {
    *(undefined4 *)(param_1 + 0xf4) = 0;
    if (param_3 == '\0') {
      (*pcVar1)(param_1 + 0x10,1,*(undefined4 *)(param_1 + 0xf8),param_2);
    }
    else {
      (*pcVar1)(param_1 + 100,2,*(undefined4 *)(param_1 + 0xf8),param_2);
    }
  }
  FUN_600a5760();
  return;
}



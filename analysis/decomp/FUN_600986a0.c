// 600986a0  FUN_600986a0  size=58 bytes
// --- callers ---
//   60098d8c FUN_60098d8c
// --- callees ---


undefined4 FUN_600986a0(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 6) == ' ') {
    if (*(code **)(DAT_600986dc + 0xcc) != (code *)0x0) {
      (**(code **)(DAT_600986dc + 0xcc))
                (param_1,*(undefined2 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



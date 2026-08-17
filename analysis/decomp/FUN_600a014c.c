// 600a014c  FUN_600a014c  size=80 bytes
// --- callers ---
//   600fd176 FUN_600fd176
//   600f2a38 FUN_600f2a38
// --- callees ---
//   600a00bc FUN_600a00bc
//   600a01c4 FUN_600a01c4
//   600992d4 FUN_600992d4


void FUN_600a014c(code *param_1)

{
  undefined1 local_9;
  
  if ((*(int *)(DAT_600a019c + 0x71c) != 0) && (param_1 != *(code **)(DAT_600a019c + 0x71c))) {
    if (param_1 == (code *)0x0) {
      return;
    }
    local_9 = 5;
    (*param_1)(&local_9);
    return;
  }
  FUN_600992d4();
  FUN_600a00bc();
  *(code **)(DAT_600a019c + 0x71c) = param_1;
  FUN_600a01c4();
  return;
}



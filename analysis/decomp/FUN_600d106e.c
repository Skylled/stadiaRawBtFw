// 600d106e  FUN_600d106e  size=34 bytes
// --- callers ---
//   600551b8 FUN_600551b8
//   60055350 FUN_60055350
//   600550e4 FUN_600550e4
// --- callees ---
//   600d0ef2 FUN_600d0ef2


undefined4 FUN_600d106e(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 3;
  }
  else {
    if (param_1[1] != 0) {
      (**(code **)(param_1[1] + 4))(*param_1);
      param_1[1] = 0;
    }
    FUN_600d0ef2(param_1);
    uVar1 = 0;
  }
  return uVar1;
}



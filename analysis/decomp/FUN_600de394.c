// 600de394  FUN_600de394  size=32 bytes
// --- callers ---
//   6007df4c FUN_6007df4c
//   6007ded0 FUN_6007ded0
// --- callees ---
//   6007b9d4 FUN_6007b9d4


void FUN_600de394(int *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_1[1] - *param_1 >> 2;
  if (uVar1 < param_2) {
    FUN_6007b9d4(param_1,param_2 - uVar1);
  }
  else if (param_2 < uVar1) {
    param_1[1] = *param_1 + param_2 * 4;
  }
  return;
}



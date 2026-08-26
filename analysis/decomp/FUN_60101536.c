// 60101536  FUN_60101536  size=38 bytes
// --- callers ---
//   6010155c FUN_6010155c
//   600cbdf4 buffer__600cbdf4
// --- callees ---


uint FUN_60101536(int *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 + 0x10 + *(int *)(*param_1 + param_2);
  if ((uint)param_1[2] < uVar1) {
    if (param_1[1] - 4U < uVar1) {
      uVar1 = 0;
    }
    else if (*(int *)(*param_1 + uVar1) == 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}


